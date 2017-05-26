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

// WindowsGlobalizationPhoneNumberFormatting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.PhoneNumberFormatting.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalizationPhoneNumberFormatting.h"
#include "WindowsGlobalizationPhoneNumberFormatting_priv.h"

@implementation WGPPhoneNumberInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory> WGPIPhoneNumberInfoFactory_inst() {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.PhoneNumberFormatting.PhoneNumberInfo").Get(), &inst));
    return inst;
}

+ (WGPPhoneNumberInfo*)make:(NSString*)number {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(number).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGPPhoneNumberInfo>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics> WGPIPhoneNumberInfoStatics_inst() {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfoStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.PhoneNumberFormatting.PhoneNumberInfo").Get(), &inst));
    return inst;
}

+ (WGPPhoneNumberParseResult)tryParse:(NSString*)input phoneNumber:(WGPPhoneNumberInfo**)phoneNumber {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> phoneNumberOutUnmarshaled;
    ABI::Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParse(nsStrToHstr(input).Get(), phoneNumberOutUnmarshaled.GetAddressOf(), &unmarshalledReturn));
    *phoneNumber = _createRtProxy<WGPPhoneNumberInfo>(phoneNumberOutUnmarshaled.Get());
    return (WGPPhoneNumberParseResult)unmarshalledReturn;
}

+ (WGPPhoneNumberParseResult)tryParseWithRegion:(NSString*)input
                                     regionCode:(NSString*)regionCode
                                    phoneNumber:(WGPPhoneNumberInfo**)phoneNumber {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo> phoneNumberOutUnmarshaled;
    ABI::Windows::Globalization::PhoneNumberFormatting::PhoneNumberParseResult unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberInfoStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryParseWithRegion(nsStrToHstr(input).Get(),
                                                    nsStrToHstr(regionCode).Get(),
                                                    phoneNumberOutUnmarshaled.GetAddressOf(),
                                                    &unmarshalledReturn));
    *phoneNumber = _createRtProxy<WGPPhoneNumberInfo>(phoneNumberOutUnmarshaled.Get());
    return (WGPPhoneNumberParseResult)unmarshalledReturn;
}

- (int)countryCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_CountryCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)getLengthOfGeographicalAreaCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetLengthOfGeographicalAreaCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)getNationalSignificantNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetNationalSignificantNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)getLengthOfNationalDestinationCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetLengthOfNationalDestinationCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGPPredictedPhoneNumberKind)predictNumberKind {
    ABI::Windows::Globalization::PhoneNumberFormatting::PredictedPhoneNumberKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->PredictNumberKind(&unmarshalledReturn));
    return (WGPPredictedPhoneNumberKind)unmarshalledReturn;
}

- (NSString*)getGeographicRegionCode {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetGeographicRegionCode(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGPPhoneNumberMatchResult)checkNumberMatch:(WGPPhoneNumberInfo*)otherNumber {
    ABI::Windows::Globalization::PhoneNumberFormatting::PhoneNumberMatchResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(self);
    THROW_NS_IF_FAILED(
        _comInst->CheckNumberMatch(_getRtInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(otherNumber).Get(),
                                   &unmarshalledReturn));
    return (WGPPhoneNumberMatchResult)unmarshalledReturn;
}

- (NSString*)toString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IStringable>(self);
    THROW_NS_IF_FAILED(_comInst->ToString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGPPhoneNumberFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Globalization.PhoneNumberFormatting.PhoneNumberFormatter").Get(), &out));
    return [_createRtProxy<WGPPhoneNumberFormatter>(out.Get()) retain];
}

ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics> WGPIPhoneNumberFormatterStatics_inst() {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.PhoneNumberFormatting.PhoneNumberFormatter").Get(), &inst));
    return inst;
}

+ (void)tryCreate:(NSString*)regionCode phoneNumber:(WGPPhoneNumberFormatter**)phoneNumber {
    ComPtr<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter> phoneNumberOutUnmarshaled;
    auto _comInst = WGPIPhoneNumberFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryCreate(nsStrToHstr(regionCode).Get(), phoneNumberOutUnmarshaled.GetAddressOf()));
    *phoneNumber = _createRtProxy<WGPPhoneNumberFormatter>(phoneNumberOutUnmarshaled.Get());
}

+ (int)getCountryCodeForRegion:(NSString*)regionCode {
    int unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetCountryCodeForRegion(nsStrToHstr(regionCode).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (NSString*)getNationalDirectDialingPrefixForRegion:(NSString*)regionCode stripNonDigit:(BOOL)stripNonDigit {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberFormatterStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetNationalDirectDialingPrefixForRegion(nsStrToHstr(regionCode).Get(), (boolean)stripNonDigit, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wrapWithLeftToRightMarkers:(NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = WGPIPhoneNumberFormatterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->WrapWithLeftToRightMarkers(nsStrToHstr(number).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)format:(WGPPhoneNumberInfo*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->Format(_getRtInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(number).Get(),
                                        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatWithOutputFormat:(WGPPhoneNumberInfo*)number numberFormat:(WGPPhoneNumberFormat)numberFormat {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatWithOutputFormat(
        _getRtInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberInfo>(number).Get(),
        (ABI::Windows::Globalization::PhoneNumberFormatting::PhoneNumberFormat)numberFormat,
        &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatPartialString:(NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatPartialString(nsStrToHstr(number).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatString:(NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatString(nsStrToHstr(number).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatStringWithLeftToRightMarkers:(NSString*)number {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::PhoneNumberFormatting::IPhoneNumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatStringWithLeftToRightMarkers(nsStrToHstr(number).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
