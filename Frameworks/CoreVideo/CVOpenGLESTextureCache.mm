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
#import <CoreVideo/CVOpenGLESTextureCache.h>

const CFStringRef kCVOpenGLESTextureCacheMaximumTextureAgeKey = static_cast<CFStringRef>(@"kCVOpenGLESTextureCacheMaximumTextureAgeKey");

/**
 @Status Stub
 @Notes
*/
CFTypeID CVOpenGLESTextureCacheGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVOpenGLESTextureCacheCreate(CFAllocatorRef allocator,
                                      CFDictionaryRef cacheAttributes,
                                      CVEAGLContext eaglContext,
                                      CFDictionaryRef textureAttributes,
                                      CVOpenGLESTextureCacheRef _Nullable* cacheOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVOpenGLESTextureCacheCreateTextureFromImage(CFAllocatorRef allocator,
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
                                                      CVOpenGLESTextureRef _Nullable* textureOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVOpenGLESTextureCacheFlush(CVOpenGLESTextureCacheRef textureCache, CVOptionFlags options) {
    UNIMPLEMENTED();
}
