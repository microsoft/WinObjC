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
    void* _returnValue;
    BOOL _retainArguments;
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
		_returnValue = IwMalloc(_callFrame->getReturnLength()); // promoted return length

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
	return nil;
    //return *((id*)args[0]);
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
	return nullptr;
    //return *((SEL*)args[1]);
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
	memcpy(ext.location, buf, ext.length);

	/*
    if (_retainArguments) {
        char* type = (char*)[_methodSignature getArgumentTypeAtIndex:index];

        if (strcmp(type, "@") == 0) {
            id arg = *((id*)buf);
            [arg retain];

            if (args[index] != NULL) {
                arg = *((id*)args[index]);
                [arg release];
            }
        }
    }

    if (args[index]) {
        IwFree(args[index]);
    }

    args[index] = copyArgument(self, buf, index);
	*/
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
	/*
    if (!_retainArguments) {
        _retainArguments = true;

        DWORD numArgs = [_methodSignature numberOfArguments];

        //  retain arguments
        for (unsigned int i = 0; i < numArgs; i++) {
            char* type = (char*)[_methodSignature getArgumentTypeAtIndex:i];

            if (args[i] != NULL) {
                if (strcmp(type, "@") == 0) {
                    id arg = *((id*)args[i]);
                    [arg retain];
                }
            }
        }
    }
	*/
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
	/*
    DWORD numArgs = [_methodSignature numberOfArguments];

    //  release arguments
    if (_retainArguments) {
        for (unsigned int i = 0; i < numArgs; i++) {
            char* type = (char*)[_methodSignature getArgumentTypeAtIndex:i];

            if (args[i] != NULL) {
                if (strcmp(type, "@") == 0) {
                    id arg = *((id*)args[i]);
                    [arg release];
                }
            }
        }
    }
    for (unsigned int i = 0; i < numArgs; i++) {
        if (args[i] != NULL) {
            IwFree(args[i]);
        }
    }

    if (returnValue) {
        IwFree(returnValue);
    }

    [_methodSignature release];

    [super dealloc];
	*/
	IwFree(_returnValue);
	[super dealloc];
}

/**
 @Status Caveat
 @Notes as above
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
 @Status Caveat
 @Notes For variadics, only works with 6 stack args max.
*/
- (void)invoke {
	void* pfn = &objc_msgSend;
	if (_callFrame->getRequiresStructReturn()) {
		pfn = &objc_msgSend_stret;
	}

	_callFrame->execute(pfn, _returnValue);
	//CallWithAllocatedFrame(*_callFrame, _returnType, _returnLength, _returnValue, pfn);
}

@end
