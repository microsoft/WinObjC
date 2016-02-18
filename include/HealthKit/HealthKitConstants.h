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
#pragma once

#import <HealthKit/HealthKitExport.h>
#import <Foundation/NSObjCRuntime.h>

@class NSString;

typedef enum : NSInteger {
    HKBodyTemperatureSensorLocationOther = 0,
    HKBodyTemperatureSensorLocationArmpit,
    HKBodyTemperatureSensorLocationBody,
    HKBodyTemperatureSensorLocationEar,
    HKBodyTemperatureSensorLocationFinger,
    HKBodyTemperatureSensorLocationGastroIntestinal,
    HKBodyTemperatureSensorLocationMouth,
    HKBodyTemperatureSensorLocationRectum,
    HKBodyTemperatureSensorLocationToe,
    HKBodyTemperatureSensorLocationEarDrum,
    HKBodyTemperatureSensorLocationTemporalArtery,
    HKBodyTemperatureSensorLocationForehead,
} HKBodyTemperatureSensorLocation;

typedef enum : NSInteger {
    HKHeartRateSensorLocationOther = 0,
    HKHeartRateSensorLocationChest,
    HKHeartRateSensorLocationWrist,
    HKHeartRateSensorLocationFinger,
    HKHeartRateSensorLocationHand,
    HKHeartRateSensorLocationEarLobe,
    HKHeartRateSensorLocationFoot,
} HKHeartRateSensorLocation;

typedef enum : NSUInteger {
    HKWorkoutActivityTypeAmericanFootball = 1,
    HKWorkoutActivityTypeArchery,
    HKWorkoutActivityTypeAustralianFootball,
    HKWorkoutActivityTypeBadminton,
    HKWorkoutActivityTypeBaseball,
    HKWorkoutActivityTypeBasketball,
    HKWorkoutActivityTypeBowling,
    HKWorkoutActivityTypeBoxing,
    HKWorkoutActivityTypeClimbing,
    HKWorkoutActivityTypeCricket,
    HKWorkoutActivityTypeCrossTraining,
    HKWorkoutActivityTypeCurling,
    HKWorkoutActivityTypeCycling,
    HKWorkoutActivityTypeDance,
    HKWorkoutActivityTypeDanceInspiredTraining,
    HKWorkoutActivityTypeElliptical,
    HKWorkoutActivityTypeEquestrianSports,
    HKWorkoutActivityTypeFencing,
    HKWorkoutActivityTypeFishing,
    HKWorkoutActivityTypeFunctionalStrengthTraining,
    HKWorkoutActivityTypeGolf,
    HKWorkoutActivityTypeGymnastics,
    HKWorkoutActivityTypeHandball,
    HKWorkoutActivityTypeHiking,
    HKWorkoutActivityTypeHockey,
    HKWorkoutActivityTypeHunting,
    HKWorkoutActivityTypeLacrosse,
    HKWorkoutActivityTypeMartialArts,
    HKWorkoutActivityTypeMindAndBody,
    HKWorkoutActivityTypeMixedMetabolicCardioTraining,
    HKWorkoutActivityTypePaddleSports,
    HKWorkoutActivityTypePlay,
    HKWorkoutActivityTypePreparationAndRecovery,
    HKWorkoutActivityTypeRacquetball,
    HKWorkoutActivityTypeRowing,
    HKWorkoutActivityTypeRugby,
    HKWorkoutActivityTypeRunning,
    HKWorkoutActivityTypeSailing,
    HKWorkoutActivityTypeSkatingSports,
    HKWorkoutActivityTypeSnowSports,
    HKWorkoutActivityTypeSoccer,
    HKWorkoutActivityTypeSoftball,
    HKWorkoutActivityTypeSquash,
    HKWorkoutActivityTypeStairClimbing,
    HKWorkoutActivityTypeSurfingSports,
    HKWorkoutActivityTypeSwimming,
    HKWorkoutActivityTypeTableTennis,
    HKWorkoutActivityTypeTennis,
    HKWorkoutActivityTypeTrackAndField,
    HKWorkoutActivityTypeTraditionalStrengthTraining,
    HKWorkoutActivityTypeVolleyball,
    HKWorkoutActivityTypeWalking,
    HKWorkoutActivityTypeWaterFitness,
    HKWorkoutActivityTypeWaterPolo,
    HKWorkoutActivityTypeWaterSports,
    HKWorkoutActivityTypeWrestling,
    HKWorkoutActivityTypeYoga,
    HKWorkoutActivityTypeOther = 3000,
} HKWorkoutActivityType;

typedef enum : NSInteger {
    HKWorkoutSessionStateNotStarted = 1,
    HKWorkoutSessionStateRunning,
    HKWorkoutSessionStateEnded,
} HKWorkoutSessionState;

typedef enum : NSInteger {
    HKWorkoutSessionLocationTypeUnknown = 1,
    HKWorkoutSessionLocationTypeIndoor,
    HKWorkoutSessionLocationTypeOutdoor,
} HKWorkoutSessionLocationType;

typedef enum : NSInteger {
    HKNoError = 0,
    HKErrorHealthDataUnavailable,
    HKErrorHealthDataRestricted,
    HKErrorInvalidArgument,
    HKErrorAuthorizationDenied,
    HKErrorAuthorizationNotDetermined,
    HKErrorDatabaseInaccessible,
    HKErrorUserCanceled,
    HKErrorAnotherWorkoutSessionStarted,
    HKErrorUserExitedWorkoutSession,
} HKErrorCode;

typedef enum : NSInteger {
    HKUpdateFrequencyImmediate = 1,
    HKUpdateFrequencyHourly,
    HKUpdateFrequencyDaily,
    HKUpdateFrequencyWeekly
} HKUpdateFrequency;

typedef enum : NSInteger {
    HKAuthorizationStatusNotDetermined = 0,
    HKAuthorizationStatusSharingDenied,
    HKAuthorizationStatusSharingAuthorized,
} HKAuthorizationStatus;

typedef enum : NSInteger {
    HKFitzpatrickSkinTypeNotSet = 1,
    HKFitzpatrickSkinTypeI,
    HKFitzpatrickSkinTypeII,
    HKFitzpatrickSkinTypeIII,
    HKFitzpatrickSkinTypeIV,
    HKFitzpatrickSkinTypeV,
    HKFitzpatrickSkinTypeVI,
} HKFitzpatrickSkinType;

typedef enum : NSInteger {
    HKCategoryValueSleepAnalysisInBed,
    HKCategoryValueSleepAnalysisAsleep,
} HKCategoryValueSleepAnalysis;

typedef enum : NSInteger {
    HKCategoryValueAppleStandHourStood = 0,
    HKCategoryValueAppleStandHourIdle,
} HKCategoryValueAppleStandHour;

typedef enum : NSInteger {
    HKCategoryValueCervicalMucusQualityDry = 1,
    HKCategoryValueCervicalMucusQualitySticky,
    HKCategoryValueCervicalMucusQualityCreamy,
    HKCategoryValueCervicalMucusQualityWatery,
    HKCategoryValueCervicalMucusQualityEggWhite,
} HKCategoryValueCervicalMucusQuality;

typedef enum : NSInteger {
    HKCategoryValueOvulationTestResultNegative = 1,
    HKCategoryValueOvulationTestResultPositive,
    HKCategoryValueOvulationTestResultIndeterminate,
} HKCategoryValueOvulationTestResult;

typedef enum : NSInteger {
    HKCategoryValueMenstrualFlowUnspecified = 1,
    HKCategoryValueMenstrualFlowLight,
    HKCategoryValueMenstrualFlowMedium,
    HKCategoryValueMenstrualFlowHeavy
} HKCategoryValueMenstrualFlow;

typedef enum : NSInteger {
    HKCategoryValueNotApplicable = 0,
} HKCategoryValue;

typedef enum : NSInteger {
    HKBiologicalSexNotSet = 0,
    HKBiologicalSexFemale,
    HKBiologicalSexMale,
    HKBiologicalSexOther,
} HKBiologicalSex;

typedef enum : NSInteger {
    HKBloodTypeNotSet = 0,
    HKBloodTypeAPositive,
    HKBloodTypeANegative,
    HKBloodTypeBPositive,
    HKBloodTypeBNegative,
    HKBloodTypeABPositive,
    HKBloodTypeABNegative,
    HKBloodTypeOPositive,
    HKBloodTypeONegative,
} HKBloodType;

HEALTHKIT_EXPORT NSString* const HKMetadataKeyDeviceSerialNumber;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyBodyTemperatureSensorLocation;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyHeartRateSensorLocation;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyFoodType;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyUDIDeviceIdentifier;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyUDIProductionIdentifier;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyDigitalSignature;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyExternalUUID;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyTimeZone;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyDeviceName;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyDeviceManufacturerName;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyWasTakenInLab;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyReferenceRangeLowerLimit;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyReferenceRangeUpperLimit;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyWasUserEntered;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyWorkoutBrandName;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyGroupFitness;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyIndoorWorkout;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyCoachedWorkout;
HEALTHKIT_EXPORT NSString* const HKMetadataKeySexualActivityProtectionUsed;
HEALTHKIT_EXPORT NSString* const HKMetadataKeyMenstrualCycleStart;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBodyMassIndex;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBodyFatPercentage;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierHeight;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBodyMass;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierLeanBodyMass;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierStepCount;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDistanceWalkingRunning;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDistanceCycling;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBasalEnergyBurned;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierActiveEnergyBurned;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierFlightsClimbed;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierNikeFuel;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierHeartRate;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBodyTemperature;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBasalBodyTemperature;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBloodPressureSystolic;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBloodPressureDiastolic;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierRespiratoryRate;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierOxygenSaturation;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierPeripheralPerfusionIndex;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBloodGlucose;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierNumberOfTimesFallen;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierElectrodermalActivity;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierInhalerUsage;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierBloodAlcoholContent;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierForcedVitalCapacity;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierForcedExpiratoryVolume1;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierPeakExpiratoryFlowRate;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryBiotin;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryCaffeine;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryCalcium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryCarbohydrates;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryChloride;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryCholesterol;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryChromium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryCopper;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryEnergyConsumed;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFatMonounsaturated;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFatPolyunsaturated;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFatSaturated;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFatTotal;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFiber;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryFolate;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryIodine;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryIron;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryMagnesium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryManganese;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryMolybdenum;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryNiacin;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryPantothenicAcid;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryPhosphorus;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryPotassium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryProtein;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryRiboflavin;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietarySelenium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietarySodium;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietarySugar;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryThiamin;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminA;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminB12;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminB6;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminC;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminD;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminE;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryVitaminK;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryWater;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierDietaryZinc;
HEALTHKIT_EXPORT NSString* const HKQuantityTypeIdentifierUVExposure;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierSleepAnalysis;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierAppleStandHour;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierCervicalMucusQuality;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierOvulationTestResult;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierMenstrualFlow;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierIntermenstrualBleeding;
HEALTHKIT_EXPORT NSString* const HKCategoryTypeIdentifierSexualActivity;
HEALTHKIT_EXPORT NSString* const HKCharacteristicTypeIdentifierBiologicalSex;
HEALTHKIT_EXPORT NSString* const HKCharacteristicTypeIdentifierBloodType;
HEALTHKIT_EXPORT NSString* const HKCharacteristicTypeIdentifierDateOfBirth;
HEALTHKIT_EXPORT NSString* const HKCharacteristicTypeIdentifierFitzpatrickSkinType;
HEALTHKIT_EXPORT NSString* const HKCorrelationTypeIdentifierBloodPressure;
HEALTHKIT_EXPORT NSString* const HKCorrelationTypeIdentifierFood;
HEALTHKIT_EXPORT NSString* const HKWorkoutTypeIdentifier;
HEALTHKIT_EXPORT NSString* const HKErrorDomain;
