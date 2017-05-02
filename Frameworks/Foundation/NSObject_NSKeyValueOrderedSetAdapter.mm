//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import "NSObject_NSKeyValueCoding-Internal.h"

/*
* KVC Ordered Set Adapters
*
* mutableOrderedSetValueForKey:@"xx" will ALWAYS return an NSOrderedSet-workalike. It'll do the following things:
* - Preferentially use countOfXx and objectInXxAtIndex: for accessors.
* - Preferentially use insertObject:inXxAtIndex: and -removeObjectFromXxAtIndex: for mutators.
* - If these don't exist, accessors and mutators are proxied through to the following:
*     - The getters getXx, xx, and isXx.
*     - The instance Variables _xx or xx.
*     - valueForKey:@"xx"
* - If we used an ivar or valueForKey:, values of nil become empty NSOrderedSets.
* - If we used a getter, a mutable copy of the object we get back is made.
* - The mutation is attempted.
*     - If we used an ivar, this will fail for immutable members.
* - If a method mutated the copy of xx, setters cascade as follows:
*     - The setter setXx:
*     - Directly into the instance variable _xx or xx.
*     - setValue: forKey:@"xx"
*
* Exceptions are expected at every stage of this pipeline.
* if the ivar xx contains a NSNumber, we will attempt (fail) to get a mutable copy of it,
* and then attempt (fail) to treat it like an array. This is entirely in keeping
* with the behaviour of the reference platform.
*
* No caching is done, as, on the reference platform
*
* NSMutableOrderedSet* orderedSet = [object mutableOrderedSetValueForKey:@"xx"];
* [object setValue:[NSSet orderedSetWithObject:@1024] forKey:@"xx"];
*
* [orderedSet containsObject:@1024];
*
* holds true.
*/

namespace {
struct ProxyOrderedSet : public ProxyOrderedBase {
    ProxyOrderedSet(id target, NSString* key, objc_ivar* ivar) : ProxyOrderedBase(target, key, ivar) {
    }

protected:
    virtual id _getEmptyContainer() override {
        return [NSMutableOrderedSet orderedSet];
    }
};
}

@interface _NSMutableKeyProxyOrderedSet () {
    std::shared_ptr<ProxyOrderedSet> _proxyOrderedSet;
}
- (id)_initWithProxyOrderedSet:(std::shared_ptr<ProxyOrderedSet>)proxyOrderedSet;
@end

@implementation _NSMutableKeyProxyOrderedSet
+ (instancetype)proxyOrderedSetForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxyOrderedSet = std::make_shared<ProxyOrderedSet>(object, key, ivar);
    }
    return self;
}

- (id)_initWithProxyOrderedSet:(std::shared_ptr<ProxyOrderedSet>)proxyOrderedSet {
    if (self = [super init]) {
        _proxyOrderedSet = std::move(proxyOrderedSet);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyOrderedSet->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyOrderedSet->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyOrderedSet->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyOrderedSet->getObjectsRange(objects, range);
}

// mutable methods
- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    _proxyOrderedSet->insertObjectAtIndex(object, index);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    _proxyOrderedSet->removeObjectAtIndex(index);
}

- (void)insertObjects:(NSArray*)objects atIndexes:(NSIndexSet*)indexes {
    _proxyOrderedSet->insertObjectsAtIndexes(objects, indexes);
}

- (void)removeObjectsAtIndexes:(NSIndexSet*)indexes {
    _proxyOrderedSet->removeObjectsAtIndexes(indexes);
}

- (void)addObject:(id)object {
    _proxyOrderedSet->addObject(object);
}

- (void)removeLastObject {
    _proxyOrderedSet->removeLastObject();
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)object {
    _proxyOrderedSet->replaceObjectAtIndexWithObject(index, object);
}

@end
