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

#import <AudioToolBox/AudioFormat.h>
#import <CoreAudio/CoreAudioTypes.h>
#import <CoreFoundation/CFPropertyList.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFArray.h>
#import <CoreVideo/CVImageBuffer.h>
#import <CoreMedia/CMTime.h>
#import <CoreMedia/CoreMediaExport.h>

typedef struct opaqueCMFormatDescription* CMFormatDescriptionRef;
typedef CMFormatDescriptionRef CMAudioFormatDescriptionRef;
typedef CMFormatDescriptionRef CMVideoFormatDescriptionRef;
typedef CMFormatDescriptionRef CMTimeCodeFormatDescriptionRef;
typedef CMFormatDescriptionRef CMMetadataFormatDescriptionRef;
typedef uint32_t CMAudioFormatDescriptionMask;
typedef struct {
    int32_t width;
    int32_t height;
} CMVideoDimensions;
typedef FourCharCode CMMediaType;
typedef uint32_t CMTextDisplayFlags;
typedef int8_t CMTextJustificationValue;
typedef CMFormatDescriptionRef CMMuxedFormatDescriptionRef;
typedef CMFormatDescriptionRef CMClosedCaptionFormatDescriptionRef;
typedef FourCharCode CMTimeCodeFormatType;
typedef FourCharCode CMTextFormatType;
typedef FourCharCode CMAudioCodecType;
typedef FourCharCode CMMuxedStreamType;
typedef FourCharCode CMClosedCaptionFormatType;
typedef FourCharCode CMPixelFormatType;
typedef FourCharCode CMMetadataFormatType;
typedef FourCharCode CMVideoCodecType;

enum {
    kCMMediaType_Video = 'vide',
    kCMMediaType_Audio = 'soun',
    kCMMediaType_Muxed = 'muxx',
    kCMMediaType_Text = 'text',
    kCMMediaType_ClosedCaption = 'clcp',
    kCMMediaType_Subtitle = 'sbtl',
    kCMMediaType_TimeCode = 'tmcd',
    kCMMediaType_TimedMetadata = 'tmet',
    kCMMediaType_Metadata = 'meta'
};

enum { kCMTextFormatType_QTText = 'text', kCMTextFormatType_3GText = 'tx3g' };
enum { kCMTextJustification_left_top = 0, kCMTextJustification_centered = 1, kCMTextJustification_bottom_right = -1 };
enum { kCMAudioCodecType_AAC_LCProtected = 'paac', kCMAudioCodecType_AAC_AudibleProtected = 'aaac' };
enum { kCMClosedCaptionFormatType_CEA608 = 'c608', kCMClosedCaptionFormatType_CEA708 = 'c708' };
enum {
    kCMPixelFormat_32ARGB = 32,
    kCMPixelFormat_32BGRA = 'BGRA',
    kCMPixelFormat_24RGB = 24,
    kCMPixelFormat_16BE555 = 16,
    kCMPixelFormat_16BE565 = 'B565',
    kCMPixelFormat_16LE555 = 'L555',
    kCMPixelFormat_16LE565 = 'L565',
    kCMPixelFormat_16LE5551 = '5551',
    kCMPixelFormat_422YpCbCr8 = '2vuy',
    kCMPixelFormat_422YpCbCr8_yuvs = 'yuvs',
    kCMPixelFormat_444YpCbCr8 = 'v308',
    kCMPixelFormat_4444YpCbCrA8 = 'v408',
    kCMPixelFormat_422YpCbCr16 = 'v216',
    kCMPixelFormat_422YpCbCr10 = 'v210',
    kCMPixelFormat_444YpCbCr10 = 'v410',
    kCMPixelFormat_8IndexedGray_WhiteIsZero = 0x00000028,
};

enum {
    kCMTimedMetadataFormatType_ICY = 'icy ',
    kCMTimedMetadataFormatType_ID3 = 'id3 ',
    kCMTimedMetadataFormatType_Boxed = 'mebx',
};

enum {
    kCMVideoCodecType_422YpCbCr8 = kCMPixelFormat_422YpCbCr8,
    kCMVideoCodecType_Animation = 'rle ',
    kCMVideoCodecType_Cinepak = 'cvid',
    kCMVideoCodecType_JPEG = 'jpeg',
    kCMVideoCodecType_JPEG_OpenDML = 'dmb1',
    kCMVideoCodecType_SorensonVideo = 'SVQ1',
    kCMVideoCodecType_SorensonVideo3 = 'SVQ3',
    kCMVideoCodecType_H263 = 'h263',
    kCMVideoCodecType_H264 = 'avc1',
    kCMVideoCodecType_MPEG4Video = 'mp4v',
    kCMVideoCodecType_MPEG2Video = 'mp2v',
    kCMVideoCodecType_MPEG1Video = 'mp1v',
    kCMVideoCodecType_DVCNTSC = 'dvc ',
    kCMVideoCodecType_DVCPAL = 'dvcp',
    kCMVideoCodecType_DVCProPAL = 'dvpp',
    kCMVideoCodecType_DVCPro50NTSC = 'dv5n',
    kCMVideoCodecType_DVCPro50PAL = 'dv5p',
    kCMVideoCodecType_DVCPROHD720p60 = 'dvhp',
    kCMVideoCodecType_DVCPROHD720p50 = 'dvhq',
    kCMVideoCodecType_DVCPROHD1080i60 = 'dvh6',
    kCMVideoCodecType_DVCPROHD1080i50 = 'dvh5',
    kCMVideoCodecType_DVCPROHD1080p30 = 'dvh3',
    kCMVideoCodecType_DVCPROHD1080p25 = 'dvh2',
};

COREMEDIA_EXPORT OSStatus CMFormatDescriptionCreate(CFAllocatorRef allocator,
                                                    CMMediaType mediaType,
                                                    FourCharCode mediaSubtype,
                                                    CFDictionaryRef extensions,
                                                    CMFormatDescriptionRef _Nullable* descOut) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMFormatDescriptionEqual(CMFormatDescriptionRef desc1, CMFormatDescriptionRef desc2) STUB_METHOD;
COREMEDIA_EXPORT CFPropertyListRef CMFormatDescriptionGetExtension(CMFormatDescriptionRef desc, CFStringRef extensionKey) STUB_METHOD;
COREMEDIA_EXPORT CFDictionaryRef CMFormatDescriptionGetExtensions(CMFormatDescriptionRef desc) STUB_METHOD;
COREMEDIA_EXPORT FourCharCode CMFormatDescriptionGetMediaSubType(CMFormatDescriptionRef desc) STUB_METHOD;
COREMEDIA_EXPORT CMMediaType CMFormatDescriptionGetMediaType(CMFormatDescriptionRef desc) STUB_METHOD;
COREMEDIA_EXPORT CFTypeID CMFormatDescriptionGetTypeID() STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMAudioFormatDescriptionCreate(CFAllocatorRef allocator,
                                                         const AudioStreamBasicDescription* asbd,
                                                         size_t layoutSize,
                                                         const AudioChannelLayout* layout,
                                                         size_t magicCookieSize,
                                                         const void* magicCookie,
                                                         CFDictionaryRef extensions,
                                                         CMAudioFormatDescriptionRef _Nullable* outDesc) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMAudioFormatDescriptionEqual(CMAudioFormatDescriptionRef desc1,
                                                       CMAudioFormatDescriptionRef desc2,
                                                       CMAudioFormatDescriptionMask equalityMask,
                                                       CMAudioFormatDescriptionMask* equalityMaskOut) STUB_METHOD;
COREMEDIA_EXPORT const AudioChannelLayout* CMAudioFormatDescriptionGetChannelLayout(CMAudioFormatDescriptionRef desc,
                                                                                    size_t* layoutSize) STUB_METHOD;
COREMEDIA_EXPORT const AudioFormatListItem* CMAudioFormatDescriptionGetFormatList(CMAudioFormatDescriptionRef desc,
                                                                                  size_t* formatListSize) STUB_METHOD;
COREMEDIA_EXPORT const void* CMAudioFormatDescriptionGetMagicCookie(CMAudioFormatDescriptionRef desc, size_t* cookieSizeOut) STUB_METHOD;
COREMEDIA_EXPORT const AudioFormatListItem* CMAudioFormatDescriptionGetMostCompatibleFormat(CMAudioFormatDescriptionRef desc) STUB_METHOD;
COREMEDIA_EXPORT const AudioFormatListItem* CMAudioFormatDescriptionGetRichestDecodableFormat(CMAudioFormatDescriptionRef desc) STUB_METHOD;
COREMEDIA_EXPORT const AudioStreamBasicDescription* CMAudioFormatDescriptionGetStreamBasicDescription(CMAudioFormatDescriptionRef desc)
    STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMVideoFormatDescriptionCreate(CFAllocatorRef allocator,
                                                         CMVideoCodecType codecType,
                                                         int32_t width,
                                                         int32_t height,
                                                         CFDictionaryRef extensions,
                                                         CMVideoFormatDescriptionRef _Nullable* outDesc) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMVideoFormatDescriptionCreateForImageBuffer(CFAllocatorRef allocator,
                                                                       CVImageBufferRef imageBuffer,
                                                                       CMVideoFormatDescriptionRef _Nullable* outDesc) STUB_METHOD;
COREMEDIA_EXPORT CGRect CMVideoFormatDescriptionGetCleanAperture(CMVideoFormatDescriptionRef videoDesc,
                                                                 Boolean originIsAtTopLeft) STUB_METHOD;
COREMEDIA_EXPORT CMVideoDimensions CMVideoFormatDescriptionGetDimensions(CMVideoFormatDescriptionRef videoDesc) STUB_METHOD;
COREMEDIA_EXPORT CFArrayRef CMVideoFormatDescriptionGetExtensionKeysCommonWithImageBuffers() STUB_METHOD;
COREMEDIA_EXPORT CGSize CMVideoFormatDescriptionGetPresentationDimensions(CMVideoFormatDescriptionRef videoDesc,
                                                                          Boolean usePixelAspectRatio,
                                                                          Boolean useCleanAperture) STUB_METHOD;
COREMEDIA_EXPORT Boolean CMVideoFormatDescriptionMatchesImageBuffer(CMVideoFormatDescriptionRef desc,
                                                                    CVImageBufferRef imageBuffer) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMMuxedFormatDescriptionCreate(CFAllocatorRef allocator,
                                                         CMMuxedStreamType muxType,
                                                         CFDictionaryRef extensions,
                                                         CMMuxedFormatDescriptionRef _Nullable* outDesc) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMMetadataFormatDescriptionCreateWithKeys(CFAllocatorRef allocator,
                                                                    CMMetadataFormatType metadataType,
                                                                    CFArrayRef keys,
                                                                    CMMetadataFormatDescriptionRef _Nullable* outDesc) STUB_METHOD;
COREMEDIA_EXPORT CFDictionaryRef CMMetadataFormatDescriptionGetKeyWithLocalID(CMMetadataFormatDescriptionRef desc,
                                                                              OSType localKeyID) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTextFormatDescriptionGetDefaultStyle(CMFormatDescriptionRef desc,
                                                                 uint16_t* outLocalFontID,
                                                                 Boolean* outBold,
                                                                 Boolean* outItalic,
                                                                 Boolean* outUnderline,
                                                                 CGFloat* outFontSize,
                                                                 CGFloat outColorComponents[4]) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTextFormatDescriptionGetDefaultTextBox(CMFormatDescriptionRef desc,
                                                                   Boolean originIsAtTopLeft,
                                                                   CGFloat heightOfTextTrack,
                                                                   CGRect* outDefaultTextBox) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTextFormatDescriptionGetDisplayFlags(CMFormatDescriptionRef desc,
                                                                 CMTextDisplayFlags* outDisplayFlags) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTextFormatDescriptionGetFontName(CMFormatDescriptionRef desc,
                                                             uint16_t localFontID,
                                                             CFStringRef _Nullable* outFontName) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTextFormatDescriptionGetJustification(CMFormatDescriptionRef desc,
                                                                  CMTextJustificationValue* outHorizontalJust,
                                                                  CMTextJustificationValue* outVerticalJust) STUB_METHOD;
COREMEDIA_EXPORT OSStatus CMTimeCodeFormatDescriptionCreate(CFAllocatorRef allocator,
                                                            CMTimeCodeFormatType timeCodeFormatType,
                                                            CMTime frameDuration,
                                                            uint32_t frameQuanta,
                                                            uint32_t tcFlags,
                                                            CFDictionaryRef extensions,
                                                            CMTimeCodeFormatDescriptionRef _Nullable* descOut) STUB_METHOD;
COREMEDIA_EXPORT CMTime CMTimeCodeFormatDescriptionGetFrameDuration(CMTimeCodeFormatDescriptionRef timeCodeFormatDescription) STUB_METHOD;
COREMEDIA_EXPORT uint32_t CMTimeCodeFormatDescriptionGetFrameQuanta(CMTimeCodeFormatDescriptionRef timeCodeFormatDescription) STUB_METHOD;
COREMEDIA_EXPORT uint32_t CMTimeCodeFormatDescriptionGetTimeCodeFlags(CMTimeCodeFormatDescriptionRef desc) STUB_METHOD;

enum {
    kCMFormatDescriptionError_InvalidParameter = -12710,
    kCMFormatDescriptionError_AllocationFailed = -12711,
};

enum {
    kCMTimeCodeFormatType_TimeCode32 = 'tmcd',
    kCMTimeCodeFormatType_TimeCode64 = 'tc64',
    kCMTimeCodeFormatType_Counter32 = 'cn32',
    kCMTimeCodeFormatType_Counter64 = 'cn64'
};

enum { kCMTimeCodeFlag_DropFrame = 1 << 0, kCMTimeCodeFlag_24HourMax = 1 << 1, kCMTimeCodeFlag_NegTimesOK = 1 << 2 };

enum {
    kCMTextDisplayFlag_scrollIn = 0x00000020,
    kCMTextDisplayFlag_scrollOut = 0x00000040,
    kCMTextDisplayFlag_scrollDirectionMask = 0x00000180,
    kCMTextDisplayFlag_scrollDirection_bottomToTop = 0x00000000,
    kCMTextDisplayFlag_scrollDirection_rightToLeft = 0x00000080,
    kCMTextDisplayFlag_scrollDirection_topToBottom = 0x00000100,
    kCMTextDisplayFlag_scrollDirection_leftToRight = 0x00000180,
    kCMTextDisplayFlag_continuousKaraoke = 0x00000800,
    kCMTextDisplayFlag_writeTextVertically = 0x00020000,
    kCMTextDisplayFlag_fillTextRegion = 0x00040000,
    kCMTextDisplayFlag_forcedSubtitlesPresent = 0x40000000,
    kCMTextDisplayFlag_allSubtitlesForced = 0x80000000,
};

enum {
    kCMAudioFormatDescriptionMask_StreamBasicDescription = (1 << 0),
    kCMAudioFormatDescriptionMask_MagicCookie = (1 << 1),
    kCMAudioFormatDescriptionMask_ChannelLayout = (1 << 2),
    kCMAudioFormatDescriptionMask_Extensions = (1 << 3),
    kCMAudioFormatDescriptionMask_All = kCMAudioFormatDescriptionMask_StreamBasicDescription | kCMAudioFormatDescriptionMask_MagicCookie |
                                        kCMAudioFormatDescriptionMask_ChannelLayout | kCMAudioFormatDescriptionMask_Extensions
};

enum {
    kCMMuxedStreamType_MPEG1System = 'mp1s',
    kCMMuxedStreamType_MPEG2Transport = 'mp2t',
    kCMMuxedStreamType_MPEG2Program = 'mp2p',
    kCMMuxedStreamType_DV = 'dv '
};

COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionConformsToMPEG2VideoProfile;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionExtension_TemporalQuality;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionExtension_SpatialQuality;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionExtension_Version;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionExtension_RevisionLevel;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionExtension_Vendor;
COREMEDIA_EXPORT const CFStringRef kCMFormatDescriptionVendor_Apple;

// Extension keys and values common to kCMTextFormatType_QTText and kCMTextFormatType_3GText format descriptions
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_DisplayFlags;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_BackgroundColor;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionColor_Red;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionColor_Green;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionColor_Blue;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionColor_Alpha;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_DefaultTextBox;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionRect_Top;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionRect_Left;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionRect_Bottom;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionRect_Right;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_DefaultStyle;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_StartChar;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_Font;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_FontFace;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_ForegroundColor;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_FontSize;

// Extension keys and values specific to kCMTextFormatType_3GText
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_HorizontalJustification;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_VerticalJustification;

// Extension keys and values specific to the kCMTextFormatType_3GText kCMTextFormatDescriptionExtension_DefaultStyle dictionary
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_EndChar;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_FontTable;

// Extension keys and values specific to kCMTextFormatType_QTText
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_TextJustification;

// Extension keys and values specific to the kCMTextFormatType_QTText kCMTextFormatDescriptionExtension_DefaultStyle dictionary
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_Height;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionStyle_Ascent;
COREMEDIA_EXPORT const CFStringRef kCMTextFormatDescriptionExtension_DefaultFontName;

enum {
    kCMMPEG2VideoProfile_HDV_720p30 = 'hdv1',
    kCMMPEG2VideoProfile_HDV_1080i60 = 'hdv2',
    kCMMPEG2VideoProfile_HDV_1080i50 = 'hdv3',
    kCMMPEG2VideoProfile_HDV_720p24 = 'hdv4',
    kCMMPEG2VideoProfile_HDV_720p25 = 'hdv5',
    kCMMPEG2VideoProfile_HDV_1080p24 = 'hdv6',
    kCMMPEG2VideoProfile_HDV_1080p25 = 'hdv7',
    kCMMPEG2VideoProfile_HDV_1080p30 = 'hdv8',
    kCMMPEG2VideoProfile_HDV_720p60 = 'hdv9',
    kCMMPEG2VideoProfile_HDV_720p50 = 'hdva',
    kCMMPEG2VideoProfile_XDCAM_HD_1080i60_VBR35 = 'xdv2',
    kCMMPEG2VideoProfile_XDCAM_HD_1080i50_VBR35 = 'xdv3',
    kCMMPEG2VideoProfile_XDCAM_HD_1080p24_VBR35 = 'xdv6',
    kCMMPEG2VideoProfile_XDCAM_HD_1080p25_VBR35 = 'xdv7',
    kCMMPEG2VideoProfile_XDCAM_HD_1080p30_VBR35 = 'xdv8',
    kCMMPEG2VideoProfile_XDCAM_EX_720p24_VBR35 = 'xdv4',
    kCMMPEG2VideoProfile_XDCAM_EX_720p25_VBR35 = 'xdv5',
    kCMMPEG2VideoProfile_XDCAM_EX_720p30_VBR35 = 'xdv1',
    kCMMPEG2VideoProfile_XDCAM_EX_720p50_VBR35 = 'xdva',
    kCMMPEG2VideoProfile_XDCAM_EX_720p60_VBR35 = 'xdv9',
    kCMMPEG2VideoProfile_XDCAM_EX_1080i60_VBR35 = 'xdvb',
    kCMMPEG2VideoProfile_XDCAM_EX_1080i50_VBR35 = 'xdvc',
    kCMMPEG2VideoProfile_XDCAM_EX_1080p24_VBR35 = 'xdvd',
    kCMMPEG2VideoProfile_XDCAM_EX_1080p25_VBR35 = 'xdve',
    kCMMPEG2VideoProfile_XDCAM_EX_1080p30_VBR35 = 'xdvf',
    kCMMPEG2VideoProfile_XDCAM_HD422_720p50_CBR50 = 'xd5a',
    kCMMPEG2VideoProfile_XDCAM_HD422_720p60_CBR50 = 'xd59',
    kCMMPEG2VideoProfile_XDCAM_HD422_1080i60_CBR50 = 'xd5b',
    kCMMPEG2VideoProfile_XDCAM_HD422_1080i50_CBR50 = 'xd5c',
    kCMMPEG2VideoProfile_XDCAM_HD422_1080p24_CBR50 = 'xd5d',
    kCMMPEG2VideoProfile_XDCAM_HD422_1080p25_CBR50 = 'xd5e',
    kCMMPEG2VideoProfile_XDCAM_HD422_1080p30_CBR50 = 'xd5f',
    kCMMPEG2VideoProfile_XDCAM_HD_540p = 'xdhd',
    kCMMPEG2VideoProfile_XDCAM_HD422_540p = 'xdh2',
};