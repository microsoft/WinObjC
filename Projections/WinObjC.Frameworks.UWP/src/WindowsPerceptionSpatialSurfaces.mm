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

// WindowsPerceptionSpatialSurfaces.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Perception.Spatial.Surfaces.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPerceptionSpatialSurfaces.h"
#include "WindowsPerceptionSpatialSurfaces_priv.h"

@implementation WPSSSpatialSurfaceInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WFDateTime*)updateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (id /* WPSSpatialBoundingOrientedBox* */)tryGetBounds:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<IReference<ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetBounds(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
                               unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WPSSpatialBoundingOrientedBox, ABI::Windows::Perception::Spatial::SpatialBoundingOrientedBox>::convert(
        unmarshalledReturn.Get());
}

- (void)tryComputeLatestMeshAsync:(double)maxTrianglesPerCubicMeter
                          success:(void (^)(WPSSSpatialSurfaceMesh*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLatestMeshAsync(maxTrianglesPerCubicMeter, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPSSSpatialSurfaceMesh>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)tryComputeLatestMeshWithOptionsAsync:(double)maxTrianglesPerCubicMeter
                                     options:(WPSSSpatialSurfaceMeshOptions*)options
                                     success:(void (^)(WPSSSpatialSurfaceMesh*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->TryComputeLatestMeshWithOptionsAsync(
        maxTrianglesPerCubicMeter,
        _getRtInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(options).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceMesh*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WPSSSpatialSurfaceMesh>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

@end

@implementation WPSSSpatialSurfaceMeshBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGDDirectXPixelFormat)format {
    ABI::Windows::Graphics::DirectX::DirectXPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(&unmarshalledReturn));
    return (WGDDirectXPixelFormat)unmarshalledReturn;
}

- (unsigned int)stride {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stride(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)elementCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WSSIBuffer>*)data {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WPSSSpatialSurfaceMesh

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WPSSSpatialSurfaceInfo*)surfaceInfo {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_SurfaceInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSSpatialSurfaceInfo>(unmarshalledReturn.Get());
}

- (WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

- (WPSSSpatialSurfaceMeshBuffer*)triangleIndices {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriangleIndices(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSSpatialSurfaceMeshBuffer>(unmarshalledReturn.Get());
}

- (WPSSSpatialSurfaceMeshBuffer*)vertexPositions {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexPositions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSSpatialSurfaceMeshBuffer>(unmarshalledReturn.Get());
}

- (WFNVector3*)vertexPositionScale {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexPositionScale(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (WPSSSpatialSurfaceMeshBuffer*)vertexNormals {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMesh>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexNormals(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSSpatialSurfaceMeshBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WPSSSpatialSurfaceMeshOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshOptions").Get(), &out));
    return [_createRtProxy<WPSSSpatialSurfaceMeshOptions>(out.Get()) retain];
}

ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> WPSSISpatialSurfaceMeshOptionsStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptionsStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceMeshOptions").Get(), &inst));
    return inst;
}

+ (NSArray* /* WGDDirectXPixelFormat */)supportedVertexPositionFormats {
    ComPtr<IVectorView<ABI::Windows::Graphics::DirectX::DirectXPixelFormat>> unmarshalledReturn;
    auto _comInst = WPSSISpatialSurfaceMeshOptionsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedVertexPositionFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGDDirectXPixelFormat_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WGDDirectXPixelFormat */)supportedTriangleIndexFormats {
    ComPtr<IVectorView<ABI::Windows::Graphics::DirectX::DirectXPixelFormat>> unmarshalledReturn;
    auto _comInst = WPSSISpatialSurfaceMeshOptionsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedTriangleIndexFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGDDirectXPixelFormat_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WGDDirectXPixelFormat */)supportedVertexNormalFormats {
    ComPtr<IVectorView<ABI::Windows::Graphics::DirectX::DirectXPixelFormat>> unmarshalledReturn;
    auto _comInst = WPSSISpatialSurfaceMeshOptionsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedVertexNormalFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGDDirectXPixelFormat_create(unmarshalledReturn.Get());
}

- (WGDDirectXPixelFormat)vertexPositionFormat {
    ABI::Windows::Graphics::DirectX::DirectXPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexPositionFormat(&unmarshalledReturn));
    return (WGDDirectXPixelFormat)unmarshalledReturn;
}

- (void)setVertexPositionFormat:(WGDDirectXPixelFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_VertexPositionFormat((ABI::Windows::Graphics::DirectX::DirectXPixelFormat)value));
}

- (WGDDirectXPixelFormat)triangleIndexFormat {
    ABI::Windows::Graphics::DirectX::DirectXPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TriangleIndexFormat(&unmarshalledReturn));
    return (WGDDirectXPixelFormat)unmarshalledReturn;
}

- (void)setTriangleIndexFormat:(WGDDirectXPixelFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_TriangleIndexFormat((ABI::Windows::Graphics::DirectX::DirectXPixelFormat)value));
}

- (WGDDirectXPixelFormat)vertexNormalFormat {
    ABI::Windows::Graphics::DirectX::DirectXPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_VertexNormalFormat(&unmarshalledReturn));
    return (WGDDirectXPixelFormat)unmarshalledReturn;
}

- (void)setVertexNormalFormat:(WGDDirectXPixelFormat)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_VertexNormalFormat((ABI::Windows::Graphics::DirectX::DirectXPixelFormat)value));
}

- (BOOL)includeVertexNormals {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IncludeVertexNormals(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIncludeVertexNormals:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceMeshOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IncludeVertexNormals((boolean)value));
}

@end

@implementation WPSSSpatialSurfaceObserver

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceObserver").Get(),
                                              &out));
    return [_createRtProxy<WPSSSpatialSurfaceObserver>(out.Get()) retain];
}

ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> WPSSISpatialSurfaceObserverStatics_inst() {
    ComPtr<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserverStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Perception.Spatial.Surfaces.SpatialSurfaceObserver").Get(), &inst));
    return inst;
}

+ (void)requestAccessAsyncWithSuccess:(void (^)(WPSSpatialPerceptionAccessStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>> unmarshalledReturn;
    auto _comInst = WPSSISpatialSurfaceObserverStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Perception::Spatial::SpatialPerceptionAccessStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WPSSpatialPerceptionAccessStatus)result);
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (NSDictionary* /* WFGUID*, WPSSSpatialSurfaceInfo* */)getObservedSurfaces {
    ComPtr<IMapView<GUID, ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>(self);
    THROW_NS_IF_FAILED(_comInst->GetObservedSurfaces(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WFGUID_WPSSSpatialSurfaceInfo_create(unmarshalledReturn.Get());
}

- (void)setBoundingVolume:(WPSSpatialBoundingVolume*)bounds {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetBoundingVolume(_getRtInterface<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume>(bounds).Get()));
}

- (void)setBoundingVolumes:(id<NSFastEnumeration> /* WPSSpatialBoundingVolume* */)bounds {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>(self);
    THROW_NS_IF_FAILED(_comInst->SetBoundingVolumes(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Perception::Spatial::SpatialBoundingVolume*,
                                                              ABI::Windows::Perception::Spatial::ISpatialBoundingVolume*>>::type>*>(
            ConvertToIterable<
                WPSSpatialBoundingVolume,
                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Perception::Spatial::SpatialBoundingVolume*,
                                                                  ABI::Windows::Perception::Spatial::ISpatialBoundingVolume*>>(bounds)
                .Get())));
}

- (EventRegistrationToken)addObservedSurfacesChangedEvent:(void (^)(WPSSSpatialSurfaceObserver*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>(self);
    THROW_NS_IF_FAILED(_comInst->add_ObservedSurfacesChanged(
        Make<ITypedEventHandler_Windows_Perception_Spatial_Surfaces_SpatialSurfaceObserver_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeObservedSurfacesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceObserver>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ObservedSurfacesChanged(token));
}

@end

id RTProxiedIterableNSArray_WPSSpatialBoundingVolume_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter =
        std::make_unique<IterableArrayAdapterObj<IIterable<ABI::Windows::Perception::Spatial::SpatialBoundingVolume*>,
                                                 RTIterableObj<ABI::Windows::Perception::Spatial::ISpatialBoundingVolume*,
                                                               IIterable<ABI::Windows::Perception::Spatial::SpatialBoundingVolume*>,
                                                               WPSSpatialBoundingVolume,
                                                               ABI::Windows::Perception::Spatial::SpatialBoundingVolume*,
                                                               dummyObjCCreator,
                                                               dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGDDirectXPixelFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::DirectX::DirectXPixelFormat>,
                                         RTArrayObj<ABI::Windows::Graphics::DirectX::DirectXPixelFormat,
                                                    IVectorView<ABI::Windows::Graphics::DirectX::DirectXPixelFormat>,
                                                    WGDDirectXPixelFormat,
                                                    ABI::Windows::Graphics::DirectX::DirectXPixelFormat,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_WFGUID_WPSSSpatialSurfaceInfo_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<GUID, ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<GUID, GUID, WFGUID, ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo*>>,
        RTMapViewObj<GUID,
                     GUID,
                     ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo*,
                     ABI::Windows::Perception::Spatial::Surfaces::ISpatialSurfaceInfo*,
                     WFGUID,
                     WPSSSpatialSurfaceInfo,
                     IMapView<GUID, ABI::Windows::Perception::Spatial::Surfaces::SpatialSurfaceInfo*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
