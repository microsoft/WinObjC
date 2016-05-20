// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

    .global __CFCharacterSetBitmapData
__CFCharacterSetBitmapData:
    .incbin "CoreFoundation/CharacterSets/CFCharacterSetBitmaps.bitmap"

    .global __CFCharacterSetBitmapDataEnd
__CFCharacterSetBitmapDataEnd:
    .byte 0

    .global __CFCharacterSetBitmapDataSize
__CFCharacterSetBitmapDataSize:
    .int __CFCharacterSetBitmapDataEnd - __CFCharacterSetBitmapData
