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

#include <io.h>
#include <stdio.h>

#include "EbrFile.h"

class EbrIOFile : public EbrFile {
public:

    EbrIOFile(int fid);
    virtual ~EbrIOFile();

    virtual int Read(void* dest, size_t count) override;
    virtual int Write(const void* dest, size_t count) override;

    virtual int Stat(struct stat* ret) override;
    virtual int Stat64i32(struct _stat64i32* ret) override;

    virtual __int64 Lseek(__int64 pos, int whence) override;
    virtual intptr_t GetOSFHandle() override;

    virtual __int64 Tell() override;
    virtual int Flush() override;
    virtual int Truncate64(__int64 size) override;

    static std::shared_ptr<EbrFile> CreateInstance(const char* path, int mode, int share, int pmode);

private:
    int m_fid;
};