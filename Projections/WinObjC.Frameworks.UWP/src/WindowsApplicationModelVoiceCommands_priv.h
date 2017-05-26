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

// WindowsApplicationModelVoiceCommands_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsStorage_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsGlobalization_priv.h"
#include "WindowsMediaSpeechRecognition_priv.h"
#include "WindowsApplicationModelAppService_priv.h"
ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandDefinitionManagerStatics>
WAVIVoiceCommandDefinitionManagerStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandResponseStatics> WAVIVoiceCommandResponseStatics_inst();
ComPtr<ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnectionStatics>
WAVIVoiceCommandServiceConnectionStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_WAVVoiceCommandContentTile_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WAVVoiceCommandDefinition_create(IInspectable* val);
id RTProxiedNSMutableArray_WAVVoiceCommandContentTile_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedIterableNSArray_WAVVoiceCommandContentTile, RTProxiedNSArray_NSString,
    RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString;
@class RTProxiedNSDictionary_NSString_WAVVoiceCommandDefinition, RTProxiedNSMutableArray_WAVVoiceCommandContentTile;

#ifndef __ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandServiceConnection*,
                                                       ABI::Windows::ApplicationModel::VoiceCommands::VoiceCommandCompletedEventArgs*>> {
    void (^_delegate)(WAVVoiceCommandServiceConnection*, WAVVoiceCommandCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs(
        void (^del)(WAVVoiceCommandServiceConnection*, WAVVoiceCommandCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_ApplicationModel_VoiceCommands_VoiceCommandServiceConnection_Windows_ApplicationModel_VoiceCommands_VoiceCommandCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection* arg0,
           ABI::Windows::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WAVVoiceCommandServiceConnection>(arg0), _createRtProxy<WAVVoiceCommandCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
