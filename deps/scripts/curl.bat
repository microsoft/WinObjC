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

pushd ..\3rdparty\curl

:: Check for required tools
if not defined CMAKE_BIN goto :MissingCMake
if not exist %CMAKE_BIN% goto :MissingCMake
if not defined MSBUILD_BIN goto :MissingMSBuild
if not exist %MSBUILD_BIN% goto :MissingMSBuild
where git > nul 2>nul
if errorlevel 1 goto :MissingGit

:: Applying patch to curl source code if it has not been previously applied
git diff --exit-code > nul 2>nul
if %errorlevel% equ 0 (
    echo:
    echo Applying curl.patch on top of %cd%...
    echo:
    git apply %~dp0curl.patch
)

:: Initialize common path
set BUILD.DEPS.PATH=%~dp0..

:: Copy all header files to include directory
echo:
echo Copying curl header files...
echo:
xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl

:: Build and deploy Windows 10 library
:Win10
if %BUILD.win10%==N goto Win8.1

:Win10x86
if %BUILD.x86%==N goto Win10x64
echo:
echo Build curl for Windows 10 apps x86...
echo:

rd /s /q win10x86 > nul 2>nul
rd /s /q win10x86 > nul 2>nul
md win10x86
pushd win10x86

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 14 2015" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="10.0"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"

popd

:Win10x64
if %BUILD.x64%==N goto Win10ARM
echo:
echo Build curl for Windows 10 apps x64...
echo:

rd /s /q win10x64 > nul 2>nul
rd /s /q win10x64 > nul 2>nul
md win10x64
pushd win10x64

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 14 2015 Win64" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="10.0"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"

popd

:Win10ARM
if %BUILD.ARM%==N goto Win8.1
echo:
echo Build curl for Windows 10 apps ARM...
echo:

rd /s /q win10ARM > nul 2>nul
rd /s /q win10ARM > nul 2>nul
md win10ARM
pushd win10ARM

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 14 2015 ARM" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="10.0"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"

popd

:: Build and deploy Windows 8.1 library
:Win8.1
if %BUILD.win8.1%==N goto Phone8.1

:Win8.1x86
if %BUILD.x86%==N goto Win8.1x64
echo:
echo Build curl for Windows 8.1 apps x86...
echo:

rd /s /q win8.1x86 > nul 2>nul
rd /s /q win8.1x86 > nul 2>nul
md win8.1x86
pushd win8.1x86

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 12 2013" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="8.1"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x86\"

popd

:Win8.1x64
if %BUILD.x64%==N goto Win8.1ARM
echo:
echo Build curl for Windows 8.1 apps x64...
echo:

rd /s /q win8.1x64 > nul 2>nul
rd /s /q win8.1x64 > nul 2>nul
md win8.1x64
pushd win8.1x64

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 12 2013 Win64" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="8.1"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\x64\"

popd

:Win8.1ARM
if %BUILD.ARM%==N goto Phone8.1
echo:
echo Build curl for Windows 8.1 apps ARM...
echo:

rd /s /q win8.1ARM > nul 2>nul
rd /s /q win8.1ARM > nul 2>nul
md win8.1ARM
pushd win8.1ARM

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 12 2013 ARM" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsStore" ^
-DCMAKE_SYSTEM_VERSION="8.1"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Windows 8.1\ARM\"

popd

:: Build and deploy Windows Phone 8.1 library
:Phone8.1
if %BUILD.phone8.1%==N goto Cleanup

:Phone8.1ARM
if %BUILD.ARM%==N goto Phone8.1x86
echo:
echo Build curl for Windows Phone 8.1 apps ARM...
echo:

rd /s /q phone8.1ARM > nul 2>nul
rd /s /q phone8.1ARM > nul 2>nul
md phone8.1ARM
pushd phone8.1ARM

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 12 2013 ARM" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsPhone" ^
-DCMAKE_SYSTEM_VERSION="8.1"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\ARM\"

popd

:Phone8.1x86
if %BUILD.x86%==N goto Cleanup
echo:
echo Build curl for Windows Phone 8.1 apps x86...
echo:

rd /s /q phone8.1x86 > nul 2>nul
rd /s /q phone8.1x86 > nul 2>nul
md phone8.1x86
pushd phone8.1x86

%CMAKE_BIN% ^
.. ^
-G "Visual Studio 12 2013" ^
-DOPENSSL_ROOT_DIR="%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86" ^
-DOPENSSL_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DZLIB_LIBRARY="%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86\libz.lib" ^
-DZLIB_INCLUDE_DIR="%BUILD.DEPS.PATH%\prebuilt\include" ^
-DBUILD_CURL_TESTS:BOOL="OFF" ^
-DCURL_DISABLE_TELNET:BOOL="ON" ^
-DCMAKE_SYSTEM_NAME="WindowsPhone" ^
-DCMAKE_SYSTEM_VERSION="8.1"

%MSBUILD_BIN% lib\libcurl.vcxproj /p:configuration=RelWithDebInfo

xcopy /y /i include\curl\*.h %BUILD.DEPS.PATH%\prebuilt\include\curl
xcopy /y lib\RelWithDebInfo\libcurl.dll "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86\"
xcopy /y lib\RelWithDebInfo\libcurl_imp.lib "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86\"
xcopy /y lib\RelWithDebInfo\libcurl.pdb "%BUILD.DEPS.PATH%\prebuilt\Windows Phone 8.1\x86\"

popd

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

:MissingCMake
echo CMake is needed. Install and provide the executable path in CMAKE_BIN environment variable. E.g.
echo:
echo     set CMAKE_BIN="C:\Program Files (x86)\CMake\Bin\cmake.exe"
goto Cleanup

:MissingMSBuild
echo MSBuild.exe is needed. Install and provide the executable path in MSBUILD_BIN environment variable. E.g.
echo:
echo     set MSBUILD_BIN="C:\Program Files (x86)\MSBuild\14.0\Bin\MSBuild.exe"
goto Cleanup

:MissingGit
echo Git is needed. Install and ensure git is in your path environment variable
goto Cleanup

:Cleanup
popd
@endlocal