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
@class WUIIInkDrawingAttributes, WUIIInkStrokeRenderingSegment, WUIIInkStroke, WUIIInkStrokeBuilder, WUIIInkRecognitionResult,
    WUIIInkStrokeContainer, WUIIInkRecognizer, WUIIInkRecognizerContainer, WUIIInkManager;
@protocol WUIIIInkDrawingAttributes
, WUIIIInkStrokeRenderingSegment, WUIIIInkStroke, WUIIIInkStrokeBuilder, WUIIIInkRecognitionResult, WUIIIInkStrokeContainer,
    WUIIIInkRecognizer, WUIIIInkRecognizerContainer, WUIIIInkManager;

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

#include "WindowsUIInput.h"
#include "WindowsUI.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.IInkStrokeContainer
#ifndef __WUIIIInkStrokeContainer_DEFINED__
#define __WUIIIInkStrokeContainer_DEFINED__

@protocol WUIIIInkStrokeContainer
@property (readonly) WFRect* boundingRect;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /*WFPoint*/)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)recognitionResults;
- (id<NSFastEnumeration> /*WUIIInkStroke*/)getStrokes;
- (id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)getRecognitionResults;
@end

#endif // __WUIIIInkStrokeContainer_DEFINED__

// Windows.UI.Input.Inking.IInkRecognizerContainer
#ifndef __WUIIIInkRecognizerContainer_DEFINED__
#define __WUIIIInkRecognizerContainer_DEFINED__

@protocol WUIIIInkRecognizerContainer
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/))success
               failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WUIIInkRecognizer*/)getRecognizers;
@end

#endif // __WUIIIInkRecognizerContainer_DEFINED__

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
- (id<NSFastEnumeration> /*WUIIInkStrokeRenderingSegment*/)getRenderingSegments;
- (WUIIInkStroke*)clone;
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
- (WUIIInkStroke*)createStroke:(id<NSFastEnumeration> /*WFPoint*/)points;
- (void)setDefaultDrawingAttributes:(WUIIInkDrawingAttributes*)drawingAttributes;
@end

#endif // __WUIIInkStrokeBuilder_DEFINED__

// Windows.UI.Input.Inking.InkRecognitionResult
#ifndef __WUIIInkRecognitionResult_DEFINED__
#define __WUIIInkRecognitionResult_DEFINED__

WINRT_EXPORT
@interface WUIIInkRecognitionResult : RTObject
@property (readonly) WFRect* boundingRect;
- (id<NSFastEnumeration> /*String*/)getTextCandidates;
- (id<NSFastEnumeration> /*WUIIInkStroke*/)getStrokes;
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
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /*WFPoint*/)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)recognitionResults;
- (id<NSFastEnumeration> /*WUIIInkStroke*/)getStrokes;
- (id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)getRecognitionResults;
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
               success:(void (^)(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/))success
               failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WUIIInkRecognizer*/)getRecognizers;
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
- (void)recognizeAsync2:(WUIIInkRecognitionTarget)recognitionTarget
                success:(void (^)(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/))success
                failure:(void (^)(NSError*))failure;
- (void)addStroke:(WUIIInkStroke*)stroke;
- (WFRect*)deleteSelected;
- (WFRect*)moveSelected:(WFPoint*)translation;
- (WFRect*)selectWithPolyLine:(id<NSFastEnumeration> /*WFPoint*/)polyline;
- (WFRect*)selectWithLine:(WFPoint*)from to:(WFPoint*)to;
- (void)copySelectedToClipboard;
- (WFRect*)pasteFromClipboard:(WFPoint*)position;
- (BOOL)canPasteFromClipboard;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
- (void)saveAsync:(RTObject<WSSIOutputStream>*)outputStream
          success:(void (^)(unsigned))success
         progress:(void (^)(unsigned))progress
          failure:(void (^)(NSError*))failure;
- (void)updateRecognitionResults:(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)recognitionResults;
- (id<NSFastEnumeration> /*WUIIInkStroke*/)getStrokes;
- (id<NSFastEnumeration> /*WUIIInkRecognitionResult*/)getRecognitionResults;
- (void)setDefaultRecognizer:(WUIIInkRecognizer*)recognizer;
- (void)recognizeAsync:(WUIIInkStrokeContainer*)strokeCollection
     recognitionTarget:(WUIIInkRecognitionTarget)recognitionTarget
               success:(void (^)(id<NSFastEnumeration> /*WUIIInkRecognitionResult*/))success
               failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WUIIInkRecognizer*/)getRecognizers;
// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncActionWithProgress`1<UInt64>)
@end

#endif // __WUIIInkManager_DEFINED__
