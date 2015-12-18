//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <sys/stat.h>
#include <libgen.h>
#include <string.h>
#include <errno.h>
#include <algorithm>
#include <unistd.h>
#if defined(_MSC_VER)
#include <direct.h> // getcwd
#include <Windows.h>
#include <Psapi.h>
#endif

#include "SBLog.h"
#include "sbassert.h"
#include "stringutils.h"
#include "fileutils.h"

String sb_basename(const String& path)
{
  char *cpath = strdup(path.c_str());
  char *bname = ::basename(cpath);
  String ret;
      
  if (bname) ret = bname;

  free(cpath);
  return ret;
}

String sb_dirname(const String& path)
{
  String ret;
  char *cpath = strdup(path.c_str());
  char *bname = ::dirname(cpath);

  if (bname) ret = bname;

  free(cpath);
  return ret;
}

String sb_fname(const String& path)
{
  String fixedPath = posixPath(path);

  // Special case
  if (fixedPath == ".")
    return path;

  size_t ext_pos = fixedPath.rfind(".");
  size_t dir_pos = fixedPath.rfind("/");

  if (ext_pos != String::npos) {
    if (dir_pos == String::npos || (dir_pos != String::npos && dir_pos < ext_pos)) {
      return fixedPath.substr(0, ext_pos);
    }
  }
  return path;
}

String sb_fextension(const String& path)
{
  String fixedPath = posixPath(path);

  String ext;
  size_t ext_pos = fixedPath.rfind(".");
  size_t dir_pos = fixedPath.rfind("/");

  if (ext_pos != String::npos) {
    if (dir_pos == String::npos || (dir_pos != String::npos && dir_pos < ext_pos)) {
      ext = fixedPath.substr(ext_pos + 1);
    }
  }
  return ext;
}

String sb_realpath(const String& path)
{
  char abspath[PATH_MAX+1];
  if (realpath(path.c_str(), abspath))
    return abspath;
  else
    return "";
}

void findFiles(const String& searchDir, const StringVec& filePatterns, int fileType, bool recursive, StringList& results)
{
  struct dirent *entry;
  DIR *dir = opendir(searchDir.c_str());
  
  if (!dir) {
    SBLog::warning() << "Failed to open \"" << searchDir << "\" directory for file search." << std::endl;
    return;
  }
  
  while ((entry = readdir(dir))) {
    // Ignore . and .. so we dont accidentally recurse on them
    if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
      continue;
      
    // Get full path to entry
    String path = joinPaths(searchDir, entry->d_name);
    
    // Check if the file matches our search criteria
    if (entry->d_type == fileType && matchWildcardList(entry->d_name, filePatterns)) {
      results.push_back(path);
      continue;
    }
    
    // Possibly recurse
    if (entry->d_type == DT_DIR && recursive) {
      findFiles(path, filePatterns, fileType, recursive, results);
    }
  }

  closedir(dir);
}

String sb_expanduser(const String& path)
{
  if (!path.empty() && path[0] == '~') {
    String homeDir;
    assert(sb_getenv("HOME", homeDir));
    return homeDir + path.substr(1);
  } else {
    return path;
  }
}

void findFiles(const String& searchDir, const String& filePattern, int fileType, bool recursive, StringList& results)
{
  StringVec filePatterns(1, filePattern);
  findFiles(searchDir, filePatterns, fileType, recursive, results);
}

bool fileExists(const String& path)
{
  // Handle ~ in path
  String fixedPath = sb_expanduser(path);

  struct stat st;
  return !stat(fixedPath.c_str(), &st);
}

bool isFile(const String& filePath)
{
  // Handle ~ in path
  String fixedPath = sb_expanduser(filePath);

  struct stat st;
  return !stat(fixedPath.c_str(), &st) && S_ISREG(st.st_mode);
}

bool isDir(const String& dirPath)
{
  // Handle ~ in path
  String fixedPath = sb_expanduser(dirPath);

  struct stat st;
  return !stat(fixedPath.c_str(), &st) && S_ISDIR(st.st_mode);
}

String sanitizePath(const String &path)
{
  // Standardize slashes to POSIX style
  String fixedPath = posixPath(path);

  // Check if path is absolute
  bool isAbsolute = isAbsolutePath(fixedPath);

  // Tokenize path
  StringList pathComponents;
  std::size_t start = 0;
  do {
    std::size_t separator = (std::min)(fixedPath.find('/', start), fixedPath.length());
    String token = fixedPath.substr(start, separator - start);
    if (token.empty() || token == ".") {
      // a/./b -> a/b and a//b -> a/b
    } else if (token == "..") {
      if (pathComponents.empty()) {
        // ../a -> ../a
        // /../a -> /a
        if (!isAbsolute)
          pathComponents.push_back(token);
      } else {
        // ../../a -> ../../a
        // a/../c -> c
        if (pathComponents.back() == "..")
          pathComponents.push_back(token);
        else
          pathComponents.pop_back();
      }
    } else {
      pathComponents.push_back(token);
    }

    start = separator + 1;
  } while (start < path.length());

  // Figure out if we need to add a leading slash
  String prefix;
  if (strBeginsWith(fixedPath, "/"))
    prefix = "/";

  // Return reassembled path
  return prefix + joinStrings(pathComponents, "/");
}

bool isAbsolutePath(const String &path, PathStyle style)
{
  if (style == WindowsPath)
    return ((path.length() >= 2 && isalpha(path[0]) && path[1] == ':') ||
            strBeginsWith(path, "/") || strBeginsWith(path, "\\"));
  else if (style == PosixPath)
    return strBeginsWith(path, "/");
  else
    return false;
}

String getcwd()
{
  char cwd[PATH_MAX+1];
  sbAssert(getcwd(cwd, sizeof(cwd)), "Failed to get CWD");
  return posixPath(cwd);
}

String joinPaths(const String& lhs, const String& rhs, bool sanitize)
{
  String joinedPath;
  if (rhs.empty()) {
    joinedPath = lhs;
  } else if (lhs.empty() || isAbsolutePath(rhs)) {
    joinedPath = rhs;
  } else {
    joinedPath = lhs + "/" + rhs;
  }

  if (sanitize) {
    return sanitizePath(joinedPath);
  } else {
    return joinedPath;
  }
}

void getRecursiveDirList(const String& baseDir, StringVec& dirVec, const StringVec& ignoreList)
{ 
  DIR* dir = opendir(baseDir.c_str());
  if (!dir)
    return;
    
  dirVec.push_back(baseDir);

  struct dirent* entry;
  while ((entry = readdir(dir))) {
    if (entry->d_type == DT_DIR) {
      String path = joinPaths(baseDir, entry->d_name);
         
      if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
        continue;
        
      if (matchWildcardList(entry->d_name, ignoreList))
        continue;
      
      getRecursiveDirList(path, dirVec, ignoreList);
    }
  }

  closedir(dir);
}

int mkpath(const String& dirPath, mode_t mode)
{
  String parentPath = sb_dirname(dirPath);
  if (parentPath == "." || parentPath == dirPath)
    return 0;

  int rv = 0;
  if ((mkpath(parentPath, mode) == -1) && (errno != EEXIST))
    rv = -1;

#if defined(_MSC_VER)
  if ((rv == 0) && (mkdir(dirPath.c_str()) == -1) && (errno != EEXIST))
#else
  if ((rv == 0) && (mkdir(dirPath.c_str(), mode) == -1) && (errno != EEXIST))
#endif
    rv = -1;

  return (rv);
}

const StringVec& getHeaderExts()
{
  static const char* const _headerExts[] = {"*.h", "*.hh", "*.hpp", "*.pch"};
  static StringVec extList(_headerExts, _headerExts + sizeof(_headerExts) / sizeof(char*));
  return extList;
}

const StringVec& getHeaderTypes()
{
  static const char* const _headerTypes[] = {"sourcecode.c.h", "sourcecode.cpp.h"};
  static StringVec typeList(_headerTypes, _headerTypes + sizeof(_headerTypes) / sizeof(char*));
  return typeList;
}

String platformPath(const String& path, PathStyle style)
{
  if (style == WindowsPath)
    return sb_replace(path, "/", "\\", -1);
  else if (style == PosixPath)
    return sb_replace(path, "\\", "/", -1);
  else
    return path;
}

bool comparePaths(const String& p1, const String& p2)
{
  return strToLower(p1) == strToLower(p2);
}

// FIXME: Fails on Windows if one of the paths does not specify a drive letter
// E.g. c:\foo\bar and \foo\myfile.txt
String getRelativePath(const String& fromAbsPath, const String& toAbsPath)
{
  // Tokenize the paths
  StringVec fromTokens, toTokens;
  tokenize(posixPath(fromAbsPath), fromTokens, "/", "", "", "", "\\", false, false);
  tokenize(posixPath(toAbsPath), toTokens, "/", "", "", "", "\\", false, false);

  // Find the longest common prefix
  unsigned i = 0;
  StringVec::iterator fromIt = fromTokens.begin();
  StringVec::iterator toIt = toTokens.begin();
  for (; fromIt != fromTokens.end() && toIt != toTokens.end(); fromIt++, toIt++, i++) {
    if (!comparePaths(*fromIt, *toIt))
      break;
  }

  if (i > 0) {
    // Assemble the relative path
    StringVec relPathTokens(fromTokens.size() - i, "..");
    relPathTokens.insert(relPathTokens.end(), toIt, toTokens.end());
    return joinStrings(relPathTokens, "/");
  } else {
    // Paths have nothing in common, so no relative path exists (Windows-only)
    return sanitizePath(toAbsPath);
  }
}

void getRelativePaths(const String& fromAbsPath, StringVec& toAbsPaths)
{
  StringVec::iterator pathsIt = toAbsPaths.begin();
  for (; pathsIt != toAbsPaths.end(); pathsIt++) {
    *pathsIt = getRelativePath(fromAbsPath, *pathsIt);
  }
}

void openOutputFileStream(OFStream& ofs, const String& outFilePath, OFStream::openmode mode)
{
  // Create directories
  std::string outputDir = sb_dirname(outFilePath);
  if (mkpath(outputDir)) {
    SBLog::warning() << "Failed to create " << outputDir << " output directory path." << std::endl;
    return;
  }

  // Open output file
  ofs.open(outFilePath.c_str(), mode);
  if (!ofs.is_open()) {
    SBLog::warning() << "Failed to open " << outFilePath << " for writing." << std::endl;
    return;
  }
}

String getBinaryLocation()
{
#if defined(_MSC_VER)
  char pathToExe[MAX_PATH];
  GetModuleFileNameEx(GetCurrentProcess(), NULL, pathToExe, sizeof(pathToExe) / sizeof(pathToExe[0]));
  return pathToExe;
#else
#error Function not defined for current platform.
#endif
}