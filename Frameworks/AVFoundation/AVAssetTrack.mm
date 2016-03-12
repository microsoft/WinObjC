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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const AVTrackAssociationTypeAudioFallback = @"AVTrackAssociationTypeAudioFallback";
NSString* const AVTrackAssociationTypeChapterList = @"AVTrackAssociationTypeChapterList";
NSString* const AVTrackAssociationTypeForcedSubtitlesOnly = @"AVTrackAssociationTypeForcedSubtitlesOnly";
NSString* const AVTrackAssociationTypeSelectionFollower = @"AVTrackAssociationTypeSelectionFollower";
NSString* const AVTrackAssociationTypeTimecode = @"AVTrackAssociationTypeTimecode";
NSString* const AVTrackAssociationTypeMetadataReferent = @"AVTrackAssociationTypeMetadataReferent";

@implementation AVAssetTrack
/**
@Status Stub
@Notes
*/
- (BOOL)hasMediaCharacteristic:(NSString*)mediaCharacteristic {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVAssetTrackSegment*)segmentForTrackTime:(CMTime)trackTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (CMTime)samplePresentationTimeForTrackTime:(CMTime)trackTime {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)metadataForFormat:(NSString*)format {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)associatedTracksOfType:(NSString*)trackAssociationType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)loadValuesAsynchronouslyForKeys:(NSArray*)keys completionHandler:(void (^)(void))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVKeyValueStatus)statusOfValueForKey:(NSString*)key error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
