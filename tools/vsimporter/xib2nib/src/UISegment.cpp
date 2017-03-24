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

#include "UISegment.h"
#include "UIColor.h"

UISegment::UISegment(XIBObject* info, int style, int position, UIColor* tintColor) {
    _info = info;
    _style = style;
    _position = position;
    _tintColor = tintColor;
    _outputClassName = "UISegment";
    _connectedObjects = nullptr;
    _connections = nullptr;
}

void UISegment::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);

    obj->_outputClassName = "UISegment";
}

void UISegment::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);

    obj->_outputClassName = "UISegment";
}

void UISegment::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);
    if (_info)
        AddOutputMember(writer, "UISegmentInfo", _info);
    if (_style)
        AddInt(writer, "UISegmentStyle", _style);
    if (_position)
        AddInt(writer, "UISegmentPosition", _position);
    if (_tintColor)
        AddOutputMember(writer, "UISegmentTintColor", _tintColor);
}
