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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSIndexPath.h"

@implementation NSIndexPath

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathWithIndex:(NSUInteger)index {
    return [[[self alloc] initWithIndexes:&index length:1] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathWithIndexes:(const NSUInteger*)indexes length:(NSUInteger)length {
    return [[[self alloc] initWithIndexes:indexes length:length] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathForRow:(NSInteger)row inSection:(NSInteger)section {
    unsigned indexes[] = { section, row };

    return [[[self alloc] initWithIndexes:indexes length:2] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSIndexPath*)indexPathForItem:(NSInteger)row inSection:(NSInteger)section {
    NSUInteger indexes[] = { section, row };
    return [[[self alloc] initWithIndexes:indexes length:2] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIndex:(NSUInteger)index {
    return [self initWithIndexes:&index length:1];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithIndexes:(const NSUInteger*)indexes length:(NSUInteger)length {
    _length = length;
    _indexes = (unsigned*)IwMalloc(length * sizeof(unsigned));
    if (_indexes == nil) {
        [self release];
        return nil;
    }

    for (unsigned i = 0; i < length; i++) {
        _indexes[i] = indexes[i];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:[NSIndexPath class]]) {
        NSIndexPath* otherPath = other;
        return _length == otherPath->_length && (memcmp(_indexes, otherPath->_indexes, _length * sizeof(DWORD)) == 0);
    }

    return FALSE;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    if (_indexes) {
        IwFree(_indexes);
    }
    [super dealloc];
}

/**
 @Status Caveat
 @Notes position must be valid
*/
- (unsigned)indexAtPosition:(unsigned)position {
    if (position >= _length) {
        assert(0);
        //[NSException raise:NSInvalidArgumentException format:@"Unable to remove index from zero length path."];
        return 0;
    }

    return _indexes[position];
}

/**
 @Status Interoperable
*/
- (void)getIndexes:(NSUInteger*)indexes {
    for (unsigned int i = 0; i < _length; i++) {
        indexes[i] = _indexes[i];
    }
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[[self class] alloc] initWithIndexes:_indexes length:_length];
}

/**
 @Status Interoperable
*/
- (NSIndexPath*)indexPathByAddingIndex:(NSUInteger)newIndex {
    id ret = [[self class] alloc];

    NSUInteger* indexCopy = (NSUInteger*)IwMalloc((_length + 1) * sizeof(DWORD));
    memcpy(indexCopy, _indexes, _length * sizeof(DWORD));
    indexCopy[_length] = newIndex;

    [ret initWithIndexes:indexCopy length:_length + 1];

    IwFree(indexCopy);

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    return _length;
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    unsigned ret = 0;

    for (unsigned int i = 0; i < _length; i++) {
        ret += _indexes[i];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (int)compare:(id)otherObj {
    int len1 = [self length];
    int len2 = [otherObj length];

    for (int i = 0; i < len1 && i < len2; i++) {
        int val1 = [self indexAtPosition:i];
        int val2 = [otherObj indexAtPosition:i];

        if (val1 < val2) {
            return -1;
        }
        if (val1 > val2) {
            return 1;
        }
    }

    if (len1 < len2) {
        return -1;
    }
    if (len1 > len2) {
        return 1;
    }

    return 0;
}

/**
 @Status Interoperable
*/
- (NSInteger)item {
    return [self row];
}

/**
 @Status Interoperable
*/
- (NSInteger)row {
    return [self indexAtPosition:1];
}

/**
 @Status Interoperable
*/
- (NSInteger)section {
    return [self indexAtPosition:0];
}

/**
 @Status Stub
*/
- (NSIndexPath*)indexPathByRemovingLastIndex {
    UNIMPLEMENTED();
    return self;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)init {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getIndexes:(NSUInteger*)indexes range:(NSRange)positionRange {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

@end
