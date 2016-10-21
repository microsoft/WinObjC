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
#import "Foundation/NSStream.h"
#import "Foundation/NSString.h"
#import "Foundation/NSInputStream.h"
#import "LoggingNative.h"

#import "NSCFInputStream.h"

static const wchar_t* TAG = L"NSInputStream";

@implementation NSInputStream

BASE_CLASS_REQUIRED_IMPLS(NSInputStream, NSInputStreamPrototype, CFReadStreamGetTypeID);

/**
 @Status Interoperable
*/
+ (id)inputStreamWithFileAtPath:(id)file {
    return [[[self alloc] initWithFileAtPath:file] autorelease];
}

/**
 @Status Interoperable
*/
+ (id)inputStreamWithData:(id)data {
    return [[[self alloc] initWithData:data] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
+ (instancetype)inputStreamWithURL:(NSURL*)url {
    return [[[self alloc] initWithURL:url] autorelease];
}

/**
 @Status Interoperable
*/
- (id)initWithData:(id)data {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)initWithFileAtPath:(id)file {
    return [self initWithURL:[NSURL fileURLWithPath:file]];
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)initWithURL:(NSURL*)url {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (int)read:(uint8_t*)buf maxLength:(NSUInteger)maxLength {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)hasBytesAvailable {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)getBuffer:(uint8_t* _Nullable*)buffer length:(NSUInteger*)len {
    return NSInvalidAbstractInvocationReturn();
}

@end
