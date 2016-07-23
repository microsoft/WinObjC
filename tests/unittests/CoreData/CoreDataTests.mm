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

#include <TestFramework.h>
#import <CoreData/CoreData.h>
#import "CoreData/NSManagedObjectModel-XMLParsing.h"
#import <Foundation/Foundation.h>

TEST(CoreData, NSManagedObjectModelInit) {
    ASSERT_OBJCEQ(nil,
                  [[[NSManagedObjectModel alloc] initWithContentsOfURL:[NSURL fileURLWithPath:@"Z:\\path\\does\\not\\exist.xcdatamodel"]]
                      autorelease]);
}

TEST(CoreData, NSManagedObjectModel_Basic) {
    // Represented model:
    // Entity: Person
    //         age (int16, required)
    //         friend (->Person, optional, max 1)
    //         [user info: key => value]
    static NSString* xmlModel = @"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?><model userDefinedModelVersionIdentifier=\"\"><entity name=\"Person\" syncable=\"YES\"><attribute name=\"age\" attributeType=\"Integer 16\" defaultValueString=\"0\" syncable=\"YES\"/><relationship name=\"friend\" optional=\"YES\" maxCount=\"1\" deletionRule=\"Nullify\" destinationEntity=\"Person\" syncable=\"YES\"/><userInfo><entry key=\"key\" value=\"value\"/></userInfo></entity></model>";
    NSManagedObjectModel* model = _NSManagedObjectModelFromXMLData([xmlModel dataUsingEncoding:NSUTF8StringEncoding], nil);
    ASSERT_OBJCNE(nil, model);
    EXPECT_EQ(1, model.entities.count);
    
    NSEntityDescription* personEntity = [model.entitiesByName objectForKey:@"Person"];
    ASSERT_OBJCNE(nil, personEntity);
    EXPECT_EQ(2, personEntity.properties.count);
    
    // age is not a relationship; this should fail.
    EXPECT_OBJCEQ(nil, [personEntity.relationshipsByName objectForKey:@"age"]);

    NSAttributeDescription* personAgeAttribute = [personEntity.attributesByName objectForKey:@"age"];

    ASSERT_OBJCNE(nil, personAgeAttribute);
    // pointer equal; we want to make sure they're the same object.
    EXPECT_EQ(personAgeAttribute, [personEntity.propertiesByName objectForKey:@"age"]);

    EXPECT_FALSE(personAgeAttribute.optional);
    EXPECT_EQ(NSInteger16AttributeType, personAgeAttribute.attributeType);
    EXPECT_OBJCEQ(@0, personAgeAttribute.defaultValue);

    // friend is a relationship; this should fail.
    EXPECT_OBJCEQ(nil, [personEntity.attributesByName objectForKey:@"friend"]);

    NSRelationshipDescription* personFriendRelationship = [personEntity.relationshipsByName objectForKey:@"friend"];

    ASSERT_OBJCNE(nil, personFriendRelationship);
    // pointer equal; we want to make sure they're the same object.
    EXPECT_EQ(personFriendRelationship, [personEntity.propertiesByName objectForKey:@"friend"]);

    EXPECT_TRUE(personFriendRelationship.optional);
    EXPECT_EQ(personEntity, personFriendRelationship.destinationEntity); // pointer compare; same entity.
    EXPECT_FALSE(personFriendRelationship.toMany);
    EXPECT_EQ(1, personFriendRelationship.maxCount);
    EXPECT_EQ(NSNullifyDeleteRule, personFriendRelationship.deleteRule);

    NSDictionary* personUserInfo = personEntity.userInfo;
    ASSERT_OBJCNE(nil, personUserInfo);
    EXPECT_OBJCEQ(@"value", personUserInfo[@"key"]);
}
