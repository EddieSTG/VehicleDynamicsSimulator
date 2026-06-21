@echo off
rem Build script that uses the existing CMakePresets.json
rem Usage: build.bat [preset]

set PRESET=%1
if "%PRESET%"=="" set PRESET=x64-release

necho Configuring with preset %PRESET%...
cmake --preset %PRESET%
if %ERRORLEVEL% neq 0 exit /b %ERRORLEVEL%

necho Building with preset %PRESET%...
cmake --build --preset %PRESET%
exit /b %ERRORLEVEL%
