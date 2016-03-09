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
#import <CoreImage/CIFilter.h>

NSString* const kCIAttributeFilterName = @"kCIAttributeFilterName";
NSString* const kCIAttributeFilterDisplayName = @"kCIAttributeFilterDisplayName";
NSString* const kCIAttributeDescription = @"kCIAttributeDescription";
NSString* const kCIAttributeFilterAvailable_Mac = @"kCIAttributeFilterAvailable_Mac";
NSString* const kCIAttributeFilterAvailable_iOS = @"kCIAttributeFilterAvailable_iOS";
NSString* const kCIAttributeReferenceDocumentation = @"kCIAttributeReferenceDocumentation";
NSString* const kCIAttributeFilterCategories = @"kCIAttributeFilterCategories";
NSString* const kCIAttributeClass = @"kCIAttributeClass";
NSString* const kCIAttributeType = @"kCIAttributeType";
NSString* const kCIAttributeMin = @"kCIAttributeMin";
NSString* const kCIAttributeMax = @"kCIAttributeMax";
NSString* const kCIAttributeSliderMin = @"kCIAttributeSliderMin";
NSString* const kCIAttributeSliderMax = @"kCIAttributeSliderMax";
NSString* const kCIAttributeDefault = @"kCIAttributeDefault";
NSString* const kCIAttributeIdentity = @"kCIAttributeIdentity";
NSString* const kCIAttributeName = @"kCIAttributeName";
NSString* const kCIAttributeDisplayName = @"kCIAttributeDisplayName";
NSString* const kCIAttributeTypeTime = @"kCIAttributeTypeTime";
NSString* const kCIAttributeTypeScalar = @"kCIAttributeTypeScalar";
NSString* const kCIAttributeTypeDistance = @"kCIAttributeTypeDistance";
NSString* const kCIAttributeTypeAngle = @"kCIAttributeTypeAngle";
NSString* const kCIAttributeTypeBoolean = @"kCIAttributeTypeBoolean";
NSString* const kCIAttributeTypeInteger = @"kCIAttributeTypeInteger";
NSString* const kCIAttributeTypeCount = @"kCIAttributeTypeCount";
NSString* const kCIAttributeTypePosition = @"kCIAttributeTypePosition";
NSString* const kCIAttributeTypeOffset = @"kCIAttributeTypeOffset";
NSString* const kCIAttributeTypePosition3 = @"kCIAttributeTypePosition3";
NSString* const kCIAttributeTypeRectangle = @"kCIAttributeTypeRectangle";
NSString* const kCIAttributeTypeOpaqueColor = @"kCIAttributeTypeOpaqueColor";
NSString* const kCIAttributeTypeGradient = @"kCIAttributeTypeGradient";
NSString* const kCIAttributeTypeColor = @"kCIAttributeTypeColor";
NSString* const kCIAttributeTypeImage = @"kCIAttributeTypeImage";
NSString* const kCIAttributeTypeTransform = @"kCIAttributeTypeTransform";
NSString* const kCICategoryDistortionEffect = @"kCICategoryDistortionEffect";
NSString* const kCICategoryGeometryAdjustment = @"kCICategoryGeometryAdjustment";
NSString* const kCICategoryCompositeOperation = @"kCICategoryCompositeOperation";
NSString* const kCICategoryHalftoneEffect = @"kCICategoryHalftoneEffect";
NSString* const kCICategoryColorAdjustment = @"kCICategoryColorAdjustment";
NSString* const kCICategoryColorEffect = @"kCICategoryColorEffect";
NSString* const kCICategoryTransition = @"kCICategoryTransition";
NSString* const kCICategoryTileEffect = @"kCICategoryTileEffect";
NSString* const kCICategoryGenerator = @"kCICategoryGenerator";
NSString* const kCICategoryReduction = @"kCICategoryReduction";
NSString* const kCICategoryGradient = @"kCICategoryGradient";
NSString* const kCICategoryStylize = @"kCICategoryStylize";
NSString* const kCICategorySharpen = @"kCICategorySharpen";
NSString* const kCICategoryBlur = @"kCICategoryBlur";
NSString* const kCICategoryVideo = @"kCICategoryVideo";
NSString* const kCICategoryStillImage = @"kCICategoryStillImage";
NSString* const kCICategoryInterlaced = @"kCICategoryInterlaced";
NSString* const kCICategoryNonSquarePixels = @"kCICategoryNonSquarePixels";
NSString* const kCICategoryHighDynamicRange = @"kCICategoryHighDynamicRange";
NSString* const kCICategoryBuiltIn = @"kCICategoryBuiltIn";
NSString* const kCICategoryFilterGenerator = @"kCICategoryFilterGenerator";
NSString* const kCIUIParameterSet = @"kCIUIParameterSet";
NSString* const kCIUISetBasic = @"kCIUISetBasic";
NSString* const kCIUISetIntermediate = @"kCIUISetIntermediate";
NSString* const kCIUISetAdvanced = @"kCIUISetAdvanced";
NSString* const kCIUISetDevelopment = @"kCIUISetDevelopment";
NSString* const kCIOutputImageKey = @"kCIOutputImageKey";
NSString* const kCIInputBackgroundImageKey = @"kCIInputBackgroundImageKey";
NSString* const kCIInputImageKey = @"kCIInputImageKey";
NSString* const kCIInputTimeKey = @"kCIInputTimeKey";
NSString* const kCIInputTransformKey = @"kCIInputTransformKey";
NSString* const kCIInputScaleKey = @"kCIInputScaleKey";
NSString* const kCIInputAspectRatioKey = @"kCIInputAspectRatioKey";
NSString* const kCIInputCenterKey = @"kCIInputCenterKey";
NSString* const kCIInputRadiusKey = @"kCIInputRadiusKey";
NSString* const kCIInputAngleKey = @"kCIInputAngleKey";
NSString* const kCIInputRefractionKey = @"kCIInputRefractionKey";
NSString* const kCIInputWidthKey = @"kCIInputWidthKey";
NSString* const kCIInputSharpnessKey = @"kCIInputSharpnessKey";
NSString* const kCIInputIntensityKey = @"kCIInputIntensityKey";
NSString* const kCIInputEVKey = @"kCIInputEVKey";
NSString* const kCIInputSaturationKey = @"kCIInputSaturationKey";
NSString* const kCIInputColorKey = @"kCIInputColorKey";
NSString* const kCIInputBrightnessKey = @"kCIInputBrightnessKey";
NSString* const kCIInputContrastKey = @"kCIInputContrastKey";
NSString* const kCIInputGradientImageKey = @"kCIInputGradientImageKey";
NSString* const kCIInputMaskImageKey = @"kCIInputMaskImageKey";
NSString* const kCIInputShadingImageKey = @"kCIInputShadingImageKey";
NSString* const kCIInputTargetImageKey = @"kCIInputTargetImageKey";
NSString* const kCIInputExtentKey = @"kCIInputExtentKey";
NSString* const kCIInputVersionKey = @"kCIInputVersionKey";
NSString* const kCIInputNeutralLocation = @"kCIInputNeutralLocation";
NSString* const kCIInputBiasKey = @"kCIInputBiasKey";

@implementation CIFilter
/**
 @Status Stub
 @Notes
*/
+ (CIFilter*)filterWithName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIFilter*)filterWithName:(NSString*)name withInputParameters:(NSDictionary*)params {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CIFilter*)filterWithName:(NSString*)name keysAndValues:(id)key0 {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)filterNamesInCategories:(NSArray*)categories {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)filterNamesInCategory:(NSString*)category {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)registerFilterName:(NSString*)name constructor:(id<CIFilterConstructor>)anObject classAttributes:(NSDictionary*)attributes {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setDefaults {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedNameForFilterName:(NSString*)filterName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedNameForCategory:(NSString*)category {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedDescriptionForFilterName:(NSString*)filterName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSURL*)localizedReferenceDocumentationForFilterName:(NSString*)filterName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSData*)serializedXMPFromFilters:(NSArray*)filters inputImageExtent:(CGRect)extent {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)filterArrayFromSerializedXMP:(NSData*)xmpData inputImageExtent:(CGRect)extent error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
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
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
