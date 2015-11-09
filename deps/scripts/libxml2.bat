@setlocal
@echo off

if "%1" == "/?" goto Usage

:: Initialize build configuration
set BUILD.ARM=N
set BUILD.x86=N
set BUILD.x64=N
set BUILD.win10=N
set BUILD.win8.1=N
set BUILD.phone8.1=N

:: Iterate through arguments and set the right configuration
for %%a in (%*) do (
    if /I "%%a"=="ARM" (
        set BUILD.ARM=Y
    ) else if /I "%%a"=="x86" (
        set BUILD.x86=Y
    ) else if /I "%%a"=="x64" (
        set BUILD.x64=Y
    ) else if /I "%%a"=="win10" (
        set BUILD.win10=Y
    ) else if /I "%%a"=="win8.1" (
        set BUILD.win8.1=Y
    ) else if /I "%%a"=="phone8.1" (
        set BUILD.phone8.1=Y
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

:: Set build all platform if none are specified
if %BUILD.win10%==N (
    if %BUILD.win8.1%==N (
        if %BUILD.phone8.1%==N (
            set BUILD.win10=Y
            set BUILD.win8.1=Y
            set BUILD.phone8.1=Y
        )
    )
)

pushd ..\3rdparty\libxml2legacy

:: Check for required tools
if not defined MSBUILD_BIN goto :MissingMSBuild
if not exist %MSBUILD_BIN% goto :MissingMSBuild

:: Initialize common path
set BUILD.DEPS.PATH=%~dp0..

:: Copy all header files to include directory
echo:
echo Copying libxml2 header files...
echo:
xcopy /y /i include\libxml\*.h %BUILD.DEPS.PATH%\prebuilt\include\libxml

:: Build and deploy Windows 10 library
:Win10
if %BUILD.win10%==N goto Win8.1

:Win10x86
if %BUILD.x86%==N goto Win10x64
echo:
echo Build libxml2 for Windows 10 apps x86...
echo:

%MSBUILD_BIN% Win10\libxml2.Win10.vcxproj /p:Configuration=Release;Platform=x86

call :CopyBuildOutput Win10 Win10 "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86"

:Win10x64
if %BUILD.x64%==N goto Win10ARM
echo:
echo Build libxml2 for Windows 10 apps x64...
echo:

%MSBUILD_BIN% Win10\libxml2.Win10.vcxproj /p:Configuration=Release;Platform=x64

call :CopyBuildOutput Win10\x64 Win10 "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\X64"

:Win10ARM
if %BUILD.ARM%==N goto Win8.1
echo:
echo Build libxml2 for Windows 10 apps ARM...
echo:

%MSBUILD_BIN% Win10\libxml2.Win10.vcxproj /p:Configuration=Release;Platform=ARM

call :CopyBuildOutput Win10\ARM Win10 "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM"

:: Build and deploy Windows 8.1 library
:Win8.1
if %BUILD.win8.1%==N goto Phone8.1

:Win8.1x86
if %BUILD.x86%==N goto Win8.1x64
echo:
echo Build libxml2 for Windows 8.1 apps x86...
echo:

%MSBUILD_BIN% Win8.1\Win8.1.Windows\libxml2.Win8.1.Windows.vcxproj /p:Configuration=Release;Platform=x86

call :CopyBuildOutput Win8.1\Win8.1.Windows\. Win8.1.Windows "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86"

:Win8.1x64
if %BUILD.x64%==N goto Win8.1ARM
echo:
echo Build libxml2 for Windows 8.1 apps x64...
echo:

%MSBUILD_BIN% Win8.1\Win8.1.Windows\libxml2.Win8.1.Windows.vcxproj /p:Configuration=Release;Platform=x64

call :CopyBuildOutput Win8.1\Win8.1.Windows\x64 Win8.1.Windows "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64"

:Win8.1ARM
if %BUILD.ARM%==N goto Phone8.1
echo:
echo Build libxml2 for Windows 8.1 apps ARM...
echo:

%MSBUILD_BIN% Win8.1\Win8.1.Windows\libxml2.Win8.1.Windows.vcxproj /p:Configuration=Release;Platform=ARM

call :CopyBuildOutput Win8.1\Win8.1.Windows\ARM Win8.1.Windows "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM"

:: Build and deploy Windows Phone 8.1 library
:Phone8.1
if %BUILD.phone8.1%==N goto Cleanup

:Phone8.1ARM
if %BUILD.ARM%==N goto Phone8.1x86
echo:
echo Build libxml2 for Windows Phone 8.1 apps ARM...
echo:

%MSBUILD_BIN% Win8.1\Win8.1.WindowsPhone\libxml2.Win8.1.WindowsPhone.vcxproj /p:Configuration=Release;Platform=ARM

call :CopyBuildOutput Win8.1\Win8.1.WindowsPhone\ARM Win8.1.WindowsPhone "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM"

:Phone8.1x86
if %BUILD.x86%==N goto Cleanup
echo:
echo Build libxml2 for Windows Phone 8.1 apps x86...
echo:

%MSBUILD_BIN% Win8.1\Win8.1.WindowsPhone\libxml2.Win8.1.WindowsPhone.vcxproj /p:Configuration=Release;Platform=x86

call :CopyBuildOutput Win8.1\Win8.1.WindowsPhone\. Win8.1.WindowsPhone "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86"

goto Cleanup

:: Display help message
:Usage
echo The correct usage is:
echo     %0 [option]
echo:
echo where [option] is: ARM ^| x86 ^| x64 ^| win10 ^| win8.1 ^| phone8.1
echo:
echo For example:
echo     %0 win10
echo     %0 phone8.1 ARM
echo     %0 ARM x86
goto :eof

:MissingMSBuild
echo MSBuild.exe is needed. Install and provide the executable path in MSBUILD_BIN environment variable. E.g.
echo:
echo     set MSBUILD_BIN="C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
goto Cleanup

:Cleanup
popd
@endlocal
exit /b

:CopyBuildOutput
xcopy /y /i %1\Release\libxml2.%2\libxml2.dll %3\libxml2.dll
xcopy /y /i %1\Release\libxml2.%2\libxml2.lib %3\libxml2.lib
xcopy /y /i %1\Release\libxml2.%2\libxml2.pdb %3\libxml2.pdb
exit /b
