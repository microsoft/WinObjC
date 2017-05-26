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

// WindowsUIXamlData.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Data.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIXamlData_priv.h"

@implementation WUXDIItemsRangeInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IItemsRangeInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)rangesChanged:(WUXDItemIndexRange*)visibleRange trackedItems:(NSArray* /* WUXDItemIndexRange* */)trackedItems {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IItemsRangeInfo>(self);
    THROW_NS_IF_FAILED(_comInst->RangesChanged(
        _getRtInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(visibleRange).Get(),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Data::ItemIndexRange*,
                                                              ABI::Windows::UI::Xaml::Data::IItemIndexRange*>>::type>*>(
            ConvertToVectorView<WUXDItemIndexRange,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::UI::Xaml::Data::ItemIndexRange*,
                                                                                  ABI::Windows::UI::Xaml::Data::IItemIndexRange*>>(
                trackedItems)
                .Get())));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WUXDISelectionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ISelectionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)selectRange:(WUXDItemIndexRange*)itemIndexRange {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISelectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->SelectRange(_getRtInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(itemIndexRange).Get()));
}

- (void)deselectRange:(WUXDItemIndexRange*)itemIndexRange {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISelectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->DeselectRange(_getRtInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(itemIndexRange).Get()));
}

- (BOOL)isSelected:(int)index {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISelectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->IsSelected(index, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUXDItemIndexRange* */)getSelectedRanges {
    ComPtr<IVectorView<ABI::Windows::UI::Xaml::Data::ItemIndexRange*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISelectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelectedRanges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUXDItemIndexRange_create(unmarshalledReturn.Get());
}

@end

@implementation WUXDICustomProperty

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICustomProperty> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXITypeName*)type {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject*)getValue:(RTObject*)target {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->GetValue([target comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setValue:(RTObject*)target value:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue([target comObj].Get(), [value comObj].Get()));
}

- (RTObject*)getIndexedValue:(RTObject*)target index:(RTObject*)index {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->GetIndexedValue([target comObj].Get(), [index comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setIndexedValue:(RTObject*)target value:(RTObject*)value index:(RTObject*)index {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->SetIndexedValue([target comObj].Get(), [value comObj].Get(), [index comObj].Get()));
}

- (BOOL)canWrite {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanWrite(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canRead {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomProperty>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRead(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXDICustomPropertyProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXDICustomProperty>*)getCustomProperty:(NSString*)name {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICustomProperty> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetCustomProperty(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDICustomProperty>(unmarshalledReturn.Get());
}

- (RTObject<WUXDICustomProperty>*)getIndexedProperty:(NSString*)name type:(WUXITypeName*)type {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICustomProperty> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetIndexedProperty(nsStrToHstr(name).Get(), *[type internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDICustomProperty>(unmarshalledReturn.Get());
}

- (NSString*)getStringRepresentation {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetStringRepresentation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXITypeName*)type {
    ABI::Windows::UI::Xaml::Interop::TypeName unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return WUXITypeName_create(unmarshalledReturn);
}

@end

@implementation WUXDINotifyPropertyChanged

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::INotifyPropertyChanged> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addPropertyChangedEvent:(WUXDPropertyChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::INotifyPropertyChanged>(self);
    THROW_NS_IF_FAILED(_comInst->add_PropertyChanged(Make<WUXDPropertyChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePropertyChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::INotifyPropertyChanged>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PropertyChanged(token));
}

@end

@implementation WUXDISupportIncrementalLoading

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ISupportIncrementalLoading> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)loadMoreItemsAsync:(unsigned int)count success:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISupportIncrementalLoading>(self);
    THROW_NS_IF_FAILED(_comInst->LoadMoreItemsAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(WUXDLoadMoreItemsResult_create(result));
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

- (BOOL)hasMoreItems {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ISupportIncrementalLoading>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreItems(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXDIValueConverter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IValueConverter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->Convert([value comObj].Get(),
                                         *[targetType internalStruct],
                                         [parameter comObj].Get(),
                                         nsStrToHstr(language).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->ConvertBack([value comObj].Get(),
                                             *[targetType internalStruct],
                                             [parameter comObj].Get(),
                                             nsStrToHstr(language).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXDICollectionView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)currentItem {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentItem(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (int)currentPosition {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isCurrentAfterLast {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCurrentAfterLast(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isCurrentBeforeFirst {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCurrentBeforeFirst(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSMutableArray<RTObservableCollection>* /* RTObject* */)collectionGroups {
    ComPtr<IObservableVector<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_CollectionGroups(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_RTObject_create(unmarshalledReturn.Get());
}

- (BOOL)hasMoreItems {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreItems(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addCurrentChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentChanged(token));
}

- (EventRegistrationToken)addCurrentChangingEvent:(WUXDCurrentChangingEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->add_CurrentChanging(Make<WUXDCurrentChangingEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCurrentChangingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CurrentChanging(token));
}

- (BOOL)moveCurrentTo:(RTObject*)item {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentTo([item comObj].Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveCurrentToPosition:(int)index {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentToPosition(index, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveCurrentToFirst {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentToFirst(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveCurrentToLast {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentToLast(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveCurrentToNext {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentToNext(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)moveCurrentToPrevious {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->MoveCurrentToPrevious(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)loadMoreItemsAsync:(unsigned int)count success:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionView>(self);
    THROW_NS_IF_FAILED(_comInst->LoadMoreItemsAsync(count, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(WUXDLoadMoreItemsResult_create(result));
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

@implementation WUXDICollectionViewFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXDICollectionView>*)createView {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDICollectionView>(unmarshalledReturn.Get());
}

@end

@implementation WUXDICollectionViewGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)group {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Group(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (NSMutableArray<RTObservableCollection>* /* RTObject* */)groupItems {
    ComPtr<IObservableVector<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_GroupItems(unmarshalledReturn.GetAddressOf()));
    return RTProxiedObservableNSMutableArray_RTObject_create(unmarshalledReturn.Get());
}

@end

@implementation WUXDCurrentChangingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgsFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.CurrentChangingEventArgs").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXDCurrentChangingEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (BOOL)cancel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cancel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCancel:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Cancel((boolean)value));
}

- (BOOL)isCancelable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCancelable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXDPropertyChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXDPropertyChangedEventArgs*)makeInstance:(NSString*)name {
    ComPtr<ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.PropertyChangedEventArgs").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstance(nsStrToHstr(name).Get(), outer.Get(), &inner, &instance));
    WUXDPropertyChangedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (NSString*)propertyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PropertyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXDBindingExpressionBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingExpressionBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXDBindingOperations

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingOperations> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Data::IBindingOperationsStatics> WUXDIBindingOperationsStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingOperationsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.BindingOperations").Get(), &inst));
    return inst;
}

+ (void)setBinding:(WXDependencyObject*)target dp:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding {
    auto _comInst = WUXDIBindingOperationsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetBinding(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(target).Get(),
                                            _getRtInterface<ABI::Windows::UI::Xaml::IDependencyProperty>(dp).Get(),
                                            _getRtInterface<ABI::Windows::UI::Xaml::Data::IBindingBase>(binding).Get()));
}

@end

@implementation WUXDBindingBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingBaseFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.BindingBase").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingBase> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXDBindingBase* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

@end

@implementation WUXDBindingExpression

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingExpression> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)dataItem {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBindingExpression>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataItem(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (WUXDBinding*)parentBinding {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBinding> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBindingExpression>(self);
    THROW_NS_IF_FAILED(_comInst->get_ParentBinding(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDBinding>(unmarshalledReturn.Get());
}

- (void)updateSource {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBindingExpression>(self);
    THROW_NS_IF_FAILED(_comInst->UpdateSource());
}

@end

@implementation WUXDRelativeSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IRelativeSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Data::IRelativeSourceFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.RelativeSource").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::IRelativeSource> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXDRelativeSource* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WUXDRelativeSourceMode)mode {
    ABI::Windows::UI::Xaml::Data::RelativeSourceMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IRelativeSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WUXDRelativeSourceMode)unmarshalledReturn;
}

- (void)setMode:(WUXDRelativeSourceMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IRelativeSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::UI::Xaml::Data::RelativeSourceMode)value));
}

@end

@implementation WUXDBinding

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBinding> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Data::IBindingFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.Binding").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::IBinding> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXDBinding* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (WXPropertyPath*)path {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Path(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyPath>(unmarshalledReturn.Get());
}

- (void)setPath:(WXPropertyPath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Path(_getRtInterface<ABI::Windows::UI::Xaml::IPropertyPath>(value).Get()));
}

- (WUXDBindingMode)mode {
    ABI::Windows::UI::Xaml::Data::BindingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WUXDBindingMode)unmarshalledReturn;
}

- (void)setMode:(WUXDBindingMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::UI::Xaml::Data::BindingMode)value));
}

- (RTObject*)source {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setSource:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source([value comObj].Get()));
}

- (WUXDRelativeSource*)relativeSource {
    ComPtr<ABI::Windows::UI::Xaml::Data::IRelativeSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_RelativeSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDRelativeSource>(unmarshalledReturn.Get());
}

- (void)setRelativeSource:(WUXDRelativeSource*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_RelativeSource(_getRtInterface<ABI::Windows::UI::Xaml::Data::IRelativeSource>(value).Get()));
}

- (NSString*)elementName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setElementName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_ElementName(nsStrToHstr(value).Get()));
}

- (RTObject<WUXDIValueConverter>*)converter {
    ComPtr<ABI::Windows::UI::Xaml::Data::IValueConverter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_Converter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDIValueConverter>(unmarshalledReturn.Get());
}

- (void)setConverter:(RTObject<WUXDIValueConverter>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_Converter(_getRtInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(value).Get()));
}

- (RTObject*)converterParameter {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConverterParameter(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setConverterParameter:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConverterParameter([value comObj].Get()));
}

- (NSString*)converterLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConverterLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setConverterLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConverterLanguage(nsStrToHstr(value).Get()));
}

- (RTObject*)fallbackValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FallbackValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setFallbackValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->put_FallbackValue([value comObj].Get()));
}

- (RTObject*)targetNullValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetNullValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setTargetNullValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetNullValue([value comObj].Get()));
}

- (WUXDUpdateSourceTrigger)updateSourceTrigger {
    ABI::Windows::UI::Xaml::Data::UpdateSourceTrigger unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UpdateSourceTrigger(&unmarshalledReturn));
    return (WUXDUpdateSourceTrigger)unmarshalledReturn;
}

- (void)setUpdateSourceTrigger:(WUXDUpdateSourceTrigger)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IBinding2>(self);
    THROW_NS_IF_FAILED(_comInst->put_UpdateSourceTrigger((ABI::Windows::UI::Xaml::Data::UpdateSourceTrigger)value));
}

@end

@implementation WUXDItemIndexRange

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::IItemIndexRange> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXDItemIndexRange*)makeInstance:(int)firstIndex length:(unsigned int)length {
    ComPtr<ABI::Windows::UI::Xaml::Data::IItemIndexRangeFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.ItemIndexRange").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Data::IItemIndexRange> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstance(firstIndex, length, outer.Get(), &inner, &instance));
    WUXDItemIndexRange* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (int)firstIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)length {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_Length(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IItemIndexRange>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXDCollectionViewSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Data.CollectionViewSource").Get(), &out));
    return [_createRtProxy<WUXDCollectionViewSource>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewSourceStatics> WUXDICollectionViewSourceStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionViewSourceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Data.CollectionViewSource").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)sourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDICollectionViewSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)viewProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDICollectionViewSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ViewProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isSourceGroupedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDICollectionViewSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSourceGroupedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemsPathProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDICollectionViewSourceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemsPathProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (RTObject*)source {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setSource:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source([value comObj].Get()));
}

- (RTObject<WUXDICollectionView>*)view {
    ComPtr<ABI::Windows::UI::Xaml::Data::ICollectionView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_View(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDICollectionView>(unmarshalledReturn.Get());
}

- (BOOL)isSourceGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSourceGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSourceGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSourceGrouped((boolean)value));
}

- (WXPropertyPath*)itemsPath {
    ComPtr<ABI::Windows::UI::Xaml::IPropertyPath> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemsPath(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXPropertyPath>(unmarshalledReturn.Get());
}

- (void)setItemsPath:(WXPropertyPath*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::ICollectionViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemsPath(_getRtInterface<ABI::Windows::UI::Xaml::IPropertyPath>(value).Get()));
}

@end

@implementation WUXDLoadMoreItemsResult {
    ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult)s {
    WUXDLoadMoreItemsResult* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult*)internalStruct {
    return &structVal;
}
- (unsigned int)count {
    return structVal.Count;
}
- (void)setCount:(unsigned int)val {
    structVal.Count = val;
}
@end
