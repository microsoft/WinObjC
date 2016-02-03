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

#import <EventKitUI/EventKitUIExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIContentContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>
#import <EventKit/EKSource.h>

@class EKEventStore;
@protocol EKCalendarChooserDelegate;
@class NSSet;

typedef enum { EKCalendarChooserDisplayAllCalendars, EKCalendarChooserDisplayWritableCalendarsOnly } EKCalendarChooserDisplayStyle;
typedef enum { EKCalendarChooserSelectionStyleSingle, EKCalendarChooserSelectionStyleMultiple } EKCalendarChooserSelectionStyle;
EVENTKITUI_EXPORT_CLASS
@interface EKCalendarChooser
    : UIViewController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
- (id)initWithSelectionStyle:(EKCalendarChooserSelectionStyle)selectionStyle
                displayStyle:(EKCalendarChooserDisplayStyle)displayStyle
                  eventStore:(EKEventStore*)eventStore STUB_METHOD;
- (id)initWithSelectionStyle:(EKCalendarChooserSelectionStyle)selectionStyle
                displayStyle:(EKCalendarChooserDisplayStyle)displayStyle
                  entityType:(EKEntityType)entityType
                  eventStore:(EKEventStore*)eventStore STUB_METHOD;
@property (nonatomic, assign) id<EKCalendarChooserDelegate> delegate STUB_PROPERTY;
@property (copy, nonatomic) NSSet* selectedCalendars STUB_PROPERTY;
@property (readonly, nonatomic) EKCalendarChooserSelectionStyle selectionStyle STUB_PROPERTY;
@property (nonatomic) BOOL showsCancelButton STUB_PROPERTY;
@property (nonatomic) BOOL showsDoneButton STUB_PROPERTY;
@end
