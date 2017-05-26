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

// WindowsMediaEditing_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsMediaEffects_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsMediaCore_priv.h"
#include "WindowsGraphicsImaging_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaTranscoding_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsGraphicsDirectXDirect3D11_priv.h"
static ComPtr<ABI::Windows::Media::Editing::IMediaOverlayFactory> WMEIMediaOverlayFactory_inst();
ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics> WMEIMediaClipStatics_inst();
ComPtr<ABI::Windows::Media::Editing::IMediaClipStatics2> WMEIMediaClipStatics2_inst();
ComPtr<ABI::Windows::Media::Editing::IBackgroundAudioTrackStatics> WMEIBackgroundAudioTrackStatics_inst();
ComPtr<ABI::Windows::Media::Editing::IMediaCompositionStatics> WMEIMediaCompositionStatics_inst();
static ComPtr<ABI::Windows::Media::Editing::IMediaOverlayLayerFactory> WMEIMediaOverlayLayerFactory_inst();

id RTProxiedIterableNSArray_WFTimeSpan_create(IInspectable* val);
id RTProxiedNSArray_WGIImageStream_create(IInspectable* val);
id RTProxiedNSArray_WMEEmbeddedAudioTrack_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WMEIVideoEffectDefinition_create(IInspectable* val);
id RTProxiedNSMutableArray_WMEBackgroundAudioTrack_create(IInspectable* val);
id RTProxiedNSMutableArray_WMEMediaClip_create(IInspectable* val);
id RTProxiedNSMutableArray_WMEMediaOverlay_create(IInspectable* val);
id RTProxiedNSMutableArray_WMEMediaOverlayLayer_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_NSString_create(IInspectable* val);

@class RTProxiedIterableNSArray_WFTimeSpan, RTProxiedNSArray_WGIImageStream, RTProxiedNSArray_WMEEmbeddedAudioTrack,
    RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition;
@class RTProxiedNSMutableArray_RTObject_WMEIVideoEffectDefinition, RTProxiedNSMutableArray_WMEBackgroundAudioTrack,
    RTProxiedNSMutableArray_WMEMediaClip;
@class RTProxiedNSMutableArray_WMEMediaOverlay, RTProxiedNSMutableArray_WMEMediaOverlayLayer,
    RTProxiedNSMutableDictionary_NSString_NSString;
