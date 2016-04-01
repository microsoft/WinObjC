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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class CIContext;
@class NSDictionary;
@class NSArray;
@class CIImage;

COREIMAGE_EXPORT NSString* const CIDetectorTypeFace;
COREIMAGE_EXPORT NSString* const CIDetectorTypeRectangle;
COREIMAGE_EXPORT NSString* const CIDetectorTypeQRCode;
COREIMAGE_EXPORT NSString* const CIDetectorTypeText;
COREIMAGE_EXPORT NSString* const CIDetectorAccuracy;
COREIMAGE_EXPORT NSString* const CIDetectorTracking;
COREIMAGE_EXPORT NSString* const CIDetectorMinFeatureSize;
COREIMAGE_EXPORT NSString* const CIDetectorNumberOfAngles;
COREIMAGE_EXPORT NSString* const CIDetectorAccuracyLow;
COREIMAGE_EXPORT NSString* const CIDetectorAccuracyHigh;
COREIMAGE_EXPORT NSString* const CIDetectorImageOrientation;
COREIMAGE_EXPORT NSString* const CIDetectorEyeBlink;
COREIMAGE_EXPORT NSString* const CIDetectorSmile;
COREIMAGE_EXPORT NSString* const CIDetectorFocalLength;
COREIMAGE_EXPORT NSString* const CIDetectorAspectRatio;
COREIMAGE_EXPORT NSString* const CIDetectorReturnSubFeatures;
COREIMAGE_EXPORT_CLASS
@interface CIDetector : NSObject
+ (CIDetector*)detectorOfType:(NSString*)type context:(CIContext*)context options:(NSDictionary*)options STUB_METHOD;
- (NSArray*)featuresInImage:(CIImage*)image STUB_METHOD;
- (NSArray*)featuresInImage:(CIImage*)image options:(NSDictionary*)options STUB_METHOD;
@end
