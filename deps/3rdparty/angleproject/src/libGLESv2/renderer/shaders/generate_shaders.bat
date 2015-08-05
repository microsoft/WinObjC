@ECHO OFF
REM
REM Copyright (c) 2012 The ANGLE Project Authors. All rights reserved.
REM Use of this source code is governed by a BSD-style license that can be
REM found in the LICENSE file.
REM

PATH %PATH%;%DXSDK_DIR%\Utilities\bin\x86

fxc /E standardvs /T vs_2_0 /Fh compiled/standardvs.h Blit.vs
fxc /E flipyvs /T vs_2_0 /Fh compiled/flipyvs.h Blit.vs
fxc /E passthroughps /T ps_2_0 /Fh compiled/passthroughps.h Blit.ps
fxc /E luminanceps /T ps_2_0 /Fh compiled/luminanceps.h Blit.ps
fxc /E componentmaskps /T ps_2_0 /Fh compiled/componentmaskps.h Blit.ps

fxc /E VS_Passthrough /T vs_4_0 /Fh compiled/passthrough11vs.h Passthrough11.hlsl
fxc /E PS_PassthroughRGBA /T ps_4_0 /Fh compiled/passthroughrgba11ps.h Passthrough11.hlsl
fxc /E PS_PassthroughRGB /T ps_4_0 /Fh compiled/passthroughrgb11ps.h Passthrough11.hlsl
fxc /E PS_PassthroughLum /T ps_4_0 /Fh compiled/passthroughlum11ps.h Passthrough11.hlsl
fxc /E PS_PassthroughLumAlpha /T ps_4_0 /Fh compiled/passthroughlumalpha11ps.h Passthrough11.hlsl

fxc /E VS_Clear /T vs_4_0 /Fh compiled/clear11vs.h Clear11.hlsl
fxc /E PS_ClearSingle /T ps_4_0 /Fh compiled/clearsingle11ps.h Clear11.hlsl
fxc /E PS_ClearMultiple /T ps_4_0 /Fh compiled/clearmultiple11ps.h Clear11.hlsl

REM WinRT section
fxc /Gec /nologo /E standardvs /T vs_4_0_level_9_1 /Fh compiled/winrt/standardvs.h /Vn g_vs20_standardvs /Qstrip_reflect /Qstrip_debug Blit.vs
fxc /Gec /nologo /E flipyvs /T vs_4_0_level_9_1 /Fh compiled/winrt/flipyvs.h /Vn g_vs20_flipyvs /Qstrip_reflect /Qstrip_debug Blit.vs
fxc /Gec /nologo /E passthroughps /T ps_4_0_level_9_1 /Fh compiled/winrt/passthroughps.h /Vn g_ps20_passthroughps /Qstrip_reflect /Qstrip_debug Blit.ps
fxc /Gec /nologo /E luminanceps /T ps_4_0_level_9_1 /Fh compiled/winrt/luminanceps.h /Vn g_ps20_luminanceps /Qstrip_reflect /Qstrip_debug Blit.ps
fxc /Gec /nologo /E componentmaskps /T ps_4_0_level_9_1 /Fh compiled/winrt/componentmaskps.h /Vn g_ps20_componentmaskps /Qstrip_reflect /Qstrip_debug Blit.ps

fxc /Gec /nologo /E VS_Passthrough /T vs_4_0_level_9_1 /Fh compiled/winrt/passthrough11vs.h /Vn g_VS_Passthrough /Qstrip_reflect /Qstrip_debug Passthrough11.hlsl
fxc /Gec /nologo /E PS_PassthroughRGBA /T ps_4_0_level_9_1 /Fh compiled/winrt/passthroughrgba11ps.h /Vn g_PS_PassthroughRGBA /Qstrip_reflect /Qstrip_debug Passthrough11.hlsl
fxc /Gec /nologo /E PS_PassthroughRGB /T ps_4_0_level_9_1 /Fh compiled/winrt/passthroughrgb11ps.h /Vn g_PS_PassthroughRGB /Qstrip_reflect /Qstrip_debug Passthrough11.hlsl
fxc /Gec /nologo /E PS_PassthroughLum /T ps_4_0_level_9_1 /Fh compiled/winrt/passthroughlum11ps.h /Vn g_PS_PassthroughLum /Qstrip_reflect /Qstrip_debug Passthrough11.hlsl
fxc /Gec /nologo /E PS_PassthroughLumAlpha /T ps_4_0_level_9_1 /Fh compiled/winrt/passthroughlumalpha11ps.h /Vn g_PS_PassthroughLumAlpha /Qstrip_reflect /Qstrip_debug Passthrough11.hlsl

fxc /Gec /nologo /E VS_Clear /T vs_4_0_level_9_1 /Fh compiled/winrt/clear11vs.h /Vn g_VS_Clear /Qstrip_reflect /Qstrip_debug Clear11.hlsl
fxc /Gec /nologo /E PS_ClearSingle /T ps_4_0_level_9_1 /Fh compiled/winrt/clearsingle11ps.h /Vn g_PS_ClearSingle /Qstrip_reflect /Qstrip_debug Clear11.hlsl
fxc /Gec /nologo /E PS_ClearMultiple_winrt /T ps_4_0_level_9_1 /Fh compiled/winrt/clearmultiple11ps.h /Vn g_PS_ClearMultiple /Qstrip_reflect /Qstrip_debug Clear11.hlsl