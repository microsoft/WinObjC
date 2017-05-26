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

// WindowsStorageFileProperties_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorageStreams_priv.h"
#include "WindowsStorage_priv.h"
#include "WindowsDevicesGeolocation_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Storage::FileProperties::IGeotagHelperStatics> WSFIGeotagHelperStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_RTObject_create(IInspectable* val);
id RTProxiedKeyValuePair_NSString_RTObject_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableDictionary_NSString_RTObject_create(IInspectable* val);

@class Nullable_Double, RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_RTProxiedKeyValuePair_NSString_RTObject,
    RTProxiedKeyValuePair_NSString_RTObject;
@class RTProxiedNSArray_NSString, RTProxiedNSMutableArray_NSString, RTProxiedNSMutableDictionary_NSString_RTObject;

typedef IKeyValuePair<HSTRING, IInspectable*>* IKeyValuePair_HSTRING_IInspectablePtr_Ptr;
