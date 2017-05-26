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

// WindowsApplicationModelDataTransferShareTarget.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.DataTransfer.ShareTarget.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelDataTransferShareTarget.h"
#include "WindowsApplicationModelDataTransferShareTarget_priv.h"

@implementation WADSQuickLink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.ApplicationModel.DataTransfer.ShareTarget.QuickLink").Get(),
                                              &out));
    return [_createRtProxy<WADSQuickLink>(out.Get()) retain];
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (WSSRandomAccessStreamReference*)thumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Thumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

- (void)setThumbnail:(WSSRandomAccessStreamReference*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Thumbnail(_getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStreamReference>(value).Get()));
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setId:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->put_Id(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* NSString * */)supportedDataFormats {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedDataFormats(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (NSMutableArray* /* NSString * */)supportedFileTypes {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedFileTypes(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WADSShareOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackageView*)data {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackageView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Data(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackageView>(unmarshalledReturn.Get());
}

- (NSString*)quickLinkId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_QuickLinkId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)removeThisQuickLink {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveThisQuickLink());
}

- (void)reportStarted {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportStarted());
}

- (void)reportDataRetrieved {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportDataRetrieved());
}

- (void)reportSubmittedBackgroundTask {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportSubmittedBackgroundTask());
}

- (void)reportCompletedWithQuickLink:(WADSQuickLink*)quicklink {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedWithQuickLink(
        _getRtInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IQuickLink>(quicklink).Get()));
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportError(nsStrToHstr(value).Get()));
}

- (void)dismissUI {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2>(self);
    THROW_NS_IF_FAILED(_comInst->DismissUI());
}

@end

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
