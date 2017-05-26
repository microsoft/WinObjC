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

// WindowsGraphicsImaging.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Imaging.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsGraphicsImaging_priv.h"

@implementation WGIIBitmapPropertiesView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getPropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPropertiesAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IMap<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapPropertySet>(result.Get()));
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

@implementation WGIIBitmapFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (WGIBitmapPropertiesView*)bitmapProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapPropertiesView>(unmarshalledReturn.Get());
}

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (double)dpiX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dpiY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetPixelDataAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPixelDataTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                               (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                               _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                               (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                               (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

@implementation WGIIBitmapFrameWithSoftwareBitmap

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getSoftwareBitmapAsyncWithSuccess:(void (^)(WGISoftwareBitmap*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapConvertedAsync:(WGIBitmapPixelFormat)pixelFormat
                              alphaMode:(WGIBitmapAlphaMode)alphaMode
                                success:(void (^)(WGISoftwareBitmap*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapConvertedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                                 (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                                alphaMode:(WGIBitmapAlphaMode)alphaMode
                                transform:(WGIBitmapTransform*)transform
                      exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                      colorManagementMode:(WGIColorManagementMode)colorManagementMode
                                  success:(void (^)(WGISoftwareBitmap*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetSoftwareBitmapTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                    (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                                    (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                                    (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (WGIBitmapPropertiesView*)bitmapProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapPropertiesView>(unmarshalledReturn.Get());
}

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (double)dpiX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dpiY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetPixelDataAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPixelDataTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                               (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                               _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                               (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                               (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

@implementation WGIBitmapTransform

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTransform> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Imaging.BitmapTransform").Get(), &out));
    return [_createRtProxy<WGIBitmapTransform>(out.Get()) retain];
}

- (unsigned int)scaledWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaledWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaledWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaledWidth(value));
}

- (unsigned int)scaledHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScaledHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setScaledHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScaledHeight(value));
}

- (WGIBitmapInterpolationMode)interpolationMode {
    ABI::Windows::Graphics::Imaging::BitmapInterpolationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterpolationMode(&unmarshalledReturn));
    return (WGIBitmapInterpolationMode)unmarshalledReturn;
}

- (void)setInterpolationMode:(WGIBitmapInterpolationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_InterpolationMode((ABI::Windows::Graphics::Imaging::BitmapInterpolationMode)value));
}

- (WGIBitmapFlip)flip {
    ABI::Windows::Graphics::Imaging::BitmapFlip unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Flip(&unmarshalledReturn));
    return (WGIBitmapFlip)unmarshalledReturn;
}

- (void)setFlip:(WGIBitmapFlip)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Flip((ABI::Windows::Graphics::Imaging::BitmapFlip)value));
}

- (WGIBitmapRotation)rotation {
    ABI::Windows::Graphics::Imaging::BitmapRotation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rotation(&unmarshalledReturn));
    return (WGIBitmapRotation)unmarshalledReturn;
}

- (void)setRotation:(WGIBitmapRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rotation((ABI::Windows::Graphics::Imaging::BitmapRotation)value));
}

- (WGIBitmapBounds*)bounds {
    ABI::Windows::Graphics::Imaging::BitmapBounds unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bounds(&unmarshalledReturn));
    return WGIBitmapBounds_create(unmarshalledReturn);
}

- (void)setBounds:(WGIBitmapBounds*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bounds(*[value internalStruct]));
}

@end

@implementation WGIBitmapTypedValue

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTypedValue> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTypedValueFactory> WGIIBitmapTypedValueFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTypedValueFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Imaging.BitmapTypedValue").Get(), &inst));
    return inst;
}

+ (WGIBitmapTypedValue*)make:(RTObject*)value type:(WFPropertyType)type {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTypedValue> unmarshalledReturn;
    auto _comInst = WGIIBitmapTypedValueFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create([value comObj].Get(), (ABI::Windows::Foundation::PropertyType)type, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGIBitmapTypedValue>(unmarshalledReturn.Get()) retain];
}

- (RTObject*)value {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTypedValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WFPropertyType)type {
    ABI::Windows::Foundation::PropertyType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapTypedValue>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WFPropertyType)unmarshalledReturn;
}

@end

@implementation WGIBitmapPropertySet {
    RTMapObj<HSTRING,
             HSTRING,
             ABI::Windows::Graphics::Imaging::BitmapTypedValue*,
             ABI::Windows::Graphics::Imaging::IBitmapTypedValue*,
             NSString,
             WGIBitmapTypedValue,
             IMap<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj,
                 RTProxiedNSMutableDictionary_NSString_WGIBitmapTypedValue,
                 HSTRING,
                 HSTRING,
                 ABI::Windows::Graphics::Imaging::IBitmapTypedValue*,
                 ABI::Windows::Graphics::Imaging::BitmapTypedValue*,
                 NSString,
                 WGIBitmapTypedValue)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IMap<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Imaging.BitmapPropertySet").Get(), &out));
    return [_createRtProxy<WGIBitmapPropertySet>(out.Get()) retain];
}

@end

@implementation WGIBitmapPropertiesView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getPropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPropertiesAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IMap<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapPropertySet>(result.Get()));
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

@implementation WGIBitmapProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)setPropertiesAsync:
    (id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, WGIBitmapTypedValue* > */)propertiesToSet {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SetPropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>,
                              RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create>(propertiesToSet)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)getPropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                   success:(void (^)(WGIBitmapPropertySet*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPropertiesAsync(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapPropertySet*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IMap<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapPropertySet>(result.Get()));
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

@implementation WGIPixelDataProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* uint8_t */)detachPixelData {
    uint8_t* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IPixelDataProvider>(self);
    THROW_NS_IF_FAILED(_comInst->DetachPixelData(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_UInt8_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WGIImageStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)size {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSize:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(value));
}

- (RTObject<WSSIInputStream>*)getInputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetInputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)getOutputStreamAt:(uint64_t)position {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->GetOutputStreamAt(position, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (uint64_t)position {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)seek:(uint64_t)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(position));
}

- (RTObject<WSSIRandomAccessStream>*)cloneStream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->CloneStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (BOOL)canRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canWrite {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanWrite(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)readAsync:(RTObject<WSSIBuffer>*)buffer
            count:(unsigned int)count
          options:(WSSInputStreamOptions)options
          success:(void (^)(RTObject<WSSIBuffer>*))success
         progress:(void (^)(unsigned int))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IInputStream>(self);
    THROW_NS_IF_FAILED(_comInst->ReadAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                           count,
                                           (ABI::Windows::Storage::Streams::InputStreamOptions)options,
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
            ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
            ABI::Windows::Foundation::IAsyncOperationProgressHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>,
            FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
                         unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<ABI::Windows::Storage::Streams::IBuffer*, unsigned int>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

- (void)writeAsync:(RTObject<WSSIBuffer>*)buffer
           success:(void (^)(unsigned int))success
          progress:(void (^)(unsigned int))progress
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->WriteAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<unsigned int, unsigned int>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, unsigned int status) {
                @autoreleasepool {
                    progressRc(status);
                    return S_OK;
                }
            });
        unmarshalledReturn->put_Progress(progressHandler.Get());
    }
    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<unsigned int, unsigned int>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<unsigned int, unsigned int>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    unsigned int result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(result);
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

- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IOutputStream>(self);
    THROW_NS_IF_FAILED(_comInst->FlushAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IContentTypeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGIBitmapFrame

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapFrame> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (WGIBitmapPropertiesView*)bitmapProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapPropertiesView>(unmarshalledReturn.Get());
}

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (double)dpiX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dpiY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetPixelDataAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPixelDataTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                               (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                               _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                               (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                               (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getSoftwareBitmapAsyncWithSuccess:(void (^)(WGISoftwareBitmap*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapConvertedAsync:(WGIBitmapPixelFormat)pixelFormat
                              alphaMode:(WGIBitmapAlphaMode)alphaMode
                                success:(void (^)(WGISoftwareBitmap*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapConvertedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                                 (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                                alphaMode:(WGIBitmapAlphaMode)alphaMode
                                transform:(WGIBitmapTransform*)transform
                      exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                      colorManagementMode:(WGIColorManagementMode)colorManagementMode
                                  success:(void (^)(WGISoftwareBitmap*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetSoftwareBitmapTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                    (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                                    (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                                    (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

@implementation WGIBitmapCodecInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)codecId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CodecId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSArray* /* NSString * */)fileExtensions {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileExtensions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)friendlyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FriendlyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)mimeTypes {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_MimeTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WGIBitmapDecoder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoderStatics> WGIIBitmapDecoderStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Imaging.BitmapDecoder").Get(), &inst));
    return inst;
}

+ (WFGUID*)bmpDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BmpDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)jpegDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JpegDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)pngDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PngDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)tiffDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TiffDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gifDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GifDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)jpegXRDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JpegXRDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)icoDecoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IcoDecoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (NSArray* /* WGIBitmapCodecInformation* */)getDecoderInformationEnumerator {
    ComPtr<IVectorView<ABI::Windows::Graphics::Imaging::BitmapCodecInformation*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDecoderInformationEnumerator(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIBitmapCodecInformation_create(unmarshalledReturn.Get());
}

+ (void)createAsync:(RTObject<WSSIRandomAccessStream>*)stream
            success:(void (^)(WGIBitmapDecoder*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapDecoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapDecoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapDecoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapDecoder>(result.Get()));
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

+ (void)createWithIdAsync:(WFGUID*)decoderId
                   stream:(RTObject<WSSIRandomAccessStream>*)stream
                  success:(void (^)(WGIBitmapDecoder*))success
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapDecoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapDecoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithIdAsync(decoderId.guidValue,
                                                   _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapDecoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapDecoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapDecoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapDecoder>(result.Get()));
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

- (WGIBitmapPropertiesView*)bitmapContainerProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapContainerProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapPropertiesView>(unmarshalledReturn.Get());
}

- (WGIBitmapCodecInformation*)decoderInformation {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecoderInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapCodecInformation>(unmarshalledReturn.Get());
}

- (unsigned int)frameCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrameCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPreviewAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(self);
    THROW_NS_IF_FAILED(_comInst->GetPreviewAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (void)getFrameAsync:(unsigned int)frameIndex success:(void (^)(WGIBitmapFrame*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapFrame*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(self);
    THROW_NS_IF_FAILED(_comInst->GetFrameAsync(frameIndex, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapFrame*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapFrame*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapFrame> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapFrame>(result.Get()));
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

- (void)getThumbnailAsyncWithSuccess:(void (^)(WGIImageStream*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::ImageStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::ImageStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIImageStream>(result.Get()));
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

- (WGIBitmapPropertiesView*)bitmapProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapPropertiesView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapPropertiesView>(unmarshalledReturn.Get());
}

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (double)dpiX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dpiY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)pixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)orientedPixelHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->get_OrientedPixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)getPixelDataAsyncWithSuccess:(void (^)(WGIPixelDataProvider*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(_comInst->GetPixelDataAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getPixelDataTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                           alphaMode:(WGIBitmapAlphaMode)alphaMode
                           transform:(WGIBitmapTransform*)transform
                 exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                 colorManagementMode:(WGIColorManagementMode)colorManagementMode
                             success:(void (^)(WGIPixelDataProvider*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrame>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPixelDataTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                               (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                               _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                               (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                               (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::PixelDataProvider*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::PixelDataProvider*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IPixelDataProvider> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIPixelDataProvider>(result.Get()));
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

- (void)getSoftwareBitmapAsyncWithSuccess:(void (^)(WGISoftwareBitmap*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapConvertedAsync:(WGIBitmapPixelFormat)pixelFormat
                              alphaMode:(WGIBitmapAlphaMode)alphaMode
                                success:(void (^)(WGISoftwareBitmap*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetSoftwareBitmapConvertedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                                 (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (void)getSoftwareBitmapTransformedAsync:(WGIBitmapPixelFormat)pixelFormat
                                alphaMode:(WGIBitmapAlphaMode)alphaMode
                                transform:(WGIBitmapTransform*)transform
                      exifOrientationMode:(WGIExifOrientationMode)exifOrientationMode
                      colorManagementMode:(WGIColorManagementMode)colorManagementMode
                                  success:(void (^)(WGISoftwareBitmap*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapFrameWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetSoftwareBitmapTransformedAsync((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                                    (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                                    _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapTransform>(transform).Get(),
                                                    (ABI::Windows::Graphics::Imaging::ExifOrientationMode)exifOrientationMode,
                                                    (ABI::Windows::Graphics::Imaging::ColorManagementMode)colorManagementMode,
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

@implementation WGIBitmapEncoder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoderStatics> WGIIBitmapEncoderStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Imaging.BitmapEncoder").Get(), &inst));
    return inst;
}

+ (WFGUID*)bmpEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BmpEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)jpegEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JpegEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)pngEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PngEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)tiffEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TiffEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)gifEncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GifEncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (WFGUID*)jpegXREncoderId {
    GUID unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JpegXREncoderId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (NSArray* /* WGIBitmapCodecInformation* */)getEncoderInformationEnumerator {
    ComPtr<IVectorView<ABI::Windows::Graphics::Imaging::BitmapCodecInformation*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetEncoderInformationEnumerator(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIBitmapCodecInformation_create(unmarshalledReturn.Get());
}

+ (void)createAsync:(WFGUID*)encoderId
             stream:(RTObject<WSSIRandomAccessStream>*)stream
            success:(void (^)(WGIBitmapEncoder*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAsync(encoderId.guidValue,
                                             _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapEncoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapEncoder>(result.Get()));
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

+ (void)createWithEncodingOptionsAsync:(WFGUID*)encoderId
                                stream:(RTObject<WSSIRandomAccessStream>*)stream
                       encodingOptions:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, WGIBitmapTypedValue* > */)encodingOptions
                               success:(void (^)(WGIBitmapEncoder*))success
                               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithEncodingOptionsAsync(
        encoderId.guidValue,
        _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>,
                              RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create>(encodingOptions)
                .Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapEncoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapEncoder>(result.Get()));
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

+ (void)createForTranscodingAsync:(RTObject<WSSIRandomAccessStream>*)stream
                    bitmapDecoder:(WGIBitmapDecoder*)bitmapDecoder
                          success:(void (^)(WGIBitmapEncoder*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateForTranscodingAsync(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                            _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(bitmapDecoder).Get(),
                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapEncoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapEncoder>(result.Get()));
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

+ (void)createForInPlacePropertyEncodingAsync:(WGIBitmapDecoder*)bitmapDecoder
                                      success:(void (^)(WGIBitmapEncoder*))success
                                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>> unmarshalledReturn;
    auto _comInst = WGIIBitmapEncoderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateForInPlacePropertyEncodingAsync(
        _getRtInterface<ABI::Windows::Graphics::Imaging::IBitmapDecoder>(bitmapDecoder).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::BitmapEncoder*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::BitmapEncoder*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::IBitmapEncoder> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGIBitmapEncoder>(result.Get()));
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

- (WGIBitmapCodecInformation*)encoderInformation {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncoderInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapCodecInformation>(unmarshalledReturn.Get());
}

- (WGIBitmapProperties*)bitmapProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapProperties>(unmarshalledReturn.Get());
}

- (WGIBitmapProperties*)bitmapContainerProperties {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapContainerProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapProperties>(unmarshalledReturn.Get());
}

- (BOOL)isThumbnailGenerated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsThumbnailGenerated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsThumbnailGenerated:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsThumbnailGenerated((boolean)value));
}

- (unsigned int)generatedThumbnailWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeneratedThumbnailWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGeneratedThumbnailWidth:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_GeneratedThumbnailWidth(value));
}

- (unsigned int)generatedThumbnailHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeneratedThumbnailHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGeneratedThumbnailHeight:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->put_GeneratedThumbnailHeight(value));
}

- (WGIBitmapTransform*)bitmapTransform {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapTransform> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapTransform(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapTransform>(unmarshalledReturn.Get());
}

- (void)setPixelData:(WGIBitmapPixelFormat)pixelFormat
           alphaMode:(WGIBitmapAlphaMode)alphaMode
               width:(unsigned int)width
              height:(unsigned int)height
                dpiX:(double)dpiX
                dpiY:(double)dpiY
              pixels:(NSArray* /* uint8_t */)pixels {
    UINT32 __pixels_ArrayLen = 0;
    bool __pixels_IsTemp = false;
    uint8_t* __pixels_Array = NULL;
    if (!ConvertToCArray<uint8_t>(pixels, &__pixels_ArrayLen, &__pixels_Array, &__pixels_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->SetPixelData((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)pixelFormat,
                                              (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alphaMode,
                                              width,
                                              height,
                                              dpiX,
                                              dpiY,
                                              __pixels_ArrayLen,
                                              __pixels_Array));
    if (__pixels_IsTemp)
        CoTaskMemFree(__pixels_Array);
}

- (RTObject<WFIAsyncAction>*)goToNextFrameAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->GoToNextFrameAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)goToNextFrameWithEncodingOptionsAsync:
    (id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, WGIBitmapTypedValue* > */)encodingOptions {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->GoToNextFrameWithEncodingOptionsAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
                                  IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>,
                              RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create>(encodingOptions)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)flushAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoder>(self);
    THROW_NS_IF_FAILED(_comInst->FlushAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)setSoftwareBitmap:(WGISoftwareBitmap*)bitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapEncoderWithSoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->SetSoftwareBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(bitmap).Get()));
}

@end

@implementation WGIBitmapBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)getPlaneCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->GetPlaneCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGIBitmapPlaneDescription*)getPlaneDescription:(int)index {
    ABI::Windows::Graphics::Imaging::BitmapPlaneDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::IBitmapBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->GetPlaneDescription(index, &unmarshalledReturn));
    return WGIBitmapPlaneDescription_create(unmarshalledReturn);
}

- (RTObject<WFIMemoryBufferReference>*)createReference {
    ComPtr<ABI::Windows::Foundation::IMemoryBufferReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IMemoryBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->CreateReference(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIMemoryBufferReference>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WGISoftwareBitmap

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapFactory> WGIISoftwareBitmapFactory_inst() {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Imaging.SoftwareBitmap").Get(), &inst));
    return inst;
}

+ (WGISoftwareBitmap*)make:(WGIBitmapPixelFormat)format width:(int)width height:(int)height {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format, width, height, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get()) retain];
}

+ (WGISoftwareBitmap*)makeWithAlpha:(WGIBitmapPixelFormat)format width:(int)width height:(int)height alpha:(WGIBitmapAlphaMode)alpha {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithAlpha((ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                                 width,
                                                 height,
                                                 (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
                                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapStatics> WGIISoftwareBitmapStatics_inst() {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmapStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Imaging.SoftwareBitmap").Get(), &inst));
    return inst;
}

+ (WGISoftwareBitmap*)Copy:(WGISoftwareBitmap*)source {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->Copy(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(source).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

+ (WGISoftwareBitmap*)convert:(WGISoftwareBitmap*)source format:(WGIBitmapPixelFormat)format {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Convert(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(source).Get(),
                                         (ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

+ (WGISoftwareBitmap*)convertWithAlpha:(WGISoftwareBitmap*)source format:(WGIBitmapPixelFormat)format alpha:(WGIBitmapAlphaMode)alpha {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertWithAlpha(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(source).Get(),
                                                  (ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                                  (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

+ (WGISoftwareBitmap*)createCopyFromBuffer:(RTObject<WSSIBuffer>*)source
                                    format:(WGIBitmapPixelFormat)format
                                     width:(int)width
                                    height:(int)height {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCopyFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(source).Get(),
                                                      (ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                                      width,
                                                      height,
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

+ (WGISoftwareBitmap*)createCopyWithAlphaFromBuffer:(RTObject<WSSIBuffer>*)source
                                             format:(WGIBitmapPixelFormat)format
                                              width:(int)width
                                             height:(int)height
                                              alpha:(WGIBitmapAlphaMode)alpha {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCopyWithAlphaFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(source).Get(),
                                                               (ABI::Windows::Graphics::Imaging::BitmapPixelFormat)format,
                                                               width,
                                                               height,
                                                               (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

+ (void)createCopyFromSurfaceAsync:(RTObject<WGDDIDirect3DSurface>*)surface
                           success:(void (^)(WGISoftwareBitmap*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateCopyFromSurfaceAsync(_getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>(surface).Get(),
                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

+ (void)createCopyWithAlphaFromSurfaceAsync:(RTObject<WGDDIDirect3DSurface>*)surface
                                      alpha:(WGIBitmapAlphaMode)alpha
                                    success:(void (^)(WGISoftwareBitmap*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>> unmarshalledReturn;
    auto _comInst = WGIISoftwareBitmapStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCopyWithAlphaFromSurfaceAsync(
        _getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>(surface).Get(),
        (ABI::Windows::Graphics::Imaging::BitmapAlphaMode)alpha,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Graphics::Imaging::SoftwareBitmap*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WGISoftwareBitmap>(result.Get()));
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

- (WGIBitmapPixelFormat)bitmapPixelFormat {
    ABI::Windows::Graphics::Imaging::BitmapPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapPixelFormat(&unmarshalledReturn));
    return (WGIBitmapPixelFormat)unmarshalledReturn;
}

- (WGIBitmapAlphaMode)bitmapAlphaMode {
    ABI::Windows::Graphics::Imaging::BitmapAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapAlphaMode(&unmarshalledReturn));
    return (WGIBitmapAlphaMode)unmarshalledReturn;
}

- (int)pixelWidth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)pixelHeight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDpiX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->put_DpiX(value));
}

- (double)dpiX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDpiY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->put_DpiY(value));
}

- (double)dpiY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGIBitmapBuffer*)lockBuffer:(WGIBitmapBufferAccessMode)mode {
    ComPtr<ABI::Windows::Graphics::Imaging::IBitmapBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(
        _comInst->LockBuffer((ABI::Windows::Graphics::Imaging::BitmapBufferAccessMode)mode, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIBitmapBuffer>(unmarshalledReturn.Get());
}

- (void)copyTo:(WGISoftwareBitmap*)bitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->CopyTo(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(bitmap).Get()));
}

- (void)copyFromBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->CopyFromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (void)copyToBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->CopyToBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (WGISoftwareBitmap*)getReadOnlyView {
    ComPtr<ABI::Windows::Graphics::Imaging::ISoftwareBitmap> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(self);
    THROW_NS_IF_FAILED(_comInst->GetReadOnlyView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGISoftwareBitmap>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WGIBitmapBounds {
    ABI::Windows::Graphics::Imaging::BitmapBounds structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapBounds)s {
    WGIBitmapBounds* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Imaging::BitmapBounds*)internalStruct {
    return &structVal;
}
- (unsigned int)x {
    return structVal.X;
}
- (void)setX:(unsigned int)val {
    structVal.X = val;
}
- (unsigned int)y {
    return structVal.Y;
}
- (void)setY:(unsigned int)val {
    structVal.Y = val;
}
- (unsigned int)width {
    return structVal.Width;
}
- (void)setWidth:(unsigned int)val {
    structVal.Width = val;
}
- (unsigned int)height {
    return structVal.Height;
}
- (void)setHeight:(unsigned int)val {
    structVal.Height = val;
}
@end
@implementation WGIBitmapSize {
    ABI::Windows::Graphics::Imaging::BitmapSize structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapSize)s {
    WGIBitmapSize* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Imaging::BitmapSize*)internalStruct {
    return &structVal;
}
- (unsigned int)width {
    return structVal.Width;
}
- (void)setWidth:(unsigned int)val {
    structVal.Width = val;
}
- (unsigned int)height {
    return structVal.Height;
}
- (void)setHeight:(unsigned int)val {
    structVal.Height = val;
}
@end
@implementation WGIBitmapPlaneDescription {
    ABI::Windows::Graphics::Imaging::BitmapPlaneDescription structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Imaging::BitmapPlaneDescription)s {
    WGIBitmapPlaneDescription* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Imaging::BitmapPlaneDescription*)internalStruct {
    return &structVal;
}
- (int)startIndex {
    return structVal.StartIndex;
}
- (void)setStartIndex:(int)val {
    structVal.StartIndex = val;
}
- (int)width {
    return structVal.Width;
}
- (void)setWidth:(int)val {
    structVal.Width = val;
}
- (int)height {
    return structVal.Height;
}
- (void)setHeight:(int)val {
    structVal.Height = val;
}
- (int)stride {
    return structVal.Stride;
}
- (void)setStride:(int)val {
    structVal.Stride = val;
}
@end
id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IKeyValuePair_HSTRING_Graphics_Imaging_BitmapTypedValuePtr_Ptr>,
        RTIterableObj<IKeyValuePair_HSTRING_Graphics_Imaging_BitmapTypedValuePtr_Ptr,
                      IIterable<IKeyValuePair_HSTRING_Graphics_Imaging_BitmapTypedValuePtr_Ptr>,
                      RTProxiedKeyValuePair,
                      IKeyValuePair_HSTRING_Graphics_Imaging_BitmapTypedValuePtr_Ptr,
                      RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create,
                      ConvertToIterable<RTProxiedKeyValuePair,
                                        ABI::Windows::Foundation::Internal::AggregateType<
                                            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*,
                                            IKeyValuePair<HSTRING, ABI::Windows::Graphics::Imaging::BitmapTypedValue*>*>,
                                        RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_WGIBitmapTypedValue_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter =
        std::make_unique<KeyValuePairAdapterObj<RTKeyValuePairObj<HSTRING,
                                                                  HSTRING,
                                                                  ABI::Windows::Graphics::Imaging::IBitmapTypedValue*,
                                                                  ABI::Windows::Graphics::Imaging::BitmapTypedValue*,
                                                                  NSString,
                                                                  WGIBitmapTypedValue,
                                                                  dummyObjCCreator,
                                                                  dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGIBitmapCodecInformation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::Imaging::BitmapCodecInformation*>,
                                         RTArrayObj<ABI::Windows::Graphics::Imaging::IBitmapCodecInformation*,
                                                    IVectorView<ABI::Windows::Graphics::Imaging::BitmapCodecInformation*>,
                                                    WGIBitmapCodecInformation,
                                                    ABI::Windows::Graphics::Imaging::BitmapCodecInformation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
