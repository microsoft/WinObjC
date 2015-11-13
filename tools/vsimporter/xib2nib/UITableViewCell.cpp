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

#include "UITableViewCell.h"

UITableViewCell::UITableViewCell()
{
    _indentationLevel = 0;
    _indentationWidth = 0;
    _selectionStyle = 0;
    _reuseIdentifier = NULL;
    _detailTextLabel = NULL;
    _imageView = NULL;
    _textLabel = NULL;
}

void UITableViewCell::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    obj->_outputClassName = "UITableViewCell";

    _reuseIdentifier = obj->GetString("IBUIReuseIdentifier", NULL);
    _contentView = (UIView *) obj->FindMember("IBUIContentView");
    _imageView = (UIView *) new XIBObjectNil();
    _textLabel = (UIView *) new XIBObjectNil();
    _detailTextLabel = (UIView *) new XIBObjectNil();
    _selectionStyle = obj->GetInt("IBUISelectionStyle", 0);
    _indentationLevel = obj->GetInt("IBUIIndentationLevel", 0);
    if ( obj->FindMember("IBUIIndentationWidth") ) _indentationWidth = obj->FindMember("IBUIIndentationWidth")->floatValue();
}

void UITableViewCell::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    obj->_outputClassName = "UITableViewCell";

    _contentView = (UIView *)obj->FindMember("contentView");
}

void UITableViewCell::Awaken()
{
    UIView::Awaken();
    if ( _contentView ) {
        _contentView->_clipsToBounds = false;
        _contentView->_backgroundColor = NULL;
        _contentView->_contentMode = 0;
        _contentView->_multipleTouchEnabled = false;
    }
}

void UITableViewCell::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    writer->_allUIObjects->AddMember(NULL, this);
    if ( _contentView ) {
        _contentView->setFrame(getFrame());
        _contentView->_opaque = true;
        int count = _contentView->_subviews->count();
        for ( int i = 0; i < count; i ++ ) {
            UIView *curObj = (UIView *) _contentView->_subviews->objectAtIndex(i);
            //curObj->_bounds.height  = _contentView->_bounds.height;
            writer->_allUIObjects->AddMember(NULL, curObj);
        }
        _contentView->_ignoreUIObject = true;
    }

    UIView::ConvertStaticMappings(writer, obj);

    if ( _indentationLevel ) obj->AddInt(writer, "UIIndentationLevel", _indentationLevel);
    if ( _indentationWidth != 0.0f ) obj->AddOutputMember(writer, "UIIndentationWidth", new XIBObjectFloat(_indentationWidth));
    if ( _reuseIdentifier ) obj->AddString(writer, "UIReuseIdentifier", _reuseIdentifier);
    if ( _contentView ) {
        _contentView->_outputClassName = "UITableViewCellContentView";
        obj->AddOutputMember(writer, "UIContentView", _contentView);
    }
    if ( _imageView ) obj->AddOutputMember(writer, "UIImageView", _imageView);
    if ( _textLabel ) obj->AddOutputMember(writer, "UITextLabel", _textLabel);
    if ( _detailTextLabel ) obj->AddOutputMember(writer, "UIDetailTextLabel", _detailTextLabel);
    obj->AddBool(writer, "UITableCellBackgroundColorSet", true);
    obj->AddInt(writer, "UISelectionStyle", _selectionStyle);
}

ObjectConverter *UITableViewCell::Clone()
{
    return new UITableViewCell();
}
