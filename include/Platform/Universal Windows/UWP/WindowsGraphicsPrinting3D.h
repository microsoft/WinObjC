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

// WindowsGraphicsPrinting3D.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
#define OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsPrinting3D.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPPrint3DTaskCompletedEventArgs, WGPPrint3DTaskSourceChangedEventArgs, WGPPrint3DTask, WGPPrint3DTaskSourceRequestedArgs, WGPPrint3DTaskRequest, WGPPrint3DTaskRequestedEventArgs, WGPPrint3DManager, WGPPrinting3DMeshVerificationResult, WGPPrinting3DTextureResource, WGPPrinting3DComponent, WGPPrinting3DMesh, WGPPrinting3DComponentWithMatrix, WGPPrinting3DColorMaterial, WGPPrinting3DModelTexture, WGPPrinting3DBaseMaterialGroup, WGPPrinting3DBaseMaterial, WGPPrinting3DColorMaterialGroup, WGPPrinting3DTexture2CoordMaterialGroup, WGPPrinting3DTexture2CoordMaterial, WGPPrinting3DCompositeMaterialGroup, WGPPrinting3DCompositeMaterial, WGPPrinting3DMultiplePropertyMaterialGroup, WGPPrinting3DMultiplePropertyMaterial, WGPPrinting3DMaterial, WGPPrinting3DModel, WGPPrinting3DFaceReductionOptions, WGPPrinting3D3MFPackage;
@class WGPPrinting3DBufferDescription;
@protocol WGPIPrint3DTaskCompletedEventArgs, WGPIPrint3DTaskSourceChangedEventArgs, WGPIPrint3DTask, WGPIPrint3DTaskSourceRequestedArgs, WGPIPrint3DTaskRequest, WGPIPrint3DTaskRequestedEventArgs, WGPIPrint3DManagerStatics, WGPIPrint3DManager, WGPIPrinting3DMesh, WGPIPrinting3DModelTexture, WGPIPrinting3DTextureResource, WGPIPrinting3DComponentWithMatrix, WGPIPrinting3DComponent, WGPIPrinting3DBaseMaterialStatics, WGPIPrinting3DBaseMaterial, WGPIPrinting3DColorMaterial, WGPIPrinting3DColorMaterial2, WGPIPrinting3DTexture2CoordMaterial, WGPIPrinting3DCompositeMaterial, WGPIPrinting3DMultiplePropertyMaterial, WGPIPrinting3DBaseMaterialGroupFactory, WGPIPrinting3DBaseMaterialGroup, WGPIPrinting3DColorMaterialGroupFactory, WGPIPrinting3DColorMaterialGroup, WGPIPrinting3DTexture2CoordMaterialGroupFactory, WGPIPrinting3DTexture2CoordMaterialGroup, WGPIPrinting3DTexture2CoordMaterialGroup2, WGPIPrinting3DCompositeMaterialGroupFactory, WGPIPrinting3DCompositeMaterialGroup2, WGPIPrinting3DCompositeMaterialGroup, WGPIPrinting3DMultiplePropertyMaterialGroupFactory, WGPIPrinting3DMultiplePropertyMaterialGroup, WGPIPrinting3DMaterial, WGPIPrinting3DMeshVerificationResult, WGPIPrinting3DModel, WGPIPrinting3DFaceReductionOptions, WGPIPrinting3DModel2, WGPIPrinting3D3MFPackageStatics, WGPIPrinting3D3MFPackage, WGPIPrinting3D3MFPackage2;

// Windows.Graphics.Printing3D.Print3DTaskDetail
enum _WGPPrint3DTaskDetail {
    WGPPrint3DTaskDetailUnknown = 0,
    WGPPrint3DTaskDetailModelExceedsPrintBed = 1,
    WGPPrint3DTaskDetailUploadFailed = 2,
    WGPPrint3DTaskDetailInvalidMaterialSelection = 3,
    WGPPrint3DTaskDetailInvalidModel = 4,
    WGPPrint3DTaskDetailModelNotManifold = 5,
    WGPPrint3DTaskDetailInvalidPrintTicket = 6,
};
typedef unsigned WGPPrint3DTaskDetail;

// Windows.Graphics.Printing3D.Print3DTaskCompletion
enum _WGPPrint3DTaskCompletion {
    WGPPrint3DTaskCompletionAbandoned = 0,
    WGPPrint3DTaskCompletionCanceled = 1,
    WGPPrint3DTaskCompletionFailed = 2,
    WGPPrint3DTaskCompletionSlicing = 3,
    WGPPrint3DTaskCompletionSubmitted = 4,
};
typedef unsigned WGPPrint3DTaskCompletion;

// Windows.Graphics.Printing3D.Printing3DBufferFormat
enum _WGPPrinting3DBufferFormat {
    WGPPrinting3DBufferFormatUnknown = 0,
    WGPPrinting3DBufferFormatR32G32B32A32Float = 2,
    WGPPrinting3DBufferFormatR32G32B32A32UInt = 3,
    WGPPrinting3DBufferFormatR32G32B32Float = 6,
    WGPPrinting3DBufferFormatR32G32B32UInt = 7,
    WGPPrinting3DBufferFormatPrinting3DDouble = 500,
    WGPPrinting3DBufferFormatPrinting3DUInt = 501,
};
typedef unsigned WGPPrinting3DBufferFormat;

// Windows.Graphics.Printing3D.Printing3DMeshVerificationMode
enum _WGPPrinting3DMeshVerificationMode {
    WGPPrinting3DMeshVerificationModeFindFirstError = 0,
    WGPPrinting3DMeshVerificationModeFindAllErrors = 1,
};
typedef unsigned WGPPrinting3DMeshVerificationMode;

// Windows.Graphics.Printing3D.Printing3DModelUnit
enum _WGPPrinting3DModelUnit {
    WGPPrinting3DModelUnitMeter = 0,
    WGPPrinting3DModelUnitMicron = 1,
    WGPPrinting3DModelUnitMillimeter = 2,
    WGPPrinting3DModelUnitCentimeter = 3,
    WGPPrinting3DModelUnitInch = 4,
    WGPPrinting3DModelUnitFoot = 5,
};
typedef unsigned WGPPrinting3DModelUnit;

// Windows.Graphics.Printing3D.Printing3DTextureEdgeBehavior
enum _WGPPrinting3DTextureEdgeBehavior {
    WGPPrinting3DTextureEdgeBehaviorNone = 0,
    WGPPrinting3DTextureEdgeBehaviorWrap = 1,
    WGPPrinting3DTextureEdgeBehaviorMirror = 2,
    WGPPrinting3DTextureEdgeBehaviorClamp = 3,
};
typedef unsigned WGPPrinting3DTextureEdgeBehavior;

// Windows.Graphics.Printing3D.Printing3DObjectType
enum _WGPPrinting3DObjectType {
    WGPPrinting3DObjectTypeModel = 0,
    WGPPrinting3DObjectTypeSupport = 1,
    WGPPrinting3DObjectTypeOthers = 2,
};
typedef unsigned WGPPrinting3DObjectType;

// Windows.Graphics.Printing3D.Printing3DPackageCompression
enum _WGPPrinting3DPackageCompression {
    WGPPrinting3DPackageCompressionLow = 0,
    WGPPrinting3DPackageCompressionMedium = 1,
    WGPPrinting3DPackageCompressionHigh = 2,
};
typedef unsigned WGPPrinting3DPackageCompression;

#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsUI.h"
// Windows.Graphics.Printing3D.Print3DTaskSourceRequestedHandler
#ifndef __WGPPrint3DTaskSourceRequestedHandler__DEFINED
#define __WGPPrint3DTaskSourceRequestedHandler__DEFINED
typedef void(^WGPPrint3DTaskSourceRequestedHandler)(WGPPrint3DTaskSourceRequestedArgs* args);
#endif // __WGPPrint3DTaskSourceRequestedHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.Graphics.Printing3D.Printing3DBufferDescription
OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DBufferDescription : NSObject
+ (instancetype)new;
@property WGPPrinting3DBufferFormat format;
@property unsigned int stride;
@end

// Windows.Graphics.Printing3D.Print3DTaskSourceRequestedHandler
#ifndef __WGPPrint3DTaskSourceRequestedHandler__DEFINED
#define __WGPPrint3DTaskSourceRequestedHandler__DEFINED
typedef void(^WGPPrint3DTaskSourceRequestedHandler)(WGPPrint3DTaskSourceRequestedArgs* args);
#endif // __WGPPrint3DTaskSourceRequestedHandler__DEFINED

// Windows.Graphics.Printing3D.Print3DTaskCompletedEventArgs
#ifndef __WGPPrint3DTaskCompletedEventArgs_DEFINED__
#define __WGPPrint3DTaskCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTaskCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPrint3DTaskCompletion completion;
@property (readonly) WGPPrint3DTaskDetail extendedStatus;
@end

#endif // __WGPPrint3DTaskCompletedEventArgs_DEFINED__

// Windows.Graphics.Printing3D.Print3DTaskSourceChangedEventArgs
#ifndef __WGPPrint3DTaskSourceChangedEventArgs_DEFINED__
#define __WGPPrint3DTaskSourceChangedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTaskSourceChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPrinting3D3MFPackage* source;
@end

#endif // __WGPPrint3DTaskSourceChangedEventArgs_DEFINED__

// Windows.Graphics.Printing3D.Print3DTask
#ifndef __WGPPrint3DTask_DEFINED__
#define __WGPPrint3DTask_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTask : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPrinting3D3MFPackage* source;
- (EventRegistrationToken)addCompletedEvent:(void(^)(WGPPrint3DTask*, WGPPrint3DTaskCompletedEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSourceChangedEvent:(void(^)(WGPPrint3DTask*, WGPPrint3DTaskSourceChangedEventArgs*))del;
- (void)removeSourceChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSubmittingEvent:(void(^)(WGPPrint3DTask*, RTObject*))del;
- (void)removeSubmittingEvent:(EventRegistrationToken)tok;
@end

#endif // __WGPPrint3DTask_DEFINED__

// Windows.Graphics.Printing3D.Print3DTaskSourceRequestedArgs
#ifndef __WGPPrint3DTaskSourceRequestedArgs_DEFINED__
#define __WGPPrint3DTaskSourceRequestedArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTaskSourceRequestedArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)setSource:(WGPPrinting3D3MFPackage*)source;
@end

#endif // __WGPPrint3DTaskSourceRequestedArgs_DEFINED__

// Windows.Graphics.Printing3D.Print3DTaskRequest
#ifndef __WGPPrint3DTaskRequest_DEFINED__
#define __WGPPrint3DTaskRequest_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTaskRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WGPPrint3DTask*)createTask:(NSString *)title printerId:(NSString *)printerId handler:(WGPPrint3DTaskSourceRequestedHandler)handler;
@end

#endif // __WGPPrint3DTaskRequest_DEFINED__

// Windows.Graphics.Printing3D.Print3DTaskRequestedEventArgs
#ifndef __WGPPrint3DTaskRequestedEventArgs_DEFINED__
#define __WGPPrint3DTaskRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DTaskRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPrint3DTaskRequest* request;
@end

#endif // __WGPPrint3DTaskRequestedEventArgs_DEFINED__

// Windows.Graphics.Printing3D.Print3DManager
#ifndef __WGPPrint3DManager_DEFINED__
#define __WGPPrint3DManager_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrint3DManager : RTObject
+ (WGPPrint3DManager*)getForCurrentView;
+ (void)showPrintUIAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addTaskRequestedEvent:(void(^)(WGPPrint3DManager*, WGPPrint3DTaskRequestedEventArgs*))del;
- (void)removeTaskRequestedEvent:(EventRegistrationToken)tok;
@end

#endif // __WGPPrint3DManager_DEFINED__

// Windows.Graphics.Printing3D.Printing3DMeshVerificationResult
#ifndef __WGPPrinting3DMeshVerificationResult_DEFINED__
#define __WGPPrinting3DMeshVerificationResult_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DMeshVerificationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isValid;
@property (readonly) NSArray* /* unsigned int */ nonmanifoldTriangles;
@property (readonly) NSArray* /* unsigned int */ reversedNormalTriangles;
@end

#endif // __WGPPrinting3DMeshVerificationResult_DEFINED__

// Windows.Graphics.Printing3D.Printing3DTextureResource
#ifndef __WGPPrinting3DTextureResource_DEFINED__
#define __WGPPrinting3DTextureResource_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DTextureResource : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIRandomAccessStreamWithContentType>* textureData;
@property (retain) NSString * name;
@end

#endif // __WGPPrinting3DTextureResource_DEFINED__

// Windows.Graphics.Printing3D.Printing3DComponent
#ifndef __WGPPrinting3DComponent_DEFINED__
#define __WGPPrinting3DComponent_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DComponent : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WGPPrinting3DObjectType type;
@property (retain) WGPPrinting3DTextureResource* thumbnail;
@property (retain) NSString * partNumber;
@property (retain) NSString * name;
@property (retain) WGPPrinting3DMesh* mesh;
@property (readonly) NSMutableArray* /* WGPPrinting3DComponentWithMatrix* */ components;
@end

#endif // __WGPPrinting3DComponent_DEFINED__

// Windows.Graphics.Printing3D.Printing3DMesh
#ifndef __WGPPrinting3DMesh_DEFINED__
#define __WGPPrinting3DMesh_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DMesh : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WGPPrinting3DBufferDescription* vertexPositionsDescription;
@property (retain) WGPPrinting3DBufferDescription* vertexNormalsDescription;
@property unsigned int vertexCount;
@property (retain) WGPPrinting3DBufferDescription* triangleMaterialIndicesDescription;
@property (retain) WGPPrinting3DBufferDescription* triangleIndicesDescription;
@property unsigned int indexCount;
@property (readonly) RTObject<WFCIPropertySet>* bufferDescriptionSet;
@property (readonly) RTObject<WFCIPropertySet>* bufferSet;
- (RTObject<WSSIBuffer>*)getVertexPositions;
- (void)createVertexPositions:(unsigned int)value;
- (RTObject<WSSIBuffer>*)getVertexNormals;
- (void)createVertexNormals:(unsigned int)value;
- (RTObject<WSSIBuffer>*)getTriangleIndices;
- (void)createTriangleIndices:(unsigned int)value;
- (RTObject<WSSIBuffer>*)getTriangleMaterialIndices;
- (void)createTriangleMaterialIndices:(unsigned int)value;
- (void)verifyAsync:(WGPPrinting3DMeshVerificationMode)value success:(void (^)(WGPPrinting3DMeshVerificationResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WGPPrinting3DMesh_DEFINED__

// Windows.Graphics.Printing3D.Printing3DComponentWithMatrix
#ifndef __WGPPrinting3DComponentWithMatrix_DEFINED__
#define __WGPPrinting3DComponentWithMatrix_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DComponentWithMatrix : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFNMatrix4x4* matrix;
@property (retain) WGPPrinting3DComponent* component;
@end

#endif // __WGPPrinting3DComponentWithMatrix_DEFINED__

// Windows.Graphics.Printing3D.Printing3DColorMaterial
#ifndef __WGPPrinting3DColorMaterial_DEFINED__
#define __WGPPrinting3DColorMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DColorMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int value;
@property (retain) WUColor* color;
@end

#endif // __WGPPrinting3DColorMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DModelTexture
#ifndef __WGPPrinting3DModelTexture_DEFINED__
#define __WGPPrinting3DModelTexture_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DModelTexture : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WGPPrinting3DTextureEdgeBehavior tileStyleV;
@property WGPPrinting3DTextureEdgeBehavior tileStyleU;
@property (retain) WGPPrinting3DTextureResource* textureResource;
@end

#endif // __WGPPrinting3DModelTexture_DEFINED__

// Windows.Graphics.Printing3D.Printing3DBaseMaterialGroup
#ifndef __WGPPrinting3DBaseMaterialGroup_DEFINED__
#define __WGPPrinting3DBaseMaterialGroup_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DBaseMaterialGroup : RTObject
+ (WGPPrinting3DBaseMaterialGroup*)make:(unsigned int)MaterialGroupId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WGPPrinting3DBaseMaterial* */ bases;
@property (readonly) unsigned int materialGroupId;
@end

#endif // __WGPPrinting3DBaseMaterialGroup_DEFINED__

// Windows.Graphics.Printing3D.Printing3DBaseMaterial
#ifndef __WGPPrinting3DBaseMaterial_DEFINED__
#define __WGPPrinting3DBaseMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DBaseMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property (retain) WGPPrinting3DColorMaterial* color;
+ (NSString *)abs;
+ (NSString *)pla;
@end

#endif // __WGPPrinting3DBaseMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DColorMaterialGroup
#ifndef __WGPPrinting3DColorMaterialGroup_DEFINED__
#define __WGPPrinting3DColorMaterialGroup_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DColorMaterialGroup : RTObject
+ (WGPPrinting3DColorMaterialGroup*)make:(unsigned int)MaterialGroupId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WGPPrinting3DColorMaterial* */ colors;
@property (readonly) unsigned int materialGroupId;
@end

#endif // __WGPPrinting3DColorMaterialGroup_DEFINED__

// Windows.Graphics.Printing3D.Printing3DTexture2CoordMaterialGroup
#ifndef __WGPPrinting3DTexture2CoordMaterialGroup_DEFINED__
#define __WGPPrinting3DTexture2CoordMaterialGroup_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DTexture2CoordMaterialGroup : RTObject
+ (WGPPrinting3DTexture2CoordMaterialGroup*)make:(unsigned int)MaterialGroupId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int materialGroupId;
@property (readonly) NSMutableArray* /* WGPPrinting3DTexture2CoordMaterial* */ texture2Coords;
@property (retain) WGPPrinting3DModelTexture* texture;
@end

#endif // __WGPPrinting3DTexture2CoordMaterialGroup_DEFINED__

// Windows.Graphics.Printing3D.Printing3DTexture2CoordMaterial
#ifndef __WGPPrinting3DTexture2CoordMaterial_DEFINED__
#define __WGPPrinting3DTexture2CoordMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DTexture2CoordMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double v;
@property double u;
@property (retain) WGPPrinting3DModelTexture* texture;
@end

#endif // __WGPPrinting3DTexture2CoordMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DCompositeMaterialGroup
#ifndef __WGPPrinting3DCompositeMaterialGroup_DEFINED__
#define __WGPPrinting3DCompositeMaterialGroup_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DCompositeMaterialGroup : RTObject
+ (WGPPrinting3DCompositeMaterialGroup*)make:(unsigned int)MaterialGroupId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WGPPrinting3DCompositeMaterial* */ composites;
@property (readonly) unsigned int materialGroupId;
@property (readonly) NSMutableArray* /* unsigned int */ materialIndices;
@property (retain) WGPPrinting3DBaseMaterialGroup* baseMaterialGroup;
@end

#endif // __WGPPrinting3DCompositeMaterialGroup_DEFINED__

// Windows.Graphics.Printing3D.Printing3DCompositeMaterial
#ifndef __WGPPrinting3DCompositeMaterial_DEFINED__
#define __WGPPrinting3DCompositeMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DCompositeMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* double */ values;
@end

#endif // __WGPPrinting3DCompositeMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DMultiplePropertyMaterialGroup
#ifndef __WGPPrinting3DMultiplePropertyMaterialGroup_DEFINED__
#define __WGPPrinting3DMultiplePropertyMaterialGroup_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DMultiplePropertyMaterialGroup : RTObject
+ (WGPPrinting3DMultiplePropertyMaterialGroup*)make:(unsigned int)MaterialGroupId ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int materialGroupId;
@property (readonly) NSMutableArray* /* unsigned int */ materialGroupIndices;
@property (readonly) NSMutableArray* /* WGPPrinting3DMultiplePropertyMaterial* */ multipleProperties;
@end

#endif // __WGPPrinting3DMultiplePropertyMaterialGroup_DEFINED__

// Windows.Graphics.Printing3D.Printing3DMultiplePropertyMaterial
#ifndef __WGPPrinting3DMultiplePropertyMaterial_DEFINED__
#define __WGPPrinting3DMultiplePropertyMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DMultiplePropertyMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* unsigned int */ materialIndices;
@end

#endif // __WGPPrinting3DMultiplePropertyMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DMaterial
#ifndef __WGPPrinting3DMaterial_DEFINED__
#define __WGPPrinting3DMaterial_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DMaterial : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WGPPrinting3DBaseMaterialGroup* */ baseGroups;
@property (readonly) NSMutableArray* /* WGPPrinting3DColorMaterialGroup* */ colorGroups;
@property (readonly) NSMutableArray* /* WGPPrinting3DCompositeMaterialGroup* */ compositeGroups;
@property (readonly) NSMutableArray* /* WGPPrinting3DMultiplePropertyMaterialGroup* */ multiplePropertyGroups;
@property (readonly) NSMutableArray* /* WGPPrinting3DTexture2CoordMaterialGroup* */ texture2CoordGroups;
@end

#endif // __WGPPrinting3DMaterial_DEFINED__

// Windows.Graphics.Printing3D.Printing3DModel
#ifndef __WGPPrinting3DModel_DEFINED__
#define __WGPPrinting3DModel_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DModel : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * Version;
@property WGPPrinting3DModelUnit unit;
@property (retain) WGPPrinting3DMaterial* material;
@property (retain) WGPPrinting3DComponent* build;
@property (readonly) NSMutableArray* /* WGPPrinting3DComponent* */ components;
@property (readonly) NSMutableArray* /* WGPPrinting3DMesh* */ meshes;
@property (readonly) NSMutableDictionary* /* NSString *, NSString * */ metadata;
@property (readonly) NSMutableArray* /* NSString * */ requiredExtensions;
@property (readonly) NSMutableArray* /* WGPPrinting3DModelTexture* */ textures;
- (RTObject<WFIAsyncAction>*)repairAsync;
- (WGPPrinting3DModel*)clone;
- (void)tryPartialRepairAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryPartialRepairWithTimeAsync:(WFTimeSpan*)maxWaitTime success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryReduceFacesAsyncWithSuccess:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure;
- (void)tryReduceFacesWithOptionsAsync:(WGPPrinting3DFaceReductionOptions*)printing3DFaceReductionOptions success:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure;
- (void)tryReduceFacesWithOptionsAndTimeAsync:(WGPPrinting3DFaceReductionOptions*)printing3DFaceReductionOptions maxWait:(WFTimeSpan*)maxWait success:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure;
- (void)repairWithProgressAsyncWithSuccess:(void (^)(BOOL))success progress:(void (^)(double))progress failure:(void (^)(NSError*))failure;
@end

#endif // __WGPPrinting3DModel_DEFINED__

// Windows.Graphics.Printing3D.Printing3DFaceReductionOptions
#ifndef __WGPPrinting3DFaceReductionOptions_DEFINED__
#define __WGPPrinting3DFaceReductionOptions_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3DFaceReductionOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property unsigned int targetTriangleCount;
@property double maxReductionArea;
@property double maxEdgeLength;
@end

#endif // __WGPPrinting3DFaceReductionOptions_DEFINED__

// Windows.Graphics.Printing3D.Printing3D3MFPackage
#ifndef __WGPPrinting3D3MFPackage_DEFINED__
#define __WGPPrinting3D3MFPackage_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTING3DEXPORT
@interface WGPPrinting3D3MFPackage : RTObject
+ (void)loadAsync:(RTObject<WSSIRandomAccessStream>*)value success:(void (^)(WGPPrinting3D3MFPackage*))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WGPPrinting3DTextureResource* thumbnail;
@property (retain) RTObject<WSSIRandomAccessStream>* printTicket;
@property (retain) RTObject<WSSIRandomAccessStream>* modelPart;
@property (readonly) NSMutableArray* /* WGPPrinting3DTextureResource* */ textures;
@property WGPPrinting3DPackageCompression compression;
- (void)saveAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)loadModelFromPackageAsync:(RTObject<WSSIRandomAccessStream>*)value success:(void (^)(WGPPrinting3DModel*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveModelToPackageAsync:(WGPPrinting3DModel*)value;
@end

#endif // __WGPPrinting3D3MFPackage_DEFINED__

