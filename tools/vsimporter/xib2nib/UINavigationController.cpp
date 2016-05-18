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

#include "UINavigationController.h"
#include "UINavigationBar.h"
#include "UINavigationItem.h"
#include "UIToolbar.h"

UINavigationController::UINavigationController() {
    _navigationBar = NULL;
    _toolBar = NULL;
}

void UINavigationController::InitFromXIB(XIBObject* obj) {
    UIViewController::InitFromXIB(obj);

    _navigationBar = (UINavigationBar*)FindMember("IBUINavigationBar");
    _toolBar = (UIToolbar*)FindMember("IBUIToolbar");

    _outputClassName = "UINavigationController";
}

void UINavigationController::InitFromStory(XIBObject* obj) {
    UIViewController::InitFromStory(obj);

    _navigationBar = (UINavigationBar*)FindMemberAndHandle("navigationBar");
    _outputClassName = "UINavigationController";
}

void UINavigationController::Awaken() {
    UIViewController::Awaken();

    if (_navigationBar) {
        _navigationBar->_delegate = this;
        _navigationBar->_autoresizingMask = UIViewAutoresizingFlexibleWidth;
    }
    if (_toolBar) {
        _toolBar->_autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleTopMargin;
    }
    for (int i = 0; i < _childViewControllers->count(); i++) {
        UIViewController* curController = (UIViewController*)_childViewControllers->objectAtIndex(i);

        if (curController->_navigationItem) {
            if (!_navigationBar->_items) {
                _navigationBar->_items = new XIBArray();
            }
            curController->_navigationItem->_navigationBar = _navigationBar;
            _navigationBar->_items->AddMember(NULL, curController->_navigationItem);
        }
    }
}

void UINavigationController::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIViewController::ConvertStaticMappings(writer, obj);

    if (_navigationBar)
        AddOutputMember(writer, "UINavigationBar", _navigationBar);
    if (_toolBar)
        AddOutputMember(writer, "UIToolbar", _toolBar);
}