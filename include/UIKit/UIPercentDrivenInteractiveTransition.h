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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <UIKit/UIViewControllerInteractiveTransitioning.h>
#import <UIKit/UIView.h>

UIKIT_EXPORT_CLASS
@interface UIPercentDrivenInteractiveTransition : NSObject <UIViewControllerInteractiveTransitioning>
@property (assign, nonatomic) UIViewAnimationCurve completionCurve STUB_PROPERTY;
@property (readonly) CGFloat duration STUB_PROPERTY;
@property (readonly) CGFloat percentComplete STUB_PROPERTY;
@property (assign, nonatomic) CGFloat completionSpeed STUB_PROPERTY;
- (void)updateInteractiveTransition:(CGFloat)percentComplete STUB_METHOD;
- (void)cancelInteractiveTransition STUB_METHOD;
- (void)finishInteractiveTransition STUB_METHOD;
@end
