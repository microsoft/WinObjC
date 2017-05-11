//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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

#import "Starboard.h"
#import <Foundation/NSMutableString.h>
#import <Foundation/NSURLProtocol.h>
#import <Foundation/NSMutableArray.h>
#import <Foundation/NSNumber.h>
#import <Foundation/NSMutableData.h>
#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSRunLoop.h>
#import <Foundation/NSTimer.h>
#import <Foundation/NSStream.h>
#import <Foundation/NSError.h>
#import <Foundation/NSHTTPURLResponse.h>
#import "NSURLProtocol_file.h"
#import "NSURLProtocolInternal.h"
#import "LoggingNative.h"

static const wchar_t* TAG = L"NSURLProtocol_file";

@implementation NSURLProtocol_file {
@private
    StrongId<NSString> _path;
}

+ (void)load {
    [NSURLProtocol registerClass:self];
}

+ (BOOL)canInitWithRequest:(id)request {
    id scheme = [[request URL] scheme];

    if ([scheme isEqualToString:@"file"])
        return YES;

    return NO;
}

- (id)initWithRequest:(id)request cachedResponse:(id)response client:(id)client {
    if (self = [super initWithRequest:request cachedResponse:response client:client]) {
        id url = [self.request URL];
        TraceVerbose(TAG, L"Loading %hs", [[url absoluteString] UTF8String]);

        _path.attach([[url path] copy]);
    }

    return self;
}

- (id)startLoading {
    // TODO 1162: An NSInputStream should be initialized here and run loop events should be used to schedule
    // the file operations.
    return self;
}

- (id)stopLoading {
    return self;
}

- (id)statusVersion:(id)versionStr {
    return self;
}

- (id)_doFileLoad {
    NSData* dataReceived = [NSData dataWithContentsOfFile:_path];

    id<NSURLProtocolClient> client = self.client;
    [client URLProtocol:self didReceiveResponse:nil cacheStoragePolicy:NSURLCacheStorageAllowed];
    [client URLProtocol:self didLoadData:dataReceived];
    [client URLProtocolDidFinishLoading:self];

    return self;
}

@end
