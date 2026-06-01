// Image switcher: tabbed navigation that cross-fades between stacked images.
// Supports multiple independent instances per page (no global IDs).

document.addEventListener("DOMContentLoaded", () => {
    const switchers = document.querySelectorAll<HTMLElement>("[data-image-switcher]");

    switchers.forEach((switcher) => {
        const tabs = Array.from(switcher.querySelectorAll<HTMLButtonElement>("[data-switcher-tab]"));
        const images = Array.from(switcher.querySelectorAll<HTMLImageElement>("[data-switcher-image]"));
        if (!tabs.length || !images.length) return;

        const activate = (index: number): void => {
            tabs.forEach((tab, i) => {
                const active = i === index;
                tab.setAttribute("aria-selected", active ? "true" : "false");
                tab.classList.toggle("bg-white/30", active);
                tab.classList.toggle("hover:bg-white/10", !active);
            });
            images.forEach((img, i) => {
                img.classList.toggle("opacity-0", i !== index);
            });
        };

        tabs.forEach((tab, index) => {
            tab.addEventListener("click", () => activate(index));
        });
    });
});
