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

// WindowsGraphicsImaging.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGIBitmapTransform, WGIBitmapTypedValue, WGIBitmapPropertySet, WGIBitmapPropertiesView, WGIBitmapProperties, WGIPixelDataProvider,
    WGIImageStream, WGIBitmapFrame, WGIBitmapCodecInformation, WGIBitmapDecoder, WGIBitmapEncoder;
@class WGIBitmapBounds;
@protocol WGIIBitmapTransform
, WGIIBitmapTypedValue, WGIIBitmapTypedValueFactory, WGIIBitmapPropertiesView, WGIIBitmapProperties, WGIIPixelDataProvider, WGIIBitmapFrame,
    WGIIBitmapCodecInformation, WGIIBitmapDecoderStatics, WGIIBitmapDecoder, WGIIBitmapEncoderStatics, WGIIBitmapEncoder;

// Windows.Graphics.Imaging.BitmapPixelFormat
enum _WGIBitmapPixelFormat {
    WGIBitmapPixelFormatUnknown = 0,
    WGIBitmapPixelFormatRgba16 = 12,
    WGIBitmapPixelFormatRgba8 = 30,
    WGIBitmapPixelFormatBgra8 = 87,
};
typedef unsigned WGIBitmapPixelFormat;

// Windows.Graphics.Imaging.BitmapAlphaMode
enum _WGIBitmapAlphaMode {
    WGIBitmapAlphaModePremultiplied = 0,
    WGIBitmapAlphaModeStraight = 1,
    WGIBitmapAlphaModeIgnore = 2,
};
typedef unsigned WGIBitmapAlphaMode;

// Windows.Graphics.Imaging.BitmapInterpolationMode
enum _WGIBitmapInterpolationMode {
    WGIBitmapInterpolationModeNearestNeighbor = 0,
    WGIBitmapInterpolationModeLinear = 1,
    WGIBitmapInterpolationModeCubic = 2,
    WGIBitmapInterpolationModeFant = 3,
};
typedef unsigned WGIBitmapInterpolationMode;

// Windows.Graphics.Imaging.BitmapFlip
enum _WGIBitmapFlip {
    WGIBitmapFlipNone = 0,
    WGIBitmapFlipHorizontal = 1,
    WGIBitmapFlipVertical = 2,
};
typedef unsigned WGIBitmapFlip;

// Windows.Graphics.Imaging.BitmapRotation
enum _WGIBitmapRotation {
    WGIBitmapRotationNone = 0,
    WGIBitmapRotationClockwise90Degrees = 1,
    WGIBitmapRotationClockwise180Degrees = 2,
    WGIBitmapRotationClockwise270Degrees = 3,
};
typedef unsigned WGIBitmapRotation;

// Windows.Graphics.Imaging.ColorManagementMode
enum _WGIColorManagementMode {
    WGIColorManagementModeDoNotColorManage = 0,
    WGIColorManagementModeColorManageToSRgb = 1,
};
typedef unsigned WGIColorManagementMode;

// Windows.Graphics.Imaging.ExifOrientationMode
enum _WGIExifOrientationMode {
    WGIExifOrientationModeIgnoreExifOrientation = 0,
    WGIExifOrientationModeRespectExifOrientation = 1,
};
typedef unsigned WGIExifOrientationMode;

// Windows.Graphics.Imaging.PngFilterMode
enum _WGIPngFilterMode {
    WGIPngFilterModeAutomatic = 0,
    WGIPngFilterModeNone = 1,
    WGIPngFilterModeSub = 2,
    WGIPngFilterModeUp = 3,
    WGIPngFilterModeAverage = 4,
    WGIPngFilterModePaeth = 5,
    WGIPngFilterModeAdaptive = 6,
};
typedef unsigned WGIPngFilterMode;

// Windows.Graphics.Imaging.TiffCompressionMode
enum _WGITiffCompressionMode {
    WGITiffCompressionModeAutomatic = 0,
    WGITiffCompressionModeNone = 1,
    WGITiffCompressionModeCcitt3 = 2,
    WGITiffCompressionModeCcitt4 = 3,
    WGITiffCompressionModeLzw = 4,
    WGITiffCompressionModeRle = 5,
    WGITiffCompressionModeZip = 6,
    WGITiffCompressionModeLzwhDifferencing = 7,
};
typedef unsigned WGITiffCompressionMode;

// Windows.Graphics.Imaging.JpegSubsamplingMode
enum _WGIJpegSubsamplingMode {
    WGIJpegSubsamplingModeDefault = 0,
    WGIJpegSubsamplingModeY4Cb2Cr0 = 1,
    WGIJpegSubsamplingModeY4Cb2Cr2 = 2,
    WGIJpegSubsamplingModeY4Cb4Cr4 = 3,
};
typedef unsigned WGIJpegSubsamplingMode;

#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.Imaging.BitmapBounds
WINRT_EXPORT
@interface WGIBitmapBounds : NSObject
+ (instancetype) new;
@property unsigned x;
@property unsigned y;
@property unsigned width;
@property unsigned height;
@end

// Windows.Graphics.Imaging.IBitmapPropertiesView
#ifndef __WGIIBitmapPropertiesView_DEFINED__
#define __WGIIBitmapPropertiesView_DEFINED__

@protocol WGIIBitmapPropertiesView
- (void)getPropertiesAsync:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure;
@end

#endif // __WGIIBitmapPropertiesView_DEFINED__

// Windows.Graphics.Imaging.IBitmapFrame
#ifndef __WGIIBitmapFrame_DEFINED__
#define __WGIIBitmapFrame_DEFINED__

@protocol WGIIBitmapFrame
@property (readonly) WGIBitmapAlphaMode bitmapAlphaMode;
@property (readonly) WGIBitmapPixelFormat bitmapPixelFormat;
@property (readonly) WGIBitmapPropertiesView* bitmapProperties;
@property (readonly) double dpiX;
@property (readonly) double dpiY;
@property (readonly) unsigned orientedPixelHeight;
@property (readonly) unsigned orientedPixelWidth;
@property (readonly) unsigned pixelHeight;
@property (readonly) unsigned pixelWidth;
- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WGIIBitmapFrame_DEFINED__

// Windows.Graphics.Imaging.BitmapTransform
#ifndef __WGIBitmapTransform_DEFINED__
#define __WGIBitmapTransform_DEFINED__

WINRT_EXPORT
@interface WGIBitmapTransform : RTObject
+ (instancetype)create ACTIVATOR;
@property unsigned scaledWidth;
@property unsigned scaledHeight;
@property WGIBitmapRotation rotation;
@property WGIBitmapInterpolationMode interpolationMode;
@property WGIBitmapFlip flip;
@property (copy) WGIBitmapBounds* bounds;
@end

#endif // __WGIBitmapTransform_DEFINED__

// Windows.Graphics.Imaging.BitmapTypedValue
#ifndef __WGIBitmapTypedValue_DEFINED__
#define __WGIBitmapTypedValue_DEFINED__

WINRT_EXPORT
@interface WGIBitmapTypedValue : RTObject
+ (WGIBitmapTypedValue*)create:(RTObject*)value type:(WFPropertyType)type ACTIVATOR;
@property (readonly) WFPropertyType type;
@property (readonly) RTObject* value;
@end

#endif // __WGIBitmapTypedValue_DEFINED__

// Windows.Graphics.Imaging.BitmapPropertySet
#ifndef __WGIBitmapPropertySet_DEFINED__
#define __WGIBitmapPropertySet_DEFINED__

WINRT_EXPORT
@interface WGIBitmapPropertySet : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,Windows.Graphics.Imaging.BitmapTypedValue> type information
@end

#endif // __WGIBitmapPropertySet_DEFINED__

// Windows.Graphics.Imaging.BitmapPropertiesView
#ifndef __WGIBitmapPropertiesView_DEFINED__
#define __WGIBitmapPropertiesView_DEFINED__

WINRT_EXPORT
@interface WGIBitmapPropertiesView : RTObject <WGIIBitmapPropertiesView>
- (void)getPropertiesAsync:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure;
@end

#endif // __WGIBitmapPropertiesView_DEFINED__

// Windows.Graphics.Imaging.BitmapProperties
#ifndef __WGIBitmapProperties_DEFINED__
#define __WGIBitmapProperties_DEFINED__

WINRT_EXPORT
@interface WGIBitmapProperties : RTObject <WGIIBitmapPropertiesView>
// Failed to generate member SetPropertiesAsync (Can't marshal
// Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.Graphics.Imaging.BitmapTypedValue>)
- (void)getPropertiesAsync:(id<NSFastEnumeration> /*String*/)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure;
@end

#endif // __WGIBitmapProperties_DEFINED__

// Windows.Graphics.Imaging.PixelDataProvider
#ifndef __WGIPixelDataProvider_DEFINED__
#define __WGIPixelDataProvider_DEFINED__

WINRT_EXPORT
@interface WGIPixelDataProvider : RTObject
- (id<NSFastEnumeration> /*UInt8*/)detachPixelData;
@end

#endif // __WGIPixelDataProvider_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Storage.Streams.IInputStream
#ifndef __WSSIInputStream_DEFINED__
#define __WSSIInputStream_DEFINED__

@protocol WSSIInputStream <WFIClosable>
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIOutputStream_DEFINED__

// Windows.Storage.Streams.IRandomAccessStream
#ifndef __WSSIRandomAccessStream_DEFINED__
#define __WSSIRandomAccessStream_DEFINED__

@protocol WSSIRandomAccessStream <WFIClosable, WSSIInputStream, WSSIOutputStream>
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
@property uint64_t size;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStream_DEFINED__

// Windows.Storage.Streams.IContentTypeProvider
#ifndef __WSSIContentTypeProvider_DEFINED__
#define __WSSIContentTypeProvider_DEFINED__

@protocol WSSIContentTypeProvider
@property (readonly) NSString* contentType;
@end

#endif // __WSSIContentTypeProvider_DEFINED__

// Windows.Storage.Streams.IRandomAccessStreamWithContentType
#ifndef __WSSIRandomAccessStreamWithContentType_DEFINED__
#define __WSSIRandomAccessStreamWithContentType_DEFINED__

@protocol
    WSSIRandomAccessStreamWithContentType <WSSIRandomAccessStream, WFIClosable, WSSIInputStream, WSSIOutputStream, WSSIContentTypeProvider>
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Graphics.Imaging.ImageStream
#ifndef __WGIImageStream_DEFINED__
#define __WGIImageStream_DEFINED__

WINRT_EXPORT
@interface WGIImageStream : RTObject <WSSIRandomAccessStreamWithContentType,
                                      WSSIContentTypeProvider,
                                      WSSIRandomAccessStream,
                                      WSSIOutputStream,
                                      WFIClosable,
                                      WSSIInputStream>
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
@property (readonly) NSString* contentType;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned))success
          progress:(void (^)(unsigned))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGIImageStream_DEFINED__

// Windows.Graphics.Imaging.BitmapFrame
#ifndef __WGIBitmapFrame_DEFINED__
#define __WGIBitmapFrame_DEFINED__

WINRT_EXPORT
@interface WGIBitmapFrame : RTObject <WGIIBitmapFrame>
@property (readonly) WGIBitmapAlphaMode bitmapAlphaMode;
@property (readonly) WGIBitmapPixelFormat bitmapPixelFormat;
@property (readonly) WGIBitmapPropertiesView* bitmapProperties;
@property (readonly) double dpiX;
@property (readonly) double dpiY;
@property (readonly) unsigned orientedPixelHeight;
@property (readonly) unsigned orientedPixelWidth;
@property (readonly) unsigned pixelHeight;
@property (readonly) unsigned pixelWidth;
- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WGIBitmapFrame_DEFINED__

// Windows.Graphics.Imaging.BitmapCodecInformation
#ifndef __WGIBitmapCodecInformation_DEFINED__
#define __WGIBitmapCodecInformation_DEFINED__

WINRT_EXPORT
@interface WGIBitmapCodecInformation : RTObject
@property (readonly) WFGUID* codecId;
@property (readonly) id<NSFastEnumeration> /*String*/ fileExtensions;
@property (readonly) NSString* friendlyName;
@property (readonly) id<NSFastEnumeration> /*String*/ mimeTypes;
@end

#endif // __WGIBitmapCodecInformation_DEFINED__

// Windows.Graphics.Imaging.BitmapDecoder
#ifndef __WGIBitmapDecoder_DEFINED__
#define __WGIBitmapDecoder_DEFINED__

WINRT_EXPORT
@interface WGIBitmapDecoder : RTObject <WGIIBitmapFrame>
+ (id<NSFastEnumeration> /*WGIBitmapCodecInformation*/)getDecoderInformationEnumerator;
+ (void)createAsync:(RTObject<WSSIRandomAccessStream>*)stream
            success:(void (^)(WGIBitmapDecoder*))success
            failure:(void (^)(NSError*))failure;
+ (void)createWithIdAsync:(WFGUID*)decoderId
                   stream:(RTObject<WSSIRandomAccessStream>*)stream
                  success:(void (^)(WGIBitmapDecoder*))success
                  failure:(void (^)(NSError*))failure;
@property (readonly) WGIBitmapPropertiesView* bitmapContainerProperties;
@property (readonly) WGIBitmapCodecInformation* decoderInformation;
@property (readonly) unsigned frameCount;
@property (readonly) WGIBitmapAlphaMode bitmapAlphaMode;
@property (readonly) WGIBitmapPixelFormat bitmapPixelFormat;
@property (readonly) WGIBitmapPropertiesView* bitmapProperties;
@property (readonly) double dpiX;
@property (readonly) double dpiY;
@property (readonly) unsigned orientedPixelHeight;
@property (readonly) unsigned orientedPixelWidth;
@property (readonly) unsigned pixelHeight;
@property (readonly) unsigned pixelWidth;
+ (WFGUID*)bmpDecoderId;
+ (WFGUID*)gifDecoderId;
+ (WFGUID*)icoDecoderId;
+ (WFGUID*)jpegDecoderId;
+ (WFGUID*)jpegXRDecoderId;
+ (WFGUID*)pngDecoderId;
+ (WFGUID*)tiffDecoderId;
- (void)getPreviewAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure;
- (void)getFrameAsync:(unsigned)frameIndex success:(void (^)(WGIBitmapFrame*))success failure:(void (^)(NSError*))failure;
- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure;
- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure;
@end

#endif // __WGIBitmapDecoder_DEFINED__

// Windows.Graphics.Imaging.BitmapEncoder
#ifndef __WGIBitmapEncoder_DEFINED__
#define __WGIBitmapEncoder_DEFINED__

WINRT_EXPORT
@interface WGIBitmapEncoder : RTObject
+ (id<NSFastEnumeration> /*WGIBitmapCodecInformation*/)getEncoderInformationEnumerator;
+ (void)createAsync:(WFGUID*)encoderId
             stream:(RTObject<WSSIRandomAccessStream>*)stream
            success:(void (^)(WGIBitmapEncoder*))success
            failure:(void (^)(NSError*))failure;
// Failed to generate member CreateAsync (Can't marshal
// Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.Graphics.Imaging.BitmapTypedValue>)
+ (void)createForTranscodingAsync:(RTObject<WSSIRandomAccessStream>*)stream
                    bitmapDecoder:(WGIBitmapDecoder*)bitmapDecoder
                          success:(void (^)(WGIBitmapEncoder*))success
                          failure:(void (^)(NSError*))failure;
+ (void)createForInPlacePropertyEncodingAsync:(WGIBitmapDecoder*)bitmapDecoder
                                      success:(void (^)(WGIBitmapEncoder*))success
                                      failure:(void (^)(NSError*))failure;
@property BOOL isThumbnailGenerated;
@property unsigned generatedThumbnailWidth;
@property unsigned generatedThumbnailHeight;
@property (readonly) WGIBitmapProperties* bitmapContainerProperties;
@property (readonly) WGIBitmapProperties* bitmapProperties;
@property (readonly) WGIBitmapTransform* bitmapTransform;
@property (readonly) WGIBitmapCodecInformation* encoderInformation;
+ (WFGUID*)bmpEncoderId;
+ (WFGUID*)gifEncoderId;
+ (WFGUID*)jpegEncoderId;
+ (WFGUID*)jpegXREncoderId;
+ (WFGUID*)pngEncoderId;
+ (WFGUID*)tiffEncoderId;
- (void)setPixelData:(WGIBitmapPixelFormat)pixelFormat
           alphaMode:(WGIBitmapAlphaMode)alphaMode
               width:(unsigned)width
              height:(unsigned)height
                dpiX:(double)dpiX
                dpiY:(double)dpiY
              pixels:(id<NSFastEnumeration> /*UInt8*/)pixels;
- (RTObject<WFIAsyncAction>*)goToNextFrameAsync;
// Failed to generate member GoToNextFrameAsync (Can't marshal
// Windows.Foundation.Collections.IKeyValuePair`2<String,Windows.Graphics.Imaging.BitmapTypedValue>)
- (RTObject<WFIAsyncAction>*)flushAsync;
@end

#endif // __WGIBitmapEncoder_DEFINED__
