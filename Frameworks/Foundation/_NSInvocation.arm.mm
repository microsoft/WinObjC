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

#import <cstdint>
#import <bitset>
#import <vector>
#import <algorithm>

constexpr size_t GPR_COUNT = 4;
constexpr size_t g_gprLength = GPR_COUNT * sizeof(uintptr_t); // 4 GPRs;
constexpr size_t SPFR_COUNT = 16;
constexpr size_t g_sfprLength = SPFR_COUNT * sizeof(float); // 16 single-precision float registers

enum _arm_return_type {
    ARM_NONE,
    ARM_VFP_S,
    ARM_VFP_D,
    ARM_VFP_HOMOGENOUS,
    ARM_INT,
    ARM_INT64,
    ARM_STRUCT,
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

static _arm_return_type _getReturnType(const char* typeEncoding) {
    switch (typeEncoding[0]) {
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
            return ARM_INT;
        case _C_LNG_LNG:
        case _C_ULNG_LNG:
            return ARM_INT64;
        case _C_STRUCT_B: {
            const char* typeEncodingPtr = typeEncoding;
            size_t size = objc_sizeof_type(typeEncoding);
            char type = uniformTypeFromStructSpecifier(&typeEncodingPtr);

            if (type == _C_FLT && size <= sizeof(float) * 4) {
                return ARM_VFP_HOMOGENOUS;
            }

            if (type == _C_DBL && size <= sizeof(double) * 4) {
                return ARM_VFP_HOMOGENOUS;
            }

            if (size <= 4) {
                return ARM_INT;
            }

            return ARM_STRUCT;
        }
        case _C_FLT:
            return ARM_VFP_S;
        case _C_DBL:
            return ARM_VFP_D;
        case _C_VOID:
            return ARM_NONE;
    }
    return ARM_NONE;
}

struct _NSInvocationCallFrame::impl {
    StrongId<NSMethodSignature> _methodSignature;

    uint8_t* _buffer;
    size_t _length;
    _arm_return_type _returnType;
    size_t _returnLength;

    /* views into _buffer */
    uint8_t* stack;
    uintptr_t* registers;
    float* singleRegisters;
    double* doubleRegisters;

    std::bitset<GPR_COUNT> gprUsage;
    std::bitset<SPFR_COUNT> spUsage;
    unsigned int stackBytes;

    bool _stret;
    allocation_extent _stretExtent;

    std::vector<allocation_extent> _allocationExtents;

    impl(NSMethodSignature* methodSignature)
        : _methodSignature(methodSignature),
          gprUsage(0),
          spUsage(0),
          stackBytes(0),
          _stret(false),
          _allocationExtents([methodSignature numberOfArguments]) {
        auto nArguments = [_methodSignature numberOfArguments];
        _length = 0;
        for (int i = 0; i < nArguments; ++i) {
            // Some arguments are <4 bytes, but we need to make sure that we only allocate in register-width chunks.
            _length += std::max(sizeof(uintptr_t), objc_aligned_size([_methodSignature getArgumentTypeAtIndex:i]));
        }

        _length += g_sfprLength + g_gprLength;

        _returnType = _getReturnType([_methodSignature methodReturnType]);

        _returnLength = [_methodSignature methodReturnLength];

        if (_returnType == ARM_STRUCT) {
            _stret = true;
            _length += sizeof(void*);
        } else if (_returnType == ARM_VFP_HOMOGENOUS) {
            // Promote all homogenous vfp returns to the size of all four double-width registers
            _returnLength = std::max(sizeof(double) * 4, _returnLength);
        } else if (_returnType == ARM_NONE) {
            // Do nothing; there's no point in allocating for this.
        } else {
            // Promote all non-stret return lengths to one machine word.
            _returnLength = std::max(sizeof(uintptr_t), _returnLength);
        }

        _buffer = new uint8_t[_length];

        stack = _buffer + g_sfprLength + g_gprLength;
        registers = reinterpret_cast<uintptr_t*>(_buffer + g_sfprLength);
        singleRegisters = reinterpret_cast<float*>(_buffer);
        doubleRegisters = reinterpret_cast<double*>(singleRegisters);

        if (_stret) {
            _stretExtent = _allocateArgument("^v");
        }

        for (int i = 0; i < nArguments; ++i) {
            _allocationExtents[i] = std::move(_allocateArgument([_methodSignature getArgumentTypeAtIndex:i]));
        }
    }

    void _alignStack(size_t alignment = 0) {
        if (alignment) {
            stackBytes = NSINVOCATION_ALIGN(stackBytes, alignment);
        }
    }

    allocation_extent _allocateStackWords(size_t count, size_t alignment = alignof(uintptr_t)) {
        stackBytes = NSINVOCATION_ALIGN(stackBytes, alignment);
        allocation_extent extent{ stack + stackBytes, count * sizeof(uintptr_t) };
        stackBytes += extent.length;

        return extent;
    }

    allocation_extent _allocateMachineWords(unsigned int count, size_t alignment = alignof(uintptr_t)) {
        // ARM: Many cases.
        // 1. #words < 4*remaining_reg = all in registers (consecutive)
        // 2. #words > 4*remaining_reg =
        //   2a. Stack is UNUSED: fill registers where they will fit, then move to stack
        //       Our allocator is great at this: they're laid out side-by-side.
        //   2b. Stack is USED: put the entire batch onto the stack, and mark every register as used.
        // Since we lay out regs right before stack, this will always be a single extent (!)
        auto nreg = 0;
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
            uintptr_t* start = &registers[nreg];
            auto unallocatedWords = count;
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

    allocation_extent _allocateFloats(size_t count) {
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
            allocation_extent extent{ &singleRegisters[nreg], count * sizeof(float) };
            for (size_t i = 0; i < count; ++i) {
                spUsage[nreg] = 1;
                ++nreg;
            }
            return extent;
        }
    }

    allocation_extent _allocateDoubles(size_t count) {
        auto nreg = firstUnused(spUsage);
        if (nreg % 2 == 1) {
            ++nreg; // doubles take up even-numbered single-precision registers.
        }
        // If this double-precision argument would not fit in the float registers,
        // Calling Convention dictates we disable the remaining float registers.
        if (nreg + (count * 2) > SPFR_COUNT) {
            spUsage.set(); // All FP regs are now used.
            return _allocateStackWords((count * sizeof(double)) / sizeof(uintptr_t), alignof(double));
        } else {
            allocation_extent extent{ &doubleRegisters[nreg / 2], count * sizeof(double) };
            for (size_t i = 0; i < count; ++i) {
                spUsage[nreg] = 1; // A single double in a double register marks two single registers as used.
                spUsage[nreg + 1] = 1;
                nreg += 2;
            }
            return extent;
        }
    }

    allocation_extent _allocateArgument(const char* typeEncoding) {
        switch (typeEncoding[0]) {
            // All integral types < qword are promoted.
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
        return { nullptr, 0 };
    }

    void storeArgument(const void* value, unsigned int index) {
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

        memcpy(extent.location, value, size);
    }

    void loadArgument(void* value, unsigned int index) const {
        auto& extent = _allocationExtents[index];
        const char* type = [_methodSignature getArgumentTypeAtIndex:index];
        size_t size = objc_sizeof_type(type);
        memcpy(value, extent.location, size);
    }
};

_NSInvocationCallFrame::_NSInvocationCallFrame(NSMethodSignature* methodSignature)
    : _impl(new _NSInvocationCallFrame::impl(methodSignature)) {
}

_NSInvocationCallFrame::~_NSInvocationCallFrame() {
    delete _impl;
}

void _NSInvocationCallFrame::storeArgument(const void* value, unsigned int index) {
    _impl->storeArgument(value, index);
}

void _NSInvocationCallFrame::loadArgument(void* value, unsigned int index) const {
    _impl->loadArgument(value, index);
}

size_t _NSInvocationCallFrame::getReturnLength() const {
    return _impl->_returnLength;
}

bool _NSInvocationCallFrame::getRequiresStructReturn() const {
    return _impl->_stret;
}

struct armFrame {
    /* Populated by stm r1, {fp, lr} */
    void* savedFramePointer;
    void* savedLinkRegister;

    void* returnValue;
    _arm_return_type returnType;
};

void _NSInvocationCallFrame::execute(void* functionPointer, void* returnValuePointer) const {
    if (_impl->_stret) {
        // populate stret out if necessary.
        memcpy(_impl->_stretExtent.location, &returnValuePointer, _impl->_stretExtent.length);
    }

    // alloca is guaranteed to give us a 16-byte aligned return.
    auto frameLength = _impl->_length;
    auto promotedFrameLength = NSINVOCATION_ALIGN(frameLength, alignof(struct armFrame));

    uint8_t* arena = (uint8_t*)_alloca(promotedFrameLength + sizeof(struct armFrame));
    armFrame* frame = (armFrame*)(arena + promotedFrameLength);

    memcpy(arena, _impl->_buffer, frameLength);

    frame->returnValue = returnValuePointer;
    frame->returnType = _impl->_returnType;

    unsigned int fpCount = _impl->spUsage.count();
    if (fpCount > 0) {
        _CallFrameInternal_VFP(arena, frame, functionPointer, (fpCount + 1) / 2 /* ceil */);
    } else {
        // If we didn't use the floating-point registers at all, we can skip 64 bytes
        // of register reads and go straight to the r0-3 + stack case.
        _CallFrameInternal(arena + g_sfprLength, frame, functionPointer);
    }
}