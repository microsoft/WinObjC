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

#ifndef _CFHTTPMESSAGE_H_
#define _CFHTTPMESSAGE_H_

#import <StarboardExport.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFURL.h>

typedef struct __CFHTTPMessage* CFHTTPMessageRef;

SB_EXPORT const CFStringRef kCFHTTPVersion1_0;
SB_EXPORT const CFStringRef kCFHTTPVersion1_1;

SB_EXPORT CFHTTPMessageRef CFHTTPMessageCreateRequest(CFAllocatorRef alloc, CFStringRef reqMethod, CFURLRef url, CFStringRef httpVersion);
SB_EXPORT void CFHTTPMessageSetHeaderFieldValue(CFHTTPMessageRef msg, CFStringRef headerField, CFStringRef value);

SB_EXPORT Boolean CFHTTPMessageIsHeaderComplete(CFHTTPMessageRef msg);
SB_EXPORT CFDictionaryRef CFHTTPMessageCopyAllHeaderFields(CFHTTPMessageRef msg);
SB_EXPORT CFIndex CFHTTPMessageGetResponseStatusCode(CFHTTPMessageRef reply);
SB_EXPORT CFStringRef CFHTTPMessageCopyResponseStatusLine(CFHTTPMessageRef reply);
SB_EXPORT CFStringRef CFHTTPMessageCopyVersion(CFHTTPMessageRef msg);
SB_EXPORT void CFHTTPMessageSetBody(CFHTTPMessageRef message, CFDataRef bodyData);
SB_EXPORT CFStringRef CFHTTPMessageCopyHeaderFieldValue(CFHTTPMessageRef message, CFStringRef headerField);

SB_EXPORT CFHTTPMessageRef CFHTTPMessageCreateEmpty(CFAllocatorRef alloc, Boolean isRequest);
SB_EXPORT Boolean CFHTTPMessageAppendBytes(CFHTTPMessageRef message, const UInt8* newBytes, CFIndex numBytes);
SB_EXPORT CFDataRef CFHTTPMessageCopySerializedMessage(CFHTTPMessageRef request);
SB_EXPORT CFStringRef CFHTTPMessageCopyRequestMethod(CFHTTPMessageRef request);
SB_EXPORT CFURLRef CFHTTPMessageCopyRequestURL(CFHTTPMessageRef request);
SB_EXPORT CFHTTPMessageRef CFHTTPMessageCreateResponse(CFAllocatorRef alloc,
                                                       CFIndex statusCode,
                                                       CFStringRef statusDescription,
                                                       CFStringRef httpVersion);

#endif /* _CFHTTPMESSAGE_H_ */