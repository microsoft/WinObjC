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
#import "DWriteWrapper_CoreText.h"
#import <algorithm>
#import <CFCppBase.h>
#import "LoggingNative.h"

static const wchar_t* TAG = L"CTTypesetter";

const CFStringRef kCTTypesetterOptionDisableBidiProcessing = CFSTR("kCTTypesetterOptionDisableBidiProcessing");
const CFStringRef kCTTypesetterOptionForcedEmbeddingLevel = CFSTR("kCTTypesetterOptionForcedEmbeddingLevel");

struct __CTTypesetter : CoreFoundation::CppBase<__CTTypesetter> {
    __CTTypesetter(CFAttributedStringRef attributedString) : _attributedString(attributedString) {
    }

    inline CFAttributedStringRef AttributedString() const {
        return _attributedString;
    }

private:
    woc::StrongCF<CFAttributedStringRef> _attributedString;
};

CFAttributedStringRef _CTTypesetterGetAttributedString(CTTypesetterRef typesetter) {
    RETURN_NULL_IF(!typesetter);
    return typesetter->AttributedString();
}

/**
@Status Interoperable
*/
CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string) {
    return __CTTypesetter::CreateInstance(kCFAllocatorDefault, string);
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
*/
CTLineRef CTTypesetterCreateLine(CTTypesetterRef typesetter, CFRange stringRange) {
    return CTTypesetterCreateLineWithOffset(typesetter, stringRange, 0.0f);
}

/**
 @Status Interoperable
*/
CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef ts, CFRange range, double offset) {
    CTFrameRef frame = _DWriteGetFrame(ts->AttributedString(), range, CGRectMake(offset, 0, FLT_MAX, FLT_MAX));
    RETURN_NULL_IF(!frame);

    CFIndex count = CFArrayGetCount(frame->_lines);
    if (count != 1) {
        TraceError(TAG,
                   L"CTTypesetterCreateLineWithOffset - range {%f, %f} did not fit on a single line, instead used %u.",
                   range.location,
                   range.length,
                   count);
        return nullptr;
    }

    return static_cast<CTLineRef>(CFRetain(CFArrayGetValueAtIndex(frame->_lines, 0)));
}

/**
 @Status Interoperable
*/
CFIndex CTTypesetterSuggestLineBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    return CTTypesetterSuggestLineBreakWithOffset(typesetter, startIndex, width, 0.0f);
}

/**
 @Status Interoperable
*/
CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef typesetter, CFIndex index, double width, double offset) {
    CTFrameRef frame = _DWriteGetFrame(typesetter->AttributedString(),
                                       CFRangeMake(index, CFAttributedStringGetLength(typesetter->AttributedString()) - index),
                                       CGRectMake(offset, 0, width, FLT_MAX));

    if (CFArrayGetCount(frame->_lines) > 0) {
        CTLineRef line = static_cast<CTLineRef>(CFArrayGetValueAtIndex(frame->_lines, 0));
        return line->_strRange.length;
    }

    return 0;
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
 @Status Interoperable
*/
CFTypeID CTTypesetterGetTypeID() {
    return __CTTypesetter::GetTypeID();
}
