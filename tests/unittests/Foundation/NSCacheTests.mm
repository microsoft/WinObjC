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

#include <TestFramework.h>
#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>
#import <ErrorHandling.h>
#include <Windows.h>

#define TEST_PREFIX Foundation_NSCache_Tests
#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)
#define TEST_IDENT(x) CONCAT(TEST_PREFIX, _##x)

@interface TEST_IDENT(BlockDelegate) : NSObject <NSCacheDelegate> {
    StrongId<void(^)(NSCache*, id)> _block;
}
+ (instancetype)delegateWithBlock:(void(^)(NSCache*, id))block;
@end

@implementation TEST_IDENT(BlockDelegate)
+ (instancetype)delegateWithBlock:(void(^)(NSCache*, id))block {
    return [[[self alloc] initWithBlock:block] autorelease];
}

- (instancetype)initWithBlock:(void(^)(NSCache*, id))block {
    if (self = [super init]) {
        _block = block;
    }
    return self;
}

- (void)cache:(NSCache*)cache willEvictObject:(id)object {
    _block(cache, object);
}
@end


TEST(NSCache, Sanity) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    EXPECT_NO_THROW([cache setObject:@"object" forKey:@"key"]);
    EXPECT_OBJCEQ(@"object", [cache objectForKey:@"key"]);

    // A lookup with a different key with the same hash should produce the same value.
    EXPECT_OBJCEQ(@"object", [cache objectForKey:[[@"key" mutableCopy] autorelease]]);

    EXPECT_OBJCEQ(nil, [cache objectForKey:@"nonexistentKey"]);

    EXPECT_NO_THROW(cache.name = @"Cache Name");
    EXPECT_OBJCEQ(@"Cache Name", cache.name);
}

TEST(NSCache, CountEviction) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.countLimit = 500);
    for(int i = 0; i < 1000; ++i) {
        EXPECT_NO_THROW([cache setObject:@(i) forKey:@(i)]);
    }

    // 0 was the earliest object: it should be long gone.
    EXPECT_OBJCEQ(nil, [cache objectForKey:@(0)]);
    // 600 was one of the later objects: it should not be gone.
    EXPECT_OBJCNE(nil, [cache objectForKey:@(600)]);
}

TEST(NSCache, LRUEviction) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.countLimit = 500);
    for(int i = 0; i < 1000; ++i) {
        EXPECT_NO_THROW([cache setObject:@(i) forKey:@(i)]);

        // brute force: use 0 every iteration through the loop so that it is always the most recently used.
        EXPECT_OBJCEQ(@(0), [cache objectForKey:@(0)]);
    }

    // 0 was the earliest object, but it should have been constantly refreshed.
    EXPECT_OBJCNE(nil, [cache objectForKey:@(0)]);
    // 1 was still an early object, but nobody cared about it.
    EXPECT_OBJCEQ(nil, [cache objectForKey:@(1)]);
}

TEST(NSCache, CostEviction) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.totalCostLimit = 499500); // 0 + 1 + ... + 998 + 999
    for(int i = 0; i < 1000; ++i) {
        EXPECT_NO_THROW([cache setObject:@(i) forKey:@(i) cost:i]);
    }

    // we're still under cost limit, so all objects should be alive.
    EXPECT_OBJCNE(nil, [cache objectForKey:@(0)]);
    EXPECT_OBJCNE(nil, [cache objectForKey:@(600)]);

    // This should evict the first n objects whose costs add up to ~1000. That's 1-45. 1-44 cost 990, which isn't enough; 45 costs 45, and puts us at 1035.
    EXPECT_NO_THROW([cache setObject:@(1000) forKey:@(1000) cost:1000]);
    // skip item 0: it just got refreshed and doesn't cost anything anyway.
    for(int i = 1; i <= 45; ++i) {
        EXPECT_OBJCEQ_MSG(nil, [cache objectForKey:@(i)], "item %d", i);
    }

    EXPECT_OBJCNE(nil, [cache objectForKey:@(46)]);
    EXPECT_OBJCNE(nil, [cache objectForKey:@(1000)]);
}

TEST(NSCache, Delegate) {
    NSCache* cache = nil;

    __block NSCache* lastEvictedCache = nil;
    __block id lastEvictedObject = nil;

    id<NSCacheDelegate> delegate = [TEST_IDENT(BlockDelegate) delegateWithBlock:^(NSCache* cache, id object){
        lastEvictedCache = cache;
        lastEvictedObject = object;
    }];
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.delegate = delegate);

    /* Test that a replaced key evicts the old object. */
    [cache setObject:@"one" forKey:@"key"];
    [cache setObject:@"two" forKey:@"key"];

    EXPECT_OBJCEQ(cache, lastEvictedCache);
    EXPECT_OBJCEQ(@"one", lastEvictedObject);

    /* Test that an object removed via normal means evicts it. */
    [cache removeObjectForKey:@"key"];

    EXPECT_OBJCEQ(@"two", lastEvictedObject);

    /* Test that inserting an object over cost causes it to be added and then evicted. */
    ASSERT_NO_THROW(cache.totalCostLimit = 10);
    [cache setObject:@"huge" forKey:@"key" cost:11];

    EXPECT_OBJCEQ(@"huge", lastEvictedObject);
}

@interface TEST_IDENT(Discardable) : NSObject <NSDiscardableContent> {
    long _accessCount;
    bool _discarded;
}
@end

@implementation TEST_IDENT(Discardable)
- (instancetype)init {
    if (self = [super init]) {
        _accessCount = 1;
        _discarded = false;
    }
    return self;
}

- (BOOL)beginContentAccess {
    if (_discarded) {
        return NO;
    }
    InterlockedIncrement(&_accessCount);
    return YES;
}

- (void)endContentAccess {
    if (_discarded || _accessCount == 0) {
        return;
    }
    InterlockedDecrement(&_accessCount);
}

- (void)discardContentIfPossible {
    if (_accessCount != 0) {
        return;
    }
    _discarded = true;
}

- (BOOL)isContentDiscarded {
    return _discarded;
}
@end

/* Do not discard accessed objects, even on remove. */
TEST(NSCache, DiscardableContent_KeepAccessedOnRemove) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);

    StrongId<id<NSDiscardableContent>> disc = [[TEST_IDENT(Discardable) new] autorelease];

    ASSERT_NO_THROW([cache setObject:disc forKey:@"disc"]);
    EXPECT_NO_THROW([cache removeObjectForKey:@"disc"]);
    EXPECT_FALSE([disc isContentDiscarded]); // This should not have been discarded, as it started out accessed.
}

/* Discard unaccessed objects on remove. */
TEST(NSCache, DiscardableContent_DiscardStaleOnRemove) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);

    StrongId<id<NSDiscardableContent>> disc = [[TEST_IDENT(Discardable) new] autorelease];

    ASSERT_NO_THROW([cache setObject:disc forKey:@"disc"]);
    [disc endContentAccess]; // these start with the content "accessed."
    EXPECT_NO_THROW([cache removeObjectForKey:@"disc"]);
    EXPECT_TRUE([disc isContentDiscarded]); // This *should* have been discarded, as we removed its +1 access.
}

/* Discard unaccessed objects on cost evict. */
TEST(NSCache, DiscardableContent_DiscardAndRemoveOnEvict) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.totalCostLimit = 50);

    StrongId<id<NSDiscardableContent>> disc = [[TEST_IDENT(Discardable) new] autorelease];

    [disc endContentAccess];
    ASSERT_NO_THROW([cache setObject:disc forKey:@"disc" cost:100]); // Intentionally add over cost to force eviction.
    EXPECT_TRUE([disc isContentDiscarded]);
    EXPECT_OBJCEQ(nil, [cache objectForKey:@"disc"]);
}

/* Discard unaccessed objects on cost evict, but keep them in the cache. */
TEST(NSCache, DiscardableContent_DiscardButKeepOnEvict) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.totalCostLimit = 50);
    ASSERT_NO_THROW(cache.evictsObjectsWithDiscardedContent = NO);

    StrongId<id<NSDiscardableContent>> disc = [[TEST_IDENT(Discardable) new] autorelease];

    [disc endContentAccess];
    ASSERT_NO_THROW([cache setObject:disc forKey:@"disc" cost:100]); // Intentionally add over cost to force eviction.
    EXPECT_TRUE([disc isContentDiscarded]);
    EXPECT_OBJCNE(nil, [cache objectForKey:@"disc"]);
}

/* Discard unaccessed objects on removeAllObjects. */
TEST(NSCache, DiscardableContent_DiscardOnRemoveAll) {
    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    ASSERT_NO_THROW(cache.evictsObjectsWithDiscardedContent = NO);

    StrongId<NSMutableArray<id<NSDiscardableContent>>> discardables = [NSMutableArray array];
    for (int i = 0; i < 10; ++i) {
        id newDiscardable = [[TEST_IDENT(Discardable) new] autorelease];
        [newDiscardable endContentAccess];
        [discardables addObject:newDiscardable];
        ASSERT_NO_THROW_MSG([cache setObject:newDiscardable forKey:@(i)], "entry %d", i);;
    }

    EXPECT_NO_THROW([cache removeAllObjects]);

    for (int i = 0; i < 10; ++i) {
        EXPECT_OBJCEQ_MSG(nil, [cache objectForKey:@(i)], "entry %d", i);
        EXPECT_TRUE_MSG([[discardables objectAtIndex:i] isContentDiscarded], "entry %d", i);
    }
}

TEST(NSCache, AutoreleasedKeys) {
    WinObjC_SetZombiesEnabled(YES);
    auto defer = wil::ScopeExit([]() { WinObjC_SetZombiesEnabled(NO); });

    NSCache* cache = nil;
    ASSERT_NO_THROW(cache = [[NSCache new] autorelease]);
    {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        for (unsigned int i = 0; i < 100; ++i) {
            NSString* key = [[NSString alloc] initWithFormat:@"key-%u", i]; // +1 (1)
            EXPECT_NO_THROW([cache setObject:@"whatever" forKey:key]);      // +1 (2)
            [key release];                                                  // -1 (1)
        }
        [pool release];
    }

    {
        NSAutoreleasePool* pool = [NSAutoreleasePool new];
        ASSERT_NO_THROW([cache setObject:@"stomp" forKey:@"key-0"]);
        [pool release];
    }

    ASSERT_NO_THROW([cache removeObjectForKey:@"key-0"]);

    ASSERT_NO_THROW([cache setObject:@"stomp" forKey:@"key-1"]);
    ASSERT_NO_THROW([cache removeObjectForKey:@"key-1"]);
}