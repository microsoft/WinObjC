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

@implementation AVAssetWriterInput
/**
@Status Stub
@Notes
*/
+ (instancetype)assetWriterInputWithMediaType:(NSString*)mediaType outputSettings:(NSDictionary*)outputSettings {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (instancetype)assetWriterInputWithMediaType:(NSString*)mediaType
                               outputSettings:(NSDictionary*)outputSettings
                             sourceFormatHint:(CMFormatDescriptionRef)sourceFormatHint {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithMediaType:(NSString*)mediaType outputSettings:(NSDictionary*)outputSettings {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithMediaType:(NSString*)mediaType
                   outputSettings:(NSDictionary*)outputSettings
                 sourceFormatHint:(CMFormatDescriptionRef)sourceFormatHint {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)appendSampleBuffer:(CMSampleBufferRef)sampleBuffer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)markAsFinished {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)requestMediaDataWhenReadyOnQueue:(dispatch_queue_t)queue usingBlock:(void (^)(void))block {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)addTrackAssociationWithTrackOfInput:(AVAssetWriterInput*)input type:(NSString*)trackAssociationType {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canAddTrackAssociationWithTrackOfInput:(AVAssetWriterInput*)input type:(NSString*)trackAssociationType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)markCurrentPassAsFinished {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)respondToEachPassDescriptionOnQueue:(dispatch_queue_t)queue usingBlock:(dispatch_block_t)block {
    UNIMPLEMENTED();
}

@end
