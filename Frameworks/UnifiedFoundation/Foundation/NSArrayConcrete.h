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

@interface NSArrayConcrete : NSMutableArray

+ (void)load;

+ (NSObject*)allocWithZone:(NSZone*)zone;
- (id)retain;
- (oneway void)release;
- (id)autorelease;
- (NSUInteger)retainCount;
- (void)dealloc;

- (NSArray*)initWithObjects:(id*)objs count:(NSUInteger)count;
- (NSUInteger)count;
- (id)objectAtIndex:(NSUInteger)index;

- (void)removeObjectAtIndex:(NSUInteger)index;
- (void)removeLastObject;
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj;
- (void)insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index;
- (void)addObject:(NSObject*)objAddr;

// Not actually necessary. Optimization here for CF backed array.
- (void)removeAllObjects;

@end