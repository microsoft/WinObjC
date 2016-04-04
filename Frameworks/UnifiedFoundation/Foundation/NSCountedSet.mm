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
#include <Foundation/NSCountedSet.h>
#include "NSCountedSetConcrete.h"
#include "NSRaise.h"

@implementation NSCountedSet

+ ALLOC_CONCRETE_SUBCLASS_WITH_ZONE(NSCountedSet, NSCountedSetConcrete);

/**
 @Status Interoperable
*/
- (instancetype)initWithObjects:(id _Nonnull const* _Nullable)objects count:(unsigned)count {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCapacity:(unsigned)capacity {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSUInteger)countForObject:(id)object {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (unsigned)count {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSEnumerator*)objectEnumerator {
    // TODO: As an optimization, create a parallel implementation of this function, so that subclasses will not have to override this
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)member:(id)object {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (void)addObject:(id)object {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeObject:(id)object {
    // This class is a class cluster "interface". A concrete implementation (default or derived) MUST implement this.
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (void)removeAllObjects {
    // TODO: As an optimization, create a parallel implementation of this function, so that subclasses will not have to override this
    NSInvalidAbstractInvocation();
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [[[self class] alloc] initWithSet:self];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    // NSCountedSet is derived from NSMutableSet
    return [self copy];
}

@end
