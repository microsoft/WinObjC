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

// WindowsApplicationModelExtendedExecutionForeground.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.ExtendedExecution.Foreground.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelExtendedExecutionForeground.h"
#include "WindowsApplicationModelExtendedExecutionForeground_priv.h"

@implementation WAEFExtendedExecutionForegroundRevokedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAEFExtendedExecutionForegroundRevokedReason)reason {
    ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundRevokedReason unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundRevokedEventArgs>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WAEFExtendedExecutionForegroundRevokedReason)unmarshalledReturn;
}

@end

@implementation WAEFExtendedExecutionForegroundSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.ExtendedExecution.Foreground.ExtendedExecutionForegroundSession").Get(), &out));
    return [_createRtProxy<WAEFExtendedExecutionForegroundSession>(out.Get()) retain];
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDescription:(NSString*)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_Description(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addRevokedEvent:(void (^)(RTObject*, WAEFExtendedExecutionForegroundRevokedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_Revoked(
        Make<
            ITypedEventHandler_System_Object_Windows_ApplicationModel_ExtendedExecution_Foreground_ExtendedExecutionForegroundRevokedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRevokedEvent:(EventRegistrationToken)token {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Revoked(token));
}

- (void)requestExtensionAsyncWithSuccess:(void (^)(WAEFExtendedExecutionForegroundResult))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>>
        unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->RequestExtensionAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WAEFExtendedExecutionForegroundResult)result);
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

- (WAEFExtendedExecutionForegroundReason)reason {
    ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WAEFExtendedExecutionForegroundReason)unmarshalledReturn;
}

- (void)setReason:(WAEFExtendedExecutionForegroundReason)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::IExtendedExecutionForegroundSession>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Reason((ABI::Windows::ApplicationModel::ExtendedExecution::Foreground::ExtendedExecutionForegroundReason)value));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end
