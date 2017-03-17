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

#pragma once
#include "UIView.h"

enum UIActivityIndicatorViewStyle {
    UIActivityIndicatorViewStyleInvalid = -1,
    UIActivityIndicatorViewStyleWhiteLarge = 0,
    UIActivityIndicatorViewStyleWhite = 1,
    UIActivityIndicatorViewStyleGray = 2,
};

class UIActivityIndicatorView : public UIView {
public:
    UIActivityIndicatorViewStyle _style;
    bool _animating;
    UIColor* _tintColor;
    UIRect _frame;
    UIActivityIndicatorView();

    virtual void Awaken();
    virtual void InitFromXIB(XIBObject* obj);
    virtual void InitFromStory(XIBObject* obj);
    virtual void ConvertStaticMappings(NIBWriter* writer, XIBObject* obj);
};
