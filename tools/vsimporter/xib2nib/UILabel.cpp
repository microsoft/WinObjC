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

#include "UILabel.h"
#include "UIColor.h"
#include "UIFont.h"
#include <assert.h>

static void MakeMutable(struct _PropertyMapper *prop, NIBWriter *writer, XIBObject *propObj, XIBObject *obj)
{
    propObj->_className = "NSMutableString";
    obj->AddOutputMember(writer, prop->nibName, propObj);
}

static void WriteLayoutWidth(struct _PropertyMapper *prop, NIBWriter *writer, XIBObject *propObj, XIBObject *obj)
{
    obj->AddOutputMember(writer, "UIPreferredMaxLayoutWidth", new XIBObjectFloat(propObj->floatValue()));
}

static PropertyMapper propertyMappings[] = {
    "IBUIShadowColor", "UIShadowColor", NULL,
    "IBUILineBreakMode", "UILineBreakMode", NULL,
    "preferredMaxLayoutWidth", "UIPreferredMaxLayoutWidth", WriteLayoutWidth,
};
static const int numPropertyMappings = sizeof(propertyMappings) / sizeof(PropertyMapper);

UILabel::UILabel()
{
    _text = NULL;
    _textAlignment = 0;
    _highlightedColor = NULL;
    _textColor = NULL;
    _numberOfLines = 1;
    _baselineAdjustment = 0;
    _adjustsFontSizeToFit = false;
    _minimumFontSize = -1.0f;
    _font = NULL;
}

void UILabel::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    _shadowOffset = obj->GetSize("IBUIShadowOffset", 0, -1.0f);
    _text = obj->GetString("IBUIText", NULL);
    _textColor = (UIColor *) obj->FindMember("IBUITextColor");
    if ( _textColor && _textColor->isNil() ) _textColor = NULL;
    _highlightedColor = (UIColor *) obj->FindMember("IBUIHighlightedColor");
    if ( _highlightedColor && _highlightedColor->isNil() ) _highlightedColor = NULL;

    _baselineAdjustment = obj->GetInt("IBUIBaselineAdjustment", 0);

    _textAlignment = obj->GetInt("IBUITextAlignment", 0);
    _numberOfLines = obj->GetInt("IBUINumberOfLines", 1);
    _font = (UIFont *) obj->FindMember("IBUIFontDescription");
    if ( !_font ) _font = (UIFont *) obj->FindMember("IBUIFont");

    if ( FindMember("IBUIMinimumFontSize") ) {
        _minimumFontSize = FindMember("IBUIMinimumFontSize")->floatValue();
        _adjustsFontSizeToFit = true;
    }
    obj->_outputClassName = "UILabel";
}

void UILabel::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    memset(&_shadowOffset, 0, sizeof(_shadowOffset));
    _shadowOffset.height = -1.0f;
    _text = getAttrib("text");
    _textColor = (UIColor *) obj->FindMember("textColor");
    _font = (UIFont *) obj->FindMember("fontDescription");

    if ( getAttrib("numberOfLines") ) {
        _numberOfLines = atoi(getAttrib("numberOfLines"));
    }
    if ( getAttrib("textAlignment") ) {
        const char *pAlign = getAttrib("textAlignment");

        if ( strcmp(pAlign, "left") == 0 ) {
            _textAlignment = 0;
        } else if ( strcmp(pAlign, "center") == 0 ) {
            _textAlignment = 1;
        } else if (strcmp(pAlign, "right") == 0 ) {
            _textAlignment = 2;
        } else {
            assert(0);
        }
    }
    if ( getAttrib("minimumFontSize") ) {
        _minimumFontSize = strtod(getAttrib("minimumFontSize"), NULL);
        const char *adjust = getAttrib("adjustsFontSizeToFit");
        
        if ( !adjust || strcmp(adjust, "NO") != 0 )_adjustsFontSizeToFit = true;
    }
    obj->_outputClassName = "UILabel";
}

void UILabel::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    if ( _shadowOffset.width != 0.0 || _shadowOffset.height != 0.0 ) obj->AddSize(writer, "UIShadowOffset", _shadowOffset);
    if ( _text ) obj->AddString(writer, "UIText", _text);
    if ( _textColor ) {
        obj->AddOutputMember(writer, "UITextColor", _textColor);
    } else {
        UIColor *color = new UIColor(4, 4, 0.0f, 0.0f, 0.0f, 1.0f, "whiteColor");
        obj->AddOutputMember(writer, "UITextColor", color->CreateObject(writer));
    }
    if ( _highlightedColor ) {
        obj->AddOutputMember(writer, "UIHighlightedColor", _highlightedColor);
    }
    AddOutputMember(writer, "UIMinimumScaleFactor", new XIBObjectFloat(1.0f));
    if ( _textAlignment != 0 ) AddInt(writer, "UITextAlignment", _textAlignment);
    if ( _numberOfLines != 1 ) AddInt(writer, "UINumberOfLines", _numberOfLines);
    if ( _baselineAdjustment != 0 ) AddInt(writer, "UIBaselineAdjustment", _baselineAdjustment);
    if ( _numberOfLines == 1 ) {
        if ( _adjustsFontSizeToFit ) AddBool(writer, "UIAdjustsFontSizeToFit", _adjustsFontSizeToFit);
        if ( _minimumFontSize != -1.0f ) AddOutputMember(writer, "UIMinimumFontSize", new XIBObjectFloat(_minimumFontSize));
    }
    if ( _font ) AddOutputMember(writer, "UIFont", _font);

    Map(writer, obj, propertyMappings, numPropertyMappings);
    UIView::ConvertStaticMappings(writer, obj);
}

ObjectConverter *UILabel::Clone()
{
    return new UILabel();
}