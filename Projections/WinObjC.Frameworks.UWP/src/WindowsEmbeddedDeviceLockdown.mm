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

// WindowsEmbeddedDeviceLockdown.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Embedded.DeviceLockdown.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsEmbeddedDeviceLockdown.h"
#include "WindowsEmbeddedDeviceLockdown_priv.h"

@implementation WEDDeviceLockdownProfileInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileInformation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WEDDeviceLockdownProfile

ComPtr<ABI::Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileStatics> WEDIDeviceLockdownProfileStatics_inst() {
    ComPtr<ABI::Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Embedded.DeviceLockdown.DeviceLockdownProfile").Get(), &inst));
    return inst;
}

+ (NSArray* /* WFGUID* */)getSupportedLockdownProfiles {
    ComPtr<IVectorView<GUID>> unmarshalledReturn;
    auto _comInst = WEDIDeviceLockdownProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetSupportedLockdownProfiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WFGUID_create(unmarshalledReturn.Get());
}

+ (WFGUID*)getCurrentLockdownProfile {
    GUID unmarshalledReturn;
    auto _comInst = WEDIDeviceLockdownProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentLockdownProfile(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

+ (RTObject<WFIAsyncAction>*)applyLockdownProfileAsync:(WFGUID*)profileID {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WEDIDeviceLockdownProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ApplyLockdownProfileAsync(profileID.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (WEDDeviceLockdownProfileInformation*)getLockdownProfileInformation:(WFGUID*)profileID {
    ComPtr<ABI::Windows::Embedded::DeviceLockdown::IDeviceLockdownProfileInformation> unmarshalledReturn;
    auto _comInst = WEDIDeviceLockdownProfileStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLockdownProfileInformation(profileID.guidValue, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WEDDeviceLockdownProfileInformation>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WFGUID_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<GUID>, RTArrayObj<GUID, IVectorView<GUID>, WFGUID, GUID, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
