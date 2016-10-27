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

#import <TestFramework.h>
#import <UIKit/UIFont.h>
#import <CoreText/CoreText.h>

TEST(UIFont, FamilyName) {
    UIFont* font = [UIFont fontWithName:@"Segoe UI" size:22];
    ASSERT_TRUE_MSG(font != nil, "Failed: Font is nil.");

    NSString* familyName = [font familyName];
    ASSERT_OBJCEQ_MSG(familyName, @"Segoe UI", "Failed: Incorrect font family name");
}

TEST(UIFont, FamilyNames) {
    NSArray<NSString*>* familyNames = [UIFont familyNames];
    ASSERT_TRUE_MSG(familyNames != nil, "Failed: familyNames is nil.");
    ASSERT_TRUE_MSG(familyNames.count > 0, "Failed: familyNames is empty.");

    for (id obj in familyNames) {
        ASSERT_TRUE_MSG(obj != nil, "Failed: The family name is nil.");
        ASSERT_TRUE_MSG([obj isKindOfClass:[NSString class]], "Failed: Incorrect object type in familyNames.");
    }
}

TEST(UIFont, FontNamesForFamilyName) {
    NSArray<NSString*>* familyNames = [UIFont familyNames];
    ASSERT_TRUE_MSG(familyNames != nil, "Failed: familyNames is nil.");
    ASSERT_TRUE_MSG(familyNames.count > 0, "Failed: familyNames is empty.");

    NSString* familyName = (NSString*)familyNames.firstObject;
    ASSERT_TRUE_MSG(familyName != nil, "Failed: The first object of familyNames is nil.");

    NSArray<NSString*>* fontNames = [UIFont fontNamesForFamilyName:familyName];
    ASSERT_TRUE_MSG(fontNames != nil, "Failed: fontNames is nil.");
    ASSERT_TRUE_MSG(fontNames.count > 0, "Failed: fontNames is empty.");

    for (id obj in fontNames) {
        ASSERT_TRUE_MSG(obj != nil, "Failed: The font name is nil.");
        ASSERT_TRUE_MSG([obj isKindOfClass:[NSString class]], "Failed: Incorrect object type in fontNames.");
    }
}

TEST(UIFont, CopyWithZone) {
    UIFont* font = [UIFont fontWithName:@"Segoe UI" size:22];
    NSUInteger count = [font retainCount];

    id newFont = [font copy];
    NSUInteger newCount = [font retainCount];

    ASSERT_TRUE_MSG([newFont isKindOfClass:[UIFont class]], "Failed: Incorrect object type.");
    ASSERT_TRUE_MSG(font == newFont, "Failed: newFont is not the same as font.");
    ASSERT_TRUE_MSG(newCount == count + 1, "Failed: font retainCount did not increase by 1 after it is copied.");

    [newFont release];
}

TEST(UIFont, FontWithName) {
    UIFont* fontPositiveWithName = [UIFont fontWithName:@"Segoe UI" size:10];
    UIFont* fontZeroWithName = [UIFont fontWithName:@"Segoe UI" size:0];
    UIFont* fontNegativeWithName = [UIFont fontWithName:@"Segoe UI" size:-10];

    ASSERT_TRUE_MSG([fontPositiveWithName pointSize] == 10, "Failed: Size of fontPositiveWithName is not positive.");
    ASSERT_EQ_MSG([UIFont systemFontSize], [fontZeroWithName pointSize], "Failed: Size of fontZeroWithName is not systemFontSize.");
    ASSERT_EQ_MSG([UIFont systemFontSize], [fontNegativeWithName pointSize], "Failed: Size of fontNegativeWithName is not systemFontSize.");
}

TEST(UIFont, FontWithSize) {
    UIFont* font = [UIFont fontWithName:@"Segoe UI" size:10];

    UIFont* fontPositiveWithSize = [font fontWithSize:10];
    UIFont* fontZeroWithSize = [font fontWithSize:0];
    UIFont* fontNegativeWithSize = [font fontWithSize:-10];

    ASSERT_TRUE_MSG([fontPositiveWithSize pointSize] == 10, "Failed: Size of fontPositiveWithSize is not positive.");
    ASSERT_TRUE_MSG([fontZeroWithSize pointSize] == 14, "Failed: Size of fontZeroWithSize is not systemtFontSize.");
    ASSERT_TRUE_MSG([fontNegativeWithSize pointSize] == 14, "Failed: Size of fontNegativeWithSize is not systemtFontSize.");
}

TEST(UIFont, FontWithDescriptor) {
    UIFontDescriptor* fontDescriptor = [UIFontDescriptor fontDescriptorWithName:@"Segoe UI" size:-10];
    UIFont* fontPositiveWithDescriptor = [UIFont fontWithDescriptor:fontDescriptor size:10];
    UIFont* fontZeroWithDescriptor = [UIFont fontWithDescriptor:fontDescriptor size:0];
    UIFont* fontNegativeWithDescriptor = [UIFont fontWithDescriptor:fontDescriptor size:-10];

    ASSERT_TRUE_MSG([fontPositiveWithDescriptor pointSize] == 10, "Failed: Size of fontPositiveWithDescriptor is not positive.");
    ASSERT_TRUE_MSG([fontZeroWithDescriptor pointSize] == 14, "Failed: Size of fontZeroWithDescriptor is not systemtFontSize.");
    ASSERT_TRUE_MSG([fontNegativeWithDescriptor pointSize] == 14, "Failed: Size of fontNegativeWithDescriptor is not systemtFontSize.");
}

TEST(UIFont, Description) {
    ASSERT_OBJCNE(nil, [[UIFont systemFontOfSize:12.0f] description]);
}

TEST(UIFont, Metrics) {
    float size = 22.0f;
    UIFont* font = [UIFont fontWithName:@"Segoe UI" size:size];
    ASSERT_OBJCEQ(@"Segoe UI", [font fontName]);

    ASSERT_NE(0, [font descender]);
    ASSERT_NE(0, [font ascender]);
    ASSERT_NE(0, [font capHeight]);
    ASSERT_NE(0, [font xHeight]);

    ASSERT_EQ(size, [font pointSize]);
}

TEST(UIFont, Bridging) {
    float size = 14.5f;
    NSString* name = @"Times New Roman Bold Italic";

    UIFont* uiFont = [UIFont fontWithName:name size:size];
    CTFontRef ctFont = CTFontCreateWithName((__bridge CFStringRef)name, size, nullptr);
    CFAutorelease(ctFont);

    ASSERT_OBJCEQ(uiFont, (id)ctFont);

    // Call CoreText function on UIFont
    ASSERT_OBJCEQ(name, (id)CFAutorelease(CTFontCopyFullName((__bridge CTFontRef)uiFont)));

    // Call UIKit function on CTFont
    ASSERT_EQ(size, [(__bridge UIFont*)ctFont pointSize]);
}