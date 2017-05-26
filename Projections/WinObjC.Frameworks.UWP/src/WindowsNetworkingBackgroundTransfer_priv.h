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

// WindowsNetworkingBackgroundTransfer_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsApplicationModelBackground_priv.h"
#include "WindowsWeb_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsSecurityCredentials_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsUINotifications_priv.h"
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferGroupStatics> WNBIBackgroundTransferGroupStatics_inst();
static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferContentPartFactory>
WNBIBackgroundTransferContentPartFactory_inst();
static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderFactory> WNBIBackgroundDownloaderFactory_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderUserConsent> WNBIBackgroundDownloaderUserConsent_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods> WNBIBackgroundDownloaderStaticMethods_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundDownloaderStaticMethods2> WNBIBackgroundDownloaderStaticMethods2_inst();
static ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderFactory> WNBIBackgroundUploaderFactory_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods2> WNBIBackgroundUploaderStaticMethods2_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderStaticMethods> WNBIBackgroundUploaderStaticMethods_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundUploaderUserConsent> WNBIBackgroundUploaderUserConsent_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IBackgroundTransferErrorStaticMethods> WNBIBackgroundTransferErrorStaticMethods_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcher> WNBIContentPrefetcher_inst();
ComPtr<ABI::Windows::Networking::BackgroundTransfer::IContentPrefetcherTime> WNBIContentPrefetcherTime_inst();
@interface WNBBackgroundDownloadProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress*)internalStruct;
@end
inline WNBBackgroundDownloadProgress* WNBBackgroundDownloadProgress_create(
    ABI::Windows::Networking::BackgroundTransfer::BackgroundDownloadProgress val) {
    return [WNBBackgroundDownloadProgress createWith:val];
}
@interface WNBBackgroundUploadProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress*)internalStruct;
@end
inline WNBBackgroundUploadProgress* WNBBackgroundUploadProgress_create(
    ABI::Windows::Networking::BackgroundTransfer::BackgroundUploadProgress val) {
    return [WNBBackgroundUploadProgress createWith:val];
}

id RTProxiedIterableNSArray_WNBBackgroundTransferContentPart_create(IInspectable* val);
id RTProxiedIterableNSArray_WNBDownloadOperation_create(IInspectable* val);
id RTProxiedIterableNSArray_WNBUploadOperation_create(IInspectable* val);
id RTProxiedNSArray_WNBDownloadOperation_create(IInspectable* val);
id RTProxiedNSArray_WNBUploadOperation_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_WFUri_create(IInspectable* val);

@class Nullable_WFDateTime, RTProxiedIterableNSArray_WNBBackgroundTransferContentPart, RTProxiedIterableNSArray_WNBDownloadOperation;
@class RTProxiedIterableNSArray_WNBUploadOperation, RTProxiedNSArray_WNBDownloadOperation, RTProxiedNSArray_WNBUploadOperation,
    RTProxiedNSDictionary_NSString_NSString;
@class RTProxiedNSMutableArray_WFUri;
