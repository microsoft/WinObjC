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

// WindowsDevicesBluetoothRfcomm_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsDevicesBluetooth_priv.h"
#include "WindowsNetworkingSockets_priv.h"
#include "WindowsNetworking_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsDevicesEnumeration_priv.h"
ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics2> WDBRIRfcommDeviceServiceStatics2_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommDeviceServiceStatics> WDBRIRfcommDeviceServiceStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceIdStatics> WDBRIRfcommServiceIdStatics_inst();
ComPtr<ABI::Windows::Devices::Bluetooth::Rfcomm::IRfcommServiceProviderStatics> WDBRIRfcommServiceProviderStatics_inst();

id RTProxiedNSArray_WDBRRfcommDeviceService_create(IInspectable* val);
id RTProxiedNSDictionary_UInt32_RTObject_WSSIBuffer_create(IInspectable* val);
id RTProxiedNSMutableDictionary_UInt32_RTObject_WSSIBuffer_create(IInspectable* val);

@class RTProxiedNSArray_WDBRRfcommDeviceService, RTProxiedNSDictionary_UInt32_RTObject_WSSIBuffer,
    RTProxiedNSMutableDictionary_UInt32_RTObject_WSSIBuffer;
