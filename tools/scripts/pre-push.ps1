#
# Performs style checks on our codebase before pushing.
#

Param(
  [string]$upstreamName
)

."$PSScriptRoot/common.ps1"

# Ensures all changes are formatted correctly.
function Format-SourceFiles {
    $repoRootDirectory = Get-RepoRoot
    
    $upstreamName = "$upstreamName".Trim()
    if (!$upstreamName) {
        $upstreamName = & git.exe rev-parse --symbolic-full-name `@`{u`}
        Check-Result
    }
    
    $upstreamName = "$upstreamName".Trim()
    if (!$upstreamName) {
        $Host.UI.WriteErrorLine("Please set an upstream branch or pass one as the first argument to the script.")
        exit 1
    }
    
    $Host.UI.WriteLine("Upstream is $upstreamName")

    # Get a flat list of all changed files
    $diffedFiles = Get-DiffedFiles $upstreamName
    $stagedFiles = Get-UnstagedFiles
    $unstagedFiles = Get-UnstagedFiles
    
    if ($stagedFiles -or $unstagedFiles) {
        $Host.UI.WriteErrorLine("Error: cannot have staged or unstaged files")
        exit 1
    }
    
    $changedFiles = @()
    
    # Run clang-format over each file
    foreach ($file in $diffedFiles) {
        $file = "$file".Trim()
        
        if ($file) {
            $difference = ClangFormatFile $repoRootDirectory $file $True

            if ($difference) {
                $changedFiles += $file
                $difference = ClangFormatFile $repoRootDirectory $file $False
            }
        }
    }

    # Was anything changed?
    if ($changedFiles) {
        $changedFilesString = $changedFiles -join [environment]::NewLine
        
        $errorMessage =
            "The following files required style changes and have been modified: " + [environment]::NewLine +
            [environment]::NewLine +
            $changedFilesString + [environment]::NewLine +
            [environment]::NewLine +
            "Review the changed files, stage, commit them, and re-run this script. " + [environment]::NewLine +
            [environment]::NewLine +
            "Otherwise, run the following command to revert the formatting changes: " + [environment]::NewLine +
            [environment]::NewLine +
            "git reset --hard HEAD" + [environment]::NewLine

        $Host.UI.WriteErrorLine($errorMessage)
        exit 1
    } else {
        $Host.UI.WriteLine("All files are formatted correctly.")
    }
}

# Perform validation.
try {
    $ErrorActionPreference = "Stop"
    $Host.UI.WriteLine("Performing pre-push validation...")

    # Make sure the source conforms to our coding standards
    Format-SourceFiles
    
} catch [Exception] {
    $Host.UI.WriteErrorLine("Exception encountered when formatting files.")
    $Host.UI.WriteErrorLine($_.Exception.Message)
    exit 1
}
