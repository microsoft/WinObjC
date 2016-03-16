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

@implementation AVAsset
/**
@Status Stub
@Notes
*/
+ (instancetype)assetWithURL:(NSURL*)URL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)cancelLoading {
    UNIMPLEMENTED();
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
- (NSArray*)chapterMetadataGroupsWithTitleLocale:(NSLocale*)locale containingItemsWithCommonKeys:(NSArray*)commonKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)chapterMetadataGroupsBestMatchingPreferredLanguages:(NSArray*)preferredLanguages {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVAssetTrack*)trackWithTrackID:(CMPersistentTrackID)trackID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)tracksWithMediaCharacteristic:(NSString*)mediaCharacteristic {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (NSArray*)tracksWithMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (CMPersistentTrackID)unusedTrackID {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVMediaSelectionGroup*)mediaSelectionGroupForMediaCharacteristic:(NSString*)mediaCharacteristic {
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
