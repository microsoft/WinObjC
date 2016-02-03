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

#import <HealthKit/HealthKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;

HEALTHKIT_EXPORT_CLASS
@interface HKDevice : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithName:(NSString*)name
                manufacturer:(NSString*)manufacturer
                       model:(NSString*)model
             hardwareVersion:(NSString*)hardwareVersion
             firmwareVersion:(NSString*)firmwareVersion
             softwareVersion:(NSString*)softwareVersion
             localIdentifier:(NSString*)localIdentifier
         UDIDeviceIdentifier:(NSString*)UDIDeviceIdentifier STUB_METHOD;
+ (HKDevice*)localDevice STUB_METHOD;
@property (readonly) NSString* UDIDeviceIdentifier STUB_PROPERTY;
@property (readonly) NSString* firmwareVersion STUB_PROPERTY;
@property (readonly) NSString* hardwareVersion STUB_PROPERTY;
@property (readonly) NSString* localIdentifier STUB_PROPERTY;
@property (readonly) NSString* manufacturer STUB_PROPERTY;
@property (readonly) NSString* model STUB_PROPERTY;
@property (readonly) NSString* name STUB_PROPERTY;
@property (readonly) NSString* softwareVersion STUB_PROPERTY;
@end
