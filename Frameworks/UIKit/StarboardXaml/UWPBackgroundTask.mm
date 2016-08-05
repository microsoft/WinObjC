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

/**
 * Helper class to request/unregister background task on behalf of an UWP application.
 *
 * UWP background tasks are implemented using ApplicationTrigger task. When Application request for a background task, an
 * ApplicationTrigger will be held to prevent the application from being suspended.
 * UWP application only support one active ApplicationTrigger task active at any given point in time, this class takes care of reference
 * counting and handling multiple request/unregister requests.
 */

#import <Starboard.h>
#import <Foundation/Foundation.h>
#import <UIKit\UIKitExport.h>
#include <COMIncludes.h>
#import <wrl/client.h>
#import <WRLHelpers.h>
#import <wrl/wrappers/corewrappers.h>
#import <Windows.Foundation.Collections.h>
#import <windows.applicationModel.background.h>
#include <COMIncludes_end.h>
#import <dispatch/dispatch.h>
#import "StarboardXaml.h"
#import "UWPBackgroundTask.h"

#pragma region Types and Namespaces
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::ApplicationModel::Background;

#define MakeApplicationTriggerRequestCompletedCallback                                                                         \
    ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::ClassicCom>, \
                                                            IAsyncOperationCompletedHandler<ApplicationTriggerResult>>>

#pragma endregion

static const wchar_t* TAG = L"UWPBackgroundTask";
// Hard coded timeout value for ApplicationTrigger task in RS1. Today there is no way to query this value.
static const double s_backgroundTaskTimeout = 10 * 60; // 10 minutes

@interface UWPBackgroundTask () {
    BOOL _isRunningInBackground;
    BOOL _blockBackgroundTaskRequests;
    int _count;
    NSMutableDictionary* _map;
    NSDate* _expirationDate;
    NSTimer* _countdownTimer;
}

- (ComPtr<IBackgroundTaskRegistration>)_backgroundTaskAlreadyRegistered;
- (void)_registerBackgroundTask;
- (void)_unregisterBackgroundTask;
@end

@implementation UWPBackgroundTask

#pragma region Internal Methods
/**
 * Helper method to check if an background task is already registered.
 *
 * @return {ComPtr<IBackgroundTaskRegistration>} IBackgroundTaskRegistration instance of the registered background task.
 */
- (ComPtr<IBackgroundTaskRegistration>)_backgroundTaskAlreadyRegistered {
    // Get an IBackgroundTaskRegistrationStatics interface pointer.
    ComPtr<IBackgroundTaskRegistrationStatics> backgroundTaskRegistrationStatics;
    FAIL_FAST_IF_FAILED(Windows::Foundation::GetActivationFactory(
        Wrappers::HStringReference(RuntimeClass_Windows_ApplicationModel_Background_BackgroundTaskRegistration).Get(),
        &backgroundTaskRegistrationStatics));

    // Get the collection of registered background tasks.
    ComPtr<IMapView<GUID, IBackgroundTaskRegistration*>> allTasks;
    FAIL_FAST_IF_FAILED(backgroundTaskRegistrationStatics->get_AllTasks(&allTasks));

    // Get the tasks as an IIterable.
    ComPtr<IIterable<IKeyValuePair<GUID, IBackgroundTaskRegistration*>*>> allTasksIterable;
    FAIL_FAST_IF_FAILED(allTasks.As(&allTasksIterable));

    // Get an iterator over the tasks.
    ComPtr<IIterator<IKeyValuePair<GUID, IBackgroundTaskRegistration*>*>> iterator;
    FAIL_FAST_IF_FAILED(allTasksIterable->First(&iterator));

    // Check if the iterator references a valid key-value pair in the collection.
    boolean hasCurrent;
    FAIL_FAST_IF_FAILED(iterator->get_HasCurrent(&hasCurrent));

    // Iterate over all registered background tasks.
    while (hasCurrent) {
        // Get the current key-value pair from the iterator.
        ComPtr<IKeyValuePair<GUID, IBackgroundTaskRegistration*>> currentKeyValuePair;
        FAIL_FAST_IF_FAILED(iterator->get_Current(&currentKeyValuePair));

        // Get the IBackgroundTaskRegistration instance from the key-value pair.
        ComPtr<IBackgroundTaskRegistration> currentTask;
        FAIL_FAST_IF_FAILED(currentKeyValuePair->get_Value(&currentTask));

        // Get the task name from the IBackgroundTaskRegistration instance.
        Wrappers::HString currentTaskName;
        FAIL_FAST_IF_FAILED(currentTask->get_Name(currentTaskName.GetAddressOf()));

        // Check if the current task's name is BackgroundApplicationTriggerTaskName. If so,
        // the task is already registred.
        if (currentTaskName == Wrappers::HStringReference(c_backgroundTaskName)) {
            return currentTask;
        }

        // Advance the iterator to the next key-value pair in the collection.
        FAIL_FAST_IF_FAILED(iterator->MoveNext(&hasCurrent));
    }

    return nullptr;
}

/**
 * Helper method that gets called when the background task is about to expire.
 *
 * @param {NSTimer*} timer Not used.
 */
- (void)_performExpirationHandlerCallback:(NSTimer*)timer {
    // Make sure this callback happens on the main UI thread.
    if ([NSThread currentThread] != [NSThread mainThread]) {
        FAIL_FAST_MSG("_performExpirationHandlerCallback should be only scheduled on the main UI thread!");
    }

    NSMutableDictionary* mapCopy;
    @synchronized(self) {
        TraceVerbose(TAG, L"Background task is about to expire!");
        _blockBackgroundTaskRequests = YES;
        mapCopy = [_map copy];
    }

    // Note: we do not call _unregisterBackgroundTask here as calling the handler block that the application registered should
    // invoke endBackgroundTask: which in-turn should call unregisterBackgroundTask: and _unregisterBackgroundTask.
    // If for some reason the application does not call endBackgroundTask:, Windows will invoke the background task completion
    // handler with appropriate status which we will log and use to unregister the task (refer to StarboardXaml.cpp)

    // Invoke handler blocks for all registered tasks from the application.
    for (NSNumber* key in mapCopy) {
        id handler = [mapCopy objectForKey:key];
        if (handler != nil) {
            TraceVerbose(TAG, L"Invoking handler block for background taskId %ld.", [key integerValue]);
            void (^handlerBlock)(void) = (void (^)(void))handler;
            handlerBlock();
        }
    }
}

/**
 * Helper method that actually performs the background task (ApplicationTrigger) registration with the system.
 */
- (void)_registerBackgroundTask {
    // Get an IBackgroundTaskBuilder interface pointer.
    ComPtr<IBackgroundTaskBuilder> backgroundTaskBuilder;
    FAIL_FAST_IF_FAILED(Windows::Foundation::ActivateInstance(
        Wrappers::HStringReference(RuntimeClass_Windows_ApplicationModel_Background_BackgroundTaskBuilder).Get(), &backgroundTaskBuilder));

    // Get an IApplicationTrigger interface pointer.
    ComPtr<IApplicationTrigger> applicationTrigger;
    FAIL_FAST_IF_FAILED(Windows::Foundation::ActivateInstance(
        Wrappers::HStringReference(RuntimeClass_Windows_ApplicationModel_Background_ApplicationTrigger).Get(), &applicationTrigger));

    // Set properties on the BackgroundTaskBuilder.
    ComPtr<IBackgroundTrigger> backgroundTrigger;
    FAIL_FAST_IF_FAILED(applicationTrigger.As(&backgroundTrigger));
    Wrappers::HStringReference taskName(c_backgroundTaskName);
    FAIL_FAST_IF_FAILED(backgroundTaskBuilder->put_Name(taskName.Get()));
    FAIL_FAST_IF_FAILED(backgroundTaskBuilder->SetTrigger(backgroundTrigger.Get()));

    // Register the background task.
    ComPtr<IBackgroundTaskRegistration> taskRegistration;
    FAIL_FAST_IF_FAILED(backgroundTaskBuilder->Register(&taskRegistration));

    // Request ApplicationTrigger.
    IAsyncOperation<ApplicationTriggerResult>* triggerResult;
    FAIL_FAST_IF_FAILED(applicationTrigger->RequestAsync(&triggerResult));

    StrongId<UWPBackgroundTask> strongSelf(self);
    auto triggerResultCallback =
        MakeApplicationTriggerRequestCompletedCallback([strongSelf](IAsyncOperation<ApplicationTriggerResult> * triggerResult,
                                                                    AsyncStatus status) noexcept -> HRESULT {
            if (status == AsyncStatus::Completed) {
                TraceVerbose(TAG, L"Background task request completed successfully.");
                ApplicationTriggerResult result;
                FAIL_FAST_IF_FAILED(triggerResult->GetResults(&result));
                if (result == ApplicationTriggerResult::ApplicationTriggerResult_Allowed) {
                    TraceVerbose(TAG, L"Background task started successfully.");
                    // Keep track of the time when the ApplicationTrigger task will expire.
                    strongSelf->_expirationDate = [NSDate dateWithTimeIntervalSinceNow:s_backgroundTaskTimeout];

                    // Start a count down timer so we can call the application handlers before the background task expires.
                    // Note: we configure the timer to fire 1 minute before the background task times out so we have enough
                    // time to call all the registerted handler blocks.
                    strongSelf->_countdownTimer = [NSTimer scheduledTimerWithTimeInterval:(s_backgroundTaskTimeout - 60)
                                                                                   target:strongSelf
                                                                                 selector:@selector(_performExpirationHandlerCallback:)
                                                                                 userInfo:nil
                                                                                  repeats:NO];
                } else {
                    TraceError(TAG, L"Background task failed with result %d!", result);
                    FAIL_FAST();
                }
            } else {
                TraceError(TAG, L"Background task request failed with status %d!", status);
                FAIL_FAST();
            }

            return S_OK;
        });

    FAIL_FAST_IF_FAILED(triggerResult->put_Completed(triggerResultCallback.Get()));
}

/**
 * Helper method that actually performs the background task (ApplicationTrigger) un-registration with the system.
 */
- (void)_unregisterBackgroundTask {
    ComPtr<IBackgroundTaskRegistration> task = [self _backgroundTaskAlreadyRegistered];
    if (task != nullptr) {
        FAIL_FAST_IF_FAILED(task->Unregister(true));
        [_countdownTimer invalidate];
        _countdownTimer = nil;
        _expirationDate = nil;
        TraceVerbose(TAG, L"Background task successfully unregistered.");
    }
}
#pragma endregion

/**
 * Hidden method for UWPBackgroundTask class instance initialization.
 *
 * @return {instancetype} UWPBackgroundTask instance.
 */
- (instancetype)init {
    if (self = [super init]) {
        _count = 0;
        _map = [[NSMutableDictionary alloc] init];
        _blockBackgroundTaskRequests = NO;
        _expirationDate = nil;
        _countdownTimer = nil;
    }

    return self;
}

/**
 * Class instance method to return a singleton instance of UWPBackgroundTask.
 *
 * @return {instancetype} UWPBackgroundTask instance.
 */
+ (instancetype)sharedInstance {
    static UWPBackgroundTask* sharedBackgroundTask = [[self alloc] init];
    return sharedBackgroundTask;
}

/**
 * Returns the the amount of time the app has to run in the background before it may be forcibly killed by the system.
 *
 * @return {double} The time remaining in seconds.
 *                  While the app is running in the foreground, the value in this property remains suitably large.
 *                  If the app starts one or more long-running tasks using the beginBackgroundTaskWithExpirationHandler: method and
 *                  then transitions to the background, the value reflects the amount of time the app has left to run.
 */
- (double)timeRemaining {
    @synchronized(self) {
        if (_expirationDate != nil) {
            return [_expirationDate timeIntervalSinceDate:[NSDate date]];
        }
    }

    return [[NSDate distantPast] timeIntervalSinceDate:[NSDate date]];
}

/**
 * Called when the application is about to enter background.
 */
- (void)isEnteringBackground {
    @synchronized(self) {
        _isRunningInBackground = YES;
        // Register for background task if there are pending requests.
        if ([_map count] != 0) {
            [self _registerBackgroundTask];
        }
    }
}

/**
 * Called when the application is about to enter foreground.
 */
- (void)isEnteringForeground {
    @synchronized(self) {
        _isRunningInBackground = NO;
        _blockBackgroundTaskRequests = NO;
        // Unregister the background task as the application is exiting background.
        if ([_map count] != 0) {
            [self _unregisterBackgroundTask];
        }
    }
}

/**
 * Method to request background task on behalf of the application. Apps can request for multiple background tasks but
 * only one task will be registered (as UWP only supports one ApplicationTrigger task per application which backs the background task).
 * This method will take care of proper reference counting of each request.
 *
 * @param {void (^handler)(void)} Handler block to call back on when the background task expires.
 * @return {NSUInteger} background task id.
 */
- (NSUInteger)requestBackgroundTask:(void (^)(void))handler {
    @synchronized(self) {
        // Do not allow any further requests from the application after the background task timer has expired.
        if (_blockBackgroundTaskRequests) {
            TraceError(TAG, L"New background task requested after the time expiration!");
            return UIBackgroundTaskInvalid;
        }

        ++_count;
        TraceVerbose(TAG, L"Background task requested - %ld [current task count = %ld].", _count, [_map count]);
        [_map setObject:handler forKey:[NSNumber numberWithInt:_count]];

        // Verify if the task is already registered.
        ComPtr<IBackgroundTaskRegistration> task = [self _backgroundTaskAlreadyRegistered];
        if (task != nullptr) {
            // Check if the task was left un-registered from the previous run. If so, unregister the old task and continue.
            if ([_map count] == 1) {
                TraceWarning(TAG, L"Cleaning-up and un-registering background task from the previous run of the application!");
                FAIL_FAST_IF_FAILED(task->Unregister(true));
            } else {
                TraceVerbose(TAG, L"Requested background task when one is already in progress [new task count = %ld]", _count);
                return _count;
            }
        }

        // Register background task only when the application is in the background else the registeration will be deffered until the
        // application is about to enter background.
        if (_isRunningInBackground) {
            [self _registerBackgroundTask];
        }

        return _count;
    }
}

/**
 * Method to request background task un-registration. This method will take care of proper reference counting of each request and will
 * take care of un-registering background task with the system only after all of them have un-registered.
 *
 * @param {NSUInteger} triggerId background task to un-register.
 */
- (void)unregisterBackgroundTask:(NSUInteger)triggerId {
    @synchronized(self) {
        TraceVerbose(TAG, L"Background task unregister requested for taskId %ld [current count = %ld].", triggerId, [_map count]);
        if ([_map count] == 0) {
            TraceWarning(TAG, L"Background task unregister requested when there is no task in progress!");
            return;
        }

        if ([_map objectForKey:[NSNumber numberWithInt:triggerId]] == nil) {
            TraceError(TAG, L"Background task unregister requested for invalid taskId %ld!", triggerId);
            return;
        }

        [_map removeObjectForKey:[NSNumber numberWithInt:triggerId]];

        if ([_map count] == 0) {
            // The last requested Background task is un-registering, unregister background task (ApplicationTrigger) from the system.
            [self _unregisterBackgroundTask];
        } else {
            TraceVerbose(TAG, L"Currently %ld Background tasks are in progress.", [_map count]);
        }
    }
}

@end