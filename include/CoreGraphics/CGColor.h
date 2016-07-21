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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGPattern.h>

COREGRAPHICS_EXPORT CGColorRef CGColorRetain(CGColorRef color);
COREGRAPHICS_EXPORT void CGColorRelease(CGColorRef color);
COREGRAPHICS_EXPORT CGColorRef CGColorCreate(CGColorSpaceRef space, const CGFloat* components);
COREGRAPHICS_EXPORT CGColorRef CGColorCreateWithPattern(CGColorSpaceRef colorSpace, CGPatternRef pattern, const CGFloat* components);
COREGRAPHICS_EXPORT CGColorRef CGColorCreateCopy(CGColorRef color);
COREGRAPHICS_EXPORT CGColorRef CGColorCreateCopyWithAlpha(CGColorRef color, CGFloat alpha);
COREGRAPHICS_EXPORT bool CGColorEqualToColor(CGColorRef color1, CGColorRef color2);
COREGRAPHICS_EXPORT CGFloat CGColorGetAlpha(CGColorRef color);
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorGetColorSpace(CGColorRef color);
COREGRAPHICS_EXPORT size_t CGColorGetNumberOfComponents(CGColorRef color);
COREGRAPHICS_EXPORT const CGFloat* CGColorGetComponents(CGColorRef color);
COREGRAPHICS_EXPORT CGPatternRef CGColorGetPattern(CGColorRef color);
COREGRAPHICS_EXPORT CFTypeID CGColorGetTypeID();
