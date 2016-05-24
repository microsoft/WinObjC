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

#import <CoreFoundation/CFAttributedString.h>
#import <Foundation/NSAttributedString.h>
#import <Foundation/NSMutableAttributedString.h>
#import "NSCFAttributedString.h"
#import "CFFoundationInternal.h"

#import <algorithm>

#pragma region NSAttributedStringPrototype
@implementation NSAttributedStringPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (_Nullable instancetype)init {
    return [self initWithString:@"" attributes:nil];
}

- (_Nullable instancetype)initWithAttributedString:(NSAttributedString*)string {
    return reinterpret_cast<NSAttributedStringPrototype*>(static_cast<NSAttributedString*>(
        CFAttributedStringCreateWithSubstring(kCFAllocatorDefault, static_cast<CFAttributedStringRef>(string), CFRange{ 0, [string length] })));
}

- (_Nullable instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    return reinterpret_cast<NSAttributedStringPrototype*>(static_cast<NSAttributedString*>(
        CFAttributedStringCreate(kCFAllocatorDefault, static_cast<CFStringRef>(string), static_cast<CFDictionaryRef>(attributes))));
}

@end

#pragma endregion

#pragma region NSMutableAttributedStringPrototype
@implementation NSMutableAttributedStringPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (_Nullable instancetype)init {
    return [self initWithString:@"" attributes:nil];
}

- (_Nullable instancetype)initWithAttributedString:(NSAttributedString*)string {
    return reinterpret_cast<NSMutableAttributedStringPrototype*>(CFAttributedStringCreateMutableCopy(kCFAllocatorDefault, 0, static_cast<CFAttributedStringRef>(string)));
}

- (_Nullable instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    NSMutableAttributedString* attributedString = static_cast<NSMutableAttributedString*>(CFAttributedStringCreateMutable(kCFAllocatorDefault, 0));
    CFAttributedStringReplaceString(static_cast<CFMutableAttributedStringRef>(attributedString),
                                    CFRange{ 0, 0 },
                                    static_cast<CFStringRef>(string));
    CFAttributedStringSetAttributes(static_cast<CFMutableAttributedStringRef>(attributedString),
                                    CFRange{ 0, [string length] },
                                    static_cast<CFDictionaryRef>(attributes),
                                    YES);

    return reinterpret_cast<NSMutableAttributedStringPrototype*>(attributedString);
}

@end
#pragma endregion

#pragma region NSCF Bridged Class
@interface NSCFAttributedString : NSMutableAttributedString
@end

@implementation NSCFAttributedString

BRIDGED_CLASS_REQUIRED_IMPLS(CFAttributedStringRef, CFAttributedStringGetTypeID, NSAttributedString, NSCFAttributedString)

- (NSString*)string {
    return (__bridge NSString*)CFAttributedStringGetString(reinterpret_cast<CFAttributedStringRef>(self));
}

- (id)attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    return (__bridge id)CFAttributedStringGetAttribute(reinterpret_cast<CFAttributedStringRef>(self),
                                                       location,
                                                       (__bridge CFStringRef)name,
                                                       reinterpret_cast<CFRange*>(range));
}

- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    return (__bridge NSDictionary*)CFAttributedStringGetAttributes(reinterpret_cast<CFAttributedStringRef>(self),
                                                                   location,
                                                                   reinterpret_cast<CFRange*>(range));
}

- (NSMutableString*)mutableString {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    return (__bridge NSMutableString*)CFAttributedStringGetMutableString(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    THROW_NS_IF_FALSE(E_BOUNDS, ((range.location + range.length) <= [self length]));

    CFAttributedStringSetAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                   *reinterpret_cast<CFRange*>(&range),
                                   (__bridge CFStringRef)name,
                                   value);
}

- (void)removeAttribute:(NSString*)name range:(NSRange)range {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    CFAttributedStringRemoveAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                      *reinterpret_cast<CFRange*>(&range),
                                      (__bridge CFStringRef)name);
}

- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    CFAttributedStringSetAttributes(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    *reinterpret_cast<CFRange*>(&range),
                                    (__bridge CFDictionaryRef)attributes,
                                    true);
}

- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    CFAttributedStringReplaceString(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    *reinterpret_cast<CFRange*>(&range),
                                    (__bridge CFStringRef)string);
}

- (void)beginEditing {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    CFAttributedStringBeginEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

- (void)endEditing {
    BRIDGED_THROW_IF_IMMUTABLE(_CFAttributedStringIsMutable, CFAttributedStringRef);
    CFAttributedStringEndEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

- (NSObject*)copyWithZone:(NSZone*)zone {
    if (_CFAttributedStringIsMutable((CFAttributedStringRef)self)) {
        return (NSObject*)CFAttributedStringCreateCopy(kCFAllocatorDefault, (CFAttributedStringRef)self);
    }

    return [self retain];
}

- (NSObject*)mutableCopyWithZone:(NSZone*)zone {
    return (NSObject*)CFAttributedStringCreateMutableCopy(kCFAllocatorDefault, 0, (CFAttributedStringRef)self);
}

@end

#pragma endregion