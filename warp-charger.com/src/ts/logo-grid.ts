(function () {
    const grid = document.getElementById("logo-grid");
    if (!grid) return;

    const buttons = grid.querySelectorAll<HTMLElement>("[data-detail]");
    let activePanel: HTMLElement | null = null;
    let activeBtn: HTMLElement | null = null;

    function closeActive(): void {
        if (activePanel && activeBtn) {
            activePanel.classList.add("hidden");
            activeBtn.classList.remove("active");
            activePanel = null;
            activeBtn = null;
        }
    }

    buttons.forEach((btn) => {
        btn.addEventListener("click", () => {
            const id = "detail-" + btn.dataset.detail;
            const panel = document.getElementById(id);
            if (!panel) return;
            if (activePanel === panel) {
                closeActive();
                return;
            }
            closeActive();
            panel.classList.remove("hidden");
            btn.classList.add("active");
            activePanel = panel;
            activeBtn = btn;
            panel.scrollIntoView({ behavior: "smooth", block: "nearest" });
        });
    });

    document.querySelectorAll<HTMLElement>(".detail-close").forEach((btn) => {
        btn.addEventListener("click", closeActive);
    });
})();
