// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

    .global __CFUnicodeDataL
__CFUnicodeDataL:
    .incbin "CoreFoundation/CharacterSets/CFUnicodeData-L.mapping"

    .global __CFUnicodeDataLEnd
__CFUnicodeDataLEnd:
    .byte 0

    .global __CFUnicodeDataLSize
__CFUnicodeDataLSize:
    .int __CFUnicodeDataLEnd - __CFUnicodeDataL
