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

@implementation AVAudioPlayer
/**
@Status Stub
@Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    if (outError)
        *outError = nil;
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithData:(NSData*)data error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    if (outError)
        *outError = nil;
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)url fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    if (outError)
        *outError = nil;
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithData:(NSData*)data fileTypeHint:(NSString*)utiString error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    if (outError)
        *outError = nil;
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)play {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)playAtTime:(NSTimeInterval)time {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)pause {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)stop {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)prepareToPlay {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (float)averagePowerForChannel:(NSUInteger)channelNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (float)peakPowerForChannel:(NSUInteger)channelNumber {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)updateMeters {
    UNIMPLEMENTED();
}

@end
