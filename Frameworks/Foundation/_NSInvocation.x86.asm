;******************************************************************************
;
; Copyright (c) Microsoft. All rights reserved.
;
; This code is licensed under the MIT License (MIT).
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
;
;******************************************************************************

.686P
.XMM
.MODEL FLAT

; A lot of the fallthrough logic and stack frame setup here is from libffi/x86/sysv.S

PUBLIC @_CallFrameInternal@8
PUBLIC __NSInvocation_ForwardingBridgeNoStret
PUBLIC __NSInvocation_ForwardingBridge

_TEXT SEGMENT
; FASTCALL: Arguments ECX, EDX are a struct x86call* and new stack pointer, respectively.
@_CallFrameInternal@8 PROC
    mov eax, [esp]
    mov [ecx], ebp
    mov [ecx + 4], eax
    mov [ecx + 8], ebx
    mov ebp, ecx ; new stack frame based on ecx (call)
    ; call+stack were allocated via alloca, as we are stealing our calling
    ; function's stack frame.
    ; layout: [args] [old ebp] [old return value] [ebx save] [rest of x86call]
    ;         ^ ESP  ^ EBP
    ; The stack pointer for the callee is set to the arg pack, and the 
    ; base pointer is set to the stack frame we set up.
    ; This keeps the debugger able to properly walk the stack.

    ; stackp is already in edx.
    mov esp, edx

    mov eax, [ebp + 24]
    call eax

    mov ecx, [ebp + 20] ; return out pointer
    mov ebx, [ebp + 12] ; return type
    jmp JUMPTABLE[ebx * 4]

_CASE_RETURN_TYPE_FLOAT:
    fstp DWORD PTR [ecx]
    jmp LOCAL_ret

_CASE_RETURN_TYPE_DOUBLE:
    fstp QWORD PTR [ecx]
    jmp LOCAL_ret

_CASE_RETURN_TYPE_SINT8:
    movsx eax, al
    mov [ecx], eax ; return length has been promoted
    jmp LOCAL_ret

_CASE_RETURN_TYPE_UINT8:
    movzx eax, al
    mov [ecx], eax ; return length has been promoted
    jmp LOCAL_ret

_CASE_RETURN_TYPE_SINT16:
    movsx eax, ax
    mov [ecx], eax ; return length has been promoted
    jmp LOCAL_ret

_CASE_RETURN_TYPE_UINT16:
    movzx eax, ax
    mov [ecx], eax ; return length has been promoted
    jmp LOCAL_ret

_CASE_RETURN_TYPE_INT64:
    mov [ecx + 4], edx
    ; Fall through to populate [ecx] from eax as well.
_CASE_RETURN_TYPE_POINTER: ; x86: these are the same width
_CASE_RETURN_TYPE_INT32:
    mov [ecx], eax
    jmp LOCAL_ret

_CASE_RETURN_TYPE_NONE:
_CASE_RETURN_TYPE_STRUCT:
    ; Only 1/2/3/4-byte structs can be returned in registers, but they
    ; have been handled by the return type generator.
LOCAL_ret:
    mov ebx, [ebp + 8] ; +8 = saved EBX
    mov esp, ebp
    pop ebp
    ret

JUMPTABLE:
    ; MUST BE KEPT IN THE ORDER FROM _NSInvocation.x86.mm
    DWORD _CASE_RETURN_TYPE_NONE
    DWORD _CASE_RETURN_TYPE_SINT8
    DWORD _CASE_RETURN_TYPE_UINT8
    DWORD _CASE_RETURN_TYPE_SINT16
    DWORD _CASE_RETURN_TYPE_UINT16
    DWORD _CASE_RETURN_TYPE_INT32
    DWORD _CASE_RETURN_TYPE_INT64
    DWORD _CASE_RETURN_TYPE_POINTER
    DWORD _CASE_RETURN_TYPE_FLOAT
    DWORD _CASE_RETURN_TYPE_DOUBLE
    DWORD _CASE_RETURN_TYPE_STRUCT

@_CallFrameInternal@8 ENDP

EXTERN __NSInvocation_ForwardFrame:NEAR

; Stret version.
__NSInvocation_ForwardingBridge PROC
    mov ecx, [esp + 4] ; stret to ecx
    mov edx, esp
    push ebp

    ; Save the incoming values off the old stack.
    add edx, 8 ; account for return pointer *and stret*

    jmp __NSInvocation_ForwardingBridge_Internal
__NSInvocation_ForwardingBridge ENDP

__NSInvocation_ForwardingBridgeNoStret PROC
    xor ecx, ecx
    mov edx, esp
    push ebp

    ; Save the incoming values off the old stack.
    add edx, 4 ; account for return pointer

    ; Fall through to the internal handler
    ; We expect this case to be more common, so we put it here.
__NSInvocation_ForwardingBridgeNoStret ENDP

__NSInvocation_ForwardingBridge_Internal PROC

    ; Switch the stack frame, allocate space for locals
    mov ebp, esp
    push ebx ; save ebx at the top of our frame
    sub esp, 8 ; sizeof(bridgedForwardInfo)
    mov ebx, esp

    push ebx ; bridgedForwardInfo

    test ecx, ecx
    jnz adjustForStret
    push edx ; frame
    jmp stretAdjusted

adjustForStret:
    sub edx, 4 ; stret must be part of frame
    push edx ; frame - 4
    add edx, 4

stretAdjusted:
    mov eax, [edx + 4]
    push eax ; sel

    mov eax, [edx]
    push eax ; self

    push ecx ; stret (can be nullptr)
    call __NSInvocation_ForwardFrame
    add esp, 20 ; args off the stack

    mov ecx, ebx
    mov ecx, [ebx] ; ecx = return value pointer
    mov ebx, [ebx + 4] ; ebx = return type
    jmp JUMPTABLE[ebx * 4]

_CASE_RETURN_TYPE_FLOAT:
    fld DWORD PTR [ecx]
    jmp LOCAL_ret

_CASE_RETURN_TYPE_DOUBLE:
    fld QWORD PTR [ecx]
    jmp LOCAL_ret

_CASE_RETURN_TYPE_SINT8:
    mov al, BYTE PTR [ecx]
    movsx eax, al
    jmp LOCAL_ret

_CASE_RETURN_TYPE_UINT8:
    mov al, BYTE PTR [ecx]
    movzx eax, al
    jmp LOCAL_ret

_CASE_RETURN_TYPE_SINT16:
    mov ax, WORD PTR [ecx]
    movsx eax, ax
    jmp LOCAL_ret

_CASE_RETURN_TYPE_UINT16:
    mov ax, WORD PTR [ecx]
    movzx eax, ax
    jmp LOCAL_ret

_CASE_RETURN_TYPE_INT64:
    mov edx, [ecx + 4]
    ; Fall through to populate eax from [ecx]
_CASE_RETURN_TYPE_POINTER: ; x86: these are the same width
_CASE_RETURN_TYPE_INT32:
    mov eax, [ecx]
    jmp LOCAL_ret

_CASE_RETURN_TYPE_NONE:
_CASE_RETURN_TYPE_STRUCT:
    ; struct was handled by ForwardFrame
LOCAL_ret:
    add esp, 8 ; struct off the stack
    pop ebx
    pop ebp
    ret

JUMPTABLE:
    ; MUST BE KEPT IN THE ORDER FROM _NSInvocation.x86.mm
    DWORD _CASE_RETURN_TYPE_NONE
    DWORD _CASE_RETURN_TYPE_SINT8
    DWORD _CASE_RETURN_TYPE_UINT8
    DWORD _CASE_RETURN_TYPE_SINT16
    DWORD _CASE_RETURN_TYPE_UINT16
    DWORD _CASE_RETURN_TYPE_INT32
    DWORD _CASE_RETURN_TYPE_INT64
    DWORD _CASE_RETURN_TYPE_POINTER
    DWORD _CASE_RETURN_TYPE_FLOAT
    DWORD _CASE_RETURN_TYPE_DOUBLE
    DWORD _CASE_RETURN_TYPE_STRUCT

__NSInvocation_ForwardingBridge_Internal ENDP

_TEXT ENDS
END
