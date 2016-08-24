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

#import <AddressBook/AddressBookExport.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABMultiValue.h>

#import <CoreFoundation/CFString.h>

typedef CFTypeRef ABMutableMultiValueRef;
ADDRESSBOOK_EXPORT ABMutableMultiValueRef ABMultiValueCreateMutable(ABPropertyType type);
ADDRESSBOOK_EXPORT ABMutableMultiValueRef ABMultiValueCreateMutableCopy(ABMultiValueRef multiValue);
ADDRESSBOOK_EXPORT bool ABMultiValueAddValueAndLabel(ABMutableMultiValueRef multiValue,
                                                     CFTypeRef value,
                                                     CFStringRef label,
                                                     ABMultiValueIdentifier* outIdentifier);

ADDRESSBOOK_EXPORT bool ABMultiValueReplaceValueAtIndex(ABMutableMultiValueRef multiValue, CFTypeRef value, CFIndex index);
ADDRESSBOOK_EXPORT bool ABMultiValueReplaceLabelAtIndex(ABMutableMultiValueRef multiValue, CFStringRef label, CFIndex index);
ADDRESSBOOK_EXPORT bool ABMultiValueInsertValueAndLabelAtIndex(
    ABMutableMultiValueRef multiValue, CFTypeRef value, CFStringRef label, CFIndex index, ABMultiValueIdentifier* outIdentifier);

ADDRESSBOOK_EXPORT bool ABMultiValueRemoveValueAndLabelAtIndex(ABMutableMultiValueRef multiValue, CFIndex index);
