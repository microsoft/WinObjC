@echo off
echo.
echo Running tests from test_list.txt
echo.

SET CURTEST=
SET PASSED=TRUE
SETLOCAL enabledelayedexpansion
IF EXIST test_results.txt DEL test_results.txt

FOR /F "tokens=1 eol=#" %%t IN (test_list.txt) DO (
    SET CURTEST=%%t
    echo |set /p=!CURTEST! 
    echo. >> test_results.txt 
    echo =========^> Running !CURTEST! >> test_results.txt 
    IF NOT EXIST bin\!CURTEST!.exe (
        echo Can't find bin\!CURTEST!.exe
        SET PASSED=FALSE
        goto error
    )
    bin\!CURTEST!.exe >> test_results.txt 2>&1
    IF NOT !ERRORLEVEL!==0 (
        SET RESULT=FAILED err=!ERRORLEVEL!
        SET PASSED=FALSE
    ) ELSE (
        SET RESULT=PASSED
    )
    echo ^<========= !CURTEST! !RESULT!>> test_results.txt 
    echo. >> test_results.txt 
    
    echo !RESULT!
)
:error
IF "%PASSED%"=="TRUE" goto passed
echo.
echo One or more tests FAILED
echo.
goto done
:passed
echo.
echo All tests PASSED
echo.
:done
echo See test_results.txt for logs
echo.