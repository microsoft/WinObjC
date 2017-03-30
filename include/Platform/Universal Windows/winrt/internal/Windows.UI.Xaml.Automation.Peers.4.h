// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Automation::Peers {

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
class IAutomationPeerOverridesT : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides;

    Windows::Foundation::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface)
    {
        return shim().as<IAutomationPeerOverrides>().GetPatternCore(patternInterface);
    }

    hstring GetAcceleratorKeyCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAcceleratorKeyCore();
    }

    hstring GetAccessKeyCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAccessKeyCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAutomationControlTypeCore();
    }

    hstring GetAutomationIdCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetAutomationIdCore();
    }

    Windows::Foundation::Rect GetBoundingRectangleCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetBoundingRectangleCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetChildrenCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetChildrenCore();
    }

    hstring GetClassNameCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetClassNameCore();
    }

    Windows::Foundation::Point GetClickablePointCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetClickablePointCore();
    }

    hstring GetHelpTextCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetHelpTextCore();
    }

    hstring GetItemStatusCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetItemStatusCore();
    }

    hstring GetItemTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetItemTypeCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetLabeledByCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLabeledByCore();
    }

    hstring GetLocalizedControlTypeCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLocalizedControlTypeCore();
    }

    hstring GetNameCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetNameCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationOrientation GetOrientationCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetOrientationCore();
    }

    bool HasKeyboardFocusCore()
    {
        return shim().as<IAutomationPeerOverrides>().HasKeyboardFocusCore();
    }

    bool IsContentElementCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsContentElementCore();
    }

    bool IsControlElementCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsControlElementCore();
    }

    bool IsEnabledCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsEnabledCore();
    }

    bool IsKeyboardFocusableCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsKeyboardFocusableCore();
    }

    bool IsOffscreenCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsOffscreenCore();
    }

    bool IsPasswordCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsPasswordCore();
    }

    bool IsRequiredForFormCore()
    {
        return shim().as<IAutomationPeerOverrides>().IsRequiredForFormCore();
    }

    void SetFocusCore()
    {
        shim().as<IAutomationPeerOverrides>().SetFocusCore();
    }

    Windows::UI::Xaml::Automation::Peers::AutomationPeer GetPeerFromPointCore(const Windows::Foundation::Point & point)
    {
        return shim().as<IAutomationPeerOverrides>().GetPeerFromPointCore(point);
    }

    Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting GetLiveSettingCore()
    {
        return shim().as<IAutomationPeerOverrides>().GetLiveSettingCore();
    }

    HRESULT __stdcall abi_GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface patternInterface, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPatternCore(patternInterface));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAcceleratorKeyCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAcceleratorKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAccessKeyCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAccessKeyCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationControlTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationControlType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAutomationIdCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAutomationIdCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetBoundingRectangleCore(impl::abi_arg_out<Windows::Foundation::Rect> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetBoundingRectangleCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChildrenCore(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetChildrenCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClassNameCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClassNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetClickablePointCore(impl::abi_arg_out<Windows::Foundation::Point> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetClickablePointCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetHelpTextCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetHelpTextCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemStatusCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemStatusCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetItemTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetItemTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLabeledByCore(impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLabeledByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedControlTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedControlTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetNameCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetOrientationCore(Windows::UI::Xaml::Automation::Peers::AutomationOrientation * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetOrientationCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_HasKeyboardFocusCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HasKeyboardFocusCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsContentElementCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsContentElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsControlElementCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsControlElementCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsEnabledCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsEnabledCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsKeyboardFocusableCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsKeyboardFocusableCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsOffscreenCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsOffscreenCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsPasswordCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPasswordCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsRequiredForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsRequiredForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetFocusCore() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPeerFromPointCore(impl::abi_arg_in<Windows::Foundation::Point> point, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPeerFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&point)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLiveSettingCore(Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLiveSettingCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
class IAutomationPeerOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides2 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2;

    void ShowContextMenuCore()
    {
        shim().as<IAutomationPeerOverrides2>().ShowContextMenuCore();
    }

    Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetControlledPeersCore()
    {
        return shim().as<IAutomationPeerOverrides2>().GetControlledPeersCore();
    }

    HRESULT __stdcall abi_ShowContextMenuCore() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContextMenuCore();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetControlledPeersCore(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetControlledPeersCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
class IAutomationPeerOverrides3T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides3 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3;

    Windows::Foundation::IInspectable NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction)
    {
        return shim().as<IAutomationPeerOverrides3>().NavigateCore(direction);
    }

    Windows::Foundation::IInspectable GetElementFromPointCore(const Windows::Foundation::Point & pointInWindowCoordinates)
    {
        return shim().as<IAutomationPeerOverrides3>().GetElementFromPointCore(pointInWindowCoordinates);
    }

    Windows::Foundation::IInspectable GetFocusedElementCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetFocusedElementCore();
    }

    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> GetAnnotationsCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetAnnotationsCore();
    }

    int32_t GetPositionInSetCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetPositionInSetCore();
    }

    int32_t GetSizeOfSetCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetSizeOfSetCore();
    }

    int32_t GetLevelCore()
    {
        return shim().as<IAutomationPeerOverrides3>().GetLevelCore();
    }

    HRESULT __stdcall abi_NavigateCore(Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection direction, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().NavigateCore(direction));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetElementFromPointCore(impl::abi_arg_in<Windows::Foundation::Point> pointInWindowCoordinates, impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetElementFromPointCore(*reinterpret_cast<const Windows::Foundation::Point *>(&pointInWindowCoordinates)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFocusedElementCore(impl::abi_arg_out<Windows::Foundation::IInspectable> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFocusedElementCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnnotationsCore(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetAnnotationsCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetPositionInSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetPositionInSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetSizeOfSetCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetSizeOfSetCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLevelCore(int32_t * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLevelCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
class IAutomationPeerOverrides4T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides4 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4;

    Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType GetLandmarkTypeCore()
    {
        return shim().as<IAutomationPeerOverrides4>().GetLandmarkTypeCore();
    }

    hstring GetLocalizedLandmarkTypeCore()
    {
        return shim().as<IAutomationPeerOverrides4>().GetLocalizedLandmarkTypeCore();
    }

    HRESULT __stdcall abi_GetLandmarkTypeCore(Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetLocalizedLandmarkTypeCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetLocalizedLandmarkTypeCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
class IAutomationPeerOverrides5T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IAutomationPeerOverrides5 = winrt::Windows::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5;

    bool IsPeripheralCore()
    {
        return shim().as<IAutomationPeerOverrides5>().IsPeripheralCore();
    }

    bool IsDataValidForFormCore()
    {
        return shim().as<IAutomationPeerOverrides5>().IsDataValidForFormCore();
    }

    hstring GetFullDescriptionCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFullDescriptionCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetDescribedByCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetDescribedByCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsToCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFlowsToCore();
    }

    Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer> GetFlowsFromCore()
    {
        return shim().as<IAutomationPeerOverrides5>().GetFlowsFromCore();
    }

    HRESULT __stdcall abi_IsPeripheralCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsPeripheralCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsDataValidForFormCore(bool * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().IsDataValidForFormCore());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFullDescriptionCore(impl::abi_arg_out<hstring> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFullDescriptionCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDescribedByCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetDescribedByCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsToCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlowsToCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetFlowsFromCore(impl::abi_arg_out<Windows::Foundation::Collections::IIterable<Windows::UI::Xaml::Automation::Peers::AutomationPeer>> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().GetFlowsFromCore());
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D, typename A = ABI::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
class IItemsControlAutomationPeerOverrides2T : public A
{
    D & shim() noexcept { return *static_cast<D *>(this); }

public:

    using IItemsControlAutomationPeerOverrides2 = winrt::Windows::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2;

    Windows::UI::Xaml::Automation::Peers::ItemAutomationPeer OnCreateItemAutomationPeer(const Windows::Foundation::IInspectable & item)
    {
        return shim().as<IItemsControlAutomationPeerOverrides2>().OnCreateItemAutomationPeer(item);
    }

    HRESULT __stdcall abi_OnCreateItemAutomationPeer(impl::abi_arg_in<Windows::Foundation::IInspectable> item, impl::abi_arg_out<Windows::UI::Xaml::Automation::Peers::IItemAutomationPeer> returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().OnCreateItemAutomationPeer(*reinterpret_cast<const Windows::Foundation::IInspectable *>(&item)));
            return S_OK;
        }
        catch (...)
        {
            *returnValue = nullptr;
            return impl::to_hresult();
        }
    }
};

}

}
