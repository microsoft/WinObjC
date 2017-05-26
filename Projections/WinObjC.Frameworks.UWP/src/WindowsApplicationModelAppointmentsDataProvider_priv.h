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

// WindowsApplicationModelAppointmentsDataProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModelAppointments_priv.h"

id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WAAAppointmentInvitee_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedNSArray_NSString, RTProxiedNSArray_WAAAppointmentInvitee;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCancelMeetingRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCancelMeetingRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCancelMeetingRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCancelMeetingRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCancelMeetingRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarCancelMeetingRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs* arg1)
        override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarForwardMeetingRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarForwardMeetingRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarForwardMeetingRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarForwardMeetingRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarForwardMeetingRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarForwardMeetingRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarProposeNewTimeForMeetingRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs* arg1)
        override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarSyncManagerSyncRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarSyncManagerSyncRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarSyncManagerSyncRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarSyncManagerSyncRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarSyncManagerSyncRequestEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarSyncManagerSyncRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentDataProviderConnection*,
              ABI::Windows::ApplicationModel::Appointments::DataProvider::AppointmentCalendarUpdateMeetingResponseRequestEventArgs*>> {
    void (^_delegate)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs(
        void (^del)(WAADAppointmentDataProviderConnection*, WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_Appointments_DataProvider_AppointmentDataProviderConnection_Windows_ApplicationModel_Appointments_DataProvider_AppointmentCalendarUpdateMeetingResponseRequestEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentDataProviderConnection* arg0,
           ABI::Windows::ApplicationModel::Appointments::DataProvider::IAppointmentCalendarUpdateMeetingResponseRequestEventArgs* arg1)
        override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAADAppointmentDataProviderConnection>(arg0),
                      _createRtProxy<WAADAppointmentCalendarUpdateMeetingResponseRequestEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
