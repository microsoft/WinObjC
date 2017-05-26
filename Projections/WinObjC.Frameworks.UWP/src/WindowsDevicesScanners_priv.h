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

// WindowsDevicesScanners_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGraphicsPrinting_priv.h"
#include "WindowsStorage_priv.h"
ComPtr<ABI::Windows::Devices::Scanners::IImageScannerStatics> WDSIImageScannerStatics_inst();
@interface WDSImageScannerResolution (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::Scanners::ImageScannerResolution)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::Scanners::ImageScannerResolution*)internalStruct;
@end
inline WDSImageScannerResolution* WDSImageScannerResolution_create(ABI::Windows::Devices::Scanners::ImageScannerResolution val) {
    return [WDSImageScannerResolution createWith:val];
}

id RTProxiedNSArray_WSStorageFile_create(IInspectable* val);

@class RTProxiedNSArray_WSStorageFile;
