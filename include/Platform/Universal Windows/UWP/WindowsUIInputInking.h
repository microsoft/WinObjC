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

// WindowsUIInputInking.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTINKINGEXPORT
#define OBJCUWPWINDOWSUIINPUTINKINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputInking.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUIIInkUnprocessedInput, WUIIInkStrokeInput, WUIIInkInputProcessingConfiguration, WUIIInkSynchronizer, WUIIInkPresenter, WUIIInkStrokesCollectedEventArgs, WUIIInkStrokesErasedEventArgs, WUIIInkPresenterRuler, WUIIInkPresenterProtractor, WUIIInkPoint, WUIIInkDrawingAttributesPencilProperties, WUIIInkDrawingAttributes, WUIIInkStrokeRenderingSegment, WUIIInkStroke, WUIIInkStrokeBuilder, WUIIInkRecognitionResult, WUIIInkStrokeContainer, WUIIInkRecognizer, WUIIInkRecognizerContainer, WUIIInkManager;
@protocol WUIIIInkStrokesCollectedEventArgs, WUIIIInkStrokesErasedEventArgs, WUIIIInkPresenter, WUIIIInkPresenter2, WUIIIInkInputProcessingConfiguration, WUIIIInkSynchronizer, WUIIIInkUnprocessedInput, WUIIIInkStrokeInput, WUIIIInkPresenterStencil, WUIIIInkPresenterRuler, WUIIIInkPresenterRuler2, WUIIIInkPresenterProtractor, WUIIIInkPresenterRulerFactory, WUIIIInkPresenterProtractorFactory, WUIIIInkPoint, WUIIIInkPoint2, WUIIIInkPointFactory, WUIIIInkPointFactory2, WUIIIInkDrawingAttributes, WUIIIInkDrawingAttributes2, WUIIIInkDrawingAttributesPencilProperties, WUIIIInkDrawingAttributes3, WUIIIInkDrawingAttributes4, WUIIIInkDrawingAttributesStatics, WUIIIInkStrokeRenderingSegment, WUIIIInkStroke, WUIIIInkStroke2, WUIIIInkStroke3, WUIIIInkStrokeBuilder, WUIIIInkStrokeBuilder2, WUIIIInkStrokeBuilder3, WUIIIInkRecognitionResult, WUIIIInkStrokeContainer, WUIIIInkStrokeContainer2, WUIIIInkStrokeContainer3, WUIIIInkRecognizer, WUIIIInkRecognizerContainer, WUIIIInkManager;

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

// Windows.UI.Input.Inking.InkPresenterStencilKind
enum _WUIIInkPresenterStencilKind {
    WUIIInkPresenterStencilKindOther = 0,
    WUIIInkPresenterStencilKindRuler = 1,
    WUIIInkPresenterStencilKindProtractor = 2,
};
typedef unsigned WUIIInkPresenterStencilKind;

// Windows.UI.Input.Inking.InkHighContrastAdjustment
enum _WUIIInkHighContrastAdjustment {
    WUIIInkHighContrastAdjustmentUseSystemColorsWhenNecessary = 0,
    WUIIInkHighContrastAdjustmentUseSystemColors = 1,
    WUIIInkHighContrastAdjustmentUseOriginalColors = 2,
};
typedef unsigned WUIIInkHighContrastAdjustment;

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

// Windows.UI.Input.Inking.InkDrawingAttributesKind
enum _WUIIInkDrawingAttributesKind {
    WUIIInkDrawingAttributesKindDefault = 0,
    WUIIInkDrawingAttributesKindPencil = 1,
};
typedef unsigned WUIIInkDrawingAttributesKind;

// Windows.UI.Input.Inking.InkPersistenceFormat
enum _WUIIInkPersistenceFormat {
    WUIIInkPersistenceFormatGifWithEmbeddedIsf = 0,
    WUIIInkPersistenceFormatIsf = 1,
};
typedef unsigned WUIIInkPersistenceFormat;

#include "WindowsUICore.h"
#include "WindowsFoundation.h"
#include "WindowsUIInput.h"
#include "WindowsUI.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.IInkPresenterStencil
#ifndef __WUIIIInkPresenterStencil_DEFINED__
#define __WUIIIInkPresenterStencil_DEFINED__

@protocol WUIIIInkPresenterStencil
@property (retain) WUColor* backgroundColor;
@property (retain) WUColor* foregroundColor;
@property BOOL isVisible;
@property (readonly) WUIIInkPresenterStencilKind kind;
@property (retain) WFNMatrix3x2* transform;
@end

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIIInkPresenterStencil : RTObject <WUIIIInkPresenterStencil>
@end

#endif // __WUIIIInkPresenterStencil_DEFINED__

// Windows.UI.Input.Inking.IInkPresenterRulerFactory
#ifndef __WUIIIInkPresenterRulerFactory_DEFINED__
#define __WUIIIInkPresenterRulerFactory_DEFINED__

@protocol WUIIIInkPresenterRulerFactory
- (WUIIInkPresenterRuler*)create:(WUIIInkPresenter*)inkPresenter;
@end

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIIInkPresenterRulerFactory : RTObject <WUIIIInkPresenterRulerFactory>
@end

#endif // __WUIIIInkPresenterRulerFactory_DEFINED__

// Windows.UI.Input.Inking.IInkPointFactory
#ifndef __WUIIIInkPointFactory_DEFINED__
#define __WUIIIInkPointFactory_DEFINED__

@protocol WUIIIInkPointFactory
- (WUIIInkPoint*)createInkPoint:(WFPoint*)position pressure:(float)pressure;
@end

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIIInkPointFactory : RTObject <WUIIIInkPointFactory>
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
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray* /* WUIIInkStroke* */)getStrokes;
- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults;
@end

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIIInkStrokeContainer : RTObject <WUIIIInkStrokeContainer>
@end

#endif // __WUIIIInkStrokeContainer_DEFINED__

// Windows.UI.Input.Inking.IInkRecognizerContainer
#ifndef __WUIIIInkRecognizerContainer_DEFINED__
#define __WUIIIInkRecognizerContainer_DEFINED__

@protocol WUIIIInkRecognizerContainer
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WUIIInkRecognizer* */)getRecognizers;
@end

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIIInkRecognizerContainer : RTObject <WUIIIInkRecognizerContainer>
@end

#endif // __WUIIIInkRecognizerContainer_DEFINED__

// Windows.UI.Input.Inking.InkUnprocessedInput
#ifndef __WUIIInkUnprocessedInput_DEFINED__
#define __WUIIInkUnprocessedInput_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkUnprocessedInput : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addPointerEnteredEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerHoveredEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerHoveredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerLostEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(void(^)(WUIIInkUnprocessedInput*, WUCPointerEventArgs*))del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIIInkUnprocessedInput_DEFINED__

// Windows.UI.Input.Inking.InkStrokeInput
#ifndef __WUIIInkStrokeInput_DEFINED__
#define __WUIIInkStrokeInput_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokeInput : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addStrokeCanceledEvent:(void(^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeContinuedEvent:(void(^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeContinuedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeEndedEvent:(void(^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokeStartedEvent:(void(^)(WUIIInkStrokeInput*, WUCPointerEventArgs*))del;
- (void)removeStrokeStartedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIIInkStrokeInput_DEFINED__

// Windows.UI.Input.Inking.InkInputProcessingConfiguration
#ifndef __WUIIInkInputProcessingConfiguration_DEFINED__
#define __WUIIInkInputProcessingConfiguration_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkInputProcessingConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUIIInkInputRightDragAction rightDragAction;
@property WUIIInkInputProcessingMode mode;
@end

#endif // __WUIIInkInputProcessingConfiguration_DEFINED__

// Windows.UI.Input.Inking.InkSynchronizer
#ifndef __WUIIInkSynchronizer_DEFINED__
#define __WUIIInkSynchronizer_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkSynchronizer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (NSArray* /* WUIIInkStroke* */)beginDry;
- (void)endDry;
@end

#endif // __WUIIInkSynchronizer_DEFINED__

// Windows.UI.Input.Inking.InkPresenter
#ifndef __WUIIInkPresenter_DEFINED__
#define __WUIIInkPresenter_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkPresenter : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUIIInkStrokeContainer* strokeContainer;
@property BOOL isInputEnabled;
@property WUCCoreInputDeviceTypes inputDeviceTypes;
@property (readonly) WUIIInkInputProcessingConfiguration* inputProcessingConfiguration;
@property (readonly) WUIIInkStrokeInput* strokeInput;
@property (readonly) WUIIInkUnprocessedInput* unprocessedInput;
@property WUIIInkHighContrastAdjustment highContrastAdjustment;
- (EventRegistrationToken)addStrokesCollectedEvent:(void(^)(WUIIInkPresenter*, WUIIInkStrokesCollectedEventArgs*))del;
- (void)removeStrokesCollectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStrokesErasedEvent:(void(^)(WUIIInkPresenter*, WUIIInkStrokesErasedEventArgs*))del;
- (void)removeStrokesErasedEvent:(EventRegistrationToken)tok;
- (WUIIInkDrawingAttributes*)copyDefaultDrawingAttributes __attribute__ ((ns_returns_not_retained));
- (void)updateDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)value;
- (WUIIInkSynchronizer*)activateCustomDrying;
- (void)setPredefinedConfiguration:(WUIIInkPresenterPredefinedConfiguration)value;
@end

#endif // __WUIIInkPresenter_DEFINED__

// Windows.UI.Input.Inking.InkStrokesCollectedEventArgs
#ifndef __WUIIInkStrokesCollectedEventArgs_DEFINED__
#define __WUIIInkStrokesCollectedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokesCollectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WUIIInkStroke* */ strokes;
@end

#endif // __WUIIInkStrokesCollectedEventArgs_DEFINED__

// Windows.UI.Input.Inking.InkStrokesErasedEventArgs
#ifndef __WUIIInkStrokesErasedEventArgs_DEFINED__
#define __WUIIInkStrokesErasedEventArgs_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokesErasedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WUIIInkStroke* */ strokes;
@end

#endif // __WUIIInkStrokesErasedEventArgs_DEFINED__

// Windows.UI.Input.Inking.InkPresenterRuler
#ifndef __WUIIInkPresenterRuler_DEFINED__
#define __WUIIInkPresenterRuler_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkPresenterRuler : RTObject <WUIIIInkPresenterStencil>
+ (WUIIInkPresenterRuler*)make:(WUIIInkPresenter*)inkPresenter ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double width;
@property double length;
@property BOOL isCompassVisible;
@property BOOL areTickMarksVisible;
@property (retain) WFNMatrix3x2* transform;
@property BOOL isVisible;
@property (retain) WUColor* foregroundColor;
@property (retain) WUColor* backgroundColor;
@property (readonly) WUIIInkPresenterStencilKind kind;
@end

#endif // __WUIIInkPresenterRuler_DEFINED__

// Windows.UI.Input.Inking.InkPresenterProtractor
#ifndef __WUIIInkPresenterProtractor_DEFINED__
#define __WUIIInkPresenterProtractor_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkPresenterProtractor : RTObject <WUIIIInkPresenterStencil>
+ (WUIIInkPresenterProtractor*)make:(WUIIInkPresenter*)inkPresenter ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double radius;
@property BOOL isResizable;
@property BOOL isCenterMarkerVisible;
@property BOOL isAngleReadoutVisible;
@property BOOL areTickMarksVisible;
@property BOOL areRaysVisible;
@property (retain) WUColor* accentColor;
@property (retain) WFNMatrix3x2* transform;
@property BOOL isVisible;
@property (retain) WUColor* foregroundColor;
@property (retain) WUColor* backgroundColor;
@property (readonly) WUIIInkPresenterStencilKind kind;
@end

#endif // __WUIIInkPresenterProtractor_DEFINED__

// Windows.UI.Input.Inking.InkPoint
#ifndef __WUIIInkPoint_DEFINED__
#define __WUIIInkPoint_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkPoint : RTObject
+ (WUIIInkPoint*)makeInkPoint:(WFPoint*)position pressure:(float)pressure ACTIVATOR;
+ (WUIIInkPoint*)makeInkPointWithTiltAndTimestamp:(WFPoint*)position pressure:(float)pressure tiltX:(float)tiltX tiltY:(float)tiltY timestamp:(uint64_t)timestamp ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFPoint* position;
@property (readonly) float pressure;
@property (readonly) float tiltX;
@property (readonly) float tiltY;
@property (readonly) uint64_t timestamp;
@end

#endif // __WUIIInkPoint_DEFINED__

// Windows.UI.Input.Inking.InkDrawingAttributesPencilProperties
#ifndef __WUIIInkDrawingAttributesPencilProperties_DEFINED__
#define __WUIIInkDrawingAttributesPencilProperties_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkDrawingAttributesPencilProperties : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double opacity;
@end

#endif // __WUIIInkDrawingAttributesPencilProperties_DEFINED__

// Windows.UI.Input.Inking.InkDrawingAttributes
#ifndef __WUIIInkDrawingAttributes_DEFINED__
#define __WUIIInkDrawingAttributes_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkDrawingAttributes : RTObject
+ (WUIIInkDrawingAttributes*)createForPencil;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFSize* size;
@property WUIIPenTipShape penTip;
@property BOOL ignorePressure;
@property BOOL fitToCurve;
@property (retain) WUColor* color;
@property (retain) WFNMatrix3x2* penTipTransform;
@property BOOL drawAsHighlighter;
@property (readonly) WUIIInkDrawingAttributesKind kind;
@property (readonly) WUIIInkDrawingAttributesPencilProperties* pencilProperties;
@property BOOL ignoreTilt;
@end

#endif // __WUIIInkDrawingAttributes_DEFINED__

// Windows.UI.Input.Inking.InkStrokeRenderingSegment
#ifndef __WUIIInkStrokeRenderingSegment_DEFINED__
#define __WUIIInkStrokeRenderingSegment_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokeRenderingSegment : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStroke : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL selected;
@property (retain) WUIIInkDrawingAttributes* drawingAttributes;
@property (readonly) WFRect* boundingRect;
@property (readonly) BOOL recognized;
@property (retain) WFNMatrix3x2* pointTransform;
@property (retain) id /* WFDateTime* */ strokeStartedTime;
@property (retain) id /* WFTimeSpan* */ strokeDuration;
@property (readonly) unsigned int id;
- (NSArray* /* WUIIInkStrokeRenderingSegment* */)getRenderingSegments;
- (WUIIInkStroke*)clone;
- (NSArray* /* WUIIInkPoint* */)getInkPoints;
@end

#endif // __WUIIInkStroke_DEFINED__

// Windows.UI.Input.Inking.InkStrokeBuilder
#ifndef __WUIIInkStrokeBuilder_DEFINED__
#define __WUIIInkStrokeBuilder_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokeBuilder : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)beginStroke:(WUIPointerPoint*)pointerPoint;
- (WUIPointerPoint*)appendToStroke:(WUIPointerPoint*)pointerPoint;
- (WUIIInkStroke*)endStroke:(WUIPointerPoint*)pointerPoint;
- (WUIIInkStroke*)createStroke:(id<NSFastEnumeration> /* WFPoint* */)points;
- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes;
- (WUIIInkStroke*)createStrokeFromInkPoints:(id<NSFastEnumeration> /* WUIIInkPoint* */)inkPoints transform:(WFNMatrix3x2*)transform;
- (WUIIInkStroke*)createStrokeFromInkPoints:(id<NSFastEnumeration> /* WUIIInkPoint* */)inkPoints transform:(WFNMatrix3x2*)transform strokeStartedTime:(id /* WFDateTime* */)strokeStartedTime strokeDuration:(id /* WFTimeSpan* */)strokeDuration;
@end

#endif // __WUIIInkStrokeBuilder_DEFINED__

// Windows.UI.Input.Inking.InkRecognitionResult
#ifndef __WUIIInkRecognitionResult_DEFINED__
#define __WUIIInkRecognitionResult_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkRecognitionResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
- (NSArray* /* NSString * */)getTextCandidates;
- (NSArray* /* WUIIInkStroke* */)getStrokes;
@end

#endif // __WUIIInkRecognitionResult_DEFINED__

// Windows.UI.Input.Inking.InkStrokeContainer
#ifndef __WUIIInkStrokeContainer_DEFINED__
#define __WUIIInkStrokeContainer_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkStrokeContainer : RTObject <WUIIIInkStrokeContainer>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray* /* WUIIInkStroke* */)getStrokes;
- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults;
- (void)addStrokes:(id<NSFastEnumeration> /* WUIIInkStroke* */)strokes;
- (void)clear;
- (void)saveWithFormatAsync:(RTObject<WSSIOutputStream>*)outputStream inkPersistenceFormat:(WUIIInkPersistenceFormat)inkPersistenceFormat success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (WUIIInkStroke*)getStrokeById:(unsigned int)id;
@end

#endif // __WUIIInkStrokeContainer_DEFINED__

// Windows.UI.Input.Inking.InkRecognizer
#ifndef __WUIIInkRecognizer_DEFINED__
#define __WUIIInkRecognizer_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkRecognizer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * name;
@end

#endif // __WUIIInkRecognizer_DEFINED__

// Windows.UI.Input.Inking.InkRecognizerContainer
#ifndef __WUIIInkRecognizerContainer_DEFINED__
#define __WUIIInkRecognizerContainer_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkRecognizerContainer : RTObject <WUIIIInkRecognizerContainer>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WUIIInkRecognizer* */)getRecognizers;
@end

#endif // __WUIIInkRecognizerContainer_DEFINED__

// Windows.UI.Input.Inking.InkManager
#ifndef __WUIIInkManager_DEFINED__
#define __WUIIInkManager_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGEXPORT
@interface WUIIInkManager : RTObject <WUIIIInkRecognizerContainer, WUIIIInkStrokeContainer>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUIIInkManipulationMode mode;
@property (readonly) WFRect* boundingRect;
- (void)processPointerDown:(WUIPointerPoint*)pointerPoint;
- (RTObject*)processPointerUpdate:(WUIPointerPoint*)pointerPoint;
- (WFRect*)processPointerUp:(WUIPointerPoint*)pointerPoint;
- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes;
- (void)recognizeAsync2:(WUIIInkRecognitionTarget)recognitionTarget success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success failure:(void (^)(NSError*))failure;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /* WFPoint* */)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream success:(void (^)(unsigned int))success progress:(void (^)(unsigned int))progress failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(NSArray* /* WUIIInkRecognitionResult* */)recognitionResults;
- (NSArray* /* WUIIInkStroke* */)getStrokes;
- (NSArray* /* WUIIInkRecognitionResult* */)getRecognitionResults;
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget success:(void (^)(NSArray* /* WUIIInkRecognitionResult* */))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WUIIInkRecognizer* */)getRecognizers;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
@end

#endif // __WUIIInkManager_DEFINED__

