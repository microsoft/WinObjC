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
#include "UIControl.h"

struct EdgeInsets {
    float top;
    float left;
    float bottom;
    float right;

    EdgeInsets() : top(INFINITY), left(INFINITY), bottom(INFINITY), right(INFINITY) {
    }

    bool IsValid() {
        return top != INFINITY && left != INFINITY && bottom != INFINITY && right != INFINITY;
    }
};

class UIFont;
class UIButton : public UIControl {
public:
    int _buttonType;
    UIFont* _font;
    XIBObject* _statefulContent;
    bool _adjustsImageWhenHighlighted;
    bool _adjustsImageWhenDisabled;
    EdgeInsets _imageEdgeInsets;
    EdgeInsets _contentEdgeInsets;
    EdgeInsets _titleEdgeInsets;

    UIButton();
    virtual void InitFromXIB(XIBObject* obj);
    virtual void InitFromStory(XIBObject* obj);
    virtual void ConvertStaticMappings(NIBWriter* writer, XIBObject* obj);
    void WriteStatefulContent(NIBWriter* writer, XIBObject* obj);
};
