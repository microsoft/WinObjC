

set OLDLIB=%LIB%
set LIB=

if /i "%1" == "x86" goto :x86_chooser
if /i "%1" == "x64" goto :x64_chooser
if /i "%1" == "arm" goto :arm_chooser
goto :usage

:x86_chooser
if /i "%2" == "10.0" goto :x86_win10
if /i "%2" == "8.1" goto :x86_win8.1
if /i "%2" == "phone8.1" goto :x86_win_phone8.1
goto :usage

:x64_chooser
if /i "%2" == "10.0" goto :x64_win10
if /i "%2" == "8.1" goto :x64_win8.1
goto :usage

:arm_chooser
if /i "%2" == "10.0" goto :arm_win10
if /i "%2" == "8.1" goto :arm_win8.1
if /i "%2" == "phone8.1" goto :arm_win_phone8.1
goto :usage

:x86_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\ATLMFC\LIB;C:\Program Files (x86)\Windows Kits\10\\lib\10.0.10056.0\ucrt\x86;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10069.0\um\x86;
set type=x86
set winPlat=Windows\ Universal
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows Universal/x86/"
goto :make

:x64_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\lib\amd64;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store\amd64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10069.0\ucrt\x64;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10069.0\um\x64;
set type=x64
set winPlat=Windows\ Universal
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows Universal/x64/"
goto :make

:arm_win10
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\atlmfc\lib\arm;C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\lib\store\arm;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10069.0\ucrt\arm;C:\Program Files (x86)\Windows Kits\10\Lib\10.0.10069.0\um\arm;
set type=arm
set winPlat=Windows\ Universal
set winVersion=10.0
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows Universal/ARM/"
goto :make

:x86_win8.1
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib\store;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib;C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x86; 
set type=x86
set winPlat=Windows\ 8.1
set winVersion=8.1
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows 8.1/x86/"
goto :make

:x64_win8.1
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib\store\amd64;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib\amd64;C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\x64; 
set type=x64
set winPlat=Windows\ 8.1
set winVersion=8.1
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows 8.1/x64/"
goto :make

:arm_win8.1
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib\store\arm;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib\arm;C:\Program Files (x86)\Windows Kits\8.1\Lib\winv6.3\um\arm; 
set type=arm
set winPlat=Windows\ 8.1
set winVersion=8.1
set winSystemName=WindowsStore
set outdir="../../prebuilt/Windows 8.1/ARM/"
goto :make

:x86_win_phone8.1
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib\store;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib;C:\Program Files (x86)\Windows Phone Kits\8.1\lib\x86;
set type=x86
set winPlat=Windows\ Phone\ 8.1
set winVersion=8.1
set winSystemName=WindowsPhone
set outdir="../../prebuilt/Windows Phone 8.1/x86/"
goto :make

:arm_win_phone8.1
set LIB=C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\lib\store\arm;C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\atlmfc\lib\arm;C:\Program Files (x86)\Windows Phone Kits\8.1\lib\ARM; 
set type=arm
set winPlat=Windows\ Phone\ 8.1
set winVersion=8.1
set winSystemName=WindowsPhone
set outdir="../../prebuilt/Windows Phone 8.1/ARM/"
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
echo     %0 [arch] [platform]
echo where [arch] is: x86 ^| x64 ^| ARM
echo       [platform] is: 10.0 ^| 8.1 ^| phone8.1
echo Note that phone8.1 and x64 may not be used simultaneously
set LIB=%OLDLIB%
exit /b 1

:compile_error
echo There was a compile error
cd %startDir%
set LIB=%OLDLIB%
exit /b 1

