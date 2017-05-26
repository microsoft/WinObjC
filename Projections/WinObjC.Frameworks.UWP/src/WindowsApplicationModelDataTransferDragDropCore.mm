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

// WindowsApplicationModelDataTransferDragDropCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.DataTransfer.DragDrop.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelDataTransferDragDropCore.h"
#include "WindowsApplicationModelDataTransferDragDropCore_priv.h"

@implementation WADDCICoreDropOperationTarget

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)enterAsync:(WADDCCoreDragInfo*)dragInfo
    dragUIOverride:(WADDCCoreDragUIOverride*)dragUIOverride
           success:(void (^)(WADDataPackageOperation))success
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>(self);
    THROW_NS_IF_FAILED(_comInst->EnterAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(dragInfo).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(dragUIOverride).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WADDataPackageOperation)result);
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

- (void)overAsync:(WADDCCoreDragInfo*)dragInfo
    dragUIOverride:(WADDCCoreDragUIOverride*)dragUIOverride
           success:(void (^)(WADDataPackageOperation))success
           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>(self);
    THROW_NS_IF_FAILED(_comInst->OverAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(dragInfo).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(dragUIOverride).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WADDataPackageOperation)result);
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

- (RTObject<WFIAsyncAction>*)leaveAsync:(WADDCCoreDragInfo*)dragInfo {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->LeaveAsync(_getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(dragInfo).Get(),
                             unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)dropAsync:(WADDCCoreDragInfo*)dragInfo success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>(self);
    THROW_NS_IF_FAILED(
        _comInst->DropAsync(_getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(dragInfo).Get(),
                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WADDataPackageOperation)result);
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

@implementation WADDCCoreDragInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackageView*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackageView>(unmarshalledReturn.Get());
}

- (WADDDragDropModifiers)modifiers {
    ABI::Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Modifiers(&unmarshalledReturn));
    return (WADDDragDropModifiers)unmarshalledReturn;
}

- (WFPoint*)position {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WADDataPackageOperation)allowedOperations {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragInfo2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedOperations(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

@end

@implementation WADDCCoreDragUIOverride

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetContentFromSoftwareBitmap(_getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get()));
}

- (void)setContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->SetContentFromSoftwareBitmapWithAnchorPoint(
        _getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get(), *[anchorPoint internalStruct]));
}

- (BOOL)isContentVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsContentVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsContentVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsContentVisible((boolean)value));
}

- (NSString*)caption {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_Caption(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCaption:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_Caption(nsStrToHstr(value).Get()));
}

- (BOOL)isCaptionVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCaptionVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCaptionVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCaptionVisible((boolean)value));
}

- (BOOL)isGlyphVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGlyphVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGlyphVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGlyphVisible((boolean)value));
}

- (void)clear {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragUIOverride>(self);
    THROW_NS_IF_FAILED(_comInst->Clear());
}

@end

@implementation WADDCCoreDragDropManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManagerStatics> WADDCICoreDragDropManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragDropManager").Get(), &inst));
    return inst;
}

+ (WADDCCoreDragDropManager*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager> unmarshalledReturn;
    auto _comInst = WADDCICoreDragDropManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDCCoreDragDropManager>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addTargetRequestedEvent:(void (^)(WADDCCoreDragDropManager*,
                                                            WADDCCoreDropOperationTargetRequestedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_TargetRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDragDropManager_Windows_ApplicationModel_DataTransfer_DragDrop_Core_CoreDropOperationTargetRequestedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTargetRequestedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TargetRequested(value));
}

- (BOOL)areConcurrentOperationsEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreConcurrentOperationsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAreConcurrentOperationsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragDropManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_AreConcurrentOperationsEnabled((boolean)value));
}

@end

@implementation WADDCCoreDropOperationTargetRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setTarget:(RTObject<WADDCICoreDropOperationTarget>*)target {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTargetRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetTarget(
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDropOperationTarget>(target).Get()));
}

@end

@implementation WADDCCoreDragOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.DragDrop.Core.CoreDragOperation").Get(), &out));
    return [_createRtProxy<WADDCCoreDragOperation>(out.Get()) retain];
}

- (WADDataPackage*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackage>(unmarshalledReturn.Get());
}

- (void)setPointerId:(unsigned int)pointerId {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->SetPointerId(pointerId));
}

- (void)setDragUIContentFromSoftwareBitmap:(WGISoftwareBitmap*)softwareBitmap {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->SetDragUIContentFromSoftwareBitmap(
        _getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get()));
}

- (void)setDragUIContentFromSoftwareBitmapWithAnchorPoint:(WGISoftwareBitmap*)softwareBitmap anchorPoint:(WFPoint*)anchorPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->SetDragUIContentFromSoftwareBitmapWithAnchorPoint(
        _getRtInterface<ABI::Windows::Graphics::Imaging::ISoftwareBitmap>(softwareBitmap).Get(), *[anchorPoint internalStruct]));
}

- (WADDCCoreDragUIContentMode)dragUIContentMode {
    ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragUIContentMode(&unmarshalledReturn));
    return (WADDCCoreDragUIContentMode)unmarshalledReturn;
}

- (void)setDragUIContentMode:(WADDCCoreDragUIContentMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_DragUIContentMode((ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::CoreDragUIContentMode)value));
}

- (void)startAsyncWithSuccess:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WADDataPackageOperation)result);
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

- (WADDataPackageOperation)allowedOperations {
    ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedOperations(&unmarshalledReturn));
    return (WADDataPackageOperation)unmarshalledReturn;
}

- (void)setAllowedOperations:(WADDataPackageOperation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::DragDrop::Core::ICoreDragOperation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowedOperations((ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation)value));
}

@end
