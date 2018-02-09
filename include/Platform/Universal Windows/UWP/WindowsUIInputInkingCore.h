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

// WindowsUIInputInkingCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
#define OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputInkingCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUIICCoreInkIndependentInputSource, WUIICCoreWetStrokeUpdateEventArgs, WUIICCoreWetStrokeUpdateSource, WUIICCoreInkPresenterHost, WUIICCoreIncrementalInkStroke;
@protocol WUIICICoreInkIndependentInputSource, WUIICICoreInkIndependentInputSourceStatics, WUIICICoreWetStrokeUpdateEventArgs, WUIICICoreWetStrokeUpdateSource, WUIICICoreWetStrokeUpdateSourceStatics, WUIICICoreInkPresenterHost, WUIICICoreIncrementalInkStroke, WUIICICoreIncrementalInkStrokeFactory;

// Windows.UI.Input.Inking.Core.CoreWetStrokeDisposition
enum _WUIICCoreWetStrokeDisposition {
    WUIICCoreWetStrokeDispositionInking = 0,
    WUIICCoreWetStrokeDispositionCompleted = 1,
    WUIICCoreWetStrokeDispositionCanceled = 2,
};
typedef unsigned WUIICCoreWetStrokeDisposition;

#include "WindowsFoundation.h"
#include "WindowsUICore.h"
#include "WindowsUIInputInking.h"
#include "WindowsUIComposition.h"
#include "WindowsFoundationNumerics.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.Core.CoreInkIndependentInputSource
#ifndef __WUIICCoreInkIndependentInputSource_DEFINED__
#define __WUIICCoreInkIndependentInputSource_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
@interface WUIICCoreInkIndependentInputSource : RTObject
+ (WUIICCoreInkIndependentInputSource*)create:(WUIIInkPresenter*)inkPresenter;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addPointerEnteringEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerEnteringEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitingEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerExitingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerHoveringEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerHoveringEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerLostEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovingEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerMovingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressingEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerPressingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasingEvent:(void(^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerReleasingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIICCoreInkIndependentInputSource_DEFINED__

// Windows.UI.Input.Inking.Core.CoreWetStrokeUpdateEventArgs
#ifndef __WUIICCoreWetStrokeUpdateEventArgs_DEFINED__
#define __WUIICCoreWetStrokeUpdateEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
@interface WUIICCoreWetStrokeUpdateEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUIICCoreWetStrokeDisposition disposition;
@property (readonly) NSMutableArray* /* WUIIInkPoint* */ newInkPoints __attribute__ ((ns_returns_not_retained));
@property (readonly) unsigned int pointerId;
@end

#endif // __WUIICCoreWetStrokeUpdateEventArgs_DEFINED__

// Windows.UI.Input.Inking.Core.CoreWetStrokeUpdateSource
#ifndef __WUIICCoreWetStrokeUpdateSource_DEFINED__
#define __WUIICCoreWetStrokeUpdateSource_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
@interface WUIICCoreWetStrokeUpdateSource : RTObject
+ (WUIICCoreWetStrokeUpdateSource*)create:(WUIIInkPresenter*)inkPresenter;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addWetStrokeCanceledEvent:(void(^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))del;
- (void)removeWetStrokeCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWetStrokeCompletedEvent:(void(^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))del;
- (void)removeWetStrokeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWetStrokeContinuingEvent:(void(^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))del;
- (void)removeWetStrokeContinuingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWetStrokeStartingEvent:(void(^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))del;
- (void)removeWetStrokeStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addWetStrokeStoppingEvent:(void(^)(WUIICCoreWetStrokeUpdateSource*, WUIICCoreWetStrokeUpdateEventArgs*))del;
- (void)removeWetStrokeStoppingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIICCoreWetStrokeUpdateSource_DEFINED__

// Windows.UI.Input.Inking.Core.CoreInkPresenterHost
#ifndef __WUIICCoreInkPresenterHost_DEFINED__
#define __WUIICCoreInkPresenterHost_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
@interface WUIICCoreInkPresenterHost : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUCContainerVisual* rootVisual;
@property (readonly) WUIIInkPresenter* inkPresenter;
@end

#endif // __WUIICCoreInkPresenterHost_DEFINED__

// Windows.UI.Input.Inking.Core.CoreIncrementalInkStroke
#ifndef __WUIICCoreIncrementalInkStroke_DEFINED__
#define __WUIICCoreIncrementalInkStroke_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGCOREEXPORT
@interface WUIICCoreIncrementalInkStroke : RTObject
+ (WUIICCoreIncrementalInkStroke*)make:(WUIIInkDrawingAttributes*)drawingAttributes pointTransform:(WFNMatrix3x2*)pointTransform ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) WUIIInkDrawingAttributes* drawingAttributes;
@property (readonly) WFNMatrix3x2* pointTransform;
- (WFRect*)appendInkPoints:(id<NSFastEnumeration> /* WUIIInkPoint* */)inkPoints;
- (WUIIInkStroke*)createInkStroke;
@end

#endif // __WUIICCoreIncrementalInkStroke_DEFINED__

