document.addEventListener("DOMContentLoaded", () => {
    document.querySelectorAll<HTMLElement>("[data-code-tabs]").forEach((group) => {
        const panels = group.querySelectorAll<HTMLElement>("[data-tab-panel]");
        const buttons = group.querySelectorAll<HTMLElement>("[data-tab-btn]");

        buttons.forEach((btn, idx) => {
            btn.addEventListener("click", () => {
                panels.forEach((panel, i) => {
                    panel.classList.toggle("hidden", i !== idx);
                });
                buttons.forEach((b, i) => {
                    const active = i === idx;
                    // Legacy dark-theme classes (HTTP/MQTT pills)
                    b.classList.toggle("bg-white/30", active);
                    b.classList.toggle("bg-transparent", !active);
                    // Generic data-attribute hook for light/custom themes
                    b.setAttribute("data-active", active ? "true" : "false");
                });
            });
        });
    });
});
