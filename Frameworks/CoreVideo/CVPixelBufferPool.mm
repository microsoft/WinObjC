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
#import <CoreVideo/CVPixelBufferPool.h>

const CFStringRef kCVPixelBufferPoolMinimumBufferCountKey = static_cast<CFStringRef>(@"kCVPixelBufferPoolMinimumBufferCountKey");
const CFStringRef kCVPixelBufferPoolMaximumBufferAgeKey = static_cast<CFStringRef>(@"kCVPixelBufferPoolMaximumBufferAgeKey");
const CFStringRef kCVPixelBufferPoolAllocationThresholdKey = static_cast<CFStringRef>(@"kCVPixelBufferPoolAllocationThresholdKey");
const CFStringRef kCVPixelBufferPoolFreeBufferNotification = static_cast<CFStringRef>(@"kCVPixelBufferPoolFreeBufferNotification");

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferPoolCreate(CFAllocatorRef allocator,
                                 CFDictionaryRef poolAttributes,
                                 CFDictionaryRef pixelBufferAttributes,
                                 CVPixelBufferPoolRef _Nullable* poolOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferPoolCreatePixelBuffer(CFAllocatorRef allocator,
                                            CVPixelBufferPoolRef pixelBufferPool,
                                            CVPixelBufferRef _Nullable* pixelBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CVReturn CVPixelBufferPoolCreatePixelBufferWithAuxAttributes(CFAllocatorRef allocator,
                                                             CVPixelBufferPoolRef pixelBufferPool,
                                                             CFDictionaryRef auxAttributes,
                                                             CVPixelBufferRef _Nullable* pixelBufferOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CVPixelBufferPoolGetAttributes(CVPixelBufferPoolRef pool) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CVPixelBufferPoolGetPixelBufferAttributes(CVPixelBufferPoolRef pool) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CVPixelBufferPoolGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CVPixelBufferPoolRelease(CVPixelBufferPoolRef pixelBufferPool) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CVPixelBufferPoolRef CVPixelBufferPoolRetain(CVPixelBufferPoolRef pixelBufferPool) {
    UNIMPLEMENTED();
    return StubReturn();
}
