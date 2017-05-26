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

// WindowsNetworking.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Networking.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsNetworking.h"
#include "WindowsNetworking_priv.h"

@implementation WNHostName

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::IHostName> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::IHostNameFactory> WNIHostNameFactory_inst() {
    ComPtr<ABI::Windows::Networking::IHostNameFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.HostName").Get(), &inst));
    return inst;
}

+ (WNHostName*)makeHostName:(NSString*)hostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = WNIHostNameFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateHostName(nsStrToHstr(hostName).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNHostName>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Networking::IHostNameStatics> WNIHostNameStatics_inst() {
    ComPtr<ABI::Windows::Networking::IHostNameStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.HostName").Get(), &inst));
    return inst;
}

+ (int)compare:(NSString*)value1 value2:(NSString*)value2 {
    int unmarshalledReturn;
    auto _comInst = WNIHostNameStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Compare(nsStrToHstr(value1).Get(), nsStrToHstr(value2).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (WNCIPInformation*)iPInformation {
    ComPtr<ABI::Windows::Networking::Connectivity::IIPInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->get_IPInformation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNCIPInformation>(unmarshalledReturn.Get());
}

- (NSString*)rawName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)canonicalName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanonicalName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WNHostNameType)type {
    ABI::Windows::Networking::HostNameType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WNHostNameType)unmarshalledReturn;
}

- (BOOL)IsEqual:(WNHostName*)hostName {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IHostName>(self);
    THROW_NS_IF_FAILED(_comInst->IsEqual(_getRtInterface<ABI::Windows::Networking::IHostName>(hostName).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WNEndpointPair

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Networking::IEndpointPair> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Networking::IEndpointPairFactory> WNIEndpointPairFactory_inst() {
    ComPtr<ABI::Windows::Networking::IEndpointPairFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Networking.EndpointPair").Get(), &inst));
    return inst;
}

+ (WNEndpointPair*)makeEndpointPair:(WNHostName*)localHostName
                   localServiceName:(NSString*)localServiceName
                     remoteHostName:(WNHostName*)remoteHostName
                  remoteServiceName:(NSString*)remoteServiceName {
    ComPtr<ABI::Windows::Networking::IEndpointPair> unmarshalledReturn;
    auto _comInst = WNIEndpointPairFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateEndpointPair(_getRtInterface<ABI::Windows::Networking::IHostName>(localHostName).Get(),
                                                    nsStrToHstr(localServiceName).Get(),
                                                    _getRtInterface<ABI::Windows::Networking::IHostName>(remoteHostName).Get(),
                                                    nsStrToHstr(remoteServiceName).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WNEndpointPair>(unmarshalledReturn.Get()) retain];
}

- (WNHostName*)localHostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalHostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setLocalHostName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalHostName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (NSString*)localServiceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->get_LocalServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLocalServiceName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->put_LocalServiceName(nsStrToHstr(value).Get()));
}

- (WNHostName*)remoteHostName {
    ComPtr<ABI::Windows::Networking::IHostName> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteHostName(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WNHostName>(unmarshalledReturn.Get());
}

- (void)setRemoteHostName:(WNHostName*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteHostName(_getRtInterface<ABI::Windows::Networking::IHostName>(value).Get()));
}

- (NSString*)remoteServiceName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->get_RemoteServiceName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setRemoteServiceName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Networking::IEndpointPair>(self);
    THROW_NS_IF_FAILED(_comInst->put_RemoteServiceName(nsStrToHstr(value).Get()));
}

@end
