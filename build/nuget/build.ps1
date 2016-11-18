<#
.SYNOPSIS
    Creates a nuget package for the specified nuspec.
#>
Param (
        [Parameter(Mandatory=$true, HelpMessage="nuspec file")]
        [string]$Nuspec,

        [Parameter(Mandatory=$false, HelpMessage="repo to pull binaries for nuspec")]
        [string]$Repo,

        [Parameter(Mandatory=$false, HelpMessage="Build Configuration")]
        [ValidateSet('debug', 'release')]
        [string]$BuildConfiguration = 'debug'
)

$scriptPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName
if(!$Repo) {
    $Repo = [System.IO.Path]::Combine($scriptPath, "..\..")
}

$version = "0.0.1"
$timeStamp = get-date -format yyyyMMddHHmmss
$fullVersion = "$version-$timeStamp.pr"

$nuget = [System.IO.Path]::Combine($scriptPath, "nuget.exe")

$nugetArgs = "pack -nopackageanalysis -Version $fullVersion -Properties root=$Repo -Properties configuration=$BuildConfiguration -Verbosity detailed $Nuspec"

write-host $nuget $nugetArgs
& $nuget $nugetArgs.split()

