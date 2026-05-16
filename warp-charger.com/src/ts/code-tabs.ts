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
                    b.classList.toggle("bg-white/30", i === idx);
                    b.classList.toggle("bg-transparent", i !== idx);
                });
            });
        });
    });
});
