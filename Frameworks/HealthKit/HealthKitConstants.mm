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

#import <StubReturn.h>

#import <HealthKit/HealthKitConstants.h>

NSString* const HKMetadataKeyDeviceSerialNumber = @"HKMetadataKeyDeviceSerialNumber";
NSString* const HKMetadataKeyBodyTemperatureSensorLocation = @"HKMetadataKeyBodyTemperatureSensorLocation";
NSString* const HKMetadataKeyHeartRateSensorLocation = @"HKMetadataKeyHeartRateSensorLocation";
NSString* const HKMetadataKeyFoodType = @"HKMetadataKeyFoodType";
NSString* const HKMetadataKeyUDIDeviceIdentifier = @"HKMetadataKeyUDIDeviceIdentifier";
NSString* const HKMetadataKeyUDIProductionIdentifier = @"HKMetadataKeyUDIProductionIdentifier";
NSString* const HKMetadataKeyDigitalSignature = @"HKMetadataKeyDigitalSignature";
NSString* const HKMetadataKeyExternalUUID = @"HKMetadataKeyExternalUUID";
NSString* const HKMetadataKeyTimeZone = @"HKMetadataKeyTimeZone";
NSString* const HKMetadataKeyDeviceName = @"HKMetadataKeyDeviceName";
NSString* const HKMetadataKeyDeviceManufacturerName = @"HKMetadataKeyDeviceManufacturerName";
NSString* const HKMetadataKeyWasTakenInLab = @"HKMetadataKeyWasTakenInLab";
NSString* const HKMetadataKeyReferenceRangeLowerLimit = @"HKMetadataKeyReferenceRangeLowerLimit";
NSString* const HKMetadataKeyReferenceRangeUpperLimit = @"HKMetadataKeyReferenceRangeUpperLimit";
NSString* const HKMetadataKeyWasUserEntered = @"HKMetadataKeyWasUserEntered";
NSString* const HKMetadataKeyWorkoutBrandName = @"HKMetadataKeyWorkoutBrandName";
NSString* const HKMetadataKeyGroupFitness = @"HKMetadataKeyGroupFitness";
NSString* const HKMetadataKeyIndoorWorkout = @"HKMetadataKeyIndoorWorkout";
NSString* const HKMetadataKeyCoachedWorkout = @"HKMetadataKeyCoachedWorkout";
NSString* const HKMetadataKeySexualActivityProtectionUsed = @"HKMetadataKeySexualActivityProtectionUsed";
NSString* const HKMetadataKeyMenstrualCycleStart = @"HKMetadataKeyMenstrualCycleStart";
NSString* const HKQuantityTypeIdentifierBodyMassIndex = @"HKQuantityTypeIdentifierBodyMassIndex";
NSString* const HKQuantityTypeIdentifierBodyFatPercentage = @"HKQuantityTypeIdentifierBodyFatPercentage";
NSString* const HKQuantityTypeIdentifierHeight = @"HKQuantityTypeIdentifierHeight";
NSString* const HKQuantityTypeIdentifierBodyMass = @"HKQuantityTypeIdentifierBodyMass";
NSString* const HKQuantityTypeIdentifierLeanBodyMass = @"HKQuantityTypeIdentifierLeanBodyMass";
NSString* const HKQuantityTypeIdentifierStepCount = @"HKQuantityTypeIdentifierStepCount";
NSString* const HKQuantityTypeIdentifierDistanceWalkingRunning = @"HKQuantityTypeIdentifierDistanceWalkingRunning";
NSString* const HKQuantityTypeIdentifierDistanceCycling = @"HKQuantityTypeIdentifierDistanceCycling";
NSString* const HKQuantityTypeIdentifierBasalEnergyBurned = @"HKQuantityTypeIdentifierBasalEnergyBurned";
NSString* const HKQuantityTypeIdentifierActiveEnergyBurned = @"HKQuantityTypeIdentifierActiveEnergyBurned";
NSString* const HKQuantityTypeIdentifierFlightsClimbed = @"HKQuantityTypeIdentifierFlightsClimbed";
NSString* const HKQuantityTypeIdentifierNikeFuel = @"HKQuantityTypeIdentifierNikeFuel";
NSString* const HKQuantityTypeIdentifierHeartRate = @"HKQuantityTypeIdentifierHeartRate";
NSString* const HKQuantityTypeIdentifierBodyTemperature = @"HKQuantityTypeIdentifierBodyTemperature";
NSString* const HKQuantityTypeIdentifierBasalBodyTemperature = @"HKQuantityTypeIdentifierBasalBodyTemperature";
NSString* const HKQuantityTypeIdentifierBloodPressureSystolic = @"HKQuantityTypeIdentifierBloodPressureSystolic";
NSString* const HKQuantityTypeIdentifierBloodPressureDiastolic = @"HKQuantityTypeIdentifierBloodPressureDiastolic";
NSString* const HKQuantityTypeIdentifierRespiratoryRate = @"HKQuantityTypeIdentifierRespiratoryRate";
NSString* const HKQuantityTypeIdentifierOxygenSaturation = @"HKQuantityTypeIdentifierOxygenSaturation";
NSString* const HKQuantityTypeIdentifierPeripheralPerfusionIndex = @"HKQuantityTypeIdentifierPeripheralPerfusionIndex";
NSString* const HKQuantityTypeIdentifierBloodGlucose = @"HKQuantityTypeIdentifierBloodGlucose";
NSString* const HKQuantityTypeIdentifierNumberOfTimesFallen = @"HKQuantityTypeIdentifierNumberOfTimesFallen";
NSString* const HKQuantityTypeIdentifierElectrodermalActivity = @"HKQuantityTypeIdentifierElectrodermalActivity";
NSString* const HKQuantityTypeIdentifierInhalerUsage = @"HKQuantityTypeIdentifierInhalerUsage";
NSString* const HKQuantityTypeIdentifierBloodAlcoholContent = @"HKQuantityTypeIdentifierBloodAlcoholContent";
NSString* const HKQuantityTypeIdentifierForcedVitalCapacity = @"HKQuantityTypeIdentifierForcedVitalCapacity";
NSString* const HKQuantityTypeIdentifierForcedExpiratoryVolume1 = @"HKQuantityTypeIdentifierForcedExpiratoryVolume1";
NSString* const HKQuantityTypeIdentifierPeakExpiratoryFlowRate = @"HKQuantityTypeIdentifierPeakExpiratoryFlowRate";
NSString* const HKQuantityTypeIdentifierDietaryBiotin = @"HKQuantityTypeIdentifierDietaryBiotin";
NSString* const HKQuantityTypeIdentifierDietaryCaffeine = @"HKQuantityTypeIdentifierDietaryCaffeine";
NSString* const HKQuantityTypeIdentifierDietaryCalcium = @"HKQuantityTypeIdentifierDietaryCalcium";
NSString* const HKQuantityTypeIdentifierDietaryCarbohydrates = @"HKQuantityTypeIdentifierDietaryCarbohydrates";
NSString* const HKQuantityTypeIdentifierDietaryChloride = @"HKQuantityTypeIdentifierDietaryChloride";
NSString* const HKQuantityTypeIdentifierDietaryCholesterol = @"HKQuantityTypeIdentifierDietaryCholesterol";
NSString* const HKQuantityTypeIdentifierDietaryChromium = @"HKQuantityTypeIdentifierDietaryChromium";
NSString* const HKQuantityTypeIdentifierDietaryCopper = @"HKQuantityTypeIdentifierDietaryCopper";
NSString* const HKQuantityTypeIdentifierDietaryEnergyConsumed = @"HKQuantityTypeIdentifierDietaryEnergyConsumed";
NSString* const HKQuantityTypeIdentifierDietaryFatMonounsaturated = @"HKQuantityTypeIdentifierDietaryFatMonounsaturated";
NSString* const HKQuantityTypeIdentifierDietaryFatPolyunsaturated = @"HKQuantityTypeIdentifierDietaryFatPolyunsaturated";
NSString* const HKQuantityTypeIdentifierDietaryFatSaturated = @"HKQuantityTypeIdentifierDietaryFatSaturated";
NSString* const HKQuantityTypeIdentifierDietaryFatTotal = @"HKQuantityTypeIdentifierDietaryFatTotal";
NSString* const HKQuantityTypeIdentifierDietaryFiber = @"HKQuantityTypeIdentifierDietaryFiber";
NSString* const HKQuantityTypeIdentifierDietaryFolate = @"HKQuantityTypeIdentifierDietaryFolate";
NSString* const HKQuantityTypeIdentifierDietaryIodine = @"HKQuantityTypeIdentifierDietaryIodine";
NSString* const HKQuantityTypeIdentifierDietaryIron = @"HKQuantityTypeIdentifierDietaryIron";
NSString* const HKQuantityTypeIdentifierDietaryMagnesium = @"HKQuantityTypeIdentifierDietaryMagnesium";
NSString* const HKQuantityTypeIdentifierDietaryManganese = @"HKQuantityTypeIdentifierDietaryManganese";
NSString* const HKQuantityTypeIdentifierDietaryMolybdenum = @"HKQuantityTypeIdentifierDietaryMolybdenum";
NSString* const HKQuantityTypeIdentifierDietaryNiacin = @"HKQuantityTypeIdentifierDietaryNiacin";
NSString* const HKQuantityTypeIdentifierDietaryPantothenicAcid = @"HKQuantityTypeIdentifierDietaryPantothenicAcid";
NSString* const HKQuantityTypeIdentifierDietaryPhosphorus = @"HKQuantityTypeIdentifierDietaryPhosphorus";
NSString* const HKQuantityTypeIdentifierDietaryPotassium = @"HKQuantityTypeIdentifierDietaryPotassium";
NSString* const HKQuantityTypeIdentifierDietaryProtein = @"HKQuantityTypeIdentifierDietaryProtein";
NSString* const HKQuantityTypeIdentifierDietaryRiboflavin = @"HKQuantityTypeIdentifierDietaryRiboflavin";
NSString* const HKQuantityTypeIdentifierDietarySelenium = @"HKQuantityTypeIdentifierDietarySelenium";
NSString* const HKQuantityTypeIdentifierDietarySodium = @"HKQuantityTypeIdentifierDietarySodium";
NSString* const HKQuantityTypeIdentifierDietarySugar = @"HKQuantityTypeIdentifierDietarySugar";
NSString* const HKQuantityTypeIdentifierDietaryThiamin = @"HKQuantityTypeIdentifierDietaryThiamin";
NSString* const HKQuantityTypeIdentifierDietaryVitaminA = @"HKQuantityTypeIdentifierDietaryVitaminA";
NSString* const HKQuantityTypeIdentifierDietaryVitaminB12 = @"HKQuantityTypeIdentifierDietaryVitaminB12";
NSString* const HKQuantityTypeIdentifierDietaryVitaminB6 = @"HKQuantityTypeIdentifierDietaryVitaminB6";
NSString* const HKQuantityTypeIdentifierDietaryVitaminC = @"HKQuantityTypeIdentifierDietaryVitaminC";
NSString* const HKQuantityTypeIdentifierDietaryVitaminD = @"HKQuantityTypeIdentifierDietaryVitaminD";
NSString* const HKQuantityTypeIdentifierDietaryVitaminE = @"HKQuantityTypeIdentifierDietaryVitaminE";
NSString* const HKQuantityTypeIdentifierDietaryVitaminK = @"HKQuantityTypeIdentifierDietaryVitaminK";
NSString* const HKQuantityTypeIdentifierDietaryWater = @"HKQuantityTypeIdentifierDietaryWater";
NSString* const HKQuantityTypeIdentifierDietaryZinc = @"HKQuantityTypeIdentifierDietaryZinc";
NSString* const HKQuantityTypeIdentifierUVExposure = @"HKQuantityTypeIdentifierUVExposure";
NSString* const HKCategoryTypeIdentifierSleepAnalysis = @"HKCategoryTypeIdentifierSleepAnalysis";
NSString* const HKCategoryTypeIdentifierAppleStandHour = @"HKCategoryTypeIdentifierAppleStandHour";
NSString* const HKCategoryTypeIdentifierCervicalMucusQuality = @"HKCategoryTypeIdentifierCervicalMucusQuality";
NSString* const HKCategoryTypeIdentifierOvulationTestResult = @"HKCategoryTypeIdentifierOvulationTestResult";
NSString* const HKCategoryTypeIdentifierMenstrualFlow = @"HKCategoryTypeIdentifierMenstrualFlow";
NSString* const HKCategoryTypeIdentifierIntermenstrualBleeding = @"HKCategoryTypeIdentifierIntermenstrualBleeding";
NSString* const HKCategoryTypeIdentifierSexualActivity = @"HKCategoryTypeIdentifierSexualActivity";
NSString* const HKCharacteristicTypeIdentifierBiologicalSex = @"HKCharacteristicTypeIdentifierBiologicalSex";
NSString* const HKCharacteristicTypeIdentifierBloodType = @"HKCharacteristicTypeIdentifierBloodType";
NSString* const HKCharacteristicTypeIdentifierDateOfBirth = @"HKCharacteristicTypeIdentifierDateOfBirth";
NSString* const HKCharacteristicTypeIdentifierFitzpatrickSkinType = @"HKCharacteristicTypeIdentifierFitzpatrickSkinType";
NSString* const HKCorrelationTypeIdentifierBloodPressure = @"HKCorrelationTypeIdentifierBloodPressure";
NSString* const HKCorrelationTypeIdentifierFood = @"HKCorrelationTypeIdentifierFood";
NSString* const HKWorkoutTypeIdentifier = @"HKWorkoutTypeIdentifier";
NSString* const HKErrorDomain = @"HKErrorDomain";
