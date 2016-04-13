//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <CoreFoundation/CFAttributedString.h>
#import <CoreFoundation/CFString.h>
#import <Foundation/NSAttributedString.h>
#import <Foundation/NSMutableAttributedString.h>

#import "CFAttributedStringInternal.h"
#import "CFUtils.h"

// Helper macros - automatically call equivalent NS function if the caller is not the concrete subclass, and return
#define CALL_NS_FUNC_IF_NONCONCRETE(aStr, ...)                       \
    if ([aStr class] != [NSMutableAttributedStringConcrete class]) { \
        [aStr __VA_ARGS__];                                          \
        return;                                                      \
    }

#define RETURN_NS_FUNC_IF_NONCONCRETE(aStr, returnType, ...)         \
    if ([aStr class] != [NSMutableAttributedStringConcrete class]) { \
        return (__bridge returnType)[aStr __VA_ARGS__];              \
    }

CFAttributedStringRef _CFAttributedStringCreateEmpty(void) {
    return __CFMutableAttributedString::alloc([NSMutableAttributedStringConcrete class]);
}

/**
 @Status Interoperable
*/
CFAttributedStringRef CFAttributedStringCreate(CFAllocatorRef alloc, CFStringRef str, CFDictionaryRef attributes) {
    return (__bridge CFAttributedStringRef)
        [[NSAttributedString alloc] initWithString:(__bridge NSString*)str attributes:(__bridge NSDictionary*)attributes];
}

/**
 @Status Interoperable
*/
CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef alloc, CFAttributedStringRef aStr) {
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFAttributedStringRef, copy);
    return (__bridge CFAttributedStringRef)[[NSAttributedString alloc] initWithAttributedString:(__bridge NSAttributedString*)aStr];
}

/**
 @Status Interoperable
*/
CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef alloc, CFAttributedStringRef aStr, CFRange range) {
    // clang-format off
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFAttributedStringRef, 
        attributedSubstringFromRange:*reinterpret_cast<NSRange*>(&range));
    // clang-format on

    CFAttributedStringRef ret = CFAttributedStringCreateMutableCopy(alloc, CFAttributedStringGetLength(aStr), aStr);

    // Remove the section of the string before the range
    if (range.location > 0) {
        CFAttributedStringReplaceString(ret, { 0, range.location }, (__bridge CFStringRef) @"");
    }

    // The range to keep now must extend from 0 to range.length
    // Remove the section of the string after the range to keep
    CFIndex retLength = CFAttributedStringGetLength(ret);
    if (range.length < retLength) {
        CFAttributedStringReplaceString(ret, { range.length, retLength - range.length }, (__bridge CFStringRef) @"");
    }

    return ret;
}

/**
 @Status Interoperable
*/
CFIndex CFAttributedStringGetLength(CFAttributedStringRef aStr) {
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFIndex, length);
    return aStr->getLength();
}

/**
 @Status Interoperable
*/
CFStringRef CFAttributedStringGetString(CFAttributedStringRef aStr) {
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFStringRef, string);
    return aStr->getString();
}

/**
 @Status Interoperable
*/
CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange* effectiveRange) {
    // clang-format off
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFTypeRef, 
        attribute:(__bridge NSString*)attrName atIndex:loc effectiveRange:reinterpret_cast<NSRange*>(effectiveRange));
    // clang-format on

    return aStr->getAttribute(loc, attrName, effectiveRange);
}

/**
 @Status Interoperable
*/
CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef aStr, CFIndex loc, CFRange* effectiveRange) {
    // clang-format off
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFDictionaryRef, 
        attributesAtIndex:loc effectiveRange:reinterpret_cast<NSRange*>(effectiveRange));
    // clang-format on

    return aStr->getAttributes(loc, effectiveRange);
}

/**
 @Status Interoperable
*/
CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(
    CFAttributedStringRef aStr, CFIndex loc, CFStringRef attrName, CFRange inRange, CFRange* longestEffectiveRange) {
    // clang-format off
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFTypeRef,
        attribute:(__bridge NSString*)attrName atIndex:loc longestEffectiveRange:reinterpret_cast<NSRange*>(longestEffectiveRange) 
        inRange:*reinterpret_cast<NSRange*>(&inRange));
    // clang-format on

    CFTypeRef returnValue = CFAttributedStringGetAttribute(aStr, loc, attrName, longestEffectiveRange);

    if (longestEffectiveRange) {
        *longestEffectiveRange = CFRangeIntersection(inRange, *longestEffectiveRange);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef aStr,
                                                                        CFIndex loc,
                                                                        CFRange inRange,
                                                                        CFRange* longestEffectiveRange) {
    // clang-format off
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFDictionaryRef, 
        attributesAtIndex:loc longestEffectiveRange:reinterpret_cast<NSRange*>(longestEffectiveRange) 
        inRange:*reinterpret_cast<NSRange*>(&inRange));
    // clang-format on

    CFDictionaryRef returnValue = CFAttributedStringGetAttributes(aStr, loc, longestEffectiveRange);

    if (longestEffectiveRange) {
        *longestEffectiveRange = CFRangeIntersection(inRange, *longestEffectiveRange);
    }

    return returnValue;
}

// CFMutableAttributedString functions

/**
 @Status Interoperable
*/
CFMutableAttributedStringRef CFAttributedStringCreateMutable(CFAllocatorRef alloc, CFIndex maxLength) {
    return _CFAttributedStringCreateEmpty();
}

/**
 @Status Interoperable
*/
CFMutableAttributedStringRef CFAttributedStringCreateMutableCopy(CFAllocatorRef alloc, CFIndex maxLength, CFAttributedStringRef aStr) {
    RETURN_NS_FUNC_IF_NONCONCRETE((__bridge NSAttributedString*)aStr, CFMutableAttributedStringRef, mutableCopy);
    return CFAttributedStringCreateCopy(alloc, aStr);
}

/**
 @Status Interoperable
*/
void CFAttributedStringBeginEditing(CFMutableAttributedStringRef aStr) {
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, beginEditing);
    aStr->beginEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringEndEditing(CFMutableAttributedStringRef aStr) {
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, endEditing);
    aStr->endEditing();
}

/**
 @Status Stub
 @Notes  Needs more full-featured CF(Mutable)String implementation, and probably more stable KVO, before this can be brought up
 TODO: 5505196
 */
CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef aStr) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Interoperable
*/
void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef name) {
    // clang-format off
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, 
        removeAttribute:(__bridge NSString*)name range:*reinterpret_cast<NSRange*>(&range));
    // clang-format on

    aStr->removeAttribute(range, name);
    aStr->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringReplaceString(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef replacement) {
    // clang-format off
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, 
        replaceCharactersInRange:*reinterpret_cast<NSRange*>(&range) withString:(__bridge NSString*)replacement);
    // clang-format on

    aStr->replaceString(range, replacement);
    aStr->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef aStr, CFRange range, CFAttributedStringRef replacement) {
    // clang-format off
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, 
        replaceCharactersInRange:*reinterpret_cast<NSRange*>(&range) withAttributedString:(__bridge NSAttributedString*)replacement);
    // clang-format on

    // Check whether the attributed string to replace in is of the concrete class (has understood storage)
    NSAttributedString* nsReplacement = (__bridge NSAttributedString*)replacement;
    if ([nsReplacement class] != [NSMutableAttributedStringConcrete class]) {
        // Convert the attributed string to the NSMutableAttributedString base class, for which the storage is known to CF
        // TODO 6749418 - this could probably be more efficient...
        __block NSMutableAttributedString* attrStringToUse = [[NSMutableAttributedString alloc] initWithString:[nsReplacement string]];

        [nsReplacement enumerateAttributesInRange:{ 0, [nsReplacement length] }
                                          options:NSAttributedStringEnumerationLongestEffectiveRangeNotRequired
                                       usingBlock:^void(NSDictionary* val, NSRange range, BOOL* stop) {
                                           [attrStringToUse addAttributes:val range:range];
                                       }];

        aStr->replaceAttributedString(range, (__bridge CFMutableAttributedStringRef)attrStringToUse);
        [attrStringToUse release];

    } else {
        aStr->replaceAttributedString(range, replacement);
    }
}

/**
 @Status Interoperable
*/
void CFAttributedStringSetAttribute(CFMutableAttributedStringRef aStr, CFRange range, CFStringRef name, CFTypeRef value) {
    // clang-format off
    CALL_NS_FUNC_IF_NONCONCRETE((__bridge NSMutableAttributedString*)aStr, 
        addAttribute:(__bridge NSString*)name value:(id)value range:*reinterpret_cast<NSRange*>(&range));
    // clang-format on

    aStr->setAttribute(range, name, value);
    aStr->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringSetAttributes(CFMutableAttributedStringRef aStr,
                                     CFRange range,
                                     CFDictionaryRef replacement,
                                     Boolean clearOtherAttributes) {
    if ([(__bridge NSAttributedString*)aStr class] != [NSMutableAttributedStringConcrete class]) {
        if (clearOtherAttributes) {
            [(__bridge NSMutableAttributedString*)aStr addAttributes:(__bridge NSDictionary*)replacement
                                                               range:*reinterpret_cast<NSRange*>(&range)];
        } else {
            [(__bridge NSMutableAttributedString*)aStr setAttributes:(__bridge NSDictionary*)replacement
                                                               range:*reinterpret_cast<NSRange*>(&range)];
        }
        return;
    }

    aStr->setAttributes(range, replacement, clearOtherAttributes);
}