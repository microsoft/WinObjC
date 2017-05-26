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

// WindowsDevicesSpi_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesSpiProvider_priv.h"
#include "WindowsFoundation_priv.h"
static ComPtr<ABI::Windows::Devices::Spi::ISpiConnectionSettingsFactory> WDSISpiConnectionSettingsFactory_inst();
ComPtr<ABI::Windows::Devices::Spi::ISpiDeviceStatics> WDSISpiDeviceStatics_inst();
ComPtr<ABI::Windows::Devices::Spi::ISpiControllerStatics> WDSISpiControllerStatics_inst();

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);
id RTProxiedNSArray_Int32_create(IInspectable* val);
id RTProxiedNSArray_WDSSpiController_create(IInspectable* val);

@class RTProxiedNSArray_C_UInt8, RTProxiedNSArray_Int32, RTProxiedNSArray_WDSSpiController;
