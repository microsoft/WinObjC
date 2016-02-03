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

#import <AudioToolbox/AudioFormat.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFormatGetProperty(AudioFormatPropertyID inPropertyID,
                                UInt32 inSpecifierSize,
                                const void* inSpecifier,
                                UInt32* ioPropertyDataSize,
                                void* outPropertyData) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus AudioFormatGetPropertyInfo(AudioFormatPropertyID inPropertyID,
                                    UInt32 inSpecifierSize,
                                    const void* inSpecifier,
                                    UInt32* outPropertyDataSize) {
    UNIMPLEMENTED();
    return StubReturn();
}