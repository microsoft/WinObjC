// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml {

template <typename D, typename ... Interfaces> struct AdaptiveTriggerT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected, Windows::UI::Xaml::IAdaptiveTrigger>
{
    using composable = AdaptiveTrigger;

protected:

    AdaptiveTriggerT()
    {
        get_activation_factory<AdaptiveTrigger, IAdaptiveTriggerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ApplicationT :
    overrides<D, Windows::UI::Xaml::IApplicationOverridesT<D>, Windows::UI::Xaml::IApplicationOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IApplication, Windows::UI::Xaml::IApplication2>
{
    using composable = Application;

protected:

    ApplicationT()
    {
        get_activation_factory<Application, IApplicationFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDataTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = DataTemplate;

protected:

    DataTemplateT()
    {
        get_activation_factory<DataTemplate, IDataTemplateFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DataTemplateKeyT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDataTemplateKey>
{
    using composable = DataTemplateKey;

protected:

    DataTemplateKeyT()
    {
        get_activation_factory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstance(*this, this->m_inner);
    }

    DataTemplateKeyT(const Windows::Foundation::IInspectable & dataType)
    {
        get_activation_factory<DataTemplateKey, IDataTemplateKeyFactory>().CreateInstanceWithType(dataType, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DependencyObjectT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = DependencyObject;

protected:

    DependencyObjectT()
    {
        get_activation_factory<DependencyObject, IDependencyObjectFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DependencyObjectCollectionT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>>
{
    using composable = DependencyObjectCollection;

protected:

    DependencyObjectCollectionT()
    {
        get_activation_factory<DependencyObjectCollection, IDependencyObjectCollectionFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct DispatcherTimerT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDispatcherTimer>
{
    using composable = DispatcherTimer;

protected:

    DispatcherTimerT()
    {
        get_activation_factory<DispatcherTimer, IDispatcherTimerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkElementT :
    overrides<D, Windows::UI::Xaml::IUIElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverridesT<D>, Windows::UI::Xaml::IFrameworkElementOverrides2T<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    using composable = FrameworkElement;

protected:

    FrameworkElementT()
    {
        get_activation_factory<FrameworkElement, IFrameworkElementFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct FrameworkTemplateT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    using composable = FrameworkTemplate;

protected:

    FrameworkTemplateT()
    {
        get_activation_factory<FrameworkTemplate, IFrameworkTemplateFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct PropertyMetadataT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IPropertyMetadata>
{
    using composable = PropertyMetadata;

protected:

    PropertyMetadataT(const Windows::Foundation::IInspectable & defaultValue)
    {
        get_activation_factory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValue(defaultValue, *this, this->m_inner);
    }

    PropertyMetadataT(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback)
    {
        get_activation_factory<PropertyMetadata, IPropertyMetadataFactory>().CreateInstanceWithDefaultValueAndCallback(defaultValue, propertyChangedCallback, *this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct ResourceDictionaryT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IResourceDictionary, Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>>>
{
    using composable = ResourceDictionary;

protected:

    ResourceDictionaryT()
    {
        get_activation_factory<ResourceDictionary, IResourceDictionaryFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct RoutedEventArgsT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IRoutedEventArgs>
{
    using composable = RoutedEventArgs;

protected:

    RoutedEventArgsT()
    {
        get_activation_factory<RoutedEventArgs, IRoutedEventArgsFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct StateTriggerBaseT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase, Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    using composable = StateTriggerBase;

protected:

    StateTriggerBaseT()
    {
        get_activation_factory<StateTriggerBase, IStateTriggerBaseFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualStateManagerT :
    overrides<D, Windows::UI::Xaml::IVisualStateManagerOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManager, Windows::UI::Xaml::IVisualStateManagerProtected>
{
    using composable = VisualStateManager;

protected:

    VisualStateManagerT()
    {
        get_activation_factory<VisualStateManager, IVisualStateManagerFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct VisualTransitionT :
    overrides<D, Windows::Foundation::IInspectable, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualTransition>
{
    using composable = VisualTransition;

protected:

    VisualTransitionT()
    {
        get_activation_factory<VisualTransition, IVisualTransitionFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
