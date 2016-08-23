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
#import <CoreBluetooth/CBConstants.h>
#import <Foundation/NSObject.h>
#import <dispatch/dispatch.h>
#import <objc/runtime.h>

@class NSString;
@protocol CBPeripheralManagerDelegate;
@class NSDictionary;
@class CBMutableService;
@class NSData;
@class CBMutableCharacteristic;
@class NSArray;
@class CBATTRequest;
@class CBCentral;

typedef enum {
    CBPeripheralManagerStateUnknown = 0,
    CBPeripheralManagerStateResetting,
    CBPeripheralManagerStateUnsupported,
    CBPeripheralManagerStateUnauthorized,
    CBPeripheralManagerStatePoweredOff,
    CBPeripheralManagerStatePoweredOn,
} CBPeripheralManagerState;
typedef enum {
    CBPeripheralManagerConnectionLatencyLow = 0,
    CBPeripheralManagerConnectionLatencyMedium,
    CBPeripheralManagerConnectionLatencyHigh,
} CBPeripheralManagerConnectionLatency;
typedef enum {
    CBPeripheralManagerAuthorizationStatusNotDetermined = 0,
    CBPeripheralManagerAuthorizationStatusRestricted,
    CBPeripheralManagerAuthorizationStatusDenied,
    CBPeripheralManagerAuthorizationStatusAuthorized,
} CBPeripheralManagerAuthorizationStatus;
typedef CBPeripheralManagerAuthorizationStatus CBPeripheralAuthorizationStatus;

COREBLUETOOTH_EXPORT NSString* const CBPeripheralManagerOptionShowPowerAlertKey;
COREBLUETOOTH_EXPORT NSString* const CBPeripheralManagerOptionRestoreIdentifierKey;
COREBLUETOOTH_EXPORT_CLASS

@interface CBPeripheralManager : NSObject <NSObject>
- (id)initWithDelegate:(id<CBPeripheralManagerDelegate>)delegate queue:(dispatch_queue_t)queue STUB_METHOD;
- (id)initWithDelegate:(id<CBPeripheralManagerDelegate>)delegate queue:(dispatch_queue_t)queue options:(NSDictionary*)options STUB_METHOD;
@property (nonatomic, weak) id<CBPeripheralManagerDelegate> delegate STUB_PROPERTY;
@property (readonly) CBPeripheralManagerState state STUB_PROPERTY;
+ (CBPeripheralAuthorizationStatus)authorizationStatus STUB_METHOD;
- (void)addService:(CBMutableService*)service STUB_METHOD;
- (void)removeService:(CBMutableService*)service STUB_METHOD;
- (void)removeAllServices STUB_METHOD;
- (void)startAdvertising:(NSDictionary*)advertisementData STUB_METHOD;
- (void)stopAdvertising STUB_METHOD;
@property (readonly) BOOL isAdvertising STUB_PROPERTY;
- (BOOL)updateValue:(NSData*)value
       forCharacteristic:(CBMutableCharacteristic*)characteristic
    onSubscribedCentrals:(NSArray*)centrals STUB_METHOD;
- (void)respondToRequest:(CBATTRequest*)request withResult:(CBATTError)result STUB_METHOD;
- (void)setDesiredConnectionLatency:(CBPeripheralManagerConnectionLatency)latency forCentral:(CBCentral*)central STUB_METHOD;
@end
