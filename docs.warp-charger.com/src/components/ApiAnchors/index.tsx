import useBrokenLinks from '@docusaurus/useBrokenLinks';

interface Props {
  ids: string[];
}

// The headings of the API reference have the hardware type as suffix
// (e.g. evse_state_warp4). Links point to the function without suffix
// (e.g. #evse_state), the suffix is added by src/theme/DocItem/TOC/Desktop.
// Register the anchors without suffix, so that the broken anchor check
// of Docusaurus accepts those links. Renders nothing.
export default function ApiAnchors({ ids }: Props): null {
  const brokenLinks = useBrokenLinks();

  for (const id of ids) {
    brokenLinks.collectAnchor(id);
  }

  return null;
}
