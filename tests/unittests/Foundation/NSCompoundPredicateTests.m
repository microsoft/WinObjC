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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSCompoundPredicate, Init) {
    NSCompoundPredicate* compoundPredicate = [[NSCompoundPredicate alloc] init];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");
    [compoundPredicate release];
}

TEST(Foundation, NSCompoundPredicate_NOTPredicateWithSubpredicate) {
    NSPredicate* predicate = [[NSPredicate alloc] init];
    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate notPredicateWithSubpredicate:predicate];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSNotPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSNotPredicateType.");

    [predicate release];
}

TEST(NSCompoundPredicate, NOTPredicateWithSubpredicateEval) {
    NSArray* array = @[ @1, @2, @3, @7, @8, @11, @14, @19, @20 ];

    NSPredicate* evenNumbersPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return [number integerValue] % 2 == 0;
    }];

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate notPredicateWithSubpredicate:evenNumbersPredicate];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSNotPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSNotPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    for (id object in array) {
        if (([object integerValue] % 2)) {
            ASSERT_EQ_MSG(YES,
                          [filteredArray containsObject:object],
                          "FAILED: not predicate filter did not work as expected, value not found.");
        }
    }
}

TEST(Foundation, NSCompoundPredicate_ANDPredicateWithSubpredicates) {
    NSArray* predicates = [[NSArray alloc] init];
    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:predicates];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSAndPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSAndPredicateType.");

    [predicates release];
}

TEST(NSCompoundPredicate, _ANDPredicateWithSubpredicatesEval) {
    NSArray* array = @[ @1, @1, @1, @1, @1, @0 ];

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return [number integerValue] == 1;
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        return YES;
    }];

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:@[ predicate1, predicate2 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSAndPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSAndPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    for (id object in filteredArray) {
        ASSERT_EQ_MSG(YES, [object integerValue] == 1, "FAILED: AND predicate filter did not work as expected.");
    }
}

TEST(NSCompoundPredicate, _ANDPredicateWithSubpredicatesEval2) {
    NSArray* array = @[ @1, @2 ];

    NSPredicate* oddPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* evenPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:@[ oddPredicate, evenPredicate ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSAndPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSAndPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(YES, [filteredArray count] == 0, "FAILED: AND predicate filter did not work as expected.");
}

TEST(NSCompoundPredicate, _ANDPredicateWithSubpredicatesEvalWithNOT) {
    NSArray* array = @[ @1, @2 ];

    NSPredicate* oddPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* evenPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSCompoundPredicate* predicate3 = [NSCompoundPredicate notPredicateWithSubpredicate:evenPredicate];
    ASSERT_TRUE_MSG(predicate3 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:@[ oddPredicate, predicate3 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSAndPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSAndPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(YES, [filteredArray count] == 1, "FAILED: AND predicate filter did not work as expected.");
    ASSERT_EQ_MSG(1, [[filteredArray firstObject] integerValue], "FAILED: AND predicate filter did not work as expected.");
}

TEST(Foundation, NSCompoundPredicate_ORPredicateWithSubpredicates) {
    NSArray* predicates = [[NSArray alloc] init];
    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate orPredicateWithSubpredicates:predicates];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSOrPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSOrPredicateType.");

    [predicates release];
}

TEST(NSCompoundPredicate, ORPredicateWithSubpredicatesEval) {
    NSArray* array = @[ @1, @1, @1, @1, @1, @0 ];

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return [number integerValue] == 0;
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        return NO;
    }];

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate orPredicateWithSubpredicates:@[ predicate1, predicate2 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSOrPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSOrPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(YES, [filteredArray count] == 1, "FAILED: OR predicate filter did not work as expected.");
    ASSERT_EQ_MSG(0, [[filteredArray firstObject] integerValue], "FAILED: OR predicate filter did not work as expected.");
}

TEST(NSCompoundPredicate, ORPredicateWithSubpredicatesEval2) {
    NSArray* array = @[ @1, @2, @3, @4, @5, @6 ];

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate orPredicateWithSubpredicates:@[ predicate1, predicate2 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSOrPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSOrPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG([array count], [filteredArray count], "FAILED: OR predicate filter did not work as expected.");

    for (id object in array) {
        int val = [object integerValue];
        ASSERT_EQ_MSG(YES, [filteredArray containsObject:object], "FAILED: OR predicate filter did not work as expected.");
    }
}

TEST(NSCompoundPredicate, ORPredicateWithSubpredicatesEvalWithNOT) {
    NSArray* array = @[ @1, @2, @3, @4, @5, @6 ];

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSCompoundPredicate* predicate3 = [NSCompoundPredicate notPredicateWithSubpredicate:predicate2];
    ASSERT_TRUE_MSG(predicate3 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate orPredicateWithSubpredicates:@[ predicate1, predicate3 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSOrPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSOrPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(3, [filteredArray count], "FAILED: OR predicate filter did not work as expected.");

    for (id object in array) {
        if (([object integerValue] % 2) != 0) {
            ASSERT_EQ_MSG(YES, [filteredArray containsObject:object], "FAILED: OR predicate filter did not work as expected.");
        }
    }
}

TEST(NSCompoundPredicate, ORPredicateWithSubpredicatesEvalWithNOTWithAND) {
    // testing ((!predicate1) || (predicate2 && predicate3) || (predicate4))

    NSArray* array = @[ @1, @2, @3, @4, @5, @6, @7 ];

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSPredicate* predicate3 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        return NO;
    }];

    NSPredicate* predicate4 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] > 2);
    }];

    NSCompoundPredicate* p0 = [NSCompoundPredicate notPredicateWithSubpredicate:predicate1];
    ASSERT_TRUE_MSG(p0 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* p1 = [NSCompoundPredicate andPredicateWithSubpredicates:@[ predicate2, predicate3 ]];
    ASSERT_TRUE_MSG(p1 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate orPredicateWithSubpredicates:@[ p0, p1, predicate4 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSOrPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSOrPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(6,
                  [filteredArray count],
                  "FAILED: ((!predicate1) || (predicate2 && predicate3) || (predicate4)) filter did not work as expected.");

    for (id object in filteredArray) {
        int value = [object integerValue];
        ASSERT_EQ_MSG(YES,
                      (value >= 2) && (value <= 7),
                      "FAILED: ((!predicate1) || (predicate2 && predicate3) || (predicate4)) filter did not work as expected.");
    }
}

TEST(NSCompoundPredicate, ORPredicateWithSubpredicatesEvalWithNOTWithAND2) {
    // testing (((!predicate1) || (predicate2 && !predicate3) || (predicate4)) && (predicate5))

    NSMutableArray* array = [[NSMutableArray alloc] init];

    for (int i = 1; i < 20; ++i) {
        [array addObject:[NSNumber numberWithInt:i]];
    }

    NSPredicate* predicate1 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 != 0);
    }];

    NSPredicate* predicate2 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] % 2 == 0);
    }];

    NSPredicate* predicate3 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        return NO;
    }];

    NSPredicate* predicate4 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] > 2) && ([number integerValue] < 9);
    }];

    NSPredicate* predicate5 = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return ([number integerValue] > 12);
    }];

    NSCompoundPredicate* p0 = [NSCompoundPredicate notPredicateWithSubpredicate:predicate1];
    ASSERT_TRUE_MSG(p0 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* p1 = [NSCompoundPredicate notPredicateWithSubpredicate:predicate3];
    ASSERT_TRUE_MSG(p1 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* p2 = [NSCompoundPredicate andPredicateWithSubpredicates:@[ predicate2, p1 ]];
    ASSERT_TRUE_MSG(p2 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* p3 = [NSCompoundPredicate orPredicateWithSubpredicates:@[ p0, p2, predicate4 ]];
    ASSERT_TRUE_MSG(p3 != nil, "FAILED: compoundPredicate should be non-null!");

    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate andPredicateWithSubpredicates:@[ p3, predicate5 ]];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSAndPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSAndPredicateType.");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:compoundPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");

    ASSERT_EQ_MSG(
        3,
        [filteredArray count],
        "FAILED: (((!predicate1) || (predicate2 && !predicate3) || (predicate4)) && (predicate5)) filter did not work as expected.");

    for (int i = 14; i < 19; i++) {
        if ((i % 2) == 0) {
            ASSERT_EQ_MSG(YES,
                          [filteredArray containsObject:[NSNumber numberWithInt:i]],
                          "FAILED: (((!predicate1) || (predicate2 && !predicate3) || (predicate4)) && (predicate5)) filter did not work as "
                          "expected.");
        }
    }

    [array release];
}

TEST(NSCompoundPredicate, ArchiveAndUnarchiveObject) {
    NSCompoundPredicate* compoundPredicate = [[NSCompoundPredicate alloc] init];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:compoundPredicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");
    // unarchive
    NSCompoundPredicate* unArchivedcompoundPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedcompoundPredicate != nil, "FAILED: unArchivedcompoundPredicate should be non-null!");

    [compoundPredicate release];
}

TEST(Foundation, NSCompoundPredicate_copy) {
    NSPredicate* predicate = [[NSPredicate alloc] init];
    NSCompoundPredicate* compoundPredicate = [NSCompoundPredicate notPredicateWithSubpredicate:predicate];
    ASSERT_TRUE_MSG(compoundPredicate != nil, "FAILED: compoundPredicate should be non-null!");

    ASSERT_TRUE_MSG([compoundPredicate subpredicates] != nil, "FAILED: subpredicates should be non-null!");
    ASSERT_EQ_MSG(NSNotPredicateType, [compoundPredicate compoundPredicateType], "FAILED: type should be NSNotPredicateType.");

    NSCompoundPredicate* copyObj = [compoundPredicate copy];
    ASSERT_TRUE_MSG(copyObj != nil, "FAILED: copyObj should be non-null!");

    ASSERT_OBJCEQ_MSG([compoundPredicate subpredicates], [copyObj subpredicates], "FAILED: subpredicates do not match.");
    ASSERT_EQ_MSG([compoundPredicate compoundPredicateType],
                  [copyObj compoundPredicateType],
                  "FAILED: compoundPredicateType do not match.");

    [predicate release];
    [copyObj release];
}
