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

#include <list>
#include <mutex>
#include <map>
#include <string>

@interface NSURLCache () {
    std::recursive_mutex _mutex;
    std::list<std::pair<std::string, StrongId<NSCachedURLResponse>>> _cache;
    std::map<std::string, decltype(_cache)::iterator> _iterators;
}
@end

static NSString* kNSURLCacheSharedCacheDirectoryName = @"SharedURLCache";
static NSUInteger kNSURLCacheDefaultMemoryCapacity = 128 * 1024 * 1024;
static NSUInteger kNSURLCacheDefaultDiskCapacity = 0;

@implementation NSURLCache

static StrongId<NSURLCache> _sharedURLCache;

/**
@Status Interoperable
*/
+ (instancetype)sharedURLCache {
    @synchronized (self) {
        if (!_sharedURLCache && self == [NSURLCache class]) {
            _sharedURLCache.attach([[self alloc] _initWithSharedDefaults]);
        }
        return _sharedURLCache;
    }
}

/**
@Status Interoperable
*/
+ (void)setSharedURLCache:(NSURLCache*)cache {
    _sharedURLCache = cache;
}

/**
@Status Caveat
@Notes Only caches in memory.
*/
- (instancetype)initWithMemoryCapacity:(NSUInteger)memCapacity diskCapacity:(NSUInteger)diskCapacity diskPath:(NSString*)path {
    if (self = [super init]) {
        _memoryCapacity = memCapacity;
        _diskCapacity = diskCapacity;
    }
    return self;
}

- (instancetype)_initWithSharedDefaults {
    return [self initWithMemoryCapacity:kNSURLCacheDefaultMemoryCapacity
                           diskCapacity:kNSURLCacheDefaultDiskCapacity
                               diskPath:kNSURLCacheSharedCacheDirectoryName];
}

- (NSString*)_cacheKeyForURL:(NSURL*)url {
    NSString* absoluteString = [url absoluteString];
    NSRange hashRange = [absoluteString rangeOfString:@"#" options:NSBackwardsSearch];
    if (hashRange.location == NSNotFound) {
        return absoluteString;
    }

    return [absoluteString substringToIndex:hashRange.location];
}

- (void)_insertResponse:(NSCachedURLResponse*)response forKey:(const std::string&)key {
    _cache.emplace_front(key, response);
    _iterators[key] = _cache.begin();
}

/**
@Status Caveat
@Notes Only caches in memory.
*/
- (NSCachedURLResponse*)cachedResponseForRequest:(NSURLRequest*)request {
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    std::string cacheKey([[self _cacheKeyForURL:[request URL]] UTF8String]);
    const auto /* TODO(DH): auto&, compiler bug */ mapIterator = _iterators.find(cacheKey);
    if (mapIterator == _iterators.end()) {
        return nil;
    }

    const auto &iterator = mapIterator->second;
    auto cachedResponse(iterator->second);

    // only promote this entry to the head of the LRU list if it's not the most recent entry.
    if (iterator != _cache.begin()) {
        _cache.erase(iterator);
        [self _insertResponse:cachedResponse forKey:cacheKey];
    }

    return cachedResponse;
}

/**
@Status Caveat
@Notes Only caches in memory.
*/
- (void)storeCachedResponse:(NSCachedURLResponse*)cachedResponse forRequest:(NSURLRequest*)request {
    if (cachedResponse.storagePolicy == NSURLCacheStorageNotAllowed) {
        return;
    }

    std::lock_guard<std::recursive_mutex> lock(_mutex);
    [self removeCachedResponseForRequest:request];

    auto cachedResponseLength = [[cachedResponse data] length];
    while (_currentMemoryUsage > _memoryCapacity - cachedResponseLength) {
        if (_cache.size() == 0) {
            // We could not satisfy the request: do not cache this response.
            return;
        }
        auto lastEntry = _cache.back();
        _cache.pop_back();
        _iterators.erase(lastEntry.first);
        _currentMemoryUsage -= [[lastEntry.second data] length];
    }

    std::string cacheKey([[self _cacheKeyForURL:[request URL]] UTF8String]);
    [self _insertResponse:cachedResponse forKey:cacheKey];
    _currentMemoryUsage += cachedResponseLength;
}

/**
@Status Interoperable
*/
- (void)removeCachedResponseForRequest:(NSURLRequest*)request {
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    std::string cacheKey([[self _cacheKeyForURL:[request URL]] UTF8String]);
    const auto /* TODO(DH): auto&, compiler bug */ mapIterator = _iterators.find(cacheKey);
    if (mapIterator != _iterators.end()) {
        const auto &iterator = mapIterator->second;
        _currentMemoryUsage -= [[iterator->second data] length];
        _cache.erase(iterator);
        _iterators.erase(cacheKey);
    }
}

/**
@Status Interoperable
*/
- (void)removeAllCachedResponses {
    std::lock_guard<std::recursive_mutex> lock(_mutex);
    _currentMemoryUsage = 0;
    _cache.clear();
    _iterators.clear();
}

@end
