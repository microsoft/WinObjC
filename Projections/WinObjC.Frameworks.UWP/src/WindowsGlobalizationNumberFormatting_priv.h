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

// WindowsGlobalizationNumberFormatting_priv.h
// Forward decls for private object generation
#pragma once

static ComPtr<ABI::Windows::Globalization::NumberFormatting::IDecimalFormatterFactory> WGNIDecimalFormatterFactory_inst();
static ComPtr<ABI::Windows::Globalization::NumberFormatting::IPercentFormatterFactory> WGNIPercentFormatterFactory_inst();
static ComPtr<ABI::Windows::Globalization::NumberFormatting::IPermilleFormatterFactory> WGNIPermilleFormatterFactory_inst();
static ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory> WGNICurrencyFormatterFactory_inst();
static ComPtr<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory> WGNINumeralSystemTranslatorFactory_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);

@class Nullable_Double, Nullable_Int64, Nullable_UInt64, RTProxiedIterableNSArray_NSString, RTProxiedNSArray_NSString;
