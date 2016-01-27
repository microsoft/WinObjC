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

#import <StubReturn.h>
#import <MapKit/MKMapView.h>

@implementation MKMapView
/**
 @Status Stub
 @Notes
*/
- (void)setRegion:(MKCoordinateRegion)region animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)showAnnotations:(NSArray*)annotations animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setVisibleMapRect:(MKMapRect)mapRect animated:(BOOL)animate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setVisibleMapRect:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setCamera:(MKMapCamera*)camera animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setUserTrackingMode:(MKUserTrackingMode)mode animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addAnnotation:(id<MKAnnotation>)annotation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addAnnotations:(NSArray*)annotations {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAnnotation:(id<MKAnnotation>)annotation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAnnotations:(NSArray*)annotations {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (MKAnnotationView*)viewForAnnotation:(id<MKAnnotation>)annotation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSSet*)annotationsInMapRect:(MKMapRect)mapRect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKAnnotationView*)dequeueReusableAnnotationViewWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)selectAnnotation:(id<MKAnnotation>)annotation animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deselectAnnotation:(id<MKAnnotation>)annotation animated:(BOOL)animated {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)overlaysInLevel:(MKOverlayLevel)level {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKOverlayRenderer*)rendererForOverlay:(id<MKOverlay>)overlay {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKOverlayView*)viewForOverlay:(id<MKOverlay>)overlay {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOverlay:(id<MKOverlay>)overlay level:(MKOverlayLevel)level {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOverlays:(NSArray*)overlays level:(MKOverlayLevel)level {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOverlay:(id<MKOverlay>)overlay {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addOverlays:(NSArray*)overlays {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertOverlay:(id<MKOverlay>)overlay atIndex:(NSUInteger)index level:(MKOverlayLevel)level {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertOverlay:(id<MKOverlay>)overlay atIndex:(NSUInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertOverlay:(id<MKOverlay>)overlay aboveOverlay:(id<MKOverlay>)sibling {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertOverlay:(id<MKOverlay>)overlay belowOverlay:(id<MKOverlay>)sibling {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)exchangeOverlay:(id<MKOverlay>)overlay1 withOverlay:(id<MKOverlay>)overlay2 {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)exchangeOverlayAtIndex:(NSUInteger)index1 withOverlayAtIndex:(NSUInteger)index2 {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeOverlay:(id<MKOverlay>)overlay {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeOverlays:(NSArray*)overlays {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGRect)convertRegion:(MKCoordinateRegion)region toRectToView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKCoordinateRegion)regionThatFits:(MKCoordinateRegion)region {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (MKMapRect)mapRectThatFits:(MKMapRect)mapRect edgePadding:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
