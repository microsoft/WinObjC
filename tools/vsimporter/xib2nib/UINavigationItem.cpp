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

#include "UINavigationItem.h"
#include "UINavigationBar.h"

UINavigationItem::UINavigationItem()
{
    _title = NULL;
    _leftBarButtonItem = NULL;
    _navigationBar = NULL;
}

void UINavigationItem::InitFromXIB(XIBObject *obj)
{
    ObjectConverterSwapper::InitFromXIB(obj);
    _title = GetString("IBUITitle", NULL);
    _leftBarButtonItem = FindMember("IBUILeftBarButtonItem");
    _navigationBar = (UINavigationBar *) FindMember("IBUINavigationBar");

    obj->_outputClassName = "UINavigationItem";
}

void UINavigationItem::InitFromStory(XIBObject *obj)
{
    ObjectConverterSwapper::InitFromStory(obj);
    _title = obj->getAttrib("title");
    _leftBarButtonItem = obj->FindMember("leftBarButtonItem");

    obj->_outputClassName = "UINavigationItem";
}

void UINavigationItem::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    ObjectConverterSwapper::ConvertStaticMappings(writer, obj);

    if ( _title ) AddString(writer, "UITitle", _title);
    if ( _leftBarButtonItem ) AddOutputMember(writer, "UILeftBarButtonItem", _leftBarButtonItem);

    XIBArray *leftItems = new XIBArray();
    if ( _leftBarButtonItem ) {
        leftItems->AddMember(NULL, _leftBarButtonItem);
        obj->AddOutputMember(writer, "UILeftBarButtonItems", leftItems);    
    }
    if ( _navigationBar ) AddOutputMember(writer, "UINavigationBar", _navigationBar);
}

