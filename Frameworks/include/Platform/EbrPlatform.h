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

#ifndef __EBRPLATFORM_H
#define __EBRPLATFORM_H
#include <pthread.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include <MacTypes.h>

struct EbrTimeval {
    unsigned __int64 tv_sec; /* seconds since Jan. 1, 1970 */
    unsigned int tv_usec; /* and microseconds */
};

#ifndef IWPLATFORM_EXPORT
#define IWPLATFORM_EXPORT __declspec(dllimport)
#endif

enum EbrFileType { EbrFileTypeUnknown, EbrFileTypeIO, EbrFileTypeSocket, EbrFileTypeVirtual, EbrFileTypeZipAsset };

class IWPLATFORM_EXPORT EbrFile {
public:
    int idx;
    EbrFileType type;

    EbrFile();
    virtual ~EbrFile();

    virtual int Close();
    virtual size_t Read(void* dest, size_t elem, size_t count);
    virtual size_t Write(void* dest, size_t elem, size_t count);
    virtual int Seek(long offset, int origin);
    virtual size_t Tell();
    virtual int Eof();
    virtual int Putc(int c);
    virtual int Rewind();
    virtual int Error();
    virtual int Getc();
    virtual int Ungetc(int val);
    virtual char* Gets(char* dest, size_t size);
    virtual int Puts(const char* str);
    virtual void Clearerr();
    virtual int Flush();
    virtual int Setpos(__int64* pos);
    virtual int Getpos(__int64* pos);

    virtual int HostFd();
    virtual int Stat(struct stat* ret);
    virtual int Read(void* dest, size_t count);
    virtual int Write(const void* src, size_t count);
    virtual int Lseek(off_t pos, int whence);
    virtual int Truncate(off_t size);
    virtual int Dup();

    virtual void* Mmap(void* addr, size_t size, uint32_t prot, uint32_t flags, uint32_t offset);
    virtual int Munmap(void* addr, size_t size);
};

IWPLATFORM_EXPORT EbrFile* EbrAllocFile(EbrFile* ioInterface);
IWPLATFORM_EXPORT void EbrFreeFile(EbrFile* pFile);
IWPLATFORM_EXPORT EbrFile* EbrFileFromFd(int fd);
IWPLATFORM_EXPORT EbrFileType EbrFileGetType(EbrFile* pFile);

struct stat;

IWPLATFORM_EXPORT EbrFile* EbrFmake(FILE* fp);
IWPLATFORM_EXPORT EbrFile* EbrFopen(const char* filename, const char* mode);
IWPLATFORM_EXPORT EbrFile* EbrFdopen(int handle, const char* mode);
IWPLATFORM_EXPORT int EbrFclose(EbrFile* file);
IWPLATFORM_EXPORT size_t EbrFread(void* dest, size_t elem, size_t count, EbrFile* file);
IWPLATFORM_EXPORT size_t EbrFwrite(void* dest, size_t elem, size_t count, EbrFile* file);
IWPLATFORM_EXPORT int EbrFseek(EbrFile* fp, long offset, int origin);
IWPLATFORM_EXPORT size_t EbrFtell(EbrFile* fp);
IWPLATFORM_EXPORT int EbrFeof(EbrFile* fp);
IWPLATFORM_EXPORT int EbrStat(const char* filename, struct stat* ret);
IWPLATFORM_EXPORT int EbrFputc(int c, EbrFile* fp);
IWPLATFORM_EXPORT int EbrAccess(const char* file, int mode);
IWPLATFORM_EXPORT int EbrRewind(EbrFile* fp);
IWPLATFORM_EXPORT int EbrFerror(EbrFile* fp);
IWPLATFORM_EXPORT int EbrFgetc(EbrFile* fp);
IWPLATFORM_EXPORT int EbrUngetc(int val, EbrFile* fp);
IWPLATFORM_EXPORT char* EbrFgets(char* dest, size_t size, EbrFile* fp);
IWPLATFORM_EXPORT int EbrFputs(const char* str, EbrFile* fp);
IWPLATFORM_EXPORT int EbrFileno(EbrFile* fp);
IWPLATFORM_EXPORT FILE* EbrNativeFILE(EbrFile* fp);
IWPLATFORM_EXPORT void EbrClearerr(EbrFile* fp);
IWPLATFORM_EXPORT EbrFile* EbrFreopen(const char* filename, const char* mode, EbrFile* cur);
IWPLATFORM_EXPORT int EbrFflush(EbrFile* fp);
IWPLATFORM_EXPORT int EbrFsetpos(EbrFile* fp, __int64* pos);
IWPLATFORM_EXPORT int EbrFgetpos(EbrFile* fp, __int64* pos);

IWPLATFORM_EXPORT int EbrOpen(const char* file, int mode, int share);
IWPLATFORM_EXPORT int EbrClose(int fd);
IWPLATFORM_EXPORT int EbrFd2Host(int fd);
IWPLATFORM_EXPORT void* EbrFdGetPtr(int fd);
IWPLATFORM_EXPORT int EbrFstat(int fd, struct stat* ret);
IWPLATFORM_EXPORT int EbrRead(int fd, void* dest, size_t count);
IWPLATFORM_EXPORT int EbrWrite(int fd, const void* src, size_t count);
IWPLATFORM_EXPORT int EbrLseek(int fd, off_t pos, int whence);
IWPLATFORM_EXPORT int EbrTruncate(int fd, off_t size);
IWPLATFORM_EXPORT int EbrDup(int fd);

#define EBR_PAGE_READ 0x01
#define EBR_PAGE_WRITE 0x02
#define EBR_PAGE_EXECUTE 0x04

IWPLATFORM_EXPORT void* EbrMmap(void* addr, size_t size, uint32_t prot, uint32_t flags, int fd, uint32_t offset);
IWPLATFORM_EXPORT int EbrMunmap(void* addr, size_t size);

IWPLATFORM_EXPORT bool EbrRename(const char* path1, const char* path2);
IWPLATFORM_EXPORT bool EbrUnlink(const char* path);
IWPLATFORM_EXPORT bool EbrMkdir(const char* path);

IWPLATFORM_EXPORT char* EbrGetcwd(char* buf, size_t len);
IWPLATFORM_EXPORT int EbrChdir(const char* path);

// Remove an item at this path, be it a file or directory:
IWPLATFORM_EXPORT bool EbrRemove(const char* path);
IWPLATFORM_EXPORT bool EbrRemoveEmptyDir(const char* path);

struct _EbrDirEnt {
    char fileName[4096];
    bool isDir;
};

typedef struct _EbrDirEnt EbrDirEnt;

struct EbrDir;

class EbrDirReader {
public:
    virtual bool readNext(EbrDir* curDir, EbrDirEnt* end) = 0;
    virtual ~EbrDirReader() {
    }
};

IWPLATFORM_EXPORT bool EbrIsDir(const char* path);
IWPLATFORM_EXPORT EbrDir* EbrOpenDir(const char* path);
IWPLATFORM_EXPORT bool EbrReadDir(EbrDir* pDir, EbrDirEnt* ent);
IWPLATFORM_EXPORT void EbrCloseDir(EbrDir* pDir);

IWPLATFORM_EXPORT int EbrGetTimeOfDay(struct EbrTimeval* curtime);
IWPLATFORM_EXPORT double EbrGetMediaTime();
IWPLATFORM_EXPORT void EbrSetAPC(int signal, void (*func)(int));
IWPLATFORM_EXPORT void EbrCallAPC(pthread_t thread, int signal, int param);
IWPLATFORM_EXPORT void EbrPlatformInit();
IWPLATFORM_EXPORT int EbrGetWantedOrientation();
IWPLATFORM_EXPORT void EbrExitToBackground();

//  maxLen should be MAX_PATH.  Sorry Jordan.
IWPLATFORM_EXPORT bool EbrGetRootMapping(const char* dirName, char* dirOut, uint32_t maxLen);
IWPLATFORM_EXPORT const char* EbrGetWritableFolder();
IWPLATFORM_EXPORT void EbrSetWritableFolder(const char* folder);

IWPLATFORM_EXPORT void EbrPlatformCommonInit();

IWPLATFORM_EXPORT void EbrBlockIfBackground();
IWPLATFORM_EXPORT void EbrEnterBackground();
IWPLATFORM_EXPORT void EbrLeaveBackground();

IWPLATFORM_EXPORT void EbrSignalsSafe();
IWPLATFORM_EXPORT void EbrSignalsUnsafe();

typedef void* EbrEvent;

IWPLATFORM_EXPORT void EbrEventInit(EbrEvent* pEvent);
IWPLATFORM_EXPORT void EbrEventSignal(EbrEvent event);
IWPLATFORM_EXPORT void EbrEventWait(EbrEvent event);
IWPLATFORM_EXPORT bool EbrEventTryWait(EbrEvent event);
IWPLATFORM_EXPORT bool EbrEventTimedWait(EbrEvent event, double seconds);

IWPLATFORM_EXPORT void EbrRequestFrame();

typedef struct {
    int WakeupSocketRead, WakeupSocketWrite;
    void *fdread, *fdwrite, *fderror;
    int max, result;
} SocketWait;

IWPLATFORM_EXPORT int EbrEventTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets);
IWPLATFORM_EXPORT void EbrEventDestroy(EbrEvent event);
IWPLATFORM_EXPORT void EbrOpenURL(const char* url);
IWPLATFORM_EXPORT void EbrUUIDCreate128(void* dest);

typedef struct {
    const char* platformName;
    const char* manufacturer;
    const char* model;
    const char* deviceProductName;
    const char* serialNo;
    const char* carrier;
    const char* osVersion;
    int osVersionInt;
    int deviceResX, deviceResY;
    float devicePhysWidth, devicePhysHeight;
} EbrPlatformInfo;

IWPLATFORM_EXPORT EbrPlatformInfo* EbrGetDeviceInfo();

class TimingFunction {
public:
    double startTime;
    const char* pName;

    TimingFunction(const char* name) {
        pName = name;
        startTime = EbrGetMediaTime();
    }

    ~TimingFunction() {
        double endTime = EbrGetMediaTime();
        // printf("%s: %f ms\n", pName, (endTime - startTime) * 1000.0);
    }
};

IWPLATFORM_EXPORT void* EbrSystemMalloc(size_t sz);
IWPLATFORM_EXPORT void EbrSystemFree(void* ptr);

IWPLATFORM_EXPORT bool EbrIsBridgedClass(const char* name);
IWPLATFORM_EXPORT void EbrThrowFatal(int code, const char* errorFmt, ...);
IWPLATFORM_EXPORT void EbrThrowFatalWithTrace(int code, const char* backTrace, const char* errorFmt, ...);
IWPLATFORM_EXPORT void EbrThrowFatalWithStack(int code, const char* errorFmt, ...);

IWPLATFORM_EXPORT void EbrSetCurrentThreadName(const char* name);

IWPLATFORM_EXPORT void EbrThreadMakeBackgroundExecutable();

IWPLATFORM_EXPORT bool EbrGetRandomData(void* dest, int numBytes);

IWPLATFORM_EXPORT bool EbrUIAppStart();
#endif
