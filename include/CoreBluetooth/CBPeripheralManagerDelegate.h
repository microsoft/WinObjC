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

@class NSString;
@class CBPeripheralManager;
@class NSDictionary;
@class CBService;
@class NSError;
@class CBCentral;
@class CBCharacteristic;
@class CBATTRequest;
@class NSArray;

COREBLUETOOTH_EXPORT NSString* const CBPeripheralManagerRestoredStateServicesKey;
COREBLUETOOTH_EXPORT NSString* const CBPeripheralManagerRestoredStateAdvertisementDataKey;

@protocol CBPeripheralManagerDelegate
@optional
- (void)peripheralManagerDidUpdateState:(CBPeripheralManager*)peripheral;
- (void)peripheralManager:(CBPeripheralManager*)peripheral willRestoreState:(NSDictionary*)dict;
- (void)peripheralManager:(CBPeripheralManager*)peripheral didAddService:(CBService*)service error:(NSError*)error;
- (void)peripheralManagerDidStartAdvertising:(CBPeripheralManager*)peripheral error:(NSError*)error;
- (void)peripheralManager:(CBPeripheralManager*)peripheral
                         central:(CBCentral*)central
    didSubscribeToCharacteristic:(CBCharacteristic*)characteristic;
- (void)peripheralManager:(CBPeripheralManager*)peripheral
                             central:(CBCentral*)central
    didUnsubscribeFromCharacteristic:(CBCharacteristic*)characteristic;
- (void)peripheralManagerIsReadyToUpdateSubscribers:(CBPeripheralManager*)peripheral;
- (void)peripheralManager:(CBPeripheralManager*)peripheral didReceiveReadRequest:(CBATTRequest*)request;
- (void)peripheralManager:(CBPeripheralManager*)peripheral didReceiveWriteRequests:(NSArray*)requests;
@end
