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

#import <MapKit/MapKitExport.h>
#import <UIKit/UIAppearance.h>
#import <MapKit/MKAnnotationView.h>

@class UIColor;

typedef enum MKPinAnnotationColor : NSUInteger {
    MKPinAnnotationColorRed = 0,
    MKPinAnnotationColorGreen,
    MKPinAnnotationColorPurple
} MKPinAnnotationColor;

MAPKIT_EXPORT_CLASS
@interface MKPinAnnotationView : MKAnnotationView <NSCoding,
                                                   UIAppearance,
                                                   UIAppearanceContainer,
                                                   UICoordinateSpace,
                                                   UIDynamicItem,
                                                   UIFocusEnvironment,
                                                   UITraitEnvironment>
@property (nonatomic, strong) UIColor* pinTintColor STUB_PROPERTY;
@property (nonatomic) BOOL animatesDrop STUB_PROPERTY;
@property (nonatomic) MKPinAnnotationColor pinColor STUB_PROPERTY;
+ (UIColor*)redPinColor STUB_METHOD;
+ (UIColor*)greenPinColor STUB_METHOD;
+ (UIColor*)purplePinColor STUB_METHOD;
@end
