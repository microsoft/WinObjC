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

pushd ..\3rdparty\openssl

:: Initialize common path
set BUILD.DEPS.PATH=%~dp0..

:: Copy all header files to include directory
echo:
echo Copying openssl header files...
echo:
echo d | xcopy /s /y inc32\openssl %BUILD.DEPS.PATH%\prebuilt\include\openssl

:: Build and deploy Windows 10 library
call ms\do_vsprojects14.bat

:Win10x86
if %BUILD.x86%==N goto Win10x64
echo:
echo Build openssl for Windows 10 apps x86...
echo:

cd vsout\NT-Universal-10.0-Dll-Unicode
call build.bat Release Win32
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\Win32\bin\*eay32.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\Win32\bin\*eay32.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\Win32\bin\*eay32.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x86\"

:Win10x64
if %BUILD.x64%==N goto Win10ARM
echo:
echo Build openssl for Windows 10 apps x64...
echo:

cd vsout\NT-Universal-10.0-Dll-Unicode
call build.bat Release x64
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\x64\bin\*eay32.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\x64\bin\*eay32.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\x64\bin\*eay32.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\x64\"

:Win10ARM
if %BUILD.ARM%==N goto Cleanup
echo:
echo Build openssl for Windows 10 apps ARM...
echo:

cd vsout\NT-Universal-10.0-Dll-Unicode
call build.bat Release arm
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\arm\bin\*eay32.dll "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\arm\bin\*eay32.lib "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"
xcopy /y vsout\NT-Universal-10.0-Dll-Unicode\Release\arm\bin\*eay32.pdb "%BUILD.DEPS.PATH%\prebuilt\Universal Windows\ARM\"

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

:Cleanup
popd
@endlocal