// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Phone.PersonalInformation.Provisioning.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::Phone::PersonalInformation::Provisioning {

struct ContactPartnerProvisioningManager
{
    ContactPartnerProvisioningManager() = delete;
    static Windows::Foundation::IAsyncAction AssociateNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId);
    static Windows::Foundation::IAsyncAction ImportVcardToSystemAsync(const Windows::Storage::Streams::IInputStream & stream);
    static Windows::Foundation::IAsyncAction AssociateSocialNetworkAccountAsync(const Windows::Phone::PersonalInformation::ContactStore & store, hstring_view networkName, hstring_view networkAccountId);
};

struct MessagePartnerProvisioningManager
{
    MessagePartnerProvisioningManager() = delete;
    static Windows::Foundation::IAsyncAction ImportSmsToSystemAsync(bool incoming, bool read, hstring_view body, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime);
    static Windows::Foundation::IAsyncAction ImportMmsToSystemAsync(bool incoming, bool read, hstring_view subject, hstring_view sender, vector_view<hstring> recipients, const Windows::Foundation::DateTime & deliveryTime, vector_view<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable>> attachments);
};

}

}
