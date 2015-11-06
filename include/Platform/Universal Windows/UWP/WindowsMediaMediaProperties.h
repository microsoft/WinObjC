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

// WindowsMediaMediaProperties.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMMMediaRatio, WMMMediaPropertySet, WMMAudioEncodingProperties, WMMMediaEncodingSubtypes, WMMH264ProfileIds, WMMMpeg2ProfileIds,
    WMMVideoEncodingProperties, WMMImageEncodingProperties, WMMContainerEncodingProperties, WMMMediaEncodingProfile;
@protocol WMMIMediaRatio
, WMMIMediaEncodingProperties, WMMIAudioEncodingProperties, WMMIAudioEncodingPropertiesWithFormatUserData,
    WMMIAudioEncodingPropertiesStatics, WMMIVideoEncodingProperties, WMMIMediaEncodingSubtypesStatics, WMMIH264ProfileIdsStatics,
    WMMIMpeg2ProfileIdsStatics, WMMIVideoEncodingProperties2, WMMIVideoEncodingPropertiesStatics, WMMIImageEncodingProperties,
    WMMIImageEncodingPropertiesStatics, WMMIImageEncodingPropertiesStatics2, WMMIContainerEncodingProperties,
    WMMIMediaEncodingProfileStatics, WMMIMediaEncodingProfileStatics2, WMMIMediaEncodingProfile;

// Windows.Media.MediaProperties.MediaPixelFormat
enum _WMMMediaPixelFormat {
    WMMMediaPixelFormatNv12 = 0,
    WMMMediaPixelFormatBgra8 = 1,
};
typedef unsigned WMMMediaPixelFormat;

// Windows.Media.MediaProperties.MediaThumbnailFormat
enum _WMMMediaThumbnailFormat {
    WMMMediaThumbnailFormatBmp = 0,
    WMMMediaThumbnailFormatBgra8 = 1,
};
typedef unsigned WMMMediaThumbnailFormat;

// Windows.Media.MediaProperties.AudioEncodingQuality
enum _WMMAudioEncodingQuality {
    WMMAudioEncodingQualityAuto = 0,
    WMMAudioEncodingQualityHigh = 1,
    WMMAudioEncodingQualityMedium = 2,
    WMMAudioEncodingQualityLow = 3,
};
typedef unsigned WMMAudioEncodingQuality;

// Windows.Media.MediaProperties.VideoEncodingQuality
enum _WMMVideoEncodingQuality {
    WMMVideoEncodingQualityAuto = 0,
    WMMVideoEncodingQualityHD1080p = 1,
    WMMVideoEncodingQualityHD720p = 2,
    WMMVideoEncodingQualityWvga = 3,
    WMMVideoEncodingQualityNtsc = 4,
    WMMVideoEncodingQualityPal = 5,
    WMMVideoEncodingQualityVga = 6,
    WMMVideoEncodingQualityQvga = 7,
};
typedef unsigned WMMVideoEncodingQuality;

// Windows.Media.MediaProperties.MediaRotation
enum _WMMMediaRotation {
    WMMMediaRotationNone = 0,
    WMMMediaRotationClockwise90Degrees = 1,
    WMMMediaRotationClockwise180Degrees = 2,
    WMMMediaRotationClockwise270Degrees = 3,
};
typedef unsigned WMMMediaRotation;

// Windows.Media.MediaProperties.MediaMirroringOptions
enum _WMMMediaMirroringOptions {
    WMMMediaMirroringOptionsNone = 0,
    WMMMediaMirroringOptionsHorizontal = 1,
    WMMMediaMirroringOptionsVertical = 2,
};
typedef unsigned WMMMediaMirroringOptions;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Media.MediaProperties.IMediaEncodingProperties
#ifndef __WMMIMediaEncodingProperties_DEFINED__
#define __WMMIMediaEncodingProperties_DEFINED__

@protocol WMMIMediaEncodingProperties
@property (readonly) WMMMediaPropertySet* properties;
@property (copy) NSString* subtype;
@property (readonly) NSString* type;
@end

#endif // __WMMIMediaEncodingProperties_DEFINED__

// Windows.Media.MediaProperties.MediaRatio
#ifndef __WMMMediaRatio_DEFINED__
#define __WMMMediaRatio_DEFINED__

WINRT_EXPORT
@interface WMMMediaRatio : RTObject
@property unsigned int numerator;
@property unsigned int denominator;
@end

#endif // __WMMMediaRatio_DEFINED__

// Windows.Media.MediaProperties.MediaPropertySet
#ifndef __WMMMediaPropertySet_DEFINED__
#define __WMMMediaPropertySet_DEFINED__

WINRT_EXPORT
@interface WMMMediaPropertySet : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned int size;
- (id)objectForKey:(id)key;
- (NSArray*)allKeys;
- (NSArray*)allKeysForObject:(id)obj;
- (NSArray*)allValues;
- (id)keyEnumerator;
- (unsigned int)count;

- (void)setObject:(id)obj forKey:(id)key;
- (void)setObject:(id)object forKeyedSubscript:(id)key;
- (void)removeObjectForKey:(id)key;
- (void)removeAllObjects;
- (void)removeObjectsForKeys:(NSArray*)keys;
- (void)addEntriesFromDictionary:(NSDictionary*)otherDict;
- (void)addEntriesFromDictionaryNoReplace:(NSDictionary*)otherDict;
- (void)setDictionary:(NSDictionary*)dict;
@end

#endif // __WMMMediaPropertySet_DEFINED__

// Windows.Media.MediaProperties.AudioEncodingProperties
#ifndef __WMMAudioEncodingProperties_DEFINED__
#define __WMMAudioEncodingProperties_DEFINED__

WINRT_EXPORT
@interface WMMAudioEncodingProperties : RTObject <WMMIMediaEncodingProperties>
+ (WMMAudioEncodingProperties*)createAac:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate;
+ (WMMAudioEncodingProperties*)createAacAdts:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate;
+ (WMMAudioEncodingProperties*)createMp3:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate;
+ (WMMAudioEncodingProperties*)createPcm:(unsigned int)sampleRate
                            channelCount:(unsigned int)channelCount
                           bitsPerSample:(unsigned int)bitsPerSample;
+ (WMMAudioEncodingProperties*)createWma:(unsigned int)sampleRate channelCount:(unsigned int)channelCount bitrate:(unsigned int)bitrate;
+ (instancetype)create ACTIVATOR;
@property unsigned int sampleRate;
@property unsigned int channelCount;
@property unsigned int bitsPerSample;
@property unsigned int bitrate;
@property (copy) NSString* subtype;
@property (readonly) WMMMediaPropertySet* properties;
@property (readonly) NSString* type;
- (void)setFormatUserData:(id<NSFastEnumeration> /* uint8_t */)value;
- (void)getFormatUserData:(id<NSFastEnumeration> /* uint8_t */*)value;
@end

#endif // __WMMAudioEncodingProperties_DEFINED__

// Windows.Media.MediaProperties.MediaEncodingSubtypes
#ifndef __WMMMediaEncodingSubtypes_DEFINED__
#define __WMMMediaEncodingSubtypes_DEFINED__

WINRT_EXPORT
@interface WMMMediaEncodingSubtypes : RTObject
+ (NSString*)aac;
+ (NSString*)aacAdts;
+ (NSString*)ac3;
+ (NSString*)amrNb;
+ (NSString*)amrWb;
+ (NSString*)argb32;
+ (NSString*)asf;
+ (NSString*)avi;
+ (NSString*)bgra8;
+ (NSString*)bmp;
+ (NSString*)eac3;
+ (NSString*)Float;
+ (NSString*)gif;
+ (NSString*)h263;
+ (NSString*)h264;
+ (NSString*)h264Es;
+ (NSString*)hevc;
+ (NSString*)hevcEs;
+ (NSString*)iyuv;
+ (NSString*)jpeg;
+ (NSString*)jpegXr;
+ (NSString*)mjpg;
+ (NSString*)mp3;
+ (NSString*)mpeg;
+ (NSString*)mpeg1;
+ (NSString*)mpeg2;
+ (NSString*)mpeg4;
+ (NSString*)nv12;
+ (NSString*)pcm;
+ (NSString*)png;
+ (NSString*)rgb24;
+ (NSString*)rgb32;
+ (NSString*)tiff;
+ (NSString*)wave;
+ (NSString*)wma8;
+ (NSString*)wma9;
+ (NSString*)wmv3;
+ (NSString*)wvc1;
+ (NSString*)yuy2;
+ (NSString*)yv12;
@end

#endif // __WMMMediaEncodingSubtypes_DEFINED__

// Windows.Media.MediaProperties.H264ProfileIds
#ifndef __WMMH264ProfileIds_DEFINED__
#define __WMMH264ProfileIds_DEFINED__

WINRT_EXPORT
@interface WMMH264ProfileIds : RTObject
+ (int)baseline;
+ (int)constrainedBaseline;
+ (int)extended;
+ (int)high;
+ (int)high10;
+ (int)high422;
+ (int)high444;
+ (int)main;
+ (int)multiviewHigh;
+ (int)stereoHigh;
@end

#endif // __WMMH264ProfileIds_DEFINED__

// Windows.Media.MediaProperties.Mpeg2ProfileIds
#ifndef __WMMMpeg2ProfileIds_DEFINED__
#define __WMMMpeg2ProfileIds_DEFINED__

WINRT_EXPORT
@interface WMMMpeg2ProfileIds : RTObject
+ (int)high;
+ (int)main;
+ (int)signalNoiseRatioScalable;
+ (int)simple;
+ (int)spatiallyScalable;
@end

#endif // __WMMMpeg2ProfileIds_DEFINED__

// Windows.Media.MediaProperties.VideoEncodingProperties
#ifndef __WMMVideoEncodingProperties_DEFINED__
#define __WMMVideoEncodingProperties_DEFINED__

WINRT_EXPORT
@interface WMMVideoEncodingProperties : RTObject <WMMIMediaEncodingProperties>
+ (WMMVideoEncodingProperties*)createH264;
+ (WMMVideoEncodingProperties*)createMpeg2;
+ (WMMVideoEncodingProperties*)createUncompressed:(NSString*)subtype width:(unsigned int)width height:(unsigned int)height;
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* subtype;
@property (readonly) WMMMediaPropertySet* properties;
@property (readonly) NSString* type;
@property unsigned int width;
@property unsigned int height;
@property unsigned int bitrate;
@property (readonly) WMMMediaRatio* frameRate;
@property (readonly) WMMMediaRatio* pixelAspectRatio;
@property int profileId;
- (void)setFormatUserData:(id<NSFastEnumeration> /* uint8_t */)value;
- (void)getFormatUserData:(id<NSFastEnumeration> /* uint8_t */*)value;
@end

#endif // __WMMVideoEncodingProperties_DEFINED__

// Windows.Media.MediaProperties.ImageEncodingProperties
#ifndef __WMMImageEncodingProperties_DEFINED__
#define __WMMImageEncodingProperties_DEFINED__

WINRT_EXPORT
@interface WMMImageEncodingProperties : RTObject <WMMIMediaEncodingProperties>
+ (WMMImageEncodingProperties*)createJpeg;
+ (WMMImageEncodingProperties*)createPng;
+ (WMMImageEncodingProperties*)createJpegXR;
+ (WMMImageEncodingProperties*)createUncompressed:(WMMMediaPixelFormat)format;
+ (WMMImageEncodingProperties*)createBmp;
+ (instancetype)create ACTIVATOR;
@property unsigned int width;
@property unsigned int height;
@property (copy) NSString* subtype;
@property (readonly) WMMMediaPropertySet* properties;
@property (readonly) NSString* type;
@end

#endif // __WMMImageEncodingProperties_DEFINED__

// Windows.Media.MediaProperties.ContainerEncodingProperties
#ifndef __WMMContainerEncodingProperties_DEFINED__
#define __WMMContainerEncodingProperties_DEFINED__

WINRT_EXPORT
@interface WMMContainerEncodingProperties : RTObject <WMMIMediaEncodingProperties>
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* subtype;
@property (readonly) WMMMediaPropertySet* properties;
@property (readonly) NSString* type;
@end

#endif // __WMMContainerEncodingProperties_DEFINED__

// Windows.Media.MediaProperties.MediaEncodingProfile
#ifndef __WMMMediaEncodingProfile_DEFINED__
#define __WMMMediaEncodingProfile_DEFINED__

WINRT_EXPORT
@interface WMMMediaEncodingProfile : RTObject
+ (WMMMediaEncodingProfile*)createM4a:(WMMAudioEncodingQuality)quality;
+ (WMMMediaEncodingProfile*)createMp3:(WMMAudioEncodingQuality)quality;
+ (WMMMediaEncodingProfile*)createWma:(WMMAudioEncodingQuality)quality;
+ (WMMMediaEncodingProfile*)createMp4:(WMMVideoEncodingQuality)quality;
+ (WMMMediaEncodingProfile*)createWmv:(WMMVideoEncodingQuality)quality;
+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file
                    success:(void (^)(WMMMediaEncodingProfile*))success
                    failure:(void (^)(NSError*))failure;
+ (void)createFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)stream
                      success:(void (^)(WMMMediaEncodingProfile*))success
                      failure:(void (^)(NSError*))failure;
+ (WMMMediaEncodingProfile*)createWav:(WMMAudioEncodingQuality)quality;
+ (WMMMediaEncodingProfile*)createAvi:(WMMVideoEncodingQuality)quality;
+ (instancetype)create ACTIVATOR;
@property (copy) WMMVideoEncodingProperties* video;
@property (copy) WMMContainerEncodingProperties* container;
@property (copy) WMMAudioEncodingProperties* audio;
@end

#endif // __WMMMediaEncodingProfile_DEFINED__
