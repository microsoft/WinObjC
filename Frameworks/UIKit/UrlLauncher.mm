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
    WFUri* uri = [[WFUri createUri:[url absoluteString]] autorelease];

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
        NSLog(@"openURL failed. Error: %@", launchError);
    };

    [_launcher launchUriAsync:uri success:launchSuccess failure:launchFailure];
}

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
    WFUri* uri = [[WFUri createUri:[url absoluteString]] autorelease];

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
        NSLog(@"canOpenURL failed. Error: %@", queryError);
    };

    [_launcher queryUriSupportAsync:uri launchQuerySupportType:WSLaunchQuerySupportTypeUri success:querySuccess failure:queryFailure];
}
@end
