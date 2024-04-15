import React from 'react';
import Desktop from '@theme-original/DocItem/TOC/Desktop';
import type DesktopType from '@theme/DocItem/TOC/Desktop';
import type { WrapperProps } from '@docusaurus/types';

import Tabs from '@site/src/components/MultilineTabs';
import TabItem from '@theme/TabItem';

type Props = WrapperProps<typeof DesktopType>;

export default function DesktopWrapper(props: Props): JSX.Element {
    return (
        <>
            <Tabs groupId="apiType" queryString className='unique-tabs'>
                <TabItem value="http" label="HTTP (curl)"> </TabItem>
                <TabItem value="mqtt" label="MQTT (mosquitto)"> </TabItem>
            </Tabs>
            <hr />
            <Tabs groupId="hardwareType" queryString className='unique-tabs'>
                <TabItem value="warp1" label="WARP1 Charger">
                    <hr />
                    <Tabs groupId="chargerVariant" queryString className='unique-tabs'>
                        <TabItem value="smart" label="Smart"> </TabItem>
                        <TabItem value="pro" label="Pro"> </TabItem>
                    </Tabs>
                </TabItem>
                <TabItem value="warp2" label="WARP2 Charger">
                    <hr />
                    <Tabs groupId="chargerVariant" queryString className='unique-tabs'>
                        <TabItem value="smart" label="Smart"> </TabItem>
                        <TabItem value="pro" label="Pro"> </TabItem>
                    </Tabs>
                </TabItem>
                <TabItem value="warp3" label="WARP3 Charger">
                    <hr />
                    <Tabs groupId="chargerVariant" queryString className='unique-tabs'>
                        <TabItem value="smart" label="Smart"> </TabItem>
                        <TabItem value="pro" label="Pro"> </TabItem>
                    </Tabs>
                </TabItem>
                <TabItem value="wem" label="WARP Energy Manager"> </TabItem>
                <TabItem value="all" label="Alle Typen"> </TabItem>
            </Tabs>
            <hr />
            <Desktop {...props} />
        </>
    );
}
