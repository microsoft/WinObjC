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

#import <cstddef>

struct _NSInvocationAllocationExtent {
    std::ptrdiff_t offset;
    size_t length;
};

#define NSINVOCATION_ALIGN(n, alignment) ((n + (alignment - 1)) & ~(alignment - 1))

#if _M_IX86
extern "C" __declspec(naked) void __fastcall _CallFrameInternal(struct x86Frame* call, void* stackBuffer);
#include "_NSInvocation.x86.h"
#elif _M_ARM
extern "C" __declspec(naked) void _CallFrameInternal_VFP(void* arena, struct armFrame* frame, void* fp, unsigned int fpUsed);
extern "C" __declspec(naked) void _CallFrameInternal(void* arena, struct armFrame* frame, void* fp);
#include "_NSInvocation.arm.h"
#endif