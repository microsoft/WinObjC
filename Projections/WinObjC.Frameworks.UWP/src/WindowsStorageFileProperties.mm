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

// WindowsStorageFileProperties.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.FileProperties.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageFileProperties.h"
#include "WindowsStorageFileProperties_priv.h"

@implementation WSFIStorageItemExtraProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFGeotagHelper

ComPtr<ABI::Windows::Storage::FileProperties::IGeotagHelperStatics> WSFIGeotagHelperStatics_inst() {
    ComPtr<ABI::Windows::Storage::FileProperties::IGeotagHelperStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.FileProperties.GeotagHelper").Get(),
                                                       &inst));
    return inst;
}

+ (void)getGeotagAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(WDGGeopoint*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geopoint*>> unmarshalledReturn;
    auto _comInst = WSFIGeotagHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetGeotagAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Devices::Geolocation::Geopoint*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Devices::Geolocation::Geopoint*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Devices::Geolocation::IGeopoint> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WDGGeopoint>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)setGeotagFromGeolocatorAsync:(RTObject<WSIStorageFile>*)file geolocator:(WDGGeolocator*)geolocator {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSFIGeotagHelperStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetGeotagFromGeolocatorAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                               _getRtInterface<ABI::Windows::Devices::Geolocation::IGeolocator>(geolocator).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)setGeotagAsync:(RTObject<WSIStorageFile>*)file geopoint:(WDGGeopoint*)geopoint {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSFIGeotagHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetGeotagAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                _getRtInterface<ABI::Windows::Devices::Geolocation::IGeopoint>(geopoint).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFStorageItemThumbnail

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

- (unsigned int)originalWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IThumbnailProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)originalHeight {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IThumbnailProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginalHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)returnedSmallerCachedSize {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IThumbnailProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReturnedSmallerCachedSize(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSFThumbnailType)type {
    ABI::Windows::Storage::FileProperties::ThumbnailType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IThumbnailProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WSFThumbnailType)unmarshalledReturn;
}

@end

@implementation WSFMusicProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)album {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Album(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAlbum:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Album(nsStrToHstr(value).Get()));
}

- (NSString*)artist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Artist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setArtist:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Artist(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)genre {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Genre(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)trackNumber {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_TrackNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTrackNumber:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_TrackNumber(value));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (unsigned int)rating {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rating(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRating:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rating(value));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (unsigned int)bitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)albumArtist {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlbumArtist(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAlbumArtist:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_AlbumArtist(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)composers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Composers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)conductors {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Conductors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtitle(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)producers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Producers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)publisher {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Publisher(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPublisher:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Publisher(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)writers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Writers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)year {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Year(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setYear:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IMusicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Year(value));
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFVideoProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)rating {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rating(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRating:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rating(value));
}

- (NSMutableArray* /* NSString * */)keywords {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (id /* double */)latitude {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Latitude(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)longitude {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Longitude(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)subtitle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subtitle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSubtitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Subtitle(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)producers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Producers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)publisher {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Publisher(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPublisher:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Publisher(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)writers {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Writers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (unsigned int)year {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Year(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setYear:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Year(value));
}

- (unsigned int)bitrate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bitrate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSMutableArray* /* NSString * */)directors {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Directors(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WSFVideoOrientation)orientation {
    ABI::Windows::Storage::FileProperties::VideoOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IVideoProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WSFVideoOrientation)unmarshalledReturn;
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFImageProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IImageProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)rating {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rating(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRating:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rating(value));
}

- (NSMutableArray* /* NSString * */)keywords {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (WFDateTime*)dateTaken {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateTaken(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setDateTaken:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_DateTaken(*[value internalStruct]));
}

- (unsigned int)width {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Width(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)height {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (id /* double */)latitude {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Latitude(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (id /* double */)longitude {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Longitude(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (NSString*)cameraManufacturer {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraManufacturer(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCameraManufacturer:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_CameraManufacturer(nsStrToHstr(value).Get()));
}

- (NSString*)cameraModel {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CameraModel(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCameraModel:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_CameraModel(nsStrToHstr(value).Get()));
}

- (WSFPhotoOrientation)orientation {
    ABI::Windows::Storage::FileProperties::PhotoOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WSFPhotoOrientation)unmarshalledReturn;
}

- (NSArray* /* NSString * */)peopleNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IImageProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeopleNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFDocumentProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IDocumentProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* NSString * */)author {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)keywords {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setComment:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IDocumentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Comment(nsStrToHstr(value).Get()));
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFStorageItemContentProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)getMusicPropertiesAsyncWithSuccess:(void (^)(WSFMusicProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::MusicProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetMusicPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::MusicProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::MusicProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IMusicProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFMusicProperties>(result.Get()));
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

- (void)getVideoPropertiesAsyncWithSuccess:(void (^)(WSFVideoProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::VideoProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetVideoPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::VideoProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::VideoProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IVideoProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFVideoProperties>(result.Get()));
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

- (void)getImagePropertiesAsyncWithSuccess:(void (^)(WSFImageProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::ImageProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetImagePropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::ImageProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::ImageProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IImageProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFImageProperties>(result.Get()));
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

- (void)getDocumentPropertiesAsyncWithSuccess:(void (^)(WSFDocumentProperties*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::DocumentProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemContentProperties>(self);
    THROW_NS_IF_FAILED(_comInst->GetDocumentPropertiesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::FileProperties::DocumentProperties*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::FileProperties::DocumentProperties*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::FileProperties::IDocumentProperties> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSFDocumentProperties>(result.Get()));
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

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSFBasicProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::FileProperties::IBasicProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)size {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IBasicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)dateModified {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IBasicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateModified(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDateTime*)itemDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IBasicProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)retrievePropertiesAsync:(id<NSFastEnumeration> /* NSString * */)propertiesToRetrieve
                        success:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success
                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->RetrievePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(propertiesToRetrieve).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IMap<HSTRING, IInspectable*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IMap<HSTRING, IInspectable*>*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IMap<HSTRING, IInspectable*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSMutableDictionary_NSString_RTObject_create(result.Get()));
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

- (RTObject<WFIAsyncAction>*)savePropertiesAsync:(id<NSFastEnumeration> /* RTKeyValuePair* < NSString *, RTObject* > */)propertiesToSave {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsync(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                              IKeyValuePair<HSTRING, IInspectable*>*>>::type>*>(
            ConvertToIterable<RTProxiedKeyValuePair,
                              ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                IKeyValuePair<HSTRING, IInspectable*>*>,
                              RTProxiedKeyValuePair_NSString_RTObject_create>(propertiesToSave)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)savePropertiesAsyncOverloadDefault {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::FileProperties::IStorageItemExtraProperties>(self);
    THROW_NS_IF_FAILED(_comInst->SavePropertiesAsyncOverloadDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<IterableArrayAdapterObj<
        IIterable<IKeyValuePair_HSTRING_IInspectablePtr_Ptr>,
        RTIterableObj<IKeyValuePair_HSTRING_IInspectablePtr_Ptr,
                      IIterable<IKeyValuePair_HSTRING_IInspectablePtr_Ptr>,
                      RTProxiedKeyValuePair,
                      IKeyValuePair_HSTRING_IInspectablePtr_Ptr,
                      RTProxiedKeyValuePair_NSString_RTObject_create,
                      ConvertToIterable<RTProxiedKeyValuePair,
                                        ABI::Windows::Foundation::Internal::AggregateType<IKeyValuePair<HSTRING, IInspectable*>*,
                                                                                          IKeyValuePair<HSTRING, IInspectable*>*>,
                                        RTProxiedKeyValuePair_NSString_RTObject_create>>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedKeyValuePair_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<KeyValuePairAdapter> adapter = std::make_unique<KeyValuePairAdapterObj<
        RTKeyValuePairObj<HSTRING, HSTRING, IInspectable*, IInspectable*, NSString, RTObject, dummyObjCCreator, dummyObjCCreator>>>();
    return _createRtProxyWithAdapter<RTProxiedKeyValuePair, KeyValuePairAdapter>(val, std::move(adapter));
    ;
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val) {
    std::unique_ptr<MutableDictionaryAdapter> adapter = std::make_unique<
        MutableDictionaryAdapterObj<IMap<HSTRING, IInspectable*>,
                                    DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IInspectable*>>,
                                    RTMapObj<HSTRING,
                                             HSTRING,
                                             IInspectable*,
                                             IInspectable*,
                                             NSString,
                                             RTObject,
                                             IMap<HSTRING, IInspectable*>,
                                             dummyObjCCreator,
                                             dummyObjCCreator,
                                             dummyWRLCreator,
                                             dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}
