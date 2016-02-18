//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <CoreBluetooth/CoreBluetoothExport.h>
#import <CoreBluetooth/CBPeer.h>

#import <CoreFoundation/CFUUID.h>

#import <Foundation/NSObject.h>

@class NSUUID;
@class NSString;
@protocol CBPeripheralDelegate;
@class NSArray;
@class CBService;
@class CBCharacteristic;
@class CBDescriptor;
@class NSData;
@class NSNumber;

typedef enum {
    CBCharacteristicWriteWithResponse = 0,
    CBCharacteristicWriteWithoutResponse,
} CBCharacteristicWriteType;
typedef enum {
    CBPeripheralStateDisconnected = 0,
    CBPeripheralStateConnecting,
    CBPeripheralStateConnected,
} CBPeripheralState;

COREBLUETOOTH_EXPORT_CLASS
@interface CBPeripheral : CBPeer <NSCopying, NSObject>
@property (readonly, nonatomic) CFUUIDRef UUID STUB_PROPERTY;
@property (readonly, nonatomic) NSUUID* identifier STUB_PROPERTY;
@property (readonly, retain) NSString* name STUB_PROPERTY;
@property (assign, nonatomic) id<CBPeripheralDelegate> delegate STUB_PROPERTY;
- (void)discoverServices:(NSArray*)serviceUUIDs STUB_METHOD;
- (void)discoverIncludedServices:(NSArray*)includedServiceUUIDs forService:(CBService*)service STUB_METHOD;
@property (readonly, retain) NSArray* services STUB_PROPERTY;
- (void)discoverCharacteristics:(NSArray*)characteristicUUIDs forService:(CBService*)service STUB_METHOD;
- (void)discoverDescriptorsForCharacteristic:(CBCharacteristic*)characteristic STUB_METHOD;
- (void)readValueForCharacteristic:(CBCharacteristic*)characteristic STUB_METHOD;
- (void)readValueForDescriptor:(CBDescriptor*)descriptor STUB_METHOD;
- (void)writeValue:(NSData*)data forCharacteristic:(CBCharacteristic*)characteristic type:(CBCharacteristicWriteType)type STUB_METHOD;
- (void)writeValue:(NSData*)data forDescriptor:(CBDescriptor*)descriptor STUB_METHOD;
- (void)setNotifyValue:(BOOL)enabled forCharacteristic:(CBCharacteristic*)characteristic STUB_METHOD;
@property (readonly) BOOL isConnected STUB_PROPERTY;
@property (readonly) CBPeripheralState state STUB_PROPERTY;
- (void)readRSSI STUB_METHOD;
@property (readonly, retain) NSNumber* RSSI STUB_PROPERTY;
@end
