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

#import <CoreText/CTParagraphStyle.h>
#import <StubReturn.h>
#import "CoreTextInternal.h"
#import "CFCppBase.h"
#import <stddef.h>

// Contains the expected size of the data for any specifier
static constexpr size_t __CTParagraphStyleSizeTable[kCTParagraphStyleSpecifierCount] = {
        [kCTParagraphStyleSpecifierAlignment] = sizeof(CTTextAlignment),
        [kCTParagraphStyleSpecifierFirstLineHeadIndent] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierHeadIndent] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierTailIndent] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierTabStops] = sizeof(CFArrayRef),
        [kCTParagraphStyleSpecifierDefaultTabInterval] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierLineBreakMode] = sizeof(CTLineBreakMode),
        [kCTParagraphStyleSpecifierLineHeightMultiple] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierMaximumLineHeight] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierMinimumLineHeight] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierLineSpacing] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierParagraphSpacing] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierParagraphSpacingBefore] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierBaseWritingDirection] = sizeof(CTWritingDirection),
        [kCTParagraphStyleSpecifierMaximumLineSpacing] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierMinimumLineSpacing] = sizeof(CGFloat),
        [kCTParagraphStyleSpecifierLineSpacingAdjustment] = sizeof(CGFloat),
};

#pragma region __CTParagraphStyle
struct __CTParagraphStyle : CoreFoundation::CppBase<__CTParagraphStyle> {
    __CTParagraphStyle() {
        static woc::unique_cf<CFArrayRef> __defaultValues{ []() {
            constexpr CGFloat c_defaultFloat = 0.0;
            // Need to store Alignment and LineBreakMode as ints in CFNumberRef
            constexpr int c_defaultAlignment = kCTNaturalTextAlignment;
            constexpr int c_defaultLineBreakMode = kCTLineBreakByWordWrapping;
            constexpr CTWritingDirection c_defaultWritingDirection = kCTWritingDirectionNatural;
            woc::unique_cf<CFNumberRef> __alignment{ CFNumberCreate(nullptr, kCFNumberIntType, &c_defaultAlignment) };
            woc::unique_cf<CFNumberRef> __lineBreakMode{ CFNumberCreate(nullptr, kCFNumberIntType, &c_defaultLineBreakMode) };
            woc::unique_cf<CFNumberRef> __writingDirection{ CFNumberCreate(nullptr, kCFNumberSInt8Type, &c_defaultWritingDirection) };
            woc::unique_cf<CFNumberRef> __floatDefault{ CFNumberCreate(nullptr, kCFNumberCGFloatType, &c_defaultFloat) };
            CFTypeRef values[kCTParagraphStyleSpecifierCount] = {
                __alignment.get(),    __floatDefault.get(),  __floatDefault.get(), __floatDefault.get(),     nullptr,
                __floatDefault.get(), __lineBreakMode.get(), __floatDefault.get(), __floatDefault.get(),     __floatDefault.get(),
                __floatDefault.get(), __floatDefault.get(),  __floatDefault.get(), __writingDirection.get(), __floatDefault.get(),
                __floatDefault.get(), __floatDefault.get(),
            };
            return CFArrayCreate(nullptr, values, kCTParagraphStyleSpecifierCount, &kCFTypeArrayCallBacks);
        }() };
        _styles.reset(CFArrayCreateMutableCopy(nullptr, kCTParagraphStyleSpecifierCount, __defaultValues.get()));
    }

    __CTParagraphStyle(const __CTParagraphStyle& rhs) {
        _styles.reset(CFArrayCreateMutableCopy(nullptr, kCTParagraphStyleSpecifierCount, rhs._styles.get()));
    }

    bool SetValue(CTParagraphStyleSpecifier specifier, size_t size, const void* value) {
        if (specifier < kCTParagraphStyleSpecifierCount && size == __CTParagraphStyleSizeTable[specifier]) {
            woc::unique_cf<CFTypeRef> newValue{};
            switch (specifier) {
                case kCTParagraphStyleSpecifierTabStops:
                    // Tab Stops not supported
                    return false;
                case kCTParagraphStyleSpecifierAlignment:
                case kCTParagraphStyleSpecifierLineBreakMode: {
                    // CFNumber has no UInt8Type, so store all int values as standard int
                    int intValue = *static_cast<const uint8_t*>(value);
                    newValue.reset(CFNumberCreate(nullptr, kCFNumberIntType, &intValue));
                } break;
                case kCTParagraphStyleSpecifierBaseWritingDirection:
                    newValue.reset(CFNumberCreate(nullptr, kCFNumberSInt8Type, value));
                    break;
                default:
                    // All other values are of type CGFloat
                    newValue.reset(CFNumberCreate(nullptr, kCFNumberCGFloatType, value));
                    break;
            }

            CFArraySetValueAtIndex(_styles.get(), specifier, newValue.get());
            return true;
        }

        return false;
    }

    bool SetValue(const CTParagraphStyleSetting& setting) {
        return SetValue(setting.spec, setting.valueSize, setting.value);
    }

    bool GetValue(CTParagraphStyleSpecifier specifier, size_t size, void* outValue) const {
        if (specifier <= kCTParagraphStyleSpecifierCount && outValue != nullptr && size == __CTParagraphStyleSizeTable[specifier]) {
            switch (specifier) {
                case kCTParagraphStyleSpecifierTabStops:
                    // Tab Stops not supported
                    return false;
                case kCTParagraphStyleSpecifierAlignment:
                case kCTParagraphStyleSpecifierLineBreakMode:
                    // CFNumber has no UInt8Type, so store all int values as standard int
                    {
                        int intValue = 0;
                        CFNumberGetValue(static_cast<CFNumberRef>(CFArrayGetValueAtIndex(_styles.get(), specifier)),
                                         kCFNumberIntType,
                                         &intValue);
                        *static_cast<uint8_t*>(outValue) = intValue;
                        return true;
                    }
                case kCTParagraphStyleSpecifierBaseWritingDirection:
                    CFNumberGetValue(static_cast<CFNumberRef>(CFArrayGetValueAtIndex(_styles.get(), specifier)),
                                     kCFNumberSInt8Type,
                                     outValue);
                    return true;
                default:
                    // All other values are of type CGFloat
                    CFNumberGetValue(static_cast<CFNumberRef>(CFArrayGetValueAtIndex(_styles.get(), specifier)),
                                     kCFNumberCGFloatType,
                                     outValue);
                    return true;
            }
        }

        return false;
    }

private:
    woc::unique_cf<CFMutableArrayRef> _styles;
};

#pragma endregion

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops not supported
*/
CTParagraphStyleRef CTParagraphStyleCreate(const CTParagraphStyleSetting* settings, size_t settingsCount) {
    __CTParagraphStyle* style = __CTParagraphStyle::CreateInstance();

    if (settings != nullptr) {
        for (size_t i = 0; i < settingsCount; ++i) {
            style->SetValue(settings[i]);
        }
    }

    return style;
}

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops not supported
*/
CTParagraphStyleRef CTParagraphStyleCreateCopy(CTParagraphStyleRef paragraphStyle) {
    return paragraphStyle ? __CTParagraphStyle::CreateInstance(nullptr, *paragraphStyle) : nullptr;
}

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops not supported
*/
bool CTParagraphStyleGetValueForSpecifier(CTParagraphStyleRef paragraphStyle,
                                          CTParagraphStyleSpecifier spec,
                                          size_t valueBufferSize,
                                          void* valueBuffer) {
    RETURN_FALSE_IF(paragraphStyle == nullptr);
    if (paragraphStyle->GetValue(spec, valueBufferSize, valueBuffer)) {
        return true;
    }

    if (valueBuffer) {
        memset(valueBuffer, 0, valueBufferSize);
    }

    return false;
}

/**
 @Status Interoperable
 @Notes
*/
CFTypeID CTParagraphStyleGetTypeID() {
    return __CTParagraphStyle::GetTypeID();
}