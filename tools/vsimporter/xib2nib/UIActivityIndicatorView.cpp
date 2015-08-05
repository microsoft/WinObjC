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

#include "UIActivityIndicatorView.h"
#include "UIColor.h"

UIActivityIndicatorView::UIActivityIndicatorView()
{
    _style = 0;
    _animating = false;
    _tintColor = NULL;
}

void UIActivityIndicatorView::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    _outputClassName = "UIActivityIndicatorView";
    _animating = obj->GetBool("IBUIAnimating", false);
    _style = obj->GetInt("IBUIStyle", 0);
}

void UIActivityIndicatorView::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);

    _outputClassName = "UIActivityIndicatorView";
}

void UIActivityIndicatorView::Awaken()
{
    UIView::Awaken();

    switch ( _style ) {
        case 2:
            _tintColor = new UIColor(4, 4, 1.0f, 0.0f, 0.0f, 0.0f, "whiteColor");
            break;
    }
}

void UIActivityIndicatorView::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    UIView::ConvertStaticMappings(writer, obj);
    if ( _style ) AddInt(writer, "UIActivityIndicatorViewStyle", _style);
    if ( _animating ) AddBool(writer, "UIAnimating", _animating);
    if ( _tintColor ) AddOutputMember(writer, "UITintColor", _tintColor);
}

