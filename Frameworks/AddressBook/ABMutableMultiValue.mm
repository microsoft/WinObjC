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

#import <AddressBook/ABMutableMultiValue.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"
#import "ABMultiValueInternal.h"

/**
 @Status Interoperable
 @Notes
*/
ABMutableMultiValueRef ABMultiValueCreateMutable(ABPropertyType type) {
    return (__bridge_retained ABMutableMultiValueRef)[[_ABMultiValue alloc] initWithPropertyType:type];
}

/**
 @Status Interoperable
 @Notes
*/
ABMutableMultiValueRef ABMultiValueCreateMutableCopy(ABMultiValueRef multiValue) {
    RETURN_NULL_IF(multiValue == nullptr);

    return (__bridge_retained ABMutableMultiValueRef)[(__bridge _ABMultiValue*)multiValue mutableCopy];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABMultiValueAddValueAndLabel(ABMutableMultiValueRef multiValue,
                                  CFTypeRef value,
                                  CFStringRef label,
                                  ABMultiValueIdentifier* outIdentifier) {
    RETURN_FALSE_IF(multiValue == nullptr);

    return [(__bridge _ABMultiValue*)multiValue addValue:value andLabel:label outIdentifier:outIdentifier];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABMultiValueReplaceValueAtIndex(ABMutableMultiValueRef multiValue, CFTypeRef value, CFIndex index) {
    RETURN_FALSE_IF(multiValue == nullptr);

    return [(__bridge _ABMultiValue*)multiValue replaceValue:value atIndex:index];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABMultiValueReplaceLabelAtIndex(ABMutableMultiValueRef multiValue, CFStringRef label, CFIndex index) {
    RETURN_FALSE_IF(multiValue == nullptr);

    return [(__bridge _ABMultiValue*)multiValue replaceLabel:label atIndex:index];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABMultiValueInsertValueAndLabelAtIndex(
    ABMutableMultiValueRef multiValue, CFTypeRef value, CFStringRef label, CFIndex index, ABMultiValueIdentifier* outIdentifier) {
    RETURN_FALSE_IF(multiValue == nullptr);

    return [(__bridge _ABMultiValue*)multiValue insertValue:value andLabel:label atIndex:index outIdentifier:outIdentifier];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABMultiValueRemoveValueAndLabelAtIndex(ABMutableMultiValueRef multiValue, CFIndex index) {
    RETURN_FALSE_IF(multiValue == nullptr);

    return [(__bridge _ABMultiValue*)multiValue removeValueAndLabelAtIndex:index];
}