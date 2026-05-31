(function () {
    const menuBtn = document.getElementById("mobile-menu-btn");
    const closeBtn = document.getElementById("mobile-menu-close");
    const overlay = document.getElementById("mobile-menu-overlay");
    const panel = document.getElementById("mobile-menu");

    if (!menuBtn || !closeBtn || !overlay || !panel) return;

    function openMenu(): void {
        overlay!.classList.remove("opacity-0", "invisible");
        overlay!.classList.add("opacity-100");
        panel!.classList.remove("translate-x-full");
        panel!.classList.add("translate-x-0");
        menuBtn!.setAttribute("aria-expanded", "true");
        document.body.style.overflow = "hidden";
    }

    function closeMenu(): void {
        overlay!.classList.remove("opacity-100");
        overlay!.classList.add("opacity-0");
        panel!.classList.remove("translate-x-0");
        panel!.classList.add("translate-x-full");
        menuBtn!.setAttribute("aria-expanded", "false");
        document.body.style.overflow = "";
        setTimeout(() => overlay!.classList.add("invisible"), 300);
    }

    menuBtn.addEventListener("click", openMenu);
    closeBtn.addEventListener("click", closeMenu);
    overlay.addEventListener("click", closeMenu);

    document.addEventListener("keydown", (e: KeyboardEvent) => {
        if (e.key === "Escape") closeMenu();
    });

    document.querySelectorAll<HTMLButtonElement>(".mobile-accordion-btn").forEach((btn) => {
        btn.addEventListener("click", () => {
            const target = btn.dataset.target;
            if (!target) return;
            const content = document.getElementById(target) as HTMLElement | null;
            const icon = btn.querySelector<HTMLElement>(".expand-icon");
            if (!content) return;

            const isOpen = btn.getAttribute("aria-expanded") === "true";
            btn.setAttribute("aria-expanded", String(!isOpen));
            if (isOpen) {
                content.style.maxHeight = "0";
                if (icon) icon.style.transform = "";
            } else {
                content.style.maxHeight = content.scrollHeight + "px";
                if (icon) icon.style.transform = "rotate(180deg)";
            }
        });
    });
})();
