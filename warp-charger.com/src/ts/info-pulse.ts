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

    // Once the user opens any info popover, suppress the attention pulse on
    // every info button for the rest of the page visit (in-memory, resets on
    // reload). Otherwise switching scenario tabs would reveal a fresh,
    // never-clicked button that starts pulsing again.
    let globallyStopped = false;
    const timers: number[] = [];
    const stopAll = (): void => {
        if (globallyStopped) return;
        globallyStopped = true;
        timers.forEach((id) => window.clearTimeout(id));
        rings.forEach((ring) => ring.classList.remove("is-pulsing"));
    };

    document.querySelectorAll<HTMLElement>("[data-info-btn]").forEach((btn) => {
        btn.addEventListener("click", stopAll);
    });

    rings.forEach((ring) => {
        const schedule = (): void => {
            const id = window.setTimeout(() => {
                if (globallyStopped) return;
                // Skip while the tab is hidden to avoid a burst on refocus.
                if (!document.hidden) pulseOnce(ring);
                schedule();
            }, randomDelay());
            timers.push(id);
        };

        ring.addEventListener("animationend", () =>
            ring.classList.remove("is-pulsing"),
        );
        schedule();
    });
});
