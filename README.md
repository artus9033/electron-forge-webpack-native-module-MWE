# electron-forge-webpack-native-module-MWE

A reproduction MWE exposing a bug in the template that fails to relocate native modules that are `npm link`-ed or installed with `npm i ./src/native`.

# Instructions

1. `git clone`
2. `npm i`
3. `cd src`
4. `cd native`
5. `npm i` (postinstall will configure & build the addon)
6. `npm link`
7. `cd ../..`
8. `npm link native-module`
9. `npm run start` will greet You with an error dialog:
