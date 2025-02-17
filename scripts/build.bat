@echo off
mkdir "../build"
pushd "../build"
cl.exe "../src/medify.c" user32.lib gdi32.lib
popd