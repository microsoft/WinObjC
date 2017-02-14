<#
.SYNOPSIS
    Runs Functional Tests for Islandwood project.

.PARAMETER TAEFDirectory
    The path to TAEF binaries

.PARAMETER TestDirectory
    The path to test binaries

.PARAMETER Platform
    platform to run tests on. Valid values are Win32 or ARM

.PARAMETER Config
    Test configuration to use for the test. Valid values are Debug or Release

.PARAMETER Device
    IP or MAC address of the device to run tests on

.PARAMETER TestFilter
    Test filter to use for the test. Supports wildcard characters

.PARAMETER WTLOutputDirectory
    Path to test output. If not set, no result file will be saved.

.PARAMETER NoCopy
    Switch to disable copying test to the device

.PARAMETER TestWorkingDirectory
    Path to the working test directory from where the tests will be run

.PARAMETER PackageRootPath
    Path to build share where the TAEF package can be found

.PARAMETER RedirectTAEFErrors
    Redirect TAEF errors/failures to stderr.  This is used to integrate with VSTS powershell task.

.PARAMETER WTTLogPath
    Path to find WTTLog dll

.EXAMPLE
    Run-FunctionalTests.ps1 -TAEFDirectory D:\TAEF
    Run-FunctionalTests.ps1 -TAEFDirectory \data\test\bin -Platform ARM

#>
param(
    [string]$TAEFDirectory = "",

    [string]$TestDirectory = "",

    [string][ValidateSet("Win32", "ARM")]
    $Platform = "Win32",

    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [string]$Device = "127.0.0.1",

    [string]$TestFilter = $null,

    [string]$WTLOutputDirectory = $null,

    [switch]$NoCopy,

    [string]$TestWorkingDirectory = "",

    [string]$PackageRootPath = $null,

    [switch]$RedirectTAEFErrors,

    [string]$WTTLogPath = $null
)

$script:exitCode = 0

if ($NoCopy)
{
    if ($TestWorkingDirectory -eq "")
    {
         throw "Please specify -TestWorkingDirectory argument with -NoCopy option."
    }
}

if ($TestWorkingDirectory -ne "")
{
    if (!$NoCopy)
    {
         throw "Please specify -NoCopy option when using -TestWorkingDirectory argument."
    }
}

$TargetingDevice = ($Platform -eq "ARM")

function EnsureDeviceConnection
{
    if ($DeviceAddress -eq $null)
    {
        if ((Get-Command Open-Device -ErrorAction SilentlyContinue) -eq $null)
        {
            Write-Host "Can't connect to device. Try installing TShell."
            throw "DeviceConnectError"
        }

        # If the caller has already connected to the device, use the existing connection.
        # Otherwise, try connecting to device now.
        Open-Device $Device
    }
}

function DeployTests
{
    if ($TargetingDevice)
    {
        # Make sure TAEF package is installed on the device
        Try
        {
            # Checking for installed packages is not trivial. For now keep it simple.
            dird \data\test\bin\TE.TestMode.UAP.dll | Out-Null
        }
        Catch
        {
            $TAEFPackageName = "Microsoft.Windows.Test.Taef"

            Write-Host -ForegroundColor Cyan "Installing $TAEFPackageName package - this may take about a minute"
            if ($PackageRootPath -eq [string]$null)
            {
                deployd -Packages $TAEFPackageName -OnDevice
            }
            else
            {
                deployd -Packages $TAEFPackageName -PackageRootPath $PackageRootPath
            }
        }

        if (!$NoCopy)
        {

            # Copy the tests to the device
            Write-Host -ForegroundColor Cyan "Copying tests to the device - this may take about a minute"

            Try
            {
                mdd $TestDstDirectory
            }
            Catch
            {
                # putd fails if the directory doesn't already exist.
                # mdd fails if the directory does already exist.
                # This is awkward.
            }

            putd -recurse $TestSrcDirectory\* $TestDstDirectory
        }
    }
    else
    {
        # Otherwise run tests in place
    }
}

function ExecTest($argList)
{
    Write-Host -ForegroundColor Cyan "Starting test execution..."

    if ($TAEFDirectory -eq "")
    {
        $taefPath = Join-Path $TestSrcDirectory te.exe
    }
    else
    {
        $taefPath = Join-Path $TAEFDirectory te.exe
    }

    $testPath = Join-Path $TestDstDirectory $DefaultTestBinary

    if ($TargetingDevice)
    {
        cmdd $taefPath $testPath $argList

        if ($WTLOutputDirectory -ne [string]$null)
        {
            # Fetch the output from the device
            getd $outputRemoteName $outputLocalName
            deld $outputRemoteName
        }
    }
    else
    {
        $arguments = "$testPath" + "$argList"
        if ($RedirectTAEFErrors) {
            $output = Invoke-Expression "$taefPath $arguments"
            $script:exitCode = $LASTEXITCODE
            foreach ($o in $output) {
                            
                if ($o.StartsWith("Error:") -or $o.Contains("[Failed]")) {

                    #TAEF does not report exceptions/crashes/failures during test cleanup as test failures.
                    #However, it will log a message like: "Error: TAEF: [HRESULT 0x8000FFFF] ...."
                    #We want to detect and mark these as test failures.
                    $script:exitCode = 1

                    #Note: Adding ##[error]: is just to make the errors show up as red in VSTS output
                    #Unfortunately, writing the output to stderr (write-error) creates a lot of noise in powershell.
                    #And attempting to use Console.WriteError or $host.ui.WriteErrorLine results in lines be displayed out of order.
                    write-host "##[error]: $o" -foregroundcolor red

                } else {
                    write-host $o
                }
            }
        } else {
            Invoke-Expression "$taefPath $arguments"
            $script:exitCode = $LASTEXITCODE
        }
    }
}

if (!$NoCopy)
{
    if ($TestDirectory -eq "")
    {
        $MyPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName;
        $TestSrcDirectory = Join-Path $MyPath "..\build\$Platform\$Config\Tests"
    }
    else
    {
        $TestSrcDirectory = $TestDirectory
    }

    if ($TargetingDevice)
    {
        $TestDstDirectory = "\data\test\bin\islandwood\FunctionalTests"
    }
    else
    {
        $TestDstDirectory = $TestSrcDirectory
    }
}
else
{
    $TestDstDirectory = $TestWorkingDirectory
}

if ($TargetingDevice)
{
    EnsureDeviceConnection
}

$DefaultTestBinary = "FunctionalTests.dll"

DeployTests

if (($WTLOutputDirectory -ne [string]$null) -and ((Test-Path -Path $WTLOutputDirectory -PathType Container) -eq 0))
{
    New-Item -ItemType Directory -Path $WTLOutputDirectory
}

$outputLocalName = $null;
$outputRemoteName = $null;
$argList = "";

$outputFileName = "FunctionalTestsResult.wtl"

# Decide where the WTL output files will live
if ($WTLOutputDirectory -ne [string]$null)
{
    $WTTLogFullPath = Join-Path $WTTLogPath wttlog.dll 
    Copy-Item $WTTLogFullPath -Destination $TestSrcDirectory -Force

    if ($TargetingDevice)
    {
        $outputLocalName = Join-Path -Path $WTLOutputDirectory -ChildPath $outputFileName
        $outputRemoteName = Join-Path -Path $TestDstDirectory -ChildPath $outputFileName
        $argList += " /logFile:$outputRemoteName /enableWttLogging"
    }
    else
    {
        $outputLocalName = Join-Path -Path $WTLOutputDirectory -ChildPath $outputFileName
        $argList += " /logFile:$outputLocalName /enableWttLogging"
    }
}


if($TestFilter -ne [string]$null)
{
    $argList += " /name:$TestFilter"
}

ExecTest($argList)

exit $script:exitCode
