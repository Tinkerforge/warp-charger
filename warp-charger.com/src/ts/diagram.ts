/*
 * MicroGraphRenderer: SVG Energy Flow Graph
 *
 * Originally from coupling media GmbH.
 * Ported to TypeScript for the warp-charger.com homepage.
 *
 * Supports multiple diagrams per page; each diagram supplies its own animation
 * config (steps, default colors, interval) inside its JSON config under the
 * `animation` key. Element lookups are scoped to a per-diagram root element
 * marked with `data-diagram-root` so multiple instances don't collide.
 */

interface DiagramNode {
    id: string;
    position: string;
    label?: string;
    label_key?: string;
    icon?: string;
    highlighted?: string | boolean;
    colorful?: boolean;
}

interface DiagramEdge {
    id: string;
    source: string;
    target: string;
    status?: string;
    speed?: number | string;
    dotted?: string | boolean;
    icon?: string;
    "icon-color"?: string;
}

type FlowColor = "blue" | "green";

interface AnimationStepConfig {
    activeEdges: Record<string, { speed?: number; color?: FlowColor; label?: string }>;
    edgeLabels?: Record<string, string>;
    dimmedNodes?: string[];
    nodeIcons?: Record<string, string>;
    nodeIconSequence?: Record<string, string[]>;
    nodeLabels?: Record<string, string>;
    weather?: "sun-dim" | "sun" | "sun-bright" | "cloud" | "moon";
    price?: "cheap" | "normal" | "expensive";
    priceLabel?: string;
    temperature?: "cold" | "mild" | "warm";
    temperatureLabel?: string;
    descriptionKey?: string;
}

interface AnimationConfig {
    stepIntervalMs?: number;
    defaultEdgeColors?: Record<string, FlowColor>;
    steps: AnimationStepConfig[];
}

interface DiagramConfig {
    grid: { width: string | number; height: string | number };
    graph: { nodes: DiagramNode[]; edges: DiagramEdge[] };
    animation?: AnimationConfig;
}

interface RendererOptions {
    assetBase: string;
    labels?: Record<string, string>;
    descriptions?: Record<string, string>;
    ariaLabel?: string;
    weatherEl?: HTMLElement | null;
    priceEl?: HTMLElement | null;
    priceLabelEl?: HTMLElement | null;
    temperatureEl?: HTMLElement | null;
    temperatureLabelEl?: HTMLElement | null;
    descriptionEl?: HTMLElement | null;
    stepEyebrowEl?: HTMLElement | null;
    stepEyebrowTemplate?: string;
    stepDotsEl?: HTMLElement | null;
    stepDotAriaTemplate?: string;
}

const NS = "http://www.w3.org/2000/svg";
const XHTML = "http://www.w3.org/1999/xhtml";

class MicroGraphRenderer {
    static CELL = 1000;
    static R = 300;
    static UNIT_W = 600;
    static UNIT_H = 28;
    static TRACK_W = 14;
    static LABEL_FS = 55;
    static LABEL_OFFSET_Y = 75;
    static TRACK_GHOST_W = 0.6;
    static ANIM_DUR_MAX = 6;
    static ANIM_DUR_MIN = 0.3;
    static EDGE_ICON_SIZE = 160;

    private config: DiagramConfig;
    private container: HTMLElement;
    private opts: RendererOptions;
    _animSvg: SVGSVGElement | null = null;
    private _staticSvg: SVGSVGElement | null = null;
    private _nodeMap: Record<string, { x: number; y: number; node: DiagramNode }> = {};
    private _unitVB: string | null = null;
    private _unitPaths: SVGPathElement[] | null = null;
    private _unitDefs: Element[] | null = null;
    private _subStepTimers: number[] = [];
    private _currentStepIdx = 0;

    static async create(
        configPath: string,
        container: HTMLElement,
        opts: RendererOptions,
    ): Promise<MicroGraphRenderer> {
        const config: DiagramConfig = await fetch(configPath, { cache: "no-store" }).then((r) => {
            if (!r.ok) throw new Error(`Config fetch failed: HTTP ${r.status}`);
            return r.json();
        });
        const renderer = new MicroGraphRenderer(config, container, opts);
        await renderer._loadUnitSvg();
        renderer._prefetchStepIcons();
        return renderer;
    }

    private _prefetchStepIcons(): void {
        const steps = this.config.animation?.steps;
        if (!steps) return;
        const seen = new Set<string>();
        const add = (file: string) => {
            if (seen.has(file)) return;
            seen.add(file);
            const img = new Image();
            img.src = `${this.opts.assetBase}${file}`;
        };
        for (const step of steps) {
            if (step.nodeIcons) for (const f of Object.values(step.nodeIcons)) add(f);
            if (step.nodeIconSequence)
                for (const seq of Object.values(step.nodeIconSequence))
                    for (const f of seq) add(f);
        }
    }

    private _setNodeIcon(nodeId: string, iconFile: string): void {
        const iconEl = this._staticSvg?.querySelector(
            `#mg-node-icon-${nodeId}`,
        ) as SVGImageElement | null;
        if (!iconEl) return;
        const nextSrc = `${this.opts.assetBase}${iconFile}`;
        if (iconEl.getAttribute("href") !== nextSrc) {
            iconEl.setAttribute("href", nextSrc);
        }
    }

    constructor(config: DiagramConfig, container: HTMLElement, opts: RendererOptions) {
        this.config = config;
        this.container = container;
        this.opts = opts;
    }

    get animation(): AnimationConfig | undefined {
        return this.config.animation;
    }

    get currentStepIdx(): number {
        return this._currentStepIdx;
    }

    get stepCount(): number {
        return this.animation?.steps.length ?? 0;
    }

    /**
     * Resolve the description text for a given step index (mod stepCount).
     * Used by the info-popover swipe UI to preview neighbouring steps while
     * the finger is dragging.
     */
    descriptionForStep(idx: number): string {
        const steps = this.animation?.steps;
        if (!steps || !steps.length) return "";
        const n = steps.length;
        const step = steps[((idx % n) + n) % n];
        return step.descriptionKey
            ? (this.opts.descriptions?.[step.descriptionKey] ?? "")
            : "";
    }

    /**
     * Jump to a specific step (mod stepCount). Applies the step and updates
     * the UI surfaces tied to step state (eyebrow label, dot indicators).
     */
    gotoStep(idx: number): void {
        const steps = this.animation?.steps;
        if (!steps || !steps.length) return;
        const n = steps.length;
        const normalized = ((idx % n) + n) % n;
        this._currentStepIdx = normalized;
        this.applyStep(steps[normalized]);
        this._updateStepEyebrow();
        this._ensureStepDots();
        this._updateStepDots();
    }

    private _updateStepEyebrow(): void {
        const el = this.opts.stepEyebrowEl;
        if (!el) return;
        const template = this.opts.stepEyebrowTemplate || "Schritt {n}";
        el.textContent = template.replace("{n}", String(this._currentStepIdx + 1));
    }

    private _ensureStepDots(): void {
        const host = this.opts.stepDotsEl;
        if (!host) return;
        const total = this.stepCount;
        if (total <= 1) {
            host.classList.add("hidden");
            host.replaceChildren();
            return;
        }
        // Rebuild only when the existing dots don't match this renderer's
        // step count. This matters when two diagrams share one container
        // (e.g. battery priority/discharge sub-tabs): switching tabs must
        // restore the correct dot count + unhide the row.
        host.classList.remove("hidden");
        const existing = host.querySelectorAll<HTMLElement>("[data-step-dot]");
        if (existing.length === total) return;
        const ariaTemplate = this.opts.stepDotAriaTemplate || "Schritt {n} anzeigen";
        host.replaceChildren();
        for (let i = 0; i < total; i++) {
            const btn = document.createElement("button");
            btn.type = "button";
            btn.dataset.stepDot = String(i);
            btn.dataset.active = "false";
            btn.setAttribute(
                "aria-label",
                ariaTemplate.replace("{n}", String(i + 1)),
            );
            btn.className =
                "h-2.5 w-2.5 cursor-pointer rounded-full bg-light-grey transition-colors hover:bg-grey data-[active=true]:bg-black";
            host.appendChild(btn);
        }
    }

    private _updateStepDots(): void {
        const host = this.opts.stepDotsEl;
        if (!host) return;
        host.querySelectorAll<HTMLElement>("[data-step-dot]").forEach((el) => {
            const idx = parseInt(el.dataset.stepDot || "-1", 10);
            el.dataset.active = idx === this._currentStepIdx ? "true" : "false";
        });
    }

    private async _loadUnitSvg(): Promise<void> {
        try {
            const text = await fetch(`${this.opts.assetBase}energy-unit.svg`).then((r) => {
                if (!r.ok) throw new Error(`HTTP ${r.status}`);
                return r.text();
            });
            const root = new DOMParser().parseFromString(text, "image/svg+xml")
                .documentElement as unknown as SVGSVGElement;
            if (root.nodeName === "parsererror") throw new Error("SVG parse error");
            this._unitVB =
                root.getAttribute("viewBox") ||
                `0 0 ${root.getAttribute("width")} ${root.getAttribute("height")}`;
            this._unitPaths = Array.from(root.querySelectorAll("path"));
            this._unitDefs = Array.from(root.querySelectorAll("defs > *"));
        } catch (e) {
            console.warn(
                `MicroGraphRenderer: energy-unit.svg not loaded (${(e as Error).message}), using fallback.`,
            );
        }
    }

    private _parsePos(str: string): { col: number; row: number } {
        const m = str.match(/\((\d+),\s*(\d+)\)/);
        if (!m) throw new Error(`Invalid position string: "${str}"`);
        return { col: parseInt(m[1]), row: parseInt(m[2]) };
    }

    private _center(posStr: string): { x: number; y: number } {
        const { col, row } = this._parsePos(posStr);
        const C = MicroGraphRenderer.CELL;
        return { x: col * C + C / 2, y: row * C + C / 2 };
    }

    private getBezierPath(x1: number, y1: number, x2: number, y2: number): string {
        const dx = x2 - x1;
        const dy = y2 - y1;
        if (dx !== 0 && dy !== 0) {
            return `M ${x1} ${y1} L ${x2} ${y2}`;
        }
        let cx1: number, cy1: number, cx2: number, cy2: number;
        if (Math.abs(dx) >= Math.abs(dy)) {
            cx1 = x1 + dx * 0.5;
            cy1 = y1;
            cx2 = x2 - dx * 0.5;
            cy2 = y2;
        } else {
            cx1 = x1;
            cy1 = y1 + dy * 0.5;
            cx2 = x2;
            cy2 = y2 - dy * 0.5;
        }
        return `M ${x1} ${y1} C ${cx1} ${cy1}, ${cx2} ${cy2}, ${x2} ${y2}`;
    }

    private _el<K extends keyof SVGElementTagNameMap>(
        tag: K,
        attrs: Record<string, string | number> = {},
    ): SVGElementTagNameMap[K] {
        const el = document.createElementNS(NS, tag) as SVGElementTagNameMap[K];
        for (const [k, v] of Object.entries(attrs)) el.setAttribute(k, String(v));
        return el;
    }

    private _speedToDur(speed: number | string | undefined): string {
        const s = Math.max(0, Math.min(1, parseFloat(String(speed)) || 0.5));
        const { ANIM_DUR_MAX: max, ANIM_DUR_MIN: min } = MicroGraphRenderer;
        return (max - s * (max - min)).toFixed(2);
    }

    private _buildMover(edge: DiagramEdge, pathD: string, speed: number | string = 0.5): SVGGElement {
        const W = MicroGraphRenderer.UNIT_W;
        const H = MicroGraphRenderer.UNIT_H;

        const mover = this._el("g", {
            id: `mg-mover-${edge.id}`,
            class: "energy-unit-mover",
            style: "will-change: transform;",
        });

        const anim = this._el("animateMotion", {
            id: `mg-anim-${edge.id}`,
            path: pathD,
            dur: `${this._speedToDur(speed)}s`,
            repeatCount: "indefinite",
            rotate: "auto-reverse",
            keyPoints: "0;1",
            keyTimes: "0;1",
            calcMode: "linear",
        });
        mover.appendChild(anim);

        const vfx = this._el("g", {
            style:
                "transform: scale(var(--mg-vfx-scale)); filter: blur(var(--mg-vfx-blur)) drop-shadow(0 0 var(--mg-vfx-glow-near-spread) var(--mg-vfx-glow-near-color)) drop-shadow(0 0 var(--mg-vfx-glow-far-spread) var(--mg-vfx-glow-far-color));",
        });

        const unitSvg = this._el("svg", {
            x: -(W / 2),
            y: -(H / 2),
            width: W,
            height: H,
            viewBox: this._unitVB || `0 0 ${W} ${H}`,
            preserveAspectRatio: "none",
        });
        this._unitPaths?.forEach((p) => unitSvg.appendChild(p.cloneNode(true)));

        vfx.appendChild(unitSvg);
        mover.appendChild(vfx);
        return mover;
    }

    private _resolveLabel(node: DiagramNode): string {
        if (node.label_key && this.opts.labels && this.opts.labels[node.label_key]) {
            return this.opts.labels[node.label_key];
        }
        return node.label || "";
    }

    render(): MicroGraphRenderer {
        const { grid, graph } = this.config;
        const cols = parseInt(String(grid.width));
        const rows = parseInt(String(grid.height));
        const C = MicroGraphRenderer.CELL;
        const vb = `0 0 ${cols * C} ${rows * C + 300}`;

        graph.nodes.forEach((node) => {
            this._nodeMap[node.id] = { ...this._center(node.position), node };
        });

        const layerWrapper = document.createElement("div");
        layerWrapper.style.cssText = "position: relative;";

        const animSvg = this._el("svg", {
            viewBox: vb,
            xmlns: NS,
            overflow: "visible",
            "aria-hidden": "true",
            class: "w-full h-auto",
        });
        this._animSvg = animSvg;

        const defs = this._el("defs");
        this._unitDefs?.forEach((d) => defs.appendChild(d.cloneNode(true)));
        animSvg.appendChild(defs);

        const edgeLayer = this._el("g", { id: "mg-edge-layer" });
        graph.edges.forEach((edge) => {
            const src = this._nodeMap[edge.source];
            const tgt = this._nodeMap[edge.target];
            const pathD = this.getBezierPath(src.x, src.y, tgt.x, tgt.y);
            const trackId = `mg-track-${edge.id}`;
            const active = edge.status === "active";
            const dotted = edge.dotted === "true" || edge.dotted === true;
            const dashArr = dotted ? `1 ${MicroGraphRenderer.TRACK_W * 3}` : null;

            const group = this._el("g", {
                id: `mg-edge-${edge.id}`,
                opacity: edge.status === "inactive" ? "0.5" : "1",
            });

            const ghostAttrs: Record<string, string> = {
                d: pathD,
                class: "mg-track mg-track-ghost",
                "stroke-width": String(
                    MicroGraphRenderer.TRACK_W * MicroGraphRenderer.TRACK_GHOST_W,
                ),
                "stroke-linecap": "round",
                fill: "none",
            };
            if (dashArr) ghostAttrs["stroke-dasharray"] = dashArr;
            group.appendChild(this._el("path", ghostAttrs));

            const trackAttrs: Record<string, string> = {
                id: trackId,
                d: pathD,
                class: "mg-track",
                "stroke-width": String(MicroGraphRenderer.TRACK_W),
                "stroke-linecap": "round",
                fill: "none",
            };
            if (dashArr) trackAttrs["stroke-dasharray"] = dashArr;
            group.appendChild(this._el("path", trackAttrs));

            if (active) group.appendChild(this._buildMover(edge, pathD, edge.speed));

            if (edge.icon) {
                const S = MicroGraphRenderer.EDGE_ICON_SIZE;
                const mx = (src.x + tgt.x) / 2;
                const my = (src.y + tgt.y) / 2;
                const imgAttrs: Record<string, string | number> = {
                    href: `${this.opts.assetBase}${edge.icon}`,
                    x: mx - S / 2,
                    y: my - S - 40,
                    width: S,
                    height: S,
                };
                if (edge["icon-color"]) {
                    const filterId = `mg-edge-icon-filter-${edge.id}`;
                    const filter = this._el("filter", { id: filterId });
                    const flood = this._el("feFlood", {
                        "flood-color": edge["icon-color"],
                        result: "color",
                    });
                    const comp = this._el("feComposite", {
                        in: "color",
                        in2: "SourceGraphic",
                        operator: "in",
                    });
                    filter.appendChild(flood);
                    filter.appendChild(comp);
                    defs.appendChild(filter);
                    imgAttrs.filter = `url(#${filterId})`;
                }
                group.appendChild(this._el("image", imgAttrs));
            }

            edgeLayer.appendChild(group);
        });
        animSvg.appendChild(edgeLayer);

        const staticSvg = this._el("svg", {
            viewBox: vb,
            xmlns: NS,
            role: "img",
            "aria-label": this.opts.ariaLabel || "Energy flow diagram",
            style:
                "position: absolute; top: 0; left: 0; width: 100%; height: 100%; pointer-events: none;",
        });
        this._staticSvg = staticSvg;

        // Defs on the static SVG: a black-tint filter for monochrome icons.
        // We render icons as native SVG <image> elements (not HTML in
        // <foreignObject>) because iOS Safari has paint bugs with HTML
        // inside foreignObject, especially when CSS `filter` or
        // `mask-image` is involved.
        const staticDefs = this._el("defs");
        const blackFilter = this._el("filter", {
            id: "mg-icon-black",
            x: "0",
            y: "0",
            width: "1",
            height: "1",
        });
        const flood = this._el("feFlood", { "flood-color": "#000", result: "color" });
        const comp = this._el("feComposite", { in: "color", in2: "SourceGraphic", operator: "in" });
        blackFilter.appendChild(flood);
        blackFilter.appendChild(comp);
        staticDefs.appendChild(blackFilter);
        staticSvg.appendChild(staticDefs);

        const nodeLayer = this._el("g", { id: "mg-node-layer" });
        graph.nodes.forEach((node) => {
            const { x, y } = this._nodeMap[node.id];
            const highlighted = node.highlighted === "true" || node.highlighted === true;
            const R = highlighted ? MicroGraphRenderer.R : Math.round(MicroGraphRenderer.R * 0.75);
            const group = this._el("g", { id: `mg-node-${node.id}` });

            const BLEED = 300;
            const fo = this._el("foreignObject", {
                x: x - R - BLEED,
                y: y - R - BLEED,
                width: (R + BLEED) * 2,
                height: (R + BLEED) * 2,
                overflow: "visible",
            });
            const foWrapper = document.createElementNS(XHTML, "div");
            foWrapper.setAttribute("xmlns", XHTML);
            (foWrapper as HTMLElement).style.cssText =
                `width:100%;height:100%;padding:${BLEED}px;box-sizing:border-box;pointer-events:none;`;
            const outer = document.createElementNS(XHTML, "div") as HTMLElement;
            outer.className = highlighted
                ? "mg-node-outer mg-node-outer--highlighted"
                : "mg-node-outer";
            outer.style.pointerEvents = "auto";
            const inner = document.createElementNS(XHTML, "div") as HTMLElement;
            inner.className = highlighted
                ? "mg-node-inner mg-node-inner--highlighted"
                : "mg-node-inner";
            outer.appendChild(inner);
            foWrapper.appendChild(outer);
            fo.appendChild(foWrapper);
            group.appendChild(fo);

            // Icon as native SVG <image> sibling to the foreignObject card.
            // Sized to ~60% of the card's diameter (2R), centered on node.
            if (node.icon) {
                const iconSize = Math.round(R * 1.2);
                const iconAttrs: Record<string, string | number> = {
                    id: `mg-node-icon-${node.id}`,
                    href: `${this.opts.assetBase}${node.icon}`,
                    x: x - iconSize / 2,
                    y: y - iconSize / 2,
                    width: iconSize,
                    height: iconSize,
                    preserveAspectRatio: "xMidYMid meet",
                    class: node.colorful ? "mg-node-svg-icon mg-node-svg-icon--colorful" : "mg-node-svg-icon",
                };
                if (!node.colorful) {
                    iconAttrs.filter = "url(#mg-icon-black)";
                }
                const iconImg = this._el("image", iconAttrs);
                group.appendChild(iconImg);
            }

            const label = this._el("text", {
                x,
                y: y + R + MicroGraphRenderer.LABEL_OFFSET_Y,
                "text-anchor": "middle",
                "font-family": "system-ui, -apple-system, sans-serif",
                "font-size": String(MicroGraphRenderer.LABEL_FS),
                "font-weight": "600",
                "letter-spacing": "1",
                class: "mg-label",
            });
            label.textContent = this._resolveLabel(node);
            group.appendChild(label);

            // Visible per-step sublabel (e.g. heat pump SG-Ready mode).
            // Empty by default; populated by applyStep via step.nodeLabels.
            const sublabel = this._el("text", {
                id: `mg-node-sublabel-${node.id}`,
                x,
                y: y + R + MicroGraphRenderer.LABEL_OFFSET_Y,
                "text-anchor": "middle",
                "dominant-baseline": "middle",
                "font-family": "system-ui, -apple-system, sans-serif",
                "font-size": String(Math.round(MicroGraphRenderer.LABEL_FS * 1.3)),
                "font-weight": "600",
                fill: "#0f172a",
                stroke: "white",
                "stroke-width": "16",
                "paint-order": "stroke",
                class: "mg-node-sublabel",
            });
            group.appendChild(sublabel);
            nodeLayer.appendChild(group);
        });
        staticSvg.appendChild(nodeLayer);

        // Edge label layer: per-edge text shown above the path midpoint, used
        // by animation steps (e.g. flow amounts in kW). Empty by default.
        const edgeLabelLayer = this._el("g", { id: "mg-edge-label-layer" });
        graph.edges.forEach((edge) => {
            const src = this._nodeMap[edge.source];
            const tgt = this._nodeMap[edge.target];
            const mx = (src.x + tgt.x) / 2;
            const my = (src.y + tgt.y) / 2;
            const label = this._el("text", {
                id: `mg-edge-label-${edge.id}`,
                x: mx,
                y: my,
                "text-anchor": "middle",
                "dominant-baseline": "middle",
                "font-family": "system-ui, -apple-system, sans-serif",
                "font-size": String(Math.round(MicroGraphRenderer.LABEL_FS * 1.6)),
                "font-weight": "700",
                fill: "#0f172a",
                stroke: "white",
                "stroke-width": "16",
                "paint-order": "stroke",
                class: "mg-edge-label",
                opacity: "0",
            });
            edgeLabelLayer.appendChild(label);
        });
        staticSvg.appendChild(edgeLabelLayer);

        layerWrapper.appendChild(animSvg);
        layerWrapper.appendChild(staticSvg);
        this.container.replaceChildren(layerWrapper);
        return this;
    }

    pauseAnimations(): void {
        const svg = this._animSvg as unknown as { pauseAnimations?: () => void } | null;
        svg?.pauseAnimations?.();
        for (const t of this._subStepTimers) clearInterval(t);
        this._subStepTimers = [];
    }

    unpauseAnimations(): void {
        const svg = this._animSvg as unknown as { unpauseAnimations?: () => void } | null;
        svg?.unpauseAnimations?.();
    }

    /**
     * Apply an animation step: dim/un-dim nodes, activate/deactivate edges,
     * optionally override edge speeds, and color the flow.
     */
    applyStep(step: AnimationStepConfig): void {
        const { graph } = this.config;
        const defaults = this.config.animation?.defaultEdgeColors || {};

        graph.edges.forEach((edge) => {
            const active = step.activeEdges[edge.id];
            const edgeEl = this._animSvg?.querySelector(
                `#mg-edge-${edge.id}`,
            ) as SVGGElement | null;
            const moverEl = this._animSvg?.querySelector(
                `#mg-mover-${edge.id}`,
            ) as SVGGElement | null;
            const animEl = this._animSvg?.querySelector(
                `#mg-anim-${edge.id}`,
            ) as SVGElement | null;

            if (edgeEl) {
                edgeEl.style.opacity = active ? "1" : "0.2";
                const color =
                    (active && active.color) || defaults[edge.id] || "blue";
                edgeEl.classList.toggle("mg-flow-green", color === "green");
            }
            if (moverEl) moverEl.style.display = active ? "" : "none";
            if (animEl) {
                const speed = active && active.speed != null ? active.speed : edge.speed;
                animEl.setAttribute("dur", `${this._speedToDur(speed)}s`);
            }

            const labelEl = this._staticSvg?.querySelector(
                `#mg-edge-label-${edge.id}`,
            ) as SVGTextElement | null;
            if (labelEl) {
                const text =
                    (active && active.label) ?? step.edgeLabels?.[edge.id] ?? "";
                labelEl.textContent = text;
                labelEl.style.opacity = text ? "1" : "0";
            }
        });

        const dimmed = new Set(step.dimmedNodes ?? []);
        graph.nodes.forEach((node) => {
            const nodeEl = this._staticSvg?.querySelector(
                `#mg-node-${node.id}`,
            ) as SVGGElement | null;
            if (nodeEl) nodeEl.classList.toggle("mg-node-dimmed", dimmed.has(node.id));
            // Reset sublabel to empty; per-step overrides applied below.
            const sublabelEl = this._staticSvg?.querySelector(
                `#mg-node-sublabel-${node.id}`,
            ) as SVGTextElement | null;
            if (sublabelEl) sublabelEl.textContent = "";
        });

        if (step.nodeLabels) {
            for (const [nodeId, text] of Object.entries(step.nodeLabels)) {
                const sublabelEl = this._staticSvg?.querySelector(
                    `#mg-node-sublabel-${nodeId}`,
                ) as SVGTextElement | null;
                if (sublabelEl) {
                    // Allow values to reference an opts.labels key for i18n;
                    // fall back to the literal string if no match exists.
                    sublabelEl.textContent = this.opts.labels?.[text] ?? text;
                }
            }
        }

        if (step.nodeIcons) {
            for (const [nodeId, iconFile] of Object.entries(step.nodeIcons)) {
                this._setNodeIcon(nodeId, iconFile);
            }
        }

        // Clear any in-flight sub-step timers from the previous step.
        for (const t of this._subStepTimers) clearInterval(t);
        this._subStepTimers = [];

        if (step.nodeIconSequence) {
            const stepMs = this.config.animation?.stepIntervalMs ?? 4000;
            for (const [nodeId, sequence] of Object.entries(step.nodeIconSequence)) {
                if (!sequence.length) continue;
                // Show first frame immediately, then advance every slice.
                this._setNodeIcon(nodeId, sequence[0]);
                if (sequence.length === 1) continue;
                const slice = stepMs / sequence.length;
                let idx = 1;
                const timer = window.setInterval(() => {
                    this._setNodeIcon(nodeId, sequence[idx]);
                    idx += 1;
                    if (idx >= sequence.length) {
                        clearInterval(timer);
                        this._subStepTimers = this._subStepTimers.filter((t) => t !== timer);
                    }
                }, slice);
                this._subStepTimers.push(timer);
            }
        }

        if (this.opts.weatherEl && step.weather) {
            this.opts.weatherEl.dataset.weather = step.weather;
        }

        if (this.opts.priceEl && step.price) {
            this.opts.priceEl.dataset.price = step.price;
        }

        if (this.opts.priceLabelEl && step.priceLabel !== undefined) {
            this.opts.priceLabelEl.textContent = step.priceLabel;
        }

        if (this.opts.temperatureEl && step.temperature) {
            this.opts.temperatureEl.dataset.temperature = step.temperature;
        }

        if (this.opts.temperatureLabelEl && step.temperatureLabel !== undefined) {
            this.opts.temperatureLabelEl.textContent = step.temperatureLabel;
        }

        if (this.opts.descriptionEl) {
            const text = step.descriptionKey
                ? (this.opts.descriptions?.[step.descriptionKey] ?? "")
                : "";
            this.opts.descriptionEl.textContent = text;
        }
    }
}

/**
 * Spotlight highlight: a separate fixed-grid background overlay is masked so
 * it only shows up where the moving energy units currently are.
 *
 * Scoped per-diagram: `wrapper` is the diagram-root element that contains
 * both the highlight and the canvas. The IntersectionObserver watches that
 * same wrapper so off-screen diagrams pause their animations and step timer.
 */
function attachSpotlight(
    wrapper: HTMLElement,
    highlight: HTMLElement,
    renderer: MicroGraphRenderer,
): { pauseAutoAdvance: () => void; resumeAutoAdvance: () => void; readonly isInView: boolean } {
    let stepTimer: number | null = null;
    let nextStepIdx = 0;
    let manualPause = false;
    let inView = false;

    const animation = renderer.animation;
    const steps = animation?.steps;
    const stepIntervalMs = animation?.stepIntervalMs ?? 4000;
    const hasSteps = !!steps && steps.length > 0;

    // The highlighted-grid overlay used to be revealed via a per-frame
    // mask-image animation tracking each energy unit. That loop dominated
    // CPU (especially in Firefox) and the visual effect proved too subtle
    // to be worth the cost, so the overlay is hidden and no rAF runs.
    highlight.style.display = "none";

    function tickStep() {
        if (!hasSteps) return;
        renderer.gotoStep(nextStepIdx);
        nextStepIdx = (nextStepIdx + 1) % steps!.length;
    }

    function startStepTimer() {
        if (!hasSteps || manualPause || !inView || stepTimer != null) return;
        stepTimer = window.setInterval(tickStep, stepIntervalMs);
    }

    function stopStepTimer() {
        if (stepTimer != null) {
            clearInterval(stepTimer);
            stepTimer = null;
        }
    }

    // Apply step 0 immediately so the diagram doesn't briefly show all edges active.
    tickStep();

    new IntersectionObserver(
        (entries) => {
            entries.forEach((entry) => {
                inView = entry.isIntersecting;
                if (inView) {
                    renderer.unpauseAnimations();
                    // Re-apply current step so the shared popover (eyebrow,
                    // dots, description) reflects this diagram immediately,
                    // not the one that was visible before.
                    if (hasSteps) renderer.gotoStep(renderer.currentStepIdx);
                    startStepTimer();
                } else {
                    renderer.pauseAnimations();
                    stopStepTimer();
                }
            });
        },
        { threshold: 0 },
    ).observe(wrapper);

    inView = true;
    // Intentional: start the timer synchronously here so animation begins
    // immediately on load. The IntersectionObserver above will also call
    // startStepTimer() once its initial async callback fires, but the
    // `stepTimer != null` guard inside startStepTimer makes that a no-op.
    startStepTimer();
    startStepTimer();

    return {
        pauseAutoAdvance() {
            manualPause = true;
            stopStepTimer();
        },
        resumeAutoAdvance() {
            manualPause = false;
            nextStepIdx = (renderer.currentStepIdx + 1) % Math.max(1, renderer.stepCount);
            startStepTimer();
        },
        get isInView() {
            return inView;
        },
    };
}

function initOne(canvas: HTMLElement): void {
    const configUrl = canvas.dataset.configUrl;
    const assetBase = canvas.dataset.assetBase;
    if (!configUrl || !assetBase) {
        console.warn("Diagram canvas missing data-config-url or data-asset-base");
        return;
    }

    const root =
        canvas.closest<HTMLElement>("[data-diagram-root]") ?? canvas.parentElement;
    const highlight =
        root?.querySelector<HTMLElement>("[data-diagram-highlight]") ?? null;
    const weatherEl =
        root?.querySelector<HTMLElement>("[data-diagram-weather]") ?? null;
    const priceEl =
        root?.querySelector<HTMLElement>("[data-diagram-price]") ?? null;
    const priceLabelEl =
        root?.querySelector<HTMLElement>("[data-diagram-price-label]") ?? null;
    const temperatureEl =
        root?.querySelector<HTMLElement>("[data-diagram-temperature]") ?? null;
    const temperatureLabelEl =
        root?.querySelector<HTMLElement>("[data-diagram-temperature-label]") ?? null;
    const descriptionEl =
        root?.querySelector<HTMLElement>("[data-diagram-description]")
        ?? root?.closest<HTMLElement>("[data-scenario-panel]")
            ?.querySelector<HTMLElement>("[data-diagram-description]")
        ?? root?.closest<HTMLElement>("[data-scenario-switcher]")
            ?.querySelector<HTMLElement>("[data-diagram-description]")
        ?? null;
    const stepEyebrowEl =
        root?.querySelector<HTMLElement>("[data-diagram-step-eyebrow]")
        ?? root?.closest<HTMLElement>("[data-scenario-panel]")
            ?.querySelector<HTMLElement>("[data-diagram-step-eyebrow]")
        ?? null;
    const stepDotsEl =
        root?.querySelector<HTMLElement>("[data-diagram-step-dots]")
        ?? root?.closest<HTMLElement>("[data-scenario-panel]")
            ?.querySelector<HTMLElement>("[data-diagram-step-dots]")
        ?? null;
    const stepEyebrowTemplate =
        stepEyebrowEl?.dataset.template
        ?? root?.closest<HTMLElement>("[data-scenario-panel]")
            ?.querySelector<HTMLElement>("[data-diagram-step-eyebrow]")?.dataset.template
        ?? undefined;
    const stepDotAriaTemplate =
        stepDotsEl?.dataset.ariaTemplate ?? undefined;

    let labels: Record<string, string> | undefined;
    if (canvas.dataset.labels) {
        try {
            labels = JSON.parse(canvas.dataset.labels);
        } catch (e) {
            console.warn("Diagram: failed to parse data-labels", e);
        }
    }
    let descriptions: Record<string, string> | undefined;
    if (canvas.dataset.descriptions) {
        try {
            descriptions = JSON.parse(canvas.dataset.descriptions);
        } catch (e) {
            console.warn("Diagram: failed to parse data-descriptions", e);
        }
    }
    const ariaLabel = canvas.dataset.ariaLabel;

    MicroGraphRenderer.create(configUrl, canvas, {
        assetBase,
        labels,
        descriptions,
        ariaLabel,
        weatherEl,
        priceEl,
        priceLabelEl,
        temperatureEl,
        temperatureLabelEl,
        descriptionEl,
        stepEyebrowEl,
        stepEyebrowTemplate,
        stepDotsEl,
        stepDotAriaTemplate,
    })
        .then((renderer) => {
            renderer.render();
            let controller: ReturnType<typeof attachSpotlight> | null = null;
            if (root && highlight) controller = attachSpotlight(root, highlight, renderer);
            // Pause auto-advance while the scenario info popover is open, so
            // the description the user is reading stays in sync with the
            // diagram. Resume on close.
            const panelEl = root?.closest<HTMLElement>("[data-scenario-panel]");
            if (panelEl && controller) {
                panelEl.addEventListener("scenario-popover-open", () => {
                    if (controller && !controller.isInView) return;
                    controller?.pauseAutoAdvance();
                });
                panelEl.addEventListener("scenario-popover-close", () => {
                    if (controller && !controller.isInView) return;
                    controller?.resumeAutoAdvance();
                });
            }
            if (stepDotsEl) {
                stepDotsEl.addEventListener("click", (e) => {
                    const target = e.target as HTMLElement | null;
                    const dot = target?.closest<HTMLElement>("[data-step-dot]");
                    if (!dot) return;
                    // Multiple renderers may share one dots container (e.g.
                    // battery priority/discharge sub-tabs). Only the visible
                    // one should react, otherwise it would clobber the
                    // popover with its own step description.
                    if (controller && !controller.isInView) return;
                    const idx = parseInt(dot.dataset.stepDot || "-1", 10);
                    if (idx < 0) return;
                    controller?.pauseAutoAdvance();
                    renderer.gotoStep(idx);
                });
            }

            // Touch swipe on the info popover lets the user advance/rewind
            // steps without aiming for the small dots. To make the gesture
            // visible, the description text sits on a 3-slide track
            // (prev / current / next) that follows the finger and snaps to a
            // neighbour on release, mirroring the image switcher carousel.
            //
            // A single popover can be shared by several renderers (e.g. the
            // load-management panel has static/dynamic sub-tab diagrams). Each
            // registers itself; the track + listeners are built only once and
            // resolve the currently in-view renderer at gesture time. Building
            // per renderer would otherwise wrap the description repeatedly,
            // nesting tracks and blowing up the popover height.
            const popoverEl = panelEl?.querySelector<HTMLElement>("[data-info-popover]");
            if (popoverEl && descriptionEl && descriptionEl.parentElement) {
                interface SwipeSource {
                    renderer: MicroGraphRenderer;
                    controller: ReturnType<typeof attachSpotlight> | null;
                }
                const pop = popoverEl as HTMLElement & {
                    _swipeSources?: SwipeSource[];
                    _swipeInit?: boolean;
                };
                const sources: SwipeSource[] = (pop._swipeSources ??= []);
                sources.push({ renderer, controller });

                const activeSource = (): SwipeSource =>
                    sources.find((s) => !s.controller || s.controller.isInView) ??
                    sources[0];

                if (!pop._swipeInit) {
                    pop._swipeInit = true;

                    const prefersReducedMotion = window.matchMedia(
                        "(prefers-reduced-motion: reduce)",
                    ).matches;

                    const TRANSITION = "transform 250ms ease";
                    const slideClass = descriptionEl.className;

                    // Build the viewport/track around the existing description
                    // <p>, which becomes the centre slide (renderer target).
                    const viewport = document.createElement("div");
                    viewport.className = "relative overflow-hidden";
                    const track = document.createElement("div");
                    track.className = "flex w-full";
                    track.style.transition = TRANSITION;

                    const makeSlide = (): HTMLParagraphElement => {
                        const p = document.createElement("p");
                        p.className = slideClass;
                        p.setAttribute("aria-hidden", "true");
                        p.style.flex = "0 0 100%";
                        p.style.width = "100%";
                        return p;
                    };
                    const prevSlide = makeSlide();
                    const nextSlide = makeSlide();

                    descriptionEl.parentElement!.insertBefore(viewport, descriptionEl);
                    descriptionEl.style.flex = "0 0 100%";
                    descriptionEl.style.width = "100%";
                    track.append(prevSlide, descriptionEl, nextSlide);
                    viewport.appendChild(track);

                    // Centre slide visible => shift the track left one slide.
                    const center = (animate: boolean): void => {
                        track.style.transition = animate ? TRANSITION : "none";
                        track.style.transform = "translateX(-100%)";
                    };
                    center(false);

                    const fillNeighbours = (): void => {
                        const r = activeSource().renderer;
                        const total = r.stepCount;
                        if (!total) return;
                        const cur = r.currentStepIdx;
                        prevSlide.textContent = r.descriptionForStep(cur - 1);
                        nextSlide.textContent = r.descriptionForStep(cur + 1);
                    };

                    const SWIPE_THRESHOLD = 40; // px
                    let startX = 0;
                    let startY = 0;
                    let dx = 0;
                    let tracking = false;
                    let locked = false; // horizontal gesture confirmed

                    const commit = (delta: number): void => {
                        const src = activeSource();
                        const r = src.renderer;
                        if (!r.stepCount) {
                            center(true);
                            return;
                        }
                        src.controller?.pauseAutoAdvance();
                        const finish = (): void => {
                            r.gotoStep(r.currentStepIdx + delta);
                            center(false);
                            fillNeighbours();
                        };
                        if (prefersReducedMotion) {
                            finish();
                            return;
                        }
                        // Slide fully to the chosen neighbour, then snap back
                        // once the centre slide shows that step's text.
                        track.style.transition = TRANSITION;
                        track.style.transform = `translateX(${delta > 0 ? "-200%" : "0%"})`;
                        const onEnd = (): void => {
                            track.removeEventListener("transitionend", onEnd);
                            finish();
                        };
                        track.addEventListener("transitionend", onEnd);
                    };

                    popoverEl.addEventListener(
                        "touchstart",
                        (e) => {
                            if (e.touches.length !== 1) {
                                tracking = false;
                                return;
                            }
                            startX = e.touches[0].clientX;
                            startY = e.touches[0].clientY;
                            dx = 0;
                            tracking = true;
                            locked = false;
                            fillNeighbours();
                            track.style.transition = "none";
                        },
                        { passive: true },
                    );

                    popoverEl.addEventListener(
                        "touchmove",
                        (e) => {
                            if (!tracking) return;
                            const t = e.touches[0];
                            const mx = t.clientX - startX;
                            const my = t.clientY - startY;
                            if (!locked) {
                                if (Math.abs(mx) < 8 && Math.abs(my) < 8) return;
                                if (Math.abs(mx) <= Math.abs(my)) {
                                    // Vertical scroll: let the page handle it.
                                    tracking = false;
                                    center(true);
                                    return;
                                }
                                locked = true;
                            }
                            dx = mx;
                            track.style.transform = `translateX(calc(-100% + ${dx}px))`;
                        },
                        { passive: true },
                    );

                    const end = (): void => {
                        if (!tracking) return;
                        tracking = false;
                        if (dx <= -SWIPE_THRESHOLD) {
                            commit(1); // swipe left -> next
                        } else if (dx >= SWIPE_THRESHOLD) {
                            commit(-1); // swipe right -> previous
                        } else {
                            center(true); // snap back
                        }
                    };

                    popoverEl.addEventListener("touchend", end, { passive: true });
                    popoverEl.addEventListener(
                        "touchcancel",
                        () => {
                            if (!tracking) return;
                            tracking = false;
                            center(true);
                        },
                        { passive: true },
                    );
                }
            }
        })
        .catch((err) => {
            console.error("MicroGraphRenderer failed to initialize:", err);
        });
}

function init(): void {
    const canvases = document.querySelectorAll<HTMLElement>("[data-diagram-canvas]");
    canvases.forEach(initOne);
}

if (document.readyState === "loading") {
    document.addEventListener("DOMContentLoaded", init);
} else {
    init();
}
