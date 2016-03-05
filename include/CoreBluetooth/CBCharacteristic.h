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
#import <CoreBluetooth/CBAttribute.h>

@class CBUUID;
@class CBService;
@class NSData;
@class NSArray;

typedef enum {
    CBCharacteristicPropertyBroadcast = 0x01,
    CBCharacteristicPropertyRead = 0x02,
    CBCharacteristicPropertyWriteWithoutResponse = 0x04,
    CBCharacteristicPropertyWrite = 0x08,
    CBCharacteristicPropertyNotify = 0x10,
    CBCharacteristicPropertyIndicate = 0x20,
    CBCharacteristicPropertyAuthenticatedSignedWrites = 0x40,
    CBCharacteristicPropertyExtendedProperties = 0x80,
    CBCharacteristicPropertyNotifyEncryptionRequired = 0x100,
    CBCharacteristicPropertyIndicateEncryptionRequired = 0x200,
} CBCharacteristicProperties;

COREBLUETOOTH_EXPORT_CLASS
@interface CBCharacteristic : CBAttribute
@property (readonly, nonatomic) CBUUID* UUID STUB_PROPERTY;
@property (readonly, assign, nonatomic) CBService* service STUB_PROPERTY;
@property (readonly, retain) NSData* value STUB_PROPERTY;
@property (readonly, retain) NSArray* descriptors STUB_PROPERTY;
@property (readonly, nonatomic) CBCharacteristicProperties properties STUB_PROPERTY;
@property (readonly) BOOL isNotifying STUB_PROPERTY;
@property (readonly) BOOL isBroadcasted STUB_PROPERTY;
@end
