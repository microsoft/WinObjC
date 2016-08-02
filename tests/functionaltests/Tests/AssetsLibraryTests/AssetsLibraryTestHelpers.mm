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
#import <UWP/WindowsStorage.h>

static bool copyFileToPicturesLibrary(NSString* fullPathToFile, NSString* fileName) {
    __block bool success = YES;

    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    void (^onFailure)(NSError*) = ^(NSError* error) {
        LOG_ERROR([[error description] UTF8String]);
        success = NO;
        dispatch_group_leave(group);
    };

    // Get StorageFile reference for file in local folder
    [WSStorageFile getFileFromPathAsync:fullPathToFile
        success:^void(WSStorageFile* storageFile) {
            // Get StorageFolder for Picture Library known folder
            [WSStorageLibrary getLibraryAsync:WSKnownLibraryIdPictures
                success:^void(WSStorageLibrary* picturesLibrary) {
                    [picturesLibrary.saveFolder tryGetItemAsync:fileName
                        success:^void(RTObject<WSIStorageItem>* storageItem) {
                            if (storageItem == nil) {
                                [storageFile copyOverloadDefaultNameAndOptions:picturesLibrary.saveFolder
                                    success:^void(WSStorageFile* storageFile) {
                                        dispatch_group_leave(group);
                                    }
                                    failure:onFailure];
                            } else {
                                dispatch_group_leave(group);
                            }
                        }
                        failure:onFailure];
                }
                failure:onFailure];
        }
        failure:onFailure];

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
    __block bool success = YES;
    NSString* fileName = [NSString stringWithUTF8String:fileNameTemp];

    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    void (^onFailure)(NSError*) = ^(NSError* error) {
        LOG_ERROR([[error description] UTF8String]);
        success = NO;
        dispatch_group_leave(group);
    };

    [WSStorageLibrary getLibraryAsync:WSKnownLibraryIdPictures
        success:^void(WSStorageLibrary* picturesLibrary) {
            [picturesLibrary.saveFolder getFileAsync:fileName
                success:^void(WSStorageFile* storageFile) {
                    // Delete permantently so the Recycle Bin doesn't get filled up
                    [storageFile deleteAsync:WSStorageDeleteOptionPermanentDelete];
                    dispatch_group_leave(group);
                }
                failure:onFailure];
        }
        failure:onFailure];

    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    dispatch_release(group);

    return success;
}
