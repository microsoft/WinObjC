// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml::Data {

struct LoadMoreItemsResult;

}

namespace Windows::UI::Xaml::Data {

using LoadMoreItemsResult = ABI::Windows::UI::Xaml::Data::LoadMoreItemsResult;

}

namespace ABI::Windows::UI::Xaml::Data {

struct CurrentChangingEventHandler;
struct IBinding;
struct IBinding2;
struct IBindingBase;
struct IBindingBaseFactory;
struct IBindingExpression;
struct IBindingExpressionBase;
struct IBindingExpressionBaseFactory;
struct IBindingExpressionFactory;
struct IBindingFactory;
struct IBindingOperations;
struct IBindingOperationsStatics;
struct ICollectionView;
struct ICollectionViewFactory;
struct ICollectionViewGroup;
struct ICollectionViewSource;
struct ICollectionViewSourceStatics;
struct ICurrentChangingEventArgs;
struct ICurrentChangingEventArgsFactory;
struct ICustomProperty;
struct ICustomPropertyProvider;
struct IItemIndexRange;
struct IItemIndexRangeFactory;
struct IItemsRangeInfo;
struct INotifyPropertyChanged;
struct IPropertyChangedEventArgs;
struct IPropertyChangedEventArgsFactory;
struct IRelativeSource;
struct IRelativeSourceFactory;
struct ISelectionInfo;
struct ISupportIncrementalLoading;
struct IValueConverter;
struct PropertyChangedEventHandler;
struct Binding;
struct BindingBase;
struct BindingExpression;
struct BindingExpressionBase;
struct BindingOperations;
struct CollectionViewSource;
struct CurrentChangingEventArgs;
struct ItemIndexRange;
struct PropertyChangedEventArgs;
struct RelativeSource;

}

namespace Windows::UI::Xaml::Data {

struct CurrentChangingEventHandler;
struct PropertyChangedEventHandler;
struct IBinding;
struct IBinding2;
struct IBindingBase;
struct IBindingBaseFactory;
struct IBindingExpression;
struct IBindingExpressionBase;
struct IBindingExpressionBaseFactory;
struct IBindingExpressionFactory;
struct IBindingFactory;
struct IBindingOperations;
struct IBindingOperationsStatics;
struct ICollectionView;
struct ICollectionViewFactory;
struct ICollectionViewGroup;
struct ICollectionViewSource;
struct ICollectionViewSourceStatics;
struct ICurrentChangingEventArgs;
struct ICurrentChangingEventArgsFactory;
struct ICustomProperty;
struct ICustomPropertyProvider;
struct IItemIndexRange;
struct IItemIndexRangeFactory;
struct IItemsRangeInfo;
struct INotifyPropertyChanged;
struct IPropertyChangedEventArgs;
struct IPropertyChangedEventArgsFactory;
struct IRelativeSource;
struct IRelativeSourceFactory;
struct ISelectionInfo;
struct ISupportIncrementalLoading;
struct IValueConverter;
struct Binding;
struct BindingBase;
struct BindingExpression;
struct BindingExpressionBase;
struct BindingOperations;
struct CollectionViewSource;
struct CurrentChangingEventArgs;
struct ItemIndexRange;
struct PropertyChangedEventArgs;
struct RelativeSource;

}

namespace Windows::UI::Xaml::Data {

template <typename T> struct impl_IBinding;
template <typename T> struct impl_IBinding2;
template <typename T> struct impl_IBindingBase;
template <typename T> struct impl_IBindingBaseFactory;
template <typename T> struct impl_IBindingExpression;
template <typename T> struct impl_IBindingExpressionBase;
template <typename T> struct impl_IBindingExpressionBaseFactory;
template <typename T> struct impl_IBindingExpressionFactory;
template <typename T> struct impl_IBindingFactory;
template <typename T> struct impl_IBindingOperations;
template <typename T> struct impl_IBindingOperationsStatics;
template <typename T> struct impl_ICollectionView;
template <typename T> struct impl_ICollectionViewFactory;
template <typename T> struct impl_ICollectionViewGroup;
template <typename T> struct impl_ICollectionViewSource;
template <typename T> struct impl_ICollectionViewSourceStatics;
template <typename T> struct impl_ICurrentChangingEventArgs;
template <typename T> struct impl_ICurrentChangingEventArgsFactory;
template <typename T> struct impl_ICustomProperty;
template <typename T> struct impl_ICustomPropertyProvider;
template <typename T> struct impl_IItemIndexRange;
template <typename T> struct impl_IItemIndexRangeFactory;
template <typename T> struct impl_IItemsRangeInfo;
template <typename T> struct impl_INotifyPropertyChanged;
template <typename T> struct impl_IPropertyChangedEventArgs;
template <typename T> struct impl_IPropertyChangedEventArgsFactory;
template <typename T> struct impl_IRelativeSource;
template <typename T> struct impl_IRelativeSourceFactory;
template <typename T> struct impl_ISelectionInfo;
template <typename T> struct impl_ISupportIncrementalLoading;
template <typename T> struct impl_IValueConverter;
template <typename T> struct impl_CurrentChangingEventHandler;
template <typename T> struct impl_PropertyChangedEventHandler;

}

namespace Windows::UI::Xaml::Data {

enum class BindingMode
{
    OneWay = 1,
    OneTime = 2,
    TwoWay = 3,
};

enum class RelativeSourceMode
{
    None = 0,
    TemplatedParent = 1,
    Self = 2,
};

enum class UpdateSourceTrigger
{
    Default = 0,
    PropertyChanged = 1,
    Explicit = 2,
};

}

}
