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
#include <Foundation/NSMutableSet.h>
#import "BridgeHelpers.h"

@interface NSSetConcrete : NSMutableSet

BRIDGED_CLASS_REQUIRED_DECLS

- (instancetype)init;
- (instancetype)initWithObjects:(id*)objects count:(unsigned)count;
@property (readonly) NSUInteger count;
- (id)member:(id)object;
- (NSEnumerator*)objectEnumerator;

- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)addObject:(id)object;
- (void)removeObject:(id)object;
- (void)removeAllObjects;

@end