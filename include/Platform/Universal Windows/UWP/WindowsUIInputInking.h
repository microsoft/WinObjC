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

// WindowsUIInputInking.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUIIInkUnprocessedInput, WUIIInkStrokeInput, WUIIInkInputProcessingConfiguration, WUIIInkSynchronizer, WUIIInkPresenter,
    WUIIInkStrokesCollectedEventArgs, WUIIInkStrokesErasedEventArgs, WUIIInkPoint, WUIIInkDrawingAttributes, WUIIInkStrokeRenderingSegment,
    WUIIInkStroke, WUIIInkStrokeBuilder, WUIIInkRecognitionResult, WUIIInkStrokeContainer, WUIIInkRecognizer, WUIIInkRecognizerContainer,
    WUIIInkManager;
@protocol WUIIIInkStrokesCollectedEventArgs
, WUIIIInkStrokesErasedEventArgs, WUIIIInkPresenter, WUIIIInkInputProcessingConfiguration, WUIIIInkSynchronizer, WUIIIInkUnprocessedInput,
    WUIIIInkStrokeInput, WUIIIInkPoint, WUIIIInkPointFactory, WUIIIInkDrawingAttributes, WUIIIInkDrawingAttributes2,
    WUIIIInkStrokeRenderingSegment, WUIIIInkStroke, WUIIIInkStroke2, WUIIIInkStrokeBuilder, WUIIIInkStrokeBuilder2,
    WUIIIInkRecognitionResult, WUIIIInkStrokeContainer, WUIIIInkStrokeContainer2, WUIIIInkRecognizer, WUIIIInkRecognizerContainer,
    WUIIIInkManager;

// Windows.UI.Input.Inking.InkPresenterPredefinedConfiguration
enum _WUIIInkPresenterPredefinedConfiguration {
    WUIIInkPresenterPredefinedConfigurationSimpleSinglePointer = 0,
    WUIIInkPresenterPredefinedConfigurationSimpleMultiplePointer = 1,
};
typedef unsigned WUIIInkPresenterPredefinedConfiguration;

// Windows.UI.Input.Inking.InkInputRightDragAction
enum _WUIIInkInputRightDragAction {
    WUIIInkInputRightDragActionLeaveUnprocessed = 0,
    WUIIInkInputRightDragActionAllowProcessing = 1,
};
typedef unsigned WUIIInkInputRightDragAction;

// Windows.UI.Input.Inking.InkInputProcessingMode
enum _WUIIInkInputProcessingMode {
    WUIIInkInputProcessingModeNone = 0,
    WUIIInkInputProcessingModeInking = 1,
    WUIIInkInputProcessingModeErasing = 2,
};
typedef unsigned WUIIInkInputProcessingMode;

// Windows.UI.Input.Inking.InkManipulationMode
enum _WUIIInkManipulationMode {
    WUIIInkManipulationModeInking = 0,
    WUIIInkManipulationModeErasing = 1,
    WUIIInkManipulationModeSelecting = 2,
};
typedef unsigned WUIIInkManipulationMode;

// Windows.UI.Input.Inking.InkRecognitionTarget
enum _WUIIInkRecognitionTarget {
    WUIIInkRecognitionTargetAll = 0,
    WUIIInkRecognitionTargetSelected = 1,
    WUIIInkRecognitionTargetRecent = 2,
};
typedef unsigned WUIIInkRecognitionTarget;

// Windows.UI.Input.Inking.PenTipShape
enum _WUIIPenTipShape {
    WUIIPenTipShapeCircle = 0,
    WUIIPenTipShapeRectangle = 1,
};
typedef unsigned WUIIPenTipShape;

#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsUIInput.h"
#include "WindowsUI.h"
#include "WindowsFoundationNumerics.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.IInkPointFactory
#ifndef __WUIIIInkPointFactory_DEFINED__
#define __WUIIIInkPointFactory_DEFINED__

@protocol WUIIIInkPointFactory
- (WUIIInkPoint*)createInkPoint:(WFPoint*)position pressure:(float)pressure;
@end

#endif // __WUIIIInkPointFactory_DEFINED__

// Windows.UI.Input.Inking.IInkStrokeContainer
#ifndef __WUIIIInkStrokeContainer_DEFINED__
#define __WUIIIInkStrokeContainer_DEFINED__

@protocol WUIIIInkStrokeContainer
@property (readonly) WFRect* boundingRect;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray*)getStrokes;
- (NSArray*)getRecognitionResults;
@end

#endif // __WUIIIInkStrokeContainer_DEFINED__

// Windows.UI.Input.Inking.IInkRecognizerContainer
#ifndef __WUIIIInkRecognizerContainer_DEFINED__
#define __WUIIIInkRecognizerContainer_DEFINED__

@protocol WUIIIInkRecognizerContainer
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray*))success
               failure:(void (^)(NSError*))failure;
- (NSArray*)getRecognizers;
@end

#endif // __WUIIIInkRecognizerContainer_DEFINED__

// Windows.UI.Input.Inking.InkUnprocessedInput
#ifndef __WUIIInkUnprocessedInput_DEFINED__
#define __WUIIInkUnprocessedInput_DEFINED__

WINRT_EXPORT
@interface WUIIInkUnprocessedInput : RTObject
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addPointerEnteredEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerHoveredEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerHoveredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerLostEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void (^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIIInkUnprocessedInput_DEFINED__

// Windows.UI.Input.Inking.InkStrokeInput
#ifndef __WUIIInkStrokeInput_DEFINED__
#define __WUIIInkStrokeInput_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokeInput : RTObject
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addStrokeCanceledEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeContinuedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeContinuedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeEndedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeStartedEvent:(void (^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeStartedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIIInkStrokeInput_DEFINED__

// Windows.UI.Input.Inking.InkInputProcessingConfiguration
#ifndef __WUIIInkInputProcessingConfiguration_DEFINED__
#define __WUIIInkInputProcessingConfiguration_DEFINED__

WINRT_EXPORT
@interface WUIIInkInputProcessingConfiguration : RTObject
@property WUIIInkInputRightDragAction rightDragAction;
@property WUIIInkInputProcessingMode mode;
@end

#endif // __WUIIInkInputProcessingConfiguration_DEFINED__

// Windows.UI.Input.Inking.InkSynchronizer
#ifndef __WUIIInkSynchronizer_DEFINED__
#define __WUIIInkSynchronizer_DEFINED__

WINRT_EXPORT
@interface WUIIInkSynchronizer : RTObject
- (NSArray*)beginDry;
- (void)endDry;
@end

#endif // __WUIIInkSynchronizer_DEFINED__

// Windows.UI.Input.Inking.InkPresenter
#ifndef __WUIIInkPresenter_DEFINED__
#define __WUIIInkPresenter_DEFINED__

WINRT_EXPORT
@interface WUIIInkPresenter : RTObject
@property (copy) WUIIInkStrokeContainer* strokeContainer;
@property BOOL isInputEnabled;
@property WUCCoreInputDeviceTypes inputDeviceTypes;
@property (readonly) WUIIInkInputProcessingConfiguration* inputProcessingConfiguration;
@property (readonly) WUIIInkStrokeInput* strokeInput;
@property (readonly) WUIIInkUnprocessedInput* unprocessedInput;
- (EventRegistrationToken)addStrokesCollectedEvent:(void (^)(WUIIInkPresenter*, WUIIInkStrokesCollectedEventArgs*))del;
- (void)removeStrokesCollectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokesErasedEvent:(void (^)(WUIIInkPresenter*, WUIIInkStrokesErasedEventArgs*))del;
- (void)removeStrokesErasedEvent:(EventRegistrationToken)tok;
- (WUIIInkDrawingAttributes*)copyDefaultDrawingAttributes;
- (void)updateDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)value;
- (WUIIInkSynchronizer*)activateCustomDrying;
- (void)setPredefinedConfiguration:(WUIIInkPresenterPredefinedConfiguration)value;
@end

#endif // __WUIIInkPresenter_DEFINED__

// Windows.UI.Input.Inking.InkStrokesCollectedEventArgs
#ifndef __WUIIInkStrokesCollectedEventArgs_DEFINED__
#define __WUIIInkStrokesCollectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokesCollectedEventArgs : RTObject
@property (readonly) NSArray* strokes;
@end

#endif // __WUIIInkStrokesCollectedEventArgs_DEFINED__

// Windows.UI.Input.Inking.InkStrokesErasedEventArgs
#ifndef __WUIIInkStrokesErasedEventArgs_DEFINED__
#define __WUIIInkStrokesErasedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokesErasedEventArgs : RTObject
@property (readonly) NSArray* strokes;
@end

#endif // __WUIIInkStrokesErasedEventArgs_DEFINED__

// Windows.UI.Input.Inking.InkPoint
#ifndef __WUIIInkPoint_DEFINED__
#define __WUIIInkPoint_DEFINED__

WINRT_EXPORT
@interface WUIIInkPoint : RTObject
+ (WUIIInkPoint*)createInkPoint:(WFPoint*)position pressure:(float)pressure ACTIVATOR;
@property (readonly) WFPoint* position;
@property (readonly) float pressure;
@end

#endif // __WUIIInkPoint_DEFINED__

// Windows.UI.Input.Inking.InkDrawingAttributes
#ifndef __WUIIInkDrawingAttributes_DEFINED__
#define __WUIIInkDrawingAttributes_DEFINED__

WINRT_EXPORT
@interface WUIIInkDrawingAttributes : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFSize* size;
@property WUIIPenTipShape penTip;
@property BOOL ignorePressure;
@property BOOL fitToCurve;
@property (copy) WUColor* color;
@property (copy) WFNMatrix3x2* penTipTransform;
@property BOOL drawAsHighlighter;
@end

#endif // __WUIIInkDrawingAttributes_DEFINED__

// Windows.UI.Input.Inking.InkStrokeRenderingSegment
#ifndef __WUIIInkStrokeRenderingSegment_DEFINED__
#define __WUIIInkStrokeRenderingSegment_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokeRenderingSegment : RTObject
@property (readonly) WFPoint* bezierControlPoint1;
@property (readonly) WFPoint* bezierControlPoint2;
@property (readonly) WFPoint* position;
@property (readonly) float pressure;
@property (readonly) float tiltX;
@property (readonly) float tiltY;
@property (readonly) float twist;
@end

#endif // __WUIIInkStrokeRenderingSegment_DEFINED__

// Windows.UI.Input.Inking.InkStroke
#ifndef __WUIIInkStroke_DEFINED__
#define __WUIIInkStroke_DEFINED__

WINRT_EXPORT
@interface WUIIInkStroke : RTObject
@property BOOL selected;
@property (copy) WUIIInkDrawingAttributes* drawingAttributes;
@property (readonly) WFRect* boundingRect;
@property (readonly) BOOL recognized;
@property (copy) WFNMatrix3x2* pointTransform;
- (NSArray*)getRenderingSegments;
- (WUIIInkStroke*)clone;
- (NSArray*)getInkPoints;
@end

#endif // __WUIIInkStroke_DEFINED__

// Windows.UI.Input.Inking.InkStrokeBuilder
#ifndef __WUIIInkStrokeBuilder_DEFINED__
#define __WUIIInkStrokeBuilder_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokeBuilder : RTObject
+ (instancetype)create ACTIVATOR;
- (void)beginStroke:(WUIPointerPoint*)pointerPoint;
- (WUIPointerPoint*)appendToStroke:(WUIPointerPoint*)pointerPoint;
- (WUIIInkStroke*)endStroke:(WUIPointerPoint*)pointerPoint;
- (WUIIInkStroke*)createStroke:(id<NSFastEnumeration> /* WFPoint* */)points;
- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes;
- (WUIIInkStroke*)createStrokeFromInkPoints:(id<NSFastEnumeration> /* WUIIInkPoint* */)inkPoints transform:(WFNMatrix3x2*)transform;
@end

#endif // __WUIIInkStrokeBuilder_DEFINED__

// Windows.UI.Input.Inking.InkRecognitionResult
#ifndef __WUIIInkRecognitionResult_DEFINED__
#define __WUIIInkRecognitionResult_DEFINED__

WINRT_EXPORT
@interface WUIIInkRecognitionResult : RTObject
@property (readonly) WFRect* boundingRect;
- (NSArray*)getTextCandidates;
- (NSArray*)getStrokes;
@end

#endif // __WUIIInkRecognitionResult_DEFINED__

// Windows.UI.Input.Inking.InkStrokeContainer
#ifndef __WUIIInkStrokeContainer_DEFINED__
#define __WUIIInkStrokeContainer_DEFINED__

WINRT_EXPORT
@interface WUIIInkStrokeContainer : RTObject <WUIIIInkStrokeContainer>
+ (instancetype)create ACTIVATOR;
@property (readonly) WFRect* boundingRect;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray*)getStrokes;
- (NSArray*)getRecognitionResults;
- (void)addStrokes:(id<NSFastEnumeration> /* WUIIInkStroke* */)strokes;
- (void)clear;
@end

#endif // __WUIIInkStrokeContainer_DEFINED__

// Windows.UI.Input.Inking.InkRecognizer
#ifndef __WUIIInkRecognizer_DEFINED__
#define __WUIIInkRecognizer_DEFINED__

WINRT_EXPORT
@interface WUIIInkRecognizer : RTObject
@property (readonly) NSString* name;
@end

#endif // __WUIIInkRecognizer_DEFINED__

// Windows.UI.Input.Inking.InkRecognizerContainer
#ifndef __WUIIInkRecognizerContainer_DEFINED__
#define __WUIIInkRecognizerContainer_DEFINED__

WINRT_EXPORT
@interface WUIIInkRecognizerContainer : RTObject <WUIIIInkRecognizerContainer>
+ (instancetype)create ACTIVATOR;
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray*))success
               failure:(void (^)(NSError*))failure;
- (NSArray*)getRecognizers;
@end

#endif // __WUIIInkRecognizerContainer_DEFINED__

// Windows.UI.Input.Inking.InkManager
#ifndef __WUIIInkManager_DEFINED__
#define __WUIIInkManager_DEFINED__

WINRT_EXPORT
@interface WUIIInkManager : RTObject <WUIIIInkRecognizerContainer, WUIIIInkStrokeContainer>
+ (instancetype)create ACTIVATOR;
@property WUIIInkManipulationMode mode;
@property (readonly) WFRect* boundingRect;
- (void)processPointerDown:(WUIPointerPoint*)pointerPoint;
- (RTObject*)processPointerUpdate:(WUIPointerPoint*)pointerPoint;
- (WFRect*)processPointerUp:(WUIPointerPoint*)pointerPoint;
- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes;
- (void)recognizeAsync2:(WUIIInkRecognitionTarget)recognitionTarget success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned int))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray*)getStrokes;
- (NSArray*)getRecognitionResults;
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(NSArray*))success
               failure:(void (^)(NSError*))failure;
- (NSArray*)getRecognizers;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
@end

#endif // __WUIIInkManager_DEFINED__
