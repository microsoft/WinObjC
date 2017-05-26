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

// WindowsGlobalization.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalization.h"
#include "WindowsGlobalization_priv.h"

@implementation WGCalendarIdentifiers

ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics3> WGICalendarIdentifiersStatics3_inst() {
    ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.CalendarIdentifiers").Get(), &inst));
    return inst;
}

+ (NSString*)chineseLunar {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChineseLunar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)japaneseLunar {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_JapaneseLunar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)koreanLunar {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_KoreanLunar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)taiwanLunar {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_TaiwanLunar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)vietnameseLunar {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_VietnameseLunar(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics2> WGICalendarIdentifiersStatics2_inst() {
    ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.CalendarIdentifiers").Get(), &inst));
    return inst;
}

+ (NSString*)persian {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Persian(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics> WGICalendarIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::Globalization::ICalendarIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.CalendarIdentifiers").Get(), &inst));
    return inst;
}

+ (NSString*)gregorian {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gregorian(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hebrew {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Hebrew(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hijri {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Hijri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)japanese {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Japanese(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)julian {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Julian(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)korean {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Korean(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)taiwan {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Taiwan(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)thai {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Thai(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)umAlQura {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICalendarIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UmAlQura(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGClockIdentifiers

ComPtr<ABI::Windows::Globalization::IClockIdentifiersStatics> WGIClockIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::Globalization::IClockIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.ClockIdentifiers").Get(), &inst));
    return inst;
}

+ (NSString*)twelveHour {
    HSTRING unmarshalledReturn;
    auto _comInst = WGIClockIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TwelveHour(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)twentyFourHour {
    HSTRING unmarshalledReturn;
    auto _comInst = WGIClockIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TwentyFourHour(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGNumeralSystemIdentifiers

ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics2> WGINumeralSystemIdentifiersStatics2_inst() {
    ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.NumeralSystemIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)brah {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Brah(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)osma {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_Osma(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mathBold {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathBold(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mathDbl {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathDbl(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mathSans {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathSans(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mathSanb {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathSanb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mathMono {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_MathMono(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zmthBold {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZmthBold(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zmthDbl {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZmthDbl(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zmthSans {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZmthSans(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zmthSanb {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZmthSanb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zmthMono {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZmthMono(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics> WGINumeralSystemIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::Globalization::INumeralSystemIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.NumeralSystemIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)arab {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Arab(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)arabExt {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ArabExt(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bali {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Bali(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)beng {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Beng(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cham {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Cham(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)deva {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Deva(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)fullWide {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FullWide(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gujr {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gujr(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)guru {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Guru(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)haniDec {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HaniDec(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)java {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Java(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kali {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Kali(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)khmr {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Khmr(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)knda {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Knda(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lana {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Lana(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lanaTham {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LanaTham(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)laoo {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Laoo(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)latn {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Latn(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lepc {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Lepc(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)limb {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Limb(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mlym {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mlym(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mong {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mong(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mtei {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mtei(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mymr {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Mymr(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mymrShan {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MymrShan(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nkoo {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Nkoo(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)olck {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Olck(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)orya {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Orya(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)saur {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Saur(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sund {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Sund(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)talu {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Talu(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tamlDec {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TamlDec(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)telu {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Telu(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)thai {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Thai(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tibt {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Tibt(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)vaii {
    HSTRING unmarshalledReturn;
    auto _comInst = WGINumeralSystemIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Vaii(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGCurrencyIdentifiers

ComPtr<ABI::Windows::Globalization::ICurrencyIdentifiersStatics> WGICurrencyIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::Globalization::ICurrencyIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.CurrencyIdentifiers").Get(), &inst));
    return inst;
}

+ (NSString*)aED {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AED(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aFN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AFN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aLL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ALL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aMD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AMD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aNG {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ANG(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aOA {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AOA(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aRS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ARS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aUD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AUD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aWG {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AWG(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)aZN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AZN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bAM {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BAM(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bBD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BBD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bDT {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BDT(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bGN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BGN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bHD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BHD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bIF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BIF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bMD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BMD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bND {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BND(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bOB {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BOB(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bRL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BRL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bSD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BSD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bTN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BTN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bWP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BWP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bYR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BYR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)bZD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BZD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cAD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CAD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cDF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CDF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cHF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CHF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cLP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CLP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cNY {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CNY(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cOP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_COP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cRC {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CRC(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cUP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CUP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cVE {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CVE(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)cZK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CZK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dJF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DJF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dKK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DKK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dOP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DOP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)dZD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DZD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eGP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EGP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eRN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ERN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eTB {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ETB(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)eUR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EUR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)fJD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FJD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)fKP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FKP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gBP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GBP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gEL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GEL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gHS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GHS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gIP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GIP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gMD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GMD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gNF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GNF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gTQ {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GTQ(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)gYD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GYD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hKD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HKD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hNL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HNL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hRK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HRK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hTG {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HTG(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)hUF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HUF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iDR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IDR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iLS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ILS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iNR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_INR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iQD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IQD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iRR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IRR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)iSK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ISK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jMD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JMD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jOD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JOD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)jPY {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_JPY(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kES {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KES(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kGS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KGS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kHR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KHR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kMF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KMF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kPW {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KPW(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kRW {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KRW(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kWD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KWD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kYD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KYD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)kZT {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_KZT(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lAK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LAK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lBP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LBP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lKR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LKR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lRD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LRD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lSL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LSL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lTL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LTL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lVL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LVL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lYD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LYD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mAD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MAD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mDL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MDL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mGA {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MGA(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mKD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MKD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mMK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MMK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mNT {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MNT(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mOP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MOP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mRO {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MRO(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mUR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MUR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mVR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MVR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mWK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MWK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mXN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MXN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mYR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MYR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)mZN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MZN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nAD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NAD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nGN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NGN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nIO {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NIO(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nOK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NOK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nPR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NPR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)nZD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NZD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)oMR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OMR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pAB {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PAB(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pEN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PEN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pGK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PGK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pHP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PHP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pKR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PKR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pLN {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PLN(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)pYG {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PYG(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)qAR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_QAR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rON {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RON(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rSD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RSD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rUB {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RUB(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)rWF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RWF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sAR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SAR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sBD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SBD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sCR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SCR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sDG {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SDG(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sEK {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SEK(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sGD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SGD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sHP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SHP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sLL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SLL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sOS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SOS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sRD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SRD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sTD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_STD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sYP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SYP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sZL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SZL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tHB {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_THB(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tJS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TJS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tMT {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TMT(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tND {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TND(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tOP {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TOP(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tRY {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TRY(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tTD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TTD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tWD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TWD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)tZS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TZS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uAH {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UAH(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uGX {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UGX(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uSD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_USD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uYU {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UYU(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)uZS {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UZS(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)vEF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VEF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)vND {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VND(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)vUV {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VUV(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)wST {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WST(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xAF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XAF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xCD {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XCD(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xOF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XOF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xPF {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XPF(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)xXX {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_XXX(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)yER {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_YER(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zAR {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZAR(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zMW {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZMW(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)zWL {
    HSTRING unmarshalledReturn;
    auto _comInst = WGICurrencyIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZWL(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGGeographicRegion

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::IGeographicRegion> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.GeographicRegion").Get(), &out));
    return [_createRtProxy<WGGeographicRegion>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Globalization::IGeographicRegionFactory> WGIGeographicRegionFactory_inst() {
    ComPtr<ABI::Windows::Globalization::IGeographicRegionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.GeographicRegion").Get(), &inst));
    return inst;
}

+ (WGGeographicRegion*)makeGeographicRegion:(NSString*)geographicRegionCode {
    ComPtr<ABI::Windows::Globalization::IGeographicRegion> unmarshalledReturn;
    auto _comInst = WGIGeographicRegionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateGeographicRegion(nsStrToHstr(geographicRegionCode).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGGeographicRegion>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Globalization::IGeographicRegionStatics> WGIGeographicRegionStatics_inst() {
    ComPtr<ABI::Windows::Globalization::IGeographicRegionStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.GeographicRegion").Get(), &inst));
    return inst;
}

+ (BOOL)isSupported:(NSString*)geographicRegionCode {
    boolean unmarshalledReturn;
    auto _comInst = WGIGeographicRegionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(nsStrToHstr(geographicRegionCode).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)code {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_Code(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)codeTwoLetter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_CodeTwoLetter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)codeThreeLetter {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_CodeThreeLetter(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)codeThreeDigit {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_CodeThreeDigit(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nativeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_NativeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)currenciesInUse {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IGeographicRegion>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrenciesInUse(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WGLanguage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::ILanguage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::ILanguageFactory> WGILanguageFactory_inst() {
    ComPtr<ABI::Windows::Globalization::ILanguageFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Language").Get(), &inst));
    return inst;
}

+ (WGLanguage*)makeLanguage:(NSString*)languageTag {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = WGILanguageFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateLanguage(nsStrToHstr(languageTag).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGLanguage>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::Globalization::ILanguageStatics2> WGILanguageStatics2_inst() {
    ComPtr<ABI::Windows::Globalization::ILanguageStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Language").Get(), &inst));
    return inst;
}

+ (BOOL)trySetInputMethodLanguageTag:(NSString*)languageTag {
    boolean unmarshalledReturn;
    auto _comInst = WGILanguageStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->TrySetInputMethodLanguageTag(nsStrToHstr(languageTag).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Globalization::ILanguageStatics> WGILanguageStatics_inst() {
    ComPtr<ABI::Windows::Globalization::ILanguageStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Language").Get(), &inst));
    return inst;
}

+ (BOOL)isWellFormed:(NSString*)languageTag {
    boolean unmarshalledReturn;
    auto _comInst = WGILanguageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsWellFormed(nsStrToHstr(languageTag).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (NSString*)currentInputMethodLanguageTag {
    HSTRING unmarshalledReturn;
    auto _comInst = WGILanguageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentInputMethodLanguageTag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)languageTag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ILanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_LanguageTag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ILanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nativeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ILanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_NativeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)script {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ILanguage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Script(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)getExtensionSubtags:(NSString*)singleton {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ILanguageExtensionSubtags>(self);
    THROW_NS_IF_FAILED(_comInst->GetExtensionSubtags(nsStrToHstr(singleton).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WGCalendar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::ICalendar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::ICalendarFactory2> WGICalendarFactory2_inst() {
    ComPtr<ABI::Windows::Globalization::ICalendarFactory2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Calendar").Get(), &inst));
    return inst;
}

+ (WGCalendar*)makeCalendarWithTimeZone:(id<NSFastEnumeration> /* NSString * */)languages
                               calendar:(NSString*)calendar
                                  clock:(NSString*)clock
                             timeZoneId:(NSString*)timeZoneId {
    ComPtr<ABI::Windows::Globalization::ICalendar> unmarshalledReturn;
    auto _comInst = WGICalendarFactory2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCalendarWithTimeZone(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(calendar).Get(),
        nsStrToHstr(clock).Get(),
        nsStrToHstr(timeZoneId).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGCalendar>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.Calendar").Get(), &out));
    return [_createRtProxy<WGCalendar>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Globalization::ICalendarFactory> WGICalendarFactory_inst() {
    ComPtr<ABI::Windows::Globalization::ICalendarFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.Calendar").Get(), &inst));
    return inst;
}

+ (WGCalendar*)makeCalendarDefaultCalendarAndClock:(id<NSFastEnumeration> /* NSString * */)languages {
    ComPtr<ABI::Windows::Globalization::ICalendar> unmarshalledReturn;
    auto _comInst = WGICalendarFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCalendarDefaultCalendarAndClock(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGCalendar>(unmarshalledReturn.Get()) retain];
}

+ (WGCalendar*)makeCalendar:(id<NSFastEnumeration> /* NSString * */)languages calendar:(NSString*)calendar clock:(NSString*)clock {
    ComPtr<ABI::Windows::Globalization::ICalendar> unmarshalledReturn;
    auto _comInst = WGICalendarFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateCalendar(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                     ConvertToIterable<NSString, HSTRING>(languages).Get()),
                                 nsStrToHstr(calendar).Get(),
                                 nsStrToHstr(clock).Get(),
                                 unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGCalendar>(unmarshalledReturn.Get()) retain];
}

- (WGCalendar*)clone {
    ComPtr<ABI::Windows::Globalization::ICalendar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGCalendar>(unmarshalledReturn.Get());
}

- (void)setToMin {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SetToMin());
}

- (void)setToMax {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SetToMax());
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)getCalendarSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->GetCalendarSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)changeCalendarSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeCalendarSystem(nsStrToHstr(value).Get()));
}

- (NSString*)getClock {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->GetClock(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)changeClock:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeClock(nsStrToHstr(value).Get()));
}

- (WFDateTime*)getDateTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->GetDateTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)setDateTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SetDateTime(*[value internalStruct]));
}

- (void)setToNow {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SetToNow());
}

- (int)firstEra {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstEra(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastEra {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastEra(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfEras {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfEras(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)era {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Era(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEra:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Era(value));
}

- (void)addEras:(int)eras {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddEras(eras));
}

- (NSString*)eraAsFullString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->EraAsFullString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)eraAsString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->EraAsString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)firstYearInThisEra {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstYearInThisEra(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastYearInThisEra {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastYearInThisEra(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfYearsInThisEra {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfYearsInThisEra(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)year {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Year(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setYear:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Year(value));
}

- (void)addYears:(int)years {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddYears(years));
}

- (NSString*)yearAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->YearAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)yearAsTruncatedString:(int)remainingDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->YearAsTruncatedString(remainingDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)yearAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->YearAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)firstMonthInThisYear {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstMonthInThisYear(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastMonthInThisYear {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastMonthInThisYear(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfMonthsInThisYear {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfMonthsInThisYear(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)month {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Month(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMonth:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Month(value));
}

- (void)addMonths:(int)months {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddMonths(months));
}

- (NSString*)monthAsFullString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsFullString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)monthAsString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)monthAsFullSoloString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsFullSoloString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)monthAsSoloString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsSoloString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)monthAsNumericString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsNumericString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)monthAsPaddedNumericString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MonthAsPaddedNumericString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)addWeeks:(int)weeks {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddWeeks(weeks));
}

- (int)firstDayInThisMonth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstDayInThisMonth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastDayInThisMonth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastDayInThisMonth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfDaysInThisMonth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfDaysInThisMonth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)day {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Day(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDay:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Day(value));
}

- (void)addDays:(int)days {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddDays(days));
}

- (NSString*)dayAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dayAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WGDayOfWeek)dayOfWeek {
    ABI::Windows::Globalization::DayOfWeek unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_DayOfWeek(&unmarshalledReturn));
    return (WGDayOfWeek)unmarshalledReturn;
}

- (NSString*)dayOfWeekAsFullString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayOfWeekAsFullString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dayOfWeekAsString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayOfWeekAsString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dayOfWeekAsFullSoloString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayOfWeekAsFullSoloString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dayOfWeekAsSoloString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->DayOfWeekAsSoloString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)firstPeriodInThisDay {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstPeriodInThisDay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastPeriodInThisDay {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastPeriodInThisDay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfPeriodsInThisDay {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfPeriodsInThisDay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)period {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Period(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPeriod:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Period(value));
}

- (void)addPeriods:(int)periods {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddPeriods(periods));
}

- (NSString*)periodAsFullString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->PeriodAsFullString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)periodAsString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->PeriodAsString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)firstHourInThisPeriod {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstHourInThisPeriod(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastHourInThisPeriod {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastHourInThisPeriod(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfHoursInThisPeriod {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfHoursInThisPeriod(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)hour {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hour(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHour:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Hour(value));
}

- (void)addHours:(int)hours {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddHours(hours));
}

- (NSString*)hourAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->HourAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)hourAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->HourAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)minute {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minute(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinute:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Minute(value));
}

- (void)addMinutes:(int)minutes {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddMinutes(minutes));
}

- (NSString*)minuteAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MinuteAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)minuteAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->MinuteAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)second {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Second(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSecond:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Second(value));
}

- (void)addSeconds:(int)seconds {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddSeconds(seconds));
}

- (NSString*)secondAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SecondAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)secondAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->SecondAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)nanosecond {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Nanosecond(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setNanosecond:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Nanosecond(value));
}

- (void)addNanoseconds:(int)nanoseconds {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->AddNanoseconds(nanoseconds));
}

- (NSString*)nanosecondAsString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->NanosecondAsString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)nanosecondAsPaddedString:(int)minDigits {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->NanosecondAsPaddedString(minDigits, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)compare:(WGCalendar*)other {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->Compare(_getRtInterface<ABI::Windows::Globalization::ICalendar>(other).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)compareDateTime:(WFDateTime*)other {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->CompareDateTime(*[other internalStruct], &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)copyTo:(WGCalendar*)other {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->CopyTo(_getRtInterface<ABI::Windows::Globalization::ICalendar>(other).Get()));
}

- (int)firstMinuteInThisHour {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstMinuteInThisHour(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastMinuteInThisHour {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastMinuteInThisHour(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfMinutesInThisHour {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfMinutesInThisHour(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)firstSecondInThisMinute {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstSecondInThisMinute(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)lastSecondInThisMinute {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastSecondInThisMinute(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)numberOfSecondsInThisMinute {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberOfSecondsInThisMinute(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isDaylightSavingTime {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ICalendar>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDaylightSavingTime(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)getTimeZone {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ITimeZoneOnCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->GetTimeZone(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)changeTimeZone:(NSString*)timeZoneId {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ITimeZoneOnCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->ChangeTimeZone(nsStrToHstr(timeZoneId).Get()));
}

- (NSString*)timeZoneAsFullString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ITimeZoneOnCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->TimeZoneAsFullString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)timeZoneAsString:(int)idealLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::ITimeZoneOnCalendar>(self);
    THROW_NS_IF_FAILED(_comInst->TimeZoneAsString(idealLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGApplicationLanguages

ComPtr<ABI::Windows::Globalization::IApplicationLanguagesStatics> WGIApplicationLanguagesStatics_inst() {
    ComPtr<ABI::Windows::Globalization::IApplicationLanguagesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.ApplicationLanguages").Get(), &inst));
    return inst;
}

+ (NSString*)primaryLanguageOverride {
    HSTRING unmarshalledReturn;
    auto _comInst = WGIApplicationLanguagesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PrimaryLanguageOverride(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setPrimaryLanguageOverride:(NSString*)value {
    auto _comInst = WGIApplicationLanguagesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_PrimaryLanguageOverride(nsStrToHstr(value).Get()));
}

+ (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WGIApplicationLanguagesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (NSArray* /* NSString * */)manifestLanguages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WGIApplicationLanguagesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ManifestLanguages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WGJapanesePhoneme

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::IJapanesePhoneme> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IJapanesePhoneme>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)yomiText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IJapanesePhoneme>(self);
    THROW_NS_IF_FAILED(_comInst->get_YomiText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isPhraseStart {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::IJapanesePhoneme>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPhraseStart(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WGJapanesePhoneticAnalyzer

ComPtr<ABI::Windows::Globalization::IJapanesePhoneticAnalyzerStatics> WGIJapanesePhoneticAnalyzerStatics_inst() {
    ComPtr<ABI::Windows::Globalization::IJapanesePhoneticAnalyzerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Globalization.JapanesePhoneticAnalyzer").Get(),
                                                       &inst));
    return inst;
}

+ (NSArray* /* WGJapanesePhoneme* */)getWords:(NSString*)input {
    ComPtr<IVectorView<ABI::Windows::Globalization::JapanesePhoneme*>> unmarshalledReturn;
    auto _comInst = WGIJapanesePhoneticAnalyzerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetWords(nsStrToHstr(input).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGJapanesePhoneme_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WGJapanesePhoneme* */)getWordsWithMonoRubyOption:(NSString*)input monoRuby:(BOOL)monoRuby {
    ComPtr<IVectorView<ABI::Windows::Globalization::JapanesePhoneme*>> unmarshalledReturn;
    auto _comInst = WGIJapanesePhoneticAnalyzerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetWordsWithMonoRubyOption(nsStrToHstr(input).Get(), (boolean)monoRuby, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGJapanesePhoneme_create(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGJapanesePhoneme_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Globalization::JapanesePhoneme*>,
                                         RTArrayObj<ABI::Windows::Globalization::IJapanesePhoneme*,
                                                    IVectorView<ABI::Windows::Globalization::JapanesePhoneme*>,
                                                    WGJapanesePhoneme,
                                                    ABI::Windows::Globalization::JapanesePhoneme*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
