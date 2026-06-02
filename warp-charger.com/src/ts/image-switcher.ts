// Image switcher: tabbed navigation that slides between images on a track.
// Supports multiple independent instances per page (no global IDs) and
// finger-follow swiping on touch devices.

document.addEventListener("DOMContentLoaded", () => {
    const switchers = document.querySelectorAll<HTMLElement>("[data-image-switcher]");

    switchers.forEach((switcher) => {
        const tabs = Array.from(switcher.querySelectorAll<HTMLButtonElement>("[data-switcher-tab]"));
        const images = Array.from(switcher.querySelectorAll<HTMLImageElement>("[data-switcher-image]"));
        const track = switcher.querySelector<HTMLElement>("[data-switcher-track]");
        const viewport = switcher.querySelector<HTMLElement>("[data-switcher-viewport]");
        if (!tabs.length || !images.length || !track || !viewport) return;

        let current = 0;
        const transition = "transform 300ms ease";
        track.style.transition = transition;

        const setOffset = (px: number): void => {
            track.style.transform = `translate3d(${px}px, 0, 0)`;
        };

        const activate = (index: number): void => {
            current = Math.max(0, Math.min(images.length - 1, index));
            tabs.forEach((tab, i) => {
                const active = i === current;
                tab.setAttribute("aria-selected", active ? "true" : "false");
                tab.classList.toggle("bg-white/30", active);
                tab.classList.toggle("hover:bg-white/10", !active);
            });
            track.style.transition = transition;
            setOffset(-current * viewport.clientWidth);
        };

        tabs.forEach((tab, index) => {
            tab.addEventListener("click", () => activate(index));
        });

        // Keep the track aligned if the viewport is resized.
        window.addEventListener("resize", () => {
            track.style.transition = "none";
            setOffset(-current * viewport.clientWidth);
        });

        // Finger-follow swipe: the track tracks the finger, then snaps.
        let startX = 0;
        let startY = 0;
        let delta = 0;
        let dragging = false;
        let locked = false; // direction resolved as horizontal

        viewport.addEventListener(
            "touchstart",
            (event: TouchEvent) => {
                if (event.touches.length !== 1) return;
                startX = event.touches[0].clientX;
                startY = event.touches[0].clientY;
                delta = 0;
                dragging = true;
                locked = false;
                track.style.transition = "none";
            },
            { passive: true },
        );

        viewport.addEventListener(
            "touchmove",
            (event: TouchEvent) => {
                if (!dragging) return;
                const dx = event.touches[0].clientX - startX;
                const dy = event.touches[0].clientY - startY;

                if (!locked) {
                    // Decide whether this is a horizontal swipe or vertical scroll.
                    if (Math.abs(dx) < 8 && Math.abs(dy) < 8) return;
                    if (Math.abs(dx) <= Math.abs(dy)) {
                        dragging = false; // vertical scroll, let the page handle it
                        track.style.transition = transition;
                        setOffset(-current * viewport.clientWidth);
                        return;
                    }
                    locked = true;
                }

                delta = dx;
                // Add resistance at the edges so it can't be dragged past the ends.
                if ((current === 0 && delta > 0) || (current === images.length - 1 && delta < 0)) {
                    delta *= 0.3;
                }
                setOffset(-current * viewport.clientWidth + delta);
            },
            { passive: true },
        );

        const endDrag = (): void => {
            if (!dragging) return;
            dragging = false;
            const threshold = Math.min(80, viewport.clientWidth * 0.2);
            if (delta < -threshold && current < images.length - 1) {
                activate(current + 1);
            } else if (delta > threshold && current > 0) {
                activate(current - 1);
            } else {
                activate(current); // snap back
            }
        };

        viewport.addEventListener("touchend", endDrag, { passive: true });
        viewport.addEventListener("touchcancel", endDrag, { passive: true });
    });
});
