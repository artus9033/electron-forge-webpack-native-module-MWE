# electron-forge-webpack-native-module-MWE

A reproduction MWE exposing a bug in the template that fails to relocate local native modules if they are requried via `bindings`.

# Instructions

1. `git clone`
2. `npm i` (postinstall will configure & build the addon)
3. `npm run start` will greet You with an error dialog if you uncomment `src/index.ts` line 3 in favor of line 4
