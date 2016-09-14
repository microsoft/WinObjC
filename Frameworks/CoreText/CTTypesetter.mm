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
#import "CGFontInternal.h"
#import "UIFontInternal.h"
#import <CoreText/DWriteWrapper.h>
#import <Foundation/NSAttributedString.h>
#import <algorithm>
#import "LoggingNative.h"

static const wchar_t* TAG = L"CTTypesetter";

const CFStringRef kCTTypesetterOptionDisableBidiProcessing = static_cast<CFStringRef>(@"kCTTypesetterOptionDisableBidiProcessing");
const CFStringRef kCTTypesetterOptionForcedEmbeddingLevel = static_cast<CFStringRef>(@"kCTTypesetterOptionForcedEmbeddingLevel");

// TODO::
// Remove once CTFont and UIFont are bridgable classes
static IWLazyClassLookup _LazyUIFont("UIFont");

@implementation _CTTypesetter
- (instancetype)initWithAttributedString:(NSAttributedString*)str {
    _attributedString.attach([str retain]);
    _string.attach([[str string] copy]);

    //  Measure the string
    _characters.resize(str.length);
    [_string getCharacters:_characters.data()];

    return self;
}

- (void)dealloc {
    _string = nil;
    _attributedString = nil;
    [super dealloc];
}
@end

static CFIndex _DoWrap(CTTypesetterRef ts, CFRange range, WidthFinderFunc widthFunc, void* widthParam, double offset, CTLineRef* outLine) {
    // TODO::
    // Replace this with DWrite
    UNIMPLEMENTED();
    return StubReturn();
}

static float FixedWidthFinderFunc(void* opaque, CFIndex idx, float offset, float height) {
    return *((double*)opaque) - offset;
}

static float UnlimitedWidthFinderFunc(void* opaque, CFIndex idx, float offset, float height) {
    return FLT_MAX;
}

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
    NSArray<_CTLine*>* lines = _DWriteGetLines(static_cast<_CTTypesetter*>(ts), range, CGRectMake(offset, 0, FLT_MAX, FLT_MAX));
    THROW_NS_IF_FALSE(E_UNEXPECTED, [lines count] == 1);

    return static_cast<CTLineRef>([[lines objectAtIndex:0] retain]);
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    return CTTypesetterSuggestLineBreakWithOffset(typesetter, startIndex, width, 0.0f);
}

// Private/exported function
CFIndex _CTTypesetterSuggestLineBreakWithOffsetAndCallback(
    CTTypesetterRef ts, CFIndex index, double offset, WidthFinderFunc callback, void* opaque) {
    // TODO::
    // Implement this for NSLayout* to work.
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef ts, CFIndex index, double width, double offset) {
    return _CTTypesetterSuggestLineBreakWithOffsetAndCallback(ts, index, offset, FixedWidthFinderFunc, &width);
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
 @Status Stub
 @Notes
*/
CFTypeID CTTypesetterGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
