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

// WindowsGraphicsPrinting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Graphics.Printing.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGraphicsPrinting.h"
#include "WindowsGraphicsPrinting_priv.h"

@implementation WGPIPrintTaskOptionsCoreProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setMediaSize:(WGPPrintMediaSize)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaSize((ABI::Windows::Graphics::Printing::PrintMediaSize)value));
}

- (WGPPrintMediaSize)mediaSize {
    ABI::Windows::Graphics::Printing::PrintMediaSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSize(&unmarshalledReturn));
    return (WGPPrintMediaSize)unmarshalledReturn;
}

- (void)setMediaType:(WGPPrintMediaType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaType((ABI::Windows::Graphics::Printing::PrintMediaType)value));
}

- (WGPPrintMediaType)mediaType {
    ABI::Windows::Graphics::Printing::PrintMediaType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return (WGPPrintMediaType)unmarshalledReturn;
}

- (void)setOrientation:(WGPPrintOrientation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation((ABI::Windows::Graphics::Printing::PrintOrientation)value));
}

- (WGPPrintOrientation)orientation {
    ABI::Windows::Graphics::Printing::PrintOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WGPPrintOrientation)unmarshalledReturn;
}

- (void)setPrintQuality:(WGPPrintQuality)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrintQuality((ABI::Windows::Graphics::Printing::PrintQuality)value));
}

- (WGPPrintQuality)printQuality {
    ABI::Windows::Graphics::Printing::PrintQuality unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintQuality(&unmarshalledReturn));
    return (WGPPrintQuality)unmarshalledReturn;
}

- (void)setColorMode:(WGPPrintColorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorMode((ABI::Windows::Graphics::Printing::PrintColorMode)value));
}

- (WGPPrintColorMode)colorMode {
    ABI::Windows::Graphics::Printing::PrintColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return (WGPPrintColorMode)unmarshalledReturn;
}

- (void)setDuplex:(WGPPrintDuplex)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duplex((ABI::Windows::Graphics::Printing::PrintDuplex)value));
}

- (WGPPrintDuplex)duplex {
    ABI::Windows::Graphics::Printing::PrintDuplex unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duplex(&unmarshalledReturn));
    return (WGPPrintDuplex)unmarshalledReturn;
}

- (void)setCollation:(WGPPrintCollation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Collation((ABI::Windows::Graphics::Printing::PrintCollation)value));
}

- (WGPPrintCollation)collation {
    ABI::Windows::Graphics::Printing::PrintCollation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Collation(&unmarshalledReturn));
    return (WGPPrintCollation)unmarshalledReturn;
}

- (void)setStaple:(WGPPrintStaple)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Staple((ABI::Windows::Graphics::Printing::PrintStaple)value));
}

- (WGPPrintStaple)staple {
    ABI::Windows::Graphics::Printing::PrintStaple unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Staple(&unmarshalledReturn));
    return (WGPPrintStaple)unmarshalledReturn;
}

- (void)setHolePunch:(WGPPrintHolePunch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_HolePunch((ABI::Windows::Graphics::Printing::PrintHolePunch)value));
}

- (WGPPrintHolePunch)holePunch {
    ABI::Windows::Graphics::Printing::PrintHolePunch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_HolePunch(&unmarshalledReturn));
    return (WGPPrintHolePunch)unmarshalledReturn;
}

- (void)setBinding:(WGPPrintBinding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Binding((ABI::Windows::Graphics::Printing::PrintBinding)value));
}

- (WGPPrintBinding)binding {
    ABI::Windows::Graphics::Printing::PrintBinding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Binding(&unmarshalledReturn));
    return (WGPPrintBinding)unmarshalledReturn;
}

- (unsigned int)minCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setNumberOfCopies:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumberOfCopies(value));
}

- (unsigned int)numberOfCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPIPrintTaskOptionsCoreUIConfiguration

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* NSString * */)displayedOptions {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayedOptions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WGPIPrintTaskOptionsCore

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber {
    ABI::Windows::Graphics::Printing::PrintPageDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore>(self);
    THROW_NS_IF_FAILED(_comInst->GetPageDescription(jobPageNumber, &unmarshalledReturn));
    return WGPPrintPageDescription_create(unmarshalledReturn);
}

@end

@implementation WGPIPrintDocumentSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintDocumentSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WGPPrintPageInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintPageInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Graphics.Printing.PrintPageInfo").Get(), &out));
    return [_createRtProxy<WGPPrintPageInfo>(out.Get()) retain];
}

- (void)setMediaSize:(WGPPrintMediaSize)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaSize((ABI::Windows::Graphics::Printing::PrintMediaSize)value));
}

- (WGPPrintMediaSize)mediaSize {
    ABI::Windows::Graphics::Printing::PrintMediaSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSize(&unmarshalledReturn));
    return (WGPPrintMediaSize)unmarshalledReturn;
}

- (void)setPageSize:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_PageSize(*[value internalStruct]));
}

- (WFSize*)pageSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setDpiX:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DpiX(value));
}

- (unsigned int)dpiX {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDpiY:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DpiY(value));
}

- (unsigned int)dpiY {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DpiY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOrientation:(WGPPrintOrientation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation((ABI::Windows::Graphics::Printing::PrintOrientation)value));
}

- (WGPPrintOrientation)orientation {
    ABI::Windows::Graphics::Printing::PrintOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WGPPrintOrientation)unmarshalledReturn;
}

@end

@implementation WGPPrintTaskOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber {
    ABI::Windows::Graphics::Printing::PrintPageDescription unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore>(self);
    THROW_NS_IF_FAILED(_comInst->GetPageDescription(jobPageNumber, &unmarshalledReturn));
    return WGPPrintPageDescription_create(unmarshalledReturn);
}

- (void)setMediaSize:(WGPPrintMediaSize)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaSize((ABI::Windows::Graphics::Printing::PrintMediaSize)value));
}

- (WGPPrintMediaSize)mediaSize {
    ABI::Windows::Graphics::Printing::PrintMediaSize unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaSize(&unmarshalledReturn));
    return (WGPPrintMediaSize)unmarshalledReturn;
}

- (void)setMediaType:(WGPPrintMediaType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_MediaType((ABI::Windows::Graphics::Printing::PrintMediaType)value));
}

- (WGPPrintMediaType)mediaType {
    ABI::Windows::Graphics::Printing::PrintMediaType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return (WGPPrintMediaType)unmarshalledReturn;
}

- (void)setOrientation:(WGPPrintOrientation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation((ABI::Windows::Graphics::Printing::PrintOrientation)value));
}

- (WGPPrintOrientation)orientation {
    ABI::Windows::Graphics::Printing::PrintOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WGPPrintOrientation)unmarshalledReturn;
}

- (void)setPrintQuality:(WGPPrintQuality)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_PrintQuality((ABI::Windows::Graphics::Printing::PrintQuality)value));
}

- (WGPPrintQuality)printQuality {
    ABI::Windows::Graphics::Printing::PrintQuality unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintQuality(&unmarshalledReturn));
    return (WGPPrintQuality)unmarshalledReturn;
}

- (void)setColorMode:(WGPPrintColorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorMode((ABI::Windows::Graphics::Printing::PrintColorMode)value));
}

- (WGPPrintColorMode)colorMode {
    ABI::Windows::Graphics::Printing::PrintColorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return (WGPPrintColorMode)unmarshalledReturn;
}

- (void)setDuplex:(WGPPrintDuplex)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duplex((ABI::Windows::Graphics::Printing::PrintDuplex)value));
}

- (WGPPrintDuplex)duplex {
    ABI::Windows::Graphics::Printing::PrintDuplex unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duplex(&unmarshalledReturn));
    return (WGPPrintDuplex)unmarshalledReturn;
}

- (void)setCollation:(WGPPrintCollation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Collation((ABI::Windows::Graphics::Printing::PrintCollation)value));
}

- (WGPPrintCollation)collation {
    ABI::Windows::Graphics::Printing::PrintCollation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Collation(&unmarshalledReturn));
    return (WGPPrintCollation)unmarshalledReturn;
}

- (void)setStaple:(WGPPrintStaple)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Staple((ABI::Windows::Graphics::Printing::PrintStaple)value));
}

- (WGPPrintStaple)staple {
    ABI::Windows::Graphics::Printing::PrintStaple unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Staple(&unmarshalledReturn));
    return (WGPPrintStaple)unmarshalledReturn;
}

- (void)setHolePunch:(WGPPrintHolePunch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_HolePunch((ABI::Windows::Graphics::Printing::PrintHolePunch)value));
}

- (WGPPrintHolePunch)holePunch {
    ABI::Windows::Graphics::Printing::PrintHolePunch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_HolePunch(&unmarshalledReturn));
    return (WGPPrintHolePunch)unmarshalledReturn;
}

- (void)setBinding:(WGPPrintBinding)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_Binding((ABI::Windows::Graphics::Printing::PrintBinding)value));
}

- (WGPPrintBinding)binding {
    ABI::Windows::Graphics::Printing::PrintBinding unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_Binding(&unmarshalledReturn));
    return (WGPPrintBinding)unmarshalledReturn;
}

- (unsigned int)minCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)maxCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setNumberOfCopies:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumberOfCopies(value));
}

- (unsigned int)numberOfCopies {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfCopies(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSMutableArray* /* NSString * */)displayedOptions {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCoreUIConfiguration>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayedOptions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (void)setBordering:(WGPPrintBordering)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bordering((ABI::Windows::Graphics::Printing::PrintBordering)value));
}

- (WGPPrintBordering)bordering {
    ABI::Windows::Graphics::Printing::PrintBordering unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bordering(&unmarshalledReturn));
    return (WGPPrintBordering)unmarshalledReturn;
}

- (RTObject<WSSIRandomAccessStream>*)getPagePrintTicket:(WGPPrintPageInfo*)printPageInfo {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskOptions>(self);
    THROW_NS_IF_FAILED(_comInst->GetPagePrintTicket(_getRtInterface<ABI::Windows::Graphics::Printing::IPrintPageInfo>(printPageInfo).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

@end

@implementation WGPStandardPrintTaskOptions

ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic> WGPIStandardPrintTaskOptionsStatic_inst() {
    ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing.StandardPrintTaskOptions").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)mediaSize {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaSize(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mediaType {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_MediaType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)orientation {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)printQuality {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_PrintQuality(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)colorMode {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorMode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)duplex {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Duplex(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)collation {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Collation(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)staple {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Staple(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)holePunch {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_HolePunch(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)binding {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Binding(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)copies {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_Copies(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nUp {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_NUp(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)inputBin {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic_inst();
    THROW_NS_IF_FAILED(_comInst->get_InputBin(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic2> WGPIStandardPrintTaskOptionsStatic2_inst() {
    ComPtr<ABI::Windows::Graphics::Printing::IStandardPrintTaskOptionsStatic2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing.StandardPrintTaskOptions").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)bordering {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIStandardPrintTaskOptionsStatic2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bordering(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGPPrintTaskProgressingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskProgressingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)documentPageCount {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskProgressingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentPageCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGPPrintTaskCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrintTaskCompletion)completion {
    ABI::Windows::Graphics::Printing::PrintTaskCompletion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completion(&unmarshalledReturn));
    return (WGPPrintTaskCompletion)unmarshalledReturn;
}

@end

@implementation WGPPrintTask

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WADDataPackagePropertySet*)properties {
    ComPtr<ABI::Windows::ApplicationModel::DataTransfer::IDataPackagePropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WADDataPackagePropertySet>(unmarshalledReturn.Get());
}

- (RTObject<WGPIPrintDocumentSource>*)source {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintDocumentSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPIPrintDocumentSource>(unmarshalledReturn.Get());
}

- (WGPPrintTaskOptions*)options {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskOptions>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPreviewingEvent:(void (^)(WGPPrintTask*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Previewing(Make<ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object>(eventHandler).Get(),
                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePreviewingEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Previewing(eventCookie));
}

- (EventRegistrationToken)addSubmittingEvent:(void (^)(WGPPrintTask*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Submitting(Make<ITypedEventHandler_Windows_Graphics_Printing_PrintTask_System_Object>(eventHandler).Get(),
                                 &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSubmittingEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Submitting(eventCookie));
}

- (EventRegistrationToken)addProgressingEvent:(void (^)(WGPPrintTask*, WGPPrintTaskProgressingEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->add_Progressing(
        Make<ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskProgressingEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeProgressingEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Progressing(eventCookie));
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WGPPrintTask*, WGPPrintTaskCompletedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<ITypedEventHandler_Windows_Graphics_Printing_PrintTask_Windows_Graphics_Printing_PrintTaskCompletedEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(eventCookie));
}

- (void)setIsPrinterTargetEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPrinterTargetEnabled((boolean)value));
}

- (BOOL)isPrinterTargetEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPrinterTargetEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIs3DManufacturingTargetEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport>(self);
    THROW_NS_IF_FAILED(_comInst->put_Is3DManufacturingTargetEnabled((boolean)value));
}

- (BOOL)is3DManufacturingTargetEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskTargetDeviceSupport>(self);
    THROW_NS_IF_FAILED(_comInst->get_Is3DManufacturingTargetEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsPreviewEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsPreviewEnabled((boolean)value));
}

- (BOOL)isPreviewEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTask2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPreviewEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGPPrintTaskSourceRequestedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WGPPrintTaskSourceRequestedArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setSource:(RTObject<WGPIPrintDocumentSource>*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->SetSource(_getRtInterface<ABI::Windows::Graphics::Printing::IPrintDocumentSource>(source).Get()));
}

- (WGPPrintTaskSourceRequestedDeferral*)getDeferral {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskSourceRequestedArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskSourceRequestedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrintTaskRequestedDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskRequestedDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskRequestedDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WGPPrintTaskRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WGPPrintTask*)createPrintTask:(NSString*)title handler:(WGPPrintTaskSourceRequestedHandler)handler {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTask> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskRequest>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePrintTask(nsStrToHstr(title).Get(),
                                                 Make<WGPPrintTaskSourceRequestedHandler_shim>(handler).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTask>(unmarshalledReturn.Get());
}

- (WGPPrintTaskRequestedDeferral*)getDeferral {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskRequestedDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskRequestedDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrintTaskRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGPPrintTaskRequest*)request {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintTaskRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskRequest>(unmarshalledReturn.Get());
}

@end

@implementation WGPPrintManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic2> WGPIPrintManagerStatic2_inst() {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing.PrintManager").Get(), &inst));
    return inst;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WGPIPrintManagerStatic2_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic> WGPIPrintManagerStatic_inst() {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintManagerStatic> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Graphics.Printing.PrintManager").Get(), &inst));
    return inst;
}

+ (WGPPrintManager*)getForCurrentView {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintManager> unmarshalledReturn;
    auto _comInst = WGPIPrintManagerStatic_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintManager>(unmarshalledReturn.Get());
}

+ (void)showPrintUIAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WGPIPrintManagerStatic_inst();
    THROW_NS_IF_FAILED(_comInst->ShowPrintUIAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addPrintTaskRequestedEvent:(void (^)(WGPPrintManager*, WGPPrintTaskRequestedEventArgs*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_PrintTaskRequested(
        Make<ITypedEventHandler_Windows_Graphics_Printing_PrintManager_Windows_Graphics_Printing_PrintTaskRequestedEventArgs>(eventHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePrintTaskRequestedEvent:(EventRegistrationToken)eventCookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Printing::IPrintManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PrintTaskRequested(eventCookie));
}

@end

@implementation WGPPrintPageDescription {
    ABI::Windows::Graphics::Printing::PrintPageDescription structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Graphics::Printing::PrintPageDescription)s {
    WGPPrintPageDescription* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Graphics::Printing::PrintPageDescription*)internalStruct {
    return &structVal;
}
- (WFSize*)pageSize {
    return WFSize_create(structVal.PageSize);
}
- (void)setPageSize:(WFSize*)val {
    structVal.PageSize = *[val internalStruct];
}
- (WFRect*)imageableRect {
    return WFRect_create(structVal.ImageableRect);
}
- (void)setImageableRect:(WFRect*)val {
    structVal.ImageableRect = *[val internalStruct];
}
- (unsigned int)dpiX {
    return structVal.DpiX;
}
- (void)setDpiX:(unsigned int)val {
    structVal.DpiX = val;
}
- (unsigned int)dpiY {
    return structVal.DpiY;
}
- (void)setDpiY:(unsigned int)val {
    structVal.DpiY = val;
}
@end
id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
