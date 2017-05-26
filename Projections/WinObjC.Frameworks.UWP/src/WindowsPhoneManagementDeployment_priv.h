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

// WindowsPhoneManagementDeployment_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsManagementDeployment_priv.h"
#include "WindowsApplicationModel_priv.h"
ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics> WPMDIInstallationManagerStatics_inst();
ComPtr<ABI::Windows::Phone::Management::Deployment::IInstallationManagerStatics2> WPMDIInstallationManagerStatics2_inst();
ComPtr<ABI::Windows::Phone::Management::Deployment::IEnterpriseEnrollmentManager> WPMDIEnterpriseEnrollmentManager_inst();

id RTProxiedIterableNSArray_WAPackage_create(IInspectable* val);
id RTProxiedIterableNSArray_WFUri_create(IInspectable* val);
id RTProxiedNSArray_WPMDEnterprise_create(IInspectable* val);

@class RTProxiedIterableNSArray_WAPackage, RTProxiedIterableNSArray_WFUri, RTProxiedNSArray_WPMDEnterprise;
