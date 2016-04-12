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

#import <CoreVideo/CoreVideoExport.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFDictionary.h>

#import <CoreFoundation/CFString.h>

typedef struct _CVPixelBufferPool* CVPixelBufferPoolRef;

COREVIDEO_EXPORT CVReturn CVPixelBufferPoolCreate(CFAllocatorRef allocator,
                                                  CFDictionaryRef poolAttributes,
                                                  CFDictionaryRef pixelBufferAttributes,
                                                  CVPixelBufferPoolRef _Nullable* poolOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferPoolCreatePixelBuffer(CFAllocatorRef allocator,
                                                             CVPixelBufferPoolRef pixelBufferPool,
                                                             CVPixelBufferRef _Nullable* pixelBufferOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVPixelBufferPoolCreatePixelBufferWithAuxAttributes(CFAllocatorRef allocator,
                                                                              CVPixelBufferPoolRef pixelBufferPool,
                                                                              CFDictionaryRef auxAttributes,
                                                                              CVPixelBufferRef _Nullable* pixelBufferOut) STUB_METHOD;
COREVIDEO_EXPORT CFDictionaryRef CVPixelBufferPoolGetAttributes(CVPixelBufferPoolRef pool) STUB_METHOD;
COREVIDEO_EXPORT CFDictionaryRef CVPixelBufferPoolGetPixelBufferAttributes(CVPixelBufferPoolRef pool) STUB_METHOD;
COREVIDEO_EXPORT CFTypeID CVPixelBufferPoolGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT void CVPixelBufferPoolRelease(CVPixelBufferPoolRef pixelBufferPool) STUB_METHOD;
COREVIDEO_EXPORT CVPixelBufferPoolRef CVPixelBufferPoolRetain(CVPixelBufferPoolRef pixelBufferPool) STUB_METHOD;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPoolMinimumBufferCountKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPoolMaximumBufferAgeKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPoolAllocationThresholdKey;
COREVIDEO_EXPORT const CFStringRef kCVPixelBufferPoolFreeBufferNotification;
