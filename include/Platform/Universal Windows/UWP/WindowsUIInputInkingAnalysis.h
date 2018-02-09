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

// WindowsUIInputInkingAnalysis.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
#define OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIInputInkingAnalysis.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUIIAInkAnalysisRoot, WUIIAInkAnalysisResult, WUIIAInkAnalyzer, WUIIAInkAnalysisNode, WUIIAInkAnalysisWritingRegion, WUIIAInkAnalysisParagraph, WUIIAInkAnalysisListItem, WUIIAInkAnalysisInkBullet, WUIIAInkAnalysisLine, WUIIAInkAnalysisInkWord, WUIIAInkAnalysisInkDrawing;
@protocol WUIIAIInkAnalyzer, WUIIAIInkAnalyzerFactory, WUIIAIInkAnalysisResult, WUIIAIInkAnalysisNode, WUIIAIInkAnalysisRoot, WUIIAIInkAnalysisWritingRegion, WUIIAIInkAnalysisParagraph, WUIIAIInkAnalysisListItem, WUIIAIInkAnalysisInkBullet, WUIIAIInkAnalysisLine, WUIIAIInkAnalysisInkWord, WUIIAIInkAnalysisInkDrawing;

// Windows.UI.Input.Inking.Analysis.InkAnalysisDrawingKind
enum _WUIIAInkAnalysisDrawingKind {
    WUIIAInkAnalysisDrawingKindDrawing = 0,
    WUIIAInkAnalysisDrawingKindCircle = 1,
    WUIIAInkAnalysisDrawingKindEllipse = 2,
    WUIIAInkAnalysisDrawingKindTriangle = 3,
    WUIIAInkAnalysisDrawingKindIsoscelesTriangle = 4,
    WUIIAInkAnalysisDrawingKindEquilateralTriangle = 5,
    WUIIAInkAnalysisDrawingKindRightTriangle = 6,
    WUIIAInkAnalysisDrawingKindQuadrilateral = 7,
    WUIIAInkAnalysisDrawingKindRectangle = 8,
    WUIIAInkAnalysisDrawingKindSquare = 9,
    WUIIAInkAnalysisDrawingKindDiamond = 10,
    WUIIAInkAnalysisDrawingKindTrapezoid = 11,
    WUIIAInkAnalysisDrawingKindParallelogram = 12,
    WUIIAInkAnalysisDrawingKindPentagon = 13,
    WUIIAInkAnalysisDrawingKindHexagon = 14,
};
typedef unsigned WUIIAInkAnalysisDrawingKind;

// Windows.UI.Input.Inking.Analysis.InkAnalysisNodeKind
enum _WUIIAInkAnalysisNodeKind {
    WUIIAInkAnalysisNodeKindUnclassifiedInk = 0,
    WUIIAInkAnalysisNodeKindRoot = 1,
    WUIIAInkAnalysisNodeKindWritingRegion = 2,
    WUIIAInkAnalysisNodeKindParagraph = 3,
    WUIIAInkAnalysisNodeKindLine = 4,
    WUIIAInkAnalysisNodeKindInkWord = 5,
    WUIIAInkAnalysisNodeKindInkBullet = 6,
    WUIIAInkAnalysisNodeKindInkDrawing = 7,
    WUIIAInkAnalysisNodeKindListItem = 8,
};
typedef unsigned WUIIAInkAnalysisNodeKind;

// Windows.UI.Input.Inking.Analysis.InkAnalysisStatus
enum _WUIIAInkAnalysisStatus {
    WUIIAInkAnalysisStatusUpdated = 0,
    WUIIAInkAnalysisStatusUnchanged = 1,
};
typedef unsigned WUIIAInkAnalysisStatus;

// Windows.UI.Input.Inking.Analysis.InkAnalysisStrokeKind
enum _WUIIAInkAnalysisStrokeKind {
    WUIIAInkAnalysisStrokeKindAuto = 0,
    WUIIAInkAnalysisStrokeKindWriting = 1,
    WUIIAInkAnalysisStrokeKindDrawing = 2,
};
typedef unsigned WUIIAInkAnalysisStrokeKind;

#include "WindowsUIInputInking.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.Analysis.IInkAnalyzerFactory
#ifndef __WUIIAIInkAnalyzerFactory_DEFINED__
#define __WUIIAIInkAnalyzerFactory_DEFINED__

@protocol WUIIAIInkAnalyzerFactory
- (WUIIAInkAnalyzer*)createAnalyzer;
@end

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAIInkAnalyzerFactory : RTObject <WUIIAIInkAnalyzerFactory>
@end

#endif // __WUIIAIInkAnalyzerFactory_DEFINED__

// Windows.UI.Input.Inking.Analysis.IInkAnalysisNode
#ifndef __WUIIAIInkAnalysisNode_DEFINED__
#define __WUIIAIInkAnalysisNode_DEFINED__

@protocol WUIIAIInkAnalysisNode
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAIInkAnalysisNode : RTObject <WUIIAIInkAnalysisNode>
@end

#endif // __WUIIAIInkAnalysisNode_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisRoot
#ifndef __WUIIAInkAnalysisRoot_DEFINED__
#define __WUIIAInkAnalysisRoot_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisRoot : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
@property (readonly) NSString * recognizedText;
- (NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */)findNodes:(WUIIAInkAnalysisNodeKind)nodeKind;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisRoot_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisResult
#ifndef __WUIIAInkAnalysisResult_DEFINED__
#define __WUIIAInkAnalysisResult_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIAInkAnalysisStatus status;
@end

#endif // __WUIIAInkAnalysisResult_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalyzer
#ifndef __WUIIAInkAnalyzer_DEFINED__
#define __WUIIAInkAnalyzer_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalyzer : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIAInkAnalysisRoot* analysisRoot;
@property (readonly) BOOL isAnalyzing;
- (void)addDataForStroke:(WUIIInkStroke*)stroke;
- (void)addDataForStrokes:(id<NSFastEnumeration> /* WUIIInkStroke* */)strokes;
- (void)clearDataForAllStrokes;
- (void)removeDataForStroke:(unsigned int)strokeId;
- (void)removeDataForStrokes:(id<NSFastEnumeration> /* unsigned int */)strokeIds;
- (void)replaceDataForStroke:(WUIIInkStroke*)stroke;
- (void)setStrokeDataKind:(unsigned int)strokeId strokeKind:(WUIIAInkAnalysisStrokeKind)strokeKind;
- (void)analyzeAsyncWithSuccess:(void (^)(WUIIAInkAnalysisResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WUIIAInkAnalyzer_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisNode
#ifndef __WUIIAInkAnalysisNode_DEFINED__
#define __WUIIAInkAnalysisNode_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisNode : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisNode_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisWritingRegion
#ifndef __WUIIAInkAnalysisWritingRegion_DEFINED__
#define __WUIIAInkAnalysisWritingRegion_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisWritingRegion : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
@property (readonly) NSString * recognizedText;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisWritingRegion_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisParagraph
#ifndef __WUIIAInkAnalysisParagraph_DEFINED__
#define __WUIIAInkAnalysisParagraph_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisParagraph : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
@property (readonly) NSString * recognizedText;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisParagraph_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisListItem
#ifndef __WUIIAInkAnalysisListItem_DEFINED__
#define __WUIIAInkAnalysisListItem_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisListItem : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * recognizedText;
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisListItem_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisInkBullet
#ifndef __WUIIAInkAnalysisInkBullet_DEFINED__
#define __WUIIAInkAnalysisInkBullet_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisInkBullet : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * recognizedText;
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisInkBullet_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisLine
#ifndef __WUIIAInkAnalysisLine_DEFINED__
#define __WUIIAInkAnalysisLine_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisLine : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int indentLevel;
@property (readonly) NSString * recognizedText;
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisLine_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisInkWord
#ifndef __WUIIAInkAnalysisInkWord_DEFINED__
#define __WUIIAInkAnalysisInkWord_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisInkWord : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * recognizedText;
@property (readonly) NSArray* /* NSString * */ textAlternates;
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisInkWord_DEFINED__

// Windows.UI.Input.Inking.Analysis.InkAnalysisInkDrawing
#ifndef __WUIIAInkAnalysisInkDrawing_DEFINED__
#define __WUIIAInkAnalysisInkDrawing_DEFINED__

OBJCUWPWINDOWSUIINPUTINKINGANALYSISEXPORT
@interface WUIIAInkAnalysisInkDrawing : RTObject <WUIIAIInkAnalysisNode>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFPoint* center;
@property (readonly) WUIIAInkAnalysisDrawingKind drawingKind;
@property (readonly) NSArray* /* WFPoint* */ points;
@property (readonly) WFRect* boundingRect;
@property (readonly) NSArray* /* RTObject<WUIIAIInkAnalysisNode>* */ children;
@property (readonly) unsigned int id;
@property (readonly) WUIIAInkAnalysisNodeKind kind;
@property (readonly) RTObject<WUIIAIInkAnalysisNode>* parent;
@property (readonly) NSArray* /* WFPoint* */ rotatedBoundingRect;
- (NSArray* /* unsigned int */)getStrokeIds;
@end

#endif // __WUIIAInkAnalysisInkDrawing_DEFINED__

