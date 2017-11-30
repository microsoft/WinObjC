//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSNull, Bridged) {
    ASSERT_EQ((void*)[NSNull null], (void*)kCFNull); // Pointer equality required.
}

TEST(NSNull, Singleton) {
    ASSERT_NE(nil, [NSNull null]);
    ASSERT_EQ([NSNull null], [NSNull null]);
    ASSERT_EQ([NSNull null], [NSNull alloc]);
    ASSERT_EQ([NSNull alloc], [NSNull alloc]);
}

TEST(NSNull, CopiesAreSingleton) {
    ASSERT_EQ([NSNull null], [[NSNull null] copy]);
}

TEST(NSNull, CFNullCanReceiveMessages) {
    ASSERT_EQ([NSNull null], [static_cast<NSNull*>(kCFNull) self]);
}

TEST(NSNull, ObjectEquality) {
    ASSERT_OBJCEQ([NSNull null], [NSNull alloc]);
}

TEST(NSNull, CanDeserializeFromPropertyList) {
    // The only way to represent a serialized CFNull is via binary property list.
    // This property list contains:
    // 0x00:        u8[8] header                       (bplist00)
    // -- object table --
    // 0x08: kCFNull (0x00)
    // -- offset table --
    // 0x09: 0x08
    // -- plist trailer --
    // 0x0A - 0x0E: u8[5] unused                       (0x00 * 5)
    // 0x0F:        u8    sort version                 (0x00)
    // 0x10:        u8    size of offset table entries (0x01)
    // 0x11:        u8    size of embedded objects     (0x01)
    // 0x12 - 0x19: u64   number of objects            (0x01)
    // 0x1A - 0x21: u64   toplevel object              (0x00)
    // 0x22 - 0x29: u64   offset to offset table       (0x09)

    const unsigned char rawPlist[] = { 'b',  'p',  'l',  'i',  's',  't',  '0',  '0',  0x00, 0x08, 0x00, 0x00, 0x00, 0x00,
                                       0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
                                       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x09 };
    NSData* plistData = [NSData dataWithBytes:rawPlist length:std::extent<decltype(rawPlist)>::value];
    NSObject* nullObject = nil;
    ASSERT_NO_THROW(
        nullObject =
            [NSPropertyListSerialization propertyListFromData:plistData mutabilityOption:0 format:nullptr errorDescription:nullptr]);
    ASSERT_NE(nil, nullObject);

    EXPECT_EQ([NSNull null], nullObject);
}