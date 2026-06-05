interface TabData {
    badge: string;
    headline: string;
    body: string;
    image: string;
}

document.addEventListener("DOMContentLoaded", () => {
    // Showcase mobile/tablet image slider
    const showcaseTrack = document.getElementById("showcase-slider-track");
    const showcaseDots = Array.from(document.querySelectorAll<HTMLElement>("[data-showcase-dot]"));

    if (showcaseTrack && showcaseDots.length) {
        const slideCount = showcaseDots.length;
        let activeIndex = 0;
        let autoplayTimer: ReturnType<typeof setInterval> | null = null;

        const updateDots = (index: number): void => {
            activeIndex = index;
            showcaseDots.forEach((dot, i) => {
                if (i === index) {
                    dot.classList.add("bg-white", "scale-125");
                    dot.classList.remove("bg-white/45");
                } else {
                    dot.classList.add("bg-white/45");
                    dot.classList.remove("bg-white", "scale-125");
                }
            });
        };

        const goToSlide = (index: number, smooth = true): void => {
            showcaseTrack.scrollTo({
                left: showcaseTrack.offsetWidth * index,
                behavior: smooth ? "smooth" : "instant",
            });
            updateDots(index);
        };

        const startAutoplay = (): void => {
            stopAutoplay();
            autoplayTimer = setInterval(() => {
                goToSlide((activeIndex + 1) % slideCount);
            }, 4000);
        };

        const stopAutoplay = (): void => {
            if (autoplayTimer) clearInterval(autoplayTimer);
        };

        showcaseTrack.addEventListener(
            "scroll",
            () => {
                const index = Math.round(showcaseTrack.scrollLeft / showcaseTrack.offsetWidth);
                updateDots(index);
            },
            { passive: true },
        );

        showcaseTrack.addEventListener("touchstart", () => stopAutoplay(), { passive: true });
        showcaseTrack.addEventListener("touchend", () => startAutoplay(), { passive: true });

        showcaseDots.forEach((dot) => {
            dot.addEventListener("click", () => {
                goToSlide(parseInt(dot.dataset.showcaseDot ?? "0", 10));
                startAutoplay();
            });
        });

        startAutoplay();
    }

    // Tabbed slider
    const sliderNav = document.querySelector<HTMLElement>('nav[aria-label="Slider tabs"]');
    if (!sliderNav) return;

    const sliderSection = sliderNav.closest<HTMLElement>("[data-slider-tabs]");
    if (!sliderSection) return;

    const imageBase = sliderSection.dataset.sliderImageBase ?? "/static/images/";
    const showMoreText = sliderSection.dataset.sliderShowMore ?? "show more";
    const showLessText = sliderSection.dataset.sliderShowLess ?? "show less";

    let tabData: TabData[] = [];
    try {
        tabData = JSON.parse(sliderSection.dataset.sliderTabs ?? "[]");
    } catch {
        return;
    }
    if (!tabData.length) return;

    const tabs = Array.from(sliderNav.querySelectorAll<HTMLButtonElement>("button"));

    const sliderImage = document.getElementById("slider-image") as HTMLImageElement | null;
    const sliderImageBg = document.getElementById("slider-image-bg") as HTMLImageElement | null;
    const sliderBadge = document.getElementById("slider-badge") as HTMLElement | null;
    const sliderHeadline = document.getElementById("slider-headline") as HTMLElement | null;
    const sliderBody = document.getElementById("slider-body") as HTMLElement | null;
    const sliderTextContent = document.getElementById("slider-text-content") as HTMLElement | null;
    const sliderMehrBtn = document.getElementById("slider-mehr-btn") as HTMLElement | null;
    const sliderArticle = sliderTextContent?.closest<HTMLElement>("article") ?? null;

    if (!sliderImage || !sliderHeadline || !sliderBody) return;

    // Mobile "mehr anzeigen"
    let bodyExpanded = false;
    let isAnimating = false;
    let savedClampedHeight = 0;

    const isMobile = (): boolean => window.innerWidth < 768;

    function applyClamp(): void {
        sliderBody!.style.display = "-webkit-box";
        (sliderBody as any).style.webkitLineClamp = "4";
        (sliderBody as any).style.webkitBoxOrient = "vertical";
        sliderBody!.style.overflow = "hidden";
        sliderBody!.style.maxHeight = "";
    }

    function checkMehrAnzeigen(): void {
        if (!sliderMehrBtn || !sliderBody) return;
        if (!isMobile()) {
            sliderMehrBtn.classList.add("hidden");
            sliderBody.style.display = "";
            (sliderBody as any).style.webkitLineClamp = "";
            (sliderBody as any).style.webkitBoxOrient = "";
            sliderBody.style.overflow = "";
            sliderBody.style.maxHeight = "";
            return;
        }
        applyClamp();
        sliderMehrBtn.classList.toggle(
            "hidden",
            sliderBody.scrollHeight <= sliderBody.clientHeight + 1,
        );
    }

    function getAvailableBodyHeight(): number {
        if (!sliderTextContent || !sliderBody) return 0;
        const style = getComputedStyle(sliderTextContent);
        const pt = parseFloat(style.paddingTop) || 0;
        const pb = parseFloat(style.paddingBottom) || 0;
        const gap = parseFloat(style.rowGap) || 12;
        const innerH = sliderTextContent.clientHeight - pt - pb;

        let siblingsH = 0;
        let count = 0;
        for (const child of Array.from(sliderTextContent.children)) {
            if (child === sliderBody) continue;
            if (getComputedStyle(child).display === "none") continue;
            siblingsH += (child as HTMLElement).offsetHeight;
            count++;
        }
        return innerH - siblingsH - count * gap;
    }

    function resetBodyStyles(): void {
        if (!sliderBody) return;
        sliderBody.style.transition = "";
        sliderBody.style.maxHeight = "";
        sliderBody.style.overflow = "";
        sliderBody.style.overflowY = "";
        sliderBody.style.display = "";
        (sliderBody as any).style.webkitLineClamp = "";
        (sliderBody as any).style.webkitBoxOrient = "";
        if (sliderArticle) sliderArticle.style.height = "";
    }

    function collapseBodyImmediate(): void {
        isAnimating = false;
        bodyExpanded = false;
        resetBodyStyles();
        if (sliderMehrBtn) sliderMehrBtn.textContent = showMoreText;
        checkMehrAnzeigen();
    }

    function expandBody(): void {
        if (isAnimating || !sliderBody) return;
        isAnimating = true;
        bodyExpanded = true;

        savedClampedHeight = sliderBody.clientHeight;

        if (sliderArticle) sliderArticle.style.height = sliderArticle.offsetHeight + "px";

        sliderBody.style.maxHeight = savedClampedHeight + "px";
        sliderBody.style.overflow = "hidden";
        sliderBody.style.display = "block";
        (sliderBody as any).style.webkitLineClamp = "";
        (sliderBody as any).style.webkitBoxOrient = "";

        const naturalHeight = sliderBody.scrollHeight;
        const available = getAvailableBodyHeight();
        const targetHeight = Math.min(naturalHeight, available);
        const needsScroll = naturalHeight > available;

        if (sliderMehrBtn) sliderMehrBtn.textContent = showLessText;

        requestAnimationFrame(() => {
            requestAnimationFrame(() => {
                sliderBody!.style.transition = "max-height 0.4s cubic-bezier(0.4, 0, 0.2, 1)";
                sliderBody!.style.maxHeight = targetHeight + "px";
                sliderBody!.addEventListener(
                    "transitionend",
                    () => {
                        sliderBody!.style.transition = "";
                        if (needsScroll) sliderBody!.style.overflowY = "auto";
                        isAnimating = false;
                    },
                    { once: true },
                );
            });
        });
    }

    function collapseBody(): void {
        if (isAnimating || !sliderBody) return;
        isAnimating = true;
        bodyExpanded = false;

        sliderBody.style.overflowY = "";
        sliderBody.style.overflow = "hidden";

        if (sliderMehrBtn) sliderMehrBtn.textContent = showMoreText;

        sliderBody.style.transition = "max-height 0.4s cubic-bezier(0.4, 0, 0.2, 1)";
        sliderBody.style.maxHeight = savedClampedHeight + "px";

        sliderBody.addEventListener(
            "transitionend",
            () => {
                sliderBody!.style.transition = "";
                if (sliderArticle) sliderArticle.style.height = "";
                checkMehrAnzeigen();
                isAnimating = false;
            },
            { once: true },
        );
    }

    if (sliderMehrBtn) {
        sliderMehrBtn.addEventListener("click", () => {
            bodyExpanded ? collapseBody() : expandBody();
        });
    }

    checkMehrAnzeigen();
    window.addEventListener("resize", collapseBodyImmediate, { passive: true });

    // Tab switching
    let transitionTimeout: ReturnType<typeof setTimeout>;
    let currentIndex = 0;

    function activateTab(index: number): void {
        index = Math.max(0, Math.min(tabs.length - 1, index));

        tabs.forEach((t, i) => {
            if (i === index) {
                t.setAttribute("aria-selected", "true");
                t.classList.add("bg-white/30");
                t.classList.remove("hover:bg-white/10");
            } else {
                t.setAttribute("aria-selected", "false");
                t.classList.remove("bg-white/30");
                t.classList.add("hover:bg-white/10");
            }
        });

        const data = tabData[index];
        const imageSrc = imageBase + data.image;

        if (sliderImageBg) {
            clearTimeout(transitionTimeout);
            sliderImageBg.src = imageSrc;
            sliderImage!.style.transition = "";
            sliderImage!.style.opacity = "0";

            transitionTimeout = setTimeout(() => {
                sliderImage!.style.transition = "none";
                sliderImage!.src = imageSrc;
                sliderImage!.alt = data.headline;
                sliderImage!.style.opacity = "1";
                void sliderImage!.offsetWidth;
                sliderImage!.style.transition = "";
            }, 300);
        }

        sliderHeadline!.textContent = data.headline;
        sliderBody!.textContent = data.body;

        if (sliderBadge) {
            if (data.badge) {
                sliderBadge.textContent = data.badge;
                sliderBadge.style.display = "block";
            } else {
                sliderBadge.style.display = "none";
            }
        }

        collapseBodyImmediate();
        currentIndex = index;
    }

    tabs.forEach((tab, index) => {
        tab.addEventListener("click", () => activateTab(index));
    });

    // Swipe between tabs on touch devices. Uses the same direction-locked
    // gesture detection as the company-page image switcher (so vertical page
    // scrolling still works), but keeps the existing cross-fade transition
    // instead of dragging the content with the finger.
    if (sliderArticle) {
        const swipeTarget = sliderArticle;
        let startX = 0;
        let startY = 0;
        let dragging = false;
        let locked = false;

        swipeTarget.addEventListener(
            "touchstart",
            (event: TouchEvent) => {
                if (event.touches.length !== 1) return;
                startX = event.touches[0].clientX;
                startY = event.touches[0].clientY;
                dragging = true;
                locked = false;
            },
            { passive: true },
        );

        swipeTarget.addEventListener(
            "touchmove",
            (event: TouchEvent) => {
                if (!dragging || locked) return;
                const dx = event.touches[0].clientX - startX;
                const dy = event.touches[0].clientY - startY;
                // Ignore tiny moves until a clear direction emerges.
                if (Math.abs(dx) < 8 && Math.abs(dy) < 8) return;
                if (Math.abs(dx) <= Math.abs(dy)) {
                    dragging = false; // vertical scroll, let the page handle it
                    return;
                }
                locked = true; // horizontal swipe
            },
            { passive: true },
        );

        const endSwipe = (event: TouchEvent): void => {
            if (!dragging) return;
            dragging = false;
            if (!locked) return;
            const dx = (event.changedTouches[0]?.clientX ?? startX) - startX;
            const threshold = Math.min(80, swipeTarget.clientWidth * 0.2);
            if (dx <= -threshold) {
                activateTab(currentIndex + 1); // swipe left → next
            } else if (dx >= threshold) {
                activateTab(currentIndex - 1); // swipe right → previous
            }
        };

        swipeTarget.addEventListener("touchend", endSwipe, { passive: true });
        swipeTarget.addEventListener("touchcancel", endSwipe, { passive: true });
    }
});
