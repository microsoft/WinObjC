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

#import <CoreMedia/CMFormatDescription.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef kCMFormatDescriptionConformsToMPEG2VideoProfile = static_cast<CFStringRef>(@"ConformsToMPEG2VideoProfile");
const CFStringRef kCMFormatDescriptionExtension_TemporalQuality = static_cast<CFStringRef>(@"TemporalQuality");
const CFStringRef kCMFormatDescriptionExtension_SpatialQuality = static_cast<CFStringRef>(@"SpatialQuality");
const CFStringRef kCMFormatDescriptionExtension_Version = static_cast<CFStringRef>(@"Version");
const CFStringRef kCMFormatDescriptionExtension_RevisionLevel = static_cast<CFStringRef>(@"RevisionLevel");
const CFStringRef kCMFormatDescriptionExtension_Vendor = static_cast<CFStringRef>(@"Vendor");
const CFStringRef kCMFormatDescriptionVendor_Apple = static_cast<CFStringRef>(@"appl");
const CFStringRef kCMTextFormatDescriptionExtension_DisplayFlags = static_cast<CFStringRef>(@"DisplayFlags");
const CFStringRef kCMTextFormatDescriptionExtension_BackgroundColor = static_cast<CFStringRef>(@"BackgroundColor");
const CFStringRef kCMTextFormatDescriptionColor_Red = static_cast<CFStringRef>(@"Red");
const CFStringRef kCMTextFormatDescriptionColor_Green = static_cast<CFStringRef>(@"Green");
const CFStringRef kCMTextFormatDescriptionColor_Blue = static_cast<CFStringRef>(@"Blue");
const CFStringRef kCMTextFormatDescriptionColor_Alpha = static_cast<CFStringRef>(@"Alpha");
const CFStringRef kCMTextFormatDescriptionExtension_DefaultTextBox = static_cast<CFStringRef>(@"DefaultTextBox");
const CFStringRef kCMTextFormatDescriptionRect_Top = static_cast<CFStringRef>(@"Top");
const CFStringRef kCMTextFormatDescriptionRect_Left = static_cast<CFStringRef>(@"Left");
const CFStringRef kCMTextFormatDescriptionRect_Bottom = static_cast<CFStringRef>(@"Bottom");
const CFStringRef kCMTextFormatDescriptionRect_Right = static_cast<CFStringRef>(@"Right");
const CFStringRef kCMTextFormatDescriptionExtension_DefaultStyle = static_cast<CFStringRef>(@"DefaultStyle");
const CFStringRef kCMTextFormatDescriptionStyle_StartChar = static_cast<CFStringRef>(@"StartChar");
const CFStringRef kCMTextFormatDescriptionStyle_Font = static_cast<CFStringRef>(@"Font");
const CFStringRef kCMTextFormatDescriptionStyle_FontFace = static_cast<CFStringRef>(@"FontFace");
const CFStringRef kCMTextFormatDescriptionStyle_ForegroundColor = static_cast<CFStringRef>(@"ForegroundColor");
const CFStringRef kCMTextFormatDescriptionStyle_FontSize = static_cast<CFStringRef>(@"FontSize");
const CFStringRef kCMTextFormatDescriptionExtension_HorizontalJustification = static_cast<CFStringRef>(@"HorizontalJustification");
const CFStringRef kCMTextFormatDescriptionExtension_VerticalJustification = static_cast<CFStringRef>(@"VerticalJustification");
const CFStringRef kCMTextFormatDescriptionStyle_EndChar = static_cast<CFStringRef>(@"EndChar");
const CFStringRef kCMTextFormatDescriptionExtension_FontTable = static_cast<CFStringRef>(@"FontTable");
const CFStringRef kCMTextFormatDescriptionExtension_TextJustification = static_cast<CFStringRef>(@"TextJustification");
const CFStringRef kCMTextFormatDescriptionStyle_Height = static_cast<CFStringRef>(@"Height");
const CFStringRef kCMTextFormatDescriptionStyle_Ascent = static_cast<CFStringRef>(@"Ascent");
const CFStringRef kCMTextFormatDescriptionExtension_DefaultFontName = static_cast<CFStringRef>(@"DefaultFontName");

/**
 @Status Stub
*/
OSStatus CMFormatDescriptionCreate(CFAllocatorRef allocator,
                                   CMMediaType mediaType,
                                   FourCharCode mediaSubtype,
                                   CFDictionaryRef extensions,
                                   CMFormatDescriptionRef _Nullable* descOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMFormatDescriptionEqual(CMFormatDescriptionRef desc1, CMFormatDescriptionRef desc2) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFPropertyListRef CMFormatDescriptionGetExtension(CMFormatDescriptionRef desc, CFStringRef extensionKey) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFDictionaryRef CMFormatDescriptionGetExtensions(CMFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
FourCharCode CMFormatDescriptionGetMediaSubType(CMFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMMediaType CMFormatDescriptionGetMediaType(CMFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFTypeID CMFormatDescriptionGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMAudioFormatDescriptionCreate(CFAllocatorRef allocator,
                                        const AudioStreamBasicDescription* asbd,
                                        size_t layoutSize,
                                        const AudioChannelLayout* layout,
                                        size_t magicCookieSize,
                                        const void* magicCookie,
                                        CFDictionaryRef extensions,
                                        CMAudioFormatDescriptionRef _Nullable* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMAudioFormatDescriptionEqual(CMAudioFormatDescriptionRef desc1,
                                      CMAudioFormatDescriptionRef desc2,
                                      CMAudioFormatDescriptionMask equalityMask,
                                      CMAudioFormatDescriptionMask* equalityMaskOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const AudioChannelLayout* CMAudioFormatDescriptionGetChannelLayout(CMAudioFormatDescriptionRef desc, size_t* layoutSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const AudioFormatListItem* CMAudioFormatDescriptionGetFormatList(CMAudioFormatDescriptionRef desc, size_t* formatListSize) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const void* CMAudioFormatDescriptionGetMagicCookie(CMAudioFormatDescriptionRef desc, size_t* cookieSizeOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const AudioFormatListItem* CMAudioFormatDescriptionGetMostCompatibleFormat(CMAudioFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const AudioFormatListItem* CMAudioFormatDescriptionGetRichestDecodableFormat(CMAudioFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
const AudioStreamBasicDescription* CMAudioFormatDescriptionGetStreamBasicDescription(CMAudioFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMVideoFormatDescriptionCreate(CFAllocatorRef allocator,
                                        CMVideoCodecType codecType,
                                        int32_t width,
                                        int32_t height,
                                        CFDictionaryRef extensions,
                                        CMVideoFormatDescriptionRef _Nullable* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMVideoFormatDescriptionCreateForImageBuffer(CFAllocatorRef allocator,
                                                      CVImageBufferRef imageBuffer,
                                                      CMVideoFormatDescriptionRef _Nullable* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CGRect CMVideoFormatDescriptionGetCleanAperture(CMVideoFormatDescriptionRef videoDesc, Boolean originIsAtTopLeft) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMVideoDimensions CMVideoFormatDescriptionGetDimensions(CMVideoFormatDescriptionRef videoDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFArrayRef CMVideoFormatDescriptionGetExtensionKeysCommonWithImageBuffers() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CGSize CMVideoFormatDescriptionGetPresentationDimensions(CMVideoFormatDescriptionRef videoDesc,
                                                         Boolean usePixelAspectRatio,
                                                         Boolean useCleanAperture) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
Boolean CMVideoFormatDescriptionMatchesImageBuffer(CMVideoFormatDescriptionRef desc, CVImageBufferRef imageBuffer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMMuxedFormatDescriptionCreate(CFAllocatorRef allocator,
                                        CMMuxedStreamType muxType,
                                        CFDictionaryRef extensions,
                                        CMMuxedFormatDescriptionRef _Nullable* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMMetadataFormatDescriptionCreateWithKeys(CFAllocatorRef allocator,
                                                   CMMetadataFormatType metadataType,
                                                   CFArrayRef keys,
                                                   CMMetadataFormatDescriptionRef _Nullable* outDesc) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CFDictionaryRef CMMetadataFormatDescriptionGetKeyWithLocalID(CMMetadataFormatDescriptionRef desc, OSType localKeyID) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTextFormatDescriptionGetDefaultStyle(CMFormatDescriptionRef desc,
                                                uint16_t* outLocalFontID,
                                                Boolean* outBold,
                                                Boolean* outItalic,
                                                Boolean* outUnderline,
                                                CGFloat* outFontSize,
                                                CGFloat outColorComponents[4]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTextFormatDescriptionGetDefaultTextBox(CMFormatDescriptionRef desc,
                                                  Boolean originIsAtTopLeft,
                                                  CGFloat heightOfTextTrack,
                                                  CGRect* outDefaultTextBox) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTextFormatDescriptionGetDisplayFlags(CMFormatDescriptionRef desc, CMTextDisplayFlags* outDisplayFlags) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTextFormatDescriptionGetFontName(CMFormatDescriptionRef desc, uint16_t localFontID, CFStringRef _Nullable* outFontName) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTextFormatDescriptionGetJustification(CMFormatDescriptionRef desc,
                                                 CMTextJustificationValue* outHorizontalJust,
                                                 CMTextJustificationValue* outVerticalJust) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
OSStatus CMTimeCodeFormatDescriptionCreate(CFAllocatorRef allocator,
                                           CMTimeCodeFormatType timeCodeFormatType,
                                           CMTime frameDuration,
                                           uint32_t frameQuanta,
                                           uint32_t tcFlags,
                                           CFDictionaryRef extensions,
                                           CMTimeCodeFormatDescriptionRef _Nullable* descOut) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
CMTime CMTimeCodeFormatDescriptionGetFrameDuration(CMTimeCodeFormatDescriptionRef timeCodeFormatDescription) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
uint32_t CMTimeCodeFormatDescriptionGetFrameQuanta(CMTimeCodeFormatDescriptionRef timeCodeFormatDescription) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
uint32_t CMTimeCodeFormatDescriptionGetTimeCodeFlags(CMTimeCodeFormatDescriptionRef desc) {
    UNIMPLEMENTED();
    return StubReturn();
}
