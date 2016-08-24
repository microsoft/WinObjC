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
#pragma once

#import <CoreText/CoreTextExport.h>
#import <CoreFoundation/CoreFoundation.h>
#import <CoreGraphics/CGBase.h>

typedef CGFloat (*CTRunDelegateGetAscentCallback)(void* refCon);
typedef CGFloat (*CTRunDelegateGetDescentCallback)(void* refCon);
typedef CGFloat (*CTRunDelegateGetWidthCallback)(void* refCon);
typedef void (*CTRunDelegateDeallocateCallback)(void* refCon);
typedef struct {
    CFIndex version;
    CTRunDelegateDeallocateCallback dealloc;
    CTRunDelegateGetAscentCallback getAscent;
    CTRunDelegateGetDescentCallback getDescent;
    CTRunDelegateGetWidthCallback getWidth;
} CTRunDelegateCallbacks;
typedef const struct __CTRunDelegate* CTRunDelegateRef;

enum {
    kCTRunDelegateVersion1 = 1,
    kCTRunDelegateCurrentVersion = kCTRunDelegateVersion1,
};

CORETEXT_EXPORT CTRunDelegateRef CTRunDelegateCreate(const CTRunDelegateCallbacks* callbacks, void* refCon) STUB_METHOD;
CORETEXT_EXPORT void* CTRunDelegateGetRefCon(CTRunDelegateRef runDelegate) STUB_METHOD;
CORETEXT_EXPORT CFTypeID CTRunDelegateGetTypeID() STUB_METHOD;