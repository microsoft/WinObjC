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

#import <NSObject_NSKeyValueCoding-Internal.h>

/*
* KVC Array Adapters
*
* On the reference platform, valueForKey:@"xx" will return a NSArray-workalike if you implement
* countOfXx and objectInXxAtIndex:.
*
* mutableArrayValueForKey:@"xx" will ALWAYS return an NSArray-workalike. It'll do the following things:
* - Preferentially use countOfXx and objectInXxAtIndex: for accessors.
* - Preferentially use insertObject:inXxAtIndex: and -removeObjectFromXxAtIndex: for mutators.
* - If these don't exist, accessors and mutators are proxied through to the following:
*     - The getters getXx, xx, and isXx.
*     - The instance Variables _xx or xx.
*     - valueForKey:@"xx"
* - If we used an ivar or valueForKey:, values of nil become empty arrays, @[].
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
* NSMutableArray* array = [object mutableArrayValueForKey:@"xx"];
* [object setValue:@[@1024] forKey:@"xx"];
*
* [[array objectAtIndex:0] isEqual:@(1024)];
*
* holds true.
*/

namespace {
struct ProxyArray : public ProxyOrderedBase {
    ProxyArray(id target, NSString* key, objc_ivar* ivar) : ProxyOrderedBase(target, key, ivar) {
    }

protected:
    virtual id _getEmptyContainer() override {
        return [NSMutableArray array];
    }
};
}

@interface _NSKeyProxyArray () {
    std::shared_ptr<ProxyArray> _proxyArray;
}
@end

@interface _NSMutableKeyProxyArray () {
    std::shared_ptr<ProxyArray> _proxyArray;
}
- (id)_initWithProxyArray:(std::shared_ptr<ProxyArray>)proxyArray;
@end

@implementation _NSKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxyArray = std::make_shared<ProxyArray>(object, key, ivar);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyArray->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyArray->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyArray->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyArray->getObjectsRange(objects, range);
}

- (_NSMutableKeyProxyArray*)_mutableProxy {
    return [[[_NSMutableKeyProxyArray alloc] _initWithProxyArray:_proxyArray] autorelease];
}

- (NSMutableArray*)mutableCopy {
    return [self _mutableProxy];
}
@end

@implementation _NSMutableKeyProxyArray
+ (instancetype)proxyArrayForObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    return [[[self alloc] initWithObject:object key:key ivar:ivar] autorelease];
}

- (id)initWithObject:(id)object key:(NSString*)key ivar:(struct objc_ivar*)ivar {
    if (self = [super init]) {
        _proxyArray = std::make_shared<ProxyArray>(object, key, ivar);
    }
    return self;
}

- (id)_initWithProxyArray:(std::shared_ptr<ProxyArray>)proxyArray {
    if (self = [super init]) {
        _proxyArray = std::move(proxyArray);
    }
    return self;
}

- (NSUInteger)count {
    return _proxyArray->count();
}

- (id)objectAtIndex:(NSUInteger)index {
    return _proxyArray->objectAtIndex(index);
}

- (NSArray*)objectsAtIndexes:(NSIndexSet*)indexes {
    return _proxyArray->objectsAtIndexes(indexes);
}

- (void)getObjects:(id[])objects range:(NSRange)range {
    return _proxyArray->getObjectsRange(objects, range);
}

// mutable methods
- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    _proxyArray->insertObjectAtIndex(object, index);
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    _proxyArray->removeObjectAtIndex(index);
}

- (void)addObject:(id)object {
    _proxyArray->addObject(object);
}

- (void)removeLastObject {
    _proxyArray->removeLastObject();
}

- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)object {
    _proxyArray->replaceObjectAtIndexWithObject(index, object);
}

@end
