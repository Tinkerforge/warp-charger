// Tap-to-open behavior for the desktop navigation on touch devices
// (e.g. iPad in landscape, where the desktop menu is shown but the user
// has no mouse to trigger the CSS `:hover` / Tailwind `group-hover:`
// dropdowns). On `(hover: none)` devices we toggle `data-open="true"`
// on the `<li class="nav-item group ...">` (and the language switcher
// container), which CSS rules in `input.css` translate into the same
// visual state as `group-hover:`.
document.addEventListener("DOMContentLoaded", () => {
    if (!window.matchMedia("(hover: none)").matches) return;

    const triggers = Array.from(
        document.querySelectorAll<HTMLElement>(
            "header li.nav-item.group, header [data-tap-dropdown]"
        )
    );
    if (triggers.length === 0) return;

    const closeAll = (except?: HTMLElement) => {
        triggers.forEach((t) => {
            if (t !== except) delete t.dataset.open;
        });
    };

    triggers.forEach((trigger) => {
        trigger.addEventListener("click", (event) => {
            // Let taps on real links (inside the dropdown) navigate normally.
            const target = event.target as HTMLElement | null;
            if (target && target.closest("a")) return;

            event.stopPropagation();
            const isOpen = trigger.dataset.open === "true";
            closeAll(trigger);
            if (isOpen) {
                delete trigger.dataset.open;
            } else {
                trigger.dataset.open = "true";
            }
        });
    });

    // Tap outside any trigger closes all dropdowns.
    document.addEventListener("click", (event) => {
        const target = event.target as HTMLElement | null;
        if (target && triggers.some((t) => t.contains(target))) return;
        closeAll();
    });

    // Closing on Escape for keyboard users on hybrid devices.
    document.addEventListener("keyup", (event) => {
        if (event.key === "Escape") closeAll();
    });
});
