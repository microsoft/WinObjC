# Windows Bridge for iOS Dev Design Specification: NSInvocation

## Feature Summary

**NSInvocation** is a Foundation class that provides an object representation of a method call.
It encapsulates a target, a selector, and a pack of arguments whose contents can be installed
or interrogated at runtime.

## Challenges

Objective-C methods are implemented as though they were C functions, with standard C function calling conventions, taking 2+n arguments.
The first two arguments passed to a method implementation are always `self` (the target of the message) and `_cmd` (the message selector).
The remaining arguments are laid out according to the platform's default calling convention -- `__cdecl` on Win32 and *AAPCS*<sup>1</sup> on ARM.

Methods that return structures above a certain *platform-defined* length limit are emitted with a hidden first argument, shifting `self` and `_cmd`
one machine word up to make room for a *structure return* pointer. This out pointer is populated with the return value of the method automatically.

Herein lies the challenge: **NSInvocation** must be able to lay out arguments at runtime, based solely on the Objective-C method signature
provided during its construction.

<sup>1. Procedure Call Standard for the ARM Architecture. [PDF link](http://infocenter.arm.com/help/topic/com.arm.doc.ihi0042f/IHI0042F_aapcs.pdf)</sup>

## Architecture Decisions

NSInvocation will rely on an internal platform-specific interface, `_NSInvocationCallFrame`, to do its argument allocation.

`_NSInvocationCallFrame` has only three responsibilities: determining whether a method requires special struct return handling, storing an argument, and loading an argument.

Therefore, platform support for NSInvocation will be provided via two discrete modules:

1. A conformant implementation of `_NSInvocationCallFrame`.
2. An assembly thunk that will take the platform internal representation of `_NSInvocationCallFrame` and dispatch a call to a function pointer with the stored arguments.

### X86 details

X86 is the easier of the two currently-supported architectures for which to allocate arguments.

* Every argument is placed on the stack, in stack-ascending order.
* Arguments less than four bytes in width are sign- or zero-extended and stored in one 32-bit doubleword and emitted onto the stack.
* Arguments greater than four bytes in width are promoted to an even number of 32-bit doubleword and emitted onto the stack.
* Values are returned in `eax` (if less than or equal to four bytes), `eax+edx` (if between four and eight bytes) and via hidden struct parameter.

### ARM details

Arguments in ARM are split between general-purpose registers, floating point registers, and the stack based on a few rules. While the rules are laid out in the *Procedure Call Standard*,
they will be included here in brief.

* Non-floating-point arguments less than or equal to four bytes in width are sign- or zero-extended and stored preferentially in registers `R0` through `R3`.
  * If there are no unallocated registers, these arguments are placed on the stack.
* Non-floating-point arguments eight bytes in width requiring 8-byte alignment are stored preferentially in `R0,R1` or `R2,R3`.
  * If these registers are not available, the entire argument is placed on the stack.
* Single-precision floating point arguments are preferentially allocated to single-precision registers `S0` through `S15`.
  * If there are no unallocated single-precision registers, these arguments are placed on the stack.
* Double-precision floating point arguments are preferentially allocated to double-precision registers `D0` through `D7`.
  * If there are no unallocated double-precision registers, these arguments are aligned to 8 bytes and on the stack.
  * Each `Dx` register consumes two `Sx` registers. They will be unavailable for floating-point arguments.
* Aggregates of 1-4 single- or double-precision values are allocated to available floating-point registers.
* Aggregates of anything else > 4 bytes in length are allocated to the remaining registers and split onto the stack.
* Values are returned in `R0` (<= 4 bytes), `R0+R1` (4-8 bytes), `S0` (single-precision), `D0` (double-precision), `D0-D4` (aggregate <=4 floats/doubles) and via hidden struct parameter.

## Implementation

To handle the diverse requirements for argument allocation on ARM, an *allocation extent* system was designed. Each argument is
allocated into a large arena which can be subdivided by its storage class (registers, float registers, stack).

An argument allocation extent contains an offset and a length.

On ARM, the argument arena allocated for `- (void)hello:(int)arg1 world:(double)arg2` may look like this:

```
| FLOATING POINT REGISTERS               | GENERAL PURPOSE REGS  | STACK |
+------------------------------------------------------------------------+
| arg2 |                                 | self | sel | arg1     |       +
+------------------------------------------------------------------------+
|                                        |      |     |          |       |
0                                       64     68    72

Extents:
self: {64, 4}
 sel: {68, 4}
arg1: {64, 2}
arg2: { 0, 8}
```

While the equivalent arena on x86 will resemble:
```
| STACK                                                                  |
+------------------------------------------------------------------------+
| self | sel | arg1 | arg2 |                                             |
+------------------------------------------------------------------------+
|      |     |      |
0      4     8     12

Extents:
self: { 0, 4}
 sel: { 4, 4}
arg1: { 8, 4}
arg2: {12, 4}
```

This allows the platform-specific assembly thunk to most efficiently dispatch the function call.

### ARM Dispatching

The arena begins with 8 double-width floating-point slots, each of which represents one double-width register.

The assembly thunk will begin with `VLDMIA ..., {D0-D8}` to consume all eight of them at once, load them into registers, and advance the arena pointer.

It will then consume the 4 register-width slots, each of which represents one general purpose register from `R0` to `R3`. It does so with `LDMIA ..., {R0-R3}`.

At this point, all that remains in the arena is the stack. The thunk temporarily redirects the stack pointer so that it points here, and calls the function. Every argument
is precisely where the destination method expects it.

### X86 Dispatching

X86 proves to be the easy case; the stack pointer is directed at the arena, and the function is called.

## Rationale

By making sure that **NSInvocation**'s internal memory layout matches a fully realized argument frame, we gain a few benefits. The arguments need be copied fewer times; they
can generally be used as-is, or copied into a single buffer at the start of the dispatch.

More important, however, is that this memory layout be reversible. Take `forwardInvocation:`. Invocation forwarding is a powerful mechanism in Foundation that takes a
failed message dispatch and packages it up to be resolved later. It could be saved on a stack, used for a callback, queried for information, or even discarded entirely.

By ensuring that the memory layout within an invocation closely matches the platform's preferred argument layout, `forwardInvocation:` can quickly and with a single copy move
from a partially-evaluated method dispatch (with arguments on the stack, in registers, or wherever they might be) to a boxed **NSInvocation** containing the same.