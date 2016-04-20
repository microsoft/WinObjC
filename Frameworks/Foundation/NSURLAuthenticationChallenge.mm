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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSString.h"
#import "Foundation/NSURLAuthenticationChallenge.h"
#import "Foundation/NSURLProtectionSpace.h"

@interface NSURLAuthenticationChallenge () {
    StrongId<id> _protectionSpace;
    StrongId<id> _sender;
}
@end

@implementation NSURLAuthenticationChallenge

/**
 @Status Stub
*/
- (NSInteger)previousFailureCount {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
- (id)protectionSpace {
    UNIMPLEMENTED();
    return _protectionSpace;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    if (self = [super init]) {
        _protectionSpace.attach([NSURLProtectionSpace new]);
    }
    return self;
}

/**
 @Status Stub
*/
- (id)sender {
    UNIMPLEMENTED();
    return _sender;
}

- (void)setSender:(id)sender {
    _sender = sender;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithAuthenticationChallenge:(NSURLAuthenticationChallenge*)challenge
                                         sender:(id<NSURLAuthenticationChallengeSender>)sender {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithProtectionSpace:(NSURLProtectionSpace*)space
                     proposedCredential:(NSURLCredential*)credential
                   previousFailureCount:(NSInteger)count
                        failureResponse:(NSURLResponse*)response
                                  error:(NSError*)error
                                 sender:(id<NSURLAuthenticationChallengeSender>)sender {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

@end
