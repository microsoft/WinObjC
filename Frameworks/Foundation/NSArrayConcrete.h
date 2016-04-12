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
#pragma once
#import <Foundation/NSMutableArray.h>
#import "BridgeHelpers.h"

#pragma region Immutable Concrete Subclass
@interface NSArrayConcrete : NSArray

- (_Nullable instancetype)init;
- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objs count:(NSUInteger)count;
- (NSUInteger)count;
- (_Nonnull id)objectAtIndex:(NSUInteger)index;

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@interface NSMutableArrayConcrete : NSMutableArray

- (_Nullable instancetype)init;
- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objs count:(NSUInteger)count;
- (NSUInteger)count;
- (_Nonnull id)objectAtIndex:(NSUInteger)index;

- (_Nullable instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject* _Nonnull)obj;
- (void)insertObject:(NSObject* _Nonnull)objAddr atIndex:(NSUInteger)index;
- (void)addObject:(NSObject* _Nonnull)objAddr;

// Not actually necessary. Optimization here for CF backed array.
- (void)removeAllObjects;

@end
#pragma endregion

#pragma region NSCF Bridged Class
@interface NSCFArray : NSMutableArray

BRIDGED_CLASS_REQUIRED_DECLS

- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objs count:(NSUInteger)count;
- (NSUInteger)count;
- (_Nonnull id)objectAtIndex:(NSUInteger)index;

- (_Nullable instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject* _Nonnull)obj;
- (void)insertObject:(NSObject* _Nonnull)objAddr atIndex:(NSUInteger)index;
- (void)addObject:(NSObject* _Nonnull)objAddr;

// Not actually necessary. Optimization here for CF backed array.
- (void)removeAllObjects;
@end
#pragma endregion