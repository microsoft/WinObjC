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

#define MAX(a, b) ((a) > (b) ? (a) : (b))

size_t objc_alignof_type(const char* type);

static inline size_t ROUND(size_t v, size_t a) {
    if (v % a == 0) {
        return v;
    } else {
        return v + a - (v % a);
    }
}

enum {
    _C_ID = '@',
    _C_CHR = 'c',
    _C_UCHR = 'C',
    _C_INT = 'i',
    _C_UINT = 'I',
    _C_FLT = 'f',
    _C_DBL = 'd',
    _C_VOID = 'v',
    _C_UNDEF = '?',
    _C_CLASS = '#',
    _C_SEL = ':',
    _C_CHARPTR = '*',
    _C_SHT = 's',
    _C_USHT = 'S',
    _C_LNG = 'l',
    _C_ULNG = 'L',
    _C_LNGLNG = 'q',
    _C_LNG_LNG = _C_LNGLNG,
    _C_ULNGLNG = 'Q',
    _C_ULNG_LNG = _C_ULNGLNG,
    _C_BFLD = 'b',
    _C_ARY_B = '[',
    _C_STRUCT_B = '{',
    _C_UNION_B = '(',
    _C_ARY_E = ']',
    _C_STRUCT_E = '}',
    _C_UNION_E = ')',
    _C_PTR = '^',
    _C_CONST = 'r',
    _C_IN = 'n',
    _C_INOUT = 'N',
    _C_OUT = 'o',
    _C_BYCOPY = 'R',
    _C_ONEWAY = 'V',
    _C_COMPLEX = 'j',
};

#define _C_BOOL 'B'

static inline const char* objc_skip_type_qualifier(const char* type) {
    assert(type != NULL);

    while (*type == _C_CONST || *type == _C_IN || *type == _C_INOUT || *type == _C_OUT || *type == _C_BYCOPY || *type == _C_ONEWAY) {
        type++;
    }
    while (*type && isdigit(*type)) {
        type++;
    }
    return type;
}

const char* objc_skip_type_specifier(const char* type, BOOL skipDigits) {
    assert(type != NULL);

    type = objc_skip_type_qualifier(type);

    switch (*type) {
        /* The following are one character type codes */
        case _C_UNDEF:
        case _C_CLASS:
        case _C_SEL:
        case _C_CHR:
        case _C_UCHR:
        case _C_CHARPTR:
#ifdef _C_ATOM
        case _C_ATOM:
#endif
#ifdef _C_BOOL
        case _C_BOOL:
#endif
        case _C_SHT:
        case _C_USHT:
        case _C_INT:
        case _C_UINT:
        case _C_LNG:
        case _C_ULNG:
        case _C_FLT:
        case _C_DBL:
        case _C_VOID:
        case _C_LNG_LNG:
        case _C_ULNG_LNG:
            ++type;
            break;

        case _C_COMPLEX:
            ++type;
            type = objc_skip_type_specifier(type, skipDigits);
            break;

        case _C_BFLD:
            while (isdigit(*++type)) {
                ;
            }
            break;

        case _C_ID:
            ++type;
            if (*type == '"') {
                /* embedded field name in an ivar_type */
                type = strchr(type + 1, '"');
                if (type != NULL) {
                    type++;
                }
            }
            break;

        case _C_ARY_B:
            /* skip digits, typespec and closing ']' */

            while (isdigit(*++type)) {
                ;
            }
            type = objc_skip_type_specifier(type, skipDigits);
            assert(type == NULL || *type == _C_ARY_E);
            if (type) {
                type++;
            }
            break;

        case _C_STRUCT_B:
            /* skip name, and elements until closing '}'  */
            while (*type != _C_STRUCT_E && *type++ != '=') {
                ;
            }
            while (type && *type != _C_STRUCT_E) {
                if (*type == '"') {
                    /* embedded field names */
                    type = strchr(type + 1, '"');
                    if (type != NULL) {
                        type++;
                    } else {
                        return NULL;
                    }
                }
                type = objc_skip_type_specifier(type, skipDigits);
            }
            if (type) {
                type++;
            }
            break;

        case _C_UNION_B:
            /* skip name, and elements until closing ')'  */
            while (*type != _C_UNION_E && *type++ != '=') {
                ;
            }
            while (type && *type != _C_UNION_E) {
                if (*type == '"') {
                    /* embedded field names */
                    type = strchr(type + 1, '"');
                    if (type != NULL) {
                        type++;
                    } else {
                        return NULL;
                    }
                }
                type = objc_skip_type_specifier(type, skipDigits);
            }
            if (type) {
                type++;
            }
            break;

        case _C_PTR:
        case _C_CONST:
        case _C_IN:
        case _C_INOUT:
        case _C_OUT:
        case _C_BYCOPY:
        case _C_ONEWAY:

            /* Just skip the following typespec */
            type = objc_skip_type_specifier(type + 1, skipDigits);
            break;

        default:
            EbrDebugLog("objc_skip_type_specifier: Unhandled type '%#x' %s", *type, type);
            return NULL;
    }

    if (skipDigits) {
        /* The compiler inserts a number after the actual signature,
        * this number may or may not be usefull depending on the compiler
        * version. We never use it.
        */
        while (type && *type && isdigit(*type)) {
            type++;
        }
    }

    return type;
}

/*
Return the alignment of an object specified by type
*/

/*
*  On MacOS X, the elements of a struct are aligned differently inside the
*  struct than outside. That is, the maximum alignment of any struct field
*  (except the first) is 4, doubles outside of a struct have an alignment of
*  8.
*
*  Other platform don't seem to have this inconsistency.
*
*  XXX: sizeof_struct, alignof_struct and {de,}pythonify_c_struct should
*  probably be moved to platform dependend files. As long as this is the
*  only platform dependent code this isn't worth the effort.
*/

static inline size_t PyObjC_EmbeddedAlignOfType(const char* type) {
    assert(type != NULL);

    size_t align = objc_alignof_type(type);

#if (defined(__i386__) || defined(__x86_64__)) && !defined(LINUX)
    return align;

#else
    if (align < 4 || align == 16) {
        return align;
    } else {
        return 4;
    }
#endif
}

#define __alignof__(x)sizeof(x)

size_t objc_alignof_type(const char* type) {
    assert(type != NULL);

    switch (*type) {
        case _C_VOID:
            return __alignof__(char);
        case _C_ID:
            return 4;
        case _C_CLASS:
            return 4;
        case _C_SEL:
            return 4;
        case _C_CHR:
            return __alignof__(char);
        case _C_UCHR:
            return __alignof__(unsigned char);
        case _C_SHT:
            return __alignof__(short);
        case _C_USHT:
            return __alignof__(unsigned short);
#ifdef _C_BOOL
        case _C_BOOL:
            return __alignof__(bool);
#endif
        case _C_INT:
            return __alignof__(int);
        case _C_UINT:
            return __alignof__(unsigned int);
        case _C_LNG:
            return __alignof__(long);
        case _C_ULNG:
            return __alignof__(unsigned long);
        case _C_FLT:
            return __alignof__(float);
        case _C_DBL:
#if defined(__APPLE__) && defined(__i386__)
            /* The ABI says natural alignment is 4 bytes, but
            * GCC's __alignof__ says 8. The latter is wrong.
            */
            return 4;
#else
            return __alignof__(double);
#endif

        case _C_CHARPTR:
            return __alignof__(char*);
#ifdef _C_ATOM
        case _C_ATOM:
            return __alignof__(char*);
#endif
        case _C_PTR:
            return __alignof__(void*);
#if defined(__APPLE__) && defined(__i386__)
        /* The ABI says natural alignment is 4 bytes, but
        * GCC's __alignof__ says 8. The latter is wrong.
        */
        case _C_LNG_LNG:
            return 4;
        case _C_ULNG_LNG:
            return 4;
#else
        case _C_LNG_LNG:
            return __alignof__(long long);
        case _C_ULNG_LNG:
            return __alignof__(unsigned long long);
#endif

        case _C_COMPLEX:
            ++type;
            return objc_alignof_type(type);

        case _C_ARY_B:
            while (isdigit(*++type)) { /* do nothing */
                ;
            }
            return objc_alignof_type(type);

        case _C_STRUCT_B: {
            struct fooalign {
                int x;
                double y;
            };
            while (*type != _C_STRUCT_E && *type++ != '=') { /* do nothing */
                ;
            }
            if (*type != _C_STRUCT_E) {
                int have_align = 0;
                size_t align = 0;

                while (type != NULL && *type != _C_STRUCT_E) {
                    if (*type == '"') {
                        type = strchr(type + 1, '"');
                        if (type) {
                            type++;
                        }
                    }
                    if (have_align) {
                        align = MAX(align, PyObjC_EmbeddedAlignOfType(type));
                    } else {
                        align = objc_alignof_type(type);
                        have_align = 1;
                    }
                    type = objc_skip_type_specifier(type, YES);
                }
                if (type == NULL) {
                    return -1;
                }
                return align;
            } else {
                return __alignof__(fooalign);
            }
        }

        case _C_UNION_B: {
            size_t maxalign = 0;
            type++;
            while (*type != _C_UNION_E && *type++ != '=') {
                ; /* skip "<name>=" */
            }
            while (*type != _C_UNION_E) {
                if (*type == '"') {
                    type = strchr(type + 1, '"');
                    if (type) {
                        type++;
                    }
                }
                size_t item_align = objc_alignof_type(type);
                if (item_align == -1) {
                    return -1;
                }
                maxalign = MAX(maxalign, item_align);
                type = objc_skip_type_specifier(type, YES);
            }
            return maxalign;
        }

        case _C_CONST:
        case _C_IN:
        case _C_INOUT:
        case _C_OUT:
        case _C_BYCOPY:
        case _C_ONEWAY:
            return objc_alignof_type(type + 1);

        case _C_BFLD:
            return 1;

        default:
            EbrDebugLog("objc_alignof_type: Unhandled type '%c' %s", *type, type);
            return -1;
    }
}

size_t objc_sizeof_type(const char* type);

/*
The aligned size if the size rounded up to the nearest alignment.
*/

static inline size_t PyObjCRT_AlignedSize(const char* type) {
    assert(type != NULL);

    size_t size = objc_sizeof_type(type);
    size_t align = objc_alignof_type(type);

    if (size == -1 || align == -1) {
        return -1;
    }
    return ROUND(size, align);
}

/*
return the size of an object specified by type
*/

size_t objc_sizeof_type(const char* type) {
    assert(type != NULL);

    size_t itemSize;
    switch (*type) {
        case _C_VOID:
            return 1; // More convenient than the correct value.
        case _C_ID:
            return 4;
        case _C_CLASS:
            return 4;
        case _C_SEL:
            return 4;
        case _C_CHR:
            return sizeof(char);
        case _C_UCHR:
            return sizeof(unsigned char);
        case _C_SHT:
            return sizeof(short);
        case _C_USHT:
            return sizeof(unsigned short);
#ifdef _C_BOOL
        case _C_BOOL:
            return sizeof(bool);
#endif
        case _C_INT:
            return sizeof(int);
        case _C_UINT:
            return sizeof(unsigned int);
        case _C_LNG:
            return sizeof(long);
        case _C_ULNG:
            return sizeof(unsigned long);
        case _C_FLT:
            return sizeof(float);
        case _C_DBL:
            return sizeof(double);
        case _C_LNG_LNG:
            return sizeof(long long);
        case _C_ULNG_LNG:
            return sizeof(unsigned long long);

        case _C_PTR:
        case _C_CHARPTR:
#ifdef _C_ATOM
        case _C_ATOM:
#endif
            return sizeof(char*);

        case _C_COMPLEX: // A complex is stored as two back-to-back copies of the same type.
            ++type;
            return 2 * objc_sizeof_type(type);

        case _C_ARY_B: {
            size_t len = atoi(type + 1);
            size_t item_align;
            while (isdigit(*++type)) {
                ;
            }
            item_align = PyObjCRT_AlignedSize(type);
            if (item_align == -1) {
                return -1;
            }
            return len * item_align;
        } break;

        case _C_STRUCT_B: {
            size_t acc_size = 0;
            int have_align = 0;
            size_t align;
            size_t max_align = 0;

            while (*type != _C_STRUCT_E && *type++ != '=') {
                ; /* skip "<name>=" */
            }
            while (*type != _C_STRUCT_E) {
                if (*type == '"') {
                    type = strchr(type + 1, '"');
                    if (type) {
                        type++;
                    }
                }
                if (have_align) {
                    align = PyObjC_EmbeddedAlignOfType(type);
                    if (align == -1) {
                        return -1;
                    }
                } else {
                    align = objc_alignof_type(type);
                    if (align == -1) {
                        return -1;
                    }
                    have_align = 1;
                }
                max_align = MAX(align, max_align);
                acc_size = ROUND(acc_size, align);

                itemSize = objc_sizeof_type(type);
                if (itemSize == -1) {
                    return -1;
                }
                acc_size += itemSize;
                type = objc_skip_type_specifier(type, YES);
            }
            if (max_align) {
                acc_size = ROUND(acc_size, max_align);
            }
            return acc_size;
        }

        case _C_UNION_B: {
            size_t max_size = 0;
            while (*type != _C_UNION_E && *type++ != '=') {
                ; /* skip "<name>=" */
            }

            while (*type != _C_UNION_E) {
                if (*type == '"') {
                    type = strchr(type + 1, '"');
                    if (type) {
                        type++;
                    }
                }
                itemSize = objc_sizeof_type(type);
                if (itemSize == -1) {
                    return -1;
                }
                max_size = MAX(max_size, itemSize);
                type = objc_skip_type_specifier(type, YES);
            }
            return max_size;
        }

        case _C_CONST:
        case _C_IN:
        case _C_INOUT:
        case _C_OUT:
        case _C_BYCOPY:
        case _C_ONEWAY:
            return objc_sizeof_type(type + 1);

        case _C_BFLD: {
            long i = strtol(type + 1, NULL, 10);
            return (i + 7) / 8;
        } break;

        default:
            EbrDebugLog("objc_sizeof_type: Unhandled type '%#x', %s", *type, type);
            return -1;
    }
}

bool getTypeSize(char type, int* size) {
    switch (type) {
        case '@':
        case ':':
        case 'f':
        case 'i':
        case 'I':
        case '^':
        case '#':
            *size = 4;
            return true;

        case 'd':
        case 'Q':
        case 'q':
            *size = 8;
            return true;

        case 'c':
        case 'B':
        case 'C':
            *size = 1;
            return true;

        case 'v':
            *size = 0;
            return true;
    }

    return false;
}

int getArgumentSize(const char* type) {
    int size = objc_sizeof_type(type);
    assert(size != -1);
    return size;
}

@implementation NSInvocation : NSObject
static void* copyArgument(NSInvocation* self, void* buf, int index) {
    char* type = (char*)[self->_methodSignature getArgumentTypeAtIndex:index];

    int size = getArgumentSize(type);

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

    int size = getArgumentSize(type);
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
    int length = getArgumentSize(type);

    memcpy(buf, returnValue, length);
}

/**
 @Status Interoperable
*/
- (void)setReturnValue:(void*)buf {
    char* type = (char*)[_methodSignature methodReturnType];
    int length = getArgumentSize(type);

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
    int returnSize = getArgumentSize(type);
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

        int size = getArgumentSize(type);
        size = (size + 3) & ~3;
        totalLength += size;
    }

    unsigned stackParams[32];
    int stackParamsLen = 0;

    for (unsigned i = 0; i < numArgs; i++) {
        char* type = (char*)[_methodSignature getArgumentTypeAtIndex:i];

        int size = getArgumentSize(type);
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
