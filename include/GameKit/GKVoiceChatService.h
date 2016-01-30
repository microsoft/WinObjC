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

#import <Foundation/NSObjCRuntime.h>
#import <Foundation/NSObject.h>

@class NSString;
@protocol GKVoiceChatClient;
@class NSError;
@class NSData;

typedef enum {
    GKVoiceChatServiceInternalError = 32000,
    GKVoiceChatServiceNoRemotePacketsError = 32001,
    GKVoiceChatServiceUnableToConnectError = 32002,
    GKVoiceChatServiceRemoteParticipantHangupError = 32003,
    GKVoiceChatServiceInvalidCallIDError = 32004,
    GKVoiceChatServiceAudioUnavailableError = 32005,
    GKVoiceChatServiceUninitializedClientError = 32006,
    GKVoiceChatServiceClientMissingRequiredMethodsError = 32007,
    GKVoiceChatServiceRemoteParticipantBusyError = 32008,
    GKVoiceChatServiceRemoteParticipantCancelledError = 32009,
    GKVoiceChatServiceRemoteParticipantResponseInvalidError = 32010,
    GKVoiceChatServiceRemoteParticipantDeclinedInviteError = 32011,
    GKVoiceChatServiceMethodCurrentlyInvalidError = 32012,
    GKVoiceChatServiceNetworkConfigurationError = 32013,
    GKVoiceChatServiceUnsupportedRemoteVersionError = 32014,
    GKVoiceChatServiceOutOfMemoryError = 32015,
    GKVoiceChatServiceInvalidParameterError = 32016,
} GKVoiceChatServiceError;

GAMEKIT_EXPORT NSString* const GKVoiceChatServiceErrorDomain;

GAMEKIT_EXPORT_CLASS
@interface GKVoiceChatService : NSObject <NSObject>
+ (BOOL)isVoIPAllowed STUB_METHOD;
+ (GKVoiceChatService*)defaultVoiceChatService STUB_METHOD;
- (BOOL)startVoiceChatWithParticipantID:(NSString*)participantID error:(NSError**)error STUB_METHOD;
- (void)stopVoiceChatWithParticipantID:(NSString*)participantID STUB_METHOD;
- (BOOL)acceptCallID:(NSInteger)callID error:(NSError**)error STUB_METHOD;
- (void)denyCallID:(NSInteger)callID STUB_METHOD;
- (void)receivedData:(NSData*)arbitraryData fromParticipantID:(NSString*)participantID STUB_METHOD;
- (void)receivedRealTimeData:(NSData*)audio fromParticipantID:(NSString*)participantID STUB_METHOD;
@property (getter=isMicrophoneMuted, nonatomic) BOOL microphoneMuted STUB_PROPERTY;
@property (nonatomic) float remoteParticipantVolume STUB_PROPERTY;
@property (getter=isInputMeteringEnabled, nonatomic) BOOL inputMeteringEnabled STUB_PROPERTY;
@property (readonly) float inputMeterLevel STUB_PROPERTY;
@property (getter=isOutputMeteringEnabled, nonatomic) BOOL outputMeteringEnabled STUB_PROPERTY;
@property (readonly) float outputMeterLevel STUB_PROPERTY;
@property (assign) id<GKVoiceChatClient> client STUB_PROPERTY;
@end
