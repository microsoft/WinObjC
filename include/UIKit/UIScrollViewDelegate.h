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
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/NSObject.h>

@class UIScrollView;
@class UIView;

@protocol UIScrollViewDelegate <NSObject>
@optional
- (void)scrollViewDidScroll:(UIScrollView*)scrollView;
- (void)scrollViewWillBeginDragging:(UIScrollView*)scrollView;
- (void)scrollViewWillEndDragging:(UIScrollView*)scrollView
                     withVelocity:(CGPoint)velocity
              targetContentOffset:(inout CGPoint*)targetContentOffset;
- (void)scrollViewDidEndDragging:(UIScrollView*)scrollView willDecelerate:(BOOL)decelerate;
- (BOOL)scrollViewShouldScrollToTop:(UIScrollView*)scrollView;
- (void)scrollViewDidScrollToTop:(UIScrollView*)scrollView;
- (void)scrollViewWillBeginDecelerating:(UIScrollView*)scrollView;
- (void)scrollViewDidEndDecelerating:(UIScrollView*)scrollView;
- (UIView*)viewForZoomingInScrollView:(UIScrollView*)scrollView;
- (void)scrollViewWillBeginZooming:(UIScrollView*)scrollView withView:(UIView*)view;
- (void)scrollViewDidEndZooming:(UIScrollView*)scrollView withView:(UIView*)view atScale:(CGFloat)scale;
- (void)scrollViewDidZoom:(UIScrollView*)scrollView;
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView*)scrollView;
@end
