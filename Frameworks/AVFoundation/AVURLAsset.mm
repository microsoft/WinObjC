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

NSString* const AVURLAssetPreferPreciseDurationAndTimingKey = @"AVURLAssetPreferPreciseDurationAndTimingKey";
NSString* const AVURLAssetReferenceRestrictionsKey = @"AVURLAssetReferenceRestrictionsKey";
NSString* const AVURLAssetHTTPCookiesKey = @"AVURLAssetHTTPCookiesKey";

@implementation AVURLAsset
/**
@Status Stub
@Notes
*/
- (instancetype)initWithURL:(NSURL*)URL options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)URLAssetWithURL:(NSURL*)URL options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (AVAssetTrack*)compatibleTrackForCompositionTrack:(AVCompositionTrack*)compositionTrack {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)audiovisualMIMETypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)audiovisualTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)isPlayableExtendedMIMEType:(NSString*)extendedMIMEType {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
