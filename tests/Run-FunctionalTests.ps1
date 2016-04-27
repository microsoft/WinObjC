<#
.SYNOPSIS
    Runs Functional Tests for Islandwood project.
#>
param(
    [Parameter(HelpMessage="Directory of TAEF binaries")]
    [string]$TAEFDirectory = "",
    
    [Parameter(ParameterSetName="TestLocation", HelpMessage="Directory of Tests to run")]
    [string]$TestDirectory = "",

    [Parameter(HelpMessage="Architecture of tests to run")]
    [string][ValidateSet("Win32", "ARM")]
    $Platform = "Win32",

    [Parameter(ParameterSetName="TestLocation", HelpMessage="Directory of Tests to run")]
    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [Parameter(HelpMessage="IP or MAC address of remote device to run tests on")]
    [string]$Device = "127.0.0.1",

    [Parameter(HelpMessage="Regex of Tests to run")]
    [string]$TestFilter = $null,

    [Parameter(HelpMessage="Location to place output wtl files. If not set, no result files will be saved.")]
    [string]$WTLOutputDirectory = $null,
    
    [Parameter(HelpMessage="TAEF package install path.")]
    [string]$PackageRootPath = $null
)

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
            
            Write-Host -ForegroundColor Cyan "Installing $TAEFPackageName package - this may take a while... (about 5 minutes)"
            if ($TAEFDirectory -eq [string]$null)
            {
                deployd -Packages $TAEFPackageName -OnDevice
            }
            else
            {
                deployd -Packages $TAEFPackageName -PackageRootPath $PackageRootPath
            }
        }

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
        $taefPath = "te.exe"
    }
    else
    {
        $taefPath = Join-Path $TAEFDirectory te.exe
    }
    
    $testPath = Join-Path $TestDstDirectory $DefaultTestBinary

    if ($TargetingDevice)
    {
        Write-Host $argList
        cmdd $taefPath $testPath $argList

        # Fetch the output from the device
        getd $outputRemoteName $outputLocalName
        deld $outputRemoteName
    }
    else
    {
        $arguments = "$testPath" + "$argList"
        Invoke-Expression "$taefPath $arguments"
    }
}

if ($TestDirectory -eq "") 
{
    $MyPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName;
    $TestSrcDirectory = Join-Path $MyPath "..\build\Tests\FunctionalTests\$Platform\$Config\FunctionalTests"
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

$outputFileName = [System.IO.Path]::GetRandomFileName() + ".wtl"

# Decide where the WTL output files will live
if ($WTLOutputDirectory -eq [string]$null)
{
    $outputLocalName = $outputFileName
}
else
{
    $outputLocalName = Join-Path -Path $WTLOutputDirectory -ChildPath $outputFileName
}

if ($TargetingDevice)
{
    $outputRemoteName = Join-Path -Path $TestDstDirectory -ChildPath $outputFileName
}
else
{
    $outputRemoteName = $outputLocalName
}

$argList = " /logFile:$outputRemoteName"

if($TestFilter -ne [string]$null)
{
    $argList += " /name:$TestFilter"
}

ExecTest($argList)

exit
