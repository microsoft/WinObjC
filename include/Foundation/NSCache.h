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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@protocol NSCacheDelegate;

FOUNDATION_EXPORT_CLASS
@interface NSCache <KeyType, ObjectType> : NSObject
@property (copy) NSString* name;
- (ObjectType)objectForKey:(KeyType)key;
- (void)setObject:(ObjectType)obj forKey:(KeyType)key;
- (void)setObject:(ObjectType)obj forKey:(KeyType)key cost:(NSUInteger)num;
- (void)removeObjectForKey:(KeyType)key;
- (void)removeAllObjects;
@property NSUInteger countLimit;
@property NSUInteger totalCostLimit;
@property BOOL evictsObjectsWithDiscardedContent;
@property (assign) id<NSCacheDelegate> delegate;
@end

@protocol NSCacheDelegate <NSObject>
@optional
- (void)cache:(NSCache*)cache willEvictObject:(id)obj;
@end
