interface NewsletterData {
    email: string;
    action: string;
}

// Backend: rapidmail signup (double opt-in) via the Flask endpoint.

async function sendNewsletterSignup(data: NewsletterData): Promise<void> {
    const body = new URLSearchParams({ email: data.email });
    const res = await fetch(data.action, {
        method: "POST",
        headers: { "X-Requested-With": "XMLHttpRequest" },
        body,
    });
    if (!res.ok) {
        throw new Error(`Newsletter signup failed: ${res.status}`);
    }
}

// Validation

const EMAIL_RE = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

// Init: Newsletter Form

const newsletterForm = document.getElementById("newsletter-form") as HTMLFormElement | null;
const newsletterButton = document.getElementById("newsletter-submit") as HTMLButtonElement | null;

if (newsletterForm && newsletterButton) {
    const input = document.getElementById("newsletter-email") as HTMLInputElement;
    const wrap = document.getElementById("wrap-newsletter") as HTMLElement;
    const error = document.getElementById("error-newsletter") as HTMLElement;

    const nlSuccess = newsletterForm.dataset.i18nNewsletterSuccess ?? "Thank you!";
    const nlError = newsletterForm.dataset.i18nNewsletterError ?? "Something went wrong.";
    const nlAction = newsletterForm.dataset.newsletterAction ?? "";

    input.addEventListener("input", () => {
        wrap.classList.remove("border-red-500");
        wrap.classList.add(wrap.dataset.border ?? "");
        error.classList.add("hidden");
    });

    newsletterForm.addEventListener("submit", async (e: Event) => {
        e.preventDefault();

        const email = input.value;
        const valid = EMAIL_RE.test(email.trim());

        wrap.classList.toggle("border-red-500", !valid);
        wrap.classList.toggle(wrap.dataset.border ?? "", valid);
        error.classList.toggle("hidden", valid);

        if (!valid) return;

        newsletterButton!.disabled = true;
        document.getElementById("newsletter-submit-error")?.remove();

        try {
            await sendNewsletterSignup({ email, action: nlAction });
            const banner = document.createElement("p");
            banner.className = "text-green-400 text-sm";
            banner.textContent = nlSuccess;
            newsletterForm!.replaceWith(banner);
        } catch {
            newsletterButton!.disabled = false;
            const el = document.createElement("p");
            el.id = "newsletter-submit-error";
            el.className = "text-red-400 text-xs pl-1";
            el.textContent = nlError;
            wrap.insertAdjacentElement("afterend", el);
        }
    });
}
