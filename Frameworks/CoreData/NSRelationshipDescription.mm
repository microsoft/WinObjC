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

@interface NSRelationshipDescription () {
    StrongId<NSString> _destinationEntityName;
    StrongId<NSString> _inverseEntityName;
    StrongId<NSString> _inverseRelationshipName;
}
@end

@implementation NSRelationshipDescription
+ (NSDeleteRule)_deletionRuleFromString:(NSString*)string {
    static StrongId<NSDictionary<NSString*, NSNumber*>> _deleteRules = @{
        @"Nullify" : @(NSNullifyDeleteRule),
        @"Cascade" : @(NSCascadeDeleteRule),
        @"Deny" : @(NSDenyDeleteRule),
    };

    // 0/nil is NSNoActionDeleteRule
    return (NSDeleteRule)[[_deleteRules objectForKey:string] unsignedIntegerValue];
}
- (instancetype)_initWithXMLElementName:(NSString*)entityName attributes:(NSDictionary<NSString*, NSString*>*)attributes {
    if (self = [super _initWithXMLElementName:entityName attributes:attributes]) {
        _destinationEntityName.attach([attributes[@"destinationEntity"] copy]);

        _inverseEntityName.attach([attributes[@"inverseEntity"] copy]);
        _inverseRelationshipName.attach([attributes[@"inverseName"] copy]);

        _deleteRule = [[self class] _deletionRuleFromString:attributes[@"deletionRule"]];

        _toMany = [attributes[@"toMany"] isEqualToString:@"YES"];

        if (!_toMany) {
            _minCount = _maxCount = 1;
        } else {
            _minCount = [attributes[@"minCount"] integerValue];
            _maxCount = [attributes[@"maxCount"] integerValue];
        }

        _ordered = [attributes[@"ordered"] isEqualToString:@"YES"];
    }
    return self;
}

- (void)_awakeFromXML {
    // No derived properties to calculate.
}

- (NSString*)_destinationEntityName {
    return [[_destinationEntityName retain] autorelease];
}

- (NSString*)_inverseEntityName {
    return [[_inverseEntityName retain] autorelease];
}

- (NSString*)_inverseRelationshipName {
    return [[_inverseRelationshipName retain] autorelease];
}

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@ %p: %@,%hs%hs%hs%hs%hs%hs%hs destination=%@ inverse=%p userInfo=%@>",
                                      object_getClass(self),
                                      self,
                                      self.name,
                                      self.optional ? " optional" : "",
                                      self.transient ? " transient" : "",
                                      self.indexed ? " indexed" : "",
                                      self.storedInExternalRecord ? " external" : "",
                                      self.indexedBySpotlight ? " spotlight" : "",
                                      self.toMany ? " to-many" : "",
                                      self.ordered ? " ordered" : "",
                                      _destinationEntity.name,
                                      _inverseRelationship,
                                      self.userInfo];
}

- (NSData*)versionHash {
    // TODO(DH): calculate.
    return [super versionHash];
}
@end
