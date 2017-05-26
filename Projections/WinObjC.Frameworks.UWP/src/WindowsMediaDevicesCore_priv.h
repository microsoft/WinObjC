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

// WindowsMediaDevicesCore_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsMediaMediaProperties_priv.h"
#include "WindowsFoundationNumerics_priv.h"
#include "WindowsPerceptionSpatial_priv.h"

id RTProxiedNSArray_C_WFNVector2_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector2* val);
id RTProxiedNSArray_C_WFNVector3_create(UINT32 size, ABI::Windows::Foundation::Numerics::Vector3* val);
id RTProxiedNSArray_C_WFPoint_create(UINT32 size, ABI::Windows::Foundation::Point* val);
id RTProxiedNSMutableArray_WMDCFrameController_create(IInspectable* val);

@class Nullable_Boolean, Nullable_Single, Nullable_UInt32, Nullable_WFTimeSpan, RTProxiedNSArray_C_WFNVector2,
    RTProxiedNSArray_C_WFNVector3;
@class RTProxiedNSArray_C_WFPoint, RTProxiedNSMutableArray_WMDCFrameController;
