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

#import "UrlLauncher.h"
#import "NSLogging.h"

static const wchar_t* TAG = L"UrlLauncher";

@interface UrlLauncher () {
    Class _launcher;
    NSCondition* _launchCondition;
    BOOL _launchCompleted;
    BOOL _launchDidSucceed;
    NSCondition* _canOpenCondition;
    BOOL _canOpenCompleted;
    BOOL _canOpenDidSucceed;
}
@end

@implementation UrlLauncher
- (UrlLauncher*)initWithLauncher:(Class)launcher {
    if (self = [super init]) {
        _launcher = launcher;
        _launchCondition = [NSCondition new];
        _canOpenCondition = [NSCondition new];
    }

    return self;
}

/**
 * Opens the given URL asynchronously, if it can be opened.
 * Note: This method only returns the status for if the URL can be opened and not actual open URL call status.
 *
 * @param {NSURL*} url URL to open
 * @return {BOOL} true if the URL can be opened, false otherwise
 */
- (BOOL)_openURLAsync:(NSURL*)url {
    if ([self _canOpenURL:url]) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0),
                       ^{
                           [self _openURL:url];
                       });
        return YES;
    }

    return NO;
}

/**
 * Opens the given URL synchronously.
 * Note: This method can block, so it not recommended to call from the main thread
 *
 * @param {NSURL*} url URL to open
 * @return {BOOL} true if the URL was opened successfully, false otherwise
 */
- (BOOL)_openURL:(NSURL*)url {
    @synchronized(self) {
        NSThread* thread = [[NSThread alloc] initWithTarget:self selector:@selector(_openURLHelper:) object:url];
        [_launchCondition lock];
        _launchCompleted = NO;
        [thread start];

        while (_launchCompleted == NO) {
            [_launchCondition wait];
        }

        [_launchCondition unlock];
        [thread release];
        return _launchDidSucceed;
    }
}

// Called on a separate thread to avoid UI thread contention
- (void)_openURLHelper:(NSURL*)url {
    WFUri* uri = [[WFUri makeUri:[url absoluteString]] autorelease];

    void (^launchSuccess)(BOOL) = ^void(BOOL didHandle) {
        [_launchCondition lock];
        _launchDidSucceed = didHandle;
        _launchCompleted = YES;
        [_launchCondition signal];
        [_launchCondition unlock];
    };

    void (^launchFailure)(NSError*) = ^void(NSError* launchError) {
        [_launchCondition lock];
        _launchDidSucceed = NO;
        _launchCompleted = YES;
        [_launchCondition signal];
        [_launchCondition unlock];
        NSTraceError(TAG, @"openURL failed. Error: %@", launchError);
    };

    [_launcher launchUriAsync:uri success:launchSuccess failure:launchFailure];
}

/**
 * Checks if the given URL can be opened synchronously.
 * Note: This method can block, but because it will not block for a long time it should be OK to call it from the main thread.
 *
 * @param {NSURL*} url URL to check
 * @return {BOOL} true if the URL can be opened successfully, false otherwise
 */
- (BOOL)_canOpenURL:(NSURL*)url {
    @synchronized(self) {
        NSThread* thread = [[NSThread alloc] initWithTarget:self selector:@selector(_canOpenURLHelper:) object:url];
        [_canOpenCondition lock];
        _canOpenCompleted = NO;
        [thread start];

        while (_canOpenCompleted == NO) {
            [_canOpenCondition wait];
        }

        [_canOpenCondition unlock];
        [thread release];
        return _canOpenDidSucceed;
    }
}

// Called on a separate thread to avoid UI thread contention
- (void)_canOpenURLHelper:(NSURL*)url {
    WFUri* uri = [[WFUri makeUri:[url absoluteString]] autorelease];

    void (^querySuccess)(WSLaunchQuerySupportStatus) = ^void(WSLaunchQuerySupportStatus status) {
        [_canOpenCondition lock];
        _canOpenDidSucceed = (status == WSLaunchQuerySupportStatusAvailable);
        _canOpenCompleted = YES;
        [_canOpenCondition signal];
        [_canOpenCondition unlock];
    };

    void (^queryFailure)(NSError*) = ^void(NSError* queryError) {
        [_canOpenCondition lock];
        _canOpenDidSucceed = NO;
        _canOpenCompleted = YES;
        [_canOpenCondition signal];
        [_canOpenCondition unlock];
        NSTraceError(TAG, @"canOpenURL failed. Error: %@", queryError);
    };

    [_launcher queryUriSupportAsync:uri launchQuerySupportType:WSLaunchQuerySupportTypeUri success:querySuccess failure:queryFailure];
}
@end
