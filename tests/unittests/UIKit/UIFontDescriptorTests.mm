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
#import <UIKit/UIKit.h>

TEST(UIFontDescriptor, Bridging) {
    // Garbage values
    NSDictionary* fontAttributes = @{
        UIFontDescriptorCharacterSetAttribute : @34,
        UIFontDescriptorFamilyAttribute : @-523523.5,
        UIFontDescriptorMatrixAttribute : @"TESTING"
    };

    UIFontDescriptor* uiFontDescriptor = [UIFontDescriptor fontDescriptorWithFontAttributes:fontAttributes];
    CTFontDescriptorRef ctFontDescriptor = CTFontDescriptorCreateWithAttributes((__bridge CFDictionaryRef)fontAttributes);
    CFAutorelease(ctFontDescriptor);

    // UIKit can use CoreText functions
    ASSERT_OBJCEQ(fontAttributes[UIFontDescriptorMatrixAttribute],
                  (id)CFAutorelease(CTFontDescriptorCopyAttribute((__bridge CTFontDescriptorRef)uiFontDescriptor,
                                                                  (__bridge CFStringRef)UIFontDescriptorMatrixAttribute)));

    // CoreText can use UIKit functions
    ASSERT_OBJCEQ(fontAttributes, [(__bridge UIFontDescriptor*)ctFontDescriptor fontAttributes]);
}

TEST(UIFontDescriptor, NameAndSize) {
    NSString* name = @"Arial";
    const float size = 12.52f;
    UIFontDescriptor* fd = [UIFontDescriptor fontDescriptorWithName:name size:size];

    ASSERT_OBJCEQ(name, [fd objectForKey:UIFontDescriptorNameAttribute]);
    ASSERT_EQ(size, fd.pointSize);
}

TEST(UIFontDescriptor, BadPointSize) {
    UIFontDescriptor* fd = [UIFontDescriptor fontDescriptorWithFontAttributes:@{}];
    ASSERT_OBJCNE(nil, fd);
    ASSERT_EQ(0, [fd pointSize]);

    fd = fd = [UIFontDescriptor fontDescriptorWithFontAttributes:@{ UIFontDescriptorSizeAttribute : @"shouldn't be a string" }];
    ASSERT_OBJCNE(nil, fd);
    ASSERT_EQ(0, [fd pointSize]);
}

TEST(UIFontDescriptor, ByAddingAttributes) {
    NSString* name = @"FontName";
    UIFontDescriptor* fd = [UIFontDescriptor fontDescriptorWithName:name size:144.34f];

    UIFontDescriptor* newFd = [fd fontDescriptorByAddingAttributes:@{
        UIFontDescriptorSizeAttribute : @10.0f,
        UIFontDescriptorMatrixAttribute : @"TESTING"
    }];

    NSDictionary* expectedAttributes =
        @{ UIFontDescriptorSizeAttribute : @10.0f,
           UIFontDescriptorMatrixAttribute : @"TESTING",
           UIFontDescriptorNameAttribute : name };
    ASSERT_OBJCEQ(expectedAttributes, [newFd fontAttributes]);
}