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

// WindowsMediaEditing.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMEMediaOverlay, WMEMediaClip, WMEEmbeddedAudioTrack, WMEBackgroundAudioTrack, WMEMediaComposition, WMEMediaOverlayLayer;
@protocol WMEIMediaClip
, WMEIMediaComposition, WMEIMediaClipStatics, WMEIMediaClipStatics2, WMEIMediaCompositionStatics, WMEIEmbeddedAudioTrack,
    WMEIBackgroundAudioTrack, WMEIBackgroundAudioTrackStatics, WMEIMediaComposition2, WMEIMediaOverlay, WMEIMediaOverlayFactory,
    WMEIMediaOverlayLayerFactory, WMEIMediaOverlayLayer;

// Windows.Media.Editing.VideoFramePrecision
enum _WMEVideoFramePrecision {
    WMEVideoFramePrecisionNearestFrame = 0,
    WMEVideoFramePrecisionNearestKeyFrame = 1,
};
typedef unsigned WMEVideoFramePrecision;

// Windows.Media.Editing.MediaTrimmingPreference
enum _WMEMediaTrimmingPreference {
    WMEMediaTrimmingPreferenceFast = 0,
    WMEMediaTrimmingPreferencePrecise = 1,
};
typedef unsigned WMEMediaTrimmingPreference;

#include "WindowsMediaEffects.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaTranscoding.h"
#include "WindowsFoundationCollections.h"
#include "WindowsMediaMediaProperties.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsStorage.h"
#include "WindowsMediaCore.h"
#include "WindowsUI.h"
#include "WindowsGraphicsDirectXDirect3D11.h"

#import <Foundation/Foundation.h>

// Windows.Media.Editing.MediaOverlay
#ifndef __WMEMediaOverlay_DEFINED__
#define __WMEMediaOverlay_DEFINED__

WINRT_EXPORT
@interface WMEMediaOverlay : RTObject
+ (WMEMediaOverlay*)create:(WMEMediaClip*)clip ACTIVATOR;
+ (WMEMediaOverlay*)createWithPositionAndOpacity:(WMEMediaClip*)clip position:(WFRect*)position opacity:(double)opacity ACTIVATOR;
@property (copy) WFRect* position;
@property double opacity;
@property (copy) WFTimeSpan* delay;
@property BOOL audioEnabled;
@property (readonly) WMEMediaClip* clip;
- (WMEMediaOverlay*)clone;
@end

#endif // __WMEMediaOverlay_DEFINED__

// Windows.Media.Editing.MediaClip
#ifndef __WMEMediaClip_DEFINED__
#define __WMEMediaClip_DEFINED__

WINRT_EXPORT
@interface WMEMediaClip : RTObject
+ (WMEMediaClip*)createFromColor:(WUColor*)color originalDuration:(WFTimeSpan*)originalDuration;
+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WMEMediaClip*))success failure:(void (^)(NSError*))failure;
+ (void)createFromImageFileAsync:(RTObject<WSIStorageFile>*)file
                originalDuration:(WFTimeSpan*)originalDuration
                         success:(void (^)(WMEMediaClip*))success
                         failure:(void (^)(NSError*))failure;
+ (WMEMediaClip*)createFromSurface:(RTObject<WGDDIDirect3DSurface>*)surface originalDuration:(WFTimeSpan*)originalDuration;
@property unsigned int selectedEmbeddedAudioTrackIndex;
@property (copy) WFTimeSpan* trimTimeFromEnd;
@property double volume;
@property (copy) WFTimeSpan* trimTimeFromStart;
@property (readonly) NSArray* embeddedAudioTracks;
@property (readonly) WFTimeSpan* endTimeInComposition;
@property (readonly) WFTimeSpan* originalDuration;
@property (readonly) WFTimeSpan* startTimeInComposition;
@property (readonly) WFTimeSpan* trimmedDuration;
@property (readonly) NSMutableDictionary* userData;
@property (readonly) NSMutableArray* videoEffectDefinitions;
@property (readonly) NSMutableArray* audioEffectDefinitions;
- (WMEMediaClip*)clone;
- (WMMVideoEncodingProperties*)getVideoEncodingProperties;
@end

#endif // __WMEMediaClip_DEFINED__

// Windows.Media.Editing.EmbeddedAudioTrack
#ifndef __WMEEmbeddedAudioTrack_DEFINED__
#define __WMEEmbeddedAudioTrack_DEFINED__

WINRT_EXPORT
@interface WMEEmbeddedAudioTrack : RTObject
- (WMMAudioEncodingProperties*)getAudioEncodingProperties;
@end

#endif // __WMEEmbeddedAudioTrack_DEFINED__

// Windows.Media.Editing.BackgroundAudioTrack
#ifndef __WMEBackgroundAudioTrack_DEFINED__
#define __WMEBackgroundAudioTrack_DEFINED__

WINRT_EXPORT
@interface WMEBackgroundAudioTrack : RTObject
+ (WMEBackgroundAudioTrack*)createFromEmbeddedAudioTrack:(WMEEmbeddedAudioTrack*)embeddedAudioTrack;
+ (void)createFromFileAsync:(RTObject<WSIStorageFile>*)file
                    success:(void (^)(WMEBackgroundAudioTrack*))success
                    failure:(void (^)(NSError*))failure;
@property double volume;
@property (copy) WFTimeSpan* trimTimeFromStart;
@property (copy) WFTimeSpan* trimTimeFromEnd;
@property (copy) WFTimeSpan* delay;
@property (readonly) NSMutableArray* audioEffectDefinitions;
@property (readonly) WFTimeSpan* originalDuration;
@property (readonly) WFTimeSpan* trimmedDuration;
@property (readonly) NSMutableDictionary* userData;
- (WMEBackgroundAudioTrack*)clone;
- (WMMAudioEncodingProperties*)getAudioEncodingProperties;
@end

#endif // __WMEBackgroundAudioTrack_DEFINED__

// Windows.Media.Editing.MediaComposition
#ifndef __WMEMediaComposition_DEFINED__
#define __WMEMediaComposition_DEFINED__

WINRT_EXPORT
@interface WMEMediaComposition : RTObject
+ (void)loadAsync:(WSStorageFile*)file success:(void (^)(WMEMediaComposition*))success failure:(void (^)(NSError*))failure;
+ (instancetype)create ACTIVATOR;
@property (readonly) NSMutableArray* backgroundAudioTracks;
@property (readonly) NSMutableArray* clips;
@property (readonly) WFTimeSpan* duration;
@property (readonly) NSMutableDictionary* userData;
@property (readonly) NSMutableArray* overlayLayers;
- (WMEMediaComposition*)clone;
- (RTObject<WFIAsyncAction>*)saveAsync:(RTObject<WSIStorageFile>*)file;
- (void)getThumbnailAsync:(WFTimeSpan*)timeFromStart
              scaledWidth:(int)scaledWidth
             scaledHeight:(int)scaledHeight
           framePrecision:(WMEVideoFramePrecision)framePrecision
                  success:(void (^)(WGIImageStream*))success
                  failure:(void (^)(NSError*))failure;
- (void)getThumbnailsAsync:(id<NSFastEnumeration> /* WFTimeSpan* */)timesFromStart
               scaledWidth:(int)scaledWidth
              scaledHeight:(int)scaledHeight
            framePrecision:(WMEVideoFramePrecision)framePrecision
                   success:(void (^)(NSArray*))success
                   failure:(void (^)(NSError*))failure;
- (void)renderToFileAsync:(RTObject<WSIStorageFile>*)destination
                  success:(void (^)(WMTTranscodeFailureReason))success
                 progress:(void (^)(double))progress
                  failure:(void (^)(NSError*))failure;
- (void)renderToFileWithTrimmingPreferenceAsync:(RTObject<WSIStorageFile>*)destination
                             trimmingPreference:(WMEMediaTrimmingPreference)trimmingPreference
                                        success:(void (^)(WMTTranscodeFailureReason))success
                                       progress:(void (^)(double))progress
                                        failure:(void (^)(NSError*))failure;
- (void)renderToFileWithProfileAsync:(RTObject<WSIStorageFile>*)destination
                  trimmingPreference:(WMEMediaTrimmingPreference)trimmingPreference
                     encodingProfile:(WMMMediaEncodingProfile*)encodingProfile
                             success:(void (^)(WMTTranscodeFailureReason))success
                            progress:(void (^)(double))progress
                             failure:(void (^)(NSError*))failure;
- (WMMMediaEncodingProfile*)createDefaultEncodingProfile;
- (WMCMediaStreamSource*)generateMediaStreamSource;
- (WMCMediaStreamSource*)generateMediaStreamSourceWithProfile:(WMMMediaEncodingProfile*)encodingProfile;
- (WMCMediaStreamSource*)generatePreviewMediaStreamSource:(int)scaledWidth scaledHeight:(int)scaledHeight;
@end

#endif // __WMEMediaComposition_DEFINED__

// Windows.Media.Editing.MediaOverlayLayer
#ifndef __WMEMediaOverlayLayer_DEFINED__
#define __WMEMediaOverlayLayer_DEFINED__

WINRT_EXPORT
@interface WMEMediaOverlayLayer : RTObject
+ (WMEMediaOverlayLayer*)createWithCompositorDefinition:(RTObject<WMEIVideoCompositorDefinition>*)compositorDefinition ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject<WMEIVideoCompositorDefinition>* customCompositorDefinition;
@property (readonly) NSMutableArray* overlays;
- (WMEMediaOverlayLayer*)clone;
@end

#endif // __WMEMediaOverlayLayer_DEFINED__
