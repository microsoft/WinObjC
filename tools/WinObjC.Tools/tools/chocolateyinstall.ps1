$ErrorActionPreference = 'Stop';

$packageName = 'WinObjC.tools'
$silentArgs = '' # "/s /S /q /Q /quiet /silent /SILENT /VERYSILENT" # try any of these to get the silent installer #msi is always /quiet
$validExitCodes = @(0) #please insert other valid exit codes here, exit codes for ms http://msdn.microsoft.com/en-us/library/aa368542(VS.85).aspx
$toolsDir = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"

$installPath = & vswhere -latest -property installationPath

if(!$installPath) {
    throw "There was an error finding latest Visual Studio install location. Please make sure Visual Studio (2017 or later) is installed correctly."
}

$vsixInstaller = gci -File -Recurse -Filter vsixinstaller.exe -Path $installPath

Write-Host "Installing Objective-C Visual Studio 2017 Extension ... " -ForegroundColor Blue

$result = Install-Vsix -Installer $vsixInstaller.FullName -InstallFile "$toolsDir\objc-language-services-VS2017.vsix"
if($result -eq 2004) { #2004: Blocking Process (need to close VS)
    throw "A process is blocking the installation of the Visual Studio Extension. Please close all Visual Studio instances and try again."
}

if($result -gt 0 -and $result -ne 1001) { #1001: Already installed
    throw "There was an error installing the Objective-C Visual Studio 2017 Extension. The exit code returned was $result."
}

Write-Host "Downloading Nugetizer Visual Studio 2017 Extension ... " -ForegroundColor Blue
Get-ChocolateyWebFile -PackageName $packageName -FileFullPath "$toolsDir\nugetizer-2017.vsix" -Url 'http://bit.ly/nugetizer-2017'

Write-Host "Installing Nugetizer Visual Studio 2017 Extension ... " -ForegroundColor Blue
$result = Install-Vsix -Installer $vsixInstaller.FullName -InstallFile "$toolsDir\nugetizer-2017.vsix"
if($result -eq 2004) { #2004: Blocking Process (need to close VS)
    throw "A process is blocking the installation of the Visual Studio Extension. Please close all Visual Studio instances and try again."
}

if($result -gt 0 -and $result -ne 1001) { #1001: Already installed
    throw "There was an error installing the Objective-C Visual Studio 2017 Extension. The exit code returned was $result."
}
