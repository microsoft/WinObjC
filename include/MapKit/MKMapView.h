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
#import <UIKit/UIView.h>
#import <MapKit/MapKitDataTypes.h>

@protocol MKMapViewDelegate;
@class NSArray;
@class MKMapCamera;
@class MKUserLocation;
@protocol MKAnnotation;
@class MKAnnotationView;
@class NSSet;
@class NSString;
@class MKOverlayRenderer;
@protocol MKOverlay;
@class MKOverlayView;

typedef enum : NSUInteger {
    MKMapTypeStandard,
    MKMapTypeSatellite,
    MKMapTypeHybrid,
    MKMapTypeSatelliteFlyover,
    MKMapTypeHybridFlyover,
} MKMapType;

typedef enum : NSInteger {
    MKUserTrackingModeNone = 0,
    MKUserTrackingModeFollow,
    MKUserTrackingModeFollowWithHeading,
} MKUserTrackingMode;

typedef enum : NSInteger { MKOverlayLevelAboveRoads = 0, MKOverlayLevelAboveLabels } MKOverlayLevel;

MAPKIT_EXPORT_CLASS
@interface MKMapView
    : UIView <NSCoding, UIAppearance, UIAppearanceContainer, UICoordinateSpace, UIDynamicItem, UIFocusEnvironment, UITraitEnvironment>
@property (nonatomic) MKMapType mapType STUB_PROPERTY;
@property (getter=isZoomEnabled, nonatomic) BOOL zoomEnabled STUB_PROPERTY;
@property (getter=isScrollEnabled, nonatomic) BOOL scrollEnabled STUB_PROPERTY;
@property (getter=isPitchEnabled, nonatomic) BOOL pitchEnabled STUB_PROPERTY;
@property (getter=isRotateEnabled, nonatomic) BOOL rotateEnabled STUB_PROPERTY;
@property (nonatomic) id<MKMapViewDelegate> delegate STUB_PROPERTY; // TODO: property should be weak
@property (nonatomic) MKCoordinateRegion region STUB_PROPERTY;
- (void)setRegion:(MKCoordinateRegion)region animated:(BOOL)animated STUB_METHOD;
@property (nonatomic) CLLocationCoordinate2D centerCoordinate STUB_PROPERTY;
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated STUB_METHOD;
- (void)showAnnotations:(NSArray*)annotations animated:(BOOL)animated STUB_METHOD;
@property (nonatomic) MKMapRect visibleMapRect STUB_PROPERTY;
- (void)setVisibleMapRect:(MKMapRect)mapRect animated:(BOOL)animate STUB_METHOD;
- (void)setVisibleMapRect:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animate STUB_METHOD;
@property (copy, nonatomic) MKMapCamera* camera STUB_PROPERTY;
- (void)setCamera:(MKMapCamera*)camera animated:(BOOL)animated STUB_METHOD;
@property (nonatomic) BOOL showsPointsOfInterest STUB_PROPERTY;
@property (nonatomic) BOOL showsBuildings STUB_PROPERTY;
@property (nonatomic) BOOL showsCompass STUB_PROPERTY;
@property (nonatomic) BOOL showsScale STUB_PROPERTY;
@property (nonatomic) BOOL showsTraffic STUB_PROPERTY;
@property (nonatomic) BOOL showsUserLocation STUB_PROPERTY;
@property (readonly, getter=isUserLocationVisible, nonatomic) BOOL userLocationVisible STUB_PROPERTY;
@property (readonly, nonatomic) MKUserLocation* userLocation STUB_PROPERTY;
@property (nonatomic) MKUserTrackingMode userTrackingMode STUB_PROPERTY;
- (void)setUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated STUB_METHOD;
@property (readonly, nonatomic) NSArray* annotations STUB_PROPERTY;
- (void)addAnnotation:(id<MKAnnotation>)annotation STUB_METHOD;
- (void)addAnnotations:(NSArray*)annotations STUB_METHOD;
- (void)removeAnnotation:(id<MKAnnotation>)annotation STUB_METHOD;
- (void)removeAnnotations:(NSArray*)annotations STUB_METHOD;
- (MKAnnotationView*)viewForAnnotation:(id<MKAnnotation>)annotation STUB_METHOD;
- (NSSet*)annotationsInMapRect:(MKMapRect)mapRect STUB_METHOD;
@property (readonly, nonatomic) CGRect annotationVisibleRect STUB_PROPERTY;
- (MKAnnotationView*)dequeueReusableAnnotationViewWithIdentifier:(NSString*)identifier STUB_METHOD;
@property (copy, nonatomic) NSArray* selectedAnnotations STUB_PROPERTY;
- (void)selectAnnotation:(id<MKAnnotation>)annotation animated:(BOOL)animated STUB_METHOD;
- (void)deselectAnnotation:(id<MKAnnotation>)annotation animated:(BOOL)animated STUB_METHOD;
@property (readonly, nonatomic) NSArray* overlays STUB_PROPERTY;
- (NSArray*)overlaysInLevel:(MKOverlayLevel)level STUB_METHOD;
- (MKOverlayRenderer*)rendererForOverlay:(id<MKOverlay>)overlay STUB_METHOD;
- (MKOverlayView*)viewForOverlay:(id<MKOverlay>)overlay STUB_METHOD;
- (void)addOverlay:(id<MKOverlay>)overlay level:(MKOverlayLevel)level STUB_METHOD;
- (void)addOverlays:(NSArray*)overlays level:(MKOverlayLevel)level STUB_METHOD;
- (void)addOverlay:(id<MKOverlay>)overlay STUB_METHOD;
- (void)addOverlays:(NSArray*)overlays STUB_METHOD;
- (void)insertOverlay:(id<MKOverlay>)overlay atIndex:(NSUInteger)index level:(MKOverlayLevel)level STUB_METHOD;
- (void)insertOverlay:(id<MKOverlay>)overlay atIndex:(NSUInteger)index STUB_METHOD;
- (void)insertOverlay:(id<MKOverlay>)overlay aboveOverlay:(id<MKOverlay>)sibling STUB_METHOD;
- (void)insertOverlay:(id<MKOverlay>)overlay belowOverlay:(id<MKOverlay>)sibling STUB_METHOD;
- (void)exchangeOverlay:(id<MKOverlay>)overlay1 withOverlay:(id<MKOverlay>)overlay2 STUB_METHOD;
- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2 STUB_METHOD;
- (void)removeOverlay:(id<MKOverlay>)overlay STUB_METHOD;
- (void)removeOverlays:(NSArray*)overlays STUB_METHOD;
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView*)view STUB_METHOD;
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView*)view STUB_METHOD;
- (CGRect)convertRegion:(MKCoordinateRegion)region toRectToView:(UIView*)view STUB_METHOD;
- (MKCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView*)view STUB_METHOD;
- (MKCoordinateRegion)regionThatFits:(MKCoordinateRegion)region STUB_METHOD;
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect STUB_METHOD;
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets STUB_METHOD;
@end
