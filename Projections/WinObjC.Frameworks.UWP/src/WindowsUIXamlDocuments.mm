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

// WindowsUIXamlDocuments.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Documents.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlDocuments.h"
#include "WindowsUIXamlDocuments_priv.h"

@implementation WUXDBlockCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Documents::IBlock*,
                      IVector<ABI::Windows::UI::Xaml::Documents::Block*>,
                      WUXDBlock,
                      ABI::Windows::UI::Xaml::Documents::Block*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WUXDBlock, ABI::Windows::UI::Xaml::Documents::IBlock*, ABI::Windows::UI::Xaml::Documents::Block*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Documents::Block*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXDInlineCollection {
    RTMutableArrayObj<ABI::Windows::UI::Xaml::Documents::IInline*,
                      IVector<ABI::Windows::UI::Xaml::Documents::Inline*>,
                      WUXDInline,
                      ABI::Windows::UI::Xaml::Documents::Inline*,
                      dummyObjCCreator,
                      dummyWRLCreator>
        _array;
}
INTEROP_IMPL_VECTOR_FULL(self.comObj, WUXDInline, ABI::Windows::UI::Xaml::Documents::IInline*, ABI::Windows::UI::Xaml::Documents::Inline*)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Documents::Inline*>> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXDTextPointer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WXDependencyObject*)parent {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (WXFrameworkElement*)visualParent {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualParent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXFrameworkElement>(unmarshalledReturn.Get());
}

- (WUXDLogicalDirection)logicalDirection {
    ABI::Windows::UI::Xaml::Documents::LogicalDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_LogicalDirection(&unmarshalledReturn));
    return (WUXDLogicalDirection)unmarshalledReturn;
}

- (int)offset {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFRect*)getCharacterRect:(WUXDLogicalDirection)direction {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->GetCharacterRect((ABI::Windows::UI::Xaml::Documents::LogicalDirection)direction, &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (WUXDTextPointer*)getPositionAtOffset:(int)offset direction:(WUXDLogicalDirection)direction {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextPointer>(self);
    THROW_NS_IF_FAILED(_comInst->GetPositionAtOffset(offset,
                                                     (ABI::Windows::UI::Xaml::Documents::LogicalDirection)direction,
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDTextPointer>(unmarshalledReturn.Get());
}

@end

@implementation WUXDTypography

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITypography> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Documents::ITypographyStatics> WUXDITypographyStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITypographyStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Typography").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)annotationAlternatesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AnnotationAlternatesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getAnnotationAlternates:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAnnotationAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setAnnotationAlternates:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetAnnotationAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)eastAsianExpertFormsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EastAsianExpertFormsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getEastAsianExpertForms:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetEastAsianExpertForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setEastAsianExpertForms:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetEastAsianExpertForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)eastAsianLanguageProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EastAsianLanguageProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontEastAsianLanguage)getEastAsianLanguage:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontEastAsianLanguage unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetEastAsianLanguage(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontEastAsianLanguage)unmarshalledReturn;
}

+ (void)setEastAsianLanguage:(WXDependencyObject*)element value:(WXFontEastAsianLanguage)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetEastAsianLanguage(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                      (ABI::Windows::UI::Xaml::FontEastAsianLanguage)value));
}

+ (WXDependencyProperty*)eastAsianWidthsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EastAsianWidthsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontEastAsianWidths)getEastAsianWidths:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontEastAsianWidths unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetEastAsianWidths(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontEastAsianWidths)unmarshalledReturn;
}

+ (void)setEastAsianWidths:(WXDependencyObject*)element value:(WXFontEastAsianWidths)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetEastAsianWidths(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                    (ABI::Windows::UI::Xaml::FontEastAsianWidths)value));
}

+ (WXDependencyProperty*)standardLigaturesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StandardLigaturesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStandardLigatures:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStandardLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStandardLigatures:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStandardLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)contextualLigaturesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContextualLigaturesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getContextualLigatures:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetContextualLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setContextualLigatures:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetContextualLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)discretionaryLigaturesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DiscretionaryLigaturesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getDiscretionaryLigatures:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDiscretionaryLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                           &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setDiscretionaryLigatures:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetDiscretionaryLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)historicalLigaturesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HistoricalLigaturesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getHistoricalLigatures:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetHistoricalLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setHistoricalLigatures:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetHistoricalLigatures(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)standardSwashesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StandardSwashesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getStandardSwashes:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStandardSwashes(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setStandardSwashes:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetStandardSwashes(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)contextualSwashesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContextualSwashesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getContextualSwashes:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetContextualSwashes(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setContextualSwashes:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetContextualSwashes(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)contextualAlternatesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContextualAlternatesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getContextualAlternates:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetContextualAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setContextualAlternates:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetContextualAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticAlternatesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticAlternatesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getStylisticAlternates:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setStylisticAlternates:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetStylisticAlternates(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)stylisticSet1Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet1Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet1:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet1(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet1:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet1(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet2Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet2Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet2:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet2(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet2:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet2(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet3Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet3Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet3:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet3(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet3:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet3(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet4Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet4Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet4:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet4(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet4:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet4(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet5Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet5Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet5:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet5(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet5:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet5(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet6Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet6Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet6:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet6(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet6:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet6(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet7Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet7Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet7:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet7(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet7:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet7(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet8Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet8Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet8:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet8(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet8:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet8(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet9Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet9Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet9:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet9(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet9:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet9(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet10Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet10Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet10:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet10(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet10:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet10(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet11Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet11Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet11:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet11(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet11:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet11(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet12Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet12Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet12:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet12(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet12:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet12(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet13Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet13Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet13:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet13(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet13:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet13(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet14Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet14Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet14:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet14(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet14:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet14(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet15Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet15Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet15:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet15(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet15:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet15(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet16Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet16Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet16:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet16(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet16:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet16(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet17Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet17Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet17:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet17(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet17:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet17(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet18Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet18Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet18:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet18(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet18:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet18(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet19Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet19Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet19:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet19(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet19:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet19(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)stylisticSet20Property {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StylisticSet20Property(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getStylisticSet20:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStylisticSet20(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setStylisticSet20:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetStylisticSet20(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)capitalsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapitalsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontCapitals)getCapitals:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontCapitals unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetCapitals(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontCapitals)unmarshalledReturn;
}

+ (void)setCapitals:(WXDependencyObject*)element value:(WXFontCapitals)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetCapitals(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                             (ABI::Windows::UI::Xaml::FontCapitals)value));
}

+ (WXDependencyProperty*)capitalSpacingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CapitalSpacingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getCapitalSpacing:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetCapitalSpacing(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setCapitalSpacing:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetCapitalSpacing(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)kerningProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KerningProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getKerning:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetKerning(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setKerning:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetKerning(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)caseSensitiveFormsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CaseSensitiveFormsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getCaseSensitiveForms:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetCaseSensitiveForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setCaseSensitiveForms:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetCaseSensitiveForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)historicalFormsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HistoricalFormsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getHistoricalForms:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetHistoricalForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setHistoricalForms:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetHistoricalForms(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)fractionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FractionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontFraction)getFraction:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontFraction unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFraction(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontFraction)unmarshalledReturn;
}

+ (void)setFraction:(WXDependencyObject*)element value:(WXFontFraction)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetFraction(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                             (ABI::Windows::UI::Xaml::FontFraction)value));
}

+ (WXDependencyProperty*)numeralStyleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NumeralStyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontNumeralStyle)getNumeralStyle:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontNumeralStyle unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetNumeralStyle(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontNumeralStyle)unmarshalledReturn;
}

+ (void)setNumeralStyle:(WXDependencyObject*)element value:(WXFontNumeralStyle)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetNumeralStyle(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                 (ABI::Windows::UI::Xaml::FontNumeralStyle)value));
}

+ (WXDependencyProperty*)numeralAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NumeralAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontNumeralAlignment)getNumeralAlignment:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontNumeralAlignment unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetNumeralAlignment(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontNumeralAlignment)unmarshalledReturn;
}

+ (void)setNumeralAlignment:(WXDependencyObject*)element value:(WXFontNumeralAlignment)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetNumeralAlignment(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                     (ABI::Windows::UI::Xaml::FontNumeralAlignment)value));
}

+ (WXDependencyProperty*)slashedZeroProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SlashedZeroProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getSlashedZero:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetSlashedZero(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setSlashedZero:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetSlashedZero(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)mathematicalGreekProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathematicalGreekProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getMathematicalGreek:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetMathematicalGreek(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setMathematicalGreek:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetMathematicalGreek(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)variantsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VariantsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXFontVariants)getVariants:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::FontVariants unmarshalledReturn;
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetVariants(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WXFontVariants)unmarshalledReturn;
}

+ (void)setVariants:(WXDependencyObject*)element value:(WXFontVariants)value {
    auto _comInst = WUXDITypographyStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetVariants(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                             (ABI::Windows::UI::Xaml::FontVariants)value));
}

@end

@implementation WUXDTextElement

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElement> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics3> WUXDITextElementStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.TextElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)allowFocusOnInteractionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteractionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)accessKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExitDisplayModeOnAccessKeyInvokedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics2> WUXDITextElementStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.TextElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsTextScaleFactorEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics> WUXDITextElementStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextElementStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.TextElement").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)fontSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontFamilyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontFamilyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontWeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontWeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontStyleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontStyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontStretchProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontStretchProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)characterSpacingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CharacterSpacingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)foregroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)languageProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDITextElementStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LanguageProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (double)fontSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFontSize:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontSize(value));
}

- (WUXMFontFamily*)fontFamily {
    ComPtr<ABI::Windows::UI::Xaml::Media::IFontFamily> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontFamily(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMFontFamily>(unmarshalledReturn.Get());
}

- (void)setFontFamily:(WUXMFontFamily*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontFamily(_getRtInterface<ABI::Windows::UI::Xaml::Media::IFontFamily>(value).Get()));
}

- (WUTFontWeight*)fontWeight {
    ABI::Windows::UI::Text::FontWeight unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontWeight(&unmarshalledReturn));
    return WUTFontWeight_create(unmarshalledReturn);
}

- (void)setFontWeight:(WUTFontWeight*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontWeight(*[value internalStruct]));
}

- (WUTFontStyle)fontStyle {
    ABI::Windows::UI::Text::FontStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStyle(&unmarshalledReturn));
    return (WUTFontStyle)unmarshalledReturn;
}

- (void)setFontStyle:(WUTFontStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontStyle((ABI::Windows::UI::Text::FontStyle)value));
}

- (WUTFontStretch)fontStretch {
    ABI::Windows::UI::Text::FontStretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontStretch(&unmarshalledReturn));
    return (WUTFontStretch)unmarshalledReturn;
}

- (void)setFontStretch:(WUTFontStretch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontStretch((ABI::Windows::UI::Text::FontStretch)value));
}

- (int)characterSpacing {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_CharacterSpacing(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setCharacterSpacing:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_CharacterSpacing(value));
}

- (WUXMBrush*)foreground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Foreground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Foreground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setLanguage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->put_Language(nsStrToHstr(value).Get()));
}

- (WUXDTextPointer*)contentStart {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentStart(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDTextPointer>(unmarshalledReturn.Get());
}

- (WUXDTextPointer*)contentEnd {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentEnd(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDTextPointer>(unmarshalledReturn.Get());
}

- (WUXDTextPointer*)elementStart {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementStart(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDTextPointer>(unmarshalledReturn.Get());
}

- (WUXDTextPointer*)elementEnd {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ITextPointer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementEnd(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDTextPointer>(unmarshalledReturn.Get());
}

- (RTObject*)findName:(NSString*)name {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement>(self);
    THROW_NS_IF_FAILED(_comInst->FindName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)onDisconnectVisualChildren {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElementOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnDisconnectVisualChildren());
}

- (BOOL)isTextScaleFactorEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTextScaleFactorEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsTextScaleFactorEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsTextScaleFactorEnabled((boolean)value));
}

- (BOOL)allowFocusOnInteraction {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteraction(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowFocusOnInteraction:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowFocusOnInteraction((boolean)value));
}

- (NSString*)accessKey {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccessKey(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAccessKey:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->put_AccessKey(nsStrToHstr(value).Get()));
}

- (BOOL)exitDisplayModeOnAccessKeyInvoked {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitDisplayModeOnAccessKeyInvoked(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setExitDisplayModeOnAccessKeyInvoked:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ITextElement3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExitDisplayModeOnAccessKeyInvoked((boolean)value));
}

@end

@implementation WUXDBlock

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IBlock> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IBlockStatics> WUXDIBlockStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IBlockStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Block").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)textAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIBlockStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TextAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)lineHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIBlockStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LineHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)lineStackingStrategyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIBlockStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LineStackingStrategyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)marginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIBlockStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXTextAlignment)textAlignment {
    ABI::Windows::UI::Xaml::TextAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextAlignment(&unmarshalledReturn));
    return (WXTextAlignment)unmarshalledReturn;
}

- (void)setTextAlignment:(WXTextAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextAlignment((ABI::Windows::UI::Xaml::TextAlignment)value));
}

- (double)lineHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLineHeight:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineHeight(value));
}

- (WXLineStackingStrategy)lineStackingStrategy {
    ABI::Windows::UI::Xaml::LineStackingStrategy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineStackingStrategy(&unmarshalledReturn));
    return (WXLineStackingStrategy)unmarshalledReturn;
}

- (void)setLineStackingStrategy:(WXLineStackingStrategy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->put_LineStackingStrategy((ABI::Windows::UI::Xaml::LineStackingStrategy)value));
}

- (WXThickness*)margin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->get_Margin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IBlock>(self);
    THROW_NS_IF_FAILED(_comInst->put_Margin(*[value internalStruct]));
}

@end

@implementation WUXDInline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IInline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXDInlineUIContainer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IInlineUIContainer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.InlineUIContainer").Get(), &out));
    return [_createRtProxy<WUXDInlineUIContainer>(out.Get()) retain];
}

- (WXUIElement*)child {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IInlineUIContainer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Child(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setChild:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IInlineUIContainer>(self);
    THROW_NS_IF_FAILED(_comInst->put_Child(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

@end

@implementation WUXDLineBreak

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ILineBreak> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.LineBreak").Get(), &out));
    return [_createRtProxy<WUXDLineBreak>(out.Get()) retain];
}

@end

@implementation WUXDParagraph

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IParagraph> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Paragraph").Get(), &out));
    return [_createRtProxy<WUXDParagraph>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IParagraphStatics> WUXDIParagraphStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IParagraphStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Paragraph").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)textIndentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIParagraphStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TextIndentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXDInlineCollection*)inlines {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Documents::Inline*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IParagraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_Inlines(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDInlineCollection>(unmarshalledReturn.Get());
}

- (double)textIndent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IParagraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextIndent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTextIndent:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IParagraph>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextIndent(value));
}

@end

@implementation WUXDRun

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IRun> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Run").Get(), &out));
    return [_createRtProxy<WUXDRun>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IRunStatics> WUXDIRunStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IRunStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Run").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)flowDirectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIRunStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowDirectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IRun>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IRun>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (WXFlowDirection)flowDirection {
    ABI::Windows::UI::Xaml::FlowDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IRun>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlowDirection(&unmarshalledReturn));
    return (WXFlowDirection)unmarshalledReturn;
}

- (void)setFlowDirection:(WXFlowDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IRun>(self);
    THROW_NS_IF_FAILED(_comInst->put_FlowDirection((ABI::Windows::UI::Xaml::FlowDirection)value));
}

@end

@implementation WUXDSpan

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ISpan> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Documents::ISpanFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Span").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Documents::ISpan> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXDITextElementOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXDITextElementOverrides)]) {
        typedOuter = Make<WUXDITextElementOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXDSpan* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (WUXDInlineCollection*)inlines {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Documents::Inline*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ISpan>(self);
    THROW_NS_IF_FAILED(_comInst->get_Inlines(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXDInlineCollection>(unmarshalledReturn.Get());
}

- (void)setInlines:(WUXDInlineCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::ISpan>(self);
    THROW_NS_IF_FAILED(_comInst->put_Inlines(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Documents::Inline*>>(value).Get()));
}

@end

@implementation WUXDBold

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IBold> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Bold").Get(), &out));
    return [_createRtProxy<WUXDBold>(out.Get()) retain];
}

@end

@implementation WUXDItalic

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IItalic> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Italic").Get(), &out));
    return [_createRtProxy<WUXDItalic>(out.Get()) retain];
}

@end

@implementation WUXDUnderline

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IUnderline> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Underline").Get(), &out));
    return [_createRtProxy<WUXDUnderline>(out.Get()) retain];
}

@end

@implementation WUXDHyperlink

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlink> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Hyperlink").Get(), &out));
    return [_createRtProxy<WUXDHyperlink>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics> WUXDIHyperlinkStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Hyperlink").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)navigateUriProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NavigateUriProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics3> WUXDIHyperlinkStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Hyperlink").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)xYFocusLeftProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_XYFocusLeftProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)xYFocusRightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_XYFocusRightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)xYFocusUpProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_XYFocusUpProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)xYFocusDownProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_XYFocusDownProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)elementSoundModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_ElementSoundModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics2> WUXDIHyperlinkStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Hyperlink").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)underlineStyleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIHyperlinkStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_UnderlineStyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WFUri*)navigateUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink>(self);
    THROW_NS_IF_FAILED(_comInst->get_NavigateUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setNavigateUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink>(self);
    THROW_NS_IF_FAILED(_comInst->put_NavigateUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (EventRegistrationToken)addClickEvent:(void (^)(WUXDHyperlink*, WUXDHyperlinkClickEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink>(self);
    THROW_NS_IF_FAILED(_comInst->add_Click(
        Make<ITypedEventHandler_Windows_UI_Xaml_Documents_Hyperlink_Windows_UI_Xaml_Documents_HyperlinkClickEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Click(token));
}

- (WUXDUnderlineStyle)underlineStyle {
    ABI::Windows::UI::Xaml::Documents::UnderlineStyle unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink2>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnderlineStyle(&unmarshalledReturn));
    return (WUXDUnderlineStyle)unmarshalledReturn;
}

- (void)setUnderlineStyle:(WUXDUnderlineStyle)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink2>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnderlineStyle((ABI::Windows::UI::Xaml::Documents::UnderlineStyle)value));
}

- (WXDependencyObject*)xYFocusLeft {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->get_XYFocusLeft(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setXYFocusLeft:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->put_XYFocusLeft(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (WXDependencyObject*)xYFocusRight {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->get_XYFocusRight(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setXYFocusRight:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->put_XYFocusRight(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (WXDependencyObject*)xYFocusUp {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->get_XYFocusUp(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setXYFocusUp:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->put_XYFocusUp(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (WXDependencyObject*)xYFocusDown {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyObject> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->get_XYFocusDown(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyObject>(unmarshalledReturn.Get());
}

- (void)setXYFocusDown:(WXDependencyObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->put_XYFocusDown(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(value).Get()));
}

- (WXElementSoundMode)elementSoundMode {
    ABI::Windows::UI::Xaml::ElementSoundMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementSoundMode(&unmarshalledReturn));
    return (WXElementSoundMode)unmarshalledReturn;
}

- (void)setElementSoundMode:(WXElementSoundMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IHyperlink3>(self);
    THROW_NS_IF_FAILED(_comInst->put_ElementSoundMode((ABI::Windows::UI::Xaml::ElementSoundMode)value));
}

@end

@implementation WUXDHyperlinkClickEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IHyperlinkClickEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXDGlyphs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IGlyphs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Documents.Glyphs").Get(), &out));
    return [_createRtProxy<WUXDGlyphs>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IGlyphsStatics2> WUXDIGlyphsStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IGlyphsStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Glyphs").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isColorFontEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsColorFontEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)colorFontPaletteIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColorFontPaletteIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Documents::IGlyphsStatics> WUXDIGlyphsStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Documents::IGlyphsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Documents.Glyphs").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)unicodeStringProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UnicodeStringProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)indicesProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IndicesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontUriProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontUriProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)styleSimulationsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StyleSimulationsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fontRenderingEmSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FontRenderingEmSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)originXProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OriginXProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)originYProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OriginYProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)fillProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXDIGlyphsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (NSString*)unicodeString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnicodeString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setUnicodeString:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_UnicodeString(nsStrToHstr(value).Get()));
}

- (NSString*)indices {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Indices(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setIndices:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Indices(nsStrToHstr(value).Get()));
}

- (WFUri*)fontUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setFontUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (WUXMStyleSimulations)styleSimulations {
    ABI::Windows::UI::Xaml::Media::StyleSimulations unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_StyleSimulations(&unmarshalledReturn));
    return (WUXMStyleSimulations)unmarshalledReturn;
}

- (void)setStyleSimulations:(WUXMStyleSimulations)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_StyleSimulations((ABI::Windows::UI::Xaml::Media::StyleSimulations)value));
}

- (double)fontRenderingEmSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_FontRenderingEmSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFontRenderingEmSize:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_FontRenderingEmSize(value));
}

- (double)originX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOriginX:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_OriginX(value));
}

- (double)originY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OriginY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOriginY:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_OriginY(value));
}

- (WUXMBrush*)fill {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fill(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFill:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Fill(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (BOOL)isColorFontEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsColorFontEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsColorFontEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs2>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsColorFontEnabled((boolean)value));
}

- (int)colorFontPaletteIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColorFontPaletteIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setColorFontPaletteIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Documents::IGlyphs2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ColorFontPaletteIndex(value));
}

@end
