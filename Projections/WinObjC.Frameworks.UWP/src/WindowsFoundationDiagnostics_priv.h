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

// WindowsFoundationDiagnostics_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics> WFDIAsyncCausalityTracerStatics_inst();
ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorDetailsStatics> WFDIErrorDetailsStatics_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingOptionsFactory> WFDILoggingOptionsFactory_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptionsFactory> WFDILoggingChannelOptionsFactory_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivityFactory> WFDILoggingActivityFactory_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory> WFDILoggingChannelFactory_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory2> WFDILoggingChannelFactory2_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSessionFactory> WFDILoggingSessionFactory_inst();
static ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSessionFactory> WFDIFileLoggingSessionFactory_inst();

id RTProxiedNSArray_C_Boolean_create(UINT32 size, boolean* val);
id RTProxiedNSArray_C_Char16_create(UINT32 size, wchar_t* val);
id RTProxiedNSArray_C_Double_create(UINT32 size, double* val);
id RTProxiedNSArray_C_Int16_create(UINT32 size, int16_t* val);
id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val);
id RTProxiedNSArray_C_Int64_create(UINT32 size, int64_t* val);
id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
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
@class RTProxiedNSArray_C_Int64, RTProxiedNSArray_C_NSString, RTProxiedNSArray_C_Single, RTProxiedNSArray_C_UInt16,
    RTProxiedNSArray_C_UInt32;
@class RTProxiedNSArray_C_UInt64, RTProxiedNSArray_C_UInt8, RTProxiedNSArray_C_WFDateTime, RTProxiedNSArray_C_WFGUID,
    RTProxiedNSArray_C_WFPoint;
@class RTProxiedNSArray_C_WFRect, RTProxiedNSArray_C_WFSize, RTProxiedNSArray_C_WFTimeSpan;

#ifndef __EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs__DEFINED
#define __EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs__DEFINED
class EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Foundation::Diagnostics::TracingStatusChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WFDTracingStatusChangedEventArgs*);

public:
    EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs(void (^del)(RTObject*, WFDTracingStatusChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WFDTracingStatusChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs__DEFINED
class ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession*,
                                                                       ABI::Windows::Foundation::Diagnostics::LogFileGeneratedEventArgs*>> {
    void (^_delegate)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*);

public:
    ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs(
        void (^del)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::Diagnostics::IFileLoggingSession* arg0,
                                             ABI::Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFDIFileLoggingSession>(arg0), _createRtProxy<WFDLogFileGeneratedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object__DEFINED
#define __ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object__DEFINED
class ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Foundation::Diagnostics::ILoggingChannel*, IInspectable*>> {
    void (^_delegate)(RTObject<WFDILoggingChannel>*, RTObject*);

public:
    ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object(void (^del)(RTObject<WFDILoggingChannel>*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Foundation::Diagnostics::ILoggingChannel* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WFDILoggingChannel>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
