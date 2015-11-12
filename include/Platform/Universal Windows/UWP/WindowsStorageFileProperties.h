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

// WindowsStorageFileProperties.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSFGeotagHelper, WSFStorageItemThumbnail, WSFMusicProperties, WSFVideoProperties, WSFImageProperties, WSFDocumentProperties,
    WSFStorageItemContentProperties, WSFBasicProperties;
@protocol WSFIGeotagHelperStatics
, WSFIThumbnailProperties, WSFIStorageItemExtraProperties, WSFIStorageItemContentProperties, WSFIMusicProperties, WSFIImageProperties,
    WSFIVideoProperties, WSFIDocumentProperties, WSFIBasicProperties;

// Windows.Storage.FileProperties.PropertyPrefetchOptions
enum _WSFPropertyPrefetchOptions {
    WSFPropertyPrefetchOptionsNone = 0,
    WSFPropertyPrefetchOptionsMusicProperties = 1,
    WSFPropertyPrefetchOptionsVideoProperties = 2,
    WSFPropertyPrefetchOptionsImageProperties = 4,
    WSFPropertyPrefetchOptionsDocumentProperties = 8,
    WSFPropertyPrefetchOptionsBasicProperties = 16,
};
typedef unsigned WSFPropertyPrefetchOptions;

// Windows.Storage.FileProperties.ThumbnailType
enum _WSFThumbnailType {
    WSFThumbnailTypeImage = 0,
    WSFThumbnailTypeIcon = 1,
};
typedef unsigned WSFThumbnailType;

// Windows.Storage.FileProperties.ThumbnailMode
enum _WSFThumbnailMode {
    WSFThumbnailModePicturesView = 0,
    WSFThumbnailModeVideosView = 1,
    WSFThumbnailModeMusicView = 2,
    WSFThumbnailModeDocumentsView = 3,
    WSFThumbnailModeListView = 4,
    WSFThumbnailModeSingleItem = 5,
};
typedef unsigned WSFThumbnailMode;

// Windows.Storage.FileProperties.ThumbnailOptions
enum _WSFThumbnailOptions {
    WSFThumbnailOptionsNone = 0,
    WSFThumbnailOptionsReturnOnlyIfCached = 1,
    WSFThumbnailOptionsResizeThumbnail = 2,
    WSFThumbnailOptionsUseCurrentScale = 4,
};
typedef unsigned WSFThumbnailOptions;

// Windows.Storage.FileProperties.PhotoOrientation
enum _WSFPhotoOrientation {
    WSFPhotoOrientationUnspecified = 0,
    WSFPhotoOrientationNormal = 1,
    WSFPhotoOrientationFlipHorizontal = 2,
    WSFPhotoOrientationRotate180 = 3,
    WSFPhotoOrientationFlipVertical = 4,
    WSFPhotoOrientationTranspose = 5,
    WSFPhotoOrientationRotate270 = 6,
    WSFPhotoOrientationTransverse = 7,
    WSFPhotoOrientationRotate90 = 8,
};
typedef unsigned WSFPhotoOrientation;

// Windows.Storage.FileProperties.VideoOrientation
enum _WSFVideoOrientation {
    WSFVideoOrientationNormal = 0,
    WSFVideoOrientationRotate90 = 90,
    WSFVideoOrientationRotate180 = 180,
    WSFVideoOrientationRotate270 = 270,
};
typedef unsigned WSFVideoOrientation;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"
#include "WindowsFoundation.h"
#include "WindowsDevicesGeolocation.h"

#import <Foundation/Foundation.h>

// Windows.Storage.FileProperties.IStorageItemExtraProperties
#ifndef __WSFIStorageItemExtraProperties_DEFINED__
#define __WSFIStorageItemExtraProperties_DEFINED__

@protocol WSFIStorageItemExtraProperties
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFIStorageItemExtraProperties_DEFINED__

// Windows.Storage.FileProperties.GeotagHelper
#ifndef __WSFGeotagHelper_DEFINED__
#define __WSFGeotagHelper_DEFINED__

WINRT_EXPORT
@interface WSFGeotagHelper : RTObject
+ (void)getGeotagAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDGGeopoint*))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)setGeotagFromGeolocatorAsync:(RTObject<WSIStorageFile>*)file geolocator:(WDGGeolocator*)geolocator;
+ (RTObject<WFIAsyncAction>*)setGeotagAsync:(RTObject<WSIStorageFile>*)file geopoint:(WDGGeopoint*)geopoint;
@end

#endif // __WSFGeotagHelper_DEFINED__

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
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WSSIInputStream_DEFINED__

// Windows.Storage.Streams.IOutputStream
#ifndef __WSSIOutputStream_DEFINED__
#define __WSSIOutputStream_DEFINED__

@protocol WSSIOutputStream <WFIClosable>
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
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
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
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
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSSIRandomAccessStreamWithContentType_DEFINED__

// Windows.Storage.FileProperties.StorageItemThumbnail
#ifndef __WSFStorageItemThumbnail_DEFINED__
#define __WSFStorageItemThumbnail_DEFINED__

WINRT_EXPORT
@interface WSFStorageItemThumbnail : RTObject <WSSIRandomAccessStreamWithContentType,
                                               WSSIContentTypeProvider,
                                               WSSIRandomAccessStream,
                                               WSSIOutputStream,
                                               WFIClosable,
                                               WSSIInputStream>
@property (readonly) unsigned int originalHeight;
@property (readonly) unsigned int originalWidth;
@property (readonly) BOOL returnedSmallerCachedSize;
@property (readonly) WSFThumbnailType type;
@property (readonly) NSString* contentType;
@property uint64_t size;
@property (readonly) BOOL canRead;
@property (readonly) BOOL canWrite;
@property (readonly) uint64_t position;
- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position;
- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position;
- (void)seek:(uint64_t)position;
- (RTObject<WSSIRandomAccessStream>*)cloneStream;
- (void)close;
- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure;
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WSFStorageItemThumbnail_DEFINED__

// Windows.Storage.FileProperties.MusicProperties
#ifndef __WSFMusicProperties_DEFINED__
#define __WSFMusicProperties_DEFINED__

WINRT_EXPORT
@interface WSFMusicProperties : RTObject <WSFIStorageItemExtraProperties>
@property unsigned int rating;
@property (copy) NSString* albumArtist;
@property (copy) NSString* album;
@property (copy) NSString* artist;
@property (copy) NSString* publisher;
@property unsigned int year;
@property unsigned int trackNumber;
@property (copy) NSString* title;
@property (copy) NSString* subtitle;
@property (readonly) NSMutableArray* producers;
@property (readonly) NSMutableArray* composers;
@property (readonly) NSMutableArray* conductors;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSMutableArray* writers;
@property (readonly) NSMutableArray* genre;
@property (readonly) unsigned int bitrate;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFMusicProperties_DEFINED__

// Windows.Storage.FileProperties.VideoProperties
#ifndef __WSFVideoProperties_DEFINED__
#define __WSFVideoProperties_DEFINED__

WINRT_EXPORT
@interface WSFVideoProperties : RTObject <WSFIStorageItemExtraProperties>
@property unsigned int year;
@property (copy) NSString* title;
@property (copy) NSString* subtitle;
@property (copy) NSString* publisher;
@property unsigned int rating;
@property (readonly) id latitude;
@property (readonly) WSFVideoOrientation orientation;
@property (readonly) WFTimeSpan* duration;
@property (readonly) unsigned int bitrate;
@property (readonly) NSMutableArray* producers;
@property (readonly) NSMutableArray* directors;
@property (readonly) unsigned int height;
@property (readonly) unsigned int width;
@property (readonly) id longitude;
@property (readonly) NSMutableArray* writers;
@property (readonly) NSMutableArray* keywords;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFVideoProperties_DEFINED__

// Windows.Storage.FileProperties.ImageProperties
#ifndef __WSFImageProperties_DEFINED__
#define __WSFImageProperties_DEFINED__

WINRT_EXPORT
@interface WSFImageProperties : RTObject <WSFIStorageItemExtraProperties>
@property (copy) NSString* title;
@property unsigned int rating;
@property (copy) WFDateTime* dateTaken;
@property (copy) NSString* cameraModel;
@property (copy) NSString* cameraManufacturer;
@property (readonly) id latitude;
@property (readonly) id longitude;
@property (readonly) WSFPhotoOrientation orientation;
@property (readonly) NSArray* peopleNames;
@property (readonly) unsigned int height;
@property (readonly) NSMutableArray* keywords;
@property (readonly) unsigned int width;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFImageProperties_DEFINED__

// Windows.Storage.FileProperties.DocumentProperties
#ifndef __WSFDocumentProperties_DEFINED__
#define __WSFDocumentProperties_DEFINED__

WINRT_EXPORT
@interface WSFDocumentProperties : RTObject <WSFIStorageItemExtraProperties>
@property (copy) NSString* title;
@property (copy) NSString* comment;
@property (readonly) NSMutableArray* author;
@property (readonly) NSMutableArray* keywords;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFDocumentProperties_DEFINED__

// Windows.Storage.FileProperties.StorageItemContentProperties
#ifndef __WSFStorageItemContentProperties_DEFINED__
#define __WSFStorageItemContentProperties_DEFINED__

WINRT_EXPORT
@interface WSFStorageItemContentProperties : RTObject <WSFIStorageItemExtraProperties>
- (void)getMusicPropertiesAsyncWithSuccess:(void (^)(WSFMusicProperties*))success failure:(void (^)(NSError*))failure;
- (void)getVideoPropertiesAsyncWithSuccess:(void (^)(WSFVideoProperties*))success failure:(void (^)(NSError*))failure;
- (void)getImagePropertiesAsyncWithSuccess:(void (^)(WSFImageProperties*))success failure:(void (^)(NSError*))failure;
- (void)getDocumentPropertiesAsyncWithSuccess:(void (^)(WSFDocumentProperties*))success failure:(void (^)(NSError*))failure;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFStorageItemContentProperties_DEFINED__

// Windows.Storage.FileProperties.BasicProperties
#ifndef __WSFBasicProperties_DEFINED__
#define __WSFBasicProperties_DEFINED__

WINRT_EXPORT
@interface WSFBasicProperties : RTObject <WSFIStorageItemExtraProperties>
@property (readonly) WFDateTime* dateModified;
@property (readonly) WFDateTime* itemDate;
@property (readonly) uint64_t size;
- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary*))success
                        failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* */)propertiesToSave;
- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault;
@end

#endif // __WSFBasicProperties_DEFINED__
