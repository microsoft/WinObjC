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

#include "UIToolbar.h"
#include <assert.h>

UIToolbar::UIToolbar() {
    _items = NULL;
    _style = 0;
}

void UIToolbar::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);

    _items = (XIBArray*)FindMember("IBUIItems");

    _outputClassName = "UIToolbar";
}

void UIToolbar::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);
    _items = (XIBArray*)FindMemberClass("items");
    _outputClassName = "UIToolbar";

    const char* style = getAttrib("barStyle");
    if (style) {
        bool isHandled = true;
        if (strcmp(style, "blackOpaque") == 0) {
            _style = 1;
        } else if (strcmp(style, "blackTranslucent") == 0) {
            _style = 2;
        } else {
            isHandled = false;
        }

        if (isHandled) {
            getAttrAndHandle("barStyle");
        }
    }
}

void UIToolbar::Awaken() {
    _opaque = true;
}

void UIToolbar::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);
    if (_style != 0)
        AddInt(writer, "UIBarStyle", _style);

    if (!_items)
        _items = new XIBArray();
    if (_items)
        AddOutputMember(writer, "UIItems", _items);
}
