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

#ifndef _CTRUN_H_
#define _CTRUN_H_

#import <StarboardExport.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreGraphics/CGFont.h>

ENABLE_IMPLICIT_BRIDGING

typedef const struct __CTRun *CTRunRef;

SB_EXPORT double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat *ascent, CGFloat *descent, CGFloat *leading);
SB_EXPORT CFRange CTRunGetStringRange(CTRunRef run);
SB_EXPORT CFDictionaryRef CTRunGetAttributes(CTRunRef run);
SB_EXPORT CFIndex CTRunGetGlyphCount(CTRunRef run);
SB_EXPORT void CTRunGetGlyphs(CTRunRef run, CFRange range, CGGlyph buffer[]);
SB_EXPORT void CTRunGetPositions(CTRunRef run, CFRange range, CGPoint buffer[]);

DISABLE_IMPLICIT_BRIDGING

#endif /* _CTRUN_H_ */