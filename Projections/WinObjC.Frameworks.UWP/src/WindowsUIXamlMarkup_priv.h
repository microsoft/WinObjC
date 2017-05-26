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

// WindowsUIXamlMarkup_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIXamlInterop_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsFoundation_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBinaryWriterStatics> WUXMIXamlBinaryWriterStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlReaderStatics> WUXMIXamlReaderStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Markup::IXamlBindingHelperStatics> WUXMIXamlBindingHelperStatics_inst();
@interface WUXMXamlBinaryWriterErrorInformation (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation*)internalStruct;
@end
inline WUXMXamlBinaryWriterErrorInformation* WUXMXamlBinaryWriterErrorInformation_create(
    ABI::Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation val) {
    return [WUXMXamlBinaryWriterErrorInformation createWith:val];
}
@interface WUXMXmlnsDefinition (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Markup::XmlnsDefinition)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Xaml::Markup::XmlnsDefinition*)internalStruct;
@end
inline WUXMXmlnsDefinition* WUXMXmlnsDefinition_create(ABI::Windows::UI::Xaml::Markup::XmlnsDefinition val) {
    return [WUXMXmlnsDefinition createWith:val];
}

id RTProxiedNSArray_C_WUXMXmlnsDefinition_create(UINT32 size, ABI::Windows::UI::Xaml::Markup::XmlnsDefinition* val);
id RTProxiedNSMutableArray_RTObject_WSSIRandomAccessStream_create(IInspectable* val);

@class RTProxiedNSArray_C_WUXMXmlnsDefinition, RTProxiedNSMutableArray_RTObject_WSSIRandomAccessStream;
