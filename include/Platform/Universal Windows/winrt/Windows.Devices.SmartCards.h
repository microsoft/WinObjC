// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Storage.Streams.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Security.Cryptography.Core.3.h"
#include "internal/Windows.Devices.SmartCards.3.h"
#include "Windows.Devices.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Devices::SmartCards {

template <typename L> SmartCardPinResetHandler::SmartCardPinResetHandler(L lambda) :
    SmartCardPinResetHandler(impl::make_delegate<impl_SmartCardPinResetHandler<L>, SmartCardPinResetHandler>(std::forward<L>(lambda)))
{}

template <typename F> SmartCardPinResetHandler::SmartCardPinResetHandler(F * function) :
    SmartCardPinResetHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> SmartCardPinResetHandler::SmartCardPinResetHandler(O * object, M method) :
    SmartCardPinResetHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void SmartCardPinResetHandler::operator()(const Windows::Devices::SmartCards::SmartCardProvisioning & sender, const Windows::Devices::SmartCards::SmartCardPinResetRequest & request) const
{
    check_hresult((*(abi<SmartCardPinResetHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(request)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ICardAddedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ICardAddedEventArgs>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ICardRemovedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ICardRemovedEventArgs>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCard> : produce_base<D, Windows::Devices::SmartCards::ISmartCard>
{
    HRESULT __stdcall get_Reader(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardReader> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reader());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatusAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStatusAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAnswerToResetAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAnswerToResetAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroup> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroup>
{
    HRESULT __stdcall get_DisplayName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DisplayName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_DisplayName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppletIds(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppletIds());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmartCardEmulationCategory(Windows::Devices::SmartCards::SmartCardEmulationCategory * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCardEmulationCategory());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmartCardEmulationCategory(Windows::Devices::SmartCards::SmartCardEmulationCategory value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmartCardEmulationCategory(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SmartCardEmulationType(Windows::Devices::SmartCards::SmartCardEmulationType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCardEmulationType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SmartCardEmulationType(Windows::Devices::SmartCards::SmartCardEmulationType value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmartCardEmulationType(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutomaticEnablement(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutomaticEnablement());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutomaticEnablement(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomaticEnablement(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<hstring> displayName, impl::abi_arg_in<Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer>> appletIds, Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, Windows::Devices::SmartCards::SmartCardEmulationType emulationType, impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardAppletIdGroup> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const hstring *>(&displayName), *reinterpret_cast<const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> *>(&appletIds), emulationCategory, emulationType));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>
{
    HRESULT __stdcall get_ActivationPolicy(Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ActivationPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppletIdGroup(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardAppletIdGroup> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppletIdGroup());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestActivationPolicyChangeAsync(Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy policy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestActivationPolicyChangeAsync(policy));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetAutomaticResponseApdusAsync(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu>> apdus, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SetAutomaticResponseApdusAsync(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> *>(&apdus)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAppletIdGroupStatics>
{
    HRESULT __stdcall get_MaxAppletIds(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAppletIds());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu>
{
    HRESULT __stdcall get_CommandApdu(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandApdu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommandApdu(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandApdu(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CommandApduBitMask(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandApduBitMask());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CommandApduBitMask(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandApduBitMask(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShouldMatchLength(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShouldMatchLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShouldMatchLength(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShouldMatchLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AppletId(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AppletId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AppletId(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppletId(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ResponseApdu(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ResponseApdu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ResponseApdu(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResponseApdu(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>
{
    HRESULT __stdcall get_InputState(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InputState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InputState(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputState(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_OutputState(impl::abi_arg_out<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OutputState());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_OutputState(impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OutputState(*reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
{
    HRESULT __stdcall get_AllowWhenCryptogramGeneratorNotPrepared(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AllowWhenCryptogramGeneratorNotPrepared());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AllowWhenCryptogramGeneratorNotPrepared(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowWhenCryptogramGeneratorNotPrepared(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory> : produce_base<D, Windows::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> commandApdu, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> responseApdu, impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardAutomaticResponseApdu> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&commandApdu), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&responseApdu)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardChallengeContext> : produce_base<D, Windows::Devices::SmartCards::ISmartCardChallengeContext>
{
    HRESULT __stdcall get_Challenge(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Challenge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_VerifyResponseAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().VerifyResponseAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, bool formatCard, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProvisionAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), formatCard));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ProvisionAsyncWithNewCardId(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, bool formatCard, GUID newCardId, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ProvisionAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), formatCard, newCardId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ChangeAdministrativeKeyAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> newAdministrativeKey, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ChangeAdministrativeKeyAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&newAdministrativeKey)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardConnect> : produce_base<D, Windows::Devices::SmartCards::ISmartCardConnect>
{
    HRESULT __stdcall abi_ConnectAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ConnectAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardConnection> : produce_base<D, Windows::Devices::SmartCards::ISmartCardConnection>
{
    HRESULT __stdcall abi_TransmitAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> command, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TransmitAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&command)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramGenerator> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramGenerator>
{
    HRESULT __stdcall get_SupportedCryptogramMaterialTypes(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedCryptogramMaterialTypes());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCryptogramAlgorithms(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedCryptogramAlgorithms());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCryptogramMaterialPackageFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedCryptogramMaterialPackageFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedCryptogramMaterialPackageConfirmationResponseFormats(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedCryptogramMaterialPackageConfirmationResponseFormats());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedSmartCardCryptogramStorageKeyCapabilities(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().SupportedSmartCardCryptogramStorageKeyCapabilities());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteCryptogramMaterialStorageKeyAsync(impl::abi_arg_in<hstring> storageKeyName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteCryptogramMaterialStorageKeyAsync(*reinterpret_cast<const hstring *>(&storageKeyName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateCryptogramMaterialStorageKeyAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, impl::abi_arg_in<hstring> storageKeyName, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm algorithm, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities capabilities, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().CreateCryptogramMaterialStorageKeyAsync(promptingBehavior, *reinterpret_cast<const hstring *>(&storageKeyName), algorithm, capabilities));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestCryptogramMaterialStorageKeyInfoAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, impl::abi_arg_in<hstring> storageKeyName, Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType format, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestCryptogramMaterialStorageKeyInfoAsync(promptingBehavior, *reinterpret_cast<const hstring *>(&storageKeyName), format));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_ImportCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat format, impl::abi_arg_in<hstring> storageKeyName, impl::abi_arg_in<hstring> materialPackageName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> cryptogramMaterialPackage, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().ImportCryptogramMaterialPackageAsync(format, *reinterpret_cast<const hstring *>(&storageKeyName), *reinterpret_cast<const hstring *>(&materialPackageName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&cryptogramMaterialPackage)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryProvePossessionOfCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat responseFormat, impl::abi_arg_in<hstring> materialPackageName, impl::abi_arg_in<hstring> materialName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> challenge, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryProvePossessionOfCryptogramMaterialPackageAsync(promptingBehavior, responseFormat, *reinterpret_cast<const hstring *>(&materialPackageName), *reinterpret_cast<const hstring *>(&materialName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&challenge)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestUnlockCryptogramMaterialForUseAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestUnlockCryptogramMaterialForUseAsync(promptingBehavior));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_DeleteCryptogramMaterialPackageAsync(impl::abi_arg_in<hstring> materialPackageName, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().DeleteCryptogramMaterialPackageAsync(*reinterpret_cast<const hstring *>(&materialPackageName)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>
{
    HRESULT __stdcall abi_GetSmartCardCryptogramGeneratorAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetSmartCardCryptogramGeneratorAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>
{
    HRESULT __stdcall get_OperationStatus(Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OperationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Proof(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Proof());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep>
{
    HRESULT __stdcall get_Algorithm(Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Algorithm());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Algorithm(Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Algorithm(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SourceData(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceData(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CryptogramMaterialPackageName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CryptogramMaterialPackageName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CryptogramMaterialPackageName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CryptogramMaterialPackageName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CryptogramMaterialName(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CryptogramMaterialName());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CryptogramMaterialName(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CryptogramMaterialName(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TemplateOffset(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TemplateOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_TemplateOffset(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TemplateOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CryptogramOffset(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CryptogramOffset());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CryptogramOffset(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CryptogramOffset(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CryptogramLength(int32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CryptogramLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CryptogramLength(int32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CryptogramLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_CryptogramPlacementOptions(Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CryptogramPlacementOptions());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_CryptogramPlacementOptions(Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CryptogramPlacementOptions(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ChainedOutputStep(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ChainedOutputStep());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ChainedOutputStep(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardCryptogramPlacementStep> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChainedOutputStep(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>
{
    HRESULT __stdcall get_OperationStatus(Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OperationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublicKeyBlobType(Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicKeyBlobType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PublicKey(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PublicKey());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttestationStatus(Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttestationStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Attestation(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Attestation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AttestationCertificateChain(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AttestationCertificateChain());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Capabilities(Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Capabilities());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
{
    HRESULT __stdcall get_OperationalRequirements(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().OperationalRequirements());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulator> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulator>
{
    HRESULT __stdcall get_EnablementPolicy(Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EnablementPolicy());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulator2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulator2>
{
    HRESULT __stdcall add_ApduReceived(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ApduReceived(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ApduReceived(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApduReceived(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ConnectionDeactivated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs>> value, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().ConnectionDeactivated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ConnectionDeactivated(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionDeactivated(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Start() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_IsHostCardEmulationSupported(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsHostCardEmulationSupported());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>
{
    HRESULT __stdcall get_CommandApdu(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CommandApdu());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ConnectionProperties(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRespondAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> responseApdu, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryRespondAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&responseApdu)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AutomaticResponseStatus(Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutomaticResponseStatus());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>
{
    HRESULT __stdcall get_State(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRespondWithStateAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> responseApdu, impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> nextState, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryRespondAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&responseApdu), *reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&nextState)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
{
    HRESULT __stdcall abi_TryRespondWithCryptogramsAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> responseTemplate, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep>> cryptogramPlacementSteps, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryRespondWithCryptogramsAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&responseTemplate), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> *>(&cryptogramPlacementSteps)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryRespondWithCryptogramsAndStateAsync(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> responseTemplate, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep>> cryptogramPlacementSteps, impl::abi_arg_in<Windows::Foundation::IReference<uint32_t>> nextState, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryRespondWithCryptogramsAsync(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&responseTemplate), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> *>(&cryptogramPlacementSteps), *reinterpret_cast<const Windows::Foundation::IReference<uint32_t> *>(&nextState)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>
{
    HRESULT __stdcall get_ConnectionProperties(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ConnectionProperties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Reason(Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Reason());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>
{
    HRESULT __stdcall get_Id(GUID * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Id());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Source(Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Source());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorStatics>
{
    HRESULT __stdcall abi_GetDefaultAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDefaultAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardEmulatorStatics2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardEmulatorStatics2>
{
    HRESULT __stdcall abi_GetAppletIdGroupRegistrationsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAppletIdGroupRegistrationsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RegisterAppletIdGroupAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardAppletIdGroup> appletIdGroup, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RegisterAppletIdGroupAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardAppletIdGroup *>(&appletIdGroup)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_UnregisterAppletIdGroupAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardAppletIdGroupRegistration> registration, impl::abi_arg_out<Windows::Foundation::IAsyncAction> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().UnregisterAppletIdGroupAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration *>(&registration)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxAppletIdGroupRegistrations(uint16_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxAppletIdGroupRegistrations());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinPolicy> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinPolicy>
{
    HRESULT __stdcall get_MinLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MinLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MinLength(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_MaxLength(uint32_t * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().MaxLength());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_MaxLength(uint32_t value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxLength(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UppercaseLetters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UppercaseLetters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().LowercaseLetters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LowercaseLetters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Digits());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Digits(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SpecialCharacters());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecialCharacters(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinResetDeferral> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinResetDeferral>
{
    HRESULT __stdcall abi_Complete() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardPinResetRequest> : produce_base<D, Windows::Devices::SmartCards::ISmartCardPinResetRequest>
{
    HRESULT __stdcall get_Challenge(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Challenge());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Deadline(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Deadline());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeferral(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardPinResetDeferral> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetDeferral());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetResponse(impl::abi_arg_in<Windows::Storage::Streams::IBuffer> response) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetResponse(*reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&response));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioning> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioning>
{
    HRESULT __stdcall get_SmartCard(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCard> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SmartCard());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetIdAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<GUID>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetIdAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetNameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetNameAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetChallengeContextAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetChallengeContextAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPinChangeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestPinChangeAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestPinResetAsync(impl::abi_arg_in<Windows::Devices::SmartCards::SmartCardPinResetHandler> handler, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestPinResetAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinResetHandler *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioning2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioning2>
{
    HRESULT __stdcall abi_GetAuthorityKeyContainerNameAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<hstring>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetAuthorityKeyContainerNameAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics>
{
    HRESULT __stdcall abi_FromSmartCardAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCard> card, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromSmartCardAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCard *>(&card)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsync(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardCreationAsyncWithCardId(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, GUID cardId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy), cardId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestVirtualSmartCardDeletionAsync(impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCard> card, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestVirtualSmartCardDeletionAsync(*reinterpret_cast<const Windows::Devices::SmartCards::SmartCard *>(&card)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardProvisioningStatics2>
{
    HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsync(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAttestedVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RequestAttestedVirtualSmartCardCreationAsyncWithCardId(impl::abi_arg_in<hstring> friendlyName, impl::abi_arg_in<Windows::Storage::Streams::IBuffer> administrativeKey, impl::abi_arg_in<Windows::Devices::SmartCards::ISmartCardPinPolicy> pinPolicy, GUID cardId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().RequestAttestedVirtualSmartCardCreationAsync(*reinterpret_cast<const hstring *>(&friendlyName), *reinterpret_cast<const Windows::Storage::Streams::IBuffer *>(&administrativeKey), *reinterpret_cast<const Windows::Devices::SmartCards::SmartCardPinPolicy *>(&pinPolicy), cardId));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardReader> : produce_base<D, Windows::Devices::SmartCards::ISmartCardReader>
{
    HRESULT __stdcall get_DeviceId(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().DeviceId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Kind(Windows::Devices::SmartCards::SmartCardReaderKind * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Kind());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetStatusAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().GetStatusAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FindAllCardsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FindAllCardsAsync());
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CardAdded(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CardAdded(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CardAdded(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardAdded(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_CardRemoved(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs>> handler, event_token * token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *token = detach_abi(this->shim().CardRemoved(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> *>(&handler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_CardRemoved(event_token token) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CardRemoved(token);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardReaderStatics> : produce_base<D, Windows::Devices::SmartCards::ISmartCardReaderStatics>
{
    HRESULT __stdcall abi_GetDeviceSelector(impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector());
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetDeviceSelectorWithKind(Windows::Devices::SmartCards::SmartCardReaderKind kind, impl::abi_arg_out<hstring> selector) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *selector = detach_abi(this->shim().GetDeviceSelector(kind));
            return S_OK;
        }
        catch (...)
        {
            *selector = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_FromIdAsync(impl::abi_arg_in<hstring> deviceId, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().FromIdAsync(*reinterpret_cast<const hstring *>(&deviceId)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardTriggerDetails> : produce_base<D, Windows::Devices::SmartCards::ISmartCardTriggerDetails>
{
    HRESULT __stdcall get_TriggerType(Windows::Devices::SmartCards::SmartCardTriggerType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriggerType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourceAppletId(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourceAppletId());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TriggerData(impl::abi_arg_out<Windows::Storage::Streams::IBuffer> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TriggerData());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Devices::SmartCards::ISmartCardTriggerDetails2> : produce_base<D, Windows::Devices::SmartCards::ISmartCardTriggerDetails2>
{
    HRESULT __stdcall get_Emulator(impl::abi_arg_out<Windows::Devices::SmartCards::ISmartCardEmulator> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Emulator());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryLaunchCurrentAppAsync(impl::abi_arg_in<hstring> arguments, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryLaunchCurrentAppAsync(*reinterpret_cast<const hstring *>(&arguments)));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_TryLaunchCurrentAppWithBehaviorAsync(impl::abi_arg_in<hstring> arguments, Windows::Devices::SmartCards::SmartCardLaunchBehavior behavior, impl::abi_arg_out<Windows::Foundation::IAsyncOperation<bool>> result) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_abi(this->shim().TryLaunchCurrentAppAsync(*reinterpret_cast<const hstring *>(&arguments), behavior));
            return S_OK;
        }
        catch (...)
        {
            *result = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Devices::SmartCards {

template <typename D> hstring impl_ISmartCardReaderStatics<D>::GetDeviceSelector() const
{
    hstring selector;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_GetDeviceSelector(put_abi(selector)));
    return selector;
}

template <typename D> hstring impl_ISmartCardReaderStatics<D>::GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind) const
{
    hstring selector;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_GetDeviceSelectorWithKind(kind, put_abi(selector)));
    return selector;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> impl_ISmartCardReaderStatics<D>::FromIdAsync(hstring_view deviceId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> result;
    check_hresult(WINRT_SHIM(ISmartCardReaderStatics)->abi_FromIdAsync(get_abi(deviceId), put_abi(result)));
    return result;
}

template <typename D> hstring impl_ISmartCardReader<D>::DeviceId() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_DeviceId(put_abi(value)));
    return value;
}

template <typename D> hstring impl_ISmartCardReader<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardReaderKind impl_ISmartCardReader<D>::Kind() const
{
    Windows::Devices::SmartCards::SmartCardReaderKind value {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->get_Kind(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> impl_ISmartCardReader<D>::GetStatusAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardReaderStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardReader)->abi_GetStatusAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> impl_ISmartCardReader<D>::FindAllCardsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCard>> result;
    check_hresult(WINRT_SHIM(ISmartCardReader)->abi_FindAllCardsAsync(put_abi(result)));
    return result;
}

template <typename D> event_token impl_ISmartCardReader<D>::CardAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->add_CardAdded(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardReader> impl_ISmartCardReader<D>::CardAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardAddedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISmartCardReader>(this, &ABI::Windows::Devices::SmartCards::ISmartCardReader::remove_CardAdded, CardAdded(handler));
}

template <typename D> void impl_ISmartCardReader<D>::CardAdded(event_token token) const
{
    check_hresult(WINRT_SHIM(ISmartCardReader)->remove_CardAdded(token));
}

template <typename D> event_token impl_ISmartCardReader<D>::CardRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardReader)->add_CardRemoved(get_abi(handler), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardReader> impl_ISmartCardReader<D>::CardRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardReader, Windows::Devices::SmartCards::CardRemovedEventArgs> & handler) const
{
    return impl::make_event_revoker<D, ISmartCardReader>(this, &ABI::Windows::Devices::SmartCards::ISmartCardReader::remove_CardRemoved, CardRemoved(handler));
}

template <typename D> void impl_ISmartCardReader<D>::CardRemoved(event_token token) const
{
    check_hresult(WINRT_SHIM(ISmartCardReader)->remove_CardRemoved(token));
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ICardAddedEventArgs<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ICardAddedEventArgs)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ICardRemovedEventArgs<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ICardRemovedEventArgs)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardReader impl_ISmartCard<D>::Reader() const
{
    Windows::Devices::SmartCards::SmartCardReader value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCard)->get_Reader(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> impl_ISmartCard<D>::GetStatusAsync() const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardStatus> result;
    check_hresult(WINRT_SHIM(ISmartCard)->abi_GetStatusAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ISmartCard<D>::GetAnswerToResetAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> result;
    check_hresult(WINRT_SHIM(ISmartCard)->abi_GetAnswerToResetAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_FromSmartCardAsync(get_abi(card), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardCreationAsync(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardCreationAsyncWithCardId(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), cardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioningStatics<D>::RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics)->abi_RequestVirtualSmartCardDeletionAsync(get_abi(card), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics2<D>::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics2)->abi_RequestAttestedVirtualSmartCardCreationAsync(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> impl_ISmartCardProvisioningStatics2<D>::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioningStatics2)->abi_RequestAttestedVirtualSmartCardCreationAsyncWithCardId(get_abi(friendlyName), get_abi(administrativeKey), get_abi(pinPolicy), cardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCard impl_ISmartCardProvisioning<D>::SmartCard() const
{
    Windows::Devices::SmartCards::SmartCard value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->get_SmartCard(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<GUID> impl_ISmartCardProvisioning<D>::GetIdAsync() const
{
    Windows::Foundation::IAsyncOperation<GUID> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetIdAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ISmartCardProvisioning<D>::GetNameAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetNameAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> impl_ISmartCardProvisioning<D>::GetChallengeContextAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardChallengeContext> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_GetChallengeContextAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioning<D>::RequestPinChangeAsync() const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_RequestPinChangeAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardProvisioning<D>::RequestPinResetAsync(const Windows::Devices::SmartCards::SmartCardPinResetHandler & handler) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning)->abi_RequestPinResetAsync(get_abi(handler), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<hstring> impl_ISmartCardProvisioning2<D>::GetAuthorityKeyContainerNameAsync() const
{
    Windows::Foundation::IAsyncOperation<hstring> result;
    check_hresult(WINRT_SHIM(ISmartCardProvisioning2)->abi_GetAuthorityKeyContainerNameAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardPinResetRequest<D>::Challenge() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->get_Challenge(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::DateTime impl_ISmartCardPinResetRequest<D>::Deadline() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->get_Deadline(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinResetDeferral impl_ISmartCardPinResetRequest<D>::GetDeferral() const
{
    Windows::Devices::SmartCards::SmartCardPinResetDeferral result { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->abi_GetDeferral(put_abi(result)));
    return result;
}

template <typename D> void impl_ISmartCardPinResetRequest<D>::SetResponse(const Windows::Storage::Streams::IBuffer & response) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinResetRequest)->abi_SetResponse(get_abi(response)));
}

template <typename D> void impl_ISmartCardPinResetDeferral<D>::Complete() const
{
    check_hresult(WINRT_SHIM(ISmartCardPinResetDeferral)->abi_Complete());
}

template <typename D> uint32_t impl_ISmartCardPinPolicy<D>::MinLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_MinLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::MinLength(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_MinLength(value));
}

template <typename D> uint32_t impl_ISmartCardPinPolicy<D>::MaxLength() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_MaxLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::MaxLength(uint32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_MaxLength(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::UppercaseLetters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_UppercaseLetters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::UppercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_UppercaseLetters(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::LowercaseLetters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_LowercaseLetters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::LowercaseLetters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_LowercaseLetters(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::Digits() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_Digits(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::Digits(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_Digits(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption impl_ISmartCardPinPolicy<D>::SpecialCharacters() const
{
    Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value {};
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->get_SpecialCharacters(&value));
    return value;
}

template <typename D> void impl_ISmartCardPinPolicy<D>::SpecialCharacters(Windows::Devices::SmartCards::SmartCardPinCharacterPolicyOption value) const
{
    check_hresult(WINRT_SHIM(ISmartCardPinPolicy)->put_SpecialCharacters(value));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> impl_ISmartCardConnect<D>::ConnectAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardConnection> result;
    check_hresult(WINRT_SHIM(ISmartCardConnect)->abi_ConnectAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardChallengeContext<D>::Challenge() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->get_Challenge(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardChallengeContext<D>::VerifyResponseAsync(const Windows::Storage::Streams::IBuffer & response) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_VerifyResponseAsync(get_abi(response), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ProvisionAsync(get_abi(response), formatCard, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ProvisionAsync(const Windows::Storage::Streams::IBuffer & response, bool formatCard, GUID newCardId) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ProvisionAsyncWithNewCardId(get_abi(response), formatCard, newCardId, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardChallengeContext<D>::ChangeAdministrativeKeyAsync(const Windows::Storage::Streams::IBuffer & response, const Windows::Storage::Streams::IBuffer & newAdministrativeKey) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardChallengeContext)->abi_ChangeAdministrativeKeyAsync(get_abi(response), get_abi(newAdministrativeKey), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> impl_ISmartCardConnection<D>::TransmitAsync(const Windows::Storage::Streams::IBuffer & command) const
{
    Windows::Foundation::IAsyncOperation<Windows::Storage::Streams::IBuffer> result;
    check_hresult(WINRT_SHIM(ISmartCardConnection)->abi_TransmitAsync(get_abi(command), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCardTriggerType impl_ISmartCardTriggerDetails<D>::TriggerType() const
{
    Windows::Devices::SmartCards::SmartCardTriggerType value {};
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails)->get_TriggerType(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardTriggerDetails<D>::SourceAppletId() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails)->get_SourceAppletId(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardTriggerDetails<D>::TriggerData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails)->get_TriggerData(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulator impl_ISmartCardTriggerDetails2<D>::Emulator() const
{
    Windows::Devices::SmartCards::SmartCardEmulator value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails2)->get_Emulator(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardTriggerDetails2<D>::TryLaunchCurrentAppAsync(hstring_view arguments) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails2)->abi_TryLaunchCurrentAppAsync(get_abi(arguments), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardTriggerDetails2<D>::TryLaunchCurrentAppAsync(hstring_view arguments, Windows::Devices::SmartCards::SmartCardLaunchBehavior behavior) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardTriggerDetails2)->abi_TryLaunchCurrentAppWithBehaviorAsync(get_abi(arguments), behavior, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> impl_ISmartCardEmulatorStatics<D>::GetDefaultAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorStatics)->abi_GetDefaultAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> impl_ISmartCardEmulatorStatics2<D>::GetAppletIdGroupRegistrationsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorStatics2)->abi_GetAppletIdGroupRegistrationsAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> impl_ISmartCardEmulatorStatics2<D>::RegisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroup & appletIdGroup) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorStatics2)->abi_RegisterAppletIdGroupAsync(get_abi(appletIdGroup), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardEmulatorStatics2<D>::UnregisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration & registration) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorStatics2)->abi_UnregisterAppletIdGroupAsync(get_abi(registration), put_abi(result)));
    return result;
}

template <typename D> uint16_t impl_ISmartCardEmulatorStatics2<D>::MaxAppletIdGroupRegistrations() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorStatics2)->get_MaxAppletIdGroupRegistrations(&value));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy impl_ISmartCardEmulator<D>::EnablementPolicy() const
{
    Windows::Devices::SmartCards::SmartCardEmulatorEnablementPolicy value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulator)->get_EnablementPolicy(&value));
    return value;
}

template <typename D> event_token impl_ISmartCardEmulator2<D>::ApduReceived(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->add_ApduReceived(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardEmulator2> impl_ISmartCardEmulator2<D>::ApduReceived(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ISmartCardEmulator2>(this, &ABI::Windows::Devices::SmartCards::ISmartCardEmulator2::remove_ApduReceived, ApduReceived(value));
}

template <typename D> void impl_ISmartCardEmulator2<D>::ApduReceived(event_token value) const
{
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->remove_ApduReceived(value));
}

template <typename D> event_token impl_ISmartCardEmulator2<D>::ConnectionDeactivated(const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> & value) const
{
    event_token token {};
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->add_ConnectionDeactivated(get_abi(value), &token));
    return token;
}

template <typename D> event_revoker<ISmartCardEmulator2> impl_ISmartCardEmulator2<D>::ConnectionDeactivated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::SmartCards::SmartCardEmulator, Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ISmartCardEmulator2>(this, &ABI::Windows::Devices::SmartCards::ISmartCardEmulator2::remove_ConnectionDeactivated, ConnectionDeactivated(value));
}

template <typename D> void impl_ISmartCardEmulator2<D>::ConnectionDeactivated(event_token value) const
{
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->remove_ConnectionDeactivated(value));
}

template <typename D> void impl_ISmartCardEmulator2<D>::Start() const
{
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->abi_Start());
}

template <typename D> bool impl_ISmartCardEmulator2<D>::IsHostCardEmulationSupported() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulator2)->abi_IsHostCardEmulationSupported(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardEmulatorApduReceivedEventArgs<D>::CommandApdu() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs)->get_CommandApdu(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties impl_ISmartCardEmulatorApduReceivedEventArgs<D>::ConnectionProperties() const
{
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs)->get_ConnectionProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardEmulatorApduReceivedEventArgs<D>::TryRespondAsync(const Windows::Storage::Streams::IBuffer & responseApdu) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs)->abi_TryRespondAsync(get_abi(responseApdu), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus impl_ISmartCardEmulatorApduReceivedEventArgs<D>::AutomaticResponseStatus() const
{
    Windows::Devices::SmartCards::SmartCardAutomaticResponseStatus value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs)->get_AutomaticResponseStatus(&value));
    return value;
}

template <typename D> uint32_t impl_ISmartCardEmulatorApduReceivedEventArgs2<D>::State() const
{
    uint32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs2)->get_State(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<bool> impl_ISmartCardEmulatorApduReceivedEventArgs2<D>::TryRespondAsync(const Windows::Storage::Streams::IBuffer & responseApdu, const optional<uint32_t> & nextState) const
{
    Windows::Foundation::IAsyncOperation<bool> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgs2)->abi_TryRespondWithStateAsync(get_abi(responseApdu), get_abi(nextState), put_abi(result)));
    return result;
}

template <typename D> GUID impl_ISmartCardEmulatorConnectionProperties<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorConnectionProperties)->get_Id(&value));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource impl_ISmartCardEmulatorConnectionProperties<D>::Source() const
{
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionSource value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorConnectionProperties)->get_Source(&value));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties impl_ISmartCardEmulatorConnectionDeactivatedEventArgs<D>::ConnectionProperties() const
{
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionProperties value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardEmulatorConnectionDeactivatedEventArgs)->get_ConnectionProperties(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason impl_ISmartCardEmulatorConnectionDeactivatedEventArgs<D>::Reason() const
{
    Windows::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason value {};
    check_hresult(WINRT_SHIM(ISmartCardEmulatorConnectionDeactivatedEventArgs)->get_Reason(&value));
    return value;
}

template <typename D> hstring impl_ISmartCardAppletIdGroup<D>::DisplayName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->get_DisplayName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAppletIdGroup<D>::DisplayName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->put_DisplayName(get_abi(value)));
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> impl_ISmartCardAppletIdGroup<D>::AppletIds() const
{
    Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> value;
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->get_AppletIds(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulationCategory impl_ISmartCardAppletIdGroup<D>::SmartCardEmulationCategory() const
{
    Windows::Devices::SmartCards::SmartCardEmulationCategory value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->get_SmartCardEmulationCategory(&value));
    return value;
}

template <typename D> void impl_ISmartCardAppletIdGroup<D>::SmartCardEmulationCategory(Windows::Devices::SmartCards::SmartCardEmulationCategory value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->put_SmartCardEmulationCategory(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardEmulationType impl_ISmartCardAppletIdGroup<D>::SmartCardEmulationType() const
{
    Windows::Devices::SmartCards::SmartCardEmulationType value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->get_SmartCardEmulationType(&value));
    return value;
}

template <typename D> void impl_ISmartCardAppletIdGroup<D>::SmartCardEmulationType(Windows::Devices::SmartCards::SmartCardEmulationType value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->put_SmartCardEmulationType(value));
}

template <typename D> bool impl_ISmartCardAppletIdGroup<D>::AutomaticEnablement() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->get_AutomaticEnablement(&value));
    return value;
}

template <typename D> void impl_ISmartCardAppletIdGroup<D>::AutomaticEnablement(bool value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroup)->put_AutomaticEnablement(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardAppletIdGroup impl_ISmartCardAppletIdGroupFactory<D>::Create(hstring_view displayName, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> & appletIds, Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, Windows::Devices::SmartCards::SmartCardEmulationType emulationType) const
{
    Windows::Devices::SmartCards::SmartCardAppletIdGroup result { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupFactory)->abi_Create(get_abi(displayName), get_abi(appletIds), emulationCategory, emulationType, put_abi(result)));
    return result;
}

template <typename D> uint16_t impl_ISmartCardAppletIdGroupStatics<D>::MaxAppletIds() const
{
    uint16_t value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupStatics)->get_MaxAppletIds(&value));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy impl_ISmartCardAppletIdGroupRegistration<D>::ActivationPolicy() const
{
    Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupRegistration)->get_ActivationPolicy(&value));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardAppletIdGroup impl_ISmartCardAppletIdGroupRegistration<D>::AppletIdGroup() const
{
    Windows::Devices::SmartCards::SmartCardAppletIdGroup value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupRegistration)->get_AppletIdGroup(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> impl_ISmartCardAppletIdGroupRegistration<D>::RequestActivationPolicyChangeAsync(Windows::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy policy) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardActivationPolicyChangeResult> result;
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupRegistration)->abi_RequestActivationPolicyChangeAsync(policy, put_abi(result)));
    return result;
}

template <typename D> GUID impl_ISmartCardAppletIdGroupRegistration<D>::Id() const
{
    GUID value {};
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupRegistration)->get_Id(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISmartCardAppletIdGroupRegistration<D>::SetAutomaticResponseApdusAsync(iterable<Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu> apdus) const
{
    Windows::Foundation::IAsyncAction result;
    check_hresult(WINRT_SHIM(ISmartCardAppletIdGroupRegistration)->abi_SetAutomaticResponseApdusAsync(get_abi(apdus), put_abi(result)));
    return result;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardAutomaticResponseApdu<D>::CommandApdu() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->get_CommandApdu(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu<D>::CommandApdu(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->put_CommandApdu(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardAutomaticResponseApdu<D>::CommandApduBitMask() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->get_CommandApduBitMask(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu<D>::CommandApduBitMask(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->put_CommandApduBitMask(get_abi(value)));
}

template <typename D> bool impl_ISmartCardAutomaticResponseApdu<D>::ShouldMatchLength() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->get_ShouldMatchLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu<D>::ShouldMatchLength(bool value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->put_ShouldMatchLength(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardAutomaticResponseApdu<D>::AppletId() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->get_AppletId(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu<D>::AppletId(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->put_AppletId(get_abi(value)));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardAutomaticResponseApdu<D>::ResponseApdu() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->get_ResponseApdu(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu<D>::ResponseApdu(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu)->put_ResponseApdu(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ISmartCardAutomaticResponseApdu2<D>::InputState() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu2)->get_InputState(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu2<D>::InputState(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu2)->put_InputState(get_abi(value)));
}

template <typename D> Windows::Foundation::IReference<uint32_t> impl_ISmartCardAutomaticResponseApdu2<D>::OutputState() const
{
    Windows::Foundation::IReference<uint32_t> value;
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu2)->get_OutputState(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu2<D>::OutputState(const optional<uint32_t> & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu2)->put_OutputState(get_abi(value)));
}

template <typename D> bool impl_ISmartCardAutomaticResponseApdu3<D>::AllowWhenCryptogramGeneratorNotPrepared() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu3)->get_AllowWhenCryptogramGeneratorNotPrepared(&value));
    return value;
}

template <typename D> void impl_ISmartCardAutomaticResponseApdu3<D>::AllowWhenCryptogramGeneratorNotPrepared(bool value) const
{
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApdu3)->put_AllowWhenCryptogramGeneratorNotPrepared(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu impl_ISmartCardAutomaticResponseApduFactory<D>::Create(const Windows::Storage::Streams::IBuffer & commandApdu, const Windows::Storage::Streams::IBuffer & responseApdu) const
{
    Windows::Devices::SmartCards::SmartCardAutomaticResponseApdu result { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardAutomaticResponseApduFactory)->abi_Create(get_abi(commandApdu), get_abi(responseApdu), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms<D>::TryRespondWithCryptogramsAsync(const Windows::Storage::Streams::IBuffer & responseTemplate, iterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> cryptogramPlacementSteps) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgsWithCryptograms)->abi_TryRespondWithCryptogramsAsync(get_abi(responseTemplate), get_abi(cryptogramPlacementSteps), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms<D>::TryRespondWithCryptogramsAsync(const Windows::Storage::Streams::IBuffer & responseTemplate, iterable<Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep> cryptogramPlacementSteps, const optional<uint32_t> & nextState) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardEmulatorApduReceivedEventArgsWithCryptograms)->abi_TryRespondWithCryptogramsAndStateAsync(get_abi(responseTemplate), get_abi(cryptogramPlacementSteps), get_abi(nextState), put_abi(result)));
    return result;
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus impl_ISmartCardCryptogramStorageKeyInfo<D>::OperationStatus() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_OperationStatus(&value));
    return value;
}

template <typename D> Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType impl_ISmartCardCryptogramStorageKeyInfo<D>::PublicKeyBlobType() const
{
    Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_PublicKeyBlobType(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardCryptogramStorageKeyInfo<D>::PublicKey() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_PublicKey(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus impl_ISmartCardCryptogramStorageKeyInfo<D>::AttestationStatus() const
{
    Windows::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_AttestationStatus(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardCryptogramStorageKeyInfo<D>::Attestation() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_Attestation(put_abi(value)));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardCryptogramStorageKeyInfo<D>::AttestationCertificateChain() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_AttestationCertificateChain(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities impl_ISmartCardCryptogramStorageKeyInfo<D>::Capabilities() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo)->get_Capabilities(&value));
    return value;
}

template <typename D> hstring impl_ISmartCardCryptogramStorageKeyInfo2<D>::OperationalRequirements() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramStorageKeyInfo2)->get_OperationalRequirements(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus impl_ISmartCardCryptogramMaterialPossessionProof<D>::OperationStatus() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramMaterialPossessionProof)->get_OperationStatus(&value));
    return value;
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardCryptogramMaterialPossessionProof<D>::Proof() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramMaterialPossessionProof)->get_Proof(put_abi(value)));
    return value;
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm impl_ISmartCardCryptogramPlacementStep<D>::Algorithm() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_Algorithm(&value));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::Algorithm(Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_Algorithm(value));
}

template <typename D> Windows::Storage::Streams::IBuffer impl_ISmartCardCryptogramPlacementStep<D>::SourceData() const
{
    Windows::Storage::Streams::IBuffer value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_SourceData(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::SourceData(const Windows::Storage::Streams::IBuffer & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_SourceData(get_abi(value)));
}

template <typename D> hstring impl_ISmartCardCryptogramPlacementStep<D>::CryptogramMaterialPackageName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_CryptogramMaterialPackageName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::CryptogramMaterialPackageName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_CryptogramMaterialPackageName(get_abi(value)));
}

template <typename D> hstring impl_ISmartCardCryptogramPlacementStep<D>::CryptogramMaterialName() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_CryptogramMaterialName(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::CryptogramMaterialName(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_CryptogramMaterialName(get_abi(value)));
}

template <typename D> int32_t impl_ISmartCardCryptogramPlacementStep<D>::TemplateOffset() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_TemplateOffset(&value));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::TemplateOffset(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_TemplateOffset(value));
}

template <typename D> int32_t impl_ISmartCardCryptogramPlacementStep<D>::CryptogramOffset() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_CryptogramOffset(&value));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::CryptogramOffset(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_CryptogramOffset(value));
}

template <typename D> int32_t impl_ISmartCardCryptogramPlacementStep<D>::CryptogramLength() const
{
    int32_t value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_CryptogramLength(&value));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::CryptogramLength(int32_t value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_CryptogramLength(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions impl_ISmartCardCryptogramPlacementStep<D>::CryptogramPlacementOptions() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions value {};
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_CryptogramPlacementOptions(&value));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::CryptogramPlacementOptions(Windows::Devices::SmartCards::SmartCardCryptogramPlacementOptions value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_CryptogramPlacementOptions(value));
}

template <typename D> Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep impl_ISmartCardCryptogramPlacementStep<D>::ChainedOutputStep() const
{
    Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep value { nullptr };
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->get_ChainedOutputStep(put_abi(value)));
    return value;
}

template <typename D> void impl_ISmartCardCryptogramPlacementStep<D>::ChainedOutputStep(const Windows::Devices::SmartCards::SmartCardCryptogramPlacementStep & value) const
{
    check_hresult(WINRT_SHIM(ISmartCardCryptogramPlacementStep)->put_ChainedOutputStep(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> impl_ISmartCardCryptogramGeneratorStatics<D>::GetSmartCardCryptogramGeneratorAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGeneratorStatics)->abi_GetSmartCardCryptogramGeneratorAsync(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> impl_ISmartCardCryptogramGenerator<D>::SupportedCryptogramMaterialTypes() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialType> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->get_SupportedCryptogramMaterialTypes(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> impl_ISmartCardCryptogramGenerator<D>::SupportedCryptogramAlgorithms() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramAlgorithm> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->get_SupportedCryptogramAlgorithms(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> impl_ISmartCardCryptogramGenerator<D>::SupportedCryptogramMaterialPackageFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->get_SupportedCryptogramMaterialPackageFormats(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> impl_ISmartCardCryptogramGenerator<D>::SupportedCryptogramMaterialPackageConfirmationResponseFormats() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->get_SupportedCryptogramMaterialPackageConfirmationResponseFormats(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> impl_ISmartCardCryptogramGenerator<D>::SupportedSmartCardCryptogramStorageKeyCapabilities() const
{
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->get_SupportedSmartCardCryptogramStorageKeyCapabilities(put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardCryptogramGenerator<D>::DeleteCryptogramMaterialStorageKeyAsync(hstring_view storageKeyName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_DeleteCryptogramMaterialStorageKeyAsync(get_abi(storageKeyName), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardCryptogramGenerator<D>::CreateCryptogramMaterialStorageKeyAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring_view storageKeyName, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm algorithm, Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities capabilities) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_CreateCryptogramMaterialStorageKeyAsync(promptingBehavior, get_abi(storageKeyName), algorithm, capabilities, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> impl_ISmartCardCryptogramGenerator<D>::RequestCryptogramMaterialStorageKeyInfoAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, hstring_view storageKeyName, Windows::Security::Cryptography::Core::CryptographicPublicKeyBlobType format) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_RequestCryptogramMaterialStorageKeyInfoAsync(promptingBehavior, get_abi(storageKeyName), format, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardCryptogramGenerator<D>::ImportCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat format, hstring_view storageKeyName, hstring_view materialPackageName, const Windows::Storage::Streams::IBuffer & cryptogramMaterialPackage) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_ImportCryptogramMaterialPackageAsync(format, get_abi(storageKeyName), get_abi(materialPackageName), get_abi(cryptogramMaterialPackage), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> impl_ISmartCardCryptogramGenerator<D>::TryProvePossessionOfCryptogramMaterialPackageAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior, Windows::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat responseFormat, hstring_view materialPackageName, hstring_view materialName, const Windows::Storage::Streams::IBuffer & challenge) const
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_TryProvePossessionOfCryptogramMaterialPackageAsync(promptingBehavior, responseFormat, get_abi(materialPackageName), get_abi(materialName), get_abi(challenge), put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardCryptogramGenerator<D>::RequestUnlockCryptogramMaterialForUseAsync(Windows::Devices::SmartCards::SmartCardUnlockPromptingBehavior promptingBehavior) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_RequestUnlockCryptogramMaterialForUseAsync(promptingBehavior, put_abi(result)));
    return result;
}

template <typename D> Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> impl_ISmartCardCryptogramGenerator<D>::DeleteCryptogramMaterialPackageAsync(hstring_view materialPackageName) const
{
    Windows::Foundation::IAsyncOperation<winrt::Windows::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> result;
    check_hresult(WINRT_SHIM(ISmartCardCryptogramGenerator)->abi_DeleteCryptogramMaterialPackageAsync(get_abi(materialPackageName), put_abi(result)));
    return result;
}

inline SmartCardAppletIdGroup::SmartCardAppletIdGroup() :
    SmartCardAppletIdGroup(activate_instance<SmartCardAppletIdGroup>())
{}

inline SmartCardAppletIdGroup::SmartCardAppletIdGroup(hstring_view displayName, const Windows::Foundation::Collections::IVector<Windows::Storage::Streams::IBuffer> & appletIds, Windows::Devices::SmartCards::SmartCardEmulationCategory emulationCategory, Windows::Devices::SmartCards::SmartCardEmulationType emulationType) :
    SmartCardAppletIdGroup(get_activation_factory<SmartCardAppletIdGroup, ISmartCardAppletIdGroupFactory>().Create(displayName, appletIds, emulationCategory, emulationType))
{}

inline uint16_t SmartCardAppletIdGroup::MaxAppletIds()
{
    return get_activation_factory<SmartCardAppletIdGroup, ISmartCardAppletIdGroupStatics>().MaxAppletIds();
}

inline SmartCardAutomaticResponseApdu::SmartCardAutomaticResponseApdu(const Windows::Storage::Streams::IBuffer & commandApdu, const Windows::Storage::Streams::IBuffer & responseApdu) :
    SmartCardAutomaticResponseApdu(get_activation_factory<SmartCardAutomaticResponseApdu, ISmartCardAutomaticResponseApduFactory>().Create(commandApdu, responseApdu))
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardCryptogramGenerator> SmartCardCryptogramGenerator::GetSmartCardCryptogramGeneratorAsync()
{
    return get_activation_factory<SmartCardCryptogramGenerator, ISmartCardCryptogramGeneratorStatics>().GetSmartCardCryptogramGeneratorAsync();
}

inline SmartCardCryptogramPlacementStep::SmartCardCryptogramPlacementStep() :
    SmartCardCryptogramPlacementStep(activate_instance<SmartCardCryptogramPlacementStep>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardEmulator> SmartCardEmulator::GetDefaultAsync()
{
    return get_activation_factory<SmartCardEmulator, ISmartCardEmulatorStatics>().GetDefaultAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration>> SmartCardEmulator::GetAppletIdGroupRegistrationsAsync()
{
    return get_activation_factory<SmartCardEmulator, ISmartCardEmulatorStatics2>().GetAppletIdGroupRegistrationsAsync();
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration> SmartCardEmulator::RegisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroup & appletIdGroup)
{
    return get_activation_factory<SmartCardEmulator, ISmartCardEmulatorStatics2>().RegisterAppletIdGroupAsync(appletIdGroup);
}

inline Windows::Foundation::IAsyncAction SmartCardEmulator::UnregisterAppletIdGroupAsync(const Windows::Devices::SmartCards::SmartCardAppletIdGroupRegistration & registration)
{
    return get_activation_factory<SmartCardEmulator, ISmartCardEmulatorStatics2>().UnregisterAppletIdGroupAsync(registration);
}

inline uint16_t SmartCardEmulator::MaxAppletIdGroupRegistrations()
{
    return get_activation_factory<SmartCardEmulator, ISmartCardEmulatorStatics2>().MaxAppletIdGroupRegistrations();
}

inline SmartCardPinPolicy::SmartCardPinPolicy() :
    SmartCardPinPolicy(activate_instance<SmartCardPinPolicy>())
{}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::FromSmartCardAsync(const Windows::Devices::SmartCards::SmartCard & card)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().FromSmartCardAsync(card);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy, cardId);
}

inline Windows::Foundation::IAsyncOperation<bool> SmartCardProvisioning::RequestVirtualSmartCardDeletionAsync(const Windows::Devices::SmartCards::SmartCard & card)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics>().RequestVirtualSmartCardDeletionAsync(card);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics2>().RequestAttestedVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardProvisioning> SmartCardProvisioning::RequestAttestedVirtualSmartCardCreationAsync(hstring_view friendlyName, const Windows::Storage::Streams::IBuffer & administrativeKey, const Windows::Devices::SmartCards::SmartCardPinPolicy & pinPolicy, GUID cardId)
{
    return get_activation_factory<SmartCardProvisioning, ISmartCardProvisioningStatics2>().RequestAttestedVirtualSmartCardCreationAsync(friendlyName, administrativeKey, pinPolicy, cardId);
}

inline hstring SmartCardReader::GetDeviceSelector()
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().GetDeviceSelector();
}

inline hstring SmartCardReader::GetDeviceSelector(Windows::Devices::SmartCards::SmartCardReaderKind kind)
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().GetDeviceSelector(kind);
}

inline Windows::Foundation::IAsyncOperation<Windows::Devices::SmartCards::SmartCardReader> SmartCardReader::FromIdAsync(hstring_view deviceId)
{
    return get_activation_factory<SmartCardReader, ISmartCardReaderStatics>().FromIdAsync(deviceId);
}

}

}
#pragma warning(pop)
