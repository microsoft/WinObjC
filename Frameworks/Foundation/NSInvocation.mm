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
#import "Foundation/NSInvocation.h"
#import <ctype.h>
#import "LoggingNative.h"
#import <objc/encoding.h>
#import "ErrorHandling.h"

#include "FrameAllocator.h"
#include <vector>
#include <memory>

static const wchar_t* TAG = L"NSInvocation";

@implementation NSInvocation {
    NSMethodSignature* _methodSignature;

    std::unique_ptr<_NSInvocationCallFrame> _callFrame;
    std::vector<allocation_extent> _extents;

    size_t _returnLength;
    BOOL _retainArguments;

    uint8_t _smallReturnValueOptimization[8];
    void* _returnValue;
}

/**
 @Status Interoperable
*/
+ (NSInvocation*)invocationWithMethodSignature:(NSMethodSignature*)methodSignature {
    return [[[self alloc] initWithMethodSignature:methodSignature] autorelease];
}

/**
 @Status Interoperable
 */
- (instancetype)initWithMethodSignature:(NSMethodSignature*)methodSignature {
    if (self = [super init]) {
        _methodSignature = [methodSignature retain];

        _callFrame.reset(new _NSInvocationCallFrame(methodSignature));

        // true _non-promoted_ return length.
        _returnLength = methodSignature.methodReturnLength;//_callFrame->getReturnLength();
        auto promotedReturnLength = _callFrame->getReturnLength();
        if (promotedReturnLength > 8) {
            _returnValue = IwMalloc(promotedReturnLength); // promoted return length
        } else {
            _returnValue = &_smallReturnValueOptimization;
        }

        NSInteger nArgs = [methodSignature numberOfArguments];
        for(NSInteger i = 0; i < nArgs; ++i) {
            _extents.emplace_back(_callFrame->allocateArgument([methodSignature getArgumentTypeAtIndex:i]));
        }

    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)setTarget:(id)targetObj {
    [self setArgument:&targetObj atIndex:0];
}

/**
 @Status Interoperable
*/
- (id)target {
    id target = nil;
    [self getArgument:&target atIndex:0];
    return target;
}

/**
 @Status Interoperable
*/
- (void)setSelector:(SEL)targSelector {
    [self setArgument:&targSelector atIndex:1];
}

/**
 @Status Interoperable
*/
- (SEL)selector {
    SEL selector = nil;
    [self getArgument:&selector atIndex:1];
    return selector;
}

/**
 @Status Interoperable
*/
- (NSMethodSignature*)methodSignature {
    return _methodSignature;
}

/**
 @Status Interoperable
*/
- (void)setArgument:(void*)buf atIndex:(int)index {
    if ((index < 0) || (index >= [_methodSignature numberOfArguments]) || (index >= MAX_ARGS)) {
        TraceVerbose(TAG, L"index = %d, MAX_ARGS = %d, MethodSig arguments = %d", index, MAX_ARGS, [_methodSignature numberOfArguments]);
        [NSException raise:NSInvalidArgumentException format:@"The number of arguments exceeds the allowed limit."];
    }

    allocation_extent &ext = _extents[index];
    if (_retainArguments) {
        auto argumentType = [_methodSignature getArgumentTypeAtIndex:index];
        if (argumentType[0] == '@') {
            // Release old value:
            id oldValue = nil;
            [self getArgument:&oldValue atIndex:index];
            [(*(id*)buf) retain];
            [oldValue release];
        } else if (argumentType[0] == '*') {
            char *oldValue = nullptr;
            [self getArgument:&oldValue atIndex:index];
            IwFree(oldValue);
            *(char**)buf = IwStrDup(*(char**)buf);
        }
    }
    memcpy(ext.location, buf, ext.length);
}

/**
 @Status Interoperable
*/
- (void)getArgument:(void*)buf atIndex:(int)index {
    if (index >= MAX_ARGS) {
        TraceVerbose(TAG, L"index = %d, MAX_ARGS = %d!", index, MAX_ARGS);
        assert(0);
    }

    allocation_extent &ext = _extents[index];
    memcpy(buf, ext.location, ext.length);
}

/**
 @Status Interoperable
*/
- (void)retainArguments {
    if (!_retainArguments) {
        _retainArguments = true;

        auto numArgs = [_methodSignature numberOfArguments];

        for (unsigned int i = 0; i < numArgs; i++) {
            auto type = [_methodSignature getArgumentTypeAtIndex:i];
            if (type[0] == '@') {
                // id or block
                id arg = nil;
                [self getArgument:&arg atIndex:i];
                [arg retain];
            } else if (type[0] == '*') {
                // char*
                char* arg = nullptr;
                [self getArgument:&arg atIndex:i];
                arg = IwStrDup(arg);
                [self setArgument:&arg atIndex:i];
            }
        }
    }
}

/**
 @Status Interoperable
*/
- (void)getReturnValue:(void*)buf {
    memcpy(buf, _returnValue, _returnLength);
}

/**
 @Status Interoperable
*/
- (void)setReturnValue:(void*)buf {
    memcpy(_returnValue, buf, _returnLength);
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    // Release retained/string-copied arguments
    if (_retainArguments) {
        auto numArgs = [_methodSignature numberOfArguments];

        for (unsigned int i = 0; i < numArgs; i++) {
            auto type = [_methodSignature getArgumentTypeAtIndex:i];
            if (type[0] == '@') {
                // id or block
                id arg = nil;
                [self getArgument:&arg atIndex:i];
                [arg release];
            } else if (type[0] == '*') {
                char* arg = nullptr;
                [self getArgument:&arg atIndex:i];
                IwFree(arg);
            }
        }
    }

    if (_returnValue != &_smallReturnValueOptimization) {
        IwFree(_returnValue);
    }

    [_methodSignature release];

    [super dealloc];
}

/**
 @Status Interoperable
*/
- (void)invokeWithTarget:(id)target {
    [self setTarget:target];
    [self invoke];
}

// uniformTypeFromStructSpecifier attempts to determine the common type for an aggregate.
// For aggregates of disparate types or unknowable types, this function returns \0.
// struct type encodings are generally of the form {name=mmm}, where m is a member encoding.
// This function requires a char** so that it may advance the type encoding in the recursive case.
//
// Base case:
// {CGSize=ff}
//  ====f====  <- homogenous type is f
//
// {Struct=il}
// --- no homogenous type ---
//
// Recursive case:
// {CGRect={CGSize=ff}{CGPoint=ff}}
//          ====f====  =====f==== <- recursively resolve homogenous type of sub-structures
//              |           |
//              v           v
//  ==============f============== <- resolve homogenous type for CGRect to f
char uniformTypeFromStructSpecifier(const char** type) {
    char uniformType = '\0';
    do {
        ++(*type);
        if (_C_STRUCT_E == **type) {
            // premature end: forward-declared struct with unknown members.
            return '\0';
        }
    } while ('=' != **type);

    ++(*type); // skip the =

    while (**type != _C_STRUCT_E) {
        if (**type == '"') {
            // Occasionally, struct encodings store field names as in {name="x"f"y"f}. Skip those.
            do {
                ++(*type);
            } while ('"' != **type);
            ++(*type);
        }
        char v = **type;
        switch (v) {
            case _C_STRUCT_B:
                v = uniformTypeFromStructSpecifier(type);
                if (!v) {
                    return '\0';
                }
                break;
            default:
                *type = objc_skip_typespec(*type);
                break;
        }
        if (!uniformType) {
            uniformType = v;
        } else if (uniformType != v) {
            return '\0';
        }
    }

    ++(*type);
    return uniformType;
}

#if _M_IX86
#define ARCH_SMALL_STRUCT_SIZE 8
typedef uint64_t arch_small_struct_type;
#elif _M_ARM
#define ARCH_SMALL_STRUCT_SIZE 4
typedef uint32_t arch_small_struct_type;
#else
#warning unsupported platform for struct returns
#endif

#if _M_ARM
template <typename UniformType>
struct uniformAggregate {
    UniformType val[4];
};
template <typename UniformType, typename... Args>
static uniformAggregate<UniformType> callUniformAggregateImp(IMP imp, id target, SEL selector, Args... args) {
    return ((uniformAggregate<UniformType> (*)(id, SEL, Args...))imp)(target, selector, args...);
}
#endif

/**
 @Status Interoperable
*/
- (void)invoke {
    void* pfn = &objc_msgSend;
    if (_callFrame->getRequiresStructReturn()) {
        pfn = &objc_msgSend_stret;
    }

    _callFrame->execute(pfn, _returnValue);
}

@end
