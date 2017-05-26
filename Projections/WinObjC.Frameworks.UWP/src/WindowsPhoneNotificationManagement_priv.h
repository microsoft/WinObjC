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

// WindowsPhoneNotificationManagement_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelAppointments_priv.h"
#include "WindowsApplicationModelEmail_priv.h"
#include "WindowsStorageStreams_priv.h"
ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager2> WPNMIAccessoryManager2_inst();
ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager3> WPNMIAccessoryManager3_inst();
ComPtr<ABI::Windows::Phone::Notification::Management::IAccessoryManager> WPNMIAccessoryManager_inst();

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WPNMEmailAccountInfo_create(IInspectable* val);
id RTProxiedNSArray_WPNMEmailFolderInfo_create(IInspectable* val);
id RTProxiedNSArray_WPNMPhoneLineDetails_create(IInspectable* val);
id RTProxiedNSArray_WPNMSpeedDialEntry_create(IInspectable* val);
id RTProxiedNSArray_WPNMTextResponse_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WPNMAppNotificationInfo_create(IInspectable* val);

@class RTProxiedNSArray_NSString, RTProxiedNSArray_WPNMEmailAccountInfo, RTProxiedNSArray_WPNMEmailFolderInfo,
    RTProxiedNSArray_WPNMPhoneLineDetails;
@class RTProxiedNSArray_WPNMSpeedDialEntry, RTProxiedNSArray_WPNMTextResponse, RTProxiedNSDictionary_NSString_WPNMAppNotificationInfo;
