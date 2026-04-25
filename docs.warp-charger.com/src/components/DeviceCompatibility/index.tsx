import React from 'react';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import Admonition from '@theme/Admonition';
import styles from './styles.module.css';

// TODO: Uncomment WARP4 when it is released.
const ALL_DEVICES = [
  { id: 'wc1', label: 'WARP1 Charger' },
  { id: 'wc2', label: 'WARP2 Charger' },
  { id: 'wc3', label: 'WARP3 Charger' },
  //{ id: 'wc4', label: 'WARP4 Charger' },
  { id: 'wem1', label: 'WARP Energy Manager 1' },
  { id: 'wem2', label: 'WARP Energy Manager 2' },
] as const;

export type DeviceId = (typeof ALL_DEVICES)[number]['id'];

interface Props {
  supported: DeviceId[];
}

const TITLES: Record<string, string> = {
  de: 'Verfügbar für',
  en: 'Available for',
};

export default function DeviceCompatibility({ supported }: Props): JSX.Element {
  const { i18n } = useDocusaurusContext();
  const title = TITLES[i18n.currentLocale] ?? TITLES.en;
  const supportedSet = new Set(supported);
  const devices = ALL_DEVICES.filter(({ id }) => supportedSet.has(id));

  return (
    <Admonition type="note" title={title}>
      <div className={styles.badges}>
        {devices.map(({ id, label }) => (
          <span key={id} className={styles.badge}>
            {label}
          </span>
        ))}
      </div>
    </Admonition>
  );
}
