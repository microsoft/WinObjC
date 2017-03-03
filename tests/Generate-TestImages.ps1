<#
.SYNOPSIS
    Generates CoreGraphics Drawing Test Images for the Islandwood Project

.PARAMETER TestDirectory
    The path to test binaries

.PARAMETER Config
    Test configuration to use for the test. Valid values are Debug or Release

.PARAMETER TestFilter
    Test filter to use for the test. Supports wildcard characters

.PARAMETER Output
    Directory into which to place the generated images.

.EXAMPLE
    Generate-TestImages.ps1

#>
param(
    [string]$TestDirectory,

    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [string]$TestFilter,

    [string]$Output = ".\images"
)

mkdir $Output -EA SilentlyContinue | Out-Null

# Since TE runs the tests in a UAP host process, it can't normally write files
# outside its container. Adding ALL APPLICATION PACKAGES to the ACLs on the output
# directory gives it that right.
& icacls $Output /grant "ALL APPLICATION PACKAGES:(OI)(CI)(F)" /t /q | Out-Null

& "$PSScriptRoot\Run-Tests.ps1" -TestDirectory:$TestDirectory -Config:$Config -TestFilter:$TestFilter -ModuleFilter:"CoreGraphics.Drawing.UnitTests.dll" -Parameters:@{
    "Generate" = "True"
    "Out" = "$(Resolve-Path $Output)"
}

exit $LASTEXITCODE
