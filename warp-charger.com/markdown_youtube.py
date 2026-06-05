"""Custom Markdown extension: embed YouTube videos in blog posts.

Drop a video into any blog ``.md`` with a single line:

    [youtube: Xxqdi2Cyhz0]

The value may be a bare 11-character video id, or any common YouTube URL
(``https://www.youtube.com/watch?v=ID``, ``https://youtu.be/ID``,
``.../embed/ID``, ``.../shorts/ID``) -- the id is extracted automatically.

An optional title (used as the iframe's accessible name) can be added after a
pipe:

    [youtube: Xxqdi2Cyhz0 | WARP at Power2Drive 2026]

It expands to a responsive, privacy-friendly (youtube-nocookie) 16:9 embed.
The directive must be on its own line.
"""

import html as _html
import re

from markdown.extensions import Extension
from markdown.preprocessors import Preprocessor

# A line consisting solely of a [youtube: ...] directive (leading/trailing
# whitespace allowed). Case-insensitive on the "youtube" keyword.
_DIRECTIVE_RE = re.compile(r"^\s*\[youtube:\s*(?P<body>[^\]]+?)\s*\]\s*$", re.IGNORECASE)

# Extract an 11-char video id from the common YouTube URL shapes.
_URL_ID_RE = re.compile(
    r"(?:youtu\.be/|youtube(?:-nocookie)?\.com/(?:watch\?(?:[^ ]*&)?v=|embed/|shorts/|v/))"
    r"(?P<id>[A-Za-z0-9_-]{11})"
)
_BARE_ID_RE = re.compile(r"^[A-Za-z0-9_-]{11}$")

_DEFAULT_TITLE = "YouTube video player"


def extract_video_id(value):
    """Return the YouTube video id from a bare id or any common URL form, else None."""
    value = value.strip()
    match = _URL_ID_RE.search(value)
    if match:
        return match.group("id")
    if _BARE_ID_RE.match(value):
        return value
    return None


def render_embed(video_id, title=_DEFAULT_TITLE):
    """Return the responsive, privacy-friendly iframe markup for a video id."""
    safe_title = _html.escape(title or _DEFAULT_TITLE, quote=True)
    return (
        '<div style="position: relative; aspect-ratio: 16 / 9; margin: 1.25rem 0; '
        'border-radius: 12px; overflow: hidden;">'
        f'<iframe src="https://www.youtube-nocookie.com/embed/{video_id}" '
        f'title="{safe_title}" loading="lazy" '
        'style="position: absolute; inset: 0; width: 100%; height: 100%; border: 0;" '
        'allow="accelerometer; autoplay; clipboard-write; encrypted-media; '
        'gyroscope; picture-in-picture; web-share" '
        'referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>'
        "</div>"
    )


class YouTubeEmbedPreprocessor(Preprocessor):
    def run(self, lines):
        new_lines = []
        for line in lines:
            match = _DIRECTIVE_RE.match(line)
            if match:
                body = match.group("body")
                id_part, _, title_part = body.partition("|")
                video_id = extract_video_id(id_part)
                if video_id:
                    html = render_embed(video_id, title_part.strip() or _DEFAULT_TITLE)
                    # Stash the raw HTML so Markdown leaves it untouched, and put
                    # the placeholder on its own line (blank lines around it) so
                    # it forms its own block and isn't wrapped in a <p>.
                    placeholder = self.md.htmlStash.store(html)
                    new_lines.extend(("", placeholder, ""))
                    continue
                # Unparseable id: leave the original line so the author notices.
            new_lines.append(line)
        return new_lines


class YouTubeEmbedExtension(Extension):
    def extendMarkdown(self, md):
        # Priority 7 runs after fenced_code (25) and reference (15), so a
        # directive inside a code block is left as-is.
        md.preprocessors.register(YouTubeEmbedPreprocessor(md), "youtube_embed", 7)


def makeExtension(**kwargs):
    return YouTubeEmbedExtension(**kwargs)
