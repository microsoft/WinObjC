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

#include "UIActivityIndicatorView.h"
#include "UIColor.h"

UIActivityIndicatorView::UIActivityIndicatorView() {
    _animating = false;
    _style = 0;
    _tintColor = NULL;
}

void UIActivityIndicatorView::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);

    _style = obj->GetInt("IBUIStyle", 0);
    _animating = obj->GetBool("IBUIAnimating", false);

    _outputClassName = "UIActivityIndicatorView";
}

void UIActivityIndicatorView::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);

    const char* animatingAttr = getAttrAndHandle("animating");
    if (animatingAttr && strcmp(animatingAttr, "YES") == 0) {
        _animating = true;
    }

    const char* styleAttr = getAttrAndHandle("style");
    if (styleAttr) {
        if (strcmp(styleAttr, "white") == 0) {
            _style = 0;
        } else if (strcmp(styleAttr, "whiteLarge") == 0) {
            _style = 1;
        } else if (strcmp(styleAttr, "gray") == 0) {
            _style = 2;
        }
    }

    XIBObject* rectAttr = FindMember("frame");
    _frame = { 0, 0, 0, 0 };
    if (rectAttr) {
        _frame.x = strtof(rectAttr->getAttrAndHandle("x"), NULL);
        _frame.y = strtof(rectAttr->getAttrAndHandle("y"), NULL);
        _frame.width = strtof(rectAttr->getAttrAndHandle("width"), NULL);
        _frame.height = strtof(rectAttr->getAttrAndHandle("height"), NULL);
    }

    _outputClassName = "UIActivityIndicatorView";
}

void UIActivityIndicatorView::Awaken() {
    UIView::Awaken();

    switch (_style) {
        case 0: // whiteLarge
        case 1: // white
            _tintColor = new UIColor(4, 4, 1.0f, 0.0f, 0.0f, 1.0f, "whiteColor");
            break;
        case 2: // gray
            _tintColor = new UIColor(4, 4, 0.5f, 0.5f, 0.5f, 1.0f, "grayColor");
            break;
    }
}

void UIActivityIndicatorView::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);

    if (_style) {
        AddInt(writer, "UIActivityIndicatorViewStyle", _style);
    }

    if (_animating) {
        AddBool(writer, "UIAnimating", _animating);
    }

    if (_tintColor) {
        AddOutputMember(writer, "UITintColor", _tintColor);
    }

    // When UINibUnArchiver have decodeCGrectForKey method.Code needs to be refactored.
    AddInt(writer, "UIFrameX", (int)_frame.x);
    AddInt(writer, "UIFrameY", (int)_frame.y);
    AddInt(writer, "UIFrameWidth", (int)_frame.width);
    AddInt(writer, "UIFrameHeight", (int)_frame.height);
}
