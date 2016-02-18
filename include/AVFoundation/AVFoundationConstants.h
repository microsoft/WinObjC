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

#import <AVFoundation/AVFoundationExport.h>
#import <CoreFoundation/CFDate.h>

@class NSString;

AVFOUNDATION_EXPORT NSString* const AVMediaTypeVideo;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeAudio;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeText;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeClosedCaption;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeSubtitle;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeTimecode;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeTimedMetadata;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeMetadata;
AVFOUNDATION_EXPORT NSString* const AVMediaTypeMuxed;
AVFOUNDATION_EXPORT NSString* const AVLayerVideoGravityResize;
AVFOUNDATION_EXPORT NSString* const AVLayerVideoGravityResizeAspect;
AVFOUNDATION_EXPORT NSString* const AVLayerVideoGravityResizeAspectFill;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicVisual;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicAudible;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicLegible;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicFrameBased;
AVFOUNDATION_EXPORT NSString* const AVVideoCodecKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCodecH264;
AVFOUNDATION_EXPORT NSString* const AVVideoCodecJPEG;
AVFOUNDATION_EXPORT NSString* const AVVideoWidthKey;
AVFOUNDATION_EXPORT NSString* const AVVideoHeightKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCompressionPropertiesKey;
AVFOUNDATION_EXPORT NSString* const AVVideoAverageBitRateKey;
AVFOUNDATION_EXPORT NSString* const AVVideoQualityKey;
AVFOUNDATION_EXPORT NSString* const AVVideoMaxKeyFrameIntervalKey;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelKey;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Baseline30;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Baseline31;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Baseline41;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Main30;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Main31;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Main32;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264Main41;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264High40;
AVFOUNDATION_EXPORT NSString* const AVVideoProfileLevelH264High41;
AVFOUNDATION_EXPORT NSString* const AVVideoPixelAspectRatioKey;
AVFOUNDATION_EXPORT NSString* const AVVideoPixelAspectRatioHorizontalSpacingKey;
AVFOUNDATION_EXPORT NSString* const AVVideoPixelAspectRatioVerticalSpacingKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCleanApertureKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCleanApertureWidthKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCleanApertureHeightKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCleanApertureHorizontalOffsetKey;
AVFOUNDATION_EXPORT NSString* const AVVideoCleanApertureVerticalOffsetKey;
AVFOUNDATION_EXPORT NSString* const AVFileType3GPP;
AVFOUNDATION_EXPORT NSString* const AVFileType3GPP2;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAIFC;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAIFF;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAMR;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAC3;
AVFOUNDATION_EXPORT NSString* const AVFileTypeMPEGLayer3;
AVFOUNDATION_EXPORT NSString* const AVFileTypeSunAU;
AVFOUNDATION_EXPORT NSString* const AVFileTypeCoreAudioFormat;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAppleM4V;
AVFOUNDATION_EXPORT NSString* const AVFileTypeMPEG4;
AVFOUNDATION_EXPORT NSString* const AVFileTypeAppleM4A;
AVFOUNDATION_EXPORT NSString* const AVFileTypeQuickTimeMovie;
AVFOUNDATION_EXPORT NSString* const AVFileTypeWAVE;
AVFOUNDATION_EXPORT const CFTimeInterval AVCoreAnimationBeginTimeAtZero;
AVFOUNDATION_EXPORT NSString* const AVVideoScalingModeKey;
AVFOUNDATION_EXPORT NSString* const AVVideoScalingModeFit;
AVFOUNDATION_EXPORT NSString* const AVVideoScalingModeResize;
AVFOUNDATION_EXPORT NSString* const AVVideoScalingModeResizeAspect;
AVFOUNDATION_EXPORT NSString* const AVVideoScalingModeResizeAspectFill;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicIsMainProgramContent;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicIsAuxiliaryContent;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicContainsOnlyForcedSubtitles;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicTranscribesSpokenDialogForAccessibility;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicDescribesMusicAndSoundForAccessibility;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicDescribesVideoForAccessibility;
AVFOUNDATION_EXPORT NSString* const AVMediaCharacteristicEasyToRead;

AVFOUNDATION_EXPORT NSString* const AVMetadataKeySpaceCommon;
AVFOUNDATION_EXPORT NSString* const AVMetadataKeySpaceID3;
AVFOUNDATION_EXPORT NSString* const AVMetadataKeySpaceiTunes;
AVFOUNDATION_EXPORT NSString* const AVMetadataKeySpaceQuickTimeUserData;
AVFOUNDATION_EXPORT NSString* const AVMetadataKeySpaceQuickTimeMetadata;
AVFOUNDATION_EXPORT NSString* const AVMetadataFormatID3Metadata;
AVFOUNDATION_EXPORT NSString* const AVMetadataFormatiTunesMetadata;
AVFOUNDATION_EXPORT NSString* const AVMetadataFormatQuickTimeUserData;
AVFOUNDATION_EXPORT NSString* const AVMetadataFormatQuickTimeMetadata;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyTitle;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyCreator;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeySubject;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyDescription;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyPublisher;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyContributor;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyCreationDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyLastModifiedDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyType;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyFormat;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyIdentifier;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeySource;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyLanguage;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyRelation;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyLocation;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyCopyrights;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyAlbumName;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyAuthor;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyArtwork;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyMake;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeyModel;
AVFOUNDATION_EXPORT NSString* const AVMetadataCommonKeySoftware;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyAudioEncryption;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyAttachedPicture;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyAudioSeekPointIndex;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyComments;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyCommerical;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEncryption;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEqualization;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEqualization2;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEventTimingCodes;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyGeneralEncapsulatedObject;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyGroupIdentifier;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInvolvedPeopleList_v23;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyLink;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyMusicCDIdentifier;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyMPEGLocationLookupTable;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOwnership;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPrivate;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPlayCounter;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPopularimeter;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPositionSynchronization;
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyRecommendedBufferSize; /* RBUF Recommended
                             buffer size */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyRelativeVolumeAdjustment; /* RVAD Relative volume
                                    adjustment */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyRelativeVolumeAdjustment2; /* RVA2 Relative volume
                                    adjustment (2) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyReverb; /* RVRB Reverb */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySeek; /* SEEK Seek frame */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySignature; /* SIGN Signature frame */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySynchronizedLyric; /* SYLT Synchronized
                             lyric/text */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySynchronizedTempoCodes; /* SYTC Synchronized tempo
                                    codes */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyAlbumTitle; /* TALB Album/Movie/Show title */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyBeatsPerMinute; /* TBPM BPM (beats per minute) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyComposer; /* TCOM Composer */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyContentType; /* TCON Content type */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyCopyright; /* TCOP Copyright message */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyDate; /* TDAT Date */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEncodingTime; /* TDEN Encoding time */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPlaylistDelay; /* TDLY Playlist delay */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalReleaseTime; /* TDOR Original release time
                                    */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyRecordingTime; /* TDRC Recording time */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyReleaseTime; /* TDRL Release time */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTaggingTime; /* TDTG Tagging time */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEncodedBy; /* TENC Encoded by */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyLyricist; /* TEXT Lyricist/Text writer */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyFileType; /* TFLT File type */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTime; /* TIME Time */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInvolvedPeopleList_v24; /* TIPL Involved
                             people list */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyContentGroupDescription; /* TIT1 Content group
                                    description */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTitleDescription; /* TIT2 Title/songname/content
                                    description */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySubTitle; /* TIT3 Subtitle/Description refinement */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInitialKey; /* TKEY Initial key */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyLanguage; /* TLAN Language(s) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyLength; /* TLEN Length */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyMusicianCreditsList; /* TMCL Musician credits list
                                    */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyMediaType; /* TMED Media type */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyMood; /* TMOO Mood */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalAlbumTitle; /* TOAL Original
                                    album/movie/show title */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalFilename; /* TOFN Original filename */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalLyricist; /* TOLY Original
                             lyricist(s)/text
                             writer(s) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalArtist; /* TOPE Original
                             artist(s)/performer(s) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOriginalReleaseYear; /* TORY Original release year
                                    */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyFileOwner; /* TOWN File owner/licensee */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyLeadPerformer; /* TPE1 Lead
                             performer(s)/Soloist(s) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyBand; /* TPE2 Band/orchestra/accompaniment */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyConductor; /* TPE3 Conductor/performer refinement */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyModifiedBy; /* TPE4 Interpreted remixed or
                             otherwise modified by */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPartOfASet; /* TPOS Part of a set */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyProducedNotice; /* TPRO Produced notice */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPublisher; /* TPUB Publisher */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTrackNumber; /* TRCK Track number/Position in set */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyRecordingDates; /* TRDA Recording dates */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInternetRadioStationName; /* TRSN Internet radio
                                    station name */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInternetRadioStationOwner; /* TRSO Internet radio
                                    station owner */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySize; /* TSIZ Size */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyAlbumSortOrder; /* TSOA Album sort order */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPerformerSortOrder; /* TSOP Performer sort order */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTitleSortOrder; /* TSOT Title sort order */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyInternationalStandardRecordingCode; /* TSRC ISRC
                                    (international
                                    standard
                                    recording
                                    code) */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyEncodedWith; /* TSSE Software/Hardware and
                             settings used for encoding */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeySetSubtitle; /* TSST Set subtitle */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyYear; /* TYER Year */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyUserText; /* TXXX User defined text
                             information frame */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyUniqueFileIdentifier; /* UFID Unique file
                             identifier */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyTermsOfUse; /* USER Terms of use */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyUnsynchronizedLyric; /* USLT Unsynchronized
                                    lyric/text transcription */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyCommercialInformation; /* WCOM Commercial
                             information */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyCopyrightInformation; /* WCOP Copyright/Legal
                                    information */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOfficialAudioFileWebpage; /* WOAF Official audio
                                    file webpage */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOfficialArtistWebpage; /* WOAR Official
                             artist/performer
                             webpage */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOfficialAudioSourceWebpage; /* WOAS Official audio
                                    source webpage */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOfficialInternetRadioStationHomepage; /* WORS
                                    Official
                                    Internet
                                    radio
                                    station
                                    homepage */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyPayment; /* WPAY Payment */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyOfficialPublisherWebpage; /* WPUB Publishers
                                    official webpage */
AVFOUNDATION_EXPORT NSString* const AVMetadataID3MetadataKeyUserURL; /* WXXX User defined URL link frame */
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAlbum;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyUserComment;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyCoverArt;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyCopyright;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyReleaseDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyEncodedBy;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyPredefinedGenre;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyUserGenre;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeySongName;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyTrackSubTitle;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyEncodingTool;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyComposer;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAlbumArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAccountKind;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAppleID;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyArtistID;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeySongID;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyDiscCompilation;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyDiscNumber;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyGenreID;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyGrouping;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyPlaylistID;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyContentRating;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyBeatsPerMin;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyTrackNumber;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyArtDirector;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyArranger;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAuthor;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyLyrics;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyAcknowledgement;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyConductor;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyDescription;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyDirector;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyEQ;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyLinerNotes;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyRecordCompany;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyOriginalArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyPhonogramRights;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyProducer;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyPerformer;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyPublisher;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeySoundEngineer;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeySoloist;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyCredits;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyThanks;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyOnlineExtras;
AVFOUNDATION_EXPORT NSString* const AVMetadataiTunesMetadataKeyExecProducer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyAlbum;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyArranger;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyAuthor;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyChapter;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyComment;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyComposer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyCopyright;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyCreationDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyDescription;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyDirector;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyDisclaimer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyEncodedBy;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyFullName;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyGenre;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyHostComputer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyInformation;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyKeywords;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyMake;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyModel;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyOriginalArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyOriginalFormat;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyOriginalSource;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyPerformers;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyProducer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyPublisher;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyProduct;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeySoftware;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeySpecialPlaybackRequirements;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyTrack;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyWarning;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyWriter;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyURLLink;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyLocationISO6709;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyTrackName;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyCredits;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyPhonogramRights;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeUserDataKeyTaggedCharacteristic;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCameraIdentifier;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCameraFrameReadoutTime;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyTitle;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCollectionUser;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyRatingUser;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationName;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationBody;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationNote;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationRole;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyDirectionFacing;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyDirectionMotion;
AVFOUNDATION_EXPORT NSString* const AVMetadataISOUserDataKeyCopyright;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyCopyright;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyAuthor;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyPerformer;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyGenre;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyRecordingYear;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyLocation;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyTitle;
AVFOUNDATION_EXPORT NSString* const AVMetadata3GPUserDataKeyDescription;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyAuthor;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyComment;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCopyright;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCreationDate;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyDirector;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyDisplayName;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyInformation;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyKeywords;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyProducer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyPublisher;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyAlbum;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyArtwork;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyDescription;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeySoftware;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyYear;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyGenre;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyiXML;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyLocationISO6709;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyMake;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyModel;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyArranger;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyEncodedBy;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyOriginalArtist;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyPerformer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyComposer;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyCredits;
AVFOUNDATION_EXPORT NSString* const AVMetadataQuickTimeMetadataKeyPhonogramRights;
AVFOUNDATION_EXPORT NSString* const AVFormatIDKey;
AVFOUNDATION_EXPORT NSString* const AVSampleRateKey;
AVFOUNDATION_EXPORT NSString* const AVNumberOfChannelsKey;
AVFOUNDATION_EXPORT NSString* const AVLinearPCMBitDepthKey;
AVFOUNDATION_EXPORT NSString* const AVLinearPCMIsBigEndianKey;
AVFOUNDATION_EXPORT NSString* const AVLinearPCMIsFloatKey;
AVFOUNDATION_EXPORT NSString* const AVLinearPCMIsNonInterleaved;
#define AVLinearPCMIsNonInterleavedKey AVLinearPCMIsNonInterleaved
AVFOUNDATION_EXPORT NSString* const AVEncoderAudioQualityKey;
AVFOUNDATION_EXPORT NSString* const AVEncoderBitRateKey;
AVFOUNDATION_EXPORT NSString* const AVEncoderBitRatePerChannelKey;
AVFOUNDATION_EXPORT NSString* const AVEncoderBitRateStrategyKey;
AVFOUNDATION_EXPORT NSString* const AVEncoderBitDepthHintKey;
AVFOUNDATION_EXPORT NSString* const AVSampleRateConverterAudioQualityKey;
AVFOUNDATION_EXPORT NSString* const AVEncoderAudioQualityForVBRKey;
AVFOUNDATION_EXPORT NSString* const AVSampleRateConverterAlgorithmKey;
AVFOUNDATION_EXPORT NSString* const AVAudioBitRateStrategy_Constant;
AVFOUNDATION_EXPORT NSString* const AVAudioBitRateStrategy_LongTermAverage;
AVFOUNDATION_EXPORT NSString* const AVAudioBitRateStrategy_VariableConstrained;
AVFOUNDATION_EXPORT NSString* const AVAudioBitRateStrategy_Variable;
AVFOUNDATION_EXPORT NSString* const AVSampleRateConverterAlgorithm_Normal;
AVFOUNDATION_EXPORT NSString* const AVSampleRateConverterAlgorithm_Mastering;
AVFOUNDATION_EXPORT NSString* const AVAudioTimePitchAlgorithmLowQualityZeroLatency;
AVFOUNDATION_EXPORT NSString* const AVAudioTimePitchAlgorithmTimeDomain;
AVFOUNDATION_EXPORT NSString* const AVAudioTimePitchAlgorithmSpectral;
AVFOUNDATION_EXPORT NSString* const AVAudioTimePitchAlgorithmVarispeed;
AVFOUNDATION_EXPORT NSString* const AVChannelLayoutKey;

AVFOUNDATION_EXPORT const NSString* AVFoundationErrorDomain;
AVFOUNDATION_EXPORT NSString* const AVErrorDeviceKey;
AVFOUNDATION_EXPORT NSString* const AVErrorTimeKey;
AVFOUNDATION_EXPORT NSString* const AVErrorFileSizeKey;
AVFOUNDATION_EXPORT NSString* const AVErrorPIDKey;
AVFOUNDATION_EXPORT NSString* const AVErrorRecordingSuccessfullyFinishedKey;
AVFOUNDATION_EXPORT NSString* const AVErrorMediaTypeKey;
AVFOUNDATION_EXPORT NSString* const AVErrorMediaSubTypeKey;
enum {
    AVErrorUnknown = -11800,
    AVErrorOutOfMemory = -11801,
    AVErrorSessionNotRunning = -11803,
    AVErrorDeviceAlreadyUsedByAnotherSession = -11804,
    AVErrorNoDataCaptured = -11805,
    AVErrorSessionConfigurationChanged = -11806,
    AVErrorDiskFull = -11807,
    AVErrorDeviceWasDisconnected = -11808,
    AVErrorMediaChanged = -11809,
    AVErrorMaximumDurationReached = -11810,
    AVErrorMaximumFileSizeReached = -11811,
    AVErrorMediaDiscontinuity = -11812,
    AVErrorMaximumNumberOfSamplesForFileFormatReached = -11813,
    AVErrorDeviceNotConnected = -11814,
    AVErrorDeviceInUseByAnotherApplication = -11815,
    AVErrorDeviceLockedForConfigurationByAnotherProcess = -11817,
    AVErrorSessionWasInterrupted = -11818,
    AVErrorMediaServicesWereReset = -11819,
    AVErrorExportFailed = -11820,
    AVErrorDecodeFailed = -11821,
    AVErrorInvalidSourceMedia = -11822,
    AVErrorFileAlreadyExists = -11823,
    AVErrorCompositionTrackSegmentsNotContiguous = -11824,
    AVErrorInvalidCompositionTrackSegmentDuration = -11825,
    AVErrorInvalidCompositionTrackSegmentSourceStartTime = -11826,
    AVErrorInvalidCompositionTrackSegmentSourceDuration = -11827,
    AVErrorFileFormatNotRecognized = -11828,
    AVErrorFileFailedToParse = -11829,
    AVErrorMaximumStillImageCaptureRequestsExceeded = -11830,
    AVErrorContentIsProtected = -11831,
    AVErrorNoImageAtTime = -11832,
    AVErrorDecoderNotFound = -11833,
    AVErrorEncoderNotFound = -11834,
    AVErrorContentIsNotAuthorized = -11835,
    AVErrorApplicationIsNotAuthorized = -11836,
    AVErrorDeviceIsNotAvailableInBackground = -11837,
    AVErrorOperationNotSupportedForAsset = -11838,
    AVErrorDecoderTemporarilyUnavailable = -11839,
    AVErrorEncoderTemporarilyUnavailable = -11840,
    AVErrorInvalidVideoComposition = -11841,
    AVErrorReferenceForbiddenByReferencePolicy = -11842,
    AVErrorInvalidOutputURLPathExtension = -11843,
    AVErrorScreenCaptureFailed = -11844,
    AVErrorDisplayWasDisabled = -11845,
    AVErrorTorchLevelUnavailable = -11846,
    AVErrorOperationInterrupted = -11847,
    AVErrorIncompatibleAsset = -11848,
    AVErrorFailedToLoadMediaData = -11849,
    AVErrorServerIncorrectlyConfigured = -11850,
    AVErrorApplicationIsNotAuthorizedToUseDevice = -11852,
};
