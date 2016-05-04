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
#import <NSRaise.h>

#import "NSCFAttributedString.h"
#import "BridgeHelpers.h"

@implementation NSMutableAttributedString

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSMutableAttributedString, NSMutableAttributedStringPrototype);

/**
 @Status Stub
 @Notes Not implemented on the concrete subclass.
*/
- (NSMutableString*)mutableString {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeAttribute:(NSString*)name range:(NSRange)range {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string {
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)addAttributes:(NSDictionary*)attributes range:(NSRange)range {
    for (NSString* name in attributes) {
        [self addAttribute:name value:[attributes objectForKey:name] range:range];
    }
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
- (void)insertAttributedString:(NSAttributedString*)attributedString atIndex:(NSUInteger)index {
    [self replaceCharactersInRange:NSMakeRange(index, 0) withAttributedString:attributedString];
}

/**
 @Status Interoperable
*/
- (void)replaceCharactersInRange:(NSRange)replaceRange withAttributedString:(NSAttributedString*)attributedString {
    [self replaceCharactersInRange:replaceRange withString:[attributedString string]];

    [attributedString enumerateAttributesInRange:{ 0, [attributedString length] }
                                         options:0
                                      usingBlock:^void(NSDictionary* val, NSRange range, BOOL* stop) {
                                          [self setAttributes:val range:{ range.location + replaceRange.location, range.length }];
                                      }];
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
- (void)beginEditing{
    // Default implementation is a no-op
}

    /**
     @Status Interoperable
    */
    - (void)endEditing {
    // Default implementation is a no-op
}

@end