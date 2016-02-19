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
#import <CoreVideo/CVMetalTextureCache.h>

const CFStringRef kCVMetalTextureCacheMaximumTextureAgeKey = static_cast<CFStringRef>(@"kCVMetalTextureCacheMaximumTextureAgeKey");

/**
 @Status Stub
 @Notes
*/
CFTypeID CVMetalTextureCacheGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVMetalTextureCacheCreate(CFAllocatorRef allocator,
                                   CFDictionaryRef cacheAttributes,
                                   id<MTLDevice> metalDevice,
                                   CFDictionaryRef textureAttributes,
                                   CVMetalTextureCacheRef _Nullable* cacheOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVMetalTextureCacheCreateTextureFromImage(CFAllocatorRef allocator,
                                                   CVMetalTextureCacheRef textureCache,
                                                   CVImageBufferRef sourceImage,
                                                   CFDictionaryRef textureAttributes,
                                                   MTLPixelFormat pixelFormat,
                                                   size_t width,
                                                   size_t height,
                                                   size_t planeIndex,
                                                   CVMetalTextureRef _Nullable* textureOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVMetalTextureCacheFlush(CVMetalTextureCacheRef textureCache, CVOptionFlags options) {
    UNIMPLEMENTED();
}
