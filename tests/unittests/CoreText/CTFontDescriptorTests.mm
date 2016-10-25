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