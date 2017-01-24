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

#include "Starboard.h"
#import <StubReturn.h>

#import <UIKit/NSParagraphStyle.h>
#import <UIKit/UIGraphics.h>
#import "NSParagraphStyleInternal.h"

@implementation NSParagraphStyle

- (void)dealloc {
    [_tabStops release];
    [super dealloc];
}

- (instancetype)init {
    if (self = [super init]) {
        self.alignment = NSTextAlignmentNatural;
        self.lineBreakMode = NSLineBreakByWordWrapping;
        self.baseWritingDirection = NSWritingDirectionNatural;
    }

    return self;
}

/**
 @Status Caveat
 @Notes Tab Stops not supported
*/
+ (NSParagraphStyle*)defaultParagraphStyle {
    static StrongId<NSParagraphStyle> _default{[[self new] autorelease] };
    return _default.get();
}

/**
 @Status Stub
*/
+ (NSWritingDirection)defaultWritingDirectionForLanguage:(NSString*)languageName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    NSMutableParagraphStyle* copy = [[NSMutableParagraphStyle alloc] init];
    [copy setParagraphStyle:self];
    return copy;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    if (self = [super init]) {
        _alignment = (NSTextAlignment)[decoder decodeInt64ForKey:@"_NSParagraphStyle._alignment"];
        _firstLineHeadIndent = [decoder decodeFloatForKey:@"_NSParagraphStyle._firstLineHeadIndent"];
        _headIndent = [decoder decodeFloatForKey:@"_NSParagraphStyle._headIndent"];
        _tailIndent = [decoder decodeFloatForKey:@"_NSParagraphStyle._tailIndent"];
        _lineBreakMode = [decoder decodeInt64ForKey:@"_NSParagraphStyle._lineBreakMode"];
        _maximumLineHeight = [decoder decodeFloatForKey:@"_NSParagraphStyle._maximumLineHeight"];
        _minimumLineHeight = [decoder decodeFloatForKey:@"_NSParagraphStyle._minimumLineHeight"];
        _lineSpacing = [decoder decodeFloatForKey:@"_NSParagraphStyle._lineSpacing"];
        _paragraphSpacing = [decoder decodeFloatForKey:@"_NSParagraphStyle._paragraphSpacing"];
        _paragraphSpacingBefore = [decoder decodeFloatForKey:@"_NSParagraphStyle._paragraphSpacingBefore"];
        _baseWritingDirection = (NSWritingDirection)[decoder decodeInt64ForKey:@"_NSParagraphStyle._baseWritingDirection"];
        _lineHeightMultiple = [decoder decodeFloatForKey:@"_NSParagraphStyle._lineHeightMultiple"];
        _tabStops = [[decoder decodeObjectOfClass:[NSArray class] forKey:@"_NSParagraphStyle._tabStops"] retain];
        _defaultTabInterval = [decoder decodeFloatForKey:@"_NSParagraphStyle._defaultTabInterval"];
        _hyphenationFactor = [decoder decodeFloatForKey:@"_NSParagraphStyle._hyphenationFactor"];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeInt64:_alignment forKey:@"_NSParagraphStyle._alignment"];
    [encoder encodeFloat:_firstLineHeadIndent forKey:@"_NSParagraphStyle._firstLineHeadIndent"];
    [encoder encodeFloat:_headIndent forKey:@"_NSParagraphStyle._headIndent"];
    [encoder encodeFloat:_tailIndent forKey:@"_NSParagraphStyle._tailIndent"];
    [encoder encodeInt64:_lineBreakMode forKey:@"_NSParagraphStyle._lineBreakMode"];
    [encoder encodeFloat:_maximumLineHeight forKey:@"_NSParagraphStyle._maximumLineHeight"];
    [encoder encodeFloat:_minimumLineHeight forKey:@"_NSParagraphStyle._minimumLineHeight"];
    [encoder encodeFloat:_lineSpacing forKey:@"_NSParagraphStyle._lineSpacing"];
    [encoder encodeFloat:_paragraphSpacing forKey:@"_NSParagraphStyle._paragraphSpacing"];
    [encoder encodeFloat:_paragraphSpacingBefore forKey:@"_NSParagraphStyle._paragraphSpacingBefore"];
    [encoder encodeInt64:_baseWritingDirection forKey:@"_NSParagraphStyle._baseWritingDirection"];
    [encoder encodeFloat:_lineHeightMultiple forKey:@"_NSParagraphStyle._lineHeightMultiple"];
    [encoder encodeObject:_tabStops forKey:@"_NSParagraphStyle._tabStops"];
    [encoder encodeFloat:_defaultTabInterval forKey:@"_NSParagraphStyle._defaultTabInterval"];
    [encoder encodeFloat:_hyphenationFactor forKey:@"_NSParagraphStyle._hyphenationFactor"];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

- (CTParagraphStyleRef)_createCTParagraphStyle {
    CTLineBreakMode lineBreakMode = self.lineBreakMode;
    CTWritingDirection writingDirection = self.baseWritingDirection;
    CTTextAlignment alignment = NSTextAlignmentToCTTextAlignment(self.alignment);
    CTParagraphStyleSetting settings[14] =
        { { kCTParagraphStyleSpecifierAlignment, sizeof(CTTextAlignment), &alignment },
          { kCTParagraphStyleSpecifierFirstLineHeadIndent, sizeof(CGFloat), &_firstLineHeadIndent },
          { kCTParagraphStyleSpecifierHeadIndent, sizeof(CGFloat), &_headIndent },
          { kCTParagraphStyleSpecifierTailIndent, sizeof(CGFloat), &_tailIndent },
          { kCTParagraphStyleSpecifierTabStops, sizeof(CFArrayRef), &_tabStops },
          { kCTParagraphStyleSpecifierDefaultTabInterval, sizeof(CGFloat), &_defaultTabInterval },
          { kCTParagraphStyleSpecifierLineBreakMode, sizeof(CGFloat), &lineBreakMode },
          { kCTParagraphStyleSpecifierLineHeightMultiple, sizeof(CGFloat), &_lineHeightMultiple },
          { kCTParagraphStyleSpecifierMaximumLineHeight, sizeof(CGFloat), &_maximumLineHeight },
          { kCTParagraphStyleSpecifierMinimumLineHeight, sizeof(CGFloat), &_minimumLineHeight },
          { kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &_lineSpacing },
          { kCTParagraphStyleSpecifierParagraphSpacing, sizeof(CGFloat), &_paragraphSpacing },
          { kCTParagraphStyleSpecifierParagraphSpacingBefore, sizeof(CGFloat), &_paragraphSpacingBefore },
          { kCTParagraphStyleSpecifierBaseWritingDirection, sizeof(CGFloat), &writingDirection } };
    return CTParagraphStyleCreate(settings, std::extent<decltype(settings)>::value);
}

- (void)_setParagraphStyle:(NSParagraphStyle*)obj {
    self.alignment = obj.alignment;
    self.firstLineHeadIndent = obj.firstLineHeadIndent;
    self.headIndent = obj.headIndent;
    self.tailIndent = obj.tailIndent;
    self.lineBreakMode = obj.lineBreakMode;
    self.maximumLineHeight = obj.maximumLineHeight;
    self.minimumLineHeight = obj.minimumLineHeight;
    self.lineSpacing = obj.lineSpacing;
    self.paragraphSpacing = obj.paragraphSpacing;
    self.paragraphSpacingBefore = obj.paragraphSpacingBefore;
    self.baseWritingDirection = obj.baseWritingDirection;
    self.lineHeightMultiple = obj.lineHeightMultiple;
    self.tabStops = obj.tabStops;
    self.defaultTabInterval = obj.defaultTabInterval;
    self.hyphenationFactor = obj.hyphenationFactor;
}

@end