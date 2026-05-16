const list = document.querySelector(".news-card")?.parentElement as HTMLElement | null;

if (list) {
    list.style.position = "relative";

    list.querySelectorAll<HTMLElement>(".news-toggle").forEach((btn) => {
        btn.addEventListener("click", () => {
            const card = btn.closest<HTMLElement>(".news-card");
            if (!card) return;
            if (card.classList.contains("news-expanded")) {
                collapse(card);
            } else {
                const alreadyExpanded = list.querySelector<HTMLElement>(".news-expanded");
                if (alreadyExpanded) collapse(alreadyExpanded);
                expand(card);
            }
        });
    });
}

function expand(card: HTMLElement): void {
    if (!list) return;
    const containerHeight = list.offsetHeight;
    const cardTop = card.offsetTop;
    const cardHeight = card.offsetHeight;

    card.dataset.originalTop = String(cardTop);

    list.style.height = containerHeight + "px";

    const placeholder = document.createElement("div");
    placeholder.className = "news-placeholder";
    placeholder.style.height = cardHeight + "px";
    placeholder.style.flexShrink = "0";
    card.before(placeholder);

    card.style.position = "absolute";
    card.style.top = cardTop + "px";
    card.style.left = "0";
    card.style.right = "0";
    card.style.height = cardHeight + "px";
    card.style.zIndex = "10";

    const excerpt = card.querySelector<HTMLElement>(".news-excerpt");
    if (excerpt) {
        const excerptText = excerpt.querySelector<HTMLElement>("p");
        const fullContent = excerpt.querySelector<HTMLElement>("div");
        if (excerptText) excerptText.classList.add("hidden");
        if (fullContent) fullContent.classList.remove("hidden");
    }

    const toggle = card.querySelector<HTMLElement>(".news-toggle");
    if (toggle) toggle.textContent = toggle.dataset.i18nLess ?? "show less";
    card.classList.add("news-expanded");

    requestAnimationFrame(() => {
        requestAnimationFrame(() => {
            card.style.transition =
                "top 0.4s cubic-bezier(0.4, 0, 0.2, 1), height 0.4s cubic-bezier(0.4, 0, 0.2, 1)";
            card.style.top = "0";
            card.style.height = containerHeight + "px";
            card.addEventListener(
                "transitionend",
                () => {
                    card.style.transition = "";
                    card.style.overflowY = "auto";
                },
                { once: true },
            );
        });
    });
}

function collapse(card: HTMLElement): void {
    if (!list) return;
    const placeholder = list.querySelector<HTMLElement>(".news-placeholder");
    const originalHeight = placeholder ? parseInt(placeholder.style.height) : card.offsetHeight;
    const originalTop = parseFloat(card.dataset.originalTop ?? "0");

    card.style.overflowY = "";

    const excerpt = card.querySelector<HTMLElement>(".news-excerpt");
    if (excerpt) {
        const excerptText = excerpt.querySelector<HTMLElement>("p");
        const fullContent = excerpt.querySelector<HTMLElement>("div");
        if (excerptText) excerptText.classList.remove("hidden");
        if (fullContent) fullContent.classList.add("hidden");
    }

    const toggle = card.querySelector<HTMLElement>(".news-toggle");
    if (toggle) toggle.textContent = toggle.dataset.i18nMore ?? "show more";

    card.style.transition =
        "top 0.4s cubic-bezier(0.4, 0, 0.2, 1), height 0.4s cubic-bezier(0.4, 0, 0.2, 1)";
    card.style.top = originalTop + "px";
    card.style.height = originalHeight + "px";

    card.addEventListener(
        "transitionend",
        () => {
            placeholder?.remove();
            card.style.cssText = "";
            delete card.dataset.originalTop;
            list!.style.height = "";
            card.classList.remove("news-expanded");
        },
        { once: true },
    );
}
