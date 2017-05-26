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

// WindowsStorageProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStorageProvider.h"
#include "WindowsStorageProvider_priv.h"

@implementation WSPCachedFileUpdaterUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (WSPCachedFileTarget)updateTarget {
    ABI::Windows::Storage::Provider::CachedFileTarget unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateTarget(&unmarshalledReturn));
    return (WSPCachedFileTarget)unmarshalledReturn;
}

- (EventRegistrationToken)addFileUpdateRequestedEvent:(void (^)(WSPCachedFileUpdaterUI*, WSPFileUpdateRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_FileUpdateRequested(
        Make<ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_Windows_Storage_Provider_FileUpdateRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFileUpdateRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FileUpdateRequested(token));
}

- (EventRegistrationToken)addUIRequestedEvent:(void (^)(WSPCachedFileUpdaterUI*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_UIRequested(Make<ITypedEventHandler_Windows_Storage_Provider_CachedFileUpdaterUI_System_Object>(handler).Get(),
                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUIRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UIRequested(token));
}

- (WSPUIStatus)uIStatus {
    ABI::Windows::Storage::Provider::UIStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_UIStatus(&unmarshalledReturn));
    return (WSPUIStatus)unmarshalledReturn;
}

- (WSPFileUpdateRequest*)updateRequest {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPFileUpdateRequest>(unmarshalledReturn.Get());
}

- (WSPFileUpdateRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::ICachedFileUpdaterUI2>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPFileUpdateRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WSPFileUpdateRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPFileUpdateRequest*)request {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPFileUpdateRequest>(unmarshalledReturn.Get());
}

@end

@implementation WSPFileUpdateRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)contentId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (WSPFileUpdateStatus)status {
    ABI::Windows::Storage::Provider::FileUpdateStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSPFileUpdateStatus)unmarshalledReturn;
}

- (void)setStatus:(WSPFileUpdateStatus)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Status((ABI::Windows::Storage::Provider::FileUpdateStatus)value));
}

- (WSPFileUpdateRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPFileUpdateRequestDeferral>(unmarshalledReturn.Get());
}

- (void)updateLocalFile:(RTObject<WSIStorageFile>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateLocalFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

- (NSString*)userInputNeededMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserInputNeededMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUserInputNeededMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequest2>(self);
    THROW_NS_IF_FAILED(_comInst->put_UserInputNeededMessage(nsStrToHstr(value).Get()));
}

@end

@implementation WSPFileUpdateRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Provider::IFileUpdateRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WSPCachedFileUpdater

ComPtr<ABI::Windows::Storage::Provider::ICachedFileUpdaterStatics> WSPICachedFileUpdaterStatics_inst() {
    ComPtr<ABI::Windows::Storage::Provider::ICachedFileUpdaterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Storage.Provider.CachedFileUpdater").Get(), &inst));
    return inst;
}

+ (void)setUpdateInformation:(RTObject<WSIStorageFile>*)file
                   contentId:(NSString*)contentId
                    readMode:(WSPReadActivationMode)readMode
                   writeMode:(WSPWriteActivationMode)writeMode
                     options:(WSPCachedFileOptions)options {
    auto _comInst = WSPICachedFileUpdaterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetUpdateInformation(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                      nsStrToHstr(contentId).Get(),
                                                      (ABI::Windows::Storage::Provider::ReadActivationMode)readMode,
                                                      (ABI::Windows::Storage::Provider::WriteActivationMode)writeMode,
                                                      (ABI::Windows::Storage::Provider::CachedFileOptions)options));
}

@end
