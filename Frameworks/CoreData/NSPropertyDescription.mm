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

@implementation NSPropertyDescription
- (instancetype)_initWithXMLElementName:(NSString*)entityName attributes:(NSDictionary<NSString*, NSString*>*)attributes {
    if (self = [super init]) {
        _name = [attributes[@"name"] copy];
        _renamingIdentifier = [attributes[@"elementID"] copy];
        _versionHashModifier = [attributes[@"versionHashModifier"] copy];

        _optional = [attributes[@"optional"] isEqualToString:@"YES"];
        _transient = [attributes[@"transient"] isEqualToString:@"YES"];
        _indexed = [attributes[@"indexed"] isEqualToString:@"YES"];
        _storedInExternalRecord = [attributes[@"storedInTruthFile"] isEqualToString:@"YES"];
        _indexedBySpotlight = [attributes[@"spotlightIndexingEnabled"] isEqualToString:@"YES"];
    }
    return self;
}

- (void)dealloc {
    [_name release];
    [_userInfo release];
    [_validationPredicates release];
    [_validationWarnings release];
    [_versionHash release];
    [_versionHashModifier release];
    [_renamingIdentifier release];

    [super dealloc];
}

- (void)setEntity:(NSEntityDescription*)entity {
    _entity = entity;
}

- (bool)_insertChildElement:(id<_NSCDXMLCoding>)childElement {
    return NO;
}

- (void)_awakeFromXML {
}

- (NSString*)description {
    return [NSString stringWithFormat:@"<%@ %p: %@,%hs%hs%hs%hs%hs userInfo=%@>",
                                      object_getClass(self),
                                      self,
                                      self.name,
                                      self.optional ? " optional" : "",
                                      self.transient ? " transient" : "",
                                      self.indexed ? " indexed" : "",
                                      self.storedInExternalRecord ? " external" : "",
                                      self.indexedBySpotlight ? " spotlight" : "",
                                      self.userInfo];
}

/**
@Status Stub
@Notes
*/
- (void)setValidationPredicates:(NSArray*)validationPredicates withValidationWarnings:(NSArray*)validationWarnings {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
