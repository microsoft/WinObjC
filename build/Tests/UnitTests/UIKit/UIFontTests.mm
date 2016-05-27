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
#import <UIKit/UIFont.h>

TEST(UIFontTest, FamilyName) {
    UIFont* font = [UIFont fontWithName:@"SegoeUI" size:22];
    ASSERT_TRUE_MSG(font != nil, "Failed: Font is nil.");

    NSString* familyName = [font familyName];
    ASSERT_OBJCEQ_MSG(familyName, @"Segoe UI", "Failed: Incorrect font family name");
}

TEST(UIFontTest, FamilyNames) {
    NSArray<NSString*>* familyNames = [UIFont familyNames];
    ASSERT_TRUE_MSG(familyNames != nil, "Failed: familyNames is nil.");
    ASSERT_TRUE_MSG(familyNames.count > 0, "Failed: familyNames is empty.");

    for (id obj in familyNames) {
        ASSERT_TRUE_MSG(obj != nil, "Failed: The family name is nil.");
        ASSERT_TRUE_MSG([obj isKindOfClass:[NSString class]], "Failed: Incorrect object type in familyNames.");
    }
}

TEST(UIFontTest, FontNamesForFamilyName) {
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
