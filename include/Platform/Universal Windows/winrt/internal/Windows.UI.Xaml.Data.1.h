// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.Data.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Data {

struct LoadMoreItemsResult
{
    uint32_t Count;
};

}

namespace Windows::UI::Xaml::Data {

using LoadMoreItemsResult = ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult;

}

namespace ABI::Windows::UI::Xaml::Data {

struct __declspec(uuid("f3888db8-139f-4dce-8dc9-f7f1444d1185")) __declspec(novtable) CurrentChangingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Data::ICurrentChangingEventArgs * e) = 0;
};

struct __declspec(uuid("3f7a0c6b-d00f-4730-8c1d-48e16c46f9ca")) __declspec(novtable) IBinding : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Path(Windows::UI::Xaml::IPropertyPath ** value) = 0;
    virtual HRESULT __stdcall put_Path(Windows::UI::Xaml::IPropertyPath * value) = 0;
    virtual HRESULT __stdcall get_Mode(winrt::Windows::UI::Xaml::Data::BindingMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::UI::Xaml::Data::BindingMode value) = 0;
    virtual HRESULT __stdcall get_Source(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_RelativeSource(Windows::UI::Xaml::Data::IRelativeSource ** value) = 0;
    virtual HRESULT __stdcall put_RelativeSource(Windows::UI::Xaml::Data::IRelativeSource * value) = 0;
    virtual HRESULT __stdcall get_ElementName(hstring * value) = 0;
    virtual HRESULT __stdcall put_ElementName(hstring value) = 0;
    virtual HRESULT __stdcall get_Converter(Windows::UI::Xaml::Data::IValueConverter ** value) = 0;
    virtual HRESULT __stdcall put_Converter(Windows::UI::Xaml::Data::IValueConverter * value) = 0;
    virtual HRESULT __stdcall get_ConverterParameter(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_ConverterParameter(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_ConverterLanguage(hstring * value) = 0;
    virtual HRESULT __stdcall put_ConverterLanguage(hstring value) = 0;
};

struct __declspec(uuid("34f96fcb-0406-48b3-9e82-f333ec4c6910")) __declspec(novtable) IBinding2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FallbackValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_FallbackValue(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_TargetNullValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_TargetNullValue(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_UpdateSourceTrigger(winrt::Windows::UI::Xaml::Data::UpdateSourceTrigger * value) = 0;
    virtual HRESULT __stdcall put_UpdateSourceTrigger(winrt::Windows::UI::Xaml::Data::UpdateSourceTrigger value) = 0;
};

struct __declspec(uuid("1589a2ab-3d15-49bc-a447-8a5448e58870")) __declspec(novtable) IBindingBase : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("22dafc3a-7701-4666-a1ba-9859bdcfec34")) __declspec(novtable) IBindingBaseFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::IBindingBase ** instance) = 0;
};

struct __declspec(uuid("516a19a5-c2fd-4a9e-9fd3-9aa42f995a3c")) __declspec(novtable) IBindingExpression : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataItem(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_ParentBinding(Windows::UI::Xaml::Data::IBinding ** value) = 0;
    virtual HRESULT __stdcall abi_UpdateSource() = 0;
};

struct __declspec(uuid("fded3154-e954-4f67-8fb6-6ed79b3a1cb3")) __declspec(novtable) IBindingExpressionBase : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ea7116a7-c2d9-4375-b471-66b9c48c7930")) __declspec(novtable) IBindingExpressionBaseFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1cb55cd9-db72-40b3-a2b5-24ee6ea5c328")) __declspec(novtable) IBindingExpressionFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("ff42bb08-c39e-4f7e-8434-a1569083883c")) __declspec(novtable) IBindingFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::IBinding ** instance) = 0;
};

struct __declspec(uuid("6fffd738-9839-419c-a17a-4b3604e1524e")) __declspec(novtable) IBindingOperations : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e155ef73-95a0-4aab-8c7d-2a47da073c79")) __declspec(novtable) IBindingOperationsStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetBinding(Windows::UI::Xaml::IDependencyObject * target, Windows::UI::Xaml::IDependencyProperty * dp, Windows::UI::Xaml::Data::IBindingBase * binding) = 0;
};

struct __declspec(uuid("8be8bfe4-dbef-44df-8126-a31a89121ddc")) __declspec(novtable) ICollectionView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentItem(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_CurrentPosition(int32_t * value) = 0;
    virtual HRESULT __stdcall get_IsCurrentAfterLast(bool * value) = 0;
    virtual HRESULT __stdcall get_IsCurrentBeforeFirst(bool * value) = 0;
    virtual HRESULT __stdcall get_CollectionGroups(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_HasMoreItems(bool * value) = 0;
    virtual HRESULT __stdcall add_CurrentChanged(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentChanging(Windows::UI::Xaml::Data::CurrentChangingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentChanging(event_token token) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentTo(Windows::Foundation::IInspectable * item, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentToPosition(int32_t index, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentToFirst(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentToLast(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentToNext(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_MoveCurrentToPrevious(bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_LoadMoreItemsAsync(uint32_t count, Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> ** returnValue) = 0;
};

struct __declspec(uuid("34d4aaf4-8e72-4950-9192-ecd07d399d0a")) __declspec(novtable) ICollectionViewFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateView(Windows::UI::Xaml::Data::ICollectionView ** result) = 0;
};

struct __declspec(uuid("7e01b9d8-d7b5-48b6-b31c-5bb5bdf5f09b")) __declspec(novtable) ICollectionViewGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Group(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_GroupItems(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("a66a1146-d2fb-4ead-be9f-3578a466dcfe")) __declspec(novtable) ICollectionViewSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_View(Windows::UI::Xaml::Data::ICollectionView ** value) = 0;
    virtual HRESULT __stdcall get_IsSourceGrouped(bool * value) = 0;
    virtual HRESULT __stdcall put_IsSourceGrouped(bool value) = 0;
    virtual HRESULT __stdcall get_ItemsPath(Windows::UI::Xaml::IPropertyPath ** value) = 0;
    virtual HRESULT __stdcall put_ItemsPath(Windows::UI::Xaml::IPropertyPath * value) = 0;
};

struct __declspec(uuid("173a0710-46af-4c0c-818b-21b6ef81bf65")) __declspec(novtable) ICollectionViewSourceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SourceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ViewProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsSourceGroupedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ItemsPathProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("f9891e29-51cc-47dd-a5b9-35dc4914af69")) __declspec(novtable) ICurrentChangingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall get_IsCancelable(bool * value) = 0;
};

struct __declspec(uuid("153bbeee-62f3-48cf-8183-8be26de3a66e")) __declspec(novtable) ICurrentChangingEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::ICurrentChangingEventArgs ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateWithCancelableParameter(bool isCancelable, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::ICurrentChangingEventArgs ** instance) = 0;
};

struct __declspec(uuid("30da92c0-23e8-42a0-ae7c-734a0e5d2782")) __declspec(novtable) ICustomProperty : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Type(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetValue(Windows::Foundation::IInspectable * target, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetValue(Windows::Foundation::IInspectable * target, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_GetIndexedValue(Windows::Foundation::IInspectable * target, Windows::Foundation::IInspectable * index, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetIndexedValue(Windows::Foundation::IInspectable * target, Windows::Foundation::IInspectable * value, Windows::Foundation::IInspectable * index) = 0;
    virtual HRESULT __stdcall get_CanWrite(bool * value) = 0;
    virtual HRESULT __stdcall get_CanRead(bool * value) = 0;
};

struct __declspec(uuid("7c925755-3e48-42b4-8677-76372267033f")) __declspec(novtable) ICustomPropertyProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetCustomProperty(hstring name, Windows::UI::Xaml::Data::ICustomProperty ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIndexedProperty(hstring name, Windows::UI::Xaml::Interop::TypeName type, Windows::UI::Xaml::Data::ICustomProperty ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetStringRepresentation(hstring * returnValue) = 0;
    virtual HRESULT __stdcall get_Type(Windows::UI::Xaml::Interop::TypeName * value) = 0;
};

struct __declspec(uuid("83b834be-0583-4a26-9b64-8bf4a2f65704")) __declspec(novtable) IItemIndexRange : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FirstIndex(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Length(uint32_t * value) = 0;
    virtual HRESULT __stdcall get_LastIndex(int32_t * value) = 0;
};

struct __declspec(uuid("86e2c440-2e7a-4c7d-a664-e8abf07bfc7e")) __declspec(novtable) IItemIndexRangeFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(int32_t firstIndex, uint32_t length, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::IItemIndexRange ** instance) = 0;
};

struct __declspec(uuid("f05f5665-71fd-45a2-be13-a081d294a68d")) __declspec(novtable) IItemsRangeInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RangesChanged(Windows::UI::Xaml::Data::IItemIndexRange * visibleRange, Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> * trackedItems) = 0;
};

struct __declspec(uuid("cf75d69c-f2f4-486b-b302-bb4c09baebfa")) __declspec(novtable) INotifyPropertyChanged : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_PropertyChanged(Windows::UI::Xaml::Data::PropertyChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PropertyChanged(event_token token) = 0;
};

struct __declspec(uuid("4f33a9a0-5cf4-47a4-b16f-d7faaf17457e")) __declspec(novtable) IPropertyChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PropertyName(hstring * value) = 0;
};

struct __declspec(uuid("6dcc9c03-e0c7-4eee-8ea9-37e3406eeb1c")) __declspec(novtable) IPropertyChangedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(hstring name, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::IPropertyChangedEventArgs ** instance) = 0;
};

struct __declspec(uuid("2397ce84-2822-483a-b499-d0f031e06c6b")) __declspec(novtable) IRelativeSource : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Mode(winrt::Windows::UI::Xaml::Data::RelativeSourceMode * value) = 0;
    virtual HRESULT __stdcall put_Mode(winrt::Windows::UI::Xaml::Data::RelativeSourceMode value) = 0;
};

struct __declspec(uuid("ef8392cd-446e-4f93-aacb-9b1255577460")) __declspec(novtable) IRelativeSourceFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::Data::IRelativeSource ** instance) = 0;
};

struct __declspec(uuid("2e12ca86-e1ed-4245-be49-207e42aec524")) __declspec(novtable) ISelectionInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SelectRange(Windows::UI::Xaml::Data::IItemIndexRange * itemIndexRange) = 0;
    virtual HRESULT __stdcall abi_DeselectRange(Windows::UI::Xaml::Data::IItemIndexRange * itemIndexRange) = 0;
    virtual HRESULT __stdcall abi_IsSelected(int32_t index, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetSelectedRanges(Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> ** returnValue) = 0;
};

struct __declspec(uuid("7f5ee992-7694-4e6c-a51b-e34bf43de743")) __declspec(novtable) ISupportIncrementalLoading : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadMoreItemsAsync(uint32_t count, Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> ** operation) = 0;
    virtual HRESULT __stdcall get_HasMoreItems(bool * value) = 0;
};

struct __declspec(uuid("e6f2fef0-0712-487f-b313-f300b8d79aa1")) __declspec(novtable) IValueConverter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Convert(Windows::Foundation::IInspectable * value, Windows::UI::Xaml::Interop::TypeName targetType, Windows::Foundation::IInspectable * parameter, hstring language, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_ConvertBack(Windows::Foundation::IInspectable * value, Windows::UI::Xaml::Interop::TypeName targetType, Windows::Foundation::IInspectable * parameter, hstring language, Windows::Foundation::IInspectable ** returnValue) = 0;
};

struct __declspec(uuid("50f19c16-0a22-4d8e-a089-1ea9951657d2")) __declspec(novtable) PropertyChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::Data::IPropertyChangedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::Data::Binding> { using default_interface = Windows::UI::Xaml::Data::IBinding; };
template <> struct traits<Windows::UI::Xaml::Data::BindingBase> { using default_interface = Windows::UI::Xaml::Data::IBindingBase; };
template <> struct traits<Windows::UI::Xaml::Data::BindingExpression> { using default_interface = Windows::UI::Xaml::Data::IBindingExpression; };
template <> struct traits<Windows::UI::Xaml::Data::BindingExpressionBase> { using default_interface = Windows::UI::Xaml::Data::IBindingExpressionBase; };
template <> struct traits<Windows::UI::Xaml::Data::BindingOperations> { using default_interface = Windows::UI::Xaml::Data::IBindingOperations; };
template <> struct traits<Windows::UI::Xaml::Data::CollectionViewSource> { using default_interface = Windows::UI::Xaml::Data::ICollectionViewSource; };
template <> struct traits<Windows::UI::Xaml::Data::CurrentChangingEventArgs> { using default_interface = Windows::UI::Xaml::Data::ICurrentChangingEventArgs; };
template <> struct traits<Windows::UI::Xaml::Data::ItemIndexRange> { using default_interface = Windows::UI::Xaml::Data::IItemIndexRange; };
template <> struct traits<Windows::UI::Xaml::Data::PropertyChangedEventArgs> { using default_interface = Windows::UI::Xaml::Data::IPropertyChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Data::RelativeSource> { using default_interface = Windows::UI::Xaml::Data::IRelativeSource; };

}

namespace Windows::UI::Xaml::Data {

template <typename D>
struct WINRT_EBO impl_IBinding
{
    Windows::UI::Xaml::PropertyPath Path() const;
    void Path(const Windows::UI::Xaml::PropertyPath & value) const;
    Windows::UI::Xaml::Data::BindingMode Mode() const;
    void Mode(Windows::UI::Xaml::Data::BindingMode value) const;
    Windows::Foundation::IInspectable Source() const;
    void Source(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::Data::RelativeSource RelativeSource() const;
    void RelativeSource(const Windows::UI::Xaml::Data::RelativeSource & value) const;
    hstring ElementName() const;
    void ElementName(hstring_view value) const;
    Windows::UI::Xaml::Data::IValueConverter Converter() const;
    void Converter(const Windows::UI::Xaml::Data::IValueConverter & value) const;
    Windows::Foundation::IInspectable ConverterParameter() const;
    void ConverterParameter(const Windows::Foundation::IInspectable & value) const;
    hstring ConverterLanguage() const;
    void ConverterLanguage(hstring_view value) const;
};

template <typename D>
struct WINRT_EBO impl_IBinding2
{
    Windows::Foundation::IInspectable FallbackValue() const;
    void FallbackValue(const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::IInspectable TargetNullValue() const;
    void TargetNullValue(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::Data::UpdateSourceTrigger UpdateSourceTrigger() const;
    void UpdateSourceTrigger(Windows::UI::Xaml::Data::UpdateSourceTrigger value) const;
};

template <typename D>
struct WINRT_EBO impl_IBindingBase
{
};

template <typename D>
struct WINRT_EBO impl_IBindingBaseFactory
{
    Windows::UI::Xaml::Data::BindingBase CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IBindingExpression
{
    Windows::Foundation::IInspectable DataItem() const;
    Windows::UI::Xaml::Data::Binding ParentBinding() const;
    void UpdateSource() const;
};

template <typename D>
struct WINRT_EBO impl_IBindingExpressionBase
{
};

template <typename D>
struct WINRT_EBO impl_IBindingExpressionBaseFactory
{
};

template <typename D>
struct WINRT_EBO impl_IBindingExpressionFactory
{
};

template <typename D>
struct WINRT_EBO impl_IBindingFactory
{
    Windows::UI::Xaml::Data::Binding CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IBindingOperations
{
};

template <typename D>
struct WINRT_EBO impl_IBindingOperationsStatics
{
    void SetBinding(const Windows::UI::Xaml::DependencyObject & target, const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding) const;
};

template <typename D>
struct WINRT_EBO impl_ICollectionView
{
    Windows::Foundation::IInspectable CurrentItem() const;
    int32_t CurrentPosition() const;
    bool IsCurrentAfterLast() const;
    bool IsCurrentBeforeFirst() const;
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> CollectionGroups() const;
    bool HasMoreItems() const;
    event_token CurrentChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using CurrentChanged_revoker = event_revoker<ICollectionView>;
    CurrentChanged_revoker CurrentChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void CurrentChanged(event_token token) const;
    event_token CurrentChanging(const Windows::UI::Xaml::Data::CurrentChangingEventHandler & value) const;
    using CurrentChanging_revoker = event_revoker<ICollectionView>;
    CurrentChanging_revoker CurrentChanging(auto_revoke_t, const Windows::UI::Xaml::Data::CurrentChangingEventHandler & value) const;
    void CurrentChanging(event_token token) const;
    bool MoveCurrentTo(const Windows::Foundation::IInspectable & item) const;
    bool MoveCurrentToPosition(int32_t index) const;
    bool MoveCurrentToFirst() const;
    bool MoveCurrentToLast() const;
    bool MoveCurrentToNext() const;
    bool MoveCurrentToPrevious() const;
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> LoadMoreItemsAsync(uint32_t count) const;
};

template <typename D>
struct WINRT_EBO impl_ICollectionViewFactory
{
    Windows::UI::Xaml::Data::ICollectionView CreateView() const;
};

template <typename D>
struct WINRT_EBO impl_ICollectionViewGroup
{
    Windows::Foundation::IInspectable Group() const;
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> GroupItems() const;
};

template <typename D>
struct WINRT_EBO impl_ICollectionViewSource
{
    Windows::Foundation::IInspectable Source() const;
    void Source(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::Data::ICollectionView View() const;
    bool IsSourceGrouped() const;
    void IsSourceGrouped(bool value) const;
    Windows::UI::Xaml::PropertyPath ItemsPath() const;
    void ItemsPath(const Windows::UI::Xaml::PropertyPath & value) const;
};

template <typename D>
struct WINRT_EBO impl_ICollectionViewSourceStatics
{
    Windows::UI::Xaml::DependencyProperty SourceProperty() const;
    Windows::UI::Xaml::DependencyProperty ViewProperty() const;
    Windows::UI::Xaml::DependencyProperty IsSourceGroupedProperty() const;
    Windows::UI::Xaml::DependencyProperty ItemsPathProperty() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentChangingEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
    bool IsCancelable() const;
};

template <typename D>
struct WINRT_EBO impl_ICurrentChangingEventArgsFactory
{
    Windows::UI::Xaml::Data::CurrentChangingEventArgs CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::Data::CurrentChangingEventArgs CreateWithCancelableParameter(bool isCancelable, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ICustomProperty
{
    Windows::UI::Xaml::Interop::TypeName Type() const;
    hstring Name() const;
    Windows::Foundation::IInspectable GetValue(const Windows::Foundation::IInspectable & target) const;
    void SetValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & value) const;
    Windows::Foundation::IInspectable GetIndexedValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & index) const;
    void SetIndexedValue(const Windows::Foundation::IInspectable & target, const Windows::Foundation::IInspectable & value, const Windows::Foundation::IInspectable & index) const;
    bool CanWrite() const;
    bool CanRead() const;
};

template <typename D>
struct WINRT_EBO impl_ICustomPropertyProvider
{
    Windows::UI::Xaml::Data::ICustomProperty GetCustomProperty(hstring_view name) const;
    Windows::UI::Xaml::Data::ICustomProperty GetIndexedProperty(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & type) const;
    hstring GetStringRepresentation() const;
    Windows::UI::Xaml::Interop::TypeName Type() const;
};

template <typename D>
struct WINRT_EBO impl_IItemIndexRange
{
    int32_t FirstIndex() const;
    uint32_t Length() const;
    int32_t LastIndex() const;
};

template <typename D>
struct WINRT_EBO impl_IItemIndexRangeFactory
{
    Windows::UI::Xaml::Data::ItemIndexRange CreateInstance(int32_t firstIndex, uint32_t length, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IItemsRangeInfo
{
    void RangesChanged(const Windows::UI::Xaml::Data::ItemIndexRange & visibleRange, vector_view<Windows::UI::Xaml::Data::ItemIndexRange> trackedItems) const;
};

template <typename D>
struct WINRT_EBO impl_INotifyPropertyChanged
{
    event_token PropertyChanged(const Windows::UI::Xaml::Data::PropertyChangedEventHandler & value) const;
    using PropertyChanged_revoker = event_revoker<INotifyPropertyChanged>;
    PropertyChanged_revoker PropertyChanged(auto_revoke_t, const Windows::UI::Xaml::Data::PropertyChangedEventHandler & value) const;
    void PropertyChanged(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyChangedEventArgs
{
    hstring PropertyName() const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyChangedEventArgsFactory
{
    Windows::UI::Xaml::Data::PropertyChangedEventArgs CreateInstance(hstring_view name, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRelativeSource
{
    Windows::UI::Xaml::Data::RelativeSourceMode Mode() const;
    void Mode(Windows::UI::Xaml::Data::RelativeSourceMode value) const;
};

template <typename D>
struct WINRT_EBO impl_IRelativeSourceFactory
{
    Windows::UI::Xaml::Data::RelativeSource CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISelectionInfo
{
    void SelectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const;
    void DeselectRange(const Windows::UI::Xaml::Data::ItemIndexRange & itemIndexRange) const;
    bool IsSelected(int32_t index) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Data::ItemIndexRange> GetSelectedRanges() const;
};

template <typename D>
struct WINRT_EBO impl_ISupportIncrementalLoading
{
    Windows::Foundation::IAsyncOperation<Windows::UI::Xaml::Data::LoadMoreItemsResult> LoadMoreItemsAsync(uint32_t count) const;
    bool HasMoreItems() const;
};

template <typename D>
struct WINRT_EBO impl_IValueConverter
{
    Windows::Foundation::IInspectable Convert(const Windows::Foundation::IInspectable & value, const Windows::UI::Xaml::Interop::TypeName & targetType, const Windows::Foundation::IInspectable & parameter, hstring_view language) const;
    Windows::Foundation::IInspectable ConvertBack(const Windows::Foundation::IInspectable & value, const Windows::UI::Xaml::Interop::TypeName & targetType, const Windows::Foundation::IInspectable & parameter, hstring_view language) const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::Data::CurrentChangingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Data::CurrentChangingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Data::IBinding>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBinding;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBinding<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBinding2>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBinding2;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBinding2<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingBase>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingBase;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingBase<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingExpression>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingExpression;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingExpression<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingExpressionBase>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingExpressionBase;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingExpressionBase<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingExpressionBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingExpressionBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingExpressionBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingExpressionFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingExpressionFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingExpressionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingOperations>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingOperations;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingOperations<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IBindingOperationsStatics>
{
    using abi = ABI::Windows::UI::Xaml::Data::IBindingOperationsStatics;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IBindingOperationsStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICollectionView>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICollectionView;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICollectionView<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICollectionViewFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICollectionViewFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICollectionViewFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICollectionViewGroup>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICollectionViewGroup;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICollectionViewGroup<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICollectionViewSource>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICollectionViewSource;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICollectionViewSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICollectionViewSourceStatics>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICollectionViewSourceStatics;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICollectionViewSourceStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICurrentChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICurrentChangingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICurrentChangingEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICurrentChangingEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICurrentChangingEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICustomProperty>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICustomProperty;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICustomProperty<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ICustomPropertyProvider>
{
    using abi = ABI::Windows::UI::Xaml::Data::ICustomPropertyProvider;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ICustomPropertyProvider<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IItemIndexRange>
{
    using abi = ABI::Windows::UI::Xaml::Data::IItemIndexRange;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IItemIndexRange<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IItemIndexRangeFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IItemIndexRangeFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IItemIndexRangeFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IItemsRangeInfo>
{
    using abi = ABI::Windows::UI::Xaml::Data::IItemsRangeInfo;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IItemsRangeInfo<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::INotifyPropertyChanged>
{
    using abi = ABI::Windows::UI::Xaml::Data::INotifyPropertyChanged;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_INotifyPropertyChanged<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IPropertyChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IPropertyChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IPropertyChangedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IPropertyChangedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IRelativeSource>
{
    using abi = ABI::Windows::UI::Xaml::Data::IRelativeSource;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IRelativeSource<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IRelativeSourceFactory>
{
    using abi = ABI::Windows::UI::Xaml::Data::IRelativeSourceFactory;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IRelativeSourceFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ISelectionInfo>
{
    using abi = ABI::Windows::UI::Xaml::Data::ISelectionInfo;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ISelectionInfo<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::ISupportIncrementalLoading>
{
    using abi = ABI::Windows::UI::Xaml::Data::ISupportIncrementalLoading;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_ISupportIncrementalLoading<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::IValueConverter>
{
    using abi = ABI::Windows::UI::Xaml::Data::IValueConverter;
    template <typename D> using consume = Windows::UI::Xaml::Data::impl_IValueConverter<D>;
};

template <> struct traits<Windows::UI::Xaml::Data::PropertyChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::Data::PropertyChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::Data::Binding>
{
    using abi = ABI::Windows::UI::Xaml::Data::Binding;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.Binding"; }
};

template <> struct traits<Windows::UI::Xaml::Data::BindingBase>
{
    using abi = ABI::Windows::UI::Xaml::Data::BindingBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.BindingBase"; }
};

template <> struct traits<Windows::UI::Xaml::Data::BindingExpression>
{
    using abi = ABI::Windows::UI::Xaml::Data::BindingExpression;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.BindingExpression"; }
};

template <> struct traits<Windows::UI::Xaml::Data::BindingExpressionBase>
{
    using abi = ABI::Windows::UI::Xaml::Data::BindingExpressionBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.BindingExpressionBase"; }
};

template <> struct traits<Windows::UI::Xaml::Data::BindingOperations>
{
    using abi = ABI::Windows::UI::Xaml::Data::BindingOperations;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.BindingOperations"; }
};

template <> struct traits<Windows::UI::Xaml::Data::CollectionViewSource>
{
    using abi = ABI::Windows::UI::Xaml::Data::CollectionViewSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.CollectionViewSource"; }
};

template <> struct traits<Windows::UI::Xaml::Data::CurrentChangingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Data::CurrentChangingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.CurrentChangingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Data::ItemIndexRange>
{
    using abi = ABI::Windows::UI::Xaml::Data::ItemIndexRange;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.ItemIndexRange"; }
};

template <> struct traits<Windows::UI::Xaml::Data::PropertyChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::Data::PropertyChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.PropertyChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Data::RelativeSource>
{
    using abi = ABI::Windows::UI::Xaml::Data::RelativeSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Data.RelativeSource"; }
};

}

}
