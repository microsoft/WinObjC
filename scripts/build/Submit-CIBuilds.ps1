<#
.SYNOPSIS
    Submits a CI build to Visual Studio Online given a set of repository-specific criteria.
#>
[CmdletBinding(SupportsShouldProcess=$true)]
Param (
    [string]$RemoteURL,
    [string]$Remote,
    [string]$Ref,
    [string]$Config,
    [switch]$Reconfigure,
    [switch]$SkipRemoteCheck,
    [string]$BuildFilter,
    [string]$SourceBranch='develop',

    [string]$AuthUsername,
    [string]$AuthToken
)

Function Coalesce {
    ForEach($a in $Args) {
        If($null -ne $a) {
            return $a;
        }
    }
}

Function Get-GitVersion {
    $version = (&git.exe --version 2>$null)
    If ($LASTEXITCODE -NE 0) {
        Throw "Don't you have git? git --version failed."
    }

    $vstr = $version.Split(" ")[2] -Replace "^(\d+\.\d+\.\d+)\.?.*$", "`$1"
    Return [System.Version]$vstr
}

Function Get-GitRemoteUrl {
    <#
    .SYNOPSIS
    Retrieves the fully-qualified (and, in the case of GitHub, SSH-stripped) URL for a git remote.
    #>
    Param (
        [Parameter(Mandatory=$true,Position=1)]
        [string]$Remote
    )
    $origin = $null
    If (Get-GitVersion -Ge [System.Version]"2.7.0.0") {
        $origin = (& git.exe remote get-url $Remote 2>$null)
    } Else {
        $origin = (& git.exe config --get "remote.$Remote.url" 2>$null)
    }
    If ($LASTEXITCODE -NE 0) {
        Throw "$Remote is not a valid remote."
    }
    return ($origin -replace "^git@github.com:(.*)`$", "https://github.com/`$1")
}

Function Get-LatestRemoteRevision {
    <#
    .SYNOPSIS
    Retrieves the latest revision for a given git remote and ref.
    #>
    Param (
        [Parameter(Mandatory=$true,Position=1)]
        [string]$Remote,

        [Parameter(Mandatory=$true,Position=2)]
        [string]$BranchName
    )
    $ret = (& git.exe ls-remote $Remote $BranchName 2>$null)
    If ($LASTEXITCODE -NE 0) {
        Throw "Failed to find latest SHA1 for $PullRequest."
    }
    return $ret.Split("`t")[0]
}

Function Get-LatestLocalRevision {
    <#
    .SYNOPSIS
    Retrieves the latest revision for a given local ref.
    #>
    $ret = (& git.exe rev-parse HEAD 2>$null)
    If ($LASTEXITCODE -NE 0) {
        Throw "Failed to determine local SHA1."
    }
    return $ret
}

Function Get-GitBranchRemoteName {
    <#
    .SYNOPSIS
    Retrieves the remote name that a branch is tracking, if any.
    #>
    Param (
        [string]$Branch
    )
    $ret = (& git.exe config --get "branch.$Branch.remote" 2>$null)
    If ($LASTEXITCODE -NE 0) {
        return $null
    }
    return $ret
}

Function Get-GitBranchTrackingName {
    <#
    .SYNOPSIS
    Retrieves the remote branch that a local branch is tracking, if any.
    #>
    Param (
        [string]$Branch
    )
    $ret = (& git.exe config --get "branch.$Branch.merge" 2>$null)
    If ($LASTEXITCODE -NE 0) {
        return $null
    }
    return $ret -Replace "^refs/heads/", ""
}

Function Get-GitBranch {
    <#
    .SYNOPSIS
    Retrieves the current Git branch.
    #>
    $ret = (& git.exe symbolic-ref HEAD 2>$null)
    If ($LASTEXITCODE -NE 0) {
        Throw "Failed to determine current branch."
    }
    return $ret -Replace "^refs/heads/", ""
}

Function Get-GitRepositoryRoot {
    <#
    .SYNOPSIS
    Retrieves the root directory for the current Git repository.
    #>
    $ret = (& git.exe rev-parse --show-toplevel 2>$null)
    If ($LASTEXITCODE -NE 0) {
        throw "It does not appear that this is a Git working directory."
    }
    return $ret -Replace "/", "\"
}

Function Generate-UserConfig {
    Write-Host "Regenerating user configuration."
    Write-Host -NoNewLine -ForegroundColor Cyan  "If you are creating a new access token, please make sure that`n" `
                                                 "it has access to the " -Separator ""
    Write-Host -NoNewLine -ForegroundColor Green $REPOCONFIG.VSO.Instance
    Write-Host -NoNewLine -ForegroundColor Cyan  " VSO account.`n" `
                                                 "`n" `
                                                 "Specify the " -Separator ""
    Write-Host -NoNewLine -ForegroundColor Green "Build (read and execute)"
    Write-Host            -ForegroundColor Cyan  " scope."
    Write-Host            -ForegroundColor Blue  "https://winobjc.visualstudio.com/_details/security/tokens`n"
    $config = @{}
    $config.VSO = @{}
    $config.VSO.UserName = If($AuthUsername) { $AuthUsername } Else { Read-Host -Prompt "VSO E-mail Address" }
    $config.VSO.AccessToken = If($AuthToken) { ConvertTo-SecureString -AsPlainText -Force $AuthToken } Else { Read-Host -Prompt "VSO Access Token" -AsSecureString }
    return $config
}

Function Get-CliXmlConfigFile {
    Param (
        [Parameter(Mandatory=$true)]
        [string]$Name,

        [Parameter(Mandatory=$true)]
        [scriptblock]$Otherwise,

        [switch]$User
    )
    If ($User) {
        $ConfigRoot = $Env:USERPROFILE
    } Else {
        $ConfigRoot = Get-GitRepositoryRoot
    }
    $ConfigPath = $ConfigRoot + "\" + $Name
    $ret = $null
    If (Test-Path $ConfigPath) {
        $ret = (Import-CliXML $ConfigPath -EA SilentlyContinue)
    }
    If ($Reconfigure -or !$ret) {
        $ret = $Otherwise.InvokeReturnAsIs()
        Export-CliXML -Path $ConfigPath -InputObject $ret -WhatIf:$false
    }
    return $ret
}

$repoConfigPath = (Get-GitRepositoryRoot) + "\.ci-repo.xml"
$REPOCONFIG = [xml](Get-Content $repoConfigPath -ErrorAction SilentlyContinue)

If (!$REPOCONFIG) {
    Write-Error "Can't find repository config $repoConfigPath."
    Return
}

$REPOCONFIG = $REPOCONFIG.RepositoryConfig

$USERCONFIG = Get-CliXmlConfigFile -User -Name ".ci-user.xml" -Otherwise { Generate-UserConfig }

If ($Reconfigure) {
    Return
}

$shouldConfirmPushed = !$SkipRemoteCheck
If (![string]::IsNullOrEmpty($Ref)) {
    $shouldConfirmPushed = $false
}

If ([string]::IsNullOrEmpty($Ref)) {
    $Ref = (Get-GitBranch)
}

If ([string]::IsNullOrEmpty($RemoteURL)) {
    If ([string]::IsNullOrEmpty($Remote)) {
        # Determine the remote from the current branch, if possible.
        $Remote = (Get-GitBranchRemoteName $Ref)
        If ($Remote -Eq ".") {
            Throw "Local remotes are not supported. What even is a local remote?"
        }
        If ([string]::IsNullOrEmpty($Remote)) {
            # Fall back to origin if there's no remote for the current branch.
            $Remote = "origin"
        } Else {
            # If we derived the remote from the local Ref, stomp it with the remote tracking branch name.
            $Ref = Coalesce (Get-GitBranchTrackingName $Ref) $Ref
        }
    }
    $RemoteURL = (Get-GitRemoteUrl $Remote)
}

Write-Verbose "Ref       : $Ref"
Write-Verbose "Remote    : $Remote"
Write-Verbose "Remote URL: $RemoteURL"

If ($shouldConfirmPushed) {
    $remoteSHA=(Get-LatestRemoteRevision $RemoteURL $Ref)
    $localSHA=(Get-LatestLocalRevision)
    If ($localSHA -NE $remoteSha) {
        Write-Warning -Message "REMOTE OUT OF SYNC`n - local`n   $($localSHA.Substring(0,7))`n - $RemoteURL $Ref`n   $($remoteSHA.Substring(0,7))`nPerhaps you forgot to push?`n"
        $response = (Read-Host -Prompt "Schedule a build anyway? [N]")
        If ([string]::IsNullOrEmpty($response) -Or $response[0] -Ne "y") {
            Write-Warning -Message "Glad I asked."
            Return
        }
    }
}

#$vsoAuthCredential = (New-Object -TypeName "System.Management.Automation.PSCredential" -ArgumentList $USERCONFIG.VSO.UserName, $USERCONFIG.VSO.AccessToken)
$unmaskedAuthToken = [System.Runtime.InteropServices.marshal]::PtrToStringAuto([System.Runtime.InteropServices.marshal]::SecureStringToBSTR($USERCONFIG.VSO.AccessToken))
$encodedAuthCredential = [System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes("$($USERCONFIG.VSO.UserName):$($unmaskedAuthToken)"))
$headers = @{
    Authorization = "Basic $($encodedAuthCredential)"
}
$vsoBuildsURL = "https://$($REPOCONFIG.VSO.Instance)/DefaultCollection/$($REPOCONFIG.VSO.Project)/_apis/build/builds?api-version=2.0"

$matchingDefinitions = $REPOCONFIG.VSO.BuildDefinitions.BuildDefinitionSet
If (![string]::IsNullOrEmpty($BuildFilter)) {
    $matchingDefinitions = $matchingDefinitions | ? { $_.Name -Like $BuildFilter }
} Else {
    $matchingDefinitions = $matchingDefinitions | ? {
        If($_.MatchRemote) {
            $RemoteURL -Like $_.MatchRemote
        } Else {
            $False
        }
    }
}

ForEach($definitionSet in $matchingDefinitions) {
    $parameters = @{}
    $requestBody = @{}
    ForEach($parameter in $definitionSet.ConfigMappings.Parameter) {
        $parameters[$parameter.Key] = $parameter.InnerText.Replace("`$REMOTEURL", $RemoteURL).Replace("`$BRANCH", $Ref)
    }
    If ($definitionSet.ConfigMappings.SourceBranch) {
        $requestBody.sourceBranch = $definitionSet.ConfigMappings.SourceBranch.Replace("`$SOURCEBRANCH", $SourceBranch)
    }
    $requestBody.parameters = (ConvertTo-JSON -Compress $parameters)

    $filteredIDs = [Object[]]($definitionSet.ID | ? {
        If ([string]::IsNullOrEmpty($Config) -Or $_.Configuration -Eq $Config) {
            $_
        }
    })

    Write-Verbose "Submitting $($filteredIDs.Count) build$(If ($filteredIDs.Count -Ne 1) { "s" }) in $($definitionSet.Name) configuration."
    ForEach($defId in $filteredIDs) {
        $defIdNumber = [int]$defId.InnerText
        $outgoingReq = $requestBody.Clone()
        $outgoingReq.definition = @{
            id = [int]$defIdNumber;
        }

        Try {
            Write-Verbose "Queueing build $defIdNumber."
            If ($PSCmdlet.ShouldProcess("$defIdNumber", "Enqueue")) {
                $response = (Invoke-WebRequest -Body (ConvertTo-JSON -Compress $outgoingReq) -Headers $headers -ContentType "application/json" -Method Post -Uri $vsoBuildsURL)
                If ($response.StatusCode -Eq 200) {
                    Write-Output (ConvertFrom-JSON $response.Content)._links.web.href
                }
            } Else {
                Write-Verbose "POST $vsoBuildsURL`n$(ConvertTo-JSON $outgoingReq)"
            }
        } Catch {
            Write-Error "Failed to queue build $($defIdNumber): $($_.Exception.Message)"
        }
    }
}

# vim: ts=4 sw=4 et
