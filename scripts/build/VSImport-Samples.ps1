<#
    .SYNOPSIS
    This script is used in the VSO build to unzip the WinObjC.Tools NuGet
    package and run vsimporter on the samples that have a XCode Project.
#>
param(
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since
    #      powershell will block waiting for user input.
    [string]$zipFile = $(throw 'Mandatory parameter "zipFile" is not set.'),
    [string]$tempDir = $(throw 'Madatory parameter "tempDir" is not set.')
    )

write-host $MyInvocation.Line
$ErrorActionPreference = "Stop"

& $PSScriptRoot\unzip.ps1 -zipFile $zipFile -outputDir $tempDir

$XCodeProjects = gci -recurse $PSScriptRoot\..\..\samples\*.xcodeproj
$XCodeProjects += gci -recurse $PSScriptRoot\..\..\tests\testapps\*.xcodeproj
foreach($XCodeProject in $XCodeProjects)
{
    write-host $XCodeProject
    & $tempDir\tools\vsimporter.exe -project $XCodeProject
    if($lastexitcode -ne 0)
    {
        throw "VSImporter exited with error code: $lastexitcode"
    }
}

Remove-Item $tempDir -Force -Recurse

exit 0
