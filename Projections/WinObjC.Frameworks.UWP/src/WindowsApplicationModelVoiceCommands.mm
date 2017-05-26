//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

// WindowsApplicationModelVoiceCommands.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.VoiceCommands.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelVoiceCommands.h"
#include "WindowsApplicationModelVoiceCommands_priv.h"

@implementation WAVVoiceCommandDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)setPhraseListAsync:(NSString*)phraseListName phraseList:(id<NSFastEnumeration> /* NSString * */)phraseList {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPhraseListAsync(nsStrToHstr(phraseListName).Get(),
                                     static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(phraseList).Get()),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAVVoiceCommandDefinitionManager

ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics>
WAVIVoiceCommandDefinitionManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.VoiceCommands.VoiceCommandDefinitionManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)installCommandDefinitionsFromStorageFileAsync:(WSStorageFile*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandDefinitionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->InstallCommandDefinitionsFromStorageFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (NSDictionary* /* NSString *, WAVVoiceCommandDefinition* */)installedCommandDefinitions {
    ComPtr<IMapView<HSTRING, ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition*>> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandDefinitionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_InstalledCommandDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WAVVoiceCommandDefinition_create(unmarshalledReturn.Get());
}

@end

@implementation WAVVoiceCommandContentTile

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.VoiceCommands.VoiceCommandContentTile").Get(), &out));
    return [_createRtProxy<WAVVoiceCommandContentTile>(out.Get()) retain];
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)textLine1 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextLine1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTextLine1:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextLine1(nsStrToHstr(value).Get()));
}

- (NSString*)textLine2 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextLine2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTextLine2:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextLine2(nsStrToHstr(value).Get()));
}

- (NSString*)textLine3 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextLine3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTextLine3:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextLine3(nsStrToHstr(value).Get()));
}

- (RTObject<WSIStorageFile>*)image {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_Image(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

- (void)setImage:(RTObject<WSIStorageFile>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_Image(_getRtInterface<ABI::Windows::Storage::IStorageFile>(value).Get()));
}

- (RTObject*)appContext {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppContext(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setAppContext:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppContext([value comObj].Get()));
}

- (NSString*)appLaunchArgument {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppLaunchArgument(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAppLaunchArgument:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppLaunchArgument(nsStrToHstr(value).Get()));
}

- (WAVVoiceCommandContentTileType)contentTileType {
    ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTileType(&unmarshalledReturn));
    return (WAVVoiceCommandContentTileType)unmarshalledReturn;
}

- (void)setContentTileType:(WAVVoiceCommandContentTileType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentTileType((ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTileType)value));
}

@end

@implementation WAVVoiceCommandUserMessage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.ApplicationModel.VoiceCommands.VoiceCommandUserMessage").Get(), &out));
    return [_createRtProxy<WAVVoiceCommandUserMessage>(out.Get()) retain];
}

- (NSString*)displayMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setDisplayMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayMessage(nsStrToHstr(value).Get()));
}

- (NSString*)spokenMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpokenMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSpokenMessage:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpokenMessage(nsStrToHstr(value).Get()));
}

@end

@implementation WAVVoiceCommand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)commandName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSDictionary* /* NSString *, NSArray* < NSString * > */)properties {
    ComPtr<IMapView<HSTRING, IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WMSSpeechRecognitionResult*)speechRecognitionResult {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpeechRecognitionResult(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognitionResult>(unmarshalledReturn.Get());
}

@end

@implementation WAVVoiceCommandResponse

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics> WAVIVoiceCommandResponseStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.VoiceCommands.VoiceCommandResponse").Get(), &inst));
    return inst;
}

+ (unsigned int)maxSupportedVoiceCommandContentTiles {
    unsigned int unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandResponseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxSupportedVoiceCommandContentTiles(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WAVVoiceCommandResponse*)createResponse:(WAVVoiceCommandUserMessage*)userMessage {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandResponseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResponse(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(userMessage).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandResponse>(unmarshalledReturn.Get());
}

+ (WAVVoiceCommandResponse*)createResponseWithTiles:(WAVVoiceCommandUserMessage*)message
                                       contentTiles:(id<NSFastEnumeration> /* WAVVoiceCommandContentTile* */)contentTiles {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandResponseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResponseWithTiles(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(message).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
            ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*>>::type>*>(
            ConvertToIterable<WAVVoiceCommandContentTile,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
                                  ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*>>(contentTiles)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandResponse>(unmarshalledReturn.Get());
}

+ (WAVVoiceCommandResponse*)createResponseForPrompt:(WAVVoiceCommandUserMessage*)message
                                      repeatMessage:(WAVVoiceCommandUserMessage*)repeatMessage {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandResponseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResponseForPrompt(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(message).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(repeatMessage).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandResponse>(unmarshalledReturn.Get());
}

+ (WAVVoiceCommandResponse*)createResponseForPromptWithTiles:(WAVVoiceCommandUserMessage*)message
                                               repeatMessage:(WAVVoiceCommandUserMessage*)repeatMessage
                                                contentTiles:(id<NSFastEnumeration> /* WAVVoiceCommandContentTile* */)contentTiles {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandResponseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateResponseForPromptWithTiles(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(message).Get(),
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(repeatMessage).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<ABI::Windows::Foundation::Internal::AggregateType<
            ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
            ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*>>::type>*>(
            ConvertToIterable<WAVVoiceCommandContentTile,
                              ABI::Windows::Foundation::Internal::AggregateType<
                                  ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
                                  ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*>>(contentTiles)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandResponse>(unmarshalledReturn.Get());
}

- (WAVVoiceCommandUserMessage*)message {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_Message(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandUserMessage>(unmarshalledReturn.Get());
}

- (void)setMessage:(WAVVoiceCommandUserMessage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_Message(_getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(value).Get()));
}

- (WAVVoiceCommandUserMessage*)repeatMessage {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_RepeatMessage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandUserMessage>(unmarshalledReturn.Get());
}

- (void)setRepeatMessage:(WAVVoiceCommandUserMessage*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_RepeatMessage(_getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage>(value).Get()));
}

- (NSString*)appLaunchArgument {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppLaunchArgument(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAppLaunchArgument:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(_comInst->put_AppLaunchArgument(nsStrToHstr(value).Get()));
}

- (NSMutableArray* /* WAVVoiceCommandContentTile* */)voiceCommandContentTiles {
    ComPtr<IVector<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_VoiceCommandContentTiles(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WAVVoiceCommandContentTile_create(unmarshalledReturn.Get());
}

@end

@implementation WAVVoiceCommandConfirmationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)confirmed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Confirmed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WAVVoiceCommandDisambiguationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAVVoiceCommandContentTile*)selectedItem {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedItem(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandContentTile>(unmarshalledReturn.Get());
}

@end

@implementation WAVVoiceCommandServiceConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics>
WAVIVoiceCommandServiceConnectionStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.VoiceCommands.VoiceCommandServiceConnection").Get(), &inst));
    return inst;
}

+ (WAVVoiceCommandServiceConnection*)fromAppServiceTriggerDetails:(WAAAppServiceTriggerDetails*)triggerDetails {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection> unmarshalledReturn;
    auto _comInst = WAVIVoiceCommandServiceConnectionStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromAppServiceTriggerDetails(
        _getRtInterface<ABI::Windows::ApplicationModel::AppService::IAppServiceTriggerDetails>(triggerDetails).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAVVoiceCommandServiceConnection>(unmarshalledReturn.Get());
}

- (void)getVoiceCommandAsyncWithSuccess:(void (^)(WAVVoiceCommand*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->GetVoiceCommandAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommand*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommand*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommand> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WAVVoiceCommand>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)requestConfirmationAsync:(WAVVoiceCommandResponse*)response
                         success:(void (^)(WAVVoiceCommandConfirmationResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->RequestConfirmationAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandConfirmationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAVVoiceCommandConfirmationResult>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)requestDisambiguationAsync:(WAVVoiceCommandResponse*)response
                           success:(void (^)(WAVVoiceCommandDisambiguationResult*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->RequestDisambiguationAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDisambiguationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAVVoiceCommandDisambiguationResult>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (RTObject<WFIAsyncAction>*)reportProgressAsync:(WAVVoiceCommandResponse*)response {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportProgressAsync(_getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportSuccessAsync:(WAVVoiceCommandResponse*)response {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportSuccessAsync(_getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailureAsync:(WAVVoiceCommandResponse*)response {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportFailureAsync(_getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)requestAppLaunchAsync:(WAVVoiceCommandResponse*)response {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->RequestAppLaunchAsync(
        _getRtInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponse>(response).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (WGLanguage*)language {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addVoiceCommandCompletedEvent:(void (^)(WAVVoiceCommandServiceConnection*,
                                                                  WAVVoiceCommandCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_VoiceCommandCompleted(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVoiceCommandCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VoiceCommandCompleted(token));
}

@end

@implementation WAVVoiceCommandCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAVVoiceCommandCompletionReason)reason {
    ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletionReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WAVVoiceCommandCompletionReason)unmarshalledReturn;
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedIterableNSArray_WAVVoiceCommandContentTile_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*>,
                                RTIterableObj<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*,
                                              IIterable<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*>,
                                              WAVVoiceCommandContentTile,
                                              ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
                                              dummyObjCCreator,
                                              dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IVectorView<HSTRING>*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IVectorView<HSTRING>*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IVectorView<HSTRING>*,
                                          IVectorView<HSTRING>*,
                                          NSString,
                                          RTProxiedNSArray,
                                          IMapView<HSTRING, IVectorView<HSTRING>*>,
                                          dummyObjCCreator,
                                          RTProxiedNSArray_NSString_create,
                                          dummyWRLCreator,
                                          ConvertToVectorView<NSString, HSTRING>>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WAVVoiceCommandDefinition_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition*,
                     ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinition*,
                     NSString,
                     WAVVoiceCommandDefinition,
                     IMapView<HSTRING, ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandDefinition*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WAVVoiceCommandContentTile_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*>,
                               RTMutableArrayObj<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandContentTile*,
                                                 IVector<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*>,
                                                 WAVVoiceCommandContentTile,
                                                 ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandContentTile*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
