//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <CoreGraphics/CGGeometry.h>

@class UIActivityViewController;
@class NSString;
@class UIImage;

@protocol UIActivityItemSource <NSObject>
@required
- (id)activityViewControllerPlaceholderItem:(UIActivityViewController*)activityViewController;
- (id)activityViewController:(UIActivityViewController*)activityViewController itemForActivityType:(NSString*)activityType;
@optional
- (NSString*)activityViewController:(UIActivityViewController*)activityViewController subjectForActivityType:(NSString*)activityType;
- (NSString*)activityViewController:(UIActivityViewController*)activityViewController
  dataTypeIdentifierForActivityType:(NSString*)activityType;
- (UIImage*)activityViewController:(UIActivityViewController*)activityViewController
     thumbnailImageForActivityType:(NSString*)activityType
                     suggestedSize:(CGSize)size;
@end
