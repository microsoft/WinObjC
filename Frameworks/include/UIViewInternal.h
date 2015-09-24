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

#ifndef _UIVIEWPRIVATE_H_
#define _UIVIEWPRIVATE_H_

#include "LinkedList.h"

class AutoLayoutProperties;
class ConstraintProperties;

class UIViewPrivateState : public LLTreeNode<UIViewPrivateState, UIView>
{
public:
    id superview;   //  id
    idretaint<UIColor> backgroundColor;
    id curTouch, curTouchEvent, curTouchSet;
    uint32_t tag;
    BOOL userInteractionEnabled;
    BOOL multipleTouchEnabled;
    UIViewContentMode contentMode;
    AutoLayoutProperties *layoutProperties;
    id currentTouches;
    id gestures;
    NSMutableArray* constraints;
    bool _isChangingParent;
    bool _constraintsNeedUpdate;

    UIViewAutoresizing autoresizingMask;
    CGSize             _contentHuggingPriority;
    CGSize             _contentCompressionResistancePriority;
    BOOL               autoresizesSubviews;
    BOOL               translatesAutoresizingMaskIntoConstraints;
    BOOL               _constrained;
    CGRect             _resizeRoundingError;

    UIViewPrivateState()
    {
        superview = nil;
        backgroundColor = nil;
        curTouch = nil;
        curTouchEvent = nil;
        curTouchSet = nil;
        tag = 0;
        userInteractionEnabled = 0;
        multipleTouchEnabled = 0;
        contentMode = UIViewContentModeScaleToFill;
        currentTouches = nil;
        gestures = nil;
        constraints = nil;
        translatesAutoresizingMaskIntoConstraints = TRUE;
        layoutProperties = NULL;
        _isChangingParent = false;
        _constraintsNeedUpdate = false;
        _constrained = false;
        _contentHuggingPriority.height = 250.0f;
        _contentHuggingPriority.width = 250.0f;
        _contentCompressionResistancePriority.height = 750.0f;
        _contentCompressionResistancePriority.width = 750.0f;

        autoresizingMask = (UIViewAutoresizing) 0;
        autoresizesSubviews = FALSE;
        memset(&_resizeRoundingError, 0, sizeof(_resizeRoundingError));
    }
};

class NSLayoutConstraintPrivateState
{
public:
    NSLayoutConstraintPrivateState() 
        : _constraints(NULL)
    { 
    }

    ConstraintProperties* _constraints;
};

// This is a bit of a hack (since didMoveToWindow should only be in UIView-derived classes)
// but we use this to resign firstResponder-ship so carets stop blinking when moving between windows.
@interface UIResponder ()
-(void)didMoveToWindow;
@end

@interface UIView() {
@public
    UIViewPrivateState* priv;
}
-(void) initPriv;
-(UIViewPrivateState*) _privateState;
@end

@interface NSLayoutConstraint() { 
    NSLayoutConstraintPrivateState* priv;
}
-(NSLayoutConstraintPrivateState*) _privateState;
- (void)printConstraint;
+ (void)printConstraints:(NSArray*)constraints;

- (void)_setShouldLayout;
+ (void)_setNestedAnimationsEnabled:(BOOL)enable;
@end

@interface _UILayoutGuide : UIView<UILayoutSupport>
@end

#endif /* _UIVIEWPRIVATE_H_ */
