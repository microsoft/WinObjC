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

// WindowsApplicationModelDataTransferDragDropCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WADDCCoreDragInfo, WADDCCoreDragUIOverride, WADDCCoreDragDropManager, WADDCCoreDropOperationTargetRequestedEventArgs,
    WADDCCoreDragOperation;
@protocol WADDCICoreDragInfo
, WADDCICoreDragUIOverride, WADDCICoreDropOperationTarget, WADDCICoreDragOperation, WADDCICoreDragDropManagerStatics,
    WADDCICoreDragDropManager, WADDCICoreDropOperationTargetRequestedEventArgs;

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragUIContentMode
enum _WADDCCoreDragUIContentMode {
    WADDCCoreDragUIContentModeAuto = 0,
    WADDCCoreDragUIContentModeDeferred = 1,
};
typedef unsigned WADDCCoreDragUIContentMode;

#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsApplicationModelDataTransferDragDrop.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsImaging.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.ICoreDropOperationTarget
#ifndef __WADDCICoreDropOperationTarget_DEFINED__
#define __WADDCICoreDropOperationTarget_DEFINED__

@protocol WADDCICoreDropOperationTarget
- (void)enterAsync:(WADDCCoreDragInfo*)dragInfo
    dragUIOverride:(WADDCCoreDragUIOverride*)dragUIOverride
           success:(void (^)(WADDataPackageOperation))success
           failure:(void (^)(NSError*))failure;
- (void)overAsync:(WADDCCoreDragInfo*)dragInfo
   dragUIOverride:(WADDCCoreDragUIOverride*)dragUIOverride
          success:(void (^)(WADDataPackageOperation))success
          failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)leaveAsync:(WADDCCoreDragInfo*)dragInfo;
- (void)dropAsync:(WADDCCoreDragInfo*)dragInfo success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
@end

#endif // __WADDCICoreDropOperationTarget_DEFINED__

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragInfo
#ifndef __WADDCCoreDragInfo_DEFINED__
#define __WADDCCoreDragInfo_DEFINED__

WINRT_EXPORT
@interface WADDCCoreDragInfo : RTObject
@property (readonly) WADDataPackageView* data;
@property (readonly) WADDDragDropModifiers modifiers;
@property (readonly) WFPoint* position;
@end

#endif // __WADDCCoreDragInfo_DEFINED__

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragUIOverride
#ifndef __WADDCCoreDragUIOverride_DEFINED__
#define __WADDCCoreDragUIOverride_DEFINED__

WINRT_EXPORT
@interface WADDCCoreDragUIOverride : RTObject
@property BOOL isGlyphVisible;
@property BOOL isContentVisible;
@property BOOL isCaptionVisible;
@property (copy) NSString* caption;
- (void)setContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap;
- (void)setContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint;
- (void)clear;
@end

#endif // __WADDCCoreDragUIOverride_DEFINED__

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragDropManager
#ifndef __WADDCCoreDragDropManager_DEFINED__
#define __WADDCCoreDragDropManager_DEFINED__

WINRT_EXPORT
@interface WADDCCoreDragDropManager : RTObject
+ (WADDCCoreDragDropManager*)getForCurrentView;
@property BOOL areConcurrentOperationsEnabled;
- (EventRegistrationToken)addTargetRequestedEvent:(void (^)(WADDCCoreDragDropManager*, WADDCCoreDropOperationTargetRequestedEventArgs*))del;
- (void)removeTargetRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WADDCCoreDragDropManager_DEFINED__

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDropOperationTargetRequestedEventArgs
#ifndef __WADDCCoreDropOperationTargetRequestedEventArgs_DEFINED__
#define __WADDCCoreDropOperationTargetRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WADDCCoreDropOperationTargetRequestedEventArgs : RTObject
- (void)setTarget:(RTObject<WADDCICoreDropOperationTarget>*)target;
@end

#endif // __WADDCCoreDropOperationTargetRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragOperation
#ifndef __WADDCCoreDragOperation_DEFINED__
#define __WADDCCoreDragOperation_DEFINED__

WINRT_EXPORT
@interface WADDCCoreDragOperation : RTObject
+ (instancetype)create ACTIVATOR;
@property WADDCCoreDragUIContentMode dragUIContentMode;
@property (readonly) WADDataPackage* data;
- (void)setPointerId:(unsigned int)pointerId;
- (void)setDragUIContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap;
- (void)setDragUIContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint;
- (void)startAsyncWithSuccess:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
@end

#endif // __WADDCCoreDragOperation_DEFINED__
