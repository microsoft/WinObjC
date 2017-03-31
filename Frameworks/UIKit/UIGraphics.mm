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

#import <UIKit/UIKit.h>
#import <StubReturn.h>

/**
 @Status Stub
 @Notes
*/
CGVector CGVectorFromString(NSString* string) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSString* NSStringFromCGAffineTransform(CGAffineTransform transform) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSString* NSStringFromCGVector(CGVector vector) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
UIEdgeInsets UIEdgeInsetsFromString(NSString* string) {
    UIEdgeInsets ret = UIEdgeInsetsZero;

    // Inset strings are formated as {A, B, C, D} where A,B,C and D are CGFloats types.
    // Example: "{80.0f, 80.0f, 80f, 80f}" and "{80, 80, 80, 80}" are a valid edge insets in string format
    if ([string length] > 1) {
        // Strip off curly braces and use the delimiter to separate components
        NSString* strWithoutBraces = [string substringWithRange : NSMakeRange(1, string.length - 2)];
        NSArray* components = [strWithoutBraces componentsSeparatedByString : @","];

        if (components.count == 4) {
            ret.top = ((NSString*)[components objectAtIndex:0]).floatValue;
            ret.left = ((NSString*)[components objectAtIndex:1]).floatValue;
            ret.bottom = ((NSString*)[components objectAtIndex:2]).floatValue;
            ret.right = ((NSString*)[components objectAtIndex:3]).floatValue;
        }
    }

    return ret;
}

/**
 @Status Stub
 @Notes
*/
UIOffset UIOffsetFromString(NSString* string) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
UIFloatRange UIFloatRangeMake(CGFloat minimum, CGFloat maximum) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIFloatRangeIsInfinite(UIFloatRange range) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIFloatRangeIsEqualToRange(UIFloatRange range, UIFloatRange otherRange) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
CTTextAlignment NSTextAlignmentToCTTextAlignment(NSTextAlignment alignment) {
    switch (alignment) {
        case NSTextAlignmentRight:
            return kCTRightTextAlignment;
        case NSTextAlignmentCenter:
            return kCTCenterTextAlignment;
        default:
            return alignment;
    }
}

/**
 @Status Stub
 @Notes
*/
NSString* NSStringFromUIEdgeInsets(UIEdgeInsets insets) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSString* NSStringFromUIOffset(UIOffset offset) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
NSTextAlignment NSTextAlignmentFromCTTextAlignment(CTTextAlignment ctTextAlignment) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsBeginPDFContextToData(NSMutableData* data, CGRect bounds, NSDictionary* documentInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIGraphicsBeginPDFContextToFile(NSString* path, CGRect bounds, NSDictionary* documentInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsEndPDFContext() {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsBeginPDFPage() {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsBeginPDFPageWithInfo(CGRect bounds, NSDictionary* pageInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGRect UIGraphicsGetPDFContextBounds() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsAddPDFContextDestinationAtPoint(NSString* name, CGPoint point) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsSetPDFContextDestinationForRect(NSString* name, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIGraphicsSetPDFContextURLForRect(NSURL* url, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
UIGuidedAccessRestrictionState UIGuidedAccessRestrictionStateForIdentifier(NSString* restrictionIdentifier) {
    UNIMPLEMENTED();
    return StubReturn();
}
