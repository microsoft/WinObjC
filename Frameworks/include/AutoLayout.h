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

#import "UIKit/UIView.h"
#import "UIKit/NSLayoutConstraint.h"
#import "UIViewInternal.h"

extern "C" bool InitializeAutoLayout();

@protocol AutoLayoutConstraint
- (void)autoLayoutAlloc;
- (void)autoLayoutDealloc;
- (void)autoLayoutConstraintAddedToView:(UIView*)view;
- (void)autoLayoutConstraintRemovedFromView;
@end

@interface NSLayoutConstraint (AutoLayout) <AutoLayoutConstraint>
@end

@protocol AutoLayoutView
- (void)autoLayoutAlloc;
- (void)autoLayoutDealloc;
- (void)autoLayoutLayoutSubviews;
- (void)autoLayoutInitWithCoder:(NSCoder*)coder;
- (void)autoLayoutUpdateConstraints;
@end

@interface UIView (AutoLayout) <AutoLayoutView>
- (void)invalidateContentSize;
@end
