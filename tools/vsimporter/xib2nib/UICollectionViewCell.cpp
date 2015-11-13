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

#include "UICollectionViewCell.h"

UICollectionReusableView::UICollectionReusableView()
{
}

void UICollectionReusableView::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    obj->_outputClassName = "UICollectionReusableView";
}

void UICollectionReusableView::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    obj->_outputClassName = "UICollectionReusableView";
}

void UICollectionReusableView::Awaken()
{
    UIView::Awaken();
}

void UICollectionReusableView::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    writer->_allUIObjects->AddMember(NULL, this);

    UIView::ConvertStaticMappings(writer, obj);
}

ObjectConverter *UICollectionReusableView::Clone()
{
    return new UICollectionReusableView();
}

UICollectionViewCell::UICollectionViewCell()
{
}

void UICollectionViewCell::InitFromXIB(XIBObject *obj)
{
    UICollectionReusableView::InitFromXIB(obj);

    obj->_outputClassName = "UICollectionViewCell";
    _contentView = (UIView *)obj->FindMember("IBUIContentView");
}

void UICollectionViewCell::InitFromStory(XIBObject *obj)
{
    UICollectionReusableView::InitFromStory(obj);

    obj->_outputClassName = "UICollectionViewCell";
    _contentView = (UIView *)obj->FindMember("contentView");
}

void UICollectionViewCell::Awaken()
{
    UICollectionReusableView::Awaken();
    if (_contentView) {
        _contentView->_clipsToBounds = false;
        _contentView->_backgroundColor = NULL;
        _contentView->_contentMode = 0;
        _contentView->_multipleTouchEnabled = false;
    }
}

void UICollectionViewCell::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    writer->_allUIObjects->AddMember(NULL, this);
    if (_contentView) {
        _contentView->setFrame(getFrame());
        _contentView->_opaque = true;
        int count = _contentView->_subviews->count();
        for (int i = 0; i < count; i++) {
            UIView *curObj = (UIView *)_contentView->_subviews->objectAtIndex(i);
            //curObj->_bounds.height  = _contentView->_bounds.height;
            writer->_allUIObjects->AddMember(NULL, curObj);
        }
        _contentView->_ignoreUIObject = true;
    }

    UICollectionReusableView::ConvertStaticMappings(writer, obj);

    if (_contentView) {
        _contentView->_outputClassName = "UICollectionViewCellContentView";
        obj->AddOutputMember(writer, "UIContentView", _contentView);
    }
}

ObjectConverter *UICollectionViewCell::Clone()
{
    return new UICollectionViewCell();
}
