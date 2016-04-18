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

NSString* const AVAssetExportPresetLowQuality = @"AVAssetExportPresetLowQuality";
NSString* const AVAssetExportPresetMediumQuality = @"AVAssetExportPresetMediumQuality";
NSString* const AVAssetExportPresetHighestQuality = @"AVAssetExportPresetHighestQuality";
NSString* const AVAssetExportPreset640x480 = @"AVAssetExportPreset640x480";
NSString* const AVAssetExportPreset960x540 = @"AVAssetExportPreset960x540";
NSString* const AVAssetExportPreset1280x720 = @"AVAssetExportPreset1280x720";
NSString* const AVAssetExportPreset1920x1080 = @"AVAssetExportPreset1920x1080";
NSString* const AVAssetExportPreset3840x2160 = @"AVAssetExportPreset3840x2160";
NSString* const AVAssetExportPresetAppleM4A = @"AVAssetExportPresetAppleM4A";
NSString* const AVAssetExportPresetPassthrough = @"AVAssetExportPresetPassthrough";

@implementation AVAssetExportSession
/**
@Status Stub
@Notes
*/
- (instancetype)initWithAsset:(AVAsset*)asset presetName:(NSString*)presetName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)exportSessionWithAsset:(AVAsset*)asset presetName:(NSString*)presetName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)allExportPresets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)exportPresetsCompatibleWithAsset:(AVAsset*)asset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (void)determineCompatibilityOfExportPreset:(NSString*)presetName
                                   withAsset:(AVAsset*)asset
                              outputFileType:(NSString*)outputFileType
                           completionHandler:(void (^)(BOOL))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)determineCompatibleFileTypesWithCompletionHandler:(void (^)(NSArray*))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)exportAsynchronouslyWithCompletionHandler:(void (^)(void))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)cancelExport {
    UNIMPLEMENTED();
}

@end
