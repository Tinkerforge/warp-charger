/**
 * Remark plugin that rewrites generic "current device" documentation links to
 * the current generation at build time, so that a single config constant
 * controls where every generic link points.
 *
 *   [WARP Charger](@current-charger/introduction)        -> /docs/<charger>/introduction
 *   [WARP Energy Manager](@current-wem/introduction)      -> /docs/<wem>/introduction
 *
 * When a new generation ships, only the `charger` / `wem` options (set from the
 * CURRENT_CHARGER / CURRENT_WEM constants in docusaurus.config.ts) need to be
 * updated and every generic link follows.
 */
function currentDeviceLinks(options = {}) {
  const charger = options.charger || 'warp4';
  const wem = options.wem || 'wem2';

  const rewrite = (url) => {
    if (typeof url !== 'string') {
      return url;
    }
    if (url.startsWith('@current-charger/')) {
      return `/docs/${charger}/` + url.slice('@current-charger/'.length);
    }
    if (url.startsWith('@current-wem/')) {
      return `/docs/${wem}/` + url.slice('@current-wem/'.length);
    }
    return url;
  };

  const visit = (node) => {
    if (!node || typeof node !== 'object') {
      return;
    }
    if (node.type === 'link') {
      node.url = rewrite(node.url);
    }
    if (Array.isArray(node.children)) {
      node.children.forEach(visit);
    }
  };

  return (tree) => visit(tree);
}

module.exports = currentDeviceLinks;
