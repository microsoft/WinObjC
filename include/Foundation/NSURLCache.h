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
@class NSCachedURLResponse;
@class NSURLRequest;

FOUNDATION_EXPORT_CLASS
@interface NSURLCache : NSObject
+ (NSURLCache*)sharedURLCache;
+ (void)setSharedURLCache:(NSURLCache*)cache;
- (instancetype)initWithMemoryCapacity:(NSUInteger)memoryCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(NSString*)path;
- (NSCachedURLResponse*)cachedResponseForRequest:(NSURLRequest*)request;
- (void)storeCachedResponse:(NSCachedURLResponse*)cachedResponse forRequest:(NSURLRequest*)request;
- (void)removeAllCachedResponses;
- (void)removeCachedResponseForRequest:(NSURLRequest*)request;
@property (readonly) NSUInteger currentDiskUsage;
@property NSUInteger diskCapacity;
@property (readonly) NSUInteger currentMemoryUsage;
@property NSUInteger memoryCapacity;
@end
