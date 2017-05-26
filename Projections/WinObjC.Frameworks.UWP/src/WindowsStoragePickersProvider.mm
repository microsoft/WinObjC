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

// WindowsStoragePickersProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Storage.Pickers.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsStoragePickersProvider.h"
#include "WindowsStoragePickersProvider_priv.h"

@implementation WSPPFileRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IFileRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSPPFileOpenPickerUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPAddFileResult)addFile:(NSString*)id file:(RTObject<WSIStorageFile>*)file {
    ABI::Windows::Storage::Pickers::Provider::AddFileResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddFile(nsStrToHstr(id).Get(), _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));
    return (WSPPAddFileResult)unmarshalledReturn;
}

- (void)removeFile:(NSString*)id {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFile(nsStrToHstr(id).Get()));
}

- (BOOL)containsFile:(NSString*)id {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->ContainsFile(nsStrToHstr(id).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canAddFile:(RTObject<WSIStorageFile>*)file {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->CanAddFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* NSString * */)allowedFileTypes {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedFileTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WSPPFileSelectionMode)selectionMode {
    ABI::Windows::Storage::Pickers::Provider::FileSelectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionMode(&unmarshalledReturn));
    return (WSPPFileSelectionMode)unmarshalledReturn;
}

- (NSString*)settingsIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_SettingsIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (EventRegistrationToken)addFileRemovedEvent:(void (^)(WSPPFileOpenPickerUI*, WSPPFileRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_FileRemoved(
        Make<ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_FileRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFileRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FileRemoved(token));
}

- (EventRegistrationToken)addClosingEvent:(void (^)(WSPPFileOpenPickerUI*, WSPPPickerClosingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closing(
        Make<ITypedEventHandler_Windows_Storage_Pickers_Provider_FileOpenPickerUI_Windows_Storage_Pickers_Provider_PickerClosingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileOpenPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closing(token));
}

@end

@implementation WSPPPickerClosingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IPickerClosingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPPickerClosingOperation*)closingOperation {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IPickerClosingOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IPickerClosingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClosingOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPPickerClosingOperation>(unmarshalledReturn.Get());
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IPickerClosingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSPPPickerClosingOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IPickerClosingOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPPickerClosingDeferral*)getDeferral {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IPickerClosingDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IPickerClosingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPPickerClosingDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IPickerClosingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WSPPPickerClosingDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IPickerClosingDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IPickerClosingDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WSPPFileSavePickerUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSArray* /* NSString * */)allowedFileTypes {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowedFileTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)settingsIdentifier {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_SettingsIdentifier(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)fileName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSPPSetFileNameResult)trySetFileName:(NSString*)value {
    ABI::Windows::Storage::Pickers::Provider::SetFileNameResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->TrySetFileName(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return (WSPPSetFileNameResult)unmarshalledReturn;
}

- (EventRegistrationToken)addFileNameChangedEvent:(void (^)(WSPPFileSavePickerUI*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_FileNameChanged(
        Make<ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFileNameChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FileNameChanged(token));
}

- (EventRegistrationToken)addTargetFileRequestedEvent:(void (^)(WSPPFileSavePickerUI*, WSPPTargetFileRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_TargetFileRequested(
        Make<
            ITypedEventHandler_Windows_Storage_Pickers_Provider_FileSavePickerUI_Windows_Storage_Pickers_Provider_TargetFileRequestedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTargetFileRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::IFileSavePickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TargetFileRequested(token));
}

@end

@implementation WSPPTargetFileRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSPPTargetFileRequest*)request {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPTargetFileRequest>(unmarshalledReturn.Get());
}

@end

@implementation WSPPTargetFileRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSIStorageFile>*)targetFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

- (void)setTargetFile:(RTObject<WSIStorageFile>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetFile(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

- (WSPPTargetFileRequestDeferral*)getDeferral {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSPPTargetFileRequestDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WSPPTargetFileRequestDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Storage::Pickers::Provider::ITargetFileRequestDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
