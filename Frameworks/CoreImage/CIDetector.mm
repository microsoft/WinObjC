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
#import <CoreImage/CIDetector.h>

NSString* const CIDetectorTypeFace = @"CIDetectorTypeFace";
NSString* const CIDetectorTypeRectangle = @"CIDetectorTypeRectangle";
NSString* const CIDetectorTypeQRCode = @"CIDetectorTypeQRCode";
NSString* const CIDetectorTypeText = @"CIDetectorTypeText";
NSString* const CIDetectorAccuracy = @"CIDetectorAccuracy";
NSString* const CIDetectorTracking = @"CIDetectorTracking";
NSString* const CIDetectorMinFeatureSize = @"CIDetectorMinFeatureSize";
NSString* const CIDetectorNumberOfAngles = @"CIDetectorNumberOfAngles";
NSString* const CIDetectorAccuracyLow = @"CIDetectorAccuracyLow";
NSString* const CIDetectorAccuracyHigh = @"CIDetectorAccuracyHigh";
NSString* const CIDetectorImageOrientation = @"CIDetectorImageOrientation";
NSString* const CIDetectorEyeBlink = @"CIDetectorEyeBlink";
NSString* const CIDetectorSmile = @"CIDetectorSmile";
NSString* const CIDetectorFocalLength = @"CIDetectorFocalLength";
NSString* const CIDetectorAspectRatio = @"CIDetectorAspectRatio";
NSString* const CIDetectorReturnSubFeatures = @"CIDetectorReturnSubFeatures";

@implementation CIDetector
/**
 @Status Stub
 @Notes
*/
+ (CIDetector*)detectorOfType:(NSString*)type context:(CIContext*)context options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)featuresInImage:(CIImage*)image {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)featuresInImage:(CIImage*)image options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
