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

#pragma once

#import <Starboard/SmartTypes.h>
#import <Foundation/NSMethodSignature.h>

#import <cstdint>
#import <bitset>
#import <vector>
#import <algorithm>

constexpr size_t GPR_COUNT = 4;
constexpr size_t SPFR_COUNT = 16;

// It is a _NSInvocationCallFrame's job to carve out allocation extents from a buffer.
class _NSInvocationCallFrame {
private:
    // Reference guaranteed owned by NSInvocation
    NSMethodSignature* _methodSignature;

    uint8_t* _buffer;
    size_t _length;
    size_t _returnLength;
    unsigned int _returnType;

    std::bitset<GPR_COUNT> gprUsage;
    std::bitset<SPFR_COUNT> spUsage;
    unsigned int stackBytes;

    bool _structReturn;
    _NSInvocationAllocationExtent _structReturnExtent;

    std::vector<_NSInvocationAllocationExtent> _allocationExtents;

    _NSInvocationAllocationExtent _allocateStackWords(size_t count, size_t alignment = alignof(uintptr_t));
    _NSInvocationAllocationExtent _allocateMachineWords(unsigned int count, size_t alignment = alignof(uintptr_t));
    _NSInvocationAllocationExtent _allocateFloats(size_t count);
    _NSInvocationAllocationExtent _allocateDoubles(size_t count);
    _NSInvocationAllocationExtent _allocateArgument(const char* typeEncoding);

public:
    _NSInvocationCallFrame(NSMethodSignature* methodTypeEncoding);
    ~_NSInvocationCallFrame();

    void storeArgument(const void* value, unsigned int index);
    void loadArgument(void* value, unsigned int index) const;
    void copyInExistingFrame(void* frame);

    size_t getReturnLength() const;
    unsigned int getOpaquePlatformReturnType() const;
    bool getRequiresStructReturn() const;

    void execute(void*, void*) const;
};
