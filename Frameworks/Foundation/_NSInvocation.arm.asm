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

115 ; INT32
    STR r1, [r2, #4]
    ;; fall through
114 ; INT
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

    END