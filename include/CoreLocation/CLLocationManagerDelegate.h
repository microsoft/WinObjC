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
#import <CoreLocation/CLLocationManager.h>

CORELOCATION_EXPORT_CLASS
@protocol CLLocationManagerDelegate <NSObject>

// note-nithishm-11022015 - The actual type for the locations argument is didUpdateLocations:(NSArray<NSLocation*>*)locations.
// Because the compiler does not support this syntax making it a simple NSArray* type.
- (void)locationManager:(CLLocationManager*)manager didUpdateLocations:(NSArray*)locations;
- (void)locationManager:(CLLocationManager*)manager didFailWithError:(NSError*)error;
- (void)locationManager:(CLLocationManager*)manager didFinishDeferredUpdatesWithError:(NSError*)error;

- (void)locationManagerDidPauseLocationUpdates:(CLLocationManager*)manager;
- (void)locationManagerDidResumeLocationUpdates:(CLLocationManager*)manager;

- (void)locationManager:(CLLocationManager*)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status;

// TODO::
// todo-nithishm-11022015 - Need to support other delegates in future.

@end