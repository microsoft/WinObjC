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

#import <Starboard/SmartTypes.h>
#import <objc/runtime.h>
#import <objc/encoding.h>

constexpr size_t g_gprLength = GPR_COUNT * sizeof(uintptr_t); // 4 GPRs;
constexpr size_t g_sfprLength = SPFR_COUNT * sizeof(float); // 16 single-precision float registers

enum return_type {
    RETURN_TYPE_NONE,
    RETURN_TYPE_VFP_S,
    RETURN_TYPE_VFP_D,
    RETURN_TYPE_VFP_HOMOGENOUS,
    RETURN_TYPE_INT,
    RETURN_TYPE_INT64,
    RETURN_TYPE_STRUCT,
};

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

template <unsigned N>
static size_t firstUnused(const std::bitset<N>& bitset, size_t start = 0) {
    for (int i = start; i < N; ++i) {
        if (!bitset.test(i)) {
            return i;
        }
    }
    return N;
}

static return_type _getReturnType(const char* typeEncoding) {
    switch (typeEncoding[0]) {
        case _C_BOOL:
        case _C_CHR:
        case _C_SHT:
        case _C_UCHR:
        case _C_USHT:
        case _C_INT:
        case _C_LNG:
        case _C_UINT:
        case _C_ULNG:
        case _C_ID:
        case _C_CLASS:
        case _C_PTR:
        case _C_SEL:
        case _C_CHARPTR:
            return RETURN_TYPE_INT;
        case _C_LNG_LNG:
        case _C_ULNG_LNG:
            return RETURN_TYPE_INT64;
        case _C_STRUCT_B: {
            const char* typeEncodingPtr = typeEncoding;
            size_t size = objc_sizeof_type(typeEncoding);
            char type = uniformTypeFromStructSpecifier(&typeEncodingPtr);

            if (type == _C_FLT && size <= sizeof(float) * 4) {
                return RETURN_TYPE_VFP_HOMOGENOUS;
            }

            if (type == _C_DBL && size <= sizeof(double) * 4) {
                return RETURN_TYPE_VFP_HOMOGENOUS;
            }

            if (size <= 4) {
                return RETURN_TYPE_INT;
            }

            return RETURN_TYPE_STRUCT;
        }
        case _C_FLT:
            return RETURN_TYPE_VFP_S;
        case _C_DBL:
            return RETURN_TYPE_VFP_D;
        case _C_VOID:
            return RETURN_TYPE_NONE;
    }
    return RETURN_TYPE_NONE;
}

_NSInvocationCallFrame::_NSInvocationCallFrame(NSMethodSignature* methodSignature)
    : _methodSignature(methodSignature),
      gprUsage(0),
      spUsage(0),
      stackBytes(0),
      _structReturn(false),
      _allocationExtents([methodSignature numberOfArguments]) {
    _returnType = _getReturnType([_methodSignature methodReturnType]);

    _returnLength = [_methodSignature methodReturnLength];

    if (_returnType == RETURN_TYPE_STRUCT) {
        _structReturn = true;
        _structReturnExtent = _allocateArgument("^v");
    } else if (_returnType == RETURN_TYPE_VFP_HOMOGENOUS) {
        // Promote all homogenous vfp returns to the size of all four double-width registers
        _returnLength = std::max(sizeof(double) * 4, _returnLength);
    } else if (_returnType != RETURN_TYPE_NONE) {
        // Promote all non-stret return lengths to one machine word.
        _returnLength = std::max(sizeof(uintptr_t), _returnLength);
    }

    size_t length = 0;

    unsigned int nArguments = [_methodSignature numberOfArguments];
    for (unsigned int i = 0; i < nArguments; ++i) {
        // Some arguments are <4 bytes, but we need to make sure that we only allocate in register-width chunks.
        auto& extent = _allocationExtents[i] = std::move(_allocateArgument([_methodSignature getArgumentTypeAtIndex:i]));
        if (length < extent.offset + extent.length) {
            length = extent.offset + extent.length;
        }
    }

    // Because of how _CallFrame_Internal loads the registers, we
    // always allocate enough space for them.
    length = std::max(length, g_gprLength + g_sfprLength);

    _length = length;
    _buffer = static_cast<uint8_t*>(IwCalloc(length, 1));
}

_NSInvocationCallFrame::~_NSInvocationCallFrame() {
    IwFree(_buffer);
}

_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateStackWords(size_t count, size_t alignment) {
    stackBytes = NSINVOCATION_ALIGN(stackBytes, alignment);
    _NSInvocationAllocationExtent extent{ g_sfprLength + g_gprLength + stackBytes, count * sizeof(uintptr_t) };
    stackBytes += extent.length;

    return extent;
}

_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateMachineWords(unsigned int count, size_t alignment) {
    // ARM: Many cases.
    // 1. #words < 4*remaining_reg = all in registers (consecutive)
    // 2. #words > 4*remaining_reg =
    //   2a. Stack is UNUSED: fill registers where they will fit, then move to stack
    //       Our allocator is great at this: they're laid out side-by-side.
    //   2b. Stack is USED: put the entire batch onto the stack, and mark every register as used.
    // Since we lay out regs right before stack, this will always be a single extent (!)
    unsigned int nreg = 0;
redo:
    nreg = firstUnused(gprUsage);
    if (nreg >= GPR_COUNT || (nreg + count >= GPR_COUNT && stackBytes != 0)) {
        // Case 2b.
        gprUsage.set();
        return _allocateStackWords(count, alignment);
    } else {
        if (alignment == alignof(uint64_t) && nreg % 2 == 1) {
            // If we need 8b alignment, discard this register and move on to the next.
            gprUsage[nreg] = 1;
            goto redo;
        }

        // Case 1.
        std::ptrdiff_t start = g_sfprLength + (nreg * sizeof(uintptr_t));
        unsigned int unallocatedWords = count;
        for (; unallocatedWords > 0 && nreg < GPR_COUNT; ++nreg) {
            gprUsage[nreg] = 1;
            unallocatedWords--;
        }
        if (unallocatedWords == 0) {
            // It all fit in registers.
            return { start, sizeof(uintptr_t) * count };
        }

        // Case 2b. Remaining words spilled onto stack.
        stackBytes += sizeof(uintptr_t) * unallocatedWords;
        return { start, sizeof(uintptr_t) * count };
    }
}

_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateFloats(size_t count) {
    size_t nreg = 0;
redo:
    nreg = firstUnused(spUsage, nreg);
    if (nreg + count > SPFR_COUNT) {
        spUsage.set(); // All FP registers are now used.
        return _allocateStackWords((count * sizeof(float)) / sizeof(uintptr_t), alignof(float));
    } else {
        for (size_t i = 0; i < count; ++i) {
            // if we're serializing multiple floats, they must be contiguous
            if (spUsage.test(nreg + i)) {
                ++nreg;
                goto redo;
            }
        }
        _NSInvocationAllocationExtent extent{ nreg * sizeof(float), count * sizeof(float) };
        for (size_t i = 0; i < count; ++i) {
            spUsage[nreg] = 1;
            ++nreg;
        }
        return extent;
    }
}

_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateDoubles(size_t count) {
    unsigned int nreg = firstUnused(spUsage);
    if (nreg % 2 == 1) {
        ++nreg; // doubles take up even-numbered single-precision registers.
    }
    // If this double-precision argument would not fit in the float registers,
    // Calling Convention dictates we disable the remaining float registers.
    if (nreg + (count * 2) > SPFR_COUNT) {
        spUsage.set(); // All FP regs are now used.
        return _allocateStackWords((count * sizeof(double)) / sizeof(uintptr_t), alignof(double));
    } else {
        _NSInvocationAllocationExtent extent{ (nreg / 2) * sizeof(double), count * sizeof(double) };
        for (size_t i = 0; i < count; ++i) {
            spUsage[nreg] = 1; // A single double in a double register marks two single registers as used.
            spUsage[nreg + 1] = 1;
            nreg += 2;
        }
        return extent;
    }
}

_NSInvocationAllocationExtent _NSInvocationCallFrame::_allocateArgument(const char* typeEncoding) {
    switch (typeEncoding[0]) {
        // All integral types < qword are promoted.
        case _C_BOOL:
        case _C_UCHR:
        case _C_USHT:
        case _C_UINT:
        case _C_ULNG:
        case _C_CHR:
        case _C_SHT:
        case _C_INT:
        case _C_LNG:
        case _C_PTR:
        case _C_CHARPTR:
        case _C_CLASS:
        case _C_ID:
        case _C_SEL:
            return _allocateMachineWords(1);
        case _C_LNG_LNG:
        case _C_ULNG_LNG: {
            return _allocateMachineWords(2, alignof(uint64_t));
        }
        case _C_FLT:
            return _allocateFloats(1);
            break;
        case _C_DBL:
            return _allocateDoubles(1);
            break;
        case _C_STRUCT_B: {
            size_t size = std::max(sizeof(uintptr_t), objc_aligned_size(typeEncoding));
            size_t nWords = size / sizeof(uintptr_t);

            const char* te = typeEncoding;
            char t = uniformTypeFromStructSpecifier(&te);
            if (t == _C_DBL && size <= sizeof(double) * 4) {
                return _allocateDoubles(size / sizeof(double));
            } else if (t == _C_FLT && size <= sizeof(float) * 4) {
                return _allocateFloats(size / sizeof(float));
            }

            return _allocateMachineWords(nWords);
        }
    }
    return { -1, 0 };
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
    // On x86, we can copy the frame as-is; for ARM we have to only copy the allocated portions.
    uint8_t* base = _buffer;
    for(auto& extent: _allocationExtents) {
        memcpy(base + extent.offset, (uint8_t*)frame + extent.offset, extent.length);
    }
}

unsigned int _NSInvocationCallFrame::getOpaquePlatformReturnType() const {
    return _returnType;
}

struct armFrame {
    /* Populated by stm r1, {fp, lr} */
    void* savedFramePointer;
    void* savedLinkRegister;

    void* returnValue;
    unsigned int returnType;
};

void _NSInvocationCallFrame::execute(void* functionPointer, void* returnValuePointer) const {
    // alloca is guaranteed to give us a 16-byte aligned return.
    size_t frameLength = _length;
    size_t promotedFrameLength = NSINVOCATION_ALIGN(frameLength, alignof(struct armFrame));

    uint8_t* arena = (uint8_t*)_alloca(promotedFrameLength + sizeof(struct armFrame));
    armFrame* frame = (armFrame*)(arena + promotedFrameLength);

    memcpy(arena, _buffer, frameLength);

    if (_structReturn) {
        // populate stret out if necessary. we only do this on the local copy.
        memcpy(arena + _structReturnExtent.offset, &returnValuePointer, _structReturnExtent.length);
    }

    frame->returnValue = returnValuePointer;
    frame->returnType = _returnType;

    unsigned int fpCount = spUsage.count();
    if (fpCount > 0) {
        _CallFrameInternal_VFP(arena, frame, functionPointer, (fpCount + 1) / 2 /* ceil */);
    } else {
        // If we didn't use the floating-point registers at all, we can skip 64 bytes
        // of register reads and go straight to the r0-3 + stack case.
        _CallFrameInternal(arena + g_sfprLength, frame, functionPointer);
    }
}

extern "C" bool _NSInvocationTypeEncodingMandatesStructReturn(const char* typeEncoding) {
    return _getReturnType(typeEncoding) == RETURN_TYPE_STRUCT;
}
