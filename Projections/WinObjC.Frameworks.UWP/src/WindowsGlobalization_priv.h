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

// WindowsGlobalization_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics3> WGICalendarIdentifiersStatics3_inst();
ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics2> WGICalendarIdentifiersStatics2_inst();
ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics> WGICalendarIdentifiersStatics_inst();
ComPtr<ABI::Windows::Globalization::IClockIdentifiersStatics> WGIClockIdentifiersStatics_inst();
ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics2> WGINumeralSystemIdentifiersStatics2_inst();
ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics> WGINumeralSystemIdentifiersStatics_inst();
ComPtr<ABI::Windows::Globalization::ICurrencyIdentifiersStatics> WGICurrencyIdentifiersStatics_inst();
static ComPtr<ABI::Windows::Globalization::IGeographicRegionFactory> WGIGeographicRegionFactory_inst();
ComPtr<ABI::Windows::Globalization::IGeographicRegionStatics> WGIGeographicRegionStatics_inst();
static ComPtr<ABI::Windows::Globalization::ILanguageFactory> WGILanguageFactory_inst();
ComPtr<ABI::Windows::Globalization::ILanguageStatics2> WGILanguageStatics2_inst();
ComPtr<ABI::Windows::Globalization::ILanguageStatics> WGILanguageStatics_inst();
static ComPtr<ABI::Windows::Globalization::ICalendarFactory2> WGICalendarFactory2_inst();
static ComPtr<ABI::Windows::Globalization::ICalendarFactory> WGICalendarFactory_inst();
ComPtr<ABI::Windows::Globalization::IApplicationLanguagesStatics> WGIApplicationLanguagesStatics_inst();
ComPtr<ABI::Windows::Globalization::IJapanesePhoneticAnalyzerStatics> WGIJapanesePhoneticAnalyzerStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WGJapanesePhoneme_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_NSString, RTProxiedNSArray_WGJapanesePhoneme;
