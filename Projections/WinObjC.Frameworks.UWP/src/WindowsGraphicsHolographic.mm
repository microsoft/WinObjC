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

// WindowsGraphicsHolographic.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Holographic.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsHolographic.h"
#include "WindowsGraphicsHolographic_priv.h"

@implementation WGHHolographicCamera

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCamera> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFSize*)renderTargetSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderTargetSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (double)viewportScaleFactor {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportScaleFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setViewportScaleFactor:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->put_ViewportScaleFactor(value));
}

- (BOOL)isStereo {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsStereo(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setNearPlaneDistance:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->SetNearPlaneDistance(value));
}

- (void)setFarPlaneDistance:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCamera>(self);
    THROW_NS_IF_FAILED(_comInst->SetFarPlaneDistance(value));
}

@end

@implementation WGHHolographicSpace

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpace> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpaceStatics> WGHIHolographicSpaceStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpaceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Holographic.HolographicSpace").Get(),
                                                       &inst));
    return inst;
}

+ (WGHHolographicSpace*)createForCoreWindow:(WUCCoreWindow*)window {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpace> unmarshalledReturn;
    auto _comInst = WGHIHolographicSpaceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateForCoreWindow(_getRtInterface<ABI::Windows::UI::Core::ICoreWindow>(window).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicSpace>(unmarshalledReturn.Get());
}

- (WGHHolographicAdapterId*)primaryAdapterId {
    ABI::Windows::Graphics::Holographic::HolographicAdapterId unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryAdapterId(&unmarshalledReturn));
    return WGHHolographicAdapterId_create(unmarshalledReturn);
}

- (void)setDirect3D11Device:(RTObject<WGDDIDirect3DDevice>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetDirect3D11Device(_getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>(value).Get()));
}

- (EventRegistrationToken)addCameraAddedEvent:(void (^)(WGHHolographicSpace*, WGHHolographicSpaceCameraAddedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->add_CameraAdded(
        Make<
            ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraAddedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraAddedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraAdded(cookie));
}

- (EventRegistrationToken)addCameraRemovedEvent:(void (^)(WGHHolographicSpace*, WGHHolographicSpaceCameraRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->add_CameraRemoved(
        Make<
            ITypedEventHandler_Windows_Graphics_Holographic_HolographicSpace_Windows_Graphics_Holographic_HolographicSpaceCameraRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCameraRemovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CameraRemoved(cookie));
}

- (WGHHolographicFrame*)createNextFrame {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpace>(self);
    THROW_NS_IF_FAILED(_comInst->CreateNextFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicFrame>(unmarshalledReturn.Get());
}

@end

@implementation WGHHolographicSpaceCameraAddedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGHHolographicCamera*)camera {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Camera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicCamera>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraAddedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WGHHolographicSpaceCameraRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGHHolographicCamera*)camera {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicSpaceCameraRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Camera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicCamera>(unmarshalledReturn.Get());
}

@end

@implementation WGHHolographicFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WGHHolographicCamera* */)addedCameras {
    ComPtr<IVectorView<ABI::Windows::Graphics::Holographic::HolographicCamera*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_AddedCameras(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGHHolographicCamera_create(unmarshalledReturn.Get());
}

- (NSArray* /* WGHHolographicCamera* */)removedCameras {
    ComPtr<IVectorView<ABI::Windows::Graphics::Holographic::HolographicCamera*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemovedCameras(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGHHolographicCamera_create(unmarshalledReturn.Get());
}

- (WGHHolographicCameraRenderingParameters*)getRenderingParameters:(WGHHolographicCameraPose*)cameraPose {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetRenderingParameters(_getRtInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(cameraPose).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicCameraRenderingParameters>(unmarshalledReturn.Get());
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WGHHolographicFramePrediction*)currentPrediction {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicFramePrediction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPrediction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicFramePrediction>(unmarshalledReturn.Get());
}

- (void)updateCurrentPrediction {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateCurrentPrediction());
}

- (WGHHolographicFramePresentResult)presentUsingCurrentPrediction {
    ABI::Windows::Graphics::Holographic::HolographicFramePresentResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->PresentUsingCurrentPrediction(&unmarshalledReturn));
    return (WGHHolographicFramePresentResult)unmarshalledReturn;
}

- (WGHHolographicFramePresentResult)presentUsingCurrentPredictionWithBehavior:(WGHHolographicFramePresentWaitBehavior)waitBehavior {
    ABI::Windows::Graphics::Holographic::HolographicFramePresentResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->PresentUsingCurrentPredictionWithBehavior(
        (ABI::Windows::Graphics::Holographic::HolographicFramePresentWaitBehavior)waitBehavior, &unmarshalledReturn));
    return (WGHHolographicFramePresentResult)unmarshalledReturn;
}

- (void)waitForFrameToFinish {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFrame>(self);
    THROW_NS_IF_FAILED(_comInst->WaitForFrameToFinish());
}

@end

@implementation WGHHolographicCameraPose

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCameraPose> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGHHolographicCamera*)holographicCamera {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCamera> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_HolographicCamera(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGHHolographicCamera>(unmarshalledReturn.Get());
}

- (WFRect*)viewport {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_Viewport(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (id /* WGHHolographicStereoTransform* */)tryGetViewTransform:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<IReference<ABI::Windows::Graphics::Holographic::HolographicStereoTransform>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetViewTransform(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WGHHolographicStereoTransform, ABI::Windows::Graphics::Holographic::HolographicStereoTransform>::convert(
        unmarshalledReturn.Get());
}

- (WGHHolographicStereoTransform*)projectionTransform {
    ABI::Windows::Graphics::Holographic::HolographicStereoTransform unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProjectionTransform(&unmarshalledReturn));
    return WGHHolographicStereoTransform_create(unmarshalledReturn);
}

- (id /* WPSSpatialBoundingFrustum* */)tryGetCullingFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<IReference<ABI::Windows::Perception::Spatial::SpatialBoundingFrustum>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetCullingFrustum(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WPSSpatialBoundingFrustum, ABI::Windows::Perception::Spatial::SpatialBoundingFrustum>::convert(
        unmarshalledReturn.Get());
}

- (id /* WPSSpatialBoundingFrustum* */)tryGetVisibleFrustum:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<IReference<ABI::Windows::Perception::Spatial::SpatialBoundingFrustum>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetVisibleFrustum(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WPSSpatialBoundingFrustum, ABI::Windows::Perception::Spatial::SpatialBoundingFrustum>::convert(
        unmarshalledReturn.Get());
}

- (double)nearPlaneDistance {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_NearPlaneDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)farPlaneDistance {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraPose>(self);
    THROW_NS_IF_FAILED(_comInst->get_FarPlaneDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGHHolographicCameraRenderingParameters

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setFocusPoint:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetFocusPoint(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                                *[position internalStruct]));
}

- (void)setFocusPointWithNormal:(WPSSpatialCoordinateSystem*)coordinateSystem position:(WFNVector3*)position normal:(WFNVector3*)normal {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->SetFocusPointWithNormal(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        *[position internalStruct],
        *[normal internalStruct]));
}

- (void)setFocusPointWithNormalLinearVelocity:(WPSSpatialCoordinateSystem*)coordinateSystem
                                     position:(WFNVector3*)position
                                       normal:(WFNVector3*)normal
                               linearVelocity:(WFNVector3*)linearVelocity {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->SetFocusPointWithNormalLinearVelocity(
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        *[position internalStruct],
        *[normal internalStruct],
        *[linearVelocity internalStruct]));
}

- (RTObject<WGDDIDirect3DDevice>*)direct3D11Device {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direct3D11Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDIDirect3DDevice>(unmarshalledReturn.Get());
}

- (RTObject<WGDDIDirect3DSurface>*)direct3D11BackBuffer {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicCameraRenderingParameters>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direct3D11BackBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDIDirect3DSurface>(unmarshalledReturn.Get());
}

@end

@implementation WGHHolographicFramePrediction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Holographic::IHolographicFramePrediction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WGHHolographicCameraPose* */)cameraPoses {
    ComPtr<IVectorView<ABI::Windows::Graphics::Holographic::HolographicCameraPose*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFramePrediction>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraPoses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGHHolographicCameraPose_create(unmarshalledReturn.Get());
}

- (WPPerceptionTimestamp*)timestamp {
    ComPtr<ABI::Windows::Perception::IPerceptionTimestamp> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Holographic::IHolographicFramePrediction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPPerceptionTimestamp>(unmarshalledReturn.Get());
}

@end

@implementation WGHHolographicStereoTransform {
    ABI::Windows::Graphics::Holographic::HolographicStereoTransform structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Holographic::HolographicStereoTransform)s {
    WGHHolographicStereoTransform* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Holographic::HolographicStereoTransform*)internalStruct {
    return &structVal;
}
- (WFNMatrix4x4*)left {
    return WFNMatrix4x4_create(structVal.Left);
}
- (void)setLeft:(WFNMatrix4x4*)val {
    structVal.Left = *[val internalStruct];
}
- (WFNMatrix4x4*)right {
    return WFNMatrix4x4_create(structVal.Right);
}
- (void)setRight:(WFNMatrix4x4*)val {
    structVal.Right = *[val internalStruct];
}
@end
@implementation WGHHolographicAdapterId {
    ABI::Windows::Graphics::Holographic::HolographicAdapterId structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Holographic::HolographicAdapterId)s {
    WGHHolographicAdapterId* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Holographic::HolographicAdapterId*)internalStruct {
    return &structVal;
}
- (unsigned int)lowPart {
    return structVal.LowPart;
}
- (void)setLowPart:(unsigned int)val {
    structVal.LowPart = val;
}
- (int)highPart {
    return structVal.HighPart;
}
- (void)setHighPart:(int)val {
    structVal.HighPart = val;
}
@end
id RTProxiedNSArray_WGHHolographicCamera_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::Holographic::HolographicCamera*>,
                                         RTArrayObj<ABI::Windows::Graphics::Holographic::IHolographicCamera*,
                                                    IVectorView<ABI::Windows::Graphics::Holographic::HolographicCamera*>,
                                                    WGHHolographicCamera,
                                                    ABI::Windows::Graphics::Holographic::HolographicCamera*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGHHolographicCameraPose_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::Holographic::HolographicCameraPose*>,
                                         RTArrayObj<ABI::Windows::Graphics::Holographic::IHolographicCameraPose*,
                                                    IVectorView<ABI::Windows::Graphics::Holographic::HolographicCameraPose*>,
                                                    WGHHolographicCameraPose,
                                                    ABI::Windows::Graphics::Holographic::HolographicCameraPose*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
