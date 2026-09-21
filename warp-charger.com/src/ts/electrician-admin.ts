import "maplibre-gl/dist/maplibre-gl.css";
import * as maplibregl from "maplibre-gl";
import { Protocol } from "pmtiles";

async function init(): Promise<void> {
    const el = document.getElementById("admin-map");
    if (!el) return;
    const form = document.getElementById("electrician-form") as HTMLFormElement;
    const lat = document.getElementById("lat") as HTMLInputElement;
    const lon = document.getElementById("lon") as HTMLInputElement;
    const manual = document.getElementById("manual") as HTMLInputElement;
    const status = document.getElementById("map-status")!;
    const locationStatus = document.getElementById("location-status")!;
    let map: maplibregl.Map | undefined;
    let marker: maplibregl.Marker | undefined;

    function position(): [number, number] | null {
        if (!lat.value || !lon.value) return null;
        const a = Number(lat.value), o = Number(lon.value);
        return Number.isFinite(a) && Number.isFinite(o) && Math.abs(a) <= 90 && Math.abs(o) <= 180 ? [o, a] : null;
    }

    function showPosition(fly = false): void {
        const pos = position();
        if (!map || !pos) return;
        if (!marker) {
            marker = new maplibregl.Marker({ color: "#2563eb", draggable: manual.checked })
                .setLngLat(pos).addTo(map);
            marker.on("dragend", () => {
                const p = marker!.getLngLat();
                setPosition(p.lng, p.lat);
            });
        } else {
            marker.setLngLat(pos);
        }
        if (fly) map.easeTo({ center: pos, zoom: 13 });
    }

    function setPosition(lng: number, latitude: number): void {
        lat.value = latitude.toFixed(6);
        lon.value = lng.toFixed(6);
        manual.checked = true;
        locationStatus.textContent = "Manueller Standort – zum Übernehmen speichern.";
        showPosition();
        marker?.setDraggable(true);
    }

    manual.addEventListener("change", () => marker?.setDraggable(manual.checked));
    for (const input of [lat, lon]) {
        input.addEventListener("input", () => {
            manual.checked = true;
            marker?.setDraggable(true);
            locationStatus.textContent = "Manueller Standort – zum Übernehmen speichern.";
            showPosition(true);
        });
    }
    form.querySelectorAll<HTMLInputElement | HTMLSelectElement>("[data-address]").forEach((input) => {
        input.addEventListener("input", () => {
            manual.checked = false;
            marker?.setDraggable(false);
            locationStatus.textContent = "Adresse geändert. Der angezeigte Standort gehört noch zur vorherigen Adresse und wird beim Speichern aktualisiert.";
        });
    });
    form.addEventListener("submit", () => {
        document.getElementById("save-status")!.textContent = "Bitte warten – Adresse wird geprüft …";
        // Defer disabling until after the browser captures the submit button's action.
        window.setTimeout(() => form.querySelectorAll<HTMLButtonElement>("button[type=submit]")
            .forEach((button) => { button.disabled = true; }), 0);
    });

    try {
        maplibregl.setWorkerUrl(el.dataset.worker!);
        maplibregl.addProtocol("pmtiles", new Protocol().tile);
        const response = await fetch(el.dataset.style!);
        if (!response.ok) throw new Error("style");
        const style = await response.json() as maplibregl.StyleSpecification;
        const pos = position();
        map = new maplibregl.Map({ container: el, style, center: pos ?? [10.2, 50.6],
            zoom: pos ? 13 : 4, maxZoom: 18, attributionControl: false });
        map.addControl(new maplibregl.NavigationControl(), "top-right");
        map.addControl(new maplibregl.AttributionControl({ compact: true,
            customAttribution: "© OpenStreetMap · Protomaps" }));
        map.on("click", (event) => {
            if (manual.checked) setPosition(event.lngLat.lng, event.lngLat.lat);
        });
        map.on("error", () => {
            status.textContent = "Kartendaten konnten nicht vollständig geladen werden. Koordinaten können unten eingegeben werden.";
        });
        showPosition();
        status.textContent = "Standort prüfen oder manuell korrigieren.";
    } catch {
        status.textContent = "Karte nicht verfügbar. Adresssuche oder Koordinateneingabe verwenden.";
    }
}

void init();
