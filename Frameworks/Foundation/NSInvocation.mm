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

static const wchar_t* TAG = L"NSInvocation";

@implementation NSInvocation
static void* copyArgument(NSInvocation* self, void* buf, int index) {
    char* type = (char*)[self->_methodSignature getArgumentTypeAtIndex:index];

    int size = objc_sizeof_type(type);

    void* ret = (void*)IwMalloc(size);
    memcpy(ret, buf, size);

    return ret;
}

/**
 @Status Interoperable
*/
+ (NSInvocation*)invocationWithMethodSignature:(id)methodSignature {
    NSInvocation* ret = [self alloc];
    ret->_methodSignature = [methodSignature retain];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (void)setTarget:(id)targetObj {
    if (args[0]) {
        IwFree(args[0]);
    }
    args[0] = copyArgument(self, &targetObj, 0);
}

/**
 @Status Interoperable
*/
- (id)target {
    return *((id*)args[0]);
}

/**
 @Status Interoperable
*/
- (void)setSelector:(SEL)targSelector {
    uint32_t argSelectorEmu = (uint32_t)targSelector;

    if (args[1]) {
        IwFree(args[1]);
    }
    args[1] = copyArgument(self, &argSelectorEmu, 1);
}

/**
 @Status Interoperable
*/
- (SEL)selector {
    return *((SEL*)args[1]);
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

    if (retainArguments) {
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
}

/**
 @Status Interoperable
*/
- (void)getArgument:(void*)buf atIndex:(int)index {
    if (index >= MAX_ARGS) {
        TraceVerbose(TAG, L"index = %d, MAX_ARGS = %d!", index, MAX_ARGS);
        assert(0);
    }

    char* type = (char*)[_methodSignature getArgumentTypeAtIndex:index];

    int size = objc_sizeof_type(type);
    memcpy(buf, args[index], size);
}

/**
 @Status Interoperable
*/
- (void)retainArguments {
    if (!retainArguments) {
        retainArguments = true;

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
}

/**
 @Status Interoperable
*/
- (void)getReturnValue:(void*)buf {
    char* type = (char*)[_methodSignature methodReturnType];
    int length = objc_sizeof_type(type);

    memcpy(buf, returnValue, length);
}

/**
 @Status Interoperable
*/
- (void)setReturnValue:(void*)buf {
    char* type = (char*)[_methodSignature methodReturnType];
    int length = objc_sizeof_type(type);

    if (returnValue) {
        IwFree(returnValue);
    }

    returnValue = (char*)IwMalloc(length);

    memcpy(returnValue, buf, length);
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    DWORD numArgs = [_methodSignature numberOfArguments];

    //  release arguments
    if (retainArguments) {
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
static char uniformTypeFromStructSpecifier(const char** type) {
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
    const char* type = [_methodSignature methodReturnType];
    int returnSize = objc_sizeof_type(type);
    const char* pMsgFunc = "_objc_msgSend";

    unsigned totalLength = 0;
    unsigned numArgs = [_methodSignature numberOfArguments];
    char* pReturnVal = NULL;

    //  structure return type?
    if (type[0] == '{') {
        pReturnVal = (char*)IwMalloc(returnSize);
        totalLength += 4;
        pMsgFunc = "_objc_msgSend_stret";
    }

    for (unsigned int i = 0; i < numArgs; i++) {
        char* type = (char*)[_methodSignature getArgumentTypeAtIndex:i];

        int size = objc_sizeof_type(type);
        size = (size + 3) & ~3;
        totalLength += size;
    }

    unsigned stackParams[32];
    int stackParamsLen = 0;

    for (unsigned i = 0; i < numArgs; i++) {
        char* type = (char*)[_methodSignature getArgumentTypeAtIndex:i];

        int size = objc_sizeof_type(type);
        char* curArg = (char*)args[i];

        while (size > 0) {
            unsigned curWord = 0;

            if (curArg != NULL) {
                memcpy(&curWord, curArg, size > 4 ? 4 : size);
            } else {
                TraceWarning(TAG, L"Warning: NSInvocation argument not set");
            }

            stackParams[stackParamsLen++] = curWord;
            curArg += 4;
            size -= 4;
        }
    }
    if (strcmp(pMsgFunc, "_objc_msgSend") == 0) {
        id target = (id)stackParams[0];
        SEL sel = (SEL)stackParams[1];
        unsigned (*imp)(id, SEL, ...) = (unsigned (*)(id, SEL, ...))[target methodForSelector:sel];

        if (strcmp(type, "f") == 0) {
            float (*impFloat)(id, SEL) = (float (*)(id, SEL))[target methodForSelector:sel];
            returnValue = IwMalloc(sizeof(float));
            assert(stackParamsLen == 2);
            *(float*)returnValue = impFloat(target, sel);
        } else if (strcmp(type, "d") == 0) {
            double (*impDouble)(id, SEL) = (double (*)(id, SEL))[target methodForSelector:sel];
            returnValue = IwMalloc(sizeof(double));
            assert(stackParamsLen == 2);
            *(double*)returnValue = impDouble(target, sel);
        } else {
            switch (stackParamsLen) {
                case 2: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 3: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 4: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 5: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 6: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 7: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 8: {
                    unsigned retVal;

                    retVal = imp(
                        target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6], stackParams[7]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 9: {
                    unsigned retVal;

                    retVal = imp(
                        target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6], stackParams[7], stackParams[8]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 10: {
                    unsigned retVal;

                    retVal = imp(
                        target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6], stackParams[7], stackParams[8], stackParams[9]);
                    returnValue = IwMalloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                default:
                    FAIL_FAST_HR_MSG(E_UNEXPECTED, "Unhandled # of args: %d", stackParamsLen);
                    break;
            }
        }
    } else {
        id target = (id)stackParams[0];
        SEL sel = (SEL)stackParams[1];

        id (*imp)(id, SEL, ...) = [target methodForSelector:sel];
        void (*stretImp)(void*, id, SEL, ...) = (void (*)(void*, id, SEL, ...))imp;
        // structs below a certain size may be returned in registers. on x86, that limit is 8 bytes. on ARM it is 4.
        switch (stackParamsLen) {
            case 2: {
#if _M_ARM
                // As in the _Procedure Call Standard for the ARM Architecture_, section 6.1,
                // aggregates containing 1-4 floats or doubles and no other types are returned in floating-point
                // registers. Here, we use a struct containing four floats/doubles to capture the full surface
                // area of the floating point register set in use for returns.
                const char* ptype = type;
                char uniformType = uniformTypeFromStructSpecifier(&ptype);
                if (returnSize <= sizeof(float) * 4 && uniformType == _C_FLT) {
                    auto retVal = callUniformAggregateImp<float>(imp, target, sel);
                    memcpy(pReturnVal, &retVal, returnSize);
                } else if (returnSize <= sizeof(double) * 4 && uniformType == _C_DBL) {
                    auto retVal = callUniformAggregateImp<double>(imp, target, sel);
                    memcpy(pReturnVal, &retVal, returnSize);
                } else
#endif
#ifdef ARCH_SMALL_STRUCT_SIZE
                    if (returnSize <= ARCH_SMALL_STRUCT_SIZE) {
                    arch_small_struct_type (*smallStructImp)(id, SEL, ...) = (arch_small_struct_type (*)(id, SEL, ...))stretImp;
                    auto retVal = smallStructImp(target, sel);
                    memcpy(pReturnVal, &retVal, returnSize);
                } else
#endif
                {
                    stretImp(pReturnVal, target, sel);
                }
                returnValue = pReturnVal;
            } break;

            default:
                TraceError(TAG,
                           L"Unable to realize stret imp call to -[%hs %hs] for >= 3 arguments.",
                           class_getName(object_getClass(target)),
                           sel_getName(sel));
                FAIL_FAST();
                break;
        }
    }
}

@end
