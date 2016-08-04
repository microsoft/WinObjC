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

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <windows.h>

// Expose some private functions of the NSPointerArray implementation
@interface NSPointerArray (Private)
- (NSUInteger)allocatedCount;
- (const void* const)containerPtr;
@end

// Helper class, used to track deallocations
@interface DummyTestClass : NSObject {
    NSUInteger* _notify;
}
@end

@implementation DummyTestClass
- (instancetype)initWithNotifyPtr:(NSUInteger*)notify {
    if (self = [super init]) {
        _notify = notify;
    }
    return self;
}

- (void)dealloc {
    *_notify = *_notify + 1;
    [super dealloc];
}
@end

TEST(NSPointerArray, Equality) {
    NSPointerArray* arr1 = [NSPointerArray strongObjectsPointerArray];
    [arr1 addPointer:@1];
    [arr1 addPointer:nullptr];
    [arr1 addPointer:@2];

    NSPointerArray* arr2 = [NSPointerArray strongObjectsPointerArray];
    [arr2 addPointer:@1];
    [arr2 addPointer:nullptr];
    [arr2 addPointer:@2];
    BOOL equalArray1Array2 = [arr1 isEqual:arr2];
    ASSERT_TRUE_MSG(equalArray1Array2, @"Both arrays should be equal");

    NSPointerArray* arr3 = [NSPointerArray strongObjectsPointerArray];
    [arr3 addPointer:@1];
    [arr3 addPointer:@2];
    [arr3 addPointer:nullptr];
    BOOL equalArray1Array3 = [arr1 isEqual:arr3];
    ASSERT_FALSE_MSG(equalArray1Array3, @"Both arrays should not be equal");

    // Check the behaviour of the equality on C strings
    const char* s1 = "first string";
    const char* s2 = "second string";
    const char* s3 = "third string";

    NSPointerArray* cPtrArray1 = [NSPointerArray pointerArrayWithOptions:NSPointerFunctionsCStringPersonality];
    [cPtrArray1 addPointer:nullptr];
    [cPtrArray1 addPointer:const_cast<char*>(s1)];
    [cPtrArray1 addPointer:const_cast<char*>(s2)];

    char* dup_s1 = _strdup(s1);

    NSPointerArray* cPtrArray2 = [NSPointerArray pointerArrayWithOptions:NSPointerFunctionsCStringPersonality];
    [cPtrArray2 addPointer:nullptr];
    [cPtrArray2 addPointer:dup_s1];
    [cPtrArray2 addPointer:const_cast<char*>(s2)];
    BOOL equalCStrA1A2 = [cPtrArray1 isEqual:cPtrArray2];

    NSPointerArray* cPtrArray3 = [NSPointerArray pointerArrayWithOptions:NSPointerFunctionsCStringPersonality];
    [cPtrArray3 addPointer:nullptr];
    [cPtrArray3 addPointer:dup_s1];
    [cPtrArray3 addPointer:const_cast<char*>(s3)];
    BOOL equalCStrA1A3 = [cPtrArray1 isEqual:cPtrArray3];

    NSUInteger h1 = [cPtrArray1 hash];
    NSUInteger h2 = [cPtrArray2 hash];
    NSUInteger h3 = [cPtrArray3 hash];

    ASSERT_TRUE_MSG(equalCStrA1A2, "Arrays of C strings should be equal");
    ASSERT_FALSE_MSG(equalCStrA1A3, "Arrays of C strings should not be equal");

    ASSERT_EQ_MSG(h1, h2, "Hash value of C strings arrays should be equal");
    ASSERT_NE_MSG(h1, h3, "Hash value of C strings arrays should not be equal");

    free(dup_s1);
}

TEST(NSPointerArray, RemovePointer) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];

    const int total = 100;
    NSUInteger notification = 0;
    for (int i = 0; i < total; i++) {
        [array addPointer:[[DummyTestClass alloc] initWithNotifyPtr:&notification]];
    }

    ASSERT_GE_MSG(array.allocatedCount, array.count, @"There should be more allocated element than elements in array");
    ASSERT_NE_MSG(array.containerPtr, nullptr, @"A container should have been allocated");

    for (int i = 0; i < total; i++) {
        [array removePointerAtIndex:array.count / 2];
        ASSERT_EQ_MSG(array.count, total - 1 - i, @"Incorrect number of elements released");
    }

    ASSERT_EQ_MSG(array.count, 0, @"Incorrect number of elements in array");
    ASSERT_EQ_MSG(array.allocatedCount, 0, @"There should be no allocated element in array");
    ASSERT_EQ_MSG(array.containerPtr, nullptr, @"Container should have been freed");
}