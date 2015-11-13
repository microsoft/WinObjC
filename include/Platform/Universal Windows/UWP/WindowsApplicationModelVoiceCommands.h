//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsApplicationModelVoiceCommands.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WAVVoiceCommandDefinition, WAVVoiceCommandDefinitionManager, WAVVoiceCommandContentTile, WAVVoiceCommandUserMessage, WAVVoiceCommand,
    WAVVoiceCommandResponse, WAVVoiceCommandConfirmationResult, WAVVoiceCommandDisambiguationResult, WAVVoiceCommandServiceConnection,
    WAVVoiceCommandCompletedEventArgs;
@protocol WAVIVoiceCommandDefinitionManagerStatics
, WAVIVoiceCommandDefinition, WAVIVoiceCommandContentTile, WAVIVoiceCommandUserMessage, WAVIVoiceCommand,
    WAVIVoiceCommandCompletedEventArgs, WAVIVoiceCommandDisambiguationResult, WAVIVoiceCommandConfirmationResult,
    WAVIVoiceCommandServiceConnection, WAVIVoiceCommandServiceConnectionStatics, WAVIVoiceCommandResponseStatics, WAVIVoiceCommandResponse;

// Windows.ApplicationModel.VoiceCommands.VoiceCommandContentTileType
enum _WAVVoiceCommandContentTileType {
    WAVVoiceCommandContentTileTypeTitleOnly = 0,
    WAVVoiceCommandContentTileTypeTitleWithText = 1,
    WAVVoiceCommandContentTileTypeTitleWith68x68Icon = 2,
    WAVVoiceCommandContentTileTypeTitleWith68x68IconAndText = 3,
    WAVVoiceCommandContentTileTypeTitleWith68x92Icon = 4,
    WAVVoiceCommandContentTileTypeTitleWith68x92IconAndText = 5,
    WAVVoiceCommandContentTileTypeTitleWith280x140Icon = 6,
    WAVVoiceCommandContentTileTypeTitleWith280x140IconAndText = 7,
};
typedef unsigned WAVVoiceCommandContentTileType;

// Windows.ApplicationModel.VoiceCommands.VoiceCommandCompletionReason
enum _WAVVoiceCommandCompletionReason {
    WAVVoiceCommandCompletionReasonUnknown = 0,
    WAVVoiceCommandCompletionReasonCommunicationFailed = 1,
    WAVVoiceCommandCompletionReasonResourceLimitsExceeded = 2,
    WAVVoiceCommandCompletionReasonCanceled = 3,
    WAVVoiceCommandCompletionReasonTimeoutExceeded = 4,
    WAVVoiceCommandCompletionReasonAppLaunched = 5,
    WAVVoiceCommandCompletionReasonCompleted = 6,
};
typedef unsigned WAVVoiceCommandCompletionReason;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsGlobalization.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsApplicationModelAppService.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.VoiceCommands.VoiceCommandDefinition
#ifndef __WAVVoiceCommandDefinition_DEFINED__
#define __WAVVoiceCommandDefinition_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandDefinition : RTObject
@property (readonly) NSString* language;
@property (readonly) NSString* name;
- (RTObject<WFIAsyncAction>*)setPhraseListAsync:(NSString*)phraseListName phraseList:(id<NSFastEnumeration> /* NSString * */)phraseList;
@end

#endif // __WAVVoiceCommandDefinition_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandDefinitionManager
#ifndef __WAVVoiceCommandDefinitionManager_DEFINED__
#define __WAVVoiceCommandDefinitionManager_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandDefinitionManager : RTObject
+ (RTObject<WFIAsyncAction>*)installCommandDefinitionsFromStorageFileAsync:(WSStorageFile*)file;
+ (NSDictionary*)installedCommandDefinitions;
@end

#endif // __WAVVoiceCommandDefinitionManager_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandContentTile
#ifndef __WAVVoiceCommandContentTile_DEFINED__
#define __WAVVoiceCommandContentTile_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandContentTile : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property (copy) NSString* textLine3;
@property (copy) NSString* textLine2;
@property (copy) NSString* textLine1;
@property (copy) RTObject<WSIStorageFile>* image;
@property WAVVoiceCommandContentTileType contentTileType;
@property (copy) NSString* appLaunchArgument;
@property (copy) RTObject* appContext;
@end

#endif // __WAVVoiceCommandContentTile_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandUserMessage
#ifndef __WAVVoiceCommandUserMessage_DEFINED__
#define __WAVVoiceCommandUserMessage_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandUserMessage : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* spokenMessage;
@property (copy) NSString* displayMessage;
@end

#endif // __WAVVoiceCommandUserMessage_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommand
#ifndef __WAVVoiceCommand_DEFINED__
#define __WAVVoiceCommand_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommand : RTObject
@property (readonly) NSString* commandName;
@property (readonly) NSDictionary* properties;
@property (readonly) WMSSpeechRecognitionResult* speechRecognitionResult;
@end

#endif // __WAVVoiceCommand_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandResponse
#ifndef __WAVVoiceCommandResponse_DEFINED__
#define __WAVVoiceCommandResponse_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandResponse : RTObject
+ (WAVVoiceCommandResponse*)createResponse:(WAVVoiceCommandUserMessage*)userMessage;
+ (WAVVoiceCommandResponse*)createResponseWithTiles:(WAVVoiceCommandUserMessage*)message
                                       contentTiles:(id<NSFastEnumeration> /* WAVVoiceCommandContentTile* */)contentTiles;
+ (WAVVoiceCommandResponse*)createResponseForPrompt:(WAVVoiceCommandUserMessage*)message
                                      repeatMessage:(WAVVoiceCommandUserMessage*)repeatMessage;
+ (WAVVoiceCommandResponse*)createResponseForPromptWithTiles:(WAVVoiceCommandUserMessage*)message
                                               repeatMessage:(WAVVoiceCommandUserMessage*)repeatMessage
                                                contentTiles:(id<NSFastEnumeration> /* WAVVoiceCommandContentTile* */)contentTiles;
@property (copy) WAVVoiceCommandUserMessage* repeatMessage;
@property (copy) WAVVoiceCommandUserMessage* message;
@property (copy) NSString* appLaunchArgument;
@property (readonly) NSMutableArray* voiceCommandContentTiles;
+ (unsigned int)maxSupportedVoiceCommandContentTiles;
@end

#endif // __WAVVoiceCommandResponse_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandConfirmationResult
#ifndef __WAVVoiceCommandConfirmationResult_DEFINED__
#define __WAVVoiceCommandConfirmationResult_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandConfirmationResult : RTObject
@property (readonly) BOOL confirmed;
@end

#endif // __WAVVoiceCommandConfirmationResult_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandDisambiguationResult
#ifndef __WAVVoiceCommandDisambiguationResult_DEFINED__
#define __WAVVoiceCommandDisambiguationResult_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandDisambiguationResult : RTObject
@property (readonly) WAVVoiceCommandContentTile* selectedItem;
@end

#endif // __WAVVoiceCommandDisambiguationResult_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandServiceConnection
#ifndef __WAVVoiceCommandServiceConnection_DEFINED__
#define __WAVVoiceCommandServiceConnection_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandServiceConnection : RTObject
+ (WAVVoiceCommandServiceConnection*)fromAppServiceTriggerDetails:(WAAAppServiceTriggerDetails*)triggerDetails;
@property (readonly) WGLanguage* language;
- (EventRegistrationToken)addVoiceCommandCompletedEvent:(void (^)(WAVVoiceCommandServiceConnection*,
                                                                  WAVVoiceCommandCompletedEventArgs*))del;
- (void)removeVoiceCommandCompletedEvent:(EventRegistrationToken)tok;
- (void)getVoiceCommandAsyncWithSuccess:(void (^)(WAVVoiceCommand*))success failure:(void (^)(NSError*))failure;
- (void)requestConfirmationAsync:(WAVVoiceCommandResponse*)response
                         success:(void (^)(WAVVoiceCommandConfirmationResult*))success
                         failure:(void (^)(NSError*))failure;
- (void)requestDisambiguationAsync:(WAVVoiceCommandResponse*)response
                           success:(void (^)(WAVVoiceCommandDisambiguationResult*))success
                           failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)reportProgressAsync:(WAVVoiceCommandResponse*)response;
- (RTObject<WFIAsyncAction>*)reportSuccessAsync:(WAVVoiceCommandResponse*)response;
- (RTObject<WFIAsyncAction>*)reportFailureAsync:(WAVVoiceCommandResponse*)response;
- (RTObject<WFIAsyncAction>*)requestAppLaunchAsync:(WAVVoiceCommandResponse*)response;
@end

#endif // __WAVVoiceCommandServiceConnection_DEFINED__

// Windows.ApplicationModel.VoiceCommands.VoiceCommandCompletedEventArgs
#ifndef __WAVVoiceCommandCompletedEventArgs_DEFINED__
#define __WAVVoiceCommandCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WAVVoiceCommandCompletedEventArgs : RTObject
@property (readonly) WAVVoiceCommandCompletionReason reason;
@end

#endif // __WAVVoiceCommandCompletedEventArgs_DEFINED__
