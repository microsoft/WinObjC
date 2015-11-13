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

#ifndef _UIATTACHMENTBEHAVIOR_H_
#define _UIATTACHMENTBEHAVIOR_H_

#import <UIKit/UIDynamicBehavior.h>
#import <UIKit/UIDynamicAnimator.h>

@class NSArray;

@interface UIAttachmentBehavior : UIDynamicBehavior

@property (nonatomic, readonly, copy) NSArray* items;
@property (readwrite, nonatomic) CGFloat length;
@property (readwrite, nonatomic) CGFloat damping;
@property (readwrite, nonatomic) CGFloat frequency;
@property (readwrite, nonatomic) CGPoint anchorPoint;

- (instancetype)initWithItem:(id<UIDynamicItem>)item attachedToAnchor:(CGPoint)point;

@end

#endif /* _UIATTACHMENTBEHAVIOR_H_ */