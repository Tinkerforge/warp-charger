import React from 'react';
import Link from '@docusaurus/Link';
import useBaseUrl from '@docusaurus/useBaseUrl';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import styles from './styles.module.css';

type Lang = 'de' | 'en';
type Text = Record<Lang, string>;

const T = {
  kicker: {de: 'WARP by Tinkerforge', en: 'WARP by Tinkerforge'},
  title: {de: 'Dokumentation', en: 'Documentation'},
  lead: {
    de: 'Installation, Einrichtung und Schnittstellen von WARP Charger, WARP Energy Manager und WARP Ladesäule.',
    en: 'Installation, setup and interfaces of the WARP Charger, WARP Energy Manager and WARP Charger Stand.',
  },
  firstSteps: {de: 'Erste Schritte', en: 'First Steps'},
  older: {de: 'Ältere Generationen', en: 'Older Generations'},
} satisfies Record<string, Text>;

const PRODUCTS: {name: Text | string; to: string; img: string; older: {label: Text | string; to: string}[]}[] = [
  {
    name: 'WARP4 Charger',
    to: '/docs/warp4/introduction',
    img: '/img/home/warp4-charger.webp',
    older: [
      {label: 'WARP3', to: '/docs/warp3/introduction'},
      {label: 'WARP2', to: '/docs/warp2/introduction'},
      {label: 'WARP1', to: '/docs/warp1/introduction'},
    ],
  },
  {
    name: 'WARP Energy Manager 2.0',
    to: '/docs/wem2/introduction',
    img: '/img/home/energy-manager-2.webp',
    older: [{label: 'WEM1', to: '/docs/wem1/introduction'}],
  },
  {
    name: {de: 'WARP4 Ladesäule', en: 'WARP4 Charger Stand'},
    to: '/docs/warp4_stand/introduction',
    img: '/img/home/warp-charger-stand.webp',
    older: [{label: {de: 'Vorgängermodell', en: 'Previous generation'}, to: '/docs/warp_ladesäule/introduction'}],
  },
];

export default function HomeOverview(): JSX.Element {
  const {i18n} = useDocusaurusContext();
  const lang: Lang = i18n.currentLocale === 'de' ? 'de' : 'en';
  const t = (x: Text | string) => (typeof x === 'string' ? x : x[lang]);

  return (
    <div className={styles.home}>
      <section className={styles.hero}>
        <div className={styles.heroText}>
          <div className={styles.kicker}>{t(T.kicker)}</div>
          <h1 className={styles.title}>{t(T.title)}</h1>
          <p className={styles.lead}>{t(T.lead)}</p>
          <div className={styles.buttons}>
            <Link className={styles.btnPrimary} to="/docs/tutorials/first_steps">{t(T.firstSteps)}</Link>
          </div>
        </div>
        <img className={styles.heroImage} src={useBaseUrl('/img/home/warp4-charger.webp')} alt="" />
      </section>

      <div className={styles.products}>
        {PRODUCTS.map((p) => (
          <div key={p.to} className={styles.product}>
            <Link to={p.to} className={styles.productMain}>
              <div className={styles.productImage}>
                <img src={useBaseUrl(p.img)} alt={t(p.name)} loading="lazy" />
              </div>
              <div className={styles.productName}>{t(p.name)}</div>
            </Link>
            <div className={styles.older}>
              <span className={styles.olderLabel}>{t(T.older)}:</span>{' '}
              {p.older.map((o, i) => (
                <React.Fragment key={o.to}>
                  {i > 0 && ' · '}
                  <Link to={o.to}>{t(o.label)}</Link>
                </React.Fragment>
              ))}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}
