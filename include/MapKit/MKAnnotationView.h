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

@protocol MKAnnotation;
@class NSString;
@class UIImage;

typedef enum MKAnnotationViewDragState {
    MKAnnotationViewDragStateNone = 0,
    MKAnnotationViewDragStateStarting,
    MKAnnotationViewDragStateDragging,
    MKAnnotationViewDragStateCanceling,
    MKAnnotationViewDragStateEnding
} MKAnnotationViewDragState;

// Missing declaration of //apple_ref/c/data/MKAnnotationCalloutInfoDidChangeNotification

MAPKIT_EXPORT_CLASS
@interface MKAnnotationView
    : UIView <NSCoding, UIAppearance, UIAppearanceContainer, UICoordinateSpace, UIDynamicItem, UIFocusEnvironment, UITraitEnvironment>
- (instancetype)initWithAnnotation:(id<MKAnnotation>)annotation reuseIdentifier:(NSString*)reuseIdentifier STUB_METHOD;
- (void)prepareForReuse STUB_METHOD;
@property (getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
@property (nonatomic, strong) UIImage* image STUB_PROPERTY;
@property (getter=isHighlighted, nonatomic) BOOL highlighted STUB_PROPERTY;
@property (nonatomic, strong) id<MKAnnotation> annotation STUB_PROPERTY;
@property (nonatomic) CGPoint centerOffset STUB_PROPERTY;
@property (nonatomic) CGPoint calloutOffset STUB_PROPERTY;
@property (readonly, nonatomic) NSString* reuseIdentifier STUB_PROPERTY;
- (void)setSelected:(BOOL)selected animated:(BOOL)animated STUB_METHOD;
@property (getter=isSelected, nonatomic) BOOL selected STUB_PROPERTY;
@property (nonatomic) BOOL canShowCallout STUB_PROPERTY;
@property (nonatomic, strong) UIView* leftCalloutAccessoryView STUB_PROPERTY;
@property (nonatomic, strong) UIView* rightCalloutAccessoryView STUB_PROPERTY;
@property (nonatomic, strong) UIView* detailCalloutAccessoryView STUB_PROPERTY;
@property (getter=isDraggable, nonatomic) BOOL draggable STUB_PROPERTY;
- (void)setDragState:(MKAnnotationViewDragState)newDragState animated:(BOOL)animated STUB_METHOD;
@property (nonatomic) MKAnnotationViewDragState dragState STUB_PROPERTY;
@end
