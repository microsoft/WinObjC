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

#include "Starboard.h"

#include <COMIncludes.h>
#include <wrl/client.h>
#include <audioclient.h>
#include <cguid.h>
#include <mmreg.h>
#include <propsys.h>
#include <ks.h>
#include <ksmedia.h>

#include <synchapi.h>
#include <Mmdeviceapi.h>
#include "windows.media.devices.h"
#include <COMIncludes_End.h>

#include <process.h>
#include <stdlib.h>
#include <assert.h>

#include <eh.h>
#include <vector>
#include <map>
#include <deque>
#include <mutex>
#include <memory>
#include <thread>

#include "OpenAL\al.h"
#include "OpenAL\alc.h"

#undef AL_API
#undef ALC_API

#define AL_API __declspec(dllexport)
#define ALC_API __declspec(dllexport)

using namespace Microsoft::WRL;
using namespace std;

typedef struct { float left, right; } MixBufFrame;

#define FP_WHOLE(x) ((x) >> 16)
#define FP_DIV(x, y) ((((DWORD)(x)) << 16) / (DWORD)(y))

class ALBufferPlayback {
public:
    int _curSourceBufPos;

    //  Always filled with float stereo frames at source buffer frequency
    MixBufFrame _frameBuf[256];
    int _frameBufLen, _frameBufMax;
    int _frameBufFreq;

    //  16:16 fixed point for resampling
    DWORD _frameBufPos;

    ALBufferPlayback() {
        Reset();
    }

    void Reset() {
        _curSourceBufPos = 0;
        _frameBufPos = 0;
        _frameBufLen = 0;
        _frameBufFreq = 0;
        _frameBufMax = 256;
    }
};

class ALBuffer {
public:
    int _freq, _bits, _channels;
    void* _data;
    int _dataLen;
    int _frameLen;
    int _handle;

    ALBuffer() {
        _freq = _bits = _channels = _dataLen = 0;
        _handle = -1;
        _data = NULL;
    }

    ~ALBuffer() {
        if (_data) {
            free(_data);
            _data = NULL;
        }
    }

    bool FillBuffer(ALBufferPlayback* bufInfo) {
        int sourceFramesAvailable = (_dataLen - bufInfo->_curSourceBufPos) / _frameLen;
        int framesToCopy = sourceFramesAvailable < (bufInfo->_frameBufMax - bufInfo->_frameBufLen)
                               ? sourceFramesAvailable
                               : (bufInfo->_frameBufMax - bufInfo->_frameBufLen);

        BYTE* dataStart = ((BYTE*)_data) + bufInfo->_curSourceBufPos;
        if (_bits == 16) {
            if (_channels == 2) {
                signed short* src = (signed short*)dataStart;
                MixBufFrame* dst = (MixBufFrame*)&bufInfo->_frameBuf[bufInfo->_frameBufLen];
                int left = framesToCopy;
                while (left--) {
                    dst->left = (*src) / 32767.0f;
                    src++;
                    dst->right = (*src) / 32767.0f;
                    src++;
                    dst++;
                }
            } else {
                signed short* src = (signed short*)dataStart;
                MixBufFrame* dst = (MixBufFrame*)&bufInfo->_frameBuf[bufInfo->_frameBufLen];
                int left = framesToCopy;
                while (left--) {
                    dst->right = dst->left = (*src) / 32767.0f;
                    dst++;
                    src++;
                }
            }
        } else if (_bits == 8) {
            if (_channels == 2) {
                unsigned char* src = (unsigned char*)dataStart;
                MixBufFrame* dst = (MixBufFrame*)&bufInfo->_frameBuf[bufInfo->_frameBufLen];
                int left = framesToCopy;
                while (left--) {
                    dst->left = (*src) / 255.0f;
                    src++;
                    dst->right = (*src) / 255.0f;
                    src++;
                    dst++;
                }
            } else {
                unsigned char* src = (unsigned char*)dataStart;
                MixBufFrame* dst = (MixBufFrame*)&bufInfo->_frameBuf[bufInfo->_frameBufLen];
                int left = framesToCopy;
                while (left--) {
                    dst->right = dst->left = (*src) / 255.0f;
                    dst++;
                    src++;
                }
            }
        } else {
            printf("bits is %d\n", _bits);
            assert(0);
        }

        bufInfo->_curSourceBufPos += framesToCopy * _frameLen;
        bufInfo->_frameBufLen += framesToCopy;
        bufInfo->_frameBufFreq = _freq;
        return bufInfo->_curSourceBufPos < _dataLen;
    }

    void BufferData(ALenum format, const ALvoid* data, ALsizei size, ALsizei freq) {
        if (_data)
            free(_data);
        if (!data) {
            _bits = 16;
            _channels = 1;
            _freq = 11000;
            _data = NULL;
            _dataLen = 0;
            _frameLen = 1;
            return;
        }

        switch (format) {
            case AL_FORMAT_STEREO16:
                _bits = 16;
                _channels = 2;
                break;

            case AL_FORMAT_MONO16:
                _bits = 16;
                _channels = 1;
                break;

            case AL_FORMAT_STEREO8:
                _bits = 8;
                _channels = 2;
                break;

            case AL_FORMAT_MONO8:
                _bits = 8;
                _channels = 1;
                break;

            default:
                assert(0);
                break;
        }
        _data = (void*)malloc(size);
        memcpy(_data, data, size);
        _dataLen = size;
        _freq = freq;
        _frameLen = _bits * _channels / 8;
    }
};

class ALSource;
struct ALCcontext_struct;

struct ALCdevice_struct {
private:
    typedef vector<ALCcontext_struct*> ContextsList;
    ContextsList _contexts;
    mutex _contextsLock;
    HANDLE _playbackWakeup, _playbackTerminated;
    bool _terminateThread;
    std::thread _playbackThread;

public:
    typedef enum { SourcePlay } CommandType;

private:
    struct Command {
        CommandType _type;
        void* _ptr;
    };

    deque<Command> _commands;
    mutex _commandsLock;

public:
    void AudioPlaybackThread();
    ALCdevice_struct();
    void Destroy();
    ALCcontext_struct* CreateContext();
    void QueueCommand(CommandType type, void* param);
};

class BufferList {
public:
    shared_ptr<BufferList> nextBuffer;
    shared_ptr<ALBuffer> buf;
    bool addToProcessedList;
};

struct ALCcontext_struct {
private:
    map<int, shared_ptr<ALBuffer>> _buffers;
    int _curBufId;
    map<int, shared_ptr<ALSource>> _sources;
    mutex _listLock;

public:
    ALCdevice* _parent;
    ALCcontext_struct(ALCdevice* parent);

    void Destroy();
    void GenSources(ALsizei n, ALuint* sources);
    void DeleteSources(ALsizei n, const ALuint* sources);
    void GenBuffers(ALsizei n, ALuint* buffers);
    void BufferData(ALuint buffer, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq);
    void Sourcei(ALuint source, ALenum param, ALint value);
    void Sourcef(ALuint source, ALenum param, ALfloat value);
    void GetSourcei(ALuint source, ALenum param, ALint* value);
    void SourcePlay(ALuint source);
    void SourceStop(ALuint source);
    bool MixStream(MixBufFrame* destBuffer, DWORD numSamples);
    void SourceQueueBuffers(ALuint source, ALsizei nb, const ALuint* buffers);
    void SourceUnqueueBuffers(ALuint source, ALsizei nb, ALuint* buffers);
    void DeleteBuffers(ALsizei n, const ALuint* buffers);
    shared_ptr<ALBuffer> BufferForHandle(int buf) {
        shared_ptr<ALBuffer> ret;

        _listLock.lock();
        ret = _buffers[buf];
        _listLock.unlock();

        return ret;
    }
};

class ALSource {
public:
    shared_ptr<BufferList> _firstBuffer, _curBuffer, _lastBuffer;
    recursive_mutex _listLock;
    ALBufferPlayback _bufInfo;
    DWORD _state;
    DWORD _internalState;
    ALCcontext* _parent;
    BOOL _looping;
    vector<shared_ptr<ALBuffer>> _processedBuffers;

    ~ALSource() {
        _parent = NULL;
    }

    void GetNextBuffer() {
        _listLock.lock();
        if (_state == AL_STOPPED) {
            _curBuffer = NULL;
            _listLock.unlock();
            return;
        }

        if (_curBuffer == NULL) {
            _curBuffer = _firstBuffer;
        } else {
            if (_curBuffer->addToProcessedList) {
                shared_ptr<BufferList> cur = _curBuffer;
                shared_ptr<BufferList> next = _curBuffer->nextBuffer;

                _processedBuffers.push_back(cur->buf);
                if (cur == _firstBuffer) {
                    _firstBuffer = next;
                }
                if (cur == _lastBuffer) {
                    _lastBuffer = next;
                }
                _curBuffer = next;
            } else {
                _curBuffer = _curBuffer->nextBuffer;
            }

            if (_curBuffer == NULL) {
                if (_looping == TRUE) {
                    _curBuffer = _firstBuffer;
                } else {
                    _state = AL_STOPPED;
                }
            }
        }
        _listLock.unlock();
    }

    bool MixStream(MixBufFrame* destBuffer, DWORD numFrames) {
        if (_state != AL_PLAYING)
            return false;

        bool addedSamples = false;
        bool nextBuffer = false;

        _listLock.lock();
        while (numFrames > 0) {
            if (_curBuffer == NULL || nextBuffer) {
                nextBuffer = false;
                GetNextBuffer();
                _bufInfo.Reset();
            }

            if (_curBuffer != NULL) {
                if (FP_WHOLE(_bufInfo._frameBufPos) >= _bufInfo._frameBufLen) {
                    _bufInfo._frameBufPos &= 0xFFFF;
                    _bufInfo._frameBufLen = 0;

                    bool moreData = _curBuffer->buf->FillBuffer(&_bufInfo);
                    if (!moreData) {
                        nextBuffer = true;
                    }
                }

                DWORD scaler = FP_DIV(_bufInfo._frameBufFreq, 44100);

                if (FP_WHOLE(_bufInfo._frameBufPos) < _bufInfo._frameBufLen) {
                    addedSamples = true;
                }

                while (FP_WHOLE(_bufInfo._frameBufPos) < _bufInfo._frameBufLen && numFrames > 0) {
                    MixBufFrame* srcFrame = &_bufInfo._frameBuf[FP_WHOLE(_bufInfo._frameBufPos)];

                    destBuffer->left += srcFrame->left;
                    destBuffer->right += srcFrame->right;
                    destBuffer++;
                    numFrames--;
                    _bufInfo._frameBufPos += scaler;
                }
            } else
                break;
        }
        _listLock.unlock();

        return addedSamples;
    }

    void ClearQueue() {
        _listLock.lock();
        shared_ptr<BufferList> cur = _firstBuffer;
        while (cur) {
            shared_ptr<BufferList> next = cur->nextBuffer;
            cur->nextBuffer = NULL;
            cur = next;
        }

        _firstBuffer = NULL;
        _lastBuffer = NULL;
        _curBuffer = NULL;
        _listLock.unlock();
    }

    void QueueBuffer(shared_ptr<ALBuffer> buf, bool addToProcessedList = false) {
        shared_ptr<BufferList> newItem = make_shared<BufferList>();
        newItem->buf = buf;
        newItem->nextBuffer = NULL;
        newItem->addToProcessedList = addToProcessedList;

        _listLock.lock();
        if (_lastBuffer) {
            _lastBuffer->nextBuffer = newItem;
        }
        if (_firstBuffer == NULL) {
            _firstBuffer = newItem;
        }
        if (_lastBuffer == NULL) {
            _lastBuffer = newItem;
        }
        _listLock.unlock();
    }

    void QueueBuffers(ALsizei nb, const ALuint* buffers) {
        for (int i = 0; i < nb; i++) {
            QueueBuffer(_parent->BufferForHandle(buffers[i]), true);
        }
    }

    void UnqueueBuffers(ALsizei nb, ALuint* buffers) {
        _listLock.lock();
        assert(_processedBuffers.size() >= nb);
        for (int i = 0; i < nb; i++) {
            buffers[i] = _processedBuffers[i]->_handle;
        }
        _processedBuffers.erase(_processedBuffers.begin(), _processedBuffers.begin() + nb);
        _listLock.unlock();
    }

    ALSource(ALCcontext_struct* parent) {
        _parent = parent;
        _firstBuffer = NULL;
        _curBuffer = NULL;
        _lastBuffer = NULL;
        _looping = FALSE;
        _state = AL_INITIAL;
        _internalState = AL_INITIAL;
    }

    void GetSourcei(ALenum param, ALint* value) {
        switch (param) {
            case AL_SOURCE_STATE:
                *value = _state;
                return;

            case AL_BUFFERS_QUEUED: {
                _listLock.lock();
                int count = 0;
                shared_ptr<BufferList> cur = _firstBuffer;
                while (cur) {
                    count++;
                    cur = cur->nextBuffer;
                }
                *value = count;
                _listLock.unlock();
            } break;

            case AL_BUFFERS_PROCESSED:
                _listLock.lock();
                *value = _processedBuffers.size();
                _listLock.unlock();
                break;

            default:
                assert(0);
                break;
        }
    }

    void Sourcei(ALenum param, ALint value) {
        switch (param) {
            case AL_BUFFER: {
                ClearQueue();
                if (value != 0) {
                    shared_ptr<ALBuffer> buf = _parent->BufferForHandle(value);
                    QueueBuffer(buf);
                    if (_state == AL_PLAYING) {
                        _parent->_parent->QueueCommand(ALCdevice_struct::SourcePlay, this);
                    }
                }
            } break;

            case AL_LOOPING:
                _looping = value == AL_TRUE;
                break;

            default:
                assert(0);
                break;

            case AL_SOURCE_RELATIVE:
                break;
        }
    }

    void Sourcef(ALenum param, ALfloat value) {
        switch (param) {
            case AL_GAIN:
            case AL_ROLLOFF_FACTOR:
            case AL_PITCH: {
                EbrDebugLog("Not supported");
                // assert(value == 1.0);
            } break;

            default:
                assert(0);
                break;
        }
    }

    void Play() {
        if (_state == AL_PLAYING)
            return;
        _state = AL_PLAYING;

        _parent->_parent->QueueCommand(ALCdevice_struct::SourcePlay, this);
    }

    void Stop() {
        _state = AL_STOPPED;
    }
};

ALCcontext_struct::ALCcontext_struct(ALCdevice* parent) : _parent(parent) {
    _curBufId = 1;
}

void ALCcontext_struct::Destroy() {
}

void ALCcontext_struct::GenSources(ALsizei n, ALuint* sources) {
    _listLock.lock();
    for (int i = 0; i < n; i++) {
        static int handleNum = 1;
        int handle = handleNum;

        handleNum++;
        sources[i] = handle;
        shared_ptr<ALSource> newSource = make_shared<ALSource>(this);
        _sources[handle] = newSource;
    }
    _listLock.unlock();
}

void ALCcontext_struct::DeleteSources(ALsizei n, const ALuint* sources) {
    _listLock.lock();
    for (int i = 0; i < n; i++) {
        auto it = _sources.find(sources[i]);
        _sources.erase(it);
    }
    _listLock.unlock();
}

void ALCcontext_struct::GenBuffers(ALsizei n, ALuint* buffers) {
    _listLock.lock();
    for (int i = 0; i < n; i++) {
        int handle = _curBufId++;
        buffers[i] = handle;
        shared_ptr<ALBuffer> newBuffer = make_shared<ALBuffer>();

        newBuffer->_handle = handle;
        _buffers[newBuffer->_handle] = newBuffer;
    }
    _listLock.unlock();
}

bool ALCcontext_struct::MixStream(MixBufFrame* destBuffer, DWORD numFrames) {
    bool ret = false;
    _listLock.lock();
    for (auto& curSource : _sources) {
        bool addedSamples = curSource.second->MixStream(destBuffer, numFrames);
        if (addedSamples)
            ret = true;
    }
    _listLock.unlock();

    return ret;
}

void ALCcontext_struct::BufferData(ALuint buffer, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq) {
    BufferForHandle(buffer)->BufferData(format, data, size, freq);
}

void ALCcontext_struct::Sourcei(ALuint source, ALenum param, ALint value) {
    if (_sources.find(source) == _sources.end())
        return;

    _sources[source]->Sourcei(param, value);
}

void ALCcontext_struct::Sourcef(ALuint source, ALenum param, ALfloat value) {
    if (_sources.find(source) == _sources.end())
        return;

    _sources[source]->Sourcef(param, value);
}

void ALCcontext_struct::GetSourcei(ALuint source, ALenum param, ALint* value) {
    if (_sources.find(source) == _sources.end())
        return;

    _sources[source]->GetSourcei(param, value);
}

void ALCcontext_struct::SourcePlay(ALuint source) {
    if (_sources.find(source) == _sources.end())
        return;

    _sources[source]->Play();
}

void ALCcontext_struct::SourceQueueBuffers(ALuint source, ALsizei nb, const ALuint* buffers) {
    _sources[source]->QueueBuffers(nb, buffers);
}

void ALCcontext_struct::SourceUnqueueBuffers(ALuint source, ALsizei nb, ALuint* buffers) {
    _sources[source]->UnqueueBuffers(nb, buffers);
}

void ALCcontext_struct::DeleteBuffers(ALsizei n, const ALuint* buffers) {
    for (int i = 0; i < n; i++) {
        auto it = _buffers.find(buffers[i]);
        _buffers.erase(it);
    }
}

void ALCcontext_struct::SourceStop(ALuint source) {
    if (_sources.find(source) == _sources.end())
        return;

    _sources[source]->Stop();
}

ALCdevice_struct::ALCdevice_struct() {
    _playbackWakeup = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
    _playbackTerminated = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
    _terminateThread = false;

#ifdef EBRIUS
    auto workItemHandler = ref new Windows::System::Threading::WorkItemHandler(
        [=](Windows::Foundation::IAsyncAction ^ ) { AudioPlaybackThread(); }, Platform::CallbackContext::Any);

    Windows::System::Threading::ThreadPool::RunAsync(workItemHandler,
                                                     Windows::System::Threading::WorkItemPriority::High,
                                                     Windows::System::Threading::WorkItemOptions::TimeSliced);
#else
    _playbackThread = std::thread(&ALCdevice_struct::AudioPlaybackThread, this);
#endif
}

class AudioDeviceOpenHandler : public IActivateAudioInterfaceCompletionHandler, IAgileObject {
public:
    ComPtr<IAudioClient2> client;
    HANDLE completed;

    AudioDeviceOpenHandler() {
        completed = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
    }

    void Wait() {
        WaitForSingleObjectEx(completed, INFINITE, TRUE);
    }

    HRESULT CALLBACK QueryInterface(REFIID riid, void** ppvObject) {
        if (riid == __uuidof(IActivateAudioInterfaceCompletionHandler) || riid == __uuidof(IAgileObject)) {
            *ppvObject = this;
            return S_OK;
        }

        return E_NOTIMPL;
    }

    ULONG CALLBACK AddRef() {
        return 1;
    }

    ULONG CALLBACK Release() {
        return 1;
    }

    HRESULT CALLBACK ActivateCompleted(IActivateAudioInterfaceAsyncOperation* activateOperation) {
        IUnknown* pUnk;

        HRESULT hr = E_FAIL;
        activateOperation->GetActivateResult(&hr, &pUnk);
        if (pUnk) {
            pUnk->QueryInterface(__uuidof(client), (void**)client.GetAddressOf());
        }
        SetEvent(completed);

        return S_OK;
    }
};

const GUID OUTPUT_DEVICE = { 0xe6327cad, 0xdcec, 0x4949, 0xae, 0x8a, 0x99, 0x1e, 0x97, 0x6a, 0x79, 0xd2 };

void ALCdevice_struct::AudioPlaybackThread() {
    ComPtr<IAudioClient2> client;
    ComPtr<IAudioRenderClient> renderClient;
    HANDLE hBufferReadyEvent;
    HRESULT hr;

    EbrSetCurrentThreadName("OpenAL playback thread");

    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    __block AudioDeviceOpenHandler openCallback;
    __block IActivateAudioInterfaceAsyncOperation* complete;
    __block HRESULT activateResult = E_FAIL;

    void (^activateAudioOnMainThread)() = ^void() {
        ABI::Windows::Media::Devices::IMediaDeviceStatics* deviceFinder;
        HSTRING mediaDeviceClass;
        WindowsCreateString(RuntimeClass_Windows_Media_Devices_MediaDevice,
                            wcslen(RuntimeClass_Windows_Media_Devices_MediaDevice),
                            &mediaDeviceClass);
        ABI::Windows::Foundation::GetActivationFactory(mediaDeviceClass, &deviceFinder);
        WindowsDeleteString(mediaDeviceClass);

        HSTRING defaultRenderDevice;
        deviceFinder->GetDefaultAudioRenderId(ABI::Windows::Media::Devices::AudioDeviceRole::AudioDeviceRole_Default,
                                              &defaultRenderDevice);
        deviceFinder->Release();

        UINT32 len = 0;
        PCWSTR deviceNameRaw = WindowsGetStringRawBuffer(defaultRenderDevice, &len);
        PWSTR deviceName = (PWSTR)calloc(len + 1, 2);
        memcpy(deviceName, deviceNameRaw, len * 2);

        activateResult = ActivateAudioInterfaceAsync(deviceName,
                                                     (REFIID) __uuidof(IAudioClient2),
                                                     NULL,
                                                     (IActivateAudioInterfaceCompletionHandler*)&openCallback,
                                                     &complete);
        free(deviceName);
        WindowsDeleteString(defaultRenderDevice);
    };
    NSArray* modes = [[NSArray alloc] initWithObject:kCFRunLoopDefaultMode];
    [[NSRunLoop mainRunLoop] performSelector:@selector(invoke)
                                      target:activateAudioOnMainThread
                                    argument:nil
                                       order:0
                                       modes:modes];
    openCallback.Wait();

    hr = activateResult;
    client = openCallback.client;

    hBufferReadyEvent = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);

    WAVEFORMATEX outputFmt = { 0 };
    outputFmt.wFormatTag = WAVE_FORMAT_IEEE_FLOAT;
    outputFmt.cbSize = 0;
    outputFmt.nChannels = 2;
    outputFmt.nSamplesPerSec = 44100;
    outputFmt.wBitsPerSample = 32;
    outputFmt.nBlockAlign = outputFmt.nChannels * outputFmt.wBitsPerSample / 8;
    outputFmt.nAvgBytesPerSec = outputFmt.nSamplesPerSec * outputFmt.nBlockAlign;

    if (FAILED(hr) || !client) {
        EbrDebugLog("Failed to create client audio device");
    } else {
        hr = client->Initialize(AUDCLNT_SHAREMODE_SHARED,
                                AUDCLNT_STREAMFLAGS_RATEADJUST | AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
                                1000000LL,
                                0,
                                &outputFmt,
                                NULL);
        if (FAILED(hr)) {
            EbrDebugLog("IAudioClient::Initialize failed hr=0x%x\n", hr);
        }

        hr = client->SetEventHandle(hBufferReadyEvent);
        if (FAILED(hr)) {
            EbrDebugLog("IAudioClient::SetEventHandle failed hr=0x%x\n", hr);
        }

        hr = client->GetService(__uuidof(IAudioRenderClient), (void**)renderClient.GetAddressOf());
        if (FAILED(hr)) {
            EbrDebugLog("IAudioClient::GetService failed hr=0x%x\n", hr);
        }

        hr = client->Start();
        if (FAILED(hr)) {
            EbrDebugLog("IAudioClient::Start failed hr=0x%x\n", hr);
        }
    }

    bool playing = false;
    if (renderClient == nullptr) {
        EbrDebugLog("Failed to obtain audio interface");
    }

    BYTE* sampleBacking = 0;

    while (!_terminateThread) {
        HANDLE waitHandles[2];
        int numWaitHandles = 0;

        waitHandles[numWaitHandles++] = _playbackWakeup;

        DWORD timeout = INFINITE;
        if (playing == true) {
            waitHandles[numWaitHandles++] = hBufferReadyEvent;

            // If we are pretending to play sound, don't wait
            if (!renderClient)
                timeout = 50;
        }

        DWORD result = WaitForMultipleObjectsEx(numWaitHandles, waitHandles, FALSE, timeout, TRUE);
        if (_terminateThread)
            break;

        for (;;) {
            _commandsLock.lock();
            if (_commands.size() == 0) {
                _commandsLock.unlock();
                break;
            }
            Command cmd = _commands.back();
            _commands.pop_back();
            _commandsLock.unlock();

            switch (cmd._type) {
                case SourcePlay:
                    playing = true;
                    //((ALSource *) cmd._ptr)->StartPlaying();
                    break;
            }
        }

        BYTE* sampleBuf;
        UINT framesToFill;

        if (renderClient) {
            UINT32 padding, bufSize;
            client->GetBufferSize(&bufSize);
            client->GetCurrentPadding(&padding);

            framesToFill = bufSize - padding;
        } else {
            // Fallback when we don't have an audio device lock
            framesToFill = 2048;
            if (!sampleBacking)
                sampleBacking = (BYTE*)realloc(sampleBacking, framesToFill * outputFmt.nBlockAlign);
            sampleBuf = sampleBacking;
        }

        if (framesToFill > 0) {
            if (renderClient) {
                hr = renderClient->GetBuffer(framesToFill, &sampleBuf);
                if (FAILED(hr)) {
                    EbrDebugLog("GetBuffer failed hr=0x%x\n", hr);
                }
                if (sampleBuf == NULL) {
                    EbrThrowFatal(0, "NULL sampleBuf");
                }
            }

            memset(sampleBuf, 0, framesToFill * outputFmt.nBlockAlign);

            bool didAddSamples = false;
            _contextsLock.lock();
            for (auto curContext : _contexts) {
                bool didAdd = curContext->MixStream((MixBufFrame*)sampleBuf, framesToFill);
                if (didAdd)
                    didAddSamples = true;
            }
            _contextsLock.unlock();

            //  Clip .. could do AGC here?
            DWORD framesLeft = framesToFill;
            MixBufFrame* curFrame = (MixBufFrame*)sampleBuf;
            while (framesLeft--) {
                if (curFrame->left < -1.0f) {
                    curFrame->left = -1.0f;
                } else if (curFrame->left > 1.0f) {
                    curFrame->left = 1.0f;
                }
                if (curFrame->right < -1.0f) {
                    curFrame->right = -1.0f;
                } else if (curFrame->right > 1.0f) {
                    curFrame->right = 1.0f;
                }
                curFrame++;
            }

            if (renderClient)
                renderClient->ReleaseBuffer(framesToFill, 0);

            playing = didAddSamples;
        }
    }

    client->Stop();
    CloseHandle(hBufferReadyEvent);
    SetEvent(_playbackTerminated);
}

void ALCdevice_struct::Destroy() {
    _terminateThread = true;
    SetEvent(_playbackWakeup);
    WaitForSingleObjectEx(_playbackTerminated, INFINITE, TRUE);

    delete this;
}

ALCcontext_struct* ALCdevice_struct::CreateContext() {
    ALCcontext_struct* ret = new ALCcontext_struct(this);

    _contextsLock.lock();
    _contexts.push_back(ret);
    _contextsLock.unlock();

    return ret;
}

void ALCdevice_struct::QueueCommand(CommandType type, void* param) {
    Command newCmd;
    newCmd._type = type;
    newCmd._ptr = param;

    _commandsLock.lock();
    _commands.push_front(newCmd);
    _commandsLock.unlock();

    SetEvent(this->_playbackWakeup);
}

ALC_API ALCdevice* ALC_APIENTRY alcOpenDevice(const ALCchar* devicename) {
    static ALCdevice_struct* ret = NULL;
    if (!ret) {
        ret = new ALCdevice_struct();
    }
    return ret;
}

ALC_API ALCboolean ALC_APIENTRY alcCloseDevice(ALCdevice* device) {
    device->Destroy();

    return true;
}

ALC_API ALCcontext* ALC_APIENTRY alcCreateContext(ALCdevice* device, const ALCint* attrlist) {
    return device->CreateContext();
}

static __declspec(thread) ALCcontext* _threadContext;
static ALCcontext* _globalContext;

#define alCurrentContext (_threadContext ? _threadContext : _globalContext)

ALC_API ALCboolean ALC_APIENTRY alcMakeContextCurrent(ALCcontext* context) {
    _globalContext = context;

    return AL_TRUE;
}

ALC_API ALCboolean ALC_APIENTRY alcSetThreadContext(ALCcontext* context) {
    _threadContext = context;

    return AL_TRUE;
}

ALC_API void ALC_APIENTRY alcProcessContext(ALCcontext* context) {
}

ALC_API void ALC_APIENTRY alcSuspendContext(ALCcontext* context) {
}

ALC_API void ALC_APIENTRY alcDestroyContext(ALCcontext* context) {
    context->Destroy();
}

ALC_API ALCcontext* ALC_APIENTRY alcGetCurrentContext(void) {
    return _globalContext;
}

ALC_API ALCdevice* ALC_APIENTRY alcGetContextsDevice(ALCcontext* context) {
    return context->_parent;
}

AL_API void AL_APIENTRY alGenSources(ALsizei n, ALuint* sources) {
    alCurrentContext->GenSources(n, sources);
}

AL_API void AL_APIENTRY alDeleteSources(ALsizei n, const ALuint* sources) {
    alCurrentContext->DeleteSources(n, sources);
}

AL_API void AL_APIENTRY alGenBuffers(ALsizei n, ALuint* buffers) {
    alCurrentContext->GenBuffers(n, buffers);
}

AL_API void AL_APIENTRY alBufferData(ALuint buffer, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq) {
    alCurrentContext->BufferData(buffer, format, data, size, freq);
}

AL_API void AL_APIENTRY
alBufferDataStatic(ALuint buffer, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq) {
    alCurrentContext->BufferData(buffer, format, data, size, freq);
}

AL_API void AL_APIENTRY alSourcei(ALuint source, ALenum param, ALint value) {
    alCurrentContext->Sourcei(source, param, value);
}

AL_API void AL_APIENTRY alGetSourcei(ALuint source, ALenum param, ALint* value) {
    if (!alCurrentContext) {
        if (value)
            *value = AL_STOPPED;
        return;
    }

    alCurrentContext->GetSourcei(source, param, value);
}

AL_API void AL_APIENTRY alSourcef(ALuint source, ALenum param, ALfloat value) {
    alCurrentContext->Sourcef(source, param, value);
}

AL_API void AL_APIENTRY alSourcePlay(ALuint source) {
    alCurrentContext->SourcePlay(source);
}

ALC_API ALCenum ALC_APIENTRY alcGetError(ALCdevice* device) {
    // assert(0);
    return 0;
}

ALC_API ALCboolean ALC_APIENTRY alcIsExtensionPresent(ALCdevice* device, const ALCchar* extname) {
    // assert(0);
    return AL_FALSE;
}

ALC_API ALCenum ALC_APIENTRY alcGetEnumValue(ALCdevice* device, const ALCchar* enumname) {
    // assert(0);
    return 0;
}

ALC_API const ALCchar* ALC_APIENTRY alcGetString(ALCdevice* device, ALCenum param) {
    // assert(0);
    return NULL;
}

ALC_API void ALC_APIENTRY alcGetIntegerv(ALCdevice* device, ALCenum param, ALCsizei size, ALCint* values) {
    // assert(0);
}

ALC_API void* ALC_APIENTRY alcGetProcAddress(ALCdevice* device, const ALCchar* funcname) {
    if (strcmp(funcname, "alcSetThreadContext") == 0) {
        return &alcSetThreadContext;
    }
    if (strcmp(funcname, "alBufferDataStatic") == 0) {
        return &alBufferDataStatic;
    }
    // assert(0);
    return NULL;
}

AL_API void AL_APIENTRY alEnable(ALenum capability) {
    // assert(0);
}

AL_API void AL_APIENTRY alDisable(ALenum capability) {
    // assert(0);
}

AL_API ALboolean AL_APIENTRY alIsEnabled(ALenum capability) {
    // assert(0);
    return AL_FALSE;
}

AL_API const ALchar* AL_APIENTRY alGetString(ALenum param) {
    // assert(0);
    return NULL;
}

AL_API void AL_APIENTRY alGetBooleanv(ALenum param, ALboolean* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetIntegerv(ALenum param, ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetFloatv(ALenum param, ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetDoublev(ALenum param, ALdouble* values) {
    // assert(0);
}

AL_API ALboolean AL_APIENTRY alGetBoolean(ALenum param) {
    // assert(0);
    return AL_FALSE;
}

AL_API ALint AL_APIENTRY alGetInteger(ALenum param) {
    // assert(0);
    return 0;
}

AL_API ALfloat AL_APIENTRY alGetFloat(ALenum param) {
    // assert(0);
    return 0;
}

AL_API ALdouble AL_APIENTRY alGetDouble(ALenum param) {
    // assert(0);
    return 0;
}

AL_API ALenum AL_APIENTRY alGetError(void) {
    // assert(0);
    return 0;
}

AL_API ALboolean AL_APIENTRY alIsExtensionPresent(const ALchar* extname) {
    // assert(0);
    return AL_FALSE;
}

AL_API ALenum AL_APIENTRY alGetEnumValue(const ALchar* ename) {
    // assert(0);
    return 0;
}

AL_API void AL_APIENTRY alListenerf(ALenum param, ALfloat value) {
    // assert(0);
}

AL_API void AL_APIENTRY alListener3f(ALenum param, ALfloat value1, ALfloat value2, ALfloat value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alListenerfv(ALenum param, const ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alListeneri(ALenum param, ALint value) {
    // assert(0);
}

AL_API void AL_APIENTRY alListener3i(ALenum param, ALint value1, ALint value2, ALint value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alListeneriv(ALenum param, const ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListenerf(ALenum param, ALfloat* value) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListener3f(ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListenerfv(ALenum param, ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListeneri(ALenum param, ALint* value) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListener3i(ALenum param, ALint* value1, ALint* value2, ALint* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetListeneriv(ALenum param, ALint* values) {
    // assert(0);
}

AL_API ALboolean AL_APIENTRY alIsSource(ALuint source) {
    // assert(0);
    return AL_FALSE;
}

AL_API void AL_APIENTRY alSource3f(ALuint source, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourcefv(ALuint source, ALenum param, const ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alSource3i(ALuint source, ALenum param, ALint value1, ALint value2, ALint value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourceiv(ALuint source, ALenum param, const ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetSourcef(ALuint source, ALenum param, ALfloat* value) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetSource3f(ALuint source, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetSourcefv(ALuint source, ALenum param, ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetSource3i(ALuint source, ALenum param, ALint* value1, ALint* value2, ALint* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetSourceiv(ALuint source, ALenum param, ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourcePlayv(ALsizei n, const ALuint* sources) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourceStopv(ALsizei n, const ALuint* sources) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourceRewindv(ALsizei n, const ALuint* sources) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourcePausev(ALsizei n, const ALuint* sources) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourceStop(ALuint source) {
    alCurrentContext->SourceStop(source);
}

AL_API void AL_APIENTRY alSourceRewind(ALuint source) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourcePause(ALuint source) {
    // assert(0);
}

AL_API void AL_APIENTRY alSourceQueueBuffers(ALuint source, ALsizei nb, const ALuint* buffers) {
    alCurrentContext->SourceQueueBuffers(source, nb, buffers);
}

AL_API void AL_APIENTRY alSourceUnqueueBuffers(ALuint source, ALsizei nb, ALuint* buffers) {
    alCurrentContext->SourceUnqueueBuffers(source, nb, buffers);
}

AL_API void AL_APIENTRY alDeleteBuffers(ALsizei n, const ALuint* buffers) {
    alCurrentContext->DeleteBuffers(n, buffers);
}

AL_API ALboolean AL_APIENTRY alIsBuffer(ALuint buffer) {
    // assert(0);
    return AL_FALSE;
}

AL_API void AL_APIENTRY alBufferf(ALuint buffer, ALenum param, ALfloat value) {
    // assert(0);
}

AL_API void AL_APIENTRY alBuffer3f(ALuint buffer, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alBufferfv(ALuint buffer, ALenum param, const ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alBufferi(ALuint buffer, ALenum param, ALint value) {
    // assert(0);
}

AL_API void AL_APIENTRY alBuffer3i(ALuint buffer, ALenum param, ALint value1, ALint value2, ALint value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alBufferiv(ALuint buffer, ALenum param, const ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBufferf(ALuint buffer, ALenum param, ALfloat* value) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBuffer3f(ALuint buffer, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBufferfv(ALuint buffer, ALenum param, ALfloat* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBufferi(ALuint buffer, ALenum param, ALint* value) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBuffer3i(ALuint buffer, ALenum param, ALint* value1, ALint* value2, ALint* value3) {
    // assert(0);
}

AL_API void AL_APIENTRY alGetBufferiv(ALuint buffer, ALenum param, ALint* values) {
    // assert(0);
}

AL_API void AL_APIENTRY alDistanceModel(ALenum distanceModel) {
    // assert(0);
}

AL_API void AL_APIENTRY alDopplerFactor(ALfloat value) {
    // assert(0);
}

AL_API void AL_APIENTRY alDopplerVelocity(ALfloat value) {
    // assert(0);
}

AL_API void AL_APIENTRY alSpeedOfSound(ALfloat value) {
    // assert(0);
}
