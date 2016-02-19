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

#import <StubReturn.h>
#import <AssetsLibrary/ALAsset.h>

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

@implementation ALAsset
/**
 @Status Stub
 @Notes
*/
- (id)valueForProperty:(NSString*)property {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (ALAssetRepresentation*)defaultRepresentation {
    UNIMPLEMENTED();
    return StubReturn();
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
