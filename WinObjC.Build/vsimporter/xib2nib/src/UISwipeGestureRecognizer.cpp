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

#include "UISwipeGestureRecognizer.h"

const UISwipeGestureRecognizerDirection g_defaultDirection = UISwipeGestureRecognizerDirectionRight;
const int g_defaultNumberOfTouchesRequired = 1;

UISwipeGestureRecognizer::UISwipeGestureRecognizer() {
    _direction = g_defaultDirection;
    _numberOfTouchesRequired = g_defaultNumberOfTouchesRequired;
}

void UISwipeGestureRecognizer::InitFromXIB(XIBObject* obj) {
    UIGestureRecognizer::InitFromXIB(obj);

    _outputClassName = "UISwipeGestureRecognizer";
}

void UISwipeGestureRecognizer::InitFromStory(XIBObject* obj) {
    UIGestureRecognizer::InitFromStory(obj);

    const char* direction = getAttrib("direction");
    if (direction) {
        if (strcmp(direction, "left") == 0) {
            _direction = UISwipeGestureRecognizerDirectionLeft;
        } else if (strcmp(direction, "up") == 0) {
            _direction = UISwipeGestureRecognizerDirectionUp;
        } else if (strcmp(direction, "down") == 0) {
            _direction = UISwipeGestureRecognizerDirectionDown;
        } else if (strcmp(direction, "right") == 0) {
            _direction = UISwipeGestureRecognizerDirectionRight;
        }
    }

    const char* numberOfTouchesRequired = getAttrib("numberOfTouchesRequired");
    if (numberOfTouchesRequired) {
        _numberOfTouchesRequired = strtol(numberOfTouchesRequired, NULL, 10);
    }

    _outputClassName = "UISwipeGestureRecognizer";
}

void UISwipeGestureRecognizer::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIGestureRecognizer::ConvertStaticMappings(writer, obj);

    if (_direction != g_defaultDirection) {
        AddInt(writer, "UISwipeGestureRecognizer.direction", _direction);
    }

    if (_numberOfTouchesRequired != g_defaultNumberOfTouchesRequired) {
        AddInt(writer, "UISwipeGestureRecognizer.numberOfTouchesRequired", _numberOfTouchesRequired);
    }
}
