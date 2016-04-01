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

@implementation AVAssetWriter
/**
@Status Stub
@Notes
*/
+ (instancetype)assetWriterWithURL:(NSURL*)outputURL fileType:(NSString*)outputFileType error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithURL:(NSURL*)outputURL fileType:(NSString*)outputFileType error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)startWriting {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)finishWriting {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)finishWritingWithCompletionHandler:(void (^)(void))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)cancelWriting {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)addInput:(AVAssetWriterInput*)input {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canAddInput:(AVAssetWriterInput*)input {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)startSessionAtSourceTime:(CMTime)startTime {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)endSessionAtSourceTime:(CMTime)endTime {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canApplyOutputSettings:(NSDictionary*)outputSettings forMediaType:(NSString*)mediaType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)addInputGroup:(AVAssetWriterInputGroup*)inputGroup {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)canAddInputGroup:(AVAssetWriterInputGroup*)inputGroup {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
