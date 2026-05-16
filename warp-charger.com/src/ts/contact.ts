interface ContactFormData {
    name: string;
    email: string;
    message: string;
}

interface NewsletterData {
    email: string;
}

// Backend Placeholders

async function sendContactForm(_data: ContactFormData): Promise<void> {
    throw new Error("Backend not yet implemented");
}

async function sendNewsletterSignup(_data: NewsletterData): Promise<void> {
    throw new Error("Backend not yet implemented");
}

// Validation

const EMAIL_RE = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

function validateForm(
    name: string,
    email: string,
    message: string,
): Record<string, boolean> {
    const errors: Record<string, boolean> = {};
    if (!name.trim()) errors.name = true;
    if (!EMAIL_RE.test(email.trim())) errors.email = true;
    if (!message.trim()) errors.message = true;
    return errors;
}

// UI Helpers

function setFieldError(field: string, hasError: boolean): void {
    const wrap = document.getElementById(`wrap-${field}`) as HTMLElement | null;
    const msg = document.getElementById(`error-${field}`) as HTMLElement | null;
    if (!wrap || !msg) return;
    const defaultBorder = wrap.dataset.border ?? "";
    wrap.classList.toggle("border-red-500", hasError);
    wrap.classList.toggle(defaultBorder, !hasError);
    msg.classList.toggle("hidden", !hasError);
}

function clearFieldError(field: string): void {
    setFieldError(field, false);
}

function setSubmitting(button: HTMLButtonElement, isSubmitting: boolean, i18n: { submitting: string; submit: string }): void {
    button.disabled = isSubmitting;
    button.textContent = isSubmitting ? i18n.submitting : i18n.submit;
}

function showSuccessBanner(form: HTMLElement, message: string): void {
    const banner = document.createElement("p");
    banner.className = "text-green-400 text-sm text-center";
    banner.textContent = message;
    form.replaceWith(banner);
}

function showSubmitError(button: HTMLElement, message: string): void {
    const msg = button.nextElementSibling;
    if (msg?.id === "submit-error") return;
    const el = document.createElement("p");
    el.id = "submit-error";
    el.className = "text-red-400 text-xs text-center";
    el.textContent = message;
    button.insertAdjacentElement("afterend", el);
}

// Init: Contact Form

const form = document.getElementById("contact-form") as HTMLFormElement | null;
const button = document.getElementById("contact-submit") as HTMLButtonElement | null;

if (form && button) {
    const i18n = {
        submitting: form.dataset.i18nSubmitting ?? "Sending…",
        submit: form.dataset.i18nSubmit ?? "Submit",
        success: form.dataset.i18nSuccess ?? "Thank you!",
        error: form.dataset.i18nError ?? "Something went wrong.",
        newsletterSuccess: form.dataset.i18nNewsletterSuccess ?? "Thank you!",
        newsletterError: form.dataset.i18nNewsletterError ?? "Something went wrong.",
    };

    (["name", "email", "message"] as const).forEach((field) => {
        const el = document.getElementById(`footer-${field}`);
        el?.addEventListener("input", () => clearFieldError(field));
    });

    form.addEventListener("submit", async (e: Event) => {
        e.preventDefault();

        const name = (document.getElementById("footer-name") as HTMLInputElement).value;
        const email = (document.getElementById("footer-email") as HTMLInputElement).value;
        const message = (document.getElementById("footer-message") as HTMLTextAreaElement).value;

        const errors = validateForm(name, email, message);

        (["name", "email", "message"] as const).forEach((field) => {
            setFieldError(field, !!errors[field]);
        });

        if (Object.keys(errors).length > 0) return;

        setSubmitting(button!, true, i18n);
        document.getElementById("submit-error")?.remove();

        try {
            await sendContactForm({ name, email, message });
            showSuccessBanner(form!, i18n.success);
        } catch {
            setSubmitting(button!, false, i18n);
            showSubmitError(button!, i18n.error);
        }
    });
}

// Init: Newsletter Form

const newsletterForm = document.getElementById("newsletter-form") as HTMLFormElement | null;
const newsletterButton = document.getElementById("newsletter-submit") as HTMLButtonElement | null;

if (newsletterForm && newsletterButton) {
    const input = document.getElementById("newsletter-email") as HTMLInputElement;
    const wrap = document.getElementById("wrap-newsletter") as HTMLElement;
    const error = document.getElementById("error-newsletter") as HTMLElement;

    // Read i18n from the contact form element (shared container for all footer i18n)
    const i18nSource = document.getElementById("contact-form");
    const nlSuccess = i18nSource?.dataset.i18nNewsletterSuccess ?? "Thank you!";
    const nlError = i18nSource?.dataset.i18nNewsletterError ?? "Something went wrong.";

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
            await sendNewsletterSignup({ email });
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
