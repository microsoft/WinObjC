//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "NSInvocationInternal.h"

#import <objc/runtime.h>
#import <objc/encoding.h>

enum return_type {
    RETURN_TYPE_NONE,
    RETURN_TYPE_SINT8,
    RETURN_TYPE_UINT8,
    RETURN_TYPE_SINT16,
    RETURN_TYPE_UINT16,
    RETURN_TYPE_INT32, // Only one: no need to sign-extend
    RETURN_TYPE_INT64, // Only one: no need to sign-extend
    RETURN_TYPE_POINTER,
    RETURN_TYPE_FLOAT,
    RETURN_TYPE_DOUBLE,
    RETURN_TYPE_STRUCT,
};

struct x86Frame {
    void* ebp;
    void* retp;
    void* ebx;
    unsigned int rettype;
    size_t retlen;
    void* retvalp;
    void* funp;
};

static return_type _getReturnType(const char* typeEncoding) {
    switch (typeEncoding[0]) {
        case _C_CHR:
            return RETURN_TYPE_SINT8;
        case _C_SHT:
            return RETURN_TYPE_SINT16;
        case _C_UCHR:
            return RETURN_TYPE_UINT8;
        case _C_USHT:
            return RETURN_TYPE_UINT16;
        case _C_BOOL:
        // On Win32, due to Windows.h, BOOL is 4 bytes wide.
        // Fall through.
        case _C_INT:
        case _C_LNG:
        case _C_UINT:
        case _C_ULNG:
            return RETURN_TYPE_INT32;
        case _C_LNG_LNG:
        case _C_ULNG_LNG:
            return RETURN_TYPE_INT64;
        case _C_ID:
        case _C_CLASS:
        case _C_PTR:
        case _C_SEL:
        case _C_CHARPTR:
            return RETURN_TYPE_POINTER;
        case _C_STRUCT_B: {
            size_t size = objc_sizeof_type(typeEncoding);

            switch (size) {
                case 8:
                    return RETURN_TYPE_INT64;
                case 4:
                    return RETURN_TYPE_INT32;
                case 2:
                    return RETURN_TYPE_UINT16;
                case 1:
                    return RETURN_TYPE_UINT8;
                default:
                    return RETURN_TYPE_STRUCT;
            }
        }
        case _C_FLT:
            return RETURN_TYPE_FLOAT;
        case _C_DBL:
            return RETURN_TYPE_DOUBLE;
        case _C_VOID:
            return RETURN_TYPE_NONE;
    }
    return RETURN_TYPE_NONE;
}

_NSInvocationCallFrame::_NSInvocationCallFrame(NSMethodSignature* methodSignature)
    : _methodSignature(methodSignature), _offset(0), _structReturn(false), _allocationExtents([_methodSignature numberOfArguments]) {
    _returnType = _getReturnType([_methodSignature methodReturnType]);
    _returnLength = [_methodSignature methodReturnLength];

    // 1, 2, 4, and 8-byte structs are returned in registers.
    if (_returnType == RETURN_TYPE_STRUCT) {
        _structReturn = true;
        _structReturnExtent = _allocateArgument("^v");
    } else if (_returnType != RETURN_TYPE_NONE) {
        // Promote all non-stret return lengths to one machine word.
        _returnLength = std::max(sizeof(uintptr_t), _returnLength);
    }

    unsigned int nArguments = [_methodSignature numberOfArguments];
    for (unsigned int i = 0; i < nArguments; ++i) {
        _allocationExtents[i] = std::move(_allocateArgument([_methodSignature getArgumentTypeAtIndex:i]));
    }

    _buffer = static_cast<uint8_t*>(IwCalloc(_offset, 1));
};

_NSInvocationCallFrame::~_NSInvocationCallFrame() {
    IwFree(_buffer);
}

/* private */
_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateArgument(const char* objcTypeEncoding) {
    size_t nWords = std::max(1U, objc_aligned_size(objcTypeEncoding) / sizeof(uintptr_t));
    size_t length = nWords * sizeof(uintptr_t);

    _NSInvocationAllocationExtent extent{ _offset, length };
    _offset += length;
    return extent;
}

void _NSInvocationCallFrame::storeArgument(const void* value, unsigned int index) {
    auto& extent = _allocationExtents[index];
    const char* type = [_methodSignature getArgumentTypeAtIndex:index];
    size_t size = objc_sizeof_type(type);

    union {
        uintptr_t u;
        intptr_t i;
    } itou; // "i" to "u"

    { // integral arguments less than 4 bytes in width need sign- or zero-extension.
        switch (type[0]) {
            case _C_CHR:
                itou.i = *(signed char*)value;
                value = &itou.i;
                size = sizeof(intptr_t);
                break;
            case _C_SHT:
                itou.i = *(signed short*)value;
                value = &itou.i;
                size = sizeof(intptr_t);
                break;
            case _C_UCHR:
                itou.u = *(unsigned char*)value;
                value = &itou.u;
                size = sizeof(uintptr_t);
                break;
            case _C_USHT:
                itou.u = *(unsigned short*)value;
                value = &itou.u;
                size = sizeof(uintptr_t);
                break;
            default:
                // leave value/size alone; no extension required.
                break;
        }
    }

    memcpy(_buffer + extent.offset, value, size);
}

void _NSInvocationCallFrame::loadArgument(void* value, unsigned int index) const {
    auto& extent = _allocationExtents[index];
    const char* type = [_methodSignature getArgumentTypeAtIndex:index];
    size_t size = objc_sizeof_type(type);
    memcpy(value, _buffer + extent.offset, size);
}

size_t _NSInvocationCallFrame::getReturnLength() const {
    return _returnLength;
}

bool _NSInvocationCallFrame::getRequiresStructReturn() const {
    return _structReturn;
}

void _NSInvocationCallFrame::copyInExistingFrame(void* frame) {
    memcpy(_buffer, frame, _offset);
}

unsigned int _NSInvocationCallFrame::getOpaquePlatformReturnType() const {
    return _returnType;
}

void _NSInvocationCallFrame::execute(void* functionPointer, void* returnValuePointer) const {
    size_t frameLength = _offset;

    // alloca is guaranteed to give us a 16-byte aligned return.
    uint8_t* stack = (uint8_t*)alloca(frameLength + sizeof(struct x86Frame));
    x86Frame* frame = (x86Frame*)(stack + frameLength);

    memcpy(stack, _buffer, frameLength);
    if (_structReturn) {
        // populate stret out if necessary. we only do this on the local copy.
        memcpy(stack + _structReturnExtent.offset, &returnValuePointer, _structReturnExtent.length);
    }

    *frame = { 0, 0, 0, _returnType, _returnLength, returnValuePointer, functionPointer };

    _CallFrameInternal(frame, stack);
}

extern "C" bool _NSInvocationTypeEncodingMandatesStructReturn(const char* typeEncoding) {
    return _getReturnType(typeEncoding) == RETURN_TYPE_STRUCT;
}