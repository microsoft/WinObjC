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

@class NSURLResponse;
@class NSData;
@class NSDictionary;

typedef enum {
    NSURLCacheStorageAllowed,
    NSURLCacheStorageAllowedInMemoryOnly,
    NSURLCacheStorageNotAllowed,
} NSURLCacheStoragePolicy;

FOUNDATION_EXPORT_CLASS
@interface NSCachedURLResponse : NSObject <NSCopying, NSSecureCoding>
- (instancetype)initWithResponse:(NSURLResponse*)response data:(NSData*)data;
- (instancetype)initWithResponse:(NSURLResponse*)response
                            data:(NSData*)data
                        userInfo:(NSDictionary*)userInfo
                   storagePolicy:(NSURLCacheStoragePolicy)storagePolicy;
@property (readonly, copy) NSData* data;
@property (readonly, copy) NSURLResponse* response;
@property (readonly) NSURLCacheStoragePolicy storagePolicy;
@property (readonly, copy) NSDictionary* userInfo;
@end
