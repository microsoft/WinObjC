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
#import <AssetsLibrary/ALAssetsLibrary.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/NSObject.h>

@class NSString;
@class ALAssetRepresentation;
@class NSData;
@class NSDictionary;
@class NSURL;

ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyType;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyLocation;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyDuration;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyOrientation;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyDate;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyRepresentations;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyURLs;
ASSETSLIBRARY_EXPORT NSString* const ALAssetPropertyAssetURL;
ASSETSLIBRARY_EXPORT NSString* const ALErrorInvalidProperty;
ASSETSLIBRARY_EXPORT NSString* const ALAssetTypePhoto;
ASSETSLIBRARY_EXPORT NSString* const ALAssetTypeVideo;
ASSETSLIBRARY_EXPORT NSString* const ALAssetTypeUnknown;

ASSETSLIBRARY_EXPORT_CLASS
@interface ALAsset : NSObject <NSObject>
- (id)valueForProperty:(NSString*)property STUB_METHOD;
- (ALAssetRepresentation*)defaultRepresentation;
- (ALAssetRepresentation*)representationForUTI:(NSString*)representationUTI STUB_METHOD;
- (CGImageRef)thumbnail STUB_METHOD;
- (CGImageRef)aspectRatioThumbnail STUB_METHOD;
- (void)setImageData:(NSData*)imageData
            metadata:(NSDictionary*)metadata
     completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock STUB_METHOD;
- (void)setVideoAtPath:(NSURL*)videoPathURL completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock STUB_METHOD;
- (void)writeModifiedImageDataToSavedPhotosAlbum:(NSData*)imageData
                                        metadata:(NSDictionary*)metadata
                                 completionBlock:(ALAssetsLibraryWriteImageCompletionBlock)completionBlock STUB_METHOD;
- (void)writeModifiedVideoAtPathToSavedPhotosAlbum:(NSURL*)videoPathURL
                                   completionBlock:(ALAssetsLibraryWriteVideoCompletionBlock)completionBlock STUB_METHOD;
@property (readonly, getter=isEditable, nonatomic) BOOL editable STUB_PROPERTY;
@property (readonly, nonatomic) ALAsset* originalAsset STUB_PROPERTY;
@end
