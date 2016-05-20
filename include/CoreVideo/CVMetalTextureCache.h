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
#import <CoreFoundation/CFBase.h>

#import <CoreFoundation/CFDictionary.h>
#import <CoreVideo/CVImageBuffer.h>
#import <Metal/MetalConstants.h>
#import <CoreVideo/CVMetalTexture.h>
#import <CoreFoundation/CFString.h>
#import <CoreVideo/CVPixelBuffer.h>

@protocol MTLDevice;

typedef struct __CVMetalTextureCache* CVMetalTextureCacheRef;

COREVIDEO_EXPORT CFTypeID CVMetalTextureCacheGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVMetalTextureCacheCreate(CFAllocatorRef allocator,
                                                    CFDictionaryRef cacheAttributes,
                                                    id<MTLDevice> metalDevice,
                                                    CFDictionaryRef textureAttributes,
                                                    CVMetalTextureCacheRef _Nullable* cacheOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVMetalTextureCacheCreateTextureFromImage(CFAllocatorRef allocator,
                                                                    CVMetalTextureCacheRef textureCache,
                                                                    CVImageBufferRef sourceImage,
                                                                    CFDictionaryRef textureAttributes,
                                                                    MTLPixelFormat pixelFormat,
                                                                    size_t width,
                                                                    size_t height,
                                                                    size_t planeIndex,
                                                                    CVMetalTextureRef _Nullable* textureOut) STUB_METHOD;
COREVIDEO_EXPORT void CVMetalTextureCacheFlush(CVMetalTextureCacheRef textureCache, CVOptionFlags options) STUB_METHOD;
COREVIDEO_EXPORT const CFStringRef kCVMetalTextureCacheMaximumTextureAgeKey;