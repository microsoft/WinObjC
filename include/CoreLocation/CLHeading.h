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
#import <CoreLocation/CoreLocationDataTypes.h>

@class NSDate;

typedef double CLHeadingComponentValue;

CORELOCATION_EXPORT_CLASS
@interface CLHeading : NSObject <NSCopying, NSSecureCoding>
@property (readonly, nonatomic) CLLocationDirection magneticHeading STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationDirection trueHeading STUB_PROPERTY;
@property (readonly, nonatomic) CLLocationDirection headingAccuracy STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDate* timestamp STUB_PROPERTY;
@property (readonly, nonatomic) CLHeadingComponentValue x STUB_PROPERTY;
@property (readonly, nonatomic) CLHeadingComponentValue y STUB_PROPERTY;
@property (readonly, nonatomic) CLHeadingComponentValue z STUB_PROPERTY;
@end
