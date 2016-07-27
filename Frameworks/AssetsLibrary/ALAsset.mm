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

#import "ALAssetInternal.h"
#import "ALAssetRepresentationInternal.h"
#import <StubReturn.h>
#import <Starboard.h>
#import <Foundation/NSError.h>
#import <AssetsLibrary/ALAsset.h>
#import <AssetsLibrary/ALAssetRepresentation.h>
#import <UWP/WindowsStorage.h>

NSString* const ALAssetDomain = @"ALAsset";
NSString* const ALAssetPropertyType = @"ALAssetPropertyType";
NSString* const ALAssetPropertyLocation = @"ALAssetPropertyLocation";
NSString* const ALAssetPropertyDuration = @"ALAssetPropertyDuration";
NSString* const ALAssetPropertyOrientation = @"ALAssetPropertyOrientation";
NSString* const ALAssetPropertyDate = @"ALAssetPropertyDate";
NSString* const ALAssetPropertyRepresentations = @"ALAssetPropertyRepresentations";
NSString* const ALAssetPropertyURLs = @"ALAssetPropertyURLs";
NSString* const ALAssetPropertyAssetURL = @"ALAssetPropertyAssetURL";
NSString* const ALErrorInvalidProperty = @"ALErrorInvalidProperty";
NSString* const ALAssetTypePhoto = @"ALAssetTypePhoto";
NSString* const ALAssetTypeVideo = @"ALAssetTypeVideo";
NSString* const ALAssetTypeUnknown = @"ALAssetTypeUnknown";

@interface ALAsset () {
    StrongId<NSMutableArray> _representations;
    StrongId<NSURL> _assetURL;
    StrongId<NSString> _localPath;
}
@end

@implementation ALAsset

/**
@Status Caveat
@Notes Creates Asset Representations for representations at the url
*/
- (instancetype)_initWithURL:(NSURL*)url error:(NSError**)error {
    if ((self = [super init])) {
        __block NSError* tempError = nil;

        if (!url) {
            if (error) {
                *error = [NSError errorWithDomain:ALAssetDomain code:_ALAssetErrorCodeInvalidURL userInfo:nil];
            }
            [self release];
            return nil;
        }

        if ([url.scheme isEqualToString:@"assets-library"]) {
            _assetURL = url;

            dispatch_group_t group = dispatch_group_create();
            dispatch_group_enter(group);

            // Assemble the full path of the asset based on the location of the default Pictures library
            [WSStorageLibrary getLibraryAsync:WSKnownLibraryIdPictures
                success:^void(WSStorageLibrary* picturesLibrary) {
                    _localPath = [picturesLibrary.saveFolder.path stringByAppendingString:[_assetURL path]];
                    _localPath = [_localPath stringByReplacingOccurrencesOfString:@"/" withString:@"\\"];
                    dispatch_group_leave(group);
                }
                failure:^void(NSError* storageError) {
                    if (error) {
                        tempError = [storageError copy];
                    }
                    dispatch_group_leave(group);
                }];

            dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
            dispatch_release(group);

            if (error) {
                *error = [tempError autorelease];
            }

            if (_localPath == nil) {
                [self release];
                return nil;
            }
        } else {
            if (error) {
                *error = [NSError errorWithDomain:ALAssetDomain code:_ALAssetErrorCodeInvalidURLScheme userInfo:nil];
            }
            [self release];
            return nil;
        }

        _representations.attach([NSMutableArray new]);

        // Determine if it's a specific single file or a collection of files
        if ([_assetURL pathExtension] == nil) {
            // This url is a collection of asset representations
            // TODO: Task 8316785 - Fill _representations with all asset representations at this url
            //       starting with the default representation at index 0
        } else {
            // TODO: Task 8316836 - Set type of asset (ALAssetTypePhoto/ALAssetTypeVideo/ALAssetTypeUnknown)

            ALAssetRepresentation* assetRepresentation =
                [[[ALAssetRepresentation alloc] _initWithAssetURL:_assetURL localPath:_localPath error:error] autorelease];
            if (assetRepresentation == nil) {
                [self release];
                return nil;
            }
            [_representations addObject:assetRepresentation];
        }
    }
    return self;
}

/**
 @Status Stub
 @Notes
*/
- (id)valueForProperty:(NSString*)property {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes Return the default representation for this asset which will always be the first
        index of the representations
*/
- (ALAssetRepresentation*)defaultRepresentation {
    // TODO: Task 8317089 - If asset is not available, should return nil and
    //       post ALAssetsLibraryChangedNotification if it becomes available
    if ([_representations count] > 0) {
        return _representations[0];
    }
    return nil;
}

/**
 @Status Stub
 @Notes
*/
- (ALAssetRepresentation*)representationForUTI:(NSString*)representationUTI {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGImageRef)thumbnail {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGImageRef)aspectRatioThumbnail {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setImageData:(NSData*)imageData
            metadata:(NSDictionary*)metadata
     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setVideoAtPath:(NSURL*)videoPathURL completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeModifiedImageDataToSavedPhotosAlbum:(NSData*)imageData
                                        metadata:(NSDictionary*)metadata
                                 completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeModifiedVideoAtPathToSavedPhotosAlbum:(NSURL*)videoPathURL
                                   completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock {
    UNIMPLEMENTED();
}

@end
