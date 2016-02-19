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

#import <StubReturn.h>
#import <CoreVideo/CVBuffer.h>

const CFStringRef kCVBufferMovieTimeKey = static_cast<CFStringRef>(@"kCVBufferMovieTimeKey");
const CFStringRef kCVBufferTimeValueKey = static_cast<CFStringRef>(@"kCVBufferTimeValueKey");
const CFStringRef kCVBufferTimeScaleKey = static_cast<CFStringRef>(@"kCVBufferTimeScaleKey");
const CFStringRef kCVBufferPropagatedAttachmentsKey = static_cast<CFStringRef>(@"kCVBufferPropagatedAttachmentsKey");
const CFStringRef kCVBufferNonPropagatedAttachmentsKey = static_cast<CFStringRef>(@"kCVBufferNonPropagatedAttachmentsKey");

/**
 @Status Stub
 @Notes
*/
CFTypeRef CVBufferGetAttachment(CVBufferRef buffer, CFStringRef key, CVAttachmentMode* attachmentMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CVBufferGetAttachments(CVBufferRef buffer, CVAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferPropagateAttachments(CVBufferRef sourceBuffer, CVBufferRef destinationBuffer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferRelease(CVBufferRef buffer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferRemoveAllAttachments(CVBufferRef buffer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferRemoveAttachment(CVBufferRef buffer, CFStringRef key) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CVBufferRef CVBufferRetain(CVBufferRef buffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferSetAttachment(CVBufferRef buffer, CFStringRef key, CFTypeRef value, CVAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CVBufferSetAttachments(CVBufferRef buffer, CFDictionaryRef theAttachments, CVAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
}