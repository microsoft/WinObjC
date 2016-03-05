/**
 * OpenAL cross platform audio library
 * Copyright (C) 2014 by Le Hoang Quyen.
 * Copyright (C) 2011 by authors.
 * This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the
 *  Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 *  Boston, MA  02111-1307, USA.
 * Or go to http://www.gnu.org/copyleft/lgpl.html
 */

#include "config.h"

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include <list>
#include <new>
#include <stdexcept>

#include <windows.h>
#include <winapifamily.h>
#include <wrl\implements.h> 

#include <audioclient.h>
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP//win phone
#	include <phoneaudioclient.h>
#else //win store app
#	include <Mmdeviceapi.h>
#endif

#include <cguid.h>
#include <mmreg.h>
#ifndef _WAVEFORMATEXTENSIBLE_
#include <ks.h>
#include <ksmedia.h>
#endif

#ifdef _MSC_VER
#include <intrin.h>
#endif

#include "alMain.h"
#include "AL/al.h"
#include "AL/alc.h"
#include "thread_msg_queue_cpp11.h"

using namespace Microsoft::WRL;

#define EVENT_ACCESS_MASK (DELETE | SYNCHRONIZE | EVENT_MODIFY_STATE) 

#define WaitForSingleObject(handle, timeout) WaitForSingleObjectEx(handle, timeout, FALSE)

#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP//win phone
static inline HRESULT CoInitialize(void *arg) {
	HRESULT hr = CoInitializeEx(arg, COINIT_MULTITHREADED);
	//return hr;//TO DO: should return S_OK
	return S_OK;
}
#else//win store app
static inline HRESULT CoInitialize(void *arg) {
	//HRESULT hr = CoInitializeEx(arg, COINIT_APARTMENTTHREADED);
	Windows::Foundation::Initialize(RO_INIT_MULTITHREADED);
	//return hr;//TO DO: should return S_OK
	return S_OK;
}
#endif

#define MONO SPEAKER_FRONT_CENTER
#define STEREO (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT)
#define QUAD (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT|SPEAKER_BACK_LEFT|SPEAKER_BACK_RIGHT)
#define X5DOT1 (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT|SPEAKER_FRONT_CENTER|SPEAKER_LOW_FREQUENCY|SPEAKER_BACK_LEFT|SPEAKER_BACK_RIGHT)
#define X5DOT1SIDE (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT|SPEAKER_FRONT_CENTER|SPEAKER_LOW_FREQUENCY|SPEAKER_SIDE_LEFT|SPEAKER_SIDE_RIGHT)
#define X6DOT1 (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT|SPEAKER_FRONT_CENTER|SPEAKER_LOW_FREQUENCY|SPEAKER_BACK_CENTER|SPEAKER_SIDE_LEFT|SPEAKER_SIDE_RIGHT)
#define X7DOT1 (SPEAKER_FRONT_LEFT|SPEAKER_FRONT_RIGHT|SPEAKER_FRONT_CENTER|SPEAKER_LOW_FREQUENCY|SPEAKER_BACK_LEFT|SPEAKER_BACK_RIGHT|SPEAKER_SIDE_LEFT|SPEAKER_SIDE_RIGHT)

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p) {if (p) {(p)->Release(); (p) = 0;}}
#endif


//API's data
typedef struct {
	IAudioClient *client;
	HANDLE hNotifyEvent;

	HANDLE MsgEvent;

	volatile int killNow;
	ALvoid *thread;
	//win store
#if WINAPI_FAMILY == WINAPI_FAMILY_APP
	Windows::UI::Core::CoreDispatcher ^ uiDispatcher;
#endif
} WASAPIDevApiData;

//win store
#if WINAPI_FAMILY == WINAPI_FAMILY_APP
//callback handler to be called when audio interface has been activated
class ActivateAudioInterfaceCompletionHandler : public RuntimeClass< RuntimeClassFlags< ClassicCom >, FtmBase, IActivateAudioInterfaceCompletionHandler >
{
public:
	ActivateAudioInterfaceCompletionHandler(IAudioClient **_pClient)
		: m_completed(FALSE), m_ppClient(_pClient), m_result(S_FALSE)
	{}

	HRESULT STDMETHODCALLTYPE ActivateCompleted(IActivateAudioInterfaceAsyncOperation *operation)
	{
		HRESULT hr = S_OK;
		HRESULT hrActivateResult = S_OK;
		IUnknown *punkAudioInterface = nullptr;

		*m_ppClient = nullptr;

		// Check for a successful activation result 
		hr = operation->GetActivateResult(&hrActivateResult, &punkAudioInterface);
		if (SUCCEEDED(hr) && SUCCEEDED(hrActivateResult))
		{
			// Get the pointer for the Audio Client 
			punkAudioInterface->QueryInterface(IID_PPV_ARGS(m_ppClient));
			if (nullptr == m_ppClient)
			{
				hr = E_FAIL;
				goto exit;
			}

		}

	exit:
		SAFE_RELEASE(punkAudioInterface);

		if (FAILED(hr))
		{
			SAFE_RELEASE(*m_ppClient);
		}

		//store return code
		m_result = hr;

		InterlockedExchange(&m_completed, TRUE);//notify that the audio interface has been activated

		// Need to return S_OK 
		return S_OK;
	}

	ULONG m_completed;
	IAudioClient **m_ppClient;
	HRESULT m_result;
};

#endif//#if WINAPI_FAMILY == WINAPI_FAMILY_APP

static const ALCchar mmDevice[] = "WASAPI Default";


static MsgQueue_t *g_MsgQueue = nullptr;
static ALvoid* g_MsgQueueThread = nullptr;

typedef struct {
    HANDLE FinishedEvt;
    HRESULT result;
} ThreadRequest;

#define TM_USER_OpenDevice  (WM_USER+0)
#define TM_USER_ResetDevice (WM_USER+1)
#define TM_USER_StopDevice  (WM_USER+2)
#define TM_USER_CloseDevice (WM_USER+3)

static HRESULT WaitForResponse(ThreadRequest *req)
{
    if(WaitForSingleObject(req->FinishedEvt, INFINITE) == WAIT_OBJECT_0)
        return req->result;
    ERR("Message response error: %lu\n", GetLastError());
    return E_FAIL;
}


static ALuint WASAPIDevApiProc(ALvoid *ptr)
{
	ALCdevice *device = (ALCdevice *)ptr;
	WASAPIDevApiData *data = (WASAPIDevApiData *)device->ExtraData;
    union {
        IAudioRenderClient *iface;
        void *ptr;
    } render;
    UINT32 written, len;
    BYTE *buffer;
    HRESULT hr;

    hr = CoInitialize(NULL);
    if(FAILED(hr))
    {
        ERR("CoInitialize(NULL) failed: 0x%08lx\n", hr);
        aluHandleDisconnect(device);
        return 0;
    }

    hr = data->client->GetService( IID_IAudioRenderClient, &render.ptr);
    if(FAILED(hr))
    {
        ERR("Failed to get AudioRenderClient service: 0x%08lx\n", hr);
        aluHandleDisconnect(device);
        return 0;
    }

    SetRTPriority();

    while(!data->killNow)
    {
        hr = data->client->GetCurrentPadding( &written);
        if(FAILED(hr))
        {
            ERR("Failed to get padding: 0x%08lx\n", hr);
            aluHandleDisconnect(device);
            break;
        }

        len = device->UpdateSize*device->NumUpdates - written;
        if(len < device->UpdateSize)
        {
            DWORD res;
            res = WaitForSingleObjectEx(data->hNotifyEvent, 2000, FALSE);
            if(res != WAIT_OBJECT_0)
                ERR("WaitForSingleObjectEx error: 0x%lx\n", res);
            continue;
        }
        len -= len%device->UpdateSize;

        hr = render.iface->GetBuffer( len, &buffer);
        if(SUCCEEDED(hr))
        {
            aluMixData(device, buffer, len);
            hr = render.iface->ReleaseBuffer( len, 0);
        }
        if(FAILED(hr))
        {
            ERR("Failed to buffer data: 0x%08lx\n", hr);
            aluHandleDisconnect(device);
            break;
        }
    }

    render.iface->Release();

    CoUninitialize();
    return 0;
}


static ALCboolean MakeExtensible(WAVEFORMATEXTENSIBLE *out, const WAVEFORMATEX *in)
{
    memset(out, 0, sizeof(*out));
    if(in->wFormatTag == WAVE_FORMAT_EXTENSIBLE)
        *out = *(WAVEFORMATEXTENSIBLE*)in;
    else if(in->wFormatTag == WAVE_FORMAT_PCM)
    {
        out->Format = *in;
        out->Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
        out->Format.cbSize = sizeof(*out) - sizeof(*in);
        if(out->Format.nChannels == 1)
            out->dwChannelMask = MONO;
        else if(out->Format.nChannels == 2)
            out->dwChannelMask = STEREO;
        else
            ERR("Unhandled PCM channel count: %d\n", out->Format.nChannels);
        out->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
    }
    else if(in->wFormatTag == WAVE_FORMAT_IEEE_FLOAT)
    {
        out->Format = *in;
        out->Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
        out->Format.cbSize = sizeof(*out) - sizeof(*in);
        if(out->Format.nChannels == 1)
            out->dwChannelMask = MONO;
        else if(out->Format.nChannels == 2)
            out->dwChannelMask = STEREO;
        else
            ERR("Unhandled IEEE float channel count: %d\n", out->Format.nChannels);
        out->SubFormat = KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;
    }
    else
    {
        ERR("Unhandled format tag: 0x%04x\n", in->wFormatTag);
        return ALC_FALSE;
    }
    return ALC_TRUE;
}

static HRESULT DoReset(ALCdevice *device)
{
	WASAPIDevApiData *data = (WASAPIDevApiData *)device->ExtraData;
    WAVEFORMATEXTENSIBLE OutputType;
    WAVEFORMATEX *wfx = NULL;
    REFERENCE_TIME min_per;
    UINT32 buffer_len, min_len;
    HRESULT hr;

    hr = data->client->GetMixFormat( &wfx);
    if(FAILED(hr))
    {
        ERR("Failed to get mix format: 0x%08lx\n", hr);
        return hr;
    }

    if(!MakeExtensible(&OutputType, wfx))
    {
        CoTaskMemFree(wfx);
        return E_FAIL;
    }
    CoTaskMemFree(wfx);
    wfx = NULL;

    if(!(device->Flags&DEVICE_FREQUENCY_REQUEST))
        device->Frequency = OutputType.Format.nSamplesPerSec;
    if(!(device->Flags&DEVICE_CHANNELS_REQUEST))
    {
        if(OutputType.Format.nChannels == 1 && OutputType.dwChannelMask == MONO)
            device->FmtChans = DevFmtMono;
        else if(OutputType.Format.nChannels == 2 && OutputType.dwChannelMask == STEREO)
            device->FmtChans = DevFmtStereo;
        else if(OutputType.Format.nChannels == 4 && OutputType.dwChannelMask == QUAD)
            device->FmtChans = DevFmtQuad;
        else if(OutputType.Format.nChannels == 6 && OutputType.dwChannelMask == X5DOT1)
            device->FmtChans = DevFmtX51;
        else if(OutputType.Format.nChannels == 6 && OutputType.dwChannelMask == X5DOT1SIDE)
            device->FmtChans = DevFmtX51Side;
        else if(OutputType.Format.nChannels == 7 && OutputType.dwChannelMask == X6DOT1)
            device->FmtChans = DevFmtX61;
        else if(OutputType.Format.nChannels == 8 && OutputType.dwChannelMask == X7DOT1)
            device->FmtChans = DevFmtX71;
        else
            ERR("Unhandled channel config: %d -- 0x%08lx\n", OutputType.Format.nChannels, OutputType.dwChannelMask);
    }

    switch(device->FmtChans)
    {
        case DevFmtMono:
            OutputType.Format.nChannels = 1;
            OutputType.dwChannelMask = MONO;
            break;
        case DevFmtStereo:
            OutputType.Format.nChannels = 2;
            OutputType.dwChannelMask = STEREO;
            break;
        case DevFmtQuad:
            OutputType.Format.nChannels = 4;
            OutputType.dwChannelMask = QUAD;
            break;
        case DevFmtX51:
            OutputType.Format.nChannels = 6;
            OutputType.dwChannelMask = X5DOT1;
            break;
        case DevFmtX51Side:
            OutputType.Format.nChannels = 6;
            OutputType.dwChannelMask = X5DOT1SIDE;
            break;
        case DevFmtX61:
            OutputType.Format.nChannels = 7;
            OutputType.dwChannelMask = X6DOT1;
            break;
        case DevFmtX71:
            OutputType.Format.nChannels = 8;
            OutputType.dwChannelMask = X7DOT1;
            break;
    }
    switch(device->FmtType)
    {
        case DevFmtByte:
            device->FmtType = DevFmtUByte;
            /* fall-through */
        case DevFmtUByte:
            OutputType.Format.wBitsPerSample = 8;
            OutputType.Samples.wValidBitsPerSample = 8;
            OutputType.SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
            break;
        case DevFmtUShort:
            device->FmtType = DevFmtShort;
            /* fall-through */
        case DevFmtShort:
            OutputType.Format.wBitsPerSample = 16;
            OutputType.Samples.wValidBitsPerSample = 16;
            OutputType.SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
            break;
        case DevFmtFloat:
            OutputType.Format.wBitsPerSample = 32;
            OutputType.Samples.wValidBitsPerSample = 32;
            OutputType.SubFormat = KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;
            break;
    }
    OutputType.Format.nSamplesPerSec = device->Frequency;

    OutputType.Format.nBlockAlign = OutputType.Format.nChannels *
                                    OutputType.Format.wBitsPerSample / 8;
    OutputType.Format.nAvgBytesPerSec = OutputType.Format.nSamplesPerSec *
                                        OutputType.Format.nBlockAlign;

    hr = data->client->IsFormatSupported( AUDCLNT_SHAREMODE_SHARED, &OutputType.Format, &wfx);
    if(FAILED(hr))
    {
        ERR("Failed to check format support: 0x%08lx\n", hr);
        hr = data->client->GetMixFormat( &wfx);
    }
    if(FAILED(hr))
    {
        ERR("Failed to find a supported format: 0x%08lx\n", hr);
        return hr;
    }

    if(wfx != NULL)
    {
        if(!MakeExtensible(&OutputType, wfx))
        {
            CoTaskMemFree(wfx);
            return E_FAIL;
        }
        CoTaskMemFree(wfx);
        wfx = NULL;

        device->Frequency = OutputType.Format.nSamplesPerSec;
        if(OutputType.Format.nChannels == 1 && OutputType.dwChannelMask == MONO)
            device->FmtChans = DevFmtMono;
        else if(OutputType.Format.nChannels == 2 && OutputType.dwChannelMask == STEREO)
            device->FmtChans = DevFmtStereo;
        else if(OutputType.Format.nChannels == 4 && OutputType.dwChannelMask == QUAD)
            device->FmtChans = DevFmtQuad;
        else if(OutputType.Format.nChannels == 6 && OutputType.dwChannelMask == X5DOT1)
            device->FmtChans = DevFmtX51;
        else if(OutputType.Format.nChannels == 6 && OutputType.dwChannelMask == X5DOT1SIDE)
            device->FmtChans = DevFmtX51Side;
        else if(OutputType.Format.nChannels == 7 && OutputType.dwChannelMask == X6DOT1)
            device->FmtChans = DevFmtX61;
        else if(OutputType.Format.nChannels == 8 && OutputType.dwChannelMask == X7DOT1)
            device->FmtChans = DevFmtX71;
        else
        {
            ERR("Unhandled extensible channels: %d -- 0x%08lx\n", OutputType.Format.nChannels, OutputType.dwChannelMask);
            device->FmtChans = DevFmtStereo;
            OutputType.Format.nChannels = 2;
            OutputType.dwChannelMask = STEREO;
        }

        if(IsEqualGUID(OutputType.SubFormat, KSDATAFORMAT_SUBTYPE_PCM))
        {
            if(OutputType.Format.wBitsPerSample == 8)
                device->FmtType = DevFmtUByte;
            else if(OutputType.Format.wBitsPerSample == 16)
                device->FmtType = DevFmtShort;
            else
            {
                device->FmtType = DevFmtShort;
                OutputType.Format.wBitsPerSample = 16;
            }
        }
        else if(IsEqualGUID(OutputType.SubFormat, KSDATAFORMAT_SUBTYPE_IEEE_FLOAT))
        {
            device->FmtType = DevFmtFloat;
            OutputType.Format.wBitsPerSample = 32;
        }
        else
        {
            ERR("Unhandled format sub-type\n");
            device->FmtType = DevFmtShort;
            OutputType.Format.wBitsPerSample = 16;
            OutputType.SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
        }
        OutputType.Samples.wValidBitsPerSample = OutputType.Format.wBitsPerSample;
    }

    SetDefaultWFXChannelOrder(device);

    hr = data->client->GetDevicePeriod( &min_per, NULL);
    if(SUCCEEDED(hr))
    {
        min_len = (min_per*device->Frequency + 10000000-1) / 10000000;
        if(min_len < device->UpdateSize)
            min_len *= (device->UpdateSize + min_len/2)/min_len;

        device->NumUpdates = (device->NumUpdates*device->UpdateSize + min_len/2) /
                             min_len;
        device->NumUpdates = maxu(device->NumUpdates, 2);
        device->UpdateSize = min_len;

        hr = data->client->Initialize( AUDCLNT_SHAREMODE_SHARED,
                                     AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
                                     ((REFERENCE_TIME)device->UpdateSize*
                                      device->NumUpdates*10000000 +
                                      device->Frequency-1) / device->Frequency,
                                     0, &OutputType.Format, NULL);
    }
    if(FAILED(hr))
    {
        ERR("Failed to initialize audio client: 0x%08lx\n", hr);
        return hr;
    }

    hr = data->client->GetBufferSize( &buffer_len);
    if(FAILED(hr))
    {
        ERR("Failed to get audio buffer info: 0x%08lx\n", hr);
        return hr;
    }

    device->NumUpdates = buffer_len / device->UpdateSize;
    if(device->NumUpdates <= 1)
    {
        device->NumUpdates = 1;
        ERR("Audio client returned buffer_len < period*2; expect break up\n");
    }

    ResetEvent(data->hNotifyEvent);
    hr = data->client->SetEventHandle( data->hNotifyEvent);
    if(SUCCEEDED(hr))
        hr = data->client->Start();
    if(FAILED(hr))
    {
        ERR("Failed to start audio client: 0x%08lx\n", hr);
        return hr;
    }

    data->thread = StartThread(WASAPIDevApiProc, device);
    if(!data->thread)
    {
        data->client->Stop();
        ERR("Failed to start thread\n");
        return E_FAIL;
    }

    return hr;
}

static HRESULT ActivateDefaultAudioEndpoint(IAudioClient** ppInterface, WASAPIDevApiData* apiData)
{
	HRESULT hr = S_OK;
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP//win phone
	//get default device id
	LPCWSTR pwstrDefaultRenderDeviceId = GetDefaultAudioRenderId(AudioDeviceRole::Default);

	//activate device interface
	hr = ActivateAudioInterface(pwstrDefaultRenderDeviceId, __uuidof(IAudioClient2), (void**)ppInterface);
#else//win store
	auto asyncCompletedHandler = Make<ActivateAudioInterfaceCompletionHandler>(ppInterface);

	//get default device id
	auto deviceIdString = Windows::Media::Devices::MediaDevice::GetDefaultAudioRenderId(
		Windows::Media::Devices::AudioDeviceRole::Default);

	//activate device interface on UI Thread
	auto dispatcher = apiData->uiDispatcher;
	auto activateTask = [&, deviceIdString, asyncCompletedHandler]()
	{

		IActivateAudioInterfaceAsyncOperation *asyncOp;

		hr = ActivateAudioInterfaceAsync(deviceIdString->Data(), __uuidof(IAudioClient2), nullptr, asyncCompletedHandler.Get(), &asyncOp);

		SAFE_RELEASE(asyncOp);

	};

	if (dispatcher->HasThreadAccess)//this is ui thread
		activateTask();//run immediately
	else//run it on ui thread
		dispatcher->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal,
		ref new Windows::UI::Core::DispatchedHandler(activateTask));

	//wait for the device to be activated
	if (SUCCEEDED(hr))
	{
		while (asyncCompletedHandler->m_completed == FALSE)
		{
			sched_yield();
		}

		hr = asyncCompletedHandler->m_result;
	}

#endif

	return hr;
}

static ALuint WASAPIDevApiMsgProc(void *ptr)
{
	ThreadRequest *req = (ThreadRequest *)ptr;
    ALuint deviceCount = 0;
    WASAPIDevApiData *data;
    ALCdevice *device;
    HRESULT hr;
    QueueMsg_t msg;

    TRACE("Starting message thread\n");

    req->result = S_OK;
    SetEvent(req->FinishedEvt);

    TRACE("Starting message loop\n");
	while (g_MsgQueue->GetMsg(&msg))
    {
        TRACE("Got message %u\n", msg.message);
        switch(msg.message)
        {
        case TM_USER_OpenDevice:
            req = (ThreadRequest*)msg.wParam;
            device = (ALCdevice*)msg.lParam;
			data = (WASAPIDevApiData*)device->ExtraData;

            hr = S_OK;
            if(++deviceCount == 1)
                hr = CoInitialize(NULL);
            
			if(SUCCEEDED(hr))
				hr = ActivateDefaultAudioEndpoint(&data->client, data);

            req->result = hr;
            SetEvent(req->FinishedEvt);
            continue;

        case TM_USER_ResetDevice:
            req = (ThreadRequest*)msg.wParam;
            device = (ALCdevice*)msg.lParam;

            req->result = DoReset(device);
            SetEvent(req->FinishedEvt);
            continue;

        case TM_USER_StopDevice:
            req = (ThreadRequest*)msg.wParam;
            device = (ALCdevice*)msg.lParam;
			data = (WASAPIDevApiData *)device->ExtraData;

            if(data->thread)
            {
                data->killNow = 1;
                StopThread(data->thread);
                data->thread = NULL;

                data->killNow = 0;

                data->client->Stop();
            }

            req->result = S_OK;
            SetEvent(req->FinishedEvt);
            continue;

        case TM_USER_CloseDevice:
            req = (ThreadRequest*)msg.wParam;
            device = (ALCdevice*)msg.lParam;
			data = (WASAPIDevApiData *)device->ExtraData;

            data->client->Release();
            data->client = NULL;

			if(--deviceCount == 0)
                CoUninitialize();

            req->result = S_OK;
            SetEvent(req->FinishedEvt);
            continue;

        default:
            ERR("Unexpected message: %u\n", msg.message);
            continue;
        }
    }
    TRACE("Message loop finished\n");

	return TRUE;
}


static BOOL WASAPIDevApiLoad(void)
{
    static HRESULT InitResult;
	if (!g_MsgQueueThread)
    {
        ThreadRequest req;
        InitResult = E_FAIL;

		req.FinishedEvt = CreateEventEx(NULL, NULL, 0, EVENT_ACCESS_MASK);
        if(req.FinishedEvt == NULL)
            ERR("Failed to create event: %lu\n", GetLastError());
        else
        {
			try {
				g_MsgQueue = new MsgQueue_t();//create message queue
			}
			catch (...)
			{
				g_MsgQueue = nullptr;
			}

			if (g_MsgQueue != nullptr)
				g_MsgQueueThread = StartThread(WASAPIDevApiMsgProc, &req);//create message queue thread

			if (g_MsgQueueThread != nullptr)
			{

				InitResult = WaitForResponse(&req);
			}
			else//failed to create message queue thread
			{
				//delete message queue
				delete g_MsgQueue;
				g_MsgQueue = nullptr;
			}

            CloseHandle(req.FinishedEvt);
        }
    }
    return SUCCEEDED(InitResult);
}


static ALCenum WASAPIDevApiOpenPlayback(ALCdevice *device, const ALCchar *deviceName)
{
    WASAPIDevApiData *data = NULL;
    HRESULT hr;

    if(!deviceName)
        deviceName = mmDevice;
    else if(strcmp(deviceName, mmDevice) != 0)
        return ALC_INVALID_VALUE;

    //Initialise requested device
	data = (WASAPIDevApiData *)calloc(1, sizeof(WASAPIDevApiData));
    if(!data)
        return ALC_OUT_OF_MEMORY;
    device->ExtraData = data;

#if WINAPI_FAMILY == WINAPI_FAMILY_APP//win store
	//obtain ui dispatcher
	auto coreWindow = Windows::UI::Core::CoreWindow::GetForCurrentThread();
	if (coreWindow == nullptr)
	{
		try {
			auto mainView = Windows::ApplicationModel::Core::CoreApplication::MainView;
			if (mainView != nullptr)
				coreWindow = mainView->CoreWindow;
		}
		catch (...)
		{
			coreWindow = nullptr;
		}
	}
	//make sure the UI window is available
	bool assertTrue = coreWindow != nullptr;

	if (!assertTrue)
	{
		const char errorMsg[] = "Fatal error: You are calling a OpenAL function before UI window is visible\n\n";
#if defined DEBUG || defined _DEBUG
		OutputDebugStringA(errorMsg);
		__debugbreak();
#else
		throw std::runtime_error(errorMsg);
		//crashes the system
		//_ASSERT_EXPR(false, L"You are calling a OpenAL function before UI window is visible");
#endif
		free(data);
		device->ExtraData = NULL;

		return ALC_INVALID_DEVICE;
	}

	//get ui dispatcher
	data->uiDispatcher = coreWindow->Dispatcher;

	//make sure we are not calling this function on UI thread
	assertTrue = data->uiDispatcher->HasThreadAccess == false;

	if (!assertTrue)
	{
		const char errorMsg[] = "Fatal error: You are calling alcOpenDevice() on UI thread\n\n";
#if defined _DEBUG || defined DEBUG
		OutputDebugStringA(errorMsg);
		__debugbreak();
#else
		throw std::runtime_error(errorMsg);
		//_ASSERT_EXPR(false, L"You are calling alcOpenDevice() on UI thread");
#endif
		free(data);
		device->ExtraData = NULL;

		return ALC_INVALID_DEVICE;
	}
#endif//#if WINAPI_FAMILY == WINAPI_FAMILY_APP

    hr = S_OK;
    data->hNotifyEvent = CreateEventEx(NULL, NULL, 0, EVENT_ACCESS_MASK);
    data->MsgEvent = CreateEventEx(NULL, NULL, 0, EVENT_ACCESS_MASK);
    if(data->hNotifyEvent == NULL || data->MsgEvent == NULL)
        hr = E_FAIL;

    if(SUCCEEDED(hr))
    {
        ThreadRequest req = { data->MsgEvent, 0 };

        hr = E_FAIL;
		if (g_MsgQueue->PostMsg(TM_USER_OpenDevice, &req, device))
            hr = WaitForResponse(&req);
    }

    if(FAILED(hr))
    {
        if(data->hNotifyEvent != NULL)
            CloseHandle(data->hNotifyEvent);
        data->hNotifyEvent = NULL;
        if(data->MsgEvent != NULL)
            CloseHandle(data->MsgEvent);
        data->MsgEvent = NULL;

        free(data);
        device->ExtraData = NULL;

        ERR("Device init failed: 0x%08lx\n", hr);
        return ALC_INVALID_VALUE;
    }

    device->szDeviceName = _strdup(deviceName);
    return ALC_NO_ERROR;
}

static void WASAPIDevApiClosePlayback(ALCdevice *device)
{
	WASAPIDevApiData *data = (WASAPIDevApiData *)device->ExtraData;
    ThreadRequest req = { data->MsgEvent, 0 };

	if (g_MsgQueue->PostMsg(TM_USER_CloseDevice, &req, device))
		(void)WaitForResponse(&req);

    CloseHandle(data->MsgEvent);
    data->MsgEvent = NULL;

    CloseHandle(data->hNotifyEvent);
    data->hNotifyEvent = NULL;

    free(data);
    device->ExtraData = NULL;
}

static ALCboolean WASAPIDevApiResetPlayback(ALCdevice *device)
{
	WASAPIDevApiData *data = (WASAPIDevApiData *)device->ExtraData;
    ThreadRequest req = { data->MsgEvent, 0 };
    HRESULT hr = E_FAIL;

	if (g_MsgQueue->PostMsg(TM_USER_ResetDevice, &req, device))
        hr = WaitForResponse(&req);

    return SUCCEEDED(hr) ? ALC_TRUE : ALC_FALSE;
}

static void WASAPIDevApiStopPlayback(ALCdevice *device)
{
	WASAPIDevApiData *data = (WASAPIDevApiData *)device->ExtraData;
    ThreadRequest req = { data->MsgEvent, 0 };

    if(g_MsgQueue->PostMsg(TM_USER_StopDevice, &req, device))
        (void)WaitForResponse(&req);
}


static const BackendFuncs WASAPIDevApiFuncs = {
    WASAPIDevApiOpenPlayback,
    WASAPIDevApiClosePlayback,
    WASAPIDevApiResetPlayback,
    WASAPIDevApiStopPlayback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
};


ALCboolean alcWASAPIDevApiInit(BackendFuncs *FuncList)
{
    if(!WASAPIDevApiLoad())
        return ALC_FALSE;
    *FuncList = WASAPIDevApiFuncs;
    return ALC_TRUE;
}

void alcWASAPIDevApiDeinit(void)
{
	if (g_MsgQueueThread)
    {
		TRACE("Sending TM_QUIT\n");
		g_MsgQueue->PostMsg(TM_QUIT, 0, 0);//post quit message

		//release thread and its message queue
		StopThread(g_MsgQueueThread);
		delete g_MsgQueue;
		g_MsgQueueThread = nullptr;
		g_MsgQueue = nullptr;
    }
}

void alcWASAPIDevApiProbe(enum DevProbe type)
{
    switch(type)
    {
        case DEVICE_PROBE:
            AppendDeviceList(mmDevice);
            break;
        case ALL_DEVICE_PROBE:
            AppendAllDeviceList(mmDevice);
            break;
        case CAPTURE_DEVICE_PROBE:
            break;
    }
}
