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
#pragma once

#import <CoreBluetooth/CoreBluetoothExport.h>
#import <CoreBluetooth/CBCharacteristic.h>
#import <Foundation/NSObject.h>

@class CBUUID;
@class NSData;
@class NSArray;

typedef enum {
    CBAttributePermissionsReadable = 0x01,
    CBAttributePermissionsWriteable = 0x02,
    CBAttributePermissionsReadEncryptionRequired = 0x04,
    CBAttributePermissionsWriteEncryptionRequired = 0x08,
} CBAttributePermissions;

COREBLUETOOTH_EXPORT_CLASS
@interface CBMutableCharacteristic : NSObject <NSObject>
- (id)initWithType:(CBUUID*)UUID
        properties:(CBCharacteristicProperties)properties
             value:(NSData*)value
       permissions:(CBAttributePermissions)permissions STUB_METHOD;
@property (assign, readwrite, nonatomic) CBUUID* UUID STUB_PROPERTY;
@property (readwrite, retain) NSData* value STUB_PROPERTY;
@property (readwrite, retain) NSArray* descriptors STUB_PROPERTY;
@property (assign, readwrite, nonatomic) CBCharacteristicProperties properties STUB_PROPERTY;
@property (assign, readwrite, nonatomic) CBAttributePermissions permissions STUB_PROPERTY;
@property (readonly, retain) NSArray* subscribedCentrals STUB_PROPERTY;
@end
