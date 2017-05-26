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

// WindowsSecurityCryptography.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Cryptography.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityCryptography.h"
#include "WindowsSecurityCryptography_priv.h"

@implementation WSCCryptographicBuffer

ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> WSCICryptographicBufferStatics_inst() {
    ComPtr<ABI::Windows::Security::Cryptography::ICryptographicBufferStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Security.Cryptography.CryptographicBuffer").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)compare:(RTObject<WSSIBuffer>*)object1 object2:(RTObject<WSSIBuffer>*)object2 {
    boolean unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Compare(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(object1).Get(),
                                         _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(object2).Get(),
                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (RTObject<WSSIBuffer>*)generateRandom:(unsigned int)length {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GenerateRandom(length, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (unsigned int)generateRandomNumber {
    unsigned int unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GenerateRandomNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (RTObject<WSSIBuffer>*)createFromByteArray:(NSArray* /* uint8_t */)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromByteArray(__value_ArrayLen, __value_Array, unmarshalledReturn.GetAddressOf()));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (void)copyToByteArray:(RTObject<WSSIBuffer>*)buffer value:(NSArray* /* uint8_t */*)value {
    UINT32 __value_ArrayLen = 0;
    uint8_t* __value_Array = NULL;

    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopyToByteArray(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                 &__value_ArrayLen,
                                                 &__value_Array));
    *value = RTProxiedNSArray_C_UInt8_create(__value_ArrayLen, __value_Array);
}

+ (RTObject<WSSIBuffer>*)decodeFromHexString:(NSString*)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DecodeFromHexString(nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (NSString*)encodeToHexString:(RTObject<WSSIBuffer>*)buffer {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->EncodeToHexString(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (RTObject<WSSIBuffer>*)decodeFromBase64String:(NSString*)value {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DecodeFromBase64String(nsStrToHstr(value).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (NSString*)encodeToBase64String:(RTObject<WSSIBuffer>*)buffer {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->EncodeToBase64String(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (RTObject<WSSIBuffer>*)convertStringToBinary:(NSString*)value encoding:(WSCBinaryStringEncoding)encoding {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertStringToBinary(nsStrToHstr(value).Get(),
                                                       (ABI::Windows::Security::Cryptography::BinaryStringEncoding)encoding,
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

+ (NSString*)convertBinaryToString:(WSCBinaryStringEncoding)encoding buffer:(RTObject<WSSIBuffer>*)buffer {
    HSTRING unmarshalledReturn;
    auto _comInst = WSCICryptographicBufferStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ConvertBinaryToString((ABI::Windows::Security::Cryptography::BinaryStringEncoding)encoding,
                                                       _getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(buffer).Get(),
                                                       &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
