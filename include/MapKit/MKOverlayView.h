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
#import <Foundation/NSObject.h>
#import <UIKit/UIView.h>
#import <MapKit/MapKitDataTypes.h>

@protocol MKOverlay;

MAPKIT_EXPORT_CLASS
@interface MKOverlayView
    : UIView <NSCoding, UIAppearance, UIAppearanceContainer, UICoordinateSpace, UIDynamicItem, UIFocusEnvironment, UITraitEnvironment>
- (instancetype)initWithOverlay:(id<MKOverlay>)overlay STUB_METHOD;
@property (readonly, nonatomic) id<MKOverlay> overlay STUB_PROPERTY;
- (CGPoint)pointForMapPoint:(MKMapPoint)mapPoint STUB_METHOD;
- (MKMapPoint)mapPointForPoint:(CGPoint)point STUB_METHOD;
- (CGRect)rectForMapRect:(MKMapRect)mapRect STUB_METHOD;
- (MKMapRect)mapRectForRect:(CGRect)rect STUB_METHOD;
- (BOOL)canDrawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale STUB_METHOD;
- (void)drawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale inContext:(CGContextRef)context STUB_METHOD;
- (void)setNeedsDisplayInMapRect:(MKMapRect)mapRect STUB_METHOD;
- (void)setNeedsDisplayInMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale STUB_METHOD;
@end
