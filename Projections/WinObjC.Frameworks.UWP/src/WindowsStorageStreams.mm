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

// WindowsStorageStreams.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.Streams.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageStreams.h"
#include "WindowsStorageStreams_priv.h"

@implementation WSSIDataReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)unconsumedBufferLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnconsumedBufferLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSUnicodeEncoding)unicodeEncoding {
    ABI::Windows::Storage::Streams::UnicodeEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnicodeEncoding(&unmarshalledReturn));
    return (WSSUnicodeEncoding)unmarshalledReturn;
}

- (void)setUnicodeEncoding:(WSSUnicodeEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnicodeEncoding((ABI::Windows::Storage::Streams::UnicodeEncoding)value));
}

- (WSSByteOrder)byteOrder {
    ABI::Windows::Storage::Streams::ByteOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_ByteOrder(&unmarshalledReturn));
    return (WSSByteOrder)unmarshalledReturn;
}

- (void)setByteOrder:(WSSByteOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_ByteOrder((ABI::Windows::Storage::Streams::ByteOrder)value));
}

- (WSSInputStreamOptions)inputStreamOptions {
    ABI::Windows::Storage::Streams::InputStreamOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStreamOptions(&unmarshalledReturn));
    return (WSSInputStreamOptions)unmarshalledReturn;
}

- (void)setInputStreamOptions:(WSSInputStreamOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputStreamOptions((ABI::Windows::Storage::Streams::InputStreamOptions)value));
}

- (uint8_t)readByte {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadByte(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)readBytes:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = (UINT32)[value count];
    uint8_t* __value_Array = (uint8_t*)[value ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBytes(__value_ArrayLen, __value_Array));
}

- (RTObject<WSSIBuffer>*)readBuffer:(unsigned int)length {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBuffer(length, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (BOOL)readBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFGUID*)readGuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadGuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (int16_t)readInt16 {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)readInt32 {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)readInt64 {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)readUInt16 {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)readUInt32 {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)readUInt64 {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)readSingle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadSingle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)readDouble {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadDouble(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)readString:(unsigned int)codeUnitCount {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadString(codeUnitCount, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)readDateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadDateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)readTimeSpan {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadTimeSpan(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>)
- (RTObject<WSSIBuffer>*)detachBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->DetachBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)detachStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->DetachStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

@end

@implementation WSSIDataWriter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IDataWriter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)unstoredBufferLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnstoredBufferLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSUnicodeEncoding)unicodeEncoding {
    ABI::Windows::Storage::Streams::UnicodeEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnicodeEncoding(&unmarshalledReturn));
    return (WSSUnicodeEncoding)unmarshalledReturn;
}

- (void)setUnicodeEncoding:(WSSUnicodeEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnicodeEncoding((ABI::Windows::Storage::Streams::UnicodeEncoding)value));
}

- (WSSByteOrder)byteOrder {
    ABI::Windows::Storage::Streams::ByteOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ByteOrder(&unmarshalledReturn));
    return (WSSByteOrder)unmarshalledReturn;
}

- (void)setByteOrder:(WSSByteOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ByteOrder((ABI::Windows::Storage::Streams::ByteOrder)value));
}

- (void)writeByte:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteByte(value));
}

- (void)writeBytes:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBytes(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)writeBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (void)writeBufferRange:(RTObject<WSSIBuffer>*)buffer start:(unsigned int)start count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBufferRange(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), start, count));
}

- (void)writeBoolean:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBoolean((boolean)value));
}

- (void)writeGuid:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteGuid(value.guidValue));
}

- (void)writeInt16:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt16(value));
}

- (void)writeInt32:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt32(value));
}

- (void)writeInt64:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt64(value));
}

- (void)writeUInt16:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt16(value));
}

- (void)writeUInt32:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt32(value));
}

- (void)writeUInt64:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt64(value));
}

- (void)writeSingle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteSingle(value));
}

- (void)writeDouble:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteDouble(value));
}

- (void)writeDateTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteDateTime(*[value internalStruct]));
}

- (void)writeTimeSpan:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteTimeSpan(*[value internalStruct]));
}

- (unsigned int)writeString:(NSString*)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteString(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)measureString:(NSString*)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->MeasureString(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

// Failed to generate member StoreAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>)
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
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

- (RTObject<WSSIBuffer>*)detachBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->DetachBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)detachStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->DetachStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

@end

@implementation WSSIRandomAccessStreamReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReadAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>* op,
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
                            successRc(_createRtProxy<WSSIRandomAccessStreamWithContentType>(result.Get()));
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

@implementation WSSIBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)capacity {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

@end

@implementation WSSIContentTypeProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IContentTypeProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IContentTypeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSSIInputStreamReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IInputStreamReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)openSequentialReadAsyncWithSuccess:(void (^)(RTObject<WSSIInputStream>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IInputStream*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IInputStreamReference>(self);
    THROW_NS_IF_FAILED(_comInst->OpenSequentialReadAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IInputStream*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IInputStream*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Storage::Streams::IInputStream> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSSIInputStream>(result.Get()));
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

@implementation WSSIInputStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSIOutputStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSIRandomAccessStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> defaultInterface;
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

@end

@implementation WSSIRandomAccessStreamWithContentType

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

@implementation WSSDataReaderLoadOperation

// Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>
// Could not find base class Windows.Foundation.IAsyncOperation`1<UInt32> type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSDataReader

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Storage::Streams::IDataReaderFactory> WSSIDataReaderFactory_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IDataReaderFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.DataReader").Get(), &inst));
    return inst;
}

+ (WSSDataReader*)makeDataReader:(RTObject<WSSIInputStream>*)inputStream {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> unmarshalledReturn;
    auto _comInst = WSSIDataReaderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDataReader(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(inputStream).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSDataReader>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Storage::Streams::IDataReaderStatics> WSSIDataReaderStatics_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IDataReaderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.DataReader").Get(), &inst));
    return inst;
}

+ (WSSDataReader*)fromBuffer:(RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IDataReader> unmarshalledReturn;
    auto _comInst = WSSIDataReaderStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->FromBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSDataReader>(unmarshalledReturn.Get());
}

- (unsigned int)unconsumedBufferLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnconsumedBufferLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSUnicodeEncoding)unicodeEncoding {
    ABI::Windows::Storage::Streams::UnicodeEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnicodeEncoding(&unmarshalledReturn));
    return (WSSUnicodeEncoding)unmarshalledReturn;
}

- (void)setUnicodeEncoding:(WSSUnicodeEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnicodeEncoding((ABI::Windows::Storage::Streams::UnicodeEncoding)value));
}

- (WSSByteOrder)byteOrder {
    ABI::Windows::Storage::Streams::ByteOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_ByteOrder(&unmarshalledReturn));
    return (WSSByteOrder)unmarshalledReturn;
}

- (void)setByteOrder:(WSSByteOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_ByteOrder((ABI::Windows::Storage::Streams::ByteOrder)value));
}

- (WSSInputStreamOptions)inputStreamOptions {
    ABI::Windows::Storage::Streams::InputStreamOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputStreamOptions(&unmarshalledReturn));
    return (WSSInputStreamOptions)unmarshalledReturn;
}

- (void)setInputStreamOptions:(WSSInputStreamOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputStreamOptions((ABI::Windows::Storage::Streams::InputStreamOptions)value));
}

- (uint8_t)readByte {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadByte(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)readBytes:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = (UINT32)[value count];
    uint8_t* __value_Array = (uint8_t*)[value ptr];

    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBytes(__value_ArrayLen, __value_Array));
}

- (RTObject<WSSIBuffer>*)readBuffer:(unsigned int)length {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBuffer(length, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (BOOL)readBoolean {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadBoolean(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFGUID*)readGuid {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadGuid(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (int16_t)readInt16 {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)readInt32 {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)readInt64 {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned short)readUInt16 {
    unsigned short unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt16(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)readUInt32 {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt32(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)readUInt64 {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadUInt64(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)readSingle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadSingle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)readDouble {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadDouble(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)readString:(unsigned int)codeUnitCount {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadString(codeUnitCount, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFDateTime*)readDateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadDateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)readTimeSpan {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->ReadTimeSpan(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

// Failed to generate member LoadAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>)
- (RTObject<WSSIBuffer>*)detachBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->DetachBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIInputStream>*)detachStream {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataReader>(self);
    THROW_NS_IF_FAILED(_comInst->DetachStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSDataWriterStoreOperation

// Failed to get type for default interface: Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>
// Could not find base class Windows.Foundation.IAsyncOperation`1<UInt32> type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSDataWriter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IDataWriter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Streams.DataWriter").Get(), &out));
    return [_createRtProxy<WSSDataWriter>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Storage::Streams::IDataWriterFactory> WSSIDataWriterFactory_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IDataWriterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.DataWriter").Get(), &inst));
    return inst;
}

+ (WSSDataWriter*)makeDataWriter:(RTObject<WSSIOutputStream>*)outputStream {
    ComPtr<ABI::Windows::Storage::Streams::IDataWriter> unmarshalledReturn;
    auto _comInst = WSSIDataWriterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDataWriter(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(outputStream).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSDataWriter>(unmarshalledReturn.Get()) retain];
}

- (unsigned int)unstoredBufferLength {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnstoredBufferLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WSSUnicodeEncoding)unicodeEncoding {
    ABI::Windows::Storage::Streams::UnicodeEncoding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnicodeEncoding(&unmarshalledReturn));
    return (WSSUnicodeEncoding)unmarshalledReturn;
}

- (void)setUnicodeEncoding:(WSSUnicodeEncoding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnicodeEncoding((ABI::Windows::Storage::Streams::UnicodeEncoding)value));
}

- (WSSByteOrder)byteOrder {
    ABI::Windows::Storage::Streams::ByteOrder unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ByteOrder(&unmarshalledReturn));
    return (WSSByteOrder)unmarshalledReturn;
}

- (void)setByteOrder:(WSSByteOrder)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ByteOrder((ABI::Windows::Storage::Streams::ByteOrder)value));
}

- (void)writeByte:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteByte(value));
}

- (void)writeBytes:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBytes(__value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)writeBuffer:(RTObject<WSSIBuffer>*)buffer {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get()));
}

- (void)writeBufferRange:(RTObject<WSSIBuffer>*)buffer start:(unsigned int)start count:(unsigned int)count {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBufferRange(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), start, count));
}

- (void)writeBoolean:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteBoolean((boolean)value));
}

- (void)writeGuid:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteGuid(value.guidValue));
}

- (void)writeInt16:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt16(value));
}

- (void)writeInt32:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt32(value));
}

- (void)writeInt64:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteInt64(value));
}

- (void)writeUInt16:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt16(value));
}

- (void)writeUInt32:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt32(value));
}

- (void)writeUInt64:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteUInt64(value));
}

- (void)writeSingle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteSingle(value));
}

- (void)writeDouble:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteDouble(value));
}

- (void)writeDateTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteDateTime(*[value internalStruct]));
}

- (void)writeTimeSpan:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteTimeSpan(*[value internalStruct]));
}

- (unsigned int)writeString:(NSString*)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->WriteString(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)measureString:(NSString*)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->MeasureString(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

// Failed to generate member StoreAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<UInt32>)
- (void)flushAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
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

- (RTObject<WSSIBuffer>*)detachBuffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->DetachBuffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (RTObject<WSSIOutputStream>*)detachStream {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IDataWriter>(self);
    THROW_NS_IF_FAILED(_comInst->DetachStream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSRandomAccessStream

ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamStatics> WSSIRandomAccessStreamStatics_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.RandomAccessStream").Get(), &inst));
    return inst;
}

+ (void)copyAsync:(RTObject<WSSIInputStream>*)source
      destination:(RTObject<WSSIOutputStream>*)destination
          success:(void (^)(uint64_t))success
         progress:(void (^)(uint64_t))progress
          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopyAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(source).Get(),
                                           _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(destination).Get(),
                                           &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
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
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
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

+ (void)copySizeAsync:(RTObject<WSSIInputStream>*)source
          destination:(RTObject<WSSIOutputStream>*)destination
          bytesToCopy:(uint64_t)bytesToCopy
              success:(void (^)(uint64_t))success
             progress:(void (^)(uint64_t))progress
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopySizeAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(source).Get(),
                                               _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(destination).Get(),
                                               bytesToCopy,
                                               &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
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
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
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

+ (void)copyAndCloseAsync:(RTObject<WSSIInputStream>*)source
              destination:(RTObject<WSSIOutputStream>*)destination
                  success:(void (^)(uint64_t))success
                 progress:(void (^)(uint64_t))progress
                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopyAndCloseAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(source).Get(),
                                                   _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(destination).Get(),
                                                   &unmarshalledReturn));

    if (progress) {
        auto progressRc = makeBlockHolder(progress);
        auto progressHandler = ::Microsoft::WRL::Callback<
            ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                         ABI::Windows::Foundation::IAsyncOperationProgressHandler<uint64_t, uint64_t>,
                                         FtmBase>>(
            [progressRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, uint64_t status) {
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
                                     ABI::Windows::Foundation::IAsyncOperationWithProgressCompletedHandler<uint64_t, uint64_t>>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    uint64_t result;
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

@end

@implementation WSSBuffer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Storage::Streams::IBufferFactory> WSSIBufferFactory_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IBufferFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.Buffer").Get(), &inst));
    return inst;
}

+ (WSSBuffer*)make:(unsigned int)capacity {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSSIBufferFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(capacity, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSSBuffer>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Storage::Streams::IBufferStatics> WSSIBufferStatics_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IBufferStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.Buffer").Get(), &inst));
    return inst;
}

+ (WSSBuffer*)createCopyFromMemoryBuffer:(RTObject<WFIMemoryBuffer>*)input {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSSIBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCopyFromMemoryBuffer(_getRtInterface<ABI::Windows::Foundation::IMemoryBuffer>(input).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSBuffer>(unmarshalledReturn.Get());
}

+ (WFMemoryBuffer*)createMemoryBufferOverIBuffer:(RTObject<WSSIBuffer>*)input {
    ComPtr<ABI::Windows::Foundation::IMemoryBuffer> unmarshalledReturn;
    auto _comInst = WSSIBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateMemoryBufferOverIBuffer(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(input).Get(),
                                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFMemoryBuffer>(unmarshalledReturn.Get());
}

- (unsigned int)capacity {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Capacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLength:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IBuffer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Length(value));
}

@end

@implementation WSSRandomAccessStreamReference

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReferenceStatics> WSSIRandomAccessStreamReferenceStatics_inst() {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReferenceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Streams.RandomAccessStreamReference").Get(),
                                                       &inst));
    return inst;
}

+ (WSSRandomAccessStreamReference*)createFromFile:(RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamReferenceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

+ (WSSRandomAccessStreamReference*)createFromUri:(WFUri*)uri {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamReferenceStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateFromUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

+ (WSSRandomAccessStreamReference*)createFromStream:(RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = WSSIRandomAccessStreamReferenceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromStream(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(stream).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)openReadAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(self);
    THROW_NS_IF_FAILED(_comInst->OpenReadAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType*>* op,
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
                            successRc(_createRtProxy<WSSIRandomAccessStreamWithContentType>(result.Get()));
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

@implementation WSSFileRandomAccessStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> defaultInterface;
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

@end

@implementation WSSFileInputStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSFileOutputStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSRandomAccessStreamOverStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> defaultInterface;
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

@end

@implementation WSSInputStreamOverStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSOutputStreamOverStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSSInMemoryRandomAccessStream

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Storage.Streams.InMemoryRandomAccessStream").Get(), &out));
    return [_createRtProxy<WSSInMemoryRandomAccessStream>(out.Get()) retain];
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

@end

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
