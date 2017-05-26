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

// WindowsMediaDevicesCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Devices.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaDevicesCore.h"
#include "WindowsMediaDevicesCore_priv.h"

@implementation WMDCCameraIntrinsics

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector2*)focalLength {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocalLength(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (WFNVector2*)principalPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrincipalPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (WFNVector3*)radialDistortion {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_RadialDistortion(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WFNVector2*)tangentialDistortion {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_TangentialDistortion(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (unsigned int)imageWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)imageHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImageHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFPoint*)projectOntoFrame:(WFNVector3*)coordinate {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->ProjectOntoFrame(*[coordinate internalStruct], &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFNVector2*)unprojectAtUnitDepth:(WFPoint*)pixelCoordinate {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectAtUnitDepth(*[pixelCoordinate internalStruct], &unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)projectManyOntoFrame:(NSArray* /* WFNVector3* */)coordinates results:(NSArray* /* WFPoint* */*)results {
    UINT32 __coordinates_ArrayLen = 0;
    bool __coordinates_IsTemp = false;
    ABI::Windows::Foundation::Numerics::Vector3* __coordinates_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Numerics::Vector3>(coordinates,
                                                                      &__coordinates_ArrayLen,
                                                                      &__coordinates_Array,
                                                                      &__coordinates_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Point* __results_Array = (ABI::Windows::Foundation::Point*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(_comInst->ProjectManyOntoFrame(__coordinates_ArrayLen, __coordinates_Array, __results_ArrayLen, __results_Array));
    if (__coordinates_IsTemp)
        CoTaskMemFree(__coordinates_Array);
}

- (void)unprojectPixelsAtUnitDepth:(NSArray* /* WFPoint* */)pixelCoordinates results:(NSArray* /* WFNVector2* */*)results {
    UINT32 __pixelCoordinates_ArrayLen = 0;
    bool __pixelCoordinates_IsTemp = false;
    ABI::Windows::Foundation::Point* __pixelCoordinates_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(pixelCoordinates,
                                                          &__pixelCoordinates_ArrayLen,
                                                          &__pixelCoordinates_Array,
                                                          &__pixelCoordinates_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Numerics::Vector2* __results_Array = (ABI::Windows::Foundation::Numerics::Vector2*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(self);
    THROW_NS_IF_FAILED(
        _comInst->UnprojectPixelsAtUnitDepth(__pixelCoordinates_ArrayLen, __pixelCoordinates_Array, __results_ArrayLen, __results_Array));
    if (__pixelCoordinates_IsTemp)
        CoTaskMemFree(__pixelCoordinates_Array);
}

- (WFNMatrix4x4*)undistortedProjectionTransform {
    ABI::Windows::Foundation::Numerics::Matrix4x4 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UndistortedProjectionTransform(&unmarshalledReturn));
    return WFNMatrix4x4_create(unmarshalledReturn);
}

- (WFPoint*)distortPoint:(WFPoint*)input {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics2>(self);
    THROW_NS_IF_FAILED(_comInst->DistortPoint(*[input internalStruct], &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)distortPoints:(NSArray* /* WFPoint* */)inputs results:(NSArray* /* WFPoint* */*)results {
    UINT32 __inputs_ArrayLen = 0;
    bool __inputs_IsTemp = false;
    ABI::Windows::Foundation::Point* __inputs_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(inputs, &__inputs_ArrayLen, &__inputs_Array, &__inputs_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Point* __results_Array = (ABI::Windows::Foundation::Point*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics2>(self);
    THROW_NS_IF_FAILED(_comInst->DistortPoints(__inputs_ArrayLen, __inputs_Array, __results_ArrayLen, __results_Array));
    if (__inputs_IsTemp)
        CoTaskMemFree(__inputs_Array);
}

- (WFPoint*)undistortPoint:(WFPoint*)input {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics2>(self);
    THROW_NS_IF_FAILED(_comInst->UndistortPoint(*[input internalStruct], &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)undistortPoints:(NSArray* /* WFPoint* */)inputs results:(NSArray* /* WFPoint* */*)results {
    UINT32 __inputs_ArrayLen = 0;
    bool __inputs_IsTemp = false;
    ABI::Windows::Foundation::Point* __inputs_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(inputs, &__inputs_ArrayLen, &__inputs_Array, &__inputs_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Point* __results_Array = (ABI::Windows::Foundation::Point*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics2>(self);
    THROW_NS_IF_FAILED(_comInst->UndistortPoints(__inputs_ArrayLen, __inputs_Array, __results_ArrayLen, __results_Array));
    if (__inputs_IsTemp)
        CoTaskMemFree(__inputs_Array);
}

@end

@implementation WMDCDepthCorrelatedCoordinateMapper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector3*)unprojectPoint:(WFPoint*)sourcePoint targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->UnprojectPoint(*[sourcePoint internalStruct],
                                 _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(targetCoordinateSystem).Get(),
                                 &unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)unprojectPoints:(NSArray* /* WFPoint* */)sourcePoints
    targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem
                   results:(NSArray* /* WFNVector3* */*)results {
    UINT32 __sourcePoints_ArrayLen = 0;
    bool __sourcePoints_IsTemp = false;
    ABI::Windows::Foundation::Point* __sourcePoints_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(sourcePoints,
                                                          &__sourcePoints_ArrayLen,
                                                          &__sourcePoints_Array,
                                                          &__sourcePoints_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Numerics::Vector3* __results_Array = (ABI::Windows::Foundation::Numerics::Vector3*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(_comInst->UnprojectPoints(
        __sourcePoints_ArrayLen,
        __sourcePoints_Array,
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(targetCoordinateSystem).Get(),
        __results_ArrayLen,
        __results_Array));
    if (__sourcePoints_IsTemp)
        CoTaskMemFree(__sourcePoints_Array);
}

- (WFPoint*)mapPoint:(WFPoint*)sourcePoint
    targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem
    targetCameraIntrinsics:(WMDCCameraIntrinsics*)targetCameraIntrinsics {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->MapPoint(*[sourcePoint internalStruct],
                           _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(targetCoordinateSystem).Get(),
                           _getRtInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(targetCameraIntrinsics).Get(),
                           &unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (void)mapPoints:(NSArray* /* WFPoint* */)sourcePoints
    targetCoordinateSystem:(WPSSpatialCoordinateSystem*)targetCoordinateSystem
    targetCameraIntrinsics:(WMDCCameraIntrinsics*)targetCameraIntrinsics
                   results:(NSArray* /* WFPoint* */*)results {
    UINT32 __sourcePoints_ArrayLen = 0;
    bool __sourcePoints_IsTemp = false;
    ABI::Windows::Foundation::Point* __sourcePoints_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(sourcePoints,
                                                          &__sourcePoints_ArrayLen,
                                                          &__sourcePoints_Array,
                                                          &__sourcePoints_IsTemp))
        assert(0);
    UINT32 __results_ArrayLen = (UINT32)[results count];
    ABI::Windows::Foundation::Point* __results_Array = (ABI::Windows::Foundation::Point*)[results ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper>(self);
    THROW_NS_IF_FAILED(
        _comInst->MapPoints(__sourcePoints_ArrayLen,
                            __sourcePoints_Array,
                            _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(targetCoordinateSystem).Get(),
                            _getRtInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(targetCameraIntrinsics).Get(),
                            __results_ArrayLen,
                            __results_Array));
    if (__sourcePoints_IsTemp)
        CoTaskMemFree(__sourcePoints_Array);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMDCVariablePhotoSequenceController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (float)maxPhotosPerSecond {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPhotosPerSecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)photosPerSecondLimit {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotosPerSecondLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPhotosPerSecondLimit:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->put_PhotosPerSecondLimit(value));
}

- (WMMMediaRatio*)getHighestConcurrentFrameRate:(RTObject<WMMIMediaEncodingProperties>*)captureProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetHighestConcurrentFrameRate(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProperties>(captureProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMMMediaRatio*)getCurrentFrameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentFrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (WMDCFrameControlCapabilities*)frameCapabilities {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameCapabilities(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameControlCapabilities>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WMDCFrameController* */)desiredFrameControllers {
    ComPtr<IVector<ABI::Windows::Media::Devices::Core::FrameController*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IVariablePhotoSequenceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFrameControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WMDCFrameController_create(unmarshalledReturn.Get());
}

@end

@implementation WMDCFrameExposureCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFTimeSpan*)min {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)max {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)step {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMDCFrameExposureCompensationCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (float)min {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)max {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)step {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMDCFrameIsoSpeedCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)min {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)max {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)step {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMDCFrameFocusCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)min {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Min(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)max {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Max(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)step {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Step(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMDCFrameFlashCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)supported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Supported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)redEyeReductionSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedEyeReductionSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)powerSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMDCFrameControlCapabilities

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDCFrameExposureCapabilities*)exposure {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Exposure(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameExposureCapabilities>(unmarshalledReturn.Get());
}

- (WMDCFrameExposureCompensationCapabilities*)exposureCompensation {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameExposureCompensationCapabilities>(unmarshalledReturn.Get());
}

- (WMDCFrameIsoSpeedCapabilities*)isoSpeed {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoSpeed(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameIsoSpeedCapabilities>(unmarshalledReturn.Get());
}

- (WMDCFrameFocusCapabilities*)focus {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFocusCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_Focus(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameFocusCapabilities>(unmarshalledReturn.Get());
}

- (BOOL)photoConfirmationSupported {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoConfirmationSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMDCFrameFlashCapabilities*)flash {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFlashCapabilities> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameControlCapabilities2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Flash(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameFlashCapabilities>(unmarshalledReturn.Get());
}

@end

@implementation WMDCFrameExposureControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAuto:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Auto((boolean)value));
}

- (id /* WFTimeSpan* */)value {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setValue:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

@end

@implementation WMDCFrameExposureCompensationControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* float */)value {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (void)setValue:(id /* float */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(BuildNullable<float>(value)));
}

@end

@implementation WMDCFrameIsoSpeedControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAuto:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Auto((boolean)value));
}

- (id /* unsigned int */)value {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setValue:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(BuildNullable<unsigned int>(value)));
}

@end

@implementation WMDCFrameFocusControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFocusControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* unsigned int */)value {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (void)setValue:(id /* unsigned int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFocusControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(BuildNullable<unsigned int>(value)));
}

@end

@implementation WMDCFrameFlashControl

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFlashControl> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMDCFrameFlashMode)mode {
    ABI::Windows::Media::Devices::Core::FrameFlashMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WMDCFrameFlashMode)unmarshalledReturn;
}

- (void)setMode:(WMDCFrameFlashMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Media::Devices::Core::FrameFlashMode)value));
}

- (BOOL)Auto {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Auto(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAuto:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Auto((boolean)value));
}

- (BOOL)redEyeReduction {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_RedEyeReduction(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setRedEyeReduction:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_RedEyeReduction((boolean)value));
}

- (float)powerPercent {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_PowerPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPowerPercent:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameFlashControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_PowerPercent(value));
}

@end

@implementation WMDCFrameController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Devices.Core.FrameController").Get(), &out));
    return [_createRtProxy<WMDCFrameController>(out.Get()) retain];
}

- (WMDCFrameExposureControl*)exposureControl {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameExposureControl>(unmarshalledReturn.Get());
}

- (WMDCFrameExposureCompensationControl*)exposureCompensationControl {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameExposureCompensationControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExposureCompensationControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameExposureCompensationControl>(unmarshalledReturn.Get());
}

- (WMDCFrameIsoSpeedControl*)isoSpeedControl {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameIsoSpeedControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsoSpeedControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameIsoSpeedControl>(unmarshalledReturn.Get());
}

- (WMDCFrameFocusControl*)focusControl {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFocusControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameFocusControl>(unmarshalledReturn.Get());
}

- (id /* BOOL */)photoConfirmationEnabled {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhotoConfirmationEnabled(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (void)setPhotoConfirmationEnabled:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_PhotoConfirmationEnabled(BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (WMDCFrameFlashControl*)flashControl {
    ComPtr<ABI::Windows::Media::Devices::Core::IFrameFlashControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Devices::Core::IFrameController2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlashControl(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCFrameFlashControl>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_C_WFNVector2_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector2* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::Numerics::Vector2,
                                          RTCArrayObj<ABI::Windows::Foundation::Numerics::Vector2, WFNVector2, dummyObjCCreator>>>(size,
                                                                                                                                   val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFNVector3_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector3* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::Numerics::Vector3,
                                          RTCArrayObj<ABI::Windows::Foundation::Numerics::Vector3, WFNVector3, dummyObjCCreator>>>(size,
                                                                                                                                   val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Point, RTCArrayObj<ABI::Windows::Foundation::Point, WFPoint, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMDCFrameController_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Devices::Core::FrameController*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Devices::Core::IFrameController*,
                                                                  IVector<ABI::Windows::Media::Devices::Core::FrameController*>,
                                                                  WMDCFrameController,
                                                                  ABI::Windows::Media::Devices::Core::FrameController*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
