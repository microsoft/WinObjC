Param(
    [Parameter(Mandatory=$true)] [string] $repoRoot
)

$ErrorActionPreference = "Stop"

# Create the .tools directory
New-Item -ItemType Directory -Force -Path "$repoRoot\.tools" | Out-Null
$toolsDir = Join-Path -Resolve $repoRoot ".tools"

# Ensure nuget.exe is up-to-date
$nugetDownloadName = "nuget.exe"
. "$PSScriptRoot\Initialize-DownloadLatest.ps1" -OutDir $toolsDir -DownloadUrl "https://dist.nuget.org/win-x86-commandline/latest/nuget.exe" -DownloadName $nugetDownloadName -Unzip $false

# Ensure VSS.NuGet.AuthHelper is up-to-date
$credProviderDownloadFeed = "https://nuget.org/api/v2/"
$credProviderPackageName = "Microsoft.VisualStudio.Services.NuGet.CredentialProvider"
$credProviderExeName = "CredentialProvider.VSS.exe"

. "$PSScriptRoot\Initialize-InstallFromNuget.ps1" -OutDir $toolsDir -DownloadFeed $credProviderDownloadFeed -PackageName $credProviderPackageName -targetFileName $credProviderExeName

# Add the tools dir to the path which directly contains NuGet.exe and VSS.NuGet.AuthHelper.exe
if (!($env:Path -like "*$toolsDir;*"))
{
    $env:Path = "$toolsDir;" + $env:Path
}
