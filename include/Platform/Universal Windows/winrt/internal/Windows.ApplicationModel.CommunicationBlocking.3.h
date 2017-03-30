// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.CommunicationBlocking.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::CommunicationBlocking {

struct CommunicationBlockingAccessManager
{
    CommunicationBlockingAccessManager() = delete;
    static bool IsBlockingActive();
    static Windows::Foundation::IAsyncOperation<bool> IsBlockedNumberAsync(hstring_view number);
    static bool ShowBlockNumbersUI(iterable<hstring> phoneNumbers);
    static bool ShowUnblockNumbersUI(iterable<hstring> phoneNumbers);
    static void ShowBlockedCallsUI();
    static void ShowBlockedMessagesUI();
};

struct CommunicationBlockingAppManager
{
    CommunicationBlockingAppManager() = delete;
    static bool IsCurrentAppActiveBlockingApp();
    static void ShowCommunicationBlockingSettingsUI();
    static Windows::Foundation::IAsyncOperation<bool> RequestSetAsActiveBlockingAppAsync();
};

}

}
