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

#import <CoreBluetooth/CBPeripheralManager.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const CBPeripheralManagerOptionShowPowerAlertKey = @"CBPeripheralManagerOptionShowPowerAlertKey";
NSString* const CBPeripheralManagerOptionRestoreIdentifierKey = @"CBPeripheralManagerOptionRestoreIdentifierKey";

@implementation CBPeripheralManager
/**
 @Status Stub
 @Notes
*/
- (id)initWithDelegate:(id<CBPeripheralManagerDelegate>)delegate queue:(dispatch_queue_t)queue {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithDelegate:(id<CBPeripheralManagerDelegate>)delegate queue:(dispatch_queue_t)queue options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CBPeripheralAuthorizationStatus)authorizationStatus {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addService:(CBMutableService*)service {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeService:(CBMutableService*)service {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAllServices {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startAdvertising:(NSDictionary*)advertisementData {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopAdvertising {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)updateValue:(NSData*)value forCharacteristic:(CBMutableCharacteristic*)characteristic onSubscribedCentrals:(NSArray*)centrals {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)respondToRequest:(CBATTRequest*)request withResult:(CBATTError)result {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDesiredConnectionLatency:(CBPeripheralManagerConnectionLatency)latency forCentral:(CBCentral*)central {
    UNIMPLEMENTED();
}

@end
