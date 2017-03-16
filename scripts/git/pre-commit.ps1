#
# Performs style checks on our codebase before committing.
#

."$PSScriptRoot/common.ps1"

# Ensures all changes are formatted correctly.
function Format-SourceFiles {
    $repoRootDirectory = Get-RepoRoot

    $unstagedFiles = Get-UnstagedFiles
    $stagedFiles = Get-StagedFiles

    # Check to make sure a file isn't both staged and unstaged
    $intersection = $stagedFiles | ?{$unstagedFiles -contains $_} 
    
    if ($intersection) {        
        $intersectionString = $intersection -join [environment]::NewLine
        $Host.UI.WriteErrorLine("Error: files cannot be both staged and unstaged: " + [environment]::NewLine +
            [environment]::NewLine +
            $intersectionString + [environment]::NewLine)
        exit 1
    }

    # Run clang-format over each file
    foreach ($file in $stagedFiles) {
        $file = "$file".Trim()
        if ($file) {
            ClangFormatFile $repoRootDirectory $file $False
        }
    }

    # Was anything changed? Compare staged files to unstaged files.
    $unstagedFiles = Get-UnstagedFiles
    
    $formatChangedFiles = @()
    foreach ($file in $stagedFiles) {
        $file = "$file".Trim()
        if ($file -and ($unstagedFiles -contains $file)) {
            $formatChangedFiles += $file
        }
    }
    
    if ($formatChangedFiles) {
        $formatChangedFilesString = $formatChangedFiles -join [environment]::NewLine
        
        $errorMessage =
            "The following files required style changes and have been modified in your working directory: " + [environment]::NewLine +
            [environment]::NewLine +
            $formatChangedFilesString + [environment]::NewLine +
            [environment]::NewLine +
            "Please review the changes and re-stage the modified files before committing." + [environment]::NewLine
            
        $Host.UI.WriteErrorLine($errorMessage)
        exit 1
    }
}

# Perform validation.
try {
    $ErrorActionPreference = "Stop"
    
    $Host.UI.WriteLine("Performing pre-commit validation...")

    # Make sure the source conforms to our coding standards
    Format-SourceFiles

    $Host.UI.WriteLine("Commit approved.")
    
} catch [Exception] {
    $Host.UI.WriteErrorLine($_.Exception.Message)
    $Host.UI.WriteErrorLine("If you *must* force this commit through, use 'git commit --no-verify'.")
    exit 1
}
