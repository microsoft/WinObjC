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

#include "UITabBarController.h"
#include "UITabBar.h"
#include "UITabBarItem.h"

UITabBarController::UITabBarController() {
    _customizableViewControllers = NULL;
    _tabBar = NULL;
    _navigationItem = NULL;
}

void UITabBarController::InitFromXIB(XIBObject* obj) {
    UIViewController::InitFromXIB(obj);

    _tabBar = (UITabBar*)obj->FindMember("IBUITabBar");
    if (_tabBar) {
        _tabBar->_delegate = this;
    }
    if (_childViewControllers) {
        for (int curIdx = 0; curIdx < _childViewControllers->count(); curIdx++) {
            XIBObject* curChild = _childViewControllers->objectAtIndex(curIdx);

            if (_customizableViewControllers == NULL) {
                _customizableViewControllers = new XIBArray();
                _customizableViewControllers->_className = "NSMutableArray";
            }

            _customizableViewControllers->AddMember(NULL, curChild);
        }
    }
    _outputClassName = "UITabBarController";
}

void UITabBarController::InitFromStory(XIBObject* obj) {
    UIViewController::InitFromStory(obj);

    _tabBar = (UITabBar*)obj->FindMemberAndHandle("tabBar");
    if (_tabBar) {
        _tabBar->_delegate = this;
    }

    if (_childViewControllers) {
        for (int curIdx = 0; curIdx < _childViewControllers->count(); curIdx++) {
            XIBObject* curChild = _childViewControllers->objectAtIndex(curIdx);

            if (_customizableViewControllers == NULL) {
                _customizableViewControllers = new XIBArray();
                _customizableViewControllers->_className = "NSMutableArray";
            }

            _customizableViewControllers->AddMember(NULL, curChild);
        }
    }
    _outputClassName = "UITabBarController";
}

void UITabBarController::Awaken() {
    UIViewController::Awaken();

    float tabHeight = 0.0f;

    if (_tabBar) {
        UIRect curFrame = _tabBar->getFrame();
        curFrame.y = screenHeight - curFrame.height;
        curFrame.width = screenWidth;
        _tabBar->setFrame(curFrame);
        tabHeight = _tabBar->getFrame().height;
    }

    if (_childViewControllers) {
        for (int curIdx = 0; curIdx < _childViewControllers->count(); curIdx++) {
            UIViewController* curChild = (UIViewController*)_childViewControllers->objectAtIndex(curIdx);

            if (curChild->_view) {
                UIRect curRect = curChild->_view->getFrame();

                curRect.y = 0;
                curRect.height = screenHeight - tabHeight;
                curChild->_view->setFrame(curRect);
            }

            if (curChild->_tabBarItem) {
                if (!_tabBar->_items) {
                    _tabBar->_items = new XIBArray();
                }
                _tabBar->_items->AddMember(NULL, curChild->_tabBarItem);
            }
        }
    }
}

void UITabBarController::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIViewController::ConvertStaticMappings(writer, obj);
    if (_tabBar)
        AddOutputMember(writer, "UITabBar", _tabBar);
    if (_customizableViewControllers) {
        AddOutputMember(writer, "UICustomizableViewControllers", _customizableViewControllers);
    }
}