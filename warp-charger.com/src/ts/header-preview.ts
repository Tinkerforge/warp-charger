document.addEventListener("DOMContentLoaded", () => {
    document.querySelectorAll<HTMLElement>("[data-preview-card]").forEach((card) => {
        const imgTarget = card.querySelector<HTMLImageElement>("[data-preview-img-target]");
        const titleTarget = card.querySelector<HTMLElement>("[data-preview-title-target]");
        const descTarget = card.querySelector<HTMLElement>("[data-preview-desc-target]");
        const ctaTarget = card.querySelector<HTMLAnchorElement>("[data-preview-cta]");
        const dropdown = card.closest<HTMLElement>(".flex.min-h-104");
        if (!dropdown || !imgTarget || !titleTarget || !descTarget) return;

        const links = dropdown.querySelectorAll<HTMLElement>("a[data-preview-img]");
        links.forEach((link) => {
            link.addEventListener("mouseenter", () => {
                imgTarget.src = link.dataset.previewImg ?? "";
                titleTarget.textContent = link.dataset.previewTitle ?? "";
                descTarget.textContent = link.dataset.previewDesc ?? "";
                if (ctaTarget && link.dataset.previewLink) {
                    ctaTarget.href = link.dataset.previewLink;
                }
            });
        });
    });
});
