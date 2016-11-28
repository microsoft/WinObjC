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

UIWindow::UIWindow()
{
    _visibleAtLaunch = false;
    _resizesToFullScreen = false;
}

void UIWindow::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    _visibleAtLaunch = obj->GetBool("IBUIVisibleAtLaunch", false);
    _resizesToFullScreen = obj->GetBool("IBUIResizesToFullScreen", false);

    _outputClassName = "UIWindow";
}

void UIWindow::InitFromStory(XIBObject* obj)
{
    UIView::InitFromStory(obj);

    const char* visibleAtLaunchAttrib = getAttrib("visibleAtLaunch");
    if (visibleAtLaunchAttrib && strcmp(visibleAtLaunchAttrib, "YES") == 0) {
        _visibleAtLaunch = true;
    }

    const char* resizeToFullScreenAttrib = getAttrib("resizesToFullScreen");
    if (resizeToFullScreenAttrib && strcmp(resizeToFullScreenAttrib, "YES") == 0) {
        _resizesToFullScreen = true;
    }

    _outputClassName = "UIWindow";
}

void UIWindow::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    UIView::ConvertStaticMappings(writer, obj);

    // NOTE: There is difficulty confirming these keys are correct - NIB files generated were not conclusive in confirming these
    // keys under the unarchiver
    if (_visibleAtLaunch) {
        writer->_visibleWindows->AddMember(NULL, this);
        AddBool(writer, "UIVisibleAtLaunch", _visibleAtLaunch);
    }

    if (_resizesToFullScreen) {
        AddBool(writer, "UIResizesToFullScreen", _resizesToFullScreen);
    }
}
