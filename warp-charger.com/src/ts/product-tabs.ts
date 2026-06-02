/*
 * Product page behaviours: hero tab switching (Funktionen/Details),
 * feature pill expand/collapse with image swap, color swatches,
 * and the energy-scenario switcher placeholder.
 *
 */

// Hero tab switching (Funktionen / Details)

function initProductTabs(root: Element): void {
    const tabs = Array.from(
        root.querySelectorAll<HTMLElement>('[role="tab"][data-tab]'),
    );
    if (!tabs.length) return;

    const panels: Record<string, HTMLElement | null> = {
        funktionen: document.getElementById("panel-funktionen"),
        details: document.getElementById("panel-details"),
    };

    function activate(name: string, updateHash: boolean): void {
        tabs.forEach((tab) => {
            const isActive = tab.dataset.tab === name;
            tab.setAttribute("aria-selected", String(isActive));
            tab.classList.toggle("tab-pill-active", isActive);
        });
        for (const [key, panel] of Object.entries(panels)) {
            if (!panel) continue;
            panel.classList.toggle("hidden", key !== name);
        }
        // Reflect the active tab in the URL so it can be shared/bookmarked.
        // replaceState keeps the address bar in sync without spamming history
        // or triggering the browser's native anchor scroll.
        if (updateHash) {
            history.replaceState(null, "", `#${name}`);
        }
    }

    tabs.forEach((tab) => {
        tab.addEventListener("click", () => {
            const name = tab.dataset.tab;
            if (name) activate(name, true);
        });
    });

    // Open the tab requested by the URL hash. Supports "#details"/"#funktionen"
    // as well as deep links to any element inside the details panel.
    function applyFromHash(scroll: boolean): void {
        const raw = decodeURIComponent(location.hash.replace(/^#/, ""));
        if (!raw) return;

        let name: string | null = null;
        if (raw === "details" || raw === "funktionen") {
            name = raw;
        } else {
            const target = document.getElementById(raw);
            if (target && panels.details?.contains(target)) name = "details";
            else if (target && panels.funktionen?.contains(target)) name = "funktionen";
        }
        if (!name) return;

        activate(name, false);

        if (scroll) {
            // Scroll to the tab strip (not the panel top) so the freshly
            // activated tab stays visible above its content.
            const tablist = root.querySelector<HTMLElement>('[role="tablist"]');
            // Wait a frame so the now-visible panel has a layout to scroll to.
            requestAnimationFrame(() => {
                tablist?.scrollIntoView({ block: "start" });
            });
        }
    }

    applyFromHash(true);
    window.addEventListener("hashchange", () => applyFromHash(false));
}

document
    .querySelectorAll<HTMLElement>("[data-product-tabs]")
    .forEach(initProductTabs);

// Feature pill expand/collapse + image swap

function initFeaturePillSwitcher(root: HTMLElement): void {
    const pills = Array.from(
        root.querySelectorAll<HTMLButtonElement>(".feature-pill[data-pill]"),
    );
    const showcaseImg = root.querySelector<HTMLImageElement>(
        "[data-showcase-image]",
    );
    const swatches = Array.from(
        root.querySelectorAll<HTMLButtonElement>("[data-swatch]"),
    );

    let currentMaterial = root.dataset.variant || "edelstahl";

    function resolvePillImage(wrap: HTMLElement | null): string | null {
        if (!wrap) return null;
        const key = `pillImage${currentMaterial.charAt(0).toUpperCase()}${currentMaterial.slice(1)}`;
        if (wrap.dataset[key]) return wrap.dataset[key] ?? null;
        if (wrap.dataset.pillImageTemplate) {
            return wrap.dataset.pillImageTemplate.replace(
                "{material}",
                currentMaterial,
            );
        }
        return wrap.dataset.pillImage ?? null;
    }

    function wrapIsMaterialAware(wrap: HTMLElement | null): boolean {
        if (!wrap) return false;
        if (wrap.dataset.pillImageTemplate) return true;
        return Object.keys(wrap.dataset).some(
            (k) =>
                k.startsWith("pillImage") &&
                k !== "pillImage" &&
                k !== "pillImageTemplate",
        );
    }

    function applyImage(src: string | null): void {
        if (!showcaseImg || !src || showcaseImg.getAttribute("src") === src) {
            return;
        }
        showcaseImg.style.opacity = "0";
        const next = new Image();
        next.onload = () => {
            showcaseImg.src = src;
            showcaseImg.style.opacity = "1";
        };
        next.onerror = () => {
            showcaseImg.style.opacity = "1";
        };
        next.src = src;
    }

    function setPillState(pill: HTMLButtonElement, expanded: boolean): void {
        const wrap = pill.closest<HTMLElement>(".feature-pill-wrap");
        pill.setAttribute("aria-expanded", String(expanded));
        if (wrap) wrap.classList.toggle("is-active", expanded);
        if (expanded) {
            const src = resolvePillImage(wrap);
            if (src) applyImage(src);
        }
    }

    pills.forEach((pill) => {
        pill.addEventListener("click", () => {
            const willExpand = pill.getAttribute("aria-expanded") !== "true";
            pills.forEach((p) => setPillState(p, false));
            if (willExpand) setPillState(pill, true);
        });
    });

    swatches.forEach((swatch) => {
        swatch.addEventListener("click", () => {
            const mat = swatch.dataset.material;
            if (!mat) return;
            currentMaterial = mat;
            swatches.forEach((s) => {
                const selected = s === swatch;
                s.classList.toggle("is-selected", selected);
                s.setAttribute("aria-pressed", String(selected));
            });
            const activeWrap = root.querySelector<HTMLElement>(
                ".feature-pill-wrap.is-active",
            );
            if (activeWrap && wrapIsMaterialAware(activeWrap)) {
                applyImage(resolvePillImage(activeWrap));
            }
        });
    });
}

document
    .querySelectorAll<HTMLElement>("[data-feature-pill-switcher]")
    .forEach(initFeaturePillSwitcher);

// Energy scenario switcher (placeholder text swap + panel toggle)

function initScenarioSwitcher(root: HTMLElement): void {
    const btns = Array.from(
        root.querySelectorAll<HTMLButtonElement>(".scenario-btn[data-scenario]"),
    );
    if (!btns.length) return;

    const panels = Array.from(
        root.querySelectorAll<HTMLElement>("[data-scenario-panel]"),
    );

    const showPanel = (id: string) => {
        panels.forEach((p) => {
            p.classList.toggle("hidden", p.dataset.scenarioPanel !== id);
        });
    };

    btns.forEach((btn) => {
        btn.addEventListener("click", () => {
            btns.forEach((b) => {
                b.classList.remove("scenario-btn-active");
                b.setAttribute("aria-selected", "false");
            });
            btn.classList.add("scenario-btn-active");
            btn.setAttribute("aria-selected", "true");
            showPanel(btn.dataset.scenario || "");
        });
    });
}

document
    .querySelectorAll<HTMLElement>("[data-scenario-switcher]")
    .forEach(initScenarioSwitcher);

// Info popover inside each scenario panel: toggle on button click, close on
// outside click or Escape, close all when switching scenarios.

function initInfoPopovers(): void {
    const panels = Array.from(
        document.querySelectorAll<HTMLElement>("[data-scenario-panel]"),
    );

    const closeAll = (except?: HTMLElement) => {
        panels.forEach((panel) => {
            const pop = panel.querySelector<HTMLElement>("[data-info-popover]");
            const btn = panel.querySelector<HTMLElement>("[data-info-btn]");
            if (!pop || pop === except) return;
            if (pop.classList.contains("hidden")) return;
            pop.classList.add("hidden");
            btn?.setAttribute("aria-expanded", "false");
            panel.dispatchEvent(new CustomEvent("scenario-popover-close"));
        });
    };

    panels.forEach((panel) => {
        const btn = panel.querySelector<HTMLButtonElement>("[data-info-btn]");
        const pop = panel.querySelector<HTMLElement>("[data-info-popover]");
        if (!btn || !pop) return;

        btn.addEventListener("click", (e) => {
            e.stopPropagation();
            const willOpen = pop.classList.contains("hidden");
            closeAll();
            if (willOpen) {
                pop.classList.remove("hidden");
                btn.setAttribute("aria-expanded", "true");
                panel.dispatchEvent(new CustomEvent("scenario-popover-open"));
            }
        });

        pop.addEventListener("click", (e) => e.stopPropagation());

        pop.querySelectorAll<HTMLButtonElement>("[data-info-close]")
            .forEach((closer) => {
                closer.addEventListener("click", () => {
                    if (pop.classList.contains("hidden")) return;
                    pop.classList.add("hidden");
                    btn.setAttribute("aria-expanded", "false");
                    panel.dispatchEvent(new CustomEvent("scenario-popover-close"));
                });
            });
    });

    document.addEventListener("click", () => closeAll());
    document.addEventListener("keydown", (e) => {
        if (e.key === "Escape") closeAll();
    });

    // Close popovers whenever the scenario changes.
    document
        .querySelectorAll<HTMLButtonElement>(".scenario-btn[data-scenario]")
        .forEach((b) => b.addEventListener("click", () => closeAll()));
}

initInfoPopovers();
