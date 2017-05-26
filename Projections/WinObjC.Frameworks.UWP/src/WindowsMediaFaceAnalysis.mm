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

// WindowsMediaFaceAnalysis.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.FaceAnalysis.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaFaceAnalysis.h"
#include "WindowsMediaFaceAnalysis_priv.h"

@implementation WMFDetectedFace

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::FaceAnalysis::IDetectedFace> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGIBitmapBounds*)faceBox {
    ABI::Windows::Graphics::Imaging::BitmapBounds unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IDetectedFace>(self);
    THROW_NS_IF_FAILED(_comInst->get_FaceBox(&unmarshalledReturn));
    return WGIBitmapBounds_create(unmarshalledReturn);
}

@end

@implementation WMFFaceTracker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceTracker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceTrackerStatics> WMFIFaceTrackerStatics_inst() {
    ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceTrackerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.FaceAnalysis.FaceTracker").Get(), &inst));
    return inst;
}

+ (void)createAsyncWithSuccess:(void (^)(WMFFaceTracker*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::FaceAnalysis::FaceTracker*>> unmarshalledReturn;
    auto _comInst = WMFIFaceTrackerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::FaceAnalysis::FaceTracker*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::FaceAnalysis::FaceTracker*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceTracker> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMFFaceTracker>(result.Get()));
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

+ (NSArray* /* WGIBitmapPixelFormat */)getSupportedBitmapPixelFormats {
    ComPtr<IVectorView<ABI::Windows::Graphics::Imaging::BitmapPixelFormat>> unmarshalledReturn;
    auto _comInst = WMFIFaceTrackerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSupportedBitmapPixelFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIBitmapPixelFormat_create(unmarshalledReturn.Get());
}

+ (BOOL)isBitmapPixelFormatSupported:(WGIBitmapPixelFormat)bitmapPixelFormat {
    boolean unmarshalledReturn;
    auto _comInst = WMFIFaceTrackerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsBitmapPixelFormatSupported((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)bitmapPixelFormat, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WMFIFaceTrackerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)processNextFrameAsync:(WMVideoFrame*)videoFrame
                      success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceTracker>(self);
    THROW_NS_IF_FAILED(
        _comInst->ProcessNextFrameAsync(_getRtInterface<ABI::Windows::Media::IVideoFrame>(videoFrame).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_WMFDetectedFace_create(result.Get()));
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

- (WGIBitmapSize*)minDetectableFaceSize {
    ABI::Windows::Graphics::Imaging::BitmapSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinDetectableFaceSize(&unmarshalledReturn));
    return WGIBitmapSize_create(unmarshalledReturn);
}

- (void)setMinDetectableFaceSize:(WGIBitmapSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinDetectableFaceSize(*[value internalStruct]));
}

- (WGIBitmapSize*)maxDetectableFaceSize {
    ABI::Windows::Graphics::Imaging::BitmapSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceTracker>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDetectableFaceSize(&unmarshalledReturn));
    return WGIBitmapSize_create(unmarshalledReturn);
}

- (void)setMaxDetectableFaceSize:(WGIBitmapSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceTracker>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxDetectableFaceSize(*[value internalStruct]));
}

@end

@implementation WMFFaceDetector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceDetector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceDetectorStatics> WMFIFaceDetectorStatics_inst() {
    ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceDetectorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.FaceAnalysis.FaceDetector").Get(), &inst));
    return inst;
}

+ (void)createAsyncWithSuccess:(void (^)(WMFFaceDetector*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::FaceAnalysis::FaceDetector*>> unmarshalledReturn;
    auto _comInst = WMFIFaceDetectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::FaceAnalysis::FaceDetector*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::FaceAnalysis::FaceDetector*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::FaceAnalysis::IFaceDetector> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMFFaceDetector>(result.Get()));
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

+ (NSArray* /* WGIBitmapPixelFormat */)getSupportedBitmapPixelFormats {
    ComPtr<IVectorView<ABI::Windows::Graphics::Imaging::BitmapPixelFormat>> unmarshalledReturn;
    auto _comInst = WMFIFaceDetectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSupportedBitmapPixelFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIBitmapPixelFormat_create(unmarshalledReturn.Get());
}

+ (BOOL)isBitmapPixelFormatSupported:(WGIBitmapPixelFormat)bitmapPixelFormat {
    boolean unmarshalledReturn;
    auto _comInst = WMFIFaceDetectorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->IsBitmapPixelFormatSupported((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)bitmapPixelFormat, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WMFIFaceDetectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)detectFacesAsync:(WGISoftwareBitmap*)image
                 success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success
                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(
        _comInst->DetectFacesAsync(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(image).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_WMFDetectedFace_create(result.Get()));
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

- (void)detectFacesWithSearchAreaAsync:(WGISoftwareBitmap*)image
                            searchArea:(WGIBitmapBounds*)searchArea
                               success:(void (^)(NSMutableArray* /* WMFDetectedFace* */))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(
        _comInst->DetectFacesWithSearchAreaAsync(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(image).Get(),
                                                 *[searchArea internalStruct],
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableArray_WMFDetectedFace_create(result.Get()));
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

- (WGIBitmapSize*)minDetectableFaceSize {
    ABI::Windows::Graphics::Imaging::BitmapSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinDetectableFaceSize(&unmarshalledReturn));
    return WGIBitmapSize_create(unmarshalledReturn);
}

- (void)setMinDetectableFaceSize:(WGIBitmapSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(_comInst->put_MinDetectableFaceSize(*[value internalStruct]));
}

- (WGIBitmapSize*)maxDetectableFaceSize {
    ABI::Windows::Graphics::Imaging::BitmapSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxDetectableFaceSize(&unmarshalledReturn));
    return WGIBitmapSize_create(unmarshalledReturn);
}

- (void)setMaxDetectableFaceSize:(WGIBitmapSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::FaceAnalysis::IFaceDetector>(self);
    THROW_NS_IF_FAILED(_comInst->put_MaxDetectableFaceSize(*[value internalStruct]));
}

@end

id RTProxiedNSArray_WGIBitmapPixelFormat_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::Imaging::BitmapPixelFormat>,
                                         RTArrayObj<ABI::Windows::Graphics::Imaging::BitmapPixelFormat,
                                                    IVectorView<ABI::Windows::Graphics::Imaging::BitmapPixelFormat>,
                                                    WGIBitmapPixelFormat,
                                                    ABI::Windows::Graphics::Imaging::BitmapPixelFormat,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WMFDetectedFace_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>,
                                                RTMutableArrayObj<ABI::Windows::Media::FaceAnalysis::IDetectedFace*,
                                                                  IVector<ABI::Windows::Media::FaceAnalysis::DetectedFace*>,
                                                                  WMFDetectedFace,
                                                                  ABI::Windows::Media::FaceAnalysis::DetectedFace*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
