//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsUIXamlMediaImaging.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
#define OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXamlMediaImaging.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXMIDownloadProgressEventArgs, WUXMIBitmapSource, WUXMIRenderTargetBitmap, WUXMISurfaceImageSource, WUXMIBitmapImage, WUXMIVirtualSurfaceImageSource, WUXMIWriteableBitmap, WUXMISvgImageSourceFailedEventArgs, WUXMISvgImageSourceOpenedEventArgs, WUXMIXamlRenderingBackgroundTask, WUXMISoftwareBitmapSource, WUXMISvgImageSource;
@protocol WUXMIIDownloadProgressEventArgs, WUXMIIBitmapSource, WUXMIIBitmapSourceStatics, WUXMIIBitmapSourceFactory, WUXMIIRenderTargetBitmap, WUXMIIRenderTargetBitmapStatics, WUXMIISurfaceImageSource, WUXMIISurfaceImageSourceFactory, WUXMIIBitmapImage, WUXMIIBitmapImageStatics, WUXMIIBitmapImageFactory, WUXMIIBitmapImage2, WUXMIIBitmapImageStatics2, WUXMIIBitmapImage3, WUXMIIBitmapImageStatics3, WUXMIIVirtualSurfaceImageSource, WUXMIIVirtualSurfaceImageSourceFactory, WUXMIIWriteableBitmap, WUXMIIWriteableBitmapFactory, WUXMIISvgImageSourceFailedEventArgs, WUXMIISvgImageSourceOpenedEventArgs, WUXMIIXamlRenderingBackgroundTask, WUXMIIXamlRenderingBackgroundTaskOverrides, WUXMIIXamlRenderingBackgroundTaskFactory, WUXMIISoftwareBitmapSource, WUXMIISvgImageSource, WUXMIISvgImageSourceStatics, WUXMIISvgImageSourceFactory;

// Windows.UI.Xaml.Media.Imaging.BitmapCreateOptions
enum _WUXMIBitmapCreateOptions {
    WUXMIBitmapCreateOptionsNone = 0,
    WUXMIBitmapCreateOptionsIgnoreImageCache = 8,
};
typedef unsigned WUXMIBitmapCreateOptions;

// Windows.UI.Xaml.Media.Imaging.DecodePixelType
enum _WUXMIDecodePixelType {
    WUXMIDecodePixelTypePhysical = 0,
    WUXMIDecodePixelTypeLogical = 1,
};
typedef unsigned WUXMIDecodePixelType;

// Windows.UI.Xaml.Media.Imaging.SvgImageSourceLoadStatus
enum _WUXMISvgImageSourceLoadStatus {
    WUXMISvgImageSourceLoadStatusSuccess = 0,
    WUXMISvgImageSourceLoadStatusNetworkError = 1,
    WUXMISvgImageSourceLoadStatusInvalidFormat = 2,
    WUXMISvgImageSourceLoadStatusOther = 3,
};
typedef unsigned WUXMISvgImageSourceLoadStatus;

#include "WindowsUIXamlMedia.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"
#include "WindowsUIXaml.h"
#include "WindowsApplicationModelBackground.h"
#include "WindowsUICore.h"
#include "WindowsGraphicsImaging.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void(^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.Imaging.DownloadProgressEventHandler
#ifndef __WUXMIDownloadProgressEventHandler__DEFINED
#define __WUXMIDownloadProgressEventHandler__DEFINED
typedef void(^WUXMIDownloadProgressEventHandler)(RTObject* sender, WUXMIDownloadProgressEventArgs* e);
#endif // __WUXMIDownloadProgressEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Media.Imaging.DownloadProgressEventHandler
#ifndef __WUXMIDownloadProgressEventHandler__DEFINED
#define __WUXMIDownloadProgressEventHandler__DEFINED
typedef void(^WUXMIDownloadProgressEventHandler)(RTObject* sender, WUXMIDownloadProgressEventArgs* e);
#endif // __WUXMIDownloadProgressEventHandler__DEFINED

// Windows.UI.Xaml.Media.Imaging.IXamlRenderingBackgroundTaskOverrides
#ifndef __WUXMIIXamlRenderingBackgroundTaskOverrides_DEFINED__
#define __WUXMIIXamlRenderingBackgroundTaskOverrides_DEFINED__

@protocol WUXMIIXamlRenderingBackgroundTaskOverrides
- (void)onRun:(RTObject<WABIBackgroundTaskInstance>*)taskInstance;
@end

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIIXamlRenderingBackgroundTaskOverrides : RTObject <WUXMIIXamlRenderingBackgroundTaskOverrides>
@end

#endif // __WUXMIIXamlRenderingBackgroundTaskOverrides_DEFINED__

// Windows.UI.Xaml.Media.Imaging.DownloadProgressEventArgs
#ifndef __WUXMIDownloadProgressEventArgs_DEFINED__
#define __WUXMIDownloadProgressEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIDownloadProgressEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int progress;
@end

#endif // __WUXMIDownloadProgressEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WXDependencyObject : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Media.ImageSource
#ifndef __WUXMImageSource_DEFINED__
#define __WUXMImageSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMImageSource : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMImageSource_DEFINED__

// Windows.UI.Xaml.Media.Imaging.BitmapSource
#ifndef __WUXMIBitmapSource_DEFINED__
#define __WUXMIBitmapSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIBitmapSource : WUXMImageSource
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int pixelHeight;
@property (readonly) int pixelWidth;
+ (WXDependencyProperty*)pixelHeightProperty;
+ (WXDependencyProperty*)pixelWidthProperty;
- (void)setSource:(RTObject<WSSIRandomAccessStream>*)streamSource;
- (RTObject<WFIAsyncAction>*)setSourceAsync:(RTObject<WSSIRandomAccessStream>*)streamSource;
@end

#endif // __WUXMIBitmapSource_DEFINED__

// Windows.UI.Xaml.Media.Imaging.RenderTargetBitmap
#ifndef __WUXMIRenderTargetBitmap_DEFINED__
#define __WUXMIRenderTargetBitmap_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIRenderTargetBitmap : WUXMImageSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int pixelHeight;
@property (readonly) int pixelWidth;
+ (WXDependencyProperty*)pixelHeightProperty;
+ (WXDependencyProperty*)pixelWidthProperty;
- (RTObject<WFIAsyncAction>*)renderAsync:(WXUIElement*)element;
- (RTObject<WFIAsyncAction>*)renderToSizeAsync:(WXUIElement*)element scaledWidth:(int)scaledWidth scaledHeight:(int)scaledHeight;
- (void)getPixelsAsyncWithSuccess:(void (^)(RTObject<WSSIBuffer>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUXMIRenderTargetBitmap_DEFINED__

// Windows.UI.Xaml.Media.Imaging.SurfaceImageSource
#ifndef __WUXMISurfaceImageSource_DEFINED__
#define __WUXMISurfaceImageSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMISurfaceImageSource : WUXMImageSource
+ (WUXMISurfaceImageSource*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight ACTIVATOR;
+ (WUXMISurfaceImageSource*)makeInstanceWithDimensionsAndOpacity:(int)pixelWidth pixelHeight:(int)pixelHeight isOpaque:(BOOL)isOpaque ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMISurfaceImageSource_DEFINED__

// Windows.UI.Xaml.Media.Imaging.BitmapImage
#ifndef __WUXMIBitmapImage_DEFINED__
#define __WUXMIBitmapImage_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIBitmapImage : WUXMIBitmapSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
+ (WUXMIBitmapImage*)makeInstanceWithUriSource:(WFUri*)uriSource ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uriSource;
@property int decodePixelWidth;
@property int decodePixelHeight;
@property WUXMIBitmapCreateOptions createOptions;
@property WUXMIDecodePixelType decodePixelType;
@property BOOL autoPlay;
@property (readonly) BOOL isAnimatedBitmap;
@property (readonly) BOOL isPlaying;
+ (WXDependencyProperty*)createOptionsProperty;
+ (WXDependencyProperty*)decodePixelHeightProperty;
+ (WXDependencyProperty*)decodePixelWidthProperty;
+ (WXDependencyProperty*)uriSourceProperty;
+ (WXDependencyProperty*)decodePixelTypeProperty;
+ (WXDependencyProperty*)autoPlayProperty;
+ (WXDependencyProperty*)isAnimatedBitmapProperty;
+ (WXDependencyProperty*)isPlayingProperty;
- (EventRegistrationToken)addDownloadProgressEvent:(WUXMIDownloadProgressEventHandler)del;
- (void)removeDownloadProgressEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)del;
- (void)removeImageFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeImageOpenedEvent:(EventRegistrationToken)tok;
- (void)play;
- (void)stop;
@end

#endif // __WUXMIBitmapImage_DEFINED__

// Windows.UI.Xaml.Media.Imaging.VirtualSurfaceImageSource
#ifndef __WUXMIVirtualSurfaceImageSource_DEFINED__
#define __WUXMIVirtualSurfaceImageSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIVirtualSurfaceImageSource : WUXMISurfaceImageSource
+ (WUXMIVirtualSurfaceImageSource*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight ACTIVATOR;
+ (WUXMIVirtualSurfaceImageSource*)makeInstanceWithDimensionsAndOpacity:(int)pixelWidth pixelHeight:(int)pixelHeight isOpaque:(BOOL)isOpaque ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMIVirtualSurfaceImageSource_DEFINED__

// Windows.UI.Xaml.Media.Imaging.WriteableBitmap
#ifndef __WUXMIWriteableBitmap_DEFINED__
#define __WUXMIWriteableBitmap_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIWriteableBitmap : WUXMIBitmapSource
+ (WUXMIWriteableBitmap*)makeInstanceWithDimensions:(int)pixelWidth pixelHeight:(int)pixelHeight ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject<WSSIBuffer>* pixelBuffer;
- (void)invalidate;
@end

#endif // __WUXMIWriteableBitmap_DEFINED__

// Windows.UI.Xaml.Media.Imaging.SvgImageSourceFailedEventArgs
#ifndef __WUXMISvgImageSourceFailedEventArgs_DEFINED__
#define __WUXMISvgImageSourceFailedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMISvgImageSourceFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXMISvgImageSourceLoadStatus status;
@end

#endif // __WUXMISvgImageSourceFailedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.Imaging.SvgImageSourceOpenedEventArgs
#ifndef __WUXMISvgImageSourceOpenedEventArgs_DEFINED__
#define __WUXMISvgImageSourceOpenedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMISvgImageSourceOpenedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXMISvgImageSourceOpenedEventArgs_DEFINED__

// Windows.UI.Xaml.Media.Imaging.XamlRenderingBackgroundTask
#ifndef __WUXMIXamlRenderingBackgroundTask_DEFINED__
#define __WUXMIXamlRenderingBackgroundTask_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMIXamlRenderingBackgroundTask : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)onRun:(RTObject<WABIBackgroundTaskInstance>*)taskInstance;
@end

#endif // __WUXMIXamlRenderingBackgroundTask_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.UI.Xaml.Media.Imaging.SoftwareBitmapSource
#ifndef __WUXMISoftwareBitmapSource_DEFINED__
#define __WUXMISoftwareBitmapSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMISoftwareBitmapSource : WUXMImageSource <WFIClosable>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (RTObject<WFIAsyncAction>*)setBitmapAsync:(WGISoftwareBitmap*)softwareBitmap;
- (void)close;
@end

#endif // __WUXMISoftwareBitmapSource_DEFINED__

// Windows.UI.Xaml.Media.Imaging.SvgImageSource
#ifndef __WUXMISvgImageSource_DEFINED__
#define __WUXMISvgImageSource_DEFINED__

OBJCUWPWINDOWSUIXAMLMEDIAIMAGINGEXPORT
@interface WUXMISvgImageSource : WUXMImageSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uriSource;
@property double rasterizePixelWidth;
@property double rasterizePixelHeight;
+ (WXDependencyProperty*)rasterizePixelHeightProperty;
+ (WXDependencyProperty*)rasterizePixelWidthProperty;
+ (WXDependencyProperty*)uriSourceProperty;
- (EventRegistrationToken)addOpenFailedEvent:(void(^)(WUXMISvgImageSource*, WUXMISvgImageSourceFailedEventArgs*))del;
- (void)removeOpenFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void(^)(WUXMISvgImageSource*, WUXMISvgImageSourceOpenedEventArgs*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (void)setSourceAsync:(RTObject<WSSIRandomAccessStream>*)streamSource success:(void (^)(WUXMISvgImageSourceLoadStatus))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUXMISvgImageSource_DEFINED__

