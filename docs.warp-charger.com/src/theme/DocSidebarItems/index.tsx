import React from 'react';
import DocSidebarItems from '@theme-original/DocSidebarItems';
import type DocSidebarItemsType from '@theme/DocSidebarItems';
import type {WrapperProps} from '@docusaurus/types';
import useDocusaurusContext from '@docusaurus/useDocusaurusContext';
import DeviceSwitcherMenu, {type SwitcherDevice} from '@site/src/components/DeviceSwitcherMenu';

type Props = WrapperProps<typeof DocSidebarItemsType>;

// The switchable device families. The order is the order shown in the switcher
// (newest first).
const CHARGERS: SwitcherDevice[] = [
  {id: 'warp4', label: 'WARP4 Charger'},
  {id: 'warp3', label: 'WARP3 Charger'},
  {id: 'warp2', label: 'WARP2 Charger'},
  {id: 'warp1', label: 'WARP1 Charger'},
];
const ENERGY_MANAGERS: SwitcherDevice[] = [
  {id: 'wem2', label: 'WARP Energy Manager 2.0'},
  {id: 'wem1', label: 'WARP Energy Manager 1.0'},
];
const STANDS: SwitcherDevice[] = [
  {id: 'warp4_stand', label: 'WARP4 Ladesäule', labelEn: 'WARP4 Charger Stand'},
  {id: 'warp_ladesäule', label: 'WARP Ladesäule (Vorgängermodell)', labelEn: 'WARP Charger Stand (previous generation)'},
];

// Detects which switchable device family a sidebar category's children belong to
// by checking whether any item links to one of that family's pages.
function familyForItems(items: Props['items']): SwitcherDevice[] | null {
  if (!Array.isArray(items)) {
    return null;
  }
  const hrefs = items.flatMap((it) => 'href' in it && typeof it.href === 'string' ? [it.href] : []);
  if (hrefs.some((h) => /\/docs\/warp[1-4]\//.test(h))) {
    return CHARGERS;
  }
  if (hrefs.some((h) => /\/docs\/wem[12]\//.test(h))) {
    return ENERGY_MANAGERS;
  }
  if (hrefs.some((h) => /\/docs\/(warp4_stand|warp_lades(?:ä|%C3%A4)ule)\//i.test(h))) {
    return STANDS;
  }
  return null;
}

export default function DocSidebarItemsWrapper(props: Props): JSX.Element {
  const {i18n} = useDocusaurusContext();

  // Resolve the {locale} placeholder used in external download links so they
  // point at the download page in the current language (de/en).
  const items = props.items?.map((it) =>
    'href' in it && typeof it.href === 'string' && it.href.includes('{locale}')
      ? {...it, href: it.href.replace('{locale}', i18n.currentLocale)}
      : it,
  );

  const family = props.level === 2 ? familyForItems(items) : null;

  return (
    <>
      {/* Inject the device switcher as the first child of a device category. */}
      {family && <DeviceSwitcherMenu devices={family} />}
      <DocSidebarItems {...props} items={items} />
    </>
  );
}
