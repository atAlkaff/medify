@echo off
mkdir "../build"
pushd "../build"
cl.exe "../src/medify.cpp" user32.lib gdi32.lib taskschd.lib comsupp.lib credui.lib
popd