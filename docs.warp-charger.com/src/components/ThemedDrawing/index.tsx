import React from 'react';
import ThemedImage from '@theme/ThemedImage';
import useBaseUrl from '@docusaurus/useBaseUrl';

// Line drawing with a dark-mode variant next to it: foo.svg -> foo.dark.svg (black text and lines replaced by the dark-mode text color)
export default function ThemedDrawing({src, alt, href}: {src: string; alt: string; href?: string}): JSX.Element {
  const light = useBaseUrl(src);
  const dark = useBaseUrl(src.replace(/\.svg$/, '.dark.svg'));
  const link = useBaseUrl(href ?? '');
  const image = <ThemedImage alt={alt} sources={{light, dark}} loading="lazy" style={{width: '100%', height: 'auto'}} />;
  return href ? <a href={link}>{image}</a> : image;
}
