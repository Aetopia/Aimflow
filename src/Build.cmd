@echo off
cd "%~dp0">nul 2>&1
rmdir /Q /S "bin">nul 2>&1
mkdir "bin">nul 2>&1

gcc.exe -Os -Wl,--gc-sections -mwindows -nostdlib -s "WinMain.c" -lntdll -lUser32 -lKernel32 -o "bin\DumpTool.exe"
upx --best --ultra-brute "bin\*">nul 2>&1