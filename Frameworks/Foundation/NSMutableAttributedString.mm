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

#import <Foundation/NSMutableAttributedString.h>
#import <CoreFoundation/CFAttributedString.h>

@implementation NSMutableAttributedString

/**
 @Status Stub
*/
- (NSMutableString*)mutableString {
    return (__bridge NSMutableString*)CFAttributedStringGetMutableString(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range {
    CFAttributedStringSetAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                   CFRangeMake(range.location, range.length),
                                   (__bridge CFStringRef)name,
                                   value);
}

/**
 @Status Interoperable
*/
- (void)addAttributes:(NSDictionary*)attributes range:(NSRange)range {
    CFAttributedStringSetAttributes(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    CFRangeMake(range.location, range.length),
                                    (__bridge CFDictionaryRef)attributes,
                                    false);
}

/**
 @Status Interoperable
*/
- (void)appendAttributedString:(NSAttributedString*)attributedString {
    [self replaceCharactersInRange:NSMakeRange([self length], 0) withAttributedString:attributedString];
}

/**
 @Status Interoperable
*/
- (void)deleteCharactersInRange:(NSRange)range {
    [self replaceCharactersInRange:range withString:@""];
}

/**
 @Status Interoperable
*/
- (void)removeAttribute:(NSString*)name range:(NSRange)range {
    CFAttributedStringRemoveAttribute(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                      CFRangeMake(range.location, range.length),
                                      (__bridge CFStringRef)name);
}

/**
 @Status Interoperable
 */
- (void)insertAttributedString:(NSAttributedString*)attributedString atIndex:(NSUInteger)index {
    [self replaceCharactersInRange:NSMakeRange(index, 0) withAttributedString:attributedString];
}

/**
 @Status Interoperable
*/
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string {
    CFAttributedStringReplaceString(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    CFRangeMake(range.location, range.length),
                                    (__bridge CFStringRef)string);
}

/**
 @Status Interoperable
*/
- (void)replaceCharactersInRange:(NSRange)range withAttributedString:(NSAttributedString*)attributedString {
    CFAttributedStringReplaceAttributedString(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                              CFRangeMake(range.location, range.length),
                                              (__bridge CFAttributedStringRef)attributedString);
}

/**
 @Status Interoperable
*/
- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range {
    CFAttributedStringSetAttributes(reinterpret_cast<CFMutableAttributedStringRef>(self),
                                    CFRangeMake(range.location, range.length),
                                    (__bridge CFDictionaryRef)attributes,
                                    true);
}

/**
 @Status Interoperable
*/
- (void)setAttributedString:(NSAttributedString*)attributedString {
    [self replaceCharactersInRange:NSMakeRange(0, [self length]) withAttributedString:attributedString];
}

/**
 @Status Interoperable
*/
- (void)beginEditing {
    CFAttributedStringBeginEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

/**
 @Status Interoperable
*/
- (void)endEditing {
    CFAttributedStringEndEditing(reinterpret_cast<CFMutableAttributedStringRef>(self));
}

@end
