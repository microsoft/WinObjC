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

// WindowsMediaSpeechSynthesis_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMedia_priv.h"
ComPtr<ABI::Windows::Media::SpeechSynthesis::IInstalledVoicesStatic> WMSIInstalledVoicesStatic_inst();

id RTProxiedNSArray_RTObject_WMIMediaMarker_create(IInspectable* val);
id RTProxiedNSArray_WMSVoiceInformation_create(IInspectable* val);

@class RTProxiedNSArray_RTObject_WMIMediaMarker, RTProxiedNSArray_WMSVoiceInformation;
