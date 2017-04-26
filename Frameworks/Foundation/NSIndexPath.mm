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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSIndexPath.h"

#import <vector>
#import <numeric>

static NSString* s_archiveKey = @"_NS.IP";

@interface NSIndexPath () {
    std::vector<NSUInteger> _indexes;
}

@end

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
- (instancetype)init {
    return [self initWithIndexes:nullptr length:0];
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
    if (self = [super init]) {
        if (length != 0 && indexes != nullptr) {
            _indexes.reserve(length);
            _indexes.insert(_indexes.begin(), indexes, indexes + length);
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:[NSIndexPath class]]) {
        NSIndexPath* otherPath = other;
        return _indexes == otherPath->_indexes;
    }

    return NO;
}

/**
 @Status Interoperable
*/
- (NSUInteger)indexAtPosition:(NSUInteger)position {
    return position < _indexes.size() ? _indexes[position] : NSNotFound;
}

/**
 @Status Interoperable
*/
- (void)getIndexes:(NSUInteger*)indexes {
    std::copy(_indexes.cbegin(), _indexes.cend(), indexes);
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [[[self class] alloc] initWithIndexes:_indexes.data() length:_indexes.size()];
}

/**
 @Status Interoperable
*/
- (NSIndexPath*)indexPathByAddingIndex:(NSUInteger)newIndex {
    std::vector<NSUInteger> indexes = _indexes;
    indexes.emplace_back(newIndex);
    return [NSIndexPath indexPathWithIndexes:indexes.data() length:indexes.size()];
}

/**
 @Status Interoperable
*/
- (NSIndexPath*)indexPathByRemovingLastIndex {
    return [NSIndexPath indexPathWithIndexes:_indexes.data() length:(_indexes.empty() ? 0 : _indexes.size() - 1)];
}

/**
 @Status Interoperable
*/
- (NSUInteger)length {
    return _indexes.size();
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    if ([self length] == 0L) {
        return 0;
    }

    auto dataToHash = woc::MakeAutoCF<CFDataRef>(
        CFDataCreateWithBytesNoCopy(nullptr, (const UInt8*)_indexes.data(), _indexes.size() * sizeof(NSUInteger), kCFAllocatorNull));
    return CFHash(dataToHash);
}

/**
 @Status Interoperable
*/
- (NSComparisonResult)compare:(id)otherObj {
    if (self == otherObj) {
        return NSOrderedSame;
    }

    NSUInteger len1 = [self length];
    NSUInteger len2 = [otherObj length];

    for (NSUInteger i = 0; i < len1 && i < len2; i++) {
        NSUInteger val1 = [self indexAtPosition:i];
        NSUInteger val2 = [otherObj indexAtPosition:i];

        if (val1 < val2) {
            return NSOrderedAscending;
        }

        if (val1 > val2) {
            return NSOrderedDescending;
        }
    }

    if (len1 < len2) {
        return NSOrderedAscending;
    }
    if (len1 > len2) {
        return NSOrderedDescending;
    }

    return NSOrderedSame;
}

/**
 @Status Interoperable
*/
- (void)getIndexes:(NSUInteger*)indexes range:(NSRange)positionRange {
    if (positionRange.location + positionRange.length > [self length]) {
        [NSException raise:NSRangeException
                    format:@"-[%s %s]: range {%lu, %lu} beyond bounds (%lu)",
                           class_getName([self class]),
                           sel_getName(_cmd),
                           (unsigned long)positionRange.location,
                           (unsigned long)positionRange.length,
                           (unsigned long)[self length]];
    }

    std::copy(_indexes.cbegin() + positionRange.location, _indexes.cbegin() + positionRange.location + positionRange.length, indexes);
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)decoder {
    NSArray* indexes = [decoder decodeObjectOfClass:[NSArray class] forKey:s_archiveKey];
    std::vector<NSUInteger> values;
    values.reserve([indexes count]);
    for (NSNumber* index in indexes) {
        values.emplace_back(index.unsignedIntegerValue);
    }

    return [self initWithIndexes:values.data() length:values.size()];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    NSMutableArray* indexes = [NSMutableArray arrayWithCapacity:[self length]];
    for (auto index : _indexes) {
        [indexes addObject:[NSNumber numberWithUnsignedInteger:index]];
    }

    [coder encodeObject:indexes forKey:s_archiveKey];
}

@end
