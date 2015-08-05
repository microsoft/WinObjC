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

#include "UIWindow.h"

static PropertyMapper propertyMappings[] = {
    "IBUIResizesToFullScreen", "UIResizesToFullScreen", NULL,
};
static const int numPropertyMappings = sizeof(propertyMappings) / sizeof(PropertyMapper);

UIWindow::UIWindow()
{
    _visibleAtLaunch = false;
}

void UIWindow::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);
    _visibleAtLaunch = obj->GetBool("IBUIVisibleAtLaunch", false);

    _outputClassName = "UIWindow";
}

void UIWindow::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    if ( _visibleAtLaunch ) writer->_visibleWindows->AddMember(NULL, this);
    Map(writer, obj, propertyMappings, numPropertyMappings);
    UIView::ConvertStaticMappings(writer, obj);
}
