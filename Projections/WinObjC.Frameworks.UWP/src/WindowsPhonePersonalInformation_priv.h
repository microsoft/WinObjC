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

// WindowsPhonePersonalInformation_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Phone::PersonalInformation::IContactInformationStatics> WPPIContactInformationStatics_inst();
ComPtr<ABI::Windows::Phone::PersonalInformation::IContactStoreStatics> WPPIContactStoreStatics_inst();
static ComPtr<ABI::Windows::Phone::PersonalInformation::IStoredContactFactory> WPPIStoredContactFactory_inst();
ComPtr<ABI::Windows::Phone::PersonalInformation::IKnownContactPropertiesStatics> WPPIKnownContactPropertiesStatics_inst();

id RTProxiedNSArray_WPPContactChangeRecord_create(IInspectable* val);
id RTProxiedNSArray_WPPStoredContact_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSArray_WPPContactChangeRecord, RTProxiedNSArray_WPPStoredContact, RTProxiedNSDictionary_NSString_RTObject,
    RTProxiedNSMutableArray_NSString;
@class RTProxiedNSMutableDictionary_NSString_RTObject;
