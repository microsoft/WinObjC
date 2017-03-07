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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreFoundation/CFURL.h>
#import <CoreFoundation/CFData.h>

typedef struct __CGDataConsumer* CGDataConsumerRef;

typedef size_t (*CGDataConsumerPutBytesCallback)(void* info, const void* buffer, size_t count);
typedef void (*CGDataConsumerReleaseInfoCallback)(void* info);

typedef struct CGDataConsumerCallbacks {
    CGDataConsumerPutBytesCallback putBytes;
    CGDataConsumerReleaseInfoCallback releaseConsumer;
} CGDataConsumerCallbacks;

COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreate(void* info, const CGDataConsumerCallbacks* callbacks);
COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreateWithURL(CFURLRef url);
COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerCreateWithCFData(CFMutableDataRef data);
COREGRAPHICS_EXPORT CFTypeID CGDataConsumerGetTypeID();
COREGRAPHICS_EXPORT void CGDataConsumerRelease(CGDataConsumerRef consumer);
COREGRAPHICS_EXPORT CGDataConsumerRef CGDataConsumerRetain(CGDataConsumerRef consumer);
