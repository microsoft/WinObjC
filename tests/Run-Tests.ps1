<#
.SYNOPSIS
    Runs Tests using TAEF for Islandwood project.

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

.PARAMETER WTLOutputFile
    Name of the file to write TAEF output. If not set, no result file will be saved.

.PARAMETER NoCopy
    Switch to disable copying test to the device

.PARAMETER Parameters
    Parameters to pass to the library or libraries under test.

.PARAMETER RedirectTAEFErrors
    Redirect TAEF errors/failures to stderr.  This is used to integrate with VSTS powershell task.

.PARAMETER WTTLogPath
    Path to find WTTLog dll

.PARAMETER OutputDir
    Path to write test outptu files to.
    
.EXAMPLE
    Desktop: Run-Tests.ps1 -ModuleFilter *unittests.dll
             Run-Tests.ps1 -ModuleFilter functionaltests.dll
    Phone:  Run-Tests.ps1 -ModuleFilter *unittests.dll -platform ARM
            Run-Tests.ps1 -ModuleFilter functionaltests.dll -platform ARM

#>
param(

    [string]$TestDirectory,

    [string][ValidateSet("Win32", "ARM")]
    $Platform = "Win32",

    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [string]$Device = "127.0.0.1",

    [string]$ModuleFilter,
    
    [string]$TestFilter,

    [string]$WTLOutputFile,

    [switch]$NoCopy,

    [switch]$RedirectTAEFErrors,

    [string]$WTTLogPath,

    [System.Collections.HashTable]$Parameters = $null,

    [string]$OutputDir
)

$script:exitCode = 0

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
    if (!$NoCopy)
    {
        if ($TargetingDevice)
        {
            # Copy the tests to the device
            Write-Host -ForegroundColor Cyan "Copying tests to the device - this may take about a minute"


            $toCopy = Get-ChildItem $TestSrcDirectory -exclude *.exp,*.ilk,*.lib,*.pdb
            foreach($f in $toCopy)
            {
                $dst = Join-Path $TestDstDirectory $f.name
                if($f -is [System.IO.DirectoryInfo])
                {                    
                    Write-Host -ForegroundColor Cyan  "Copying $f\* $dst\"
                    putd -recurse $f\* $dst\
                }
                else
                {
                    Write-Host -ForegroundColor Cyan "Copying $f $dst"
                    putd $f $dst
                }
            }

            #Copy wttlog if output is requested.
            if ($WTLOutputFile)
            {
                $WTTLogFullPath = Join-Path $WTTLogPath wttlog.dll 
                putd $WTTLogFullPath $TestDstDirectory
            }
            
        }
        else
        {
            # For Desktop, we can run tests in place
            
            #Copy wttlog if output is requested.
            if ($WTLOutputFile)
            {
                $WTTLogFullPath = Join-Path $WTTLogPath wttlog.dll 
                Copy-Item $WTTLogFullPath -Destination $TestDstDirectory -Force           
            }

        }
    }
}

function ExecTest($argList)
{
    Write-Host -ForegroundColor Cyan "Starting test execution..."

    $taefPath = Join-Path $TestDstDirectory te.exe 
    $testPath = Join-Path $TestDstDirectory $ModuleFilter

    $taefPath = "`"$taefPath`""

    if ($TargetingDevice)
    {
        if ($WTLOutputFile)
        {
            $outputLocalName = $WTLOutputFile
            $outputRemoteName = Join-Path -Path $TestDstDirectory -ChildPath ([system.IO.Fileinfo]$WTLOutputFile).Name
            $argList += " /logFile:$outputRemoteName /enableWttLogging /enableetwlogging=false"
        }

        if ($OutputDir)
        {
            $localOutputDir = $OutputDir
            $remoteOutputDir = Join-Path -Path $TestDstDirectory -ChildPath "TAEFOutput"
            $argList += " /outputFolder=$remoteOutputDir"
        }

        #Note: cmdd or some other tool on the phone does not like "`"$testPath`"" and results in taef not running the test.
        Write-Host -ForegroundColor Cyan  "cmdd $taefPath $testPath $argList"
        cmdd $taefPath $testPath $argList

        if ($WTLOutputFile)
        {
            # Fetch the output from the device
            getd $outputRemoteName $outputLocalName
            deld $outputRemoteName
        }
        
        if ($OutputDir)
        {
            if(Test-Path $localOutputDir)
            {
                Remove-Item -Recurse -Force $localOutputDir -verbose
            }
            New-Item -ItemType directory -Path $localOutputDir

            getd $remoteOutputDir $localOutputDir -recurse
            deld /s $remoteOutputDir
        }
    }
    else
    {
    
        if ($WTLOutputFile)
        {
            $argList += " /logFile:$WTLOutputFile /enableWttLogging /enableetwlogging=false"
        }
        
        if ($OutputDir)
        {
            $argList += " /outputFolder=$OutputDir"
        }
    
        $testPath = "`"$testPath`""
        Write-Host -ForegroundColor Cyan  "Running $taefPath $testPath $argList"
        $arguments = "$testPath" + "$argList"
        if ($RedirectTAEFErrors) {            
            $output = Invoke-Expression "& $taefPath $arguments"
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
            Invoke-Expression "& $taefPath $arguments"
            $script:exitCode = $LASTEXITCODE
        }
    }
}

#Set the location of the test binaries
if ($TestDirectory -eq "")
{
    $MyPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName;
    $TestSrcDirectory = Join-Path $MyPath "..\build\$Platform\$Config\Universal Windows\"
}
else
{
    $TestSrcDirectory = $TestDirectory
}

if ($TargetingDevice)
{
    $TestDstDirectory = "c:\data\test\bin\islandwood\Tests"
}
else
{
    #On Desktop we run in place
    $TestDstDirectory = $TestSrcDirectory
}

if ($TargetingDevice)
{
    EnsureDeviceConnection
}

$DefaultTestBinary = "FunctionalTests.dll"

DeployTests

$argList = "";

if($TestFilter)
{
    $argList += " /name:$TestFilter"
}

If($Parameters)
{
    ForEach ($p in $Parameters.GetEnumerator()) {
        $argList += " /p:$($p.Name)=$($p.Value)"
    }
}

ExecTest($argList)

exit $script:exitCode
