//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <UIKit/NSLayoutAnchor.h>
#import <CoreGraphics/CGBase.h>

@class NSLayoutConstraint;

UIKIT_EXPORT_CLASS
@interface NSLayoutDimension : NSLayoutAnchor
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m ;
- (NSLayoutConstraint*)constraintEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m constant:(CGFloat)c;
- (NSLayoutConstraint*)constraintEqualToConstant:(CGFloat)c;
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m;
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToAnchor:(NSLayoutDimension*)anchor
                                                 multiplier:(CGFloat)m
                                                   constant:(CGFloat)c;
- (NSLayoutConstraint*)constraintGreaterThanOrEqualToConstant:(CGFloat)c;
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m;
- (NSLayoutConstraint*)constraintLessThanOrEqualToAnchor:(NSLayoutDimension*)anchor multiplier:(CGFloat)m constant:(CGFloat)c;
- (NSLayoutConstraint*)constraintLessThanOrEqualToConstant:(CGFloat)c;
@end
