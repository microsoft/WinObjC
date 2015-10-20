#
# Performs style checks on our codebase.
#

# Returns root path of git repo
function Get-RepoRoot {
    $gitCommand = "git.exe rev-parse --show-toplevel"
    $results = Invoke-Expression $gitCommand | Out-String
    return $results
}

# Returns a list of any unstaged files in the current git working directory.
function Get-UnstagedFiles {
    $gitCommand = "git.exe diff --name-only"
    $results = Invoke-Expression $gitCommand | Out-String
    return $results
}

# Ensures all changes are formatted correctly.
function Format-SourceFiles {
    $repoRootDirectory = Get-RepoRoot
    $gitCommand = "git.exe diff --cached --name-only --diff-filter=ACMRT"
    $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}
    $clangCommand = $repoRootDirectory.Trim() + "/tools/scripts/clang-format.ps1 -File "

    # Do we have to worry about any unstaged files?
    $unstagedFiles = Get-UnstagedFiles
    $hadUnstagedFiles = ![string]::IsNullOrEmpty($unstagedFiles)

    # We have some unstaged files, so stash them
    if ($hadUnstagedFiles) {
        echo "Stashing unstaged files in working directory..."
        $stashCommand = "git.exe stash -k -u --quiet 2>&1"
        $result = Invoke-Expression $stashCommand | Out-String
    }

    $manualReformattingNecessary = $false
    try {

        # Get a flat list of all staged files
        $stagedFileString = 
            Invoke-Expression $gitCommand |
            Where-Object -FilterScript $filter | Out-String

        # Run clang-format over each file
        foreach ($file in $stagedFileString.split([environment]::NewLine)) {
            if (![string]::IsNullOrEmpty($file)) {
                # The command we'll use to format the file
                $invokeCommand = $clangCommand + $file.Trim()

                # If there were no unstaged changes, we can just do the reformats in-place
                if (!$hadUnstagedFiles) {
                    Invoke-Expression -command ($invokeCommand + " 2>&1")
                } else {
                    # There were unstaged changes, so just do a dry-run check here
                    $difference = Invoke-Expression -command ($invokeCommand + " -DryRun 2>&1")
                    if ($difference) {
                        # If a reformat was necessary, print the command to the console
                        $manualReformattingNecessary = $true
                        $devCommand = $invokeCommand.Trim()
                        $Host.UI.WriteErrorLine($devCommand)
                        $Host.UI.WriteErrorLine("git " + $file.Trim() + [environment]::NewLine)
                    }
                }
            }
        }
    } finally {
        # If we stashed unstaged files pop them
        if ($hadUnstagedFiles) {
            echo "Restoring stashed files in working directory..."

            $resetCommand = "git.exe reset --hard 2>&1"
            $result = Invoke-Expression $resetCommand | Out-String

            $popCommand = "git.exe stash pop --quiet --index 2>&1"
            $result = Invoke-Expression $popCommand | Out-String
        }
    }

    if (!$hadUnstagedFiles) {
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
    } elseif ($manualReformattingNecessary) {
        $errorMessage =
            "There are formatting issues with this commit, and auto-resolution was not possible due to unstaged changes in your working directory." + [environment]::NewLine +
            "Please run the above commands to reformat each file, then re-stage them before committing."
        throw $errorMessage
    }
}

# Perform validation.
try {
    echo "Performing pre-commit validation..."

    # Make sure the source conforms to our coding standards
    Format-SourceFiles

    echo "Commit approved."
}
catch [Exception] {
    $Host.UI.WriteErrorLine($_.Exception.Message)
    $Host.UI.WriteErrorLine("If you *must* force this commit through, use 'git commit --no-verify'.")
    exit 1
}
