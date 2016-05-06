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
#import <GameKit/GKVoiceChatService.h>

NSString* const GKVoiceChatServiceErrorDomain = @"GKVoiceChatServiceErrorDomain";

@implementation GKVoiceChatService
/**
 @Status Stub
 @Notes
*/
+ (BOOL)isVoIPAllowed {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (GKVoiceChatService*)defaultVoiceChatService {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)startVoiceChatWithParticipantID:(NSString*)participantID error:(NSError**)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopVoiceChatWithParticipantID:(NSString*)participantID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)acceptCallID:(NSInteger)callID error:(NSError**)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)denyCallID:(NSInteger)callID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)receivedData:(NSData*)arbitraryData fromParticipantID:(NSString*)participantID {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)receivedRealTimeData:(NSData*)audio fromParticipantID:(NSString*)participantID {
    UNIMPLEMENTED();
}

@end
