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

// WindowsFoundationDiagnostics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Foundation.Diagnostics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsFoundationDiagnostics.h"
#include "WindowsFoundationDiagnostics_priv.h"

@implementation WFDIErrorReportingSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setErrorOptions:(WFDErrorOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings>(self);
    THROW_NS_IF_FAILED(_comInst->SetErrorOptions((ABI::Windows::Foundation::Diagnostics::ErrorOptions)value));
}

- (WFDErrorOptions)getErrorOptions {
    ABI::Windows::Foundation::Diagnostics::ErrorOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings>(self);
    THROW_NS_IF_FAILED(_comInst->GetErrorOptions(&unmarshalledReturn));
    return (WFDErrorOptions)unmarshalledReturn;
}

@end

@implementation WFDILoggingTarget

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingTarget> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabledWithLevel((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsEnabledWithLevelAndKeywords((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, keywords, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)logEvent:(NSString*)eventName {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEvent(nsStrToHstr(eventName).Get()));
}

- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEventWithFields(nsStrToHstr(eventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get()));
}

- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndLevel(nsStrToHstr(eventName).Get(),
                                             _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndOptions(nsStrToHstr(eventName).Get(),
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                               (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get()));
}

- (WFDLoggingActivity*)startActivity:(NSString*)startEventName {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->StartActivity(nsStrToHstr(startEventName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFields(nsStrToHstr(startEventName).Get(),
                                          _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndLevel(nsStrToHstr(startEventName).Get(),
                                                  _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                  (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndOptions(nsStrToHstr(startEventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                    (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

@end

@implementation WFDILoggingChannel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDLoggingLevel)level {
    ABI::Windows::Foundation::Diagnostics::LoggingLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Level(&unmarshalledReturn));
    return (WFDLoggingLevel)unmarshalledReturn;
}

- (void)logMessage:(NSString*)eventString {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->LogMessage(nsStrToHstr(eventString).Get()));
}

- (void)logMessageWithLevel:(NSString*)eventString level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogMessageWithLevel(nsStrToHstr(eventString).Get(), (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (void)logValuePair:(NSString*)value1 value2:(int)value2 {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->LogValuePair(nsStrToHstr(value1).Get(), value2));
}

- (void)logValuePairWithLevel:(NSString*)value1 value2:(int)value2 level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogValuePairWithLevel(nsStrToHstr(value1).Get(), value2, (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (EventRegistrationToken)addLoggingEnabledEvent:(void (^)(RTObject<WFDILoggingChannel>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LoggingEnabled(Make<ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLoggingEnabledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LoggingEnabled(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFDILoggingSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)saveToFileAsync:(RTObject<WSIStorageFolder>*)folder
               fileName:(NSString*)fileName
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->SaveToFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(folder).Get(),
                                                 nsStrToHstr(fileName).Get(),
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannelWithLevel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)maxLevel));
}

- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFDIFileLoggingSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannelWithLevel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)maxLevel));
}

- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)closeAndSaveToFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->CloseAndSaveToFileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

- (EventRegistrationToken)addLogFileGeneratedEvent:(void (^)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_LogFileGenerated(
        Make<
            ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLogFileGeneratedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LogFileGenerated(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFDTracingStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDCausalityTraceLevel)traceLevel {
    ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ITracingStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TraceLevel(&unmarshalledReturn));
    return (WFDCausalityTraceLevel)unmarshalledReturn;
}

@end

@implementation WFDAsyncCausalityTracer

ComPtr<ABI::Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics> WFDIAsyncCausalityTracerStatics_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IAsyncCausalityTracerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.AsyncCausalityTracer").Get(),
                                                       &inst));
    return inst;
}

+ (void)traceOperationCreation:(WFDCausalityTraceLevel)traceLevel
                        source:(WFDCausalitySource)source
                    platformId:(WFGUID*)platformId
                   operationId:(uint64_t)operationId
                 operationName:(NSString*)operationName
                relatedContext:(uint64_t)relatedContext {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TraceOperationCreation((ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel)traceLevel,
                                                        (ABI::Windows::Foundation::Diagnostics::CausalitySource)source,
                                                        platformId.guidValue,
                                                        operationId,
                                                        nsStrToHstr(operationName).Get(),
                                                        relatedContext));
}

+ (void)traceOperationCompletion:(WFDCausalityTraceLevel)traceLevel
                          source:(WFDCausalitySource)source
                      platformId:(WFGUID*)platformId
                     operationId:(uint64_t)operationId
                          status:(WFAsyncStatus)status {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TraceOperationCompletion((ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel)traceLevel,
                                                          (ABI::Windows::Foundation::Diagnostics::CausalitySource)source,
                                                          platformId.guidValue,
                                                          operationId,
                                                          (AsyncStatus)status));
}

+ (void)traceOperationRelation:(WFDCausalityTraceLevel)traceLevel
                        source:(WFDCausalitySource)source
                    platformId:(WFGUID*)platformId
                   operationId:(uint64_t)operationId
                      relation:(WFDCausalityRelation)relation {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TraceOperationRelation((ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel)traceLevel,
                                                        (ABI::Windows::Foundation::Diagnostics::CausalitySource)source,
                                                        platformId.guidValue,
                                                        operationId,
                                                        (ABI::Windows::Foundation::Diagnostics::CausalityRelation)relation));
}

+ (void)traceSynchronousWorkStart:(WFDCausalityTraceLevel)traceLevel
                           source:(WFDCausalitySource)source
                       platformId:(WFGUID*)platformId
                      operationId:(uint64_t)operationId
                             work:(WFDCausalitySynchronousWork)work {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TraceSynchronousWorkStart((ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel)traceLevel,
                                                           (ABI::Windows::Foundation::Diagnostics::CausalitySource)source,
                                                           platformId.guidValue,
                                                           operationId,
                                                           (ABI::Windows::Foundation::Diagnostics::CausalitySynchronousWork)work));
}

+ (void)traceSynchronousWorkCompletion:(WFDCausalityTraceLevel)traceLevel
                                source:(WFDCausalitySource)source
                                  work:(WFDCausalitySynchronousWork)work {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TraceSynchronousWorkCompletion((ABI::Windows::Foundation::Diagnostics::CausalityTraceLevel)traceLevel,
                                                                (ABI::Windows::Foundation::Diagnostics::CausalitySource)source,
                                                                (ABI::Windows::Foundation::Diagnostics::CausalitySynchronousWork)work));
}

+ (EventRegistrationToken)addTracingStatusChangedEvent:(void (^)(RTObject*, WFDTracingStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_TracingStatusChanged(Make<EventHandler_Windows_Foundation_Diagnostics_TracingStatusChangedEventArgs>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeTracingStatusChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = WFDIAsyncCausalityTracerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_TracingStatusChanged(cookie));
}

@end

@implementation WFDRuntimeBrokerErrorSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Diagnostics.RuntimeBrokerErrorSettings").Get(),
                                              &out));
    return [_createRtProxy<WFDRuntimeBrokerErrorSettings>(out.Get()) retain];
}

- (void)setErrorOptions:(WFDErrorOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings>(self);
    THROW_NS_IF_FAILED(_comInst->SetErrorOptions((ABI::Windows::Foundation::Diagnostics::ErrorOptions)value));
}

- (WFDErrorOptions)getErrorOptions {
    ABI::Windows::Foundation::Diagnostics::ErrorOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorReportingSettings>(self);
    THROW_NS_IF_FAILED(_comInst->GetErrorOptions(&unmarshalledReturn));
    return (WFDErrorOptions)unmarshalledReturn;
}

@end

@implementation WFDErrorDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorDetailsStatics> WFDIErrorDetailsStatics_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorDetailsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.ErrorDetails").Get(),
                                                       &inst));
    return inst;
}

+ (void)createFromHResultAsync:(int)errorCode success:(void (^)(WFDErrorDetails*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Diagnostics::ErrorDetails*>> unmarshalledReturn;
    auto _comInst = WFDIErrorDetailsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateFromHResultAsync(errorCode, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Diagnostics::ErrorDetails*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Diagnostics::ErrorDetails*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::Diagnostics::IErrorDetails> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFDErrorDetails>(result.Get()));
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

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)longDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LongDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)helpUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IErrorDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_HelpUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

@end

@implementation WFDLoggingOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingOptionsFactory> WFDILoggingOptionsFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingOptionsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingOptions").Get(),
                                                       &inst));
    return inst;
}

+ (WFDLoggingOptions*)makeWithKeywords:(int64_t)keywords {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingOptions> unmarshalledReturn;
    auto _comInst = WFDILoggingOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithKeywords(keywords, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingOptions>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingOptions").Get(), &out));
    return [_createRtProxy<WFDLoggingOptions>(out.Get()) retain];
}

- (int64_t)keywords {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Keywords(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setKeywords:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Keywords(value));
}

- (int)tags {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tags(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTags:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tags(value));
}

- (int16_t)task {
    int16_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Task(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTask:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Task(value));
}

- (WFDLoggingOpcode)opcode {
    ABI::Windows::Foundation::Diagnostics::LoggingOpcode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opcode(&unmarshalledReturn));
    return (WFDLoggingOpcode)unmarshalledReturn;
}

- (void)setOpcode:(WFDLoggingOpcode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opcode((ABI::Windows::Foundation::Diagnostics::LoggingOpcode)value));
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setActivityId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ActivityId(value.guidValue));
}

- (WFGUID*)relatedActivityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelatedActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setRelatedActivityId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelatedActivityId(value.guidValue));
}

@end

@implementation WFDLoggingChannelOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingChannelOptions").Get(), &out));
    return [_createRtProxy<WFDLoggingChannelOptions>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptionsFactory> WFDILoggingChannelOptionsFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptionsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingChannelOptions").Get(), &inst));
    return inst;
}

+ (WFDLoggingChannelOptions*)make:(WFGUID*)group {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions> unmarshalledReturn;
    auto _comInst = WFDILoggingChannelOptionsFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(group.guidValue, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingChannelOptions>(unmarshalledReturn.Get()) retain];
}

- (WFGUID*)group {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)setGroup:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Group(value.guidValue));
}

@end

@implementation WFDLoggingFields

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingFields> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingFields").Get(), &out));
    return [_createRtProxy<WFDLoggingFields>(out.Get()) retain];
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

- (void)beginStruct:(NSString*)name {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->BeginStruct(nsStrToHstr(name).Get()));
}

- (void)beginStructWithTags:(NSString*)name tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->BeginStructWithTags(nsStrToHstr(name).Get(), tags));
}

- (void)endStruct {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->EndStruct());
}

- (void)addEmpty:(NSString*)name {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddEmpty(nsStrToHstr(name).Get()));
}

- (void)addEmptyWithFormat:(NSString*)name format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddEmptyWithFormat(nsStrToHstr(name).Get(), (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addEmptyWithFormatAndTags:(NSString*)name format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddEmptyWithFormatAndTags(nsStrToHstr(name).Get(),
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addUInt8:(NSString*)name value:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt8(nsStrToHstr(name).Get(), value));
}

- (void)addUInt8WithFormat:(NSString*)name value:(uint8_t)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddUInt8WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addUInt8WithFormatAndTags:(NSString*)name value:(uint8_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt8WithFormatAndTags(nsStrToHstr(name).Get(),
                                                           value,
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addUInt8Array:(NSString*)name value:(NSArray* /* uint8_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt8Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt8ArrayWithFormat:(NSString*)name value:(NSArray* /* uint8_t */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt8ArrayWithFormat(nsStrToHstr(name).Get(),
                                                         __value_ArrayLen,
                                                         __value_Array,
                                                         (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt8ArrayWithFormatAndTags:(NSString*)name
                                 value:(NSArray* /* uint8_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint8_t* __value_Array = NULL;
    if (!ConvertToCArray<uint8_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt8ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                __value_ArrayLen,
                                                                __value_Array,
                                                                (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt16:(NSString*)name value:(int16_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt16(nsStrToHstr(name).Get(), value));
}

- (void)addInt16WithFormat:(NSString*)name value:(int16_t)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddInt16WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addInt16WithFormatAndTags:(NSString*)name value:(int16_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt16WithFormatAndTags(nsStrToHstr(name).Get(),
                                                           value,
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addInt16Array:(NSString*)name value:(NSArray* /* int16_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int16_t* __value_Array = NULL;
    if (!ConvertToCArray<int16_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt16Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt16ArrayWithFormat:(NSString*)name value:(NSArray* /* int16_t */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int16_t* __value_Array = NULL;
    if (!ConvertToCArray<int16_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt16ArrayWithFormat(nsStrToHstr(name).Get(),
                                                         __value_ArrayLen,
                                                         __value_Array,
                                                         (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt16ArrayWithFormatAndTags:(NSString*)name
                                 value:(NSArray* /* int16_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int16_t* __value_Array = NULL;
    if (!ConvertToCArray<int16_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt16ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                __value_ArrayLen,
                                                                __value_Array,
                                                                (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt16:(NSString*)name value:(unsigned short)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt16(nsStrToHstr(name).Get(), value));
}

- (void)addUInt16WithFormat:(NSString*)name value:(unsigned short)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddUInt16WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addUInt16WithFormatAndTags:(NSString*)name value:(unsigned short)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt16WithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addUInt16Array:(NSString*)name value:(NSArray* /* unsigned short */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned short* __value_Array = NULL;
    if (!ConvertToCArray<unsigned short>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt16Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt16ArrayWithFormat:(NSString*)name value:(NSArray* /* unsigned short */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned short* __value_Array = NULL;
    if (!ConvertToCArray<unsigned short>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt16ArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt16ArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* unsigned short */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned short* __value_Array = NULL;
    if (!ConvertToCArray<unsigned short>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt16ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt32:(NSString*)name value:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt32(nsStrToHstr(name).Get(), value));
}

- (void)addInt32WithFormat:(NSString*)name value:(int)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddInt32WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addInt32WithFormatAndTags:(NSString*)name value:(int)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt32WithFormatAndTags(nsStrToHstr(name).Get(),
                                                           value,
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addInt32Array:(NSString*)name value:(NSArray* /* int */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int* __value_Array = NULL;
    if (!ConvertToCArray<int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt32Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt32ArrayWithFormat:(NSString*)name value:(NSArray* /* int */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int* __value_Array = NULL;
    if (!ConvertToCArray<int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt32ArrayWithFormat(nsStrToHstr(name).Get(),
                                                         __value_ArrayLen,
                                                         __value_Array,
                                                         (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt32ArrayWithFormatAndTags:(NSString*)name value:(NSArray* /* int */)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int* __value_Array = NULL;
    if (!ConvertToCArray<int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt32ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                __value_ArrayLen,
                                                                __value_Array,
                                                                (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt32:(NSString*)name value:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt32(nsStrToHstr(name).Get(), value));
}

- (void)addUInt32WithFormat:(NSString*)name value:(unsigned int)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddUInt32WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addUInt32WithFormatAndTags:(NSString*)name value:(unsigned int)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt32WithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addUInt32Array:(NSString*)name value:(NSArray* /* unsigned int */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned int* __value_Array = NULL;
    if (!ConvertToCArray<unsigned int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt32Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt32ArrayWithFormat:(NSString*)name value:(NSArray* /* unsigned int */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned int* __value_Array = NULL;
    if (!ConvertToCArray<unsigned int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt32ArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt32ArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* unsigned int */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    unsigned int* __value_Array = NULL;
    if (!ConvertToCArray<unsigned int>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt32ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt64:(NSString*)name value:(int64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt64(nsStrToHstr(name).Get(), value));
}

- (void)addInt64WithFormat:(NSString*)name value:(int64_t)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddInt64WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addInt64WithFormatAndTags:(NSString*)name value:(int64_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt64WithFormatAndTags(nsStrToHstr(name).Get(),
                                                           value,
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addInt64Array:(NSString*)name value:(NSArray* /* int64_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int64_t* __value_Array = NULL;
    if (!ConvertToCArray<int64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt64Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt64ArrayWithFormat:(NSString*)name value:(NSArray* /* int64_t */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int64_t* __value_Array = NULL;
    if (!ConvertToCArray<int64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt64ArrayWithFormat(nsStrToHstr(name).Get(),
                                                         __value_ArrayLen,
                                                         __value_Array,
                                                         (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addInt64ArrayWithFormatAndTags:(NSString*)name
                                 value:(NSArray* /* int64_t */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    int64_t* __value_Array = NULL;
    if (!ConvertToCArray<int64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddInt64ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                __value_ArrayLen,
                                                                __value_Array,
                                                                (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt64:(NSString*)name value:(uint64_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt64(nsStrToHstr(name).Get(), value));
}

- (void)addUInt64WithFormat:(NSString*)name value:(uint64_t)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddUInt64WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addUInt64WithFormatAndTags:(NSString*)name value:(uint64_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt64WithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addUInt64Array:(NSString*)name value:(NSArray* /* uint64_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint64_t* __value_Array = NULL;
    if (!ConvertToCArray<uint64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt64Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt64ArrayWithFormat:(NSString*)name value:(NSArray* /* uint64_t */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint64_t* __value_Array = NULL;
    if (!ConvertToCArray<uint64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt64ArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addUInt64ArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* uint64_t */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    uint64_t* __value_Array = NULL;
    if (!ConvertToCArray<uint64_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddUInt64ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSingle:(NSString*)name value:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSingle(nsStrToHstr(name).Get(), value));
}

- (void)addSingleWithFormat:(NSString*)name value:(float)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddSingleWithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addSingleWithFormatAndTags:(NSString*)name value:(float)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSingleWithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addSingleArray:(NSString*)name value:(NSArray* /* float */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    float* __value_Array = NULL;
    if (!ConvertToCArray<float>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSingleArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSingleArrayWithFormat:(NSString*)name value:(NSArray* /* float */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    float* __value_Array = NULL;
    if (!ConvertToCArray<float>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSingleArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSingleArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* float */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    float* __value_Array = NULL;
    if (!ConvertToCArray<float>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSingleArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDouble:(NSString*)name value:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDouble(nsStrToHstr(name).Get(), value));
}

- (void)addDoubleWithFormat:(NSString*)name value:(double)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddDoubleWithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addDoubleWithFormatAndTags:(NSString*)name value:(double)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDoubleWithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addDoubleArray:(NSString*)name value:(NSArray* /* double */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    double* __value_Array = NULL;
    if (!ConvertToCArray<double>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDoubleArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDoubleArrayWithFormat:(NSString*)name value:(NSArray* /* double */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    double* __value_Array = NULL;
    if (!ConvertToCArray<double>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDoubleArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDoubleArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* double */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    double* __value_Array = NULL;
    if (!ConvertToCArray<double>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDoubleArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addChar16:(NSString*)name value:(wchar_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddChar16(nsStrToHstr(name).Get(), value));
}

- (void)addChar16WithFormat:(NSString*)name value:(wchar_t)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddChar16WithFormat(nsStrToHstr(name).Get(), value, (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addChar16WithFormatAndTags:(NSString*)name value:(wchar_t)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddChar16WithFormatAndTags(nsStrToHstr(name).Get(),
                                                            value,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addChar16Array:(NSString*)name value:(NSArray* /* wchar_t */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    wchar_t* __value_Array = NULL;
    if (!ConvertToCArray<wchar_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddChar16Array(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addChar16ArrayWithFormat:(NSString*)name value:(NSArray* /* wchar_t */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    wchar_t* __value_Array = NULL;
    if (!ConvertToCArray<wchar_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddChar16ArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addChar16ArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* wchar_t */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    wchar_t* __value_Array = NULL;
    if (!ConvertToCArray<wchar_t>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddChar16ArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addBoolean:(NSString*)name value:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBoolean(nsStrToHstr(name).Get(), (boolean)value));
}

- (void)addBooleanWithFormat:(NSString*)name value:(BOOL)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBooleanWithFormat(nsStrToHstr(name).Get(),
                                                      (boolean)value,
                                                      (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addBooleanWithFormatAndTags:(NSString*)name value:(BOOL)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBooleanWithFormatAndTags(nsStrToHstr(name).Get(),
                                                             (boolean)value,
                                                             (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                             tags));
}

- (void)addBooleanArray:(NSString*)name value:(NSArray* /* BOOL */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    boolean* __value_Array = NULL;
    if (!ConvertToCArray<boolean>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBooleanArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addBooleanArrayWithFormat:(NSString*)name value:(NSArray* /* BOOL */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    boolean* __value_Array = NULL;
    if (!ConvertToCArray<boolean>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBooleanArrayWithFormat(nsStrToHstr(name).Get(),
                                                           __value_ArrayLen,
                                                           __value_Array,
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addBooleanArrayWithFormatAndTags:(NSString*)name
                                   value:(NSArray* /* BOOL */)value
                                  format:(WFDLoggingFieldFormat)format
                                    tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    boolean* __value_Array = NULL;
    if (!ConvertToCArray<boolean>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddBooleanArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                  __value_ArrayLen,
                                                                  __value_Array,
                                                                  (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                  tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addString:(NSString*)name value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddString(nsStrToHstr(name).Get(), nsStrToHstr(value).Get()));
}

- (void)addStringWithFormat:(NSString*)name value:(NSString*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddStringWithFormat(nsStrToHstr(name).Get(),
                                                     nsStrToHstr(value).Get(),
                                                     (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addStringWithFormatAndTags:(NSString*)name value:(NSString*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddStringWithFormatAndTags(nsStrToHstr(name).Get(),
                                                            nsStrToHstr(value).Get(),
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                            tags));
}

- (void)addStringArray:(NSString*)name value:(NSArray* /* NSString * */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    HSTRING* __value_Array = NULL;
    if (!ConvertToCArray<HSTRING>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddStringArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addStringArrayWithFormat:(NSString*)name value:(NSArray* /* NSString * */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    HSTRING* __value_Array = NULL;
    if (!ConvertToCArray<HSTRING>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddStringArrayWithFormat(nsStrToHstr(name).Get(),
                                                          __value_ArrayLen,
                                                          __value_Array,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addStringArrayWithFormatAndTags:(NSString*)name
                                  value:(NSArray* /* NSString * */)value
                                 format:(WFDLoggingFieldFormat)format
                                   tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    HSTRING* __value_Array = NULL;
    if (!ConvertToCArray<HSTRING>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddStringArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                 __value_ArrayLen,
                                                                 __value_Array,
                                                                 (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                 tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addGuid:(NSString*)name value:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuid(nsStrToHstr(name).Get(), value.guidValue));
}

- (void)addGuidWithFormat:(NSString*)name value:(WFGUID*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuidWithFormat(nsStrToHstr(name).Get(),
                                                   value.guidValue,
                                                   (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addGuidWithFormatAndTags:(NSString*)name value:(WFGUID*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuidWithFormatAndTags(nsStrToHstr(name).Get(),
                                                          value.guidValue,
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                          tags));
}

- (void)addGuidArray:(NSString*)name value:(NSArray* /* WFGUID* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    GUID* __value_Array = NULL;
    if (!ConvertToCArray<GUID>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuidArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addGuidArrayWithFormat:(NSString*)name value:(NSArray* /* WFGUID* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    GUID* __value_Array = NULL;
    if (!ConvertToCArray<GUID>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuidArrayWithFormat(nsStrToHstr(name).Get(),
                                                        __value_ArrayLen,
                                                        __value_Array,
                                                        (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addGuidArrayWithFormatAndTags:(NSString*)name
                                value:(NSArray* /* WFGUID* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    GUID* __value_Array = NULL;
    if (!ConvertToCArray<GUID>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddGuidArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                               __value_ArrayLen,
                                                               __value_Array,
                                                               (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                               tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDateTime:(NSString*)name value:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTime(nsStrToHstr(name).Get(), *[value internalStruct]));
}

- (void)addDateTimeWithFormat:(NSString*)name value:(WFDateTime*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTimeWithFormat(nsStrToHstr(name).Get(),
                                                       *[value internalStruct],
                                                       (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addDateTimeWithFormatAndTags:(NSString*)name value:(WFDateTime*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTimeWithFormatAndTags(nsStrToHstr(name).Get(),
                                                              *[value internalStruct],
                                                              (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                              tags));
}

- (void)addDateTimeArray:(NSString*)name value:(NSArray* /* WFDateTime* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::DateTime* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::DateTime>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTimeArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDateTimeArrayWithFormat:(NSString*)name value:(NSArray* /* WFDateTime* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::DateTime* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::DateTime>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTimeArrayWithFormat(nsStrToHstr(name).Get(),
                                                            __value_ArrayLen,
                                                            __value_Array,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addDateTimeArrayWithFormatAndTags:(NSString*)name
                                    value:(NSArray* /* WFDateTime* */)value
                                   format:(WFDLoggingFieldFormat)format
                                     tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::DateTime* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::DateTime>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddDateTimeArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                   __value_ArrayLen,
                                                                   __value_Array,
                                                                   (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                   tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addTimeSpan:(NSString*)name value:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpan(nsStrToHstr(name).Get(), *[value internalStruct]));
}

- (void)addTimeSpanWithFormat:(NSString*)name value:(WFTimeSpan*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpanWithFormat(nsStrToHstr(name).Get(),
                                                       *[value internalStruct],
                                                       (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addTimeSpanWithFormatAndTags:(NSString*)name value:(WFTimeSpan*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpanWithFormatAndTags(nsStrToHstr(name).Get(),
                                                              *[value internalStruct],
                                                              (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                              tags));
}

- (void)addTimeSpanArray:(NSString*)name value:(NSArray* /* WFTimeSpan* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::TimeSpan* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::TimeSpan>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpanArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addTimeSpanArrayWithFormat:(NSString*)name value:(NSArray* /* WFTimeSpan* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::TimeSpan* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::TimeSpan>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpanArrayWithFormat(nsStrToHstr(name).Get(),
                                                            __value_ArrayLen,
                                                            __value_Array,
                                                            (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addTimeSpanArrayWithFormatAndTags:(NSString*)name
                                    value:(NSArray* /* WFTimeSpan* */)value
                                   format:(WFDLoggingFieldFormat)format
                                     tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::TimeSpan* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::TimeSpan>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddTimeSpanArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                   __value_ArrayLen,
                                                                   __value_Array,
                                                                   (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                   tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addPoint:(NSString*)name value:(WFPoint*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPoint(nsStrToHstr(name).Get(), *[value internalStruct]));
}

- (void)addPointWithFormat:(NSString*)name value:(WFPoint*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPointWithFormat(nsStrToHstr(name).Get(),
                                                    *[value internalStruct],
                                                    (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addPointWithFormatAndTags:(NSString*)name value:(WFPoint*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPointWithFormatAndTags(nsStrToHstr(name).Get(),
                                                           *[value internalStruct],
                                                           (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                           tags));
}

- (void)addPointArray:(NSString*)name value:(NSArray* /* WFPoint* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Point* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPointArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addPointArrayWithFormat:(NSString*)name value:(NSArray* /* WFPoint* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Point* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPointArrayWithFormat(nsStrToHstr(name).Get(),
                                                         __value_ArrayLen,
                                                         __value_Array,
                                                         (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addPointArrayWithFormatAndTags:(NSString*)name
                                 value:(NSArray* /* WFPoint* */)value
                                format:(WFDLoggingFieldFormat)format
                                  tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Point* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Point>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddPointArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                                __value_ArrayLen,
                                                                __value_Array,
                                                                (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                                tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSize:(NSString*)name value:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSize(nsStrToHstr(name).Get(), *[value internalStruct]));
}

- (void)addSizeWithFormat:(NSString*)name value:(WFSize*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSizeWithFormat(nsStrToHstr(name).Get(),
                                                   *[value internalStruct],
                                                   (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addSizeWithFormatAndTags:(NSString*)name value:(WFSize*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSizeWithFormatAndTags(nsStrToHstr(name).Get(),
                                                          *[value internalStruct],
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                          tags));
}

- (void)addSizeArray:(NSString*)name value:(NSArray* /* WFSize* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Size* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Size>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSizeArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSizeArrayWithFormat:(NSString*)name value:(NSArray* /* WFSize* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Size* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Size>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSizeArrayWithFormat(nsStrToHstr(name).Get(),
                                                        __value_ArrayLen,
                                                        __value_Array,
                                                        (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addSizeArrayWithFormatAndTags:(NSString*)name
                                value:(NSArray* /* WFSize* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Size* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Size>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddSizeArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                               __value_ArrayLen,
                                                               __value_Array,
                                                               (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                               tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addRect:(NSString*)name value:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRect(nsStrToHstr(name).Get(), *[value internalStruct]));
}

- (void)addRectWithFormat:(NSString*)name value:(WFRect*)value format:(WFDLoggingFieldFormat)format {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRectWithFormat(nsStrToHstr(name).Get(),
                                                   *[value internalStruct],
                                                   (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
}

- (void)addRectWithFormatAndTags:(NSString*)name value:(WFRect*)value format:(WFDLoggingFieldFormat)format tags:(int)tags {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRectWithFormatAndTags(nsStrToHstr(name).Get(),
                                                          *[value internalStruct],
                                                          (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                          tags));
}

- (void)addRectArray:(NSString*)name value:(NSArray* /* WFRect* */)value {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Rect* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Rect>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRectArray(nsStrToHstr(name).Get(), __value_ArrayLen, __value_Array));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addRectArrayWithFormat:(NSString*)name value:(NSArray* /* WFRect* */)value format:(WFDLoggingFieldFormat)format {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Rect* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Rect>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRectArrayWithFormat(nsStrToHstr(name).Get(),
                                                        __value_ArrayLen,
                                                        __value_Array,
                                                        (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

- (void)addRectArrayWithFormatAndTags:(NSString*)name
                                value:(NSArray* /* WFRect* */)value
                               format:(WFDLoggingFieldFormat)format
                                 tags:(int)tags {
    UINT32 __value_ArrayLen = 0;
    bool __value_IsTemp = false;
    ABI::Windows::Foundation::Rect* __value_Array = NULL;
    if (!ConvertToCArray<ABI::Windows::Foundation::Rect>(value, &__value_ArrayLen, &__value_Array, &__value_IsTemp))
        assert(0);

    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(self);
    THROW_NS_IF_FAILED(_comInst->AddRectArrayWithFormatAndTags(nsStrToHstr(name).Get(),
                                                               __value_ArrayLen,
                                                               __value_Array,
                                                               (ABI::Windows::Foundation::Diagnostics::LoggingFieldFormat)format,
                                                               tags));
    if (__value_IsTemp)
        CoTaskMemFree(__value_Array);
}

@end

@implementation WFDLoggingActivity

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivityFactory> WFDILoggingActivityFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivityFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingActivity").Get(),
                                                       &inst));
    return inst;
}

+ (WFDLoggingActivity*)makeLoggingActivity:(NSString*)activityName loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = WFDILoggingActivityFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateLoggingActivity(nsStrToHstr(activityName).Get(),
                                        _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get()) retain];
}

+ (WFDLoggingActivity*)makeLoggingActivityWithLevel:(NSString*)activityName
                                     loggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel
                                              level:(WFDLoggingLevel)level {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = WFDILoggingActivityFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLoggingActivityWithLevel(
        nsStrToHstr(activityName).Get(),
        _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
        (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WFDLoggingChannel*)channel {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Channel(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingChannel>(unmarshalledReturn.Get());
}

- (void)stopActivity:(NSString*)stopEventName {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity2>(self);
    THROW_NS_IF_FAILED(_comInst->StopActivity(nsStrToHstr(stopEventName).Get()));
}

- (void)stopActivityWithFields:(NSString*)stopEventName fields:(WFDLoggingFields*)fields {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity2>(self);
    THROW_NS_IF_FAILED(
        _comInst->StopActivityWithFields(nsStrToHstr(stopEventName).Get(),
                                         _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get()));
}

- (void)stopActivityWithFieldsAndOptions:(NSString*)stopEventName fields:(WFDLoggingFields*)fields options:(WFDLoggingOptions*)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingActivity2>(self);
    THROW_NS_IF_FAILED(
        _comInst->StopActivityWithFieldsAndOptions(nsStrToHstr(stopEventName).Get(),
                                                   _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                   _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get()));
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabledWithLevel((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsEnabledWithLevelAndKeywords((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, keywords, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)logEvent:(NSString*)eventName {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEvent(nsStrToHstr(eventName).Get()));
}

- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEventWithFields(nsStrToHstr(eventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get()));
}

- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndLevel(nsStrToHstr(eventName).Get(),
                                             _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndOptions(nsStrToHstr(eventName).Get(),
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                               (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get()));
}

- (WFDLoggingActivity*)startActivity:(NSString*)startEventName {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->StartActivity(nsStrToHstr(startEventName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFields(nsStrToHstr(startEventName).Get(),
                                          _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndLevel(nsStrToHstr(startEventName).Get(),
                                                  _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                  (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndOptions(nsStrToHstr(startEventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                    (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

@end

@implementation WFDLoggingChannel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory> WFDILoggingChannelFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingChannel").Get(),
                                                       &inst));
    return inst;
}

+ (WFDLoggingChannel*)make:(NSString*)name {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> unmarshalledReturn;
    auto _comInst = WFDILoggingChannelFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingChannel>(unmarshalledReturn.Get()) retain];
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory2> WFDILoggingChannelFactory2_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannelFactory2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingChannel").Get(),
                                                       &inst));
    return inst;
}

+ (WFDLoggingChannel*)makeWithOptions:(NSString*)name options:(WFDLoggingChannelOptions*)options {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> unmarshalledReturn;
    auto _comInst = WFDILoggingChannelFactory2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithOptions(nsStrToHstr(name).Get(),
                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions>(options).Get(),
                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingChannel>(unmarshalledReturn.Get()) retain];
}

+ (WFDLoggingChannel*)makeWithOptionsAndId:(NSString*)name options:(WFDLoggingChannelOptions*)options id:(WFGUID*)id {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingChannel> unmarshalledReturn;
    auto _comInst = WFDILoggingChannelFactory2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithOptionsAndId(nsStrToHstr(name).Get(),
                                         _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannelOptions>(options).Get(),
                                         id.guidValue,
                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingChannel>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)enabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDLoggingLevel)level {
    ABI::Windows::Foundation::Diagnostics::LoggingLevel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Level(&unmarshalledReturn));
    return (WFDLoggingLevel)unmarshalledReturn;
}

- (void)logMessage:(NSString*)eventString {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->LogMessage(nsStrToHstr(eventString).Get()));
}

- (void)logMessageWithLevel:(NSString*)eventString level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogMessageWithLevel(nsStrToHstr(eventString).Get(), (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (void)logValuePair:(NSString*)value1 value2:(int)value2 {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->LogValuePair(nsStrToHstr(value1).Get(), value2));
}

- (void)logValuePairWithLevel:(NSString*)value1 value2:(int)value2 level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogValuePairWithLevel(nsStrToHstr(value1).Get(), value2, (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (EventRegistrationToken)addLoggingEnabledEvent:(void (^)(RTObject<WFDILoggingChannel>*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_LoggingEnabled(Make<ITypedEventHandler_Windows_Foundation_Diagnostics_ILoggingChannel_System_Object>(handler).Get(),
                                     &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLoggingEnabledEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LoggingEnabled(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WFGUID*)id {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevel:(WFDLoggingLevel)level {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->IsEnabledWithLevel((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnabledWithLevelAndKeywords:(WFDLoggingLevel)level keywords:(int64_t)keywords {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsEnabledWithLevelAndKeywords((ABI::Windows::Foundation::Diagnostics::LoggingLevel)level, keywords, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)logEvent:(NSString*)eventName {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEvent(nsStrToHstr(eventName).Get()));
}

- (void)logEventWithFields:(NSString*)eventName fields:(WFDLoggingFields*)fields {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->LogEventWithFields(nsStrToHstr(eventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get()));
}

- (void)logEventWithFieldsAndLevel:(NSString*)eventName fields:(WFDLoggingFields*)fields level:(WFDLoggingLevel)level {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndLevel(nsStrToHstr(eventName).Get(),
                                             _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level));
}

- (void)logEventWithFieldsAndOptions:(NSString*)eventName
                              fields:(WFDLoggingFields*)fields
                               level:(WFDLoggingLevel)level
                             options:(WFDLoggingOptions*)options {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LogEventWithFieldsAndOptions(nsStrToHstr(eventName).Get(),
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                               (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                               _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get()));
}

- (WFDLoggingActivity*)startActivity:(NSString*)startEventName {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(_comInst->StartActivity(nsStrToHstr(startEventName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFields:(NSString*)startEventName fields:(WFDLoggingFields*)fields {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFields(nsStrToHstr(startEventName).Get(),
                                          _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndLevel:(NSString*)startEventName
                                                fields:(WFDLoggingFields*)fields
                                                 level:(WFDLoggingLevel)level {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndLevel(nsStrToHstr(startEventName).Get(),
                                                  _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                  (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

- (WFDLoggingActivity*)startActivityWithFieldsAndOptions:(NSString*)startEventName
                                                  fields:(WFDLoggingFields*)fields
                                                   level:(WFDLoggingLevel)level
                                                 options:(WFDLoggingOptions*)options {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingActivity> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartActivityWithFieldsAndOptions(nsStrToHstr(startEventName).Get(),
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingFields>(fields).Get(),
                                                    (ABI::Windows::Foundation::Diagnostics::LoggingLevel)level,
                                                    _getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingOptions>(options).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDLoggingActivity>(unmarshalledReturn.Get());
}

@end

@implementation WFDLoggingSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSessionFactory> WFDILoggingSessionFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSessionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.LoggingSession").Get(),
                                                       &inst));
    return inst;
}

+ (WFDLoggingSession*)make:(NSString*)name {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILoggingSession> unmarshalledReturn;
    auto _comInst = WFDILoggingSessionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDLoggingSession>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)saveToFileAsync:(RTObject<WSIStorageFolder>*)folder
               fileName:(NSString*)fileName
                success:(void (^)(WSStorageFile*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->SaveToFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(folder).Get(),
                                                 nsStrToHstr(fileName).Get(),
                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannelWithLevel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)maxLevel));
}

- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WFDLogFileGeneratedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::ILogFileGeneratedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

@end

@implementation WFDFileLoggingSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSessionFactory> WFDIFileLoggingSessionFactory_inst() {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSessionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Foundation.Diagnostics.FileLoggingSession").Get(),
                                                       &inst));
    return inst;
}

+ (WFDFileLoggingSession*)make:(NSString*)name {
    ComPtr<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession> unmarshalledReturn;
    auto _comInst = WFDIFileLoggingSessionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WFDFileLoggingSession>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)addLoggingChannelWithLevel:(RTObject<WFDILoggingChannel>*)loggingChannel maxLevel:(WFDLoggingLevel)maxLevel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddLoggingChannelWithLevel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get(),
                                             (ABI::Windows::Foundation::Diagnostics::LoggingLevel)maxLevel));
}

- (void)removeLoggingChannel:(RTObject<WFDILoggingChannel>*)loggingChannel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->RemoveLoggingChannel(_getRtInterface<ABI::Windows::Foundation::Diagnostics::ILoggingChannel>(loggingChannel).Get()));
}

- (void)closeAndSaveToFileAsyncWithSuccess:(void (^)(WSStorageFile*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->CloseAndSaveToFileAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::StorageFile*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::StorageFile*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::IStorageFile> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSStorageFile>(result.Get()));
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

- (EventRegistrationToken)addLogFileGeneratedEvent:(void (^)(RTObject<WFDIFileLoggingSession>*, WFDLogFileGeneratedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_LogFileGenerated(
        Make<
            ITypedEventHandler_Windows_Foundation_Diagnostics_IFileLoggingSession_Windows_Foundation_Diagnostics_LogFileGeneratedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLogFileGeneratedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::Diagnostics::IFileLoggingSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LogFileGenerated(token));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

id RTProxiedNSArray_C_Boolean_create(UINT32 size, boolean* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<boolean, RTCArrayObj<boolean, BOOL, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Char16_create(UINT32 size, wchar_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<wchar_t, RTCArrayObj<wchar_t, wchar_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Double_create(UINT32 size, double* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<double, RTCArrayObj<double, double, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int16_create(UINT32 size, int16_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<int16_t, RTCArrayObj<int16_t, int16_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<CArrayAdapterObj<int, RTCArrayObj<int, int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int64_create(UINT32 size, int64_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<int64_t, RTCArrayObj<int64_t, int64_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<HSTRING, RTCArrayObj<HSTRING, NSString, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Single_create(UINT32 size, float* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<float, RTCArrayObj<float, float, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt16_create(UINT32 size, unsigned short* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<unsigned short, RTCArrayObj<unsigned short, unsigned short, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt32_create(UINT32 size, unsigned int* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<unsigned int, RTCArrayObj<unsigned int, unsigned int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt64_create(UINT32 size, uint64_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint64_t, RTCArrayObj<uint64_t, uint64_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<uint8_t, RTCArrayObj<uint8_t, uint8_t, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFDateTime_create(UINT32 size, ABI::Windows::Foundation::DateTime* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::DateTime,
                                          RTCArrayObj<ABI::Windows::Foundation::DateTime, WFDateTime, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFGUID_create(UINT32 size, GUID* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<GUID, RTCArrayObj<GUID, WFGUID, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Point, RTCArrayObj<ABI::Windows::Foundation::Point, WFPoint, dummyObjCCreator>>>(size,
                                                                                                                                    val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFRect_create(UINT32 size, ABI::Windows::Foundation::Rect* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Rect, RTCArrayObj<ABI::Windows::Foundation::Rect, WFRect, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFSize_create(UINT32 size, ABI::Windows::Foundation::Size* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::Foundation::Size, RTCArrayObj<ABI::Windows::Foundation::Size, WFSize, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WFTimeSpan_create(UINT32 size, ABI::Windows::Foundation::TimeSpan* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::Foundation::TimeSpan,
                                          RTCArrayObj<ABI::Windows::Foundation::TimeSpan, WFTimeSpan, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
