"""Directory integration tests; all geocoding is mocked (no external requests)."""

import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import MagicMock, patch

from werkzeug.security import generate_password_hash

from app import app
import electrician_store as store
from electrician_geocoding import GeocodingError, geocode, lookup


class DirectoryTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.password_hash = generate_password_hash("test-password")

    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.path = Path(self.tmp.name) / "electricians.sqlite3"
        store.initialize(self.path)
        original_config = app.config.copy()
        self.addCleanup(lambda: app.config.update(original_config))
        app.config.update(TESTING=True, ELECTRICIANS_DB=str(self.path),
                          SECRET_KEY="test-secret", ADMIN_PASSWORD_HASH=self.password_hash,
                          SESSION_COOKIE_SECURE=False)
        self.client = app.test_client()
        self.data = dict(name="Test Elektrik", street="Teststraße 1", postal_code="01234",
                         city="Teststadt", country="DE", phone="0123 4567", email="info@example.org",
                         website="https://example.org", active=True)
        self.location = dict(lat=51.1, lon=13.2, source="address", label="Teststraße 1")

    def token(self, client=None):
        with (client or self.client).session_transaction("/admin") as session:
            return session["admin_csrf"]

    def login(self, client=None):
        client = client or self.client
        self.assertEqual(client.get("/admin/login").status_code, 200)
        response = client.post("/admin/login", data={"csrf_token": self.token(client), "password": "test-password"})
        self.assertEqual(response.status_code, 302)
        self.assertEqual(client.get("/admin").status_code, 200)

    def post(self, url, **overrides):
        values = {**self.data, "active": "1", "csrf_token": self.token(), "action": "save", **overrides}
        return self.client.post(url, data=values)

    def seed(self):
        return store.save_electrician(self.path, self.data, self.location)

    def test_authentication_csrf_logout_and_password_rotation(self):
        self.assertEqual(self.client.get("/admin").status_code, 302)
        self.assertEqual(self.client.post("/admin/electricians/new", data=self.data).status_code, 302)
        self.assertEqual(self.client.post("/admin/login", data={"password": "test-password"}).status_code, 400)
        self.client.get("/admin/login")
        response = self.client.post("/admin/login", data={"csrf_token": self.token(), "password": "wrong"})
        self.assertEqual(response.status_code, 401)
        self.login()
        self.assertEqual(self.client.post("/admin/electricians/new", data=self.data).status_code, 400)
        response = self.client.get("/admin")
        self.assertEqual(response.headers["Cache-Control"], "no-store")
        self.assertEqual(response.headers["X-Frame-Options"], "DENY")
        app.config["ADMIN_PASSWORD_HASH"] += "changed"
        self.assertEqual(self.client.get("/admin").status_code, 302)
        app.config["ADMIN_PASSWORD_HASH"] = self.password_hash
        self.assertEqual(self.client.post("/admin/logout", data={"csrf_token": self.token()}).status_code, 302)
        self.assertEqual(self.client.get("/admin").status_code, 302)

    def test_login_throttle_shared_by_clients(self):
        self.client.get("/admin/login")
        with patch("electrician_admin.check_password_hash", return_value=False):
            for _ in range(20):
                self.assertEqual(self.client.post("/admin/login", data={"csrf_token": self.token(), "password": "x"}).status_code, 401)
            other = app.test_client()
            other.get("/admin/login")
            response = other.post("/admin/login", data={"csrf_token": self.token(other), "password": "x"})
            self.assertEqual(response.status_code, 429)
            self.assertIn("Retry-After", response.headers)

    def test_unconfigured_admin_is_disabled(self):
        app.config["SECRET_KEY"] = None
        self.assertEqual(self.client.get("/admin").status_code, 503)
        self.assertEqual(self.client.get("/admin/login").status_code, 503)

    def test_create_contact_edit_address_edit_and_public_visibility(self):
        self.login()
        with patch("electrician_admin.geocode", return_value=self.location) as lookup:
            self.assertEqual(self.post("/admin/electricians/new").status_code, 302)
            lookup.assert_called_once()
        row = store.list_electricians(self.path)[0]
        self.assertEqual(row["postal_code"], "01234")
        for url in ("/de/elektriker-finden", "/en/find-electrician"):
            self.assertIn(b"Test Elektrik", self.client.get(url).data)
        url = f"/admin/electricians/{row['id']}"
        self.assertEqual(self.client.get(url).status_code, 200)
        with patch("electrician_admin.geocode") as lookup:
            self.assertEqual(self.post(url, revision="1", phone="98765").status_code, 302)
            lookup.assert_not_called()
        self.assertEqual(store.get_electrician(self.path, row["id"])["lat"], 51.1)
        new_location = {**self.location, "lat": 52.2}
        with patch("electrician_admin.geocode", return_value=new_location) as lookup:
            self.assertEqual(self.post(url, revision="2", street="Andere Straße 2").status_code, 302)
            lookup.assert_called_once()
        updated = store.get_electrician(self.path, row["id"])
        self.assertEqual(updated["lat"], 52.2)
        self.assertEqual(updated["street"], "Andere Straße 2")
        self.assertEqual(updated["id"], row["id"])
        self.client.post(url + "/active", data={"csrf_token": self.token(), "revision": "3", "active": "0"})
        self.assertNotIn(b"Test Elektrik", self.client.get("/en/find-electrician").data)
        self.client.post(url + "/active", data={"csrf_token": self.token(), "revision": "4", "active": "1"})
        self.assertIn(b"Test Elektrik", self.client.get("/en/find-electrician").data)

    def test_failed_geocoding_keeps_form_and_published_record(self):
        electrician_id = self.seed()
        self.login()
        with patch("electrician_admin.geocode", side_effect=GeocodingError("Adresse nicht gefunden")):
            response = self.post(f"/admin/electricians/{electrician_id}", revision="1", street="Missing 123")
        self.assertEqual(response.status_code, 400)
        self.assertIn(b"Missing 123", response.data)
        self.assertIn(b"Adresse nicht gefunden", response.data)
        row = store.get_electrician(self.path, electrician_id)
        self.assertEqual(row["street"], self.data["street"])
        self.assertEqual(row["lat"], self.location["lat"])
        self.assertEqual(row["revision"], 1)

    def test_database_write_failure_keeps_form(self):
        electrician_id = self.seed()
        self.login()
        with patch("electrician_admin.store.save_electrician", side_effect=store.sqlite3.OperationalError("locked")):
            response = self.post(f"/admin/electricians/{electrician_id}", revision="1", name="Unsaved name")
        self.assertEqual(response.status_code, 503)
        self.assertIn(b"Unsaved name", response.data)
        self.assertEqual(store.get_electrician(self.path, electrician_id)["name"], "Test Elektrik")

    def test_approximate_preview_signed_and_bound_to_address(self):
        from html.parser import HTMLParser

        class TokenParser(HTMLParser):
            token = ""

            def handle_starttag(self, tag, attrs):
                attrs = dict(attrs)
                if tag == "input" and attrs.get("name") == "location_token":
                    self.token = attrs["value"]

        self.login()
        approx = {**self.location, "source": "approximate"}
        with patch("electrician_admin.geocode", return_value=approx):
            response = self.post("/admin/electricians/new")
        self.assertEqual(response.status_code, 200)
        self.assertEqual(store.list_electricians(self.path), [])
        parser = TokenParser()
        parser.feed(response.get_data(as_text=True))
        self.assertTrue(parser.token)
        # An address change invalidates even an authentic preview token.
        with patch("electrician_admin.geocode", side_effect=GeocodingError("not found")) as lookup:
            response = self.post("/admin/electricians/new", street="Other 2", location_token=parser.token)
            self.assertEqual(response.status_code, 400)
            lookup.assert_called_once()
        # Reusing the preview for its original address does not hit the network.
        with patch("electrician_admin.geocode") as lookup:
            self.assertEqual(self.post("/admin/electricians/new", location_token=parser.token).status_code, 302)
            lookup.assert_not_called()
        self.assertEqual(store.list_electricians(self.path)[0]["location_source"], "approximate")

    def test_refresh_and_manual_override(self):
        electrician_id = self.seed()
        self.login()
        url = f"/admin/electricians/{electrician_id}"
        with patch("electrician_admin.geocode", return_value={**self.location, "lat": 50.0}) as lookup:
            self.assertEqual(self.post(url, revision="1", action="locate").status_code, 200)
            self.assertTrue(lookup.call_args.kwargs["refresh"])
        self.assertEqual(store.get_electrician(self.path, electrician_id)["lat"], 51.1)
        with patch("electrician_admin.geocode") as lookup:
            self.assertEqual(self.post(url, revision="1", manual="1", lat="50.12", lon="12.34").status_code, 302)
            lookup.assert_not_called()
        self.assertEqual(store.get_electrician(self.path, electrician_id)["location_source"], "manual")
        self.assertEqual(self.post(url, revision="2", manual="1", lat="nan", lon="12").status_code, 400)

    def test_validation_and_concurrent_edits(self):
        electrician_id = self.seed()
        self.login()
        url = f"/admin/electricians/{electrician_id}"
        for values in ({"website": "javascript:alert(1)"}, {"postal_code": "1234"},
                       {"email": "bad"}, {"name": ""}, {"country": "US"}):
            self.assertEqual(self.post(url, revision="1", **values).status_code, 400)
        with patch("electrician_admin.geocode") as lookup:
            self.assertEqual(self.post(url, revision="1", name="New name").status_code, 302)
            self.assertEqual(self.post(url, revision="1", name="Stale edit").status_code, 409)
            lookup.assert_not_called()
        self.assertEqual(store.get_electrician(self.path, electrician_id)["name"], "New name")
        with self.assertRaises(store.EditConflict):
            store.save_electrician(self.path, self.data, self.location, electrician_id, 1)

    def test_sqlite_cache_refresh_fallback_and_shared_throttle(self):
        with patch("electrician_geocoding.lookup", return_value=self.location) as lookup, patch("electrician_geocoding.time.sleep"):
            self.assertEqual(geocode(self.path, self.data)["lat"], 51.1)
            geocode(self.path, self.data)
            self.assertEqual(lookup.call_count, 1)
            geocode(self.path, self.data, refresh=True)
            self.assertEqual(lookup.call_count, 2)
        with store.connect(self.path) as db:
            db.execute("DELETE FROM rate_limits")
        with patch("electrician_geocoding.lookup", side_effect=[None, self.location]), patch("electrician_geocoding.time.sleep") as sleep:
            result = geocode(self.path, {**self.data, "street": "Another 2"})
            self.assertEqual(result["source"], "approximate")
            self.assertGreater(sleep.call_args.args[0], 0)
        with store.connect(self.path) as db:
            db.execute("UPDATE rate_limits SET value = 99999999999 WHERE key = 'geocoding'")
        with patch("electrician_geocoding.lookup") as lookup:
            with self.assertRaises(GeocodingError):
                geocode(self.path, self.data, refresh=True)
            lookup.assert_not_called()

    def test_nominatim_precision_and_network_errors(self):
        response = MagicMock()
        response.__enter__.return_value = response
        with patch("electrician_geocoding.urllib.request.urlopen", return_value=response):
            for address, source in (({}, "approximate"), ({"house_number": "1"}, "address")):
                response.read.return_value = json.dumps([{
                    "lat": "51.1", "lon": "13.2", "address": address, "display_name": "Test address",
                }]).encode()
                self.assertEqual(lookup("Test address", "DE")["source"], source)
            for body in (b'{}', b'[{"lat": "nan", "lon": 1}]', b'null', b'broken'):
                response.read.return_value = body
                with self.assertRaises(GeocodingError):
                    lookup("Test address", "DE")
        with patch("electrician_geocoding.urllib.request.urlopen", side_effect=TimeoutError):
            with self.assertRaises(GeocodingError):
                lookup("Test address", "DE")

    def test_initialization_preserves_entries_and_backup(self):
        self.seed()
        store.save_electrician(self.path, {**self.data, "name": "Inactive", "active": False}, {})
        self.assertEqual(len(store.list_electricians(self.path, public=True)), 1)
        self.assertEqual(store.list_electricians(self.path, public=True)[0]["postal_code"], "01234")
        store.initialize(self.path)
        self.assertEqual(len(store.list_electricians(self.path)), 2)
        destination = Path(self.tmp.name) / "backup.sqlite3"
        result = app.test_cli_runner().invoke(args=["electricians-backup", str(destination)])
        self.assertEqual(result.exit_code, 0, result.output)
        self.assertEqual(store.list_electricians(destination), store.list_electricians(self.path))

    def test_missing_database_does_not_create_empty_directory(self):
        missing = Path(self.tmp.name) / "missing.sqlite3"
        app.config["ELECTRICIANS_DB"] = str(missing)
        self.assertEqual(self.client.get("/en/find-electrician").status_code, 503)
        self.assertFalse(missing.exists())

    def test_delete_requires_login_csrf_and_current_revision(self):
        electrician_id = self.seed()
        url = f"/admin/electricians/{electrician_id}/delete"
        self.assertEqual(self.client.post(url, data={"revision": "1"}).status_code, 302)
        self.assertIsNotNone(store.get_electrician(self.path, electrician_id))
        self.login()
        self.assertEqual(self.client.get(url).status_code, 404)
        self.assertIsNotNone(store.get_electrician(self.path, electrician_id))
        self.assertEqual(self.client.post(url, data={"revision": "1"}).status_code, 400)
        store.save_electrician(self.path, self.data, self.location, electrician_id, 1)
        self.client.post(url, data={"csrf_token": self.token(), "revision": "1"})
        self.assertIsNotNone(store.get_electrician(self.path, electrician_id))
        response = self.client.post(url, data={"csrf_token": self.token(), "revision": "2"}, follow_redirects=True)
        self.assertEqual(response.status_code, 200)
        self.assertIsNone(store.get_electrician(self.path, electrician_id))
        self.assertNotIn(b"Test Elektrik", response.data)
        for page in ("/de/elektriker-finden", "/en/find-electrician"):
            self.assertNotIn(b"Test Elektrik", self.client.get(page).data)
        replacement_id = self.seed()
        self.assertGreater(replacement_id, electrician_id)
        self.client.post(url, data={"csrf_token": self.token(), "revision": "1"})
        self.assertIsNotNone(store.get_electrician(self.path, replacement_id))

    def test_deleted_imported_ids_are_not_reused(self):
        with store.connect(self.path) as db:
            db.execute(
                "INSERT INTO electricians (id, name, street, postal_code, city, country, phone, email, website) "
                "VALUES (144, 'Imported', '', '', '', 'DE', '', '', '')"
            )
        store.delete_electrician(self.path, 144, 1)
        self.assertEqual(self.seed(), 145)


if __name__ == "__main__":
    unittest.main()
