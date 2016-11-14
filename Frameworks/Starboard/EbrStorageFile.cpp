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

#include "EbrStorageFile.h"
#include "ErrorHandling.h"

#include "StringHelpers.h"
#include "WRLHelpers.h"

#include "RawBuffer.h"

#include <vector>
#include <fcntl.h>

using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace WRLHelpers;
using namespace ABI::Windows::Storage;
using namespace ABI::Windows::Storage::AccessCache;
using namespace ABI::Windows::Storage::FileProperties;
using namespace ABI::Windows::Storage::Streams;

std::shared_ptr<EbrFile> EbrStorageFile::CreateInstance(const char* path, int mode, int share, int pmode) {
    // Check to see if this path is a file id path.
    static const std::string c_fileIdPreamble = "/.file/id=";
    
    if ((path == nullptr) || (0 != strncmp(path, c_fileIdPreamble.c_str() , c_fileIdPreamble.length()))) {
        // Don't use a wil macro here since these are necessarily failure conditions worth logging. Normal files
        // are tried down this path too and are expected to fail.
        return nullptr;
    }

    Wrappers::HString idHString = Strings::NarrowToWide<HSTRING>(&path[c_fileIdPreamble.length()]);

    ComPtr<IStorageApplicationPermissionsStatics> storageApplicationPermissionsStatics;
    RETURN_NULL_IF_FAILED(
        GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Storage_AccessCache_StorageApplicationPermissions).Get(),
                             &storageApplicationPermissionsStatics));

    ComPtr<IStorageItemAccessList> accessList;
    RETURN_NULL_IF_FAILED(storageApplicationPermissionsStatics->get_FutureAccessList(&accessList));

    // Try to grab the item based on id.
    ComPtr<IStorageFile> storageFile;
    RETURN_NULL_IF_FAILED(AwaitResult(accessList, &IStorageItemAccessList::GetFileAsync, idHString.Get(), &storageFile));

    bool shouldAllowWrite = ((mode & _O_WRONLY) != 0) ||
                            ((mode & _O_RDWR) != 0);
    
    FileAccessMode openMode = shouldAllowWrite ? FileAccessMode_ReadWrite : FileAccessMode_Read;

    ComPtr<IRandomAccessStream> randomAccessStream;
    RETURN_NULL_IF_FAILED(AwaitResult(storageFile, &IStorageFile::OpenAsync, openMode, &randomAccessStream));

    bool shouldAppend = ((mode & _O_APPEND) != 0);

    return std::make_shared<EbrStorageFile>(
        std::move(storageFile),
        std::move(randomAccessStream),
        shouldAppend,
        shouldAllowWrite);
}

EbrStorageFile::EbrStorageFile(
        ComPtr<IStorageFile>&& storageFile, 
        ComPtr<IRandomAccessStream>&& randomAccessStream,
        bool shouldAppend,
        bool shouldAllowWrite) : 
            m_storageFile(storageFile), 
            m_randomAccessStream(randomAccessStream), 
            m_shouldAppend(shouldAppend), 
            m_shouldAllowWrite(shouldAllowWrite) {

    if (shouldAppend) {
        Lseek(0, SEEK_END);
    }
}

__int64 EbrStorageFile::Tell() {
    return Lseek(0, SEEK_CUR);
}

int EbrStorageFile::Flush() {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    unsigned long long currentPosition{};
    if (FAILED(m_randomAccessStream->get_Position(&currentPosition))) {
        return -1;
    }

    ComPtr<IOutputStream> outStream;
    if (FAILED(m_randomAccessStream->GetOutputStreamAt(currentPosition, &outStream))) {
        return -1;
    }

    boolean success = false;
    if (FAILED(AwaitResult(outStream, &IOutputStream::FlushAsync, &success))) {
        return -1;
    }

    return success ? 0 : -1;
}

int EbrStorageFile::Stat(struct stat* ret) {
    return _StatInternal(ret);
}

int EbrStorageFile::Stat64i32(struct _stat64i32* ret) {
    return _StatInternal(ret);
}

template<typename T> 
int EbrStorageFile::_StatInternal(T* ret) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    if (!ret) {
        return -1;
    }

    T toReturn{};

    ComPtr<IStorageItem> storageItem;
    if (FAILED(m_storageFile.As(&storageItem))) {
        return -1;
    }

    ComPtr<IBasicProperties> basicProperties;
    if (FAILED(AwaitResult(storageItem, &IStorageItem::GetBasicPropertiesAsync, &basicProperties))) {
        return -1;
    }

    unsigned long long size{};
    if (FAILED(basicProperties->get_Size(&size))) {
        return -1;
    }

    toReturn.st_size = (decltype(toReturn.st_size))size;

    // Just assume its a regular file.
    toReturn.st_mode = S_IFREG;

    *ret = toReturn;

    return 0;
}

intptr_t EbrStorageFile::GetOSFHandle() {
    return -1;
}

int EbrStorageFile::Read(void* dest, size_t count) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    if (!dest) {
        return -1;
    }

    unsigned long long currentPosition{};
    if (FAILED(m_randomAccessStream->get_Position(&currentPosition))) {
        return -1;
    }

    ComPtr<IInputStream> inStream;
    if (FAILED(m_randomAccessStream->GetInputStreamAt(currentPosition, &inStream))) {
        return -1;
    }

    std::vector<unsigned char> buffer(count);
    ComPtr<IBuffer> rawDataBuffer;
    if (FAILED(BufferFromRawData(&rawDataBuffer, buffer.data(), buffer.size()))) {
        return -1;
    }

    ComPtr<IBuffer> dataRead;
    if (FAILED(AwaitProgressComplete(inStream, &IInputStream::ReadAsync, rawDataBuffer.Get(), buffer.size(), InputStreamOptions_None, &dataRead))) {
        return -1;
    }

    unsigned int length{};
    if (FAILED(dataRead->get_Length(&length))) {
        return -1;
    }

    ComPtr<IBufferByteAccess> byteAccess;
    if (FAILED(dataRead.As(&byteAccess))) {
        return -1;
    }

    unsigned char* rawBytes = nullptr;
    if (FAILED(byteAccess->Buffer(&rawBytes))) {
        return -1;
    }

    // copy over bytes into the buffer.
    if (0 != memcpy_s(dest, count, rawBytes, length)) {
        return -1;
    }

    // move forward the position to account for the read.
    if (FAILED(m_randomAccessStream->Seek(length + currentPosition))) {
        return -1;
    }

    return (int)length;
}

int EbrStorageFile::Write(const void* src, size_t count) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    if (!m_shouldAllowWrite || !src) {
        return -1;
    }

    if (count == 0) {
        // Well that sure was easy.
        return 0;
    }

    unsigned long long currentPosition{};
    if (FAILED(m_randomAccessStream->get_Position(&currentPosition))) {
        return -1;
    }

    unsigned long long positionToOpen{};

    if (m_shouldAppend) {
        if (FAILED(m_randomAccessStream->get_Size(&positionToOpen))) {
            return -1;
        }
    } else {
        positionToOpen = currentPosition;
    }

    ComPtr<IOutputStream> outStream;
    if (FAILED(m_randomAccessStream->GetOutputStreamAt(positionToOpen, &outStream))) {
        return -1;
    }

    ComPtr<IBuffer> dataToWrite;
    if (FAILED(BufferFromRawData(&dataToWrite, (unsigned char*)src, count))) {
        return -1;
    }

    UINT32 result{};
    if (FAILED(AwaitProgressComplete(outStream, &IOutputStream::WriteAsync, dataToWrite.Get(), &result))) {
        return -1;
    }

    // move forward the position to account for the write.
    if (FAILED(m_randomAccessStream->Seek(result + currentPosition))) {
        return -1;
    }

    return (int)result;
}

__int64 EbrStorageFile::Lseek(__int64 pos, int whence) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);

    unsigned long long newPosition {};

    switch (whence) {
        case SEEK_CUR:
        {
            unsigned long long currentPosition{};
            if (FAILED(m_randomAccessStream->get_Position(&currentPosition))) {
                return -1;
            }

            newPosition = currentPosition + pos;
        }
            break;

        case SEEK_END:
        {
            unsigned long long size;
            if (FAILED(m_randomAccessStream->get_Size(&size))) {
                return -1;
            }

            if (pos > 0) {
                return -1;
            }

            newPosition = size + pos;
        }
            break;

        case SEEK_SET:
        default:
        {
            if (pos >= 0 ) {
                newPosition = (unsigned long long)(pos);
            } else {
                return -1;
            }
            break;
        }
    }

    if (FAILED(m_randomAccessStream->Seek(newPosition))) {
        return -1;
    }

    return (__int64)(newPosition);

}

int EbrStorageFile::Truncate64(__int64 size) {
    std::lock_guard<std::recursive_mutex> lock(m_lock);
    if (FAILED(m_randomAccessStream->put_Size(size))) {
        return -1;
    }

    return 0;
}