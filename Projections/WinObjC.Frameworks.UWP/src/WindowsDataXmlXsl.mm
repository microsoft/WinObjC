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

// WindowsDataXmlXsl.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Data.Xml.Xsl.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDataXmlXsl.h"
#include "WindowsDataXmlXsl_priv.h"

@implementation WDXXXsltProcessor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Data::Xml::Xsl::IXsltProcessor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Data::Xml::Xsl::IXsltProcessorFactory> WDXXIXsltProcessorFactory_inst() {
    ComPtr<ABI::Windows::Data::Xml::Xsl::IXsltProcessorFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Data.Xml.Xsl.XsltProcessor").Get(), &inst));
    return inst;
}

+ (WDXXXsltProcessor*)makeInstance:(WDXDXmlDocument*)document {
    ComPtr<ABI::Windows::Data::Xml::Xsl::IXsltProcessor> unmarshalledReturn;
    auto _comInst = WDXXIXsltProcessorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlDocument>(document).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDXXXsltProcessor>(unmarshalledReturn.Get()) retain];
}

- (NSString*)transformToString:(RTObject<WDXDIXmlNode>*)inputNode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Xsl::IXsltProcessor>(self);
    THROW_NS_IF_FAILED(
        _comInst->TransformToString(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(inputNode).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WDXDXmlDocument*)transformToDocument:(RTObject<WDXDIXmlNode>*)inputNode {
    ComPtr<ABI::Windows::Data::Xml::Dom::IXmlDocument> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Data::Xml::Xsl::IXsltProcessor2>(self);
    THROW_NS_IF_FAILED(_comInst->TransformToDocument(_getRtInterface<ABI::Windows::Data::Xml::Dom::IXmlNode>(inputNode).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDXDXmlDocument>(unmarshalledReturn.Get());
}

@end
