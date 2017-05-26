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

// WindowsManagementDeployment_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsApplicationModel_priv.h"
@interface WMDDeploymentProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Management::Deployment::DeploymentProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Management::Deployment::DeploymentProgress*)internalStruct;
@end
inline WMDDeploymentProgress* WMDDeploymentProgress_create(ABI::Windows::Management::Deployment::DeploymentProgress val) {
    return [WMDDeploymentProgress createWith:val];
}

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WAPackage_create(IInspectable* val);
id RTProxiedIterableNSArray_WFUri_create(IInspectable* val);
id RTProxiedIterableNSArray_WMDPackageUserInformation_create(IInspectable* val);
id RTProxiedIterableNSArray_WMDPackageVolume_create(IInspectable* val);
id RTProxiedNSArray_WMDPackageVolume_create(IInspectable* val);
id RTProxiedNSMutableArray_WAPackage_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WAPackage, RTProxiedIterableNSArray_WFUri,
    RTProxiedIterableNSArray_WMDPackageUserInformation;
@class RTProxiedIterableNSArray_WMDPackageVolume, RTProxiedNSArray_WMDPackageVolume, RTProxiedNSMutableArray_WAPackage;
