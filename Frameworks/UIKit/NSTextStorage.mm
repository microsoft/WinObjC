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

#include "Starboard.h"

#include "UIKit/NSParagraphStyle.h"

@implementation NSTextStorage {
    NSMutableArray* _layoutManagers;
    NSMutableDictionary* _defaultAttributes;
    NSMutableAttributedString* _composed;
    int _editCount;
}

- (void)_initStorage {
    _layoutManagers = [NSMutableArray new];
    _defaultAttributes = [@{ NSFontAttributeName : [UIFont defaultFont] } mutableCopy];
}

- (instancetype)init {
    _composed = [[NSMutableAttributedString alloc] init];
    [self _initStorage];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithAttributedString:(NSAttributedString*)str {
    _composed = [str mutableCopy];
    [self _initStorage];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string {
    _composed = [[NSMutableAttributedString alloc] initWithString:string];
    [self _initStorage];
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithString:(NSString*)string attributes:(NSDictionary*)attributes {
    _composed = [[NSMutableAttributedString alloc] initWithString:string attributes:attributes];
    [self _initStorage];
    return self;
}

/**
 @Status Interoperable
*/
- (void)addLayoutManager:(NSLayoutManager*)manager {
    if (![_layoutManagers containsObject:manager]) {
        [_layoutManagers addObject:manager];
        [manager setTextStorage:self];
    }
}

- (void)setDefaultAttribute:(id)attr forKey:(NSString*)key {
    if (_defaultAttributes == nil) {
        _defaultAttributes = [NSMutableDictionary new];
    }

    [_defaultAttributes setObject:attr forKey:key];
}

- (NSDictionary*)_combinedAttributes:(NSDictionary*)attributes {
    NSMutableDictionary* combined = nil;
    NSDictionary* ret = attributes;

    for (NSString* key in _defaultAttributes) {
        if (![ret objectForKey:key]) {
            if (combined == nil) {
                combined = [[ret mutableCopy] autorelease];
                ret = combined;
            }

            [combined setObject:[_defaultAttributes objectForKey:key] forKey:key];
        }
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    NSDictionary* ret = [_composed attributesAtIndex:location effectiveRange:range];

    return [self _combinedAttributes:ret];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)attributesAtIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    NSDictionary* ret = [_composed attributesAtIndex:location longestEffectiveRange:range inRange:inRange];

    return [self _combinedAttributes:ret];
}

- (void)dealloc {
    [_layoutManagers release];
    [_defaultAttributes release];
    [super dealloc];
}

- (BOOL)isEqualToAttributedString:(NSAttributedString*)other {
    return [_composed isEqualToAttributedString:other];
}

- (NSUInteger)length {
    return [_composed length];
}

- (NSString*)string {
    return [_composed string];
}

- attribute:(NSString*)name atIndex:(NSUInteger)location effectiveRange:(NSRange*)range {
    return [_composed attribute:name atIndex:location effectiveRange:range];
}

- attribute:(NSString*)name atIndex:(NSUInteger)location longestEffectiveRange:(NSRange*)range inRange:(NSRange)inRange {
    return [_composed attribute:name atIndex:location longestEffectiveRange:range inRange:inRange];
}

- (void)enumerateAttribute:(NSString*)attrName
                   inRange:(NSRange)enumerationRange
                   options:(NSAttributedStringEnumerationOptions)opts
                usingBlock:(void (^)(id value, NSRange range, BOOL* stop))block {
    [_composed enumerateAttribute:attrName inRange:enumerationRange options:opts usingBlock:block];
}

- (NSMutableString*)mutableString {
    return [_composed mutableString];
}

- (void)addAttribute:(NSString*)name value:(id)value range:(NSRange)range {
    [self beginEditing];
    [_composed addAttribute:name value:value range:range];
    [self endEditing];
}

- (void)addAttributes:(NSDictionary*)attributes range:(NSRange)range {
    [self beginEditing];
    [_composed addAttributes:attributes range:range];
    [self endEditing];
}

- (void)appendAttributedString:(NSAttributedString*)attributedString {
    [self beginEditing];
    [_composed appendAttributedString:attributedString];
    [self endEditing];
}

- (void)deleteCharactersInRange:(NSRange)range {
    [self beginEditing];
    [_composed deleteCharactersInRange:range];
    [self endEditing];
}

- (void)removeAttribute:(NSString*)name range:(NSRange)range {
    [self beginEditing];
    [_composed removeAttribute:name range:range];
    [self endEditing];
}

- (void)insertAttributedString:(NSAttributedString*)attributedString atIndex:(NSUInteger)index {
    [self beginEditing];
    [_composed insertAttributedString:attributedString atIndex:index];
    [self endEditing];
}

- (void)replaceCharactersInRange:(NSRange)range withString:(NSString*)string {
    [self beginEditing];
    [_composed replaceCharactersInRange:range withString:string];
    [self endEditing];
}

- (void)replaceCharactersInRange:(NSRange)range withAttributedString:(NSAttributedString*)attributedString {
    [self beginEditing];
    [_composed replaceCharactersInRange:range withAttributedString:attributedString];
    [self endEditing];
}

- (void)setAttributes:(NSDictionary*)attributes range:(NSRange)range {
    [self beginEditing];
    [_composed setAttributes:attributes range:range];
    [self endEditing];
}

- (void)setAttributedString:(NSAttributedString*)attributedString {
    [self beginEditing];
    [_composed setAttributedString:attributedString];
    [self endEditing];
}

/**
 @Status Interoperable
*/
- (void)beginEditing {
    [_composed beginEditing];
    _editCount++;
}

/**
 @Status Interoperable
*/
- (void)processEditing {
    NSRange range = NSMakeRange(0, [self length]);
    for (NSLayoutManager* curManager in _layoutManagers) {
        [curManager processEditingForTextStorage:self
                                          edited:NSTextStorageEditedAttributes | NSTextStorageEditedCharacters
                                           range:range
                                  changeInLength:0
                                invalidatedRange:range];
    }
}

/**
 @Status Interoperable
*/
- (void)endEditing {
    [_composed endEditing];

    if (_editCount > 0) {
        _editCount--;
    }

    if (_editCount == 0) {
        [self processEditing];
    }
}
@end
