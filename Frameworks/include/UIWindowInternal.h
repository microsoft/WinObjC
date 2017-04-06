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

#import <UIKit/UIWindow.h>

@class UIViewController;

@interface UIWindow ()
// TODO: #2441 Remove this seemingly-unnecessary private method (why not call the public setRootViewController?)
- (void)_setRootViewController:(UIViewController*)controller;

// TODO: #2440 Remove this unnecessary method in favor of properly implementing UIView point/rect conversion
- (CGPoint)_convertPoint:(CGPoint)point fromView:(UIView*)fromView toView:(UIView*)toView;
@end