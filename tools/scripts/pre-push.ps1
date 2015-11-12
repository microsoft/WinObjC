#
# Performs style checks on our codebase.
#

Param(
  [string]$upstreamName
)

# Returns root path of git repo
function Get-RepoRoot {
    $gitCommand = "git.exe rev-parse --show-toplevel"
    $results = Invoke-Expression $gitCommand | Out-String
    return $results
}

# Ensures all changes are formatted correctly.
function Format-SourceFiles {
    $repoRootDirectory = (Get-RepoRoot).Trim()
    
    if ([string]::IsNullOrEmpty($upstreamName.Trim())) {
        $upstreamName = Invoke-Expression "git.exe rev-parse --symbolic-full-name ``@``{u``}" | Out-String
        $upstreamName = $upstreamName.Trim()
    }
    
    if ([string]::IsNullOrEmpty($upstreamName.Trim())) {
        $Host.UI.WriteErrorLine("Please set an upstream branch or pass one as the first argument to the script.")
        exit 1
    }
    
    $Host.UI.WriteLine("Upstream is $upstreamName")
    
    $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}

    # Create a snapshot of the un-committed files, in case want to undo later
    $stashHash = Invoke-Expression "git.exe stash create" | Out-String

    $changedFiles = ""
    try {
        # Get a flat list of all changed files
        $stagedFileString = 
            Invoke-Expression "git.exe diff $upstreamName --name-only --diff-filter=ACMRT" |
            Where-Object -FilterScript $filter | Out-String

        # Run clang-format over each file
        foreach ($file in $stagedFileString.split([environment]::NewLine)) {
            if (![string]::IsNullOrEmpty($file)) {
                # The command we'll use to format the file
                $invokeCommand = $repoRootDirectory.Trim() + "/tools/scripts/clang-format.ps1 -File " + $file.Trim()
                
                $difference = Invoke-Expression -command ($invokeCommand + " -DryRun 2>&1")
                
                if ($difference) {
                    $changedFiles = $changedFiles + $file + [environment]::NewLine
                    Invoke-Expression -command ($invokeCommand + " 2>&1")
                }
            }
        }
    } catch [Exception] {
        $Host.UI.WriteErrorLine("Exception while formatting files.")
        $Host.UI.WriteErrorLine($_.Exception.Message)
    }

    # Was anything changed?
    if (![string]::IsNullOrEmpty($changedFiles)) {
        $infoMessage =
            "The following files required style changes and have been modified: " +
            [environment]::NewLine + [environment]::NewLine +
            $changedFiles + [environment]::NewLine +
            "Review the changed files, stage, and commit them if they look good. Then you are ready to push." + [environment]::NewLine + [environment]::NewLine +
            "Otherwise, run the following commands to revert the formatting changes: " + [environment]::NewLine + [environment]::NewLine +
            "git reset --hard HEAD" + [environment]::NewLine
            if (![string]::IsNullOrEmpty($stashHash)) {
                $infoMessage += "git stash apply " + $stashHash + [environment]::NewLine
            }
        $Host.UI.WriteLine($infoMessage)
    }
}

# Perform validation.
try {
    echo "Performing pre-push validation..."

    # Make sure the source conforms to our coding standards
    Format-SourceFiles

    Invoke-Expression -command ("git.exe status")
} catch [Exception] {
    $Host.UI.WriteErrorLine("Exception encountered when formatting files.")
    $Host.UI.WriteErrorLine($_.Exception.Message)
    exit 1
}
