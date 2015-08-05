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

#include "UIControl.h"

UIControl::UIControl()
{
    _contentVerticalAlignment = 1;
    _contentHorizontalAlignment = 1;
}

void UIControl::InitFromXIB(XIBObject *obj)
{
    UIView::InitFromXIB(obj);

    _contentVerticalAlignment = GetInt("IBUIContentVerticalAlignment", 1);
    _contentHorizontalAlignment = GetInt("IBUIContentHorizontalAlignment", 1);

    _outputClassName = "UIControl";
}

void UIControl::InitFromStory(XIBObject *obj)
{
    UIView::InitFromStory(obj);
    _outputClassName = "UIControl";
}

void UIControl::ConvertStaticMappings(NIBWriter *writer, XIBObject *obj)
{
    UIView::ConvertStaticMappings(writer, obj);

    if ( _contentVerticalAlignment != 1 ) AddInt(writer, "UIContentVerticalAlignment", _contentVerticalAlignment);
    if ( _contentHorizontalAlignment != 1 ) AddInt(writer, "UIContentHorizontalAlignment", _contentHorizontalAlignment);
}
