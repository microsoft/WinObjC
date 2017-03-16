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
#import <CoreFoundation/CoreFoundation.h>
#import <CoreText/CoreText.h>

TEST(CTFontDescriptor, AttributesAreCopied) {
    CFMutableDictionaryRef originalAttributes =
        CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFAutorelease(originalAttributes);

    CTFontDescriptorRef fd = CTFontDescriptorCreateWithAttributes(originalAttributes);
    CFAutorelease(fd);

    // Add something to the original dictionary
    CFDictionaryAddValue(originalAttributes, CFSTR("TEST"), CFSTR("VALUE"));
    ASSERT_EQ(1, CFDictionaryGetCount(originalAttributes));

    CFDictionaryRef fdDict = CTFontDescriptorCopyAttributes(fd);
    CFAutorelease(fdDict);

    // Font descriptor's dictionary should be unaltered
    ASSERT_EQ(0, CFDictionaryGetCount(fdDict));
}

TEST(CTFontDescriptor, CreateCopyWithAttributes) {
    CFStringRef name = CFSTR("Helvetica");
    CTFontDescriptorRef fd = CTFontDescriptorCreateWithNameAndSize(name, 414.0f);
    CFAutorelease(fd);

    CFMutableDictionaryRef attributesToAdd =
        CFDictionaryCreateMutable(kCFAllocatorDefault, 0, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks);
    CFAutorelease(attributesToAdd);

    // Change the size
    float newSize = 10.0f;
    CFDictionaryAddValue(attributesToAdd,
                         kCTFontSizeAttribute,
                         CFAutorelease(CFNumberCreate(kCFAllocatorDefault, kCFNumberCGFloatType, &newSize)));

    // Add an unrelated attribute
    CFDictionaryAddValue(attributesToAdd, kCTFontURLAttribute, CFSTR("TestValue"));

    CTFontDescriptorRef newFd = CTFontDescriptorCreateCopyWithAttributes(fd, attributesToAdd);
    CFAutorelease(newFd);

    // Final set of attributes should be the same as attributesToAdd, plus name
    CFDictionaryAddValue(attributesToAdd, kCTFontNameAttribute, name);
    ASSERT_OBJCEQ((id)attributesToAdd, (id)CFAutorelease(CTFontDescriptorCopyAttributes(newFd)));
}

TEST(CTFontDescriptor, CreateMatchingDescriptors) {
    auto matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(nullptr, nullptr));
    EXPECT_EQ(nullptr, matching.get());

    auto descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithNameAndSize(CFSTR("ARIALMT"), 25.5));
    matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(descriptor, nullptr));

    // There should only be one font matching the font name
    ASSERT_EQ(1, CFArrayGetCount(matching));

    CTFontDescriptorRef first = static_cast<CTFontDescriptorRef>(CFArrayGetValueAtIndex(matching, 0));
    ASSERT_NE(nullptr, first);

    auto fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(first, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"ArialMT", static_cast<NSString*>(fontName.get()));

    NSDictionary* dict = @{(id)kCTFontFamilyNameAttribute : @"ARIAL" };
    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(descriptor, nullptr));

    // There should be at least four fonts in the Arial family (possibly more)
    CFIndex familyCount = CFArrayGetCount(matching);
    ASSERT_LE(4, familyCount);

    first = static_cast<CTFontDescriptorRef>(CFArrayGetValueAtIndex(matching, 0));
    ASSERT_NE(nullptr, first);

    fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(first, kCTFontNameAttribute)));

    // First font should be the "normal" font in the family
    EXPECT_OBJCEQ(@"ArialMT", static_cast<NSString*>(fontName.get()));

    NSMutableSet* mandatory = [NSMutableSet setWithObject:(id)kCTFontFamilyNameAttribute];
    dict = @{(id)kCTFontFamilyNameAttribute : @"ARIAL", (id)kCTFontStyleNameAttribute : @"IMPOSSIBLE" };

    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(descriptor, static_cast<CFSetRef>(mandatory)));

    // No fonts match the style attribute and it's not mandatory so it's ignored
    ASSERT_LE(familyCount, CFArrayGetCount(matching));

    first = static_cast<CTFontDescriptorRef>(CFArrayGetValueAtIndex(matching, 0));
    ASSERT_NE(nullptr, first);

    fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(first, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"ArialMT", static_cast<NSString*>(fontName.get()));

    [mandatory addObject:(id)kCTFontStyleNameAttribute];
    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(descriptor, static_cast<CFSetRef>(mandatory)));

    // But when it's mandatory no descriptors are returned
    ASSERT_EQ(0, CFArrayGetCount(matching));

    dict = @{(id)kCTFontFamilyNameAttribute : @"ARIAL", (id)kCTFontStyleNameAttribute : @"ITALIC" };
    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    matching = woc::MakeAutoCF<CFArrayRef>(CTFontDescriptorCreateMatchingFontDescriptors(descriptor, static_cast<CFSetRef>(mandatory)));

    // There should only be one matching font
    EXPECT_EQ(1, CFArrayGetCount(matching));

    first = static_cast<CTFontDescriptorRef>(CFArrayGetValueAtIndex(matching, 0));
    ASSERT_NE(nullptr, first);

    fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(first, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"Arial-ItalicMT", static_cast<NSString*>(fontName.get()));
}

TEST(CTFontDescriptor, CreateMatchingDescriptor) {
    auto match = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateMatchingFontDescriptor(nullptr, nullptr));
    EXPECT_EQ(nullptr, match);

    auto descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithNameAndSize(CFSTR("ARIALMT"), 25.5));
    match = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateMatchingFontDescriptor(descriptor, nullptr));
    ASSERT_NE(nullptr, match);

    auto fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(match, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"ArialMT", static_cast<NSString*>(fontName.get()));

    NSDictionary* dict = @{(id)kCTFontFamilyNameAttribute : @"ARIAL" };
    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    match = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateMatchingFontDescriptor(descriptor, nullptr));
    ASSERT_NE(nullptr, match);

    fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(match, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"ArialMT", static_cast<NSString*>(fontName.get()));

    dict = @{(id)kCTFontFamilyNameAttribute : @"ARIAL", (id)kCTFontStyleNameAttribute : @"ITALIC" };
    descriptor = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateWithAttributes(static_cast<CFDictionaryRef>(dict)));
    match = woc::MakeAutoCF<CTFontDescriptorRef>(CTFontDescriptorCreateMatchingFontDescriptor(descriptor, nullptr));
    fontName = woc::MakeAutoCF<CFStringRef>(static_cast<CFStringRef>(CTFontDescriptorCopyAttribute(match, kCTFontNameAttribute)));
    EXPECT_OBJCEQ(@"Arial-ItalicMT", static_cast<NSString*>(fontName.get()));
}