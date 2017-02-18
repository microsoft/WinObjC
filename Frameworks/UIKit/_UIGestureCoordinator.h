//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIEvent.h>
#import <UIKit/UITapGestureRecognizer.h>

UIKIT_EXPORT_CLASS
@interface _UIGestureCoordinator : NSObject

// singleton to be used globally
+ (instancetype)singleton;

- (instancetype)init;
- (void)dealloc;

// Main entrance to send touch to gesture pipleline for processing, invoked by UIView
- (bool)processGesturesForTouch:(UITouch*)touch event:(UIEvent*)event touchEventName:(SEL)eventName;

// Reset all gestures in all container to possible state and remove them from their container
// this is called by UIView when all finger are lifted (all touch ended or cancelled)
// thus all gestures are reset
- (void)resetTrackingGestureList;

// Cancelled a gesture if it is in tracked gesture list
- (void)cancelTrackedGesture:(UIGestureRecognizer*)curgesture;

//
// TODO: The following functions are legacy behaviour related to TapGesture, we will revisit to see
// they should be exposed by GestureCoordinator
//

// Check if tracking gestures contains Tap Gesture requres multi-tap
- (BOOL)containsTapGestureRequiredMultipleTap;

// Get max number of taps required for all tap gestures
- (unsigned)maxNubmerOfTapsRequiredInAllTapGestures;

// Fail other Tap gestures except specified one
- (void)failOtherTapGesturesExcept:(UITapGestureRecognizer*)curGesture;

//
// The following are test methods
//

// Get tracking regular gestures
- (NSArray*)getRegularGestureRecognizers;

// Get tracking dmanip gestures
- (NSArray*)getDmanipGestureRecognizer;

// Get gestures in possible state
- (NSSet*)getGestureRecognizerInPossibleState;

@end
