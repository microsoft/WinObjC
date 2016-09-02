setlocal
set curdir=%~dp0
set winobjc_root=%curdir%..\..
del WinObjC.1.0.0.nupkg
nuget.exe pack -nopackageanalysis -Properties winobjc_root=%winobjc_root% -Verbosity detailed WinObjC.nuspec
