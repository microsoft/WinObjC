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

#import "ABMultiValueInternal.h"

// Private helper class to represent the values
// in an ABMultiValue, which are pairs of a label
// and value (along with an identifier).
@interface __ABMultiValuePair : NSObject

@property (copy) NSString* label;
@property id value;
@property ABMultiValueIdentifier identifier;

- (id)initWithLabel:(NSString*)label value:(id)value identifier:(ABMultiValueIdentifier)identifier;

@end

@implementation __ABMultiValuePair

- (id)initWithLabel:(NSString*)label value:(id)value identifier:(ABMultiValueIdentifier)identifier {
    if (self = [super init]) {
        self.label = label;
        self.value = value;
        self.identifier = identifier;
    }

    return self;
}

@end

@implementation _ABMultiValue {
    NSMutableArray* _list;
    int _nextIdentifier;
    ABPropertyType _propertyType;
    BOOL _mutable;
}

- (id)initWithPropertyType:(ABPropertyType)propertyType {
    if (self = [super init]) {
        self->_list = [[NSMutableArray alloc] init];
        self->_nextIdentifier = 0;
        self->_propertyType = propertyType;
        self->_mutable = YES;
    }

    return self;
}

- (BOOL)isMutable {
    return self->_mutable;
}

- (void)makeImmutable {
    self->_mutable = NO;
}

- (BOOL)appendPairWithLabel:(NSString*)label andValue:(id)value {
    if (![self isMutable]) {
        return NO;
    }

    [self->_list addObject:[[__ABMultiValuePair alloc] initWithLabel:label value:value identifier:self->_nextIdentifier]];

    // Increment the next usable identifier to ensure that each label/value pair has a unique identifier.
    self->_nextIdentifier++;
    return YES;
}

- (CFTypeRef)copyValueAtIndex:(CFIndex)index {
    if ([self->_list count] <= index || index < 0) {
        return nullptr;
    }

    return (__bridge_retained CFTypeRef)(static_cast<__ABMultiValuePair*>(self->_list[index]).value);
}

- (CFArrayRef)copyArrayOfAllValues {
    NSMutableArray* result = [NSMutableArray arrayWithCapacity:[self->_list count]];

    for (__ABMultiValuePair* pair in self->_list) {
        [result addObject:pair.value];
    }

    return (__bridge_retained CFArrayRef)result;
}

- (CFIndex)getCount {
    return [self->_list count];
}

- (CFStringRef)copyLabelAtIndex:(CFIndex)index {
    if ([self->_list count] <= index || index < 0) {
        return nullptr;
    }

    return (__bridge_retained CFStringRef)(static_cast<__ABMultiValuePair*>(self->_list[index]).label);
}

- (ABMultiValueIdentifier)getIdentifierAtIndex:(CFIndex)index {
    if ([self->_list count] <= index || index < 0) {
        return kABMultiValueInvalidIdentifier;
    }

    return static_cast<__ABMultiValuePair*>(self->_list[index]).identifier;
}

- (ABPropertyType)getPropertyType {
    return self->_propertyType;
}

- (CFIndex)getFirstIndexOfValue:(CFTypeRef)value {
    NSUInteger index = [self->_list indexOfObjectPassingTest:^BOOL(id obj, NSUInteger idx, BOOL* stop) {
        __ABMultiValuePair* pair = (__ABMultiValuePair*)obj;
        if (CFEqual(value, (__bridge CFTypeRef)pair.value)) {
            *stop = YES;
            return YES;
        } else {
            return NO;
        }
    }];

    if (index == NSNotFound) {
        return -1;
    }

    return index;
}

- (CFIndex)getIndexForIdentifier:(ABMultiValueIdentifier)identifier {
    NSUInteger index = [self->_list indexOfObjectPassingTest:^BOOL(id obj, NSUInteger idx, BOOL* stop) {
        __ABMultiValuePair* pair = (__ABMultiValuePair*)obj;
        if (identifier == pair.identifier) {
            *stop = YES;
            return YES;
        } else {
            return NO;
        }
    }];

    if (index == NSNotFound) {
        return -1;
    }

    return index;
}

- (id)mutableCopyWithZone:(NSZone*)zone {
    _ABMultiValue* copy = [[_ABMultiValue alloc] initWithPropertyType:[self getPropertyType]];
    for (__ABMultiValuePair* pair in self->_list) {
        [copy appendPairWithLabel:pair.label andValue:pair.value];
    }

    return copy;
}

- (bool)addValue:(CFTypeRef)value andLabel:(CFStringRef)label outIdentifier:(ABMultiValueIdentifier*)outIdentifier {
    if (![self isMutable]) {
        return false;
    }

    bool result = [self appendPairWithLabel:(__bridge NSString*)label andValue:(__bridge id)value];
    if (result && outIdentifier) {
        *outIdentifier = [self getIdentifierAtIndex:([self getCount] - 1)];
    }

    return result;
}

- (bool)replaceValue:(CFTypeRef)value atIndex:(CFIndex)index {
    if (![self isMutable] || [self->_list count] <= index || index < 0) {
        return false;
    }

    static_cast<__ABMultiValuePair*>(self->_list[index]).value = (__bridge id)value;
    return true;
}

- (bool)replaceLabel:(CFStringRef)label atIndex:(CFIndex)index {
    if (![self isMutable] || [self->_list count] <= index || index < 0) {
        return false;
    }

    static_cast<__ABMultiValuePair*>(self->_list[index]).label = (__bridge NSString*)label;
    return true;
}

- (bool)insertValue:(CFTypeRef)value
           andLabel:(CFStringRef)label
            atIndex:(CFIndex)index
      outIdentifier:(ABMultiValueIdentifier*)outIdentifier {
    if (![self isMutable] || [self->_list count] <= index || index < 0) {
        return false;
    }

    [self->_list insertObject:[[__ABMultiValuePair alloc] initWithLabel:(__bridge NSString*)label
                                                                  value:(__bridge id)value
                                                             identifier:self->_nextIdentifier]
                      atIndex:index];

    // Increment the next usable identifier to ensure that each label/value pair has a unique identifier.
    (self->_nextIdentifier)++;
    if (outIdentifier) {
        *outIdentifier = [self getIdentifierAtIndex:index];
    }

    return true;
}

- (bool)removeValueAndLabelAtIndex:(CFIndex)index {
    if (![self isMutable] || [self->_list count] <= index || index < 0) {
        return false;
    }

    [self->_list removeObjectAtIndex:index];
    return true;
}

@end