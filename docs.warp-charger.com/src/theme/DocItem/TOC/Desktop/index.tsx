import React, { type ReactNode, useEffect } from 'react';
import Desktop from '@theme-original/DocItem/TOC/Desktop';
import type DesktopType from '@theme/DocItem/TOC/Desktop';
import type { WrapperProps } from '@docusaurus/types';

import { ThemeClassNames } from '@docusaurus/theme-common';
import { useDoc } from '@docusaurus/plugin-content-docs/client';

import TOC from '@theme/TOC';

import MultilineTabs from '@site/src/components/MultilineTabs';
import Tabs from '@theme/Tabs';
import TabItem from '@theme/TabItem';
import { TOCItem } from '@docusaurus/mdx-loader/lib/remark/toc/types';

import styles from '@docusaurus/theme-classic/src/theme/TOC/styles.module.css';

type Props = WrapperProps<typeof DesktopType>;

let interval: NodeJS.Timeout = null;
let scrollHandled = "foobar";

const hardwareTypes = ['warp1', 'warp2', 'warp3', 'wem', 'wem2', 'any'];

export default function DocItemTOCDesktop(props: Props): ReactNode {
    const { toc, frontMatter, metadata } = useDoc();

    // We are not in the API documentation. Show the default TOC.
    if (!metadata.sourceDirName.startsWith("interfaces/mqtt_http/api_reference"))
        return <Desktop {...props} />;

    // We are in the API documentation.
    // Show the api/hardwareType tabs and filter the TOC.

    // The user selected hardware type is stored in the localStorage and part of the query string.
    // If the page is loaded with a fragment that does not fit to
    // the hardware type (fragments are suffixed with the hardware
    // type of the function), rewrite the fragment to the selected
    // type so that the browser scrolls to the correct function.
    // Also allow setting the fragment _once_ even if it is already
    // correct to force the browser to scroll to the function if
    // the hardware type was not rendered in the first run.
    if (interval == null) {
        // Use effect to make sure the interval always runs after the first render
        useEffect(() => {
            interval = setInterval(() => {
                let storedHardwareType = window?.localStorage?.getItem("docusaurus.tab.hardwareType");
                let hardwareType = new URLSearchParams(window.location.search)?.get("hardwareType") ?? storedHardwareType ?? window.location.hash.split('_').slice(-1)[0];

                if (hardwareType == null) {
                    scrollHandled = "foobar";
                    return;
                }

                let hash = window.location.hash;

                if (hash.length == 0) {
                    scrollHandled = "foobar";
                    return;
                }

                let found = false;
                for (let x of hardwareTypes) {
                    if (hash.endsWith(x)) {
                        found = true;
                        let r = new RegExp(x + '$');
                        hash = hash.replace(r, hardwareType);
                        break;
                    }
                }

                if (!found) {
                    hash = hash + "_" + hardwareType;
                }

                if (window.location.hash == hash && scrollHandled == hardwareType + hash)
                    return;

                scrollHandled = hardwareType + hash;
                history.replaceState(null, "", window.location.pathname + window.location.search + hash)
                if (window.location.hash == hash) {
                    window.location.hash = '';
                    setTimeout(() => window.location.hash = hash, 0);
                }
                window.location.hash = hash;
            }, 100);
        }, []);
    }

    const filterToC = (toc: readonly TOCItem[], hardwareType: string) => {
        let level_filter = -1;
        let result: TOCItem[] = [];

        for(let x of toc) {
            if (level_filter != -1 && x.level > level_filter)
                continue;

            if (level_filter != -1 && x.level <= level_filter)
                level_filter = -1;

            if (hardwareType != "any"
                && "hardwareType" in x
                && (x.hardwareType as string[]).indexOf(hardwareType) == -1) {
                level_filter = x.level;
                continue;
            }

            result.push({...x, id: x.id + "_" + hardwareType});
        }

        return result;
    }

    const tocprops = {
        minHeadingLevel: frontMatter.toc_min_heading_level,
        maxHeadingLevel: frontMatter.toc_max_heading_level,
        className: ThemeClassNames.docs.docTocDesktop
    };

    return <div className={styles.tableOfContents}>
        <MultilineTabs groupId="apiType" queryString className='unique-tabs'>
            <TabItem value="http" label="HTTP (curl)"> </TabItem>
            <TabItem value="mqtt" label="MQTT (mosquitto)"> </TabItem>
        </MultilineTabs>
        <hr />
        <MultilineTabs groupId="hardwareType" queryString className='unique-tabs'>
            <TabItem value="warp1" label="WARP1 Charger"> </TabItem>
            <TabItem value="warp2" label="WARP2 Charger"> </TabItem>
            <TabItem value="warp3" label="WARP3 Charger"> </TabItem>
            <TabItem value="wem" label="WARP Energy Manager"> </TabItem>
            <TabItem value="wem2" label="WARP Energy Manager 2.0"> </TabItem>
            <TabItem value="any" label="Alle Typen"> </TabItem>
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
            <TabItem value="wem2" label="WARP Energy Manager 2.0">
                <TOC toc={filterToC(toc, "wem2")} {...tocprops} />
            </TabItem>
            <TabItem value="any" label="Alle Typen">
                <TOC toc={filterToC(toc, "any")} {...tocprops} />
            </TabItem>
        </Tabs>
    </div>;
}
