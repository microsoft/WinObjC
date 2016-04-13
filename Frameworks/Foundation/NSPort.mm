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

#import <StubReturn.h>
#import <Foundation/NSPort.h>

NSString* const NSPortTimeoutException = @"NSPortTimeoutException";
NSString* const NSInvalidSendPortException = @"NSInvalidSendPortException";
NSString* const NSInvalidReceivePortException = @"NSInvalidReceivePortException";
NSString* const NSPortSendException = @"NSPortSendException";
NSString* const NSPortReceiveException = @"NSPortReceiveException";
NSString* const NSOldStyleException = @"NSOldStyleException";

@implementation NSPort
/**
 @Status Stub
 @Notes
*/
+ (id)allocWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPort*)port {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)invalidate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDelegate:(id<NSPortDelegate>)anObject {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id<NSPortDelegate>)delegate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendBeforeDate:(NSDate*)limitDate
            components:(NSMutableArray*)components
                  from:(NSPort*)receivePort
              reserved:(NSUInteger)headerSpaceReserved {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)sendBeforeDate:(NSDate*)limitDate
                 msgid:(NSUInteger)msgID
            components:(NSMutableArray*)components
                  from:(NSPort*)receivePort
              reserved:(NSUInteger)headerSpaceReserved {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeFromRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)scheduleInRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
