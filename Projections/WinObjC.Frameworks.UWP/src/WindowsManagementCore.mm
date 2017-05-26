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

// WindowsManagementCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Management.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsManagementCore.h"
#include "WindowsManagementCore_priv.h"

@implementation WMCApplicationDataManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Management::Core::IApplicationDataManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Management::Core::IApplicationDataManagerStatics> WMCIApplicationDataManagerStatics_inst() {
    ComPtr<ABI::Windows::Management::Core::IApplicationDataManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Management.Core.ApplicationDataManager").Get(),
                                                       &inst));
    return inst;
}

+ (WSApplicationData*)createForPackageFamily:(NSString*)packageFamilyName {
    ComPtr<ABI::Windows::Storage::IApplicationData> unmarshalledReturn;
    auto _comInst = WMCIApplicationDataManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateForPackageFamily(nsStrToHstr(packageFamilyName).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSApplicationData>(unmarshalledReturn.Get());
}

@end
