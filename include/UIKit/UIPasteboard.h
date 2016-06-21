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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;
@class NSData;
@class NSIndexSet;
@class UIImage;
@class NSURL;
@class UIColor;

UIKIT_EXPORT NSString* const UIPasteboardNameGeneral;
UIKIT_EXPORT NSString* const UIPasteboardNameFind;
UIKIT_EXPORT NSArray* const UIPasteboardTypeListString;
UIKIT_EXPORT NSArray* const UIPasteboardTypeListURL;
UIKIT_EXPORT NSArray* const UIPasteboardTypeListImage;
UIKIT_EXPORT NSArray* const UIPasteboardTypeListColor;
UIKIT_EXPORT NSString* const UIPasteboardChangedTypesAddedKey;
UIKIT_EXPORT NSString* const UIPasteboardChangedTypesRemovedKey;

UIKIT_EXPORT NSString* const UIPasteboardChangedNotification;
UIKIT_EXPORT NSString* const UIPasteboardRemovedNotification;

UIKIT_EXPORT_CLASS
@interface UIPasteboard : NSObject
+ (UIPasteboard*)generalPasteboard;
+ (UIPasteboard*)pasteboardWithName:(NSString*)pasteboardName create:(BOOL)create;
+ (UIPasteboard*)pasteboardWithUniqueName;
+ (void)removePasteboardWithName:(NSString*)pasteboardName;
@property (readonly, nonatomic) NSString* name;
@property (getter=isPersistent, nonatomic) BOOL persistent STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger changeCount STUB_PROPERTY;
- (NSArray*)pasteboardTypes STUB_METHOD;
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes STUB_METHOD;
- (NSData*)dataForPasteboardType:(NSString*)pasteboardType;
- (id)valueForPasteboardType:(NSString*)pasteboardType STUB_METHOD;
- (void)setData:(NSData*)data forPasteboardType:(NSString*)pasteboardType;
- (void)setValue:(id)value forPasteboardType:(NSString*)pasteboardType STUB_METHOD;
@property (readonly, nonatomic) NSInteger numberOfItems STUB_PROPERTY;
- (NSArray*)pasteboardTypesForItemSet:(NSIndexSet*)itemSet STUB_METHOD;
- (NSIndexSet*)itemSetWithPasteboardTypes:(NSArray*)pasteboardTypes STUB_METHOD;
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes inItemSet:(NSIndexSet*)itemSet STUB_METHOD;
@property (copy, nonatomic) NSArray* items STUB_PROPERTY;
- (NSArray*)dataForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet STUB_METHOD;
- (NSArray*)valuesForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet STUB_METHOD;
- (void)addItems:(NSArray*)items STUB_METHOD;
@property (copy, nonatomic) NSString* string;
@property (copy, nonatomic) NSArray* strings STUB_PROPERTY;
@property (copy, nonatomic) UIImage* image;
@property (copy, nonatomic) NSArray* images STUB_PROPERTY;
@property (copy, nonatomic) NSURL* URL;
@property (copy, nonatomic) NSArray* URLs STUB_PROPERTY;
@property (copy, nonatomic) UIColor* color STUB_PROPERTY;
@property (copy, nonatomic) NSArray* colors STUB_PROPERTY;
@end
