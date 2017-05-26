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

// WindowsManagementDeploymentPreview.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Management.Deployment.Preview.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsManagementDeploymentPreview.h"
#include "WindowsManagementDeploymentPreview_priv.h"

@implementation WMDPInstalledClassicAppInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Deployment::Preview::IInstalledClassicAppInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::Preview::IInstalledClassicAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayVersion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Management::Deployment::Preview::IInstalledClassicAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayVersion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMDPClassicAppManager

ComPtr<ABI::Windows::Management::Deployment::Preview::IClassicAppManagerStatics> WMDPIClassicAppManagerStatics_inst() {
    ComPtr<ABI::Windows::Management::Deployment::Preview::IClassicAppManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Management.Deployment.Preview.ClassicAppManager").Get(), &inst));
    return inst;
}

+ (WMDPInstalledClassicAppInfo*)findInstalledApp:(NSString*)appUninstallKey {
    ComPtr<ABI::Windows::Management::Deployment::Preview::IInstalledClassicAppInfo> unmarshalledReturn;
    auto _comInst = WMDPIClassicAppManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindInstalledApp(nsStrToHstr(appUninstallKey).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMDPInstalledClassicAppInfo>(unmarshalledReturn.Get());
}

@end
