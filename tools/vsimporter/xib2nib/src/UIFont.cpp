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

#include "UIFont.h"
#include <assert.h>

// Pulled from UIFontDescriptor.mm
const float c_smallSystemFontSize = 12.0f;
const float c_systemFontSize = 14.0f;
const float c_labelFontSize = 17.0f;
const float c_buttonFontSize = 14.0f;

UIFont::UIFont() {
    _fontName = NULL;
    _fontFamilyName = NULL;
    _fontSize = 0.0f;
    _systemFont = false;
}

void UIFont::InitFromXIB(XIBObject* obj) {
    ObjectConverter::InitFromXIB(obj);
    _fontName = obj->GetString("name", NULL);
    if (obj->FindMember("pointSize")) {
        _fontSize = obj->FindMember("pointSize")->floatValue();
    }
    if (_fontName == NULL) {
        XIBObject* nsFont = obj->_parent->FindMember("IBUIFont");
        if (nsFont) {
            _fontName = nsFont->GetString("NSName", NULL);
        }
    }
    if (_fontSize == 0.0f) {
        XIBObject* nsFont = obj->_parent->FindMember("IBUIFont");
        if (nsFont) {
            if (nsFont->FindMember("NSSize")) {
                _fontSize = nsFont->FindMember("NSSize")->floatValue();
            }
        }
    }

    XIBObject* nsFontDescriptor = obj->_parent->FindMember("IBUIFontDescription");

    // This overrides "pointSize" and parent->"NSSize"
    if (nsFontDescriptor && nsFontDescriptor->FindMember("size")) {
        switch (nsFontDescriptor->FindMember("size")->intValue()) {
            case 1: // Label size
                _fontSize = c_labelFontSize;
                break;
            case 2: // Button size
                _fontSize = c_buttonFontSize;
                break;
            case 3: // Small size
                _fontSize = c_smallSystemFontSize;
                break;
            case 4: // System size
                _fontSize = c_systemFontSize;
                break;
            default:
                printf("Unhandled symbolic font size type: %s\n", nsFontDescriptor->FindMember("size")->stringValue());
                assert(0);
                break;
        }
    }

    obj->_outputClassName = "UIFont";
}

void UIFont::InitFromStory(XIBObject* obj) {
    ObjectConverter::InitFromStory(obj);

    _fontSize = 12.0;
    auto attribute = getAttrAndHandle("pointSize");
    if (attribute) {
        _fontSize = (float)strtod(attribute, NULL);
    }

    if (getAttrib("type")) {
        const char* fontType = getAttrib("type");
        bool isHandled = true;

        if (strcmp(fontType, "system") == 0) {
            _fontName = "Helvetica";
            _systemFont = true;
        } else if (strcmp(fontType, "boldSystem") == 0) {
            _fontName = "Helvetica-Bold";
            _systemFont = true;
        } else {
            isHandled = false;
        }

        if (isHandled) {
            getAttrAndHandle("type");
        }
    } else {
        _fontName = getAttrAndHandle("name");
        _fontFamilyName = getAttrAndHandle("family");
    }

    if (getAttrib("size")) {
        const char* symbolicSize = getAttrAndHandle("size");

        if (strcmp(symbolicSize, "system") == 0) {
            _fontSize = c_systemFontSize;
        } else if (strcmp(symbolicSize, "button") == 0) {
            _fontSize = c_buttonFontSize;
        } else if (strcmp(symbolicSize, "small") == 0) {
            _fontSize = c_smallSystemFontSize;
        } else if (strcmp(symbolicSize, "label") == 0) {
            _fontSize = c_labelFontSize;
        } else {
            printf("Unhandled symbolic font size type: %s\n", symbolicSize);
            assert(0);
        }
    }

    obj->_outputClassName = "UIFont";
}

void UIFont::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    ObjectConverter::ConvertStaticMappings(writer, obj);

    AddString(writer, "UIFontName", _fontName);
    AddString(writer, "UIFontFamilyName", _fontFamilyName);
    AddOutputMember(writer, "UIFontPointSize", new XIBObjectDouble(_fontSize));

    if (_systemFont) {
        AddBool(writer, "UISystemFont", _systemFont);
    }
}
