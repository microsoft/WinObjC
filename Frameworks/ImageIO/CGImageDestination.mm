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

#import <ImageIO/CGImageDestination.h>
#import <StubReturn.h>

const CFStringRef kCGImageDestinationLossyCompressionQuality = static_cast<CFStringRef>(@"kCGImageDestinationLossyCompressionQuality");
const CFStringRef kCGImageDestinationBackgroundColor = static_cast<CFStringRef>(@"kCGImageDestinationBackgroundColor");

/**
 @Status Stub
 @Notes
*/
CGImageDestinationRef CGImageDestinationCreateWithDataConsumer(CGDataConsumerRef consumer,
                                                               CFStringRef type,
                                                               size_t count,
                                                               CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageDestinationRef CGImageDestinationCreateWithData(CFMutableDataRef data, CFStringRef type, size_t count, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGImageDestinationRef CGImageDestinationCreateWithURL(CFURLRef url, CFStringRef type, size_t count, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGImageDestinationAddImage(CGImageDestinationRef idst, CGImageRef image, CFDictionaryRef properties) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGImageDestinationAddImageFromSource(CGImageDestinationRef idst, CGImageSourceRef isrc, size_t index, CFDictionaryRef properties) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CGImageDestinationCopyTypeIdentifiers() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGImageDestinationGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGImageDestinationSetProperties(CGImageDestinationRef idst, CFDictionaryRef properties) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
bool CGImageDestinationFinalize(CGImageDestinationRef idst) {
    UNIMPLEMENTED();
    return StubReturn();
}
