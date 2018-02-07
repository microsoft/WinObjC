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

// WindowsMediaFaceAnalysis.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIAFACEANALYSISEXPORT
#define OBJCUWPWINDOWSMEDIAFACEANALYSISEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaFaceAnalysis.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMFDetectedFace, WMFFaceTracker, WMFFaceDetector;
@protocol WMFIDetectedFace, WMFIFaceDetector, WMFIFaceDetectorStatics, WMFIFaceTracker, WMFIFaceTrackerStatics;

#include "WindowsGraphicsImaging.h"
#include "WindowsMedia.h"

#import <Foundation/Foundation.h>

// Windows.Media.FaceAnalysis.DetectedFace
#ifndef __WMFDetectedFace_DEFINED__
#define __WMFDetectedFace_DEFINED__

OBJCUWPWINDOWSMEDIAFACEANALYSISEXPORT
@interface WMFDetectedFace : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGIBitmapBounds* faceBox;
@end

#endif // __WMFDetectedFace_DEFINED__

// Windows.Media.FaceAnalysis.FaceTracker
#ifndef __WMFFaceTracker_DEFINED__
#define __WMFFaceTracker_DEFINED__

OBJCUWPWINDOWSMEDIAFACEANALYSISEXPORT
@interface WMFFaceTracker : RTObject
+ (void)createAsyncWithSuccess:(void (^)(WMFFaceTracker*))success failure:(void (^)(NSError*))failure;
+ (NSArray* /* WGIBitmapPixelFormat */)getSupportedBitmapPixelFormats;
+ (BOOL)isBitmapPixelFormatSupported:(WGIBitmapPixelFormat)bitmapPixelFormat;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WGIBitmapSize* minDetectableFaceSize;
@property (retain) WGIBitmapSize* maxDetectableFaceSize;
+ (BOOL)isSupported;
- (void)processNextFrameAsync:(WMVideoFrame*)videoFrame success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMFFaceTracker_DEFINED__

// Windows.Media.FaceAnalysis.FaceDetector
#ifndef __WMFFaceDetector_DEFINED__
#define __WMFFaceDetector_DEFINED__

OBJCUWPWINDOWSMEDIAFACEANALYSISEXPORT
@interface WMFFaceDetector : RTObject
+ (void)createAsyncWithSuccess:(void (^)(WMFFaceDetector*))success failure:(void (^)(NSError*))failure;
+ (NSArray* /* WGIBitmapPixelFormat */)getSupportedBitmapPixelFormats;
+ (BOOL)isBitmapPixelFormatSupported:(WGIBitmapPixelFormat)bitmapPixelFormat;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WGIBitmapSize* minDetectableFaceSize;
@property (retain) WGIBitmapSize* maxDetectableFaceSize;
+ (BOOL)isSupported;
- (void)detectFacesAsync:(WGISoftwareBitmap*)image success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success failure:(void (^)(NSError*))failure;
- (void)detectFacesWithSearchAreaAsync:(WGISoftwareBitmap*)image searchArea:(WGIBitmapBounds*)searchArea success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WMFFaceDetector_DEFINED__

