#NOTE: Ple$ErrorActionPreference = 'Stop';

$packageName = 'WinObjC.tools'
$silentArgs = '' # "/s /S /q /Q /quiet /silent /SILENT /VERYSILENT" # try any of these to get the silent installer #msi is always /quiet
$validExitCodes = @(0) #please insert other valid exit codes here, exit codes for ms http://msdn.microsoft.com/en-us/library/aa368542(VS.85).aspx
$toolsDir = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"

$installPath = & $toolsDir\vswhere.exe -latest -property installationPath

if(!$installPath) {
    throw "There was an error finding latest Visual Studio Install location. Please make sure Visual Studio (2017 or later) is installed correctly."
}

$vsixInstaller = gci -File -Recurse -Filter vsixinstaller.exe -Path $installPath

Write-Host "Uninstalling Objective-C Visual Studio 2017 Extension ... " -ForegroundColor Blue

$result = & $vsixInstaller.FullName /q /uninstall:VSIX..9c35fff1-f084-44c1-a38e-68c707163aa2
if($result -eq 2004) { #2004: Blocking Process (need to close VS)
    throw "A process is blocking the uninstallation of the Visual Studio Extension. Please close all Visual Studio instances and try again."
}

if($result -gt 0 -and $result -ne 1002) { #1002: Not installed
    throw "There was an error uninstalling the Objective-C Visual Studio 2017 Extension. The exit code returned was $result."
}

Write-Host "Uninstalling Nugetizer Visual Studio 2017 Extension ... " -ForegroundColor Blue
$result =  & $vsixInstaller.FullName /q /uninstall:NuGet.Packaging
if($result -eq 2004) { #2004: Blocking Process (need to close VS)
    throw "A process is blocking the uninstallation of the Visual Studio Extension. Please close all Visual Studio instances and try again."
}

if($result -gt 0 -and $result -ne 1002) { #1002: Not installed
    throw "There was an error uninstalling the Objective-C Visual Studio 2017 Extension. The exit code returned was $result."
}