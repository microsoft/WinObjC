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

#import <CoreLocation/CoreLocationExport.h>
#import <Foundation/NSObject.h>
#import <CoreLocation/CLRegion.h>

@class NSUUID;
@class NSNumber;
@class NSMutableDictionary;

typedef uint16_t CLBeaconMajorValue;
typedef uint16_t CLBeaconMinorValue;

CORELOCATION_EXPORT_CLASS
@interface CLBeaconRegion : CLRegion <NSCopying, NSSecureCoding>
- (instancetype)initWithProximityUUID:(NSUUID*)proximityUUID identifier:(NSString*)identifier STUB_METHOD;
- (instancetype)initWithProximityUUID:(NSUUID*)proximityUUID major:(CLBeaconMajorValue)major identifier:(NSString*)identifier STUB_METHOD;
- (instancetype)initWithProximityUUID:(NSUUID*)proximityUUID
                                major:(CLBeaconMajorValue)major
                                minor:(CLBeaconMinorValue)minor
                           identifier:(NSString*)identifier STUB_METHOD;
@property (readonly, nonatomic, strong) NSUUID* proximityUUID STUB_PROPERTY;
@property (readonly, nonatomic, strong) NSNumber* major STUB_PROPERTY;
@property (readonly, nonatomic, strong) NSNumber* minor STUB_PROPERTY;
@property (assign, nonatomic) BOOL notifyEntryStateOnDisplay STUB_PROPERTY;
- (NSMutableDictionary*)peripheralDataWithMeasuredPower:(NSNumber*)measuredPower STUB_METHOD;
@end
