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
#import <Foundation/NSNetService.h>

NSString* const NSNetServicesErrorCode = @"NSNetServicesErrorCode";
NSString* const NSNetServicesErrorDomain = @"NSNetServicesErrorDomain";

@implementation NSNetService
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithDomain:(NSString*)domain type:(NSString*)type name:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithDomain:(NSString*)domain type:(NSString*)type name:(NSString*)name port:(int)port {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSData*)dataFromTXTRecordDictionary:(NSDictionary*)txtDictionary {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSDictionary*)dictionaryFromTXTRecordData:(NSData*)txtData {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)getInputStream:(NSInputStream* _Nullable*)inputStream outputStream:(NSOutputStream* _Nullable*)outputStream {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSData*)TXTRecordData {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)setTXTRecordData:(NSData*)recordData {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)scheduleInRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeFromRunLoop:(NSRunLoop*)aRunLoop forMode:(NSString*)mode {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)publish {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)publishWithOptions:(NSNetServiceOptions)serviceOptions {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)resolve {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)resolveWithTimeout:(NSTimeInterval)timeout {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startMonitoring {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stop {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopMonitoring {
    UNIMPLEMENTED();
}

@end
