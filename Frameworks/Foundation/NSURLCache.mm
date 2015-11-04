//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"
#include "Foundation/NSURLCache.h"

static idretain sharedURLCache;

@implementation NSURLCache : NSObject

/**
 @Status Stub
*/
+ (id)sharedURLCache {
    return sharedURLCache;
}

/**
 @Status Stub
*/
- (id)cachedResponseForRequest:(id)request {
    return nil;
}

/**
 @Status Stub
*/
+ (void)setSharedURLCache:(id)cache {
    sharedURLCache = cache;
}

/**
 @Status Stub
*/
- (void)removeAllCachedResponses {
}

+ (void)initialize {
    sharedURLCache.attach([self new]);
}

/**
 @Status Stub
*/
- (void)setMemoryCapacity:(NSUInteger)capacity {
}

/**
 @Status Stub
*/
- (void)setDiskCapacity:(NSUInteger)capacity {
}

/**
 @Status Stub
*/
- (unsigned)diskCapacity {
    return 1024 * 1024 * 1024;
}

/**
 @Status Stub
*/
- (id)initWithMemoryCapacity:(NSUInteger)memCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(id)path {
    return self;
}

@end
