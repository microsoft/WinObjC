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

// WindowsGamingUI.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Gaming.UI.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGamingUI.h"
#include "WindowsGamingUI_priv.h"

@implementation WGUGameBar

ComPtr<ABI::Windows::Gaming::UI::IGameBarStatics> WGUIGameBarStatics_inst() {
    ComPtr<ABI::Windows::Gaming::UI::IGameBarStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.UI.GameBar").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addVisibilityChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_VisibilityChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeVisibilityChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_VisibilityChanged(token));
}

+ (EventRegistrationToken)addIsInputRedirectedChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_IsInputRedirectedChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeIsInputRedirectedChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_IsInputRedirectedChanged(token));
}

+ (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isInputRedirected {
    boolean unmarshalledReturn;
    auto _comInst = WGUIGameBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsInputRedirected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
