//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <AssetsLibrary/AssetsLibraryExport.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/NSObject.h>

@class ALAssetsGroup;
@class ALAsset;
@class NSURL;
@class NSError;
@class NSString;
@class NSData;
@class NSDictionary;

typedef NSUInteger ALAssetsGroupType;
typedef void (^ALAssetsLibraryGroupsEnumerationResultsBlock)(ALAssetsGroup* group, BOOL* stop);
typedef void (^ALAssetsLibraryAssetForURLResultBlock)(ALAsset* asset);
typedef void (^ALAssetsLibraryWriteImageCompletionBlock)(NSURL* assetURL, NSError* error);
typedef void (^ALAssetsLibraryWriteVideoCompletionBlock)(NSURL* assetURL, NSError* error);
typedef void (^ALAssetsLibraryAccessFailureBlock)(NSError* error);
typedef void (^ALAssetsLibraryGroupResultBlock)(ALAssetsGroup* group);
typedef enum {
    ALAssetOrientationUp,
    ALAssetOrientationDown,
    ALAssetOrientationLeft,
    ALAssetOrientationRight,
    ALAssetOrientationUpMirrored,
    ALAssetOrientationDownMirrored,
    ALAssetOrientationLeftMirrored,
    ALAssetOrientationRightMirrored,
} ALAssetOrientation;
typedef NS_ENUM(NSInteger, ALAuthorizationStatus) {
    ALAuthorizationStatusNotDetermined = 0,
    ALAuthorizationStatusRestricted,
    ALAuthorizationStatusDenied,
    ALAuthorizationStatusAuthorized
};

enum {
    ALAssetsGroupLibrary = (1 << 0),
    ALAssetsGroupAlbum = (1 << 1),
    ALAssetsGroupEvent = (1 << 2),
    ALAssetsGroupFaces = (1 << 3),
    ALAssetsGroupSavedPhotos = (1 << 4),
    ALAssetsGroupPhotoStream = (1 << 5),
    ALAssetsGroupAll = 0xFFFFFFFF,
};

ASSETSLIBRARY_EXPORT NSString* const ALAssetLibraryUpdatedAssetsKey;
ASSETSLIBRARY_EXPORT NSString* const ALAssetLibraryInsertedAssetGroupsKey;
ASSETSLIBRARY_EXPORT NSString* const ALAssetLibraryUpdatedAssetGroupsKey;
ASSETSLIBRARY_EXPORT NSString* const ALAssetLibraryDeletedAssetGroupsKey;
ASSETSLIBRARY_EXPORT NSString* const ALAssetsLibraryErrorDomain;

enum {
    ALAssetsLibraryUnknownError = -1,
    ALAssetsLibraryWriteFailedError = -3300,
    ALAssetsLibraryWriteBusyError = -3301,
    ALAssetsLibraryWriteInvalidDataError = -3302,
    ALAssetsLibraryWriteIncompatibleDataError = -3303,
    ALAssetsLibraryWriteDataEncodingError = -3304,
    ALAssetsLibraryWriteDiskSpaceError = -3305,
    ALAssetsLibraryDataUnavailableError = -3310,
    ALAssetsLibraryAccessUserDeniedError = -3311,
    ALAssetsLibraryAccessGloballyDeniedError = -3312,
};

ASSETSLIBRARY_EXPORT_CLASS
@interface ALAssetsLibrary : NSObject <NSObject>
+ (ALAuthorizationStatus)authorizationStatus STUB_METHOD;
+ (void)disableSharedPhotoStreamsSupport STUB_METHOD;
- (void)assetForURL:(NSURL*)assetURL
        resultBlock:(ALAssetsLibraryAssetForURLResultBlock)resultBlock
       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock;
- (void)enumerateGroupsWithTypes:(ALAssetsGroupType)types
                      usingBlock:(ALAssetsLibraryGroupsEnumerationResultsBlock)enumerationBlock
                    failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock STUB_METHOD;
- (void)writeVideoAtPathToSavedPhotosAlbum:(NSURL*)videoPathURL
                           completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock STUB_METHOD;
- (BOOL)videoAtPathIsCompatibleWithSavedPhotosAlbum:(NSURL*)videoPathURL STUB_METHOD;
- (void)writeImageToSavedPhotosAlbum:(CGImageRef)imageRef
                         orientation:(ALAssetOrientation)orientation
                     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock STUB_METHOD;
- (void)writeImageDataToSavedPhotosAlbum:(NSData*)imageData
                                metadata:(NSDictionary*)metadata
                         completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock STUB_METHOD;
- (void)writeImageToSavedPhotosAlbum:(CGImageRef)imageRef
                            metadata:(NSDictionary*)metadata
                     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock STUB_METHOD;
- (void)addAssetsGroupAlbumWithName:(NSString*)name
                        resultBlock:(ALAssetsLibraryGroupResultBlock)resultBlock
                       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock STUB_METHOD;
- (void)groupForURL:(NSURL*)groupURL
        resultBlock:(ALAssetsLibraryGroupResultBlock)resultBlock
       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock STUB_METHOD;
@end
