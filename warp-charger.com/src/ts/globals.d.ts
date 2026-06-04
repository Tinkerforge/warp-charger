// Allow side-effect CSS imports from TypeScript entries (esbuild bundles them
// into a sibling .css file). Without this, tsc cannot resolve "*.css" modules.
declare module "*.css";
