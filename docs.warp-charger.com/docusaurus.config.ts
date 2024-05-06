import {themes as prismThemes} from 'prism-react-renderer';
import type {Config} from '@docusaurus/types';
import type * as Preset from '@docusaurus/preset-classic';

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
  onBrokenMarkdownLinks: 'warn',

  // Even if you don't use internationalization, you can use this field to set
  // useful metadata like html lang. For example, if your site is Chinese, you
  // may want to replace "en" with "zh-Hans".
  i18n: {
    defaultLocale: 'de',
    locales: ['de'],
  },

  presets: [
    [
      'classic',
      {
        docs: {
          sidebarPath: './sidebars.ts',
          // Please change this to your repo.
          // Remove this to remove the "edit this page" links.
          editUrl:
            'https://github.com/Tinkerforge/warp-charger/docs.warp-charger.com/',
        },
        theme: {
          customCss: './src/css/custom.css',
        },
      } satisfies Preset.Options,
    ],
  ],

  themeConfig: {
    algolia: {
      // The application ID provided by Algolia
      appId: 'WDTZV3KHAX',

      // Public API key: it is safe to commit it
      apiKey: 'ebf6f72368963d7ad6070e373b771762',

      indexName: 'warp-charger',

      // Optional: see doc section below
//      contextualSearch: true,

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
//      searchPagePath: 'search',

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
      },
      items: [
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
};

export default config;
