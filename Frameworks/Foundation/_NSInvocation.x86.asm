.686P
.XMM
.MODEL FLAT

PUBLIC @_CallFrameInternal@8

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
    shl ebx, 2
    add ebx, JUMPTABLE
    mov ebx, [ebx]
    jmp ebx

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

LOCAL_ret:
    mov ebx, [ebp + 8] ; +8 = saved EBX
    mov esp, ebp
    pop ebp
    ret

_CASE_RETURN_TYPE_STRUCT:
    ; ebx got us in here, we can stomp it now
    mov ebx, [ebp + 16] ; +16 = returnLength
    cmp ebx, 8 ; Only 8, 4, 2, 1 length structs can be returned in registers
    jg LOCAL_ret
    je _CASE_RETURN_TYPE_INT64
    cmp ebx, 4
    je _CASE_RETURN_TYPE_INT32
    cmp ebx, 2
    je _CASE_RETURN_TYPE_UINT16
    cmp ebx, 1
    je _CASE_RETURN_TYPE_UINT8
    ; everything else has already been handled by stret out; unwind
    jmp LOCAL_ret

JUMPTABLE:
    ; MUST BE KEPT IN THE ORDER FROM FrameAllocator.h
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
_TEXT ENDS
END
