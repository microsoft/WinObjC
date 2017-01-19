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

#include "UITabBarItem.h"
#include "UICustomResource.h"

UITabBarItem::UITabBarItem() {
    _title = NULL;
    _enabled = true;
    _image = NULL;
    _tag = -1;
}

void UITabBarItem::InitFromXIB(XIBObject* obj) {
    ObjectConverterSwapper::InitFromXIB(obj);

    _enabled = true;
    _title = obj->GetString("IBUITitle", NULL);
    _image = obj->FindMember("IBUIImage");
    _tag = obj->GetInt("IBUITag", -1);

    obj->_outputClassName = "UITabBarItem";
}

void UITabBarItem::InitFromStory(XIBObject* obj) {
    ObjectConverterSwapper::InitFromStory(obj);

    _title = getAttrAndHandle("title");
    _enabled = true;

    const char* imageName = getAttrAndHandle("image");
    if (imageName) {
        UICustomResource* image = new UICustomResource();
        image->_imageName = imageName;
        _image = image;
    }

    obj->_outputClassName = "UITabBarItem";
}

void UITabBarItem::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    ObjectConverterSwapper::ConvertStaticMappings(writer, obj);

    AddBool(writer, "UIEnabled", _enabled);
    if (_title)
        AddString(writer, "UITitle", _title);
    if (_image)
        AddOutputMember(writer, "UIImage", _image);
    if (_tag != -1)
        AddInt(writer, "UITag", _tag);
}
