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

#import <Foundation/NSInvocationOperation.h>
#import <Starboard/SmartTypes.h>
#import <NSLogging.h>
#import <memory>

NSString* const NSInvocationOperationVoidResultException = @"NSInvocationOperationVoidResultException";
NSString* const NSInvocationOperationCancelledException = @"NSInvocationOperationCancelledException";

@interface NSInvocationOperation () {
    StrongId<NSException> _caughtException;
    StrongId<id> _result;
}
@end

@implementation NSInvocationOperation
/**
 @Status Interoperable
*/
- (instancetype)initWithTarget:(id)target selector:(SEL)sel object:(id)arg {
    NSMethodSignature* methodSignature = [target methodSignatureForSelector:sel];
    if (!methodSignature) {
        [self release];
        return nil;
    }

    if (methodSignature.numberOfArguments > 3) { // 3: self, _cmd, arg1
        [self release];
        NSTraceError(L"NSInvocationOperation",
                     @"%hs: method '%hs' requires %u arguments (max 1)",
                     __PRETTY_FUNCTION__,
                     sel_getName(sel),
                     methodSignature.numberOfArguments - 2);
        return nil;
    }

    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:methodSignature];
    invocation.target = target;
    invocation.selector = sel;
    if (methodSignature.numberOfArguments == 3) {
        [invocation setArgument:&arg atIndex:2];
    }

    return [self initWithInvocation:invocation];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithInvocation:(NSInvocation*)invocation {
    if (!invocation) {
        [self release];
        return nil;
    }

    if (self = [super init]) {
        _invocation = [invocation retain];
        [_invocation retainArguments];
    }
    return self;
}

- (void)dealloc {
    [_invocation release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (id)result {
    @synchronized(self) {
        if (!self.finished) {
            return nil;
        }

        if (self.cancelled) {
            [NSException raise:NSInvocationOperationCancelledException format:@"%hs: %@ was cancelled", __PRETTY_FUNCTION__, self];
        }

        if (_caughtException) {
            [_caughtException raise];
        }

        if (_invocation.methodSignature.methodReturnLength == 0) {
            [NSException raise:NSInvocationOperationVoidResultException format:@"%hs: %@ has a void result", __PRETTY_FUNCTION__, self];
        }

        return [[_result retain] autorelease];
    }
}

// NSOperation
- (void)main {
    id ret = nil;
    NSException* exception = nil;
    @try {
        [_invocation invoke];

        const char* returnType = _invocation.methodSignature.methodReturnType;

        if (returnType && returnType[0] == _C_ID) {
            [_invocation getReturnValue:&ret];
        } else {
            std::unique_ptr<uint8_t[]> bytes{ new uint8_t[_invocation.methodSignature.methodReturnLength] };
            [_invocation getReturnValue:bytes.get()];
            ret = [NSValue valueWithBytes:bytes.get() objCType:returnType];
        }
    }
#ifdef _M_ARM // TODO #352 @catch(NSException*) fails on ARM
    @catch (...) {
        exception =
            [NSException exceptionWithName:NSGenericException reason:@"An exception was encountered during this operation" userInfo:nil];
    }
#else
    @catch (NSException* e) {
        exception = e;
    }
#endif

    // clang-format off
    // clang-format hilariously breaks the @ and the synchronized onto two different lines.
    @synchronized(self) {
        // clang-format on
        _result = ret;
        _caughtException = exception;
    }
}
@end
