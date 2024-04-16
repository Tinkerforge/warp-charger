import React from 'react';
import Desktop from '@theme-original/DocItem/TOC/Desktop';
import type DesktopType from '@theme/DocItem/TOC/Desktop';
import type { WrapperProps } from '@docusaurus/types';

import { ThemeClassNames } from '@docusaurus/theme-common';
import { useDoc } from '@docusaurus/theme-common/internal';

import TOC from '@theme/TOC';

import MultilineTabs from '@site/src/components/MultilineTabs';
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import { TOCItem } from '@docusaurus/mdx-loader/lib/remark/toc/types';

type Props = WrapperProps<typeof DesktopType>;

export default function DocItemTOCDesktop(props: Props): JSX.Element {
    const { toc, frontMatter, metadata } = useDoc();

    // We are not in the API documentation. Show the default TOC.
    if (!metadata.sourceDirName.startsWith("mqtt_http"))
        return <Desktop {...props} />;

    // We are in the API documentation.
    // Show the api/hardwareType tabs and filter the TOC.

    const filterToC = (toc: readonly TOCItem[], hardwareType: string) =>
        toc.filter(x => !("hardwareType" in x)
            || x.hardwareType as string == hardwareType
            || x.hardwareType == "all"
            || hardwareType == "all")
            .map(x => (!("children" in x)
                || (x.children as TOCItem[]).length == 0)
                ? x
                : { ...x, children: filterToC(x.children as TOCItem[], hardwareType) })

    const tocprops = {
        minHeadingLevel: frontMatter.toc_min_heading_level,
        maxHeadingLevel: frontMatter.toc_max_heading_level,
        className: ThemeClassNames.docs.docTocDesktop
    };

    return <>
        <MultilineTabs groupId="apiType" queryString className='unique-tabs'>
            <TabItem value="http" label="HTTP (curl)"> </TabItem>
            <TabItem value="mqtt" label="MQTT (mosquitto)"> </TabItem>
        </MultilineTabs>
        <hr />
        <MultilineTabs groupId="hardwareType" queryString className='unique-tabs'>
            <TabItem value="warp1" label="WARP1 Charger">
                <hr />
                <MultilineTabs groupId="chargerVariant" queryString className='unique-tabs'>
                    <TabItem value="smart" label="Smart"> </TabItem>
                    <TabItem value="pro" label="Pro"> </TabItem>
                </MultilineTabs>
            </TabItem>
            <TabItem value="warp2" label="WARP2 Charger">
                <hr />
                <MultilineTabs groupId="chargerVariant" queryString className='unique-tabs'>
                    <TabItem value="smart" label="Smart"> </TabItem>
                    <TabItem value="pro" label="Pro"> </TabItem>
                </MultilineTabs>
            </TabItem>
            <TabItem value="warp3" label="WARP3 Charger">
                <hr />
                <MultilineTabs groupId="chargerVariant" queryString className='unique-tabs'>
                    <TabItem value="smart" label="Smart"> </TabItem>
                    <TabItem value="pro" label="Pro"> </TabItem>
                </MultilineTabs>
            </TabItem>
            <TabItem value="wem" label="WARP Energy Manager"> </TabItem>
            <TabItem value="all" label="Alle Typen"> </TabItem>
        </MultilineTabs>

        <hr />

        <Tabs groupId="hardwareType" queryString className='hidden-tabs'>
            <TabItem value="warp1" label="WARP1 Charger">
                <TOC toc={filterToC(toc, "warp1")} {...tocprops} />
            </TabItem>
            <TabItem value="warp2" label="WARP2 Charger">
                <TOC toc={filterToC(toc, "warp2")} {...tocprops} />
            </TabItem>
            <TabItem value="warp3" label="WARP3 Charger">
                <TOC toc={filterToC(toc, "warp3")} {...tocprops} />
            </TabItem>
            <TabItem value="wem" label="WARP Energy Manager">
                <TOC toc={filterToC(toc, "wem")} {...tocprops} />
            </TabItem>
            <TabItem value="all" label="Alle Typen">
                <TOC toc={toc} {...tocprops} />
            </TabItem>
        </Tabs>
    </>;
}
