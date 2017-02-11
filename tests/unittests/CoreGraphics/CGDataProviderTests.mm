
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
#import <CoreGraphics/CoreGraphics.h>
#import <Starboard/SmartTypes.h>

#import <vector>
#import <numeric>

TEST(CGDataProvider, Create) {
    unsigned char rawData[1000];
    std::iota(rawData, rawData + 1000, 1);
    CGDataProviderCallbacks callbacks{ [](void* info, void* buffer, size_t count) {
                                          size_t size = std::min(count, (size_t)1000);
                                          std::memcpy(buffer, info, size);
                                          return size;
                                      },
                                       [](void* info, size_t count) {},
                                       nullptr,
                                       [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreate(rawData, &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(1000, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), 1000));
}

TEST(CGDataProvider, CreateLarge) {
    std::unique_ptr<size_t[]> rawData{ new size_t[12345678] };
    std::iota(rawData.get(), rawData.get() + 12345678, 1);
    CGDataProviderCallbacks callbacks{ [](void* info, void* buffer, size_t count) {
                                          static ptrdiff_t position = 0;
                                          size_t size = std::min(count, 12345678 * sizeof(size_t) - position);
                                          std::memcpy(buffer, (char*)info + position, size);
                                          position += size;
                                          return size;
                                      },
                                       [](void* info, size_t count) {},
                                       nullptr,
                                       [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreate(rawData.get(), &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(12345678 * sizeof(size_t), CFDataGetLength(data.get()));
    EXPECT_NE(rawData.get(), (size_t*)CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData.get(), CFDataGetBytePtr(data.get()), 12345678 * sizeof(size_t)));
}

TEST(CGDataProvider, CreateWithData) {
    const size_t size = 1000;
    unsigned char rawData[size];
    std::iota(rawData, rawData + size, 1);
    woc::unique_cf<CGDataProviderRef> provider{
        CGDataProviderCreateWithData(nullptr, rawData, size, [](void* info, const void* data, size_t size) {})
    };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(size, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), size));
}

TEST(CGDataProvider, CreateDirect) {
    const size_t size = 1000;
    unsigned char rawData[size];
    std::iota(rawData, rawData + size, 1);
    CGDataProviderDirectCallbacks callbacks{ 0,
                                             [](void* info) { return (const void*)info; },
                                             [](void* info, const void* pointer) {},
                                             nullptr,
                                             [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateDirect(rawData, size, &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(size, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), size));
}

TEST(CGDataProvider, CreateDirectAccess) {
    const size_t size = 1000;
    unsigned char rawData[size];
    std::iota(rawData, rawData + size, 1);
    CGDataProviderDirectAccessCallbacks callbacks{ [](void* info) { return (const void*)info; },
                                                   [](void* info, const void* pointer) {},
                                                   nullptr,
                                                   [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateDirectAccess(rawData, size, &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(size, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), size));
}

TEST(CGDataProvider, CreateSequential) {
    unsigned char rawData[1000];
    std::iota(rawData, rawData + 1000, 1);
    CGDataProviderSequentialCallbacks callbacks{ 0,
                                                 [](void* info, void* buffer, size_t count) {
                                                     size_t size = std::min(count, (size_t)1000);
                                                     std::memcpy(buffer, info, size);
                                                     return size;
                                                 },
                                                 [](void* info, off_t count) { return count; },
                                                 nullptr,
                                                 [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateSequential(rawData, &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(1000, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), 1000));
}

TEST(CGDataProvider, CreateSequentialLarge) {
    std::unique_ptr<size_t[]> rawData{ new size_t[12345678] };
    std::iota(rawData.get(), rawData.get() + 12345678, 1);
    CGDataProviderSequentialCallbacks callbacks{ 0,
                                                 [](void* info, void* buffer, size_t count) {
                                                     static ptrdiff_t position = 0;
                                                     size_t size = std::min(count, 12345678 * sizeof(size_t) - position);
                                                     std::memcpy(buffer, (char*)info + position, size);
                                                     position += size;
                                                     return size;
                                                 },
                                                 [](void* info, off_t count) { return count; },
                                                 nullptr,
                                                 [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateSequential(rawData.get(), &callbacks) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(12345678 * sizeof(size_t), CFDataGetLength(data.get()));
    EXPECT_NE(rawData.get(), (size_t*)CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData.get(), CFDataGetBytePtr(data.get()), 12345678 * sizeof(size_t)));
}

TEST(CGDataProvider, CreateWithCFData) {
    const size_t size = 1000;
    unsigned char rawData[size];
    std::iota(rawData, rawData + size, 1);
    woc::unique_cf<CFDataRef> originalData{ CFDataCreateWithBytesNoCopy(nullptr, (const UInt8*)rawData, size, kCFAllocatorNull) };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateWithCFData(originalData.get()) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(size, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), size));
}

TEST(CGDataProvider, CreateWithFilename) {
    auto fullPath = GetCurrentTestDirectory();
    NSString* relativePath = @"/data/WinObjC.ttf";
    NSString* path = [@(fullPath.c_str()) stringByAppendingPathComponent:relativePath];
    const char* filename = [path UTF8String];
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreateWithFilename(filename) };
    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };

    // Size of the data from the file
    EXPECT_EQ(1452, CFDataGetLength(data.get()));
    EXPECT_NE(nullptr, CFDataGetBytePtr(data.get()));
}

TEST(CGDataProvider, CreateEmpty) {
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreate(nullptr, nullptr) };
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateDirect(nullptr, 0, nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateDirectAccess(nullptr, 0, nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateSequential(nullptr, nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateWithURL(nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateWithCFData(nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateWithFilename(nullptr));
    EXPECT_EQ(nullptr, provider);
    provider.reset(CGDataProviderCreateWithData(nullptr, nullptr, 0, nullptr));
    EXPECT_EQ(nullptr, provider);
}

TEST(CGDataProvider, ShouldCopyCallbacks) {
    unsigned char rawData[1000];
    std::iota(rawData, rawData + 1000, 1);
    CGDataProviderCallbacks callbacks{ [](void* info, void* buffer, size_t count) {
                                          size_t size = std::min(count, (size_t)1000);
                                          std::memcpy(buffer, info, size);
                                          return size;
                                      },
                                       [](void* info, size_t count) {},
                                       nullptr,
                                       [](void* info) {} };
    woc::unique_cf<CGDataProviderRef> provider{ CGDataProviderCreate(rawData, &callbacks) };
    callbacks = { nullptr, nullptr, nullptr, nullptr };

    woc::unique_cf<CFDataRef> data{ CGDataProviderCopyData(provider.get()) };
    EXPECT_EQ(1000, CFDataGetLength(data.get()));
    EXPECT_NE(rawData, CFDataGetBytePtr(data.get()));
    EXPECT_EQ(0, std::memcmp(rawData, CFDataGetBytePtr(data.get()), 1000));
}