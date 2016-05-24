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

#import <CoreMedia/CoreMediaExport.h>
#import <CoreFoundation/CFDictionary.h>

#import <CoreFoundation/CFString.h>

typedef CFTypeRef CMAttachmentBearerRef;
typedef uint32_t CMAttachmentMode;

COREMEDIA_EXPORT CFDictionaryRef CMCopyDictionaryOfAttachments(CFAllocatorRef allocator,
                                                               CMAttachmentBearerRef target,
                                                               CMAttachmentMode attachmentMode) STUB_METHOD;
COREMEDIA_EXPORT CFTypeRef CMGetAttachment(CMAttachmentBearerRef target, CFStringRef key, CMAttachmentMode* attachmentModeOut) STUB_METHOD;
COREMEDIA_EXPORT void CMPropagateAttachments(CMAttachmentBearerRef source, CMAttachmentBearerRef destination) STUB_METHOD;
COREMEDIA_EXPORT void CMRemoveAllAttachments(CMAttachmentBearerRef target) STUB_METHOD;
COREMEDIA_EXPORT void CMRemoveAttachment(CMAttachmentBearerRef target, CFStringRef key) STUB_METHOD;
COREMEDIA_EXPORT void CMSetAttachment(CMAttachmentBearerRef target, CFStringRef key, CFTypeRef value, CMAttachmentMode attachmentMode)
    STUB_METHOD;
COREMEDIA_EXPORT void CMSetAttachments(CMAttachmentBearerRef target,
                                       CFDictionaryRef theAttachments,
                                       CMAttachmentMode attachmentMode) STUB_METHOD;

enum { kCMAttachmentMode_ShouldNotPropagate = 0, kCMAttachmentMode_ShouldPropagate = 1 };
