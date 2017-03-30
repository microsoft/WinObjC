// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.UI.Xaml.0.h"
#include "Windows.ApplicationModel.0.h"
#include "Windows.ApplicationModel.Activation.0.h"
#include "Windows.ApplicationModel.Core.0.h"
#include "Windows.ApplicationModel.DataTransfer.0.h"
#include "Windows.ApplicationModel.DataTransfer.DragDrop.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.UI.Core.0.h"
#include "Windows.UI.Input.0.h"
#include "Windows.UI.Xaml.Automation.Peers.0.h"
#include "Windows.UI.Xaml.Controls.0.h"
#include "Windows.UI.Xaml.Controls.Primitives.0.h"
#include "Windows.UI.Xaml.Data.0.h"
#include "Windows.UI.Xaml.Input.0.h"
#include "Windows.UI.Xaml.Interop.0.h"
#include "Windows.UI.Xaml.Media.0.h"
#include "Windows.UI.Xaml.Media.Animation.0.h"
#include "Windows.UI.Xaml.Media.Imaging.0.h"
#include "Windows.UI.Xaml.Media.Media3D.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.UI.Xaml.Input.1.h"
#include "Windows.ApplicationModel.DataTransfer.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::UI::Xaml {

struct CornerRadius
{
    double TopLeft;
    double TopRight;
    double BottomRight;
    double BottomLeft;
};

struct Duration
{
    Windows::Foundation::TimeSpan TimeSpan;
    winrt::Windows::UI::Xaml::DurationType Type;
};

struct Thickness
{
    double Left;
    double Top;
    double Right;
    double Bottom;
};

struct GridLength
{
    double Value;
    winrt::Windows::UI::Xaml::GridUnitType GridUnitType;
};

}

namespace Windows::UI::Xaml {

using CornerRadius = ABI::Windows::UI::Xaml::CornerRadius;
using Duration = ABI::Windows::UI::Xaml::Duration;
using Thickness = ABI::Windows::UI::Xaml::Thickness;
using GridLength = ABI::Windows::UI::Xaml::GridLength;

}

namespace ABI::Windows::UI::Xaml {

struct __declspec(uuid("b6351c55-c284-46e4-8310-fb0967fab76f")) __declspec(novtable) ApplicationInitializationCallback : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Xaml::IApplicationInitializationCallbackParams * p) = 0;
};

struct __declspec(uuid("136b1782-54ba-420d-a1aa-82828721cde6")) __declspec(novtable) BindingFailedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IBindingFailedEventArgs * e) = 0;
};

struct __declspec(uuid("d6ecb12c-15b5-4ec8-b95c-cdd208f08153")) __declspec(novtable) CreateDefaultValueCallback : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("45883d16-27bf-4bc1-ac26-94c1601f3a49")) __declspec(novtable) DependencyPropertyChangedCallback : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Xaml::IDependencyObject * sender, Windows::UI::Xaml::IDependencyProperty * dp) = 0;
};

struct __declspec(uuid("09223e5a-75be-4499-8180-1ddc005421c0")) __declspec(novtable) DependencyPropertyChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IDependencyPropertyChangedEventArgs * e) = 0;
};

struct __declspec(uuid("2ab1a205-1e73-4bcf-aabc-57b97e21961d")) __declspec(novtable) DragEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IDragEventArgs * e) = 0;
};

struct __declspec(uuid("93a956ae-1d7f-438b-b7b8-227d96b609c0")) __declspec(novtable) EnteredBackgroundEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::ApplicationModel::IEnteredBackgroundEventArgs * e) = 0;
};

struct __declspec(uuid("68e0e810-f6ea-42bc-855b-5d9b67e6a262")) __declspec(novtable) ExceptionRoutedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IExceptionRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("a5f04119-0cd9-49f1-a23f-44e547ab9f1a")) __declspec(novtable) IAdaptiveTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinWindowWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MinWindowWidth(double value) = 0;
    virtual HRESULT __stdcall get_MinWindowHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MinWindowHeight(double value) = 0;
};

struct __declspec(uuid("c966d482-5aeb-4841-9247-c1a0bdd6f59f")) __declspec(novtable) IAdaptiveTriggerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IAdaptiveTrigger ** instance) = 0;
};

struct __declspec(uuid("b92e29ea-1615-4350-9c3b-92b2986bf444")) __declspec(novtable) IAdaptiveTriggerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_MinWindowWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinWindowHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("74b861a1-7487-46a9-9a6e-c78b512726c5")) __declspec(novtable) IApplication : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Resources(Windows::UI::Xaml::IResourceDictionary ** value) = 0;
    virtual HRESULT __stdcall put_Resources(Windows::UI::Xaml::IResourceDictionary * value) = 0;
    virtual HRESULT __stdcall get_DebugSettings(Windows::UI::Xaml::IDebugSettings ** value) = 0;
    virtual HRESULT __stdcall get_RequestedTheme(winrt::Windows::UI::Xaml::ApplicationTheme * value) = 0;
    virtual HRESULT __stdcall put_RequestedTheme(winrt::Windows::UI::Xaml::ApplicationTheme value) = 0;
    virtual HRESULT __stdcall add_UnhandledException(Windows::UI::Xaml::UnhandledExceptionEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UnhandledException(event_token token) = 0;
    virtual HRESULT __stdcall add_Suspending(Windows::UI::Xaml::SuspendingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Suspending(event_token token) = 0;
    virtual HRESULT __stdcall add_Resuming(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Resuming(event_token token) = 0;
    virtual HRESULT __stdcall abi_Exit() = 0;
};

struct __declspec(uuid("019104be-522a-5904-f52f-de72010429e0")) __declspec(novtable) IApplication2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FocusVisualKind(winrt::Windows::UI::Xaml::FocusVisualKind * value) = 0;
    virtual HRESULT __stdcall put_FocusVisualKind(winrt::Windows::UI::Xaml::FocusVisualKind value) = 0;
    virtual HRESULT __stdcall get_RequiresPointerMode(winrt::Windows::UI::Xaml::ApplicationRequiresPointerMode * value) = 0;
    virtual HRESULT __stdcall put_RequiresPointerMode(winrt::Windows::UI::Xaml::ApplicationRequiresPointerMode value) = 0;
    virtual HRESULT __stdcall add_LeavingBackground(Windows::UI::Xaml::LeavingBackgroundEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LeavingBackground(event_token token) = 0;
    virtual HRESULT __stdcall add_EnteredBackground(Windows::UI::Xaml::EnteredBackgroundEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_EnteredBackground(event_token token) = 0;
};

struct __declspec(uuid("93bbe361-be5a-4ee3-b4a3-95118dc97a89")) __declspec(novtable) IApplicationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IApplication ** instance) = 0;
};

struct __declspec(uuid("751b792e-5772-4488-8b87-f547faa64474")) __declspec(novtable) IApplicationInitializationCallbackParams : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("25f99ff7-9347-459a-9fac-b2d0e11c1a0f")) __declspec(novtable) IApplicationOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnLaunched(Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnFileActivated(Windows::ApplicationModel::Activation::IFileActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnSearchActivated(Windows::ApplicationModel::Activation::ISearchActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnShareTargetActivated(Windows::ApplicationModel::Activation::IShareTargetActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnFileOpenPickerActivated(Windows::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnFileSavePickerActivated(Windows::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnCachedFileUpdaterActivated(Windows::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs * args) = 0;
    virtual HRESULT __stdcall abi_OnWindowCreated(Windows::UI::Xaml::IWindowCreatedEventArgs * args) = 0;
};

struct __declspec(uuid("db5cd2b9-d3b4-558c-c64e-0434fd1bd889")) __declspec(novtable) IApplicationOverrides2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnBackgroundActivated(Windows::ApplicationModel::Activation::IBackgroundActivatedEventArgs * args) = 0;
};

struct __declspec(uuid("06499997-f7b4-45fe-b763-7577d1d3cb4a")) __declspec(novtable) IApplicationStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::UI::Xaml::IApplication ** value) = 0;
    virtual HRESULT __stdcall abi_Start(Windows::UI::Xaml::ApplicationInitializationCallback * callback) = 0;
    virtual HRESULT __stdcall abi_LoadComponent(Windows::Foundation::IInspectable * component, Windows::Foundation::IUriRuntimeClass * resourceLocator) = 0;
    virtual HRESULT __stdcall abi_LoadComponentWithResourceLocation(Windows::Foundation::IInspectable * component, Windows::Foundation::IUriRuntimeClass * resourceLocator, winrt::Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation) = 0;
};

struct __declspec(uuid("32c1d013-4dbd-446d-bbb8-0de35048a449")) __declspec(novtable) IBindingFailedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
};

struct __declspec(uuid("fd7be182-1cdb-4288-b8c8-85ee79297bfc")) __declspec(novtable) ICornerRadiusHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("f4a1f659-d4d4-451f-a387-d6bf4b2451d4")) __declspec(novtable) ICornerRadiusHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft, Windows::UI::Xaml::CornerRadius * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromUniformRadius(double uniformRadius, Windows::UI::Xaml::CornerRadius * returnValue) = 0;
};

struct __declspec(uuid("7da68e21-0b8f-4f9f-a143-f8e7780136a2")) __declspec(novtable) IDataContextChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_NewValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("9910aec7-8ab5-4118-9bc6-09f45a35073d")) __declspec(novtable) IDataTemplate : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_LoadContent(Windows::UI::Xaml::IDependencyObject ** returnValue) = 0;
};

struct __declspec(uuid("595e9547-cdff-4b92-b773-ab396878f353")) __declspec(novtable) IDataTemplateExtension : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_ResetTemplate() = 0;
    virtual HRESULT __stdcall abi_ProcessBinding(uint32_t phase, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_ProcessBindings(Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs * arg, int32_t * returnValue) = 0;
};

struct __declspec(uuid("51ed9d7e-2b53-475b-9c88-0c1832c8351a")) __declspec(novtable) IDataTemplateFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IDataTemplate ** instance) = 0;
};

struct __declspec(uuid("873b6c28-cceb-4b61-86fa-b2cec39cc2fa")) __declspec(novtable) IDataTemplateKey : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataType(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_DataType(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("e96b2959-d982-4152-91cb-de0e4dfd7693")) __declspec(novtable) IDataTemplateKeyFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IDataTemplateKey ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithType(Windows::Foundation::IInspectable * dataType, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IDataTemplateKey ** instance) = 0;
};

struct __declspec(uuid("8af77d73-aa01-471e-bedd-8bad86219b77")) __declspec(novtable) IDataTemplateStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExtensionInstanceProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetExtensionInstance(Windows::UI::Xaml::IFrameworkElement * element, Windows::UI::Xaml::IDataTemplateExtension ** value) = 0;
    virtual HRESULT __stdcall abi_SetExtensionInstance(Windows::UI::Xaml::IFrameworkElement * element, Windows::UI::Xaml::IDataTemplateExtension * value) = 0;
};

struct __declspec(uuid("3d451f98-c6a7-4d17-8398-d83a067183d8")) __declspec(novtable) IDebugSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnableFrameRateCounter(bool * value) = 0;
    virtual HRESULT __stdcall put_EnableFrameRateCounter(bool value) = 0;
    virtual HRESULT __stdcall get_IsBindingTracingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsBindingTracingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsOverdrawHeatMapEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsOverdrawHeatMapEnabled(bool value) = 0;
    virtual HRESULT __stdcall add_BindingFailed(Windows::UI::Xaml::BindingFailedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_BindingFailed(event_token token) = 0;
};

struct __declspec(uuid("48d37585-e1a6-469b-83c8-30825037119e")) __declspec(novtable) IDebugSettings2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EnableRedrawRegions(bool * value) = 0;
    virtual HRESULT __stdcall put_EnableRedrawRegions(bool value) = 0;
};

struct __declspec(uuid("e6bb5022-0625-479f-8e32-4b583d73b7ac")) __declspec(novtable) IDebugSettings3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsTextPerformanceVisualizationEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTextPerformanceVisualizationEnabled(bool value) = 0;
};

struct __declspec(uuid("5c526665-f60e-4912-af59-5fe0680f089d")) __declspec(novtable) IDependencyObject : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetValue(Windows::UI::Xaml::IDependencyProperty * dp, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetValue(Windows::UI::Xaml::IDependencyProperty * dp, Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall abi_ClearValue(Windows::UI::Xaml::IDependencyProperty * dp) = 0;
    virtual HRESULT __stdcall abi_ReadLocalValue(Windows::UI::Xaml::IDependencyProperty * dp, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetAnimationBaseValue(Windows::UI::Xaml::IDependencyProperty * dp, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall get_Dispatcher(Windows::UI::Core::ICoreDispatcher ** value) = 0;
};

struct __declspec(uuid("29fed85d-3d22-43a1-add0-17027c08b212")) __declspec(novtable) IDependencyObject2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterPropertyChangedCallback(Windows::UI::Xaml::IDependencyProperty * dp, Windows::UI::Xaml::DependencyPropertyChangedCallback * callback, int64_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_UnregisterPropertyChangedCallback(Windows::UI::Xaml::IDependencyProperty * dp, int64_t token) = 0;
};

struct __declspec(uuid("051e79ff-b3a8-49ee-b5af-ac8f68b649e4")) __declspec(novtable) IDependencyObjectCollectionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject> ** instance) = 0;
};

struct __declspec(uuid("9a03af92-7d8a-4937-884f-ecf34fe02acb")) __declspec(novtable) IDependencyObjectFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IDependencyObject ** instance) = 0;
};

struct __declspec(uuid("85b13970-9bc4-4e96-acf1-30c8fd3d55c8")) __declspec(novtable) IDependencyProperty : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetMetadata(Windows::UI::Xaml::Interop::TypeName forType, Windows::UI::Xaml::IPropertyMetadata ** returnValue) = 0;
};

struct __declspec(uuid("81212c2b-24d0-4957-abc3-224470a93a4e")) __declspec(novtable) IDependencyPropertyChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OldValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_NewValue(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("49e5f28f-8259-4d5c-aae0-83d56dbb68d9")) __declspec(novtable) IDependencyPropertyStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UnsetValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall abi_Register(hstring name, Windows::UI::Xaml::Interop::TypeName propertyType, Windows::UI::Xaml::Interop::TypeName ownerType, Windows::UI::Xaml::IPropertyMetadata * typeMetadata, Windows::UI::Xaml::IDependencyProperty ** returnValue) = 0;
    virtual HRESULT __stdcall abi_RegisterAttached(hstring name, Windows::UI::Xaml::Interop::TypeName propertyType, Windows::UI::Xaml::Interop::TypeName ownerType, Windows::UI::Xaml::IPropertyMetadata * defaultMetadata, Windows::UI::Xaml::IDependencyProperty ** returnValue) = 0;
};

struct __declspec(uuid("d160ce46-cd22-4f5f-8c97-40e61da3e2dc")) __declspec(novtable) IDispatcherTimer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Interval(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Interval(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall add_Tick(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Tick(event_token token) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
};

struct __declspec(uuid("e9961e6e-3626-403a-afe0-040d58165632")) __declspec(novtable) IDispatcherTimerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IDispatcherTimer ** instance) = 0;
};

struct __declspec(uuid("b440c7c3-02b4-4980-9342-25dae1c0f188")) __declspec(novtable) IDragEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::ApplicationModel::DataTransfer::IDataPackage ** value) = 0;
    virtual HRESULT __stdcall put_Data(Windows::ApplicationModel::DataTransfer::IDataPackage * value) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("26336658-2917-411d-bfc3-2f22471cbbe7")) __declspec(novtable) IDragEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DataView(Windows::ApplicationModel::DataTransfer::IDataPackageView ** value) = 0;
    virtual HRESULT __stdcall get_DragUIOverride(Windows::UI::Xaml::IDragUIOverride ** value) = 0;
    virtual HRESULT __stdcall get_Modifiers(winrt::Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers * value) = 0;
    virtual HRESULT __stdcall get_AcceptedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
    virtual HRESULT __stdcall put_AcceptedOperation(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::IDragOperationDeferral ** returnValue) = 0;
};

struct __declspec(uuid("d04fc3c6-8119-427a-8152-5f9550cc0416")) __declspec(novtable) IDragEventArgs3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowedOperations(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
};

struct __declspec(uuid("ba73ecba-1b73-4086-b3d3-c223beea1633")) __declspec(novtable) IDragOperationDeferral : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Complete() = 0;
};

struct __declspec(uuid("6800d3fa-90b8-46f9-8e30-5ac25f73f0f9")) __declspec(novtable) IDragStartingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Cancel(bool * value) = 0;
    virtual HRESULT __stdcall put_Cancel(bool value) = 0;
    virtual HRESULT __stdcall get_Data(Windows::ApplicationModel::DataTransfer::IDataPackage ** value) = 0;
    virtual HRESULT __stdcall get_DragUI(Windows::UI::Xaml::IDragUI ** value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::UI::Xaml::IDragOperationDeferral ** returnValue) = 0;
    virtual HRESULT __stdcall abi_GetPosition(Windows::UI::Xaml::IUIElement * relativeTo, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("d855e08e-44b6-4211-bd0b-7fddbb6e8231")) __declspec(novtable) IDragStartingEventArgs2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowedOperations(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
    virtual HRESULT __stdcall put_AllowedOperations(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation value) = 0;
};

struct __declspec(uuid("2d9bd838-7c60-4842-9170-346fe10a226a")) __declspec(novtable) IDragUI : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetContentFromBitmapImage(Windows::UI::Xaml::Media::Imaging::IBitmapImage * bitmapImage) = 0;
    virtual HRESULT __stdcall abi_SetContentFromBitmapImageWithAnchorPoint(Windows::UI::Xaml::Media::Imaging::IBitmapImage * bitmapImage, Windows::Foundation::Point anchorPoint) = 0;
    virtual HRESULT __stdcall abi_SetContentFromSoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap * softwareBitmap) = 0;
    virtual HRESULT __stdcall abi_SetContentFromSoftwareBitmapWithAnchorPoint(Windows::Graphics::Imaging::ISoftwareBitmap * softwareBitmap, Windows::Foundation::Point anchorPoint) = 0;
    virtual HRESULT __stdcall abi_SetContentFromDataPackage() = 0;
};

struct __declspec(uuid("bd6c9dfa-c961-4861-b7a5-bf4fe4a8a6ef")) __declspec(novtable) IDragUIOverride : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Caption(hstring * value) = 0;
    virtual HRESULT __stdcall put_Caption(hstring value) = 0;
    virtual HRESULT __stdcall get_IsContentVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsContentVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsCaptionVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsCaptionVisible(bool value) = 0;
    virtual HRESULT __stdcall get_IsGlyphVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsGlyphVisible(bool value) = 0;
    virtual HRESULT __stdcall abi_Clear() = 0;
    virtual HRESULT __stdcall abi_SetContentFromBitmapImage(Windows::UI::Xaml::Media::Imaging::IBitmapImage * bitmapImage) = 0;
    virtual HRESULT __stdcall abi_SetContentFromBitmapImageWithAnchorPoint(Windows::UI::Xaml::Media::Imaging::IBitmapImage * bitmapImage, Windows::Foundation::Point anchorPoint) = 0;
    virtual HRESULT __stdcall abi_SetContentFromSoftwareBitmap(Windows::Graphics::Imaging::ISoftwareBitmap * softwareBitmap) = 0;
    virtual HRESULT __stdcall abi_SetContentFromSoftwareBitmapWithAnchorPoint(Windows::Graphics::Imaging::ISoftwareBitmap * softwareBitmap, Windows::Foundation::Point anchorPoint) = 0;
};

struct __declspec(uuid("6c4fc188-95bc-4261-9ec5-21cab677b734")) __declspec(novtable) IDropCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DropResult(winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation * value) = 0;
};

struct __declspec(uuid("25c1659f-4497-4135-940f-ee96f4d6e934")) __declspec(novtable) IDurationHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("bc88093e-3547-4ec0-b519-ffa8f9c4838c")) __declspec(novtable) IDurationHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Automatic(Windows::UI::Xaml::Duration * value) = 0;
    virtual HRESULT __stdcall get_Forever(Windows::UI::Xaml::Duration * value) = 0;
    virtual HRESULT __stdcall abi_Compare(Windows::UI::Xaml::Duration duration1, Windows::UI::Xaml::Duration duration2, int32_t * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromTimeSpan(Windows::Foundation::TimeSpan timeSpan, Windows::UI::Xaml::Duration * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetHasTimeSpan(Windows::UI::Xaml::Duration target, bool * value) = 0;
    virtual HRESULT __stdcall abi_Add(Windows::UI::Xaml::Duration target, Windows::UI::Xaml::Duration duration, Windows::UI::Xaml::Duration * returnValue) = 0;
    virtual HRESULT __stdcall abi_Equals(Windows::UI::Xaml::Duration target, Windows::UI::Xaml::Duration value, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_Subtract(Windows::UI::Xaml::Duration target, Windows::UI::Xaml::Duration duration, Windows::UI::Xaml::Duration * returnValue) = 0;
};

struct __declspec(uuid("387773a5-f036-460c-9b81-f3d6ea43f6f2")) __declspec(novtable) IElementSoundPlayer : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("217a9004-981d-41c9-b152-ada911a4b13a")) __declspec(novtable) IElementSoundPlayerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Volume(double * value) = 0;
    virtual HRESULT __stdcall put_Volume(double value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::UI::Xaml::ElementSoundPlayerState * value) = 0;
    virtual HRESULT __stdcall put_State(winrt::Windows::UI::Xaml::ElementSoundPlayerState value) = 0;
    virtual HRESULT __stdcall abi_Play(winrt::Windows::UI::Xaml::ElementSoundKind sound) = 0;
};

struct __declspec(uuid("def8f855-0b49-4087-b1a9-b8b38488f786")) __declspec(novtable) IEventTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RoutedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall put_RoutedEvent(Windows::UI::Xaml::IRoutedEvent * value) = 0;
    virtual HRESULT __stdcall get_Actions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerAction> ** value) = 0;
};

struct __declspec(uuid("dd9ff16a-4b62-4a6c-a49d-0671ef6136be")) __declspec(novtable) IExceptionRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorMessage(hstring * value) = 0;
};

struct __declspec(uuid("bba9826d-5d7a-44e7-b893-b2ae0dd24273")) __declspec(novtable) IExceptionRoutedEventArgsFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("a391d09b-4a99-4b7c-9d8d-6fa5d01f6fbf")) __declspec(novtable) IFrameworkElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Triggers(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerBase> ** value) = 0;
    virtual HRESULT __stdcall get_Resources(Windows::UI::Xaml::IResourceDictionary ** value) = 0;
    virtual HRESULT __stdcall put_Resources(Windows::UI::Xaml::IResourceDictionary * value) = 0;
    virtual HRESULT __stdcall get_Tag(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Tag(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall put_Language(hstring value) = 0;
    virtual HRESULT __stdcall get_ActualWidth(double * value) = 0;
    virtual HRESULT __stdcall get_ActualHeight(double * value) = 0;
    virtual HRESULT __stdcall get_Width(double * value) = 0;
    virtual HRESULT __stdcall put_Width(double value) = 0;
    virtual HRESULT __stdcall get_Height(double * value) = 0;
    virtual HRESULT __stdcall put_Height(double value) = 0;
    virtual HRESULT __stdcall get_MinWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MinWidth(double value) = 0;
    virtual HRESULT __stdcall get_MaxWidth(double * value) = 0;
    virtual HRESULT __stdcall put_MaxWidth(double value) = 0;
    virtual HRESULT __stdcall get_MinHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MinHeight(double value) = 0;
    virtual HRESULT __stdcall get_MaxHeight(double * value) = 0;
    virtual HRESULT __stdcall put_MaxHeight(double value) = 0;
    virtual HRESULT __stdcall get_HorizontalAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment * value) = 0;
    virtual HRESULT __stdcall put_HorizontalAlignment(winrt::Windows::UI::Xaml::HorizontalAlignment value) = 0;
    virtual HRESULT __stdcall get_VerticalAlignment(winrt::Windows::UI::Xaml::VerticalAlignment * value) = 0;
    virtual HRESULT __stdcall put_VerticalAlignment(winrt::Windows::UI::Xaml::VerticalAlignment value) = 0;
    virtual HRESULT __stdcall get_Margin(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_Margin(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall put_Name(hstring value) = 0;
    virtual HRESULT __stdcall get_BaseUri(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_DataContext(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_DataContext(Windows::Foundation::IInspectable * value) = 0;
    virtual HRESULT __stdcall get_Style(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_Style(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall get_Parent(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall get_FlowDirection(winrt::Windows::UI::Xaml::FlowDirection * value) = 0;
    virtual HRESULT __stdcall put_FlowDirection(winrt::Windows::UI::Xaml::FlowDirection value) = 0;
    virtual HRESULT __stdcall add_Loaded(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Loaded(event_token token) = 0;
    virtual HRESULT __stdcall add_Unloaded(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Unloaded(event_token token) = 0;
    virtual HRESULT __stdcall add_SizeChanged(Windows::UI::Xaml::SizeChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SizeChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_LayoutUpdated(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LayoutUpdated(event_token token) = 0;
    virtual HRESULT __stdcall abi_FindName(hstring name, Windows::Foundation::IInspectable ** returnValue) = 0;
    virtual HRESULT __stdcall abi_SetBinding(Windows::UI::Xaml::IDependencyProperty * dp, Windows::UI::Xaml::Data::IBindingBase * binding) = 0;
};

struct __declspec(uuid("f19104be-422a-4904-a52f-ee72010429e5")) __declspec(novtable) IFrameworkElement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestedTheme(winrt::Windows::UI::Xaml::ElementTheme * value) = 0;
    virtual HRESULT __stdcall put_RequestedTheme(winrt::Windows::UI::Xaml::ElementTheme value) = 0;
    virtual HRESULT __stdcall add_DataContextChanged(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DataContextChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_GetBindingExpression(Windows::UI::Xaml::IDependencyProperty * dp, Windows::UI::Xaml::Data::IBindingExpression ** returnValue) = 0;
};

struct __declspec(uuid("c81c2720-5c52-4bbe-a199-2b1e34f00f70")) __declspec(novtable) IFrameworkElement3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall add_Loading(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Loading(event_token token) = 0;
};

struct __declspec(uuid("6b765bb3-fba3-4404-bdee-1a45d1ca5f21")) __declspec(novtable) IFrameworkElement4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowFocusOnInteraction(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowFocusOnInteraction(bool value) = 0;
    virtual HRESULT __stdcall get_FocusVisualMargin(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_FocusVisualMargin(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_FocusVisualSecondaryThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_FocusVisualSecondaryThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_FocusVisualPrimaryThickness(Windows::UI::Xaml::Thickness * value) = 0;
    virtual HRESULT __stdcall put_FocusVisualPrimaryThickness(Windows::UI::Xaml::Thickness value) = 0;
    virtual HRESULT __stdcall get_FocusVisualSecondaryBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_FocusVisualSecondaryBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_FocusVisualPrimaryBrush(Windows::UI::Xaml::Media::IBrush ** value) = 0;
    virtual HRESULT __stdcall put_FocusVisualPrimaryBrush(Windows::UI::Xaml::Media::IBrush * value) = 0;
    virtual HRESULT __stdcall get_AllowFocusWhenDisabled(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowFocusWhenDisabled(bool value) = 0;
};

struct __declspec(uuid("deaee126-03ca-4966-b576-604cce93b5e8")) __declspec(novtable) IFrameworkElementFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IFrameworkElement ** instance) = 0;
};

struct __declspec(uuid("da007e54-b3c2-4b9a-aa8e-d3f071262b97")) __declspec(novtable) IFrameworkElementOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_MeasureOverride(Windows::Foundation::Size availableSize, Windows::Foundation::Size * returnValue) = 0;
    virtual HRESULT __stdcall abi_ArrangeOverride(Windows::Foundation::Size finalSize, Windows::Foundation::Size * returnValue) = 0;
    virtual HRESULT __stdcall abi_OnApplyTemplate() = 0;
};

struct __declspec(uuid("cb5cd2b9-e3b4-458c-b64e-1434fd1bd88a")) __declspec(novtable) IFrameworkElementOverrides2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GoToElementStateCore(hstring stateName, bool useTransitions, bool * returnValue) = 0;
};

struct __declspec(uuid("48383032-fbeb-4f8a-aed2-ee21fb27a57b")) __declspec(novtable) IFrameworkElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TagProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_LanguageProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ActualWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ActualHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_WidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxWidthProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MinHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MaxHeightProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_HorizontalAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VerticalAlignmentProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_MarginProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_NameProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_DataContextProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_StyleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FlowDirectionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9695db02-c0d8-4fa2-b100-3fa2df8b9538")) __declspec(novtable) IFrameworkElementStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequestedThemeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("9c41b155-c5d8-4663-bff2-d8d54fb5dbb3")) __declspec(novtable) IFrameworkElementStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AllowFocusOnInteractionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusVisualMarginProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusVisualSecondaryThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusVisualPrimaryThicknessProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusVisualSecondaryBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_FocusVisualPrimaryBrushProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AllowFocusWhenDisabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("a1e254d8-a446-4a27-9a9d-a0f59e1258a5")) __declspec(novtable) IFrameworkTemplate : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("1a78a0a5-937d-46d4-832b-94ff14dab061")) __declspec(novtable) IFrameworkTemplateFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IFrameworkTemplate ** instance) = 0;
};

struct __declspec(uuid("ddba664b-b603-47aa-942d-3833174f0d80")) __declspec(novtable) IFrameworkView : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e3b077da-35ad-4b09-b5b2-27420041ba9f")) __declspec(novtable) IFrameworkViewSource : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("7a826ce1-07a0-4083-b6d1-b1d917b976ac")) __declspec(novtable) IGridLengthHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("9d457b9b-019f-4266-8872-215f198f6a9d")) __declspec(novtable) IGridLengthHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Auto(Windows::UI::Xaml::GridLength * value) = 0;
    virtual HRESULT __stdcall abi_FromPixels(double pixels, Windows::UI::Xaml::GridLength * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromValueAndType(double value, winrt::Windows::UI::Xaml::GridUnitType type, Windows::UI::Xaml::GridLength * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIsAbsolute(Windows::UI::Xaml::GridLength target, bool * value) = 0;
    virtual HRESULT __stdcall abi_GetIsAuto(Windows::UI::Xaml::GridLength target, bool * value) = 0;
    virtual HRESULT __stdcall abi_GetIsStar(Windows::UI::Xaml::GridLength target, bool * value) = 0;
    virtual HRESULT __stdcall abi_Equals(Windows::UI::Xaml::GridLength target, Windows::UI::Xaml::GridLength value, bool * returnValue) = 0;
};

struct __declspec(uuid("46d1fa8d-5149-4153-ba3c-b03e64ee531e")) __declspec(novtable) IMediaFailedRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ErrorTrace(hstring * value) = 0;
};

struct __declspec(uuid("727bdd92-64b0-49cf-a321-a9793e73e2e7")) __declspec(novtable) IPointHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("015aca75-76d8-4b7e-8a33-7d79204691ee")) __declspec(novtable) IPointHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromCoordinates(float x, float y, Windows::Foundation::Point * returnValue) = 0;
};

struct __declspec(uuid("814ef30d-8d18-448a-8644-f2cb51e70380")) __declspec(novtable) IPropertyMetadata : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DefaultValue(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_CreateDefaultValueCallback(Windows::UI::Xaml::CreateDefaultValueCallback ** value) = 0;
};

struct __declspec(uuid("c1b81cc0-57cd-4f2f-b0a9-e1801b28f76b")) __declspec(novtable) IPropertyMetadataFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstanceWithDefaultValue(Windows::Foundation::IInspectable * defaultValue, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IPropertyMetadata ** instance) = 0;
    virtual HRESULT __stdcall abi_CreateInstanceWithDefaultValueAndCallback(Windows::Foundation::IInspectable * defaultValue, Windows::UI::Xaml::PropertyChangedCallback * propertyChangedCallback, Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IPropertyMetadata ** instance) = 0;
};

struct __declspec(uuid("3b01077a-6e06-45e9-8b5c-af243458c062")) __declspec(novtable) IPropertyMetadataStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateWithDefaultValue(Windows::Foundation::IInspectable * defaultValue, Windows::UI::Xaml::IPropertyMetadata ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateWithDefaultValueAndCallback(Windows::Foundation::IInspectable * defaultValue, Windows::UI::Xaml::PropertyChangedCallback * propertyChangedCallback, Windows::UI::Xaml::IPropertyMetadata ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateWithFactory(Windows::UI::Xaml::CreateDefaultValueCallback * createDefaultValueCallback, Windows::UI::Xaml::IPropertyMetadata ** returnValue) = 0;
    virtual HRESULT __stdcall abi_CreateWithFactoryAndCallback(Windows::UI::Xaml::CreateDefaultValueCallback * createDefaultValueCallback, Windows::UI::Xaml::PropertyChangedCallback * propertyChangedCallback, Windows::UI::Xaml::IPropertyMetadata ** returnValue) = 0;
};

struct __declspec(uuid("300e5d8a-1ff3-4d2c-95ec-27f81debacb8")) __declspec(novtable) IPropertyPath : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Path(hstring * value) = 0;
};

struct __declspec(uuid("4e4cdf99-9826-4e56-847c-ca055f162905")) __declspec(novtable) IPropertyPathFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(hstring path, Windows::UI::Xaml::IPropertyPath ** instance) = 0;
};

struct __declspec(uuid("a38781e2-4bfb-4ee2-afe5-89f31b37478d")) __declspec(novtable) IRectHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5ee163e4-c17e-494f-b580-2f0574fc3a15")) __declspec(novtable) IRectHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Empty(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall abi_FromCoordinatesAndDimensions(float x, float y, float width, float height, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromPoints(Windows::Foundation::Point point1, Windows::Foundation::Point point2, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromLocationAndSize(Windows::Foundation::Point location, Windows::Foundation::Size size, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIsEmpty(Windows::Foundation::Rect target, bool * value) = 0;
    virtual HRESULT __stdcall abi_GetBottom(Windows::Foundation::Rect target, float * value) = 0;
    virtual HRESULT __stdcall abi_GetLeft(Windows::Foundation::Rect target, float * value) = 0;
    virtual HRESULT __stdcall abi_GetRight(Windows::Foundation::Rect target, float * value) = 0;
    virtual HRESULT __stdcall abi_GetTop(Windows::Foundation::Rect target, float * value) = 0;
    virtual HRESULT __stdcall abi_Contains(Windows::Foundation::Rect target, Windows::Foundation::Point point, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_Equals(Windows::Foundation::Rect target, Windows::Foundation::Rect value, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_Intersect(Windows::Foundation::Rect target, Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_UnionWithPoint(Windows::Foundation::Rect target, Windows::Foundation::Point point, Windows::Foundation::Rect * returnValue) = 0;
    virtual HRESULT __stdcall abi_UnionWithRect(Windows::Foundation::Rect target, Windows::Foundation::Rect rect, Windows::Foundation::Rect * returnValue) = 0;
};

struct __declspec(uuid("c1ea4f24-d6de-4191-8e3a-f48601f7489c")) __declspec(novtable) IResourceDictionary : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Source(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_Source(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_MergedDictionaries(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::ResourceDictionary> ** value) = 0;
    virtual HRESULT __stdcall get_ThemeDictionaries(Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> ** value) = 0;
};

struct __declspec(uuid("ea3639b5-31b7-4271-92c9-7c9584a91c22")) __declspec(novtable) IResourceDictionaryFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IResourceDictionary ** instance) = 0;
};

struct __declspec(uuid("a6b25818-43c1-4c70-865c-7bdd5a32e327")) __declspec(novtable) IRoutedEvent : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("5c985ac6-d802-4b38-a223-bf070c43fedf")) __declspec(novtable) IRoutedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OriginalSource(Windows::Foundation::IInspectable ** value) = 0;
};

struct __declspec(uuid("b61c4d87-70e5-412e-b520-1a41ee76bbf4")) __declspec(novtable) IRoutedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IRoutedEventArgs ** instance) = 0;
};

struct __declspec(uuid("a73ded29-b4ae-4a81-be85-e690ba0d3b6e")) __declspec(novtable) ISetter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Property(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall put_Property(Windows::UI::Xaml::IDependencyProperty * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Value(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("70169561-05b1-4fa3-9d53-8e0c8c747afc")) __declspec(novtable) ISetter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Target(Windows::UI::Xaml::ITargetPropertyPath ** value) = 0;
    virtual HRESULT __stdcall put_Target(Windows::UI::Xaml::ITargetPropertyPath * value) = 0;
};

struct __declspec(uuid("418be27c-2ac4-4f22-8097-dea3aeeb2fb3")) __declspec(novtable) ISetterBase : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSealed(bool * value) = 0;
};

struct __declspec(uuid("03c40ca8-909e-4117-811c-a4529496bdf1")) __declspec(novtable) ISetterBaseCollection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSealed(bool * value) = 0;
};

struct __declspec(uuid("81f8ad60-1ce8-469d-a667-16e37cef8ba9")) __declspec(novtable) ISetterBaseFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("d3ca3d42-09b1-49d5-8891-e7b5648e02a2")) __declspec(novtable) ISetterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::IDependencyProperty * targetProperty, Windows::Foundation::IInspectable * value, Windows::UI::Xaml::ISetter ** instance) = 0;
};

struct __declspec(uuid("d5312e60-5cc1-42a1-920c-1af46be2f986")) __declspec(novtable) ISizeChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PreviousSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_NewSize(Windows::Foundation::Size * value) = 0;
};

struct __declspec(uuid("e7225a94-5d03-4a03-ba94-967fc68fcefe")) __declspec(novtable) ISizeHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("6286c5b2-cf78-4915-aa40-76004a165f5e")) __declspec(novtable) ISizeHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Empty(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall abi_FromDimensions(float width, float height, Windows::Foundation::Size * returnValue) = 0;
    virtual HRESULT __stdcall abi_GetIsEmpty(Windows::Foundation::Size target, bool * value) = 0;
    virtual HRESULT __stdcall abi_Equals(Windows::Foundation::Size target, Windows::Foundation::Size value, bool * returnValue) = 0;
};

struct __declspec(uuid("67adef2e-d8d9-49f7-a1fd-2e35eedd23cd")) __declspec(novtable) IStateTrigger : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsActive(bool * value) = 0;
    virtual HRESULT __stdcall put_IsActive(bool value) = 0;
};

struct __declspec(uuid("48b20698-af06-466c-8052-93666dde0e49")) __declspec(novtable) IStateTriggerBase : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("970e2c4b-bfaf-47b0-be42-c1d711bb2e9f")) __declspec(novtable) IStateTriggerBaseFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IStateTriggerBase ** instance) = 0;
};

struct __declspec(uuid("3c41e253-8d14-4216-994c-f9930429f6e5")) __declspec(novtable) IStateTriggerBaseProtected : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetActive(bool IsActive) = 0;
};

struct __declspec(uuid("71e95c90-b3fe-4dd3-a8a8-44a2ce25e0b8")) __declspec(novtable) IStateTriggerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsActiveProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("c4a9f225-9db7-4a7d-b6d1-f74edb9293c2")) __declspec(novtable) IStyle : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsSealed(bool * value) = 0;
    virtual HRESULT __stdcall get_Setters(Windows::UI::Xaml::ISetterBaseCollection ** value) = 0;
    virtual HRESULT __stdcall get_TargetType(Windows::UI::Xaml::Interop::TypeName * value) = 0;
    virtual HRESULT __stdcall put_TargetType(Windows::UI::Xaml::Interop::TypeName value) = 0;
    virtual HRESULT __stdcall get_BasedOn(Windows::UI::Xaml::IStyle ** value) = 0;
    virtual HRESULT __stdcall put_BasedOn(Windows::UI::Xaml::IStyle * value) = 0;
    virtual HRESULT __stdcall abi_Seal() = 0;
};

struct __declspec(uuid("a36824e3-3d81-4ce5-aa51-8b410f602fcd")) __declspec(novtable) IStyleFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::Interop::TypeName targetType, Windows::UI::Xaml::IStyle ** instance) = 0;
};

struct __declspec(uuid("40740f8e-085f-4ced-be70-6f47acf15ad0")) __declspec(novtable) ITargetPropertyPath : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Path(Windows::UI::Xaml::IPropertyPath ** value) = 0;
    virtual HRESULT __stdcall put_Path(Windows::UI::Xaml::IPropertyPath * value) = 0;
    virtual HRESULT __stdcall get_Target(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall put_Target(Windows::Foundation::IInspectable * value) = 0;
};

struct __declspec(uuid("88eeccc8-99e2-4a44-9907-b44bc86e2bbe")) __declspec(novtable) ITargetPropertyPathFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::UI::Xaml::IDependencyProperty * targetProperty, Windows::UI::Xaml::ITargetPropertyPath ** instance) = 0;
};

struct __declspec(uuid("a86bae4b-1e8f-4eeb-9013-0b2838a97b34")) __declspec(novtable) IThicknessHelper : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("c0991a7c-070c-4da6-8784-01ca800eb73a")) __declspec(novtable) IThicknessHelperStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromLengths(double left, double top, double right, double bottom, Windows::UI::Xaml::Thickness * returnValue) = 0;
    virtual HRESULT __stdcall abi_FromUniformLength(double uniformLength, Windows::UI::Xaml::Thickness * returnValue) = 0;
};

struct __declspec(uuid("a2c0df02-63d5-4b46-9b83-0868d3079621")) __declspec(novtable) ITriggerAction : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("68d2c0b9-3289-414f-8f6e-c6b97aedda03")) __declspec(novtable) ITriggerActionFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("e7ea222f-dee6-4393-a8b2-8923d641f395")) __declspec(novtable) ITriggerBase : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("6a3b9e57-fc5d-42d0-8cb9-ca50667af746")) __declspec(novtable) ITriggerBaseFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("676d0be9-b65c-41c6-ba40-58cf87f201c1")) __declspec(novtable) IUIElement : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_DesiredSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_AllowDrop(bool * value) = 0;
    virtual HRESULT __stdcall put_AllowDrop(bool value) = 0;
    virtual HRESULT __stdcall get_Opacity(double * value) = 0;
    virtual HRESULT __stdcall put_Opacity(double value) = 0;
    virtual HRESULT __stdcall get_Clip(Windows::UI::Xaml::Media::IRectangleGeometry ** value) = 0;
    virtual HRESULT __stdcall put_Clip(Windows::UI::Xaml::Media::IRectangleGeometry * value) = 0;
    virtual HRESULT __stdcall get_RenderTransform(Windows::UI::Xaml::Media::ITransform ** value) = 0;
    virtual HRESULT __stdcall put_RenderTransform(Windows::UI::Xaml::Media::ITransform * value) = 0;
    virtual HRESULT __stdcall get_Projection(Windows::UI::Xaml::Media::IProjection ** value) = 0;
    virtual HRESULT __stdcall put_Projection(Windows::UI::Xaml::Media::IProjection * value) = 0;
    virtual HRESULT __stdcall get_RenderTransformOrigin(Windows::Foundation::Point * value) = 0;
    virtual HRESULT __stdcall put_RenderTransformOrigin(Windows::Foundation::Point value) = 0;
    virtual HRESULT __stdcall get_IsHitTestVisible(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHitTestVisible(bool value) = 0;
    virtual HRESULT __stdcall get_Visibility(winrt::Windows::UI::Xaml::Visibility * value) = 0;
    virtual HRESULT __stdcall put_Visibility(winrt::Windows::UI::Xaml::Visibility value) = 0;
    virtual HRESULT __stdcall get_RenderSize(Windows::Foundation::Size * value) = 0;
    virtual HRESULT __stdcall get_UseLayoutRounding(bool * value) = 0;
    virtual HRESULT __stdcall put_UseLayoutRounding(bool value) = 0;
    virtual HRESULT __stdcall get_Transitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> ** value) = 0;
    virtual HRESULT __stdcall put_Transitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Media::Animation::Transition> * value) = 0;
    virtual HRESULT __stdcall get_CacheMode(Windows::UI::Xaml::Media::ICacheMode ** value) = 0;
    virtual HRESULT __stdcall put_CacheMode(Windows::UI::Xaml::Media::ICacheMode * value) = 0;
    virtual HRESULT __stdcall get_IsTapEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsTapEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsDoubleTapEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsDoubleTapEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsRightTapEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsRightTapEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_IsHoldingEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsHoldingEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ManipulationMode(winrt::Windows::UI::Xaml::Input::ManipulationModes * value) = 0;
    virtual HRESULT __stdcall put_ManipulationMode(winrt::Windows::UI::Xaml::Input::ManipulationModes value) = 0;
    virtual HRESULT __stdcall get_PointerCaptures(Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Input::Pointer> ** value) = 0;
    virtual HRESULT __stdcall add_KeyUp(Windows::UI::Xaml::Input::KeyEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_KeyUp(event_token token) = 0;
    virtual HRESULT __stdcall add_KeyDown(Windows::UI::Xaml::Input::KeyEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_KeyDown(event_token token) = 0;
    virtual HRESULT __stdcall add_GotFocus(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_GotFocus(event_token token) = 0;
    virtual HRESULT __stdcall add_LostFocus(Windows::UI::Xaml::RoutedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_LostFocus(event_token token) = 0;
    virtual HRESULT __stdcall add_DragEnter(Windows::UI::Xaml::DragEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragEnter(event_token token) = 0;
    virtual HRESULT __stdcall add_DragLeave(Windows::UI::Xaml::DragEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragLeave(event_token token) = 0;
    virtual HRESULT __stdcall add_DragOver(Windows::UI::Xaml::DragEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragOver(event_token token) = 0;
    virtual HRESULT __stdcall add_Drop(Windows::UI::Xaml::DragEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Drop(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerPressed(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerPressed(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerMoved(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerMoved(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerReleased(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerReleased(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerEntered(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerEntered(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerExited(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerExited(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerCaptureLost(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerCaptureLost(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerCanceled(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerCanceled(event_token token) = 0;
    virtual HRESULT __stdcall add_PointerWheelChanged(Windows::UI::Xaml::Input::PointerEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_PointerWheelChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_Tapped(Windows::UI::Xaml::Input::TappedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Tapped(event_token token) = 0;
    virtual HRESULT __stdcall add_DoubleTapped(Windows::UI::Xaml::Input::DoubleTappedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DoubleTapped(event_token token) = 0;
    virtual HRESULT __stdcall add_Holding(Windows::UI::Xaml::Input::HoldingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Holding(event_token token) = 0;
    virtual HRESULT __stdcall add_RightTapped(Windows::UI::Xaml::Input::RightTappedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_RightTapped(event_token token) = 0;
    virtual HRESULT __stdcall add_ManipulationStarting(Windows::UI::Xaml::Input::ManipulationStartingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ManipulationStarting(event_token token) = 0;
    virtual HRESULT __stdcall add_ManipulationInertiaStarting(Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ManipulationInertiaStarting(event_token token) = 0;
    virtual HRESULT __stdcall add_ManipulationStarted(Windows::UI::Xaml::Input::ManipulationStartedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ManipulationStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_ManipulationDelta(Windows::UI::Xaml::Input::ManipulationDeltaEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ManipulationDelta(event_token token) = 0;
    virtual HRESULT __stdcall add_ManipulationCompleted(Windows::UI::Xaml::Input::ManipulationCompletedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ManipulationCompleted(event_token token) = 0;
    virtual HRESULT __stdcall abi_Measure(Windows::Foundation::Size availableSize) = 0;
    virtual HRESULT __stdcall abi_Arrange(Windows::Foundation::Rect finalRect) = 0;
    virtual HRESULT __stdcall abi_CapturePointer(Windows::UI::Xaml::Input::IPointer * value, bool * returnValue) = 0;
    virtual HRESULT __stdcall abi_ReleasePointerCapture(Windows::UI::Xaml::Input::IPointer * value) = 0;
    virtual HRESULT __stdcall abi_ReleasePointerCaptures() = 0;
    virtual HRESULT __stdcall abi_AddHandler(Windows::UI::Xaml::IRoutedEvent * routedEvent, Windows::Foundation::IInspectable * handler, bool handledEventsToo) = 0;
    virtual HRESULT __stdcall abi_RemoveHandler(Windows::UI::Xaml::IRoutedEvent * routedEvent, Windows::Foundation::IInspectable * handler) = 0;
    virtual HRESULT __stdcall abi_TransformToVisual(Windows::UI::Xaml::IUIElement * visual, Windows::UI::Xaml::Media::IGeneralTransform ** returnValue) = 0;
    virtual HRESULT __stdcall abi_InvalidateMeasure() = 0;
    virtual HRESULT __stdcall abi_InvalidateArrange() = 0;
    virtual HRESULT __stdcall abi_UpdateLayout() = 0;
};

struct __declspec(uuid("676d0bf9-b66c-41d6-ba50-58cf87f201d1")) __declspec(novtable) IUIElement2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompositeMode(winrt::Windows::UI::Xaml::Media::ElementCompositeMode * value) = 0;
    virtual HRESULT __stdcall put_CompositeMode(winrt::Windows::UI::Xaml::Media::ElementCompositeMode value) = 0;
    virtual HRESULT __stdcall abi_CancelDirectManipulations(bool * returnValue) = 0;
};

struct __declspec(uuid("bc2b28f1-26f2-4aab-b256-3b5350881e37")) __declspec(novtable) IUIElement3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Transform3D(Windows::UI::Xaml::Media::Media3D::ITransform3D ** value) = 0;
    virtual HRESULT __stdcall put_Transform3D(Windows::UI::Xaml::Media::Media3D::ITransform3D * value) = 0;
    virtual HRESULT __stdcall get_CanDrag(bool * value) = 0;
    virtual HRESULT __stdcall put_CanDrag(bool value) = 0;
    virtual HRESULT __stdcall add_DragStarting(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DragStarting(event_token token) = 0;
    virtual HRESULT __stdcall add_DropCompleted(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_DropCompleted(event_token token) = 0;
    virtual HRESULT __stdcall abi_StartDragAsync(Windows::UI::Input::IPointerPoint * pointerPoint, Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> ** returnValue) = 0;
};

struct __declspec(uuid("69145cd4-199a-4657-9e57-e99e8f136712")) __declspec(novtable) IUIElement4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContextFlyout(Windows::UI::Xaml::Controls::Primitives::IFlyoutBase ** value) = 0;
    virtual HRESULT __stdcall put_ContextFlyout(Windows::UI::Xaml::Controls::Primitives::IFlyoutBase * value) = 0;
    virtual HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvoked(bool * value) = 0;
    virtual HRESULT __stdcall put_ExitDisplayModeOnAccessKeyInvoked(bool value) = 0;
    virtual HRESULT __stdcall get_IsAccessKeyScope(bool * value) = 0;
    virtual HRESULT __stdcall put_IsAccessKeyScope(bool value) = 0;
    virtual HRESULT __stdcall get_AccessKeyScopeOwner(Windows::UI::Xaml::IDependencyObject ** value) = 0;
    virtual HRESULT __stdcall put_AccessKeyScopeOwner(Windows::UI::Xaml::IDependencyObject * value) = 0;
    virtual HRESULT __stdcall get_AccessKey(hstring * value) = 0;
    virtual HRESULT __stdcall put_AccessKey(hstring value) = 0;
    virtual HRESULT __stdcall add_ContextRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_ContextCanceled(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_ContextCanceled(event_token token) = 0;
    virtual HRESULT __stdcall add_AccessKeyDisplayRequested(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AccessKeyDisplayRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_AccessKeyDisplayDismissed(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AccessKeyDisplayDismissed(event_token token) = 0;
    virtual HRESULT __stdcall add_AccessKeyInvoked(Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AccessKeyInvoked(event_token token) = 0;
};

struct __declspec(uuid("b9ee93fe-a338-419f-ac32-91dcaadf5d08")) __declspec(novtable) IUIElementFactory : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("608d2f1d-7858-4aeb-89e4-b54e2c7ed3d3")) __declspec(novtable) IUIElementOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_OnCreateAutomationPeer(Windows::UI::Xaml::Automation::Peers::IAutomationPeer ** returnValue) = 0;
    virtual HRESULT __stdcall abi_OnDisconnectVisualChildren() = 0;
    virtual HRESULT __stdcall abi_FindSubElementsForTouchTargeting(Windows::Foundation::Point point, Windows::Foundation::Rect boundingRect, Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> ** returnValue) = 0;
};

struct __declspec(uuid("58d3573b-f52c-45be-988b-a5869564873c")) __declspec(novtable) IUIElementStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_KeyDownEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_KeyUpEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerEnteredEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerPressedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerMovedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerReleasedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerExitedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerCaptureLostEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerCanceledEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_PointerWheelChangedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_TappedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_DoubleTappedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_HoldingEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_RightTappedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationStartingEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationInertiaStartingEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationStartedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationDeltaEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationCompletedEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_DragEnterEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_DragLeaveEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_DragOverEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_DropEvent(Windows::UI::Xaml::IRoutedEvent ** value) = 0;
    virtual HRESULT __stdcall get_AllowDropProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_OpacityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ClipProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RenderTransformProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ProjectionProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_RenderTransformOriginProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsHitTestVisibleProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_VisibilityProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_UseLayoutRoundingProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_TransitionsProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CacheModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsTapEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsDoubleTapEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsRightTapEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsHoldingEnabledProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ManipulationModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_PointerCapturesProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("58d3574b-f53c-45be-989b-a5869564874c")) __declspec(novtable) IUIElementStatics2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CompositeModeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("d1f87ade-eca1-4561-a32b-64601b4e0597")) __declspec(novtable) IUIElementStatics3 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Transform3DProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_CanDragProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_TryStartDirectManipulation(Windows::UI::Xaml::Input::IPointer * value, bool * returnValue) = 0;
};

struct __declspec(uuid("1d157d61-16af-411f-b774-272375a4ac2c")) __declspec(novtable) IUIElementStatics4 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContextFlyoutProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_ExitDisplayModeOnAccessKeyInvokedProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_IsAccessKeyScopeProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AccessKeyScopeOwnerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall get_AccessKeyProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
};

struct __declspec(uuid("7230269c-054e-4cf3-86c5-be90eb6863d5")) __declspec(novtable) IUnhandledExceptionEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Exception(HRESULT * value) = 0;
    virtual HRESULT __stdcall get_Message(hstring * value) = 0;
    virtual HRESULT __stdcall get_Handled(bool * value) = 0;
    virtual HRESULT __stdcall put_Handled(bool value) = 0;
};

struct __declspec(uuid("6320affc-c31a-4450-afde-f6ea7bd1f586")) __declspec(novtable) IVisualState : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Storyboard(Windows::UI::Xaml::Media::Animation::IStoryboard ** value) = 0;
    virtual HRESULT __stdcall put_Storyboard(Windows::UI::Xaml::Media::Animation::IStoryboard * value) = 0;
};

struct __declspec(uuid("0fa0f896-64c0-45fb-8d24-fb83298c0d93")) __declspec(novtable) IVisualState2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Setters(Windows::UI::Xaml::ISetterBaseCollection ** value) = 0;
    virtual HRESULT __stdcall get_StateTriggers(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::StateTriggerBase> ** value) = 0;
};

struct __declspec(uuid("fe216ab1-f31f-4791-8989-c70e1d9b59ff")) __declspec(novtable) IVisualStateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OldState(Windows::UI::Xaml::IVisualState ** value) = 0;
    virtual HRESULT __stdcall put_OldState(Windows::UI::Xaml::IVisualState * value) = 0;
    virtual HRESULT __stdcall get_NewState(Windows::UI::Xaml::IVisualState ** value) = 0;
    virtual HRESULT __stdcall put_NewState(Windows::UI::Xaml::IVisualState * value) = 0;
    virtual HRESULT __stdcall get_Control(Windows::UI::Xaml::Controls::IControl ** value) = 0;
    virtual HRESULT __stdcall put_Control(Windows::UI::Xaml::Controls::IControl * value) = 0;
};

struct __declspec(uuid("e4f9d9a4-e028-44de-9b15-4929ae0a26c2")) __declspec(novtable) IVisualStateGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Transitions(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualTransition> ** value) = 0;
    virtual HRESULT __stdcall get_States(Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualState> ** value) = 0;
    virtual HRESULT __stdcall get_CurrentState(Windows::UI::Xaml::IVisualState ** value) = 0;
    virtual HRESULT __stdcall add_CurrentStateChanged(Windows::UI::Xaml::VisualStateChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentStateChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_CurrentStateChanging(Windows::UI::Xaml::VisualStateChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CurrentStateChanging(event_token token) = 0;
};

struct __declspec(uuid("6fda9f9a-6fab-4112-9258-1006a3c3476e")) __declspec(novtable) IVisualStateManager : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("85e598fd-a575-47b6-9e30-383cd08585f2")) __declspec(novtable) IVisualStateManagerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IVisualStateManager ** instance) = 0;
};

struct __declspec(uuid("4a66910e-7979-43c8-8ff4-ec6122750006")) __declspec(novtable) IVisualStateManagerOverrides : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GoToStateCore(Windows::UI::Xaml::Controls::IControl * control, Windows::UI::Xaml::IFrameworkElement * templateRoot, hstring stateName, Windows::UI::Xaml::IVisualStateGroup * group, Windows::UI::Xaml::IVisualState * state, bool useTransitions, bool * returnValue) = 0;
};

struct __declspec(uuid("4b3b8640-b0b7-404c-9ef4-d949640e245d")) __declspec(novtable) IVisualStateManagerProtected : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RaiseCurrentStateChanging(Windows::UI::Xaml::IVisualStateGroup * stateGroup, Windows::UI::Xaml::IVisualState * oldState, Windows::UI::Xaml::IVisualState * newState, Windows::UI::Xaml::Controls::IControl * control) = 0;
    virtual HRESULT __stdcall abi_RaiseCurrentStateChanged(Windows::UI::Xaml::IVisualStateGroup * stateGroup, Windows::UI::Xaml::IVisualState * oldState, Windows::UI::Xaml::IVisualState * newState, Windows::UI::Xaml::Controls::IControl * control) = 0;
};

struct __declspec(uuid("01d0e9e0-d713-414e-a74e-e63ec7ac8c3d")) __declspec(novtable) IVisualStateManagerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetVisualStateGroups(Windows::UI::Xaml::IFrameworkElement * obj, Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> ** value) = 0;
    virtual HRESULT __stdcall get_CustomVisualStateManagerProperty(Windows::UI::Xaml::IDependencyProperty ** value) = 0;
    virtual HRESULT __stdcall abi_GetCustomVisualStateManager(Windows::UI::Xaml::IFrameworkElement * obj, Windows::UI::Xaml::IVisualStateManager ** value) = 0;
    virtual HRESULT __stdcall abi_SetCustomVisualStateManager(Windows::UI::Xaml::IFrameworkElement * obj, Windows::UI::Xaml::IVisualStateManager * value) = 0;
    virtual HRESULT __stdcall abi_GoToState(Windows::UI::Xaml::Controls::IControl * control, hstring stateName, bool useTransitions, bool * returnValue) = 0;
};

struct __declspec(uuid("55c5905e-2bc7-400d-aaa4-1a2981491ee0")) __declspec(novtable) IVisualTransition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GeneratedDuration(Windows::UI::Xaml::Duration * value) = 0;
    virtual HRESULT __stdcall put_GeneratedDuration(Windows::UI::Xaml::Duration value) = 0;
    virtual HRESULT __stdcall get_GeneratedEasingFunction(Windows::UI::Xaml::Media::Animation::IEasingFunctionBase ** value) = 0;
    virtual HRESULT __stdcall put_GeneratedEasingFunction(Windows::UI::Xaml::Media::Animation::IEasingFunctionBase * value) = 0;
    virtual HRESULT __stdcall get_To(hstring * value) = 0;
    virtual HRESULT __stdcall put_To(hstring value) = 0;
    virtual HRESULT __stdcall get_From(hstring * value) = 0;
    virtual HRESULT __stdcall put_From(hstring value) = 0;
    virtual HRESULT __stdcall get_Storyboard(Windows::UI::Xaml::Media::Animation::IStoryboard ** value) = 0;
    virtual HRESULT __stdcall put_Storyboard(Windows::UI::Xaml::Media::Animation::IStoryboard * value) = 0;
};

struct __declspec(uuid("ea75864f-d1e0-4dae-b429-89fc322724f4")) __declspec(novtable) IVisualTransitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateInstance(Windows::Foundation::IInspectable * outer, Windows::Foundation::IInspectable ** inner, Windows::UI::Xaml::IVisualTransition ** instance) = 0;
};

struct __declspec(uuid("3276167d-c9f6-462d-9de2-ae4c1fd8c2e5")) __declspec(novtable) IWindow : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Bounds(Windows::Foundation::Rect * value) = 0;
    virtual HRESULT __stdcall get_Visible(bool * value) = 0;
    virtual HRESULT __stdcall get_Content(Windows::UI::Xaml::IUIElement ** value) = 0;
    virtual HRESULT __stdcall put_Content(Windows::UI::Xaml::IUIElement * value) = 0;
    virtual HRESULT __stdcall get_CoreWindow(Windows::UI::Core::ICoreWindow ** value) = 0;
    virtual HRESULT __stdcall get_Dispatcher(Windows::UI::Core::ICoreDispatcher ** value) = 0;
    virtual HRESULT __stdcall add_Activated(Windows::UI::Xaml::WindowActivatedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Activated(event_token token) = 0;
    virtual HRESULT __stdcall add_Closed(Windows::UI::Xaml::WindowClosedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Closed(event_token token) = 0;
    virtual HRESULT __stdcall add_SizeChanged(Windows::UI::Xaml::WindowSizeChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SizeChanged(event_token token) = 0;
    virtual HRESULT __stdcall add_VisibilityChanged(Windows::UI::Xaml::WindowVisibilityChangedEventHandler * value, event_token * token) = 0;
    virtual HRESULT __stdcall remove_VisibilityChanged(event_token token) = 0;
    virtual HRESULT __stdcall abi_Activate() = 0;
    virtual HRESULT __stdcall abi_Close() = 0;
};

struct __declspec(uuid("d384759f-34f6-4482-8435-f552f9b24cc8")) __declspec(novtable) IWindow2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetTitleBar(Windows::UI::Xaml::IUIElement * value) = 0;
};

struct __declspec(uuid("31b71470-feff-4654-af48-9b398ab5772b")) __declspec(novtable) IWindowCreatedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Window(Windows::UI::Xaml::IWindow ** value) = 0;
};

struct __declspec(uuid("93328409-4ea1-4afa-83dc-0c4e73e88bb1")) __declspec(novtable) IWindowStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Current(Windows::UI::Xaml::IWindow ** value) = 0;
};

struct __declspec(uuid("aaad5dad-4fc6-4aa4-b7cf-877e36ada4f6")) __declspec(novtable) LeavingBackgroundEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::ApplicationModel::ILeavingBackgroundEventArgs * e) = 0;
};

struct __declspec(uuid("5a9f8a25-d142-44a4-8231-fd676724f29b")) __declspec(novtable) PropertyChangedCallback : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::UI::Xaml::IDependencyObject * d, Windows::UI::Xaml::IDependencyPropertyChangedEventArgs * e) = 0;
};

struct __declspec(uuid("a856e674-b0b6-4bc3-bba8-1ba06e40d4b5")) __declspec(novtable) RoutedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IRoutedEventArgs * e) = 0;
};

struct __declspec(uuid("1115b13c-25d2-480b-89dc-eb3dcbd6b7fa")) __declspec(novtable) SizeChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::ISizeChangedEventArgs * e) = 0;
};

struct __declspec(uuid("23429465-e36a-40e2-b139-a4704602a6e1")) __declspec(novtable) SuspendingEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::ApplicationModel::ISuspendingEventArgs * e) = 0;
};

struct __declspec(uuid("9274e6bd-49a1-4958-beee-d0e19587b6e3")) __declspec(novtable) UnhandledExceptionEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IUnhandledExceptionEventArgs * e) = 0;
};

struct __declspec(uuid("e6d5bbd5-e029-43a6-b36d-84a81042d774")) __declspec(novtable) VisualStateChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Xaml::IVisualStateChangedEventArgs * e) = 0;
};

struct __declspec(uuid("18026348-8619-4c7b-b534-ced45d9de219")) __declspec(novtable) WindowActivatedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Core::IWindowActivatedEventArgs * e) = 0;
};

struct __declspec(uuid("0db89161-20d7-45df-9122-ba89576703ba")) __declspec(novtable) WindowClosedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Core::ICoreWindowEventArgs * e) = 0;
};

struct __declspec(uuid("5c21c742-2ced-4fd9-ba38-7118d40e966b")) __declspec(novtable) WindowSizeChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Core::IWindowSizeChangedEventArgs * e) = 0;
};

struct __declspec(uuid("10406ad6-b090-4a4a-b2ad-d682df27130f")) __declspec(novtable) WindowVisibilityChangedEventHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Foundation::IInspectable * sender, Windows::UI::Core::IVisibilityChangedEventArgs * e) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::UI::Xaml::AdaptiveTrigger> { using default_interface = Windows::UI::Xaml::IAdaptiveTrigger; };
template <> struct traits<Windows::UI::Xaml::Application> { using default_interface = Windows::UI::Xaml::IApplication; };
template <> struct traits<Windows::UI::Xaml::ApplicationInitializationCallbackParams> { using default_interface = Windows::UI::Xaml::IApplicationInitializationCallbackParams; };
template <> struct traits<Windows::UI::Xaml::BindingFailedEventArgs> { using default_interface = Windows::UI::Xaml::IBindingFailedEventArgs; };
template <> struct traits<Windows::UI::Xaml::CornerRadiusHelper> { using default_interface = Windows::UI::Xaml::ICornerRadiusHelper; };
template <> struct traits<Windows::UI::Xaml::DataContextChangedEventArgs> { using default_interface = Windows::UI::Xaml::IDataContextChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::DataTemplate> { using default_interface = Windows::UI::Xaml::IDataTemplate; };
template <> struct traits<Windows::UI::Xaml::DataTemplateKey> { using default_interface = Windows::UI::Xaml::IDataTemplateKey; };
template <> struct traits<Windows::UI::Xaml::DebugSettings> { using default_interface = Windows::UI::Xaml::IDebugSettings; };
template <> struct traits<Windows::UI::Xaml::DependencyObject> { using default_interface = Windows::UI::Xaml::IDependencyObject; };
template <> struct traits<Windows::UI::Xaml::DependencyObjectCollection> { using default_interface = Windows::Foundation::Collections::IObservableVector<Windows::UI::Xaml::DependencyObject>; };
template <> struct traits<Windows::UI::Xaml::DependencyProperty> { using default_interface = Windows::UI::Xaml::IDependencyProperty; };
template <> struct traits<Windows::UI::Xaml::DependencyPropertyChangedEventArgs> { using default_interface = Windows::UI::Xaml::IDependencyPropertyChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::DispatcherTimer> { using default_interface = Windows::UI::Xaml::IDispatcherTimer; };
template <> struct traits<Windows::UI::Xaml::DragEventArgs> { using default_interface = Windows::UI::Xaml::IDragEventArgs; };
template <> struct traits<Windows::UI::Xaml::DragOperationDeferral> { using default_interface = Windows::UI::Xaml::IDragOperationDeferral; };
template <> struct traits<Windows::UI::Xaml::DragStartingEventArgs> { using default_interface = Windows::UI::Xaml::IDragStartingEventArgs; };
template <> struct traits<Windows::UI::Xaml::DragUI> { using default_interface = Windows::UI::Xaml::IDragUI; };
template <> struct traits<Windows::UI::Xaml::DragUIOverride> { using default_interface = Windows::UI::Xaml::IDragUIOverride; };
template <> struct traits<Windows::UI::Xaml::DropCompletedEventArgs> { using default_interface = Windows::UI::Xaml::IDropCompletedEventArgs; };
template <> struct traits<Windows::UI::Xaml::DurationHelper> { using default_interface = Windows::UI::Xaml::IDurationHelper; };
template <> struct traits<Windows::UI::Xaml::ElementSoundPlayer> { using default_interface = Windows::UI::Xaml::IElementSoundPlayer; };
template <> struct traits<Windows::UI::Xaml::EventTrigger> { using default_interface = Windows::UI::Xaml::IEventTrigger; };
template <> struct traits<Windows::UI::Xaml::ExceptionRoutedEventArgs> { using default_interface = Windows::UI::Xaml::IExceptionRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::FrameworkElement> { using default_interface = Windows::UI::Xaml::IFrameworkElement; };
template <> struct traits<Windows::UI::Xaml::FrameworkTemplate> { using default_interface = Windows::UI::Xaml::IFrameworkTemplate; };
template <> struct traits<Windows::UI::Xaml::FrameworkView> { using default_interface = Windows::UI::Xaml::IFrameworkView; };
template <> struct traits<Windows::UI::Xaml::FrameworkViewSource> { using default_interface = Windows::UI::Xaml::IFrameworkViewSource; };
template <> struct traits<Windows::UI::Xaml::GridLengthHelper> { using default_interface = Windows::UI::Xaml::IGridLengthHelper; };
template <> struct traits<Windows::UI::Xaml::MediaFailedRoutedEventArgs> { using default_interface = Windows::UI::Xaml::IMediaFailedRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::PointHelper> { using default_interface = Windows::UI::Xaml::IPointHelper; };
template <> struct traits<Windows::UI::Xaml::PropertyMetadata> { using default_interface = Windows::UI::Xaml::IPropertyMetadata; };
template <> struct traits<Windows::UI::Xaml::PropertyPath> { using default_interface = Windows::UI::Xaml::IPropertyPath; };
template <> struct traits<Windows::UI::Xaml::RectHelper> { using default_interface = Windows::UI::Xaml::IRectHelper; };
template <> struct traits<Windows::UI::Xaml::ResourceDictionary> { using default_interface = Windows::UI::Xaml::IResourceDictionary; };
template <> struct traits<Windows::UI::Xaml::RoutedEvent> { using default_interface = Windows::UI::Xaml::IRoutedEvent; };
template <> struct traits<Windows::UI::Xaml::RoutedEventArgs> { using default_interface = Windows::UI::Xaml::IRoutedEventArgs; };
template <> struct traits<Windows::UI::Xaml::Setter> { using default_interface = Windows::UI::Xaml::ISetter; };
template <> struct traits<Windows::UI::Xaml::SetterBase> { using default_interface = Windows::UI::Xaml::ISetterBase; };
template <> struct traits<Windows::UI::Xaml::SetterBaseCollection> { using default_interface = Windows::UI::Xaml::ISetterBaseCollection; };
template <> struct traits<Windows::UI::Xaml::SizeChangedEventArgs> { using default_interface = Windows::UI::Xaml::ISizeChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::SizeHelper> { using default_interface = Windows::UI::Xaml::ISizeHelper; };
template <> struct traits<Windows::UI::Xaml::StateTrigger> { using default_interface = Windows::UI::Xaml::IStateTrigger; };
template <> struct traits<Windows::UI::Xaml::StateTriggerBase> { using default_interface = Windows::UI::Xaml::IStateTriggerBase; };
template <> struct traits<Windows::UI::Xaml::Style> { using default_interface = Windows::UI::Xaml::IStyle; };
template <> struct traits<Windows::UI::Xaml::TargetPropertyPath> { using default_interface = Windows::UI::Xaml::ITargetPropertyPath; };
template <> struct traits<Windows::UI::Xaml::ThicknessHelper> { using default_interface = Windows::UI::Xaml::IThicknessHelper; };
template <> struct traits<Windows::UI::Xaml::TriggerAction> { using default_interface = Windows::UI::Xaml::ITriggerAction; };
template <> struct traits<Windows::UI::Xaml::TriggerActionCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerAction>; };
template <> struct traits<Windows::UI::Xaml::TriggerBase> { using default_interface = Windows::UI::Xaml::ITriggerBase; };
template <> struct traits<Windows::UI::Xaml::TriggerCollection> { using default_interface = Windows::Foundation::Collections::IVector<Windows::UI::Xaml::TriggerBase>; };
template <> struct traits<Windows::UI::Xaml::UIElement> { using default_interface = Windows::UI::Xaml::IUIElement; };
template <> struct traits<Windows::UI::Xaml::UnhandledExceptionEventArgs> { using default_interface = Windows::UI::Xaml::IUnhandledExceptionEventArgs; };
template <> struct traits<Windows::UI::Xaml::VisualState> { using default_interface = Windows::UI::Xaml::IVisualState; };
template <> struct traits<Windows::UI::Xaml::VisualStateChangedEventArgs> { using default_interface = Windows::UI::Xaml::IVisualStateChangedEventArgs; };
template <> struct traits<Windows::UI::Xaml::VisualStateGroup> { using default_interface = Windows::UI::Xaml::IVisualStateGroup; };
template <> struct traits<Windows::UI::Xaml::VisualStateManager> { using default_interface = Windows::UI::Xaml::IVisualStateManager; };
template <> struct traits<Windows::UI::Xaml::VisualTransition> { using default_interface = Windows::UI::Xaml::IVisualTransition; };
template <> struct traits<Windows::UI::Xaml::Window> { using default_interface = Windows::UI::Xaml::IWindow; };
template <> struct traits<Windows::UI::Xaml::WindowCreatedEventArgs> { using default_interface = Windows::UI::Xaml::IWindowCreatedEventArgs; };

}

namespace Windows::UI::Xaml {

template <typename D>
struct WINRT_EBO impl_IAdaptiveTrigger
{
    double MinWindowWidth() const;
    void MinWindowWidth(double value) const;
    double MinWindowHeight() const;
    void MinWindowHeight(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveTriggerFactory
{
    Windows::UI::Xaml::AdaptiveTrigger CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IAdaptiveTriggerStatics
{
    Windows::UI::Xaml::DependencyProperty MinWindowWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MinWindowHeightProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IApplication
{
    Windows::UI::Xaml::ResourceDictionary Resources() const;
    void Resources(const Windows::UI::Xaml::ResourceDictionary & value) const;
    Windows::UI::Xaml::DebugSettings DebugSettings() const;
    Windows::UI::Xaml::ApplicationTheme RequestedTheme() const;
    void RequestedTheme(Windows::UI::Xaml::ApplicationTheme value) const;
    event_token UnhandledException(const Windows::UI::Xaml::UnhandledExceptionEventHandler & value) const;
    using UnhandledException_revoker = event_revoker<IApplication>;
    UnhandledException_revoker UnhandledException(auto_revoke_t, const Windows::UI::Xaml::UnhandledExceptionEventHandler & value) const;
    void UnhandledException(event_token token) const;
    event_token Suspending(const Windows::UI::Xaml::SuspendingEventHandler & value) const;
    using Suspending_revoker = event_revoker<IApplication>;
    Suspending_revoker Suspending(auto_revoke_t, const Windows::UI::Xaml::SuspendingEventHandler & value) const;
    void Suspending(event_token token) const;
    event_token Resuming(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Resuming_revoker = event_revoker<IApplication>;
    Resuming_revoker Resuming(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Resuming(event_token token) const;
    void Exit() const;
};

template <typename D>
struct WINRT_EBO impl_IApplication2
{
    Windows::UI::Xaml::FocusVisualKind FocusVisualKind() const;
    void FocusVisualKind(Windows::UI::Xaml::FocusVisualKind value) const;
    Windows::UI::Xaml::ApplicationRequiresPointerMode RequiresPointerMode() const;
    void RequiresPointerMode(Windows::UI::Xaml::ApplicationRequiresPointerMode value) const;
    event_token LeavingBackground(const Windows::UI::Xaml::LeavingBackgroundEventHandler & value) const;
    using LeavingBackground_revoker = event_revoker<IApplication2>;
    LeavingBackground_revoker LeavingBackground(auto_revoke_t, const Windows::UI::Xaml::LeavingBackgroundEventHandler & value) const;
    void LeavingBackground(event_token token) const;
    event_token EnteredBackground(const Windows::UI::Xaml::EnteredBackgroundEventHandler & value) const;
    using EnteredBackground_revoker = event_revoker<IApplication2>;
    EnteredBackground_revoker EnteredBackground(auto_revoke_t, const Windows::UI::Xaml::EnteredBackgroundEventHandler & value) const;
    void EnteredBackground(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationFactory
{
    Windows::UI::Xaml::Application CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationInitializationCallbackParams
{
};

template <typename D>
struct WINRT_EBO impl_IApplicationOverrides
{
    void OnActivated(const Windows::ApplicationModel::Activation::IActivatedEventArgs & args) const;
    void OnLaunched(const Windows::ApplicationModel::Activation::LaunchActivatedEventArgs & args) const;
    void OnFileActivated(const Windows::ApplicationModel::Activation::FileActivatedEventArgs & args) const;
    void OnSearchActivated(const Windows::ApplicationModel::Activation::SearchActivatedEventArgs & args) const;
    void OnShareTargetActivated(const Windows::ApplicationModel::Activation::ShareTargetActivatedEventArgs & args) const;
    void OnFileOpenPickerActivated(const Windows::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs & args) const;
    void OnFileSavePickerActivated(const Windows::ApplicationModel::Activation::FileSavePickerActivatedEventArgs & args) const;
    void OnCachedFileUpdaterActivated(const Windows::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs & args) const;
    void OnWindowCreated(const Windows::UI::Xaml::WindowCreatedEventArgs & args) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationOverrides2
{
    void OnBackgroundActivated(const Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs & args) const;
};

template <typename D>
struct WINRT_EBO impl_IApplicationStatics
{
    Windows::UI::Xaml::Application Current() const;
    void Start(const Windows::UI::Xaml::ApplicationInitializationCallback & callback) const;
    void LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator) const;
    void LoadComponent(const Windows::Foundation::IInspectable & component, const Windows::Foundation::Uri & resourceLocator, Windows::UI::Xaml::Controls::Primitives::ComponentResourceLocation componentResourceLocation) const;
};

template <typename D>
struct WINRT_EBO impl_IBindingFailedEventArgs
{
    hstring Message() const;
};

template <typename D>
struct WINRT_EBO impl_ICornerRadiusHelper
{
};

template <typename D>
struct WINRT_EBO impl_ICornerRadiusHelperStatics
{
    Windows::UI::Xaml::CornerRadius FromRadii(double topLeft, double topRight, double bottomRight, double bottomLeft) const;
    Windows::UI::Xaml::CornerRadius FromUniformRadius(double uniformRadius) const;
};

template <typename D>
struct WINRT_EBO impl_IDataContextChangedEventArgs
{
    Windows::Foundation::IInspectable NewValue() const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplate
{
    Windows::UI::Xaml::DependencyObject LoadContent() const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateExtension
{
    void ResetTemplate() const;
    bool ProcessBinding(uint32_t phase) const;
    int32_t ProcessBindings(const Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs & arg) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateFactory
{
    Windows::UI::Xaml::DataTemplate CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateKey
{
    Windows::Foundation::IInspectable DataType() const;
    void DataType(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateKeyFactory
{
    Windows::UI::Xaml::DataTemplateKey CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::DataTemplateKey CreateInstanceWithType(const Windows::Foundation::IInspectable & dataType, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDataTemplateStatics2
{
    Windows::UI::Xaml::DependencyProperty ExtensionInstanceProperty() const;
    Windows::UI::Xaml::IDataTemplateExtension GetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element) const;
    void SetExtensionInstance(const Windows::UI::Xaml::FrameworkElement & element, const Windows::UI::Xaml::IDataTemplateExtension & value) const;
};

template <typename D>
struct WINRT_EBO impl_IDebugSettings
{
    bool EnableFrameRateCounter() const;
    void EnableFrameRateCounter(bool value) const;
    bool IsBindingTracingEnabled() const;
    void IsBindingTracingEnabled(bool value) const;
    bool IsOverdrawHeatMapEnabled() const;
    void IsOverdrawHeatMapEnabled(bool value) const;
    event_token BindingFailed(const Windows::UI::Xaml::BindingFailedEventHandler & value) const;
    using BindingFailed_revoker = event_revoker<IDebugSettings>;
    BindingFailed_revoker BindingFailed(auto_revoke_t, const Windows::UI::Xaml::BindingFailedEventHandler & value) const;
    void BindingFailed(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IDebugSettings2
{
    bool EnableRedrawRegions() const;
    void EnableRedrawRegions(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDebugSettings3
{
    bool IsTextPerformanceVisualizationEnabled() const;
    void IsTextPerformanceVisualizationEnabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyObject
{
    Windows::Foundation::IInspectable GetValue(const Windows::UI::Xaml::DependencyProperty & dp) const;
    void SetValue(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::Foundation::IInspectable & value) const;
    void ClearValue(const Windows::UI::Xaml::DependencyProperty & dp) const;
    Windows::Foundation::IInspectable ReadLocalValue(const Windows::UI::Xaml::DependencyProperty & dp) const;
    Windows::Foundation::IInspectable GetAnimationBaseValue(const Windows::UI::Xaml::DependencyProperty & dp) const;
    Windows::UI::Core::CoreDispatcher Dispatcher() const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyObject2
{
    int64_t RegisterPropertyChangedCallback(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::DependencyPropertyChangedCallback & callback) const;
    void UnregisterPropertyChangedCallback(const Windows::UI::Xaml::DependencyProperty & dp, int64_t token) const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyObjectCollectionFactory
{
    Windows::UI::Xaml::DependencyObjectCollection CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyObjectFactory
{
    Windows::UI::Xaml::DependencyObject CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyProperty
{
    Windows::UI::Xaml::PropertyMetadata GetMetadata(const Windows::UI::Xaml::Interop::TypeName & forType) const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyPropertyChangedEventArgs
{
    Windows::UI::Xaml::DependencyProperty Property() const;
    Windows::Foundation::IInspectable OldValue() const;
    Windows::Foundation::IInspectable NewValue() const;
};

template <typename D>
struct WINRT_EBO impl_IDependencyPropertyStatics
{
    Windows::Foundation::IInspectable UnsetValue() const;
    Windows::UI::Xaml::DependencyProperty Register(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & typeMetadata) const;
    Windows::UI::Xaml::DependencyProperty RegisterAttached(hstring_view name, const Windows::UI::Xaml::Interop::TypeName & propertyType, const Windows::UI::Xaml::Interop::TypeName & ownerType, const Windows::UI::Xaml::PropertyMetadata & defaultMetadata) const;
};

template <typename D>
struct WINRT_EBO impl_IDispatcherTimer
{
    Windows::Foundation::TimeSpan Interval() const;
    void Interval(const Windows::Foundation::TimeSpan & value) const;
    bool IsEnabled() const;
    event_token Tick(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using Tick_revoker = event_revoker<IDispatcherTimer>;
    Tick_revoker Tick(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void Tick(event_token token) const;
    void Start() const;
    void Stop() const;
};

template <typename D>
struct WINRT_EBO impl_IDispatcherTimerFactory
{
    Windows::UI::Xaml::DispatcherTimer CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IDragEventArgs
{
    bool Handled() const;
    void Handled(bool value) const;
    Windows::ApplicationModel::DataTransfer::DataPackage Data() const;
    void Data(const Windows::ApplicationModel::DataTransfer::DataPackage & value) const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_IDragEventArgs2
{
    Windows::ApplicationModel::DataTransfer::DataPackageView DataView() const;
    Windows::UI::Xaml::DragUIOverride DragUIOverride() const;
    Windows::ApplicationModel::DataTransfer::DragDrop::DragDropModifiers Modifiers() const;
    Windows::ApplicationModel::DataTransfer::DataPackageOperation AcceptedOperation() const;
    void AcceptedOperation(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const;
    Windows::UI::Xaml::DragOperationDeferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IDragEventArgs3
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation AllowedOperations() const;
};

template <typename D>
struct WINRT_EBO impl_IDragOperationDeferral
{
    void Complete() const;
};

template <typename D>
struct WINRT_EBO impl_IDragStartingEventArgs
{
    bool Cancel() const;
    void Cancel(bool value) const;
    Windows::ApplicationModel::DataTransfer::DataPackage Data() const;
    Windows::UI::Xaml::DragUI DragUI() const;
    Windows::UI::Xaml::DragOperationDeferral GetDeferral() const;
    Windows::Foundation::Point GetPosition(const Windows::UI::Xaml::UIElement & relativeTo) const;
};

template <typename D>
struct WINRT_EBO impl_IDragStartingEventArgs2
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation AllowedOperations() const;
    void AllowedOperations(Windows::ApplicationModel::DataTransfer::DataPackageOperation value) const;
};

template <typename D>
struct WINRT_EBO impl_IDragUI
{
    void SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage) const;
    void SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage, const Windows::Foundation::Point & anchorPoint) const;
    void SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const;
    void SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const;
    void SetContentFromDataPackage() const;
};

template <typename D>
struct WINRT_EBO impl_IDragUIOverride
{
    hstring Caption() const;
    void Caption(hstring_view value) const;
    bool IsContentVisible() const;
    void IsContentVisible(bool value) const;
    bool IsCaptionVisible() const;
    void IsCaptionVisible(bool value) const;
    bool IsGlyphVisible() const;
    void IsGlyphVisible(bool value) const;
    void Clear() const;
    void SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage) const;
    void SetContentFromBitmapImage(const Windows::UI::Xaml::Media::Imaging::BitmapImage & bitmapImage, const Windows::Foundation::Point & anchorPoint) const;
    void SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap) const;
    void SetContentFromSoftwareBitmap(const Windows::Graphics::Imaging::SoftwareBitmap & softwareBitmap, const Windows::Foundation::Point & anchorPoint) const;
};

template <typename D>
struct WINRT_EBO impl_IDropCompletedEventArgs
{
    Windows::ApplicationModel::DataTransfer::DataPackageOperation DropResult() const;
};

template <typename D>
struct WINRT_EBO impl_IDurationHelper
{
};

template <typename D>
struct WINRT_EBO impl_IDurationHelperStatics
{
    Windows::UI::Xaml::Duration Automatic() const;
    Windows::UI::Xaml::Duration Forever() const;
    int32_t Compare(const Windows::UI::Xaml::Duration & duration1, const Windows::UI::Xaml::Duration & duration2) const;
    Windows::UI::Xaml::Duration FromTimeSpan(const Windows::Foundation::TimeSpan & timeSpan) const;
    bool GetHasTimeSpan(const Windows::UI::Xaml::Duration & target) const;
    Windows::UI::Xaml::Duration Add(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration) const;
    bool Equals(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & value) const;
    Windows::UI::Xaml::Duration Subtract(const Windows::UI::Xaml::Duration & target, const Windows::UI::Xaml::Duration & duration) const;
};

template <typename D>
struct WINRT_EBO impl_IElementSoundPlayer
{
};

template <typename D>
struct WINRT_EBO impl_IElementSoundPlayerStatics
{
    double Volume() const;
    void Volume(double value) const;
    Windows::UI::Xaml::ElementSoundPlayerState State() const;
    void State(Windows::UI::Xaml::ElementSoundPlayerState value) const;
    void Play(Windows::UI::Xaml::ElementSoundKind sound) const;
};

template <typename D>
struct WINRT_EBO impl_IEventTrigger
{
    Windows::UI::Xaml::RoutedEvent RoutedEvent() const;
    void RoutedEvent(const Windows::UI::Xaml::RoutedEvent & value) const;
    Windows::UI::Xaml::TriggerActionCollection Actions() const;
};

template <typename D>
struct WINRT_EBO impl_IExceptionRoutedEventArgs
{
    hstring ErrorMessage() const;
};

template <typename D>
struct WINRT_EBO impl_IExceptionRoutedEventArgsFactory
{
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElement
{
    Windows::UI::Xaml::TriggerCollection Triggers() const;
    Windows::UI::Xaml::ResourceDictionary Resources() const;
    void Resources(const Windows::UI::Xaml::ResourceDictionary & value) const;
    Windows::Foundation::IInspectable Tag() const;
    void Tag(const Windows::Foundation::IInspectable & value) const;
    hstring Language() const;
    void Language(hstring_view value) const;
    double ActualWidth() const;
    double ActualHeight() const;
    double Width() const;
    void Width(double value) const;
    double Height() const;
    void Height(double value) const;
    double MinWidth() const;
    void MinWidth(double value) const;
    double MaxWidth() const;
    void MaxWidth(double value) const;
    double MinHeight() const;
    void MinHeight(double value) const;
    double MaxHeight() const;
    void MaxHeight(double value) const;
    Windows::UI::Xaml::HorizontalAlignment HorizontalAlignment() const;
    void HorizontalAlignment(Windows::UI::Xaml::HorizontalAlignment value) const;
    Windows::UI::Xaml::VerticalAlignment VerticalAlignment() const;
    void VerticalAlignment(Windows::UI::Xaml::VerticalAlignment value) const;
    Windows::UI::Xaml::Thickness Margin() const;
    void Margin(const Windows::UI::Xaml::Thickness & value) const;
    hstring Name() const;
    void Name(hstring_view value) const;
    Windows::Foundation::Uri BaseUri() const;
    Windows::Foundation::IInspectable DataContext() const;
    void DataContext(const Windows::Foundation::IInspectable & value) const;
    Windows::UI::Xaml::Style Style() const;
    void Style(const Windows::UI::Xaml::Style & value) const;
    Windows::UI::Xaml::DependencyObject Parent() const;
    Windows::UI::Xaml::FlowDirection FlowDirection() const;
    void FlowDirection(Windows::UI::Xaml::FlowDirection value) const;
    event_token Loaded(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Loaded_revoker = event_revoker<IFrameworkElement>;
    Loaded_revoker Loaded(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Loaded(event_token token) const;
    event_token Unloaded(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using Unloaded_revoker = event_revoker<IFrameworkElement>;
    Unloaded_revoker Unloaded(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void Unloaded(event_token token) const;
    event_token SizeChanged(const Windows::UI::Xaml::SizeChangedEventHandler & value) const;
    using SizeChanged_revoker = event_revoker<IFrameworkElement>;
    SizeChanged_revoker SizeChanged(auto_revoke_t, const Windows::UI::Xaml::SizeChangedEventHandler & value) const;
    void SizeChanged(event_token token) const;
    event_token LayoutUpdated(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    using LayoutUpdated_revoker = event_revoker<IFrameworkElement>;
    LayoutUpdated_revoker LayoutUpdated(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & value) const;
    void LayoutUpdated(event_token token) const;
    Windows::Foundation::IInspectable FindName(hstring_view name) const;
    void SetBinding(const Windows::UI::Xaml::DependencyProperty & dp, const Windows::UI::Xaml::Data::BindingBase & binding) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElement2
{
    Windows::UI::Xaml::ElementTheme RequestedTheme() const;
    void RequestedTheme(Windows::UI::Xaml::ElementTheme value) const;
    event_token DataContextChanged(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> & value) const;
    using DataContextChanged_revoker = event_revoker<IFrameworkElement2>;
    DataContextChanged_revoker DataContextChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::UI::Xaml::DataContextChangedEventArgs> & value) const;
    void DataContextChanged(event_token token) const;
    Windows::UI::Xaml::Data::BindingExpression GetBindingExpression(const Windows::UI::Xaml::DependencyProperty & dp) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElement3
{
    event_token Loading(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> & value) const;
    using Loading_revoker = event_revoker<IFrameworkElement3>;
    Loading_revoker Loading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::FrameworkElement, Windows::Foundation::IInspectable> & value) const;
    void Loading(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElement4
{
    bool AllowFocusOnInteraction() const;
    void AllowFocusOnInteraction(bool value) const;
    Windows::UI::Xaml::Thickness FocusVisualMargin() const;
    void FocusVisualMargin(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Thickness FocusVisualSecondaryThickness() const;
    void FocusVisualSecondaryThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Thickness FocusVisualPrimaryThickness() const;
    void FocusVisualPrimaryThickness(const Windows::UI::Xaml::Thickness & value) const;
    Windows::UI::Xaml::Media::Brush FocusVisualSecondaryBrush() const;
    void FocusVisualSecondaryBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    Windows::UI::Xaml::Media::Brush FocusVisualPrimaryBrush() const;
    void FocusVisualPrimaryBrush(const Windows::UI::Xaml::Media::Brush & value) const;
    bool AllowFocusWhenDisabled() const;
    void AllowFocusWhenDisabled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementFactory
{
    Windows::UI::Xaml::FrameworkElement CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementOverrides
{
    Windows::Foundation::Size MeasureOverride(const Windows::Foundation::Size & availableSize) const;
    Windows::Foundation::Size ArrangeOverride(const Windows::Foundation::Size & finalSize) const;
    void OnApplyTemplate() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementOverrides2
{
    bool GoToElementStateCore(hstring_view stateName, bool useTransitions) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementStatics
{
    Windows::UI::Xaml::DependencyProperty TagProperty() const;
    Windows::UI::Xaml::DependencyProperty LanguageProperty() const;
    Windows::UI::Xaml::DependencyProperty ActualWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty ActualHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty WidthProperty() const;
    Windows::UI::Xaml::DependencyProperty HeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MinWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxWidthProperty() const;
    Windows::UI::Xaml::DependencyProperty MinHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty MaxHeightProperty() const;
    Windows::UI::Xaml::DependencyProperty HorizontalAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty VerticalAlignmentProperty() const;
    Windows::UI::Xaml::DependencyProperty MarginProperty() const;
    Windows::UI::Xaml::DependencyProperty NameProperty() const;
    Windows::UI::Xaml::DependencyProperty DataContextProperty() const;
    Windows::UI::Xaml::DependencyProperty StyleProperty() const;
    Windows::UI::Xaml::DependencyProperty FlowDirectionProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementStatics2
{
    Windows::UI::Xaml::DependencyProperty RequestedThemeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkElementStatics4
{
    Windows::UI::Xaml::DependencyProperty AllowFocusOnInteractionProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusVisualMarginProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusVisualSecondaryThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusVisualPrimaryThicknessProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusVisualSecondaryBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty FocusVisualPrimaryBrushProperty() const;
    Windows::UI::Xaml::DependencyProperty AllowFocusWhenDisabledProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkTemplate
{
};

template <typename D>
struct WINRT_EBO impl_IFrameworkTemplateFactory
{
    Windows::UI::Xaml::FrameworkTemplate CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameworkView
{
};

template <typename D>
struct WINRT_EBO impl_IFrameworkViewSource
{
};

template <typename D>
struct WINRT_EBO impl_IGridLengthHelper
{
};

template <typename D>
struct WINRT_EBO impl_IGridLengthHelperStatics
{
    Windows::UI::Xaml::GridLength Auto() const;
    Windows::UI::Xaml::GridLength FromPixels(double pixels) const;
    Windows::UI::Xaml::GridLength FromValueAndType(double value, Windows::UI::Xaml::GridUnitType type) const;
    bool GetIsAbsolute(const Windows::UI::Xaml::GridLength & target) const;
    bool GetIsAuto(const Windows::UI::Xaml::GridLength & target) const;
    bool GetIsStar(const Windows::UI::Xaml::GridLength & target) const;
    bool Equals(const Windows::UI::Xaml::GridLength & target, const Windows::UI::Xaml::GridLength & value) const;
};

template <typename D>
struct WINRT_EBO impl_IMediaFailedRoutedEventArgs
{
    hstring ErrorTrace() const;
};

template <typename D>
struct WINRT_EBO impl_IPointHelper
{
};

template <typename D>
struct WINRT_EBO impl_IPointHelperStatics
{
    Windows::Foundation::Point FromCoordinates(float x, float y) const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyMetadata
{
    Windows::Foundation::IInspectable DefaultValue() const;
    Windows::UI::Xaml::CreateDefaultValueCallback CreateDefaultValueCallback() const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyMetadataFactory
{
    Windows::UI::Xaml::PropertyMetadata CreateInstanceWithDefaultValue(const Windows::Foundation::IInspectable & defaultValue, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
    Windows::UI::Xaml::PropertyMetadata CreateInstanceWithDefaultValueAndCallback(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback, const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyMetadataStatics
{
    Windows::UI::Xaml::PropertyMetadata Create(const Windows::Foundation::IInspectable & defaultValue) const;
    Windows::UI::Xaml::PropertyMetadata Create(const Windows::Foundation::IInspectable & defaultValue, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback) const;
    Windows::UI::Xaml::PropertyMetadata Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback) const;
    Windows::UI::Xaml::PropertyMetadata Create(const Windows::UI::Xaml::CreateDefaultValueCallback & createDefaultValueCallback, const Windows::UI::Xaml::PropertyChangedCallback & propertyChangedCallback) const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyPath
{
    hstring Path() const;
};

template <typename D>
struct WINRT_EBO impl_IPropertyPathFactory
{
    Windows::UI::Xaml::PropertyPath CreateInstance(hstring_view path) const;
};

template <typename D>
struct WINRT_EBO impl_IRectHelper
{
};

template <typename D>
struct WINRT_EBO impl_IRectHelperStatics
{
    Windows::Foundation::Rect Empty() const;
    Windows::Foundation::Rect FromCoordinatesAndDimensions(float x, float y, float width, float height) const;
    Windows::Foundation::Rect FromPoints(const Windows::Foundation::Point & point1, const Windows::Foundation::Point & point2) const;
    Windows::Foundation::Rect FromLocationAndSize(const Windows::Foundation::Point & location, const Windows::Foundation::Size & size) const;
    bool GetIsEmpty(const Windows::Foundation::Rect & target) const;
    float GetBottom(const Windows::Foundation::Rect & target) const;
    float GetLeft(const Windows::Foundation::Rect & target) const;
    float GetRight(const Windows::Foundation::Rect & target) const;
    float GetTop(const Windows::Foundation::Rect & target) const;
    bool Contains(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point) const;
    bool Equals(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & value) const;
    Windows::Foundation::Rect Intersect(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect) const;
    Windows::Foundation::Rect Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Point & point) const;
    Windows::Foundation::Rect Union(const Windows::Foundation::Rect & target, const Windows::Foundation::Rect & rect) const;
};

template <typename D>
struct WINRT_EBO impl_IResourceDictionary
{
    Windows::Foundation::Uri Source() const;
    void Source(const Windows::Foundation::Uri & value) const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::ResourceDictionary> MergedDictionaries() const;
    Windows::Foundation::Collections::IMap<Windows::Foundation::IInspectable, Windows::Foundation::IInspectable> ThemeDictionaries() const;
};

template <typename D>
struct WINRT_EBO impl_IResourceDictionaryFactory
{
    Windows::UI::Xaml::ResourceDictionary CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IRoutedEvent
{
};

template <typename D>
struct WINRT_EBO impl_IRoutedEventArgs
{
    Windows::Foundation::IInspectable OriginalSource() const;
};

template <typename D>
struct WINRT_EBO impl_IRoutedEventArgsFactory
{
    Windows::UI::Xaml::RoutedEventArgs CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_ISetter
{
    Windows::UI::Xaml::DependencyProperty Property() const;
    void Property(const Windows::UI::Xaml::DependencyProperty & value) const;
    Windows::Foundation::IInspectable Value() const;
    void Value(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISetter2
{
    Windows::UI::Xaml::TargetPropertyPath Target() const;
    void Target(const Windows::UI::Xaml::TargetPropertyPath & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISetterBase
{
    bool IsSealed() const;
};

template <typename D>
struct WINRT_EBO impl_ISetterBaseCollection
{
    bool IsSealed() const;
};

template <typename D>
struct WINRT_EBO impl_ISetterBaseFactory
{
};

template <typename D>
struct WINRT_EBO impl_ISetterFactory
{
    Windows::UI::Xaml::Setter CreateInstance(const Windows::UI::Xaml::DependencyProperty & targetProperty, const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISizeChangedEventArgs
{
    Windows::Foundation::Size PreviousSize() const;
    Windows::Foundation::Size NewSize() const;
};

template <typename D>
struct WINRT_EBO impl_ISizeHelper
{
};

template <typename D>
struct WINRT_EBO impl_ISizeHelperStatics
{
    Windows::Foundation::Size Empty() const;
    Windows::Foundation::Size FromDimensions(float width, float height) const;
    bool GetIsEmpty(const Windows::Foundation::Size & target) const;
    bool Equals(const Windows::Foundation::Size & target, const Windows::Foundation::Size & value) const;
};

template <typename D>
struct WINRT_EBO impl_IStateTrigger
{
    bool IsActive() const;
    void IsActive(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IStateTriggerBase
{
};

template <typename D>
struct WINRT_EBO impl_IStateTriggerBaseFactory
{
    Windows::UI::Xaml::StateTriggerBase CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IStateTriggerBaseProtected
{
    void SetActive(bool IsActive) const;
};

template <typename D>
struct WINRT_EBO impl_IStateTriggerStatics
{
    Windows::UI::Xaml::DependencyProperty IsActiveProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IStyle
{
    bool IsSealed() const;
    Windows::UI::Xaml::SetterBaseCollection Setters() const;
    Windows::UI::Xaml::Interop::TypeName TargetType() const;
    void TargetType(const Windows::UI::Xaml::Interop::TypeName & value) const;
    Windows::UI::Xaml::Style BasedOn() const;
    void BasedOn(const Windows::UI::Xaml::Style & value) const;
    void Seal() const;
};

template <typename D>
struct WINRT_EBO impl_IStyleFactory
{
    Windows::UI::Xaml::Style CreateInstance(const Windows::UI::Xaml::Interop::TypeName & targetType) const;
};

template <typename D>
struct WINRT_EBO impl_ITargetPropertyPath
{
    Windows::UI::Xaml::PropertyPath Path() const;
    void Path(const Windows::UI::Xaml::PropertyPath & value) const;
    Windows::Foundation::IInspectable Target() const;
    void Target(const Windows::Foundation::IInspectable & value) const;
};

template <typename D>
struct WINRT_EBO impl_ITargetPropertyPathFactory
{
    Windows::UI::Xaml::TargetPropertyPath CreateInstance(const Windows::UI::Xaml::DependencyProperty & targetProperty) const;
};

template <typename D>
struct WINRT_EBO impl_IThicknessHelper
{
};

template <typename D>
struct WINRT_EBO impl_IThicknessHelperStatics
{
    Windows::UI::Xaml::Thickness FromLengths(double left, double top, double right, double bottom) const;
    Windows::UI::Xaml::Thickness FromUniformLength(double uniformLength) const;
};

template <typename D>
struct WINRT_EBO impl_ITriggerAction
{
};

template <typename D>
struct WINRT_EBO impl_ITriggerActionFactory
{
};

template <typename D>
struct WINRT_EBO impl_ITriggerBase
{
};

template <typename D>
struct WINRT_EBO impl_ITriggerBaseFactory
{
};

template <typename D>
struct WINRT_EBO impl_IUIElement
{
    Windows::Foundation::Size DesiredSize() const;
    bool AllowDrop() const;
    void AllowDrop(bool value) const;
    double Opacity() const;
    void Opacity(double value) const;
    Windows::UI::Xaml::Media::RectangleGeometry Clip() const;
    void Clip(const Windows::UI::Xaml::Media::RectangleGeometry & value) const;
    Windows::UI::Xaml::Media::Transform RenderTransform() const;
    void RenderTransform(const Windows::UI::Xaml::Media::Transform & value) const;
    Windows::UI::Xaml::Media::Projection Projection() const;
    void Projection(const Windows::UI::Xaml::Media::Projection & value) const;
    Windows::Foundation::Point RenderTransformOrigin() const;
    void RenderTransformOrigin(const Windows::Foundation::Point & value) const;
    bool IsHitTestVisible() const;
    void IsHitTestVisible(bool value) const;
    Windows::UI::Xaml::Visibility Visibility() const;
    void Visibility(Windows::UI::Xaml::Visibility value) const;
    Windows::Foundation::Size RenderSize() const;
    bool UseLayoutRounding() const;
    void UseLayoutRounding(bool value) const;
    Windows::UI::Xaml::Media::Animation::TransitionCollection Transitions() const;
    void Transitions(const Windows::UI::Xaml::Media::Animation::TransitionCollection & value) const;
    Windows::UI::Xaml::Media::CacheMode CacheMode() const;
    void CacheMode(const Windows::UI::Xaml::Media::CacheMode & value) const;
    bool IsTapEnabled() const;
    void IsTapEnabled(bool value) const;
    bool IsDoubleTapEnabled() const;
    void IsDoubleTapEnabled(bool value) const;
    bool IsRightTapEnabled() const;
    void IsRightTapEnabled(bool value) const;
    bool IsHoldingEnabled() const;
    void IsHoldingEnabled(bool value) const;
    Windows::UI::Xaml::Input::ManipulationModes ManipulationMode() const;
    void ManipulationMode(Windows::UI::Xaml::Input::ManipulationModes value) const;
    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Input::Pointer> PointerCaptures() const;
    event_token KeyUp(const Windows::UI::Xaml::Input::KeyEventHandler & value) const;
    using KeyUp_revoker = event_revoker<IUIElement>;
    KeyUp_revoker KeyUp(auto_revoke_t, const Windows::UI::Xaml::Input::KeyEventHandler & value) const;
    void KeyUp(event_token token) const;
    event_token KeyDown(const Windows::UI::Xaml::Input::KeyEventHandler & value) const;
    using KeyDown_revoker = event_revoker<IUIElement>;
    KeyDown_revoker KeyDown(auto_revoke_t, const Windows::UI::Xaml::Input::KeyEventHandler & value) const;
    void KeyDown(event_token token) const;
    event_token GotFocus(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using GotFocus_revoker = event_revoker<IUIElement>;
    GotFocus_revoker GotFocus(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void GotFocus(event_token token) const;
    event_token LostFocus(const Windows::UI::Xaml::RoutedEventHandler & value) const;
    using LostFocus_revoker = event_revoker<IUIElement>;
    LostFocus_revoker LostFocus(auto_revoke_t, const Windows::UI::Xaml::RoutedEventHandler & value) const;
    void LostFocus(event_token token) const;
    event_token DragEnter(const Windows::UI::Xaml::DragEventHandler & value) const;
    using DragEnter_revoker = event_revoker<IUIElement>;
    DragEnter_revoker DragEnter(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const;
    void DragEnter(event_token token) const;
    event_token DragLeave(const Windows::UI::Xaml::DragEventHandler & value) const;
    using DragLeave_revoker = event_revoker<IUIElement>;
    DragLeave_revoker DragLeave(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const;
    void DragLeave(event_token token) const;
    event_token DragOver(const Windows::UI::Xaml::DragEventHandler & value) const;
    using DragOver_revoker = event_revoker<IUIElement>;
    DragOver_revoker DragOver(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const;
    void DragOver(event_token token) const;
    event_token Drop(const Windows::UI::Xaml::DragEventHandler & value) const;
    using Drop_revoker = event_revoker<IUIElement>;
    Drop_revoker Drop(auto_revoke_t, const Windows::UI::Xaml::DragEventHandler & value) const;
    void Drop(event_token token) const;
    event_token PointerPressed(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerPressed_revoker = event_revoker<IUIElement>;
    PointerPressed_revoker PointerPressed(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerPressed(event_token token) const;
    event_token PointerMoved(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerMoved_revoker = event_revoker<IUIElement>;
    PointerMoved_revoker PointerMoved(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerMoved(event_token token) const;
    event_token PointerReleased(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerReleased_revoker = event_revoker<IUIElement>;
    PointerReleased_revoker PointerReleased(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerReleased(event_token token) const;
    event_token PointerEntered(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerEntered_revoker = event_revoker<IUIElement>;
    PointerEntered_revoker PointerEntered(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerEntered(event_token token) const;
    event_token PointerExited(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerExited_revoker = event_revoker<IUIElement>;
    PointerExited_revoker PointerExited(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerExited(event_token token) const;
    event_token PointerCaptureLost(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerCaptureLost_revoker = event_revoker<IUIElement>;
    PointerCaptureLost_revoker PointerCaptureLost(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerCaptureLost(event_token token) const;
    event_token PointerCanceled(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerCanceled_revoker = event_revoker<IUIElement>;
    PointerCanceled_revoker PointerCanceled(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerCanceled(event_token token) const;
    event_token PointerWheelChanged(const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    using PointerWheelChanged_revoker = event_revoker<IUIElement>;
    PointerWheelChanged_revoker PointerWheelChanged(auto_revoke_t, const Windows::UI::Xaml::Input::PointerEventHandler & value) const;
    void PointerWheelChanged(event_token token) const;
    event_token Tapped(const Windows::UI::Xaml::Input::TappedEventHandler & value) const;
    using Tapped_revoker = event_revoker<IUIElement>;
    Tapped_revoker Tapped(auto_revoke_t, const Windows::UI::Xaml::Input::TappedEventHandler & value) const;
    void Tapped(event_token token) const;
    event_token DoubleTapped(const Windows::UI::Xaml::Input::DoubleTappedEventHandler & value) const;
    using DoubleTapped_revoker = event_revoker<IUIElement>;
    DoubleTapped_revoker DoubleTapped(auto_revoke_t, const Windows::UI::Xaml::Input::DoubleTappedEventHandler & value) const;
    void DoubleTapped(event_token token) const;
    event_token Holding(const Windows::UI::Xaml::Input::HoldingEventHandler & value) const;
    using Holding_revoker = event_revoker<IUIElement>;
    Holding_revoker Holding(auto_revoke_t, const Windows::UI::Xaml::Input::HoldingEventHandler & value) const;
    void Holding(event_token token) const;
    event_token RightTapped(const Windows::UI::Xaml::Input::RightTappedEventHandler & value) const;
    using RightTapped_revoker = event_revoker<IUIElement>;
    RightTapped_revoker RightTapped(auto_revoke_t, const Windows::UI::Xaml::Input::RightTappedEventHandler & value) const;
    void RightTapped(event_token token) const;
    event_token ManipulationStarting(const Windows::UI::Xaml::Input::ManipulationStartingEventHandler & value) const;
    using ManipulationStarting_revoker = event_revoker<IUIElement>;
    ManipulationStarting_revoker ManipulationStarting(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationStartingEventHandler & value) const;
    void ManipulationStarting(event_token token) const;
    event_token ManipulationInertiaStarting(const Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler & value) const;
    using ManipulationInertiaStarting_revoker = event_revoker<IUIElement>;
    ManipulationInertiaStarting_revoker ManipulationInertiaStarting(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationInertiaStartingEventHandler & value) const;
    void ManipulationInertiaStarting(event_token token) const;
    event_token ManipulationStarted(const Windows::UI::Xaml::Input::ManipulationStartedEventHandler & value) const;
    using ManipulationStarted_revoker = event_revoker<IUIElement>;
    ManipulationStarted_revoker ManipulationStarted(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationStartedEventHandler & value) const;
    void ManipulationStarted(event_token token) const;
    event_token ManipulationDelta(const Windows::UI::Xaml::Input::ManipulationDeltaEventHandler & value) const;
    using ManipulationDelta_revoker = event_revoker<IUIElement>;
    ManipulationDelta_revoker ManipulationDelta(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationDeltaEventHandler & value) const;
    void ManipulationDelta(event_token token) const;
    event_token ManipulationCompleted(const Windows::UI::Xaml::Input::ManipulationCompletedEventHandler & value) const;
    using ManipulationCompleted_revoker = event_revoker<IUIElement>;
    ManipulationCompleted_revoker ManipulationCompleted(auto_revoke_t, const Windows::UI::Xaml::Input::ManipulationCompletedEventHandler & value) const;
    void ManipulationCompleted(event_token token) const;
    void Measure(const Windows::Foundation::Size & availableSize) const;
    void Arrange(const Windows::Foundation::Rect & finalRect) const;
    bool CapturePointer(const Windows::UI::Xaml::Input::Pointer & value) const;
    void ReleasePointerCapture(const Windows::UI::Xaml::Input::Pointer & value) const;
    void ReleasePointerCaptures() const;
    void AddHandler(const Windows::UI::Xaml::RoutedEvent & routedEvent, const Windows::Foundation::IInspectable & handler, bool handledEventsToo) const;
    void RemoveHandler(const Windows::UI::Xaml::RoutedEvent & routedEvent, const Windows::Foundation::IInspectable & handler) const;
    Windows::UI::Xaml::Media::GeneralTransform TransformToVisual(const Windows::UI::Xaml::UIElement & visual) const;
    void InvalidateMeasure() const;
    void InvalidateArrange() const;
    void UpdateLayout() const;
};

template <typename D>
struct WINRT_EBO impl_IUIElement2
{
    Windows::UI::Xaml::Media::ElementCompositeMode CompositeMode() const;
    void CompositeMode(Windows::UI::Xaml::Media::ElementCompositeMode value) const;
    bool CancelDirectManipulations() const;
};

template <typename D>
struct WINRT_EBO impl_IUIElement3
{
    Windows::UI::Xaml::Media::Media3D::Transform3D Transform3D() const;
    void Transform3D(const Windows::UI::Xaml::Media::Media3D::Transform3D & value) const;
    bool CanDrag() const;
    void CanDrag(bool value) const;
    event_token DragStarting(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> & value) const;
    using DragStarting_revoker = event_revoker<IUIElement3>;
    DragStarting_revoker DragStarting(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DragStartingEventArgs> & value) const;
    void DragStarting(event_token token) const;
    event_token DropCompleted(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> & value) const;
    using DropCompleted_revoker = event_revoker<IUIElement3>;
    DropCompleted_revoker DropCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::DropCompletedEventArgs> & value) const;
    void DropCompleted(event_token token) const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::ApplicationModel::DataTransfer::DataPackageOperation> StartDragAsync(const Windows::UI::Input::PointerPoint & pointerPoint) const;
};

template <typename D>
struct WINRT_EBO impl_IUIElement4
{
    Windows::UI::Xaml::Controls::Primitives::FlyoutBase ContextFlyout() const;
    void ContextFlyout(const Windows::UI::Xaml::Controls::Primitives::FlyoutBase & value) const;
    bool ExitDisplayModeOnAccessKeyInvoked() const;
    void ExitDisplayModeOnAccessKeyInvoked(bool value) const;
    bool IsAccessKeyScope() const;
    void IsAccessKeyScope(bool value) const;
    Windows::UI::Xaml::DependencyObject AccessKeyScopeOwner() const;
    void AccessKeyScopeOwner(const Windows::UI::Xaml::DependencyObject & value) const;
    hstring AccessKey() const;
    void AccessKey(hstring_view value) const;
    event_token ContextRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> & value) const;
    using ContextRequested_revoker = event_revoker<IUIElement4>;
    ContextRequested_revoker ContextRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::ContextRequestedEventArgs> & value) const;
    void ContextRequested(event_token token) const;
    event_token ContextCanceled(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> & value) const;
    using ContextCanceled_revoker = event_revoker<IUIElement4>;
    ContextCanceled_revoker ContextCanceled(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::RoutedEventArgs> & value) const;
    void ContextCanceled(event_token token) const;
    event_token AccessKeyDisplayRequested(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> & value) const;
    using AccessKeyDisplayRequested_revoker = event_revoker<IUIElement4>;
    AccessKeyDisplayRequested_revoker AccessKeyDisplayRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs> & value) const;
    void AccessKeyDisplayRequested(event_token token) const;
    event_token AccessKeyDisplayDismissed(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> & value) const;
    using AccessKeyDisplayDismissed_revoker = event_revoker<IUIElement4>;
    AccessKeyDisplayDismissed_revoker AccessKeyDisplayDismissed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs> & value) const;
    void AccessKeyDisplayDismissed(event_token token) const;
    event_token AccessKeyInvoked(const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> & value) const;
    using AccessKeyInvoked_revoker = event_revoker<IUIElement4>;
    AccessKeyInvoked_revoker AccessKeyInvoked(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::UI::Xaml::UIElement, Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs> & value) const;
    void AccessKeyInvoked(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementFactory
{
};

template <typename D>
struct WINRT_EBO impl_IUIElementOverrides
{
    Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer() const;
    void OnDisconnectVisualChildren() const;
    Windows::Foundation::Collections::IIterable<Windows::Foundation::Collections::IIterable<Windows::Foundation::Point>> FindSubElementsForTouchTargeting(const Windows::Foundation::Point & point, const Windows::Foundation::Rect & boundingRect) const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementStatics
{
    Windows::UI::Xaml::RoutedEvent KeyDownEvent() const;
    Windows::UI::Xaml::RoutedEvent KeyUpEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerEnteredEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerPressedEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerMovedEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerReleasedEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerExitedEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerCaptureLostEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerCanceledEvent() const;
    Windows::UI::Xaml::RoutedEvent PointerWheelChangedEvent() const;
    Windows::UI::Xaml::RoutedEvent TappedEvent() const;
    Windows::UI::Xaml::RoutedEvent DoubleTappedEvent() const;
    Windows::UI::Xaml::RoutedEvent HoldingEvent() const;
    Windows::UI::Xaml::RoutedEvent RightTappedEvent() const;
    Windows::UI::Xaml::RoutedEvent ManipulationStartingEvent() const;
    Windows::UI::Xaml::RoutedEvent ManipulationInertiaStartingEvent() const;
    Windows::UI::Xaml::RoutedEvent ManipulationStartedEvent() const;
    Windows::UI::Xaml::RoutedEvent ManipulationDeltaEvent() const;
    Windows::UI::Xaml::RoutedEvent ManipulationCompletedEvent() const;
    Windows::UI::Xaml::RoutedEvent DragEnterEvent() const;
    Windows::UI::Xaml::RoutedEvent DragLeaveEvent() const;
    Windows::UI::Xaml::RoutedEvent DragOverEvent() const;
    Windows::UI::Xaml::RoutedEvent DropEvent() const;
    Windows::UI::Xaml::DependencyProperty AllowDropProperty() const;
    Windows::UI::Xaml::DependencyProperty OpacityProperty() const;
    Windows::UI::Xaml::DependencyProperty ClipProperty() const;
    Windows::UI::Xaml::DependencyProperty RenderTransformProperty() const;
    Windows::UI::Xaml::DependencyProperty ProjectionProperty() const;
    Windows::UI::Xaml::DependencyProperty RenderTransformOriginProperty() const;
    Windows::UI::Xaml::DependencyProperty IsHitTestVisibleProperty() const;
    Windows::UI::Xaml::DependencyProperty VisibilityProperty() const;
    Windows::UI::Xaml::DependencyProperty UseLayoutRoundingProperty() const;
    Windows::UI::Xaml::DependencyProperty TransitionsProperty() const;
    Windows::UI::Xaml::DependencyProperty CacheModeProperty() const;
    Windows::UI::Xaml::DependencyProperty IsTapEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsDoubleTapEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsRightTapEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty IsHoldingEnabledProperty() const;
    Windows::UI::Xaml::DependencyProperty ManipulationModeProperty() const;
    Windows::UI::Xaml::DependencyProperty PointerCapturesProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementStatics2
{
    Windows::UI::Xaml::DependencyProperty CompositeModeProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementStatics3
{
    Windows::UI::Xaml::DependencyProperty Transform3DProperty() const;
    Windows::UI::Xaml::DependencyProperty CanDragProperty() const;
    bool TryStartDirectManipulation(const Windows::UI::Xaml::Input::Pointer & value) const;
};

template <typename D>
struct WINRT_EBO impl_IUIElementStatics4
{
    Windows::UI::Xaml::DependencyProperty ContextFlyoutProperty() const;
    Windows::UI::Xaml::DependencyProperty ExitDisplayModeOnAccessKeyInvokedProperty() const;
    Windows::UI::Xaml::DependencyProperty IsAccessKeyScopeProperty() const;
    Windows::UI::Xaml::DependencyProperty AccessKeyScopeOwnerProperty() const;
    Windows::UI::Xaml::DependencyProperty AccessKeyProperty() const;
};

template <typename D>
struct WINRT_EBO impl_IUnhandledExceptionEventArgs
{
    HRESULT Exception() const;
    hstring Message() const;
    bool Handled() const;
    void Handled(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualState
{
    hstring Name() const;
    Windows::UI::Xaml::Media::Animation::Storyboard Storyboard() const;
    void Storyboard(const Windows::UI::Xaml::Media::Animation::Storyboard & value) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualState2
{
    Windows::UI::Xaml::SetterBaseCollection Setters() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::StateTriggerBase> StateTriggers() const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateChangedEventArgs
{
    Windows::UI::Xaml::VisualState OldState() const;
    void OldState(const Windows::UI::Xaml::VisualState & value) const;
    Windows::UI::Xaml::VisualState NewState() const;
    void NewState(const Windows::UI::Xaml::VisualState & value) const;
    Windows::UI::Xaml::Controls::Control Control() const;
    void Control(const Windows::UI::Xaml::Controls::Control & value) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateGroup
{
    hstring Name() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualTransition> Transitions() const;
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualState> States() const;
    Windows::UI::Xaml::VisualState CurrentState() const;
    event_token CurrentStateChanged(const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const;
    using CurrentStateChanged_revoker = event_revoker<IVisualStateGroup>;
    CurrentStateChanged_revoker CurrentStateChanged(auto_revoke_t, const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const;
    void CurrentStateChanged(event_token token) const;
    event_token CurrentStateChanging(const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const;
    using CurrentStateChanging_revoker = event_revoker<IVisualStateGroup>;
    CurrentStateChanging_revoker CurrentStateChanging(auto_revoke_t, const Windows::UI::Xaml::VisualStateChangedEventHandler & value) const;
    void CurrentStateChanging(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateManager
{
};

template <typename D>
struct WINRT_EBO impl_IVisualStateManagerFactory
{
    Windows::UI::Xaml::VisualStateManager CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateManagerOverrides
{
    bool GoToStateCore(const Windows::UI::Xaml::Controls::Control & control, const Windows::UI::Xaml::FrameworkElement & templateRoot, hstring_view stateName, const Windows::UI::Xaml::VisualStateGroup & group, const Windows::UI::Xaml::VisualState & state, bool useTransitions) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateManagerProtected
{
    void RaiseCurrentStateChanging(const Windows::UI::Xaml::VisualStateGroup & stateGroup, const Windows::UI::Xaml::VisualState & oldState, const Windows::UI::Xaml::VisualState & newState, const Windows::UI::Xaml::Controls::Control & control) const;
    void RaiseCurrentStateChanged(const Windows::UI::Xaml::VisualStateGroup & stateGroup, const Windows::UI::Xaml::VisualState & oldState, const Windows::UI::Xaml::VisualState & newState, const Windows::UI::Xaml::Controls::Control & control) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualStateManagerStatics
{
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::VisualStateGroup> GetVisualStateGroups(const Windows::UI::Xaml::FrameworkElement & obj) const;
    Windows::UI::Xaml::DependencyProperty CustomVisualStateManagerProperty() const;
    Windows::UI::Xaml::VisualStateManager GetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj) const;
    void SetCustomVisualStateManager(const Windows::UI::Xaml::FrameworkElement & obj, const Windows::UI::Xaml::VisualStateManager & value) const;
    bool GoToState(const Windows::UI::Xaml::Controls::Control & control, hstring_view stateName, bool useTransitions) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualTransition
{
    Windows::UI::Xaml::Duration GeneratedDuration() const;
    void GeneratedDuration(const Windows::UI::Xaml::Duration & value) const;
    Windows::UI::Xaml::Media::Animation::EasingFunctionBase GeneratedEasingFunction() const;
    void GeneratedEasingFunction(const Windows::UI::Xaml::Media::Animation::EasingFunctionBase & value) const;
    hstring To() const;
    void To(hstring_view value) const;
    hstring From() const;
    void From(hstring_view value) const;
    Windows::UI::Xaml::Media::Animation::Storyboard Storyboard() const;
    void Storyboard(const Windows::UI::Xaml::Media::Animation::Storyboard & value) const;
};

template <typename D>
struct WINRT_EBO impl_IVisualTransitionFactory
{
    Windows::UI::Xaml::VisualTransition CreateInstance(const Windows::Foundation::IInspectable & outer, Windows::Foundation::IInspectable & inner) const;
};

template <typename D>
struct WINRT_EBO impl_IWindow
{
    Windows::Foundation::Rect Bounds() const;
    bool Visible() const;
    Windows::UI::Xaml::UIElement Content() const;
    void Content(const Windows::UI::Xaml::UIElement & value) const;
    Windows::UI::Core::CoreWindow CoreWindow() const;
    Windows::UI::Core::CoreDispatcher Dispatcher() const;
    event_token Activated(const Windows::UI::Xaml::WindowActivatedEventHandler & value) const;
    using Activated_revoker = event_revoker<IWindow>;
    Activated_revoker Activated(auto_revoke_t, const Windows::UI::Xaml::WindowActivatedEventHandler & value) const;
    void Activated(event_token token) const;
    event_token Closed(const Windows::UI::Xaml::WindowClosedEventHandler & value) const;
    using Closed_revoker = event_revoker<IWindow>;
    Closed_revoker Closed(auto_revoke_t, const Windows::UI::Xaml::WindowClosedEventHandler & value) const;
    void Closed(event_token token) const;
    event_token SizeChanged(const Windows::UI::Xaml::WindowSizeChangedEventHandler & value) const;
    using SizeChanged_revoker = event_revoker<IWindow>;
    SizeChanged_revoker SizeChanged(auto_revoke_t, const Windows::UI::Xaml::WindowSizeChangedEventHandler & value) const;
    void SizeChanged(event_token token) const;
    event_token VisibilityChanged(const Windows::UI::Xaml::WindowVisibilityChangedEventHandler & value) const;
    using VisibilityChanged_revoker = event_revoker<IWindow>;
    VisibilityChanged_revoker VisibilityChanged(auto_revoke_t, const Windows::UI::Xaml::WindowVisibilityChangedEventHandler & value) const;
    void VisibilityChanged(event_token token) const;
    void Activate() const;
    void Close() const;
};

template <typename D>
struct WINRT_EBO impl_IWindow2
{
    void SetTitleBar(const Windows::UI::Xaml::UIElement & value) const;
};

template <typename D>
struct WINRT_EBO impl_IWindowCreatedEventArgs
{
    Windows::UI::Xaml::Window Window() const;
};

template <typename D>
struct WINRT_EBO impl_IWindowStatics
{
    Windows::UI::Xaml::Window Current() const;
};

}

namespace impl {

template <> struct traits<Windows::UI::Xaml::ApplicationInitializationCallback>
{
    using abi = ABI::Windows::UI::Xaml::ApplicationInitializationCallback;
};

template <> struct traits<Windows::UI::Xaml::BindingFailedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::BindingFailedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::CreateDefaultValueCallback>
{
    using abi = ABI::Windows::UI::Xaml::CreateDefaultValueCallback;
};

template <> struct traits<Windows::UI::Xaml::DependencyPropertyChangedCallback>
{
    using abi = ABI::Windows::UI::Xaml::DependencyPropertyChangedCallback;
};

template <> struct traits<Windows::UI::Xaml::DependencyPropertyChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::DependencyPropertyChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::DragEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::DragEventHandler;
};

template <> struct traits<Windows::UI::Xaml::EnteredBackgroundEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::EnteredBackgroundEventHandler;
};

template <> struct traits<Windows::UI::Xaml::ExceptionRoutedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::ExceptionRoutedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::IAdaptiveTrigger>
{
    using abi = ABI::Windows::UI::Xaml::IAdaptiveTrigger;
    template <typename D> using consume = Windows::UI::Xaml::impl_IAdaptiveTrigger<D>;
};

template <> struct traits<Windows::UI::Xaml::IAdaptiveTriggerFactory>
{
    using abi = ABI::Windows::UI::Xaml::IAdaptiveTriggerFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IAdaptiveTriggerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IAdaptiveTriggerStatics>
{
    using abi = ABI::Windows::UI::Xaml::IAdaptiveTriggerStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IAdaptiveTriggerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplication>
{
    using abi = ABI::Windows::UI::Xaml::IApplication;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplication<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplication2>
{
    using abi = ABI::Windows::UI::Xaml::IApplication2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplication2<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplicationFactory>
{
    using abi = ABI::Windows::UI::Xaml::IApplicationFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplicationFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplicationInitializationCallbackParams>
{
    using abi = ABI::Windows::UI::Xaml::IApplicationInitializationCallbackParams;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplicationInitializationCallbackParams<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplicationOverrides>
{
    using abi = ABI::Windows::UI::Xaml::IApplicationOverrides;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplicationOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplicationOverrides2>
{
    using abi = ABI::Windows::UI::Xaml::IApplicationOverrides2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplicationOverrides2<D>;
};

template <> struct traits<Windows::UI::Xaml::IApplicationStatics>
{
    using abi = ABI::Windows::UI::Xaml::IApplicationStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IApplicationStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IBindingFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IBindingFailedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IBindingFailedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::ICornerRadiusHelper>
{
    using abi = ABI::Windows::UI::Xaml::ICornerRadiusHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_ICornerRadiusHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::ICornerRadiusHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::ICornerRadiusHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_ICornerRadiusHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataContextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IDataContextChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataContextChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplate>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplate;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplate<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplateExtension>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplateExtension;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplateExtension<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplateFactory>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplateFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplateFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplateKey>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplateKey;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplateKey<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplateKeyFactory>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplateKeyFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplateKeyFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IDataTemplateStatics2>
{
    using abi = ABI::Windows::UI::Xaml::IDataTemplateStatics2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDataTemplateStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::IDebugSettings>
{
    using abi = ABI::Windows::UI::Xaml::IDebugSettings;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDebugSettings<D>;
};

template <> struct traits<Windows::UI::Xaml::IDebugSettings2>
{
    using abi = ABI::Windows::UI::Xaml::IDebugSettings2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDebugSettings2<D>;
};

template <> struct traits<Windows::UI::Xaml::IDebugSettings3>
{
    using abi = ABI::Windows::UI::Xaml::IDebugSettings3;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDebugSettings3<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyObject>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyObject;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyObject<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyObject2>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyObject2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyObject2<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyObjectCollectionFactory>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyObjectCollectionFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyObjectCollectionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyObjectFactory>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyObjectFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyObjectFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyProperty>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyProperty;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyProperty<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyPropertyChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyPropertyChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IDependencyPropertyStatics>
{
    using abi = ABI::Windows::UI::Xaml::IDependencyPropertyStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDependencyPropertyStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IDispatcherTimer>
{
    using abi = ABI::Windows::UI::Xaml::IDispatcherTimer;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDispatcherTimer<D>;
};

template <> struct traits<Windows::UI::Xaml::IDispatcherTimerFactory>
{
    using abi = ABI::Windows::UI::Xaml::IDispatcherTimerFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDispatcherTimerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IDragEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::IDragEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragEventArgs3>
{
    using abi = ABI::Windows::UI::Xaml::IDragEventArgs3;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragEventArgs3<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragOperationDeferral>
{
    using abi = ABI::Windows::UI::Xaml::IDragOperationDeferral;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragOperationDeferral<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IDragStartingEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragStartingEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragStartingEventArgs2>
{
    using abi = ABI::Windows::UI::Xaml::IDragStartingEventArgs2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragStartingEventArgs2<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragUI>
{
    using abi = ABI::Windows::UI::Xaml::IDragUI;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragUI<D>;
};

template <> struct traits<Windows::UI::Xaml::IDragUIOverride>
{
    using abi = ABI::Windows::UI::Xaml::IDragUIOverride;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDragUIOverride<D>;
};

template <> struct traits<Windows::UI::Xaml::IDropCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IDropCompletedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDropCompletedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IDurationHelper>
{
    using abi = ABI::Windows::UI::Xaml::IDurationHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDurationHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::IDurationHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::IDurationHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IDurationHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IElementSoundPlayer>
{
    using abi = ABI::Windows::UI::Xaml::IElementSoundPlayer;
    template <typename D> using consume = Windows::UI::Xaml::impl_IElementSoundPlayer<D>;
};

template <> struct traits<Windows::UI::Xaml::IElementSoundPlayerStatics>
{
    using abi = ABI::Windows::UI::Xaml::IElementSoundPlayerStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IElementSoundPlayerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IEventTrigger>
{
    using abi = ABI::Windows::UI::Xaml::IEventTrigger;
    template <typename D> using consume = Windows::UI::Xaml::impl_IEventTrigger<D>;
};

template <> struct traits<Windows::UI::Xaml::IExceptionRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IExceptionRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IExceptionRoutedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::IExceptionRoutedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IExceptionRoutedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElement>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElement;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElement<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElement2>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElement2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElement2<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElement3>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElement3;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElement3<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElement4>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElement4;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElement4<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementFactory>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementOverrides>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementOverrides;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementOverrides2>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementOverrides2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementOverrides2<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementStatics2>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementStatics2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkElementStatics4>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkElementStatics4;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkElementStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkTemplate>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkTemplate;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkTemplate<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkTemplateFactory>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkTemplateFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkTemplateFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkView>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkView;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkView<D>;
};

template <> struct traits<Windows::UI::Xaml::IFrameworkViewSource>
{
    using abi = ABI::Windows::UI::Xaml::IFrameworkViewSource;
    template <typename D> using consume = Windows::UI::Xaml::impl_IFrameworkViewSource<D>;
};

template <> struct traits<Windows::UI::Xaml::IGridLengthHelper>
{
    using abi = ABI::Windows::UI::Xaml::IGridLengthHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_IGridLengthHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::IGridLengthHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::IGridLengthHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IGridLengthHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IMediaFailedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IMediaFailedRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IMediaFailedRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IPointHelper>
{
    using abi = ABI::Windows::UI::Xaml::IPointHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPointHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::IPointHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::IPointHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPointHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IPropertyMetadata>
{
    using abi = ABI::Windows::UI::Xaml::IPropertyMetadata;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPropertyMetadata<D>;
};

template <> struct traits<Windows::UI::Xaml::IPropertyMetadataFactory>
{
    using abi = ABI::Windows::UI::Xaml::IPropertyMetadataFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPropertyMetadataFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IPropertyMetadataStatics>
{
    using abi = ABI::Windows::UI::Xaml::IPropertyMetadataStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPropertyMetadataStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IPropertyPath>
{
    using abi = ABI::Windows::UI::Xaml::IPropertyPath;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPropertyPath<D>;
};

template <> struct traits<Windows::UI::Xaml::IPropertyPathFactory>
{
    using abi = ABI::Windows::UI::Xaml::IPropertyPathFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IPropertyPathFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IRectHelper>
{
    using abi = ABI::Windows::UI::Xaml::IRectHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_IRectHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::IRectHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::IRectHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IRectHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IResourceDictionary>
{
    using abi = ABI::Windows::UI::Xaml::IResourceDictionary;
    template <typename D> using consume = Windows::UI::Xaml::impl_IResourceDictionary<D>;
};

template <> struct traits<Windows::UI::Xaml::IResourceDictionaryFactory>
{
    using abi = ABI::Windows::UI::Xaml::IResourceDictionaryFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IResourceDictionaryFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IRoutedEvent>
{
    using abi = ABI::Windows::UI::Xaml::IRoutedEvent;
    template <typename D> using consume = Windows::UI::Xaml::impl_IRoutedEvent<D>;
};

template <> struct traits<Windows::UI::Xaml::IRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IRoutedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IRoutedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IRoutedEventArgsFactory>
{
    using abi = ABI::Windows::UI::Xaml::IRoutedEventArgsFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IRoutedEventArgsFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetter>
{
    using abi = ABI::Windows::UI::Xaml::ISetter;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetter<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetter2>
{
    using abi = ABI::Windows::UI::Xaml::ISetter2;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetter2<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetterBase>
{
    using abi = ABI::Windows::UI::Xaml::ISetterBase;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetterBase<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetterBaseCollection>
{
    using abi = ABI::Windows::UI::Xaml::ISetterBaseCollection;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetterBaseCollection<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetterBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::ISetterBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetterBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::ISetterFactory>
{
    using abi = ABI::Windows::UI::Xaml::ISetterFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISetterFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::ISizeChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::ISizeChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISizeChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::ISizeHelper>
{
    using abi = ABI::Windows::UI::Xaml::ISizeHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISizeHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::ISizeHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::ISizeHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_ISizeHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IStateTrigger>
{
    using abi = ABI::Windows::UI::Xaml::IStateTrigger;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStateTrigger<D>;
};

template <> struct traits<Windows::UI::Xaml::IStateTriggerBase>
{
    using abi = ABI::Windows::UI::Xaml::IStateTriggerBase;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStateTriggerBase<D>;
};

template <> struct traits<Windows::UI::Xaml::IStateTriggerBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::IStateTriggerBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStateTriggerBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IStateTriggerBaseProtected>
{
    using abi = ABI::Windows::UI::Xaml::IStateTriggerBaseProtected;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStateTriggerBaseProtected<D>;
};

template <> struct traits<Windows::UI::Xaml::IStateTriggerStatics>
{
    using abi = ABI::Windows::UI::Xaml::IStateTriggerStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStateTriggerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IStyle>
{
    using abi = ABI::Windows::UI::Xaml::IStyle;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStyle<D>;
};

template <> struct traits<Windows::UI::Xaml::IStyleFactory>
{
    using abi = ABI::Windows::UI::Xaml::IStyleFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IStyleFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::ITargetPropertyPath>
{
    using abi = ABI::Windows::UI::Xaml::ITargetPropertyPath;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITargetPropertyPath<D>;
};

template <> struct traits<Windows::UI::Xaml::ITargetPropertyPathFactory>
{
    using abi = ABI::Windows::UI::Xaml::ITargetPropertyPathFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITargetPropertyPathFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IThicknessHelper>
{
    using abi = ABI::Windows::UI::Xaml::IThicknessHelper;
    template <typename D> using consume = Windows::UI::Xaml::impl_IThicknessHelper<D>;
};

template <> struct traits<Windows::UI::Xaml::IThicknessHelperStatics>
{
    using abi = ABI::Windows::UI::Xaml::IThicknessHelperStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IThicknessHelperStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::ITriggerAction>
{
    using abi = ABI::Windows::UI::Xaml::ITriggerAction;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITriggerAction<D>;
};

template <> struct traits<Windows::UI::Xaml::ITriggerActionFactory>
{
    using abi = ABI::Windows::UI::Xaml::ITriggerActionFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITriggerActionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::ITriggerBase>
{
    using abi = ABI::Windows::UI::Xaml::ITriggerBase;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITriggerBase<D>;
};

template <> struct traits<Windows::UI::Xaml::ITriggerBaseFactory>
{
    using abi = ABI::Windows::UI::Xaml::ITriggerBaseFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_ITriggerBaseFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElement>
{
    using abi = ABI::Windows::UI::Xaml::IUIElement;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElement<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElement2>
{
    using abi = ABI::Windows::UI::Xaml::IUIElement2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElement2<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElement3>
{
    using abi = ABI::Windows::UI::Xaml::IUIElement3;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElement3<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElement4>
{
    using abi = ABI::Windows::UI::Xaml::IUIElement4;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElement4<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementFactory>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementOverrides>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementOverrides;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementStatics>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementStatics2>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementStatics2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementStatics2<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementStatics3>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementStatics3;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementStatics3<D>;
};

template <> struct traits<Windows::UI::Xaml::IUIElementStatics4>
{
    using abi = ABI::Windows::UI::Xaml::IUIElementStatics4;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUIElementStatics4<D>;
};

template <> struct traits<Windows::UI::Xaml::IUnhandledExceptionEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IUnhandledExceptionEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IUnhandledExceptionEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualState>
{
    using abi = ABI::Windows::UI::Xaml::IVisualState;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualState<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualState2>
{
    using abi = ABI::Windows::UI::Xaml::IVisualState2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualState2<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateChangedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateChangedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateGroup>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateGroup;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateGroup<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateManager>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateManager;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateManager<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateManagerFactory>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateManagerFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateManagerFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateManagerOverrides>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateManagerOverrides;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateManagerOverrides<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateManagerProtected>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateManagerProtected;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateManagerProtected<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualStateManagerStatics>
{
    using abi = ABI::Windows::UI::Xaml::IVisualStateManagerStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualStateManagerStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualTransition>
{
    using abi = ABI::Windows::UI::Xaml::IVisualTransition;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualTransition<D>;
};

template <> struct traits<Windows::UI::Xaml::IVisualTransitionFactory>
{
    using abi = ABI::Windows::UI::Xaml::IVisualTransitionFactory;
    template <typename D> using consume = Windows::UI::Xaml::impl_IVisualTransitionFactory<D>;
};

template <> struct traits<Windows::UI::Xaml::IWindow>
{
    using abi = ABI::Windows::UI::Xaml::IWindow;
    template <typename D> using consume = Windows::UI::Xaml::impl_IWindow<D>;
};

template <> struct traits<Windows::UI::Xaml::IWindow2>
{
    using abi = ABI::Windows::UI::Xaml::IWindow2;
    template <typename D> using consume = Windows::UI::Xaml::impl_IWindow2<D>;
};

template <> struct traits<Windows::UI::Xaml::IWindowCreatedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::IWindowCreatedEventArgs;
    template <typename D> using consume = Windows::UI::Xaml::impl_IWindowCreatedEventArgs<D>;
};

template <> struct traits<Windows::UI::Xaml::IWindowStatics>
{
    using abi = ABI::Windows::UI::Xaml::IWindowStatics;
    template <typename D> using consume = Windows::UI::Xaml::impl_IWindowStatics<D>;
};

template <> struct traits<Windows::UI::Xaml::LeavingBackgroundEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::LeavingBackgroundEventHandler;
};

template <> struct traits<Windows::UI::Xaml::PropertyChangedCallback>
{
    using abi = ABI::Windows::UI::Xaml::PropertyChangedCallback;
};

template <> struct traits<Windows::UI::Xaml::RoutedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::RoutedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::SizeChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::SizeChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::SuspendingEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::SuspendingEventHandler;
};

template <> struct traits<Windows::UI::Xaml::UnhandledExceptionEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::UnhandledExceptionEventHandler;
};

template <> struct traits<Windows::UI::Xaml::VisualStateChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::VisualStateChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::WindowActivatedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::WindowActivatedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::WindowClosedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::WindowClosedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::WindowSizeChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::WindowSizeChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::WindowVisibilityChangedEventHandler>
{
    using abi = ABI::Windows::UI::Xaml::WindowVisibilityChangedEventHandler;
};

template <> struct traits<Windows::UI::Xaml::AdaptiveTrigger>
{
    using abi = ABI::Windows::UI::Xaml::AdaptiveTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.AdaptiveTrigger"; }
};

template <> struct traits<Windows::UI::Xaml::Application>
{
    using abi = ABI::Windows::UI::Xaml::Application;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Application"; }
};

template <> struct traits<Windows::UI::Xaml::ApplicationInitializationCallbackParams>
{
    using abi = ABI::Windows::UI::Xaml::ApplicationInitializationCallbackParams;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.ApplicationInitializationCallbackParams"; }
};

template <> struct traits<Windows::UI::Xaml::BindingFailedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::BindingFailedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.BindingFailedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::CornerRadiusHelper>
{
    using abi = ABI::Windows::UI::Xaml::CornerRadiusHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.CornerRadiusHelper"; }
};

template <> struct traits<Windows::UI::Xaml::DataContextChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::DataContextChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DataContextChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::DataTemplate>
{
    using abi = ABI::Windows::UI::Xaml::DataTemplate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DataTemplate"; }
};

template <> struct traits<Windows::UI::Xaml::DataTemplateKey>
{
    using abi = ABI::Windows::UI::Xaml::DataTemplateKey;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DataTemplateKey"; }
};

template <> struct traits<Windows::UI::Xaml::DebugSettings>
{
    using abi = ABI::Windows::UI::Xaml::DebugSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DebugSettings"; }
};

template <> struct traits<Windows::UI::Xaml::DependencyObject>
{
    using abi = ABI::Windows::UI::Xaml::DependencyObject;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DependencyObject"; }
};

template <> struct traits<Windows::UI::Xaml::DependencyObjectCollection>
{
    using abi = ABI::Windows::UI::Xaml::DependencyObjectCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DependencyObjectCollection"; }
};

template <> struct traits<Windows::UI::Xaml::DependencyProperty>
{
    using abi = ABI::Windows::UI::Xaml::DependencyProperty;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DependencyProperty"; }
};

template <> struct traits<Windows::UI::Xaml::DependencyPropertyChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::DependencyPropertyChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DependencyPropertyChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::DispatcherTimer>
{
    using abi = ABI::Windows::UI::Xaml::DispatcherTimer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DispatcherTimer"; }
};

template <> struct traits<Windows::UI::Xaml::DragEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::DragEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DragEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::DragOperationDeferral>
{
    using abi = ABI::Windows::UI::Xaml::DragOperationDeferral;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DragOperationDeferral"; }
};

template <> struct traits<Windows::UI::Xaml::DragStartingEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::DragStartingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DragStartingEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::DragUI>
{
    using abi = ABI::Windows::UI::Xaml::DragUI;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DragUI"; }
};

template <> struct traits<Windows::UI::Xaml::DragUIOverride>
{
    using abi = ABI::Windows::UI::Xaml::DragUIOverride;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DragUIOverride"; }
};

template <> struct traits<Windows::UI::Xaml::DropCompletedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::DropCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DropCompletedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::DurationHelper>
{
    using abi = ABI::Windows::UI::Xaml::DurationHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.DurationHelper"; }
};

template <> struct traits<Windows::UI::Xaml::ElementSoundPlayer>
{
    using abi = ABI::Windows::UI::Xaml::ElementSoundPlayer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.ElementSoundPlayer"; }
};

template <> struct traits<Windows::UI::Xaml::EventTrigger>
{
    using abi = ABI::Windows::UI::Xaml::EventTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.EventTrigger"; }
};

template <> struct traits<Windows::UI::Xaml::ExceptionRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::ExceptionRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.ExceptionRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::FrameworkElement>
{
    using abi = ABI::Windows::UI::Xaml::FrameworkElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.FrameworkElement"; }
};

template <> struct traits<Windows::UI::Xaml::FrameworkTemplate>
{
    using abi = ABI::Windows::UI::Xaml::FrameworkTemplate;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.FrameworkTemplate"; }
};

template <> struct traits<Windows::UI::Xaml::FrameworkView>
{
    using abi = ABI::Windows::UI::Xaml::FrameworkView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.FrameworkView"; }
};

template <> struct traits<Windows::UI::Xaml::FrameworkViewSource>
{
    using abi = ABI::Windows::UI::Xaml::FrameworkViewSource;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.FrameworkViewSource"; }
};

template <> struct traits<Windows::UI::Xaml::GridLengthHelper>
{
    using abi = ABI::Windows::UI::Xaml::GridLengthHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.GridLengthHelper"; }
};

template <> struct traits<Windows::UI::Xaml::MediaFailedRoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::MediaFailedRoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.MediaFailedRoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::PointHelper>
{
    using abi = ABI::Windows::UI::Xaml::PointHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.PointHelper"; }
};

template <> struct traits<Windows::UI::Xaml::PropertyMetadata>
{
    using abi = ABI::Windows::UI::Xaml::PropertyMetadata;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.PropertyMetadata"; }
};

template <> struct traits<Windows::UI::Xaml::PropertyPath>
{
    using abi = ABI::Windows::UI::Xaml::PropertyPath;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.PropertyPath"; }
};

template <> struct traits<Windows::UI::Xaml::RectHelper>
{
    using abi = ABI::Windows::UI::Xaml::RectHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.RectHelper"; }
};

template <> struct traits<Windows::UI::Xaml::ResourceDictionary>
{
    using abi = ABI::Windows::UI::Xaml::ResourceDictionary;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.ResourceDictionary"; }
};

template <> struct traits<Windows::UI::Xaml::RoutedEvent>
{
    using abi = ABI::Windows::UI::Xaml::RoutedEvent;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.RoutedEvent"; }
};

template <> struct traits<Windows::UI::Xaml::RoutedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::RoutedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.RoutedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::Setter>
{
    using abi = ABI::Windows::UI::Xaml::Setter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Setter"; }
};

template <> struct traits<Windows::UI::Xaml::SetterBase>
{
    using abi = ABI::Windows::UI::Xaml::SetterBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.SetterBase"; }
};

template <> struct traits<Windows::UI::Xaml::SetterBaseCollection>
{
    using abi = ABI::Windows::UI::Xaml::SetterBaseCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.SetterBaseCollection"; }
};

template <> struct traits<Windows::UI::Xaml::SizeChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::SizeChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.SizeChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::SizeHelper>
{
    using abi = ABI::Windows::UI::Xaml::SizeHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.SizeHelper"; }
};

template <> struct traits<Windows::UI::Xaml::StateTrigger>
{
    using abi = ABI::Windows::UI::Xaml::StateTrigger;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.StateTrigger"; }
};

template <> struct traits<Windows::UI::Xaml::StateTriggerBase>
{
    using abi = ABI::Windows::UI::Xaml::StateTriggerBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.StateTriggerBase"; }
};

template <> struct traits<Windows::UI::Xaml::Style>
{
    using abi = ABI::Windows::UI::Xaml::Style;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Style"; }
};

template <> struct traits<Windows::UI::Xaml::TargetPropertyPath>
{
    using abi = ABI::Windows::UI::Xaml::TargetPropertyPath;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.TargetPropertyPath"; }
};

template <> struct traits<Windows::UI::Xaml::ThicknessHelper>
{
    using abi = ABI::Windows::UI::Xaml::ThicknessHelper;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.ThicknessHelper"; }
};

template <> struct traits<Windows::UI::Xaml::TriggerAction>
{
    using abi = ABI::Windows::UI::Xaml::TriggerAction;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.TriggerAction"; }
};

template <> struct traits<Windows::UI::Xaml::TriggerActionCollection>
{
    using abi = ABI::Windows::UI::Xaml::TriggerActionCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.TriggerActionCollection"; }
};

template <> struct traits<Windows::UI::Xaml::TriggerBase>
{
    using abi = ABI::Windows::UI::Xaml::TriggerBase;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.TriggerBase"; }
};

template <> struct traits<Windows::UI::Xaml::TriggerCollection>
{
    using abi = ABI::Windows::UI::Xaml::TriggerCollection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.TriggerCollection"; }
};

template <> struct traits<Windows::UI::Xaml::UIElement>
{
    using abi = ABI::Windows::UI::Xaml::UIElement;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.UIElement"; }
};

template <> struct traits<Windows::UI::Xaml::UnhandledExceptionEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::UnhandledExceptionEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.UnhandledExceptionEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::VisualState>
{
    using abi = ABI::Windows::UI::Xaml::VisualState;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.VisualState"; }
};

template <> struct traits<Windows::UI::Xaml::VisualStateChangedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::VisualStateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.VisualStateChangedEventArgs"; }
};

template <> struct traits<Windows::UI::Xaml::VisualStateGroup>
{
    using abi = ABI::Windows::UI::Xaml::VisualStateGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.VisualStateGroup"; }
};

template <> struct traits<Windows::UI::Xaml::VisualStateManager>
{
    using abi = ABI::Windows::UI::Xaml::VisualStateManager;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.VisualStateManager"; }
};

template <> struct traits<Windows::UI::Xaml::VisualTransition>
{
    using abi = ABI::Windows::UI::Xaml::VisualTransition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.VisualTransition"; }
};

template <> struct traits<Windows::UI::Xaml::Window>
{
    using abi = ABI::Windows::UI::Xaml::Window;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.Window"; }
};

template <> struct traits<Windows::UI::Xaml::WindowCreatedEventArgs>
{
    using abi = ABI::Windows::UI::Xaml::WindowCreatedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.UI.Xaml.WindowCreatedEventArgs"; }
};

}

}
