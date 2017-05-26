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

// WindowsNetworkingSockets_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSecurityCryptographyCertificates_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsWeb_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelBackground_priv.h"
#include "WindowsNetworkingConnectivity_priv.h"
static ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityContextFactory> WNSISocketActivityContextFactory_inst();
ComPtr<ABI::Windows::Networking::Sockets::IDatagramSocketStatics> WNSIDatagramSocketStatics_inst();
ComPtr<ABI::Windows::Networking::Sockets::IStreamSocketStatics> WNSIStreamSocketStatics_inst();
ComPtr<ABI::Windows::Networking::Sockets::ISocketActivityInformationStatics> WNSISocketActivityInformationStatics_inst();
ComPtr<ABI::Windows::Networking::Sockets::ISocketErrorStatics> WNSISocketErrorStatics_inst();
ComPtr<ABI::Windows::Networking::Sockets::IWebSocketErrorStatics> WNSIWebSocketErrorStatics_inst();
static ComPtr<ABI::Windows::Networking::Sockets::IControlChannelTriggerFactory> WNSIControlChannelTriggerFactory_inst();
@interface WNSRoundTripTimeStatistics (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::Sockets::RoundTripTimeStatistics)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::Sockets::RoundTripTimeStatistics*)internalStruct;
@end
inline WNSRoundTripTimeStatistics* WNSRoundTripTimeStatistics_create(ABI::Windows::Networking::Sockets::RoundTripTimeStatistics val) {
    return [WNSRoundTripTimeStatistics createWith:val];
}
@interface WNSBandwidthStatistics (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::Sockets::BandwidthStatistics)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::Sockets::BandwidthStatistics*)internalStruct;
@end
inline WNSBandwidthStatistics* WNSBandwidthStatistics_create(ABI::Windows::Networking::Sockets::BandwidthStatistics val) {
    return [WNSBandwidthStatistics createWith:val];
}

id RTProxiedNSArray_WNEndpointPair_create(IInspectable* val);
id RTProxiedNSArray_WSCCCertificate_create(IInspectable* val);
id RTProxiedNSArray_WSCCChainValidationResult_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WNSSocketActivityInformation_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WSCCChainValidationResult_create(IInspectable* val);

@class RTProxiedNSArray_WNEndpointPair, RTProxiedNSArray_WSCCCertificate, RTProxiedNSArray_WSCCChainValidationResult,
    RTProxiedNSDictionary_NSString_WNSSocketActivityInformation;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WSCCChainValidationResult;

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Sockets::DatagramSocket*,
                                                       ABI::Windows::Networking::Sockets::DatagramSocketMessageReceivedEventArgs*>> {
    void (^_delegate)(WNSDatagramSocket*, WNSDatagramSocketMessageReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs(
        void (^del)(WNSDatagramSocket*, WNSDatagramSocketMessageReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_DatagramSocket_Windows_Networking_Sockets_DatagramSocketMessageReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Sockets::IDatagramSocket* arg0,
                                             ABI::Windows::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSDatagramSocket>(arg0), _createRtProxy<WNSDatagramSocketMessageReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs__DEFINED
class ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Sockets::IWebSocket*,
                                                                       ABI::Windows::Networking::Sockets::WebSocketClosedEventArgs*>> {
    void (^_delegate)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs(
        void (^del)(RTObject<WNSIWebSocket>*, WNSWebSocketClosedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_IWebSocket_Windows_Networking_Sockets_WebSocketClosedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Sockets::IWebSocket* arg0,
                                             ABI::Windows::Networking::Sockets::IWebSocketClosedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSIWebSocket>(arg0), _createRtProxy<WNSWebSocketClosedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs__DEFINED
class ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Networking::Sockets::MessageWebSocket*,
                                                       ABI::Windows::Networking::Sockets::MessageWebSocketMessageReceivedEventArgs*>> {
    void (^_delegate)(WNSMessageWebSocket*, WNSMessageWebSocketMessageReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs(
        void (^del)(WNSMessageWebSocket*, WNSMessageWebSocketMessageReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_MessageWebSocketMessageReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Networking::Sockets::IMessageWebSocket* arg0,
                                             ABI::Windows::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSMessageWebSocket>(arg0), _createRtProxy<WNSMessageWebSocketMessageReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Networking::Sockets::MessageWebSocket*,
                              ABI::Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs*>> {
    void (^_delegate)(WNSMessageWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs(
        void (^del)(WNSMessageWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_MessageWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::Sockets::IMessageWebSocket* arg0,
           ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSMessageWebSocket>(arg0),
                      _createRtProxy<WNSWebSocketServerCustomValidationRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Networking::Sockets::StreamSocketListener*,
                              ABI::Windows::Networking::Sockets::StreamSocketListenerConnectionReceivedEventArgs*>> {
    void (^_delegate)(WNSStreamSocketListener*, WNSStreamSocketListenerConnectionReceivedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs(
        void (^del)(WNSStreamSocketListener*, WNSStreamSocketListenerConnectionReceivedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_StreamSocketListener_Windows_Networking_Sockets_StreamSocketListenerConnectionReceivedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::Sockets::IStreamSocketListener* arg0,
           ABI::Windows::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSStreamSocketListener>(arg0),
                      _createRtProxy<WNSStreamSocketListenerConnectionReceivedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Networking::Sockets::StreamWebSocket*,
                              ABI::Windows::Networking::Sockets::WebSocketServerCustomValidationRequestedEventArgs*>> {
    void (^_delegate)(WNSStreamWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs(
        void (^del)(WNSStreamWebSocket*, WNSWebSocketServerCustomValidationRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Networking_Sockets_StreamWebSocket_Windows_Networking_Sockets_WebSocketServerCustomValidationRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Networking::Sockets::IStreamWebSocket* arg0,
           ABI::Windows::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WNSStreamWebSocket>(arg0), _createRtProxy<WNSWebSocketServerCustomValidationRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
