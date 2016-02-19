<#
    .SYNOPSIS
    This script indexes symbols on the internal, external, and local symbol servers.
    
    .PARAMETER symbolsPath
    The path to the binaries (*.dll, *.exe, *,pdb) to index.  This will typically be the drop folder for each build.

    .PARAMETER branch
    The branch the binaries were build on.

    .PARAMETER configuration
    Debug/Release

    .PARAMETER version
    The build version for the binaries.

    .PARAMETER version
    The build version for the binaries.
    
    .PARAMETER SSindex
    The location to put the symbol server index.  The options are:
    symweb - For internal builds.
    internet - For publicly released builds.  
    islandwood - \\arcadiabuild03\release\symbols
    
    .EXAMPLE
    IndexSymbols.ps1 -symbolsPath "\\arcadiabuild03\release\develop\Debug\20160219.1\drop" -branch develop -configuration debug -version 20160219.1 -SSindex symweb,islandwood
    IndexSymbols.ps1 -symbolsPath "\\arcadiabuild03\release\master\Release\20160218.1\drop" -branch master -configuration release -version 20160218.1 -SSindex symweb,internet
#>
param(
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since powershell will block waiting for user input.
    [string]$symbolsPath = $(throw 'Mandatory parameter "symbolsPath" is not set.'),
    [string]$branch = $(throw 'Mandatory parameter "branch" is not set.'),
    [string]$configuration = $(throw 'Mandatory parameter "configuration" is not set.'),
    [string]$version = $(throw 'Mandatory parameter "version" is not set.'),
    [ValidateSet("symweb", "internet", "islandwood")]
    [string[]]$SSindex = $(throw 'Madatory parameter "SSindex" is not set.')
    )

#The symbols indexing scripts will create a request like Project_BuildId_BuildRemark.ssi.
#The project (islandwood) will be pulled from the dbg.txt.
$buildRemark = $branch + "_" + $configuration
$buildId = $version

$dbgtxt = [System.IO.Path]::Combine($PSScriptRoot, "dbg.txt")

$temp = New-TemporaryFile
write-host "Using temp file: " $temp.FullName

#get list of binaries.
$binaries = Get-ChildItem -File -recurse $symbolsPath
$binaries.FullName | Out-File -File $temp -encoding ASCII

if($SSindex -contains "symweb")
{
    write-host "Indexing on Symweb"
    \\symbols\tools\createrequest.cmd -i $dbgtxt -c -s -b $buildId -e $buildRemark -g $symbolsPath -r -d symwebrequests
}

if($SSindex -contains "internet")
{
    #createrequest checks to see if it already processed a Project_BuildId_BuildRemark.ssi request.  So, if we want to publish
    #to both symweb and archive, we need to create a unique request name.
    $buildRemark = $buildRemark + "_archive"
    write-host "Indexing on Internet"
    $dbgtxtTemp = New-TemporaryFile
    Get-Content $dbgtxt | Out-File $dbgtxtTemp -encoding ASCII
    Add-Content $dbgtxtTemp.FullName "Release=$buildRemark"
    Add-Content $dbgtxtTemp.FullName "Build=$buildId"
    Get-Content $dbgtxtTemp

    \\symbols\tools\createrequest.cmd -i $dbgtxtTemp -c -a -b $buildId -e $buildRemark -g $symbolsPath -r -d archiverequests
    Remove-Item $dbgtxtTemp
}

if($SSindex -contains "islandwood")
{
    write-host "Indexing on Islandwood Symbol Server"
    c:\Debuggers\symstore add -f @$temp /s "\\arcadiabuild03\Release\symbols" /t $buildRemark /v $buildId /o /p /l
}

Remove-Item $temp.FullName
exit(0)