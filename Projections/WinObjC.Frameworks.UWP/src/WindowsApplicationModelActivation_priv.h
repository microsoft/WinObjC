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

// WindowsApplicationModelActivation_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelUserDataAccountsProvider_priv.h"
#include "WindowsApplicationModelContactsProvider_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUINotifications_priv.h"
#include "WindowsApplicationModelAppointmentsAppointmentsProvider_priv.h"
#include "WindowsApplicationModelWallet_priv.h"
#include "WindowsDevicesPrintersExtensions_priv.h"
#include "WindowsApplicationModelContacts_priv.h"
#include "WindowsStoragePickersProvider_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
#include "WindowsUIViewManagement_priv.h"
#include "WindowsApplicationModelCalls_priv.h"
#include "WindowsMediaSpeechRecognition_priv.h"
#include "WindowsApplicationModelSearch_priv.h"
#include "WindowsApplicationModelDataTransferShareTarget_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageSearch_priv.h"
#include "WindowsFoundationCollections_priv.h"
#include "WindowsStorageProvider_priv.h"
#include "WindowsSecurityAuthenticationWeb_priv.h"
#include "WindowsSecurityAuthenticationWebProvider_priv.h"
#include "WindowsApplicationModelBackground_priv.h"

id RTProxiedNSArray_RTObject_WSIStorageItem_create(IInspectable* val);
id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);
id RTProxiedNSArray_WUNShownTileNotification_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_RTObject_WSIStorageItem, RTProxiedNSArray_WSStorageFile,
    RTProxiedNSArray_WUNShownTileNotification;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Activation::SplashScreen*, IInspectable*>> {
    void (^_delegate)(WAASplashScreen*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object(void (^del)(WAASplashScreen*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Activation_SplashScreen_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Activation::ISplashScreen* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAASplashScreen>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif
