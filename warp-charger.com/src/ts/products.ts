document.addEventListener("DOMContentLoaded", () => {
    const scrollContainer = document.getElementById("products-container");
    const btnLeft = document.getElementById("scroll-products-left");
    const btnRight = document.getElementById("scroll-products-right");
    const cards = document.querySelectorAll<HTMLElement>(".product-card");

    if (!scrollContainer) return;

    if (btnLeft && btnRight) {
        const getScrollAmount = (): number => {
            if (!cards.length) return 0;
            const cardWidth = cards[0].offsetWidth;
            const gap = parseFloat(getComputedStyle(scrollContainer).gap) || 0;
            return cardWidth + gap;
        };

        btnLeft.addEventListener("click", () => {
            scrollContainer.scrollBy({ left: -getScrollAmount(), behavior: "smooth" });
        });
        btnRight.addEventListener("click", () => {
            scrollContainer.scrollBy({ left: getScrollAmount(), behavior: "smooth" });
        });
    }

    const updateActiveCard = (): void => {
        if (!cards.length) return;

        let minDiff = Infinity;
        let activeCard: HTMLElement | null = null;

        const containerRect = scrollContainer.getBoundingClientRect();
        const paddingLeft = parseFloat(getComputedStyle(scrollContainer).paddingLeft) || 0;
        const targetX = containerRect.left + paddingLeft;

        cards.forEach((card) => {
            const rect = card.getBoundingClientRect();
            const diff = Math.abs(rect.left - targetX);

            if (diff < minDiff) {
                minDiff = diff;
                activeCard = card;
            }
        });

        cards.forEach((card) => card.classList.remove("is-active"));
        if (activeCard) {
            (activeCard as HTMLElement).classList.add("is-active");
        }
    };

    scrollContainer.addEventListener("scroll", () => {
        window.requestAnimationFrame(updateActiveCard);
    });

    window.addEventListener("resize", () => {
        window.requestAnimationFrame(updateActiveCard);
    });

    setTimeout(updateActiveCard, 50);
});
