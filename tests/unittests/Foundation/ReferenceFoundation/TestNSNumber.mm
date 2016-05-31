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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSNumber, NumberWithBool) {
    ASSERT_EQ([NSNumber numberWithBool:true].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithBool:true].charValue, int8_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].unsignedCharValue, uint8_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].shortValue, int16_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].unsignedShortValue, uint16_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].intValue, int32_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].unsignedIntValue, uint32_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].longLongValue, int64_t(1));
    ASSERT_EQ([NSNumber numberWithBool:true].unsignedLongLongValue, uint64_t(1));

    ASSERT_EQ([NSNumber numberWithBool:true].floatValue, float(1));
    ASSERT_EQ([NSNumber numberWithBool:true].doubleValue, double(1));

    ASSERT_EQ([NSNumber numberWithBool:false].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithBool:false].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithBool:false].unsignedLongLongValue, uint64_t(0));

    ASSERT_EQ([NSNumber numberWithBool:false].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithBool:false].doubleValue, double(0));
}

TEST(NSNumber, NumberWithChar) {
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].unsignedLongLongValue, uint64_t(0));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].charValue, int8_t(-37));
    // #if !(os(Linux) && arch(arm))
    //     // Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, these tests will always fail.
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].shortValue, int16_t(-37));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].intValue, int32_t(-37));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].longLongValue, int64_t(-37));
    // #endif
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].charValue, int8_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].unsignedCharValue, uint8_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].shortValue, int16_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].unsignedShortValue, uint16_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].intValue, int32_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].unsignedIntValue, uint32_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].longLongValue, int64_t(42));
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].unsignedLongLongValue, uint64_t(42));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].charValue, int8_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].unsignedCharValue, uint8_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].shortValue, int16_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].unsignedShortValue, uint16_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].intValue, int32_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].unsignedIntValue, uint32_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].longLongValue, int64_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].unsignedLongLongValue, uint64_t(CHAR_MAX));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].charValue, int8_t(CHAR_MIN));
    // #if !(os(Linux) && arch(arm))
    //     // Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, these tests will always fail.
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].shortValue, int16_t(CHAR_MIN));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].intValue, int32_t(CHAR_MIN));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].longLongValue, int64_t(CHAR_MIN));
    // #endif
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].floatValue, float(0));
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].floatValue, float(-37));
    // #endif
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].floatValue, float(42));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].floatValue, float(CHAR_MAX));
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].floatValue, float(CHAR_MIN));
    // #endif
    ASSERT_EQ([NSNumber numberWithChar:int8_t(0)].doubleValue, double(0));
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([NSNumber numberWithChar:int8_t(-37)].doubleValue, double(-37));
    // #endif
    ASSERT_EQ([NSNumber numberWithChar:int8_t(42)].doubleValue, double(42));
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MAX].doubleValue, double(CHAR_MAX));
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([NSNumber numberWithChar:CHAR_MIN].doubleValue, double(CHAR_MIN));
    // #endif
}

TEST(NSNumber, NumberWithUnsignedChar) {
    // Comment blocks in this test are in line with the reference swift test
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].unsignedLongLongValue, uint64_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].charValue, int8_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].unsignedCharValue, uint8_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].shortValue, int16_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].unsignedShortValue, uint16_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].intValue, int32_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].unsignedIntValue, uint32_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].longLongValue, int64_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].unsignedLongLongValue, uint64_t(42));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].unsignedCharValue, UCHAR_MAX);
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].shortValue, int16_t(UCHAR_MAX))
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].unsignedShortValue, uint16_t(UCHAR_MAX))
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].intValue, int32_t(UCHAR_MAX))
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].unsignedIntValue, uint32_t(UCHAR_MAX))
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].longLongValue, int64_t(UCHAR_MAX))
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].unsignedLongLongValue, uint64_t(UCHAR_MAX))
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].floatValue, float(42));
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].floatValue, float(UCHAR_MAX))
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(0)].doubleValue, double(0));
    ASSERT_EQ([NSNumber numberWithUnsignedChar:uint8_t(42)].doubleValue, double(42));
    //        ASSERT_EQ([NSNumber numberWithUnsignedChar:UCHAR_MAX].doubleValue, double(UCHAR_MAX))
    ASSERT_EQ([NSNumber numberWithUnsignedChar:0].doubleValue, double(0));
}

TEST(NSNumber, NumberWithShort) {
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].unsignedLongLongValue, uint64_t(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].charValue, int8_t(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].shortValue, int16_t(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].intValue, int32_t(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].longLongValue, int64_t(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].charValue, int8_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].unsignedCharValue, uint8_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].shortValue, int16_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].unsignedShortValue, uint16_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].intValue, int32_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].unsignedIntValue, uint32_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].longLongValue, int64_t(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].unsignedLongLongValue, uint64_t(42));
    ASSERT_EQ([NSNumber numberWithShort:SHRT_MAX].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithShort:SHRT_MIN].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].floatValue, float(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].floatValue, float(42));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(0)].doubleValue, double(0));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(-37)].doubleValue, double(-37));
    ASSERT_EQ([NSNumber numberWithShort:int16_t(42)].doubleValue, double(42));
}

TEST(NSNumber, NumberWithFloat) {
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].unsignedLongLongValue, uint64_t(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithFloat:float(-37)].charValue, int8_t(-37));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37)].shortValue, int16_t(-37));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37)].intValue, int32_t(-37));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37)].longLongValue, int64_t(-37));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].charValue, int8_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].unsignedCharValue, uint8_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].shortValue, int16_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].unsignedShortValue, uint16_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].intValue, int32_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].unsignedIntValue, uint32_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].longLongValue, int64_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(42)].unsignedLongLongValue, uint64_t(42));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37.5)].floatValue, float(-37.5));
    ASSERT_EQ([NSNumber numberWithFloat:float(42.1)].floatValue, float(42.1));
    ASSERT_EQ([NSNumber numberWithFloat:float(0)].doubleValue, double(0));
    ASSERT_EQ([NSNumber numberWithFloat:float(-37.5)].doubleValue, double(-37.5));
    ASSERT_EQ([NSNumber numberWithFloat:float(42.5)].doubleValue, double(42.5));
}

TEST(NSNumber, NumberWithDouble) {
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].boolValue, NO);
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].charValue, int8_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].unsignedCharValue, uint8_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].shortValue, int16_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].unsignedShortValue, uint16_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].intValue, int32_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].unsignedIntValue, uint32_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].longLongValue, int64_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].unsignedLongLongValue, uint64_t(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithDouble:double(-37)].charValue, int8_t(-37));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37)].shortValue, int16_t(-37));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37)].intValue, int32_t(-37));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37)].longLongValue, int64_t(-37));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].boolValue, YES);
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].charValue, int8_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].unsignedCharValue, uint8_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].shortValue, int16_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].unsignedShortValue, uint16_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].intValue, int32_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].unsignedIntValue, uint32_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].longLongValue, int64_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(42)].unsignedLongLongValue, uint64_t(42));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].floatValue, float(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37.5)].floatValue, float(-37.5));
    ASSERT_EQ([NSNumber numberWithDouble:double(42.1)].floatValue, float(42.1));
    ASSERT_EQ([NSNumber numberWithDouble:double(0)].doubleValue, double(0));
    ASSERT_EQ([NSNumber numberWithDouble:double(-37.5)].doubleValue, double(-37.5));
    ASSERT_EQ([NSNumber numberWithDouble:double(42.1)].doubleValue, double(42.1));
}

TEST(NSNumber, CompareNumberWithBool) {
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithChar:0]], NSOrderedSame);
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithChar:-1]], NSOrderedDescending);
    // #endif
    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithChar:1]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithChar:1]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithChar:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithChar:2]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithDouble:0]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithDouble:-0.1]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithBool:false] compare:[NSNumber numberWithDouble:0.1]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithDouble:1]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithDouble:0.9]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithBool:true] compare:[NSNumber numberWithDouble:1.1]], NSOrderedAscending);
}

TEST(NSNumber, CompareNumberWithChar) {
    ASSERT_EQ([[NSNumber numberWithChar:42] compare:[NSNumber numberWithChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithChar:42] compare:[NSNumber numberWithChar:0]], NSOrderedDescending);
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([[NSNumber numberWithChar:-37] compare:[NSNumber numberWithChar:16]], NSOrderedAscending);
    // #endif

    ASSERT_EQ([[NSNumber numberWithChar:1] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithChar:1] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([[NSNumber numberWithChar:-37] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);
    // #endif

    ASSERT_EQ([[NSNumber numberWithChar:42] compare:[NSNumber numberWithUnsignedChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithChar:42] compare:[NSNumber numberWithUnsignedChar:16]], NSOrderedDescending);
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([[NSNumber numberWithChar:-37] compare:[NSNumber numberWithUnsignedChar:255]], NSOrderedAscending);
    // #endif

    ASSERT_EQ([[NSNumber numberWithChar:42] compare:[NSNumber numberWithFloat:42]], NSOrderedSame);
    // #if !(os(Linux) && arch(arm))
    // Reference test comment: Linux/arm chars are unsigned, so int8_t in Swift, until this issue is resolved, this test will always fail.
    ASSERT_EQ([[NSNumber numberWithChar:-16] compare:[NSNumber numberWithFloat:-37.5]], NSOrderedDescending);
    // #endif
    ASSERT_EQ([[NSNumber numberWithChar:16] compare:[NSNumber numberWithFloat:16.1]], NSOrderedAscending);
}

TEST(NSNumber, CompareNumberWithUnsignedChar) {
    // Comment blocks in this test are in line with the reference swift test
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:42] compare:[NSNumber numberWithUnsignedChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:42] compare:[NSNumber numberWithUnsignedChar:0]], NSOrderedDescending);
    //        ASSERT_EQ([[NSNumber numberWithUnsignedChar:42] compare:[NSNumber numberWithUnsignedChar:255]], NSOrderedAscending)

    ASSERT_EQ([[NSNumber numberWithUnsignedChar:1] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:1] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:0] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithUnsignedChar:42] compare:[NSNumber numberWithShort:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:0] compare:[NSNumber numberWithShort:-123]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:255] compare:[NSNumber numberWithShort:12345]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithUnsignedChar:42] compare:[NSNumber numberWithFloat:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:0] compare:[NSNumber numberWithFloat:-37.5]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithUnsignedChar:255] compare:[NSNumber numberWithFloat:1234.5]], NSOrderedAscending);
}

TEST(NSNumber, CompareNumberWithShort) {
    ASSERT_EQ([[NSNumber numberWithShort:42] compare:[NSNumber numberWithShort:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithShort:42] compare:[NSNumber numberWithShort:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithShort:-37] compare:[NSNumber numberWithShort:12345]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithShort:1] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithShort:1] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithShort:0] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithShort:42] compare:[NSNumber numberWithUnsignedChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithShort:42] compare:[NSNumber numberWithUnsignedChar:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithShort:-37] compare:[NSNumber numberWithUnsignedChar:255]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithShort:42] compare:[NSNumber numberWithFloat:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithShort:0] compare:[NSNumber numberWithFloat:-37.5]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithShort:255] compare:[NSNumber numberWithFloat:1234.5]], NSOrderedAscending);
}

TEST(NSNumber, CompareNumberWithFloat) {
    ASSERT_EQ([[NSNumber numberWithFloat:42] compare:[NSNumber numberWithFloat:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithFloat:42] compare:[NSNumber numberWithFloat:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithFloat:-37] compare:[NSNumber numberWithFloat:12345]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithFloat:1] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithFloat:0.1] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithFloat:0.9] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithFloat:42] compare:[NSNumber numberWithUnsignedChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithFloat:0.1] compare:[NSNumber numberWithUnsignedChar:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithFloat:-254.9] compare:[NSNumber numberWithUnsignedChar:255]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithFloat:42] compare:[NSNumber numberWithDouble:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithFloat:0] compare:[NSNumber numberWithDouble:-37.5]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithFloat:-37.5] compare:[NSNumber numberWithDouble:1234.5]], NSOrderedAscending);
}

TEST(NSNumber, CompareNumberWithDouble) {
    ASSERT_EQ([[NSNumber numberWithDouble:42] compare:[NSNumber numberWithDouble:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithDouble:42] compare:[NSNumber numberWithDouble:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithDouble:-37] compare:[NSNumber numberWithDouble:12345]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithDouble:1] compare:[NSNumber numberWithBool:true]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithDouble:0.1] compare:[NSNumber numberWithBool:false]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithDouble:0.9] compare:[NSNumber numberWithBool:true]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithDouble:42] compare:[NSNumber numberWithUnsignedChar:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithDouble:0.1] compare:[NSNumber numberWithUnsignedChar:0]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithDouble:-254.9] compare:[NSNumber numberWithUnsignedChar:255]], NSOrderedAscending);

    ASSERT_EQ([[NSNumber numberWithDouble:42] compare:[NSNumber numberWithFloat:42]], NSOrderedSame);
    ASSERT_EQ([[NSNumber numberWithDouble:0] compare:[NSNumber numberWithFloat:-37.5]], NSOrderedDescending);
    ASSERT_EQ([[NSNumber numberWithDouble:-37.5] compare:[NSNumber numberWithFloat:1234.5]], NSOrderedAscending);
}

// Swift-exclusive API, somewhat private
// TEST(NSNumber, Reflection) {
//     auto ql1 = [NSNumber numberWithInteger:1234].customPlaygroundQuickLook;
//     switch (ql1) {
//         case.int(let value):
//             ASSERT_EQ(value, 1234);
//             break;
//         default:
//             ASSERT_TRUE_MSG(false, @"[NSNumber numberWithInteger:] quicklook is not an int");
//             break;
//     }

//     auto ql2 = [NSNumber numberWithFloat:1.25].customPlaygroundQuickLook;
//     switch (ql2) {
//         case.float(let value):
//             ASSERT_EQ(value, 1.25);
//             break;
//         default:
//             ASSERT_TRUE_MSG(false, @"[NSNumber numberWithFloat:] quicklook is not a float");
//             break;
//     }

//     auto ql3 = [NSNumber numberWithDouble:1.25].customPlaygroundQuickLook;
//     switch (ql3) {
//         case.double(let value):
//             ASSERT_EQ(value, 1.25);
//             break;
//         default:
//             ASSERT_TRUE_MSG(false, @"[NSNumber numberWithDouble:] quicklook is not a double");
//             break;
//     }
// }
