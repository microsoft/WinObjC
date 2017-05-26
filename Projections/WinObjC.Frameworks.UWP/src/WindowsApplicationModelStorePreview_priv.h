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

// WindowsApplicationModelStorePreview_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStorePreview> WASPIStorePreview_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics> WASPIStoreConfigurationStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics3> WASPIStoreConfigurationStatics3_inst();
ComPtr<ABI::Windows::ApplicationModel::Store::Preview::IStoreConfigurationStatics2> WASPIStoreConfigurationStatics2_inst();

id RTProxiedIterableNSArray_WASPStoreSystemFeature_create(IInspectable* val);
id RTProxiedNSArray_WASPStorePreviewProductInfo_create(IInspectable* val);
id RTProxiedNSArray_WASPStorePreviewSkuInfo_create(IInspectable* val);
id RTProxiedNSArray_WASPStoreSystemFeature_create(IInspectable* val);

@class Nullable_UInt32, RTProxiedIterableNSArray_WASPStoreSystemFeature, RTProxiedNSArray_WASPStorePreviewProductInfo,
    RTProxiedNSArray_WASPStorePreviewSkuInfo;
@class RTProxiedNSArray_WASPStoreSystemFeature;
