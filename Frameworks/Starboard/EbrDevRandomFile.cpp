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

#include "EbrDevRandomFile.h"

std::shared_ptr<EbrFile> EbrDevRandomFile::CreateInstance(const char* path, int mode, int share, int pmode) {
    static const char c_devRandomPath[] = "/dev/urandom";
    if (strncmp(path, c_devRandomPath, _countof(c_devRandomPath)) == 0) {
        return std::make_shared<EbrDevRandomFile>();
    }
    return nullptr;
}

EbrDevRandomFile::EbrDevRandomFile() {
}

int EbrDevRandomFile::Stat(struct stat* ret) {
    memset(ret, 0, sizeof(struct stat));
    return 0;
}

int EbrDevRandomFile::Stat64i32(struct _stat64i32* ret) {
    memset(ret, 0, sizeof(struct _stat64i32));
    return 0;
}

int EbrDevRandomFile::Read(void*, size_t) {
    return -1;
}

int EbrDevRandomFile::Write(const void* , size_t ) {
    return -1;
}

__int64 EbrDevRandomFile::Lseek(__int64 , int ) {
    return -1;
}

intptr_t EbrDevRandomFile::GetOSFHandle() {
    return (intptr_t)INVALID_HANDLE_VALUE;
}

__int64 EbrDevRandomFile::Tell() {
    return -1;
}

int EbrDevRandomFile::Flush() {
    return -1;
}

int EbrDevRandomFile::Truncate64(__int64) {
    return -1;
}

