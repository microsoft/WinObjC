//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include <StubReturn.h>
#include "Starboard.h"
#include "UIKit/UIPasteboard.h"

NSString* const UIPasteboardNameGeneral = @"UIPasteboardNameGeneral";
NSString* const UIPasteboardNameFind = @"UIPasteboardNameFind";
NSString* const UIPasteboardChangedTypesAddedKey = @"UIPasteboardChangedTypesAddedKey";
NSString* const UIPasteboardChangedTypesRemovedKey = @"UIPasteboardChangedTypesRemovedKey";

/** @Status Stub */
NSArray* const UIPasteboardTypeListString = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListURL = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListImage = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListColor = StubConstant();

NSString* const UIPasteboardChangedNotification = @"UIPasteboardChangedNotification";
NSString* const UIPasteboardRemovedNotification = @"UIPasteboardRemovedNotification";

@implementation UIPasteboard
/**
 @Status Stub
 @Notes
*/
+ (UIPasteboard*)generalPasteboard {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (UIPasteboard*)pasteboardWithName:(NSString*)pasteboardName create:(BOOL)create {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (UIPasteboard*)pasteboardWithUniqueName {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (void)removePasteboardWithName:(NSString*)pasteboardName {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)pasteboardTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSData*)dataForPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)valueForPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setData:(NSData*)data forPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)setValue:(id)value forPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)pasteboardTypesForItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)itemSetWithPasteboardTypes:(NSArray*)pasteboardTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)dataForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)valuesForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addItems:(NSArray*)items {
    UNIMPLEMENTED();
}

@end
