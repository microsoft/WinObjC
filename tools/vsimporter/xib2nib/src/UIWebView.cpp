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

#include "UIWebView.h"

UIWebView::UIWebView() {
    _delegate = new XIBObjectNil();
    _scalesPageToFit = false;
    _dataDetectorTypes = 0;
}

void UIWebView::InitFromXIB(XIBObject* obj) {
    UIView::InitFromXIB(obj);
    _scalesPageToFit = obj->GetBool("IBUIScalesPageToFit", false);
    _dataDetectorTypes = obj->GetInt("IBUIDataDetectorTypes", 0);

    _outputClassName = "UIWebView";
}

void UIWebView::InitFromStory(XIBObject* obj) {
    UIView::InitFromStory(obj);

    _outputClassName = "UIWebView";
}

void UIWebView::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIView::ConvertStaticMappings(writer, obj);
    AddOutputMember(writer, "UIDelegate", _delegate);
    if (_scalesPageToFit)
        AddBool(writer, "UIScalesPageToFit", _scalesPageToFit);
    if (_dataDetectorTypes)
        AddInt(writer, "UIDataDetectorTypes", _dataDetectorTypes);
}
