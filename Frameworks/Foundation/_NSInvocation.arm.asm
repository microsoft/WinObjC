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
|_CallFrameInternal_VFP|
    GLOBAL _CallFrameInternal_VFP
; FALL THROUGH TO NON-VFP CASE
    CMP r3, 1
    VLDREQ.64 d0, [r0]
    VLDMGT.64 r0, {d0-d7}

    ADD r0, r0, #64

    GLOBAL _CallFrameInternal
|_CallFrameInternal|
    STM r1, {fp, lr}
    MOV fp, r1

    MOV sp, r0
    MOV lr, r2
    MOV ip, #0
    LDMIA sp!, {r0-r3}
    BLX lr

    LDR r2, [fp, #8]
    LDR r3, [fp, #12]
    MOV sp, fp

    ADR ip, |JumpTable|
    LDR pc, [ip, r3, lsl #2]

|_CASE_ARM_VFP_S|
    VSTR s0, [r2]
    POP {fp, pc}
|_CASE_ARM_VFP_D|
    VSTR d0, [r2]
    POP {fp, pc}
|_CASE_ARM_VFP_HOMOGENOUS|
    VSTM r2, {d0-d3}
    POP {fp, pc}

|_CASE_ARM_INT64|
    STR r1, [r2, #4]
    ;; fall through
|_CASE_ARM_INT|
    STR r0, [r2]
    ;; fall through

|_CASE_ARM_STRUCT|
|_CASE_ARM_NONE|
    POP {fp, pc}

|JumpTable|
    DCD |_CASE_ARM_NONE|
    DCD |_CASE_ARM_VFP_S|
    DCD |_CASE_ARM_VFP_D|
    DCD |_CASE_ARM_VFP_HOMOGENOUS|
    DCD |_CASE_ARM_INT|
    DCD |_CASE_ARM_INT64|
    DCD |_CASE_ARM_STRUCT|

    END