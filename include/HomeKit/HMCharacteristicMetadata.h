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

#import <HomeKit/HomeKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSNumber;

HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataUnitsCelsius;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataUnitsFahrenheit;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataUnitsPercentage;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataUnitsArcDegree;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatBool;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatInt;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatFloat;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatString;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatArray;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatDictionary;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatUInt8;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatUInt16;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatUInt32;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatUInt64;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatData;
HOMEKIT_EXPORT NSString* const HMCharacteristicMetadataFormatTLV8;

HOMEKIT_EXPORT_CLASS
@interface HMCharacteristicMetadata : NSObject
@property (readonly, nonatomic) NSNumber* minimumValue STUB_PROPERTY;
@property (readonly, nonatomic) NSNumber* maximumValue STUB_PROPERTY;
@property (readonly, nonatomic) NSNumber* stepValue STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* format STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* units STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* manufacturerDescription STUB_PROPERTY;
@property (readonly, nonatomic) NSNumber* maxLength STUB_PROPERTY;
@end
