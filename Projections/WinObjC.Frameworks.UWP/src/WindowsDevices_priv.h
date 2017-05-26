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

// WindowsDevices_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesGpioProvider_priv.h"
#include "WindowsDevicesAdcProvider_priv.h"
#include "WindowsDevicesSpiProvider_priv.h"
#include "WindowsDevicesPwmProvider_priv.h"
#include "WindowsDevicesI2cProvider_priv.h"
static ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProviderFactory> WDILowLevelDevicesAggregateProviderFactory_inst();
ComPtr<ABI::Windows::Devices::ILowLevelDevicesControllerStatics> WDILowLevelDevicesControllerStatics_inst();
