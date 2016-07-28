//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreGraphics/CGDataProvider.h>

COREGRAPHICS_EXPORT void CGColorSpaceRelease(CGColorSpaceRef space);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef space);
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericGray;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericRGB;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericCMYK;
;COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericRGBLinear;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceAdobeRGB1998;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceSRGB;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericGrayGamma2_2;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceGenericXYZ;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceACESCGLinear;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceITUR_709;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceITUR_2020;
COREGRAPHICS_EXPORT const CFStringRef kCGColorSpaceROMMRGB;
COREGRAPHICS_EXPORT CGColorRef CGColorGetConstantColor(CFStringRef name);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceCMYK();
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceGray();
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceRGB();
COREGRAPHICS_EXPORT size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef space);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef baseSpace);

COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateCalibratedGray(const CGFloat whitePoint[3],
                                                                     const CGFloat blackPoint[3],
                                                                     CGFloat gamma) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateCalibratedRGB(const CGFloat whitePoint[3],
                                                                    const CGFloat blackPoint[3],
                                                                    const CGFloat gamma[3],
                                                                    const CGFloat matrix[9]) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateICCBased(size_t nComponents,
                                                               const CGFloat* range,
                                                               CGDataProviderRef profile,
                                                               CGColorSpaceRef alternate) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateWithICCProfile(CFDataRef data) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateLab(const CGFloat whitePoint[3],
                                                          const CGFloat blackPoint[3],
                                                          const CGFloat range[4]) STUB_METHOD;

COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateWithPlatformColorSpace(const void* ref) STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateIndexed(CGColorSpaceRef baseSpace,
                                                              size_t lastIndex,
                                                              const unsigned char* colorTable);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateWithName(CFStringRef name);
COREGRAPHICS_EXPORT CFDataRef CGColorSpaceCopyICCProfile(CGColorSpaceRef space) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGColorSpaceGetTypeID() STUB_METHOD;
COREGRAPHICS_EXPORT CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef space);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceGetBaseColorSpace(CGColorSpaceRef space) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGColorSpaceGetColorTableCount(CGColorSpaceRef space) STUB_METHOD;
COREGRAPHICS_EXPORT void CGColorSpaceGetColorTable(CGColorSpaceRef space, uint8_t* table) STUB_METHOD;