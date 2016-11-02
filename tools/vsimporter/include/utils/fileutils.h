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

#ifndef _FILEUTILS_H_
#define _FILEUTILS_H_

#if defined(_MSC_VER)
#include "posix_compat.h"
#endif

#include <string>
#include <algorithm>
#include <dirent.h>
#include <sys/stat.h>

#include "types.h"

typedef enum {
  WindowsPath = 1,
  PosixPath = 2,
#if defined(_MSC_VER)
  PlatformPath = WindowsPath
#else
  PlatformPath = PosixPath
#endif
} PathStyle;

/*
 * The functions dirname() and basename() break a null-terminated
 * pathname string into directory and filename components.  In the usual
 * case, dirname() returns the string up to, but not including, the
 * final '/', and basename() returns the component following the final
 * '/'.  Trailing '/' characters are not counted as part of the
 * pathname.
 * 
 * If path does not contain a slash, dirname() returns the string "."
 * while basename() returns a copy of path.  If path is the string "/",
 * then both dirname() and basename() return the string "/".  If path is
 * a NULL pointer or points to an empty string, then both dirname() and
 * basename() return the string ".".
 */
String sb_basename(const String& path);
String sb_dirname(const String& path);

/*
 * Perform a (possibly recursive) search in searchDir for any files matching
 * the specified type and filename patterns.
 */
void findFiles(const String& searchDir, const StringVec& filePatterns, int fileType, bool recursive, StringList& results);
void findFiles(const String& searchDir, const String& filePattern, int fileType, bool recursive, StringList& results);

/*
 * Get the file name or extention
 */
String sb_fname(const String& path);
String sb_fextension(const String& path);

/*
 * Real path
 */
String sb_realpath(const String& path);

/*
 * Check if specified path exists
 */
bool fileExists(const String& path);

/*
 * Check if specified file path exists
 */
bool isFile(const String& filePath);

/*
 * Check if specified directory path exists
 */
bool isDir(const String& dirPath);

/*
 * Replaces ~ in path with user's home directory.
 */
String sb_expanduser(const String& path);

/*
 * Remove as many . and .. tokens from path as possible.
 * Does not access the filesystem, or check whether the path exists.
 * Path must not contain any variables.
 */
String sanitizePath(const String &path);

/*
 * Returns true if the provided path is absolute.
 */
bool isAbsolutePath(const String &path, PathStyle style = PlatformPath);

/*
 * Returns the current working directory.
 */
String getcwd();

/*
 * Joins two paths into one.
 */
String joinPaths(const String& lhs, const String& rhs, bool sanitize = true);

/*
 * Returns a recursive directory list.
 */
void getRecursiveDirList(const String& baseDir, StringVec& dirVec, const StringVec& ignoreList);

/* 
 * Function with behaviour like `mkdir -p'
 * http://niallohiggins.com/2009/01/08/mkpath-mkdir-p-alike-in-c-for-unix/
 */
int mkpath(const String& dirPath, mode_t mode = S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);

/*
 * Return a list of possible header extensions/types.
 */
const StringVec& getHeaderExts();
const StringVec& getHeaderTypes();

/*
 * Convert between Windows and Posix paths
 */
String platformPath(const String& path, PathStyle style = PlatformPath);
inline String winPath(const String& path) { return platformPath(path, WindowsPath); }
inline String posixPath(const String& path) { return platformPath(path, PosixPath); }

/*
 * Get a relative path from one path to another.
 */
String getRelativePath(const String& fromAbsPath, const String& toAbsPath);
void getRelativePaths(const String& fromAbsPath, StringVec& toAbsPaths);

void openOutputFileStream(OFStream& ofs, const String& outFilePath, OFStream::openmode mode = OFStream::out);

#endif /* _FILEUTILS_H_ */

