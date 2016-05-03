//
//  SSSegmentedControl.h
//  SSToolkit
//
//  Created by Sam Soffes on 2/7/11.
//  Copyright 2011 Sam Soffes. All rights reserved.

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

// Limitiations:
// - Removing and inserting items is not supported
// - Setting item width is not supported
// - Setting item content offset is not supported

#pragma once

#import "UIControl.h"
#import "UIImage.h"
#import "UIFont.h"
#import <UIKit/UIBarButtonItem.h>

typedef enum {
    UISegmentedControlStylePlain, // large plain
    UISegmentedControlStyleBordered, // large bordered
    UISegmentedControlStyleBar, // small button/nav bar style. tintable
    UISegmentedControlStyleBezeled, // large bezeled style. tintable
} UISegmentedControlStyle;

enum {
    UISegmentedControlNoSegment = -1 // segment index for no selected segment
};

UIKIT_EXPORT_CLASS
@interface UISegmentedControl : UIControl

@property (nonatomic) UISegmentedControlStyle segmentedControlStyle STUB_PROPERTY;
@property (nonatomic, retain) UIColor* tintColor;
@property (nonatomic, assign, readonly) NSUInteger numberOfSegments;
@property (nonatomic, assign) NSInteger selectedSegmentIndex;
@property (nonatomic, getter=isMomentary) BOOL momentary;
@property (nonatomic) BOOL apportionsSegmentWidthsByContent STUB_PROPERTY;

- (id)initWithItems:(NSArray*)items;

- (void)setTitle:(NSString*)title forSegmentAtIndex:(NSUInteger)segment;
- (NSString*)titleForSegmentAtIndex:(NSUInteger)segment;

- (void)setImage:(UIImage*)image forSegmentAtIndex:(NSUInteger)segment;
- (UIImage*)imageForSegmentAtIndex:(NSUInteger)segment;

- (void)setEnabled:(BOOL)enabled forSegmentAtIndex:(NSUInteger)segment;
- (BOOL)isEnabledForSegmentAtIndex:(NSUInteger)segment STUB_METHOD;

- (void)setDividerImage:(UIImage*)dividerImage
    forLeftSegmentState:(UIControlState)leftState
      rightSegmentState:(UIControlState)rightState
             barMetrics:(UIBarMetrics)barMetrics STUB_METHOD;

- (void)setTitleTextAttributes:(NSDictionary*)attributes forState:(UIControlState)state;
- (void)setBackgroundImage:(UIImage*)backgroundImage forState:(UIControlState)state barMetrics:(UIBarMetrics)barMetrics;

- (void)removeAllSegments;
- (void)insertSegmentWithTitle:(NSString*)title atIndex:(NSUInteger)segment animated:(BOOL)animated;

- (void)setWidth:(CGFloat)width forSegmentAtIndex:(NSUInteger)segment;
- (void)setContentOffset:(CGSize)offset forSegmentAtIndex:(NSUInteger)segment STUB_METHOD;
- (void)insertSegmentWithImage:(UIImage*)image atIndex:(NSUInteger)segment animated:(BOOL)animated;

@end
