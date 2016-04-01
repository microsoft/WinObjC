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
#include <Foundation/NSMutableDictionary.h>
#import "BridgeHelpers.h"

@interface NSDictionaryConcrete : NSMutableDictionary

BRIDGED_CLASS_REQUIRED_DECLS

- (instancetype)init;
- (instancetype)initWithObjects:(id*)objs forKeys:(id*)keys count:(NSUInteger)count;
- (NSUInteger)count;
- (id)objectForKey:(id)key;
- (NSEnumerator*)keyEnumerator;

- (instancetype)initWithCapacity:(NSUInteger)numItems;
- (void)setObject:(id)anObject forKey:(id<NSCopying>)aKey;
- (void)removeObjectForKey:(id)key;

// Not actually necessary. Optimization here for CF backed dictionary.
- (void)removeAllObjects;
- (NSArray*)allValues;
- (NSArray*)allKeys;

@end