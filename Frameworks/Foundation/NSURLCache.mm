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
    /* annotate with type */ +(id) sharedURLCache {
        return sharedURLCache;
    }

    /* annotate with type */ -(id) cachedResponseForRequest:(id)request {
        return nil;
    }

    /* annotate with type */ +(void) setSharedURLCache:(id)cache {
        sharedURLCache = cache;
    }

    /* annotate with type */ -(void) removeAllCachedResponses {

    }

    /* annotate with type */ +(void) initialize {
        sharedURLCache.attach([self new]);
    }

    /* annotate with type */ -(void) setMemoryCapacity:(NSUInteger)capacity {
    
    }

    /* annotate with type */ -(void) setDiskCapacity:(NSUInteger)capacity {

    }

    -(unsigned) diskCapacity {
        return 1024 * 1024 * 1024;
    }

    /* annotate with type */ -(id) initWithMemoryCapacity:(NSUInteger)memCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(id)path {
        return self;
    }

    
@end

