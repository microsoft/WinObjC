@echo off

set LIBVERSION=10.0.10586.0

if "%1" == "x86" goto :make
if "%1" == "x64" goto :make
if "%1" == "ARM" goto :make
goto :usage

:make
set startDir=%CD:\=/%
set prebuiltDir=%startDir%/../prebuilt
set type=%1
set libDir="%prebuiltDir%/Universal Windows/%type%"
set headerDir="%prebuiltDir%/include"

cd "%2"
nmake clean -f Makefile.msc

nmake /f Makefile.msc libsqlite3.dll ^
FOR_WINRT=1 ^
FOR_UWP=1 ^
PLATFORM=%type% ^
NSDKLIBPATH="%WindowsSdkDir%\lib\%LIBVERSION%\um\%type%" ^
PSDKLIBPATH="%WindowsSdkDir%\lib\%LIBVERSION%\um\%type%" ^
NUCRTLIBPATH="%UniversalCRTSdkDir%\lib\%LIBVERSION%\ucrt\%type%" ^
CORE_COMPILE_OPTS="-DSQLITE_API=__declspec(dllexport) -DSQLITE_ENABLE_FTS5=1" ^
SQLITE3DLL=libsqlite3.dll ^
SQLITE3LIB=libsqlite3.lib

if errorlevel 1 goto :compile_error

cp libsqlite3.dll %libDir%
cp libsqlite3.lib %libDir%
cp libsqlite3.pdb %libDir%
cp sqlite3.h %headerDir%

cd %startDir%
set LIB=%OLDLIB%
exit /b 0

:usage 
echo Error in script usage. The correct usage is:
echo     %0 [arch] [path-to-source]
echo where [arch] is: x86 ^| x64 ^| ARM
set LIB=%OLDLIB%
exit /b 1

:compile_error
echo There was a compile error
cd %startDir%
exit /b 1

