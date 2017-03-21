<#
.SYNOPSIS
    Runs Functional Tests for Islandwood project.

.PARAMETER TestDirectory
    The path to test binaries

.PARAMETER Platform
    platform to run tests on. Valid values are Win32 or ARM

.PARAMETER Config
    Test configuration to use for the test. Valid values are Debug or Release

.PARAMETER Device
    IP or MAC address of the device to run tests on

.PARAMETER ModuleFilter
    Regex of Test Modules to look for

.PARAMETER TestFilter
    Test filter to use for the test. Supports wildcard characters

.PARAMETER WTLOutputDirectory
    Path to test output. If not set, no result file will be saved.

.PARAMETER NoCopy
    Switch to disable copying test to the device

.PARAMETER RedirectTAEFErrors
    Redirect TAEF errors/failures to stderr.  This is used to integrate with VSTS powershell task.

.PARAMETER WTTLogPath
    Path to find WTTLog dll

.PARAMETER OutputDir
    Path to write test outptu files to.
    
.EXAMPLE
    Run-UnitTests.ps1 
    Run-UnitTests.ps1 -Platform ARM

#>
param(
    [string]$TestDirectory,

    [string][ValidateSet("Win32", "ARM")]
    $Platform = "Win32",

    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [string]$Device = "127.0.0.1",

    [string]$ModuleFilter = "*.UnitTests.dll",

    [string]$TestFilter,

    [string]$WTLOutputFile,

    [switch]$NoCopy,

    [switch]$RedirectTAEFErrors,

    [string]$WTTLogPath,

    [string]$OutputDir
)

$args = @()
if ($TestDirectory) { $args += ("-TestDirectory", $TestDirectory) }
if ($Platform) { $args += ("-Platform", $Platform) }
if ($Config) { $args += ("-Config", $Config) }
if ($Device) { $args += ("-Device", $Device) }
if ($ModuleFilter) { $args += ("-ModuleFilter", $ModuleFilter) }
if ($TestFilter) { $args += ("-TestFilter", $TestFilter) }
if ($WTLOutputFile) { $args += ("-WTLOutputFile", $WTLOutputFile) }
if ($NoCopy) { $args += ("-NoCopy") }
if ($RedirectTAEFErrors) { $args += ("-RedirectTAEFErrors") }
if ($WTTLogPath) { $args += ("-WTTLogPath", $WTTLogPath) }
if ($OutputDir) { $args += ("-OutputDir", $OutputDir) }

$cmd = "$PSScriptRoot\Run-Tests.ps1"
Invoke-Expression "$cmd $args"
exit $LASTEXITCODE
