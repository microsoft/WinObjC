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
#import <mach/mach_time.h>

TEST(Foundation, SanityTest) {
    LOG_INFO("Foundation sanity test: ");

    /*** NSArray ***/
    NSArray* arr1 = [NSArray arrayWithObject:@1];
    NSArray* arr2 = [NSArray arrayWithObject:@1];
    NSArray* arr3 = [NSArray arrayWithObject:@2];

    ASSERT_OBJCEQ_MSG(arr1, arr2, "FAILED: arr1 and arr2 should be equal!\n");
    ASSERT_OBJCNE_MSG(arr1, arr3, "FAILED: arr1 and arr2 should not be equal!\n");
    ASSERT_OBJCEQ_MSG(arr1[0], arr2[0], "FAILED: arr1[0] and arr2[0] should be equal!\n");
    ASSERT_OBJCNE_MSG(arr1[0], arr3[0], "FAILED: arr1[0] and arr3[0] should not be equal!\n");

    /*** NSCalendar ***/
    //  Feb 14, 2012 12:00 GMT (leap year)
    NSDate* startDate = [NSDate dateWithTimeIntervalSince1970:1329220800.0];
    //  Apr 1, 2012 12:00 GMT
    NSDate* endDate = [NSDate dateWithTimeIntervalSince1970:1333281600.0];

    NSTimeZone* curTZ = [NSTimeZone timeZoneWithName:@"America/Los_Angeles"];

    ASSERT_FALSE_MSG(([curTZ isDaylightSavingTimeForDate:startDate] != NO || [curTZ isDaylightSavingTimeForDate:endDate] != YES),
                     "FAILED: timezone daylight savings time failure: %d %d\n",
                     [curTZ isDaylightSavingTimeForDate:startDate],
                     [curTZ isDaylightSavingTimeForDate:endDate]);

    NSCalendar* curCal = [NSCalendar currentCalendar];
    [curCal setTimeZone:curTZ];

    NSDateComponents* component1 = [curCal components:NSSecondCalendarUnit | NSMinuteCalendarUnit | NSHourCalendarUnit | NSDayCalendarUnit |
                                                      NSMonthCalendarUnit | NSYearCalendarUnit
                                             fromDate:startDate];
    ASSERT_FALSE_MSG(component1.second != 0 || component1.minute != 0 || component1.hour != 4 || component1.day != 14 ||
                         component1.month != 2 || component1.year != 2012,
                     "FAILED: component1 not accurate: %d %d %d %d %d %d\n",
                     component1.second,
                     component1.minute,
                     component1.hour,
                     component1.day,
                     component1.month,
                     component1.year);

    NSDateComponents* comp1 = [curCal components:NSSecondCalendarUnit | NSMinuteCalendarUnit | NSHourCalendarUnit | NSDayCalendarUnit |
                                                 NSMonthCalendarUnit | NSYearCalendarUnit
                                        fromDate:startDate
                                          toDate:endDate
                                         options:0];

    ASSERT_FALSE_MSG(comp1.second != 0 || comp1.minute != 0 || comp1.hour != 1 || comp1.day != 18 || comp1.month != 1 || comp1.year != 0,
                     "FAILED: component1 not accurate: %d %d %d %d %d %d\n",
                     component1.second,
                     component1.minute,
                     component1.hour,
                     component1.day,
                     component1.month,
                     component1.year);

    NSDateComponents* comp2 = [curCal components:NSSecondCalendarUnit fromDate:startDate toDate:endDate options:0];
    ASSERT_EQ_MSG(comp2.second, 4060800, "FAILED: comp2 not accurate: %d\n", comp2.second);

    /*** NSNull ***/
    NSNull *nul1 = [NSNull null], *nul2 = [NSNull alloc], *nul3 = [NSNull new], *nul4 = [nul1 copy];
    ASSERT_FALSE_MSG(nul1 != nul2 || nul2 != nul3 || nul3 != nul4 || ![nul1 isEqual:nul4],
                     "FAILED: comp1 not accurate: %d %d %d %d %d %d\n",
                     comp1.second,
                     comp1.minute,
                     comp1.hour,
                     comp1.day,
                     comp1.month,
                     comp1.year);
}

TEST(Foundation, NSUUID) {
    NSUUID* uuidA = [NSUUID UUID];
    NSUUID* uuidB = [NSUUID UUID];
    NSUUID* uuidC = [NSUUID UUID];
    ASSERT_OBJCNE_MSG(uuidA, uuidB, "FAILED: NSUUID instances should be unique");
    ASSERT_OBJCNE_MSG(uuidB, uuidC, "FAILED: NSUUID instances should be unique");

    NSUUID* uuidAClone = [[NSUUID alloc] initWithUUIDString:[uuidA UUIDString]];
    ASSERT_OBJCEQ_MSG((id)uuidA,
                      (id)uuidAClone,
                      "FAILED: An NSUUID created from parsing the string format of another UUID should equal it.");

    NSUUID* uuidBad = [[NSUUID alloc] initWithUUIDString:@"HELLOWOR-LDTH-ISIS-ABAD-UUIDSTRING!!"];
    ASSERT_TRUE_MSG(uuidBad == nil, "FAILED: NSUUID should have failed to parse this weird string: %s", [[uuidBad description] UTF8String]);

    NSUUID* uuidShort = [[NSUUID alloc] initWithUUIDString:@"000000"];
    ASSERT_TRUE_MSG(uuidShort == nil,
                    "FAILED: NSUUID should have failed to parse this short string: %s",
                    [[uuidShort description] UTF8String]);
}

@interface TestKVOSelfObserver : NSObject {
    id _dummy;
}
@end
@implementation TestKVOSelfObserver
- (id)init {
    if (self = [super init]) {
        [self addObserver:self forKeyPath:@"dummy" options:0 context:nullptr];
    }
    return self;
}
- (void)dealloc {
    [self removeObserver:self forKeyPath:@"dummy"];
    [super dealloc];
}
@end

@interface TestKVOChange : NSObject
@property (nonatomic, copy) NSString* keypath;
@property (nonatomic, assign /*weak but no arc*/) id object;
@property (nonatomic, copy) NSDictionary* info;
@property (nonatomic, assign) void* context;
@end
@implementation TestKVOChange
+ (id)changeWithKeypath:(NSString*)keypath object:(id)object info:(NSDictionary*)info context:(void*)context {
    TestKVOChange* change = [[self alloc] init];
    change.keypath = keypath;
    change.object = object;
    change.info = info;
    change.context = context;
    return change;
}
@end

@interface TestKVOObserver : NSObject {
    NSMutableDictionary* _changedKeypaths;
}
- (void)observeValueForKeyPath:(NSString*)keypath ofObject:(id)object change:(NSDictionary*)change context:(void*)context;
- (NSSet*)changesForKeypath:(NSString*)keypath;
- (NSInteger)numberOfObservedChanges;
@end

@implementation TestKVOObserver
- (id)init {
    if (self = [super init]) {
        _changedKeypaths = [NSMutableDictionary dictionary];
    }
    return self;
}
- (void)observeValueForKeyPath:(NSString*)keypath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    @synchronized(self) {
        NSMutableSet* changeSet = _changedKeypaths[keypath];
        if (!changeSet) {
            changeSet = [NSMutableSet set];
            _changedKeypaths[keypath] = changeSet;
        }
        [changeSet addObject:[TestKVOChange changeWithKeypath:keypath object:object info:change context:context]];
    }
}
- (NSSet*)changesForKeypath:(NSString*)keypath {
    @synchronized(self) {
        return [_changedKeypaths[keypath] copy];
    }
}
- (void)clear {
    @synchronized(self) {
        [_changedKeypaths removeAllObjects];
    }
}
- (NSInteger)numberOfObservedChanges {
    @synchronized(self) {
        NSInteger accumulator = 0;
        for (NSString* keypath in [_changedKeypaths allKeys]) {
            accumulator += [[_changedKeypaths objectForKey:keypath] count];
        }
        return accumulator;
    }
}
@end

struct TestKVOStruct {
    int a, b, c;
};

@interface TestKVOObject : NSObject {
    int _manuallyNotifyingIntegerProperty;
    int _ivarWithoutSetter;
}

@property (nonatomic, retain) NSString* nonNotifyingObjectProperty;

@property (nonatomic, retain) NSString* basicObjectProperty;
@property (nonatomic, assign) uint32_t basicPodProperty;
@property (nonatomic, assign) TestKVOStruct structProperty;

// derivedObjectProperty is derived from basicObjectProperty.
@property (nonatomic, readonly) NSString* derivedObjectProperty;

@property (nonatomic, retain) TestKVOObject* cascadableKey;

@property (nonatomic, retain) id recursiveDependent1;
@property (nonatomic, retain) id recursiveDependent2;

@property (nonatomic, retain) NSMutableDictionary* dictionaryProperty;

// This modifies the internal integer property and notifies about it.
- (void)incrementManualIntegerProperty;
@end

@implementation TestKVOObject
- (void)dealloc {
    [_cascadableKey release];
    [super dealloc];
}

+ (NSSet*)keyPathsForValuesAffectingDerivedObjectProperty {
    return [NSSet setWithObject:@"basicObjectProperty"];
}

+ (NSSet*)keyPathsForValuesAffectingRecursiveDependent1 {
    return [NSSet setWithObject:@"recursiveDependent2"];
}

+ (NSSet*)keyPathsForValuesAffectingRecursiveDependent2 {
    return [NSSet setWithObject:@"recursiveDependent1"];
}

+ (BOOL)automaticallyNotifiesObserversOfManuallyNotifyingIntegerProperty {
    return NO;
}

+ (BOOL)automaticallyNotifiesObserversOfNonNotifyingObjectProperty {
    return NO;
}

- (NSString*)derivedObjectProperty {
    return [NSString stringWithFormat:@"!!!%@!!!", _basicObjectProperty];
}

- (void)incrementManualIntegerProperty {
    [self willChangeValueForKey:@"manuallyNotifyingIntegerProperty"];
    _manuallyNotifyingIntegerProperty++;
    [self didChangeValueForKey:@"manuallyNotifyingIntegerProperty"];
}
@end

@interface TestKVOObject2 : NSObject
@property (nonatomic, assign) float someFloat;
@end
@implementation TestKVOObject2
@end

TEST(Foundation, KeyValueObservation_BasicChangeNotification) { // Basic change notification
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count], 1, "One change on basicObjectProperty should have fired.");
    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicPodProperty"] count], 0, "Zero changes on basicPodProperty should have fired.");
    EXPECT_EQ_MSG([[observer changesForKeypath:@"derivedObjectProperty"] count],
                  0,
                  "Zero changes on derivedObjectProperty should have fired.");

    EXPECT_OBJCEQ_MSG([[[observer changesForKeypath:@"basicObjectProperty"] anyObject] object],
                      observed,
                      "The notification object should match the observed object.");
    EXPECT_OBJCEQ_MSG(nil,
                      [[[[observer changesForKeypath:@"basicObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeOldKey],
                      "There should be no old value included in the change notification.");
    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"basicObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey],
                      @"Hello",
                      "The new value stored in the change notification should be Hello.");
}

TEST(Foundation, KeyValueObservation_ExclusiveChangeNotification) { // Exclusive change notification
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    TestKVOObserver* observer2 = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer2 forKeyPath:@"basicPodProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.basicObjectProperty = @"Hello";
    observed.basicPodProperty = 1;

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count], 1, "One change on basicObjectProperty should have fired.");
    EXPECT_EQ_MSG([[observer2 changesForKeypath:@"basicObjectProperty"] count],
                  0,
                  "No changes on basicObjectProperty for second observer should have fired.");
    EXPECT_EQ_MSG([[observer2 changesForKeypath:@"basicPodProperty"] count], 1, "One change on basicPodProperty should have fired.");
    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicPodProperty"] count],
                  0,
                  "No changes on basicPodProperty for second observer should have fired.");
}

TEST(Foundation, KeyValueObservation_ManualChangeNotification) { // Manual change notification.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"manuallyNotifyingIntegerProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed incrementManualIntegerProperty];

    EXPECT_EQ_MSG([[observer changesForKeypath:@"manuallyNotifyingIntegerProperty"] count],
                  1,
                  "One change on manuallyNotifyingIntegerProperty should have fired.");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"manuallyNotifyingIntegerProperty"] anyObject] info]
                          objectForKey:NSKeyValueChangeNewKey],
                      @(1),
                      "The new value stored in the change notification should be a boxed 1.");
}

TEST(Foundation, KeyValueObservation_BasicChangeCaptureOld) { // Basic change notification with Old Value
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionOld context:NULL];
    observed.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count], 1, "One change on basicObjectProperty should have fired.");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"basicObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeOldKey],
                      [NSNull null],
                      "The old value stored in the change notification should be null.");
}

TEST(Foundation, KeyValueObservation_CascadingNotificationWithEmptyLeaf) { // Cascading change notification testing subscribing to nil AND
                                                                           // property replacement
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer
               forKeyPath:@"cascadableKey.basicObjectProperty"
                  options:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                  context:NULL];

    TestKVOObject* subObject = [[TestKVOObject alloc] init];
    subObject.basicObjectProperty = @"Hello";
    observed.cascadableKey = subObject;

    EXPECT_EQ_MSG([[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] count],
                  1,
                  "One change on cascadableKey.basicObjectProperty should have fired.");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] anyObject] info]
                          objectForKey:NSKeyValueChangeOldKey],
                      [NSNull null],
                      "The old value stored in the change notification should be null.");

    [observer clear];

    TestKVOObject* subObject2 = [[TestKVOObject alloc] init];
    subObject2.basicObjectProperty = @"Hello";
    observed.cascadableKey = subObject2;

    EXPECT_EQ_MSG([[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] count],
                  1,
                  "A second change on cascadableKey.basicObjectProperty should have fired.");

    subObject.basicObjectProperty = @"Spurious?";

    EXPECT_NE_MSG([[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] count],
                  2,
                  "A change to the detached subkey should not have triggered a spurious notification.");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] anyObject] info]
                          objectForKey:NSKeyValueChangeOldKey],
                      @"Hello",
                      "The old value stored in the change notification should be Hello.");
}

TEST(Foundation, KeyValueObservation_PriorNotification) { // Basic change notification with a Prior notification requested
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer
               forKeyPath:@"basicObjectProperty"
                  options:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionPrior
                  context:NULL];
    observed.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count],
                  2,
                  "Two changes on basicObjectProperty should have fired (one prior change).");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"basicObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeOldKey],
                      [NSNull null],
                      "The old value stored in the change notification should be null or nil.");
}

TEST(Foundation, KeyValueObservation_DependentKeyNotification) { // Derived change notification (dependent keys)
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"derivedObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count],
                  0,
                  "No changes on basicObjectProperty should have fired (we did not register for it).");
    EXPECT_EQ_MSG([[observer changesForKeypath:@"derivedObjectProperty"] count],
                  1,
                  "One change on derivedObjectProperty should have fired.");
    [observed removeObserver:observer forKeyPath:@"derivedObjectProperty"];

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"derivedObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey],
                      @"!!!Hello!!!",
                      "The new value stored in the change notification should be !!!Hello!!! (the derived object).");
}

TEST(Foundation, KeyValueObservation_PODNotification) { // Notification on a plain old data property (non-object)
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicPodProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.basicPodProperty = 10;

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicPodProperty"] count], 1, "One change on basicPodProperty should have fired.");

    EXPECT_TRUE_MSG([[[[[observer changesForKeypath:@"basicPodProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey]
                        isKindOfClass:[NSNumber class]],
                    "The new value stored in the change notification should be an NSNumber instance.");
    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"basicPodProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey],
                      @(10),
                      "The new value stored in the change notification should be a boxed 10.");
}

TEST(Foundation, KeyValueObservation_StructNotification) { // Basic change notification on a struct type
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count], 0, "No changes on basicObjectProperty should have fired.");
    [observed addObserver:observer forKeyPath:@"structProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.structProperty = TestKVOStruct{ 1, 2, 3 };

    EXPECT_EQ_MSG([[observer changesForKeypath:@"structProperty"] count], 1, "One change on structProperty should have fired.");

    EXPECT_TRUE_MSG([[[[[observer changesForKeypath:@"structProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey]
                        isKindOfClass:[NSValue class]],
                    "The new value stored in the change notification should be an NSValue instance.");
    EXPECT_STREQ_MSG([[[[[observer changesForKeypath:@"structProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey] objCType],
                     @encode(TestKVOStruct),
                     "The new objc type stored in the change notification should have an objc type matching our Struct.");
}

TEST(Foundation, KeyValueObservation_DisabledNotification) { // No notification for non-notifying keypaths.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"nonNotifyingObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    observed.nonNotifyingObjectProperty = @"Whatever";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"nonNotifyingObjectProperty"] count],
                  0,
                  "No changes for nonNotifyingObjectProperty should have fired.");
}

TEST(Foundation, KeyValueObservation_DisabledInitialNotification) { // Initial notification for non-notifying keypaths.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"nonNotifyingObjectProperty" options:NSKeyValueObservingOptionInitial context:NULL];
    observed.nonNotifyingObjectProperty = @"Whatever";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"nonNotifyingObjectProperty"] count],
                  1,
                  "An INITIAL notification for nonNotifyingObjectProperty should have fired.");
}

TEST(Foundation, KeyValueObservation_SetValueForKeyIvarNotification) { // Notification of ivar change through setValue:forKey:
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"ivarWithoutSetter" options:NSKeyValueObservingOptionNew context:NULL];
    [observed setValue:@(1024) forKey:@"ivarWithoutSetter"];

    EXPECT_EQ_MSG([[observer changesForKeypath:@"ivarWithoutSetter"] count],
                  1,
                  "One change on ivarWithoutSetter should have fired (using setValue:forKey:).");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"ivarWithoutSetter"] anyObject] info] objectForKey:NSKeyValueChangeNewKey],
                      @(1024),
                      "The new value stored in the change notification should a boxed 1024.");
}

TEST(Foundation, KeyValueObservation_SetValueForKeyPropertyNotification) { // Notification through setValue:forKey: to make sure that we do
                                                                           // not get two notifications for the same change.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed setValue:@(1024) forKey:@"basicObjectProperty"];

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count],
                  1,
                  "ONLY one change on basicObjectProperty should have fired (using setValue:forKey: should not fire twice).");

    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"basicObjectProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey],
                      @(1024),
                      "The new value stored in the change notification should a boxed 1024.");
}

TEST(Foundation,
     KeyValueObservation_DictionaryNotification) { // Basic notification on a dictionary, which does not have properties or ivars.
    NSMutableDictionary* observed = [NSMutableDictionary dictionary];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed setObject:[[[TestKVOObject alloc] init] autorelease] forKey:@"subKey"];

    [observed addObserver:observer forKeyPath:@"arbitraryValue" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"subKey.basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];

    [observed setObject:@"Whatever" forKey:@"arbitraryValue"];
    [observed setValue:@"Whatever2" forKeyPath:@"arbitraryValue"];
    [observed setValue:@"Whatever2" forKeyPath:@"subKey.basicObjectProperty"];

    EXPECT_EQ_MSG([[observer changesForKeypath:@"arbitraryValue"] count],
                  2,
                  "On a NSMutableDictionary, a change notification for arbitraryValue.");
    EXPECT_EQ_MSG([[observer changesForKeypath:@"subKey.basicObjectProperty"] count],
                  1,
                  "On a NSMutableDictionary, a change notification for subKey.basicObjectProperty.");
}

TEST(Foundation, KeyValueObservation_BasicDeregistration) { // Deregistration test
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed removeObserver:observer forKeyPath:@"basicObjectProperty" context:NULL];
    observed.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"basicObjectProperty"] count], 0, "No changes on basicObjectProperty should have fired.");

    TestKVOObject* subObject = [[TestKVOObject alloc] init];
    observed.cascadableKey = subObject;

    [observed addObserver:observer forKeyPath:@"cascadableKey.basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed removeObserver:observer forKeyPath:@"cascadableKey.basicObjectProperty" context:NULL];

    subObject.basicObjectProperty = @"Hello";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] count],
                  0,
                  "No changes on cascadableKey.basicObjectProperty should have fired.");
}

TEST(Foundation, KeyValueObservation_DeeplyNested1) { // Double derived depth test
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer
               forKeyPath:@"cascadableKey.derivedObjectProperty.length"
                  options:NSKeyValueObservingOptionNew
                  context:NULL];

    TestKVOObject* subObject = [[TestKVOObject alloc] init];
    subObject.basicObjectProperty = @"Hello";
    observed.cascadableKey = subObject;

    EXPECT_EQ_MSG([[observer changesForKeypath:@"cascadableKey.derivedObjectProperty.length"] count],
                  1,
                  "One change on cascade.derived.length should have fired.");
    EXPECT_OBJCEQ_MSG([[[[observer changesForKeypath:@"cascadableKey.derivedObjectProperty.length"] anyObject] info]
                          objectForKey:NSKeyValueChangeNewKey],
                      @(11),
                      "The new value stored in the change notification should a boxed 11.");

    [observed removeObserver:observer forKeyPath:@"cascadableKey.derivedObjectProperty.length" context:NULL];

    [observer clear];

    subObject.basicObjectProperty = @"Whatever";

    EXPECT_EQ_MSG([[observer changesForKeypath:@"cascadableKey.derivedObjectProperty.length"] count],
                  0,
                  "No additional changes on cascade.derived.length should have fired.");
}

TEST(Foundation, KeyValueObservation_Nested1) { // Test normally-nested observation and value replacement
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey" options:0 context:nil];

    TestKVOObject* child = [[TestKVOObject alloc] init];

    observed.cascadableKey = child;
    observed.cascadableKey = nil;

    [child release];

    EXPECT_EQ(2, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_DeeplyNested2) { // Test deeply-nested observation
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey.cascadableKey" options:0 context:nil];

    TestKVOObject* child = [[TestKVOObject alloc] init];
    TestKVOObject* childChild = [[TestKVOObject alloc] init];

    observed.cascadableKey = child;
    observed.cascadableKey.cascadableKey = childChild;
    observed.cascadableKey.cascadableKey = nil;
    observed.cascadableKey = nil;

    [child release];
    [childChild release];

    EXPECT_EQ(4, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_LeafReplacement1) { // Test key value replacement and re-registration (1)
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    TestKVOObject* child = [[TestKVOObject alloc] init];
    observed.cascadableKey = child;
    [child release];

    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey" options:0 context:nil];

    observed.cascadableKey = nil;

    EXPECT_EQ(1, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_LeafReplacement2) { // Test key value replacement and re-registration (2)
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    TestKVOObject* child = [[TestKVOObject alloc] init];
    observed.cascadableKey = child;
    [child release];

    TestKVOObject* childChild = [[TestKVOObject alloc] init];
    child.cascadableKey = childChild;
    [childChild release];

    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey.cascadableKey" options:0 context:nil];

    observed.cascadableKey.cascadableKey = nil;
    observed.cascadableKey = nil;

    EXPECT_EQ(2, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_LeafReplacement3) { // Test key value replacement and re-registration (3)
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    TestKVOObject* child1 = [[TestKVOObject alloc] init];
    TestKVOObject* child2 = [[TestKVOObject alloc] init];

    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey" options:0 context:nil];

    observed.cascadableKey = child1;
    [child1 release];

    observed.cascadableKey = child2;
    [child2 release];

    observed.cascadableKey = nil;

    EXPECT_EQ(3, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_NestingWithReplacement) { // Test a more complex nested observation system
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    TestKVOObject* child1 = [[TestKVOObject alloc] init];
    TestKVOObject* child2 = [[TestKVOObject alloc] init];
    TestKVOObject* child3 = [[TestKVOObject alloc] init];
    TestKVOObject* child4 = [[TestKVOObject alloc] init];

    [observed addObserver:observer forKeyPath:@"cascadableKey.cascadableKey" options:0 context:nil];

    observed.cascadableKey = child1;
    [child1 release];

    observed.cascadableKey = nil;

    observed.cascadableKey = child2;
    [child2 release];

    observed.cascadableKey = nil;

    observed.cascadableKey = child3;
    child3.cascadableKey = child4;
    [child4 release];
    [child3 release];

    observed.cascadableKey = nil;

    EXPECT_EQ(7, [observer numberOfObservedChanges]);

    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"cascadableKey.cascadableKey"]);

    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_NestingInitial) { // Test initial observation on nested keys
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    TestKVOObject* child1 = [[TestKVOObject alloc] init];
    observed.cascadableKey = child1;

    [observed addObserver:observer
               forKeyPath:@"cascadableKey.basicObjectProperty"
                  options:NSKeyValueObservingOptionInitial | NSKeyValueObservingOptionNew
                  context:nil];
    [observed addObserver:observer
               forKeyPath:@"cascadableKey.basicPodProperty"
                  options:NSKeyValueObservingOptionInitial | NSKeyValueObservingOptionNew
                  context:nil];
    [observed addObserver:observer
               forKeyPath:@"cascadableKey.derivedObjectProperty"
                  options:NSKeyValueObservingOptionInitial | NSKeyValueObservingOptionNew
                  context:nil];

    EXPECT_EQ(3, [observer numberOfObservedChanges]);
    EXPECT_OBJCEQ([NSNull null],
                  [[[[observer changesForKeypath:@"cascadableKey.basicObjectProperty"] anyObject] info]
                      objectForKey:NSKeyValueChangeNewKey]);
    EXPECT_OBJCEQ(@(0),
                  [[[[observer changesForKeypath:@"cascadableKey.basicPodProperty"] anyObject] info] objectForKey:NSKeyValueChangeNewKey]);
    EXPECT_OBJCEQ(@"!!!(null)!!!",
                  [[[[observer changesForKeypath:@"cascadableKey.derivedObjectProperty"] anyObject] info]
                      objectForKey:NSKeyValueChangeNewKey]);
}

TEST(Foundation, KeyValueObservation_DependencyLoop) { // Make sure that dependency loops don't cause crashes.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    EXPECT_NO_THROW([observed addObserver:observer forKeyPath:@"recursiveDependent1" options:0 context:nil]);
    EXPECT_NO_THROW([observed addObserver:observer forKeyPath:@"recursiveDependent2" options:0 context:nil]);
    observed.recursiveDependent1 = @"x";
    observed.recursiveDependent2 = @"y";
    EXPECT_EQ(4, [observer numberOfObservedChanges]);
    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"recursiveDependent1"]);
    EXPECT_NO_THROW([observed removeObserver:observer forKeyPath:@"recursiveDependent2"]);
    EXPECT_NO_THROW([observer release]);
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_ObserveAllProperties) {
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer forKeyPath:@"basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"basicPodProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"structProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"derivedObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"cascadableKey" options:NSKeyValueObservingOptionNew context:NULL];
    [observed addObserver:observer forKeyPath:@"cascadableKey.basicObjectProperty" options:NSKeyValueObservingOptionNew context:NULL];

    observed.basicObjectProperty = @"WHAT"; // 2 here
    observed.basicPodProperty = 10; // 1
    observed.structProperty = TestKVOStruct{ 1, 2, 3 }; // 1

    TestKVOObject* subObject = [[TestKVOObject alloc] init];
    subObject.basicObjectProperty = @"Hello";
    observed.cascadableKey = subObject; // 2 here

    EXPECT_EQ_MSG([observer numberOfObservedChanges], 6, "There should have been 6 observed changes on the observer.");

    EXPECT_ANY_THROW([observed release]);
    EXPECT_NO_THROW([subObject release]);
}

TEST(Foundation, KeyValueObservation_RemoveWithoutContext) { // Test removal without specifying context.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer
               forKeyPath:@"basicObjectProperty"
                  options:NSKeyValueObservingOptionNew
                  context:reinterpret_cast<void*>(1)];
    [observed addObserver:observer
               forKeyPath:@"basicObjectProperty"
                  options:NSKeyValueObservingOptionNew
                  context:reinterpret_cast<void*>(2)];
    [observed removeObserver:observer forKeyPath:@"basicObjectProperty"];

    observed.basicObjectProperty = @"";

    EXPECT_EQ_MSG([observer numberOfObservedChanges],
                  1,
                  "There should be only one change notification despite registering two with contexts.");
}

TEST(Foundation, KeyValueObservation_DuplicateContext) { // Test adding duplicate contexts
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    [observed addObserver:observer
               forKeyPath:@"basicObjectProperty"
                  options:NSKeyValueObservingOptionNew
                  context:reinterpret_cast<void*>(1)];
    [observed addObserver:observer
               forKeyPath:@"basicObjectProperty"
                  options:NSKeyValueObservingOptionNew
                  context:reinterpret_cast<void*>(1)];

    observed.basicObjectProperty = @"";

    EXPECT_EQ_MSG([observer numberOfObservedChanges], 2, "There should be two observed changes, despite the identical registration.");

    [observed removeObserver:observer forKeyPath:@"basicObjectProperty" context:reinterpret_cast<void*>(1)];

    observed.basicObjectProperty = @"";

    EXPECT_EQ_MSG([observer numberOfObservedChanges],
                  3,
                  "There should be one additional observed change; the removal should have only effected one.");
}

TEST(Foundation, KeyValueObservation_RemoveUnregistered) { // Test removing an urnegistered observer
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];

    EXPECT_ANY_THROW_MSG([observed removeObserver:observer forKeyPath:@"basicObjectProperty" context:reinterpret_cast<void*>(1)],
                         "Removing an unregistered observer should throw an exception.");
}

TEST(Foundation, KeyValueObservation_SelfObservationDealloc) { // Test deallocation of an object that is its own observer
    TestKVOSelfObserver* observed = [[TestKVOSelfObserver alloc] init];
    EXPECT_NO_THROW([observed release]);
}

TEST(Foundation, KeyValueObservation_CascadeWithDiverseTypes) {
    TestKVOObject2* floatGuy = [[[TestKVOObject2 alloc] init] autorelease];
    floatGuy.someFloat = 1.234f;
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObject* child = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    child.dictionaryProperty = [NSMutableDictionary dictionaryWithObjectsAndKeys:floatGuy, @"floatGuy", nil];
    observed.cascadableKey = child;
    [observed addObserver:observer forKeyPath:@"cascadableKey.dictionaryProperty.floatGuy.someFloat" options:0 context:nil];
    observed.cascadableKey = child;
    EXPECT_EQ([observer numberOfObservedChanges], 1);
}

TEST(Foundation, KeyValueObservation_CascadeWithDiverseTypesInitializedToNil) {
    // The same test as above, but testing nil value reconstitution to ensure that the keypath is wired up properly.
    TestKVOObject* observed = [[TestKVOObject alloc] init];
    TestKVOObserver* observer = [[TestKVOObserver alloc] init];
    [observed addObserver:observer forKeyPath:@"cascadableKey.dictionaryProperty.floatGuy.someFloat" options:0 context:nil];

    TestKVOObject2* floatGuy = [[[TestKVOObject2 alloc] init] autorelease];
    floatGuy.someFloat = 1.234f;
    TestKVOObject* child = [[TestKVOObject alloc] init];
    child.dictionaryProperty = [NSMutableDictionary dictionaryWithObjectsAndKeys:floatGuy, @"floatGuy", nil];

    observed.cascadableKey = child;
    observed.cascadableKey = child;

    EXPECT_EQ([observer numberOfObservedChanges], 2);
}
