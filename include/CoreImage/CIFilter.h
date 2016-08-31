//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGBase.h>

@class NSString;
@class NSDictionary;
@class NSArray;
@protocol CIFilterConstructor;
@class CIImage;
@class NSURL;
@class NSData;
@class NSError;

COREIMAGE_EXPORT NSString* const kCIAttributeFilterName;
COREIMAGE_EXPORT NSString* const kCIAttributeFilterDisplayName;
COREIMAGE_EXPORT NSString* const kCIAttributeDescription;
COREIMAGE_EXPORT NSString* const kCIAttributeFilterAvailable_Mac;
COREIMAGE_EXPORT NSString* const kCIAttributeFilterAvailable_iOS;
COREIMAGE_EXPORT NSString* const kCIAttributeReferenceDocumentation;
COREIMAGE_EXPORT NSString* const kCIAttributeFilterCategories;
COREIMAGE_EXPORT NSString* const kCIAttributeClass;
COREIMAGE_EXPORT NSString* const kCIAttributeType;
COREIMAGE_EXPORT NSString* const kCIAttributeMin;
COREIMAGE_EXPORT NSString* const kCIAttributeMax;
COREIMAGE_EXPORT NSString* const kCIAttributeSliderMin;
COREIMAGE_EXPORT NSString* const kCIAttributeSliderMax;
COREIMAGE_EXPORT NSString* const kCIAttributeDefault;
COREIMAGE_EXPORT NSString* const kCIAttributeIdentity;
COREIMAGE_EXPORT NSString* const kCIAttributeName;
COREIMAGE_EXPORT NSString* const kCIAttributeDisplayName;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeTime;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeScalar;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeDistance;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeAngle;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeBoolean;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeInteger;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeCount;
COREIMAGE_EXPORT NSString* const kCIAttributeTypePosition;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeOffset;
COREIMAGE_EXPORT NSString* const kCIAttributeTypePosition3;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeRectangle;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeOpaqueColor;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeGradient;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeColor;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeImage;
COREIMAGE_EXPORT NSString* const kCIAttributeTypeTransform;
COREIMAGE_EXPORT NSString* const kCICategoryDistortionEffect;
COREIMAGE_EXPORT NSString* const kCICategoryGeometryAdjustment;
COREIMAGE_EXPORT NSString* const kCICategoryCompositeOperation;
COREIMAGE_EXPORT NSString* const kCICategoryHalftoneEffect;
COREIMAGE_EXPORT NSString* const kCICategoryColorAdjustment;
COREIMAGE_EXPORT NSString* const kCICategoryColorEffect;
COREIMAGE_EXPORT NSString* const kCICategoryTransition;
COREIMAGE_EXPORT NSString* const kCICategoryTileEffect;
COREIMAGE_EXPORT NSString* const kCICategoryGenerator;
COREIMAGE_EXPORT NSString* const kCICategoryReduction;
COREIMAGE_EXPORT NSString* const kCICategoryGradient;
COREIMAGE_EXPORT NSString* const kCICategoryStylize;
COREIMAGE_EXPORT NSString* const kCICategorySharpen;
COREIMAGE_EXPORT NSString* const kCICategoryBlur;
COREIMAGE_EXPORT NSString* const kCICategoryVideo;
COREIMAGE_EXPORT NSString* const kCICategoryStillImage;
COREIMAGE_EXPORT NSString* const kCICategoryInterlaced;
COREIMAGE_EXPORT NSString* const kCICategoryNonSquarePixels;
COREIMAGE_EXPORT NSString* const kCICategoryHighDynamicRange;
;
COREIMAGE_EXPORT NSString* const kCICategoryBuiltIn;
COREIMAGE_EXPORT NSString* const kCICategoryFilterGenerator;
COREIMAGE_EXPORT NSString* const kCIUIParameterSet;
COREIMAGE_EXPORT NSString* const kCIUISetBasic;
COREIMAGE_EXPORT NSString* const kCIUISetIntermediate;
COREIMAGE_EXPORT NSString* const kCIUISetAdvanced;
COREIMAGE_EXPORT NSString* const kCIUISetDevelopment;
COREIMAGE_EXPORT NSString* const kCIOutputImageKey;
COREIMAGE_EXPORT NSString* const kCIInputBackgroundImageKey;
COREIMAGE_EXPORT NSString* const kCIInputImageKey;
COREIMAGE_EXPORT NSString* const kCIInputTimeKey;
COREIMAGE_EXPORT NSString* const kCIInputTransformKey;
COREIMAGE_EXPORT NSString* const kCIInputScaleKey;
COREIMAGE_EXPORT NSString* const kCIInputAspectRatioKey;
COREIMAGE_EXPORT NSString* const kCIInputCenterKey;
COREIMAGE_EXPORT NSString* const kCIInputRadiusKey;
COREIMAGE_EXPORT NSString* const kCIInputAngleKey;
COREIMAGE_EXPORT NSString* const kCIInputRefractionKey;
COREIMAGE_EXPORT NSString* const kCIInputWidthKey;
COREIMAGE_EXPORT NSString* const kCIInputSharpnessKey;
COREIMAGE_EXPORT NSString* const kCIInputIntensityKey;
COREIMAGE_EXPORT NSString* const kCIInputEVKey;
COREIMAGE_EXPORT NSString* const kCIInputSaturationKey;
COREIMAGE_EXPORT NSString* const kCIInputColorKey;
COREIMAGE_EXPORT NSString* const kCIInputBrightnessKey;
COREIMAGE_EXPORT NSString* const kCIInputContrastKey;
COREIMAGE_EXPORT NSString* const kCIInputGradientImageKey;
COREIMAGE_EXPORT NSString* const kCIInputMaskImageKey;
COREIMAGE_EXPORT NSString* const kCIInputShadingImageKey;
COREIMAGE_EXPORT NSString* const kCIInputTargetImageKey;
COREIMAGE_EXPORT NSString* const kCIInputExtentKey;
COREIMAGE_EXPORT NSString* const kCIInputVersionKey;
COREIMAGE_EXPORT NSString* const kCIInputNeutralLocation;
COREIMAGE_EXPORT NSString* const kCIInputBiasKey;
COREIMAGE_EXPORT_CLASS

@interface CIFilter : NSObject <NSCopying, NSSecureCoding>

+ (CIFilter*)filterWithName:(NSString*)name STUB_METHOD;
+ (CIFilter*)filterWithName:(NSString*)name withInputParameters:(NSDictionary*)params STUB_METHOD;
+ (CIFilter*)filterWithName:(NSString*)name keysAndValues:(id)key0 STUB_METHOD;
+ (NSArray*)filterNamesInCategories:(NSArray*)categories STUB_METHOD;
+ (NSArray*)filterNamesInCategory:(NSString*)category STUB_METHOD;
+ (void)registerFilterName:(NSString*)name
               constructor:(id<CIFilterConstructor>)anObject
           classAttributes:(NSDictionary*)attributes STUB_METHOD;
@property (readonly, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) NSDictionary* attributes STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* inputKeys STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* outputKeys STUB_PROPERTY;
@property (readonly, nonatomic) CIImage* outputImage STUB_PROPERTY;
- (void)setDefaults STUB_METHOD;
+ (NSString*)localizedNameForFilterName:(NSString*)filterName STUB_METHOD;
+ (NSString*)localizedNameForCategory:(NSString*)category STUB_METHOD;
+ (NSString*)localizedDescriptionForFilterName:(NSString*)filterName STUB_METHOD;
+ (NSURL*)localizedReferenceDocumentationForFilterName:(NSString*)filterName STUB_METHOD;
+ (NSData*)serializedXMPFromFilters:(NSArray*)filters inputImageExtent:(CGRect)extent STUB_METHOD;
+ (NSArray*)filterArrayFromSerializedXMP:(NSData*)xmpData inputImageExtent:(CGRect)extent error:(NSError* _Nullable*)outError STUB_METHOD;
@end
