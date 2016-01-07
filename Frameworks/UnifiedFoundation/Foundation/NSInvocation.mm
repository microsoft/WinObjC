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
#include "Foundation/NSInvocation.h"
#include <ctype.h>
#include <objc/encoding.h>

@implementation NSInvocation : NSObject
static void* copyArgument(NSInvocation* self, void* buf, int index) {
    char* type = (char*)[self->_methodSignature getArgumentTypeAtIndex:index];

    int size = objc_sizeof_type(type);

    void* ret = (void*)EbrMalloc(size);
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
        EbrFree(args[0]);
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
        free(args[1]);
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
    if (index >= MAX_ARGS) {
        EbrDebugLog("index = %d, MAX_ARGS = %d!\n", index, MAX_ARGS);
        assert(0);
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
        free(args[index]);
    }

    args[index] = copyArgument(self, buf, index);
}

/**
 @Status Interoperable
*/
- (void)getArgument:(void*)buf atIndex:(int)index {
    if (index >= MAX_ARGS) {
        EbrDebugLog("index = %d, MAX_ARGS = %d!\n", index, MAX_ARGS);
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
        free(returnValue);
    }

    returnValue = (char*)malloc(length);

    memcpy(returnValue, buf, length);
}

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
            free(args[i]);
        }
    }

    if (returnValue) {
        free(returnValue);
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

/**
 @Status Caveat
 @Notes For variadics, only works with 6 stack args max.
*/
- (void)invoke {
    char* type = (char*)[_methodSignature methodReturnType];
    int returnSize = objc_sizeof_type(type);
    char* pMsgFunc = "_objc_msgSend";

    unsigned totalLength = 0;
    unsigned numArgs = [_methodSignature numberOfArguments];
    char* pReturnVal = NULL;

    //  structure return type?
    if (type[0] == '{') {
        pReturnVal = (char*)malloc(returnSize);
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
                EbrDebugLog("Warning: NSInvocation argument not set\n");
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
            float (*impFloat)(id, SEL, ...) = (float (*)(id, SEL, ...))[target methodForSelector:sel];
            returnValue = malloc(sizeof(float));
            assert(stackParamsLen == 2);
            *(float*)returnValue = impFloat(target, sel);
        } else if (strcmp(type, "d") == 0) {
            double (*impDouble)(id, SEL, ...) = (double (*)(id, SEL, ...))[target methodForSelector:sel];
            returnValue = malloc(sizeof(double));
            assert(stackParamsLen == 2);
            *(double*)returnValue = impDouble(target, sel);
        } else {
            switch (stackParamsLen) {
                case 2: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 3: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 4: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 5: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 6: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 7: {
                    unsigned retVal;

                    retVal = imp(target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                case 8: {
                    unsigned retVal;

                    retVal = imp(
                        target, (SEL)sel, stackParams[2], stackParams[3], stackParams[4], stackParams[5], stackParams[6], stackParams[7]);
                    returnValue = malloc(returnSize + 4);
                    *((unsigned*)returnValue) = retVal;
                } break;

                default:
                    EbrDebugLog("Unhandled # of args: %d\n", stackParamsLen);
                    assert(0);
                    *((char*)0) = 0;
                    break;
            }
        }
    } else {
        id target = (id)stackParams[0];
        SEL sel = (SEL)stackParams[1];

        // This is x86-only. When structs are <= 8 bytes they're returned through registers instead.
        unsigned (*imp)(void*, id, SEL, ...) = (unsigned (*)(void*, id, SEL, ...))[target methodForSelector:sel];
        unsigned __int64 (*imp64ret)(id, SEL, ...) = (unsigned __int64 (*)(id, SEL, ...))imp;

        switch (stackParamsLen) {
            case 2: {
                if (returnSize <= 8) {
                    unsigned __int64 retVal = imp64ret(target, sel);
                    memcpy(pReturnVal, &retVal, returnSize);
                } else {
                    imp(pReturnVal, target, sel);
                }
                returnValue = pReturnVal;
            } break;

            default:
                assert(0);
                break;
        }
    }
}

@end
