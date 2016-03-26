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

#import <StubReturn.h>
#import <Foundation/NSProxy.h>

@implementation NSProxy
/**
 @Status Stub
 @Notes
*/
+ (id)alloc {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (id)allocWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)dealloc {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)finalize {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)forwardInvocation:(NSInvocation*)anInvocation {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSMethodSignature*)methodSignatureForSelector:(SEL)aSelector {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)respondsToSelector:(SEL)aSelector {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (Class) class {
    UNIMPLEMENTED();
    return StubReturn();
}

    /**
     @Status Stub
     @Notes
    */
    - (Class) class {
    UNIMPLEMENTED();
    return StubReturn();
}

    /**
     @Status Stub
     @Notes
    */
    - (BOOL)isEqual : (id)anObject {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)self {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isKindOfClass:(Class)aClass {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isMemberOfClass:(Class)aClass {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)respondsToSelector:(SEL)aSelector {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)conformsToProtocol:(Protocol*)aProtocol {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)performSelector:(SEL)aSelector {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)performSelector:(SEL)aSelector withObject:(id)anObject {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)performSelector:(SEL)aSelector withObject:(id)anObject withObject:(id)anotherObject {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isProxy {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)retain {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (oneway void)release {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)autorelease {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)retainCount {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
