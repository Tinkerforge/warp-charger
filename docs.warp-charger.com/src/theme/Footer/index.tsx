// Copy of the warp-charger.com footer (warp-charger.com/templates/partials/footer.html,
// texts from translations/{de,en}/footer.yaml). Keep both in sync.
import React, {useState} from 'react';
import useBaseUrl from '@docusaurus/useBaseUrl';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import styles from './styles.module.css';

const WEBSITE = 'https://warp-charger.com';
const EMAIL_RE = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

type Lang = 'de' | 'en';

const TEXT = {
  de: {
    info_label: 'Info',
    about_link: 'Über uns',
    find_electrician_link: 'Elektriker finden',
    forum_link: 'Community-Forum',
    downloads_link: 'Downloads',
    shop_link: 'Shop',
    privacy_link: 'Datenschutz',
    imprint_link: 'Impressum',
    terms_link: 'AGB',
    withdrawal_link: 'Widerrufsrecht',
    contact_label: 'Kontakt',
    contact_headline: 'Sprechen Sie mit',
    contact_highlight: 'unserem Team.',
    phone_hint: 'Mo–Fr, 8–17 Uhr',
    newsletter_label: 'Newsletter',
    newsletter_placeholder: 'E-Mail',
    newsletter_error: 'Bitte geben Sie eine gültige E-Mail-Adresse ein.',
    newsletter_success:
      'Fast geschafft! Bitte bestätigen Sie Ihre Anmeldung über den Link in der E-Mail, die wir Ihnen gerade gesendet haben.',
    newsletter_submit_error: 'Etwas ist schiefgelaufen. Bitte versuchen Sie es erneut.',
    about_path: 'ueber-uns/unternehmen',
    electrician_path: 'elektriker-finden',
  },
  en: {
    info_label: 'Info',
    about_link: 'About Us',
    find_electrician_link: 'Find an Electrician',
    forum_link: 'Community Forum',
    downloads_link: 'Downloads',
    shop_link: 'Shop',
    privacy_link: 'Privacy',
    imprint_link: 'Imprint',
    terms_link: 'Terms',
    withdrawal_link: 'Right of Withdrawal',
    contact_label: 'Contact',
    contact_headline: 'Talk to',
    contact_highlight: 'our team.',
    phone_hint: 'Mon–Fri, 8–17',
    newsletter_label: 'Newsletter',
    newsletter_placeholder: 'Email',
    newsletter_error: 'Please enter a valid email address.',
    newsletter_success: 'Almost done! Please confirm your subscription via the link in the email we just sent you.',
    newsletter_submit_error: 'Something went wrong. Please try again.',
    about_path: 'about/company',
    electrician_path: 'find-electrician',
  },
};

// Material Symbols Outlined 400 (Apache License 2.0), 24 x 24 viewBox
const ICON_CALL =
  'M19.95 21Q16.82 21 13.78 19.64Q10.73 18.27 8.22 15.78Q5.73 13.27 4.36 10.22Q3 7.18 3 4.05Q3 3.6 3.3 3.3Q3.6 3 4.05 3H8.1Q8.45 3 8.73 3.24Q9 3.47 9.05 3.8L9.7 7.3Q9.75 7.7 9.68 7.97Q9.6 8.25 9.4 8.45L6.98 10.9Q7.48 11.82 8.16 12.69Q8.85 13.55 9.68 14.35Q10.45 15.12 11.3 15.79Q12.15 16.45 13.1 17L15.45 14.65Q15.68 14.42 16.04 14.31Q16.4 14.2 16.75 14.25L20.2 14.95Q20.55 15.05 20.77 15.31Q21 15.57 21 15.9V19.95Q21 20.4 20.7 20.7Q20.4 21 19.95 21ZM6.03 9 7.68 7.35Q7.68 7.35 7.68 7.35Q7.68 7.35 7.68 7.35L7.25 5Q7.25 5 7.25 5Q7.25 5 7.25 5H5.03Q5.03 5 5.03 5Q5.03 5 5.03 5Q5.15 6.02 5.38 7.02Q5.6 8.02 6.03 9ZM14.98 17.95Q15.95 18.38 16.96 18.62Q17.98 18.88 19 18.95Q19 18.95 19 18.95Q19 18.95 19 18.95V16.75Q19 16.75 19 16.75Q19 16.75 19 16.75L16.65 16.27Q16.65 16.27 16.65 16.27Q16.65 16.27 16.65 16.27ZM6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9Q6.03 9 6.03 9ZM14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Q14.98 17.95 14.98 17.95Z';
const ICON_MAIL =
  'M4 20Q3.18 20 2.59 19.41Q2 18.82 2 18V6Q2 5.18 2.59 4.59Q3.18 4 4 4H20Q20.83 4 21.41 4.59Q22 5.18 22 6V18Q22 18.82 21.41 19.41Q20.83 20 20 20ZM12 13 4 8V18Q4 18 4 18Q4 18 4 18H20Q20 18 20 18Q20 18 20 18V8ZM12 11 20 6H4ZM4 8V6V8V18Q4 18 4 18Q4 18 4 18Q4 18 4 18Q4 18 4 18Z';

const SOCIAL = [
  {
    label: 'GitHub',
    href: 'https://github.com/Tinkerforge',
    path: 'M12 0C5.37 0 0 5.37 0 12c0 5.31 3.435 9.795 8.205 11.385.6.105.825-.255.825-.57 0-.285-.015-1.23-.015-2.235-3.015.555-3.795-.735-4.035-1.41-.135-.345-.72-1.41-1.23-1.695-.42-.225-1.02-.78-.015-.795.945-.015 1.62.87 1.845 1.23 1.08 1.815 2.805 1.305 3.495.99.105-.78.42-1.305.765-1.605-2.67-.3-5.46-1.335-5.46-5.925 0-1.305.465-2.385 1.23-3.225-.12-.3-.54-1.53.12-3.18 0 0 1.005-.315 3.3 1.23.96-.27 1.98-.405 3-.405s2.04.135 3 .405c2.295-1.56 3.3-1.23 3.3-1.23.66 1.65.24 2.88.12 3.18.765.84 1.23 1.905 1.23 3.225 0 4.605-2.805 5.625-5.475 5.925.435.375.81 1.095.81 2.22 0 1.605-.015 2.895-.015 3.3 0 .315.225.69.825.57A12.02 12.02 0 0 0 24 12c0-6.63-5.37-12-12-12z',
  },
];

type NewsletterState = 'idle' | 'invalid' | 'sending' | 'error' | 'done';

function Newsletter({lang}: {lang: Lang}): JSX.Element {
  const t = TEXT[lang];
  const [email, setEmail] = useState('');
  const [state, setState] = useState<NewsletterState>('idle');

  if (state === 'done') {
    return <p className={styles.newsletterSuccess}>{t.newsletter_success}</p>;
  }

  const submit = async (e: React.FormEvent) => {
    e.preventDefault();
    if (!EMAIL_RE.test(email.trim())) {
      setState('invalid');
      return;
    }
    setState('sending');
    try {
      // Plain form POST without custom headers: a simple cross-origin request,
      // the website allows docs.warp-charger.com to read the response.
      const res = await fetch(`${WEBSITE}/${lang}/newsletter`, {
        method: 'POST',
        body: new URLSearchParams({email}),
      });
      if (!res.ok) throw new Error(String(res.status));
      setState('done');
    } catch {
      setState('error');
    }
  };

  return (
    <form onSubmit={submit} noValidate>
      <div className={`${styles.newsletterField} ${state === 'invalid' ? styles.newsletterInvalid : ''}`}>
        <input
          type="email"
          name="newsletter"
          value={email}
          onChange={(e) => {
            setEmail(e.target.value);
            if (state === 'invalid' || state === 'error') setState('idle');
          }}
          placeholder={t.newsletter_placeholder}
          aria-label={t.newsletter_label}
        />
        <button type="submit" disabled={state === 'sending'} aria-label={t.newsletter_label}>
          <span className={styles.divider} />
          <svg viewBox="0 0 5 9" fill="none" aria-hidden="true">
            <path d="M0.5 0.5L4.5 4.5L0.5 8.5" stroke="#1E55C3" strokeLinecap="round" strokeLinejoin="round" />
          </svg>
        </button>
      </div>
      {state === 'invalid' && <p className={styles.newsletterError}>{t.newsletter_error}</p>}
      {state === 'error' && <p className={styles.newsletterError}>{t.newsletter_submit_error}</p>}
    </form>
  );
}

function Footer(): JSX.Element {
  const {i18n} = useDocusaurusContext();
  const lang: Lang = i18n.currentLocale === 'de' ? 'de' : 'en';
  const t = TEXT[lang];
  const warpLogo = useBaseUrl('/img/footer/warp-logo-subtext.svg');
  const tfLogo = useBaseUrl('/img/footer/tinkerforge-logo.svg');

  return (
    <footer className={styles.footer}>
      <div className={styles.container}>
        <div className={styles.grid}>
          <div className={styles.card}>
            <div className={styles.cardHead}>
              <span className={styles.eyebrow}>{t.contact_label}</span>
              <p className={styles.headline}>
                {t.contact_headline} <span>{t.contact_highlight}</span>
              </p>
            </div>
            <address className={styles.address}>
              <div className={styles.contactRow}>
                <svg className={styles.contactIcon} viewBox="0 0 24 24" aria-hidden="true">
                  <path d={ICON_CALL} />
                </svg>
                <div className={styles.contactText}>
                  <a href="tel:+4952078973000" className={styles.contactLink}>+49 5207 897300-0</a>
                  <span className={styles.phoneHint}>{t.phone_hint}</span>
                </div>
              </div>
              <div className={styles.contactRow}>
                <svg className={styles.contactIcon} viewBox="0 0 24 24" aria-hidden="true">
                  <path d={ICON_MAIL} />
                </svg>
                <a href="mailto:info@tinkerforge.com" className={`${styles.contactLink} ${styles.breakAll}`}>
                  info@tinkerforge.com
                </a>
              </div>
            </address>
          </div>

          <div className={styles.right}>
            <div className={styles.infoRow}>
              <div className={styles.infoCol}>
                <span className={styles.eyebrow}>{t.info_label}</span>
                <nav className={styles.nav}>
                  <a href={`${WEBSITE}/${lang}/${t.about_path}`}>{t.about_link}</a>
                  <a href={`${WEBSITE}/${lang}/${t.electrician_path}`}>{t.find_electrician_link}</a>
                  <a href="https://www.tinkerunity.org/forum/13-warp-charger/">{t.forum_link}</a>
                  <a href={`${WEBSITE}/${lang}/software/downloads`}>{t.downloads_link}</a>
                  <a href={`https://shop.warp-charger.com/${lang}/`}>{t.shop_link}</a>
                </nav>
              </div>
              <div className={styles.logos}>
                <img src={warpLogo} loading="lazy" alt="WARP Logo" />
                <img src={tfLogo} loading="lazy" alt="Tinkerforge Logo" />
              </div>
            </div>
            <div className={styles.newsletter}>
              <span className={styles.eyebrow}>{t.newsletter_label}</span>
              <Newsletter lang={lang} />
            </div>
          </div>
        </div>

        <div className={styles.bottom}>
          <div className={styles.social}>
            {SOCIAL.map((s) => (
              <a key={s.label} href={s.href} aria-label={s.label}>
                <svg viewBox="0 0 24 24" fill="currentColor" aria-hidden="true">
                  <path d={s.path} />
                </svg>
              </a>
            ))}
          </div>
          <ul className={styles.legal}>
            <li><a href={`https://www.tinkerforge.com/${lang}/home/privacy_notice/`}>{t.privacy_link}</a></li>
            <li aria-hidden="true">·</li>
            <li><a href={`https://www.tinkerforge.com/${lang}/home/legal_info/`}>{t.imprint_link}</a></li>
            <li aria-hidden="true">·</li>
            <li><a href={`https://www.tinkerforge.com/${lang}/home/terms_and_conditions/`}>{t.terms_link}</a></li>
            <li aria-hidden="true">·</li>
            <li><a href={`https://www.tinkerforge.com/${lang}/home/right_of_revocation/`}>{t.withdrawal_link}</a></li>
          </ul>
          <p className={styles.copyright}>Copyright © {new Date().getFullYear()} Tinkerforge GmbH</p>
        </div>
      </div>
    </footer>
  );
}

export default React.memo(Footer);
