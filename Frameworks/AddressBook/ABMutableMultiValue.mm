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

/**
 @Status Stub
 @Notes
*/
ABMutableMultiValueRef ABMultiValueCreateMutable(ABPropertyType type) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ABMutableMultiValueRef ABMultiValueCreateMutableCopy(ABMultiValueRef multiValue) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABMultiValueAddValueAndLabel(ABMutableMultiValueRef multiValue,
                                  CFTypeRef value,
                                  CFStringRef label,
                                  ABMultiValueIdentifier* outIdentifier) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABMultiValueReplaceValueAtIndex(ABMutableMultiValueRef multiValue, CFTypeRef value, CFIndex index) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABMultiValueReplaceLabelAtIndex(ABMutableMultiValueRef multiValue, CFStringRef label, CFIndex index) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABMultiValueInsertValueAndLabelAtIndex(
    ABMutableMultiValueRef multiValue, CFTypeRef value, CFStringRef label, CFIndex index, ABMultiValueIdentifier* outIdentifier) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABMultiValueRemoveValueAndLabelAtIndex(ABMutableMultiValueRef multiValue, CFIndex index) {
    UNIMPLEMENTED();
    return StubReturn();
}
