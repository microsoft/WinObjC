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

#include "UIPanGestureRecognizer.h"

const int g_defaultMinimumNumberOfTouches = 1;
const int g_defaultMaximumNumberOfTouches = -1;

UIPanGestureRecognizer::UIPanGestureRecognizer() {
    _minimumNumberOfTouches = g_defaultMinimumNumberOfTouches;
    _maximumNumberOfTouches = g_defaultMaximumNumberOfTouches;
}

void UIPanGestureRecognizer::InitFromXIB(XIBObject* obj) {
    UIGestureRecognizer::InitFromXIB(obj);

    _outputClassName = "UIPanGestureRecognizer";
}

void UIPanGestureRecognizer::InitFromStory(XIBObject* obj) {
    UIGestureRecognizer::InitFromStory(obj);

    const char* minimumNumberOfTouches = getAttrib("minimumNumberOfTouches");
    if (minimumNumberOfTouches) {
        _minimumNumberOfTouches = strtol(minimumNumberOfTouches, NULL, 10);
    }

    const char* maximumNumberOfTouches = getAttrib("maximumNumberOfTouches");
    if (maximumNumberOfTouches) {
        _maximumNumberOfTouches = strtol(maximumNumberOfTouches, NULL, 10);
    }

    _outputClassName = "UIPanGestureRecognizer";
}

void UIPanGestureRecognizer::ConvertStaticMappings(NIBWriter* writer, XIBObject* obj) {
    UIGestureRecognizer::ConvertStaticMappings(writer, obj);

    if (_minimumNumberOfTouches != g_defaultMinimumNumberOfTouches && _minimumNumberOfTouches > 0) {
        AddInt(writer, "UIPanGestureRecognizer.minimumNumberOfTouches", _minimumNumberOfTouches);
    }

    if (_maximumNumberOfTouches != g_defaultMaximumNumberOfTouches && _maximumNumberOfTouches > 0) {
        AddInt(writer, "UIPanGestureRecognizer.maximumNumberOfTouches", _maximumNumberOfTouches);
    }
}
