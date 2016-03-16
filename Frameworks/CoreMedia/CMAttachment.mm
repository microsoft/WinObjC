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

#import <CoreMedia/CMAttachment.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

/**
 @Status Stub
*/
CFDictionaryRef CMCopyDictionaryOfAttachments(CFAllocatorRef allocator, CMAttachmentBearerRef target, CMAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFTypeRef CMGetAttachment(CMAttachmentBearerRef target, CFStringRef key, CMAttachmentMode* attachmentModeOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
void CMPropagateAttachments(CMAttachmentBearerRef source, CMAttachmentBearerRef destination) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CMRemoveAllAttachments(CMAttachmentBearerRef target) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CMRemoveAttachment(CMAttachmentBearerRef target, CFStringRef key) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CMSetAttachment(CMAttachmentBearerRef target, CFStringRef key, CFTypeRef value, CMAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
void CMSetAttachments(CMAttachmentBearerRef target, CFDictionaryRef theAttachments, CMAttachmentMode attachmentMode) {
    UNIMPLEMENTED();
}