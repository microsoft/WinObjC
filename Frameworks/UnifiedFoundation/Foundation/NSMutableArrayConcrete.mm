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
#include "StubReturn.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSMutableArrayConcrete.h"
#include "NSCFArray.h"
#include "BridgeHelpers.h"
#include <CoreFoundation/CFArray.h>

@implementation NSMutableArrayConcrete {
@private
    StrongId<NSCFArray> _nscf;
}

- (instancetype)initWithObjects:(id _Nonnull const*)objs count:(NSUInteger)count {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSCFArray*>(CFArrayCreateMutable(NULL, 0, &kCFTypeArrayCallBacks)));
        for (unsigned int i = 0; i < count; i++) {
            [_nscf addObject:objs[i]];
        }
    }
    return self;
}

- (instancetype)initWithCapacity:(NSUInteger)numElements {
    if (self = [super init]) {
        _nscf.attach(static_cast<NSCFArray*>(CFArrayCreateMutable(NULL, numElements, &kCFTypeArrayCallBacks)));
    }
    return self;
}

- (instancetype)init {
    return [self initWithObjects:nullptr count:0];
}

- INNER_BRIDGE_CALL(_nscf, NSUInteger, count);
- INNER_BRIDGE_CALL(_nscf, id, objectAtIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeObjectAtIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeLastObject);
- INNER_BRIDGE_CALL(_nscf, void, replaceObjectAtIndex:(NSUInteger)index withObject:(NSObject*)obj);
- INNER_BRIDGE_CALL(_nscf, void, insertObject:(NSObject*)objAddr atIndex:(NSUInteger)index);
- INNER_BRIDGE_CALL(_nscf, void, removeAllObjects);
- INNER_BRIDGE_CALL(_nscf, void, addObject:(NSObject*)objAddr);

@end
