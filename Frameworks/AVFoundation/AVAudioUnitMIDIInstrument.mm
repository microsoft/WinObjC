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

@implementation AVAudioUnitMIDIInstrument
/**
@Status Stub
@Notes
*/
- (instancetype)initWithAudioComponentDescription:(AudioComponentDescription)description {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)sendController:(uint8_t)controller withValue:(uint8_t)value onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendMIDIEvent:(uint8_t)midiStatus data1:(uint8_t)data1 {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendMIDIEvent:(uint8_t)midiStatus data1:(uint8_t)data1 data2:(uint8_t)data2 {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendMIDISysExEvent:(NSData*)midiData {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendPitchBend:(uint16_t)pitchbend onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendPressure:(uint8_t)pressure onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendPressureForKey:(uint8_t)key withValue:(uint8_t)value onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendProgramChange:(uint8_t)program bankMSB:(uint8_t)bankMSB bankLSB:(uint8_t)bankLSB onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)sendProgramChange:(uint8_t)program onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)startNote:(uint8_t)note withVelocity:(uint8_t)velocity onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)stopNote:(uint8_t)note onChannel:(uint8_t)channel {
    UNIMPLEMENTED();
}

@end
