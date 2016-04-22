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
#import <CoreVideo/CVImageBuffer.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreVideo/CVOpenGLESTexture.h>
#import <CoreFoundation/CFString.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreVideo/CVOpenGLESTextureCache.h>

@class EAGLContext;

typedef struct __CVOpenGLESTextureCache* CVOpenGLESTextureCacheRef;
typedef EAGLContext* CVEAGLContext;

COREVIDEO_EXPORT CFTypeID CVOpenGLESTextureCacheGetTypeID() STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVOpenGLESTextureCacheCreate(CFAllocatorRef allocator,
                                                       CFDictionaryRef cacheAttributes,
                                                       CVEAGLContext eaglContext,
                                                       CFDictionaryRef textureAttributes,
                                                       CVOpenGLESTextureCacheRef _Nullable* cacheOut) STUB_METHOD;
COREVIDEO_EXPORT CVReturn CVOpenGLESTextureCacheCreateTextureFromImage(CFAllocatorRef allocator,
                                                                       CVOpenGLESTextureCacheRef textureCache,
                                                                       CVImageBufferRef sourceImage,
                                                                       CFDictionaryRef textureAttributes,
                                                                       GLenum target,
                                                                       GLint internalFormat,
                                                                       GLsizei width,
                                                                       GLsizei height,
                                                                       GLenum format,
                                                                       GLenum type,
                                                                       size_t planeIndex,
                                                                       CVOpenGLESTextureRef _Nullable* textureOut) STUB_METHOD;
COREVIDEO_EXPORT void CVOpenGLESTextureCacheFlush(CVOpenGLESTextureCacheRef textureCache, CVOptionFlags options) STUB_METHOD;
COREVIDEO_EXPORT const CFStringRef kCVOpenGLESTextureCacheMaximumTextureAgeKey;
