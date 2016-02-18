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

#import <AudioToolbox/AudioToolboxExport.h>
#import <AudioToolbox/AudioConverter.h>
#import <CoreAudio/CoreAudioTypes.h>

enum { kAudioBalanceFadeType_MaxUnityGain = 0, kAudioBalanceFadeType_EqualPower = 1 };

typedef CF_ENUM(UInt32, AudioFormatPropertyID) {
    // AudioStreamBasicDescription structure properties,
    kAudioFormatProperty_FormatInfo = 'fmti',
    kAudioFormatProperty_FormatName = 'fnam',
    kAudioFormatProperty_EncodeFormatIDs = 'acof',
    kAudioFormatProperty_DecodeFormatIDs = 'acif',
    kAudioFormatProperty_FormatList = 'flst',
    kAudioFormatProperty_ASBDFromESDS = 'essd',
    kAudioFormatProperty_ChannelLayoutFromESDS = 'escl',
    kAudioFormatProperty_OutputFormatList = 'ofls',
    kAudioFormatProperty_Encoders = 'aven',
    kAudioFormatProperty_Decoders = 'avde',
    kAudioFormatProperty_FormatIsVBR = 'fvbr',
    kAudioFormatProperty_FormatIsExternallyFramed = 'fexf',
    kAudioFormatProperty_AvailableEncodeBitRates = 'aebr',
    kAudioFormatProperty_AvailableEncodeSampleRates = 'aesr',
    kAudioFormatProperty_AvailableEncodeChannelLayoutTags = 'aecl',
    kAudioFormatProperty_AvailableEncodeNumberChannels = 'avnc',
    kAudioFormatProperty_ASBDFromMPEGPacket = 'admp',
    // AudioChannelLayout structure properties
    kAudioFormatProperty_BitmapForLayoutTag = 'bmtg',
    kAudioFormatProperty_MatrixMixMap = 'mmap',
    kAudioFormatProperty_ChannelMap = 'chmp',
    kAudioFormatProperty_NumberOfChannelsForLayout = 'nchm',
    kAudioFormatProperty_ValidateChannelLayout = 'vacl',
    kAudioFormatProperty_ChannelLayoutForTag = 'cmpl',
    kAudioFormatProperty_TagForChannelLayout = 'cmpt',
    kAudioFormatProperty_ChannelLayoutName = 'lonm',
    kAudioFormatProperty_ChannelLayoutSimpleName = 'lsnm',
    kAudioFormatProperty_ChannelLayoutForBitmap = 'cmpb',
    kAudioFormatProperty_ChannelName = 'cnam',
    kAudioFormatProperty_ChannelShortName = 'csnm',
    kAudioFormatProperty_TagsForNumberOfChannels = 'tagc',
    kAudioFormatProperty_PanningMatrix = 'panm',
    kAudioFormatProperty_BalanceFade = 'balf',
    // ID3 tag (MP3 metadata ) properties
    kAudioFormatProperty_ID3TagSize = 'id3s',
    kAudioFormatProperty_ID3TagToDictionary = 'id3d'
};

enum {
    kAudioFormatProperty_HardwareCodecCapabilities = 'hwcc',
};

enum {
    kAudioDecoderComponentType = 'adec',
    kAudioEncoderComponentType = 'aenc',
};

enum { kAppleSoftwareAudioCodecManufacturer = 'appl', kAppleHardwareAudioCodecManufacturer = 'aphw' };

enum { kPanningMode_SoundField = 3, kPanningMode_VectorBasedPanning = 4 };

enum {
    kAudioFormatUnspecifiedError = 'what',
    kAudioFormatUnsupportedPropertyError = 'prop',
    kAudioFormatBadPropertySizeError = '!siz',
    kAudioFormatBadSpecifierSizeError = '!spc',
    kAudioFormatUnsupportedDataFormatError = 'fmt?',
    kAudioFormatUnknownFormatError = '!fmt'
};

struct AudioBalanceFade {
    Float32 mLeftRightBalance;
    Float32 mBackFrontFade;
    UInt32 mType;
    const AudioChannelLayout* mChannelLayout;
};

struct AudioFormatInfo {
    AudioStreamBasicDescription mASBD;
    const void* mMagicCookie;
    UInt32 mMagicCookieSize;
};

struct AudioFormatListItem {
    AudioStreamBasicDescription mASBD;
    AudioChannelLayoutTag mChannelLayoutTag;
};

struct AudioPanningInfo {
    UInt32 mPanningMode;
    UInt32 mCoordinateFlags;
    Float32 mCoordinates[3];
    Float32 mGainScale;
    const AudioChannelLayout* mOutputChannelMap;
};

struct ExtendedAudioFormatInfo {
    AudioStreamBasicDescription mASBD;
    const void* mMagicCookie;
    UInt32 mMagicCookieSize;
    AudioClassDescription mClassDescription;
};

typedef struct AudioBalanceFade AudioBalanceFade;
typedef struct AudioFormatInfo AudioFormatInfo;
typedef struct AudioFormatListItem AudioFormatListItem;
typedef struct AudioPanningInfo AudioPanningInfo;
typedef struct ExtendedAudioFormatInfo ExtendedAudioFormatInfo;

AUDIOTOOLBOX_EXPORT OSStatus AudioFormatGetProperty(AudioFormatPropertyID inPropertyID,
                                                    UInt32 inSpecifierSize,
                                                    const void* inSpecifier,
                                                    UInt32* ioPropertyDataSize,
                                                    void* outPropertyData) STUB_METHOD;
AUDIOTOOLBOX_EXPORT OSStatus AudioFormatGetPropertyInfo(AudioFormatPropertyID inPropertyID,
                                                        UInt32 inSpecifierSize,
                                                        const void* inSpecifier,
                                                        UInt32* outPropertyDataSize) STUB_METHOD;