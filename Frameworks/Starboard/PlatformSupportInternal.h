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

enum EbrFileType { EbrFileTypeUnknown, EbrFileTypeIO, EbrFileTypeSocket, EbrFileTypeVirtual, EbrFileTypeZipAsset };

class EbrFile {
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
    virtual int Stat64i32(struct _stat64i32* ret);
    virtual int Read(void* dest, size_t count);
    virtual int Write(const void* src, size_t count);
    virtual int Lseek(__int64 pos, int whence);
    virtual int Truncate(off_t size);
    virtual int Truncate64(__int64 size);
    virtual int Dup();

    virtual void* Mmap(void* addr, size_t size, uint32_t prot, uint32_t flags, uint32_t offset);
    virtual int Munmap(void* addr, size_t size);

    virtual intptr_t GetOSFHandle();
};

EbrFile* EbrAllocFile(EbrFile* ioInterface);
void EbrFreeFile(EbrFile* pFile);
EbrFile* EbrFileFromFd(int fd);
EbrFileType EbrFileGetType(EbrFile* pFile);

EbrFile* EbrFmake(FILE* fp);
EbrFile* EbrFopen(const char* filename, const char* mode);
EbrFile* EbrFdopen(int handle, const char* mode);
int EbrFclose(EbrFile* file);
size_t EbrFread(void* dest, size_t elem, size_t count, EbrFile* file);
size_t EbrFwrite(const void* dest, size_t elem, size_t count, EbrFile* file);
int EbrFseek(EbrFile* fp, long offset, int origin);
int EbrFseek64(EbrFile* fp, __int64 offset, int origin);
size_t EbrFtell(EbrFile* fp);
int EbrFeof(EbrFile* fp);

int EbrFputc(int c, EbrFile* fp);
int EbrRewind(EbrFile* fp);
int EbrFerror(EbrFile* fp);
int EbrFgetc(EbrFile* fp);
int EbrUngetc(int val, EbrFile* fp);
char* EbrFgets(char* dest, size_t size, EbrFile* fp);
int EbrFputs(const char* str, EbrFile* fp);
int EbrFileno(EbrFile* fp);
FILE* EbrNativeFILE(EbrFile* fp);
void EbrClearerr(EbrFile* fp);
EbrFile* EbrFreopen(const char* filename, const char* mode, EbrFile* cur);

int EbrFsetpos(EbrFile* fp, __int64* pos);
int EbrFgetpos(EbrFile* fp, __int64* pos);