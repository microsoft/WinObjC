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

#include <wrl.h>
#include <wrl/client.h>
#include <d3d11_2.h>
#include <d2d1_2.h>
#include <d2d1effects_1.h>
#include <dwrite_2.h>
#include <wincodec.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <concrt.h>
#include <thread>

#include <collection.h>
#include <ppltasks.h>
#include <wrl/client.h>

#define IWEXPORT __declspec(dllexport)
#include "winobjc\winobjc.h"

using namespace concurrency;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::System;
using namespace Windows::System::Threading;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::Graphics::Display;
using namespace Windows::ApplicationModel::Store;
using namespace Windows::UI;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Shapes;
using namespace Windows::ApplicationModel::Core;

void EbrSetWritableFolder(const char* folder);
void IWSetTemporaryFolder(const char* folder);

typedef void* EbrEvent;
struct SocketWait;

int EbrEventTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets);

#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE)
#define WOCGetCurrentFiber() GetCurrentFiber()
#define WOCCreateFiber(stackCommit, stackReserve, start, param) \
    CreateFiberEx(stackCommit, stackReserve, FIBER_FLAG_FLOAT_SWITCH, start, param)
#define WOCConvertThreadToFiber() ConvertThreadToFiberEx(NULL, FIBER_FLAG_FLOAT_SWITCH)
#define WOCSwitchToFiber(fiber) SwitchToFiber(fiber)
typedef VOID* WOCFiber;
typedef LPFIBER_START_ROUTINE WOCFiberStartRoutine;
#else
typedef void(CALLBACK* WOCFiberStartRoutine)(void*);
#ifdef _M_IX86
class WOCFiberContext {
public:
    void* stackPtr;
    void* framePtr;
    void* instructionPtr;
    void* excepPtr;
    void* stackHigh;
    void* stackLow;
    void *savedEsi, *savedEdi;
    void* savedEbx;
    WOCFiberStartRoutine start;
    void* param;
};
#else
class WOCFiberContext {
public:
    void *r4, *r5, *r6, *r7, *r8, *r9, *r10;
    void* framePtr;
    void* stackPtr;
    void* instructionPtr;
    void* stackHigh;
    void* stackLow;
    WOCFiberStartRoutine start;
    void* param;
};
#endif
typedef WOCFiberContext* WOCFiber;

static __declspec(thread) WOCFiber curFiber;

static void WOCFiberEntry() {
    curFiber->start(curFiber->param);
}

WOCFiber WOCGetCurrentFiber() {
    return curFiber;
}

WOCFiber WOCCreateFiber(DWORD dwStackCommitSize, DWORD dwStackReserveSize, WOCFiberStartRoutine lpStartAddress, void* lpParameter) {
    struct SEH_ENTRY {
        SEH_ENTRY* next;
        void* handler;
    };

    WOCFiber ret = new WOCFiberContext();
    char* stackStart = (char*)_aligned_malloc(dwStackReserveSize, 65536);

    ret->instructionPtr = (void*)WOCFiberEntry;
    ret->stackPtr = (void*)(stackStart + dwStackReserveSize - 32);
    ret->stackHigh = (void*)(stackStart + dwStackReserveSize);
    ret->stackLow = (void*)stackStart;

#ifdef _M_IX86
    //  Find the top-level SEH entry of our current thread
    //  RtlRaiseException does a security check and has a hard
    //  requirement that the top-level SEH handler is the one setup
    //  by CreateThread
    SEH_ENTRY* topHandler = (SEH_ENTRY*)((void**)NtCurrentTeb())[0];
    while ((void*)topHandler->next != (void*)0xFFFFFFFF) {
        topHandler = topHandler->next;
    }

    ret->stackPtr = (void*)(((char*)ret->stackPtr) - sizeof(SEH_ENTRY));
    ret->framePtr = ret->framePtr;

    //  Push the new top-level handler onto our fiber stack
    SEH_ENTRY* newTopHandler = (SEH_ENTRY*)ret->stackPtr;
    *newTopHandler = *topHandler;
    ret->excepPtr = (void*)newTopHandler;
#else
    ret->framePtr = ret->stackPtr;
#endif

    ret->start = lpStartAddress;
    ret->param = lpParameter;
    return ret;
}

WOCFiber WOCConvertThreadToFiber() {
    WOCFiber ret = new WOCFiberContext();
    curFiber = ret;
    return ret;
}

#ifdef _M_IX86
static __declspec(naked) int WOCSetJmp(WOCFiber dest) {
    __asm {
        mov ecx, [esp + 4]
        mov [ecx], esp
        add [ecx], 4 //  Pop off return address from stack in context to be restored
        mov [ecx + 4], ebp
        mov eax, [esp]
        mov [ecx + 8], eax
        mov eax, fs:[0]
        mov [ecx + 12], eax
        mov eax, fs:[4]
        mov [ecx + 16], eax
        mov eax, fs:[8]
        mov [ecx + 20], eax
        mov [ecx + 24], esi
        mov [ecx + 28], edi
        mov [ecx + 32], ebx
        mov eax, 0
        ret
    }
}

static __declspec(naked) int WOCLongJmp(WOCFiber dest) {
    __asm {
        mov ecx, [esp + 4]
        mov esp, [ecx]
        mov ebp, [ecx + 4]
        mov eax, [ecx + 12]
        mov fs:[0], eax
        mov eax, [ecx + 16]
        mov fs:[4], eax
        mov eax, [ecx + 20]
        mov fs:[8], eax
        mov esi, [ecx + 24]
        mov edi, [ecx + 28]
        mov ebx, [ecx + 32]
        mov eax, 1
        mov ecx, [ecx + 8]
        jmp ecx
    }
}
#else
extern "C" int WOCSetJmp(WOCFiber dest);
extern "C" int WOCLongJmp(WOCFiber dest);
#endif

void WOCSwitchToFiber(WOCFiber fiber) {
    WOCFiber origFiber = curFiber;
    if (WOCSetJmp(origFiber) == 0) {
        curFiber = fiber;
        WOCLongJmp(curFiber);
    } else {
        curFiber = origFiber;
    }
    return;
}
#endif

WOCFiber g_XamlUIFiber = NULL;
WOCFiber g_WinObjcUIFiber;

int XamlTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets) {
    //  If our current fiber is the main winobjc UI thread,
    //  we perform the wait on a separate worker thread, then
    //  yield to the Xaml Dispatcher fiber.  Once the worker thread wakes
    //  up, it will queue the result on the Xaml dispatcher, then
    //  have it switch back to the winobjc fiber with the result
    if (WOCGetCurrentFiber() == g_WinObjcUIFiber) {
        int retval = 0;
        bool retValValid = false;
        auto dispatcher = CoreWindow::GetForCurrentThread()->Dispatcher;
        Windows::System::Threading::ThreadPool::RunAsync(
            ref new WorkItemHandler([&retval, &retValValid, events, numEvents, timeout, sockets, dispatcher](IAsyncAction ^ action) {
                //  Wait for an event
                retval = EbrEventTimedMultipleWait(events, numEvents, timeout, sockets);
                retValValid = true;

                //  Dispatch it on the UI thread
                dispatcher->RunAsync(CoreDispatcherPriority::High, ref new DispatchedHandler([]() { WOCSwitchToFiber(g_WinObjcUIFiber); }));
            }));
        //  ** WARNING ** The "local" retval is passed by ref to the lamba - never wake up this
        //  fiber from somewhere else!
        WOCSwitchToFiber(g_XamlUIFiber);

        assert(retValValid == true);
        return retval;
    } else {
        return EbrEventTimedMultipleWait(events, numEvents, timeout, sockets);
    }
}

__declspec(dllexport) unsigned int XamlWaitHandle(uintptr_t hEvent, unsigned int timeout) {
    int retval = 0;
    bool retValValid = false;
    auto dispatcher = CoreWindow::GetForCurrentThread()->Dispatcher;
    Windows::System::Threading::ThreadPool::RunAsync(
        ref new WorkItemHandler([&retval, &retValValid, hEvent, timeout, dispatcher](IAsyncAction ^ action) {
            //  Wait for an event
            retval = WaitForSingleObjectEx((HANDLE)hEvent, timeout, TRUE);
            retValValid = true;

            //  Dispatch it on the UI thread
            dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([]() { WOCSwitchToFiber(g_WinObjcUIFiber); }));
        }));
    //  ** WARNING ** The "local" retval is passed by ref to the lamba - never wake up this
    //  fiber from somewhere else!
    WOCSwitchToFiber(g_XamlUIFiber);

    assert(retValValid == true);
    return retval;
}

int UIApplicationMainStart(int argc, char* argv[], const char* pName, const char* dName, float windowWidth, float windowHeight);

struct {
    int argc;
    char** argv;
    const char* pName;
    const char* dName;
    float windowWidth, windowHeight;
} _startparams = { 0, NULL, NULL, NULL, 0.0f, 0.0f };

static VOID CALLBACK WinObjcMainLoop(LPVOID param) {
    HANDLE hHandle = CreateEventEx(NULL, NULL, 0, EVENT_ALL_ACCESS);
    UIApplicationMainStart(_startparams.argc,
                           _startparams.argv,
                           _startparams.pName,
                           _startparams.dName,
                           _startparams.windowWidth,
                           _startparams.windowHeight);
}

void SetXamlUIWaiter();

extern "C" void* _WideStringFromNSString(void* str);

__declspec(dllexport) wchar_t* __WideStringFromNSString(void* str) {
    return (wchar_t*)_WideStringFromNSString(str);
}

static void IWStartUIRunLoop() {
    WOCConvertThreadToFiber();
    g_XamlUIFiber = WOCGetCurrentFiber();
    g_WinObjcUIFiber = WOCCreateFiber(16384, 1024 * 1024, WinObjcMainLoop, NULL);
    WOCSwitchToFiber(g_WinObjcUIFiber);
}

static const char* __const_char_From_String(Platform::String ^ str) {
    if (str == nullptr)
        return NULL;

    std::wstring wstr(str->Data());
    std::string sstr(wstr.begin(), wstr.end());

    return _strdup(sstr.data());
}

__declspec(dllexport) void IWAppInit() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;

    char writableFolder[2048];
    size_t outLen;
    auto pathData = Windows::Storage::ApplicationData::Current->LocalFolder->Path->Data();
    wcstombs_s(&outLen, writableFolder, pathData, sizeof(writableFolder));
    EbrSetWritableFolder(writableFolder);

    auto tempPathData = Windows::Storage::ApplicationData::Current->TemporaryFolder->Path->Data();
    wcstombs_s(&outLen, writableFolder, tempPathData, sizeof(writableFolder));
    IWSetTemporaryFolder(writableFolder);

    SetXamlUIWaiter();
}

__declspec(dllexport) void IWRunApplicationMain(Platform::String ^ principalClassName,
                                                Platform::String ^ delegateClassName,
                                                float windowWidth,
                                                float windowHeight) {
    IWAppInit();

    _startparams.argc = 0;
    _startparams.argv = NULL;
    _startparams.pName = __const_char_From_String(principalClassName);
    _startparams.dName = __const_char_From_String(delegateClassName);
    _startparams.windowWidth = windowWidth;
    _startparams.windowHeight = windowHeight;
    IWStartUIRunLoop();
}
