//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <MapKit/MapKitExport.h>
#import <CoreGraphics/CGBase.h>
#import <CoreLocation/CLLocation.h>

MAPKIT_EXPORT_CLASS
@interface MKMapCamera : NSObject <NSSecureCoding, NSCopying>
+ (instancetype)camera STUB_METHOD;
+ (instancetype)cameraLookingAtCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                              fromEyeCoordinate:(CLLocationCoordinate2D)eyeCoordinate
                                    eyeAltitude:(CLLocationDistance)eyeAltitude STUB_METHOD;
+ (instancetype)cameraLookingAtCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                                   fromDistance:(CLLocationDistance)distance
                                          pitch:(CGFloat)pitch
                                        heading:(CLLocationDirection)heading STUB_METHOD;
@property (nonatomic) CLLocationCoordinate2D centerCoordinate STUB_PROPERTY;
@property (nonatomic) CLLocationDirection heading STUB_PROPERTY;
@property (nonatomic) CGFloat pitch STUB_PROPERTY;
@property (nonatomic) CLLocationDistance altitude STUB_PROPERTY;
@end
