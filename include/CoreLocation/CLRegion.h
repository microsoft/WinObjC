//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocationExport.h>
#import <CoreLocation/CLLocation.h>

enum _CLRegionState {
    kCLRegionStateUnknown = 0,
    kCLRegionStateInside = 1,
    kCLRegionStateOutside = 2,
};
typedef uint32_t CLRegionState;

CORELOCATION_EXPORT_CLASS
@interface CLRegion : NSObject <NSCopying, NSCoding>

// TODO::
// todo-nithishm-11022015 - Incomplete file.

@property (readonly, nonatomic) NSString* identifier;
@property (readonly, nonatomic) CLLocationCoordinate2D center;
@property (readonly, nonatomic) CLLocationDistance radius;
@property (nonatomic, assign) BOOL notifyOnEntry;
@property (nonatomic, assign) BOOL notifyOnExit;

- (id)initCircularRegionWithCenter:(CLLocationCoordinate2D)center radius:(CLLocationDistance)radius identifier:(NSString*)identifier;

@end