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
#pragma once

#import <GameKit/GameKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class GKVoiceChatService;
@class NSData;
@class NSError;

@protocol GKVoiceChatClient <NSObject>
@required
- (NSString*)participantID;
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService sendData:(NSData*)data toParticipantID:(NSString*)participantID;

@optional
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService sendRealTimeData:(NSData*)data toParticipantID:(NSString*)participantID;
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService
    didReceiveInvitationFromParticipantID:(NSString*)participantID
                                   callID:(NSInteger)callID;
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService didStartWithParticipantID:(NSString*)participantID;
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService didNotStartWithParticipantID:(NSString*)participantID error:(NSError*)error;
- (void)voiceChatService:(GKVoiceChatService*)voiceChatService didStopWithParticipantID:(NSString*)participantID error:(NSError*)error;
@end
