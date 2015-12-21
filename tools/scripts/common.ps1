#
# Common functions used by the format scripts.
#

# Check exit code and fail fast on error
function Check-Result() {
    if (!$?) {
        throw
    }
}

# Returns root path of git repo
function Get-RepoRoot {
    $root = & git.exe rev-parse --show-toplevel 2>&1
    Check-Result
    
    return $root.Trim()
}

# Filters source files
function Filter-SourceFiles {
    if (!$args) {
        return
    }

    $filter = {$_ -like "*.mm" -or $_ -like "*.m" -or $_ -like "*.c" -or $_ -like "*.cpp" -or $_ -like "*.h"}
    [array]$files = $args | Where-Object -FilterScript $filter
    
    return $files
}

# Returns a list of any unstaged files in the current git working directory.
function Get-UnstagedFiles {
    [array]$unstagedFiles = & git.exe diff --name-only 2>&1
    Check-Result

    return Filter-SourceFiles @unstagedFiles
}

# Returns a list of diffed files against an upstream
function Get-DiffedFiles([string] $upstreamName) {
    [array]$diffedFiles = & git.exe diff $upstreamName --name-only --diff-filter=ACMRT 2>&1
    Check-Result

    return Filter-SourceFiles @diffedFiles
}

# Returns list of staged files
function Get-StagedFiles {
    [array]$stagedFiles = & git.exe diff --staged --name-only --diff-filter=ACMRT 2>&1
    Check-Result

    return Filter-SourceFiles @stagedFiles
}

# Formats the given file using ClangFormat
function ClangFormatFile([string]$repoRoot, [string]$filename, [bool]$isDryRun){
    $clangCommand = "$repoRoot/tools/scripts/clang-format.ps1"
    $filename = $filename.Trim()
    
    if ($isDryRun) {
        & "$clangCommand" -Directory "" -File $filename -DryRun 2>&1
    } else {
        & "$clangCommand" -Directory "" -File $filename 2>&1
    }
    Check-Result
}
