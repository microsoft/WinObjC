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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFURL.h>

CF_IMPLICIT_BRIDGING_ENABLED

typedef size_t (*CGDataProviderGetBytesCallback)(void* info, void* buffer, size_t count);
typedef void (*CGDataProviderReleaseInfoCallback)(void* info);
typedef void (*CGDataProviderRewindCallback)(void* info);
typedef void (*CGDataProviderSkipBytesCallback)(void* info, size_t count);
typedef off_t (*CGDataProviderSkipForwardCallback)(void* info, off_t count);
typedef const void* (*CGDataProviderGetBytePointerCallback)(void* info);
typedef size_t (*CGDataProviderGetBytesAtOffsetCallback)(void* info, void* buffer, size_t offset, size_t count);
typedef void (*CGDataProviderReleaseBytePointerCallback)(void* info, const void* pointer);
typedef size_t (*CGDataProviderGetBytesAtPositionCallback)(void* info, void* buffer, off_t position, size_t count);

typedef struct {
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipBytesCallback skipBytes;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseProvider;
} CGDataProviderCallbacks;
typedef struct {
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtOffsetCallback getBytes;
    CGDataProviderReleaseInfoCallback releaseProvider;
} CGDataProviderDirectAccessCallbacks;
typedef struct {
    unsigned int version;
    CGDataProviderGetBytePointerCallback getBytePointer;
    CGDataProviderReleaseBytePointerCallback releaseBytePointer;
    CGDataProviderGetBytesAtPositionCallback getBytesAtPosition;
    CGDataProviderReleaseInfoCallback releaseInfo;
} CGDataProviderDirectCallbacks;
typedef struct {
    unsigned int version;
    CGDataProviderGetBytesCallback getBytes;
    CGDataProviderSkipForwardCallback skipForward;
    CGDataProviderRewindCallback rewind;
    CGDataProviderReleaseInfoCallback releaseInfo;
} CGDataProviderSequentialCallbacks;
typedef void (*CGDataProviderReleaseDataCallback)(void* info, const void* data, size_t size);

COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateWithData(void* info,
                                                                   const void* data,
                                                                   size_t size,
                                                                   CGDataProviderReleaseDataCallback releaseData);
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateWithURL(CFURLRef url);
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateWithFilename(const char* filename);
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateWithCFData(CFDataRef data);
COREGRAPHICS_EXPORT CFDataRef CGDataProviderCopyData(CGDataProviderRef provider);
COREGRAPHICS_EXPORT void CGDataProviderRelease(CGDataProviderRef provider);
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderRetain(CGDataProviderRef provider);
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateDirect(void* info, off_t size, const CGDataProviderDirectCallbacks* callbacks);

COREGRAPHICS_EXPORT CFTypeID CGDataProviderGetTypeID() STUB_METHOD;
COREGRAPHICS_EXPORT CGDataProviderRef CGDataProviderCreateSequential(void* info,
                                                                     const CGDataProviderSequentialCallbacks* callbacks);

CF_IMPLICIT_BRIDGING_DISABLED
