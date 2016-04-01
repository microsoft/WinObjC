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

#import <CoreBluetooth/CBCentralManager.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const CBCentralManagerOptionShowPowerAlertKey = @"CBCentralManagerOptionShowPowerAlertKey";
NSString* const CBCentralManagerOptionRestoreIdentifierKey = @"CBCentralManagerOptionRestoreIdentifierKey";
NSString* const CBCentralManagerScanOptionAllowDuplicatesKey = @"CBCentralManagerScanOptionAllowDuplicatesKey";
NSString* const CBCentralManagerScanOptionSolicitedServiceUUIDsKey = @"CBCentralManagerScanOptionSolicitedServiceUUIDsKey";
NSString* const CBConnectPeripheralOptionNotifyOnConnectionKey = @"CBConnectPeripheralOptionNotifyOnConnectionKey";
NSString* const CBConnectPeripheralOptionNotifyOnDisconnectionKey = @"CBConnectPeripheralOptionNotifyOnDisconnectionKey";
NSString* const CBConnectPeripheralOptionNotifyOnNotificationKey = @"CBConnectPeripheralOptionNotifyOnNotificationKey";

@implementation CBCentralManager
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithDelegate:(id<CBCentralManagerDelegate>)delegate queue:(dispatch_queue_t)queue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithDelegate:(id<CBCentralManagerDelegate>)delegate queue:(dispatch_queue_t)queue options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)connectPeripheral:(CBPeripheral*)peripheral options:(NSDictionary*)options {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelPeripheralConnection:(CBPeripheral*)peripheral {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)retrieveConnectedPeripherals {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)retrieveConnectedPeripheralsWithServices:(NSArray*)serviceUUIDs {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)retrievePeripherals:(NSArray*)peripheralUUIDs {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)retrievePeripheralsWithIdentifiers:(NSArray*)identifiers {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)scanForPeripheralsWithServices:(NSArray*)serviceUUIDs options:(NSDictionary*)options {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopScan {
    UNIMPLEMENTED();
}

@end
