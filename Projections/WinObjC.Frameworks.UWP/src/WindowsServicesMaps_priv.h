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

// WindowsServicesMaps_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics2> WSMIMapLocationFinderStatics2_inst();
ComPtr<ABI::Windows::Services::Maps::IMapLocationFinderStatics> WSMIMapLocationFinderStatics_inst();
ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics2> WSMIMapRouteFinderStatics2_inst();
ComPtr<ABI::Windows::Services::Maps::IMapRouteFinderStatics> WSMIMapRouteFinderStatics_inst();
ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics3> WSMIMapServiceStatics3_inst();
ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics> WSMIMapServiceStatics_inst();
ComPtr<ABI::Windows::Services::Maps::IMapServiceStatics2> WSMIMapServiceStatics2_inst();
ComPtr<ABI::Windows::Services::Maps::IMapManagerStatics> WSMIMapManagerStatics_inst();

id RTProxiedIterableNSArray_WDGGeopoint_create(IInspectable* val);
id RTProxiedNSArray_WSMMapLocation_create(IInspectable* val);
id RTProxiedNSArray_WSMMapRoute_create(IInspectable* val);
id RTProxiedNSArray_WSMMapRouteLeg_create(IInspectable* val);
id RTProxiedNSArray_WSMMapRouteManeuver_create(IInspectable* val);

@class Nullable_Double, RTProxiedIterableNSArray_WDGGeopoint, RTProxiedNSArray_WSMMapLocation, RTProxiedNSArray_WSMMapRoute,
    RTProxiedNSArray_WSMMapRouteLeg;
@class RTProxiedNSArray_WSMMapRouteManeuver;
