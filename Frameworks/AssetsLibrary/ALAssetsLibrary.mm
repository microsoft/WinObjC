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

#import <Starboard.h>
#import <StubReturn.h>
#import "ALAssetInternal.h"
#import <AssetsLibrary/ALAssetsLibrary.h>

NSString* const ALAssetLibraryUpdatedAssetsKey = @"ALAssetLibraryUpdatedAssetsKey";
NSString* const ALAssetLibraryInsertedAssetGroupsKey = @"ALAssetLibraryInsertedAssetGroupsKey";
NSString* const ALAssetLibraryUpdatedAssetGroupsKey = @"ALAssetLibraryUpdatedAssetGroupsKey";
NSString* const ALAssetLibraryDeletedAssetGroupsKey = @"ALAssetLibraryDeletedAssetGroupsKey";
NSString* const ALAssetsLibraryErrorDomain = @"ALAssetsLibraryErrorDomain";

@implementation ALAssetsLibrary
/**
 @Status Stub
 @Notes
*/
+ (ALAuthorizationStatus)authorizationStatus {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)disableSharedPhotoStreamsSupport {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
 @Notes
*/
- (void)assetForURL:(NSURL*)assetURL
        resultBlock:(ALAssetsLibraryAssetForURLResultBlock)resultBlock
       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock {
    NSError* error;
    ALAsset* asset = [[[ALAsset alloc] _initWithURL:assetURL error:&error] autorelease];
    if (asset == nil) {
        failureBlock(error);
    } else {
        resultBlock(asset);
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateGroupsWithTypes:(ALAssetsGroupType)types
                      usingBlock:(ALAssetsLibraryGroupsEnumerationResultsBlock)enumerationBlock
                    failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeVideoAtPathToSavedPhotosAlbum:(NSURL*)videoPathURL completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)videoAtPathIsCompatibleWithSavedPhotosAlbum:(NSURL*)videoPathURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeImageToSavedPhotosAlbum:(CGImageRef)imageRef
                         orientation:(ALAssetOrientation)orientation
                     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeImageDataToSavedPhotosAlbum:(NSData*)imageData
                                metadata:(NSDictionary*)metadata
                         completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeImageToSavedPhotosAlbum:(CGImageRef)imageRef
                            metadata:(NSDictionary*)metadata
                     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addAssetsGroupAlbumWithName:(NSString*)name
                        resultBlock:(ALAssetsLibraryGroupResultBlock)resultBlock
                       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)groupForURL:(NSURL*)groupURL
        resultBlock:(ALAssetsLibraryGroupResultBlock)resultBlock
       failureBlock:(ALAssetsLibraryAccessFailureBlock)failureBlock {
    UNIMPLEMENTED();
}

@end
