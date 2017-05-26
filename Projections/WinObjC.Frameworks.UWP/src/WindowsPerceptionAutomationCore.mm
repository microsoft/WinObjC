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

// WindowsPerceptionAutomationCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Perception.Automation.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPerceptionAutomationCore.h"
#include "WindowsPerceptionAutomationCore_priv.h"

@implementation WPACCorePerceptionAutomation

ComPtr<ABI::Windows::Perception::Automation::Core::ICorePerceptionAutomationStatics> WPACICorePerceptionAutomationStatics_inst() {
    ComPtr<ABI::Windows::Perception::Automation::Core::ICorePerceptionAutomationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Perception.Automation.Core.CorePerceptionAutomation").Get(), &inst));
    return inst;
}

+ (void)setActivationFactoryProvider:(RTObject<WFIGetActivationFactory>*)provider {
    auto _comInst = WPACICorePerceptionAutomationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetActivationFactoryProvider(_getRtInterface<ABI::Windows::Foundation::IGetActivationFactory>(provider).Get()));
}

@end
