"""SQLite storage for the live electrician directory (shared by all workers)."""

import sqlite3
import time
from contextlib import contextmanager
from pathlib import Path

FIELDS = ("name", "street", "postal_code", "city", "country", "phone", "email", "website")
ADDRESS_FIELDS = ("street", "postal_code", "city", "country")


class DirectoryUnavailable(Exception):
    pass


class EditConflict(Exception):
    pass


@contextmanager
def connect(path):
    # Never silently create an empty production database on a typo/missing mount.
    try:
        db = sqlite3.connect(Path(path).resolve().as_uri() + "?mode=rw", uri=True, timeout=5)
        db.row_factory = sqlite3.Row
        if db.execute("PRAGMA user_version").fetchone()[0] != 1:
            db.close()
            raise DirectoryUnavailable("Run flask --app app electricians-init first.")
    except sqlite3.OperationalError as exc:
        raise DirectoryUnavailable("Electrician database unavailable. Check ELECTRICIANS_DB and run electricians-init.") from exc
    try:
        with db:
            yield db
    finally:
        db.close()


def initialize(path):
    path = Path(path)
    path.parent.mkdir(parents=True, exist_ok=True)
    db = sqlite3.connect(path, timeout=5)
    try:
        version = db.execute("PRAGMA user_version").fetchone()[0]
        if version == 1:
            return
        if version != 0:
            raise DirectoryUnavailable("Unsupported electrician database version.")
        db.execute("PRAGMA journal_mode=WAL")
        db.executescript("""
            BEGIN IMMEDIATE;
            CREATE TABLE IF NOT EXISTS electricians (
                id INTEGER PRIMARY KEY,
                name TEXT NOT NULL, street TEXT NOT NULL, postal_code TEXT NOT NULL,
                city TEXT NOT NULL, country TEXT NOT NULL,
                phone TEXT NOT NULL, email TEXT NOT NULL, website TEXT NOT NULL,
                lat REAL, lon REAL, location_source TEXT NOT NULL DEFAULT '',
                location_label TEXT NOT NULL DEFAULT '',
                active INTEGER NOT NULL DEFAULT 0 CHECK (active IN (0, 1)),
                revision INTEGER NOT NULL DEFAULT 1,
                created_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%SZ', 'now')),
                updated_at TEXT NOT NULL DEFAULT (strftime('%Y-%m-%dT%H:%M:%SZ', 'now')),
                CHECK ((lat IS NULL AND lon IS NULL) OR
                       (lat IS NOT NULL AND lon IS NOT NULL AND lat BETWEEN -90 AND 90 AND lon BETWEEN -180 AND 180)),
                CHECK (active = 0 OR (lat IS NOT NULL AND lon IS NOT NULL))
            );
            CREATE TABLE IF NOT EXISTS geocode_cache (
                address TEXT PRIMARY KEY, result TEXT NOT NULL
            );
            CREATE TABLE IF NOT EXISTS rate_limits (
                key TEXT PRIMARY KEY, value REAL NOT NULL, count INTEGER NOT NULL DEFAULT 0
            );
            CREATE TABLE IF NOT EXISTS metadata (key TEXT PRIMARY KEY, value TEXT NOT NULL);
            PRAGMA user_version=1;
            COMMIT;
        """)
    finally:
        db.close()


def list_electricians(path, public=False):
    with connect(path) as db:
        where = "WHERE active = 1 AND lat IS NOT NULL AND lon IS NOT NULL" if public else ""
        return [dict(row) for row in db.execute(
            f"SELECT * FROM electricians {where} ORDER BY country, city COLLATE NOCASE, name COLLATE NOCASE"
        )]


def get_electrician(path, electrician_id):
    with connect(path) as db:
        row = db.execute("SELECT * FROM electricians WHERE id = ?", (electrician_id,)).fetchone()
        return dict(row) if row else None


def save_electrician(path, data, location, electrician_id=None, revision=None):
    columns = (*FIELDS, "lat", "lon", "location_source", "location_label", "active")
    values = [data[key] for key in FIELDS] + [
        location.get("lat"), location.get("lon"), location.get("source", ""),
        location.get("label", ""), int(data["active"]),
    ]
    with connect(path) as db:
        if electrician_id is None:
            # Never reuse a deleted ID: stale browser forms must not affect a new entry.
            db.execute("BEGIN IMMEDIATE")
            last_id = db.execute("SELECT value FROM metadata WHERE key = 'last_electrician_id'").fetchone()
            highest = db.execute("SELECT COALESCE(MAX(id), 0) FROM electricians").fetchone()[0]
            new_id = max(highest, int(last_id[0]) if last_id else 0) + 1
            db.execute("INSERT OR REPLACE INTO metadata VALUES ('last_electrician_id', ?)", (str(new_id),))
            placeholders = ", ".join("?" for _ in columns)
            return db.execute(
                f"INSERT INTO electricians (id, {', '.join(columns)}) VALUES (?, {placeholders})", [new_id] + values
            ).lastrowid
        cursor = db.execute(
            f"UPDATE electricians SET {', '.join(key + ' = ?' for key in columns)}, "
            "revision = revision + 1, updated_at = strftime('%Y-%m-%dT%H:%M:%SZ', 'now') "
            "WHERE id = ? AND revision = ?", values + [electrician_id, revision],
        )
        if cursor.rowcount != 1:
            raise EditConflict("Dieser Eintrag wurde inzwischen geändert. Bitte neu öffnen und Änderungen abgleichen.")
        return electrician_id


def set_active(path, electrician_id, revision, active):
    with connect(path) as db:
        cursor = db.execute(
            "UPDATE electricians SET active = ?, revision = revision + 1, "
            "updated_at = strftime('%Y-%m-%dT%H:%M:%SZ', 'now') "
            "WHERE id = ? AND revision = ? AND (? = 0 OR (lat IS NOT NULL AND lon IS NOT NULL))",
            (int(active), electrician_id, revision, int(active)),
        )
        if cursor.rowcount != 1:
            raise EditConflict("Eintrag wurde geändert oder hat keine Koordinaten. Bitte zuerst bearbeiten.")


def delete_electrician(path, electrician_id, revision):
    with connect(path) as db:
        db.execute("BEGIN IMMEDIATE")
        # Preserve the high-water mark for imported databases as well.
        last_id = db.execute("SELECT value FROM metadata WHERE key = 'last_electrician_id'").fetchone()
        highest = db.execute("SELECT COALESCE(MAX(id), 0) FROM electricians").fetchone()[0]
        db.execute("INSERT OR REPLACE INTO metadata VALUES ('last_electrician_id', ?)",
                   (str(max(highest, int(last_id[0]) if last_id else 0)),))
        cursor = db.execute("DELETE FROM electricians WHERE id = ? AND revision = ?", (electrician_id, revision))
        if cursor.rowcount != 1:
            raise EditConflict("Eintrag wurde inzwischen geändert oder gelöscht. Bitte neu öffnen.")


def reserve_login_attempt(path):
    """Global budget: works behind a unix-socket proxy and across workers/IPs."""
    now = time.time()
    with connect(path) as db:
        db.execute("BEGIN IMMEDIATE")
        row = db.execute("SELECT * FROM rate_limits WHERE key = 'admin-login'").fetchone()
        start, count = (row["value"], row["count"]) if row and now - row["value"] < 900 else (now, 0)
        if count >= 20:
            return max(1, int(900 - (now - start)))
        db.execute("INSERT OR REPLACE INTO rate_limits VALUES ('admin-login', ?, ?)", (start, count + 1))
    return 0
