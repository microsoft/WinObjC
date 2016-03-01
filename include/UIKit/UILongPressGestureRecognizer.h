//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <UIKit/UIGestureRecognizer.h>

UIKIT_EXPORT_CLASS
@interface UILongPressGestureRecognizer : UIGestureRecognizer

// The time interval is in seconds. The default duration is is 0.5 seconds.
@property (nonatomic) CFTimeInterval minimumPressDuration;

// The allowable distance, measured in points. The default distance is 10 points
@property (nonatomic) CGFloat allowableMovement;

// The default number of taps is 0.
@property (nonatomic) NSUInteger numberOfTapsRequired;

// The default number of fingers is 1.
@property (nonatomic) NSUInteger numberOfTouchesRequired;

@end
