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

// WindowsDevicesUsb.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
#define OBJCUWP_WINDOWS_DEVICES_USB_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Devices_Usb.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WDUUsbControlRequestType, WDUUsbSetupPacket, WDUUsbDeviceClass, WDUUsbDeviceClasses, WDUUsbDevice, WDUUsbInterface,
    WDUUsbDeviceDescriptor, WDUUsbConfiguration, WDUUsbDescriptor, WDUUsbConfigurationDescriptor, WDUUsbInterfaceDescriptor,
    WDUUsbBulkInEndpointDescriptor, WDUUsbInterruptInEndpointDescriptor, WDUUsbBulkOutEndpointDescriptor,
    WDUUsbInterruptOutEndpointDescriptor, WDUUsbEndpointDescriptor, WDUUsbInterruptInEventArgs, WDUUsbInterruptInPipe, WDUUsbBulkInPipe,
    WDUUsbBulkOutPipe, WDUUsbInterruptOutPipe, WDUUsbInterfaceSetting;
@protocol WDUIUsbControlRequestType
, WDUIUsbSetupPacketFactory, WDUIUsbSetupPacket, WDUIUsbDeviceClass, WDUIUsbDeviceClassesStatics, WDUIUsbDeviceClasses,
    WDUIUsbDeviceStatics, WDUIUsbDeviceDescriptor, WDUIUsbConfigurationDescriptor, WDUIUsbConfigurationDescriptorStatics,
    WDUIUsbInterfaceDescriptor, WDUIUsbInterfaceDescriptorStatics, WDUIUsbEndpointDescriptor, WDUIUsbEndpointDescriptorStatics,
    WDUIUsbDescriptor, WDUIUsbInterruptInEventArgs, WDUIUsbBulkInPipe, WDUIUsbInterruptInPipe, WDUIUsbBulkOutPipe, WDUIUsbInterruptOutPipe,
    WDUIUsbConfiguration, WDUIUsbInterface, WDUIUsbInterfaceSetting, WDUIUsbBulkInEndpointDescriptor, WDUIUsbInterruptInEndpointDescriptor,
    WDUIUsbBulkOutEndpointDescriptor, WDUIUsbInterruptOutEndpointDescriptor, WDUIUsbDevice;

// Windows.Devices.Usb.UsbTransferDirection
enum _WDUUsbTransferDirection {
    WDUUsbTransferDirectionOut = 0,
    WDUUsbTransferDirectionIn = 1,
};
typedef unsigned WDUUsbTransferDirection;

// Windows.Devices.Usb.UsbEndpointType
enum _WDUUsbEndpointType {
    WDUUsbEndpointTypeControl = 0,
    WDUUsbEndpointTypeIsochronous = 1,
    WDUUsbEndpointTypeBulk = 2,
    WDUUsbEndpointTypeInterrupt = 3,
};
typedef unsigned WDUUsbEndpointType;

// Windows.Devices.Usb.UsbControlRecipient
enum _WDUUsbControlRecipient {
    WDUUsbControlRecipientDevice = 0,
    WDUUsbControlRecipientSpecifiedInterface = 1,
    WDUUsbControlRecipientEndpoint = 2,
    WDUUsbControlRecipientOther = 3,
    WDUUsbControlRecipientDefaultInterface = 4,
};
typedef unsigned WDUUsbControlRecipient;

// Windows.Devices.Usb.UsbControlTransferType
enum _WDUUsbControlTransferType {
    WDUUsbControlTransferTypeStandard = 0,
    WDUUsbControlTransferTypeClass = 1,
    WDUUsbControlTransferTypeVendor = 2,
};
typedef unsigned WDUUsbControlTransferType;

// Windows.Devices.Usb.UsbReadOptions
enum _WDUUsbReadOptions {
    WDUUsbReadOptionsNone = 0,
    WDUUsbReadOptionsAutoClearStall = 1,
    WDUUsbReadOptionsOverrideAutomaticBufferManagement = 2,
    WDUUsbReadOptionsIgnoreShortPacket = 4,
    WDUUsbReadOptionsAllowPartialReads = 8,
};
typedef unsigned WDUUsbReadOptions;

// Windows.Devices.Usb.UsbWriteOptions
enum _WDUUsbWriteOptions {
    WDUUsbWriteOptionsNone = 0,
    WDUUsbWriteOptionsAutoClearStall = 1,
    WDUUsbWriteOptionsShortPacketTerminate = 2,
};
typedef unsigned WDUUsbWriteOptions;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Devices.Usb.UsbControlRequestType
#ifndef __WDUUsbControlRequestType_DEFINED__
#define __WDUUsbControlRequestType_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbControlRequestType : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDUUsbControlRecipient recipient;
@property WDUUsbTransferDirection direction;
@property WDUUsbControlTransferType controlTransferType;
@property uint8_t asByte;
@end

#endif // __WDUUsbControlRequestType_DEFINED__

// Windows.Devices.Usb.UsbSetupPacket
#ifndef __WDUUsbSetupPacket_DEFINED__
#define __WDUUsbSetupPacket_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbSetupPacket : RTObject
+ (WDUUsbSetupPacket*)makeWithEightByteBuffer:(RTObject<WSSIBuffer>*)eightByteBuffer ACTIVATOR;
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property unsigned int value;
@property (retain) WDUUsbControlRequestType* requestType;
@property uint8_t request;
@property unsigned int length;
@property unsigned int index;
@end

#endif // __WDUUsbSetupPacket_DEFINED__

// Windows.Devices.Usb.UsbDeviceClass
#ifndef __WDUUsbDeviceClass_DEFINED__
#define __WDUUsbDeviceClass_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbDeviceClass : RTObject
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (retain) id /* uint8_t */ subclassCode;
@property (retain) id /* uint8_t */ protocolCode;
@property uint8_t classCode;
@end

#endif // __WDUUsbDeviceClass_DEFINED__

// Windows.Devices.Usb.UsbDeviceClasses
#ifndef __WDUUsbDeviceClasses_DEFINED__
#define __WDUUsbDeviceClasses_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbDeviceClasses : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
+ (WDUUsbDeviceClass*)activeSync;
+ (WDUUsbDeviceClass*)cdcControl;
+ (WDUUsbDeviceClass*)deviceFirmwareUpdate;
+ (WDUUsbDeviceClass*)irda;
+ (WDUUsbDeviceClass*)measurement;
+ (WDUUsbDeviceClass*)palmSync;
+ (WDUUsbDeviceClass*)personalHealthcare;
+ (WDUUsbDeviceClass*)physical;
+ (WDUUsbDeviceClass*)vendorSpecific;
@end

#endif // __WDUUsbDeviceClasses_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Devices.Usb.UsbDevice
#ifndef __WDUUsbDevice_DEFINED__
#define __WDUUsbDevice_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbDevice : RTObject <WFIClosable>
+ (NSString*)getDeviceSelector:(unsigned int)vendorId productId:(unsigned int)productId winUsbInterfaceClass:(WFGUID*)winUsbInterfaceClass;
+ (NSString*)getDeviceSelectorGuidOnly:(WFGUID*)winUsbInterfaceClass;
+ (NSString*)getDeviceSelectorVidPidOnly:(unsigned int)vendorId productId:(unsigned int)productId;
+ (NSString*)getDeviceClassSelector:(WDUUsbDeviceClass*)usbClass;
+ (void)fromIdAsync:(NSString*)deviceId success:(void (^)(WDUUsbDevice*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDUUsbConfiguration* configuration;
@property (readonly) WDUUsbInterface* defaultInterface;
@property (readonly) WDUUsbDeviceDescriptor* deviceDescriptor;
- (void)sendControlOutTransferAsync:(WDUUsbSetupPacket*)setupPacket
                             buffer:(RTObject<WSSIBuffer>*)buffer
                            success:(void (^)(unsigned int))success
                            failure:(void (^)(NSError*))failure;
- (void)sendControlOutTransferAsyncNoBuffer:(WDUUsbSetupPacket*)setupPacket
                                    success:(void (^)(unsigned int))success
                                    failure:(void (^)(NSError*))failure;
- (void)sendControlInTransferAsync:(WDUUsbSetupPacket*)setupPacket
                            buffer:(RTObject<WSSIBuffer>*)buffer
                           success:(void (^)(RTObject<WSSIBuffer>*))success
                           failure:(void (^)(NSError*))failure;
- (void)sendControlInTransferAsyncNoBuffer:(WDUUsbSetupPacket*)setupPacket
                                   success:(void (^)(RTObject<WSSIBuffer>*))success
                                   failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WDUUsbDevice_DEFINED__

// Windows.Devices.Usb.UsbInterface
#ifndef __WDUUsbInterface_DEFINED__
#define __WDUUsbInterface_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterface : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WDUUsbBulkInPipe* */ bulkInPipes;
@property (readonly) NSArray* /* WDUUsbBulkOutPipe* */ bulkOutPipes;
@property (readonly) NSArray* /* WDUUsbDescriptor* */ descriptors;
@property (readonly) uint8_t interfaceNumber;
@property (readonly) NSArray* /* WDUUsbInterfaceSetting* */ interfaceSettings;
@property (readonly) NSArray* /* WDUUsbInterruptInPipe* */ interruptInPipes;
@property (readonly) NSArray* /* WDUUsbInterruptOutPipe* */ interruptOutPipes;
@end

#endif // __WDUUsbInterface_DEFINED__

// Windows.Devices.Usb.UsbDeviceDescriptor
#ifndef __WDUUsbDeviceDescriptor_DEFINED__
#define __WDUUsbDeviceDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbDeviceDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) unsigned int bcdDeviceRevision;
@property (readonly) unsigned int bcdUsb;
@property (readonly) uint8_t maxPacketSize0;
@property (readonly) uint8_t numberOfConfigurations;
@property (readonly) unsigned int productId;
@property (readonly) unsigned int vendorId;
@end

#endif // __WDUUsbDeviceDescriptor_DEFINED__

// Windows.Devices.Usb.UsbConfiguration
#ifndef __WDUUsbConfiguration_DEFINED__
#define __WDUUsbConfiguration_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbConfiguration : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDUUsbConfigurationDescriptor* configurationDescriptor;
@property (readonly) NSArray* /* WDUUsbDescriptor* */ descriptors;
@property (readonly) NSArray* /* WDUUsbInterface* */ usbInterfaces;
@end

#endif // __WDUUsbConfiguration_DEFINED__

// Windows.Devices.Usb.UsbDescriptor
#ifndef __WDUUsbDescriptor_DEFINED__
#define __WDUUsbDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t descriptorType;
@property (readonly) uint8_t length;
- (void)readDescriptorBuffer:(RTObject<WSSIBuffer>*)buffer;
@end

#endif // __WDUUsbDescriptor_DEFINED__

// Windows.Devices.Usb.UsbConfigurationDescriptor
#ifndef __WDUUsbConfigurationDescriptor_DEFINED__
#define __WDUUsbConfigurationDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbConfigurationDescriptor : RTObject
+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbConfigurationDescriptor**)parsed;
+ (WDUUsbConfigurationDescriptor*)parse:(WDUUsbDescriptor*)descriptor;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t configurationValue;
@property (readonly) unsigned int maxPowerMilliamps;
@property (readonly) BOOL remoteWakeup;
@property (readonly) BOOL selfPowered;
@end

#endif // __WDUUsbConfigurationDescriptor_DEFINED__

// Windows.Devices.Usb.UsbInterfaceDescriptor
#ifndef __WDUUsbInterfaceDescriptor_DEFINED__
#define __WDUUsbInterfaceDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterfaceDescriptor : RTObject
+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbInterfaceDescriptor**)parsed;
+ (WDUUsbInterfaceDescriptor*)parse:(WDUUsbDescriptor*)descriptor;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t alternateSettingNumber;
@property (readonly) uint8_t classCode;
@property (readonly) uint8_t interfaceNumber;
@property (readonly) uint8_t protocolCode;
@property (readonly) uint8_t subclassCode;
@end

#endif // __WDUUsbInterfaceDescriptor_DEFINED__

// Windows.Devices.Usb.UsbBulkInEndpointDescriptor
#ifndef __WDUUsbBulkInEndpointDescriptor_DEFINED__
#define __WDUUsbBulkInEndpointDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbBulkInEndpointDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t endpointNumber;
@property (readonly) unsigned int maxPacketSize;
@property (readonly) WDUUsbBulkInPipe* pipe;
@end

#endif // __WDUUsbBulkInEndpointDescriptor_DEFINED__

// Windows.Devices.Usb.UsbInterruptInEndpointDescriptor
#ifndef __WDUUsbInterruptInEndpointDescriptor_DEFINED__
#define __WDUUsbInterruptInEndpointDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterruptInEndpointDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t endpointNumber;
@property (readonly) WFTimeSpan* interval;
@property (readonly) unsigned int maxPacketSize;
@property (readonly) WDUUsbInterruptInPipe* pipe;
@end

#endif // __WDUUsbInterruptInEndpointDescriptor_DEFINED__

// Windows.Devices.Usb.UsbBulkOutEndpointDescriptor
#ifndef __WDUUsbBulkOutEndpointDescriptor_DEFINED__
#define __WDUUsbBulkOutEndpointDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbBulkOutEndpointDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t endpointNumber;
@property (readonly) unsigned int maxPacketSize;
@property (readonly) WDUUsbBulkOutPipe* pipe;
@end

#endif // __WDUUsbBulkOutEndpointDescriptor_DEFINED__

// Windows.Devices.Usb.UsbInterruptOutEndpointDescriptor
#ifndef __WDUUsbInterruptOutEndpointDescriptor_DEFINED__
#define __WDUUsbInterruptOutEndpointDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterruptOutEndpointDescriptor : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) uint8_t endpointNumber;
@property (readonly) WFTimeSpan* interval;
@property (readonly) unsigned int maxPacketSize;
@property (readonly) WDUUsbInterruptOutPipe* pipe;
@end

#endif // __WDUUsbInterruptOutEndpointDescriptor_DEFINED__

// Windows.Devices.Usb.UsbEndpointDescriptor
#ifndef __WDUUsbEndpointDescriptor_DEFINED__
#define __WDUUsbEndpointDescriptor_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbEndpointDescriptor : RTObject
+ (BOOL)tryParse:(WDUUsbDescriptor*)descriptor parsed:(WDUUsbEndpointDescriptor**)parsed;
+ (WDUUsbEndpointDescriptor*)parse:(WDUUsbDescriptor*)descriptor;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDUUsbBulkInEndpointDescriptor* asBulkInEndpointDescriptor;
@property (readonly) WDUUsbBulkOutEndpointDescriptor* asBulkOutEndpointDescriptor;
@property (readonly) WDUUsbInterruptInEndpointDescriptor* asInterruptInEndpointDescriptor;
@property (readonly) WDUUsbInterruptOutEndpointDescriptor* asInterruptOutEndpointDescriptor;
@property (readonly) WDUUsbTransferDirection direction;
@property (readonly) uint8_t endpointNumber;
@property (readonly) WDUUsbEndpointType endpointType;
@end

#endif // __WDUUsbEndpointDescriptor_DEFINED__

// Windows.Devices.Usb.UsbInterruptInEventArgs
#ifndef __WDUUsbInterruptInEventArgs_DEFINED__
#define __WDUUsbInterruptInEventArgs_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterruptInEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) RTObject<WSSIBuffer>* interruptData;
@end

#endif // __WDUUsbInterruptInEventArgs_DEFINED__

// Windows.Devices.Usb.UsbInterruptInPipe
#ifndef __WDUUsbInterruptInPipe_DEFINED__
#define __WDUUsbInterruptInPipe_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterruptInPipe : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WDUUsbInterruptInEndpointDescriptor* endpointDescriptor;
- (EventRegistrationToken)addDataReceivedEvent:(void (^)(WDUUsbInterruptInPipe*, WDUUsbInterruptInEventArgs*))del;
- (void)removeDataReceivedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)clearStallAsync;
@end

#endif // __WDUUsbInterruptInPipe_DEFINED__

// Windows.Devices.Usb.UsbBulkInPipe
#ifndef __WDUUsbBulkInPipe_DEFINED__
#define __WDUUsbBulkInPipe_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbBulkInPipe : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDUUsbReadOptions readOptions;
@property (readonly) WDUUsbBulkInEndpointDescriptor* endpointDescriptor;
@property (readonly) RTObject<WSSIInputStream>* inputStream;
@property (readonly) unsigned int maxTransferSizeBytes;
- (RTObject<WFIAsyncAction>*)clearStallAsync;
- (void)flushBuffer;
@end

#endif // __WDUUsbBulkInPipe_DEFINED__

// Windows.Devices.Usb.UsbBulkOutPipe
#ifndef __WDUUsbBulkOutPipe_DEFINED__
#define __WDUUsbBulkOutPipe_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbBulkOutPipe : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDUUsbWriteOptions writeOptions;
@property (readonly) WDUUsbBulkOutEndpointDescriptor* endpointDescriptor;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (RTObject<WFIAsyncAction>*)clearStallAsync;
@end

#endif // __WDUUsbBulkOutPipe_DEFINED__

// Windows.Devices.Usb.UsbInterruptOutPipe
#ifndef __WDUUsbInterruptOutPipe_DEFINED__
#define __WDUUsbInterruptOutPipe_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterruptOutPipe : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WDUUsbWriteOptions writeOptions;
@property (readonly) WDUUsbInterruptOutEndpointDescriptor* endpointDescriptor;
@property (readonly) RTObject<WSSIOutputStream>* outputStream;
- (RTObject<WFIAsyncAction>*)clearStallAsync;
@end

#endif // __WDUUsbInterruptOutPipe_DEFINED__

// Windows.Devices.Usb.UsbInterfaceSetting
#ifndef __WDUUsbInterfaceSetting_DEFINED__
#define __WDUUsbInterfaceSetting_DEFINED__

OBJCUWP_WINDOWS_DEVICES_USB_EXPORT
@interface WDUUsbInterfaceSetting : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) NSArray* /* WDUUsbBulkInEndpointDescriptor* */ bulkInEndpoints;
@property (readonly) NSArray* /* WDUUsbBulkOutEndpointDescriptor* */ bulkOutEndpoints;
@property (readonly) NSArray* /* WDUUsbDescriptor* */ descriptors;
@property (readonly) WDUUsbInterfaceDescriptor* interfaceDescriptor;
@property (readonly) NSArray* /* WDUUsbInterruptInEndpointDescriptor* */ interruptInEndpoints;
@property (readonly) NSArray* /* WDUUsbInterruptOutEndpointDescriptor* */ interruptOutEndpoints;
@property (readonly) BOOL selected;
- (RTObject<WFIAsyncAction>*)selectSettingAsync;
@end

#endif // __WDUUsbInterfaceSetting_DEFINED__
