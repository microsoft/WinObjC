//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

template <typename T>
static void testGetValue(NSNumber* number, T expected) {
    const char* encodedType = [number objCType];

    ASSERT_EQ_MSG(1, strlen(encodedType), "FAILED: Unexpected NSNumber type");

#define TYPE_CASE(code, type)                                                               \
    case code: {                                                                            \
        type value = 0;                                                                     \
        [number getValue:&value];                                                           \
        EXPECT_EQ_MSG(expected, value, "FAILED: Unexpected value from NSNumber getValue:"); \
        break;                                                                              \
    }

    switch (encodedType[0]) {
        TYPE_CASE('c', char)
        TYPE_CASE('C', unsigned char)
        TYPE_CASE('s', short)
        TYPE_CASE('S', unsigned short)
        TYPE_CASE('i', int)
        TYPE_CASE('I', unsigned int)
        TYPE_CASE('l', long)
        TYPE_CASE('L', unsigned long)
        TYPE_CASE('q', long long)
        TYPE_CASE('Q', unsigned long long)
        TYPE_CASE('f', float)
        TYPE_CASE('d', double)

        default:
            EXPECT_TRUE_MSG(false, "FAILED: Unknown NSNumber type code");
    }
}

TEST(Foundation, NSNumber_numberWithShortGetStringValueUnSigned) {
    NSNumber* number = [NSNumber numberWithShort:25];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    ASSERT_OBJCEQ_MSG(@"25", [number stringValue], "FAILED: values do not match as expected.");
}

TEST(Foundation, NSNumber_numberWithShortGetStringValueSigned) {
    NSNumber* number = [NSNumber numberWithShort:-12];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    ASSERT_OBJCEQ_MSG(@"-12", [number stringValue], "FAILED: values do not match as expected.");
}

TEST(Foundation, NSNumber_numberWithUnsignedShort) {
    NSNumber* number = [NSNumber numberWithUnsignedShort:25];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    ASSERT_OBJCEQ_MSG(@"25", [number stringValue], "FAILED: values do not match as expected.");
}

TEST(Foundation, NSNumber_getValueUnSigned) {
    NSNumber* number = [NSNumber numberWithUnsignedShort:25];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    testGetValue(number, static_cast<unsigned short>(25));
}

TEST(Foundation, NSNumber_getValueSigned) {
    NSNumber* number = [NSNumber numberWithShort:-12];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    testGetValue(number, static_cast<short>(-12));
}

TEST(Foundation, NSNumber_numberWithCharGetStringValueSigned) {
    NSNumber* number = [NSNumber numberWithChar:-5];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    ASSERT_OBJCEQ_MSG(@"-5", [number stringValue], "FAILED: values do not match as expected.");
}

TEST(Foundation, NSNumber_numberWithCharGetStringValueUnsigned) {
    NSNumber* number = [NSNumber numberWithUnsignedChar:5];
    ASSERT_TRUE_MSG(number != nil, "FAILED: number should not be nil!");
    ASSERT_OBJCEQ_MSG(@"5", [number stringValue], "FAILED: values do not match as expected.");
}