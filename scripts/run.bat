@echo off
call build.bat
mkdir ../data
pushd ../data
../build/medify.exe
popd