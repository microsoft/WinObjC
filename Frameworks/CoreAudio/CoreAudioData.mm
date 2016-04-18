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

#import <StubReturn.h>
#import <CoreAudio/CoreAudio.h>

/**
 @Status Stub
 @Notes
*/
bool IsAudioFormatNativeEndian(const AudioStreamBasicDescription& f) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
UInt32 CalculateLPCMFlags(
    UInt32 inValidBitsPerChannel, UInt32 inTotalBitsPerChannel, bool inIsFloat, bool inIsBigEndian, bool inIsNonInterleaved) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void FillOutASBDForLPCM(AudioStreamBasicDescription& outASBD,
                        Float64 inSampleRate,
                        UInt32 inChannelsPerFrame,
                        UInt32 inValidBitsPerChannel,
                        UInt32 inTotalBitsPerChannel,
                        bool inIsFloat,
                        bool inIsBigEndian,
                        bool inIsNonInterleaved) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void FillOutAudioTimeStampWithHostTime(AudioTimeStamp& outATS, UInt64 inHostTime) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void FillOutAudioTimeStampWithSampleTime(AudioTimeStamp& outATS, Float64 inSampleTime) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void FillOutAudioTimeStampWithSampleAndHostTime(AudioTimeStamp& outATS, Float64 inSampleTime, UInt64 inHostTime) {
    UNIMPLEMENTED();
}
