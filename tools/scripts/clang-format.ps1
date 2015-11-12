#
# Executes clang-format on all files in the specified directory (recursively if specified).
#

param(
    [string]$Directory = "",
    [string]$File = "",
    [switch]$Recursive = $false,
    [switch]$DryRun = $false
    )

# Returns root path of git repo
function Get-RepoRoot {
    $gitCommand = "git.exe rev-parse --show-toplevel"
    $results = Invoke-Expression $gitCommand | Out-String
    return $results
}

# Run clang-format
try {
    $repoRootDirectory = (Get-RepoRoot).Trim()
    Set-Location $repoRootDirectory
    
    $clangCommand = "msvc/LLVM-3.6.0/bin/clang-format.exe -style=file "

    # If not dry-run, edit the files in-place
    if (!$DryRun) {
        $clangCommand += "-i "
    }

    # Validate args
    if ([string]::IsNullOrEmpty($File) -and [string]::IsNullOrEmpty($Directory)) {
        throw "You must specify at least one directory or file to format."
    }

    # Process a single file if specified
    if (![string]::IsNullOrEmpty($File)) {
        $invokeCommand = $clangCommand + $file.Trim()
        $invokeResult = Invoke-Expression $invokeCommand
        if ($invokeResult) {
            return diff (cat $file.Trim()) ($invokeResult)
        }
    }

    # Process a directory if specified
    if (![string]::IsNullOrEmpty($Directory)) {
        $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}
        $filesToFormat = ""
        if ($Recursive) {
            $filesToFormat = Get-ChildItem $Directory -recurse |
            Where-Object -FilterScript $filter | Select FullName | ft -hidetableheaders | Out-String
        }
        else {
            $filesToFormat = Get-ChildItem $Directory |
            Where-Object -FilterScript $filter | Select FullName | ft -hidetableheaders | Out-String
        }

        # Run clang-format over each file
        foreach ($file in $filesToFormat.split([environment]::NewLine)) {
            if (![string]::IsNullOrEmpty($file)) {
                $invokeCommand = $clangCommand + $file.Trim()
                echo $invokeCommand
                Invoke-Expression $invokeCommand
            }
        }
    }
}
catch [Exception] {
    $Host.UI.WriteErrorLine($_.Exception.Message)
    exit 1
}
