//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

typedef struct _O2ImageDestination* CGImageDestinationRef;

#import <CoreGraphics/CGImage.h>
#import <CoreGraphics/CGImageSource.h>
#import <CoreGraphics/CGDataConsumer.h>
#import <CoreFoundation/CFURL.h>

COREGRAPHICS_EXPORT const CFStringRef kCGImageDestinationLossyCompressionQuality;
COREGRAPHICS_EXPORT const CFStringRef kCGImageDestinationBackgroundColor;

COREGRAPHICS_EXPORT CFTypeID CGImageDestinationGetTypeID(void);

COREGRAPHICS_EXPORT CFArrayRef CGImageDestinationCopyTypeIdentifiers(void);

COREGRAPHICS_EXPORT CGImageDestinationRef CGImageDestinationCreateWithData(CFMutableDataRef data,
                                                                           CFStringRef type,
                                                                           size_t imageCount,
                                                                           CFDictionaryRef options);
COREGRAPHICS_EXPORT CGImageDestinationRef CGImageDestinationCreateWithDataConsumer(CGDataConsumerRef dataConsumer,
                                                                                   CFStringRef type,
                                                                                   size_t imageCount,
                                                                                   CFDictionaryRef options);
COREGRAPHICS_EXPORT CGImageDestinationRef CGImageDestinationCreateWithURL(CFURLRef url,
                                                                          CFStringRef type,
                                                                          size_t imageCount,
                                                                          CFDictionaryRef options);

COREGRAPHICS_EXPORT void CGImageDestinationSetProperties(CGImageDestinationRef self, CFDictionaryRef properties);

COREGRAPHICS_EXPORT void CGImageDestinationAddImage(CGImageDestinationRef self, CGImageRef image, CFDictionaryRef properties);
COREGRAPHICS_EXPORT void CGImageDestinationAddImageFromSource(CGImageDestinationRef self,
                                                              CGImageSourceRef imageSource,
                                                              size_t index,
                                                              CFDictionaryRef properties);

COREGRAPHICS_EXPORT bool CGImageDestinationFinalize(CGImageDestinationRef self);
