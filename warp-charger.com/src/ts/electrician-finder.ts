// Electrician finder: self-hosted MapLibre GL + PMTiles map with native
// clustering, plus a postal-code search that ranks the installer list by
// distance. Loaded only on the find-an-electrician page (separate bundle).
//
// All map assets (style, tiles, glyphs) are served from our own origin.

import "maplibre-gl/dist/maplibre-gl.css";
import "./electrician-finder.css";
import maplibregl from "maplibre-gl";
import type {
    GeoJSONSource,
    Map as MlMap,
    MapLayerMouseEvent,
    Marker,
    Popup,
    StyleSpecification,
} from "maplibre-gl";
import { Protocol } from "pmtiles";
import type { FeatureCollection, Point } from "geojson";

const BRAND = "#2563eb";

interface Electrician {
    id: string;
    name: string;
    city: string;
    postalCode: string;
    phone: string;
    email: string;
    website: string;
    lat: number;
    lon: number;
    el: HTMLElement;
    badge: HTMLElement | null;
}

// --- Small helpers ---

function lngLat(lon: number, lat: number): [number, number] {
    return [lon, lat];
}

function haversineKm(aLat: number, aLon: number, bLat: number, bLon: number): number {
    const R = 6371;
    const dLat = ((bLat - aLat) * Math.PI) / 180;
    const dLon = ((bLon - aLon) * Math.PI) / 180;
    const la1 = (aLat * Math.PI) / 180;
    const la2 = (bLat * Math.PI) / 180;
    const h =
        Math.sin(dLat / 2) ** 2 +
        Math.cos(la1) * Math.cos(la2) * Math.sin(dLon / 2) ** 2;
    return 2 * R * Math.asin(Math.sqrt(h));
}

function formatKm(km: number): string {
    return km >= 10 ? Math.round(km).toString() : km.toFixed(1);
}

const ESCAPE: Record<string, string> = {
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': "&quot;",
    "'": "&#39;",
};

function escapeHtml(s: string): string {
    return s.replace(/[&<>"']/g, (c) => ESCAPE[c] ?? c);
}

// Strip protocol and a trailing slash for a tidy website label (the full URL
// is still used for the href).
function prettyHost(url: string): string {
    return url.replace(/^https?:\/\//i, "").replace(/\/+$/, "");
}

// A minimal background-only style used when the real style.json cannot be
// loaded, so the markers still render on a plain canvas (graceful degradation).
function blankStyle(glyphs: string): StyleSpecification {
    return {
        version: 8,
        glyphs,
        sources: {},
        layers: [
            {
                id: "background",
                type: "background",
                paint: { "background-color": "#eaf0f6" },
            },
        ],
    };
}

async function loadStyle(url: string, glyphs: string): Promise<StyleSpecification> {
    if (url) {
        try {
            const res = await fetch(url);
            if (res.ok) {
                return (await res.json()) as StyleSpecification;
            }
        } catch {
            // fall through to blank style
        }
    }
    return blankStyle(glyphs);
}

function init(): void {
    const mapEl = document.getElementById("ef-map");
    if (!mapEl) return; // not the finder page

    const listEl = document.getElementById("ef-list");
    const form = document.getElementById("ef-search") as HTMLFormElement | null;
    const countrySelect = document.getElementById("ef-country") as HTMLSelectElement | null;
    const plzInput = document.getElementById("ef-plz") as HTMLInputElement | null;
    const errorEl = document.getElementById("ef-search-error");
    const resetBtn = document.getElementById("ef-reset");
    const nearmeBtn = document.getElementById("ef-nearme") as HTMLButtonElement | null;
    const headingEl = document.getElementById("ef-results-heading");
    const countEl = document.getElementById("ef-results-count");

    // i18n + config read from data-* attributes (DOM is the source of truth).
    const ds = form?.dataset ?? ({} as DOMStringMap);
    const endpoint = ds.plzEndpoint ?? "/de/api/plz";
    const tNotFound = ds.i18nNotfound ?? "No place found for that postal code.";
    const tNearMeError = ds.i18nNearmeerror ?? "Your location could not be determined.";
    const tNear = ds.i18nNear ?? "Near";
    const tAll = ds.i18nAll ?? "All installers";
    const tDistance = ds.i18nDistance ?? "km away";
    const tCountOne = ds.i18nCountone ?? "installer";
    const tCountOther = ds.i18nCountother ?? "installers";
    const tYourLocation = ds.i18nYourlocation ?? "your location";
    const tPhone = ds.i18nPhone ?? "Phone";
    const tEmail = ds.i18nEmail ?? "E-Mail";
    const tWebsite = ds.i18nWebsite ?? "Website";

    const styleUrl = mapEl.dataset.style ?? "";
    const centerLng = Number(mapEl.dataset.centerLng ?? "10.2");
    const centerLat = Number(mapEl.dataset.centerLat ?? "50.6");
    const zoom = Number(mapEl.dataset.zoom ?? "4.3");
    const attribution = mapEl.dataset.attribution ?? "";
    // Glyphs live next to the style under /static/tiles/fonts (handles any path prefix).
    const tilesBase = styleUrl.replace(/\/[^/]*$/, "") || "/static/tiles";
    const glyphsUrl = `${tilesBase}/fonts/{fontstack}/{range}.pbf`;

    // Build the electrician list straight from the rendered cards.
    const electricians: Electrician[] = Array.from(
        document.querySelectorAll<HTMLElement>(".ef-card"),
    )
        .map((el) => ({
            id: el.dataset.id ?? "",
            name: el.dataset.name ?? "",
            city: el.dataset.city ?? "",
            postalCode: el.dataset.postalCode ?? "",
            phone: el.dataset.phone ?? "",
            email: el.dataset.email ?? "",
            website: el.dataset.website ?? "",
            lat: Number(el.dataset.lat),
            lon: Number(el.dataset.lon),
            el,
            badge: el.querySelector<HTMLElement>(".ef-distance"),
        }))
        .filter((e) => Number.isFinite(e.lat) && Number.isFinite(e.lon));

    const originalOrder = [...electricians];

    let map: MlMap | null = null;
    let popup: Popup | null = null;
    let searchMarker: Marker | null = null;

    // --- DOM/list helpers (work with or without a map) ---

    function showError(msg: string): void {
        if (!errorEl) return;
        errorEl.textContent = msg;
        errorEl.classList.remove("hidden");
    }

    function hideError(): void {
        errorEl?.classList.add("hidden");
    }

    function selectCard(id: string): void {
        for (const e of electricians) {
            const active = e.id === id;
            e.el.classList.toggle("ef-card-active", active);
            if (active) e.el.scrollIntoView({ block: "nearest", behavior: "smooth" });
        }
    }

    function showPopup(e: Electrician): void {
        if (!map) return;
        popup?.remove();

        const rows: string[] = [];
        if (e.phone) {
            const tel = e.phone.replace(/\s+/g, "");
            rows.push(
                `<span class="ef-popup-label">${escapeHtml(tPhone)}:</span>` +
                    `<a href="tel:${escapeHtml(tel)}">${escapeHtml(e.phone)}</a>`,
            );
        }
        if (e.email) {
            rows.push(
                `<span class="ef-popup-label">${escapeHtml(tEmail)}:</span>` +
                    `<a href="mailto:${escapeHtml(e.email)}">${escapeHtml(e.email)}</a>`,
            );
        }
        if (e.website) {
            rows.push(
                `<span class="ef-popup-label">${escapeHtml(tWebsite)}:</span>` +
                    `<a href="${escapeHtml(e.website)}" target="_blank" rel="noopener noreferrer">` +
                    `${escapeHtml(prettyHost(e.website))}</a>`,
            );
        }

        const contact = rows.length ? `<div class="ef-popup-contact">${rows.join("")}</div>` : "";
        const location = [e.postalCode, e.city].filter(Boolean).join(" ");
        const html =
            `<strong>${escapeHtml(e.name)}</strong><br>${escapeHtml(location)}${contact}`;

        popup = new maplibregl.Popup({ offset: 14, closeButton: false, maxWidth: "320px" })
            .setLngLat(lngLat(e.lon, e.lat))
            .setHTML(html)
            .addTo(map);
    }

    function focusElectrician(e: Electrician): void {
        selectCard(e.id);
        if (map) {
            map.flyTo({ center: lngLat(e.lon, e.lat), zoom: Math.max(map.getZoom(), 9), speed: 1.2 });
            showPopup(e);
        }
    }

    function sortAndShow(lat: number, lon: number, heading: string): void {
        const ranked = electricians
            .map((e) => ({ e, km: haversineKm(lat, lon, e.lat, e.lon) }))
            .sort((a, b) => a.km - b.km);

        for (const { e, km } of ranked) {
            if (e.badge) {
                e.badge.textContent = `${formatKm(km)} ${tDistance}`;
                e.badge.classList.remove("hidden");
            }
            listEl?.appendChild(e.el); // moves the existing node -> reorders the list
        }

        if (headingEl) headingEl.textContent = heading;
        if (countEl) {
            const n = ranked.length;
            countEl.textContent = `${n} ${n === 1 ? tCountOne : tCountOther}`;
        }
        resetBtn?.classList.remove("hidden");

        if (map) {
            searchMarker?.remove();
            searchMarker = new maplibregl.Marker({ color: "#111111" })
                .setLngLat(lngLat(lon, lat))
                .addTo(map);
            const bounds = new maplibregl.LngLatBounds(lngLat(lon, lat), lngLat(lon, lat));
            for (const { e } of ranked.slice(0, 5)) bounds.extend(lngLat(e.lon, e.lat));
            map.fitBounds(bounds, { padding: 64, maxZoom: 11 });
        }

        const first = ranked[0];
        if (first) selectCard(first.e.id);
    }

    function resetView(): void {
        for (const e of originalOrder) {
            listEl?.appendChild(e.el);
            e.badge?.classList.add("hidden");
            e.el.classList.remove("ef-card-active");
        }
        if (headingEl) headingEl.textContent = tAll;
        if (countEl) countEl.textContent = `${electricians.length} ${tCountOther}`;
        resetBtn?.classList.add("hidden");
        if (plzInput) plzInput.value = "";
        hideError();
        searchMarker?.remove();
        searchMarker = null;
        popup?.remove();
        map?.flyTo({ center: lngLat(centerLng, centerLat), zoom });
    }

    // --- Wire up controls (independent of the map) ---

    form?.addEventListener("submit", (ev) => {
        ev.preventDefault();
        hideError();
        const code = plzInput?.value.trim() ?? "";
        if (!code) return;
        const country = countrySelect?.value ?? "DE";
        const url = `${endpoint}?country=${encodeURIComponent(country)}&code=${encodeURIComponent(code)}`;
        fetch(url)
            .then((res) => (res.ok ? res.json() : Promise.reject(new Error("not_found"))))
            .then((data: { ok: boolean; lat?: number; lon?: number; place?: string }) => {
                if (!data.ok || data.lat === undefined || data.lon === undefined) {
                    showError(tNotFound);
                    return;
                }
                sortAndShow(data.lat, data.lon, `${tNear} ${data.place ?? code}`);
            })
            .catch(() => showError(tNotFound));
    });

    nearmeBtn?.addEventListener("click", () => {
        if (!navigator.geolocation) {
            showError(tNearMeError);
            return;
        }
        nearmeBtn.disabled = true;
        navigator.geolocation.getCurrentPosition(
            (pos) => {
                nearmeBtn.disabled = false;
                hideError();
                sortAndShow(pos.coords.latitude, pos.coords.longitude, `${tNear} ${tYourLocation}`);
            },
            () => {
                nearmeBtn.disabled = false;
                showError(tNearMeError);
            },
            { enableHighAccuracy: false, timeout: 8000, maximumAge: 600000 },
        );
    });

    resetBtn?.addEventListener("click", resetView);

    for (const e of electricians) {
        e.el.addEventListener("click", (ev) => {
            if ((ev.target as HTMLElement).closest("a")) return; // let phone/mail/web links work
            focusElectrician(e);
        });
        e.el.addEventListener("keydown", (ev) => {
            if (ev.key !== "Enter" && ev.key !== " ") return;
            if ((ev.target as HTMLElement).closest("a")) return;
            ev.preventDefault();
            focusElectrician(e);
        });
    }

    // --- Create the map (gracefully degrade to the list if WebGL is missing) ---

    maplibregl.addProtocol("pmtiles", new Protocol().tile);

    const featureCollection: FeatureCollection<Point> = {
        type: "FeatureCollection",
        features: electricians.map((e) => ({
            type: "Feature",
            geometry: { type: "Point", coordinates: lngLat(e.lon, e.lat) },
            properties: { id: e.id, name: e.name, city: e.city },
        })),
    };

    loadStyle(styleUrl, glyphsUrl)
        .then((style) => {
            try {
                map = new maplibregl.Map({
                    container: mapEl,
                    style,
                    center: lngLat(centerLng, centerLat),
                    zoom,
                    minZoom: 4,
                    maxZoom: 16,
                    // Pin the viewport to the DACH region (DACH bbox plus a small
                    // margin) so users can't pan off to other countries or zoom
                    // out to the whole world. The dimmed mask reinforces this.
                    maxBounds: [
                        [3.5, 44.0],
                        [20.0, 56.5],
                    ],
                    attributionControl: false,
                });
            } catch {
                document.getElementById("ef-map-fallback")?.classList.replace("hidden", "flex");
                return;
            }

            const m = map;
            m.addControl(
                new maplibregl.NavigationControl({ showCompass: false }),
                "top-right",
            );
            m.addControl(
                new maplibregl.AttributionControl({ compact: true, customAttribution: attribution }),
                "bottom-right",
            );

            m.on("load", () => {
                m.addSource("electricians", {
                    type: "geojson",
                    data: featureCollection,
                    cluster: true,
                    clusterRadius: 50,
                    clusterMaxZoom: 11,
                });

                m.addLayer({
                    id: "clusters",
                    type: "circle",
                    source: "electricians",
                    filter: ["has", "point_count"],
                    paint: {
                        "circle-color": BRAND,
                        "circle-opacity": 0.9,
                        "circle-radius": ["step", ["get", "point_count"], 16, 10, 20, 25, 26],
                        "circle-stroke-width": 2,
                        "circle-stroke-color": "#ffffff",
                    },
                });

                m.addLayer({
                    id: "cluster-count",
                    type: "symbol",
                    source: "electricians",
                    filter: ["has", "point_count"],
                    layout: {
                        "text-field": ["get", "point_count_abbreviated"],
                        "text-font": ["Noto Sans Regular"],
                        "text-size": 12,
                    },
                    paint: { "text-color": "#ffffff" },
                });

                m.addLayer({
                    id: "points",
                    type: "circle",
                    source: "electricians",
                    filter: ["!", ["has", "point_count"]],
                    paint: {
                        "circle-color": BRAND,
                        "circle-radius": 7,
                        "circle-stroke-width": 2,
                        "circle-stroke-color": "#ffffff",
                    },
                });

                m.on("click", "clusters", (e: MapLayerMouseEvent) => {
                    const f = e.features?.[0];
                    if (!f) return;
                    const clusterId = Number(f.properties?.cluster_id);
                    const src = m.getSource("electricians") as GeoJSONSource;
                    src.getClusterExpansionZoom(clusterId)
                        .then((z) => {
                            const geom = f.geometry as Point;
                            m.easeTo({
                                center: geom.coordinates as [number, number],
                                zoom: z,
                            });
                        })
                        .catch(() => undefined);
                });

                m.on("click", "points", (e: MapLayerMouseEvent) => {
                    const f = e.features?.[0];
                    if (!f) return;
                    const id = String(f.properties?.id ?? "");
                    const found = electricians.find((x) => x.id === id);
                    if (found) focusElectrician(found);
                });

                for (const layer of ["clusters", "points"]) {
                    m.on("mouseenter", layer, () => {
                        m.getCanvas().style.cursor = "pointer";
                    });
                    m.on("mouseleave", layer, () => {
                        m.getCanvas().style.cursor = "";
                    });
                }
            });
        })
        .catch(() => {
            document.getElementById("ef-map-fallback")?.classList.replace("hidden", "flex");
        });
}

init();
