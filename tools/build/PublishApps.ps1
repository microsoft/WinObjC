<#
    .SYNOPSIS
    This script collects all the built apps and publishes them by architecture.
    It's main purpose is to be used in the VSO build to publish the built apps in a manner
    that makes it easy to install and test.
    
    .PARAMETER path
    The path to search for appx's

    .PARAMETER outputDir
    The output directory to publish all appx's

    .EXAMPLE
    PublishApps.ps1 -path x:\winobjc -outputDir "x:\dropoutput"
#>
param(
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since powershell will block waiting for user input.
    [string]$path = $(throw 'Mandatory parameter "path" is not set.'),
    [string]$outputDir = $(throw 'Madatory parameter "outputDir" is not set.')
    )

$apppackages = Get-ChildItem -recurse -Path $path "apppackages"

foreach($apppackage in $apppackages)
{
    #We can't just search recursively for *.appx because many the apppackages directory will contain all
    #the dependent packages. E.g. Microsoft.VCLibs.x86.Debug.14.00.appx
    #So, we find the appx by traversing down the hierarchy msbuild creates when it builds the appx.
    #E.g: x:\WinObjC\samples\HelloUI\AppPackages\HelloUI\HelloUI_1.0.0.0_Win32_Debug_Test\HelloUI_1.0.0.0_Win32_Debug.appx   
    $appxDirs = Get-ChildItem $apppackage.FullName | Get-ChildItem
    foreach($appxDir in $appxDirs)
    {
        $dest = "";
        if($appxDir -match "_arm_")
        {
            $dest = [System.IO.Path]::Combine($outputDir, "arm", $appxDir.Name)
        }
        elseif($appxDir -match "_win32_")
        {
            $dest = [System.IO.Path]::Combine($outputDir, "x86", $appxDir.Name)
        }
        else
        {
            throw "Could not determine architecture for $appxFile"
        }
        
        write-host "Copying: " $appxDir.FullName $dest
        Copy-Item -path $appxDir.FullName -destination $dest -recurse
    }
}

exit(0)
