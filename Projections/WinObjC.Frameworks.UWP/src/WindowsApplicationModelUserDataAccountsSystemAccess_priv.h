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

// WindowsApplicationModelUserDataAccountsSystemAccess_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsSecurityCredentials_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics2>
WAUSIUserDataAccountSystemAccessManagerStatics2_inst();
ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::SystemAccess::IUserDataAccountSystemAccessManagerStatics>
WAUSIUserDataAccountSystemAccessManagerStatics_inst();

id RTProxiedIterableNSArray_WAUSDeviceAccountConfiguration_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_WAUSDeviceAccountConfiguration, RTProxiedNSArray_NSString;
