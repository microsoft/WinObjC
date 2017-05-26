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

// WindowsApplicationModelAppointments_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsUI_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics> WAAIAppointmentManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics2> WAAIAppointmentManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentManagerStatics3> WAAIAppointmentManagerStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics2> WAAIAppointmentPropertiesStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::Appointments::IAppointmentPropertiesStatics> WAAIAppointmentPropertiesStatics_inst();

id RTProxiedIterableNSArray_WAAAppointmentInvitee_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WAAAppointment_create(IInspectable* val);
id RTProxiedNSArray_WAAAppointmentCalendar_create(IInspectable* val);
id RTProxiedNSArray_WAAAppointmentException_create(IInspectable* val);
id RTProxiedNSArray_WAAAppointmentStoreChange_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WAAAppointmentInvitee_create(IInspectable* val);

@class Nullable_UInt32, Nullable_WFDateTime, Nullable_WFTimeSpan, RTProxiedIterableNSArray_WAAAppointmentInvitee, RTProxiedNSArray_NSString;
@class RTProxiedNSArray_WAAAppointment, RTProxiedNSArray_WAAAppointmentCalendar, RTProxiedNSArray_WAAAppointmentException,
    RTProxiedNSArray_WAAAppointmentStoreChange;
@class RTProxiedNSMutableArray_NSString, RTProxiedNSMutableArray_WAAAppointmentInvitee;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object__DEFINED
class ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentCalendarSyncManager*,
                                                       IInspectable*>> {
    void (^_delegate)(WAAAppointmentCalendarSyncManager*, RTObject*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object(
        void (^del)(WAAAppointmentCalendarSyncManager*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentCalendarSyncManager_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::ApplicationModel::Appointments::IAppointmentCalendarSyncManager* arg0,
                                             IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppointmentCalendarSyncManager>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::Appointments::AppointmentStore*,
                                                       ABI::Windows::ApplicationModel::Appointments::AppointmentStoreChangedEventArgs*>> {
    void (^_delegate)(WAAAppointmentStore*, WAAAppointmentStoreChangedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs(
        void (^del)(WAAAppointmentStore*, WAAAppointmentStoreChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_AppointmentStore_Windows_ApplicationModel_Appointments_AppointmentStoreChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::IAppointmentStore* arg0,
           ABI::Windows::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAAAppointmentStore>(arg0), _createRtProxy<WAAAppointmentStoreChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
