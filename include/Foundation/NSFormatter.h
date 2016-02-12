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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

@class NSString;
@class NSAttributedString;
@class NSDictionary;

typedef NSUInteger NSFormattingUnitStyle;
typedef NSUInteger NSFormattingContext;
enum {
    NSFormattingUnitStyleShort = 1,
    NSFormattingUnitStyleMedium,
    NSFormattingUnitStyleLong,
};

enum {
    NSFormattingContextUnknown = 0,
    NSFormattingContextDynamic = 1,
    NSFormattingContextStandalone = 2,
    NSFormattingContextListItem = 3,
    NSFormattingContextBeginningOfSentence = 4,
    NSFormattingContextMiddleOfSentence = 5,
};

FOUNDATION_EXPORT_CLASS
@interface NSFormatter : NSObject <NSCoding, NSCopying>
- (NSAttributedString*)attributedStringForObjectValue:(id)anObject withDefaultAttributes:(NSDictionary*)attributes STUB_METHOD;
- (NSString*)editingStringForObjectValue:(id)anObject STUB_METHOD;
- (BOOL)isPartialStringValid:(NSString*)partialString
            newEditingString:(NSString* _Nullable*)newString
            errorDescription:(NSString* _Nullable*)error STUB_METHOD;

- (BOOL)isPartialStringValid:(NSString* _Nonnull*)partialStringPtr
       proposedSelectedRange:(NSRangePointer)proposedSelRangePtr
              originalString:(NSString*)origString
       originalSelectedRange:(NSRange)origSelRange
            errorDescription:(NSString* _Nullable*)error STUB_METHOD;

/* Abstract Methods */
- (NSString*)stringForObjectValue:(id)anObject;
- (BOOL)getObjectValue:(id _Nullable*)anObject forString:(NSString*)string errorDescription:(NSString* _Nullable*)error;
@end
