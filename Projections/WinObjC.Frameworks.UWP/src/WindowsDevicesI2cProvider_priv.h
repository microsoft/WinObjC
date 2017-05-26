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

// WindowsDevicesI2cProvider_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
@interface WDIPProviderI2cTransferResult (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult*)internalStruct;
@end
inline WDIPProviderI2cTransferResult* WDIPProviderI2cTransferResult_create(
    ABI::Windows::Devices::I2c::Provider::ProviderI2cTransferResult val) {
    return [WDIPProviderI2cTransferResult createWith:val];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_RTObject_WDIPII2cControllerProvider_create(IInspectable* val);

@class RTProxiedNSArray_C_UInt8, RTProxiedNSArray_RTObject_WDIPII2cControllerProvider;
