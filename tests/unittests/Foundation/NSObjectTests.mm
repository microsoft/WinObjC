//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <objc/runtime.h>

#define TEST_PREFIX Foundation_NSObject_Tests
#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)
#define TEST_IDENT(x) CONCAT(TEST_PREFIX, _##x)

typedef struct {
    int a;
    float b;
} MixedStruct;

@interface TEST_IDENT (BaseClass) : NSObject
- (void)methodWithMixedStructArg:(MixedStruct)arg;
- (MixedStruct)methodWithMixedStructReturn;
- (float)methodWithChangingReturnType;
@end

@interface TEST_IDENT (DerivedClass) : TEST_IDENT(BaseClass)
- (void)methodExtantOnlyOnDerivedType;
- (MixedStruct)methodWithMixedStructReturn;
- (int)methodWithChangingReturnType;
@end

@implementation TEST_IDENT (BaseClass)
- (void)methodWithMixedStructArg:(MixedStruct)arg {
}
- (MixedStruct)methodWithMixedStructReturn {
    return { 1, 1.0f };
}
- (float)methodWithChangingReturnType {
    return 1.0;
}
@end

@implementation TEST_IDENT (DerivedClass)
- (void)methodExtantOnlyOnDerivedType {
}
- (MixedStruct)methodWithMixedStructReturn {
    return { 2, 2.0f };
}
- (int)methodWithChangingReturnType {
    return 10;
}
@end

TEST(NSObject, InstanceMethodSignature) {
    // -[BaseClass methodWithMixedStructArg:] is a method that returns void and takes
    // a single public argument. Adding in self and _cmd (the selector) brings the true
    // argument count to 3.
    NSMethodSignature* base_mixedStructArg =
        [TEST_IDENT(BaseClass) instanceMethodSignatureForSelector:@selector(methodWithMixedStructArg:)];
    EXPECT_OBJCNE(nil, base_mixedStructArg);
    EXPECT_STREQ(@encode(void), [base_mixedStructArg methodReturnType]);
    EXPECT_EQ(0, [base_mixedStructArg methodReturnLength]);
    EXPECT_EQ(3, [base_mixedStructArg numberOfArguments]);
    EXPECT_STREQ(@encode(MixedStruct), [base_mixedStructArg getArgumentTypeAtIndex:2]);

    NSMethodSignature* base_mixedStructRet =
        [TEST_IDENT(BaseClass) instanceMethodSignatureForSelector:@selector(methodWithMixedStructReturn)];
    EXPECT_OBJCNE(nil, base_mixedStructRet);
    EXPECT_STREQ(@encode(MixedStruct), [base_mixedStructRet methodReturnType]);
    EXPECT_EQ(sizeof(MixedStruct), [base_mixedStructRet methodReturnLength]);
    EXPECT_EQ(2, [base_mixedStructRet numberOfArguments]);

    NSMethodSignature* base_changingRet =
        [TEST_IDENT(BaseClass) instanceMethodSignatureForSelector:@selector(methodWithChangingReturnType)];
    EXPECT_OBJCNE(nil, base_changingRet);
    EXPECT_STREQ(@encode(float), [base_changingRet methodReturnType]);
    EXPECT_EQ(sizeof(float), [base_changingRet methodReturnLength]);
    EXPECT_EQ(2, [base_changingRet numberOfArguments]);

    // Test that derived methods do not appear on parent classes.
    EXPECT_OBJCEQ(nil, [TEST_IDENT(BaseClass) instanceMethodSignatureForSelector:@selector(methodOnlyExtantOnDerivedType)]);

    // Test whether method signatures are inherited.
    NSMethodSignature* derived_mixedStructArg =
        [TEST_IDENT(DerivedClass) instanceMethodSignatureForSelector:@selector(methodWithMixedStructArg:)];
    EXPECT_OBJCNE(nil, derived_mixedStructArg);
    EXPECT_STREQ(@encode(void), [derived_mixedStructArg methodReturnType]);
    EXPECT_EQ(0, [derived_mixedStructArg methodReturnLength]);
    EXPECT_EQ(3, [derived_mixedStructArg numberOfArguments]);
    EXPECT_STREQ(@encode(MixedStruct), [derived_mixedStructArg getArgumentTypeAtIndex:2]);

    NSMethodSignature* derived_mixedStructRet =
        [TEST_IDENT(DerivedClass) instanceMethodSignatureForSelector:@selector(methodWithMixedStructReturn)];
    EXPECT_OBJCNE(nil, derived_mixedStructRet);
    EXPECT_STREQ(@encode(MixedStruct), [derived_mixedStructRet methodReturnType]);
    EXPECT_EQ(sizeof(MixedStruct), [derived_mixedStructRet methodReturnLength]);
    EXPECT_EQ(2, [derived_mixedStructRet numberOfArguments]);

    NSMethodSignature* derived_changingRet =
        [TEST_IDENT(DerivedClass) instanceMethodSignatureForSelector:@selector(methodWithChangingReturnType)];
    EXPECT_OBJCNE(nil, derived_changingRet);
    EXPECT_STREQ(@encode(int), [derived_changingRet methodReturnType]);
    EXPECT_EQ(sizeof(int), [derived_changingRet methodReturnLength]);
    EXPECT_EQ(2, [derived_changingRet numberOfArguments]);
}

@interface TEST_IDENT (DynamicResolution): NSObject
- (void)dynamicInstanceMethodForSignature:(int)x;
+ (void)dynamicClassMethodForSignature:(int)x;
- (void)dynamicInstanceMethodForResponseChecking;
+ (void)dynamicClassMethodForResponseChecking;
- (int)dynamicInstanceMethod;
+ (int)dynamicClassMethod;
@end

static void _voidImp(id self, SEL _cmd) {
}

static int _intImp(id self, SEL _cmd) {
    return 2048;
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"
@implementation TEST_IDENT (DynamicResolution)
+ (BOOL)resolveClassMethod:(SEL)method {
    IMP imp = nullptr;
    const char* types = nullptr;
    if (sel_isEqual(method, @selector(dynamicClassMethodForResponseChecking))) {
        imp = (IMP)&_voidImp;
        types = "v@:";
    } else if (sel_isEqual(method, @selector(dynamicClassMethodForSignature:))) {
        imp = (IMP)&_voidImp;
        types = "v@:i";
    } else if (sel_isEqual(method, @selector(dynamicClassMethod))) {
        imp = (IMP)&_intImp;
        types = "i@:";
    }
    if (imp) {
        class_addMethod(object_getClass(self), method, imp, types);
    }
    return imp != nullptr;
}

+ (BOOL)resolveInstanceMethod:(SEL)method {
    IMP imp = nullptr;
    const char* types = nullptr;
    if (sel_isEqual(method, @selector(dynamicInstanceMethodForResponseChecking))) {
        imp = (IMP)&_voidImp;
        types = "v@:";
    } else if (sel_isEqual(method, @selector(dynamicInstanceMethodForSignature:))) {
        imp = (IMP)&_voidImp;
        types = "v@:i";
    } else if (sel_isEqual(method, @selector(dynamicInstanceMethod))) {
        imp = (IMP)&_intImp;
        types = "i@:";
    }
    if (imp) {
        class_addMethod(self, method, imp, types);
    }
    return imp != nullptr;
}
@end
#pragma clang diagnostic pop

TEST(NSObject, DynamicRespondsToSelector) {
    EXPECT_TRUE([TEST_IDENT(DynamicResolution) respondsToSelector:@selector(dynamicClassMethodForResponseChecking)]);
    EXPECT_FALSE([TEST_IDENT(DynamicResolution) respondsToSelector:@selector(dynamicInstanceMethodForResponseChecking)]);
    EXPECT_TRUE([TEST_IDENT(DynamicResolution) instancesRespondToSelector:@selector(dynamicInstanceMethodForResponseChecking)]);
    EXPECT_FALSE([TEST_IDENT(DynamicResolution) instancesRespondToSelector:@selector(dynamicClassMethodForResponseChecking)]);
}

TEST(NSObject, DynamicClassResolution) {
    EXPECT_EQ(2048, [TEST_IDENT(DynamicResolution) dynamicClassMethod]);
    EXPECT_ANY_THROW([TEST_IDENT(DynamicResolution) dynamicInstanceMethod]);

    NSMethodSignature* signature = nil;
    ASSERT_OBJCNE(nil, signature = [TEST_IDENT(DynamicResolution) methodSignatureForSelector:@selector(dynamicClassMethodForSignature:)]);
    EXPECT_STREQ("i", [signature getArgumentTypeAtIndex:2]);

    EXPECT_OBJCEQ(nil, [TEST_IDENT(DynamicResolution) methodSignatureForSelector:@selector(dynamicInstanceMethodForSignature:)]);
}

TEST(NSObject, DynamicResolution) {
    id instance = [[[TEST_IDENT(DynamicResolution) alloc] init] autorelease];
    EXPECT_EQ(2048, [instance dynamicInstanceMethod]);
    EXPECT_ANY_THROW([instance dynamicClassMethod]);

    NSMethodSignature* signature = nil;
    ASSERT_OBJCNE(nil, signature = [instance methodSignatureForSelector:@selector(dynamicInstanceMethodForSignature:)]);
    EXPECT_STREQ("i", [signature getArgumentTypeAtIndex:2]);

    EXPECT_OBJCEQ(nil, [instance methodSignatureForSelector:@selector(dynamicClassMethodForSignature:)]);
}
