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
#import <Foundation/NSValueTransformer.h>

NSString* const NSNegateBooleanTransformerName = @"NSNegateBooleanTransformerName";
NSString* const NSIsNilTransformerName = @"NSIsNilTransformerName";
NSString* const NSIsNotNilTransformerName = @"NSIsNotNilTransformerName";
NSString* const NSUnarchiveFromDataTransformerName = @"NSUnarchiveFromDataTransformerName";
NSString* const NSKeyedUnarchiveFromDataTransformerName = @"NSKeyedUnarchiveFromDataTransformerName";

@implementation NSValueTransformer
/**
 @Status Stub
 @Notes
*/
+ (void)setValueTransformer:(NSValueTransformer*)transformer forName:(NSString*)name {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (NSValueTransformer*)valueTransformerForName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)valueTransformerNames {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)allowsReverseTransformation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (Class)transformedValueClass {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)transformedValue:(id)value {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)reverseTransformedValue:(id)value {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
