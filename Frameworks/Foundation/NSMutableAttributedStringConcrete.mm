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
#import "NSMutableAttributedStringConcrete.h"
#import "CFFoundationInternal.h"

#import <algorithm>

@implementation NSMutableAttributedStringConcrete

BRIDGED_CLASS_REQUIRED_IMPLS(CFAttributedStringRef, CFAttributedStringGetTypeID, NSAttributedString, NSMutableAttributedStringConcrete)

/**
 @Status Interoperable
*/
- (instancetype)initWithAttributedString:(NSAttributedString*)string {
    NSMutableAttributedStringConcrete* newSelf = nullptr;
    // need to figure out if this is a mutable init or not.
    if ([self isMemberOfClass:[NSMutableAttributedString class]]) {
        newSelf = reinterpret_cast<NSMutableAttributedStringConcrete*>(static_cast<NSMutableAttributedString*>(
            CFAttributedStringCreateMutableCopy(NULL, [string length], static_cast<CFAttributedStringRef>(string))));
    } else {
        newSelf = reinterpret_cast<NSMutableAttributedStringConcrete*>(static_cast<NSAttributedString*>(
            CFAttributedStringCreateWithSubstring(NULL, static_cast<CFAttributedStringRef>(string), CFRange{ 0, [string length] })));
    }

    [self release];
    self = newSelf;
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    NSMutableAttributedStringConcrete* newSelf = nullptr;
    // need to figure out if this is a mutable init or not.
    if ([self isMemberOfClass:[NSMutableAttributedString class]]) {
        newSelf = reinterpret_cast<NSMutableAttributedStringConcrete*>(
            static_cast<NSMutableAttributedString*>(CFAttributedStringCreateMutable(NULL, 0)));
        CFAttributedStringReplaceString(static_cast<CFMutableAttributedStringRef>(newSelf),
                                        CFRange{ 0, 0 },
                                        static_cast<CFStringRef>(string));
        CFAttributedStringSetAttributes(static_cast<CFMutableAttributedStringRef>(newSelf),
                                        CFRange{ 0, [string length] },
                                        static_cast<CFDictionaryRef>(attributes),
                                        YES);
    } else {
        newSelf = reinterpret_cast<NSMutableAttributedStringConcrete*>(static_cast<NSAttributedString*>(
            CFAttributedStringCreate(NULL, static_cast<CFStringRef>(string), static_cast<CFDictionaryRef>(attributes))));
    }

    [self release];
    self = newSelf;
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [self initWithString:static_cast<NSString*>(CFSTR("")) count:nullptr];
}

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
    return (__bridge NSMutableString*)CFAttributedStringGetMutableString(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range {
    CFAttributedStringSetAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                   *reinterpret_cast<CFRange*>(&range),
                                   (__bridge CFStringRef)name,
                                   value);
}

- (void)removeAttribute:(NSString*)name range:(NSRange)range {
    CFAttributedStringRemoveAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                      *reinterpret_cast<CFRange*>(&range),
                                      (__bridge CFStringRef)name);
}

- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range {
    CFAttributedStringSetAttributes(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    *reinterpret_cast<CFRange*>(&range),
                                    (__bridge CFDictionaryRef)attributes,
                                    true);
}

- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string {
    CFAttributedStringReplaceString(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    *reinterpret_cast<CFRange*>(&range),
                                    (__bridge CFStringRef)string);
}

- (void)beginEditing {
    CFAttributedStringBeginEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

- (void)endEditing {
    CFAttributedStringEndEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

@end