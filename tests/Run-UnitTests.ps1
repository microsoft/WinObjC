<#
.SYNOPSIS
    Runs Tests for Islandwood project.
#>
param(
    [Parameter(ParameterSetName="TestLocation", HelpMessage="Directory of Tests to run")]
    [string]$TestDirectory = "",

    [Parameter(ParameterSetName="TestLocation", HelpMessage="Directory of Tests to run")]
    [string][ValidateSet("Debug", "Release")]
    $Config = "Debug",

    [Parameter(HelpMessage="Regex of Test Modules to look for")]
    [string]$ModuleFilter = $null,

    [Parameter(HelpMessage="Regex of Tests to run")]
    [string]$TestFilter = $null,

    [Parameter(HelpMessage="Location to place output xml files. If not set, no result files will be saved.")]
    [string]$XMLOutputDirectory = $null
)

if ($TestDirectory -eq "") 
{
    $MyPath = (get-item $MyInvocation.MyCommand.Path).Directory.FullName;
    $TestDirectory = Join-Path $MyPath "..\build\$Config"
}

$DefaultModuleFilter = ".*((u|U)nit)(t|T)ests.*\.(exe)"

$Tests = $null

if ($ModuleFilter -ne [string]$null) {
    $Tests = Get-ChildItem $TestDirectory -Recurse | Where-Object {($_.Name -Match $DefaultModuleFilter) -and ($_.Name -Like ($ModuleFilter + "*exe") -or $_.Name -Like ($ModuleFilter))}
} else {
    $Tests = Get-ChildItem $TestDirectory -Recurse | Where-Object {$_.Name -Match $DefaultModuleFilter}
}

if (($XMLOutputDirectory -ne [string]$null) -and ((Test-Path -Path $XMLOutputDirectory -PathType Container) -eq 0)) {
    New-Item -ItemType Directory -Path $XMLOutputDirectory
}

$xmlOutputArray = @()
foreach ($test in $Tests) {
    $outputName = $null;
    if ($XMLOutputDirectory -eq [string]$null) {
        $outputName = [System.IO.Path]::GetRandomFileName()
    } else {
        $outputName = Join-Path -Path $XMLOutputDirectory -ChildPath ($test.Name + ".xml")
    }

    if($TestFilter -ne [string]$null) {
        & $test.FullName --gtest_output="xml:$outputName" --gtest_filter="$TestFilter"
    } else {
        & $test.FullName --gtest_output="xml:$outputName"
    }
    

    [xml]$xml = Get-Content $outputName
    $xmlOutputArray += [tuple]::Create($test.FullName, $xml)

    if ($XMLOutputDirectory -eq [string]$null) {
        Remove-Item $outputName -Force
    }
    
}

$testCount = 0;
$failureCount = 0;
$disabledCount = 0;

$failureMessageArray = @()

foreach ($xmlTuple in $xmlOutputArray) {
    foreach($testsuite in $xmlTuple.Item2.testsuites.testsuite){

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

exit $failureCount