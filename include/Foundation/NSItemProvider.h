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

@protocol NSSecureCoding;
@class NSError;
@class NSDictionary;
@class NSString;
@class NSURL;
@class NSArray;

typedef void (^NSItemProviderCompletionHandler)(id<NSSecureCoding> item, NSError* error);
typedef void (^NSItemProviderLoadHandler)(NSItemProviderCompletionHandler completionHandler,
                                          Class expectedValueClass,
                                          NSDictionary* options);
FOUNDATION_EXPORT NSString* const NSItemProviderPreferredImageSizeKey;
FOUNDATION_EXPORT NSString* const NSExtensionJavaScriptPreprocessingResultsKey;
FOUNDATION_EXPORT NSString* const NSExtensionJavaScriptFinalizeArgumentKey;

FOUNDATION_EXPORT_CLASS
@interface NSItemProvider : NSObject <NSCopying>
- (instancetype)initWithContentsOfURL:(NSURL*)fileURL STUB_METHOD;
- (instancetype)initWithItem:(id<NSSecureCoding>)item typeIdentifier:(NSString*)typeIdentifier STUB_METHOD;
- (void)registerItemForTypeIdentifier:(NSString*)typeIdentifier loadHandler:(NSItemProviderLoadHandler)loadHandler STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* registeredTypeIdentifiers STUB_PROPERTY;
- (BOOL)hasItemConformingToTypeIdentifier:(NSString*)typeIdentifier STUB_METHOD;
- (void)loadItemForTypeIdentifier:(NSString*)typeIdentifier
                          options:(NSDictionary*)options
                completionHandler:(NSItemProviderCompletionHandler)completionHandler STUB_METHOD;
- (void)loadPreviewImageWithOptions:(NSDictionary*)options completionHandler:(NSItemProviderCompletionHandler)completionHandler STUB_METHOD;
@property (copy, nonatomic) NSItemProviderLoadHandler previewImageHandler STUB_PROPERTY;
@end
