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

// WindowsGamingInputCustom_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsGamingInput_priv.h"
ComPtr<ABI::Windows::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> WGICIGameControllerFactoryManagerStatics_inst();
@interface WGICGameControllerVersionInfo (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo*)internalStruct;
@end
inline WGICGameControllerVersionInfo* WGICGameControllerVersionInfo_create(
    ABI::Windows::Gaming::Input::Custom::GameControllerVersionInfo val) {
    return [WGICGameControllerVersionInfo createWith:val];
}
@interface WGICGipFirmwareUpdateProgress (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress*)internalStruct;
@end
inline WGICGipFirmwareUpdateProgress* WGICGipFirmwareUpdateProgress_create(
    ABI::Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress val) {
    return [WGICGipFirmwareUpdateProgress createWith:val];
}

id RTProxiedNSArray_C_UInt8_create(UINT32 size, uint8_t* val);

@class RTProxiedNSArray_C_UInt8;
