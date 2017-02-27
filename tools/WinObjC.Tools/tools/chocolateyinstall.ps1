#NOTE: Please remove any commented lines to tidy up prior to releasing the package, including this one

$ErrorActionPreference = 'SilentlyContinue';

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

#
# TODO: Remove 2015 support when VS2017 ships. At that point, treat errors as failures since only one version will be supported.
#

Try
{
    Write-Host "Installing Objective-C Visual Studio 2015 Extension ... "
    Install-ChocolateyVsixPackage -PackageName "objc-syntax-highlighting" -VsixUrl "file:///$toolsDir/objc-syntax-highlighting.vsix" -VsVersion 14
}
Catch [Exception]
{
    Write-Warning "$_"
}

Try
{
    Write-Host "Installing Nugetizer Visual Studio 2015 Extension ... "
    Install-ChocolateyVsixPackage -PackageName "Nugetizer3000" -VsixUrl "file:///$toolsDir/NuGetizer3000-VS2015.vsix" -VsVersion 14
}
Catch [Exception]
{
    Write-Warning "$_"
}

Try
{
    Write-Host "Installing Objective-C Visual Studio 2017 Extension ... "
    Install-ChocolateyVsixPackage -PackageName "objc-syntax-highlighting" -VsixUrl "file:///$toolsDir/objc-language-services-VS2017.vsix" -VsVersion 15
}
Catch [Exception]
{
    Write-Warning "$_"
}

Try
{
    Write-Host "Installing Nugetizer Visual Studio 2017 Extension ... "
    Install-ChocolateyVsixPackage -PackageName "Nugetizer3000" -VsixUrl "http://bit.ly/nugetizer-2017" -VsVersion 15
}
Catch [Exception]
{
    Write-Warning "$_"
}

# if removing $url64, please remove from here
# despite the name "Install-ChocolateyZipPackage" this also works with 7z archives
#Install-ChocolateyZipPackage "$packageName" "$url" "$installDir" "$url64"
# END PORTABLE EXAMPLE
