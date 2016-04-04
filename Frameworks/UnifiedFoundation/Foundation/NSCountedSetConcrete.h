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
#import <Foundation/NSMutableData.h>
#import "BridgeHelpers.h"

// CFBag is not technically toll-free bridgeable with NSCountedSet
// However, since it shares a similar relationship as toll-free bridging, reuse the same pattern
#pragma region Immutable Concrete Subclass
@interface NSCountedSetConcrete : NSCountedSet

- (_Nullable instancetype)init;
- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objs count:(NSUInteger)count;
- (_Nullable instancetype)initWithCapacity:(NSUInteger)capacity;
- (NSUInteger)countForObject:(id _Nonnull)object;
- (unsigned)count;
- (NSEnumerator* _Nonnull)objectEnumerator;
- (id _Nullable)member:(id _Nonnull)object;
- (void)addObject:(id _Nonnull)object;
- (void)removeObject:(id _Nonnull)object;
- (void)removeAllObjects;

@end
#pragma endregion

#pragma region NSCF Bridged Class
@interface NSCFCountedSet : NSCountedSet

BRIDGED_CLASS_REQUIRED_DECLS

- (_Nullable instancetype)initWithObjects:(id _Nonnull const* _Nullable)objs count:(NSUInteger)count;
- (_Nullable instancetype)initWithCapacity:(NSUInteger)capacity;
- (NSUInteger)countForObject:(id _Nonnull)object;
- (unsigned)count;
- (NSEnumerator* _Nonnull)objectEnumerator;
- (id _Nullable)member:(id _Nonnull)object;
- (void)addObject:(id _Nonnull)object;
- (void)removeObject:(id _Nonnull)object;
- (void)removeAllObjects;

@end
#pragma endregion