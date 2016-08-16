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

#import <AddressBook/ABMultiValue.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

#import "ABMultiValueInternal.h"

/**
 @Status Interoperable
 @Notes
*/
CFTypeRef ABMultiValueCopyValueAtIndex(ABMultiValueRef multiValue, CFIndex index) {
    if (multiValue == nullptr) {
        return nullptr;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi copyValueAtIndex:index];
}

/**
 @Status Interoperable
 @Notes
*/
CFArrayRef ABMultiValueCopyArrayOfAllValues(ABMultiValueRef multiValue) {
    if (multiValue == nullptr) {
        return nullptr;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi copyArrayOfAllValues];
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex ABMultiValueGetCount(ABMultiValueRef multiValue) {
    if (multiValue == nullptr) {
        return 0;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi getCount];
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex ABMultiValueGetFirstIndexOfValue(ABMultiValueRef multiValue, CFTypeRef value) {
    if (multiValue == nullptr) {
        return -1;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi getFirstIndexOfValue:value];
}

/**
 @Status Interoperable
 @Notes
*/
CFStringRef ABMultiValueCopyLabelAtIndex(ABMultiValueRef multiValue, CFIndex index) {
    if (multiValue == nullptr) {
        return nullptr;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi copyLabelAtIndex:index];
}

/**
 @Status Interoperable
 @Notes
*/
ABMultiValueIdentifier ABMultiValueGetIdentifierAtIndex(ABMultiValueRef multiValue, CFIndex index) {
    if (multiValue == nullptr) {
        return kABMultiValueInvalidIdentifier;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi getIdentifierAtIndex:index];
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex ABMultiValueGetIndexForIdentifier(ABMultiValueRef multiValue, ABMultiValueIdentifier identifier) {
    if (multiValue == nullptr) {
        return -1;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi getIndexForIdentifier:identifier];
}

/**
 @Status Interoperable
 @Notes
*/
ABPropertyType ABMultiValueGetPropertyType(ABMultiValueRef multiValue) {
    if (multiValue == nullptr) {
        return kABInvalidPropertyType;
    }

    _ABMultiValue* multi = (__bridge _ABMultiValue*)multiValue;
    return [multi getPropertyType];
}
