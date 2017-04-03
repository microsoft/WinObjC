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

#import <UIKit/UITouch.h>
#import "CppWinRTHelpers.h"

#include "COMIncludes.h"
#import <winrt/Windows.UI.Input.h>
#import <winrt/Windows.UI.Xaml.Input.h>
#include "COMIncludes_End.h"

@interface UITouch () {
@public
    // Adding a WUXIPointerRoutedEventArgs property so that we can mark the routed event as handled/not handled
    // when touchsBegan:withEvent method is called.
    TrivialDefaultConstructor<winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs> _routedEventArgs;
    NSTimeInterval _timestamp;
    float _touchX, _touchY;
    float _previousTouchX, _previousTouchY;
    unsigned _tapCount;
    UITouchPhase _phase;
    StrongId<UIView> _view;
    TrivialDefaultConstructor<winrt::Windows::UI::Input::PointerPoint> _pointerPoint;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // TODO: This manual velocity tracking shouldn't be necessary once we move to WinRT Pan gesture recognition.
    float _velocityX, _velocityY;
}

+ (UITouch*)_createWithPoint:(CGPoint)point;
- (void)_updateWithPoint:(const winrt::Windows::UI::Input::PointerPoint&)pointerPoint
         routedEventArgs:(const winrt::Windows::UI::Xaml::Input::PointerRoutedEventArgs&)routedEventArgs
                forPhase:(UITouchPhase)touchPhase;
@end
