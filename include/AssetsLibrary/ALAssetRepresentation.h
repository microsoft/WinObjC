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
#import <AssetsLibrary/ALAssetsLibrary.h>
#import <Foundation/NSObject.h>

@class NSDictionary;
@class NSString;
@class NSError;
@class NSURL;

ASSETSLIBRARY_EXPORT_CLASS
@interface ALAssetRepresentation : NSObject <NSObject>
- (CGImageRef)CGImageWithOptions:(NSDictionary*)options STUB_METHOD;
- (CGImageRef)fullResolutionImage STUB_METHOD;
- (CGImageRef)fullScreenImage STUB_METHOD;
- (ALAssetOrientation)orientation STUB_METHOD;
- (float)scale STUB_METHOD;
- (CGSize)dimensions STUB_METHOD;
- (NSString*)filename STUB_METHOD;
- (long long)size;
- (NSUInteger)getBytes:(uint8_t*)buffer fromOffset:(long long)offset length:(NSUInteger)length error:(NSError**)error;
- (NSString*)UTI STUB_METHOD;
- (NSDictionary*)metadata STUB_METHOD;
- (NSURL*)url;
@end
