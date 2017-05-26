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

// WindowsApplicationModelExtendedExecution.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.ExtendedExecution.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelExtendedExecution.h"
#include "WindowsApplicationModelExtendedExecution_priv.h"

@implementation WAEExtendedExecutionRevokedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEExtendedExecutionRevokedReason)reason {
    ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WAEExtendedExecutionRevokedReason)unmarshalledReturn;
}

@end

@implementation WAEExtendedExecutionSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionSession").Get(), &out));
    return [_createRtProxy<WAEExtendedExecutionSession>(out.Get()) retain];
}

- (WAEExtendedExecutionReason)reason {
    ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WAEExtendedExecutionReason)unmarshalledReturn;
}

- (void)setReason:(WAEExtendedExecutionReason)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_Reason((ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionReason)value));
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (unsigned int)percentProgress {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_PercentProgress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPercentProgress:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_PercentProgress(value));
}

- (EventRegistrationToken)addRevokedEvent:(void (^)(RTObject*, WAEExtendedExecutionRevokedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_Revoked(
        Make<ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_ExtendedExecutionRevokedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRevokedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Revoked(token));
}

- (void)requestExtensionAsyncWithSuccess:(void (^)(WAEExtendedExecutionResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>(self);
    THROW_NS_IF_FAILED(_comInst->RequestExtensionAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::ApplicationModel::ExtendedExecution::ExtendedExecutionResult result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WAEExtendedExecutionResult)result);
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
