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
#import <MapKit/MKOverlayView.h>
#import <MapKit/MapKitDataTypes.h>

@class UIColor;
@class NSArray;

MAPKIT_EXPORT_CLASS
@interface MKOverlayPathView : MKOverlayView <NSCoding,
                                              UIAppearance,
                                              UIAppearanceContainer,
                                              UICoordinateSpace,
                                              UIDynamicItem,
                                              UIFocusEnvironment,
                                              UITraitEnvironment>
@property (strong) UIColor* fillColor STUB_PROPERTY;
@property (strong) UIColor* strokeColor STUB_PROPERTY;
@property CGFloat lineWidth STUB_PROPERTY;
@property CGLineJoin lineJoin STUB_PROPERTY;
@property CGLineCap lineCap STUB_PROPERTY;
@property CGFloat miterLimit STUB_PROPERTY;
@property CGFloat lineDashPhase STUB_PROPERTY;
@property (copy) NSArray* lineDashPattern STUB_PROPERTY;
@property CGPathRef path STUB_PROPERTY;
- (void)createPath STUB_METHOD;
- (void)invalidatePath STUB_METHOD;
- (void)applyStrokePropertiesToContext:(CGContextRef)context atZoomScale:(MKZoomScale)zoomScale STUB_METHOD;
- (void)applyFillPropertiesToContext:(CGContextRef)context atZoomScale:(MKZoomScale)zoomScale STUB_METHOD;
- (void)strokePath:(CGPathRef)path inContext:(CGContextRef)context STUB_METHOD;
- (void)fillPath:(CGPathRef)path inContext:(CGContextRef)context STUB_METHOD;
@end
