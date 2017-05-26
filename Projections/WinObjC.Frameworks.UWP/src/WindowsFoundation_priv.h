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

// WindowsFoundation_priv.h
// Forward decls for private object generation
#pragma once

ComPtr<ABI::Windows::Foundation::IPropertyValueStatics> WFIPropertyValueStatics_inst();
static ComPtr<ABI::Windows::Foundation::IDeferralFactory> WFIDeferralFactory_inst();
static ComPtr<ABI::Windows::Foundation::IWwwFormUrlDecoderRuntimeClassFactory> WFIWwwFormUrlDecoderRuntimeClassFactory_inst();
static ComPtr<ABI::Windows::Foundation::IUriRuntimeClassFactory> WFIUriRuntimeClassFactory_inst();
ComPtr<ABI::Windows::Foundation::IUriEscapeStatics> WFIUriEscapeStatics_inst();
static ComPtr<ABI::Windows::Foundation::IMemoryBufferFactory> WFIMemoryBufferFactory_inst();
@interface WFPoint (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Point)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Point*)internalStruct;
@end
inline WFPoint* WFPoint_create(ABI::Windows::Foundation::Point val) {
    return [WFPoint createWith:val];
}
@interface WFSize (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Size)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Size*)internalStruct;
@end
inline WFSize* WFSize_create(ABI::Windows::Foundation::Size val) {
    return [WFSize createWith:val];
}
@interface WFRect (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::Rect)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::Rect*)internalStruct;
@end
inline WFRect* WFRect_create(ABI::Windows::Foundation::Rect val) {
    return [WFRect createWith:val];
}
@interface WFDateTime (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::DateTime)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::DateTime*)internalStruct;
@end
inline WFDateTime* WFDateTime_create(ABI::Windows::Foundation::DateTime val) {
    return [WFDateTime createWith:val];
}
@interface WFTimeSpan (Internal)
+ (instancetype)createWith:(ABI::Windows::Foundation::TimeSpan)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Foundation::TimeSpan*)internalStruct;
@end
inline WFTimeSpan* WFTimeSpan_create(ABI::Windows::Foundation::TimeSpan val) {
    return [WFTimeSpan createWith:val];
}

id RTProxiedNSArray_C_Boolean_create(UINT32 size, boolean* val);
id RTProxiedNSArray_C_Char16_create(UINT32 size, wchar_t* val);
id RTProxiedNSArray_C_Double_create(UINT32 size, double* val);
id RTProxiedNSArray_C_Int16_create(UINT32 size, int16_t* val);
id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val);
id RTProxiedNSArray_C_Int64_create(UINT32 size, int64_t* val);
id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
id RTProxiedNSArray_C_RTObject_create(UINT32 size, IInspectable** val);
id RTProxiedNSArray_C_Single_create(UINT32 size, float* val);
id RTProxiedNSArray_C_UInt16_create(UINT32 size, unsigned short* val);
id RTProxiedNSArray_C_UInt32_create(UINT32 size, unsigned int* val);
id RTProxiedNSArray_C_UInt64_create(UINT32 size, uint64_t* val);
id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_C_WFDateTime_create(UINT32 size, ABI::Windows::Foundation::DateTime* val);
id RTProxiedNSArray_C_WFGUID_create(UINT32 size, GUID* val);
id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val);
id RTProxiedNSArray_C_WFRect_create(UINT32 size, ABI::Windows::Foundation::Rect* val);
id RTProxiedNSArray_C_WFSize_create(UINT32 size, ABI::Windows::Foundation::Size* val);
id RTProxiedNSArray_C_WFTimeSpan_create(UINT32 size, ABI::Windows::Foundation::TimeSpan* val);

@class RTProxiedNSArray_C_Boolean, RTProxiedNSArray_C_Char16, RTProxiedNSArray_C_Double, RTProxiedNSArray_C_Int16, RTProxiedNSArray_C_Int32;
@class RTProxiedNSArray_C_Int64, RTProxiedNSArray_C_NSString, RTProxiedNSArray_C_RTObject, RTProxiedNSArray_C_Single,
    RTProxiedNSArray_C_UInt16;
@class RTProxiedNSArray_C_UInt32, RTProxiedNSArray_C_UInt64, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_C_WFDateTime,
    RTProxiedNSArray_C_WFGUID;
@class RTProxiedNSArray_C_WFPoint, RTProxiedNSArray_C_WFRect, RTProxiedNSArray_C_WFSize, RTProxiedNSArray_C_WFTimeSpan;

#ifndef __ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object__DEFINED
class ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Foundation::IMemoryBufferReference*, IInspectable*>> {
    void (^_delegate)(RTObject<WFIMemoryBufferReference>*, RTObject*);

public:
    ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object(void (^del)(RTObject<WFIMemoryBufferReference>*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Foundation_IMemoryBufferReference_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::IMemoryBufferReference* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFIMemoryBufferReference>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WFAsyncActionCompletedHandler_shim__DEFINED
#define __WFAsyncActionCompletedHandler_shim__DEFINED
class WFAsyncActionCompletedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IAsyncActionCompletedHandler> {
    void (^_delegate)(RTObject<WFIAsyncAction>*, WFAsyncStatus);

public:
    WFAsyncActionCompletedHandler_shim(void (^del)(RTObject<WFIAsyncAction>*, WFAsyncStatus)) : _delegate([del copy]) {
    }
    ~WFAsyncActionCompletedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::IAsyncAction* arg0, AsyncStatus arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFIAsyncAction>(arg0), (unsigned)arg1);
            return 0;
        };
    }
};
#endif

#ifndef __WFDeferralCompletedHandler_shim__DEFINED
#define __WFDeferralCompletedHandler_shim__DEFINED
class WFDeferralCompletedHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IDeferralCompletedHandler> {
    void (^_delegate)();

public:
    WFDeferralCompletedHandler_shim(void (^del)()) : _delegate([del copy]) {
    }
    ~WFDeferralCompletedHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke() override {
        @autoreleasepool {
            _delegate();
            return 0;
        };
    }
};
#endif
