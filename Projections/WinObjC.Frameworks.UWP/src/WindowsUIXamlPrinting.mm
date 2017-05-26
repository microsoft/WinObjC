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

// WindowsUIXamlPrinting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Printing.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlPrinting.h"
#include "WindowsUIXamlPrinting_priv.h"

@implementation WUXPAddPagesEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IAddPagesEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Printing.AddPagesEventArgs").Get(), &out));
    return [_createRtProxy<WUXPAddPagesEventArgs>(out.Get()) retain];
}

- (WGPPrintTaskOptions*)printTaskOptions {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IAddPagesEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintTaskOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskOptions>(unmarshalledReturn.Get());
}

@end

@implementation WUXPGetPreviewPageEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Printing.GetPreviewPageEventArgs").Get(), &out));
    return [_createRtProxy<WUXPGetPreviewPageEventArgs>(out.Get()) retain];
}

- (int)pageNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IGetPreviewPageEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PageNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXPPaginateEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IPaginateEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Printing.PaginateEventArgs").Get(), &out));
    return [_createRtProxy<WUXPPaginateEventArgs>(out.Get()) retain];
}

- (WGPPrintTaskOptions*)printTaskOptions {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintTaskOptionsCore> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPaginateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrintTaskOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPPrintTaskOptions>(unmarshalledReturn.Get());
}

- (int)currentPreviewPageNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPaginateEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentPreviewPageNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXPPrintDocument

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocument> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocumentFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Printing.PrintDocument").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocument> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXPPrintDocument* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocumentStatics> WUXPIPrintDocumentStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Printing::IPrintDocumentStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Printing.PrintDocument").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)documentSourceProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXPIPrintDocumentStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DocumentSourceProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (RTObject<WGPIPrintDocumentSource>*)documentSource {
    ComPtr<ABI::Windows::Graphics::Printing::IPrintDocumentSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGPIPrintDocumentSource>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPaginateEvent:(WUXPPaginateEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->add_Paginate(Make<WUXPPaginateEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePaginateEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Paginate(token));
}

- (EventRegistrationToken)addGetPreviewPageEvent:(WUXPGetPreviewPageEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->add_GetPreviewPage(Make<WUXPGetPreviewPageEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeGetPreviewPageEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->remove_GetPreviewPage(token));
}

- (EventRegistrationToken)addAddPagesEvent:(WUXPAddPagesEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->add_AddPages(Make<WUXPAddPagesEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddPagesEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AddPages(token));
}

- (void)addPage:(WXUIElement*)pageVisual {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->AddPage(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(pageVisual).Get()));
}

- (void)addPagesComplete {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->AddPagesComplete());
}

- (void)setPreviewPageCount:(int)count type:(WUXPPreviewPageCountType)type {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SetPreviewPageCount(count, (ABI::Windows::UI::Xaml::Printing::PreviewPageCountType)type));
}

- (void)setPreviewPage:(int)pageNumber pageVisual:(WXUIElement*)pageVisual {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->SetPreviewPage(pageNumber, _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(pageVisual).Get()));
}

- (void)invalidatePreview {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Printing::IPrintDocument>(self);
    THROW_NS_IF_FAILED(_comInst->InvalidatePreview());
}

@end
