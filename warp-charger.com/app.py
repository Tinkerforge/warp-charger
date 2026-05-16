#!/usr/bin/env -S python3 -u

import json
import re
from pathlib import Path
from datetime import date
from markupsafe import Markup
from flask import Flask, render_template, abort, redirect, request, url_for, send_from_directory
from flask_flatpages import FlatPages
from translations import get_translation, SUPPORTED_LANGUAGES, DEFAULT_LANGUAGE
from firmwares import get_all_firmwares

app = Flask(__name__, static_folder="static")

# Flask-FlatPages configuration
app.config["FLATPAGES_ROOT"] = "blog"
app.config["FLATPAGES_EXTENSION"] = ".md"
app.config["FLATPAGES_MARKDOWN_EXTENSIONS"] = ["extra"]

flatpages = FlatPages(app)


# Page slug mappings per language: slug -> template
PAGES = {
    "de": {
        "produkte/warp4-charger": "pages/products/warp4-charger.html",
        "produkte/warp-ladesaeule": "pages/products/warp-charging-station.html",
        "produkte/warp-energy-manager": "pages/products/warp-energy-manager.html",
        "software/webinterface": "pages/software/webinterface.html",
        "software/apps": "pages/software/apps.html",
        "software/api-schnittstellen": "pages/software/api.html",
        "software/downloads": "pages/software/downloads.html",
        "loesungen/pv-ueberschussladen": "pages/solutions/pv-surplus-charging.html",
        "loesungen/dynamische-strompreise": "pages/solutions/dynamic-electricity-prices.html",
        "loesungen/lastmanagement": "pages/solutions/load-management.html",
        "loesungen/14a-enwg": "pages/solutions/14a-enwg.html",
        "loesungen/dienstwagenabrechnung": "pages/solutions/company-car-billing.html",
        "loesungen/foerderung-mehrparteienhaus": "pages/solutions/multi-dwelling-subsidy.html",
        "loesungen/maximale-kompatibilitaet": "pages/solutions/maximum-compatibility.html",
        "loesungen/bidirektionales-laden": "pages/solutions/bidirectional-charging.html",
        "warp-fuer/elektriker": "pages/for/electricians.html",
        "warp-fuer/architekten": "pages/for/architects.html",
        "warp-fuer/nerds": "pages/for/nerds.html",
        "warp-fuer/zu-hause": "pages/for/home.html",
        "warp-fuer/firmen": "pages/for/businesses.html",
        "ueber-uns/unternehmen": "pages/about/company.html",
        "ueber-uns/kontakt": "pages/about/contact.html",
    },
    "en": {
        "products/warp4-charger": "pages/products/warp4-charger.html",
        "products/warp-charging-station": "pages/products/warp-charging-station.html",
        "products/warp-energy-manager": "pages/products/warp-energy-manager.html",
        "software/web-interface": "pages/software/webinterface.html",
        "software/apps": "pages/software/apps.html",
        "software/api-interfaces": "pages/software/api.html",
        "software/downloads": "pages/software/downloads.html",
        "solutions/pv-surplus-charging": "pages/solutions/pv-surplus-charging.html",
        "solutions/dynamic-electricity-prices": "pages/solutions/dynamic-electricity-prices.html",
        "solutions/load-management": "pages/solutions/load-management.html",
        "solutions/14a-enwg": "pages/solutions/14a-enwg.html",
        "solutions/company-car-billing": "pages/solutions/company-car-billing.html",
        "solutions/multi-dwelling-subsidy": "pages/solutions/multi-dwelling-subsidy.html",
        "solutions/maximum-compatibility": "pages/solutions/maximum-compatibility.html",
        "solutions/bidirectional-charging": "pages/solutions/bidirectional-charging.html",
        "warp-for/electricians": "pages/for/electricians.html",
        "warp-for/architects": "pages/for/architects.html",
        "warp-for/nerds": "pages/for/nerds.html",
        "warp-for/home": "pages/for/home.html",
        "warp-for/businesses": "pages/for/businesses.html",
        "about/company": "pages/about/company.html",
        "about/contact": "pages/about/contact.html",
    },
}

# Build SLUG_ALTERNATES: maps (lang, slug) -> (other_lang, other_slug)
# Based on shared template paths
SLUG_ALTERNATES = {}
_template_to_slug = {}
for lang, slugs in PAGES.items():
    for slug, template in slugs.items():
        _template_to_slug.setdefault(template, {})[lang] = slug

for template, lang_slugs in _template_to_slug.items():
    for lang, slug in lang_slugs.items():
        for other_lang, other_slug in lang_slugs.items():
            if other_lang != lang:
                SLUG_ALTERNATES[(lang, slug)] = (other_lang, other_slug)

# Build reverse lookup: for any slug (regardless of language), find which lang it belongs to
_all_slugs = {}  # slug -> lang
for lang, slugs in PAGES.items():
    for slug in slugs:
        _all_slugs[slug] = lang


# Navigation link structure per language (used by header/footer/mobile_menu templates)
NAV_LINKS = {
    "de": {
        "products": [
            ("produkte/warp4-charger", "WARP4 Charger"),
            ("produkte/warp-ladesaeule", "WARP Ladesäule"),
            ("produkte/warp-energy-manager", "WARP Energy Manager 2.0"),
        ],
        "software": [
            ("software/webinterface", "Lokales Webinterface"),
            ("software/apps", "Android/iOS Apps"),
            ("software/api-schnittstellen", "API/Schnittstellen"),
        ],
        "software_automation": [
            ("https://docs.warp-charger.com/de/docs/smart_home/evcc", "EVCC"),
            ("https://docs.warp-charger.com/de/docs/smart_home/home_assistant", "Home Assistant"),
        ],
        "solutions_energy": [
            ("loesungen/pv-ueberschussladen", "PV-Überschussnutzung"),
            ("loesungen/dynamische-strompreise", "Dynamische Strompreise"),
            ("loesungen/lastmanagement", "Lastmanagement"),
            ("loesungen/maximale-kompatibilitaet", "Maximale Kompatibilität"),
            ("loesungen/bidirektionales-laden", "Bidirektionales Laden"),
        ],
        "solutions_compliance": [
            ("loesungen/14a-enwg", "§14a EnWG"),
            ("loesungen/dienstwagenabrechnung", "Dienstwagenabrechnung"),
            ("loesungen/foerderung-mehrparteienhaus", "Förderung Mehrparteienhaus"),
        ],
        "warp_for": [
            ("warp-fuer/elektriker", "Elektriker"),
            ("warp-fuer/architekten", "Architekten"),
            ("warp-fuer/nerds", "Nerds"),
            ("warp-fuer/zu-hause", "zu Hause"),
            ("warp-fuer/firmen", "Firmen"),
        ],
        "about": [
            ("ueber-uns/unternehmen", "Unternehmen"),
            ("https://www.tinkerunity.org/", "Community"),
            ("blog", "Neuigkeiten"),
            ("ueber-uns/unternehmen#contact", "Kontakt"),
        ],
    },
    "en": {
        "products": [
            ("products/warp4-charger", "WARP4 Charger"),
            ("products/warp-charging-station", "WARP Charging Station"),
            ("products/warp-energy-manager", "WARP Energy Manager 2.0"),
        ],
        "software": [
            ("software/web-interface", "Local Web Interface"),
            ("software/apps", "Android/iOS Apps"),
            ("software/api-interfaces", "API/Interfaces"),
        ],
        "software_automation": [
            ("https://docs.warp-charger.com/en/docs/smart_home/evcc", "EVCC"),
            ("https://docs.warp-charger.com/en/docs/smart_home/home_assistant", "Home Assistant"),
        ],
        "solutions_energy": [
            ("solutions/pv-surplus-charging", "PV Surplus Charging"),
            ("solutions/dynamic-electricity-prices", "Dynamic Electricity Prices"),
            ("solutions/load-management", "Load Management"),
            ("solutions/maximum-compatibility", "Maximum Compatibility"),
            ("solutions/bidirectional-charging", "Bidirectional Charging"),
        ],
        "solutions_compliance": [
            ("solutions/14a-enwg", "§14a EnWG"),
            ("solutions/company-car-billing", "Company Car Billing"),
            ("solutions/multi-dwelling-subsidy", "Multi-dwelling Subsidy"),
        ],
        "warp_for": [
            ("warp-for/electricians", "Electricians"),
            ("warp-for/architects", "Architects"),
            ("warp-for/nerds", "Nerds"),
            ("warp-for/home", "Home"),
            ("warp-for/businesses", "Businesses"),
        ],
        "about": [
            ("about/company", "Company"),
            ("https://www.tinkerunity.org/", "Community"),
            ("blog", "News"),
            ("about/company#contact", "Contact"),
        ],
    },
}


def get_posts(lang=None, limit=None):
    """Return blog posts sorted by date (newest first), filtered by language."""
    posts = [p for p in flatpages if p.path.startswith(f"{lang}/")]  if lang else list(flatpages)
    posts.sort(key=lambda p: p.meta.get("date", date.min), reverse=True)
    if limit:
        posts = posts[:limit]
    return posts


def get_alternate_urls(lang, slug=None):
    """Get URLs for both languages for the current page."""
    other_lang = "en" if lang == "de" else "de"
    current_url = f"/{lang}/"
    other_url = f"/{other_lang}/"

    if slug is not None:
        current_url = f"/{lang}/{slug}"
        alt = SLUG_ALTERNATES.get((lang, slug))
        if alt:
            other_url = f"/{alt[0]}/{alt[1]}"

    return {
        "de": current_url if lang == "de" else other_url,
        "en": current_url if lang == "en" else other_url,
    }


def make_template_context(lang, section_name=None, page_slug=None):
    """Build the common template context for a given language."""
    nav_t = get_translation(lang, "nav")
    meta_t = get_translation(lang, "meta")
    footer_t = get_translation(lang, "footer")

    lang_urls = get_alternate_urls(lang, page_slug)
    other_lang = "en" if lang == "de" else "de"

    return {
        "lang": lang,
        "other_lang": other_lang,
        "nav": nav_t,
        "meta": meta_t,
        "footer": footer_t,
        "nav_links": NAV_LINKS[lang],
        "lang_urls": lang_urls,
        "alternate_url": lang_urls[other_lang],
    }


@app.template_filter("timeago")
def timeago_filter(value):
    """Convert a date to a relative time string."""
    if not isinstance(value, date):
        return str(value)
    today = date.today()
    delta = today - value
    days = delta.days

    # Get current language from request context
    lang = getattr(request, "_i18n_lang", "de")

    if lang == "en":
        if days < 0:
            return "in the future"
        if days == 0:
            return "today"
        if days == 1:
            return "yesterday"
        if days < 7:
            return f"{days} days ago"
        weeks = days // 7
        months = days // 30
        years = days // 365
        if years > 0:
            remaining_months = (days - years * 365) // 30
            if remaining_months > 0:
                return f"{years} {'year' if years == 1 else 'years'}, {remaining_months} {'month' if remaining_months == 1 else 'months'} ago"
            return f"{years} {'year' if years == 1 else 'years'} ago"
        if months > 0:
            remaining_weeks = (days - months * 30) // 7
            if remaining_weeks > 0:
                return f"{months} {'month' if months == 1 else 'months'}, {remaining_weeks} {'week' if remaining_weeks == 1 else 'weeks'} ago"
            return f"{months} {'month' if months == 1 else 'months'} ago"
        return f"{weeks} {'week' if weeks == 1 else 'weeks'} ago"
    else:
        if days < 0:
            return "in der Zukunft"
        if days == 0:
            return "heute"
        if days == 1:
            return "gestern"
        if days < 7:
            return f"vor {days} Tagen"
        weeks = days // 7
        months = days // 30
        years = days // 365
        if years > 0:
            remaining_months = (days - years * 365) // 30
            if remaining_months > 0:
                return f"{years} {'Jahr' if years == 1 else 'Jahre'}, {remaining_months} {'Monat' if remaining_months == 1 else 'Monate'} her"
            return f"vor {years} {'Jahr' if years == 1 else 'Jahren'}"
        if months > 0:
            remaining_weeks = (days - months * 30) // 7
            if remaining_weeks > 0:
                return f"{months} {'Monat' if months == 1 else 'Monate'}, {remaining_weeks} {'Woche' if remaining_weeks == 1 else 'Wochen'} her"
            return f"vor {months} {'Monat' if months == 1 else 'Monaten'}"
        return f"vor {weeks} {'Woche' if weeks == 1 else 'Wochen'}"


@app.template_filter("highlight_shell")
def highlight_shell_filter(code):
    """Syntax-highlight shell code using Pygments with inline styles."""
    from pygments import highlight
    from pygments.lexers import BashLexer
    from pygments.formatters import HtmlFormatter

    if not code:
        return code

    # noclasses=True -> inline styles; nowrap=True -> no wrapper <div>/<pre>
    formatter = HtmlFormatter(
        noclasses=True,
        nowrap=True,
        style="dracula",
    )
    result = highlight(str(code).rstrip(), BashLexer(), formatter)
    return Markup(result)


@app.template_filter("excerpt")
def excerpt_filter(markdown_body, length=300):
    """Return a plain text excerpt from Markdown, stripping images and links."""
    text = re.sub(r"!\[[^\]]*\]\([^)]*\)", "", markdown_body)
    text = re.sub(r"\[([^\]]*)\]\([^)]*\)", r"\1", text)
    text = re.sub(r"\n{2,}", " ", text).strip()
    text = re.sub(r"\s+", " ", text)
    if len(text) > length:
        text = text[:length] + "..."
    return text


def render_page(lang, page_slug, translation=None, **extra_ctx):
    """Helper to render a page with standard context and optional translation."""
    if lang not in SUPPORTED_LANGUAGES:
        abort(404)
    request._i18n_lang = lang
    template = PAGES[lang].get(page_slug)
    if not template:
        abort(404)
    ctx = make_template_context(lang, page_slug=page_slug)
    if translation:
        ctx["t"] = get_translation(lang, translation)
    ctx.update(extra_ctx)
    return render_template(template, **ctx)


# --- Routes ---

@app.route("/")
def root():
    """Detect Accept-Language and redirect to /de/ or /en/."""
    accept = request.headers.get("Accept-Language", "")
    if "de" in accept.split(",")[0].lower():
        return redirect("/de/", code=302)
    return redirect("/en/", code=302)


@app.route("/<lang>/")
def index(lang):
    """Render the full homepage."""
    if lang not in SUPPORTED_LANGUAGES:
        abort(404)
    request._i18n_lang = lang

    posts = get_posts(lang=lang, limit=3)
    ctx = make_template_context(lang)
    ctx["t"] = get_translation(lang, "index")
    ctx["posts"] = posts
    return render_template("index.html", **ctx)


@app.route("/<lang>/blog", strict_slashes=False)
def blog_index(lang):
    """Blog listing page."""
    if lang not in SUPPORTED_LANGUAGES:
        abort(404)
    request._i18n_lang = lang
    posts = get_posts(lang=lang)
    ctx = make_template_context(lang, page_slug="blog")
    ctx["t"] = get_translation(lang, "blog")
    ctx["posts"] = posts
    return render_template("pages/blog/index.html", **ctx)


@app.route("/<lang>/blog/<slug>")
def blog_post(lang, slug):
    """Single blog post page."""
    if lang not in SUPPORTED_LANGUAGES:
        abort(404)
    request._i18n_lang = lang
    post = next((p for p in flatpages if p.path.startswith(f"{lang}/") and p.meta.get("slug") == slug), None)
    if post is None:
        abort(404)
    ctx = make_template_context(lang)
    ctx["t"] = get_translation(lang, "blog")
    ctx["post"] = post
    ctx["posts"] = get_posts(lang=lang)
    ctx["active_slug"] = slug
    return render_template("pages/blog/post.html", **ctx)


# --- Dedicated page routes (pages with specific data needs) ---

@app.route("/de/software/downloads")
@app.route("/en/software/downloads")
def downloads():
    """Downloads page with firmware data."""
    lang = request.path.split("/")[1]
    return render_page(lang, "software/downloads",
                       translation="downloads", firmwares=get_all_firmwares(lang))


@app.route("/de/loesungen/dienstwagenabrechnung")
@app.route("/en/solutions/company-car-billing")
def company_car_billing():
    """Company car billing page (formerly charging log & billing)."""
    lang = request.path.split("/")[1]
    slug = "loesungen/dienstwagenabrechnung" if lang == "de" else "solutions/company-car-billing"
    return render_page(lang, slug, translation="company-car-billing")


@app.route("/de/loesungen/pv-ueberschussladen")
@app.route("/en/solutions/pv-surplus-charging")
def pv_surplus_charging():
    """PV surplus charging page."""
    lang = request.path.split("/")[1]
    slug = "loesungen/pv-ueberschussladen" if lang == "de" else "solutions/pv-surplus-charging"
    return render_page(lang, slug, translation="pv-surplus-charging")


@app.route("/de/loesungen/dynamische-strompreise")
@app.route("/en/solutions/dynamic-electricity-prices")
def dynamic_electricity_prices():
    """Dynamic electricity prices page."""
    lang = request.path.split("/")[1]
    slug = "loesungen/dynamische-strompreise" if lang == "de" else "solutions/dynamic-electricity-prices"
    return render_page(lang, slug, translation="dynamic-electricity-prices")


@app.route("/de/loesungen/lastmanagement")
@app.route("/en/solutions/load-management")
def load_management():
    """Load management page."""
    lang = request.path.split("/")[1]
    slug = "loesungen/lastmanagement" if lang == "de" else "solutions/load-management"
    return render_page(lang, slug, translation="load-management")


@app.route("/de/loesungen/14a-enwg")
@app.route("/en/solutions/14a-enwg")
def p14a_enwg():
    """§14a EnWG page."""
    lang = request.path.split("/")[1]
    slug = "loesungen/14a-enwg" if lang == "de" else "solutions/14a-enwg"
    return render_page(lang, slug, translation="14a-enwg")


@app.route("/de/loesungen/maximale-kompatibilitaet")
@app.route("/en/solutions/maximum-compatibility")
def maximum_compatibility():
    """Maximum compatibility page."""
    lang = request.path.split("/")[1]
    slug = "loesungen/maximale-kompatibilitaet" if lang == "de" else "solutions/maximum-compatibility"
    data_path = Path(__file__).parent / "data" / "compatible_devices.json"
    manufacturers = json.loads(data_path.read_text()) if data_path.exists() else []
    return render_page(lang, slug, translation="maximum-compatibility", manufacturers=manufacturers)


@app.route("/de/warp-fuer/elektriker")
@app.route("/en/warp-for/electricians")
def for_electricians():
    """WARP for Electricians page."""
    lang = request.path.split("/")[1]
    slug = "warp-fuer/elektriker" if lang == "de" else "warp-for/electricians"
    return render_page(lang, slug, translation="for-electricians")


@app.route("/de/warp-fuer/architekten")
@app.route("/en/warp-for/architects")
def for_architects():
    """WARP for Architects page."""
    lang = request.path.split("/")[1]
    slug = "warp-fuer/architekten" if lang == "de" else "warp-for/architects"
    return render_page(lang, slug, translation="for-architects")


@app.route("/de/warp-fuer/nerds")
@app.route("/en/warp-for/nerds")
def for_nerds():
    """WARP for Nerds page."""
    lang = request.path.split("/")[1]
    slug = "warp-fuer/nerds" if lang == "de" else "warp-for/nerds"
    return render_page(lang, slug, translation="for-nerds")


@app.route("/de/ueber-uns/unternehmen")
@app.route("/en/about/company")
def company():
    """Company / Über uns page."""
    lang = request.path.split("/")[1]
    slug = "ueber-uns/unternehmen" if lang == "de" else "about/company"
    return render_page(lang, slug, translation="company")


@app.route("/de/software/webinterface")
@app.route("/en/software/web-interface")
def webinterface():
    """Local web interface page."""
    lang = request.path.split("/")[1]
    slug = "software/webinterface" if lang == "de" else "software/web-interface"
    return render_page(lang, slug, translation="webinterface")


@app.route("/de/software/apps")
@app.route("/en/software/apps")
def apps():
    """Android/iOS Apps page."""
    lang = request.path.split("/")[1]
    return render_page(lang, "software/apps", translation="apps")


@app.route("/de/software/api-schnittstellen")
@app.route("/en/software/api-interfaces")
def api_interfaces():
    """API & Interfaces page."""
    lang = request.path.split("/")[1]
    slug = "software/api-schnittstellen" if lang == "de" else "software/api-interfaces"
    return render_page(lang, slug, translation="api")


# --- Firmware file downloads ---

FIRMWARES_DIR = Path(__file__).parent.parent / "firmwares"
DOCUMENTS_DIR = Path(__file__).parent.parent / "documents"


@app.route("/firmwares/<path:filename>")
def firmware_download(filename):
    """Serve firmware files from the shared firmwares directory."""
    return send_from_directory(FIRMWARES_DIR, filename)


@app.route("/documents/<path:filename>")
def document_download(filename):
    """Serve document files from the shared documents directory."""
    return send_from_directory(DOCUMENTS_DIR, filename)


# --- Redirects from old WordPress site URLs ---
# Note: Old homepage was completely german, so we redirect to german pages for all old URLs.
OLD_URL_MAP = {
    "/pv-ueberschussladen": "/de/loesungen/pv-ueberschussladen",
    "/dynamische-strompreise": "/de/loesungen/dynamische-strompreise",
    "/lastmanagement": "/de/loesungen/lastmanagement",
    "/§14a-enwg": "/de/loesungen/14a-enwg",
    "/%c2%a714a-enwg": "/de/loesungen/14a-enwg",
    "/%C2%A714a-enwg": "/de/loesungen/14a-enwg",
    "/ladelogbuch-und-abrechnung": "/de/loesungen/dienstwagenabrechnung",
    "/downloads": "/de/software/downloads",
    "/warp3-charger": "/de/produkte/warp4-charger",
    "/warp-energy-manager": "/de/produkte/warp-energy-manager",
    "/warp-energy-manager-2-0": "/de/produkte/warp-energy-manager",
    "/warp-ladesaeule": "/de/produkte/warp-ladesaeule",
    # Old firmware link redirect
    "/documentation/api.html": "https://docs.warp-charger.com/de/docs/interfaces/mqtt_http/introduction/",
}


@app.before_request
def redirect_old_urls():
    """Redirect old WordPress URLs to new site (301 permanent)."""
    path = request.path.rstrip("/")
    if not path:
        return None
    target = OLD_URL_MAP.get(path)
    if target:
        return redirect(target, code=301)

@app.route("/<lang>/<path:page_path>")
def page(lang, page_path):
    """Render a sub-page, with cross-language redirect support."""
    if lang not in SUPPORTED_LANGUAGES:
        abort(404)

    request._i18n_lang = lang

    if page_path in PAGES[lang]:
        template = PAGES[lang][page_path]
        ctx = make_template_context(lang, page_slug=page_path)
        return render_template(template, **ctx)

    # Cross-language redirect: slug belongs to another language
    # Find if this slug exists in any other language and redirect to correct slug
    if page_path in _all_slugs:
        source_lang = _all_slugs[page_path]
        if source_lang != lang:
            # Find the equivalent slug in the requested language
            alt = SLUG_ALTERNATES.get((source_lang, page_path))
            if alt and alt[0] == lang:
                return redirect(f"/{lang}/{alt[1]}", code=301)

    abort(404)


@app.errorhandler(404)
def page_not_found(e):
    """Render localized 404 page."""
    # Try to determine language from URL
    path = request.path
    lang = DEFAULT_LANGUAGE
    for supported_lang in SUPPORTED_LANGUAGES:
        if path.startswith(f"/{supported_lang}/"):
            lang = supported_lang
            break

    t404 = get_translation(lang, "404")
    ctx = make_template_context(lang)
    ctx["t"] = t404
    return render_template("pages/404.html", **ctx), 404


@app.route("/sitemap.xml")
def sitemap():
    """Generate sitemap with hreflang alternates."""
    base_url = request.host_url.rstrip("/")
    pages_list = []

    # Homepage
    pages_list.append({
        "urls": {lang: f"{base_url}/{lang}/" for lang in SUPPORTED_LANGUAGES}
    })

    # All pages
    for template, lang_slugs in _template_to_slug.items():
        urls = {}
        for lang, slug in lang_slugs.items():
            urls[lang] = f"{base_url}/{lang}/{slug}"
        pages_list.append({"urls": urls})

    xml = render_template("sitemap.xml", pages=pages_list, languages=SUPPORTED_LANGUAGES)
    return xml, 200, {"Content-Type": "application/xml"}


if __name__ == "__main__":
    import os
    import socket
    import shutil
    import subprocess

    DEFAULT_PORT = 5000
    port = int(os.environ.get('PORT', DEFAULT_PORT))

    # Only scan for a free port in the main process, not in the
    # reloader child (which inherits PORT via the environment).
    if not os.environ.get('WERKZEUG_RUN_MAIN'):
        while True:
            try:
                s = socket.socket(socket.AF_INET6, socket.SOCK_STREAM)
                s.bind(('::', port))
                s.close()
                break
            except OSError:
                print(f"Port {port} already in use, trying {port + 1}")
                port += 1
        os.environ['PORT'] = str(port)
        print(f" * Running on http://localhost:{port}/")

    # Auto-start Tailwind CSS watcher if npx is available
    css_process = None
    ts_process = None
    if shutil.which("npx"):
        try:
            css_process = subprocess.Popen(
                ["npx", "@tailwindcss/cli", "-i", "./src/input.css",
                 "-o", "./static/css/output.min.css", "--watch", "--minify"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.PIPE,
            )
            print(" * Tailwind CSS watcher started (PID %d)" % css_process.pid)
        except Exception as e:
            print(" * Could not start Tailwind CSS watcher: %s" % e)

        try:
            ts_process = subprocess.Popen(
                ["npx", "esbuild", "src/ts/index.ts", "--bundle",
                 "--outfile=static/js/output.min.js", "--format=iife", "--watch"],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.PIPE,
            )
            print(" * TypeScript watcher started (PID %d)" % ts_process.pid)
        except Exception as e:
            print(" * Could not start TypeScript watcher: %s" % e)

    try:
        app.run(debug=True, host="0.0.0.0", port=port)
    finally:
        if css_process:
            css_process.terminate()
            css_process.wait()
        if ts_process:
            ts_process.terminate()
            ts_process.wait()
