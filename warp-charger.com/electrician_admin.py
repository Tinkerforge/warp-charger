"""Small password-only administration interface for the electrician directory."""

import hashlib
import hmac
import re
import secrets
import sqlite3
from datetime import timedelta
from pathlib import Path
from urllib.parse import urlsplit

import click
from flask import Blueprint, abort, current_app, flash, redirect, render_template, request, session, url_for
from itsdangerous import BadSignature, URLSafeTimedSerializer
from werkzeug.security import check_password_hash, generate_password_hash

import electrician_store as store
from electrician_geocoding import COUNTRIES, GeocodingError, address_key, coordinates, geocode

admin = Blueprint("electrician_admin", __name__, url_prefix="/admin")
SOURCE_LABELS = {"": "Standort fehlt", "imported": "Importiert (Genauigkeit unbekannt)",
                 "address": "Adresse gefunden", "approximate": "Ungefährer Standort – bitte prüfen",
                 "manual": "Manuell gesetzt"}


def db_path():
    return current_app.config["ELECTRICIANS_DB"]


def auth_tag():
    return hashlib.sha256(current_app.config["ADMIN_PASSWORD_HASH"].encode()).hexdigest()


def csrf_token():
    if "admin_csrf" not in session:
        session["admin_csrf"] = secrets.token_urlsafe(32)
    return session["admin_csrf"]


@admin.before_request
def protect_admin():
    request.max_content_length = 64 * 1024
    if not current_app.secret_key or not current_app.config.get("ADMIN_PASSWORD_HASH"):
        return render_template("admin/unavailable.html", message="Die Administration ist noch nicht eingerichtet."), 503
    authenticated = hmac.compare_digest(session.get("admin_auth", ""), auth_tag())
    if request.endpoint != "electrician_admin.login" and not authenticated:
        return redirect(url_for("electrician_admin.login"))
    if request.method == "POST":
        token = request.form.get("csrf_token", "")
        if not token or not hmac.compare_digest(token.encode(), session.get("admin_csrf", "").encode()):
            abort(400, "Sitzung abgelaufen. Bitte Seite neu laden und erneut versuchen.")


@admin.after_request
def private_response(response):
    response.headers["Cache-Control"] = "no-store"
    response.headers["X-Robots-Tag"] = "noindex, nofollow"
    response.headers["X-Frame-Options"] = "DENY"
    response.headers["Referrer-Policy"] = "same-origin"
    return response


@admin.context_processor
def template_helpers():
    return {"csrf_token": csrf_token, "source_labels": SOURCE_LABELS,
            "admin_logged_in": bool(session.get("admin_auth"))}


@admin.errorhandler(store.DirectoryUnavailable)
def unavailable(exc):
    current_app.logger.error("Electrician administration: %s", exc)
    return render_template("admin/unavailable.html", message="Die Datenbank ist noch nicht eingerichtet oder nicht erreichbar."), 503


@admin.errorhandler(sqlite3.OperationalError)
def database_busy(exc):
    current_app.logger.error("Electrician database error: %s", exc)
    return render_template("admin/unavailable.html", message="Datenbank derzeit nicht erreichbar. Bitte erneut versuchen."), 503


@admin.route("/login", methods=["GET", "POST"])
def login():
    error = None
    status = 200
    if request.method == "POST":
        retry = store.reserve_login_attempt(db_path())
        if retry:
            response = current_app.make_response((render_template(
                "admin/login.html", error="Zu viele Anmeldeversuche. Bitte später erneut versuchen."), 429))
            response.headers["Retry-After"] = str(retry)
            return response
        password = request.form.get("password", "")
        if len(password) <= 1024 and check_password_hash(current_app.config["ADMIN_PASSWORD_HASH"], password):
            session.clear()
            session.permanent = True
            session["admin_auth"] = auth_tag()
            return redirect(url_for("electrician_admin.index"))
        error, status = "Passwort ist nicht korrekt.", 401
    return render_template("admin/login.html", error=error), status


@admin.post("/logout")
def logout():
    session.clear()
    return redirect(url_for("electrician_admin.login"))


@admin.get("/", strict_slashes=False)
def index():
    query = request.args.get("q", "").strip()
    rows = store.list_electricians(db_path())
    if query:
        rows = [row for row in rows if query.casefold() in " ".join(str(row[key]) for key in store.FIELDS).casefold()]
    return render_template("admin/index.html", electricians=rows, query=query)


def validate(form):
    data = {key: form.get(key, "").strip() for key in store.FIELDS}
    data["country"] = data["country"].upper()
    data["active"] = form.get("active") == "1"
    if any(len(value) > 500 for key, value in data.items() if key != "active"):
        raise ValueError("Bitte höchstens 500 Zeichen pro Feld eingeben.")
    if not all(data[key] for key in ("name", *store.ADDRESS_FIELDS)):
        raise ValueError("Bitte Firma und vollständige Adresse eingeben.")
    if data["country"] not in COUNTRIES:
        raise ValueError("Bitte Deutschland, Österreich oder Schweiz auswählen.")
    pattern = r"[0-9]{5}" if data["country"] == "DE" else r"[0-9]{4}"
    if not re.fullmatch(pattern, data["postal_code"]):
        raise ValueError("Bitte eine gültige Postleitzahl eingeben.")
    if data["email"] and not re.fullmatch(r"[^\s@]+@[^\s@]+\.[^\s@]+", data["email"]):
        raise ValueError("Bitte eine gültige E-Mail-Adresse eingeben.")
    if data["website"]:
        url = urlsplit(data["website"])
        if url.scheme not in ("http", "https") or not url.hostname or url.username or re.search(r"\s", data["website"]):
            raise ValueError("Website muss eine vollständige http://- oder https://-Adresse sein.")
    return data


def location_signer():
    return URLSafeTimedSerializer(current_app.secret_key, salt="electrician-location")


def sign_location(data, location):
    return location_signer().dumps({"address": address_key(data), "location": location})


def read_location(token, data):
    try:
        value = location_signer().loads(token, max_age=3600)
        if value["address"] == address_key(data):
            return value["location"]
    except BadSignature:
        pass
    return None


@admin.route("/electricians/new", methods=["GET", "POST"])
@admin.route("/electricians/<int:electrician_id>", methods=["GET", "POST"])
def edit(electrician_id=None):
    existing = store.get_electrician(db_path(), electrician_id) if electrician_id else None
    if electrician_id and not existing:
        abort(404)
    form = dict(existing) if existing else {"country": "DE", "active": True, "revision": ""}
    location = {"lat": form.get("lat"), "lon": form.get("lon"),
                "source": form.get("location_source", ""), "label": form.get("location_label", "")}
    token = sign_location(form, location) if existing and location["lat"] is not None else ""
    error, notice, status = None, None, 200
    if request.method == "POST":
        form = request.form.to_dict()
        form["active"] = request.form.get("active") == "1"
        token = request.form.get("location_token", "")
        try:
            data = validate(request.form)
            if existing and str(existing["revision"]) != form.get("revision"):
                raise store.EditConflict("Dieser Eintrag wurde inzwischen geändert. Bitte neu öffnen und Änderungen abgleichen.")
            action = form.get("action", "save")
            if action not in ("save", "locate"):
                raise ValueError("Unbekannte Aktion.")
            changed = not existing or address_key(existing) != address_key(data)
            if action == "locate":
                location = geocode(db_path(), data, refresh=True)
                form.pop("manual", None)
            elif form.get("manual") == "1":
                lat, lon = coordinates(form.get("lat"), form.get("lon"))
                location = {"lat": lat, "lon": lon, "source": "manual", "label": ""}
            else:
                preview = read_location(token, data) if token else None
                if preview:
                    location = preview
                elif changed or location["lat"] is None:
                    location = geocode(db_path(), data)
                    if location["source"] == "approximate":
                        action = "locate"  # Review a coarse match before publishing it.
            token = sign_location(data, location)
            form.update(lat=location["lat"], lon=location["lon"])
            if action == "locate":
                notice = "Standort ermittelt. Bitte auf der Karte prüfen und anschließend speichern."
            else:
                store.save_electrician(db_path(), data, location, electrician_id, form.get("revision"))
                flash("Eintrag gespeichert. Die Änderung ist auf der öffentlichen Seite verfügbar.")
                return redirect(url_for("electrician_admin.index"))
        except (ValueError, GeocodingError, store.EditConflict, sqlite3.OperationalError, store.DirectoryUnavailable) as exc:
            if isinstance(exc, (sqlite3.OperationalError, store.DirectoryUnavailable)):
                current_app.logger.error("Electrician save failed: %s", exc)
                error = "Datenbank derzeit nicht erreichbar. Ihre Eingaben bleiben erhalten. Bitte erneut speichern."
                status = 503
            else:
                error = str(exc)
                status = 409 if isinstance(exc, store.EditConflict) else 400
    return render_template("admin/edit.html", form=form, electrician_id=electrician_id,
                           location=location, location_token=token, error=error, notice=notice), status


@admin.post("/electricians/<int:electrician_id>/active")
def toggle_active(electrician_id):
    if request.form.get("active") not in ("0", "1"):
        abort(400)
    try:
        store.set_active(db_path(), electrician_id, request.form.get("revision"), request.form["active"] == "1")
        flash("Sichtbarkeit aktualisiert.")
    except store.EditConflict as exc:
        flash(str(exc))
    return redirect(url_for("electrician_admin.index"))


@admin.post("/electricians/<int:electrician_id>/delete")
def delete(electrician_id):
    try:
        store.delete_electrician(db_path(), electrician_id, request.form.get("revision"))
        flash("Eintrag gelöscht.")
    except store.EditConflict as exc:
        flash(str(exc))
    return redirect(url_for("electrician_admin.index"))


def init_app(app):
    app.config.update(
        SESSION_COOKIE_NAME="warp_admin", SESSION_COOKIE_PATH="/admin",
        SESSION_COOKIE_HTTPONLY=True, SESSION_COOKIE_SAMESITE="Lax",
        PERMANENT_SESSION_LIFETIME=timedelta(hours=8), SESSION_REFRESH_EACH_REQUEST=False,
    )
    app.register_blueprint(admin)

    @app.cli.command("admin-password-hash")
    def password_hash():
        """Generate ADMIN_PASSWORD_HASH without putting the password in shell history."""
        password = click.prompt("Admin password", hide_input=True, confirmation_prompt=True)
        click.echo(generate_password_hash(password))

    @app.cli.command("electricians-init")
    def init_db():
        """Create the SQLite schema (safe to repeat)."""
        store.initialize(app.config["ELECTRICIANS_DB"])
        click.echo(f"Initialized {app.config['ELECTRICIANS_DB']}")

    @app.cli.command("electricians-backup")
    @click.argument("destination", type=click.Path())
    def backup_db(destination):
        """Create a consistent SQLite backup, including committed WAL data."""
        target = Path(destination)
        if target.exists():
            raise click.ClickException("Destination already exists; choose a new filename.")
        with store.connect(app.config["ELECTRICIANS_DB"]) as source:
            backup = sqlite3.connect(target)
            try:
                source.backup(backup)
            finally:
                backup.close()
        click.echo(f"Backup saved to {target}")
