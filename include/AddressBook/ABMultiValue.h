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

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFString.h>
#import <AddressBook/ABRecord.h>

#define kABMultiValueInvalidIdentifier -1

typedef CFTypeRef ABMultiValueRef;
typedef int32_t ABMultiValueIdentifier;

ADDRESSBOOK_EXPORT CFTypeRef ABMultiValueCopyValueAtIndex(ABMultiValueRef multiValue, CFIndex index) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABMultiValueCopyArrayOfAllValues(ABMultiValueRef multiValue) STUB_METHOD;
ADDRESSBOOK_EXPORT CFIndex ABMultiValueGetCount(ABMultiValueRef multiValue) STUB_METHOD;
ADDRESSBOOK_EXPORT CFIndex ABMultiValueGetFirstIndexOfValue(ABMultiValueRef multiValue, CFTypeRef value) STUB_METHOD;
ADDRESSBOOK_EXPORT CFStringRef ABMultiValueCopyLabelAtIndex(ABMultiValueRef multiValue, CFIndex index) STUB_METHOD;
ADDRESSBOOK_EXPORT ABMultiValueIdentifier ABMultiValueGetIdentifierAtIndex(ABMultiValueRef multiValue, CFIndex index) STUB_METHOD;
ADDRESSBOOK_EXPORT CFIndex ABMultiValueGetIndexForIdentifier(ABMultiValueRef multiValue, ABMultiValueIdentifier identifier) STUB_METHOD;
ADDRESSBOOK_EXPORT ABPropertyType ABMultiValueGetPropertyType(ABMultiValueRef multiValue) STUB_METHOD;
