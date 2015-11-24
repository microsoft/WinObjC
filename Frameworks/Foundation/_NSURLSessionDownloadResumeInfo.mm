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

#import <Foundation/Foundation.h>
#import "NSURLSessionTask-Internal.h"

@implementation _NSURLSessionDownloadResumeInfo
- (instancetype)initWithURLResponse:(NSHTTPURLResponse*)response temporaryFileURL:(NSURL*)temporaryFileURL {
    if (self = [super init]) {
        NSDictionary* headerFields = [response allHeaderFields];
        _etag = [headerFields[@"ETag"] copy];
        _lastModifiedDate = [headerFields[@"Last-Modified"] copy];
        if (!_etag && !_lastModifiedDate) {
            [self release];
            return nil;
        }

        _remoteURL = [[response URL] copy];
        _fileURL = [temporaryFileURL copy];
    }
    return self;
}

- (void)dealloc {
    [_etag release];
    [_lastModifiedDate release];
    [_remoteURL release];
    [_fileURL release];
    [super dealloc];
}

+ (BOOL)supportsSecureCoding {
    return YES;
}

- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        _remoteURL = [[coder decodeObjectOfClass:[NSURL class] forKey:@"NS.remoteURL"] retain];
        _etag = [[coder decodeObjectOfClass:[NSString class] forKey:@"NS.etag"] retain];
        _lastModifiedDate = [[coder decodeObjectOfClass:[NSString class] forKey:@"NS.lastModifiedDate"] retain];
        _fileURL = [[coder decodeObjectOfClass:[NSURL class] forKey:@"NS.fileURL"] retain];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_remoteURL forKey:@"NS.remoteURL"];
    [coder encodeObject:_etag forKey:@"NS.etag"];
    [coder encodeObject:_lastModifiedDate forKey:@"NS.lastModifiedDate"];
    [coder encodeObject:_fileURL forKey:@"NS.fileURL"];
}
@end

