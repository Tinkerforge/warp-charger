// Info button attention pulse.
// Plays a one-shot "ping" ring at random intervals so the button draws the
// eye occasionally rather than pulsing continuously. Respects reduced motion.

document.addEventListener("DOMContentLoaded", () => {
    const prefersReducedMotion = window.matchMedia(
        "(prefers-reduced-motion: reduce)",
    ).matches;
    if (prefersReducedMotion) return;

    const rings = Array.from(
        document.querySelectorAll<HTMLElement>("[data-info-pulse]"),
    );
    if (!rings.length) return;

    const randomDelay = (): number => 4000 + Math.random() * 7000; // 4-11s

    const pulseOnce = (ring: HTMLElement): void => {
        ring.classList.remove("is-pulsing");
        // Force reflow so the animation can restart.
        void ring.offsetWidth;
        ring.classList.add("is-pulsing");
    };

    rings.forEach((ring) => {
        let stopped = false;
        let timer = 0;

        const schedule = (): void => {
            timer = window.setTimeout(() => {
                if (stopped) return;
                // Skip while the tab is hidden to avoid a burst on refocus.
                if (!document.hidden) pulseOnce(ring);
                schedule();
            }, randomDelay());
        };

        // Stop pulsing for good once the user has opened the popover once.
        const button = ring.closest<HTMLElement>("[data-info-btn]");
        button?.addEventListener("click", () => {
            stopped = true;
            window.clearTimeout(timer);
            ring.classList.remove("is-pulsing");
        });

        ring.addEventListener("animationend", () =>
            ring.classList.remove("is-pulsing"),
        );
        schedule();
    });
});
