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

// Helper class used to check the behavior when subclassing NSPointerArray
@interface NSPointerArraySubClass : NSPointerArray
@end

@implementation NSPointerArraySubClass
@end

TEST(NSPointerArray, SanityTest) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];

    [array addPointer:@(1)];
    [array addPointer:nullptr];
    [array addPointer:@"a string"];

    ASSERT_EQ_MSG(array.count, 3, @"should have 3 items in the array.");
}

TEST(NSPointerArray, Subclassing) {
    NSPointerArraySubClass* s = [[NSPointerArraySubClass alloc] init];
    ASSERT_EQ_MSG(s, nil, @"It should not be possible to subclass NSPointerArray");
}

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

TEST(NSPointerArray, FastEnumeration) {
    void* ptrs[256];
    for (int i = 0; i < 256; i++) {
        ptrs[i] = static_cast<void*>(@(i));
    }

    NSPointerArray* array = [[NSPointerArray alloc] initWithOptions:NSPointerFunctionsOpaqueMemory];
    for (int i = 0; i < 256; i++) {
        [array addPointer:ptrs[i]];
    }

    NSUInteger idx = 0;
    for (NSNumber* p in array) {
        ASSERT_EQ_MSG([p intValue], idx, "Incorrect value.");
        idx++;
    }
    ASSERT_EQ_MSG(idx, 256, "Should have ran into 256 iterations");
}

TEST(NSPointerArray, AddPointer) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];

    ASSERT_EQ_MSG(array.count, 0, @"Incorrect number of elements in array");

    [array addPointer:@(1)];
    ASSERT_EQ_MSG(array.count, 1, @"Incorrect number of elements in array");

    [array addPointer:nullptr];
    ASSERT_EQ_MSG(array.count, 2, @"Incorrect number of elements in array");

    [array addPointer:@"a string"];
    ASSERT_EQ_MSG(array.count, 3, @"Incorrect number of elements in array");

    ASSERT_NE_MSG([array pointerAtIndex:0], nullptr, @"pointer at index 0 should not be null");
    ASSERT_EQ_MSG([array pointerAtIndex:1], nullptr, @"pointer at index 1 should be null");
    ASSERT_NE_MSG([array pointerAtIndex:2], nullptr, @"pointer at index 2 should not be null");
}

TEST(NSPointerArray, AllObjects) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];
    [array addPointer:@1];
    [array addPointer:@2];
    [array addPointer:nullptr];
    [array addPointer:@"a string"];

    BOOL equal = [array.allObjects isEqual:@[ @1, @2, @"a string" ]];
    ASSERT_TRUE_MSG(equal, @"Should be equal");
}

TEST(NSPointerArray, SetCount) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];

    NSUInteger notify = 0;

    for (int i = 0; i < 10; i++) {
        DummyTestClass* c = [[DummyTestClass alloc] initWithNotifyPtr:&notify];
        [array addPointer:c];
        [c release];
    }

    ASSERT_EQ_MSG(notify, 0, "Objects should have been retained by the array");

    array.count = 6;
    ASSERT_EQ_MSG(notify, 4, "Four objects should have been released by the array");

    array.count = 8;
    for (int i = 0; i < 6; i++) {
        ASSERT_NE_MSG([array pointerAtIndex:i], nullptr, "Pointer should not be null");
    }

    for (int i = 6; i < 8; i++) {
        ASSERT_EQ_MSG([array pointerAtIndex:i], nullptr, "Pointer should be null");
    }

    array.count = 0;
    ASSERT_EQ_MSG(notify, 10, "All objects should be deallocated");
}

TEST(NSPointerArray, Insert) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];
    [array addPointer:@1];
    [array addPointer:@3];

    BOOL equal1 = [array.allObjects isEqual:@[ @1, @3 ]];
    ASSERT_TRUE_MSG(equal1, @"Incorrect content");

    [array insertPointer:@2 atIndex:1];
    BOOL equal2 = [array.allObjects isEqual:@[ @1, @2, @3 ]];
    ASSERT_TRUE_MSG(equal2, @"Incorrect content");

    [array insertPointer:@4 atIndex:3];
    BOOL equal3 = [array.allObjects isEqual:@[ @1, @2, @3, @4 ]];
    ASSERT_TRUE_MSG(equal3, @"Incorrect content");
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

TEST(NSPointerArray, Compact) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];
    [array addPointer:nullptr];
    [array addPointer:@1];
    [array addPointer:nullptr];
    [array addPointer:@3];

    ASSERT_EQ_MSG(array.count, 4, @"Incorrect size");

    [array compact];
    ASSERT_EQ_MSG(array.count, 2, @"Incorrect size");

    BOOL equal = [array.allObjects isEqual:@[ @1, @3 ]];
    ASSERT_TRUE_MSG(equal, @"Incorrect content");

    [array compact];
    ASSERT_EQ_MSG(array.count, 2, @"Incorrect size");
}

TEST(NSPointerArray, Weak) {
    NSPointerArray* array = [NSPointerArray weakObjectsPointerArray];

    NSUInteger notify = 0;
    DummyTestClass* dtc = [[DummyTestClass alloc] initWithNotifyPtr:&notify];

    [array addPointer:dtc];

    ASSERT_EQ_MSG(array.count, 1, @"Incorrect size");
    void* ptr = [array pointerAtIndex:0];
    ASSERT_EQ_MSG(ptr, static_cast<void*>(dtc), @"Incorrect pointer");
    ASSERT_EQ_MSG(notify, 0, @"Instance should still be retained");

    [dtc release];
    ASSERT_EQ_MSG(notify, 1, @"Instance should have been released");
    ASSERT_EQ_MSG(array.count, 1, @"Incorrect size");
    ptr = [array pointerAtIndex:0];
    ASSERT_EQ_MSG(ptr, static_cast<void*>(dtc), @"Incorrect pointer");
}

TEST(NSPointerArray, Strong) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];

    NSUInteger notify = 0;
    DummyTestClass* dtc = [[DummyTestClass alloc] initWithNotifyPtr:&notify];

    [array addPointer:dtc];

    ASSERT_EQ_MSG(array.count, 1, @"Incorrect size");
    void* ptr = [array pointerAtIndex:0];
    ASSERT_EQ_MSG(ptr, static_cast<void*>(dtc), @"Incorrect pointer");
    ASSERT_EQ_MSG(notify, 0, @"Instance should still be retained");

    [dtc release];
    ASSERT_EQ_MSG(notify, 0, @"Instance should have been retained by the array");
    ASSERT_EQ_MSG(array.count, 1, @"Incorrect size");
    ptr = [array pointerAtIndex:0];
    ASSERT_EQ_MSG(ptr, static_cast<void*>(dtc), @"Incorrect pointer");
}

TEST(NSPointerArray, Encoder) {
    NSPointerArray* array = [NSPointerArray strongObjectsPointerArray];
    [array addPointer:@1];
    [array addPointer:@2];
    [array addPointer:nullptr];
    [array addPointer:@"a string"];

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:array];

    NSPointerArray* other = static_cast<NSPointerArray*>([NSKeyedUnarchiver unarchiveObjectWithData:data]);
    BOOL equal = [other isEqual:array];
    ASSERT_TRUE_MSG(equal, @"Arrays should be equal");
}
