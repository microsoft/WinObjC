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

UIFont::UIFont()
{
    _fontName = NULL;
    _fontSize = 0.0f;
}

void UIFont::InitFromXIB(XIBObject *obj)
{
    ObjectConverter::InitFromXIB(obj);
    _fontName = obj->GetString("name", NULL);
    if ( obj->FindMember("pointSize") ) {
        _fontSize = obj->FindMember("pointSize")->floatValue();
    }
    if ( _fontName == NULL ) {
        XIBObject *nsFont = obj->_parent->FindMember("IBUIFont");
        if ( nsFont ) {
            _fontName = nsFont->GetString("NSName", NULL);
        }
    }
    if ( _fontSize == 0.0f ) {
        XIBObject *nsFont = obj->_parent->FindMember("IBUIFont");
        if ( nsFont ) {
            if ( nsFont->FindMember("NSSize") ) {
                _fontSize = nsFont->FindMember("NSSize")->floatValue();
            }
        }
    }

    obj->_outputClassName = "UIFont";
}

void UIFont::InitFromStory(XIBObject *obj)
{
    ObjectConverter::InitFromStory(obj);

    _fontSize = strtod(getAttrib("pointSize"), NULL);

    const char *fontType = getAttrib("type");

    if (fontType) {
        if (strcmp(fontType, "system") == 0) {
            _fontName = "Helvetica";
        }
        else if (strcmp(fontType, "boldSystem") == 0) {
            _fontName = "Helvetica-Bold";
        }
        else {
            assert(0);
        }
    }
    else {
        _fontName = getAttrib("name");
    }

    obj->_outputClassName = "UIFont";
}

void UIFont::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    ObjectConverter::ConvertStaticMappings(writer, obj);

    AddString(writer, "UIFontName", _fontName);
    AddOutputMember(writer, "UIFontPointSize", new XIBObjectDouble(_fontSize));
}
