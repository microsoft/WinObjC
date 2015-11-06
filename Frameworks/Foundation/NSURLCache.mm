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

@implementation NSURLCache

/**
 @Status Stub
*/
+ (id)sharedURLCache {
    UNIMPLEMENTED();
    return sharedURLCache;
}

/**
 @Status Stub
*/
- (id)cachedResponseForRequest:(id)request {
    UNIMPLEMENTED();
    return nil;
}

/**
 @Status Stub
*/
+ (void)setSharedURLCache:(id)cache {
    UNIMPLEMENTED();
    sharedURLCache = cache;
}

/**
 @Status Stub
*/
- (void)removeAllCachedResponses {
    UNIMPLEMENTED();
}

+ (void)initialize {
    sharedURLCache.attach([self new]);
}

/**
 @Status Stub
*/
- (void)setMemoryCapacity:(NSUInteger)capacity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setDiskCapacity:(NSUInteger)capacity {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (unsigned)diskCapacity {
    UNIMPLEMENTED();
    return 1024 * 1024 * 1024;
}

/**
 @Status Stub
*/
- (id)initWithMemoryCapacity:(NSUInteger)memCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(id)path {
    UNIMPLEMENTED();
    return self;
}

@end
