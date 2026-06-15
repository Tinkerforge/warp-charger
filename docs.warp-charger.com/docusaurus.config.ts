import {themes as prismThemes} from 'prism-react-renderer';
import type {Config} from '@docusaurus/types';
import type * as Preset from '@docusaurus/preset-classic';
import currentDeviceLinks from './src/remark/currentDeviceLinks';

// The current device generations. Generic "WARP Charger" / "WARP Energy Manager"
// documentation links point at the stable alias URLs /docs/warp_charger/* and
// /docs/warp_energy_manager/*, which are redirected here. When a new generation
// ships (e.g. warp5 / wem3), updating these two constants repoints every generic
// link and the legacy URLs to the new generation.
const CURRENT_CHARGER = 'warp4';
const CURRENT_WEM = 'wem2';

const config: Config = {
  title: 'WARP Dokumentation',
  tagline: 'Dokumentation für WARP Charger, Ladesäule und Energy Manager',
  favicon: 'img/favicon.png',

  // Set the production url of your site here
  url: 'https://docs.warp-charger.com',
  // Set the /<baseUrl>/ pathname under which your site is served
  // For GitHub pages deployment, it is often '/<projectName>/'
  baseUrl: '/',

  // GitHub pages deployment config.
  // If you aren't using GitHub pages, you don't need these.
  organizationName: 'Tinkerforge', // Usually your GitHub org/user name.
  projectName: 'warp-charger', // Usually your repo name.

  onBrokenLinks: 'throw',

  // Even if you don't use internationalization, you can use this field to set
  // useful metadata like html lang. For example, if your site is Chinese, you
  // may want to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'de',
    locales: ['de', 'en'],
    localeConfigs: {
      de: {
        baseUrl: '/de/'
      },
      en: {
        baseUrl: '/en/'
      },
    },
  },

  presets: [
    [
      'classic',
      {
        docs: {
          sidebarPath: './sidebars.ts',
          routeBasePath: 'docs',
          beforeDefaultRemarkPlugins: [
            [currentDeviceLinks, {charger: CURRENT_CHARGER, wem: CURRENT_WEM}],
          ],
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/Tinkerforge/warp-charger/edit/master/docs.warp-charger.com/',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      } satisfies Preset.Options,
    ],
  ],

  plugins: [
    [
      '@docusaurus/plugin-client-redirects',
      {
        // Redirect the stable "current generation" aliases and the legacy paths
        // to their target. The locale prefix (/de, /en) is preserved.
        //   /docs/warp_charger/*        -> current charger generation
        //   /docs/warp_energy_manager/* -> current WEM generation
        //   /docs/warp4_charger/*       -> warp4 (version-specific legacy folder)
        createRedirects(existingPath: string) {
          const redirects: string[] = [];
          const match = (dir: string) =>
            existingPath.match(new RegExp(`^(.*/docs/)${dir}/(.+)$`));

          let m = match(CURRENT_CHARGER);
          if (m) redirects.push(`${m[1]}warp_charger/${m[2]}`);

          m = match(CURRENT_WEM);
          if (m) redirects.push(`${m[1]}warp_energy_manager/${m[2]}`);

          m = match('warp4');
          if (m) redirects.push(`${m[1]}warp4_charger/${m[2]}`);

          return redirects.length > 0 ? redirects : undefined;
        },
      },
    ],
  ],

  themeConfig: {
    algolia: {
      // The application ID provided by Algolia
      appId: 'WDTZV3KHAX',

      // Public API key: it is safe to commit it
      apiKey: '7e97a190bd91b4399f37ba2a3f42f3f4',

      indexName: 'warp-charger',

      // Optional: see doc section below
      contextualSearch: true,

      // Optional: Specify domains where the navigation should occur through window.location instead on history.push. Useful when our Algolia config crawls multiple documentation sites and we want to navigate with window.location.href to them.
//      externalUrlRegex: '',

      // Optional: Replace parts of the item URLs from Algolia. Useful when using the same search index for multiple deployments using a different baseUrl. You can use regexp or string in the `from` param. For example: localhost:3000 vs myCompany.com/docs
//      replaceSearchResultPathname: {
//	     from: '/docs/', // or as RegExp: /\/docs\//
//        to: '/',
//      },

      // Optional: Algolia search parameters
//      searchParameters: {},

      // Optional: path for search page that enabled by default (`false` to disable it)
      searchPagePath: 'search',

      // Optional: whether the insights feature is enabled or not on Docsearch (`false` by default)
//      insights: false,

      //... other Algolia params
    },
    // Replace with your project's social card
    // image: '',
    navbar: {
      style: 'dark',
      title: 'Dokumentation',
      logo: {
        alt: 'WARP Logo',
        src: 'img/logo.png',
        height: '25px',
        href: '/docs/home',
      },
      items: [
        {
          type: 'localeDropdown',
          position: 'right',
        },
        {
          href: 'https://warp-charger.com',
          label: 'warp-charger.com',
          position: 'right',
        },
        {
          href: 'https://www.tinkerunity.org/forum/13-warp-charger/',
          label: 'Community-Forum',
          position: 'right',
        },
        {
          href: 'https://github.com/Tinkerforge',
          label: 'GitHub',
          position: 'right',
        },
      ],
    },
    footer: {
      style: 'dark',
      links: [
        {
          title: 'Links',
          items: [
            {
              label: 'WARP Dokumentation',
              to: '/docs/home',
            },
            {
              label: 'warp-charger.com',
              href: 'https://warp-charger.com',
            },
            {
              href: 'https://www.tinkerunity.org/forum/13-warp-charger/',
              label: 'Community-Forum',
            },
          ],
        },
        {
          title: 'Contribute',
          items: [

            {
              label: 'GitHub',
              href: 'https://github.com/Tinkerforge',
            },
          ],
        },
        {
          title: 'Legal',
          items: [

            {
              label: 'Impressum',
              href: 'https://www.tinkerforge.com/de/home/legal_info/',
            },
            {
              label: 'Datenschutz',
              href: 'https://www.tinkerforge.com/de/home/privacy_notice/',
            },
            {
              label: 'AGB',
              href: 'https://www.tinkerforge.com/de/home/terms_and_conditions/',
            },
          ],
        },
      ],
      copyright: `Copyright © ${new Date().getFullYear()} Tinkerforge GmbH.`,
    },
    prism: {
      theme: prismThemes.github,
      darkTheme: prismThemes.dracula,
      additionalLanguages: ['bash'],
    },
  } satisfies Preset.ThemeConfig,

  markdown: {
    mermaid: true,
    hooks: {
      onBrokenMarkdownLinks: 'warn',
    },
  },
  themes: ['@docusaurus/theme-mermaid'],
};

export default config;
