import React from 'react';
import type {Props} from '@theme/Footer/LinkItem';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';

export default function FooterLinkItem({item}: Props): JSX.Element {
  const {i18n} = useDocusaurusContext();
  const locale = i18n.currentLocale;

  let href = item.href;

  if (href?.includes('/de/')) {
    href = href.replace(
      '/de/',
      locale === 'en' ? '/en/' : '/de/',
    );
  }

  return (
    <a
      href={href}
      target="_blank"
      rel="noopener noreferrer"
    >
      {item.label}
    </a>
  );
}
