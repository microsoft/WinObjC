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
#import <Starboard/SmartTypes.h>
#import <vector>

static const std::vector<uint8_t>
    s_testUUID{ 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10 };

TEST(NSUUID, Sanity) {
    ASSERT_OBJCNE(nil, [NSUUID UUID]);
}

TEST(NSUUID, Uniqueness) {
    ASSERT_OBJCNE([NSUUID UUID], [NSUUID UUID]);
}

TEST(NSUUID, CopyViaString) {
    NSUUID* uuid = [NSUUID UUID];
    StrongId<NSUUID> uuidClone{ woc::TakeOwnership, [[NSUUID alloc] initWithUUIDString:[uuid UUIDString]] };

    ASSERT_OBJCEQ(uuid, uuidClone.get());
}

TEST(NSUUID, InitWithString) {
    StrongId<NSUUID> uuid {
        woc::TakeOwnership, [[NSUUID alloc] initWithUUIDString:@"01020304-0506-0708-090A-0B0C0D0E0F10"]
    };

    uint8_t bytes[16];
    ASSERT_NO_THROW([uuid getUUIDBytes:(unsigned char*)bytes]);

    std::vector<uint8_t> comparand(&bytes[0], bytes + 16);
    ASSERT_EQ(s_testUUID, comparand);
}

TEST(NSUUID, InitWithUUIDBytes) {
    StrongId<NSUUID> uuid{ woc::TakeOwnership, [[NSUUID alloc] initWithUUIDBytes:(const unsigned char*)s_testUUID.data()] };

    uint8_t bytes[16];
    ASSERT_NO_THROW([uuid getUUIDBytes:(unsigned char*)bytes]);

    std::vector<uint8_t> comparand(&bytes[0], bytes + 16);
    ASSERT_EQ(s_testUUID, comparand);
}

TEST(NSUUID, CrossTypeComparison) {
    StrongId<NSUUID> fromString {
        woc::TakeOwnership, [[NSUUID alloc] initWithUUIDString:@"01020304-0506-0708-090A-0B0C0D0E0F10"]
    };
    StrongId<NSUUID> fromBytes{ woc::TakeOwnership, [[NSUUID alloc] initWithUUIDBytes:(const unsigned char*)s_testUUID.data()] };

    ASSERT_OBJCEQ(fromString, fromBytes);
}

TEST(NSUUID, UUIDString) {
    StrongId<NSUUID> uuid {
        woc::TakeOwnership, [[NSUUID alloc] initWithUUIDString:@"01020304-0506-0708-090A-0B0C0D0E0F10"]
    };

    ASSERT_OBJCEQ(@"01020304-0506-0708-090A-0B0C0D0E0F10", [uuid UUIDString]);
}

TEST(NSUUID, InvalidStrings) {
    EXPECT_OBJCEQ(nil, [[NSUUID alloc] initWithUUIDString:@"HELLOWOR-LDTH-ISIS-ABAD-UUIDSTRING!!"]);
    EXPECT_OBJCEQ(nil, [[NSUUID alloc] initWithUUIDString:@"000000"]);
}

// NSUUID is supposed to generate v4 UUIDs.
TEST(NSUUID, v4UUIDs) {
    NSUUID* uuid = [NSUUID UUID];

    uint8_t bytes[16];
    ASSERT_NO_THROW([uuid getUUIDBytes:(unsigned char*)bytes]);

    ASSERT_EQ(4, (bytes[6] & 0xF0) >> 4);
}

TEST(NSUUID, CanBeArchived) {
    NSUUID* uuid = [NSUUID UUID];

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:uuid];
    id decodedUUID = [NSKeyedUnarchiver unarchiveObjectWithData:data];

    ASSERT_OBJCEQ(uuid, decodedUUID);
}