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

// WindowsStoragePickers.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPFilePickerSelectedFilesArray, WSPFilePickerFileTypesOrderedMap, WSPFileExtensionVector, WSPFileOpenPicker, WSPFileSavePicker,
    WSPFolderPicker;
@protocol WSPIFileOpenPicker
, WSPIFileSavePicker, WSPIFolderPicker;

// Windows.Storage.Pickers.PickerViewMode
enum _WSPPickerViewMode {
    WSPPickerViewModeList = 0,
    WSPPickerViewModeThumbnail = 1,
};
typedef unsigned WSPPickerViewMode;

// Windows.Storage.Pickers.PickerLocationId
enum _WSPPickerLocationId {
    WSPPickerLocationIdDocumentsLibrary = 0,
    WSPPickerLocationIdComputerFolder = 1,
    WSPPickerLocationIdDesktop = 2,
    WSPPickerLocationIdDownloads = 3,
    WSPPickerLocationIdHomeGroup = 4,
    WSPPickerLocationIdMusicLibrary = 5,
    WSPPickerLocationIdPicturesLibrary = 6,
    WSPPickerLocationIdVideosLibrary = 7,
};
typedef unsigned WSPPickerLocationId;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsStorage.h"

// Windows.Storage.Pickers.FilePickerSelectedFilesArray
#ifndef __WSPFilePickerSelectedFilesArray_DEFINED__
#define __WSPFilePickerSelectedFilesArray_DEFINED__

WINRT_EXPORT
@interface WSPFilePickerSelectedFilesArray : RTObject
@property (readonly) unsigned size;
@end

#endif // __WSPFilePickerSelectedFilesArray_DEFINED__

// Windows.Storage.Pickers.FilePickerFileTypesOrderedMap
#ifndef __WSPFilePickerFileTypesOrderedMap_DEFINED__
#define __WSPFilePickerFileTypesOrderedMap_DEFINED__

WINRT_EXPORT
@interface WSPFilePickerFileTypesOrderedMap : RTObject
@property (readonly) unsigned size;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,Windows.Foundation.Collections.IVector`1<String>> type information
@end

#endif // __WSPFilePickerFileTypesOrderedMap_DEFINED__

// Windows.Storage.Pickers.FileExtensionVector
#ifndef __WSPFileExtensionVector_DEFINED__
#define __WSPFileExtensionVector_DEFINED__

WINRT_EXPORT
@interface WSPFileExtensionVector : RTObject
@property (readonly) unsigned size;
@end

#endif // __WSPFileExtensionVector_DEFINED__

// Windows.Storage.Pickers.FileOpenPicker
#ifndef __WSPFileOpenPicker_DEFINED__
#define __WSPFileOpenPicker_DEFINED__

WINRT_EXPORT
@interface WSPFileOpenPicker : RTObject
+ (instancetype)create ACTIVATOR;
@property WSPPickerViewMode viewMode;
@property WSPPickerLocationId suggestedStartLocation;
@property (copy) NSString* settingsIdentifier;
@property (copy) NSString* commitButtonText;
@property (readonly) id<NSFastEnumeration> /*String*/ fileTypeFilter;
- (void)pickSingleFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
- (void)pickMultipleFilesAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WSStorageFile*/))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSPFileOpenPicker_DEFINED__

// Windows.Storage.Pickers.FileSavePicker
#ifndef __WSPFileSavePicker_DEFINED__
#define __WSPFileSavePicker_DEFINED__

WINRT_EXPORT
@interface WSPFileSavePicker : RTObject
+ (instancetype)create ACTIVATOR;
@property WSPPickerLocationId suggestedStartLocation;
@property (copy) WSStorageFile* suggestedSaveFile;
@property (copy) NSString* suggestedFileName;
@property (copy) NSString* settingsIdentifier;
@property (copy) NSString* defaultFileExtension;
@property (copy) NSString* commitButtonText;
// Failed to generate property FileTypeChoices (Can't marshal
// Windows.Foundation.Collections.IMap`2<String,Windows.Foundation.Collections.IVector`1<String>>)
// Failed to generate member get_FileTypeChoices (Can't marshal
// Windows.Foundation.Collections.IMap`2<String,Windows.Foundation.Collections.IVector`1<String>>)
- (void)pickSaveFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSPFileSavePicker_DEFINED__

// Windows.Storage.Pickers.FolderPicker
#ifndef __WSPFolderPicker_DEFINED__
#define __WSPFolderPicker_DEFINED__

WINRT_EXPORT
@interface WSPFolderPicker : RTObject
+ (instancetype)create ACTIVATOR;
@property WSPPickerViewMode viewMode;
@property WSPPickerLocationId suggestedStartLocation;
@property (copy) NSString* settingsIdentifier;
@property (copy) NSString* commitButtonText;
@property (readonly) id<NSFastEnumeration> /*String*/ fileTypeFilter;
- (void)pickSingleFolderAsyncWithSuccess:(void (^)(WSStorageFolder*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSPFolderPicker_DEFINED__
