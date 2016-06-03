// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

    .global __CFUniCharPropertyDatabase
__CFUniCharPropertyDatabase:
    .incbin "CoreFoundation/CharacterSets/CFUniCharPropertyDatabase.data"

    .global __CFUniCharPropertyDatabaseEnd
__CFUniCharPropertyDatabaseEnd:
    .byte 0

    .global __CFUniCharPropertyDatabaseSize
__CFUniCharPropertyDatabaseSize:
    .int __CFUniCharPropertyDatabaseEnd - __CFUniCharPropertyDatabase
