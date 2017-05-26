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

// WindowsApplicationModelWallet_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUI_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsDevicesGeolocation_priv.h"
static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletBarcodeFactory> WAWIWalletBarcodeFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> WAWIWalletItemCustomPropertyFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletVerbFactory> WAWIWalletVerbFactory_inst();
static ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletItemFactory> WAWIWalletItemFactory_inst();
ComPtr<ABI::Windows::ApplicationModel::Wallet::IWalletManagerStatics> WAWIWalletManagerStatics_inst();

id RTProxiedNSArray_WAWWalletItem_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_WAWWalletItemCustomProperty_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_WAWWalletRelevantLocation_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_WAWWalletTransaction_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_WAWWalletVerb_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_WAWWalletItem, RTProxiedNSMutableDictionary_NSString_WAWWalletItemCustomProperty,
    RTProxiedNSMutableDictionary_NSString_WAWWalletRelevantLocation;
@class RTProxiedNSMutableDictionary_NSString_WAWWalletTransaction, RTProxiedNSMutableDictionary_NSString_WAWWalletVerb;
