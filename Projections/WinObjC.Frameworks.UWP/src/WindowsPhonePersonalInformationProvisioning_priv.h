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

// WindowsPhonePersonalInformationProvisioning_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsPhonePersonalInformation_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics2>
WPPPIContactPartnerProvisioningManagerStatics2_inst();
ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IContactPartnerProvisioningManagerStatics>
WPPPIContactPartnerProvisioningManagerStatics_inst();
ComPtr<ABI::Windows::Phone::PersonalInformation::Provisioning::IMessagePartnerProvisioningManagerStatics>
WPPPIMessagePartnerProvisioningManagerStatics_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);

@class RTProxiedNSArray_NSString, RTProxiedNSArray_RTProxiedNSDictionary_NSString_RTObject, RTProxiedNSDictionary_NSString_RTObject;

typedef IMapView<HSTRING, IInspectable*>* IMapView_HSTRING_IInspectablePtr_Ptr;
