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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSPredicate, predicate) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"1<3"];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
}

TEST(NSPredicate, predicateWithValue) {
    NSPredicate* predicateTrue = [NSPredicate predicateWithValue:YES];
    ASSERT_TRUE_MSG(predicateTrue != nil, "FAILED: predicateTrue should be non-null!");

    NSPredicate* predicateFalse = [NSPredicate predicateWithValue:NO];
    ASSERT_TRUE_MSG(predicateFalse != nil, "FAILED: predicateFalse should be non-null!");

    ASSERT_TRUE_MSG([predicateTrue evaluateWithObject:nil], "FAILED: predicate should be YES.");
    ASSERT_TRUE_MSG(![predicateFalse evaluateWithObject:nil], "FAILED: predicate should be NO.");
}

TEST(NSPredicate, PredicateWithBlock) {
    NSArray* array = @[ @1, @2, @3, @7, @8, @11, @14, @19, @20 ];

    NSPredicate* evenNumbersPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return [number integerValue] % 2 == 0;
    }];

    ASSERT_TRUE_MSG(evenNumbersPredicate != nil, "FAILED: evenNumbersPredicate should be non-null!");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:evenNumbersPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");
    for (id object in array) {
        if (!([object integerValue] % 2)) {
            ASSERT_EQ_MSG(YES, [filteredArray containsObject:object], "FAILED: even filter did not work as expected, value not found.");
        }
    }
}

// Used for testing keys and custom block.
@interface Coin : NSObject
@property (assign) NSInteger coinValue;
@end

@implementation Coin
- (instancetype)initWithValue:(NSInteger)value {
    if (self == [super init]) {
        _coinValue = value;
    }
    return self;
}
@end

TEST(NSPredicate, PredicateWithBlockSub) {
    NSMutableArray* array = [[NSMutableArray alloc] init];

    int specialValue = 10;
    int size = 10;

    NSDictionary* bindings = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:specialValue] forKey:@"rareCoinValue"];
    NSPredicate* specialCoinPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* rareCoinValue = [bindings valueForKey:@"rareCoinValue"];
        return ([evaluatedObject coinValue] == [rareCoinValue integerValue]);
    }];

    ASSERT_TRUE_MSG(specialCoinPredicate != nil, "FAILED: specialCoinPredicate should be non-null!");

    for (int i = 0; i < size; ++i) {
        Coin* obj = [[[Coin alloc] initWithValue:(i * 10)] autorelease];
        [array addObject:obj];
    }

    NSMutableArray* filteredArray = [[NSMutableArray alloc] init];

    for (int i = 0; i < size; ++i) {
        id obj = [array objectAtIndex:i];
        if ([specialCoinPredicate evaluateWithObject:obj substitutionVariables:bindings]) {
            [filteredArray addObject:obj];
        }
    }

    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");
    ASSERT_EQ_MSG(1, [filteredArray count], "FAILED: failed to filter the coins.");
    ASSERT_EQ_MSG(specialValue, [[filteredArray firstObject] coinValue], "FAILED: Unable to obtain the correct coin value.");

    [filteredArray release];
    [array release];
}

TEST(NSPredicate, ArchiveAndUnarchiveObject) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"1<3"];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:predicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");

    NSPredicate* unArchivedPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedPredicate != nil, "FAILED: unArchivedPredicate should be non-null!");
}

TEST(NSPredicate, copy) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"1<3"];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    NSPredicate* copyObj = [predicate copy];
    ASSERT_TRUE_MSG(copyObj != nil, "FAILED: copyObj should be non-null!");

    ASSERT_OBJCEQ_MSG(predicate, copyObj, "FAILED: objects do not match.");

    [copyObj release];
}

TEST(NSPredicate, stringFormatTest) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"5 > 2"];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:nil substitutionVariables:nil], "5 > 2");

    predicate = [NSPredicate predicateWithFormat:@"(5 > 2) && (1 < 0)"];
    ASSERT_TRUE_MSG(![predicate evaluateWithObject:nil substitutionVariables:nil], "(5 > 2) && (1 < 0)");
}

TEST(NSPredicate, stringFormatComplexTest) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"!((5 > 2) && (1 < 0) && (1 > 0))"];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:nil substitutionVariables:nil], "!((5 > 2) && (1 < 0) && (1 > 0))");
}

@interface PredicateTestAnimal : NSObject <NSCopying>
@property (copy) NSNumber* age;
@property (copy) NSNumber* speed;
@property (copy) NSString* name;
- (instancetype)initWithName:(NSString*)name age:(NSInteger)age speed:(NSInteger)speed;
@end

@implementation PredicateTestAnimal
- (instancetype)initWithName:(NSString*)name age:(NSInteger)age speed:(NSInteger)speed {
    if (self = [super init]) {
        _name = [name copy];
        _age = [[NSNumber numberWithInt:age] retain];
        _speed = [[NSNumber numberWithInt:speed] retain];
    }
    return self;
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (void)dealloc {
    [_name release];
    [_age release];
    [_speed release];
    [super dealloc];
}
@end

NSMutableArray* obtainListOfAnimals() {
    NSMutableArray* animals = [[[NSMutableArray alloc] init] autorelease];
    for (unsigned int i = 0; i < 10; i++) {
        PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"testAnimal" age:i speed:115] autorelease];
        [animals addObject:animal];
    }
    return animals;
}

TEST(NSPredicate, stringFormatAccessClassVarsTestAge) {
    NSMutableArray* animals = obtainListOfAnimals();

    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"age == %d", 5];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:predicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, stringFormatAccessClassVarsTestName) {
    NSMutableArray* animals = obtainListOfAnimals();
    NSString* attributeName = @"testAnimal";
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"name == %@", attributeName];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:predicate];

    ASSERT_EQ_MSG(10, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, stringFormatBETWEEN) {
    NSMutableArray* animals = obtainListOfAnimals();
    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"age BETWEEN %@", @[ @0, @3 ]];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(4, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, stringFormatGreater) {
    NSMutableArray* animals = obtainListOfAnimals();
    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"age >= 5"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(5, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, stringFormatRange) {
    NSMutableArray* animals = obtainListOfAnimals();
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"cat" age:7 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"(age >= 5) AND (age <= 8) AND (name == %@)", @"cat"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, keyPathAccess) {
    NSMutableArray* animals = obtainListOfAnimals();
    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"%K >= %@", @"age", @5];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(5, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, BeginsWith) {
    NSMutableArray* animals = [NSMutableArray array];
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"aaa" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"Abc" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"adb" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"bcd" age:5 speed:115] autorelease];
    [animals addObject:animal];
    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name BEGINSWITH[cd] %@", @"a"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(3, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, EndsWith) {
    NSMutableArray* animals = [NSMutableArray array];
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"aax" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"abc" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name ENDSWITH[cd] %@", @"x"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, Contains) {
    NSMutableArray* animals = [NSMutableArray array];
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"aax" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"ABC" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name CONTAINS[c] %@", @"bc"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, Contains2) {
    NSMutableArray* animals = [NSMutableArray array];
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"aax" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name CONTAINS[cd] %@", @"b"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(0, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, InCollection) {
    NSMutableArray* animals = [NSMutableArray array];

    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test1" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"test2" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSArray* nameCollection = @[ @"test1", @"randomName" ];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name IN %@", nameCollection];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, Matches_InstanceFieldsFilteredByRegularExpression) {
    NSMutableArray* animals = [NSMutableArray array];

    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"tesp" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name MATCHES %@", @"t.*t"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(1, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, Matches_StringsFilteredByRegularExpression) {
    NSArray* array = @[
        @"TATACCATGGGCCATCATCATCATCATCATCATCATCATCATCACAG",
        @"CGGGATCCCTATCAAGGCACCTCTTCG",
        @"CATGCCATGGATACCAACGAGTCCGAAC",
        @"CAT",
        @"CATCATCATGTCT",
        @"DOG"
    ];

    // find strings that contain a repetition of at least 3 'CAT' sequences,
    // but not followed by a further 'CA'
    NSPredicate* catPredicate = [NSPredicate predicateWithFormat:@"SELF MATCHES '.*(CAT){3,}(?!CA).*'"];

    NSArray* filteredArray = [array filteredArrayUsingPredicate:catPredicate];
    ASSERT_EQ([filteredArray count], 1);
}

TEST(NSPredicate, Matches_InstanceFieldsFilterByRegexEndingInNumbers) {
    NSMutableArray* animals = [NSMutableArray array];

    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test1" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"test2" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"testp" age:5 speed:115] autorelease];
    [animals addObject:animal];

    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name MATCHES 't.*t[0-9]'"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(2, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, Like) {
    NSMutableArray* animals = [NSMutableArray array];

    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test.foo" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"test.foo" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"hello.foo" age:5 speed:115] autorelease];
    [animals addObject:animal];

    animal = [[[PredicateTestAnimal alloc] initWithName:@"atestp.foo" age:5 speed:115] autorelease];
    [animals addObject:animal];

    // Like has to be limited to *,?. This fix is coming in via #791
    NSPredicate* betweenPredicate = [NSPredicate predicateWithFormat:@"name LIKE %@", @"test*.foo"];
    NSArray* validTestAnimals = [animals filteredArrayUsingPredicate:betweenPredicate];

    ASSERT_EQ_MSG(2, [validTestAnimals count], "FAILED: Unable to filter based on class property.");
}

TEST(NSPredicate, SelfAccess) {
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"self < 9"];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:@(8) substitutionVariables:nil], "self < 9");
}

TEST(NSPredicate, SelfAccessObjectProperty) {
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test1" age:5 speed:115] autorelease];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"self.age <= 5 "];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:animal substitutionVariables:nil], "self.age <= 5");
}

TEST(NSPredicate, SelfAccessObjectPropertyNegatives) {
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test1" age:5 speed:-7] autorelease];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"self.speed <= -5 "];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:animal substitutionVariables:nil], "self.speed <= -5");

    predicate = [NSPredicate predicateWithFormat:@"               self.speed >= -7             "];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:animal substitutionVariables:nil], "self.speed >= -7");

    predicate = [NSPredicate predicateWithFormat:@"     NOT((self.speed >= -7) AND (self.age < -15))    "];
    ASSERT_TRUE_MSG([predicate evaluateWithObject:animal substitutionVariables:nil], "(self.speed >= -7) AND (self.age < 5)");
}

TEST(NSPredicate, SubPredicate) {
    PredicateTestAnimal* animal = [[[PredicateTestAnimal alloc] initWithName:@"test1" age:5 speed:-7] autorelease];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"self.speed <= $SPEED"];

    predicate =
        [predicate predicateWithSubstitutionVariables:[NSDictionary dictionaryWithObject:[NSNumber numberWithInteger:-5] forKey:@"SPEED"]];

    ASSERT_TRUE_MSG([predicate evaluateWithObject:animal substitutionVariables:nil], "self.speed <= -5");
}
