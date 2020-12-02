import os
import shutil

def recreate_dir(path):
    if os.path.exists(path):
        shutil.rmtree(path)

    os.makedirs(path)

def specialize_template(template_filename, destination_filename, replacements, check_completeness=True, remove_template=False):
    lines = []
    replaced = set()

    with open(template_filename, 'r') as f:
        for line in f.readlines():
            for key in replacements:
                replaced_line = line.replace(key, replacements[key])

                if replaced_line != line:
                    replaced.add(key)

                line = replaced_line

            lines.append(line)

    if check_completeness and replaced != set(replacements.keys()):
        raise Exception('Not all replacements for {0} have been applied. Missing are {1}'.format(template_filename, ', '.join(set(replacements.keys() - replaced))))

    with open(destination_filename, 'w') as f:
        f.writelines(lines)

    if remove_template:
        os.remove(template_filename)

with open('assets/css/main.css') as f:
    css = f.read()

with open('assets/js/bundle.js') as f:
    js = f.read()

recreate_dir('dist')

specialize_template('assets/index.html', 'dist/index.html',
    {
        '<link href=css/main.css rel=stylesheet>': '<style rel=stylesheet>{}</style>'.format(css),
        '<script src=js/bundle.js></script>': '<script>{}</script>'.format(js)
    })
