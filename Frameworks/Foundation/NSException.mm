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
#include "Foundation/NSException.h"

NSString* const NSRangeException = @"NSRangeExcepton";
NSString* const NSGenericException = @"NSGenericException";
NSString* const NSInvalidArgumentException = @"NSInvalidArgumentException";
NSString* const NSInternalInconsistencyException = @"NSInternalInconsistencyException";
NSString* const NSObjectNotAvailableException = @"NSObjectNotAvailableException";
NSString* const NSDestinationInvalidException = @"NSDestinationInvalidException";
NSString* const NSURLErrorDomain = @"NSURLErrorDomain";
NSString* const NSOverflowException = @"NSOverflowException";

@implementation NSException {
    idretaintype(NSString) _name;
    idretaintype(NSString) _reason;
    idretaintype(NSDictionary) _userInfo;
}

- (instancetype)initWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo {
    _name.attach([name copy]);
    _reason.attach([reason copy]);
    _userInfo.attach([userInfo copy]);

    return self;
}

+ (instancetype)exceptionWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo {
    NSException* ret = [[self alloc] initWithName:name reason:reason userInfo:userInfo];

    return [ret autorelease];
}

+ (void)raise:(NSString*)name format:(NSString*)format, ... {
    va_list reader;
    va_start(reader, format);

    NSString* reason = [[NSString alloc] initWithFormat:format arguments:reader];
    va_end(reader);

    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];
    [exception raise];
}

+ (void)raiseWithLogging:(NSString*)name format:(NSString*)format, ... {
    va_list reader;
    va_start(reader, format);

    NSString* reason = [[NSString alloc] initWithFormat:format arguments:reader];
    va_end(reader);

    NSLog(@"Exception %@ raised!\nReason: %@\n", name, reason);

    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];

    [exception raise];
}

+ (void)raise:(NSString*)name format:(NSString*)format arguments:(va_list)args {
    NSString* reason = [[NSString alloc] initWithFormat:format arguments:args];
    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];
    [exception raise];
}

- (void)raise {
    @throw self;
}

- (NSString*)name {
    return _name;
}

- (NSDictionary*)userInfo {
    return _userInfo;
}

- (NSString*)reason {
    return _reason;
}
@end