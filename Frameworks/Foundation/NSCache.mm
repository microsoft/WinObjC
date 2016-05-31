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

#import <Foundation/NSCache.h>

#import <Starboard/SmartTypes.h>

#include <list>
#include <unordered_map>

@interface _NSCacheEntry : NSObject
@property (nonatomic, assign) NSUInteger cost;
@property (nonatomic, retain) id key;
@property (nonatomic, retain) id object;
@property (nonatomic, assign) BOOL discardable;
@end

@implementation _NSCacheEntry
+ (instancetype)cacheEntryWithCost:(NSUInteger)cost key:(id)key object:(id)object {
    return [[[self alloc] initWithCost:cost key:key object:object] autorelease];
}

- (instancetype)initWithCost:(NSUInteger)cost key:(id)key object:(id)object {
    if (self = [super init]) {
        _cost = cost;
        _key = [key retain];
        _object = [object retain];
        _discardable = [object conformsToProtocol:@protocol(NSDiscardableContent)];
    }
    return self;
}

- (void)dealloc {
    [_key release];
    [_object release];
    [super dealloc];
}
@end

namespace std {
template <>
struct hash<id> {
    size_t operator()(const id& obj) const {
        return [obj hash];
    }
};
template <>
struct equal_to<id> {
    bool operator()(const id& left, const id& right) const {
        return [left isEqual:right];
    }
};
}

using cacheType = std::list<StrongId<_NSCacheEntry>>;
@interface NSCache () {
    cacheType _cacheEntries;
    std::unordered_map<id, cacheType::iterator> _iterators;

    NSUInteger _countLimit;

    NSUInteger _totalCost;
    NSUInteger _totalCostLimit;

    id<NSCacheDelegate> _delegate;
    struct {
        uint8_t hasWillEvict : 1;
    } _delegateFlags;
}
@end

@implementation NSCache

- (instancetype)init {
    if (self = [super init]) {
        _evictsObjectsWithDiscardedContent = YES;
    }
    return self;
}

- (void)dealloc {
    [_name release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (id)objectForKey:(id)key {
    @synchronized(self) {
        const auto found = _iterators.find(key);
        if (found != _iterators.end()) {
            auto cacheIterator = found->second;
            StrongId<_NSCacheEntry> cacheEntry(*cacheIterator);
            _cacheEntries.erase(cacheIterator);
            _iterators.erase(found);
            [self _insertEntry:cacheEntry];
            return [cacheEntry object];
        }
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (void)setObject:(id)obj forKey:(id)key {
    [self setObject:obj forKey:key cost:0];
}

/**
 @Status Interoperable
*/
- (void)setObject:(id)obj forKey:(id)key cost:(NSUInteger)cost {
    @synchronized(self) {
        [self removeObjectForKey:key];
        [self _insertEntry:[_NSCacheEntry cacheEntryWithCost:cost key:key object:obj]];
        _totalCost += cost;

        // since this starts at the end, it shouldn't evict our new entry unless it's too large.
        // if it's too large, we will evict the new entry immediately. this matches the reference
        // platform behaviour.
        [self _evictEntriesOverCharge];
    }
}

// invariant: under lock
- (void)_insertEntry:(_NSCacheEntry*)entry {
    auto it = _cacheEntries.emplace(_cacheEntries.begin(), entry);
    _iterators[entry.key] = it;
}

/**
 @Status Interoperable
*/
- (void)removeObjectForKey:(id)key {
    @synchronized(self) {
        const auto found = _iterators.find(key);
        if (found == _iterators.end()) {
            return;
        }
        [self _evictEntry:*found->second force:true];
    }
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    @synchronized(self) {
        for (auto& entry: _cacheEntries) {
            if (_delegateFlags.hasWillEvict) {
                [_delegate cache:self willEvictObject:[entry object]];
            }
            if ([entry discardable]) {
                [[entry object] discardContentIfPossible];
            }
        }

        _cacheEntries.clear();
        _iterators.clear();
        _totalCost = 0;
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)countLimit {
    @synchronized(self) {
        return _countLimit;
    }
}

/**
 @Status Interoperable
*/
- (void)setCountLimit:(NSUInteger)countLimit {
    @synchronized(self) {
        _countLimit = countLimit;
        [self _evictEntriesOverCharge];
    }
}

/**
 @Status Interoperable
*/
- (NSUInteger)totalCostLimit {
    @synchronized(self) {
        return _totalCostLimit;
    }
}

/**
 @Status Interoperable
*/
- (void)setTotalCostLimit:(NSUInteger)totalCostLimit {
    @synchronized(self) {
        _totalCostLimit = totalCostLimit;
        [self _evictEntriesOverCharge];
    }
}

/**
 @Status Interoperable
*/
- (id<NSCacheDelegate>)delegate {
    @synchronized(self) {
        return _delegate;
    }
}

/**
 @Status Interoperable
*/
- (void)setDelegate:(id<NSCacheDelegate>)delegate {
    @synchronized(self) {
        _delegate = delegate;
        _delegateFlags.hasWillEvict = [_delegate respondsToSelector:@selector(cache:willEvictObject:)];
    }
}

// invariant: under lock
- (NSUInteger)_evictEntry:(_NSCacheEntry*)entry force:(bool)force {
    // Since we're removing potentially the last reference to entry, we need to keep it alive so that
    // we can poke at its internals.
    StrongId<_NSCacheEntry> strongEntry(entry);

    NSUInteger cost = [entry cost];

    id object = entry.object;
    if (_delegateFlags.hasWillEvict) {
        [_delegate cache:self willEvictObject:object];
    }

    bool remove = true;
    if (entry.discardable) {
        id<NSDiscardableContent> discardable = (id<NSDiscardableContent>)object;
        [discardable discardContentIfPossible];
        if ([discardable isContentDiscarded]) {
            entry.cost = 0;
            remove = force || _evictsObjectsWithDiscardedContent;
        } else {
            remove = force;
        }
    }

    _totalCost -= cost;

    if (remove) {
        // std::unordered_map<K, V> will re-hash a value of type K on erase(iterator);
        // since _cacheEntries holds the owning reference and _iterators does not, we need
        // to ensure that entry (and therefore entry.key) outlive _cacheEntries' ownership of them.
        const auto found = _iterators.find([entry key]);
        _cacheEntries.erase(found->second);
        _iterators.erase(found);
    }

    return cost;
}

// invariant: under lock
- (void)_evictEntriesOverCharge {
    if (_cacheEntries.size() == 0) {
        return;
    }

    long long overCost = _totalCost > 0 ? ((long long)_totalCost - _totalCostLimit) : 0;
    long long overCount = _countLimit > 0 ? ((long long)_cacheEntries.size() - _countLimit) : 0;
    if (overCost <= 0 && overCount <= 0) {
        return;
    }

    auto rit = _cacheEntries.end();
    do {
        _NSCacheEntry* entry = (id)*--rit;
        auto cost = [entry cost];
        bool evict = (overCount > 0 || (cost > 0 && overCost > 0));
        if (evict) {
            ++rit; // we'll decrement over this next time through
            overCost -= [self _evictEntry:entry force:false];
            overCount--;
            continue;
        }
    } while ((overCost > 0 || overCount > 0) && rit != _cacheEntries.begin());
}
@end
