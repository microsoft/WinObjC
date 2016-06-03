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

#include <TestFramework.h>
#include <CoreFoundation/CoreFoundation.h>

static const CFIndex expectedUUIDStringLength = 36; // 32 Hex characters separated by 4 dashes eg: XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX

TEST(CFUUID, Create) {
    // Validate CFUUID default initializer
    CFUUIDRef uuid1 = CFUUIDCreate(NULL);
    ASSERT_TRUE(uuid1 != NULL);

    // Validate CFUUIDCreateString
    CFStringRef str1 = CFUUIDCreateString(NULL, uuid1);
    ASSERT_TRUE(str1 != NULL);
    CFIndex actualUUIDStringLength = CFStringGetLength(str1);
    ASSERT_EQ(expectedUUIDStringLength, actualUUIDStringLength);

    // Validate CFUUIDCreateFromString
    CFUUIDRef uuid2 = CFUUIDCreateFromString(NULL, str1);
    ASSERT_TRUE(uuid2 != NULL);

    // Validate CFUUIDGetUUIDBytes and show uuid1 and uuid2 have same bytes
    CFUUIDBytes uuid1bytes = CFUUIDGetUUIDBytes(uuid1);
    CFUUIDBytes uuid2bytes = CFUUIDGetUUIDBytes(uuid2);
    ASSERT_EQ(0, memcmp(&uuid1bytes.byte0, &uuid2bytes.byte0, 16));

    // Validate CFUUIDCreateFromUUIDBytes
    CFUUIDRef uuid3 = CFUUIDCreateFromUUIDBytes(NULL, uuid2bytes);
    CFUUIDBytes uuid3bytes = CFUUIDGetUUIDBytes(uuid3);
    ASSERT_EQ(0, memcmp(&uuid2bytes.byte0, &uuid3bytes.byte0, 16));
}

TEST(CFUUID, GetConstant) {
    // Validate CFUUIDGetConstantUUIDWithBytes
    CFUUIDRef uuid4 = CFUUIDGetConstantUUIDWithBytes(
        NULL, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    CFUUIDBytes uuid4bytes = CFUUIDGetUUIDBytes(uuid4);
    for (int i = 0; i < 15; i++) {
        ASSERT_EQ(0xFF, ((uint8_t*)&uuid4bytes.byte0)[i]);
    }

    CFUUIDRef uuid5 = CFUUIDGetConstantUUIDWithBytes(
        NULL, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    CFUUIDRef uuid6 = CFUUIDGetConstantUUIDWithBytes(
        NULL, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE);

    // uuid4 and uuid5 should have the same address, while uuid6 will necessarily have a different address
    ASSERT_EQ(uuid4, uuid5);
    ASSERT_NE(uuid5, uuid6);
}