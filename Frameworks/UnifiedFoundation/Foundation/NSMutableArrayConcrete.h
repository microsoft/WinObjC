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
#include <Foundation/NSMutableArray.h>
#import "BridgeHelpers.h"

@interface NSMutableArrayConcrete : NSMutableArray

- (instancetype)init;
- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count;
- (NSUInteger)count;
- (id)objectAtIndex:(NSUInteger)index;

- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj;
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index;
- (void)addObject:(NSObject*)objAddr;

// Not actually necessary. Optimization here for CF backed array.
- (void)removeAllObjects;

@end