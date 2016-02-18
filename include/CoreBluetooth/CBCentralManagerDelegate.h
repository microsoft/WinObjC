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

@class NSString;
@class CBCentralManager;
@class CBPeripheral;
@class NSError;
@class NSDictionary;
@class NSNumber;
@class NSArray;

COREBLUETOOTH_EXPORT NSString* const CBCentralManagerRestoredStatePeripheralsKey;
COREBLUETOOTH_EXPORT NSString* const CBCentralManagerRestoredStateScanServicesKey;
COREBLUETOOTH_EXPORT NSString* const CBCentralManagerRestoredStateScanOptionsKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataLocalNameKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataManufacturerDataKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataServiceDataKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataServiceUUIDsKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataOverflowServiceUUIDsKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataTxPowerLevelKey;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataIsConnectable;
COREBLUETOOTH_EXPORT NSString* const CBAdvertisementDataSolicitedServiceUUIDsKey;

@protocol CBCentralManagerDelegate <NSObject>
@required
- (void)centralManagerDidUpdateState:(CBCentralManager*)central;
@optional
- (void)centralManager:(CBCentralManager*)central didConnectPeripheral:(CBPeripheral*)peripheral;
- (void)centralManager:(CBCentralManager*)central didDisconnectPeripheral:(CBPeripheral*)peripheral error:(NSError*)error;
- (void)centralManager:(CBCentralManager*)central didFailToConnectPeripheral:(CBPeripheral*)peripheral error:(NSError*)error;
- (void)centralManager:(CBCentralManager*)central
 didDiscoverPeripheral:(CBPeripheral*)peripheral
     advertisementData:(NSDictionary*)advertisementData
                  RSSI:(NSNumber*)RSSI;
- (void)centralManager:(CBCentralManager*)central didRetrieveConnectedPeripherals:(NSArray*)peripherals;
- (void)centralManager:(CBCentralManager*)central didRetrievePeripherals:(NSArray*)peripherals;
- (void)centralManager:(CBCentralManager*)central willRestoreState:(NSDictionary*)dict;
@end
