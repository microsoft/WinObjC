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
#import <MapKit/MKMapView.h>
#import <MapKit/MKAnnotationView.h>

@class MKMapView;
@class NSError;
@class MKUserLocation;
@class MKAnnotationView;
@protocol MKAnnotation;
@class NSArray;
@class UIControl;
@class MKOverlayRenderer;
@protocol MKOverlay;
@class MKOverlayView;

@protocol MKMapViewDelegate <NSObject>
@optional
- (void)mapView:(MKMapView*)mapView regionWillChangeAnimated:(BOOL)animated;
- (void)mapView:(MKMapView*)mapView regionDidChangeAnimated:(BOOL)animated;
- (void)mapViewWillStartLoadingMap:(MKMapView*)mapView;
- (void)mapViewDidFinishLoadingMap:(MKMapView*)mapView;
- (void)mapViewDidFailLoadingMap:(MKMapView*)mapView withError:(NSError*)error;
- (void)mapViewWillStartRenderingMap:(MKMapView*)mapView;
- (void)mapViewDidFinishRenderingMap:(MKMapView*)mapView fullyRendered:(BOOL)fullyRendered;
- (void)mapViewWillStartLocatingUser:(MKMapView*)mapView;
- (void)mapViewDidStopLocatingUser:(MKMapView*)mapView;
- (void)mapView:(MKMapView*)mapView didUpdateUserLocation:(MKUserLocation*)userLocation;
- (void)mapView:(MKMapView*)mapView didFailToLocateUserWithError:(NSError*)error;
- (void)mapView:(MKMapView*)mapView didChangeUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated;
- (MKAnnotationView*)mapView:(MKMapView*)mapView viewForAnnotation:(id<MKAnnotation>)annotation;
- (void)mapView:(MKMapView*)mapView didAddAnnotationViews:(NSArray*)views;
- (void)mapView:(MKMapView*)mapView annotationView:(MKAnnotationView*)view calloutAccessoryControlTapped:(UIControl*)control;
- (void)mapView:(MKMapView*)mapView
        annotationView:(MKAnnotationView*)annotationView
    didChangeDragState:(MKAnnotationViewDragState)newState
          fromOldState:(MKAnnotationViewDragState)oldState;
- (void)mapView:(MKMapView*)mapView didSelectAnnotationView:(MKAnnotationView*)view;
- (void)mapView:(MKMapView*)mapView didDeselectAnnotationView:(MKAnnotationView*)view;
- (MKOverlayRenderer*)mapView:(MKMapView*)mapView rendererForOverlay:(id<MKOverlay>)overlay;
- (void)mapView:(MKMapView*)mapView didAddOverlayRenderers:(NSArray*)renderers;
- (MKOverlayView*)mapView:(MKMapView*)mapView viewForOverlay:(id<MKOverlay>)overlay;
- (void)mapView:(MKMapView*)mapView didAddOverlayViews:(NSArray*)overlayViews;
@end
