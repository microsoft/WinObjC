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

CFAttributedStringRef _CFAttributedStringCreateEmpty(void) {
    return __CFMutableAttributedString::alloc([NSMutableAttributedString class]);
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
CFAttributedStringRef CFAttributedStringCreateCopy(CFAllocatorRef alloc, CFAttributedStringRef self) {
    return (__bridge CFAttributedStringRef)[[NSAttributedString alloc] initWithAttributedString:(__bridge NSAttributedString*)self];
}

/**
 @Status Interoperable
*/
CFAttributedStringRef CFAttributedStringCreateWithSubstring(CFAllocatorRef alloc, CFAttributedStringRef self, CFRange range) {
    CFAttributedStringRef ret = CFAttributedStringCreateCopy(alloc, self);

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
CFIndex CFAttributedStringGetLength(CFAttributedStringRef self) {
    return self->getLength();
}

/**
 @Status Interoperable
*/
CFStringRef CFAttributedStringGetString(CFAttributedStringRef self) {
    return self->getString();
}

/**
 @Status Interoperable
*/
CFTypeRef CFAttributedStringGetAttribute(CFAttributedStringRef self, CFIndex loc, CFStringRef attrName, CFRange* effectiveRange) {
    return self->getAttribute(loc, attrName, effectiveRange);
}

/**
 @Status Interoperable
*/
CFDictionaryRef CFAttributedStringGetAttributes(CFAttributedStringRef self, CFIndex loc, CFRange* effectiveRange) {
    return self->getAttributes(loc, effectiveRange);
}

/**
 @Status Interoperable
*/
CFTypeRef CFAttributedStringGetAttributeAndLongestEffectiveRange(
    CFAttributedStringRef self, CFIndex loc, CFStringRef attrName, CFRange inRange, CFRange* longestEffectiveRange) {
    CFRange effectiveUnclippedRange;
    CFTypeRef returnValue =
        CFAttributedStringGetAttribute(self, loc, attrName, (longestEffectiveRange) ? &effectiveUnclippedRange : nullptr);

    if (longestEffectiveRange) {
        *longestEffectiveRange = CFRangeIntersection(inRange, effectiveUnclippedRange);
    }

    return returnValue;
}

/**
 @Status Interoperable
*/
CFDictionaryRef CFAttributedStringGetAttributesAndLongestEffectiveRange(CFAttributedStringRef self,
                                                                        CFIndex loc,
                                                                        CFRange inRange,
                                                                        CFRange* longestEffectiveRange) {
    CFRange effectiveUnclippedRange;
    CFDictionaryRef returnValue = CFAttributedStringGetAttributes(self, loc, (longestEffectiveRange) ? &effectiveUnclippedRange : nullptr);

    if (longestEffectiveRange) {
        *longestEffectiveRange = CFRangeIntersection(inRange, effectiveUnclippedRange);
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
    return CFAttributedStringCreateCopy(alloc, aStr);
}

/**
 @Status Interoperable
*/
void CFAttributedStringBeginEditing(CFMutableAttributedStringRef self) {
    self->beginEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringEndEditing(CFMutableAttributedStringRef self) {
    self->endEditing();
}

/**
 @Status Stub
 @Notes  Needs more full-featured CF(Mutable)String implementation, and probably more stable KVO, before this can be brought up
 TODO: 5505196
 */
CFMutableStringRef CFAttributedStringGetMutableString(CFMutableAttributedStringRef self) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Interoperable
*/
void CFAttributedStringRemoveAttribute(CFMutableAttributedStringRef self, CFRange range, CFStringRef name) {
    self->removeAttribute(range, name);
    self->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringReplaceString(CFMutableAttributedStringRef self, CFRange range, CFStringRef replacement) {
    self->replaceString(range, replacement);
    self->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringReplaceAttributedString(CFMutableAttributedStringRef self, CFRange range, CFAttributedStringRef replacement) {
    self->replaceAttributedString(range, replacement);
}

/**
 @Status Interoperable
*/
void CFAttributedStringSetAttribute(CFMutableAttributedStringRef self, CFRange range, CFStringRef name, CFTypeRef value) {
    self->setAttribute(range, name, value);
    self->fixAttributesIfNotEditing();
}

/**
 @Status Interoperable
*/
void CFAttributedStringSetAttributes(CFMutableAttributedStringRef self,
                                     CFRange range,
                                     CFDictionaryRef replacement,
                                     Boolean clearOtherAttributes) {
    self->setAttributes(range, replacement, clearOtherAttributes);
}