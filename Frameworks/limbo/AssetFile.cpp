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

#include <Windows.h>
#include <objbase.h>
#include <algorithm>
#include <map>
#include <sys/stat.h>
#include <direct.h>
#include <io.h>

#include "Starboard.h"
#include "Platform/EbrPlatform.h"
#include "AssetFile.h"
#include "PathMapper.h"

#define strtok_r strtok_s

char CPathMapper::currentDir[4096];

void appendPath(char* curpath, const char* path) {
    char copy[4096];

    strcpy_s(copy, path);

    char* save;
    char* curToken = strtok_r(copy, "/\\", &save);
    char* curpathEnd = curpath + strlen(curpath);
    while (curToken) {
        if (strlen(curToken) == 0) {
            curToken = strtok_r(NULL, "/\\", &save);
        }
        int tokenLen = strlen(curToken);
        if (strcmp(curToken, "~") == 0) {
            strcpy_s(curpath, 2048, "/home");
            curpathEnd = curpath + strlen(curpath);
        } else {
            strcat_s(curpathEnd, 2048, "/");
            curpathEnd++;
            strcat_s(curpathEnd, 2048, curToken);
            curpathEnd += tokenLen;
        }
        curToken = strtok_r(NULL, "/\\", &save);
    }
    if (strcmp(curpath, "") == 0)
        strcpy_s(curpath, 2048, "/");
}

static void EscapePath(char* dest, const char* src) {
    while (*dest)
        dest++;

    while (*src) {
        switch (*src) {
            case '?':
                *dest = '+';
                break;

            default:
                *dest = *src;
        }

        dest++;
        src++;
    }

    *dest = 0;
}

bool convertPath(char* filePath, const char* relativePath) {
    if (!EbrGetRootMapping(NULL, filePath, 4096))
        return false;
    int curComponent = 0;

    char copy[4096];

    strcpy_s(copy, relativePath);

    char* save;
    char* curToken = strtok_r(copy, "/", &save);
    char* filePathEnd = filePath + strlen(filePath);
    while (curToken) {
        if (strlen(curToken) == 0 || strcmp(curToken, ".") == 0) {
            curToken = strtok_r(NULL, "/", &save);
            continue;
        }

        if (curComponent == 0) {
            if (!EbrGetRootMapping(curToken, filePath, 4096))
                return false;
            filePathEnd = filePath + strlen(filePath);
        } else {
            strcat_s(filePathEnd, 2048, "\\");
            filePathEnd++;
            EscapePath(filePathEnd, curToken);
            filePathEnd += strlen(curToken);
        }
        curComponent++;

        curToken = strtok_r(NULL, "/\\", &save);
    }

    if (strcmp(filePath, "") == 0)
        return false;

    return true;
}

bool fixPath(char* outPath, const char* relativePath) {
    strcpy_s(outPath, 2048, "");
    int curComponent = 0;

    if (relativePath[0] != '/')
        return false;

    char copy[4096];

    strcpy_s(copy, relativePath);

    char* save;
    char* curToken = strtok_r(copy, "/", &save);
    char* outPathEnd = outPath + strlen(outPath);
    while (curToken) {
        if (strlen(curToken) == 0 || strcmp(curToken, ".") == 0) {
            curToken = strtok_r(NULL, "/", &save);
            continue;
        }
        if (strcmp(curToken, "..") == 0) {
            if (curComponent == 0) {
                return false;
            }
            //  Move back one directory
            char* curPos = outPath + strlen(outPath);
            while (curPos >= outPath) {
                if (*curPos == '/') {
                    *curPos = 0;
                    break;
                }
                curPos--;
            }
            //  Impossible!
            if (curPos < outPath) {
                return false;
            }
            if (curPos == outPath) {
                strcpy_s(outPath, 2048, "/");
            }
            curComponent--;
            curToken = strtok_r(NULL, "/", &save);
            outPathEnd = outPath + strlen(outPath);
            continue;
        }

        strcat_s(outPathEnd, 2048, "/");
        outPathEnd++;
        strcat_s(outPathEnd, 2048, curToken);
        outPathEnd += strlen(curToken);
        curComponent++;

        curToken = strtok_r(NULL, "/", &save);
    }
    if (strcmp(outPath, "") == 0) {
        strcpy_s(outPath, 2048, "/");
    }

    return true;
}

char* CPathMapper::FixedPath() {
    if (fixedValid)
        return fixedPath;
    return NULL;
}

char* CPathMapper::MappedPath() {
    if (fixedValid && mappedValid)
        return mappedPath;
    return NULL;
}

CPathMapper::CPathMapper(const char* path) {
    char relativePath[4096];
    strcpy_s(relativePath, "");

    if (path[0] != '/') {
        appendPath(relativePath, currentDir);
    }
    appendPath(relativePath, path);
    fixedValid = fixPath(fixedPath, relativePath);
    mappedValid = convertPath(mappedPath, fixedPath);
}

void ScanAssets() {
}

struct EbrDir {
    EbrDirReader* curReader;
};

class EbrFSDirReader : public EbrDirReader {
public:
    char path[4096];
    char startPath[4096];
    HANDLE findHandle;
    WIN32_FIND_DATAW data;
    bool isFirst;

    static EbrDirReader* open(const char* path);
    virtual ~EbrFSDirReader();
    virtual bool readNext(EbrDir* curDir, EbrDirEnt* end);
};

EbrDirReader* EbrFSDirReader::open(const char* path) {
    CPathMapper map(path);
    if (!map.MappedPath())
        return NULL;

    EbrFSDirReader* ret = new EbrFSDirReader();
    sprintf_s(ret->path, "%s\\*", (const char*)CPathMapper(path));
    strcpy_s(ret->startPath, path);
    std::wstring widePath(ret->path, ret->path + strlen(ret->path));
    ret->findHandle = FindFirstFileExW(widePath.c_str(), FindExInfoStandard, &ret->data, FindExSearchNameMatch, NULL, 0);
    if (!ret->findHandle || ret->findHandle == INVALID_HANDLE_VALUE) {
        delete ret;
        return NULL;
    }
    ret->isFirst = true;

    return ret;
}

EbrFSDirReader::~EbrFSDirReader() {
    if (findHandle) {
        FindClose(findHandle);
    }
}

bool EbrFSDirReader::readNext(EbrDir* curDir, EbrDirEnt* ent) {
    if (isFirst) {
        isFirst = false;
    } else {
        if (!FindNextFileW(findHandle, &data))
            return false;
    }

    // Note that we're doing wcslen here, which is number of characters. If we've got continues
    // in the stream then we may truncate the buffer.
    std::string conv(data.cFileName, data.cFileName + wcslen(data.cFileName));
    strcpy_s(ent->fileName, conv.c_str());
    char tmpPath[4096];
    strcpy_s(tmpPath, startPath);
    strcat_s(tmpPath, "//");
    strcat_s(tmpPath, conv.c_str());
    ent->isDir = (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
    return true;
}

EbrDir* EbrOpenDir(const char* path) {
    CPathMapper map(path);
    char* fixedName = map.FixedPath();
    if (!fixedName) {
        return NULL;
    }

    if (!map.MappedPath())
        return NULL;

    EbrDirReader* fsReader = EbrFSDirReader::open(fixedName);
    if (!fsReader) {
        return NULL;
    }

    // Read it as a regular FS directory:
    EbrDir* dirRet = new EbrDir;
    dirRet->curReader = fsReader;

    return dirRet;
}

bool EbrReadDir(EbrDir* pDir, EbrDirEnt* ent) {
    return pDir->curReader->readNext(pDir, ent);
}

void EbrCloseDir(EbrDir* pDir) {
    delete pDir->curReader;
    delete pDir;
}

bool EbrIsDir(const char* path) {
    CPathMapper map(path);
    char* fixedName = map.FixedPath();
    if (!fixedName) {
        return NULL;
    }

    std::wstring unicodePath(map.MappedPath(), map.MappedPath() + strlen(map.MappedPath()));
    WIN32_FILE_ATTRIBUTE_DATA fileAttribData;
    if (GetFileAttributesExW(unicodePath.c_str(), GetFileExInfoStandard, &fileAttribData)) {
        if ((fileAttribData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
            return true;
    }
    return false;
}

int EbrStat(const char* filename, struct stat* ret) {
    CPathMapper map(filename);
    char* fixedName = map.FixedPath();
    if (!fixedName) {
        return -1;
    }

    char* assetName = fixedName + 1;

    if (EbrIsDir(filename)) {
        memset(ret, 0, sizeof(struct stat));
        ret->st_size = 0;
        ret->st_mode = 0x1B6 | 0040000;
        // MurmurHash3_x86_32(assetName, strlen(assetName), 0, &ret->st_ino);
        return 0;
    }

    if (!map.MappedPath()) {
        EbrDebugLog("OH GOD WHY EbrStat failure!\n");
        return -1;
    }

    return stat(map.MappedPath(), ret);
}

int EbrAccess(const char* file, int mode) {
    CPathMapper map(file);
    char* fixedName = map.FixedPath();
    if (!fixedName) {
        return -1;
    }

    if (!map.MappedPath())
        return -1;

    return _access(map.MappedPath(), mode);
}
