<#
    .SYNOPSIS
    This script calls the Windows App Certification Kit (WACK) on all the appx created by the samples projects
#>
param(
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since powershell will block waiting for user input.
    [string]$appxPath = $(throw 'Mandatory parameter "appxPath" is not set.')
    )

write-host $MyInvocation.Line

$appxs = gci -rec $appxPath *.appx -exclude Microsoft*
foreach ($appx in $appxs)
{
    write-host "Running WACK on $appx"
    $appxReport = $appx.FullName -Replace ".appx", ".xml"
    start-process "c:\Program Files (x86)\Windows Kits\10\App Certification Kit\appcert.exe" -Arg "reset" -wait
    #Note: Skip test 61 - Branding as we are using the default icons in the sample apps.
    start-process "c:\Program Files (x86)\Windows Kits\10\App Certification Kit\appcert.exe" -Arg "test -appxpackagepath $appx -reportoutputpath $appxReport -testid [21,31,33,38,45,46,47,49,50,51,52,53,54,55,56,57,58,60,62,63,66,68,70,71,72,74,75,77,79,80,81,83]" -wait

    #parse XML and get overall result.
    [xml]$resultXML = Get-Content $appxReport

    $result = $resultXML.Report.OVERALL_RESULT
    write-host "Test Result: $result"

    if ($result -ieq "FAIL" )
    {
        write-error "Failed WACK test."
    }
}

exit 0