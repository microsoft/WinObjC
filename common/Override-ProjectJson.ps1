<#  
    .SYNOPSIS  
    Modify the versions of a NuGet dependency in project.json files.
    This file MUST be kept up to date with the logic in winobjc.packagereference.override.targets
#>  
param(  
    #NOTE: using Parameter(Mandatory) will hang the VSO build job since  
    #      powershell will block waiting for user input.  
    [string] $ProjectJsonSearchPath = $(throw 'Mandatory parameter "ProjectJsonSearchPath" is not set.'),
    [string[]] $PackageOverrideSearchPaths =  @("$env:WINOBJC_SDK_ROOT\build\OutputPackages", "$env:WINOBJC_SDK_ROOT\tools\OutputPackages")
    )  
  
write-host $MyInvocation.Line

$ProjectJsons = gci $ProjectJsonSearchPath -include project.json -recurse
  
foreach($ProjectJsonFile in $ProjectJsons)
{  
    $FileAsJson = Get-Content $ProjectJsonFile -raw | ConvertFrom-Json

    $needsUpdate = $false

    # only bother to iterate over dependencies that start with WinObjC and are "*"
    $deps = $FileAsJson.dependencies | Get-Member -type NoteProperty | Where-Object { $_.Name.StartsWith("WinObjC") -and  $FileAsJson.dependencies."$($_.Name)" -eq "*"}
    foreach($dependency in $deps)
    { 
      $packageName = $dependency.Name

      # Try to find a matching package in one of the search paths. Sort descending by last write time.
      $searchRegex = [regex]($packageName + '\.\d+\.\d+\.\d+(-.*)?')
      $newest = ($PackageOverrideSearchPaths | gci -Recurse -File -Filter *.nupkg | Where-Object { $_.Name -match $searchRegex } | Sort-Object -descending -property LastWriteTime | Select-Object -first 1)

      if ($newest -ne $null) {
        # Got a local package. Use it. 
        # NOTE: This script only handles local packages; It does not look at git tags to try to get the latest daily builds.
        $newVersion = $newest.Name.Replace(("$packageName" + "."), "").Replace(".nupkg", "")

        if ($needsUpdate -ne $true) {
          Write-Host "Adjusting $ProjectJsonFile"
        }

        Write-Host "    Changing package $packageName to new version $newVersion"
        $FileAsJson.dependencies."$($packageName)" = $newVersion
        $needsUpdate = $true
      }
    }  

    if ($needsUpdate -eq $true) {
        $FileAsJson | ConvertTo-Json -Depth 100 | set-content $ProjectJsonFile
    }
}  
  
exit 0 
