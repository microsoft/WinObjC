//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreLocation/CoreLocationDataTypes.h>

typedef NS_ENUM(NSUInteger, CLRegionState) { CLRegionStateUnknown, CLRegionStateInside, CLRegionStateOutside };

CORELOCATION_EXPORT_CLASS
@interface CLRegion : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initCircularRegionWithCenter:(CLLocationCoordinate2D)center
                                      radius:(CLLocationDistance)radius
                                  identifier:(NSString*)identifier;
@property (readonly, copy, nonatomic) NSString* identifier;
@property (readonly, nonatomic) CLLocationCoordinate2D center;
@property (readonly, nonatomic) CLLocationDistance radius;
@property (assign, nonatomic) BOOL notifyOnEntry STUB_PROPERTY;
@property (assign, nonatomic) BOOL notifyOnExit STUB_PROPERTY;
- (BOOL)containsCoordinate:(CLLocationCoordinate2D)coordinate STUB_METHOD;
@end
