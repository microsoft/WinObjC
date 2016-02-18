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

#import <Foundation/NSObject.h>

#include <dispatch/dispatch.h>

@class NSString;
@protocol CBCentralManagerDelegate;
@class NSDictionary;
@class CBPeripheral;
@class NSArray;

typedef enum {
    CBCentralManagerStateUnknown = 0,
    CBCentralManagerStateResetting,
    CBCentralManagerStateUnsupported,
    CBCentralManagerStateUnauthorized,
    CBCentralManagerStatePoweredOff,
    CBCentralManagerStatePoweredOn,
} CBCentralManagerState;

COREBLUETOOTH_EXPORT NSString* const CBCentralManagerOptionShowPowerAlertKey;
COREBLUETOOTH_EXPORT NSString* const CBCentralManagerOptionRestoreIdentifierKey;
COREBLUETOOTH_EXPORT NSString* const CBCentralManagerScanOptionAllowDuplicatesKey;
COREBLUETOOTH_EXPORT NSString* const CBCentralManagerScanOptionSolicitedServiceUUIDsKey;
COREBLUETOOTH_EXPORT NSString* const CBConnectPeripheralOptionNotifyOnConnectionKey;
COREBLUETOOTH_EXPORT NSString* const CBConnectPeripheralOptionNotifyOnDisconnectionKey;
COREBLUETOOTH_EXPORT NSString* const CBConnectPeripheralOptionNotifyOnNotificationKey;

COREBLUETOOTH_EXPORT_CLASS
@interface CBCentralManager : NSObject
- (instancetype)initWithDelegate:(id<CBCentralManagerDelegate>)delegate queue:(dispatch_queue_t)queue STUB_METHOD;
- (instancetype)initWithDelegate:(id<CBCentralManagerDelegate>)delegate
                           queue:(dispatch_queue_t)queue
                         options:(NSDictionary*)options STUB_METHOD;
- (void)connectPeripheral:(CBPeripheral*)peripheral options:(NSDictionary*)options STUB_METHOD;
- (void)cancelPeripheralConnection:(CBPeripheral*)peripheral STUB_METHOD;
- (void)retrieveConnectedPeripherals STUB_METHOD;
- (NSArray*)retrieveConnectedPeripheralsWithServices:(NSArray*)serviceUUIDs STUB_METHOD;
- (void)retrievePeripherals:(NSArray*)peripheralUUIDs STUB_METHOD;
- (NSArray*)retrievePeripheralsWithIdentifiers:(NSArray*)identifiers STUB_METHOD;
- (void)scanForPeripheralsWithServices:(NSArray*)serviceUUIDs options:(NSDictionary*)options STUB_METHOD;
- (void)stopScan STUB_METHOD;
@property (readonly) CBCentralManagerState state STUB_PROPERTY;
@property (assign, nonatomic) id<CBCentralManagerDelegate> delegate STUB_PROPERTY;
@end
