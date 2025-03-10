import React, { type ReactNode } from 'react';
import Link from '@docusaurus/Link';
import type {Props} from '@theme/MDXComponents/A';
import isInternalUrl from "@docusaurus/isInternalUrl";
import IconExternalLink from "@theme/Icon/ExternalLink";

// https://github.com/facebook/docusaurus/discussions/9138
export default function MDXA({ href, children, ...props }: Props): ReactNode {
    return <Link {...props} href={href}>
        {children}
        {!isInternalUrl(href) && <IconExternalLink />}
    </Link>
}
