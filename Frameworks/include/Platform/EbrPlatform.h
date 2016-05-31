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
#include <StarboardExport.h>

struct EbrTimeval {
    unsigned __int64 tv_sec; /* seconds since Jan. 1, 1970 */
    unsigned int tv_usec; /* and microseconds */
};

enum EbrFileType { EbrFileTypeUnknown, EbrFileTypeIO, EbrFileTypeSocket, EbrFileTypeVirtual, EbrFileTypeZipAsset };

class SB_EXPORT_CLASS EbrFile {
public:
    int idx;
    EbrFileType type;

    EbrFile();
    virtual ~EbrFile();

    virtual int Close();
    virtual size_t Read(void* dest, size_t elem, size_t count);
    virtual size_t Write(const void* dest, size_t elem, size_t count);
    virtual int Seek(long offset, int origin);
    virtual int Seek64(__int64 offset, int origin);
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
    virtual int Lseek(__int64 pos, int whence);
    virtual int Truncate(off_t size);
    virtual int Truncate64(__int64 size);
    virtual int Dup();

    virtual void* Mmap(void* addr, size_t size, uint32_t prot, uint32_t flags, uint32_t offset);
    virtual int Munmap(void* addr, size_t size);
};

SB_EXPORT EbrFile* EbrAllocFile(EbrFile* ioInterface);
SB_EXPORT void EbrFreeFile(EbrFile* pFile);
SB_EXPORT EbrFile* EbrFileFromFd(int fd);
SB_EXPORT EbrFileType EbrFileGetType(EbrFile* pFile);

struct stat;

SB_EXPORT EbrFile* EbrFmake(FILE* fp);
SB_EXPORT EbrFile* EbrFopen(const char* filename, const char* mode);
SB_EXPORT EbrFile* EbrFdopen(int handle, const char* mode);
SB_EXPORT int EbrFclose(EbrFile* file);
SB_EXPORT size_t EbrFread(void* dest, size_t elem, size_t count, EbrFile* file);
SB_EXPORT size_t EbrFwrite(const void* dest, size_t elem, size_t count, EbrFile* file);
SB_EXPORT int EbrFseek(EbrFile* fp, long offset, int origin);
SB_EXPORT int EbrFseek64(EbrFile* fp, __int64 offset, int origin);
SB_EXPORT size_t EbrFtell(EbrFile* fp);
SB_EXPORT int EbrFeof(EbrFile* fp);
SB_EXPORT int EbrStat(const char* filename, struct stat* ret);
SB_EXPORT int EbrFputc(int c, EbrFile* fp);
SB_EXPORT int EbrAccess(const char* file, int mode);
SB_EXPORT int EbrRewind(EbrFile* fp);
SB_EXPORT int EbrFerror(EbrFile* fp);
SB_EXPORT int EbrFgetc(EbrFile* fp);
SB_EXPORT int EbrUngetc(int val, EbrFile* fp);
SB_EXPORT char* EbrFgets(char* dest, size_t size, EbrFile* fp);
SB_EXPORT int EbrFputs(const char* str, EbrFile* fp);
SB_EXPORT int EbrFileno(EbrFile* fp);
SB_EXPORT FILE* EbrNativeFILE(EbrFile* fp);
SB_EXPORT void EbrClearerr(EbrFile* fp);
SB_EXPORT EbrFile* EbrFreopen(const char* filename, const char* mode, EbrFile* cur);
SB_EXPORT int EbrFflush(EbrFile* fp);
SB_EXPORT int EbrFsetpos(EbrFile* fp, __int64* pos);
SB_EXPORT int EbrFgetpos(EbrFile* fp, __int64* pos);

SB_EXPORT int EbrOpen(const char* file, int mode, int share);
SB_EXPORT int EbrOpenWithPermission(const char* file, int mode, int share, int pmode);
SB_EXPORT int EbrClose(int fd);
SB_EXPORT int EbrFd2Host(int fd);
SB_EXPORT int EbrFstat(int fd, struct stat* ret);
SB_EXPORT int EbrRead(int fd, void* dest, size_t count);
SB_EXPORT int EbrWrite(int fd, const void* src, size_t count);
SB_EXPORT int EbrLseek(int fd, __int64 pos, int whence);
SB_EXPORT int EbrTruncate(int fd, off_t size);
SB_EXPORT int EbrTruncate64(int fd, __int64 size);
SB_EXPORT int EbrDup(int fd);

SB_EXPORT bool EbrRename(const char* path1, const char* path2);
SB_EXPORT bool EbrUnlink(const char* path);
SB_EXPORT bool EbrMkdir(const char* path);
SB_EXPORT char* EbrGetcwd(char* buf, size_t len);
SB_EXPORT int EbrChdir(const char* path);

// Remove an item at this path, be it a file or directory:
SB_EXPORT bool EbrRemove(const char* path);
SB_EXPORT bool EbrRemoveEmptyDir(const char* path);

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

SB_EXPORT bool EbrIsDir(const char* path);
SB_EXPORT EbrDir* EbrOpenDir(const char* path);
SB_EXPORT bool EbrReadDir(EbrDir* pDir, EbrDirEnt* ent);
SB_EXPORT void EbrCloseDir(EbrDir* pDir);

SB_EXPORT int EbrGetTimeOfDay(struct EbrTimeval* curtime);
SB_EXPORT double EbrGetMediaTime();
SB_EXPORT int EbrGetWantedOrientation();

//  maxLen should be MAX_PATH.  Sorry Jordan.
SB_EXPORT bool EbrGetRootMapping(const char* dirName, char* dirOut, uint32_t maxLen);
SB_EXPORT const char* EbrGetWritableFolder();
SB_EXPORT void EbrSetWritableFolder(const char* folder);

SB_EXPORT void EbrBlockIfBackground();

typedef void* EbrEvent;

SB_EXPORT void EbrEventInit(EbrEvent* pEvent);
SB_EXPORT void EbrEventSignal(EbrEvent event);
SB_EXPORT void EbrEventWait(EbrEvent event);
SB_EXPORT bool EbrEventTryWait(EbrEvent event);
SB_EXPORT bool EbrEventTimedWait(EbrEvent event, double seconds);

typedef struct {
    int WakeupSocketRead, WakeupSocketWrite;
    void *fdread, *fdwrite, *fderror;
    int max, result;
} SocketWait;

SB_EXPORT int EbrEventTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets);
SB_EXPORT void EbrEventDestroy(EbrEvent event);

#endif
