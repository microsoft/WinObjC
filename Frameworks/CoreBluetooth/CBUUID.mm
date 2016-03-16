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

#import <CoreBluetooth/CBUUID.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const CBUUIDCharacteristicExtendedPropertiesString = @"CBUUIDCharacteristicExtendedPropertiesString";
NSString* const CBUUIDCharacteristicUserDescriptionString = @"CBUUIDCharacteristicUserDescriptionString";
NSString* const CBUUIDClientCharacteristicConfigurationString = @"CBUUIDClientCharacteristicConfigurationString";
NSString* const CBUUIDServerCharacteristicConfigurationString = @"CBUUIDServerCharacteristicConfigurationString";
NSString* const CBUUIDCharacteristicFormatString = @"CBUUIDCharacteristicFormatString";
NSString* const CBUUIDCharacteristicAggregateFormatString = @"CBUUIDCharacteristicAggregateFormatString";
NSString* const CBUUIDGenericAccessProfileString = @"CBUUIDGenericAccessProfileString";
NSString* const CBUUIDGenericAttributeProfileString = @"CBUUIDGenericAttributeProfileString";
NSString* const CBUUIDDeviceNameString = @"CBUUIDDeviceNameString";
NSString* const CBUUIDAppearanceString = @"CBUUIDAppearanceString";
NSString* const CBUUIDPeripheralPrivacyFlagString = @"CBUUIDPeripheralPrivacyFlagString";
NSString* const CBUUIDReconnectionAddressString = @"CBUUIDReconnectionAddressString";
NSString* const CBUUIDPeripheralPreferredConnectionParametersString = @"CBUUIDPeripheralPreferredConnectionParametersString";
NSString* const CBUUIDServiceChangedString = @"CBUUIDServiceChangedString";

@implementation CBUUID
/**
 @Status Stub
 @Notes
*/
+ (CBUUID*)UUIDWithString:(NSString*)theString {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CBUUID*)UUIDWithData:(NSData*)theData {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CBUUID*)UUIDWithCFUUID:(CFUUIDRef)theUUID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CBUUID*)UUIDWithNSUUID:(NSUUID*)theUUID {
    UNIMPLEMENTED();
    return StubReturn();
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
