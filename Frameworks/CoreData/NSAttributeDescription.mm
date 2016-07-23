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

#import <CoreData/CoreData.h>
#import <Foundation/Foundation.h>
#import <StubReturn.h>

#import <CoreData/NSManagedObjectModel-XMLParsing.h>

@interface NSAttributeDescription () {
    StrongId<id> _minValue;
    StrongId<id> _maxValue;
}
@end

@implementation NSAttributeDescription
+ (NSAttributeType)_attributeTypeFromString:(NSString*)typeString {
    static StrongId<NSDictionary<NSString*, NSNumber*>> _attributeTypes = @{
        @"Integer 16" : @(NSInteger16AttributeType),
        @"Integer 32" : @(NSInteger32AttributeType),
        @"Integer 64" : @(NSInteger64AttributeType),
        @"Decimal" : @(NSDecimalAttributeType),
        @"Double" : @(NSDoubleAttributeType),
        @"Float" : @(NSFloatAttributeType),
        @"String" : @(NSStringAttributeType),
        @"Boolean" : @(NSBooleanAttributeType),
        @"Date" : @(NSDateAttributeType),
        @"Binary" : @(NSBinaryDataAttributeType),
        @"Transformable" : @(NSTransformableAttributeType),
        @"ObjectID" : @(NSObjectIDAttributeType),
    };
    return (NSAttributeType)[[_attributeTypes objectForKey:typeString] unsignedIntegerValue];
}

+ (NSObject<NSCopying>*)_convertValueString:(NSString*)valueString forAttributeType:(NSAttributeType)attributeType {
    switch (attributeType) {
        case NSInteger16AttributeType:
        case NSInteger32AttributeType:
        case NSInteger64AttributeType:
            return [NSNumber numberWithLongLong:[valueString longLongValue]];
        case NSDecimalAttributeType:
            return nil; // [NSDecimalNumber decimalNumberWithString:valueString]; when implemented (VSO 7346158)
        case NSFloatAttributeType:
        case NSDoubleAttributeType:
            return [NSNumber numberWithDouble:[valueString doubleValue]];
        case NSStringAttributeType:
            return valueString;
        case NSBooleanAttributeType:
            return [NSNumber numberWithBool:[valueString boolValue]];
        default:
            // This type can't have a parsed default.
            return nil;
    }
    return nil;
}

- (instancetype)_initWithXMLElementName:(NSString*)entityName attributes:(NSDictionary<NSString*, NSString*>*)attributes {
    if (self = [super _initWithXMLElementName:entityName attributes:attributes]) {
        _attributeType = [[self class] _attributeTypeFromString:attributes[@"attributeType"]];
        _valueTransformerName = [attributes[@"valueTransformerName"] copy];

        if (_attributeType == NSDateAttributeType) {
            NSString* defaultDateString = attributes[@"defaultDateTimeInterval"];
            NSString* minDateString = attributes[@"minDateTimeInterval"];
            NSString* maxDateString = attributes[@"maxDateTimeInterval"];

            _defaultValue = [[NSDate alloc] initWithTimeIntervalSinceReferenceDate:[defaultDateString longLongValue]];
            _minValue = [NSDate dateWithTimeIntervalSinceReferenceDate:[minDateString longLongValue]];
            _maxValue = [NSDate dateWithTimeIntervalSinceReferenceDate:[maxDateString longLongValue]];
        } else {
            _defaultValue = [[[self class] _convertValueString:attributes[@"defaultValueString"] forAttributeType:_attributeType] copy];
            _minValue = [[self class] _convertValueString:attributes[@"minValueString"] forAttributeType:_attributeType];
            _maxValue = [[self class] _convertValueString:attributes[@"maxValueString"] forAttributeType:_attributeType];
        }

        NSMutableArray<NSPredicate*>* validationPredicates = [NSMutableArray array];
        if (_minValue) {
            [validationPredicates addObject:[NSPredicate predicateWithFormat:@"SELF >= %@", (id)_minValue]];
        }

        if (_maxValue) {
            [validationPredicates addObject:[NSPredicate predicateWithFormat:@"SELF <= %@", (id)_maxValue]];
        }

        if (validationPredicates.count > 0) {
            self.validationPredicates = validationPredicates;
        }
    }
    return self;
}

- (void)dealloc {
    [_defaultValue release];
    [_valueTransformerName release];
    [super dealloc];
}

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@ %p: %@,%hs%hs%hs%hs%hs default=%@ userInfo=%@>",
                                      object_getClass(self),
                                      self,
                                      self.name,
                                      self.optional ? " optional" : "",
                                      self.transient ? " transient" : "",
                                      self.indexed ? " indexed" : "",
                                      self.storedInExternalRecord ? " external" : "",
                                      self.indexedBySpotlight ? " spotlight" : "",
                                      _defaultValue,
                                      self.userInfo];
}
@end
