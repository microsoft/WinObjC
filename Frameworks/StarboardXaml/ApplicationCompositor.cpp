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
// clang-format does not play well with C++/CX
// clang-format off

#include "ApplicationMain.h"
#include "StringHelpers.h"
#include "ApplicationCompositor.h"

#include <assert.h>
#include <string>

using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::System::Threading;

void IWSetTemporaryFolder(const char* folder);
void ApplicationMainHandleWindowVisibilityChangeEvent(bool visible);
void ApplicationMainHandleHighMemoryUsageEvent();

void* g_XamlUIFiber = nullptr;
void* g_WinObjcUIFiber = nullptr;

int XamlTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets) {
    //  If our current fiber is the main winobjc UI thread,
    //  we perform the wait on a separate worker thread, then
    //  yield to the Xaml Dispatcher fiber.  Once the worker thread wakes
    //  up, it will queue the result on the Xaml dispatcher, then
    //  have it switch back to the winobjc fiber with the result
    if (::GetCurrentFiber() == g_WinObjcUIFiber) {
        int retval = 0;
        bool signaled = false;
        auto dispatcher = CoreWindow::GetForCurrentThread()->Dispatcher;
        ThreadPool::RunAsync(
            ref new WorkItemHandler([&retval, &signaled, events, numEvents, timeout, sockets, dispatcher](IAsyncAction^ action) {
                //  Wait for an event
                retval = EbrEventTimedMultipleWait(events, numEvents, timeout, sockets);
                signaled = true;

                //  Dispatch it on the UI thread
                dispatcher->RunAsync(CoreDispatcherPriority::High, ref new DispatchedHandler([]() { ::SwitchToFiber(g_WinObjcUIFiber); }));
            }));

        //  ** WARNING ** The "local" retval is passed by ref to the lamba - never wake up this
        //  fiber from somewhere else!
        ::SwitchToFiber(g_XamlUIFiber);

        assert(signaled);
        return retval;
    } else {
        return EbrEventTimedMultipleWait(events, numEvents, timeout, sockets);
    }
}

extern "C" unsigned int XamlWaitHandle(uintptr_t hEvent, unsigned int timeout) {
    int retval = 0;
    bool signaled = false;
    auto dispatcher = CoreWindow::GetForCurrentThread()->Dispatcher;
    ThreadPool::RunAsync(ref new WorkItemHandler([&retval, &signaled, hEvent, timeout, dispatcher](IAsyncAction^ action) {
        //  Wait for an event
        retval = WaitForSingleObjectEx((HANDLE)hEvent, timeout, TRUE);
        signaled = true;

        //  Dispatch it on the UI thread
        dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref new DispatchedHandler([]() { ::SwitchToFiber(g_WinObjcUIFiber); }));
    }));

    //  ** WARNING ** The "local" retval is passed by ref to the lamba - never wake up this
    //  fiber from somewhere else!
    ::SwitchToFiber(g_XamlUIFiber);

    assert(signaled);
    return retval;
}

struct StartParameters {
    int argc;
    char** argv;
    std::string principalClassName;
    std::string delegateClassName;
    float windowWidth, windowHeight;
};

StartParameters g_startParams = { 0, nullptr, std::string(), std::string(), 0.0f, 0.0f };

static VOID CALLBACK WinObjcMainLoop(LPVOID param) {
    ApplicationMainStart(g_startParams.argc,
                         g_startParams.argv,
                         g_startParams.principalClassName.c_str(),
                         g_startParams.delegateClassName.c_str(),
                         g_startParams.windowWidth,
                         g_startParams.windowHeight);
}

void SetXamlUIWaiter();

static void StartCompositedRunLoop() {
    // Switch this xaml/winrt thread to a fiber, and store it
    ::ConvertThreadToFiberEx(nullptr, FIBER_FLAG_FLOAT_SWITCH);
    g_XamlUIFiber = ::GetCurrentFiber();

    // Create our WinObjC fiber
    const size_t stackCommitSize = 4096 * 4; // 4 pages
    const size_t stackReserveSize = 1024 * 1024; // 1MB
    g_WinObjcUIFiber = ::CreateFiberEx(stackCommitSize, stackReserveSize, FIBER_FLAG_FLOAT_SWITCH, WinObjcMainLoop, nullptr);

    // Switch to the WinObjC fiber to kick off the IOS launch sequence
    ::SwitchToFiber(g_WinObjcUIFiber);
}

void InitializeApp() {
    // Only init once.
    // No lock needed as this is only called from the UI thread.
    static bool initialized = false;
    if (initialized) {
        return;
    }
    initialized = true;

    // Set our writable and temp folders
    char writableFolder[2048];
    size_t outLen;
    auto pathData = Windows::Storage::ApplicationData::Current->LocalFolder->Path;
    wcstombs_s(&outLen, writableFolder, pathData->Data(), sizeof(writableFolder) - 1);
    EbrSetWritableFolder(writableFolder);

    auto tempPathData = Windows::Storage::ApplicationData::Current->TemporaryFolder->Path;
    wcstombs_s(&outLen, writableFolder, tempPathData->Data(), sizeof(writableFolder) - 1);
    IWSetTemporaryFolder(writableFolder);

    // Set the waiter routine for yielding waits to the XAML/UI thread
    SetXamlUIWaiter();
}

extern "C" void RunApplicationMain(Platform::String^ principalClassName,
                                     Platform::String^ delegateClassName,
                                     float windowWidth,
                                     float windowHeight) {
    // Perform initialization
    InitializeApp();

    // Store the start parameters to hand off to the run loop
    g_startParams.argc = 0;
    g_startParams.argv = nullptr;
    g_startParams.principalClassName = Strings::WideToNarrow(principalClassName->Data());
    g_startParams.delegateClassName = Strings::WideToNarrow(delegateClassName->Data());
    g_startParams.windowWidth = windowWidth;
    g_startParams.windowHeight = windowHeight;

    // Kick off the run loop
    StartCompositedRunLoop();
}

// clang-format off
