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

// WindowsDevicesPwm_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesPwmProvider_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics2> WDPIPwmControllerStatics2_inst();
ComPtr<ABI::Windows::Devices::Pwm::IPwmControllerStatics> WDPIPwmControllerStatics_inst();

id RTProxiedNSArray_WDPPwmController_create(IInspectable* val);

@class RTProxiedNSArray_WDPPwmController;
