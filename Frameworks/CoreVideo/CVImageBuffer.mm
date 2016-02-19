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
#import <CoreVideo/CVImageBuffer.h>

const CFStringRef kCVImageBufferCGColorSpaceKey = static_cast<CFStringRef>(@"kCVImageBufferCGColorSpaceKey");
const CFStringRef kCVImageBufferGammaLevelKey = static_cast<CFStringRef>(@"kCVImageBufferGammaLevelKey");
const CFStringRef kCVImageBufferPreferredCleanApertureKey = static_cast<CFStringRef>(@"kCVImageBufferPreferredCleanApertureKey");
const CFStringRef kCVImageBufferCleanApertureKey = static_cast<CFStringRef>(@"kCVImageBufferCleanApertureKey");
const CFStringRef kCVImageBufferFieldCountKey = static_cast<CFStringRef>(@"kCVImageBufferFieldCountKey");
const CFStringRef kCVImageBufferFieldDetailKey = static_cast<CFStringRef>(@"kCVImageBufferFieldDetailKey");
const CFStringRef kCVImageBufferPixelAspectRatioKey = static_cast<CFStringRef>(@"kCVImageBufferPixelAspectRatioKey");
const CFStringRef kCVImageBufferDisplayDimensionsKey = static_cast<CFStringRef>(@"kCVImageBufferDisplayDimensionsKey");
const CFStringRef kCVImageBufferICCProfileKey = static_cast<CFStringRef>(@"kCVImageBufferICCProfileKey");
const CFStringRef kCVImageBufferYCbCrMatrixKey = static_cast<CFStringRef>(@"kCVImageBufferYCbCrMatrixKey");
const CFStringRef kCVImageBufferColorPrimariesKey = static_cast<CFStringRef>(@"kCVImageBufferColorPrimariesKey");
const CFStringRef kCVImageBufferTransferFunctionKey = static_cast<CFStringRef>(@"kCVImageBufferTransferFunctionKey");
const CFStringRef kCVImageBufferChromaLocationTopFieldKey = static_cast<CFStringRef>(@"kCVImageBufferChromaLocationTopFieldKey");
const CFStringRef kCVImageBufferChromaLocationBottomFieldKey = static_cast<CFStringRef>(@"kCVImageBufferChromaLocationBottomFieldKey");
const CFStringRef kCVImageBufferChromaSubsamplingKey = static_cast<CFStringRef>(@"kCVImageBufferChromaSubsamplingKey");
const CFStringRef kCVImageBufferCleanApertureWidthKey = static_cast<CFStringRef>(@"kCVImageBufferCleanApertureWidthKey");
const CFStringRef kCVImageBufferCleanApertureHeightKey = static_cast<CFStringRef>(@"kCVImageBufferCleanApertureHeightKey");
const CFStringRef kCVImageBufferCleanApertureHorizontalOffsetKey =
    static_cast<CFStringRef>(@"kCVImageBufferCleanApertureHorizontalOffsetKey");
const CFStringRef kCVImageBufferCleanApertureVerticalOffsetKey = static_cast<CFStringRef>(@"kCVImageBufferCleanApertureVerticalOffsetKey");
const CFStringRef kCVImageBufferFieldDetailTemporalTopFirst = static_cast<CFStringRef>(@"kCVImageBufferFieldDetailTemporalTopFirst");
const CFStringRef kCVImageBufferFieldDetailTemporalBottomFirst = static_cast<CFStringRef>(@"kCVImageBufferFieldDetailTemporalBottomFirst");
const CFStringRef kCVImageBufferFieldDetailSpatialFirstLineEarly =
    static_cast<CFStringRef>(@"kCVImageBufferFieldDetailSpatialFirstLineEarly");
const CFStringRef kCVImageBufferFieldDetailSpatialFirstLineLate =
    static_cast<CFStringRef>(@"kCVImageBufferFieldDetailSpatialFirstLineLate");
const CFStringRef kCVImageBufferPixelAspectRatioHorizontalSpacingKey =
    static_cast<CFStringRef>(@"kCVImageBufferPixelAspectRatioHorizontalSpacingKey");
const CFStringRef kCVImageBufferPixelAspectRatioVerticalSpacingKey =
    static_cast<CFStringRef>(@"kCVImageBufferPixelAspectRatioVerticalSpacingKey");
const CFStringRef kCVImageBufferDisplayWidthKey = static_cast<CFStringRef>(@"kCVImageBufferDisplayWidthKey");
const CFStringRef kCVImageBufferDisplayHeightKey = static_cast<CFStringRef>(@"kCVImageBufferDisplayHeightKey");
const CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_709_2 = static_cast<CFStringRef>(@"kCVImageBufferYCbCrMatrix_ITU_R_709_2");
const CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_601_4 = static_cast<CFStringRef>(@"kCVImageBufferYCbCrMatrix_ITU_R_601_4");
const CFStringRef kCVImageBufferYCbCrMatrix_SMPTE_240M_1995 = static_cast<CFStringRef>(@"kCVImageBufferYCbCrMatrix_SMPTE_240M_1995");
const CFStringRef kCVImageBufferColorPrimaries_ITU_R_709_2 = static_cast<CFStringRef>(@"kCVImageBufferColorPrimaries_ITU_R_709_2");
const CFStringRef kCVImageBufferColorPrimaries_EBU_3213 = static_cast<CFStringRef>(@"kCVImageBufferColorPrimaries_EBU_3213");
const CFStringRef kCVImageBufferColorPrimaries_SMPTE_C = static_cast<CFStringRef>(@"kCVImageBufferColorPrimaries_SMPTE_C");
const CFStringRef kCVImageBufferColorPrimaries_P22 = static_cast<CFStringRef>(@"kCVImageBufferColorPrimaries_P22");
const CFStringRef kCVImageBufferTransferFunction_ITU_R_709_2 = static_cast<CFStringRef>(@"kCVImageBufferTransferFunction_ITU_R_709_2");
const CFStringRef kCVImageBufferTransferFunction_SMPTE_240M_1995 =
    static_cast<CFStringRef>(@"kCVImageBufferTransferFunction_SMPTE_240M_1995");
const CFStringRef kCVImageBufferTransferFunction_UseGamma = static_cast<CFStringRef>(@"kCVImageBufferTransferFunction_UseGamma");
const CFStringRef kCVImageBufferChromaLocation_Left = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_Left");
const CFStringRef kCVImageBufferChromaLocation_Center = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_Center");
const CFStringRef kCVImageBufferChromaLocation_TopLeft = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_TopLeft");
const CFStringRef kCVImageBufferChromaLocation_Top = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_Top");
const CFStringRef kCVImageBufferChromaLocation_BottomLeft = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_BottomLeft");
const CFStringRef kCVImageBufferChromaLocation_Bottom = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_Bottom");
const CFStringRef kCVImageBufferChromaLocation_DV420 = static_cast<CFStringRef>(@"kCVImageBufferChromaLocation_DV420");
const CFStringRef kCVImageBufferChromaSubsampling_420 = static_cast<CFStringRef>(@"kCVImageBufferChromaSubsampling_420");
const CFStringRef kCVImageBufferChromaSubsampling_422 = static_cast<CFStringRef>(@"kCVImageBufferChromaSubsampling_422");
const CFStringRef kCVImageBufferChromaSubsampling_411 = static_cast<CFStringRef>(@"kCVImageBufferChromaSubsampling_411");

/**
 @Status Stub
 @Notes
*/
CGRect CVImageBufferGetCleanRect(CVImageBufferRef imageBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGSize CVImageBufferGetDisplaySize(CVImageBufferRef imageBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGSize CVImageBufferGetEncodedSize(CVImageBufferRef imageBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
Boolean CVImageBufferIsFlipped(CVImageBufferRef imageBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}
