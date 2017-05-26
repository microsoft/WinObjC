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

// WindowsWebHttpDiagnostics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Web.Http.Diagnostics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsWebHttpDiagnostics.h"
#include "WindowsWebHttpDiagnostics_priv.h"

@implementation WWHDHttpDiagnosticSourceLocation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)sourceUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (uint64_t)lineNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)columnNumber {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColumnNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WWHDHttpDiagnosticProviderRequestSentEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WWHHttpRequestMessage*)message {
    ComPtr<ABI::Windows::Web::Http::IHttpRequestMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpRequestMessage>(unmarshalledReturn.Get());
}

- (unsigned int)processId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProcessId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)threadId {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThreadId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WWHDHttpDiagnosticRequestInitiator)initiator {
    ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Initiator(&unmarshalledReturn));
    return (WWHDHttpDiagnosticRequestInitiator)unmarshalledReturn;
}

- (NSArray* /* WWHDHttpDiagnosticSourceLocation* */)sourceLocations {
    ComPtr<IVectorView<ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WWHDHttpDiagnosticSourceLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WWHDHttpDiagnosticProviderResponseReceivedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)timestamp {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamp(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WWHHttpResponseMessage*)message {
    ComPtr<ABI::Windows::Web::Http::IHttpResponseMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHHttpResponseMessage>(unmarshalledReturn.Get());
}

@end

@implementation WWHDHttpDiagnosticProviderRequestResponseTimestamps

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFDateTime* */)cacheCheckedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheCheckedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)connectionInitiatedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionInitiatedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)nameResolvedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_NameResolvedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)sslNegotiatedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_SslNegotiatedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)connectionCompletedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConnectionCompletedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)requestSentTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestSentTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)requestCompletedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestCompletedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)responseReceivedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseReceivedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

- (id /* WFDateTime* */)responseCompletedTimestamp {
    ComPtr<IReference<ABI::Windows::Foundation::DateTime>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResponseCompletedTimestamp(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFDateTime, ABI::Windows::Foundation::DateTime>::convert(unmarshalledReturn.Get());
}

@end

@implementation WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WWHDHttpDiagnosticProviderRequestResponseTimestamps*)timestamps {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timestamps(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHDHttpDiagnosticProviderRequestResponseTimestamps>(unmarshalledReturn.Get());
}

- (WFUri*)requestedUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestedUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (unsigned int)processId {
    unsigned int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProcessId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)threadId {
    unsigned int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThreadId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WWHDHttpDiagnosticRequestInitiator)initiator {
    ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Initiator(&unmarshalledReturn));
    return (WWHDHttpDiagnosticRequestInitiator)unmarshalledReturn;
}

- (NSArray* /* WWHDHttpDiagnosticSourceLocation* */)sourceLocations {
    ComPtr<IVectorView<ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceLocations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WWHDHttpDiagnosticSourceLocation_create(unmarshalledReturn.Get());
}

@end

@implementation WWHDHttpDiagnosticProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> WWHDIHttpDiagnosticProviderStatics_inst() {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Web.Http.Diagnostics.HttpDiagnosticProvider").Get(),
                                                       &inst));
    return inst;
}

+ (WWHDHttpDiagnosticProvider*)createFromProcessDiagnosticInfo:(WSDProcessDiagnosticInfo*)processDiagnosticInfo {
    ComPtr<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider> unmarshalledReturn;
    auto _comInst = WWHDIHttpDiagnosticProviderStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromProcessDiagnosticInfo(
        _getRtInterface<ABI::Windows::System::Diagnostics::IProcessDiagnosticInfo>(processDiagnosticInfo).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WWHDHttpDiagnosticProvider>(unmarshalledReturn.Get());
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addRequestSentEvent:(void (^)(WWHDHttpDiagnosticProvider*,
                                                        WWHDHttpDiagnosticProviderRequestSentEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->add_RequestSent(
        Make<
            ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestSentEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRequestSentEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RequestSent(token));
}

- (EventRegistrationToken)addResponseReceivedEvent:(void (^)(WWHDHttpDiagnosticProvider*,
                                                             WWHDHttpDiagnosticProviderResponseReceivedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->add_ResponseReceived(
        Make<
            ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderResponseReceivedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResponseReceivedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ResponseReceived(token));
}

- (EventRegistrationToken)addRequestResponseCompletedEvent:(void (^)(WWHDHttpDiagnosticProvider*,
                                                                     WWHDHttpDiagnosticProviderRequestResponseCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->add_RequestResponseCompleted(
        Make<
            ITypedEventHandler_Windows_Web_Http_Diagnostics_HttpDiagnosticProvider_Windows_Web_Http_Diagnostics_HttpDiagnosticProviderRequestResponseCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRequestResponseCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticProvider>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RequestResponseCompleted(token));
}

@end

id RTProxiedNSArray_WWHDHttpDiagnosticSourceLocation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation*>,
                                         RTArrayObj<ABI::Windows::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation*,
                                                    IVectorView<ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation*>,
                                                    WWHDHttpDiagnosticSourceLocation,
                                                    ABI::Windows::Web::Http::Diagnostics::HttpDiagnosticSourceLocation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
