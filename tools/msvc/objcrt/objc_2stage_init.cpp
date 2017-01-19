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

#pragma comment(lib, "libobjc2")

// Legacy Loading
// --------------
// Each TU containing an Objective-C class emits a user init call to __objc_exec_module with a module.
// The module contains all selectors, categories, and classes referenced or defined within the TU.
// +load is called immediately after the class is thawed from the binary.
// If +load refers to other classes, they may not be thawed by the time it is run.
//
// Modern Loading
// --------------
// Each TU contains an Objective-C module emitted into the .objcrt$mx section. Herein we declare
// pointers into .objcrt$ma and .objcrt$mz which allow us to iterate all members in all sections
// defined between the two.
// We defer resolution of __objc_exec_class module classes until a known point where every class
// has been thawed.
// Loading happens in three stages:
// 1. Classes are thawed from the binary.
//    This happens in a library initializer registered as part of .CRT$XCL.
// 2. All classes loaded from a library are resolved and inserted into the class list. +load is called.
//    This also happens in a library initializer registered as part of .CRT$XCL.
// 3. All legacy-registered classes installed via __objc_exec_class are resolved.
//    This happens in a post-user initializer registered in .CRT$XCV.
//    Since the __objc_exec_class calls happen in .CRT$XCU, this is the only point at which we can be
//    entirely certain that they are all thawed. Were we to register legacy resolution in .CRT$XCU it
//    might happen before every class is thawed.

#pragma section(".objcrt$ma", read)
#pragma section(".objcrt$mz", read)
#pragma section(".CRT$XCLA", read)
#pragma section(".CRT$XCLB", read)
#pragma section(".CRT$XCV", read)

// .CRT is already merged to .rdata
#pragma comment(linker, "/merge:.objcrt=.rdata")

#define _SEGALLOC(seg) __declspec(allocate(seg))
typedef void (*InitFunc)();

extern "C" __declspec(selectany) _SEGALLOC(".objcrt$ma") const void* __objc_modules_a[] = { nullptr };
extern "C" __declspec(selectany) _SEGALLOC(".objcrt$mz") const void* __objc_modules_z[] = { nullptr };

extern "C" void __objc_load_module(const void*);
extern "C" void __objc_resolve_module(const void*);
extern "C" void __objc_resolve_legacy_modules();

// Step 1: Load all classes and thaw them from the binary.
static void ___objc_load_compiled_modules() {
    for (const void** i = __objc_modules_a + 1; i < __objc_modules_z; ++i) {
        if (*i) {
            __objc_load_module(*i);
        }
    }
    return;
}

// Step 2: Resolve all loaded classes and categories (call +load).
static void ___objc_resolve_compiled_modules() {
    for (const void** i = __objc_modules_a + 1; i < __objc_modules_z; ++i) {
        if (*i) {
            __objc_resolve_module(*i);
        }
    }
    return;
}

// Step 3: Resolve all classes that were legacy-registered via __objc_exec_class.
static void ___objc_legacy_resolve_all() {
    __objc_resolve_legacy_modules();
}

// Register load and resolve to happen in order during library init (.CRT$XCL).
extern "C" const InitFunc __declspec(selectany) _SEGALLOC(".CRT$XCLA") ___objc_modern_load = &___objc_load_compiled_modules;
extern "C" const InitFunc __declspec(selectany) _SEGALLOC(".CRT$XCLB") ___objc_modern_resolve = &___objc_resolve_compiled_modules;

// Register final legacy resolution to happen after user static init (nominally .CRT$XCU).
// We can't happen before .CRT$XCU here because .objc_load_function is part of .CRT$XCU;
// we would be resolving classes that have not been loaded.
extern "C" const InitFunc __declspec(selectany) _SEGALLOC(".CRT$XCV") ___objc_legacy_post_XCU = &___objc_legacy_resolve_all;

// Compiler Contract: the WinObjC build system will force this symbol to be included,
// pulling in this object even if it has been aggregated into a .lib.
extern "C" __declspec(selectany) const void* ___pin_objc_init = 0x0;

// Force inclusion of this TU.
#if defined(_M_IX86)
#pragma comment(linker, "/include:____objc_modern_load /include:____objc_modern_resolve /include:____objc_legacy_post_XCU")
#elif defined(_M_ARM)
#pragma comment(linker, "/include:___objc_modern_load /include:___objc_modern_resolve /include:___objc_legacy_post_XCU")
#else
#error Can't force-include objc_2stage_init initializers.
#endif
