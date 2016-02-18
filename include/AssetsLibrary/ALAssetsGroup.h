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

#import <AssetsLibrary/AssetsLibraryExport.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/NSObject.h>

@class ALAsset;
@class NSString;
@class NSIndexSet;
@class ALAssetsFilter;

typedef void (^ALAssetsGroupEnumerationResultsBlock)(ALAsset* result, NSUInteger index, BOOL* stop);
ASSETSLIBRARY_EXPORT NSString* const ALAssetsGroupPropertyName;
ASSETSLIBRARY_EXPORT NSString* const ALAssetsGroupPropertyType;
ASSETSLIBRARY_EXPORT NSString* const ALAssetsGroupPropertyPersistentID;
ASSETSLIBRARY_EXPORT NSString* const ALAssetsGroupPropertyURL;

ASSETSLIBRARY_EXPORT_CLASS
@interface ALAssetsGroup : NSObject <NSObject>
- (void)enumerateAssetsUsingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock STUB_METHOD;
- (void)enumerateAssetsWithOptions:(NSEnumerationOptions)options
                        usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock STUB_METHOD;
- (void)enumerateAssetsAtIndexes:(NSIndexSet*)indexSet
                         options:(NSEnumerationOptions)options
                      usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock STUB_METHOD;
- (BOOL)addAsset:(ALAsset*)asset STUB_METHOD;
- (NSInteger)numberOfAssets STUB_METHOD;
- (void)setAssetsFilter:(ALAssetsFilter*)filter STUB_METHOD;
- (id)valueForProperty:(NSString*)property STUB_METHOD;
- (CGImageRef)posterImage STUB_METHOD;
@property (readonly, getter=isEditable, nonatomic) BOOL editable STUB_PROPERTY;
@end
