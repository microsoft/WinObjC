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

#import <CoreText/CTFramesetter.h>
#import <StubReturn.h>
#import <algorithm>
#import "CoreTextInternal.h"
#import "CGPathInternal.h"
#import "DWriteWrapper_CoreText.h"

using namespace std;

@implementation _CTFramesetter : NSObject
@end

static _CTFrame* __CreateFrame(_CTFramesetter* framesetter, CGRect frameSize, CFRange range) {
    RETURN_NULL_IF(!framesetter);

    // Call _DWriteWrapper to get _CTLine object list that makes up this frame
    _CTTypesetter* typesetter = static_cast<_CTTypesetter*>(framesetter->_typesetter);
    if (range.length == 0L) {
        range.length = typesetter->_characters.size();
    }

    return [_DWriteGetFrame(static_cast<CFAttributedStringRef>(typesetter->_attributedString.get()), range, frameSize) retain];
}

/**
 @Status Interoperable
*/
CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTFramesetter* ret = [_CTFramesetter alloc];
    ret->_typesetter = static_cast<_CTTypesetter*>(CTTypesetterCreateWithAttributedString(string));
    return static_cast<CTFramesetterRef>(ret);
}

/**
 @Status Caveat
 @Notes frameAttributes parameter ignored
*/
CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter, CFRange stringRange, CGPathRef path, CFDictionaryRef frameAttributes) {
    CGRect frameSize;
    _CGPathGetBoundingBoxInternal(path, &frameSize);

    _CTFrame* ret = __CreateFrame(static_cast<_CTFramesetter*>(framesetter), frameSize, stringRange);
    ret->_path.reset(CGPathRetain(path));
    ret->_frameRect.origin = frameSize.origin;

    return static_cast<CTFrameRef>(ret);
}

/**
 @Status Interoperable
 @Notes
*/
CTTypesetterRef CTFramesetterGetTypesetter(CTFramesetterRef framesetter) {
    return framesetter ? static_cast<CTTypesetterRef>(static_cast<_CTFramesetter*>(framesetter)->_typesetter.get()) : nil;
}

/**
 @Status Interoperable
 @Notes
*/
CGSize CTFramesetterSuggestFrameSizeWithConstraints(
    CTFramesetterRef framesetter, CFRange stringRange, CFDictionaryRef frameAttributes, CGSize constraints, CFRange* fitRange) {
    CGRect frameSize = CGRectZero;
    frameSize.size = constraints;

    _CTFrame* frame = __CreateFrame(static_cast<_CTFramesetter*>(framesetter), frameSize, stringRange);
    CGSize ret = frame ? frame->_frameRect.size : CGSizeZero;

    if (fitRange) {
        *fitRange = CTFrameGetVisibleStringRange(static_cast<CTFrameRef>(frame));
    }

    [frame release];
    return ret;
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTFramesetterGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}