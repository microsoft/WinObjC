// clang-format off

// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

/*
     File:       TargetConditionals.h
 
     Contains:   Autoconfiguration of TARGET_ conditionals for Mac OS X and iPhone
     
                 Note:  TargetConditionals.h in 3.4 Universal Interfaces works
                        with all compilers.  This header only recognizes compilers
                        known to run on Mac OS X.
  
*/

#ifndef __TARGETCONDITIONALS__
#define __TARGETCONDITIONALS__
/****************************************************************************************************

    TARGET_CPU_*    
    These conditionals specify which microprocessor instruction set is being
    generated.  At most one of these is true, the rest are false.

        TARGET_CPU_PPC          - Compiler is generating PowerPC instructions for 32-bit mode
        TARGET_CPU_PPC64        - Compiler is generating PowerPC instructions for 64-bit mode
        TARGET_CPU_68K          - Compiler is generating 680x0 instructions
        TARGET_CPU_X86          - Compiler is generating x86 instructions
        TARGET_CPU_ARM          - Compiler is generating ARM instructions
        TARGET_CPU_MIPS         - Compiler is generating MIPS instructions
        TARGET_CPU_SPARC        - Compiler is generating Sparc instructions
        TARGET_CPU_ALPHA        - Compiler is generating Dec Alpha instructions


    TARGET_OS_* 
    These conditionals specify in which Operating System the generated code will
    run.  Indention is used to show which conditionals are evolutionary subclasses.  
    
    The MAC/WIN32/UNIX conditionals are mutually exclusive.
    The IOS/TV/WATCH conditionals are mutually exclusive.
    
    
        TARGET_OS_WIN32           - Generated code will run under 32-bit Windows
        TARGET_OS_UNIX            - Generated code will run under some Unix (not OSX) 
        TARGET_OS_MAC             - Generated code will run under Mac OS X variant
           TARGET_OS_IPHONE          - Generated code for firmware, devices, or simulator 
              TARGET_OS_IOS             - Generated code will run under iOS 
              TARGET_OS_TV              - Generated code will run under Apple TV OS
              TARGET_OS_WATCH           - Generated code will run under Apple Watch OS
           TARGET_OS_SIMULATOR      - Generated code will run under a simulator
           TARGET_OS_EMBEDDED       - Generated code for firmware
       
        TARGET_IPHONE_SIMULATOR   - DEPRECATED: Same as TARGET_OS_SIMULATOR
        TARGET_OS_NANO            - DEPRECATED: Same as TARGET_OS_WATCH

    TARGET_RT_* 
    These conditionals specify in which runtime the generated code will
    run. This is needed when the OS and CPU support more than one runtime
    (e.g. Mac OS X supports CFM and mach-o).

        TARGET_RT_LITTLE_ENDIAN - Generated code uses little endian format for integers
        TARGET_RT_BIG_ENDIAN    - Generated code uses big endian format for integers    
        TARGET_RT_64_BIT        - Generated code uses 64-bit pointers    
        TARGET_RT_MAC_CFM       - TARGET_OS_MAC is true and CFM68K or PowerPC CFM (TVectors) are used
        TARGET_RT_MAC_MACHO     - TARGET_OS_MAC is true and Mach-O/dlyd runtime is used
        

****************************************************************************************************/

#if __APPLE__
#define TARGET_OS_DARWIN       1
#define TARGET_OS_LINUX        0
#define TARGET_OS_WINDOWS      0
#define TARGET_OS_BSD          0
#elif __linux__
#define TARGET_OS_DARWIN       0
#define TARGET_OS_LINUX        1
#define TARGET_OS_WINDOWS      0
#define TARGET_OS_BSD          0
#elif _WIN32 || _WIN64
#define TARGET_OS_DARWIN       0
#define TARGET_OS_LINUX        0
#define TARGET_OS_WINDOWS      1
#define TARGET_OS_BSD          0
#elif __unix__
#define TARGET_OS_DARWIN       0
#define TARGET_OS_LINUX        0
#define TARGET_OS_WINDOWS      0
#define TARGET_OS_BSD          1
#else
#error unknown operating system
#endif

#define TARGET_OS_WIN32        TARGET_OS_WINDOWS
#define TARGET_OS_MAC          TARGET_OS_DARWIN

#if __x86_64__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       1
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#elif __arm64__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        1
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#elif __mips64__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       1
#elif __powerpc64__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        1
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#elif __i386__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          1
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#elif __arm__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          1
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#elif __mips__
#define TARGET_CPU_PPC          0
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         1
#define TARGET_CPU_MIPS64       0
#elif __powerpc__
#define TARGET_CPU_PPC          1
#define TARGET_CPU_PPC64        0
#define TARGET_CPU_X86          0
#define TARGET_CPU_X86_64       0
#define TARGET_CPU_ARM          0
#define TARGET_CPU_ARM64        0
#define TARGET_CPU_MIPS         0
#define TARGET_CPU_MIPS64       0
#else
#error unknown architecture
#endif

#if __LITTLE_ENDIAN__
#define TARGET_RT_LITTLE_ENDIAN 1
#define TARGET_RT_BIG_ENDIAN    0
#elif __BIG_ENDIAN__
#define TARGET_RT_LITTLE_ENDIAN 0
#define TARGET_RT_BIG_ENDIAN    1
#else
#error unknown endian
#endif

#if __LP64__
#define TARGET_RT_64_BIT        1
#else
#define TARGET_RT_64_BIT        0
#endif

#endif  /* __TARGETCONDITIONALS__ */

// clang-format on