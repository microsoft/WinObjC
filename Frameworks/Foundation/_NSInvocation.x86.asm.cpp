//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "FrameAllocator.h"
// Pushing the return struct pointer onto the stack is handled by the frame allocator user.
extern "C" __declspec(naked) void __fastcall _CallFrameInternal(struct x86call* call, void* stackBuffer) {
	__asm {
		//mov ebx, ebpp
		//mob [ebx], ebp
		// libffi layout of frame: old ebp, old ret
		mov eax, [esp]
		mov [ecx], ebp
		mov [ecx+4], eax
		mov [ecx+8], ebx
		mov ebp, ecx // new stack frame based on ecx (call)

		// stackp is already in edx.
		mov esp, edx

		mov eax, [ebp + 20]
		call eax

		mov ebx, [ebp + 12] // return type
		SWITCH ebx
		CASE RETURN_TYPE_SINT8
		ENDSW
		mov ebx, [ebp + 12]
		cmp ebx, 0
		jz LOCAL_ret
		cmp ebx, 8
		jg LOCAL_ret  // any return length over 8 has been handled by the stret out pointer

smallStructOrPod:
		mov ebx, [ebp + 16] // Integral/POD falls into here; 4 bytes is in eax, 8 bytes is in eax+edx
		mov [ebx], eax
		mov eax, [ebp + 12]
		cmp eax, 4
		jle LOCAL_ret
		mov [ebx+4], edx


LOCAL_ret:
		mov ebx, [ebp + 8]
		mov esp, ebp
		pop ebp
		ret


#if 0
		mov edx, stackBuffer
		mov ebp, esp
		mov ebx, esp
		mov esp, edx

		mov eax, funp
		call eax
		mov esp, ebx // callee-saved, this is valid after call.

		mov ebx, retlen
		cmp ebx, 0
		jz done
		cmp ebx, 8
		jg done  // any return length over 8 has been handled by the stret out pointer

smallStructOrPod:
		mov ebx, retp // Integral/POD falls into here; 4 bytes is in eax, 8 bytes is in eax+edx
		mov [ebx], eax
		mov eax, retlen
		cmp eax, 4
		jle done
		mov [ebx+4], edx
done:
#endif
	}
}
