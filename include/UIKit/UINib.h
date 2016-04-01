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

#pragma once

#import <Foundation/NSObject.h>
#import <UIKit/UIKitExport.h>

UIKIT_EXPORT NSString* const UINibExternalObjects;

@class NSBundle;
@class NSArray;
@class NSDictionary;
@class NSData;

UIKIT_EXPORT_CLASS
@interface UINib : NSObject
@property (nonatomic, readonly) NSBundle* bundle;

+ (UINib*)nibWithNibName:(NSString*)name bundle:(NSBundle*)bundle;
+ (UINib*)nibWithData:(NSData*)data bundle:(NSBundle*)bundle;
- (NSArray*)instantiateWithOwner:(id)ownerObject options:(NSDictionary*)options;
@end
