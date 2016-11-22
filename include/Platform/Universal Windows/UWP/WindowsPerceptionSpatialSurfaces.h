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

// WindowsPerceptionSpatialSurfaces.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
#define OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Perception_Spatial_Surfaces.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPSSSpatialSurfaceInfo, WPSSSpatialSurfaceMeshBuffer, WPSSSpatialSurfaceMesh, WPSSSpatialSurfaceMeshOptions, WPSSSpatialSurfaceObserver;
@protocol WPSSISpatialSurfaceMeshBuffer, WPSSISpatialSurfaceMesh, WPSSISpatialSurfaceMeshOptionsStatics, WPSSISpatialSurfaceMeshOptions, WPSSISpatialSurfaceInfo, WPSSISpatialSurfaceObserverStatics, WPSSISpatialSurfaceObserver;

#include "WindowsPerceptionSpatial.h"
#include "WindowsGraphicsDirectX.h"
#include "WindowsStorageStreams.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Perception.Spatial.Surfaces.SpatialSurfaceInfo
#ifndef __WPSSSpatialSurfaceInfo_DEFINED__
#define __WPSSSpatialSurfaceInfo_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
@interface WPSSSpatialSurfaceInfo : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WFGUID* id;
@property (readonly) WFDateTime* updateTime;
- (id /* WPSSpatialBoundingOrientedBox* */)tryGetBounds:(WPSSpatialCoordinateSystem*)coordinateSystem;
- (void)tryComputeLatestMeshAsync:(double)maxTrianglesPerCubicMeter success:(void (^)(WPSSSpatialSurfaceMesh*))success failure:(void (^)(NSError*))failure;
- (void)tryComputeLatestMeshWithOptionsAsync:(double)maxTrianglesPerCubicMeter options:(WPSSSpatialSurfaceMeshOptions*)options success:(void (^)(WPSSSpatialSurfaceMesh*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPSSSpatialSurfaceInfo_DEFINED__

// Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshBuffer
#ifndef __WPSSSpatialSurfaceMeshBuffer_DEFINED__
#define __WPSSSpatialSurfaceMeshBuffer_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
@interface WPSSSpatialSurfaceMeshBuffer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) RTObject<WSSIBuffer>* data;
@property (readonly) unsigned int elementCount;
@property (readonly) WGDDirectXPixelFormat format;
@property (readonly) unsigned int stride;
@end

#endif // __WPSSSpatialSurfaceMeshBuffer_DEFINED__

// Windows.Perception.Spatial.Surfaces.SpatialSurfaceMesh
#ifndef __WPSSSpatialSurfaceMesh_DEFINED__
#define __WPSSSpatialSurfaceMesh_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
@interface WPSSSpatialSurfaceMesh : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WPSSpatialCoordinateSystem* coordinateSystem;
@property (readonly) WPSSSpatialSurfaceInfo* surfaceInfo;
@property (readonly) WPSSSpatialSurfaceMeshBuffer* triangleIndices;
@property (readonly) WPSSSpatialSurfaceMeshBuffer* vertexNormals;
@property (readonly) WFNVector3* vertexPositionScale;
@property (readonly) WPSSSpatialSurfaceMeshBuffer* vertexPositions;
@end

#endif // __WPSSSpatialSurfaceMesh_DEFINED__

// Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshOptions
#ifndef __WPSSSpatialSurfaceMeshOptions_DEFINED__
#define __WPSSSpatialSurfaceMeshOptions_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
@interface WPSSSpatialSurfaceMeshOptions : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WGDDirectXPixelFormat vertexPositionFormat;
@property WGDDirectXPixelFormat vertexNormalFormat;
@property WGDDirectXPixelFormat triangleIndexFormat;
@property BOOL includeVertexNormals;
+ (NSArray* /* WGDDirectXPixelFormat */)supportedTriangleIndexFormats;
+ (NSArray* /* WGDDirectXPixelFormat */)supportedVertexNormalFormats;
+ (NSArray* /* WGDDirectXPixelFormat */)supportedVertexPositionFormats;
@end

#endif // __WPSSSpatialSurfaceMeshOptions_DEFINED__

// Windows.Perception.Spatial.Surfaces.SpatialSurfaceObserver
#ifndef __WPSSSpatialSurfaceObserver_DEFINED__
#define __WPSSSpatialSurfaceObserver_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_SPATIAL_SURFACES_EXPORT
@interface WPSSSpatialSurfaceObserver : RTObject
+ (void)requestAccessAsyncWithSuccess:(void (^)(WPSSpatialPerceptionAccessStatus))success failure:(void (^)(NSError*))failure;
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (EventRegistrationToken)addObservedSurfacesChangedEvent:(void(^)(WPSSSpatialSurfaceObserver*, RTObject*))del;
- (void)removeObservedSurfacesChangedEvent:(EventRegistrationToken)tok;
- (NSDictionary* /* WFGUID*, WPSSSpatialSurfaceInfo* */)getObservedSurfaces;
- (void)setBoundingVolume:(WPSSpatialBoundingVolume*)bounds;
- (void)setBoundingVolumes:(id<NSFastEnumeration> /* WPSSpatialBoundingVolume* */)bounds;
@end

#endif // __WPSSSpatialSurfaceObserver_DEFINED__

