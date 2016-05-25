@setlocal
@echo off

if "%1" == "/?" goto Usage

:: Initialize build configuration
set BUILD.ARM=N
set BUILD.x86=N
set BUILD.x64=N

:: Iterate through arguments and set the right configuration
for %%a in (%*) do (
    if /I "%%a"=="ARM" (
        set BUILD.ARM=Y
    ) else if /I "%%a"=="x86" (
        set BUILD.x86=Y
    ) else if /I "%%a"=="x64" (
        set BUILD.x64=Y
    ) else (
        goto Usage
    )
)

:: Set build all architecture if none are specified
if %BUILD.ARM%==N (
    if %BUILD.x86%==N (
        if %BUILD.x64%==N (
            set BUILD.ARM=Y
            set BUILD.x86=Y
            set BUILD.x64=Y
        )
    )
)

pushd ..\3rdparty\pixmanlegacy

:: Check for required tools
if not defined MSBUILD_PATH goto :MissingMSBuild
if not exist %MSBUILD_PATH% goto :MissingMSBuild

:: Initialize common path
set BUILD.DEPS.PATH=%~dp0..
set MSBUILD_BIN="%MSBUILD_PATH%"

:: Copy all header files to include directory
echo:
echo Copying pixman header files...
echo:
xcopy /y /i pixman\pixman.h %BUILD.DEPS.PATH%\prebuilt\include\
xcopy /y /i pixman\pixman-version.h %BUILD.DEPS.PATH%\prebuilt\include\

:: Build and deploy Windows 10 library
:Win10x86
if %BUILD.x86%==N goto Win10x64
echo:
echo Build pixman for Windows 10 apps x86...
echo:

%MSBUILD_BIN% Win10\pixmanlegacy.Windows10\pixmanlegacy.Windows10.vcxproj /p:Configuration=Release;Platform=x86

xcopy /y /i Win10\pixmanlegacy.Windows10\Release\pixmanlegacy.Windows10\pixman.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86"

:Win10x64
if %BUILD.x64%==N goto Win10ARM
echo:
echo Build pixman for Windows 10 apps x64...
echo:

%MSBUILD_BIN% Win10\pixmanlegacy.Windows10\pixmanlegacy.Windows10.vcxproj /p:Configuration=Release;Platform=x64

xcopy /y /i Win10\pixmanlegacy.Windows10\x64\Release\pixmanlegacy.Windows10\pixman.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64"


:Win10ARM
if %BUILD.ARM%==N goto Cleanup
echo:
echo Build pixman for Windows 10 apps ARM...
echo:

%MSBUILD_BIN% Win10\pixmanlegacy.Windows10\pixmanlegacy.Windows10.vcxproj /p:Configuration=Release;Platform=ARM

xcopy /y /i Win10\pixmanlegacy.Windows10\ARM\Release\pixmanlegacy.Windows10\pixman.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM"

goto Cleanup

:: Display help message
:Usage
echo The correct usage is:
echo     %0 [option]
echo:
echo where [option] is: ARM ^| x86 ^| x64
echo:
echo For example:
echo     %0 ARM x86
goto :eof

:MissingMSBuild
echo MSBuild.exe is needed. Install and provide the executable path in MSBUILD_BIN environment variable. E.g.
echo:
echo     set MSBUILD_BIN=C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe
goto Cleanup

:Cleanup
popd
@endlocal
