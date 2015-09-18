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

#include "NSLayoutConstraint.h"
#include "UIView.h"

#include <assert.h>
#include <map>

std::map<std::string, NSLayoutAttribute> storyToLayout = {
    { "left", NSLayoutAttributeLeft },
    { "right", NSLayoutAttributeRight },
    { "top", NSLayoutAttributeTop },
    { "bottom", NSLayoutAttributeBottom },
    { "leading", NSLayoutAttributeLeading },
    { "trailing", NSLayoutAttributeTrailing },
    { "width", NSLayoutAttributeWidth },
    { "height", NSLayoutAttributeHeight },
    { "centerX", NSLayoutAttributeCenterX },
    { "centerY", NSLayoutAttributeCenterY },
    { "baseline", NSLayoutAttributeBaseline },
    { "firstBaseline", NSLayoutAttributeFirstBaseline },
    { "leftMargin", NSLayoutAttributeLeftMargin },
    { "rightMargin", NSLayoutAttributeRightMargin },
    { "topMargin", NSLayoutAttributeTopMargin },
    { "bottomMargin", NSLayoutAttributeBottomMargin },
    { "leadingMargin", NSLayoutAttributeLeadingMargin },
    { "trailingMargin", NSLayoutAttributeTrailingMargin },
    { "centerXWithinMargins", NSLayoutAttributeCenterXWithinMargins },
    { "centerYWithinMargins", NSLayoutAttributeCenterYWithinMargins }
};

NSLayoutConstraint::NSLayoutConstraint()
{
	_firstItem = NULL;
	_secondItem = NULL;
	_firstAttribute = NSLayoutAttributeNotAnAttribute;
	_secondAttribute = NSLayoutAttributeNotAnAttribute;
	_relation = NSLayoutRelationEqual;
	_multiplier = 1.0f;
	_priority = NSLayoutPriorityRequired;
	_constant = 0.0f;
	_symbolicConstant = 0.0f;
    _hasSymbolicConstant = false;
}

void NSLayoutConstraint::InitFromXIB(XIBObject *obj)
{
	ObjectConverterSwapper::InitFromXIB(obj);

    _firstAttribute = (NSLayoutAttribute)obj->GetInt("firstAttribute", NSLayoutAttributeNotAnAttribute);
    _secondAttribute = (NSLayoutAttribute)obj->GetInt("secondAttribute", NSLayoutAttributeNotAnAttribute);

    _relation = (NSLayoutAttribute)obj->GetInt("relation", NSLayoutRelationEqual);

    _firstItem = obj->FindMember("firstItem");
    _secondItem = obj->FindMember("secondItem");

    if (obj->FindMember("multiplier")) {
        _multiplier = obj->FindMember("multiplier")->floatValue();
    }
    if (obj->FindMember("priority")) {
        _priority = obj->FindMember("priority")->floatValue();
    }
    if (obj->FindMember("constant") && obj->FindMember("constant")->FindMember("value")) {
        if (obj->FindMember("constant")->ClassName() == "IBLayoutConstant") {
            _constant = obj->FindMember("constant")->FindMember("value")->floatValue();
        } else {
            _hasSymbolicConstant = true;
            _symbolicConstant = obj->FindMember("constant")->FindMember("value")->floatValue(); // Hm.
        }
    }

    UIView* view = (UIView*)obj->FindMember("containingView");
    if (view) {
        view->_constraints->AddMember(NULL, this);
    }

    _outputClassName = "NSLayoutConstraint";
}

void NSLayoutConstraint::InitFromStory(XIBObject *obj)
{
    ObjectConverterSwapper::InitFromStory(obj);

    const char* attr;
    if (attr = obj->getAttrib("firstAttribute")) {
        if (storyToLayout.find(attr) != storyToLayout.end()) {
            _firstAttribute = storyToLayout[attr];
        }
    }
    if (attr = obj->getAttrib("secondAttribute")) {
        if (storyToLayout.find(attr) != storyToLayout.end()) {
            _secondAttribute = storyToLayout[attr];
        }
    }

    if (attr = obj->getAttrib("constant")) {
        if (obj->getAttrib("symbolic") && strcmp(obj->getAttrib("symbolic"), "YES") == 0) {
            _hasSymbolicConstant = true;
            _symbolicConstant = strtod(attr, NULL);
        } else {
            _constant = strtod(attr, NULL);
        }
    }
    if (attr = obj->getAttrib("priority")) {
        _priority = strtod(attr, NULL);
    }

    if (attr = obj->getAttrib("multiplier")) {
        _priority = strtod(attr, NULL);
    }

    if (attr = getAttrib("secondItem")) {
        _secondItem = findReference(attr);
        assert(_secondItem);
    }
    if (attr = getAttrib("firstItem")) {
        _firstItem = findReference(attr);
        assert(_firstItem);
    }

    _outputClassName = "NSLayoutConstraint";
}

void NSLayoutConstraint::Awaken() {
    if (!_firstItem) {
        // Alludes to superview.
        if (_secondItem && _secondItem->_parent) {
            _firstItem = dynamic_cast<UIView*>(_secondItem->_parent->_parent);
            assert(_firstItem);
        } else {
            _firstItem = dynamic_cast<UIView*>(_parent->_parent);
            assert(_firstItem);
        }
    }
}

void NSLayoutConstraint::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    AddInt(writer, "NSFirstAttribute", _firstAttribute);
    AddInt(writer, "NSSecondAttribute", _secondAttribute);

    AddInt(writer, "NSRelation", _relation);

    if (_firstItem) AddOutputMember(writer, "NSFirstItem", _firstItem);
    if (_secondItem) AddOutputMember(writer, "NSSecondItem", _secondItem);

    AddOutputMember(writer, "NSMultiplier", new XIBObjectFloat(_multiplier));
    AddInt(writer, "NSPriority", _priority);
    
    if (_hasSymbolicConstant) {
        AddOutputMember(writer, "NSSymbolicConstant", new XIBObjectFloat(_symbolicConstant));
    } else {
        AddOutputMember(writer, "NSConstant", new XIBObjectFloat(_constant));
    }

    ObjectConverterSwapper::ConvertStaticMappings(writer, obj);
}