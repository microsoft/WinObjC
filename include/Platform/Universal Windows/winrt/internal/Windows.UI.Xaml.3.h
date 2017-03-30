// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml {

template <typename H> struct impl_ApplicationInitializationCallback : implements<impl_ApplicationInitializationCallback<H>, abi<ApplicationInitializationCallback>>, H
{
    impl_ApplicationInitializationCallback(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Xaml::IApplicationInitializationCallbackParams> p) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Xaml::ApplicationInitializationCallbackParams *>(&p));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_BindingFailedEventHandler : implements<impl_BindingFailedEventHandler<H>, abi<BindingFailedEventHandler>>, H
{
    impl_BindingFailedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IBindingFailedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::BindingFailedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_CreateDefaultValueCallback : implements<impl_CreateDefaultValueCallback<H>, abi<CreateDefaultValueCallback>>, H
{
    impl_CreateDefaultValueCallback(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            *value = detach_abi((*this)());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DependencyPropertyChangedCallback : implements<impl_DependencyPropertyChangedCallback<H>, abi<DependencyPropertyChangedCallback>>, H
{
    impl_DependencyPropertyChangedCallback(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> sender, impl::abi_arg_in<Windows::UI::Xaml::IDependencyProperty> dp) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::DependencyProperty *>(&dp));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DependencyPropertyChangedEventHandler : implements<impl_DependencyPropertyChangedEventHandler<H>, abi<DependencyPropertyChangedEventHandler>>, H
{
    impl_DependencyPropertyChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IDependencyPropertyChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::DependencyPropertyChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_DragEventHandler : implements<impl_DragEventHandler<H>, abi<DragEventHandler>>, H
{
    impl_DragEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IDragEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::DragEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_EnteredBackgroundEventHandler : implements<impl_EnteredBackgroundEventHandler<H>, abi<EnteredBackgroundEventHandler>>, H
{
    impl_EnteredBackgroundEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::ApplicationModel::IEnteredBackgroundEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::ApplicationModel::EnteredBackgroundEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_ExceptionRoutedEventHandler : implements<impl_ExceptionRoutedEventHandler<H>, abi<ExceptionRoutedEventHandler>>, H
{
    impl_ExceptionRoutedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IExceptionRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::ExceptionRoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_LeavingBackgroundEventHandler : implements<impl_LeavingBackgroundEventHandler<H>, abi<LeavingBackgroundEventHandler>>, H
{
    impl_LeavingBackgroundEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::ApplicationModel::ILeavingBackgroundEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::ApplicationModel::LeavingBackgroundEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_PropertyChangedCallback : implements<impl_PropertyChangedCallback<H>, abi<PropertyChangedCallback>>, H
{
    impl_PropertyChangedCallback(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::UI::Xaml::IDependencyObject> d, impl::abi_arg_in<Windows::UI::Xaml::IDependencyPropertyChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::UI::Xaml::DependencyObject *>(&d), *reinterpret_cast<const Windows::UI::Xaml::DependencyPropertyChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_RoutedEventHandler : implements<impl_RoutedEventHandler<H>, abi<RoutedEventHandler>>, H
{
    impl_RoutedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IRoutedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::RoutedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SizeChangedEventHandler : implements<impl_SizeChangedEventHandler<H>, abi<SizeChangedEventHandler>>, H
{
    impl_SizeChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::ISizeChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::SizeChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_SuspendingEventHandler : implements<impl_SuspendingEventHandler<H>, abi<SuspendingEventHandler>>, H
{
    impl_SuspendingEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::ApplicationModel::ISuspendingEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::ApplicationModel::SuspendingEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_UnhandledExceptionEventHandler : implements<impl_UnhandledExceptionEventHandler<H>, abi<UnhandledExceptionEventHandler>>, H
{
    impl_UnhandledExceptionEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IUnhandledExceptionEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::UnhandledExceptionEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_VisualStateChangedEventHandler : implements<impl_VisualStateChangedEventHandler<H>, abi<VisualStateChangedEventHandler>>, H
{
    impl_VisualStateChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Xaml::IVisualStateChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Xaml::VisualStateChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WindowActivatedEventHandler : implements<impl_WindowActivatedEventHandler<H>, abi<WindowActivatedEventHandler>>, H
{
    impl_WindowActivatedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Core::IWindowActivatedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Core::WindowActivatedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WindowClosedEventHandler : implements<impl_WindowClosedEventHandler<H>, abi<WindowClosedEventHandler>>, H
{
    impl_WindowClosedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Core::ICoreWindowEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Core::CoreWindowEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WindowSizeChangedEventHandler : implements<impl_WindowSizeChangedEventHandler<H>, abi<WindowSizeChangedEventHandler>>, H
{
    impl_WindowSizeChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Core::IWindowSizeChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Core::WindowSizeChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename H> struct impl_WindowVisibilityChangedEventHandler : implements<impl_WindowVisibilityChangedEventHandler<H>, abi<WindowVisibilityChangedEventHandler>>, H
{
    impl_WindowVisibilityChangedEventHandler(H && handler) : H(std::forward<H>(handler)) {}

    HRESULT __stdcall abi_Invoke(impl::abi_arg_in<Windows::Foundation::IInspectable> sender, impl::abi_arg_in<Windows::UI::Core::IVisibilityChangedEventArgs> e) noexcept override
    {
        try
        {
            (*this)(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&sender), *reinterpret_cast<const Windows::UI::Core::VisibilityChangedEventArgs *>(&e));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml {

struct WINRT_EBO AdaptiveTrigger :
    Windows::UI::Xaml::IAdaptiveTrigger,
    impl::bases<AdaptiveTrigger, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::StateTriggerBase>,
    impl::require<AdaptiveTrigger, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase>
{
    AdaptiveTrigger(std::nullptr_t) noexcept {}
    AdaptiveTrigger();
    static Windows::UI::Xaml::DependencyProperty MinWindowWidthProperty();
    static Windows::UI::Xaml::DependencyProperty MinWindowHeightProperty();
};

struct WINRT_EBO Application :
    Windows::UI::Xaml::IApplication,
    impl::require<Application, Windows::UI::Xaml::IApplicationOverrides, Windows::UI::Xaml::IApplication2, Windows::UI::Xaml::IApplicationOverrides2>
{
    Application(std::nullptr_t) noexcept {}
    Application();
    static Windows::UI::Xaml::Application Current();
    static void Start(const Windows::UI::Xaml::ApplicationInitializationCallback & callback);
    static void LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator);
    static void LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator, Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation);
};

struct WINRT_EBO ApplicationInitializationCallbackParams :
    Windows::UI::Xaml::IApplicationInitializationCallbackParams
{
    ApplicationInitializationCallbackParams(std::nullptr_t) noexcept {}
};

struct WINRT_EBO BindingFailedEventArgs :
    Windows::UI::Xaml::IBindingFailedEventArgs
{
    BindingFailedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO CornerRadiusHelper :
    Windows::UI::Xaml::ICornerRadiusHelper
{
    CornerRadiusHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::CornerRadius FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft);
    static Windows::UI::Xaml::CornerRadius FromUniformRadius(double uniformRadius);
};

struct WINRT_EBO DataContextChangedEventArgs :
    Windows::UI::Xaml::IDataContextChangedEventArgs
{
    DataContextChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DataTemplate :
    Windows::UI::Xaml::IDataTemplate,
    impl::bases<DataTemplate, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::FrameworkTemplate>,
    impl::require<DataTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IFrameworkTemplate>
{
    DataTemplate(std::nullptr_t) noexcept {}
    DataTemplate();
    static Windows::UI::Xaml::DependencyProperty ExtensionInstanceProperty();
    static Windows::UI::Xaml::IDataTemplateExtension GetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element);
    static void SetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element, const Windows::UI::Xaml::IDataTemplateExtension & value);
};

struct WINRT_EBO DataTemplateKey :
    Windows::UI::Xaml::IDataTemplateKey
{
    DataTemplateKey(std::nullptr_t) noexcept {}
    DataTemplateKey();
    DataTemplateKey(const Windows::Foundation::IInspectable & dataType);
};

struct WINRT_EBO DebugSettings :
    Windows::UI::Xaml::IDebugSettings,
    impl::require<DebugSettings, Windows::UI::Xaml::IDebugSettings2, Windows::UI::Xaml::IDebugSettings3>
{
    DebugSettings(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DependencyObject :
    Windows::UI::Xaml::IDependencyObject,
    impl::require<DependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    DependencyObject(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DependencyObjectCollection :
    Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>,
    impl::bases<DependencyObjectCollection, Windows::UI::Xaml::DependencyObject>,
    impl::require<DependencyObjectCollection, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    DependencyObjectCollection(std::nullptr_t) noexcept {}
    DependencyObjectCollection();
};

struct WINRT_EBO DependencyProperty :
    Windows::UI::Xaml::IDependencyProperty
{
    DependencyProperty(std::nullptr_t) noexcept {}
    static Windows::Foundation::IInspectable UnsetValue();
    static Windows::UI::Xaml::DependencyProperty Register(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & typeMetadata);
    static Windows::UI::Xaml::DependencyProperty RegisterAttached(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & defaultMetadata);
};

struct WINRT_EBO DependencyPropertyChangedEventArgs :
    Windows::UI::Xaml::IDependencyPropertyChangedEventArgs
{
    DependencyPropertyChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DispatcherTimer :
    Windows::UI::Xaml::IDispatcherTimer
{
    DispatcherTimer(std::nullptr_t) noexcept {}
    DispatcherTimer();
};

struct WINRT_EBO DragEventArgs :
    Windows::UI::Xaml::IDragEventArgs,
    impl::bases<DragEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DragEventArgs, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::IDragEventArgs2, Windows::UI::Xaml::IDragEventArgs3>
{
    DragEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragOperationDeferral :
    Windows::UI::Xaml::IDragOperationDeferral
{
    DragOperationDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragStartingEventArgs :
    Windows::UI::Xaml::IDragStartingEventArgs,
    impl::bases<DragStartingEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DragStartingEventArgs, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::IDragStartingEventArgs2>
{
    DragStartingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragUI :
    Windows::UI::Xaml::IDragUI
{
    DragUI(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DragUIOverride :
    Windows::UI::Xaml::IDragUIOverride
{
    DragUIOverride(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DropCompletedEventArgs :
    Windows::UI::Xaml::IDropCompletedEventArgs,
    impl::bases<DropCompletedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<DropCompletedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    DropCompletedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO DurationHelper :
    Windows::UI::Xaml::IDurationHelper
{
    DurationHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Duration Automatic();
    static Windows::UI::Xaml::Duration Forever();
    static int32_t Compare(const Windows::UI::Xaml::Duration & duration1, const Windows::UI::Xaml::Duration & duration2);
    static Windows::UI::Xaml::Duration FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan);
    static bool GetHasTimeSpan(const Windows::UI::Xaml::Duration & target);
    static Windows::UI::Xaml::Duration Add(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration);
    static bool Equals(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & value);
    static Windows::UI::Xaml::Duration Subtract(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration);
};

struct WINRT_EBO ElementSoundPlayer :
    Windows::UI::Xaml::IElementSoundPlayer
{
    ElementSoundPlayer(std::nullptr_t) noexcept {}
    static double Volume();
    static void Volume(double value);
    static Windows::UI::Xaml::ElementSoundPlayerState State();
    static void State(Windows::UI::Xaml::ElementSoundPlayerState value);
    static void Play(Windows::UI::Xaml::ElementSoundKind sound);
};

struct WINRT_EBO EventTrigger :
    Windows::UI::Xaml::IEventTrigger,
    impl::bases<EventTrigger, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::TriggerBase>,
    impl::require<EventTrigger, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::ITriggerBase>
{
    EventTrigger(std::nullptr_t) noexcept {}
    EventTrigger();
};

struct WINRT_EBO ExceptionRoutedEventArgs :
    Windows::UI::Xaml::IExceptionRoutedEventArgs,
    impl::bases<ExceptionRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<ExceptionRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    ExceptionRoutedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FrameworkElement :
    Windows::UI::Xaml::IFrameworkElement,
    impl::bases<FrameworkElement, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement>,
    impl::require<FrameworkElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    FrameworkElement(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty TagProperty();
    static Windows::UI::Xaml::DependencyProperty LanguageProperty();
    static Windows::UI::Xaml::DependencyProperty ActualWidthProperty();
    static Windows::UI::Xaml::DependencyProperty ActualHeightProperty();
    static Windows::UI::Xaml::DependencyProperty WidthProperty();
    static Windows::UI::Xaml::DependencyProperty HeightProperty();
    static Windows::UI::Xaml::DependencyProperty MinWidthProperty();
    static Windows::UI::Xaml::DependencyProperty MaxWidthProperty();
    static Windows::UI::Xaml::DependencyProperty MinHeightProperty();
    static Windows::UI::Xaml::DependencyProperty MaxHeightProperty();
    static Windows::UI::Xaml::DependencyProperty HorizontalAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty VerticalAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty MarginProperty();
    static Windows::UI::Xaml::DependencyProperty NameProperty();
    static Windows::UI::Xaml::DependencyProperty DataContextProperty();
    static Windows::UI::Xaml::DependencyProperty StyleProperty();
    static Windows::UI::Xaml::DependencyProperty FlowDirectionProperty();
    static Windows::UI::Xaml::DependencyProperty RequestedThemeProperty();
    static Windows::UI::Xaml::DependencyProperty AllowFocusOnInteractionProperty();
    static Windows::UI::Xaml::DependencyProperty FocusVisualMarginProperty();
    static Windows::UI::Xaml::DependencyProperty FocusVisualSecondaryThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty FocusVisualPrimaryThicknessProperty();
    static Windows::UI::Xaml::DependencyProperty FocusVisualSecondaryBrushProperty();
    static Windows::UI::Xaml::DependencyProperty FocusVisualPrimaryBrushProperty();
    static Windows::UI::Xaml::DependencyProperty AllowFocusWhenDisabledProperty();
};

struct WINRT_EBO FrameworkTemplate :
    Windows::UI::Xaml::IFrameworkTemplate,
    impl::bases<FrameworkTemplate, Windows::UI::Xaml::DependencyObject>,
    impl::require<FrameworkTemplate, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    FrameworkTemplate(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FrameworkView :
    Windows::UI::Xaml::IFrameworkView,
    impl::require<FrameworkView, Windows::ApplicationModel::Core::IFrameworkView>
{
    FrameworkView(std::nullptr_t) noexcept {}
    FrameworkView();
};

struct WINRT_EBO FrameworkViewSource :
    Windows::UI::Xaml::IFrameworkViewSource,
    impl::require<FrameworkViewSource, Windows::ApplicationModel::Core::IFrameworkViewSource>
{
    FrameworkViewSource(std::nullptr_t) noexcept {}
    FrameworkViewSource();
};

struct WINRT_EBO GridLengthHelper :
    Windows::UI::Xaml::IGridLengthHelper
{
    GridLengthHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::GridLength Auto();
    static Windows::UI::Xaml::GridLength FromPixels(double pixels);
    static Windows::UI::Xaml::GridLength FromValueAndType(double value, Windows::UI::Xaml::GridUnitType type);
    static bool GetIsAbsolute(const Windows::UI::Xaml::GridLength & target);
    static bool GetIsAuto(const Windows::UI::Xaml::GridLength & target);
    static bool GetIsStar(const Windows::UI::Xaml::GridLength & target);
    static bool Equals(const Windows::UI::Xaml::GridLength & target, const Windows::UI::Xaml::GridLength & value);
};

struct WINRT_EBO MediaFailedRoutedEventArgs :
    Windows::UI::Xaml::IMediaFailedRoutedEventArgs,
    impl::bases<MediaFailedRoutedEventArgs, Windows::UI::Xaml::RoutedEventArgs, Windows::UI::Xaml::ExceptionRoutedEventArgs>,
    impl::require<MediaFailedRoutedEventArgs, Windows::UI::Xaml::IRoutedEventArgs, Windows::UI::Xaml::IExceptionRoutedEventArgs>
{
    MediaFailedRoutedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO PointHelper :
    Windows::UI::Xaml::IPointHelper
{
    PointHelper(std::nullptr_t) noexcept {}
    static Windows::Foundation::Point FromCoordinates(float x, float y);
};

struct WINRT_EBO PropertyMetadata :
    Windows::UI::Xaml::IPropertyMetadata
{
    PropertyMetadata(std::nullptr_t) noexcept {}
    PropertyMetadata(const Windows::Foundation::IInspectable & defaultValue);
    PropertyMetadata(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback);
    static Windows::UI::Xaml::PropertyMetadata Create(const Windows::Foundation::IInspectable & defaultValue);
    static Windows::UI::Xaml::PropertyMetadata Create(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback);
    static Windows::UI::Xaml::PropertyMetadata Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback);
    static Windows::UI::Xaml::PropertyMetadata Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback);
};

struct WINRT_EBO PropertyPath :
    Windows::UI::Xaml::IPropertyPath,
    impl::bases<PropertyPath, Windows::UI::Xaml::DependencyObject>,
    impl::require<PropertyPath, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    PropertyPath(std::nullptr_t) noexcept {}
    PropertyPath(hstring_view path);
};

struct WINRT_EBO RectHelper :
    Windows::UI::Xaml::IRectHelper
{
    RectHelper(std::nullptr_t) noexcept {}
    static Windows::Foundation::Rect Empty();
    static Windows::Foundation::Rect FromCoordinatesAndDimensions(float x, float y, float width, float height);
    static Windows::Foundation::Rect FromPoints(const Windows::Foundation::Point & point1, const Windows::Foundation::Point & point2);
    static Windows::Foundation::Rect FromLocationAndSize(const Windows::Foundation::Point & location, const Windows::Foundation::Size & size);
    static bool GetIsEmpty(const Windows::Foundation::Rect & target);
    static float GetBottom(const Windows::Foundation::Rect & target);
    static float GetLeft(const Windows::Foundation::Rect & target);
    static float GetRight(const Windows::Foundation::Rect & target);
    static float GetTop(const Windows::Foundation::Rect & target);
    static bool Contains(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point);
    static bool Equals(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & value);
    static Windows::Foundation::Rect Intersect(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect);
    static Windows::Foundation::Rect Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point);
    static Windows::Foundation::Rect Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect);
};

struct WINRT_EBO ResourceDictionary :
    Windows::UI::Xaml::IResourceDictionary,
    impl::bases<ResourceDictionary, Windows::UI::Xaml::DependencyObject>,
    impl::require<ResourceDictionary, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IKeyValuePair<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable>>>
{
    ResourceDictionary(std::nullptr_t) noexcept {}
    ResourceDictionary();
};

struct WINRT_EBO RoutedEvent :
    Windows::UI::Xaml::IRoutedEvent
{
    RoutedEvent(std::nullptr_t) noexcept {}
};

struct WINRT_EBO RoutedEventArgs :
    Windows::UI::Xaml::IRoutedEventArgs
{
    RoutedEventArgs(std::nullptr_t) noexcept {}
    RoutedEventArgs();
};

struct WINRT_EBO Setter :
    Windows::UI::Xaml::ISetter,
    impl::bases<Setter, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::SetterBase>,
    impl::require<Setter, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::ISetterBase, Windows::UI::Xaml::ISetter2>
{
    Setter(std::nullptr_t) noexcept {}
    Setter();
    Setter(const Windows::UI::Xaml::DependencyProperty & targetProperty, const Windows::Foundation::IInspectable & value);
};

struct WINRT_EBO SetterBase :
    Windows::UI::Xaml::ISetterBase,
    impl::bases<SetterBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<SetterBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    SetterBase(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SetterBaseCollection :
    Windows::UI::Xaml::ISetterBaseCollection
{
    SetterBaseCollection(std::nullptr_t) noexcept {}
    SetterBaseCollection();
};

struct WINRT_EBO SizeChangedEventArgs :
    Windows::UI::Xaml::ISizeChangedEventArgs,
    impl::bases<SizeChangedEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<SizeChangedEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    SizeChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO SizeHelper :
    Windows::UI::Xaml::ISizeHelper
{
    SizeHelper(std::nullptr_t) noexcept {}
    static Windows::Foundation::Size Empty();
    static Windows::Foundation::Size FromDimensions(float width, float height);
    static bool GetIsEmpty(const Windows::Foundation::Size & target);
    static bool Equals(const Windows::Foundation::Size & target, const Windows::Foundation::Size & value);
};

struct WINRT_EBO StateTrigger :
    Windows::UI::Xaml::IStateTrigger,
    impl::bases<StateTrigger, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::StateTriggerBase>,
    impl::require<StateTrigger, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IStateTriggerBase>
{
    StateTrigger(std::nullptr_t) noexcept {}
    StateTrigger();
    static Windows::UI::Xaml::DependencyProperty IsActiveProperty();
};

struct WINRT_EBO StateTriggerBase :
    Windows::UI::Xaml::IStateTriggerBase,
    impl::bases<StateTriggerBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<StateTriggerBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    StateTriggerBase(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Style :
    Windows::UI::Xaml::IStyle,
    impl::bases<Style, Windows::UI::Xaml::DependencyObject>,
    impl::require<Style, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Style(std::nullptr_t) noexcept {}
    Style();
    Style(const Windows::UI::Xaml::Interop::TypeName & targetType);
};

struct WINRT_EBO TargetPropertyPath :
    Windows::UI::Xaml::ITargetPropertyPath
{
    TargetPropertyPath(std::nullptr_t) noexcept {}
    TargetPropertyPath();
    TargetPropertyPath(const Windows::UI::Xaml::DependencyProperty & targetProperty);
};

struct WINRT_EBO ThicknessHelper :
    Windows::UI::Xaml::IThicknessHelper
{
    ThicknessHelper(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Thickness FromLengths(double left, double top, double right, double bottom);
    static Windows::UI::Xaml::Thickness FromUniformLength(double uniformLength);
};

struct WINRT_EBO TriggerAction :
    Windows::UI::Xaml::ITriggerAction,
    impl::bases<TriggerAction, Windows::UI::Xaml::DependencyObject>,
    impl::require<TriggerAction, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    TriggerAction(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TriggerActionCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerAction>
{
    TriggerActionCollection(std::nullptr_t) noexcept {}
    TriggerActionCollection();
};

struct WINRT_EBO TriggerBase :
    Windows::UI::Xaml::ITriggerBase,
    impl::bases<TriggerBase, Windows::UI::Xaml::DependencyObject>,
    impl::require<TriggerBase, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    TriggerBase(std::nullptr_t) noexcept {}
};

struct WINRT_EBO TriggerCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerBase>
{
    TriggerCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UIElement :
    Windows::UI::Xaml::IUIElement,
    impl::bases<UIElement, Windows::UI::Xaml::DependencyObject>,
    impl::require<UIElement, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4>
{
    UIElement(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::RoutedEvent KeyDownEvent();
    static Windows::UI::Xaml::RoutedEvent KeyUpEvent();
    static Windows::UI::Xaml::RoutedEvent PointerEnteredEvent();
    static Windows::UI::Xaml::RoutedEvent PointerPressedEvent();
    static Windows::UI::Xaml::RoutedEvent PointerMovedEvent();
    static Windows::UI::Xaml::RoutedEvent PointerReleasedEvent();
    static Windows::UI::Xaml::RoutedEvent PointerExitedEvent();
    static Windows::UI::Xaml::RoutedEvent PointerCaptureLostEvent();
    static Windows::UI::Xaml::RoutedEvent PointerCanceledEvent();
    static Windows::UI::Xaml::RoutedEvent PointerWheelChangedEvent();
    static Windows::UI::Xaml::RoutedEvent TappedEvent();
    static Windows::UI::Xaml::RoutedEvent DoubleTappedEvent();
    static Windows::UI::Xaml::RoutedEvent HoldingEvent();
    static Windows::UI::Xaml::RoutedEvent RightTappedEvent();
    static Windows::UI::Xaml::RoutedEvent ManipulationStartingEvent();
    static Windows::UI::Xaml::RoutedEvent ManipulationInertiaStartingEvent();
    static Windows::UI::Xaml::RoutedEvent ManipulationStartedEvent();
    static Windows::UI::Xaml::RoutedEvent ManipulationDeltaEvent();
    static Windows::UI::Xaml::RoutedEvent ManipulationCompletedEvent();
    static Windows::UI::Xaml::RoutedEvent DragEnterEvent();
    static Windows::UI::Xaml::RoutedEvent DragLeaveEvent();
    static Windows::UI::Xaml::RoutedEvent DragOverEvent();
    static Windows::UI::Xaml::RoutedEvent DropEvent();
    static Windows::UI::Xaml::DependencyProperty AllowDropProperty();
    static Windows::UI::Xaml::DependencyProperty OpacityProperty();
    static Windows::UI::Xaml::DependencyProperty ClipProperty();
    static Windows::UI::Xaml::DependencyProperty RenderTransformProperty();
    static Windows::UI::Xaml::DependencyProperty ProjectionProperty();
    static Windows::UI::Xaml::DependencyProperty RenderTransformOriginProperty();
    static Windows::UI::Xaml::DependencyProperty IsHitTestVisibleProperty();
    static Windows::UI::Xaml::DependencyProperty VisibilityProperty();
    static Windows::UI::Xaml::DependencyProperty UseLayoutRoundingProperty();
    static Windows::UI::Xaml::DependencyProperty TransitionsProperty();
    static Windows::UI::Xaml::DependencyProperty CacheModeProperty();
    static Windows::UI::Xaml::DependencyProperty IsTapEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsDoubleTapEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsRightTapEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty IsHoldingEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty ManipulationModeProperty();
    static Windows::UI::Xaml::DependencyProperty PointerCapturesProperty();
    static Windows::UI::Xaml::DependencyProperty CompositeModeProperty();
    static Windows::UI::Xaml::DependencyProperty Transform3DProperty();
    static Windows::UI::Xaml::DependencyProperty CanDragProperty();
    static bool TryStartDirectManipulation(const Windows::UI::Xaml::Input::Pointer & value);
    static Windows::UI::Xaml::DependencyProperty ContextFlyoutProperty();
    static Windows::UI::Xaml::DependencyProperty ExitDisplayModeOnAccessKeyInvokedProperty();
    static Windows::UI::Xaml::DependencyProperty IsAccessKeyScopeProperty();
    static Windows::UI::Xaml::DependencyProperty AccessKeyScopeOwnerProperty();
    static Windows::UI::Xaml::DependencyProperty AccessKeyProperty();
};

struct WINRT_EBO UnhandledExceptionEventArgs :
    Windows::UI::Xaml::IUnhandledExceptionEventArgs
{
    UnhandledExceptionEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO VisualState :
    Windows::UI::Xaml::IVisualState,
    impl::bases<VisualState, Windows::UI::Xaml::DependencyObject>,
    impl::require<VisualState, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualState2>
{
    VisualState(std::nullptr_t) noexcept {}
    VisualState();
};

struct WINRT_EBO VisualStateChangedEventArgs :
    Windows::UI::Xaml::IVisualStateChangedEventArgs
{
    VisualStateChangedEventArgs(std::nullptr_t) noexcept {}
    VisualStateChangedEventArgs();
};

struct WINRT_EBO VisualStateGroup :
    Windows::UI::Xaml::IVisualStateGroup,
    impl::bases<VisualStateGroup, Windows::UI::Xaml::DependencyObject>,
    impl::require<VisualStateGroup, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    VisualStateGroup(std::nullptr_t) noexcept {}
    VisualStateGroup();
};

struct WINRT_EBO VisualStateManager :
    Windows::UI::Xaml::IVisualStateManager,
    impl::bases<VisualStateManager, Windows::UI::Xaml::DependencyObject>,
    impl::require<VisualStateManager, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IVisualStateManagerOverrides>
{
    VisualStateManager(std::nullptr_t) noexcept {}
    VisualStateManager();
    static Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> GetVisualStateGroups(const Windows::UI::Xaml::FrameworkElement & obj);
    static Windows::UI::Xaml::DependencyProperty CustomVisualStateManagerProperty();
    static Windows::UI::Xaml::VisualStateManager GetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj);
    static void SetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj, const Windows::UI::Xaml::VisualStateManager & value);
    static bool GoToState(const Windows::UI::Xaml::Controls::Control & control, hstring_view stateName, bool useTransitions);
};

struct WINRT_EBO VisualTransition :
    Windows::UI::Xaml::IVisualTransition,
    impl::bases<VisualTransition, Windows::UI::Xaml::DependencyObject>,
    impl::require<VisualTransition, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    VisualTransition(std::nullptr_t) noexcept {}
    VisualTransition();
};

struct WINRT_EBO Window :
    Windows::UI::Xaml::IWindow,
    impl::require<Window, Windows::UI::Xaml::IWindow2>
{
    Window(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::Window Current();
};

struct WINRT_EBO WindowCreatedEventArgs :
    Windows::UI::Xaml::IWindowCreatedEventArgs
{
    WindowCreatedEventArgs(std::nullptr_t) noexcept {}
};

}

}
