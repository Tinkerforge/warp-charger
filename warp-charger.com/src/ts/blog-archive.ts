// Blog archive drawer (mobile-only sidebar): open/close/Escape/backdrop +
// auto-close when an archive link is clicked.

(function () {
    const btn = document.getElementById("blog-archive-toggle");
    const drawer = document.getElementById("blog-archive-drawer");
    const backdrop = document.getElementById("blog-archive-backdrop");
    const closeBtn = document.getElementById("blog-archive-close");
    if (!btn || !drawer || !backdrop) return;

    function open() {
        if (!drawer || !backdrop || !btn) return;
        drawer.classList.remove("translate-x-full");
        backdrop.classList.remove("opacity-0", "pointer-events-none");
        backdrop.classList.add("opacity-100");
        drawer.setAttribute("aria-hidden", "false");
        btn.setAttribute("aria-expanded", "true");
        document.body.style.overflow = "hidden";
    }
    function close() {
        if (!drawer || !backdrop || !btn) return;
        drawer.classList.add("translate-x-full");
        backdrop.classList.add("opacity-0", "pointer-events-none");
        backdrop.classList.remove("opacity-100");
        drawer.setAttribute("aria-hidden", "true");
        btn.setAttribute("aria-expanded", "false");
        document.body.style.overflow = "";
    }

    btn.addEventListener("click", open);
    closeBtn?.addEventListener("click", close);
    backdrop.addEventListener("click", close);
    document.addEventListener("keydown", (e) => {
        if (e.key === "Escape" && drawer.getAttribute("aria-hidden") === "false") close();
    });
    // Close drawer when an archive link is clicked (navigation feedback)
    drawer.addEventListener("click", (e) => {
        const target = e.target as HTMLElement | null;
        const a = target?.closest("a");
        if (a) close();
    });
})();
