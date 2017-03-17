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

#include "UIGestureRecognizer.h"

UIGestureRecognizer::UIGestureRecognizer() {
    _enabled = true;
    _cancelsTouchesInView = true;
    _delaysTouchesBegan = false;
    _delaysTouchesEnded = true;
}

void UIGestureRecognizer::InitFromXIB(XIBObject* obj) {
    ObjectConverterSwapper::InitFromXIB(obj);
}

void UIGestureRecognizer::InitFromStory(XIBObject* obj) {
    ObjectConverterSwapper::InitFromStory(obj);

    const char* enabled = getAttrib("enabled");
    if (enabled) {
        _enabled = strcmp(enabled, "YES") == 0;
    }

    const char* cancelsTouchesInView = getAttrib("cancelsTouchesInView");
    if (cancelsTouchesInView) {
        _cancelsTouchesInView = strcmp(cancelsTouchesInView, "YES") == 0;
    }

    const char* delaysTouchesBegan = getAttrib("delaysTouchesBegan");
    if (delaysTouchesBegan) {
        _delaysTouchesBegan = strcmp(delaysTouchesBegan, "YES") == 0;
    }

    const char* delaysTouchesEnded = getAttrib("delaysTouchesEnded");
    if (delaysTouchesEnded) {
        _delaysTouchesEnded = strcmp(delaysTouchesEnded, "YES") == 0;
    }
}

void UIGestureRecognizer::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    if (!_enabled) {
        // It is 'enabled' in the XIB, but 'disabled' is the property
        AddBool(writer, "UIGestureRecognizer.disabled", !_enabled);
    }

    if (!_cancelsTouchesInView) {
        AddBool(writer, "UIGestureRecognizer.cancelsTouchesInView", _cancelsTouchesInView);
    }

    if (_delaysTouchesBegan) {
        AddBool(writer, "UIGestureRecognizer.delaysTouchesBegan", _delaysTouchesBegan);
    }

    if (!_delaysTouchesEnded) {
        AddBool(writer, "UIGestureRecognizer.delaysTouchesEnded", _delaysTouchesEnded);
    }
}
