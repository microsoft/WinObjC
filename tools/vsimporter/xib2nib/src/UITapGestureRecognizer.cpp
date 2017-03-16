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

#include "UITapGestureRecognizer.h"

const int g_defaultNumberOfTapsRequired = 1;
const int g_defaultNumberOfTouchesRequired = 1;

UITapGestureRecognizer::UITapGestureRecognizer() {
    _numberOfTapsRequired = g_defaultNumberOfTapsRequired;
    _numberOfTouchesRequired = g_defaultNumberOfTouchesRequired;
}

void UITapGestureRecognizer::InitFromXIB(XIBObject* obj) {
    UIGestureRecognizer::InitFromXIB(obj);

    _outputClassName = "UITapGestureRecognizer";
}

void UITapGestureRecognizer::InitFromStory(XIBObject* obj) {
    UIGestureRecognizer::InitFromStory(obj);

    const char* numberOfTapsRequired = getAttrib("numberOfTapsRequired");
    if (numberOfTapsRequired) {
        _numberOfTapsRequired = strtol(numberOfTapsRequired, NULL, 10);
    }

    const char* numberOfTouchesRequired = getAttrib("numberOfTouchesRequired");
    if (numberOfTouchesRequired) {
        _numberOfTouchesRequired = strtol(numberOfTouchesRequired, NULL, 10);
    }

    _outputClassName = "UITapGestureRecognizer";
}

void UITapGestureRecognizer::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIGestureRecognizer::ConvertStaticMappings(writer, obj);

    if (_numberOfTapsRequired != g_defaultNumberOfTapsRequired) {
        AddInt(writer, "UITapGestureRecognizer.numberOfTapsRequired", _numberOfTapsRequired);
    }

    if (_numberOfTouchesRequired != g_defaultNumberOfTouchesRequired) {
        AddInt(writer, "UITapGestureRecognizer.numberOfTouchesRequired", _numberOfTouchesRequired);
    }
}
