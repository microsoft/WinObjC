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

#include "UINavigationBar.h"

UINavigationBar::UINavigationBar() {
    _barStyle = 0;
    _delegate = NULL;
    _items = NULL;
}

void UINavigationBar::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);

    _barStyle = GetInt("IBUIBarStyle", 0);
    _items = (XIBArray*)obj->FindMember("IBUIItems");
    _outputClassName = "UINavigationBar";
}

void UINavigationBar::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);

    _outputClassName = "UINavigationBar";
}

void UINavigationBar::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);
    if (_items)
        AddOutputMember(writer, "UIItems", _items);
    if (_delegate)
        AddOutputMember(writer, "UIDelegate", _delegate);
    if (_barStyle != 0)
        AddInt(writer, "UIBarStyle", _barStyle);
}
