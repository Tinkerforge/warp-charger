"""Translation loading system for i18n support."""

import os
import yaml

TRANSLATIONS_DIR = os.path.join(os.path.dirname(__file__))
SUPPORTED_LANGUAGES = ["de", "en"]
DEFAULT_LANGUAGE = "de"

_cache = {}
_mtimes = {}


def load_translation(lang, name):
    """Load a translation file and return its dict. Reloads if file changed."""
    key = (lang, name)
    path = os.path.join(TRANSLATIONS_DIR, lang, f"{name}.yaml")
    if os.path.exists(path):
        mtime = os.path.getmtime(path)
        if key not in _cache or _mtimes.get(key) != mtime:
            with open(path, "r", encoding="utf-8") as f:
                _cache[key] = yaml.safe_load(f) or {}
            _mtimes[key] = mtime
    elif key not in _cache:
        _cache[key] = {}
    return _cache[key]


def clear_cache():
    """Clear translation cache (useful in development)."""
    _cache.clear()


class TranslationDict(dict):
    """A dict subclass that returns key name on missing keys for easier debugging."""

    def __getattr__(self, name):
        try:
            return self[name]
        except KeyError:
            return f"[MISSING: {name}]"

    def __getitem__(self, key):
        try:
            return super().__getitem__(key)
        except KeyError:
            return f"[MISSING: {key}]"


def get_translation(lang, name):
    """Get a TranslationDict for a given language and section/page name."""
    data = load_translation(lang, name)
    return TranslationDict(data)
