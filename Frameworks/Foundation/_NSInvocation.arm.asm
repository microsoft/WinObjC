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

#include <kxarm.h>

    AREA |.text|,ALIGN=4,THUMB,CODE,READONLY
; r0 = arena start
; r1 = frame
; r2 = fn
; r3 = vfp count
    ALIGN
|_CallFrameInternal_VFP| PROC
    GLOBAL _CallFrameInternal_VFP
    GLOBAL _CallFrameInternal
    CMP r3, 1
    BNE %F0
    VLDR.64 d0, [r0]
    B %F1

0
    VLDM.64 r0, {d0-d7}

1
    ADD r0, r0, #64
    ; Fall through to non-VFP case
|_CallFrameInternal_VFP| ENDP
|_CallFrameInternal| PROC
    STM r1, {fp, lr}
    MOV fp, r1

    MOV sp, r0
    MOV lr, r2
    MOV ip, #0
    LDMIA sp!, {r0-r3}
    BLX lr

    LDR r2, [fp, #8] ; return pointer
    LDR r3, [fp, #12] ; return type
    MOV sp, fp

    ADR ip, %F101
    TBB [ip, r3]

100
111 ; VFP_F
    VSTR s0, [r2]
    POP {fp, pc}
112 ; VFP_D
    VSTR d0, [r2]
    POP {fp, pc}
113 ; VFP_HOMOGENOUS
    VSTM r2, {d0-d3}
    POP {fp, pc}

115 ; INT64
    STR r1, [r2, #4]
    ;; fall through
114 ; INT32
    STR r0, [r2]
    ;; fall through

116 ; STRUCT
110 ; NONE
    POP {fp, pc}

101 ; Must be kept in the order from _NSInvocation.arm.mm
    DCB (%B110-%B100)/2 ; RETURN_TYPE_NONE
    DCB (%B111-%B100)/2 ; RETURN_TYPE_VFP_S
    DCB (%B112-%B100)/2 ; RETURN_TYPE_VFP_D
    DCB (%B113-%B100)/2 ; RETURN_TYPE_VFP_HOMOGENOUS
    DCB (%B114-%B100)/2 ; RETURN_TYPE_INT
    DCB (%B115-%B100)/2 ; RETURN_TYPE_INT64
    DCB (%B116-%B100)/2 ; RETURN_TYPE_STRUCT
|_CallFrameInternal| ENDP

    EXTERN _NSInvocation_ForwardFrame

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; _NSInvocation_ForwardingBridge(void* stret, id self, SEL _cmd, ...)
    ; Second entrypoint to this function; called when there is a struct return pointer.
    ; r0 = struct return pointer
    ; r1 = self
    ; r2 = _cmd
    NESTED_ENTRY _NSInvocation_ForwardingBridge
    PROLOG_PUSH {r0-r3}
    PROLOG_VPUSH {d0-d7}
    PROLOG_NOP mov r3, sp
    PROLOG_PUSH {r4, r11, lr}
    PROLOG_STACK_ALLOC 12

    ADD fp, sp, #16
    ADD r4, sp, #4
    STR r4, [sp]
    BLX _NSInvocation_ForwardFrame ; (stret, self, sel, frame, bridgeInfo)

    ; We don't need to derive the return value here: it was already handled by the struct return pointer.

    EPILOG_STACK_FREE 12
    EPILOG_POP {r4, r11, lr}
    EPILOG_STACK_FREE 0x50
    EPILOG_RETURN
    NESTED_END

    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ; _NSInvocation_ForwardingBridgeNoStret(id self, SEL _cmd, ...)
    ; r0 = self
    ; r1 = _cmd
    ; Saves the first four registers and the VFP argument registers in the ARM call frame format
    ; expected by NSInvocation. Shifts r0 and r1 up to r1 and r2 to make space for the struct return
    ; parameter. r0 is filled with nullptr, as there is no struct return.
    NESTED_ENTRY _NSInvocation_ForwardingBridgeNoStret
    PROLOG_PUSH {r0-r3}
    PROLOG_VPUSH {d0-d7}
    PROLOG_NOP mov r3, sp
    PROLOG_PUSH {r4, r11, lr}
    PROLOG_STACK_ALLOC 12

    MOV r2, r1 ; sel
    MOV r1, r0 ; self
    MOVS r0, #0 ; stret

    ADD fp, sp, #16
    ADD r4, sp, #4
    STR r4, [sp]
    BLX _NSInvocation_ForwardFrame ; (stret, self, sel, frame, bridgeInfo)

    LDR r1, [r4, #4] ; return type
    LDR r0, [r4, #0] ; return pointer

    EPILOG_STACK_FREE 12
    EPILOG_POP {r4, r11, lr}
    EPILOG_STACK_FREE 0x50

    ADR ip, %F101
    TBB [ip, r1]

100
111 ; VFP_F
    VLDR s0, [r0]
    BX lr
112 ; VFP_D
    VLDR d0, [r0]
    BX lr
113 ; VFP_HOMOGENOUS
    VLDM r0, {d0-d3}
    BX lr

115 ; INT64
    LDR r1, [r0, #4]
    ;; fall through
114 ; INT32
    LDR r0, [r0]
    ;; fall through

116 ; STRUCT
110 ; NONE
    BX lr

101 ; Must be kept in the order from _NSInvocation.arm.mm
    DCB (%B110-%B100)/2 ; RETURN_TYPE_NONE
    DCB (%B111-%B100)/2 ; RETURN_TYPE_VFP_S
    DCB (%B112-%B100)/2 ; RETURN_TYPE_VFP_D
    DCB (%B113-%B100)/2 ; RETURN_TYPE_VFP_HOMOGENOUS
    DCB (%B114-%B100)/2 ; RETURN_TYPE_INT
    DCB (%B115-%B100)/2 ; RETURN_TYPE_INT64
    DCB (%B116-%B100)/2 ; RETURN_TYPE_STRUCT

    NESTED_END

    END