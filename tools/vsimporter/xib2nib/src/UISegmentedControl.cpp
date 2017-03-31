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

#include "UISegmentedControl.h"
#include "UIColor.h"
#include "UISegment.h"

UISegmentedControl::UISegmentedControl() {
    _segments = NULL;
    _momentary = false;
    _tintColor = NULL;
    _style = 0;
    _selected = -1;
}

void UISegmentedControl::InitFromXIB(XIBObject* obj) {
    UIControl::InitFromXIB(obj);

    _momentary = obj->GetBool("IBMomentary", false);

    XIBArray* titles = (XIBArray*)obj->FindMember("IBSegmentTitles");
    XIBArray* widths = (XIBArray*)obj->FindMember("IBSegmentWidths");
    XIBArray* enabled = (XIBArray*)obj->FindMember("IBSegmentEnabledStates");
    XIBArray* images = (XIBArray*)obj->FindMember("IBSegmentImages");
    _tintColor = (UIColor*)obj->FindMember("IBTintColor");
    _style = obj->GetInt("IBSegmentControlStyle", 0);
    _selected = obj->GetInt("IBSelectedSegmentIndex", -1);

    if (enabled) {
        _segments = new XIBArray();
        UIRect curFrame = getFrame();
        float curX = 0.0f;
        float frameWidth = curFrame.width - 5.0f;
        float segWidth = frameWidth / (float)enabled->count();

        for (int i = 0; i < enabled->count(); i++) {
            bool segEnabled = enabled->objectAtIndex(i)->intValue();

            XIBObject* title = titles->objectAtIndex(i);
            UISegment* newSeg = new UISegment(title, _style, i == 0 ? 0 : i == enabled->count() - 1 ? 2 : 1, _tintColor);
            newSeg->_ignoreUIObject = true;

            UIRect segFrame = curFrame;
            segFrame.x = (float)i * segWidth;
            // segFrame.width =

            _segments->AddMember(NULL, newSeg);
            _subviews->AddMember(NULL, newSeg);
        }
    }

    obj->_outputClassName = "UISegmentedControl";
}

void UISegmentedControl::InitFromStory(XIBObject* obj) {
    UIControl::InitFromStory(obj);

    obj->_outputClassName = "UISegmentedControl";
}

void UISegmentedControl::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIControl::ConvertStaticMappings(writer, obj);
    if (_segments)
        AddOutputMember(writer, "UISegments", _segments);
    if (_momentary)
        AddBool(writer, "UIMomentary", _momentary);
    if (_style)
        AddInt(writer, "UISegmentedControlStyle", _style);
    if (_selected != -1)
        AddInt(writer, "UISelectedSegmentIndex", _selected);
    if (_tintColor)
        AddOutputMember(writer, "UISegmentedControlTintColor", _tintColor);
}
