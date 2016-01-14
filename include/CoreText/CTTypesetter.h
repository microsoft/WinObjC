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

#ifndef _CTTYPESETTER_H_
#define _CTTYPESETTER_H_

#import <CoreText/CoreTextExport.h>
#import <CoreFoundation/CFAttributedString.h>
#import <CoreText/CTLine.h>

ENABLE_IMPLICIT_BRIDGING

typedef const struct __CTTypesetter* CTTypesetterRef;
typedef float (*WidthCalculationCallback)(void* opaque, CFIndex idx, float offset, float height);

CORETEXT_EXPORT CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string);
CORETEXT_EXPORT CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef ts, CFIndex index, double width, double offset);
CORETEXT_EXPORT CFIndex CTTypesetterSuggestLineBreakWithOffsetAndCallback(
    CTTypesetterRef ts, CFIndex index, double offset, WidthCalculationCallback callback, void* opaque);
CORETEXT_EXPORT CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef ts, CFRange range, double offset);

DISABLE_IMPLICIT_BRIDGING

#endif // _CTTYPESETTER_H_