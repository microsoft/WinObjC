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
    GLOBAL _NSInvocation_ForwardingBridgeNoStret
    GLOBAL _NSInvocation_ForwardingBridge
    ROUT
    ALIGN
    ; r0 = self
    ; r1 = _cmd
    ; Saves the first four registers and the VFP argument registers in the ARM call frame format
    ; expected by NSInvocation. Shifts r0 and r1 up to r1 and r2 to make space for the struct return
    ; parameter. r0 is filled with nullptr, as there is no struct return.
|_NSInvocation_ForwardingBridgeNoStret|
    ;;; This code must match the layout of _NSInvocation_ForwardingBridgeNoStret.prolog.xdata below.
    ; The prolog is duplicated here so that the exception records can point to one contiguous (branch-free) block
    ; of instructions for virtual unwinding.
    PUSH {r0-r3}
    VSTMDB sp!, {d0-d7}
    MOV r3, sp
    PUSH {r4, fp, lr}
    SUB sp, sp, #12
|_NSInvocation_ForwardingBridgeNoStret.prolog.end|

    MOV r2, r1 ; sel
    MOV r1, r0 ; self
    MOV r0, #0 ; stret

    ; Skip to the body of _NSInvocation_ForwardingBridgeNoStret
    B %F0

    ; Second entrypoint to this function; called when there is a struct return pointer.
    ; r0 = struct return pointer
    ; r1 = self
    ; r2 = _cmd
|_NSInvocation_ForwardingBridge|
    ;;; This code must match the layout of _NSInvocation_ForwardingBridge.prolog.xdata below.
    PUSH {r0-r3}
    VSTMDB sp!, {d0-d7}
    MOV r3, sp
    PUSH {r4, fp, lr}
    SUB sp, sp, #12
|_NSInvocation_ForwardingBridge.prolog.end|

0
|_NSInvocation_ForwardingBridge.partial1.start|
    ADD fp, sp, #16
    ADD r4, sp, #4
    STR r4, [sp]
    BLX _NSInvocation_ForwardFrame ; (stret, self, sel, frame, bridgeInfo)

    LDR r3, [r4, #4] ; return type
    LDR r2, [r4, #0] ; return pointer

|_NSInvocation_ForwardingBridge.partial1.end|
|_NSInvocation_ForwardingBridge.epilog1.start|
    ;;; This code must match the layout of _NSInvocation_ForwardingBridge.epilog1.xdata below.
    ADD sp, sp, #12 ; Consume r4 + bridgeInfo
    POP {r4, fp, lr}
    ; Consume the stored GP and VFP registers
    ADD sp, sp, #0x50 ; 0x40 for VFP, 0x10 for GPR
|_NSInvocation_ForwardingBridge.epilog1.end|

    ADR ip, %F101
    TBB [ip, r3]

100
111 ; VFP_F
    VLDR s0, [r2]
    BX lr
112 ; VFP_D
    VLDR d0, [r2]
    BX lr
113 ; VFP_HOMOGENOUS
    VLDM r2, {d0-d3}
    BX lr

115 ; INT64
    LDR r1, [r2, #4]
    ;; fall through
114 ; INT32
    LDR r0, [r2]
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

    ;;; End of functions _NSInvocation_ForwardingBridge and _NSInvocation_ForwardingBridgeNoStret
    ;;; Beginning of unwind/exception data.

    ; .pdata and .xdata are laid out as described in ARM Exception Handling (https://msdn.microsoft.com/en-us/library/dn743843.aspx)
    ; Please refer to this document for a comprehensive look at ARM exception unwinding.

    AREA |.pdata|,ALIGN=4,DATA,READONLY
    ALIGN 4
    DCD |_NSInvocation_ForwardingBridgeNoStret|
    RELOC 2
    DCD |_NSInvocation_ForwardingBridgeNoStret.prolog.xdata|
    RELOC 2

    DCD |_NSInvocation_ForwardingBridge|
    RELOC 2
    DCD |_NSInvocation_ForwardingBridge.prolog.xdata|
    RELOC 2

    DCD |_NSInvocation_ForwardingBridge.partial1.start|
    RELOC 2
    DCD |_NSInvocation_ForwardingBridge.partial1.xdata|
    RELOC 2

    DCD |_NSInvocation_ForwardingBridge.epilog1.start|
    RELOC 2
    DCD |_NSInvocation_ForwardingBridge.epilog1.xdata|
    RELOC 2

    LTORG

    AREA |.xdata|,ALIGN=2,DATA,READONLY
    ROUT
    ALIGN 4
|_NSInvocation_ForwardingBridgeNoStret.prolog.xdata|
    ; Flags: F = E = X = 0
    ; #Epilogs = 0
    DCD (((%F1 - %F0) / 4):SHL:28) :OR: ((|_NSInvocation_ForwardingBridgeNoStret.prolog.end| - |_NSInvocation_ForwardingBridgeNoStret|) / 2)
0   ; Prolog unwind; must match layout of prolog (because F=0)!
    DCB 0x03                   ; ADD sp, sp, #12
    DCB 2_10101000, 2_00010000 ; POP {r4, r11, lr}
    DCB 0xFB                   ; 16-bit NOP (covers MOV r3, sp)
    DCB 2_11110101, 0x07       ; VPOP {d0-d7}
    DCB 2_11101100, 2_00001111 ; POP {r0-r3}
    DCB 0xFF                   ; END
    ALIGN 4
1
    LTORG

    ROUT
    ALIGN 4
|_NSInvocation_ForwardingBridge.prolog.xdata|
    ; Flags: F = E = X = 0
    ; #Epilogs = 0
    DCD (((%F1 - %F0) / 4):SHL:28) :OR: ((|_NSInvocation_ForwardingBridge.prolog.end| - |_NSInvocation_ForwardingBridge|) / 2)
0   ; Prolog unwind; must match layout of prolog (because F=0)!
    DCB 0x03                   ; ADD sp, sp, #12
    DCB 2_10101000, 2_00010000 ; POP {r4, r11, lr}
    DCB 0xFB                   ; 16-bit NOP (covers MOV r3, sp)
    DCB 2_11110101, 0x07       ; VPOP {d0-d7}
    DCB 2_11101100, 2_00001111 ; POP {r0-r3}
    DCB 0xFF                   ; END
    ALIGN 4
1
    LTORG

    ROUT
    ALIGN 4
|_NSInvocation_ForwardingBridge.partial1.xdata|
    ; Flags: F = 1, E = X = 0
    ;        F means partial function (no prolog.)
    ; #Epilogs = 0
    DCD (((%F1 - %F0) / 4):SHL:28) :OR: (1:SHL:22) :OR: ((|_NSInvocation_ForwardingBridge.partial1.end| - |_NSInvocation_ForwardingBridge.partial1.start|) / 2)
0   ; Unwind the prolog; does not need to match layout (because F=1).
    DCB 0x03                   ; ADD sp, sp, #12
    DCB 2_10101000, 2_00010000 ; POP {r4, r11, lr}
    DCB 0x14                   ; ADD sp, sp, #0x50
    DCB 0xFF                   ; END
    ALIGN 4
1
    LTORG

    ROUT
    ALIGN 4
|_NSInvocation_ForwardingBridge.epilog1.xdata|
    ; Flags: F = E = 1, X = 0
    ;        F means partial function (no prolog.)
    ;        E means "no epilog list"
    ; First byte of epilog unwind codes = 0
    DCD (((%F1 - %F0) / 4):SHL:28) :OR: (1:SHL:22) :OR: (1:SHL:21) :OR: ((|_NSInvocation_ForwardingBridge.epilog1.end| - |_NSInvocation_ForwardingBridge.epilog1.start|) / 2)
0   ; Executes as the epilog; must match the layout of epilog1 (because E=1)!
    DCB 0x03                   ; ADD sp, sp, #12
    DCB 2_10101000, 2_00010000 ; POP {r4, r11, lr}
    DCB 0x14                   ; ADD sp, sp, #0x50
    DCB 0xFF                   ; END
    ALIGN 4
1
    LTORG

    END