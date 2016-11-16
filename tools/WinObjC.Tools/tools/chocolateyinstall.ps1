#NOTE: Please remove any commented lines to tidy up prior to releasing the package, including this one

# stop on all errors
$ErrorActionPreference = 'Stop';


$packageName = 'WinObjC.tools' # arbitrary name for the package, used in messages
$registryUninstallerKeyName = 'WinObjC.tools' #ensure this is the value in the registry
$installerType = 'EXE_MSI_OR_MSU' #only one of these: exe, msi, msu
$url = '' # download url
$url64 = '' # 64bit URL here or remove - if installer decides, then use $url
$silentArgs = '' # "/s /S /q /Q /quiet /silent /SILENT /VERYSILENT" # try any of these to get the silent installer #msi is always /quiet
$validExitCodes = @(0) #please insert other valid exit codes here, exit codes for ms http://msdn.microsoft.com/en-us/library/aa368542(VS.85).aspx
$toolsDir = "$(Split-Path -parent $MyInvocation.MyCommand.Definition)"

Write-Host "Adding `'$toolsDir`' to the path and the current shell path"
Install-ChocolateyPath "$toolsDir"
$env:Path = "$($env:Path);$toolsDir"

Write-Host "Installing Objective-C Visual Studio Extension ... "
Install-ChocolateyVsixPackage -PackageName "objc-syntax-highlighting" -VsixUrl "file:///$toolsDir/objc-syntax-highlighting.vsix"

Write-Host "Installing Nugetizer Visual Studio Extension ... "
Install-ChocolateyVsixPackage -PackageName "Nugetizer3000" -VsixUrl "http://bit.ly/nugetizer2015"

# if removing $url64, please remove from here
# despite the name "Install-ChocolateyZipPackage" this also works with 7z archives
#Install-ChocolateyZipPackage "$packageName" "$url" "$installDir" "$url64"
# END PORTABLE EXAMPLE
