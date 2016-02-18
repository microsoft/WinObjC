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
#import <Foundation/NSPointerArray.h>

@implementation NSPointerArray
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithOptions:(NSPointerFunctionsOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithPointerFunctions:(NSPointerFunctions*)functions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPointerArray*)pointerArrayWithOptions:(NSPointerFunctionsOptions)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPointerArray*)pointerArrayWithPointerFunctions:(NSPointerFunctions*)functions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPointerArray*)strongObjectsPointerArray {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPointerArray*)weakObjectsPointerArray {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void*)pointerAtIndex:(NSUInteger)index {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addPointer:(void*)pointer {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removePointerAtIndex:(NSUInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)insertPointer:(void*)item atIndex:(NSUInteger)index {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replacePointerAtIndex:(NSUInteger)index withPointer:(void*)item {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)compact {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id _Nonnull[])stackbuf count:(NSUInteger)len {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
