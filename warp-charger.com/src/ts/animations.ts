document.addEventListener("DOMContentLoaded", () => {
    const observer = new IntersectionObserver(
        (entries) => {
            entries.forEach((entry) => {
                if (entry.isIntersecting) {
                    entry.target.classList.remove("opacity-0", "translate-y-10");
                    entry.target.classList.add("opacity-100", "translate-y-0");
                    observer.unobserve(entry.target);
                }
            });
        },
        { threshold: 0.05 },
    );

    const sections = document.querySelectorAll("section:not(:first-of-type)");
    sections.forEach((section) => {
        section.classList.add("opacity-0", "translate-y-10", "transition-all", "duration-700");
        observer.observe(section);
    });
});
