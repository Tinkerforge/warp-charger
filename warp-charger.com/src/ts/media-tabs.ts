// Media tabs: pill navigation that toggles between an image and a video
// panel (used by the two_col_section macro's media_tabs mode).
// Supports multiple independent instances per page (no global IDs).

document.addEventListener("DOMContentLoaded", () => {
    const roots = document.querySelectorAll<HTMLElement>("[data-media-tabs]");

    roots.forEach((root) => {
        const tabs = Array.from(root.querySelectorAll<HTMLButtonElement>("[data-media-tab]"));
        const panels = Array.from(root.querySelectorAll<HTMLElement>("[data-media-panel]"));
        if (tabs.length < 2 || tabs.length !== panels.length) return;

        const activate = (index: number): void => {
            tabs.forEach((tab, i) => {
                const active = i === index;
                tab.setAttribute("aria-selected", active ? "true" : "false");
                tab.classList.toggle("bg-white/30", active);
                tab.classList.toggle("hover:bg-white/10", !active);
            });
            panels.forEach((panel, i) => {
                const active = i === index;
                panel.hidden = !active;
                // Pause a video when its tab is left so audio doesn't keep playing.
                if (!active && panel instanceof HTMLVideoElement) panel.pause();
            });
        };

        tabs.forEach((tab, index) => {
            tab.addEventListener("click", () => activate(index));
        });
    });
});
