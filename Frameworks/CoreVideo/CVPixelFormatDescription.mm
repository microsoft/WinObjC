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
#import <CoreVideo/CVPixelFormatDescription.h>

const CFStringRef kCVPixelFormatName = static_cast<CFStringRef>(@"kCVPixelFormatName");
const CFStringRef kCVPixelFormatConstant = static_cast<CFStringRef>(@"kCVPixelFormatConstant");
const CFStringRef kCVPixelFormatCodecType = static_cast<CFStringRef>(@"kCVPixelFormatCodecType");
const CFStringRef kCVPixelFormatFourCC = static_cast<CFStringRef>(@"kCVPixelFormatFourCC");
const CFStringRef kCVPixelFormatContainsAlpha = static_cast<CFStringRef>(@"kCVPixelFormatContainsAlpha");
const CFStringRef kCVPixelFormatPlanes = static_cast<CFStringRef>(@"kCVPixelFormatPlanes");
const CFStringRef kCVPixelFormatBlockWidth = static_cast<CFStringRef>(@"kCVPixelFormatBlockWidth");
const CFStringRef kCVPixelFormatBlockHeight = static_cast<CFStringRef>(@"kCVPixelFormatBlockHeight");
const CFStringRef kCVPixelFormatBitsPerBlock = static_cast<CFStringRef>(@"kCVPixelFormatBitsPerBlock");
const CFStringRef kCVPixelFormatBlockHorizontalAlignment = static_cast<CFStringRef>(@"kCVPixelFormatBlockHorizontalAlignment");
const CFStringRef kCVPixelFormatBlockVerticalAlignment = static_cast<CFStringRef>(@"kCVPixelFormatBlockVerticalAlignment");
const CFStringRef kCVPixelFormatBlackBlock = static_cast<CFStringRef>(@"kCVPixelFormatBlackBlock");
const CFStringRef kCVPixelFormatHorizontalSubsampling = static_cast<CFStringRef>(@"kCVPixelFormatHorizontalSubsampling");
const CFStringRef kCVPixelFormatVerticalSubsampling = static_cast<CFStringRef>(@"kCVPixelFormatVerticalSubsampling");
const CFStringRef kCVPixelFormatOpenGLFormat = static_cast<CFStringRef>(@"kCVPixelFormatOpenGLFormat");
const CFStringRef kCVPixelFormatOpenGLType = static_cast<CFStringRef>(@"kCVPixelFormatOpenGLType");
const CFStringRef kCVPixelFormatOpenGLInternalFormat = static_cast<CFStringRef>(@"kCVPixelFormatOpenGLInternalFormat");
const CFStringRef kCVPixelFormatCGBitmapInfo = static_cast<CFStringRef>(@"kCVPixelFormatCGBitmapInfo");
const CFStringRef kCVPixelFormatQDCompatibility = static_cast<CFStringRef>(@"kCVPixelFormatQDCompatibility");
const CFStringRef kCVPixelFormatCGBitmapContextCompatibility = static_cast<CFStringRef>(@"kCVPixelFormatCGBitmapContextCompatibility");
const CFStringRef kCVPixelFormatCGImageCompatibility = static_cast<CFStringRef>(@"kCVPixelFormatCGImageCompatibility");
const CFStringRef kCVPixelFormatOpenGLCompatibility = static_cast<CFStringRef>(@"kCVPixelFormatOpenGLCompatibility");
const CFStringRef kCVPixelFormatOpenGLESCompatibility = static_cast<CFStringRef>(@"kCVPixelFormatOpenGLESCompatibility");
const CFStringRef kCVPixelFormatFillExtendedPixelsCallback = static_cast<CFStringRef>(@"kCVPixelFormatFillExtendedPixelsCallback");

/**
 @Status Stub
 @Notes
*/
void CVPixelFormatDescriptionRegisterDescriptionWithPixelFormatType(CFDictionaryRef description, OSType pixelFormat) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CVPixelFormatDescriptionCreateWithPixelFormatType(CFAllocatorRef allocator, OSType pixelFormat) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CVPixelFormatDescriptionArrayCreateWithAllPixelFormatTypes(CFAllocatorRef allocator) {
    UNIMPLEMENTED();
    return StubReturn();
}
