@echo off
echo.
echo Building tests from test_list.txt
echo.

SET CURTEST=
SETLOCAL enabledelayedexpansion

FOR /F "delims= eol=#" %%t IN ( test_list.txt ) DO (
    SET CURTEST=%%t
    CALL buildtest.bat !CURTEST!
    IF NOT !ERRORLEVEL!==0 goto error
)
goto succeeded
:error
echo.
echo Building tests FAILED
echo.
goto done
:succeeded
echo.
echo Building tests SUCCEEDED
echo.
:done