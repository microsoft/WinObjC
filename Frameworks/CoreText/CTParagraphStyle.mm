//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <stddef.h>

static const size_t MAX_SPECIFIER_COUNT = 16;

// PropertyInfo is the struct containing the expected size of data and an offset to the struct which has the actual data.
struct PropertyInfo {
    size_t expectedSize;
    size_t offset;
};

// this table contains the expected size of the data for any specifier, and its offset in the structure.
static PropertyInfo propertyInfoTable[] = {

        [kCTParagraphStyleSpecifierAlignment] =
            {
                sizeof(CTTextAlignment), offsetof(_CTParagraphStyleProperties, _alignment),
            },

        [kCTParagraphStyleSpecifierFirstLineHeadIndent] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _firstLineHeadIndent),
            },
        [kCTParagraphStyleSpecifierHeadIndent] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _headIndent),
            },
        [kCTParagraphStyleSpecifierTailIndent] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _tailIndent),
            },
        [kCTParagraphStyleSpecifierDefaultTabInterval] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _tabInterval),
            },
        [kCTParagraphStyleSpecifierLineBreakMode] =
            {
                sizeof(CTLineBreakMode), offsetof(_CTParagraphStyleProperties, _lineBreakMode),
            },
        [kCTParagraphStyleSpecifierLineHeightMultiple] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _lineHeightMultiple),
            },
        [kCTParagraphStyleSpecifierMaximumLineHeight] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _maximumLineHeight),
            },
        [kCTParagraphStyleSpecifierMinimumLineHeight] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _minimumLineHeight),
            },
        [kCTParagraphStyleSpecifierLineSpacing] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _lineSpacing),
            },
        [kCTParagraphStyleSpecifierParagraphSpacing] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _paragraphSpacing),
            },
        [kCTParagraphStyleSpecifierParagraphSpacingBefore] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _paragraphSpacingBefore),
            },
        [kCTParagraphStyleSpecifierBaseWritingDirection] =
            {
                sizeof(CTWritingDirection), offsetof(_CTParagraphStyleProperties, _writingDirection),
            },
        [kCTParagraphStyleSpecifierMaximumLineSpacing] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _maximumLineSpacing),
            },
        [kCTParagraphStyleSpecifierMinimumLineSpacing] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _minimumLineSpacing),
            },
        [kCTParagraphStyleSpecifierLineSpacingAdjustment] =
            {
                sizeof(CGFloat), offsetof(_CTParagraphStyleProperties, _lineSpacingAdjustment),
            },

};

@implementation _CTParagraphStyle

- (id)init {
    self->_properties._maximumLineSpacing._isDefault = true;
    self->_properties._maximumLineSpacing._value = 10000000.0f;

    return self;
}
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}
@end

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops and kCTParagraphStyleSpecifierCount not supported
*/
CTParagraphStyleRef CTParagraphStyleCreate(const CTParagraphStyleSetting* settings, size_t settingsCount) {
    _CTParagraphStyle* ret = [_CTParagraphStyle new];

    if (settings) {
        _CTParagraphStyleProperties* paraStyleProperty = &ret->_properties;
        for (size_t i = 0; i < settingsCount; ++i) {
            // validate input specifier and the buffer
            if (settings[i].spec <= MAX_SPECIFIER_COUNT && settings[i].value != nullptr) {
                size_t expectedSize = propertyInfoTable[settings[i].spec].expectedSize;

                if (settings[i].valueSize == expectedSize) {
                    // structContainingData is the struct that contains the actual data and a bool varibale _isDefault to store if data has
                    // a default value or it has been set by the user.
                    // offsetToDefaultStatus is the offset to this struct, which is also in turn the offset to _isDefault bool variable
                    // within the struct.
                    size_t offsetToDefaultStatus = propertyInfoTable[settings[i].spec].offset;
                    auto structContainingData =
                        reinterpret_cast<void*>((reinterpret_cast<char*>(paraStyleProperty) + offsetToDefaultStatus));
                    *(reinterpret_cast<bool*>(structContainingData)) = false;

                    if (expectedSize == sizeof(CGFloat)) {
                        auto property = reinterpret_cast<_CTParagraphStyleFloatProperty*>(structContainingData);

                        size_t offsetForValue = offsetof(_CTParagraphStyleFloatProperty, _value);
                        auto locationToWrite = reinterpret_cast<char*>(property) + offsetForValue;
                        *reinterpret_cast<CGFloat*>(locationToWrite) = *reinterpret_cast<const CGFloat*>(settings[i].value);

                    } else if (settings[i].spec == kCTParagraphStyleSpecifierBaseWritingDirection) {
                        auto property = reinterpret_cast<_CTParagraphStyleCTWritingDirectionProperty*>(structContainingData);

                        size_t offsetForValue = offsetof(_CTParagraphStyleCTWritingDirectionProperty, _value);
                        auto locationToWrite = reinterpret_cast<char*>(property) + offsetForValue;
                        *reinterpret_cast<CTWritingDirection*>(locationToWrite) =
                            *reinterpret_cast<const CTWritingDirection*>(settings[i].value);
                    } else if (settings[i].spec == kCTParagraphStyleSpecifierAlignment) {
                        auto property = reinterpret_cast<_CTParagraphStyleCTTextAlignmentProperty*>(structContainingData);

                        size_t offsetForValue = offsetof(_CTParagraphStyleCTTextAlignmentProperty, _value);
                        auto locationToWrite = reinterpret_cast<char*>(property) + offsetForValue;
                        *reinterpret_cast<CTTextAlignment*>(locationToWrite) = *reinterpret_cast<const CTTextAlignment*>(settings[i].value);

                    } else if (settings[i].spec == kCTParagraphStyleSpecifierLineBreakMode) {
                        auto property = reinterpret_cast<_CTParagraphStyleCTLineBreakModeProperty*>(structContainingData);

                        size_t offsetForValue = offsetof(_CTParagraphStyleCTLineBreakModeProperty, _value);
                        auto locationToWrite = reinterpret_cast<char*>(property) + offsetForValue;
                        *reinterpret_cast<CTLineBreakMode*>(locationToWrite) = *reinterpret_cast<const CTLineBreakMode*>(settings[i].value);
                    }
                }
            }
        }
    }

    return static_cast<CTParagraphStyleRef>(ret);
}

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops and kCTParagraphStyleSpecifierCount not supported
*/
CTParagraphStyleRef CTParagraphStyleCreateCopy(CTParagraphStyleRef paragraphStyle) {
    if (!paragraphStyle) {
        return nil;
    }

    _CTParagraphStyle* ret = [static_cast<_CTParagraphStyle*>(paragraphStyle) copy];
    return static_cast<CTParagraphStyleRef>(ret);
}

/**
 @Status Caveat
 @Notes CTParagraphStyleSpecifier kCTParagraphStyleSpecifierTabStops and kCTParagraphStyleSpecifierCount not supported
*/
bool CTParagraphStyleGetValueForSpecifier(CTParagraphStyleRef paragraphStyle,
                                          CTParagraphStyleSpecifier spec,
                                          size_t valueBufferSize,
                                          void* valueBuffer) {
    if (!paragraphStyle || !valueBuffer) {
        return false;
    }

    _CTParagraphStyle* paraStyle = static_cast<_CTParagraphStyle*>(paragraphStyle);
    bool isDefaultValue = true;

    if (spec <= MAX_SPECIFIER_COUNT) {
        _CTParagraphStyleProperties* paraStyleProperty = &paraStyle->_properties;

        // structContainingData is the struct that contains the actual data and a bool varibale _isDefault to store if data has a default
        // value or it has been set by the user.
        // offsetToDefaultStatus is the offset to this struct, which is also in turn the offset to _isDefault bool variable within the
        // struct.
        size_t offsetToDefaultStatus = propertyInfoTable[spec].offset;
        auto structContainingData = reinterpret_cast<void*>((reinterpret_cast<char*>(paraStyleProperty) + offsetToDefaultStatus));
        isDefaultValue = *(reinterpret_cast<bool*>(structContainingData));

        size_t expectedSize = propertyInfoTable[spec].expectedSize;
        if (expectedSize == sizeof(CGFloat)) {
            auto property = reinterpret_cast<_CTParagraphStyleFloatProperty*>(structContainingData);

            size_t offsetForValue = offsetof(_CTParagraphStyleFloatProperty, _value);
            auto locationTocopy = reinterpret_cast<char*>(property) + offsetForValue;
            *reinterpret_cast<CGFloat*>(valueBuffer) = *reinterpret_cast<CGFloat*>(locationTocopy);
        } else if (spec == kCTParagraphStyleSpecifierBaseWritingDirection) {
            auto property = reinterpret_cast<_CTParagraphStyleCTWritingDirectionProperty*>(structContainingData);

            size_t offsetForValue = offsetof(_CTParagraphStyleCTWritingDirectionProperty, _value);
            auto locationTocopy = reinterpret_cast<char*>(property) + offsetForValue;
            *reinterpret_cast<CTWritingDirection*>(valueBuffer) = *reinterpret_cast<CTWritingDirection*>(locationTocopy);
        } else if (spec == kCTParagraphStyleSpecifierAlignment) {
            auto property = reinterpret_cast<_CTParagraphStyleCTTextAlignmentProperty*>(structContainingData);

            size_t offsetForValue = offsetof(_CTParagraphStyleCTTextAlignmentProperty, _value);
            auto locationTocopy = reinterpret_cast<char*>(property) + offsetForValue;
            *reinterpret_cast<CTTextAlignment*>(valueBuffer) = *reinterpret_cast<CTTextAlignment*>(locationTocopy);
        } else if (spec == kCTParagraphStyleSpecifierLineBreakMode) {
            auto property = reinterpret_cast<_CTParagraphStyleCTLineBreakModeProperty*>(structContainingData);

            size_t offsetForValue = offsetof(_CTParagraphStyleCTLineBreakModeProperty, _value);
            auto locationTocopy = reinterpret_cast<char*>(property) + offsetForValue;
            *reinterpret_cast<CTLineBreakMode*>(valueBuffer) = *reinterpret_cast<CTLineBreakMode*>(locationTocopy);
        }
    }

    return !isDefaultValue;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTParagraphStyleGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}