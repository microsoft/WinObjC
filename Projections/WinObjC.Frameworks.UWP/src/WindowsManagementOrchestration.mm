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

// WindowsManagementOrchestration.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Management.Orchestration.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsManagementOrchestration.h"
#include "WindowsManagementOrchestration_priv.h"

@implementation WMOCurrentAppOrchestration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Orchestration::ICurrentAppOrchestration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Management::Orchestration::ICurrentAppOrchestrationStatics> WMOICurrentAppOrchestrationStatics_inst() {
    ComPtr<ABI::Windows::Management::Orchestration::ICurrentAppOrchestrationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Management.Orchestration.CurrentAppOrchestration").Get(), &inst));
    return inst;
}

+ (WMOCurrentAppOrchestration*)getForCurrentView {
    ComPtr<ABI::Windows::Management::Orchestration::ICurrentAppOrchestration> unmarshalledReturn;
    auto _comInst = WMOICurrentAppOrchestrationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMOCurrentAppOrchestration>(unmarshalledReturn.Get());
}

- (WMOSingleAppModeContext*)startSingleAppMode {
    ComPtr<ABI::Windows::Management::Orchestration::ISingleAppModeContext> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Orchestration::ICurrentAppOrchestration>(self);
    THROW_NS_IF_FAILED(_comInst->StartSingleAppMode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMOSingleAppModeContext>(unmarshalledReturn.Get());
}

@end

@implementation WMOSingleAppModeContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Orchestration::ISingleAppModeContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end
