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

// WindowsMediaCaptureFrames.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Capture.Frames.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaCaptureFrames.h"
#include "WindowsMediaCaptureFrames_priv.h"

@implementation WMCFMediaFrameSourceGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics> WMCFIMediaFrameSourceGroupStatics_inst() {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroupStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Capture.Frames.MediaFrameSourceGroup").Get(),
                                                       &inst));
    return inst;
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WMCFMediaFrameSourceGroup* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>*>>
        unmarshalledReturn;
    auto _comInst = WMCFIMediaFrameSourceGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                                                    ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>*>,
                                                                FtmBase>>([successRc, failureRc](
            ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>*>* op,
            AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WMCFMediaFrameSourceGroup_create(result.Get()));
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

+ (void)fromIdAsync:(NSString*)id success:(void (^)(WMCFMediaFrameSourceGroup*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>> unmarshalledReturn;
    auto _comInst = WMCFIMediaFrameSourceGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIdAsync(nsStrToHstr(id).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCFMediaFrameSourceGroup>(result.Get()));
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

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WMCFIMediaFrameSourceGroupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WMCFMediaFrameSourceInfo* */)sourceInfos {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceInfo*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceInfos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCFMediaFrameSourceInfo_create(unmarshalledReturn.Get());
}

@end

@implementation WMCFMediaFrameSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameSourceInfo*)info {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Info(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameSourceInfo>(unmarshalledReturn.Get());
}

- (WMCFMediaFrameSourceController*)controller {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Controller(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameSourceController>(unmarshalledReturn.Get());
}

- (NSArray* /* WMCFMediaFrameFormat* */)supportedFormats {
    ComPtr<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameFormat*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMCFMediaFrameFormat_create(unmarshalledReturn.Get());
}

- (WMCFMediaFrameFormat*)currentFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameFormat>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)setFormatAsync:(WMCFMediaFrameFormat*)format {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->SetFormatAsync(_getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(format).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addFormatChangedEvent:(void (^)(WMCFMediaFrameSource*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_FormatChanged(Make<ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameSource_System_Object>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFormatChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FormatChanged(token));
}

- (WMDCCameraIntrinsics*)tryGetCameraIntrinsics:(WMCFMediaFrameFormat*)format {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSource>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryGetCameraIntrinsics(_getRtInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(format).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCCameraIntrinsics>(unmarshalledReturn.Get());
}

@end

@implementation WMCFMediaFrameReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addFrameArrivedEvent:(void (^)(WMCFMediaFrameReader*, WMCFMediaFrameArrivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->add_FrameArrived(
        Make<ITypedEventHandler_Windows_Media_Capture_Frames_MediaFrameReader_Windows_Media_Capture_Frames_MediaFrameArrivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFrameArrivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FrameArrived(token));
}

- (WMCFMediaFrameReference*)tryAcquireLatestFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->TryAcquireLatestFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameReference>(unmarshalledReturn.Get());
}

- (void)startAsyncWithSuccess:(void (^)(WMCFMediaFrameReaderStartStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Capture::Frames::MediaFrameReaderStartStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMCFMediaFrameReaderStartStatus)result);
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

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReader>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCFMediaFrameSourceInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMCMediaStreamType)mediaStreamType {
    ABI::Windows::Media::Capture::MediaStreamType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaStreamType(&unmarshalledReturn));
    return (WMCMediaStreamType)unmarshalledReturn;
}

- (WMCFMediaFrameSourceKind)sourceKind {
    ABI::Windows::Media::Capture::Frames::MediaFrameSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceKind(&unmarshalledReturn));
    return (WMCFMediaFrameSourceKind)unmarshalledReturn;
}

- (WMCFMediaFrameSourceGroup*)sourceGroup {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameSourceGroup>(unmarshalledReturn.Get());
}

- (WDEDeviceInformation*)deviceInformation {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (NSDictionary* /* WFGUID*, RTObject* */)properties {
    ComPtr<IMapView<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WFGUID_RTObject_create(unmarshalledReturn.Get());
}

- (WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

@end

@implementation WMCFMediaFrameSourceController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getPropertyAsync:(NSString*)propertyId
                 success:(void (^)(WMCFMediaFrameSourceGetPropertyResult*))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertyAsync(nsStrToHstr(propertyId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMCFMediaFrameSourceGetPropertyResult>(result.Get()));
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

- (void)setPropertyAsync:(NSString*)propertyId
           propertyValue:(RTObject*)propertyValue
                 success:(void (^)(WMCFMediaFrameSourceSetPropertyStatus))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController>(self);
    THROW_NS_IF_FAILED(_comInst->SetPropertyAsync(nsStrToHstr(propertyId).Get(), [propertyValue comObj].Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Capture::Frames::MediaFrameSourceSetPropertyStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMCFMediaFrameSourceSetPropertyStatus)result);
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

- (WMDVideoDeviceController*)videoDeviceController {
    ComPtr<ABI::Windows::Media::Devices::IVideoDeviceController> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceController>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoDeviceController(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDVideoDeviceController>(unmarshalledReturn.Get());
}

@end

@implementation WMCFMediaFrameFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)majorType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_MajorType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)subtype {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtype(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMMMediaRatio*)frameRate {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaRatio> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameRate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaRatio>(unmarshalledReturn.Get());
}

- (NSDictionary* /* WFGUID*, RTObject* */)properties {
    ComPtr<IMapView<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WFGUID_RTObject_create(unmarshalledReturn.Get());
}

- (WMCFVideoMediaFrameFormat*)videoFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrameFormat>(unmarshalledReturn.Get());
}

@end

@implementation WMCFMediaFrameArrivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameArrivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WMCFMediaFrameReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameSourceKind)sourceKind {
    ABI::Windows::Media::Capture::Frames::MediaFrameSourceKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceKind(&unmarshalledReturn));
    return (WMCFMediaFrameSourceKind)unmarshalledReturn;
}

- (WMCFMediaFrameFormat*)format {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_Format(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameFormat>(unmarshalledReturn.Get());
}

- (id /* WFTimeSpan* */)systemRelativeTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemRelativeTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (NSDictionary* /* WFGUID*, RTObject* */)properties {
    ComPtr<IMapView<GUID, IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_WFGUID_RTObject_create(unmarshalledReturn.Get());
}

- (WMCFBufferMediaFrame*)bufferMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IBufferMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_BufferMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFBufferMediaFrame>(unmarshalledReturn.Get());
}

- (WMCFVideoMediaFrame*)videoMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrame>(unmarshalledReturn.Get());
}

- (WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameReference>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSystem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPSSpatialCoordinateSystem>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMCFMediaFrameSourceGetPropertyResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameSourceGetPropertyStatus)status {
    ABI::Windows::Media::Capture::Frames::MediaFrameSourceGetPropertyStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMCFMediaFrameSourceGetPropertyStatus)unmarshalledReturn;
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGetPropertyResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WMCFVideoMediaFrameFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameFormat*)mediaFrameFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaFrameFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameFormat>(unmarshalledReturn.Get());
}

- (WMCFDepthMediaFrameFormat*)depthFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepthFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFDepthMediaFrameFormat>(unmarshalledReturn.Get());
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMCFDepthMediaFrameFormat

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFVideoMediaFrameFormat*)videoFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrameFormat>(unmarshalledReturn.Get());
}

- (double)depthScaleInMeters {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepthScaleInMeters(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMCFBufferMediaFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IBufferMediaFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameReference*)frameReference {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IBufferMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameReference>(unmarshalledReturn.Get());
}

- (RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IBufferMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

@end

@implementation WMCFVideoMediaFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameReference*)frameReference {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameReference>(unmarshalledReturn.Get());
}

- (WMCFVideoMediaFrameFormat*)videoFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrameFormat>(unmarshalledReturn.Get());
}

- (WGISoftwareBitmap*)softwareBitmap {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_SoftwareBitmap(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

- (RTObject<WGDDIDirect3DSurface>*)direct3DSurface {
    ComPtr<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direct3DSurface(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGDDIDirect3DSurface>(unmarshalledReturn.Get());
}

- (WMDCCameraIntrinsics*)cameraIntrinsics {
    ComPtr<ABI::Windows::Media::Devices::Core::ICameraIntrinsics> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraIntrinsics(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCCameraIntrinsics>(unmarshalledReturn.Get());
}

- (WMCFInfraredMediaFrame*)infraredMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_InfraredMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFInfraredMediaFrame>(unmarshalledReturn.Get());
}

- (WMCFDepthMediaFrame*)depthMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepthMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFDepthMediaFrame>(unmarshalledReturn.Get());
}

- (WMVideoFrame*)getVideoFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetVideoFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMCFInfraredMediaFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameReference*)frameReference {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameReference>(unmarshalledReturn.Get());
}

- (WMCFVideoMediaFrame*)videoMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrame>(unmarshalledReturn.Get());
}

- (BOOL)isIlluminated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IInfraredMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsIlluminated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WMCFDepthMediaFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMCFMediaFrameReference*)frameReference {
    ComPtr<ABI::Windows::Media::Capture::Frames::IMediaFrameReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFMediaFrameReference>(unmarshalledReturn.Get());
}

- (WMCFVideoMediaFrame*)videoMediaFrame {
    ComPtr<ABI::Windows::Media::Capture::Frames::IVideoMediaFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_VideoMediaFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFVideoMediaFrame>(unmarshalledReturn.Get());
}

- (WMCFDepthMediaFrameFormat*)depthFormat {
    ComPtr<ABI::Windows::Media::Capture::Frames::IDepthMediaFrameFormat> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DepthFormat(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMCFDepthMediaFrameFormat>(unmarshalledReturn.Get());
}

- (WMDCDepthCorrelatedCoordinateMapper*)tryCreateCoordinateMapper:(WMDCCameraIntrinsics*)cameraIntrinsics
                                                 coordinateSystem:(WPSSpatialCoordinateSystem*)coordinateSystem {
    ComPtr<ABI::Windows::Media::Devices::Core::IDepthCorrelatedCoordinateMapper> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Capture::Frames::IDepthMediaFrame>(self);
    THROW_NS_IF_FAILED(_comInst->TryCreateCoordinateMapper(
        _getRtInterface<ABI::Windows::Media::Devices::Core::ICameraIntrinsics>(cameraIntrinsics).Get(),
        _getRtInterface<ABI::Windows::Perception::Spatial::ISpatialCoordinateSystem>(coordinateSystem).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDCDepthCorrelatedCoordinateMapper>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WMCFMediaFrameFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameFormat*>,
                                         RTArrayObj<ABI::Windows::Media::Capture::Frames::IMediaFrameFormat*,
                                                    IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameFormat*>,
                                                    WMCFMediaFrameFormat,
                                                    ABI::Windows::Media::Capture::Frames::MediaFrameFormat*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCFMediaFrameSourceGroup_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>,
                                         RTArrayObj<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceGroup*,
                                                    IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*>,
                                                    WMCFMediaFrameSourceGroup,
                                                    ABI::Windows::Media::Capture::Frames::MediaFrameSourceGroup*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMCFMediaFrameSourceInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceInfo*>,
                                         RTArrayObj<ABI::Windows::Media::Capture::Frames::IMediaFrameSourceInfo*,
                                                    IVectorView<ABI::Windows::Media::Capture::Frames::MediaFrameSourceInfo*>,
                                                    WMCFMediaFrameSourceInfo,
                                                    ABI::Windows::Media::Capture::Frames::MediaFrameSourceInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_WFGUID_RTObject_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter =
        std::make_unique<DictionaryAdapterObj<IMapView<GUID, IInspectable*>,
                                              DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<GUID, GUID, WFGUID, IInspectable*>>,
                                              RTMapViewObj<GUID,
                                                           GUID,
                                                           IInspectable*,
                                                           IInspectable*,
                                                           WFGUID,
                                                           RTObject,
                                                           IMapView<GUID, IInspectable*>,
                                                           dummyObjCCreator,
                                                           dummyObjCCreator,
                                                           dummyWRLCreator,
                                                           dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
