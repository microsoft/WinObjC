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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSNegateBooleanTransformerName;
FOUNDATION_EXPORT NSString* const NSIsNilTransformerName;

FOUNDATION_EXPORT NSString* const NSIsNotNilTransformerName;

FOUNDATION_EXPORT NSString* const NSUnarchiveFromDataTransformerName;

FOUNDATION_EXPORT NSString* const NSKeyedUnarchiveFromDataTransformerName;

FOUNDATION_EXPORT_CLASS
@interface NSValueTransformer : NSObject
+ (void)setValueTransformer:(NSValueTransformer*)transformer forName:(NSString*)name;
+ (NSValueTransformer*)valueTransformerForName:(NSString*)name;
+ (NSArray*)valueTransformerNames;
+ (BOOL)allowsReverseTransformation;
+ (Class)transformedValueClass;
- (id)transformedValue:(id)value;
- (id)reverseTransformedValue:(id)value;
@end
