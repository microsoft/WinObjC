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
@interface NSCache : NSObject
@property (copy) NSString* name STUB_METHOD;
- (id)objectForKey:(id)key STUB_METHOD;
- (void)setObject:(id)obj forKey:(id)key STUB_METHOD;
- (void)setObject:(id)obj forKey:(id)key cost:(NSUInteger)num STUB_METHOD;
- (void)removeObjectForKey:(id)key STUB_METHOD;
- (void)removeAllObjects STUB_METHOD;
@property NSUInteger countLimit STUB_PROPERTY;
@property NSUInteger totalCostLimit STUB_PROPERTY;
@property BOOL evictsObjectsWithDiscardedContent STUB_PROPERTY;
@property (assign) id<NSCacheDelegate> delegate STUB_PROPERTY;
@end

@protocol NSCacheDelegate <NSObject>
@optional
- (void)cache:(NSCache*)cache willEvictObject:(id)obj;

@end
