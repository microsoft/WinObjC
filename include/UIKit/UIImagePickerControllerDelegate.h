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

@class UIImagePickerController;
@class NSString;
@class NSDictionary;
@class UIImage;

UIKIT_EXPORT NSString* const UIImagePickerControllerMediaType;
UIKIT_EXPORT NSString* const UIImagePickerControllerOriginalImage;
UIKIT_EXPORT NSString* const UIImagePickerControllerEditedImage;
UIKIT_EXPORT NSString* const UIImagePickerControllerCropRect;
UIKIT_EXPORT NSString* const UIImagePickerControllerMediaURL;
UIKIT_EXPORT NSString* const UIImagePickerControllerReferenceURL;
UIKIT_EXPORT NSString* const UIImagePickerControllerMediaMetadata;
UIKIT_EXPORT NSString* const UIImagePickerControllerLivePhoto;

@protocol UIImagePickerControllerDelegate <NSObject>
@optional
- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingMediaWithInfo:(NSDictionary*)info;
- (void)imagePickerController:(UIImagePickerController*)picker didFinishPickingImage:(UIImage*)image editingInfo:(NSDictionary*)editingInfo;
- (void)imagePickerControllerDidCancel:(UIImagePickerController*)picker;
@end
