<#
.SYNOPSIS
   Removes *.visualstudio.com from nuget.config files.
#>
[CmdletBinding(SupportsShouldProcess=$True)]
Param (
    [Parameter(Mandatory=$true, HelpMessage="Directory of nuget.config")]
    [string]$ConfigDir
)

$nugetPath = Resolve-Path $ConfigDir
$nugetPath = Join-Path $nugetPath "nuget.config"
$xml = [xml](Get-Content $nugetPath)
$nodes = $xml.configuration.packageSources.add | where-object {$_.Value -like "*visualstudio.com*"}
$nodes.ParentNode.RemoveChild($nodes)
$xml.Save($nugetPath)