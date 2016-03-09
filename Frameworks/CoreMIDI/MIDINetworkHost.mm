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
#import <CoreMIDI/MIDINetworkHost.h>

NSString* const MIDINetworkBonjourServiceType = @"MIDINetworkBonjourServiceType";

@implementation MIDINetworkHost
/**
 @Status Stub
 @Notes
*/
+ (instancetype)hostWithName:(NSString*)name address:(NSString*)address port:(NSUInteger)port {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)hostWithName:(NSString*)name netService:(NSNetService*)netService {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)hostWithName:(NSString*)name netServiceName:(NSString*)netServiceName netServiceDomain:(NSString*)netServiceDomain {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)hasSameAddressAs:(MIDINetworkHost*)other {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
