import React from 'react';
import Link from '@docusaurus/Link';
import {useLocation} from '@docusaurus/router';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import Translate from '@docusaurus/Translate';
import {Collapsible, useCollapsible} from '@docusaurus/theme-common';
import clsx from 'clsx';
import styles from './styles.module.css';

export type SwitcherDevice = {id: string; label: string; labelEn?: string};

// "Swap" icon to signal that this entry switches between device generations.
function SwitchIcon(): JSX.Element {
  return (
    <svg
      className={styles.icon}
      viewBox="0 0 24 24"
      fill="none"
      stroke="currentColor"
      strokeWidth="2.2"
      strokeLinecap="round"
      strokeLinejoin="round"
      aria-hidden="true">
      <polyline points="17 1 21 5 17 9" />
      <path d="M3 11V9a4 4 0 0 1 4-4h14" />
      <polyline points="7 23 3 19 7 15" />
      <path d="M21 13v2a4 4 0 0 1-4 4H3" />
    </svg>
  );
}

/**
 * Device switcher rendered as a collapsible entry inside a device sidebar
 * category (so it works on desktop and mobile, and stays within the menu).
 * Two-step: expand "Generation wechseln", then pick a generation. It is styled
 * distinctly (smaller, accent color, icon) so it stands out from normal menu
 * entries.
 *
 * When the reader is on one of the given generations' pages (/docs/<id>/<rest>),
 * every entry links to the equivalent page of the other generations so that
 * switching keeps the reader on the same topic. Otherwise it links to each
 * generation's introduction.
 */
export default function DeviceSwitcherMenu({devices}: {devices: SwitcherDevice[]}): JSX.Element {
  const {pathname} = useLocation();
  const {i18n} = useDocusaurusContext();
  const {collapsed, toggleCollapsed} = useCollapsible({initialState: true});

  // Match /docs/<id>/<rest> independently of the locale prefix (/de, /en).
  const match = pathname.match(/\/docs\/([^/]+)(?:\/([^?#]*))?$/);
  const currentDevice = devices.find((d) =>
    match && (match[1] === d.id || match[1].toLowerCase() === encodeURIComponent(d.id).toLowerCase()),
  );
  const currentId = currentDevice?.id;
  const currentRest = currentDevice ? (match?.[2] ?? '').replace(/\/$/, '') : '';

  return (
    <li
      className={clsx(
        'theme-doc-sidebar-item-category',
        'menu__list-item',
        styles.switcher,
        collapsed && 'menu__list-item--collapsed',
      )}>
      <div className="menu__list-item-collapsible">
        <a
          className={clsx(
            'menu__link menu__link--sublist menu__link--sublist-caret',
            styles.toggle,
          )}
          role="button"
          aria-expanded={!collapsed}
          href="#"
          onClick={(e) => {
            e.preventDefault();
            toggleCollapsed();
          }}>
          <SwitchIcon />
          <Translate id="deviceSwitcher.changeGeneration">Generation wechseln</Translate>
        </a>
      </div>
      <Collapsible lazy={false} as="ul" className="menu__list" collapsed={collapsed}>
        {devices.map((d) => (
          <li className="menu__list-item" key={d.id}>
            <Link
              className={clsx(
                'menu__link',
                styles.link,
                d.id === currentId && 'menu__link--active',
                d.id === currentId && styles.activeLink,
              )}
              aria-current={d.id === currentId ? 'page' : undefined}
              to={currentRest ? `/docs/${d.id}/${currentRest}` : `/docs/${d.id}/introduction`}>
              {i18n.currentLocale === 'en' ? d.labelEn ?? d.label : d.label}
            </Link>
          </li>
        ))}
      </Collapsible>
    </li>
  );
}
