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

#include "UITableViewController.h"

UITableViewController::UITableViewController() {
}

void UITableViewController::InitFromXIB(XIBObject* obj) {
    UIViewController::InitFromXIB(obj);

    _outputClassName = "UITableViewController";
}

void UITableViewController::InitFromStory(XIBObject* obj) {
    UIViewController::InitFromStory(obj);

    _outputClassName = "UITableViewController";
}

void UITableViewController::Awaken() {
    UIViewController::Awaken();

    UIRect frame = { 0, 0, 320, 416 };
    if (_view)
        _view->setFrame(frame);
}

void UITableViewController::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIViewController::ConvertStaticMappings(writer, obj);
}