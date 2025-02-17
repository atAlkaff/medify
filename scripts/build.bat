@echo off
mkdir ../build
pushd ../build
cl ../src/medify.c user32.lib gdi32.lib
popd