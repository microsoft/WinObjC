@echo off

set LIBVERSION=10.0.10586.0
set OLDLIB=%LIB%
set LIB=

if /i "%1" == "x86" goto :x86_win10
if /i "%1" == "x64" goto :x64_win10
if /i "%1" == "arm" goto :arm_win10
goto :usage

:x86_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\ATLMFC\LIB;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store;C:\Program Files (x86)\Windows Kits\10\lib\%LIBVERSION%\ucrt\x86;C:\Program Files (x86)\Windows Kits\10\Lib\%LIBVERSION%\um\x86;
set type=x86
set winPlat=Universal\ Windows
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Universal Windows/x86/"
goto :make

:x64_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\lib\amd64;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store\amd64;C:\Program Files (x86)\Windows Kits\10\Lib\%LIBVERSION%\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\Lib\%LIBVERSION%\um\x64;
set type=x64
set winPlat=Universal\ Windows
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Universal Windows/x64/"
goto :make

:arm_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\lib\arm;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store\arm;C:\Program Files (x86)\Windows Kits\10\Lib\%LIBVERSION%\ucrt\arm;C:\Program Files (x86)\Windows Kits\10\Lib\%LIBVERSION%\um\arm;
set type=arm
set winPlat=Universal\ Windows
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Universal Windows/ARM/"
goto :make

:make
set startDir=%CD:\=/%
cd ../3rdParty/cairolegacy
set prebuiltDir=%startDir%/../prebuilt
set libDir=%prebuiltDir%/%winPlat%/%type%

make clean -f Makefile.win32
rd /S /Q src\release

make -f Makefile.win32 ^
WIN_ARCH=%type% ^
WIN_VERSION=%winVersion% ^
WIN_SYSTEM_NAME=%winSystemName% ^
PIXMAN_PATH=%startDir%/../3rdParty/pixman ^
PIXMAN_CFLAGS=-I%prebuiltDir%/include ^
PIXMAN_LIBS="%libDir%/pixman.lib" ^
CAIRO_HAS_PNG_FUNCTIONS=1 ^
LIBPNG_PATH=%startDir%/../3rdParty/libpng ^
LIBPNG_CFLAGS=-I%prebuiltDir%/include ^
LIBPNG_LIBS="%libDir%/libpng.lib" ^
ZLIB_PATH=%startDir%/../3rdParty/zlib ^
ZLIB_CFLAGS=-I%prebuiltDir%/include ^
ZLIB_LIBS="%libDir%/libz.lib" ^
FREETYPE_CFLAGS=-I%prebuiltDir%/include/freetype ^
FREETYPE_LIBS="%libDir%/freetype.lib" ^
CFG=release 

if errorlevel 1 goto :compile_error

cp src/release/cairo.dll %outDir%
cp src/release/cairo.lib %outDir%
cp src/release/cairo.pdb %outDir%
cp src/release/cairo-static.lib %outDir%

cd %startDir%
set LIB=%OLDLIB%
exit /b 0

:usage 
echo Error in script usage. The correct usage is:
echo     %0 [arch]
echo where [arch] is: x86 ^| x64 ^| ARM
set LIB=%OLDLIB%
exit /b 1

:compile_error
echo There was a compile error
cd %startDir%
set LIB=%OLDLIB%
exit /b 1

