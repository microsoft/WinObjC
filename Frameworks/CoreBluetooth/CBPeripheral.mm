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

#import <CoreBluetooth/CBPeripheral.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

@implementation CBPeripheral
/**
 @Status Stub
 @Notes
*/
- (void)discoverServices:(NSArray*)serviceUUIDs {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverIncludedServices:(NSArray*)includedServiceUUIDs forService:(CBService*)service {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverCharacteristics:(NSArray*)characteristicUUIDs forService:(CBService*)service {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)discoverDescriptorsForCharacteristic:(CBCharacteristic*)characteristic {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readValueForCharacteristic:(CBCharacteristic*)characteristic {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readValueForDescriptor:(CBDescriptor*)descriptor {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeValue:(NSData*)data forCharacteristic:(CBCharacteristic*)characteristic type:(CBCharacteristicWriteType)type {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)writeValue:(NSData*)data forDescriptor:(CBDescriptor*)descriptor {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setNotifyValue:(BOOL)enabled forCharacteristic:(CBCharacteristic*)characteristic {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)readRSSI {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
