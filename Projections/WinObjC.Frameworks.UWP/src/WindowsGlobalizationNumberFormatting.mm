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

// WindowsGlobalizationNumberFormatting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Globalization.NumberFormatting.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGlobalizationNumberFormatting.h"
#include "WindowsGlobalizationNumberFormatting_priv.h"

@implementation WGNINumberRounder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)roundInt32:(int)value {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)roundUInt32:(unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)roundInt64:(int64_t)value {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)roundUInt64:(uint64_t)value {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)roundSingle:(float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundSingle(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)roundDouble:(double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundDouble(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WGNINumberFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGNINumberFormatter2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGNINumberParser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberParser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* int64_t */)parseInt:(NSString*)text {
    ComPtr<IReference<int64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int64_t, int64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)parseUInt:(NSString*)text {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseUInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* double */)parseDouble:(NSString*)text {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseDouble(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

@end

@implementation WGNINumberFormatterOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)integerDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IntegerDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIntegerDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IntegerDigits(value));
}

- (int)fractionDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FractionDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFractionDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FractionDigits(value));
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGrouped((boolean)value));
}

- (BOOL)isDecimalPointAlwaysDisplayed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecimalPointAlwaysDisplayed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecimalPointAlwaysDisplayed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecimalPointAlwaysDisplayed((boolean)value));
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGNISignificantDigitsOption

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)significantDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

@end

@implementation WGNINumberRounderOption

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WGNINumberRounder>*)numberRounder {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberRounder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGNINumberRounder>(unmarshalledReturn.Get());
}

- (void)setNumberRounder:(RTObject<WGNINumberRounder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NumberRounder(_getRtInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(value).Get()));
}

@end

@implementation WGNISignedZeroOption

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isZeroSigned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsZeroSigned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsZeroSigned:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsZeroSigned((boolean)value));
}

@end

@implementation WGNSignificantDigitsNumberRounder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.SignificantDigitsNumberRounder").Get(), &out));
    return [_createRtProxy<WGNSignificantDigitsNumberRounder>(out.Get()) retain];
}

- (int)roundInt32:(int)value {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)roundUInt32:(unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)roundInt64:(int64_t)value {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)roundUInt64:(uint64_t)value {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)roundSingle:(float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundSingle(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)roundDouble:(double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundDouble(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGNRoundingAlgorithm)roundingAlgorithm {
    ABI::Windows::Globalization::NumberFormatting::RoundingAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoundingAlgorithm(&unmarshalledReturn));
    return (WGNRoundingAlgorithm)unmarshalledReturn;
}

- (void)setRoundingAlgorithm:(WGNRoundingAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoundingAlgorithm((ABI::Windows::Globalization::NumberFormatting::RoundingAlgorithm)value));
}

- (unsigned int)significantDigits {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

@end

@implementation WGNIncrementNumberRounder

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.IncrementNumberRounder").Get(), &out));
    return [_createRtProxy<WGNIncrementNumberRounder>(out.Get()) retain];
}

- (int)roundInt32:(int)value {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)roundUInt32:(unsigned int)value {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt32(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int64_t)roundInt64:(int64_t)value {
    int64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)roundUInt64:(uint64_t)value {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundUInt64(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)roundSingle:(float)value {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundSingle(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)roundDouble:(double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->RoundDouble(value, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGNRoundingAlgorithm)roundingAlgorithm {
    ABI::Windows::Globalization::NumberFormatting::RoundingAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::IIncrementNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoundingAlgorithm(&unmarshalledReturn));
    return (WGNRoundingAlgorithm)unmarshalledReturn;
}

- (void)setRoundingAlgorithm:(WGNRoundingAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::IIncrementNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoundingAlgorithm((ABI::Windows::Globalization::NumberFormatting::RoundingAlgorithm)value));
}

- (double)increment {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::IIncrementNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->get_Increment(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIncrement:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::IIncrementNumberRounder>(self);
    THROW_NS_IF_FAILED(_comInst->put_Increment(value));
}

@end

@implementation WGNDecimalFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.NumberFormatting.DecimalFormatter").Get(),
                                              &out));
    return [_createRtProxy<WGNDecimalFormatter>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Globalization::NumberFormatting::IDecimalFormatterFactory> WGNIDecimalFormatterFactory_inst() {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::IDecimalFormatterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.DecimalFormatter").Get(), &inst));
    return inst;
}

+ (WGNDecimalFormatter*)makeDecimalFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                            geographicRegion:(NSString*)geographicRegion {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> unmarshalledReturn;
    auto _comInst = WGNIDecimalFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateDecimalFormatter(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNDecimalFormatter>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)integerDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IntegerDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIntegerDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IntegerDigits(value));
}

- (int)fractionDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FractionDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFractionDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FractionDigits(value));
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGrouped((boolean)value));
}

- (BOOL)isDecimalPointAlwaysDisplayed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecimalPointAlwaysDisplayed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecimalPointAlwaysDisplayed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecimalPointAlwaysDisplayed((boolean)value));
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* int64_t */)parseInt:(NSString*)text {
    ComPtr<IReference<int64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int64_t, int64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)parseUInt:(NSString*)text {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseUInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* double */)parseDouble:(NSString*)text {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseDouble(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (int)significantDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

- (RTObject<WGNINumberRounder>*)numberRounder {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberRounder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGNINumberRounder>(unmarshalledReturn.Get());
}

- (void)setNumberRounder:(RTObject<WGNINumberRounder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NumberRounder(_getRtInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(value).Get()));
}

- (BOOL)isZeroSigned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsZeroSigned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsZeroSigned:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsZeroSigned((boolean)value));
}

@end

@implementation WGNPercentFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::NumberFormatting::IPercentFormatterFactory> WGNIPercentFormatterFactory_inst() {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::IPercentFormatterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.PercentFormatter").Get(), &inst));
    return inst;
}

+ (WGNPercentFormatter*)makePercentFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                            geographicRegion:(NSString*)geographicRegion {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> unmarshalledReturn;
    auto _comInst = WGNIPercentFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePercentFormatter(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNPercentFormatter>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.NumberFormatting.PercentFormatter").Get(),
                                              &out));
    return [_createRtProxy<WGNPercentFormatter>(out.Get()) retain];
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)integerDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IntegerDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIntegerDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IntegerDigits(value));
}

- (int)fractionDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FractionDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFractionDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FractionDigits(value));
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGrouped((boolean)value));
}

- (BOOL)isDecimalPointAlwaysDisplayed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecimalPointAlwaysDisplayed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecimalPointAlwaysDisplayed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecimalPointAlwaysDisplayed((boolean)value));
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* int64_t */)parseInt:(NSString*)text {
    ComPtr<IReference<int64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int64_t, int64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)parseUInt:(NSString*)text {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseUInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* double */)parseDouble:(NSString*)text {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseDouble(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (int)significantDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

- (RTObject<WGNINumberRounder>*)numberRounder {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberRounder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGNINumberRounder>(unmarshalledReturn.Get());
}

- (void)setNumberRounder:(RTObject<WGNINumberRounder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NumberRounder(_getRtInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(value).Get()));
}

- (BOOL)isZeroSigned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsZeroSigned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsZeroSigned:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsZeroSigned((boolean)value));
}

@end

@implementation WGNPermilleFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::NumberFormatting::IPermilleFormatterFactory> WGNIPermilleFormatterFactory_inst() {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::IPermilleFormatterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.PermilleFormatter").Get(), &inst));
    return inst;
}

+ (WGNPermilleFormatter*)makePermilleFormatter:(id<NSFastEnumeration> /* NSString * */)languages
                              geographicRegion:(NSString*)geographicRegion {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberFormatter> unmarshalledReturn;
    auto _comInst = WGNIPermilleFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreatePermilleFormatter(
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNPermilleFormatter>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Globalization.NumberFormatting.PermilleFormatter").Get(),
                                              &out));
    return [_createRtProxy<WGNPermilleFormatter>(out.Get()) retain];
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)integerDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IntegerDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIntegerDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IntegerDigits(value));
}

- (int)fractionDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FractionDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFractionDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FractionDigits(value));
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGrouped((boolean)value));
}

- (BOOL)isDecimalPointAlwaysDisplayed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecimalPointAlwaysDisplayed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecimalPointAlwaysDisplayed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecimalPointAlwaysDisplayed((boolean)value));
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* int64_t */)parseInt:(NSString*)text {
    ComPtr<IReference<int64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int64_t, int64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)parseUInt:(NSString*)text {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseUInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* double */)parseDouble:(NSString*)text {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseDouble(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (int)significantDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

- (RTObject<WGNINumberRounder>*)numberRounder {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberRounder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGNINumberRounder>(unmarshalledReturn.Get());
}

- (void)setNumberRounder:(RTObject<WGNINumberRounder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NumberRounder(_getRtInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(value).Get()));
}

- (BOOL)isZeroSigned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsZeroSigned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsZeroSigned:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsZeroSigned((boolean)value));
}

@end

@implementation WGNCurrencyFormatter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory> WGNICurrencyFormatterFactory_inst() {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.CurrencyFormatter").Get(), &inst));
    return inst;
}

+ (WGNCurrencyFormatter*)makeCurrencyFormatterCode:(NSString*)currencyCode {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter> unmarshalledReturn;
    auto _comInst = WGNICurrencyFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCurrencyFormatterCode(nsStrToHstr(currencyCode).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNCurrencyFormatter>(unmarshalledReturn.Get()) retain];
}

+ (WGNCurrencyFormatter*)makeCurrencyFormatterCodeContext:(NSString*)currencyCode
                                                languages:(id<NSFastEnumeration> /* NSString * */)languages
                                         geographicRegion:(NSString*)geographicRegion {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter> unmarshalledReturn;
    auto _comInst = WGNICurrencyFormatterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCurrencyFormatterCodeContext(
        nsStrToHstr(currencyCode).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(languages).Get()),
        nsStrToHstr(geographicRegion).Get(),
        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNCurrencyFormatter>(unmarshalledReturn.Get()) retain];
}

- (NSString*)currency {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Currency(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCurrency:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Currency(nsStrToHstr(value).Get()));
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)geographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_GeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)integerDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IntegerDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIntegerDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IntegerDigits(value));
}

- (int)fractionDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FractionDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFractionDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FractionDigits(value));
}

- (BOOL)isGrouped {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrouped(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsGrouped:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsGrouped((boolean)value));
}

- (BOOL)isDecimalPointAlwaysDisplayed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDecimalPointAlwaysDisplayed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsDecimalPointAlwaysDisplayed:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsDecimalPointAlwaysDisplayed((boolean)value));
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)resolvedGeographicRegion {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatterOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedGeographicRegion(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatInt:(int64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatUInt:(uint64_t)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatUInt(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)formatDouble:(double)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberFormatter>(self);
    THROW_NS_IF_FAILED(_comInst->FormatDouble(value, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (id /* int64_t */)parseInt:(NSString*)text {
    ComPtr<IReference<int64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int64_t, int64_t>::convert(unmarshalledReturn.Get());
}

- (id /* uint64_t */)parseUInt:(NSString*)text {
    ComPtr<IReference<uint64_t>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseUInt(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<uint64_t, uint64_t>::convert(unmarshalledReturn.Get());
}

- (id /* double */)parseDouble:(NSString*)text {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberParser>(self);
    THROW_NS_IF_FAILED(_comInst->ParseDouble(nsStrToHstr(text).Get(), unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (WGNCurrencyFormatterMode)mode {
    ABI::Windows::Globalization::NumberFormatting::CurrencyFormatterMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mode(&unmarshalledReturn));
    return (WGNCurrencyFormatterMode)unmarshalledReturn;
}

- (void)setMode:(WGNCurrencyFormatterMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mode((ABI::Windows::Globalization::NumberFormatting::CurrencyFormatterMode)value));
}

- (void)applyRoundingForCurrency:(WGNRoundingAlgorithm)roundingAlgorithm {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ICurrencyFormatter2>(self);
    THROW_NS_IF_FAILED(
        _comInst->ApplyRoundingForCurrency((ABI::Windows::Globalization::NumberFormatting::RoundingAlgorithm)roundingAlgorithm));
}

- (int)significantDigits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignificantDigits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSignificantDigits:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignificantDigitsOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_SignificantDigits(value));
}

- (RTObject<WGNINumberRounder>*)numberRounder {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumberRounder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumberRounder(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGNINumberRounder>(unmarshalledReturn.Get());
}

- (void)setNumberRounder:(RTObject<WGNINumberRounder>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounderOption>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NumberRounder(_getRtInterface<ABI::Windows::Globalization::NumberFormatting::INumberRounder>(value).Get()));
}

- (BOOL)isZeroSigned {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsZeroSigned(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsZeroSigned:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::ISignedZeroOption>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsZeroSigned((boolean)value));
}

@end

@implementation WGNNumeralSystemTranslator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.NumeralSystemTranslator").Get(), &out));
    return [_createRtProxy<WGNNumeralSystemTranslator>(out.Get()) retain];
}

static ComPtr<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory> WGNINumeralSystemTranslatorFactory_inst() {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslatorFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Globalization.NumberFormatting.NumeralSystemTranslator").Get(), &inst));
    return inst;
}

+ (WGNNumeralSystemTranslator*)make:(id<NSFastEnumeration> /* NSString * */)languages {
    ComPtr<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator> unmarshalledReturn;
    auto _comInst = WGNINumeralSystemTranslatorFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(languages).Get()),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGNNumeralSystemTranslator>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* NSString * */)languages {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Languages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (NSString*)resolvedLanguage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolvedLanguage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)numeralSystem {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator>(self);
    THROW_NS_IF_FAILED(_comInst->get_NumeralSystem(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setNumeralSystem:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator>(self);
    THROW_NS_IF_FAILED(_comInst->put_NumeralSystem(nsStrToHstr(value).Get()));
}

- (NSString*)translateNumerals:(NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Globalization::NumberFormatting::INumeralSystemTranslator>(self);
    THROW_NS_IF_FAILED(_comInst->TranslateNumerals(nsStrToHstr(value).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
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
