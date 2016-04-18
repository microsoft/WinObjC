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

NSString* const AVAudioEngineConfigurationChangeNotification = @"AVAudioEngineConfigurationChangeNotification";

@implementation AVAudioEngine
/**
@Status Stub
@Notes
*/
- (instancetype)init {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)attachNode:(AVAudioNode*)node {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)detachNode:(AVAudioNode*)node {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)disconnectNodeInput:(AVAudioNode*)node {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)disconnectNodeInput:(AVAudioNode*)node bus:(AVAudioNodeBus)bus {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)disconnectNodeOutput:(AVAudioNode*)node {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)disconnectNodeOutput:(AVAudioNode*)node bus:(AVAudioNodeBus)bus {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)connect:(AVAudioNode*)node1 to:(AVAudioNode*)node2 format:(AVAudioFormat*)format {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)connect:(AVAudioNode*)node1
             to:(AVAudioNode*)node2
        fromBus:(AVAudioNodeBus)bus1
          toBus:(AVAudioNodeBus)bus2
         format:(AVAudioFormat*)format {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)prepare {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (BOOL)startAndReturnError:(NSError* _Nullable*)outError {
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
- (void)reset {
    UNIMPLEMENTED();
}

@end
