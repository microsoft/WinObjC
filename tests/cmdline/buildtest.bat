@echo off
SET LIBS=objcrt.lib;Starboard.lib;Foundation.lib;CoreFoundation.lib;UIKit.lib;libdispatch.lib
SET TESTNAME=%1

SHIFT
SET  TESTFILES=%1
SHIFT

:parsefiles
if "%~1" neq "" (
  set TESTFILES=%TESTFILES%;%1
  shift
  goto :parsefiles
)

echo Building %TESTNAME%
msbuild /verbosity:quiet /nologo cmdline.vcxproj.template /property:TestName="%TESTNAME%" /property:TestFilenames="%TESTFILES%" /property:LinkLibraries="%LIBS%"

