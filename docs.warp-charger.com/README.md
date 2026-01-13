# Website

The WARP documentation is built using [Docusaurus](https://docusaurus.io/), a modern static website generator.

### Installation

```sh
$ npm ci
```

### Local Development

```sh
$ npm run start
```

This command starts a local development server and opens up a browser window. Most changes are reflected live without having to restart the server.

### Build

```sh
$ npm run build
```

This command generates static content into the `build` directory and can be served using any static contents hosting service.

### Translations

```sh
$ npm run write-translations --locale en
```

When source files change, re-run write-translations to update (it appends new translations without overriding existing ones)
We use this for the menu.

This also generates some docusaurus internal translations (code.json, etc).
We just keep them as is and update them when docusaurus updates.
