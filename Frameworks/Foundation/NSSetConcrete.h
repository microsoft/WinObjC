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
#import <Foundation/NSMutableSet.h>
#import "BridgeHelpers.h"

#pragma region Immutable Concrete Subclass
@interface NSSetConcrete : NSSet

- (_Nullable instancetype)init;
- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count;
@property (readonly) NSUInteger count;
- (id _Nullable)member:(id _Nonnull)object;
- (NSEnumerator* _Nonnull)objectEnumerator;

@end
#pragma endregion

#pragma region Mutable Concrete Subclass
@interface NSMutableSetConcrete : NSMutableSet

- (_Nullable instancetype)init;
- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count;
@property (readonly) NSUInteger count;
- (id _Nullable)member:(id _Nonnull)object;
- (NSEnumerator* _Nonnull)objectEnumerator;

- (_Nullable instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)addObject:(id _Nonnull)object;
- (void)removeObject:(id _Nonnull)object;
- (void)removeAllObjects;

@end
#pragma endregion

#pragma region NSCF Bridged Class
@interface NSCFSet : NSMutableSet

BRIDGED_CLASS_REQUIRED_DECLS

- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count;
@property (readonly) NSUInteger count;
- (id _Nullable)member:(id _Nonnull)object;
- (NSEnumerator* _Nonnull)objectEnumerator;

- (_Nullable instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)addObject:(id _Nonnull)object;
- (void)removeObject:(id _Nonnull)object;
- (void)removeAllObjects;

@end
#pragma endregion