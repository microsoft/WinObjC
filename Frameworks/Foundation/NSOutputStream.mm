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
#include "Foundation/NSStream.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSOutputStream.h"
#include "LoggingNative.h"

#include "NSCFOutputStream.h"

static const wchar_t* TAG = L"NSOutputStream";

@implementation NSOutputStream

BASE_CLASS_REQUIRED_IMPLS(NSOutputStream, NSOutputStreamPrototype, CFWriteStreamGetTypeID);

/**
 @Status Interoperable
*/
+ (instancetype)outputStreamToFileAtPath:(NSString*)file append:(BOOL)append {
    return [[[self alloc] initToFileAtPath:file append:append] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)outputStreamToMemory {
    return [[[self alloc] initToMemory] autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)outputStreamToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity {
    return [[[self alloc] initToBuffer:buffer capacity:capacity] autorelease];
}

/**
 @Status Stub
*/
+ (instancetype)outputStreamWithURL:(NSURL*)url append:(BOOL)shouldAppend {
    return [[[self alloc] initWithURL:url append:shouldAppend] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initToFileAtPath:(NSString*)file append:(BOOL)append {
    return [self initWithURL:[NSURL fileURLWithPath:file] append:append];
}

/**
 @Status Interoperable
*/
- (instancetype)initToMemory {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (instancetype)initToBuffer:(uint8_t*)buffer capacity:(NSUInteger)capacity {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithURL:(NSURL*)url append:(BOOL)shouldAppend {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSInteger)write:(const uint8_t*)buf maxLength:(NSUInteger)maxLength {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)hasSpaceAvailable {
    return NSInvalidAbstractInvocationReturn();
}

@end
