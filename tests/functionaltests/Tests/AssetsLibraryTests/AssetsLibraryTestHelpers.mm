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

#import "FunctionalTestHelpers.h"
#import <Starboard/SmartTypes.h>
#import <TestFramework.h>
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.Storage.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Storage;
namespace WF = winrt::Windows::Foundation;

static bool copyFileToPicturesLibrary(NSString* fullPathToFile, NSString* fileName) {
    bool success = false;

    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    // Get StorageFile reference for file in local folder
    WF::IAsyncOperation<StorageFile> async = StorageFile::GetFileFromPathAsync(objcwinrt::string(fullPathToFile));

    async.Completed(objcwinrt::callback([fileName, group, &success] (const WF::IAsyncOperation<StorageFile>& op, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            StorageFile storageFile = op.GetResults();

            // Get StorageFolder for Picture Library known folder
            WF::IAsyncOperation<StorageLibrary> async = StorageLibrary::GetLibraryAsync(KnownLibraryId::Pictures);

            async.Completed(objcwinrt::callback([fileName, group, storageFile, &success] (const WF::IAsyncOperation<StorageLibrary>& op, WF::AsyncStatus status) {
                if (status == WF::AsyncStatus::Completed) {
                    StorageLibrary picturesLibrary = op.GetResults();
                    WF::IAsyncOperation<IStorageItem> async = picturesLibrary.SaveFolder().TryGetItemAsync(objcwinrt::string(fileName));

                    async.Completed(objcwinrt::callback([group, storageFile, picturesLibrary, &success] (const WF::IAsyncOperation<IStorageItem>& op, WF::AsyncStatus status) {
                        if (status == WF::AsyncStatus::Completed) {
                            IStorageItem storageItem = op.GetResults();

                            if (!storageItem) {
                                WF::IAsyncOperation<StorageFile> async = storageFile.CopyAsync(picturesLibrary.SaveFolder());

                                async.Completed(objcwinrt::callback([group, &success] (const WF::IAsyncOperation<StorageFile>& op, WF::AsyncStatus status) {
                                    if (status == WF::AsyncStatus::Completed) {
                                        success = true;
                                    } else {
                                        LOG_ERROR("Failed to copy to pictures library: HRESULT = %x", op.ErrorCode());
                                    }

                                    dispatch_group_leave(group);
                                }));
                            } else {
                                dispatch_group_leave(group);
                            }
                        } else {
                            LOG_ERROR("Failed to get item from pictures library: HRESULT = %x", op.ErrorCode());
                            dispatch_group_leave(group);
                        }
                    }));
                } else {
                    LOG_ERROR("Failed to open pictures library: HRESULT = %x", op.ErrorCode());
                    dispatch_group_leave(group);
                }
            }));
        } else {
            LOG_ERROR("Failed to open local StorageFile: HRESULT = %x", op.ErrorCode());
            dispatch_group_leave(group);
        }
    }));

    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    dispatch_release(group);

    return success;
}

// Copy test video file over to the Picture library
bool AssetsLibraryTestVideoSetup(const char* fileNameTemp) {
    StrongId<NSString> fileName = [NSString stringWithUTF8String:fileNameTemp];
    StrongId<NSString> testFileFullPath = appendPathRelativeToFTModule([@"data" stringByAppendingPathComponent:fileName]);
    return copyFileToPicturesLibrary(testFileFullPath, fileName);
}

// Remove video file that was copied to the Picture library
bool AssetsLibraryTestVideoCleanup(const char* fileNameTemp) {
    bool success = false;
    NSString* fileName = [NSString stringWithUTF8String:fileNameTemp];

    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    WF::IAsyncOperation<StorageLibrary> async = StorageLibrary::GetLibraryAsync(KnownLibraryId::Pictures);

    async.Completed(objcwinrt::callback([group, fileName, &success] (const WF::IAsyncOperation<StorageLibrary>& op, WF::AsyncStatus status) {
        if (status == WF::AsyncStatus::Completed) {
            StorageLibrary picturesLibrary = op.GetResults();

            WF::IAsyncOperation<StorageFile> async = picturesLibrary.SaveFolder().GetFileAsync(objcwinrt::string(fileName));

            async.Completed(objcwinrt::callback([group, &success] (const WF::IAsyncOperation<StorageFile>& op, WF::AsyncStatus status) {
                if (status == WF::AsyncStatus::Completed) {
                    StorageFile storageFile = op.GetResults();
                    storageFile.DeleteAsync(StorageDeleteOption::PermanentDelete);
                    success = true;
                } else {
                    LOG_ERROR("Failed to get file from pictures library: HRESULT = %x", op.ErrorCode());
                }

                dispatch_group_leave(group);
            }));
        } else {
            LOG_ERROR("Failed to open pictures library: HRESULT = %x", op.ErrorCode());
            dispatch_group_leave(group);
        }
    }));

    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    dispatch_release(group);

    return success;
}
