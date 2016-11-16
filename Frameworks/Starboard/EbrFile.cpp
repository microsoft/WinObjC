//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <direct.h>
#include <sys\stat.h>
#include <map>
#include <climits>
#include <regex>

#include <Platform/EbrPlatform.h>
#include <Starboard.h>
#include "PathMapper.h"
#include "LoggingNative.h"
#include "EbrFile.h"
#include "EbrIOFile.h"
#include "EbrDevRandomFile.h"
#include "EbrStorageFile.h"

static const wchar_t* TAG = L"EbrFile";

std::mutex EbrFile::s_fileMapLock{};
std::map<int, std::shared_ptr<EbrFile>> EbrFile::s_fileMap{};
int EbrFile::s_maxFileId{ 0 };

std::shared_ptr<EbrFile> EbrFile::GetFile(int fid) {
    std::lock_guard<std::mutex> guard(s_fileMapLock);

    auto iter = s_fileMap.find(fid);
    if (iter != s_fileMap.end()) {
        return iter->second;
    }

    return nullptr;
}

int EbrFile::AddFile(std::shared_ptr<EbrFile>&& file) {
    std::lock_guard<std::mutex> guard(s_fileMapLock);

    std::map<int, std::shared_ptr<EbrFile>>::iterator iter;

    // Make sure the slot is open. This should almost always be the case.
    // The only time this fails is when the id wraps around which should be
    // exceedingly rare.
    do {
        s_maxFileId = (s_maxFileId == INT_MAX) ? 0 : (s_maxFileId + 1);
        iter = s_fileMap.find(s_maxFileId);
    } while (iter != s_fileMap.end());

    s_fileMap.emplace(s_maxFileId, std::move(file));

    return s_maxFileId;
}

void EbrFile::RemoveFile(int fid) {
    std::lock_guard<std::mutex> guard(s_fileMapLock);
    s_fileMap.erase(fid);
}

//  IO funcs

int EbrOpen(const char* file, int mode, int share) {
    return EbrOpenWithPermission(file, mode, share, 0);
}

int EbrOpenWithPermission(const char* file, int mode, int share, int pmode) {
    std::shared_ptr<EbrFile> fileToAdd;

    // Special random number device. Just a stub.
    fileToAdd = EbrDevRandomFile::CreateInstance(file, mode, share, pmode);

    if (!fileToAdd) {
        // Special file type for cached storage files.
        fileToAdd = EbrStorageFile::CreateInstance(file, mode, share, pmode);
    }

    if (!fileToAdd) {
        // No more special types. Assume its a real file.
        fileToAdd = EbrIOFile::CreateInstance(file, mode, share, pmode);
    }

    return (fileToAdd) ? EbrFile::AddFile(std::move(fileToAdd)) : -1;
}

int EbrClose(int fd) {
    EbrFile::RemoveFile(fd);
    return 0;
}

int EbrFstat(int fd, struct stat* ret) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Stat(ret);
}

int EbrFstat64i32(int fd, struct _stat64i32* ret) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Stat64i32(ret);
}

intptr_t EbrGetOSFHandle(int fd) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->GetOSFHandle();
}

int EbrRead(int fd, void* dest, size_t count) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Read(dest, count);
}

int EbrWrite(int fd, const void* src, size_t count) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Write(src, count);
}

__int64 EbrLseek(int fd, __int64 pos, int whence) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Lseek(pos, whence);
}

int EbrTruncate64(int fd, __int64 size) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Truncate64(size);
}

__int64 EbrTell(int fd) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? 0 : file->Tell();
}

int EbrFflush(int fd) {
    auto file = EbrFile::GetFile(fd);
    return (file == nullptr) ? -1 : file->Flush();
}

bool EbrRemoveEmptyDir(const char* path) {
    return RemoveDirectoryA(CPathMapper(path));
}

bool EbrRename(const char* path1, const char* path2) {
    return rename(CPathMapper(path1), CPathMapper(path2)) == 0;
}

bool EbrUnlink(const char* path) {
    return _unlink(CPathMapper(path)) == 0;
}

#define FSROOT "."
#define mkdir _mkdir
char g_WritableFolder[2048] = ".";

void EbrSetWritableFolder(const char* folder) {
    strcpy_s(g_WritableFolder, folder);
}

const char* EbrGetWritableFolder() {
    return g_WritableFolder;
}

bool EbrGetRootMapping(const char* dirName, char* dirOut, uint32_t maxLen) {
    if (dirName == NULL) {
        strcpy_s(dirOut, maxLen, FSROOT);
        return true;
    }
    if (_stricmp(dirName, "Documents") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\Documents", g_WritableFolder);
        mkdir(dirOut);

        char tmpDir[4096];
        strcpy_s(tmpDir, dirOut);
        strcat_s(tmpDir, "\\Library");
        mkdir(tmpDir);
        return true;
    }
    if (_stricmp(dirName, "Cache") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\cache", g_WritableFolder);
        mkdir(dirOut);
        return true;
    }
    if (_stricmp(dirName, "Library") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\Library", g_WritableFolder);
        mkdir(dirOut);
        return true;
    }
    if (_stricmp(dirName, "AppSupport") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\AppSupport", g_WritableFolder);
        mkdir(dirOut);
        return true;
    }
    if (_stricmp(dirName, "tmp") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\tmp", g_WritableFolder);
        mkdir(dirOut);
        return true;
    }
    if (_stricmp(dirName, "shared") == 0) {
        sprintf_s(dirOut, maxLen, "%s\\shared", g_WritableFolder);
        mkdir(dirOut);
        return true;
    }
    static std::regex drive("[a-zA-Z]:");
    if (std::regex_match(dirName, drive)) {
        sprintf_s(dirOut, maxLen, dirName);
        return true;
    }
    sprintf_s(dirOut, maxLen, FSROOT "\\%s", dirName);
    return true;
}

bool EbrMkdir(const char* path) {
    return _mkdir(CPathMapper(path)) == 0;
}

char* EbrGetcwd(char* buf, size_t len) {
    strncpy_s(buf, len, CPathMapper::currentDir, len);
    return buf;
}

int EbrChdir(const char* path) {
    CPathMapper::setCWD(path);

    return 0;
}

int EbrChmod(const char* path, int mode) {
    return _chmod(CPathMapper(path), mode);
}

#define PATH_SEPARATOR "/"

bool EbrRemove(const char* path) {
    struct stat s;
    if (EbrStat(path, &s) == 0) {
        if (s.st_mode & S_IFREG) {
            if (EbrUnlink(path)) {
                return true;
            } else {
                TraceError(TAG, L"Failed to unlink file %hs", path);
                return false;
            }
        } else if (s.st_mode & S_IFDIR) {
            EbrDir* dir = EbrOpenDir(path);
            if (dir) {
                EbrDirEnt ent;
                while (EbrReadDir(dir, &ent)) {
                    if (strcmp(ent.fileName, ".") == 0 || strcmp(ent.fileName, "..") == 0) {
                        continue;
                    }

                    char fullPath[4096]; // max path?
                    sprintf_s(fullPath, sizeof(fullPath), "%s%s%s", path, PATH_SEPARATOR, ent.fileName);
                    if (!EbrRemove(fullPath)) {
                        EbrCloseDir(dir);
                        return false;
                    }
                }
                EbrCloseDir(dir);
            }

            return EbrRemoveEmptyDir(path);
        } else {
            TraceVerbose(TAG, L"Unrecognized file type: %d", s.st_mode);
            return false;
        }
    }
    return false;
}