//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsSystemDisplay.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.Display.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystemDisplay.h"
#include "WindowsSystemDisplay_priv.h"

@implementation WSDDisplayRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::Display::IDisplayRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.Display.DisplayRequest").Get(), &out));
    return [_createRtProxy<WSDDisplayRequest>(out.Get()) retain];
}

- (void)requestActive {
    auto _comInst = _getInnerInterface<ABI::Windows::System::Display::IDisplayRequest>(self);
    THROW_NS_IF_FAILED(_comInst->RequestActive());
}

- (void)requestRelease {
    auto _comInst = _getInnerInterface<ABI::Windows::System::Display::IDisplayRequest>(self);
    THROW_NS_IF_FAILED(_comInst->RequestRelease());
}

@end
