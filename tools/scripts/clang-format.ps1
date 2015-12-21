#
# Executes clang-format on all files in the specified directory (recursively if specified).
#

param(
    [string]$Directory = "",
    [string]$File = "",
    [switch]$Recursive = $false,
    [switch]$DryRun = $false
    )

."$PSScriptRoot/common.ps1"

# Run clang-format
try {
    $repoRootDirectory = Get-RepoRoot
    Set-Location $repoRootDirectory

    $File = "$File".Trim()
    $Directory = "$Directory".Trim()

    $clangPath = "msvc/LLVM-3.6.0/bin/clang-format.exe"
    [array]$clangArgs = @()
    $clangArgs += "-style=file"

    # If not dry-run, edit the files in-place
    if (!$DryRun) {
        $clangArgs += "-i"
    }

    # Validate args
    if (!$File -and !$Directory) {
        throw "You must specify at least one directory or file to format."
    }

    # Process a single file if specified
    if ($File) {
        $result = & $clangPath $clangArgs $File 2>&1
        Check-Result
        
        if ($result) {
            return diff (cat "$File") ($result)
        }
        
        return
        
    } elseif ($Directory) {
        # Process a directory if specified
        
        $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}
        $filesToFormat = ""
        
        if ($Recursive) {
            $filesToFormat = Get-ChildItem $Directory -recurse |
            Where-Object -FilterScript $filter | Select FullName | ft -hidetableheaders | Out-String
        } else {
            $filesToFormat = Get-ChildItem $Directory |
            Where-Object -FilterScript $filter | Select FullName | ft -hidetableheaders | Out-String
        }

        # Run clang-format over each file
        foreach ($File in $filesToFormat.split([environment]::NewLine)) {
            $File = "$File".Trim()

            if ($File) {
                $result = & $clangPath $clangArgs $File 2>&1
                Check-Result
            }
        }
    }
}
catch [Exception] {
    $Host.UI.WriteErrorLine($_.Exception.Message)
    exit 1
}
