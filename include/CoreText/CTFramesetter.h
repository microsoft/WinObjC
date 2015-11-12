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

#ifndef _CTFRAMESETTER_H_
#define _CTFRAMESETTER_H_

#import <CoreText/CTFrame.h>
#import <CoreText/CoreTextExport.h>
#import <CoreFoundation/CFAttributedString.h>

ENABLE_IMPLICIT_BRIDGING

typedef const struct __CTFramesetter* CTFramesetterRef;

CORETEXT_EXPORT CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter,
                                                    CFRange stringRange,
                                                    CGPathRef path,
                                                    CFDictionaryRef frameAttributes);
CORETEXT_EXPORT CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string);
CORETEXT_EXPORT CGSize CTFramesetterSuggestFrameSizeWithConstraints(
    CTFramesetterRef framesetter, CFRange stringRange, CFDictionaryRef frameAttributes, CGSize constraints, CFRange* fitRange);

DISABLE_IMPLICIT_BRIDGING

#endif // _CTFRAMESETTER_H_