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

#include "UITabBar.h"

UITabBar::UITabBar() {
    _delegate = NULL;
    _bounds.x = 0.0f;
    _bounds.y = 0.0f;
    _bounds.width = 320.0f;
    _bounds.height = 49.0f;

    _center.x = _bounds.width / 2.0f;
    _center.y = _bounds.height / 2.0f;

    _items = NULL;
}

void UITabBar::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);

    _outputClassName = "UITabBar";
}

void UITabBar::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);

    _autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;

    _outputClassName = "UITabBar";
}

void UITabBar::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);
    if (_delegate)
        AddOutputMember(writer, "UIDelegate", _delegate);
    if (_items)
        AddOutputMember(writer, "UIItems", _items);
}
