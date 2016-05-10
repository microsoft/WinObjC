<#
.SYNOPSIS
    Runs Tests for Islandwood project.
#>
param(
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

    [Parameter(HelpMessage="Regex of Test Modules to look for")]
    [string]$ModuleFilter = $null,

    [Parameter(HelpMessage="Regex of Tests to run")]
    [string]$TestFilter = $null,

    [Parameter(HelpMessage="Location to place output xml files. If not set, no result files will be saved.")]
    [string]$XMLOutputDirectory = $null,

    [Parameter(HelpMessage="Output Verbosity")]
    [string][ValidateSet("Minimal", "Verbose")]
    $Verbosity = "Verbose",
    
    [Parameter(HelpMessage="Wont Deploy in ARM. Assumes already deployed bits exist")]
    [switch] $DontDeploy
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

function DeployTests($testList)
{
    if ($TargetingDevice)
    {
        # Copy the tests to the device

        Write-Host "Copying tests to the device - this may take a while... (about 2 minutes)"

        Try {
            mdd $TestDstDirectory
        } Catch {
            # putd fails if the directory doesn't already exist.
            # mdd fails if the directory does already exist.
            # This is awkward.
        }

        foreach($test in $testList) {
          $testPath = Join-Path $TestSrcDirectory $test
          $testDirectory = [System.IO.Path]::GetDirectoryName($testPath);
          
          $testOutputPath = Join-Path $TestDstDirectory $test
          $testOutputDirectory = [System.IO.Path]::GetDirectoryName($testOutputPath);
          
          Try {
            mdd $testOutputDirectory
          } Catch {
              # putd fails if the directory doesn't already exist.
              # mdd fails if the directory does already exist.
              # This is awkward.
          }

          putd -recurse $testDirectory\*.gif $testOutputDirectory
          putd -recurse $testDirectory\*.tif $testOutputDirectory
          putd -recurse $testDirectory\*.tiff $testOutputDirectory
          putd -recurse $testDirectory\*.bmp $testOutputDirectory
          putd -recurse $testDirectory\*.ico $testOutputDirectory
          putd -recurse $testDirectory\*.png $testOutputDirectory
          putd -recurse $testDirectory\*.jpg $testOutputDirectory
          putd -recurse $testDirectory\*.dll $testOutputDirectory
          putd -recurse $testDirectory\*.exe $testOutputDirectory
          putd -recurse $testDirectory\*.txt $testOutputDirectory
          putd -recurse $testDirectory\*.bitmap $testOutputDirectory
          putd -recurse $testDirectory\*.mapping $testOutputDirectory
          putd -recurse $testDirectory\*.data $testOutputDirectory
          putd -recurse $testDirectory\*.plist $testOutputDirectory
        }
    }
    else
    {
        # Otherwise run tests in place
    }
}

function ExecTest($test, $argList, $outputRemoteName, $outputLocalName)
{
    $testPath = Join-Path $TestDstDirectory $test

    if ($TargetingDevice)
    {
        execd $testPath $argList

        # Fetch the output from the device
        getd $outputRemoteName $outputLocalName
        deld $outputRemoteName
    }
    else
    {
        if ($Verbosity -eq "Minimal")
        {
            & $testPath $argList >$null
        }
        else
        {
            & $testPath $argList
        }
    }
}

if ($TestDirectory -eq "") 
{
    $MyPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName;
    $TestSrcDirectory = Join-Path $MyPath "..\build\$Platform\$Config"
}
else
{
    $TestSrcDirectory = $TestDirectory
}

if ($TargetingDevice)
{
    $TestDstDirectory = "C:\data\test\bin\islandwood"
}
else
{
    $TestDstDirectory = $TestSrcDirectory
}

if ($TargetingDevice)
{
    EnsureDeviceConnection
}

$DefaultModuleFilter = ".*((u|U)nit)(t|T)ests.*\.(exe)"

$Tests = $null

Push-Location $TestSrcDirectory

if ($ModuleFilter -ne [string]$null) {
    $Tests = Get-ChildItem -Recurse | Where-Object {($_.Name -Match $DefaultModuleFilter) -and ($_.Name -Like ($ModuleFilter + "*exe") -or $_.Name -Like ($ModuleFilter))} | Resolve-Path -Relative
} else {
    $Tests = Get-ChildItem -Recurse | Where-Object {$_.Name -Match $DefaultModuleFilter} | Resolve-Path -Relative
}

Pop-Location

if(-not $DontDeploy) {
  DeployTests $Tests
}

if (($XMLOutputDirectory -ne [string]$null) -and ((Test-Path -Path $XMLOutputDirectory -PathType Container) -eq 0)) {
    New-Item -ItemType Directory -Path $XMLOutputDirectory
}

$xmlOutputArray = @()
$crashingTestArray = @()
foreach ($test in $Tests) {
    $testInfo = Get-Item (Join-Path $TestSrcDirectory $test)

    $outputLocalName = $null;
    $outputRemoteName = $null;

    # Decide where the XML output files will live

    if ($XMLOutputDirectory -eq [string]$null) {
        $outputLocalName = [System.IO.Path]::GetRandomFileName()
    } else {
        $outputLocalName = Join-Path -Path $XMLOutputDirectory -ChildPath ($testInfo.Name + ".xml")
    }

    if ($TargetingDevice) {
        $outputRemoteName = Join-Path -Path $TestDstDirectory -ChildPath ([System.IO.Path]::GetRandomFileName())
    } else {
        $outputRemoteName = $outputLocalName
    }

    Try {
        $argList = @("--gtest_output=xml:$outputRemoteName")

        if($TestFilter -ne [string]$null) {
            $argList += "--gtest_filter=$TestFilter"
        }

        if($Verbosity -eq "Minimal") {
            $argList += "--quiet --no-verbose"
        }

        ExecTest $test $argList $outputRemoteName $outputLocalName

        [xml]$xml = Get-Content $outputLocalName
        $xmlOutputArray += [tuple]::Create($testInfo.FullName, $xml)

        if ($XMLOutputDirectory -eq [string]$null) {
            Remove-Item $outputLocalName -Force
        }
    } Catch {

        $crashingTestArray += ($testInfo.FullName)
    }
    
}

$testCount = 0;
$failureCount = 0;
$disabledCount = 0;

$failureMessageArray = @()
$disabledMessageArray = @()

foreach ($xmlTuple in $xmlOutputArray) {
    foreach($testsuite in $xmlTuple.Item2.testsuites.testsuite) {

        $testCount += $testsuite.tests
        $failureCount += $testsuite.failures
        $disabledCount += $testsuite.disabled

        if ($testsuite.failures -ne 0) {
            foreach ($testcase in $testsuite.testcase) {
                $testFailureArray = @()
                foreach ($failure in $testcase.failure) {
                    $testFailureArray += $failure.message
                }

                if ($testFailureArray.length -ne 0) {
                    $failureMessageArray += [tuple]::Create([tuple]::Create($xmlTuple.Item1, $testsuite.name, $testcase.Name), $testFailureArray)
                }
            }
        }
        
        if ($testsuite.disabled -ne 0) {
            foreach ($testcase in $testsuite.testcase) {
                if ($testcase.status -ne "run") {
                    $disabledMessageArray += [tuple]::Create([tuple]::Create($xmlTuple.Item1, $testsuite.name, $testcase.Name), 0)
                }
            }
        }

    }
}


Write-Host "-----------------------------------------------------"
Write-Host "SUMMARY Passed: " -NoNewLine
Write-Host ($testCount - $failureCount - $disabledCount) -foregroundcolor "Green" -NoNewLine
Write-Host  " Failed: " -NoNewLine 
Write-Host ($failureCount) -foregroundcolor "Red" -NoNewLine
Write-Host  " Disabled: " -NoNewLine 
Write-Host ($disabledCount) -foregroundcolor "Yellow" -NoNewLine
Write-Host  " Total: " -NoNewLine 
Write-Host  $testCount
Write-Host  ""

if ($disabledMessageArray.length -ne 0) {
    Write-Host  "DISABLED TESTS:" -foregroundcolor "Yellow"

    foreach ($disabledMessage in $disabledMessageArray) {
        Write-Host  "  " $disabledMessage.Item1.Item2 -foregroundcolor "Yellow" -NoNewLine 
        Write-Host  "." -foregroundcolor "Yellow" -NoNewLine
        Write-Host  $disabledMessage.Item1.Item3 -foregroundcolor "Yellow"
    }
    
    Write-Host  ""
}

if ($crashingTestArray.length -ne 0) {
    Write-Host  "PROBLEMS RUNNING MODULES:" -foregroundcolor "Red"

    foreach ($crash in $crashingTestArray) {
        Write-Host  "  " $crash -foregroundcolor "Red"
    }

    Write-Host  ""
}

if ($failureMessageArray.length -ne 0) {
    Write-Host  "FAILING TESTS:" -foregroundcolor "Red"

    foreach ($errorMessage in $failureMessageArray) {
        Write-Host  "  " $errorMessage.Item1.Item2 -foregroundcolor "Red" -NoNewLine 
        Write-Host  "." -foregroundcolor "Red" -NoNewLine
        Write-Host  $errorMessage.Item1.Item3 -foregroundcolor "Red" -NoNewLine
        $reproLine = "  ( " + $errorMessage.Item1.Item1 + " --gtest_filter=" + $errorMessage.Item1.Item2 + "." + $errorMessage.Item1.Item3 + " )"
        Write-Host  $reproLine -foregroundcolor "Red"
    }
}

exit $failureCount + $crashingTestArray.length
