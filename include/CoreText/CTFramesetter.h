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

#import <CoreText/CoreTextExport.h>
#import <CoreText/CTFrame.h>
#import <CoreText/CTTypesetter.h>

#import <CoreFoundation/CFAttributedString.h>
#import <CoreFoundation/CFDictionary.h>

#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGPath.h>

typedef const struct __CTFramesetter* CTFramesetterRef;

CORETEXT_EXPORT CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string);
CORETEXT_EXPORT CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter,
                                                    CFRange stringRange,
                                                    CGPathRef path,
                                                    CFDictionaryRef frameAttributes);
CORETEXT_EXPORT CTTypesetterRef CTFramesetterGetTypesetter(CTFramesetterRef framesetter) STUB_METHOD;
CORETEXT_EXPORT CGSize CTFramesetterSuggestFrameSizeWithConstraints(
    CTFramesetterRef framesetter, CFRange stringRange, CFDictionaryRef frameAttributes, CGSize constraints, CFRange* fitRange);
CORETEXT_EXPORT CFTypeID CTFramesetterGetTypeID() STUB_METHOD;
