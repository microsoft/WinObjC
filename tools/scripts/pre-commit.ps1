#
# Performs style checks on our codebase.
#

# Returns a list of any unstaged files in the current git working directory.
function Get-UnstagedFiles {
    $gitCommand = "git diff --name-only"
    return Invoke-Expression $gitCommand | Out-String
}

# Makes sure there aren't any unstaged changes in the working directory.
function Force-StageOrStash() {
    $unstagedFiles = Get-UnstagedFiles

    if (![string]::IsNullOrEmpty($unstagedFiles)) {
        $errorMessage = 
            "The files below contain unstaged changes. Please stash or stage them before committing to WinObjC:" + 
            [environment]::NewLine + [environment]::NewLine + 
            $unstagedFiles
        throw $errorMessage
    }
}

# Ensures all changes are formatted correctly.
function Format-SourceFiles {
    $gitCommand = "git diff --cached --name-only --diff-filter=ACMRT"
    $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}
    $clangCommand = "bin/clang-format-3.7.exe -style=file -i "

    # Get a flat list of all changed files
    $stagedFileString = 
        Invoke-Expression $gitCommand | 
        Where-Object -FilterScript $filter | Out-String

    # TODO: Run clang-tidy over each file first?

    # Run clang-format over each file
    foreach ($file in $stagedFileString.split([environment]::NewLine)) {
        if (![string]::IsNullOrEmpty($file)) {
            $invokeCommand = $clangCommand + $file.Trim()
            echo $invokeCommand
            Invoke-Expression $invokeCommand
        }
    }

    # Was anything changed?
    $unstagedFiles = Get-UnstagedFiles
    if (![string]::IsNullOrEmpty($unstagedFiles)) {
        $errorMessage = 
            "The following files required style changes and have been modified in your working directory: " + 
            [environment]::NewLine + [environment]::NewLine +
            $unstagedFiles + [environment]::NewLine + 
            "Please review the changes and re-stage the modified files before committing."
        throw $errorMessage
    }
}

# Perform validation.
try {
    echo "Performing pre-commit validation..."

    # Force staged files so there's no question what changes we're validating.
    Force-StageOrStash

    # Make sure the source conforms to our coding standards 
    Format-SourceFiles
}
catch [Exception] {
    $Host.UI.WriteErrorLine($_.Exception.Message)
    exit 1
}
