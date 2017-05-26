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

// MicrosoftAdvertisingSharedWinRT_priv.h
// Forward decls for private object generation
#pragma once

#include "MicrosoftAdvertising_priv.h"
static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdErrorEventArgsFactory> MASW__IAdErrorEventArgsFactory_inst();
static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdPlacementFactory> MASW__IAdPlacementFactory_inst();
static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdExtensionFactory> MASW__IAdExtensionFactory_inst();
static ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsFactory>
MASW__IProjectedMediaConstraintsFactory_inst();
ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IProjectedMediaConstraintsStatics> MASW__IProjectedMediaConstraintsStatics_inst();
ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IAdSchedulerStatics> MASW__IAdSchedulerStatics_inst();
ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__ISdkInfoProviderStatics> MASW__ISdkInfoProviderStatics_inst();
ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IEventLoggingStatics> MASW__IEventLoggingStatics_inst();
ComPtr<ABI::Microsoft::Advertising::Shared::WinRT::__IPlatformDependencyStatics> MASW__IPlatformDependencyStatics_inst();
@interface MASWSdkInfo (Internal)
+ (instancetype)createWith:(ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo)s __attribute__((ns_returns_autoreleased));
- (ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo*)internalStruct;
@end
inline MASWSdkInfo* MASWSdkInfo_create(ABI::Microsoft::Advertising::Shared::WinRT::SdkInfo val) {
    return [MASWSdkInfo createWith:val];
}

id RTProxiedNSArray_MASWAdExtension_create(IInspectable* val);
id RTProxiedNSArray_MASWAdPackage_create(IInspectable* val);
id RTProxiedNSArray_MASWAdPod_create(IInspectable* val);
id RTProxiedNSArray_MASWVideoResource_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedNSArray_MASWAdExtension, RTProxiedNSArray_MASWAdPackage, RTProxiedNSArray_MASWAdPod, RTProxiedNSArray_MASWVideoResource;
@class RTProxiedNSArray_NSString, RTProxiedNSDictionary_NSString_NSString, RTProxiedNSDictionary_NSString_RTObject,
    RTProxiedNSMutableDictionary_NSString_NSString;
