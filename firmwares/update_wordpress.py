#!/usr/bin/env -S python3 -u

import sys
import argparse
import urllib.request
import json
import re
import html
from base64 import b64encode

firmware_types = [
    'warp3',
    'warp2',
    'warp',
    'wem2',
    'wem',
]

firmware_type_to_env_name = {
    'warp':  'warp',
    'warp2': 'warp2',
    'warp3': 'warp3',
    'wem':   'energy_manager',
    'wem2':  'energy_manager_v2',
}

firmware_type_to_wordpress_id = {
    'warp':  'warp1',
    'warp2': 'warp2',
    'warp3': 'warp3',
    'wem':   'wem',
    'wem2':  'wem2',
}

firmware_type_to_display_name = {
    'warp':  'WARP1 Charger',
    'warp2': 'WARP2 Charger',
    'warp3': 'WARP3 Charger',
    'wem':   'WARP Energy Manager',
    'wem2':  'WARP Energy Manager 2.0',
}

firmware_type_prefix = '''
<!-- wp:uagb/container {{"block_id":"{block_id_1}","widthDesktop":90,"widthMobile":96,"alignItemsTablet":"center","alignItemsMobile":"center","alignContentDesktop":"center","backgroundType":"color","backgroundColor":"var(\\u002d\\u002dast-global-color-4)","boxShadowVOffset":18,"boxShadowBlur":40,"boxShadowSpread":-10,"boxShadowVOffsetHover":20,"boxShadowBlurHover":30,"boxShadowSpreadHover":0,"topPaddingDesktop":10,"bottomPaddingDesktop":10,"leftPaddingDesktop":10,"rightPaddingDesktop":10,"rowGapDesktop":5,"widthSetByUser":true,"containerBorderTopLeftRadius":10,"containerBorderTopRightRadius":10,"containerBorderBottomLeftRadius":10,"containerBorderBottomRightRadius":10}} -->
<div class="wp-block-uagb-container uagb-block-{block_id_1}">

<!-- wp:paragraph {{"align":"center","style":{{"spacing":{{"margin":{{"top":"0px","bottom":"0px"}}}},"elements":{{"link":{{"color":{{"text":"var:preset|color|ast-global-color-5"}}}}}}}},"textColor":"ast-global-color-5"}} -->
<p class="has-text-align-center has-ast-global-color-5-color has-text-color has-link-color" style="margin-top:0px;margin-bottom:0px">{latest_firmware_date}</p>
<!-- /wp:paragraph -->

<!-- wp:heading {{"textAlign":"center","level":3,"style":{{"spacing":{{"margin":{{"top":"0px","bottom":"0px"}}}}}}}} -->
<h3 class="wp-block-heading has-text-align-center" id="firmwares-{firmware_type_wordpress_id}" style="margin-top:0px;margin-bottom:0px"><a href="https://www.warp-charger.com/firmwares/{latest_firmware_filename}" target="_blank" rel="noreferrer noopener">{firmware_display_name} Firmware {latest_firmware_version}</a></h3>
<!-- /wp:heading -->

<!-- wp:uagb/separator {{"block_id":"{block_id_2}","separatorColor":"var(\\u002d\\u002dast-global-color-0)","separatorHeight":0,"separatorHeightMobile":0,"separatorHeightTablet":0,"blockTopPadding":0,"blockBottomPadding":0,"blockTopPaddingTablet":10,"blockBottomPaddingTablet":10,"blockTopPaddingMobile":10,"blockBottomPaddingMobile":10,"blockPaddingUnit":"px","blockPaddingUnitTablet":"px","blockPaddingUnitMobile":"px"}} -->
<div class="wp-block-uagb-separator uagb-block-{block_id_2}"><div class="uagb-separator-spacing-wrapper"><div class="wp-block-uagb-separator__inner" style="--my-background-image:"></div></div></div>
<!-- /wp:uagb/separator -->

<!-- wp:details {{"style":{{"spacing":{{"blockGap":"0"}},"elements":{{"link":{{"color":{{"text":"var:preset|color|ast-global-color-5"}}}}}}}},"textColor":"ast-global-color-5"}} -->
<details class="wp-block-details has-ast-global-color-5-color has-text-color has-link-color"><summary>Prüfsumme, Changelog, Firmware-Archiv</summary>
'''

firmware_type_suffix = '''
</details>
<!-- /wp:details -->

</div>
<!-- /wp:uagb/container -->
'''

firmware_changelog = '''
<!-- wp:uagb/container {{"block_id":"{block_id_1}","rowGapDesktop":10,"textColor":"","linkColor":"","linkHoverColor":""}} -->
<div class="wp-block-uagb-container uagb-block-{block_id_1}">

<!-- wp:paragraph {{"style":{{"spacing":{{"margin":{{"top":"0px","bottom":"0px"}}}}}}}} -->
<p style="margin-top:0px;margin-bottom:0px"><a href="https://www.warp-charger.com/firmwares/{firmware_filename}" target="_blank" rel="noreferrer noopener">Firmware {firmware_version}</a> (<a href="https://www.warp-charger.com/firmwares/{firmware_filename}.sha256" target="_blank" rel="noreferrer noopener">Prüfsumme</a>) wurde am {firmware_date} veröffentlicht. Changelog:</p>
<!-- /wp:paragraph -->

<!-- wp:list {{"style":{{"spacing":{{"margin":{{"top":"0px","bottom":"0px"}}}}}}}} -->
<ul style="margin-top:0px;margin-bottom:0px" class="wp-block-list">
{firmware_changelog_items}
</ul>
<!-- /wp:list -->

<!-- wp:uagb/separator {{"block_id":"{block_id_2}","separatorColor":"var(\\u002d\\u002dast-global-color-0)","separatorHeight":0,"separatorHeightMobile":0,"separatorHeightTablet":0,"blockTopPadding":0,"blockBottomPadding":0,"blockTopPaddingTablet":10,"blockBottomPaddingTablet":10,"blockTopPaddingMobile":10,"blockBottomPaddingMobile":10,"blockPaddingUnit":"px","blockPaddingUnitTablet":"px","blockPaddingUnitMobile":"px"}} -->
<div class="wp-block-uagb-separator uagb-block-{block_id_2}"><div class="uagb-separator-spacing-wrapper"><div class="wp-block-uagb-separator__inner" style="--my-background-image:"></div></div></div>
<!-- /wp:uagb/separator -->

</div>
<!-- /wp:uagb/container -->
'''

firmware_changelog_item = '''
<!-- wp:list-item -->
<li>{text}</li>
<!-- /wp:list-item -->
'''

next_block_id = 0x70000000


def fatal(msg):
    print(msg)
    sys.exit(1)


def basic_auth(username, password):
    token = b64encode(f'{username}:{password}'.encode('utf-8')).decode('ascii')
    return f'Basic {token}'


def get_next_block_id():
    global next_block_id

    next_block_id += 1

    return f'{next_block_id:08x}'


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--dry-run', action='store_true')
    parser.add_argument('--dump', action='store_true')
    parser.add_argument('username')
    parser.add_argument('password')

    args = parser.parse_args()

    authorization = basic_auth(args.username, args.password)

    with urllib.request.urlopen(urllib.request.Request('https://www.warp-charger.com/wp-json/wp/v2/pages/540?context=edit',
                                                       headers={'Authorization': authorization})) as r:
        data = json.loads(r.read())

    content_before = data['content']['raw'].replace('--><', '-->\n\n<').replace('><!--', '>\n\n<!--')

    if args.dump:
        with open('content_before.txt', 'w') as f:
            f.write(content_before)

    wp_group_begin = '<!-- wp:group {"layout":{"type":"flex","orientation":"vertical","justifyContent":"center"}} -->'
    wp_group_end = '<!-- /wp:group -->'

    wp_group_begin_index = content_before.find(wp_group_begin)
    wp_group_end_index = content_before.find(wp_group_end)

    if wp_group_begin_index < 0:
        fatal('Cannot find wp:group begin')

    if wp_group_end_index < 0:
        fatal('Cannot find wp:group end')

    content_prefix = content_before[:wp_group_begin_index] + f'{wp_group_begin}\n<div class="wp-block-group">\n'
    content_suffix = '\n</div>\n' + content_before[wp_group_end_index:]

    content = content_prefix

    for firmware_type in firmware_types:
        index_path = f'{firmware_type_to_env_name[firmware_type]}_firmware_v2.txt'

        with open(index_path, 'r') as f:
            index_lines = f.readlines()

        for i, index_line in enumerate(index_lines):
            index_version = index_line.strip().replace('.', '_').replace('-', '_').replace('+', '_')
            changelog_path = f'{firmware_type_to_env_name[firmware_type]}_firmware_{index_version}_changelog_de.txt'

            with open(changelog_path, 'r') as f:
                changelog_lines = list(f.readlines())

            m = re.match(r'^(20[0-9]{2})-([0-9]{2})-([0-9]{2}): ([0-9]+\.[0-9]+\.[0-9]+(?:-beta\.[0-9]+)?) \([a-f0-9]+\)$', changelog_lines[0])

            if m == None:
                fatal(f'Changelog {changelog_path} is malformed')

            firmware_date = f'{m.group(3)}.{m.group(2)}.{m.group(1)}'
            firmware_version = m.group(4)
            firmware_filename = f'{firmware_type_to_env_name[firmware_type]}_firmware_{index_version}_merged.bin'

            if i == 0:
                content += firmware_type_prefix.format(block_id_1=get_next_block_id(),
                                                       block_id_2=get_next_block_id(),
                                                       firmware_type_wordpress_id=firmware_type_to_wordpress_id[firmware_type],
                                                       firmware_display_name=firmware_type_to_display_name[firmware_type],
                                                       latest_firmware_date=firmware_date,
                                                       latest_firmware_version=firmware_version,
                                                       latest_firmware_filename=firmware_filename)

            firmware_changelog_items = []

            for changelog_line in changelog_lines[1:]:
                changelog_line = changelog_line.strip().removeprefix('- ')

                if len(changelog_line) == 0:
                    continue

                changelog_line = html.escape(changelog_line, quote=False)  # FIXME: this breaks [a] tags with and &, > or < in the href
                changelog_line = re.sub(r'\[a:([^\]]+)\]', r'<a href="\1">', changelog_line)
                changelog_line = changelog_line.replace('[/a]', '</a>')
                changelog_line = changelog_line.replace('[b]', '<strong>')
                changelog_line = changelog_line.replace('[/b]', '</strong>')
                changelog_line = changelog_line.replace('[c]', '<mark style="background-color:rgba(0, 0, 0, 0);color:#ff6900" class="has-inline-color">')
                changelog_line = changelog_line.replace('[/c]', '</mark>')

                firmware_changelog_items.append(firmware_changelog_item.format(text=changelog_line))

            content += firmware_changelog.format(block_id_1=get_next_block_id(),
                                                 block_id_2=get_next_block_id(),
                                                 firmware_date=firmware_date,
                                                 firmware_version=firmware_version,
                                                 firmware_filename=firmware_filename,
                                                 firmware_changelog_items=''.join(firmware_changelog_items))

        content += firmware_type_suffix

    content += content_suffix

    if args.dump:
        with open('content.txt', 'w') as f:
            f.write(content)

    if not args.dry_run:
        with urllib.request.urlopen(urllib.request.Request('https://www.warp-charger.com/wp-json/wp/v2/pages/540',
                                                           data=json.dumps({'id': 540, 'content': content}).encode('utf-8'),
                                                           headers={'Authorization': authorization, 'Content-Type': 'application/json; charset=UTF-8'})) as r:
            data = json.loads(r.read())

        content_after = data['content']['raw']

        if args.dump:
            with open('content_after.txt', 'w') as f:
                f.write(content_after)

        if content_after != content:
            fatal('Content change was not accepted')


if __name__ == '__main__':
    main()
