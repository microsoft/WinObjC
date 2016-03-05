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
#import <CoreGraphics/CGGeometry.h>
#import <CoreVideo/CVBuffer.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFString.h>

typedef CVBufferRef CVImageBufferRef;

COREVIDEO_EXPORT CGRect CVImageBufferGetCleanRect(CVImageBufferRef imageBuffer) STUB_METHOD;
COREVIDEO_EXPORT CGSize CVImageBufferGetDisplaySize(CVImageBufferRef imageBuffer) STUB_METHOD;
COREVIDEO_EXPORT CGSize CVImageBufferGetEncodedSize(CVImageBufferRef imageBuffer) STUB_METHOD;
COREVIDEO_EXPORT Boolean CVImageBufferIsFlipped(CVImageBufferRef imageBuffer) STUB_METHOD;

COREVIDEO_EXPORT const CFStringRef kCVImageBufferCGColorSpaceKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferGammaLevelKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferPreferredCleanApertureKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferCleanApertureKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldCountKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldDetailKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferPixelAspectRatioKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferDisplayDimensionsKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferICCProfileKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferYCbCrMatrixKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferColorPrimariesKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferTransferFunctionKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocationTopFieldKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocationBottomFieldKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaSubsamplingKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferCleanApertureWidthKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferCleanApertureHeightKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferCleanApertureHorizontalOffsetKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferCleanApertureVerticalOffsetKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldDetailTemporalTopFirst;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldDetailTemporalBottomFirst;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldDetailSpatialFirstLineEarly;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferFieldDetailSpatialFirstLineLate;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferPixelAspectRatioHorizontalSpacingKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferPixelAspectRatioVerticalSpacingKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferDisplayWidthKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferDisplayHeightKey;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_709_2;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_601_4;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferYCbCrMatrix_SMPTE_240M_1995;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferColorPrimaries_ITU_R_709_2;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferColorPrimaries_EBU_3213;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferColorPrimaries_SMPTE_C;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferColorPrimaries_P22;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferTransferFunction_ITU_R_709_2;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferTransferFunction_SMPTE_240M_1995;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferTransferFunction_UseGamma;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_Left;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_Center;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_TopLeft;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_Top;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_BottomLeft;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_Bottom;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaLocation_DV420;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaSubsampling_420;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaSubsampling_422;
COREVIDEO_EXPORT const CFStringRef kCVImageBufferChromaSubsampling_411;