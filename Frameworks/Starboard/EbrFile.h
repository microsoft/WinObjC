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
#pragma once

#include <Windows.h>
#include <stdint.h>
#include <mutex>
#include <memory>
#include <map>

class EbrFile {
public:
    virtual int Read(void* dest, size_t count) = 0;
    virtual int Write(const void* dest, size_t count) = 0;

    virtual int Stat(struct stat* ret) = 0;
    virtual int Stat64i32(struct _stat64i32* ret) = 0;

    virtual __int64 Lseek(__int64 pos, int whence) = 0;
    virtual intptr_t GetOSFHandle() = 0;

    virtual __int64 Tell() = 0;
    virtual int Flush() = 0;
    virtual int Truncate64(__int64 size) = 0;

    static std::shared_ptr<EbrFile> GetFile(int fid);
    static int AddFile(std::shared_ptr<EbrFile>&& file);
    static void RemoveFile(int fid);

private:
    static std::mutex s_fileMapLock;
    static std::map<int, std::shared_ptr<EbrFile>> s_fileMap;
    static int s_maxFileId;
};