import type { ClientModule } from '@docusaurus/types';

// The API reference TOC used to append the hardware type to the fragment
// on every page, not only on API reference pages, so links such as
// #api-zähler-für-pv-überschuss_warp4 were shared. Outside of the API
// reference the headings have no such suffix: Strip it and scroll to
// the heading if the suffixed one does not exist.
const hardwareTypeSuffix = /_(warp1|warp2|warp3|warp4|wem|wem2|any)$/;

const clientModule: ClientModule = {
    onRouteDidUpdate({ location }) {
        if (location.pathname.includes('/interfaces/mqtt_http/api_reference'))
            return;

        if (!hardwareTypeSuffix.test(location.hash))
            return;

        const decode = (hash: string) => {
            try {
                return decodeURIComponent(hash.substring(1));
            } catch {
                return hash.substring(1);
            }
        };

        if (document.getElementById(decode(location.hash)))
            return;

        const hash = location.hash.replace(hardwareTypeSuffix, '');
        const element = document.getElementById(decode(hash));

        if (!element)
            return;

        history.replaceState(history.state, '', location.pathname + location.search + hash);
        element.scrollIntoView();
    },
};

export default clientModule;
