<#
    .SYNOPSIS
    This script wraps c#'s io.compression.zipfile to unzip a zip file.
    The script is intended to be used within the VSO build to unzip the winobjc SDK.
#>
param(
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since powershell will block waiting for user input.
    [string]$zipFile = $(throw 'Mandatory parameter "zipFile" is not set.'),
    [string]$outputDir = $(throw 'Madatory parameter "outputDir" is not set.')
    )

write-host $MyInvocation.Line

Add-Type -assembly "system.io.compression.filesystem";
[io.compression.zipfile]::ExtractToDirectory($zipFile, $outputDir);

exit 0
