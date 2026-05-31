// When a firmware card's parent <details> is closed, also close all nested
// per-version <details> so they don't appear pre-opened next time.
document.querySelectorAll<HTMLDetailsElement>(".firmware-card > details").forEach((parent) => {
    parent.addEventListener("toggle", () => {
        if (!parent.open) {
            parent.querySelectorAll<HTMLDetailsElement>("details[open]").forEach((inner) => {
                inner.open = false;
            });
        }
    });
});
