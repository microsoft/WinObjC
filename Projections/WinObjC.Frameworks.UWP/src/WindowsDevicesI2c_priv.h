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

// WindowsDevicesI2c_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesI2cProvider_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::I2c::II2cConnectionSettingsFactory> WDIII2cConnectionSettingsFactory_inst();
ComPtr<ABI::Windows::Devices::I2c::II2cDeviceStatics> WDIII2cDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::I2c::II2cControllerStatics> WDIII2cControllerStatics_inst();
@interface WDII2cTransferResult (Internal)
+ (instancetype)createWith:(ABI::Windows::Devices::I2c::I2cTransferResult)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Devices::I2c::I2cTransferResult*)internalStruct;
@end
inline WDII2cTransferResult* WDII2cTransferResult_create(ABI::Windows::Devices::I2c::I2cTransferResult val) {
    return [WDII2cTransferResult createWith:val];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_WDII2cController_create(IInspectable* val);

@class RTProxiedNSArray_C_UInt8, RTProxiedNSArray_WDII2cController;
