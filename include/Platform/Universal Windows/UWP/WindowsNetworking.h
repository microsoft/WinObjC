//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsNetworking.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WNHostName, WNEndpointPair;
@protocol WNIHostNameStatics
, WNIHostName, WNIHostNameFactory, WNIEndpointPair, WNIEndpointPairFactory;

// Windows.Networking.HostNameSortOptions
enum _WNHostNameSortOptions {
    WNHostNameSortOptionsNone = 0,
    WNHostNameSortOptionsOptimizeForLongConnections = 2,
};
typedef unsigned WNHostNameSortOptions;

// Windows.Networking.HostNameType
enum _WNHostNameType {
    WNHostNameTypeDomainName = 0,
    WNHostNameTypeIpv4 = 1,
    WNHostNameTypeIpv6 = 2,
    WNHostNameTypeBluetooth = 3,
};
typedef unsigned WNHostNameType;

// Windows.Networking.DomainNameType
enum _WNDomainNameType {
    WNDomainNameTypeSuffix = 0,
    WNDomainNameTypeFullyQualified = 1,
};
typedef unsigned WNDomainNameType;

#include "WindowsNetworkingConnectivity.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Foundation.IStringable
#ifndef __WFIStringable_DEFINED__
#define __WFIStringable_DEFINED__

@protocol WFIStringable
- (NSString*)toString;
@end

#endif // __WFIStringable_DEFINED__

// Windows.Networking.HostName
#ifndef __WNHostName_DEFINED__
#define __WNHostName_DEFINED__

WINRT_EXPORT
@interface WNHostName : RTObject <WFIStringable>
+ (int)compare:(NSString*)value1 value2:(NSString*)value2;
+ (WNHostName*)createHostName:(NSString*)hostName ACTIVATOR;
@property (readonly) NSString* canonicalName;
@property (readonly) NSString* displayName;
@property (readonly) WNCIPInformation* iPInformation;
@property (readonly) NSString* rawName;
@property (readonly) WNHostNameType type;
- (BOOL)isEqual:(WNHostName*)hostName;
- (NSString*)toString;
@end

#endif // __WNHostName_DEFINED__

// Windows.Networking.EndpointPair
#ifndef __WNEndpointPair_DEFINED__
#define __WNEndpointPair_DEFINED__

WINRT_EXPORT
@interface WNEndpointPair : RTObject
+ (WNEndpointPair*)createEndpointPair:(WNHostName*)localHostName
                     localServiceName:(NSString*)localServiceName
                       remoteHostName:(WNHostName*)remoteHostName
                    remoteServiceName:(NSString*)remoteServiceName ACTIVATOR;
@property (copy) NSString* remoteServiceName;
@property (copy) WNHostName* remoteHostName;
@property (copy) NSString* localServiceName;
@property (copy) WNHostName* localHostName;
@end

#endif // __WNEndpointPair_DEFINED__
