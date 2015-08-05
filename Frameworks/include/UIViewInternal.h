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

@class UIView;
class AutoLayoutProperties;

class UIViewPrivateState : public LLTreeNode<UIViewPrivateState, UIView>
{
public:
    id superview;   //  id
    idretain backgroundColor;
    id curTouch, curTouchEvent, curTouchSet;
    uint32_t tag;
    BOOL userInteractionEnabled;
    BOOL multipleTouchEnabled;
    UIViewContentMode contentMode;
    AutoLayoutProperties *layoutProperties;
    id currentTouches;
    id gestures;
    idretain constraints;
    bool _isChangingParent;

    UIViewAutoresizing autoresizingMask;
    BOOL               autoresizesSubviews;
    CGRect            _resizeRoundingError;

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
        layoutProperties = NULL;
        _isChangingParent = false;

        autoresizingMask = (UIViewAutoresizing) 0;
        autoresizesSubviews = FALSE;
        memset(&_resizeRoundingError, 0, sizeof(_resizeRoundingError));
    }
};


#endif /* _UIVIEWPRIVATE_H_ */
