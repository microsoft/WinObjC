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
#import <Starboard.h>
#import <Foundation/NSRunLoop.h>
#import <NSRunLoop+Internal.h>
#import <NSLogging.h>
#include <COMIncludes.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <WRLHelpers.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.ui.core.h>
#import <windows.system.threading.h>
#include <COMIncludes_End.h>
#import <LoggingNative.h>
#import <MainDispatcher.h>

#import <atomic>

using namespace Microsoft::WRL;
using namespace ABI::Windows::ApplicationModel::Core;
using namespace ABI::Windows::System::Threading;
using namespace ABI::Windows::UI::Core;
using namespace ABI::Windows::Foundation;

static const wchar_t* TAG = L"MainDispatcher";
static ComPtr<ICoreDispatcher> s_dispatcher;

/**
 * Method that schedules the main runloop.
 * Note: This method should only be called from the main UI thread.
 */
extern "C" void ScheduleMainRunLoop() {
    if ([NSThread currentThread] == [NSThread mainThread]) {
        NSRunLoop* runLoop = [NSRunLoop currentRunLoop];
        [runLoop _run];
    } else {
        // Main runloop should only be scheduled from the main UI thread.
        FAIL_FAST_MSG(E_UNEXPECTED, "Main runloop should only be scheduled from the main UI thread!");
    }
}

/**
 * Method that processes events for the main runloop.
 * Note: This method should only be called from the main UI thread.
 */
void _ProcessMainRunLoop(int signaled) {
    if ([NSThread currentThread] == [NSThread mainThread]) {
        NSRunLoop* runLoop = [NSRunLoop currentRunLoop];
        [runLoop _processMainRunLoop:signaled];
    } else {
        // Main runloop should only be scheduled from the main UI thread.
        FAIL_FAST_MSG(E_UNEXPECTED, "Main runloop should only be scheduled from the main UI thread!");
    }
}

/**
 * Method that schedules the main runloop on the UI thread.
 * Note: This method always schedules the work asynchronously on the UI thread to let the caller stack unwind.
 */
void _DispatchMainRunLoopOnUIThread(int signaledEvent) {
    auto dispatchCallback = WRLHelpers::MakeAgileCallback<IDispatchedHandler>([signaledEvent]() -> HRESULT {
        _ProcessMainRunLoop(signaledEvent);
        ScheduleMainRunLoop();
        return S_OK;
    });
    ComPtr<IAsyncAction> asyncAction;
    s_dispatcher->RunAsync(CoreDispatcherPriority_Normal, dispatchCallback.Get(), &asyncAction);
}

/**
 * Method that blocks on multiple events on the main runloop.
 * Because this method gets called on the main UI thread, the wait for events happens on a thread pool thread and once the wait completes
 * we schedule the main runoop to process the event back on the main UI thread.
 * Note: This method should only be called from the main UI thread.
 */
int MainRunLoopTimedMultipleWait(EbrEvent* events, int numEvents, double timeout, SocketWait* sockets) {
    if ([NSThread currentThread] == [NSThread mainThread]) {
        static std::atomic<bool> waitHasBeenScheduled(false);

        if (waitHasBeenScheduled.load()) {
            // It is safe to return here as a threadpool based wait has already been scheduled for the main runloop.
            static dispatch_once_t onceToken;
            dispatch_once(&onceToken,
                          ^{
                              // Do not log this trace warning in every loop as it creates a lot of noise.
                              TraceWarning(TAG, L"Main RunLoop is being scheduled by the application as-well!");
                          });
            return 0;
        }

        if (s_dispatcher == nullptr) {
            ComPtr<ICoreWindowStatic> coreWindowStatic;
            ComPtr<ICoreWindow> coreWindow;

            THROW_IF_FAILED(
                GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_UI_Core_CoreWindow).Get(), &coreWindowStatic));
            THROW_IF_FAILED(coreWindowStatic->GetForCurrentThread(&coreWindow));
            THROW_IF_FAILED(coreWindow->get_Dispatcher(&s_dispatcher));
        }

        if (timeout == 0) {
            // Optimization to not schedule a wait on a threadpool when the timeout value passed was 0.
            _DispatchMainRunLoopOnUIThread(-1);
        } else {
            // note-nithishm-04082016 - This code path can be optimized by having a dedicated thread to perform the main runloop wait
            // instead
            // of scheduling it on a threadpool every time. Keeping the code simple for now as this is not a regression from what we had
            // with
            // fibers. Bug 7183829 tracks this.
            ComPtr<IThreadPoolStatics> threadpool;
            THROW_IF_FAILED(
                GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_System_Threading_ThreadPool).Get(), &threadpool));
            auto agileCallback =
                WRLHelpers::MakeAgileCallback<IWorkItemHandler>([events, numEvents, timeout, sockets](_In_ IAsyncAction*) -> HRESULT {
                    int signaledEvent = EbrEventTimedMultipleWait(events, numEvents, timeout, sockets);
                    waitHasBeenScheduled.store(false);

                    //  Dispatch the main runloop on the UI thread.
                    _DispatchMainRunLoopOnUIThread(signaledEvent);

                    return S_OK;
                });

            ComPtr<IAsyncAction> asyncTask;
            waitHasBeenScheduled.store(true);
            THROW_IF_FAILED(threadpool->RunWithPriorityAsync(agileCallback.Get(), WorkItemPriority_High, &asyncTask));
        }
    } else {
        // Main runloop should only be scheduled from the main UI thread.
        FAIL_FAST_MSG(E_UNEXPECTED, "Main runloop should only be scheduled from the main UI thread!");
    }

    return 0;
}

/**
 * Method to setup the main runloop wait function for the main UI thread.
 */
extern "C" void SetupMainRunLoopTimedMultipleWaiter() {
    [NSRunLoop setUIThreadMainRunLoopWaitFunction:&MainRunLoopTimedMultipleWait];
}
