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

#import <AddressBook/ABMultiValue.h>
#import <Foundation/Foundation.h>

@interface _ABMultiValue : NSObject <NSMutableCopying>

- (id)initWithPropertyType:(ABPropertyType)propertyType;

// Once the MultiValue is made immutable,
// appendPairWithLabel:andValue: no longer does anything;
// it returns YES if the appending occurred, or NO if the
// MultiValue is immutable and no change was made.
- (BOOL)isMutable;
- (void)makeImmutable;
- (BOOL)appendPairWithLabel:(NSString*)label andValue:(id)value;

// The following methods parallel those found in ABMultiValue.mm.
- (CFTypeRef)copyValueAtIndex:(CFIndex)index;
- (CFArrayRef)copyArrayOfAllValues;
- (CFIndex)getCount;
- (CFStringRef)copyLabelAtIndex:(CFIndex)index;
- (ABMultiValueIdentifier)getIdentifierAtIndex:(CFIndex)index;
- (ABPropertyType)getPropertyType;
- (CFIndex)getFirstIndexOfValue:(CFTypeRef)value;
- (CFIndex)getIndexForIdentifier:(ABMultiValueIdentifier)identifier;

// The following methods parallel those found in ABMutableMultiValue.mm.
- (id)mutableCopyWithZone:(NSZone*)zone;
- (bool)addValue:(CFTypeRef)value andLabel:(CFStringRef)label outIdentifier:(ABMultiValueIdentifier*)outIdentifier;
- (bool)replaceValue:(CFTypeRef)value atIndex:(CFIndex)index;
- (bool)replaceLabel:(CFStringRef)label atIndex:(CFIndex)index;
- (bool)insertValue:(CFTypeRef)value
           andLabel:(CFStringRef)label
            atIndex:(CFIndex)index
      outIdentifier:(ABMultiValueIdentifier*)outIdentifier;
- (bool)removeValueAndLabelAtIndex:(CFIndex)index;

@end