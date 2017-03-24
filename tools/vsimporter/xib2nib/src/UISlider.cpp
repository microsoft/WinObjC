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

#include "UISlider.h"
#include <assert.h>

UISlider::UISlider() {
}

void UISlider::InitFromXIB(XIBObject* obj) {
    UIControl::InitFromXIB(obj);

    _minValue = _maxValue = _value = 0.0f;

    if (obj->FindMember("IBUIValue")) {
        _value = obj->FindMember("IBUIValue")->floatValue();
    }
    if (obj->FindMember("IBUIMinValue")) {
        _minValue = obj->FindMember("IBUIMinValue")->floatValue();
    }
    if (obj->FindMember("IBUIMaxValue")) {
        _maxValue = obj->FindMember("IBUIMaxValue")->floatValue();
    }
    _outputClassName = "UISlider";
}

void UISlider::InitFromStory(XIBObject* obj) {
    UIControl::InitFromStory(obj);

    if (getAttrib("minValue")) {
        _minValue = strtof(getAttrAndHandle("minValue"), NULL);
    }
    if (getAttrib("maxValue")) {
        _maxValue = strtof(getAttrAndHandle("maxValue"), NULL);
    }
    if (getAttrib("value")) {
        _value = strtof(getAttrAndHandle("value"), NULL);
    }

    _outputClassName = "UISlider";
}

void UISlider::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIControl::ConvertStaticMappings(writer, obj);
    AddOutputMember(writer, "UIValue", new XIBObjectFloat(_value));
    AddOutputMember(writer, "UIMinValue", new XIBObjectFloat(_minValue));
    AddOutputMember(writer, "UIMaxValue", new XIBObjectFloat(_maxValue));
}
