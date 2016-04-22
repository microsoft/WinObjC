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

#import <Foundation/NSObject.h>

#import <CoreVideo/CoreVideoExport.h>

#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFBase.h>

typedef struct __CVBuffer* CVBufferRef;
typedef uint32_t CVAttachmentMode;

enum {
    kCVAttachmentMode_ShouldNotPropagate = 0,
    kCVAttachmentMode_ShouldPropagate = 1,
};

COREVIDEO_EXPORT CFTypeRef CVBufferGetAttachment(CVBufferRef buffer, CFStringRef key, CVAttachmentMode* attachmentMode) STUB_METHOD;
COREVIDEO_EXPORT CFDictionaryRef CVBufferGetAttachments(CVBufferRef buffer, CVAttachmentMode attachmentMode) STUB_METHOD;
COREVIDEO_EXPORT void CVBufferPropagateAttachments(CVBufferRef sourceBuffer, CVBufferRef destinationBuffer) STUB_METHOD;
COREVIDEO_EXPORT void CVBufferRelease(CVBufferRef buffer) STUB_METHOD;
COREVIDEO_EXPORT void CVBufferRemoveAllAttachments(CVBufferRef buffer) STUB_METHOD;
COREVIDEO_EXPORT void CVBufferRemoveAttachment(CVBufferRef buffer, CFStringRef key) STUB_METHOD;
COREVIDEO_EXPORT CVBufferRef CVBufferRetain(CVBufferRef buffer) STUB_METHOD;
COREVIDEO_EXPORT void CVBufferSetAttachment(CVBufferRef buffer, CFStringRef key, CFTypeRef value, CVAttachmentMode attachmentMode)
    STUB_METHOD;
COREVIDEO_EXPORT void CVBufferSetAttachments(CVBufferRef buffer,
                                             CFDictionaryRef theAttachments,
                                             CVAttachmentMode attachmentMode) STUB_METHOD;

COREVIDEO_EXPORT const CFStringRef kCVBufferMovieTimeKey;
COREVIDEO_EXPORT const CFStringRef kCVBufferTimeValueKey;
COREVIDEO_EXPORT const CFStringRef kCVBufferTimeScaleKey;
COREVIDEO_EXPORT const CFStringRef kCVBufferPropagatedAttachmentsKey;
COREVIDEO_EXPORT const CFStringRef kCVBufferNonPropagatedAttachmentsKey;
