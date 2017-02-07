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

#include "Starboard.h"
#include "ErrorHandling.h"
#include "StringHelpers.h"
#include <sys/stat.h>

#include "AssetFile.h"
#include "PathMapper.h"

static const wchar_t* TAG = L"AssetFile";

struct EbrDir {
    EbrDirReader* curReader;
};

class EbrFSDirReader : public EbrDirReader {
public:
    std::wstring path;
    std::wstring startPath;
    HANDLE findHandle;
    WIN32_FIND_DATAW data;
    bool isFirst;

    static EbrDirReader* open(const std::wstring& path);
    virtual ~EbrFSDirReader();
    virtual bool readNext(EbrDir* curDir, EbrDirEnt* end);
};

EbrDirReader* EbrFSDirReader::open(const std::wstring& path) {
    EbrFSDirReader* ret = new EbrFSDirReader();
    ret->path = path + std::wstring(L"\\*");
    ret->startPath = path;

    ret->findHandle = FindFirstFileExW(ret->path.c_str(), FindExInfoStandard, &ret->data, FindExSearchNameMatch, NULL, 0);
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

    const std::string filename = Strings::WideToNarrow(std::wstring(data.cFileName));
    strcpy_s(ent->fileName, filename.c_str());
    ent->isDir = (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
    return true;
}

EbrDir* EbrOpenDir(const char* path) {
    CPathMapper map(path);

    if (!map) {
        return NULL;
    }

    EbrDirReader* fsReader = EbrFSDirReader::open(map.MappedPath());
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

static bool _EbrIsDir(const wchar_t* path) {
    WIN32_FILE_ATTRIBUTE_DATA fileAttribData;
    if (GetFileAttributesExW(path, GetFileExInfoStandard, &fileAttribData)) {
        if ((fileAttribData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY)
            return true;
    }
    return false;
}

bool EbrIsDir(const char* path) {
    CPathMapper map(path);

    if (!map) {
        return NULL;
    }

    return _EbrIsDir(map);
}

int EbrStat(const char* filename, struct stat* ret) {
#ifdef _USE_32BIT_TIME_T
    CPathMapper map(filename);
    if (!map) {
        TraceError(TAG, L"EbrStat failure!");
        return -1;
    }

    if (_EbrIsDir(map)) {
        memset(ret, 0, sizeof(struct stat));
        ret->st_size = 0;
        ret->st_mode = 0x1B6 | 0040000;
        return 0;
    }

    return _wstat32(map, reinterpret_cast<struct _stat32*>(ret));
#else
    // This is from stat.h, unfortunately, it doesn't define the wstat apis for non 32-bit time_t
    // essentially on our platform, EbrStat is same as EbrStat64i32.
    // keeping this #ifdef just in case.
    return EbrStat64i32(filename, reinterpret_cast<struct _stat64i32*>(ret));
#endif
}

int EbrStat64i32(const char* filename, struct _stat64i32* ret) {
    CPathMapper map(filename);
    if (!map) {
        TraceError(TAG, L"EbrStat failure!");
        return -1;
    }

    if (_EbrIsDir(map)) {
        memset(ret, 0, sizeof(struct _stat64i32));
        ret->st_size = 0;
        ret->st_mode = 0x1B6 | 0040000;
        return 0;
    }

    return _wstat64i32(map, ret);
}

int EbrAccess(const char* file, int mode) {
    CPathMapper map(file);

    if (!map)
        return -1;

    return _waccess(map, mode);
}
