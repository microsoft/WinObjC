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

// WindowsDevicesEnumerationPnp.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDEPPnpObjectUpdate, WDEPPnpObjectCollection, WDEPPnpObjectWatcher, WDEPPnpObject;
@protocol WDEPIPnpObjectUpdate
, WDEPIPnpObjectWatcher, WDEPIPnpObjectStatics, WDEPIPnpObject;

// Windows.Devices.Enumeration.Pnp.PnpObjectType
enum _WDEPPnpObjectType {
    WDEPPnpObjectTypeUnknown = 0,
    WDEPPnpObjectTypeDeviceInterface = 1,
    WDEPPnpObjectTypeDeviceContainer = 2,
    WDEPPnpObjectTypeDevice = 3,
    WDEPPnpObjectTypeDeviceInterfaceClass = 4,
    WDEPPnpObjectTypeAssociationEndpoint = 5,
    WDEPPnpObjectTypeAssociationEndpointContainer = 6,
    WDEPPnpObjectTypeAssociationEndpointService = 7,
};
typedef unsigned WDEPPnpObjectType;

#include "WindowsDevicesEnumeration.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Enumeration.Pnp.PnpObjectUpdate
#ifndef __WDEPPnpObjectUpdate_DEFINED__
#define __WDEPPnpObjectUpdate_DEFINED__

WINRT_EXPORT
@interface WDEPPnpObjectUpdate : RTObject
@property (readonly) NSString* id;
@property (readonly) NSDictionary* properties;
@property (readonly) WDEPPnpObjectType type;
@end

#endif // __WDEPPnpObjectUpdate_DEFINED__

// Windows.Devices.Enumeration.Pnp.PnpObjectCollection
#ifndef __WDEPPnpObjectCollection_DEFINED__
#define __WDEPPnpObjectCollection_DEFINED__

WINRT_EXPORT
@interface WDEPPnpObjectCollection : RTObject
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

@end

#endif // __WDEPPnpObjectCollection_DEFINED__

// Windows.Devices.Enumeration.Pnp.PnpObjectWatcher
#ifndef __WDEPPnpObjectWatcher_DEFINED__
#define __WDEPPnpObjectWatcher_DEFINED__

WINRT_EXPORT
@interface WDEPPnpObjectWatcher : RTObject
@property (readonly) WDEDeviceWatcherStatus status;
- (EventRegistrationToken)addAddedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObject*))del;
- (void)removeAddedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WDEPPnpObjectWatcher*, RTObject*))del;
- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRemovedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*))del;
- (void)removeRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStoppedEvent:(void (^)(WDEPPnpObjectWatcher*, RTObject*))del;
- (void)removeStoppedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUpdatedEvent:(void (^)(WDEPPnpObjectWatcher*, WDEPPnpObjectUpdate*))del;
- (void)removeUpdatedEvent:(EventRegistrationToken)tok;
- (void)start;
- (void)stop;
@end

#endif // __WDEPPnpObjectWatcher_DEFINED__

// Windows.Devices.Enumeration.Pnp.PnpObject
#ifndef __WDEPPnpObject_DEFINED__
#define __WDEPPnpObject_DEFINED__

WINRT_EXPORT
@interface WDEPPnpObject : RTObject
+ (void)createFromIdAsync:(WDEPPnpObjectType)type
                       id:(NSString*)id
      requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                  success:(void (^)(WDEPPnpObject*))success
                  failure:(void (^)(NSError*))failure;
+ (void)findAllAsync:(WDEPPnpObjectType)type
 requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
             success:(void (^)(WDEPPnpObjectCollection*))success
             failure:(void (^)(NSError*))failure;
+ (void)findAllAsyncAqsFilter:(WDEPPnpObjectType)type
          requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                    aqsFilter:(NSString*)aqsFilter
                      success:(void (^)(WDEPPnpObjectCollection*))success
                      failure:(void (^)(NSError*))failure;
+ (WDEPPnpObjectWatcher*)createWatcher:(WDEPPnpObjectType)type
                   requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties;
+ (WDEPPnpObjectWatcher*)createWatcherAqsFilter:(WDEPPnpObjectType)type
                            requestedProperties:(id<NSFastEnumeration> /* NSString * */)requestedProperties
                                      aqsFilter:(NSString*)aqsFilter;
@property (readonly) NSString* id;
@property (readonly) NSDictionary* properties;
@property (readonly) WDEPPnpObjectType type;
- (void)update:(WDEPPnpObjectUpdate*)updateInfo;
@end

#endif // __WDEPPnpObject_DEFINED__
