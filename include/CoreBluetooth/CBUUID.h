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

#import <CoreFoundation/CFUUID.h>

#import <Foundation/NSObject.h>

@class NSString;
@class NSData;
@class NSUUID;

COREBLUETOOTH_EXPORT NSString* const CBUUIDCharacteristicExtendedPropertiesString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDCharacteristicUserDescriptionString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDClientCharacteristicConfigurationString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDServerCharacteristicConfigurationString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDCharacteristicFormatString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDCharacteristicAggregateFormatString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDGenericAccessProfileString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDGenericAttributeProfileString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDDeviceNameString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDAppearanceString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDPeripheralPrivacyFlagString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDReconnectionAddressString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDPeripheralPreferredConnectionParametersString;
COREBLUETOOTH_EXPORT NSString* const CBUUIDServiceChangedString;

COREBLUETOOTH_EXPORT_CLASS
@interface CBUUID : NSObject <NSCopying, NSObject>
+ (CBUUID*)UUIDWithString:(NSString*)theString STUB_METHOD;
+ (CBUUID*)UUIDWithData:(NSData*)theData STUB_METHOD;
+ (CBUUID*)UUIDWithCFUUID:(CFUUIDRef)theUUID STUB_METHOD;
+ (CBUUID*)UUIDWithNSUUID:(NSUUID*)theUUID STUB_METHOD;
@property (readonly, nonatomic) NSData* data STUB_PROPERTY;
@property (readonly, nonatomic) NSString* UUIDString STUB_PROPERTY;
@end
