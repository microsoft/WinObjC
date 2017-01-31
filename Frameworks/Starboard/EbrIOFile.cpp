//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include "EbrIOFile.h"
#include "PathMapper.h"

#include <sys\stat.h>

std::shared_ptr<EbrFile> EbrIOFile::CreateInstance(const char* path, int mode, int share, int pmode) {
    int fid{};
    int result = _wsopen_s(&fid, CPathMapper(path), mode, share, pmode);

    if (result != 0) {
        return nullptr;
    }

    return std::make_shared<EbrIOFile>(fid);
}

EbrIOFile::EbrIOFile(int fid) : m_fid(fid) {
}

EbrIOFile::~EbrIOFile() {
    if (m_fid != -1) {
        _close(m_fid);
    }
}

__int64 EbrIOFile::Tell() {
    return Lseek(0, SEEK_CUR);
}

int EbrIOFile::Flush() {
    if (0 == FlushFileBuffers((HANDLE)GetOSFHandle())) {
        return -1;
    }

    return 0;
}

int EbrIOFile::Stat(struct stat* ret) {
    return fstat(m_fid, ret);
}

int EbrIOFile::Stat64i32(struct _stat64i32* ret) {
    return _fstat64i32(m_fid, ret);
}

intptr_t EbrIOFile::GetOSFHandle() {
    return _get_osfhandle(m_fid);
}

int EbrIOFile::Read(void* dest, size_t count) {
    return _read(m_fid, dest, count);
}

int EbrIOFile::Write(const void* src, size_t count) {
    return _write(m_fid, src, count);
}

__int64 EbrIOFile::Lseek(__int64 pos, int whence) {
    return _lseeki64(m_fid, pos, whence);
}

int EbrIOFile::Truncate64(__int64 size) {
    return _chsize_s(m_fid, size);
}