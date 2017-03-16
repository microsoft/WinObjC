param(
    [Parameter(Mandatory=$true)] [string] $repoRoot
)

$ErrorActionPreference = "Stop"

$scriptsDir = $PSScriptRoot
$customScriptsDir = "$repoRoot\scripts\"
$preInitScript = "$customScriptsDir\PreInit.ps1"
$preRestoreToolsScript = "$customScriptsDir\PreRestoreTools.ps1"
$postInitScript = "$customScriptsDir\PostInit.ps1"

# Run PreInit.ps1 if it exists
if (Test-Path $preInitScript) {
    . $preInitScript -RepoRoot $repoRoot
}

# Download the NuGet tools if necessary
. "$scriptsDir\Initialize-NuGet.ps1" -RepoRoot $repoRoot

# Run PreRestoreTools.ps1 if it exists
if (Test-Path $preRestoreToolsScript) {
    . $preRestoreToolsScript -RepoRoot $repoRoot
}

# Restores tool packages (if .nuget\tools\packages.config exists)
. "$scriptsDir\Restore-ToolPackages.ps1" -RepoRoot $repoRoot

# Run PostInit.ps1 if it exists
if (Test-Path $postInitScript) {
    . $postInitScript -RepoRoot $repoRoot
}