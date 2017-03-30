// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.AllJoyn.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Networking.Sockets.0.h"
#include "Windows.Security.Credentials.0.h"
#include "Windows.Security.Cryptography.Certificates.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Security.Cryptography.Certificates.1.h"
#include "Windows.Globalization.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::AllJoyn {

struct __declspec(uuid("e5a9bf00-1fa2-4839-93ef-f9df404890f7")) __declspec(novtable) IAllJoynAboutData : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_DefaultAppName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DefaultAppName(hstring value) = 0;
    virtual HRESULT __stdcall get_AppNames(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DateOfManufacture(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall put_DateOfManufacture(Windows::Foundation::IReference<Windows::Foundation::DateTime> * value) = 0;
    virtual HRESULT __stdcall get_DefaultDescription(hstring * value) = 0;
    virtual HRESULT __stdcall put_DefaultDescription(hstring value) = 0;
    virtual HRESULT __stdcall get_Descriptions(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall get_DefaultManufacturer(hstring * value) = 0;
    virtual HRESULT __stdcall put_DefaultManufacturer(hstring value) = 0;
    virtual HRESULT __stdcall get_Manufacturers(Windows::Foundation::Collections::IMap<hstring, hstring> ** value) = 0;
    virtual HRESULT __stdcall get_ModelNumber(hstring * value) = 0;
    virtual HRESULT __stdcall put_ModelNumber(hstring value) = 0;
    virtual HRESULT __stdcall get_SoftwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall put_SoftwareVersion(hstring value) = 0;
    virtual HRESULT __stdcall get_SupportUrl(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall put_SupportUrl(Windows::Foundation::IUriRuntimeClass * value) = 0;
    virtual HRESULT __stdcall get_AppId(GUID * value) = 0;
    virtual HRESULT __stdcall put_AppId(GUID value) = 0;
};

struct __declspec(uuid("6823111f-6212-4934-9c48-e19ca4984288")) __declspec(novtable) IAllJoynAboutDataView : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> ** value) = 0;
    virtual HRESULT __stdcall get_AJSoftwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_AppId(GUID * value) = 0;
    virtual HRESULT __stdcall get_DateOfManufacture(Windows::Foundation::IReference<Windows::Foundation::DateTime> ** value) = 0;
    virtual HRESULT __stdcall get_DefaultLanguage(Windows::Globalization::ILanguage ** value) = 0;
    virtual HRESULT __stdcall get_DeviceId(hstring * value) = 0;
    virtual HRESULT __stdcall get_HardwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_ModelNumber(hstring * value) = 0;
    virtual HRESULT __stdcall get_SoftwareVersion(hstring * value) = 0;
    virtual HRESULT __stdcall get_SupportedLanguages(Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> ** value) = 0;
    virtual HRESULT __stdcall get_SupportUrl(Windows::Foundation::IUriRuntimeClass ** value) = 0;
    virtual HRESULT __stdcall get_AppName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Description(hstring * value) = 0;
    virtual HRESULT __stdcall get_DeviceName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Manufacturer(hstring * value) = 0;
};

struct __declspec(uuid("57edb688-0c5e-416e-88b5-39b32d25c47d")) __declspec(novtable) IAllJoynAboutDataViewStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDataBySessionPortAsync(hstring uniqueName, Windows::Devices::AllJoyn::IAllJoynBusAttachment * busAttachment, uint16_t sessionPort, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetDataBySessionPortWithLanguageAsync(hstring uniqueName, Windows::Devices::AllJoyn::IAllJoynBusAttachment * busAttachment, uint16_t sessionPort, Windows::Globalization::ILanguage * language, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> ** operation) = 0;
};

struct __declspec(uuid("4da817d2-cd1d-4023-a7c4-16def89c28df")) __declspec(novtable) IAllJoynAcceptSessionJoiner : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Accept() = 0;
};

struct __declspec(uuid("4efb5365-3e8a-4257-8f10-539ce0d56c0f")) __declspec(novtable) IAllJoynAcceptSessionJoinerEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall get_SessionPort(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_TrafficType(winrt::Windows::Devices::AllJoyn::AllJoynTrafficType * value) = 0;
    virtual HRESULT __stdcall get_SamePhysicalNode(bool * value) = 0;
    virtual HRESULT __stdcall get_SameNetwork(bool * value) = 0;
    virtual HRESULT __stdcall abi_Accept() = 0;
};

struct __declspec(uuid("b4435bc0-6145-429e-84db-d5bfe772b14f")) __declspec(novtable) IAllJoynAcceptSessionJoinerEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring uniqueName, uint16_t sessionPort, winrt::Windows::Devices::AllJoyn::AllJoynTrafficType trafficType, uint8_t proximity, Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner * acceptSessionJoiner, Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs ** result) = 0;
};

struct __declspec(uuid("97b4701c-15dc-4b53-b6a4-7d134300d7bf")) __declspec(novtable) IAllJoynAuthenticationCompleteEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AuthenticationMechanism(winrt::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism * value) = 0;
    virtual HRESULT __stdcall get_PeerUniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall get_Succeeded(bool * value) = 0;
};

struct __declspec(uuid("f309f153-1eed-42c3-a20e-436d41fe62f6")) __declspec(novtable) IAllJoynBusAttachment : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AboutData(Windows::Devices::AllJoyn::IAllJoynAboutData ** value) = 0;
    virtual HRESULT __stdcall get_ConnectionSpecification(hstring * value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::Devices::AllJoyn::AllJoynBusAttachmentState * value) = 0;
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_PingAsync(hstring uniqueName, Windows::Foundation::IAsyncOperation<int32_t> ** operation) = 0;
    virtual HRESULT __stdcall abi_Connect() = 0;
    virtual HRESULT __stdcall abi_Disconnect() = 0;
    virtual HRESULT __stdcall add_StateChanged(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_StateChanged(event_token token) = 0;
    virtual HRESULT __stdcall get_AuthenticationMechanisms(Windows::Foundation::Collections::IVector<winrt::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism> ** value) = 0;
    virtual HRESULT __stdcall add_CredentialsRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CredentialsRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_CredentialsVerificationRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_CredentialsVerificationRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_AuthenticationComplete(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AuthenticationComplete(event_token token) = 0;
};

struct __declspec(uuid("3474cb1e-2368-43b2-b43e-6a3ac1278d98")) __declspec(novtable) IAllJoynBusAttachment2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetAboutDataAsync(Windows::Devices::AllJoyn::IAllJoynServiceInfo * serviceInfo, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetAboutDataWithLanguageAsync(Windows::Devices::AllJoyn::IAllJoynServiceInfo * serviceInfo, Windows::Globalization::ILanguage * language, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> ** operation) = 0;
    virtual HRESULT __stdcall add_AcceptSessionJoinerRequested(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AcceptSessionJoinerRequested(event_token token) = 0;
    virtual HRESULT __stdcall add_SessionJoined(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_SessionJoined(event_token token) = 0;
};

struct __declspec(uuid("642ef1a4-ad85-4ddf-90ae-604452b22288")) __declspec(novtable) IAllJoynBusAttachmentFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring connectionSpecification, Windows::Devices::AllJoyn::IAllJoynBusAttachment ** result) = 0;
};

struct __declspec(uuid("d82e75f4-c02a-41ec-a8d5-eab1558953aa")) __declspec(novtable) IAllJoynBusAttachmentStateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::Devices::AllJoyn::AllJoynBusAttachmentState * value) = 0;
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
};

struct __declspec(uuid("839d4d3d-1051-40d7-872a-8d0141115b1f")) __declspec(novtable) IAllJoynBusAttachmentStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetDefault(Windows::Devices::AllJoyn::IAllJoynBusAttachment ** defaultBusAttachment) = 0;
    virtual HRESULT __stdcall abi_GetWatcher(Windows::Foundation::Collections::IIterable<hstring> * requiredInterfaces, Windows::Devices::Enumeration::IDeviceWatcher ** deviceWatcher) = 0;
};

struct __declspec(uuid("e8fd825e-f73a-490c-8804-04e026643047")) __declspec(novtable) IAllJoynBusObject : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_AddProducer(Windows::Devices::AllJoyn::IAllJoynProducer * producer) = 0;
    virtual HRESULT __stdcall get_BusAttachment(Windows::Devices::AllJoyn::IAllJoynBusAttachment ** value) = 0;
    virtual HRESULT __stdcall get_Session(Windows::Devices::AllJoyn::IAllJoynSession ** value) = 0;
    virtual HRESULT __stdcall add_Stopped(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusObject, Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Stopped(event_token token) = 0;
};

struct __declspec(uuid("2c2f9f0b-8e02-4f9c-ac27-ea6dad5d3b50")) __declspec(novtable) IAllJoynBusObjectFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring objectPath, Windows::Devices::AllJoyn::IAllJoynBusObject ** result) = 0;
    virtual HRESULT __stdcall abi_CreateWithBusAttachment(hstring objectPath, Windows::Devices::AllJoyn::IAllJoynBusAttachment * busAttachment, Windows::Devices::AllJoyn::IAllJoynBusObject ** result) = 0;
};

struct __declspec(uuid("de102115-ef8e-4d42-b93b-a2ae74519766")) __declspec(novtable) IAllJoynBusObjectStoppedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
};

struct __declspec(uuid("6b22fd48-d0a3-4255-953a-4772b4028073")) __declspec(novtable) IAllJoynBusObjectStoppedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(int32_t status, Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs ** result) = 0;
};

struct __declspec(uuid("824650f2-a190-40b1-abab-349ec244dfaa")) __declspec(novtable) IAllJoynCredentials : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AuthenticationMechanism(winrt::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism * value) = 0;
    virtual HRESULT __stdcall get_Certificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall put_Certificate(Windows::Security::Cryptography::Certificates::ICertificate * value) = 0;
    virtual HRESULT __stdcall get_PasswordCredential(Windows::Security::Credentials::IPasswordCredential ** value) = 0;
    virtual HRESULT __stdcall put_PasswordCredential(Windows::Security::Credentials::IPasswordCredential * value) = 0;
    virtual HRESULT __stdcall get_Timeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_Timeout(Windows::Foundation::TimeSpan value) = 0;
};

struct __declspec(uuid("6a87e34e-b069-4b80-9e1a-41bc837c65d2")) __declspec(novtable) IAllJoynCredentialsRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AttemptCount(uint16_t * value) = 0;
    virtual HRESULT __stdcall get_Credentials(Windows::Devices::AllJoyn::IAllJoynCredentials ** value) = 0;
    virtual HRESULT __stdcall get_PeerUniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall get_RequestedUserName(hstring * value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

struct __declspec(uuid("800a7612-b805-44af-a2e1-792ab655a2d0")) __declspec(novtable) IAllJoynCredentialsVerificationRequestedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AuthenticationMechanism(winrt::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism * value) = 0;
    virtual HRESULT __stdcall get_PeerUniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall get_PeerCertificate(Windows::Security::Cryptography::Certificates::ICertificate ** value) = 0;
    virtual HRESULT __stdcall get_PeerCertificateErrorSeverity(winrt::Windows::Networking::Sockets::SocketSslErrorSeverity * value) = 0;
    virtual HRESULT __stdcall get_PeerCertificateErrors(Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> ** value) = 0;
    virtual HRESULT __stdcall get_PeerIntermediateCertificates(Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> ** value) = 0;
    virtual HRESULT __stdcall abi_Accept() = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

struct __declspec(uuid("ff2b0127-2c12-4859-aa3a-c74461ee814c")) __declspec(novtable) IAllJoynMessageInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SenderUniqueName(hstring * value) = 0;
};

struct __declspec(uuid("34664c2a-8289-43d4-b4a8-3f4de359f043")) __declspec(novtable) IAllJoynMessageInfoFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring senderUniqueName, Windows::Devices::AllJoyn::IAllJoynMessageInfo ** result) = 0;
};

struct __declspec(uuid("9d084679-469b-495a-a710-ac50f123069f")) __declspec(novtable) IAllJoynProducer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_SetBusObject(Windows::Devices::AllJoyn::IAllJoynBusObject * busObject) = 0;
};

struct __declspec(uuid("51309770-4937-492d-8080-236439987ceb")) __declspec(novtable) IAllJoynProducerStoppedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
};

struct __declspec(uuid("56529961-b219-4d6e-9f78-fa3f99fa8fe5")) __declspec(novtable) IAllJoynProducerStoppedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(int32_t status, Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs ** result) = 0;
};

struct __declspec(uuid("4cbe8209-b93e-4182-999b-ddd000f9c575")) __declspec(novtable) IAllJoynServiceInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
    virtual HRESULT __stdcall get_ObjectPath(hstring * value) = 0;
    virtual HRESULT __stdcall get_SessionPort(uint16_t * value) = 0;
};

struct __declspec(uuid("7581dabd-fe03-4f4b-94a4-f02fdcbd11b8")) __declspec(novtable) IAllJoynServiceInfoFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring uniqueName, hstring objectPath, uint16_t sessionPort, Windows::Devices::AllJoyn::IAllJoynServiceInfo ** result) = 0;
};

struct __declspec(uuid("3057a95f-1d3f-41f3-8969-e32792627396")) __declspec(novtable) IAllJoynServiceInfoRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
};

struct __declspec(uuid("0dbf8627-9aff-4955-9227-6953baf41569")) __declspec(novtable) IAllJoynServiceInfoRemovedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring uniqueName, Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs ** result) = 0;
};

struct __declspec(uuid("5678570a-603a-49fc-b750-0ef13609213c")) __declspec(novtable) IAllJoynServiceInfoStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_FromIdAsync(hstring deviceId, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynServiceInfo> ** operation) = 0;
};

struct __declspec(uuid("e8d11b0c-c0d4-406c-88a9-a93efa85d4b1")) __declspec(novtable) IAllJoynSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
    virtual HRESULT __stdcall abi_RemoveMemberAsync(hstring uniqueName, Windows::Foundation::IAsyncOperation<int32_t> ** operation) = 0;
    virtual HRESULT __stdcall add_MemberAdded(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MemberAdded(event_token token) = 0;
    virtual HRESULT __stdcall add_MemberRemoved(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_MemberRemoved(event_token token) = 0;
    virtual HRESULT __stdcall add_Lost(Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_Lost(event_token token) = 0;
};

struct __declspec(uuid("9e9f5bd0-b5d7-47c5-8dab-b040cc192871")) __declspec(novtable) IAllJoynSessionJoinedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Session(Windows::Devices::AllJoyn::IAllJoynSession ** value) = 0;
};

struct __declspec(uuid("6824d689-d6cb-4d9e-a09e-35806870b17f")) __declspec(novtable) IAllJoynSessionJoinedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Devices::AllJoyn::IAllJoynSession * session, Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs ** result) = 0;
};

struct __declspec(uuid("e766a48a-8bb8-4954-ae67-d2fa43d1f96b")) __declspec(novtable) IAllJoynSessionLostEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Reason(winrt::Windows::Devices::AllJoyn::AllJoynSessionLostReason * value) = 0;
};

struct __declspec(uuid("13bbfd32-d2f4-49c9-980e-2805e13586b1")) __declspec(novtable) IAllJoynSessionLostEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Devices::AllJoyn::AllJoynSessionLostReason reason, Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs ** result) = 0;
};

struct __declspec(uuid("49a2798a-0dd1-46c1-9cd6-27190e503a5e")) __declspec(novtable) IAllJoynSessionMemberAddedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
};

struct __declspec(uuid("341de352-1d33-40a1-a1d3-e5777020e1f1")) __declspec(novtable) IAllJoynSessionMemberAddedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring uniqueName, Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs ** result) = 0;
};

struct __declspec(uuid("409a219f-aa4a-4893-b430-baa1b63c6219")) __declspec(novtable) IAllJoynSessionMemberRemovedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UniqueName(hstring * value) = 0;
};

struct __declspec(uuid("c4d355e8-42b8-4b67-b757-d0cfcad59280")) __declspec(novtable) IAllJoynSessionMemberRemovedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring uniqueName, Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs ** result) = 0;
};

struct __declspec(uuid("9e05d604-a06c-46d4-b46c-0b0b54105b44")) __declspec(novtable) IAllJoynSessionStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFromServiceInfoAsync(Windows::Devices::AllJoyn::IAllJoynServiceInfo * serviceInfo, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> ** operation) = 0;
    virtual HRESULT __stdcall abi_GetFromServiceInfoAndBusAttachmentAsync(Windows::Devices::AllJoyn::IAllJoynServiceInfo * serviceInfo, Windows::Devices::AllJoyn::IAllJoynBusAttachment * busAttachment, Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> ** operation) = 0;
};

struct __declspec(uuid("d0b7a17e-0d29-4da9-8ac6-54c554bedbc5")) __declspec(novtable) IAllJoynStatusStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Ok(int32_t * value) = 0;
    virtual HRESULT __stdcall get_Fail(int32_t * value) = 0;
    virtual HRESULT __stdcall get_OperationTimedOut(int32_t * value) = 0;
    virtual HRESULT __stdcall get_OtherEndClosed(int32_t * value) = 0;
    virtual HRESULT __stdcall get_ConnectionRefused(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AuthenticationFailed(int32_t * value) = 0;
    virtual HRESULT __stdcall get_AuthenticationRejectedByUser(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SslConnectFailed(int32_t * value) = 0;
    virtual HRESULT __stdcall get_SslIdentityVerificationFailed(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InsufficientSecurity(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument1(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument2(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument3(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument4(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument5(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument6(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument7(int32_t * value) = 0;
    virtual HRESULT __stdcall get_InvalidArgument8(int32_t * value) = 0;
};

struct __declspec(uuid("c9fca03b-701d-4aa8-97dd-a2bb0a8f5fa3")) __declspec(novtable) IAllJoynWatcherStoppedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(int32_t * value) = 0;
};

struct __declspec(uuid("878fa5a8-2d50-47e1-904a-20bf0d48c782")) __declspec(novtable) IAllJoynWatcherStoppedEventArgsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(int32_t status, Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs ** result) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::AllJoyn::AllJoynAboutData> { using default_interface = Windows::Devices::AllJoyn::IAllJoynAboutData; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynAboutDataView> { using default_interface = Windows::Devices::AllJoyn::IAllJoynAboutDataView; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusAttachment> { using default_interface = Windows::Devices::AllJoyn::IAllJoynBusAttachment; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusObject> { using default_interface = Windows::Devices::AllJoyn::IAllJoynBusObject; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentials> { using default_interface = Windows::Devices::AllJoyn::IAllJoynCredentials; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynMessageInfo> { using default_interface = Windows::Devices::AllJoyn::IAllJoynMessageInfo; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynServiceInfo> { using default_interface = Windows::Devices::AllJoyn::IAllJoynServiceInfo; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynServiceInfoRemovedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynSession> { using default_interface = Windows::Devices::AllJoyn::IAllJoynSession; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs; };
template <> struct traits<Windows::Devices::AllJoyn::AllJoynWatcherStoppedEventArgs> { using default_interface = Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs; };

}

namespace Windows::Devices::AllJoyn {

template <typename D>
struct WINRT_EBO impl_IAllJoynAboutData
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    hstring DefaultAppName() const;
    void DefaultAppName(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> AppNames() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> DateOfManufacture() const;
    void DateOfManufacture(const optional<Windows::Foundation::DateTime> & value) const;
    hstring DefaultDescription() const;
    void DefaultDescription(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Descriptions() const;
    hstring DefaultManufacturer() const;
    void DefaultManufacturer(hstring_view value) const;
    Windows::Foundation::Collections::IMap<hstring, hstring> Manufacturers() const;
    hstring ModelNumber() const;
    void ModelNumber(hstring_view value) const;
    hstring SoftwareVersion() const;
    void SoftwareVersion(hstring_view value) const;
    Windows::Foundation::Uri SupportUrl() const;
    void SupportUrl(const Windows::Foundation::Uri & value) const;
    GUID AppId() const;
    void AppId(GUID value) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAboutDataView
{
    int32_t Status() const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::IInspectable> Properties() const;
    hstring AJSoftwareVersion() const;
    GUID AppId() const;
    Windows::Foundation::IReference<Windows::Foundation::DateTime> DateOfManufacture() const;
    Windows::Globalization::Language DefaultLanguage() const;
    hstring DeviceId() const;
    hstring HardwareVersion() const;
    hstring ModelNumber() const;
    hstring SoftwareVersion() const;
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> SupportedLanguages() const;
    Windows::Foundation::Uri SupportUrl() const;
    hstring AppName() const;
    hstring Description() const;
    hstring DeviceName() const;
    hstring Manufacturer() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAboutDataViewStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetDataBySessionPortAsync(hstring_view uniqueName, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment, uint16_t sessionPort) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetDataBySessionPortAsync(hstring_view uniqueName, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment, uint16_t sessionPort, const Windows::Globalization::Language & language) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAcceptSessionJoiner
{
    void Accept() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAcceptSessionJoinerEventArgs
{
    hstring UniqueName() const;
    uint16_t SessionPort() const;
    Windows::Devices::AllJoyn::AllJoynTrafficType TrafficType() const;
    bool SamePhysicalNode() const;
    bool SameNetwork() const;
    void Accept() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAcceptSessionJoinerEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs Create(hstring_view uniqueName, uint16_t sessionPort, Windows::Devices::AllJoyn::AllJoynTrafficType trafficType, uint8_t proximity, const Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner & acceptSessionJoiner) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynAuthenticationCompleteEventArgs
{
    Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism AuthenticationMechanism() const;
    hstring PeerUniqueName() const;
    bool Succeeded() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusAttachment
{
    Windows::Devices::AllJoyn::AllJoynAboutData AboutData() const;
    hstring ConnectionSpecification() const;
    Windows::Devices::AllJoyn::AllJoynBusAttachmentState State() const;
    hstring UniqueName() const;
    Windows::Foundation::IAsyncOperation<int32_t> PingAsync(hstring_view uniqueName) const;
    void Connect() const;
    void Disconnect() const;
    event_token StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs> & handler) const;
    using StateChanged_revoker = event_revoker<IAllJoynBusAttachment>;
    StateChanged_revoker StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs> & handler) const;
    void StateChanged(event_token token) const;
    Windows::Foundation::Collections::IVector<winrt::Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism> AuthenticationMechanisms() const;
    event_token CredentialsRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs> & handler) const;
    using CredentialsRequested_revoker = event_revoker<IAllJoynBusAttachment>;
    CredentialsRequested_revoker CredentialsRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs> & handler) const;
    void CredentialsRequested(event_token token) const;
    event_token CredentialsVerificationRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs> & handler) const;
    using CredentialsVerificationRequested_revoker = event_revoker<IAllJoynBusAttachment>;
    CredentialsVerificationRequested_revoker CredentialsVerificationRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs> & handler) const;
    void CredentialsVerificationRequested(event_token token) const;
    event_token AuthenticationComplete(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs> & handler) const;
    using AuthenticationComplete_revoker = event_revoker<IAllJoynBusAttachment>;
    AuthenticationComplete_revoker AuthenticationComplete(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs> & handler) const;
    void AuthenticationComplete(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusAttachment2
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetAboutDataAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynAboutDataView> GetAboutDataAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo, const Windows::Globalization::Language & language) const;
    event_token AcceptSessionJoinerRequested(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs> & handler) const;
    using AcceptSessionJoinerRequested_revoker = event_revoker<IAllJoynBusAttachment2>;
    AcceptSessionJoinerRequested_revoker AcceptSessionJoinerRequested(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs> & handler) const;
    void AcceptSessionJoinerRequested(event_token token) const;
    event_token SessionJoined(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs> & handler) const;
    using SessionJoined_revoker = event_revoker<IAllJoynBusAttachment2>;
    SessionJoined_revoker SessionJoined(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusAttachment, Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs> & handler) const;
    void SessionJoined(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusAttachmentFactory
{
    Windows::Devices::AllJoyn::AllJoynBusAttachment Create(hstring_view connectionSpecification) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusAttachmentStateChangedEventArgs
{
    Windows::Devices::AllJoyn::AllJoynBusAttachmentState State() const;
    int32_t Status() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusAttachmentStatics
{
    Windows::Devices::AllJoyn::AllJoynBusAttachment GetDefault() const;
    Windows::Devices::Enumeration::DeviceWatcher GetWatcher(iterable<hstring> requiredInterfaces) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusObject
{
    void Start() const;
    void Stop() const;
    void AddProducer(const Windows::Devices::AllJoyn::IAllJoynProducer & producer) const;
    Windows::Devices::AllJoyn::AllJoynBusAttachment BusAttachment() const;
    Windows::Devices::AllJoyn::AllJoynSession Session() const;
    event_token Stopped(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusObject, Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs> & handler) const;
    using Stopped_revoker = event_revoker<IAllJoynBusObject>;
    Stopped_revoker Stopped(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynBusObject, Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs> & handler) const;
    void Stopped(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusObjectFactory
{
    Windows::Devices::AllJoyn::AllJoynBusObject Create(hstring_view objectPath) const;
    Windows::Devices::AllJoyn::AllJoynBusObject CreateWithBusAttachment(hstring_view objectPath, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusObjectStoppedEventArgs
{
    int32_t Status() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynBusObjectStoppedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs Create(int32_t status) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynCredentials
{
    Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism AuthenticationMechanism() const;
    Windows::Security::Cryptography::Certificates::Certificate Certificate() const;
    void Certificate(const Windows::Security::Cryptography::Certificates::Certificate & value) const;
    Windows::Security::Credentials::PasswordCredential PasswordCredential() const;
    void PasswordCredential(const Windows::Security::Credentials::PasswordCredential & value) const;
    Windows::Foundation::TimeSpan Timeout() const;
    void Timeout(const Windows::Foundation::TimeSpan & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynCredentialsRequestedEventArgs
{
    uint16_t AttemptCount() const;
    Windows::Devices::AllJoyn::AllJoynCredentials Credentials() const;
    hstring PeerUniqueName() const;
    hstring RequestedUserName() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynCredentialsVerificationRequestedEventArgs
{
    Windows::Devices::AllJoyn::AllJoynAuthenticationMechanism AuthenticationMechanism() const;
    hstring PeerUniqueName() const;
    Windows::Security::Cryptography::Certificates::Certificate PeerCertificate() const;
    Windows::Networking::Sockets::SocketSslErrorSeverity PeerCertificateErrorSeverity() const;
    Windows::Foundation::Collections::IVectorView<winrt::Windows::Security::Cryptography::Certificates::ChainValidationResult> PeerCertificateErrors() const;
    Windows::Foundation::Collections::IVectorView<Windows::Security::Cryptography::Certificates::Certificate> PeerIntermediateCertificates() const;
    void Accept() const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynMessageInfo
{
    hstring SenderUniqueName() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynMessageInfoFactory
{
    Windows::Devices::AllJoyn::AllJoynMessageInfo Create(hstring_view senderUniqueName) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynProducer
{
    void SetBusObject(const Windows::Devices::AllJoyn::AllJoynBusObject & busObject) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynProducerStoppedEventArgs
{
    int32_t Status() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynProducerStoppedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs Create(int32_t status) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynServiceInfo
{
    hstring UniqueName() const;
    hstring ObjectPath() const;
    uint16_t SessionPort() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynServiceInfoFactory
{
    Windows::Devices::AllJoyn::AllJoynServiceInfo Create(hstring_view uniqueName, hstring_view objectPath, uint16_t sessionPort) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynServiceInfoRemovedEventArgs
{
    hstring UniqueName() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynServiceInfoRemovedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynServiceInfoRemovedEventArgs Create(hstring_view uniqueName) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynServiceInfoStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynServiceInfo> FromIdAsync(hstring_view deviceId) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSession
{
    int32_t Id() const;
    int32_t Status() const;
    Windows::Foundation::IAsyncOperation<int32_t> RemoveMemberAsync(hstring_view uniqueName) const;
    event_token MemberAdded(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs> & handler) const;
    using MemberAdded_revoker = event_revoker<IAllJoynSession>;
    MemberAdded_revoker MemberAdded(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs> & handler) const;
    void MemberAdded(event_token token) const;
    event_token MemberRemoved(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs> & handler) const;
    using MemberRemoved_revoker = event_revoker<IAllJoynSession>;
    MemberRemoved_revoker MemberRemoved(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs> & handler) const;
    void MemberRemoved(event_token token) const;
    event_token Lost(const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs> & handler) const;
    using Lost_revoker = event_revoker<IAllJoynSession>;
    Lost_revoker Lost(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Devices::AllJoyn::AllJoynSession, Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs> & handler) const;
    void Lost(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionJoinedEventArgs
{
    Windows::Devices::AllJoyn::AllJoynSession Session() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionJoinedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs Create(const Windows::Devices::AllJoyn::AllJoynSession & session) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionLostEventArgs
{
    Windows::Devices::AllJoyn::AllJoynSessionLostReason Reason() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionLostEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs Create(Windows::Devices::AllJoyn::AllJoynSessionLostReason reason) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionMemberAddedEventArgs
{
    hstring UniqueName() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionMemberAddedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs Create(hstring_view uniqueName) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionMemberRemovedEventArgs
{
    hstring UniqueName() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionMemberRemovedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs Create(hstring_view uniqueName) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynSessionStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> GetFromServiceInfoAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo) const;
    Windows::Foundation::IAsyncOperation<Windows::Devices::AllJoyn::AllJoynSession> GetFromServiceInfoAsync(const Windows::Devices::AllJoyn::AllJoynServiceInfo & serviceInfo, const Windows::Devices::AllJoyn::AllJoynBusAttachment & busAttachment) const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynStatusStatics
{
    int32_t Ok() const;
    int32_t Fail() const;
    int32_t OperationTimedOut() const;
    int32_t OtherEndClosed() const;
    int32_t ConnectionRefused() const;
    int32_t AuthenticationFailed() const;
    int32_t AuthenticationRejectedByUser() const;
    int32_t SslConnectFailed() const;
    int32_t SslIdentityVerificationFailed() const;
    int32_t InsufficientSecurity() const;
    int32_t InvalidArgument1() const;
    int32_t InvalidArgument2() const;
    int32_t InvalidArgument3() const;
    int32_t InvalidArgument4() const;
    int32_t InvalidArgument5() const;
    int32_t InvalidArgument6() const;
    int32_t InvalidArgument7() const;
    int32_t InvalidArgument8() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynWatcherStoppedEventArgs
{
    int32_t Status() const;
};

template <typename D>
struct WINRT_EBO impl_IAllJoynWatcherStoppedEventArgsFactory
{
    Windows::Devices::AllJoyn::AllJoynWatcherStoppedEventArgs Create(int32_t status) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAboutData>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAboutData;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAboutData<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAboutDataView>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataView;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAboutDataView<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAboutDataViewStatics>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAboutDataViewStatics;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAboutDataViewStatics<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoiner;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAcceptSessionJoiner<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAcceptSessionJoinerEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAcceptSessionJoinerEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynAuthenticationCompleteEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusAttachment>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusAttachment<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusAttachment2>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachment2;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusAttachment2<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusAttachmentFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusAttachmentFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusAttachmentStateChangedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusAttachmentStatics>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusAttachmentStatics;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusAttachmentStatics<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusObject>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusObject;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusObject<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusObjectFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusObjectFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusObjectStoppedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynBusObjectStoppedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynCredentials>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynCredentials;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynCredentials<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynCredentialsRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynCredentialsVerificationRequestedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynMessageInfo>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfo;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynMessageInfo<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynMessageInfoFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynMessageInfoFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynMessageInfoFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynProducer>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynProducer;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynProducer<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynProducerStoppedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynProducerStoppedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynProducerStoppedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynServiceInfo>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfo;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynServiceInfo<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynServiceInfoFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynServiceInfoFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynServiceInfoRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynServiceInfoRemovedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynServiceInfoStatics>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynServiceInfoStatics;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynServiceInfoStatics<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSession>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSession;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSession<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionJoinedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionJoinedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionJoinedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionLostEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionLostEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionLostEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionMemberAddedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionMemberAddedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionMemberRemovedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionMemberRemovedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynSessionStatics>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynSessionStatics;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynSessionStatics<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynStatusStatics>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynStatusStatics;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynStatusStatics<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynWatcherStoppedEventArgs<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgsFactory>
{
    using abi = ABI::Windows::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgsFactory;
    template <typename D> using consume = Windows::Devices::AllJoyn::impl_IAllJoynWatcherStoppedEventArgsFactory<D>;
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynAboutData>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynAboutData;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynAboutData"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynAboutDataView>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynAboutDataView;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynAboutDataView"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynAcceptSessionJoinerEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynAcceptSessionJoinerEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynAuthenticationCompleteEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynAuthenticationCompleteEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusAttachment>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynBusAttachment;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynBusAttachment"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynBusAttachmentStateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynBusAttachmentStateChangedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusObject>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynBusObject;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynBusObject"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynBusObjectStoppedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynBusObjectStoppedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentials>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynCredentials;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynCredentials"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynCredentialsRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynCredentialsRequestedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynCredentialsVerificationRequestedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynCredentialsVerificationRequestedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynMessageInfo>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynMessageInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynMessageInfo"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynProducerStoppedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynProducerStoppedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynServiceInfo>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynServiceInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynServiceInfo"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynServiceInfoRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynServiceInfoRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynServiceInfoRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynSession>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynSession"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynSessionJoinedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynSessionJoinedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynSessionLostEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynSessionLostEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynSessionMemberAddedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynSessionMemberAddedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynSessionMemberRemovedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynSessionMemberRemovedEventArgs"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynStatus>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynStatus"; }
};

template <> struct traits<Windows::Devices::AllJoyn::AllJoynWatcherStoppedEventArgs>
{
    using abi = ABI::Windows::Devices::AllJoyn::AllJoynWatcherStoppedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.AllJoyn.AllJoynWatcherStoppedEventArgs"; }
};

}

}
