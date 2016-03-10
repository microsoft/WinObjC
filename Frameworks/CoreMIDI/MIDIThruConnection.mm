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
#import <CoreMIDI/MIDIThruConnection.h>

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIThruConnectionCreate(CFStringRef inPersistentOwnerID, CFDataRef inConnectionParams, MIDIThruConnectionRef* outConnection) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIThruConnectionDispose(MIDIThruConnectionRef connection) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIThruConnectionFind(CFStringRef inPersistentOwnerID, CFDataRef _Nonnull* outConnectionList) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIThruConnectionGetParams(MIDIThruConnectionRef connection, CFDataRef _Nonnull* outConnectionParams) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void MIDIThruConnectionParamsInitialize(MIDIThruConnectionParams* inConnectionParams) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
OSStatus MIDIThruConnectionSetParams(MIDIThruConnectionRef connection, CFDataRef inConnectionParams) {
    UNIMPLEMENTED();
    return StubReturn();
}
