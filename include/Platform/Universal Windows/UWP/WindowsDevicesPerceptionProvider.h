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

// WindowsDevicesPerceptionProvider.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDPPPerceptionFrameProviderInfo, WDPPPerceptionPropertyChangeRequest, WDPPPerceptionFaceAuthenticationGroup,
    WDPPPerceptionControlGroup, WDPPPerceptionCorrelationGroup, WDPPPerceptionFrame, WDPPPerceptionCorrelation,
    WDPPPerceptionVideoFrameAllocator, WDPPPerceptionFrameProviderManagerService, WDPPKnownPerceptionFrameKind;
@protocol WDPPIKnownPerceptionFrameKindStatics
, WDPPIPerceptionFrameProviderManagerServiceStatics, WDPPIPerceptionFrameProviderInfo, WDPPIPerceptionControlGroupFactory,
    WDPPIPerceptionControlGroup, WDPPIPerceptionFaceAuthenticationGroupFactory, WDPPIPerceptionFaceAuthenticationGroup,
    WDPPIPerceptionCorrelationFactory, WDPPIPerceptionCorrelation, WDPPIPerceptionCorrelationGroupFactory, WDPPIPerceptionCorrelationGroup,
    WDPPIPerceptionFrame, WDPPIPerceptionVideoFrameAllocatorFactory, WDPPIPerceptionPropertyChangeRequest,
    WDPPIPerceptionFrameProviderManager, WDPPIPerceptionFrameProvider, WDPPIPerceptionVideoFrameAllocator;

#include "WindowsDevicesPerception.h"
#include "WindowsFoundationCollections.h"
#include "WindowsFoundationNumerics.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsImaging.h"
#include "WindowsMedia.h"
// Windows.Devices.Perception.Provider.PerceptionStartFaceAuthenticationHandler
#ifndef __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED
#define __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED
typedef void (^WDPPPerceptionStartFaceAuthenticationHandler)(WDPPPerceptionFaceAuthenticationGroup* sender);
#endif // __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED

// Windows.Devices.Perception.Provider.PerceptionStopFaceAuthenticationHandler
#ifndef __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED
#define __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED
typedef void (^WDPPPerceptionStopFaceAuthenticationHandler)(WDPPPerceptionFaceAuthenticationGroup* sender);
#endif // __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.Devices.Perception.Provider.PerceptionStartFaceAuthenticationHandler
#ifndef __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED
#define __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED
typedef void (^WDPPPerceptionStartFaceAuthenticationHandler)(WDPPPerceptionFaceAuthenticationGroup* sender);
#endif // __WDPPPerceptionStartFaceAuthenticationHandler__DEFINED

// Windows.Devices.Perception.Provider.PerceptionStopFaceAuthenticationHandler
#ifndef __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED
#define __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED
typedef void (^WDPPPerceptionStopFaceAuthenticationHandler)(WDPPPerceptionFaceAuthenticationGroup* sender);
#endif // __WDPPPerceptionStopFaceAuthenticationHandler__DEFINED

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Perception.Provider.IPerceptionFrameProviderManager
#ifndef __WDPPIPerceptionFrameProviderManager_DEFINED__
#define __WDPPIPerceptionFrameProviderManager_DEFINED__

@protocol WDPPIPerceptionFrameProviderManager <WFIClosable>
- (RTObject<WDPPIPerceptionFrameProvider>*)getFrameProvider:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo;
- (void)close;
@end

#endif // __WDPPIPerceptionFrameProviderManager_DEFINED__

// Windows.Devices.Perception.Provider.IPerceptionFrameProvider
#ifndef __WDPPIPerceptionFrameProvider_DEFINED__
#define __WDPPIPerceptionFrameProvider_DEFINED__

@protocol WDPPIPerceptionFrameProvider <WFIClosable>
@property (readonly) BOOL available;
@property (readonly) WDPPPerceptionFrameProviderInfo* frameProviderInfo;
@property (readonly) RTObject<WFCIPropertySet>* properties;
- (void)start;
- (void)stop;
- (void)setProperty:(WDPPPerceptionPropertyChangeRequest*)value;
- (void)close;
@end

#endif // __WDPPIPerceptionFrameProvider_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionFrameProviderInfo
#ifndef __WDPPPerceptionFrameProviderInfo_DEFINED__
#define __WDPPPerceptionFrameProviderInfo_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionFrameProviderInfo : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* id;
@property BOOL hidden;
@property (copy) NSString* frameKind;
@property (copy) NSString* displayName;
@property (copy) NSString* deviceKind;
@end

#endif // __WDPPPerceptionFrameProviderInfo_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionPropertyChangeRequest
#ifndef __WDPPPerceptionPropertyChangeRequest_DEFINED__
#define __WDPPPerceptionPropertyChangeRequest_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionPropertyChangeRequest : RTObject
@property WDPPerceptionFrameSourcePropertyChangeStatus status;
@property (readonly) NSString* name;
@property (readonly) RTObject* value;
- (WFDeferral*)getDeferral;
@end

#endif // __WDPPPerceptionPropertyChangeRequest_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionFaceAuthenticationGroup
#ifndef __WDPPPerceptionFaceAuthenticationGroup_DEFINED__
#define __WDPPPerceptionFaceAuthenticationGroup_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionFaceAuthenticationGroup : RTObject
+ (WDPPPerceptionFaceAuthenticationGroup*)create:(id<NSFastEnumeration> /* NSString * */)ids
                                    startHandler:(WDPPPerceptionStartFaceAuthenticationHandler)startHandler
                                     stopHandler:(WDPPPerceptionStopFaceAuthenticationHandler)stopHandler ACTIVATOR;
@property (readonly) NSArray* frameProviderIds;
@end

#endif // __WDPPPerceptionFaceAuthenticationGroup_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionControlGroup
#ifndef __WDPPPerceptionControlGroup_DEFINED__
#define __WDPPPerceptionControlGroup_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionControlGroup : RTObject
+ (WDPPPerceptionControlGroup*)create:(id<NSFastEnumeration> /* NSString * */)ids ACTIVATOR;
@property (readonly) NSArray* frameProviderIds;
@end

#endif // __WDPPPerceptionControlGroup_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionCorrelationGroup
#ifndef __WDPPPerceptionCorrelationGroup_DEFINED__
#define __WDPPPerceptionCorrelationGroup_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionCorrelationGroup : RTObject
+ (WDPPPerceptionCorrelationGroup*)create:(id<NSFastEnumeration> /* WDPPPerceptionCorrelation* */)relativeLocations ACTIVATOR;
@property (readonly) NSArray* relativeLocations;
@end

#endif // __WDPPPerceptionCorrelationGroup_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionFrame
#ifndef __WDPPPerceptionFrame_DEFINED__
#define __WDPPPerceptionFrame_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionFrame : RTObject
@property (copy) WFTimeSpan* relativeTime;
@property (readonly) RTObject<WFIMemoryBuffer>* frameData;
@property (readonly) WFCValueSet* properties;
@end

#endif // __WDPPPerceptionFrame_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionCorrelation
#ifndef __WDPPPerceptionCorrelation_DEFINED__
#define __WDPPPerceptionCorrelation_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionCorrelation : RTObject
+ (WDPPPerceptionCorrelation*)create:(NSString*)targetId position:(WFNVector3*)position orientation:(WFNQuaternion*)orientation ACTIVATOR;
@property (readonly) WFNQuaternion* orientation;
@property (readonly) WFNVector3* position;
@property (readonly) NSString* targetId;
@end

#endif // __WDPPPerceptionCorrelation_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionVideoFrameAllocator
#ifndef __WDPPPerceptionVideoFrameAllocator_DEFINED__
#define __WDPPPerceptionVideoFrameAllocator_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionVideoFrameAllocator : RTObject <WFIClosable>
+ (WDPPPerceptionVideoFrameAllocator*)create:(unsigned int)maxOutstandingFrameCountForWrite
                                      format:(WGIBitmapPixelFormat)format
                                  resolution:(WFSize*)resolution
                                       alpha:(WGIBitmapAlphaMode)alpha ACTIVATOR;
- (WDPPPerceptionFrame*)allocateFrame;
- (WDPPPerceptionFrame*)copyFromVideoFrame:(WMVideoFrame*)frame;
- (void)close;
@end

#endif // __WDPPPerceptionVideoFrameAllocator_DEFINED__

// Windows.Devices.Perception.Provider.PerceptionFrameProviderManagerService
#ifndef __WDPPPerceptionFrameProviderManagerService_DEFINED__
#define __WDPPPerceptionFrameProviderManagerService_DEFINED__

WINRT_EXPORT
@interface WDPPPerceptionFrameProviderManagerService : RTObject
+ (void)registerFrameProviderInfo:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                frameProviderInfo:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo;
+ (void)unregisterFrameProviderInfo:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  frameProviderInfo:(WDPPPerceptionFrameProviderInfo*)frameProviderInfo;
+ (void)registerFaceAuthenticationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                faceAuthenticationGroup:(WDPPPerceptionFaceAuthenticationGroup*)faceAuthenticationGroup;
+ (void)unregisterFaceAuthenticationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  faceAuthenticationGroup:(WDPPPerceptionFaceAuthenticationGroup*)faceAuthenticationGroup;
+ (void)registerControlGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager controlGroup:(WDPPPerceptionControlGroup*)controlGroup;
+ (void)unregisterControlGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  controlGroup:(WDPPPerceptionControlGroup*)controlGroup;
+ (void)registerCorrelationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                correlationGroup:(WDPPPerceptionCorrelationGroup*)correlationGroup;
+ (void)unregisterCorrelationGroup:(RTObject<WDPPIPerceptionFrameProviderManager>*)manager
                  correlationGroup:(WDPPPerceptionCorrelationGroup*)correlationGroup;
+ (void)updateAvailabilityForProvider:(RTObject<WDPPIPerceptionFrameProvider>*)provider available:(BOOL)available;
+ (void)publishFrameForProvider:(RTObject<WDPPIPerceptionFrameProvider>*)provider frame:(WDPPPerceptionFrame*)frame;
@end

#endif // __WDPPPerceptionFrameProviderManagerService_DEFINED__

// Windows.Devices.Perception.Provider.KnownPerceptionFrameKind
#ifndef __WDPPKnownPerceptionFrameKind_DEFINED__
#define __WDPPKnownPerceptionFrameKind_DEFINED__

WINRT_EXPORT
@interface WDPPKnownPerceptionFrameKind : RTObject
+ (NSString*)color;
+ (NSString*)depth;
+ (NSString*)infrared;
@end

#endif // __WDPPKnownPerceptionFrameKind_DEFINED__
