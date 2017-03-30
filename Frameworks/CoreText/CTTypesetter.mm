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

#import <CoreText/CTTypesetter.h>
#import <StubReturn.h>
#import "CoreTextInternal.h"
#import "UIFontInternal.h"
#import "DWriteWrapper_CoreText.h"
#import <Foundation/NSAttributedString.h>
#import <algorithm>
#import "LoggingNative.h"

static const wchar_t* TAG = L"CTTypesetter";

const CFStringRef kCTTypesetterOptionDisableBidiProcessing = CFSTR("kCTTypesetterOptionDisableBidiProcessing");
const CFStringRef kCTTypesetterOptionForcedEmbeddingLevel = CFSTR("kCTTypesetterOptionForcedEmbeddingLevel");

@implementation _CTTypesetter
- (instancetype)initWithAttributedString:(NSAttributedString*)str {
    _attributedString = str;
    _string = [str string];

    return self;
}

- (void)dealloc {
    _string = nil;
    _attributedString = nil;
    [super dealloc];
}
@end

/**
@Status Interoperable
*/
CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTTypesetter* ret = [[_CTTypesetter alloc] initWithAttributedString:(NSAttributedString*)string];
    return (CTTypesetterRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTTypesetterRef CTTypesetterCreateWithAttributedStringAndOptions(CFAttributedStringRef string, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CTLineRef CTTypesetterCreateLine(CTTypesetterRef typesetter, CFRange stringRange) {
    return CTTypesetterCreateLineWithOffset(typesetter, stringRange, 0.0f);
}

/**
 @Status Interoperable
 @Notes
*/
CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef ts, CFRange range, double offset) {
    _CTFrame* frame = _DWriteGetFrame(static_cast<CFAttributedStringRef>(static_cast<_CTTypesetter*>(ts)->_attributedString.get()),
                                      range,
                                      CGRectMake(offset, 0, FLT_MAX, FLT_MAX));

    RETURN_NULL_IF(!frame);
    if ([frame->_lines count] != 1) {
        TraceError(TAG,
                   L"CTTypesetterCreateLineWithOffset - range {%f, %f} did not fit on a single line, instead used %u.",
                   range.location,
                   range.length,
                   [frame->_lines count]);
        return nullptr;
    }

    return static_cast<CTLineRef>([[frame->_lines firstObject] retain]);
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    return CTTypesetterSuggestLineBreakWithOffset(typesetter, startIndex, width, 0.0f);
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef ts, CFIndex index, double width, double offset) {
    _CTTypesetter* typesetter = static_cast<_CTTypesetter*>(ts);
    _CTFrame* frame = _DWriteGetFrame(static_cast<CFAttributedStringRef>(typesetter->_attributedString.get()),
                                      CFRangeMake(index, [typesetter->_string length] - index),
                                      CGRectMake(offset, 0, width, FLT_MAX));
    return ([frame->_lines count] > 0) ? static_cast<_CTLine*>([frame->_lines firstObject])->_strRange.length : 0;
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTTypesetterSuggestClusterBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTTypesetterSuggestClusterBreakWithOffset(CTTypesetterRef typesetter, CFIndex startIndex, double width, double offset) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes
*/
CFTypeID CTTypesetterGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
