/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _UIIMAGEPICKERCONTROLLER_H_
#define _UIIMAGEPICKERCONTROLLER_H_

#import "UINavigationController.h"
#import <StarboardExport.h>

enum {
    UIImagePickerControllerCameraDeviceRear,
    UIImagePickerControllerCameraDeviceFront
};
typedef uint32_t UIImagePickerControllerCameraDevice;

enum {
    UIImagePickerControllerSourceTypePhotoLibrary,
    UIImagePickerControllerSourceTypeCamera,
    UIImagePickerControllerSourceTypeSavedPhotosAlbum
};
typedef uint32_t UIImagePickerControllerSourceType;

enum {
    UIImagePickerControllerCameraFlashModeOff  = -1,
    UIImagePickerControllerCameraFlashModeAuto = 0,
    UIImagePickerControllerCameraFlashModeOn   = 1
};
typedef int32_t UIImagePickerControllerCameraFlashMode;

enum {
    UIImagePickerControllerQualityTypeHigh            = 0,
    UIImagePickerControllerQualityTypeMedium          = 1,  // default value
    UIImagePickerControllerQualityTypeLow             = 2,
    UIImagePickerControllerQualityType640x480         = 3,
    UIImagePickerControllerQualityTypeIFrame1280x720  = 4,
    UIImagePickerControllerQualityTypeIFrame960x540   = 5
};
typedef uint32_t UIImagePickerControllerQualityType;

enum {
    UIImagePickerControllerCameraCaptureModePhoto,
    UIImagePickerControllerCameraCaptureModeVideo
};
typedef uint32_t UIImagePickerControllerCameraCaptureMode;

SB_EXPORT NSString *const UIImagePickerControllerMediaType;
SB_EXPORT NSString *const UIImagePickerControllerOriginalImage;
SB_EXPORT NSString *const UIImagePickerControllerEditedImage;
SB_EXPORT NSString *const UIImagePickerControllerCropRect;
SB_EXPORT NSString *const UIImagePickerControllerMediaURL;

@protocol UIImagePickerControllerDelegate <NSObject>
@end

@interface UIImagePickerController : UINavigationController

+ (NSArray *)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType;
+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType;
+ (BOOL)isCameraDeviceAvailable:(UIImagePickerControllerCameraDevice)cameraDevice;

@property (nonatomic) UIImagePickerControllerSourceType sourceType;
@property (nonatomic,assign) id <UINavigationControllerDelegate, UIImagePickerControllerDelegate> delegate;
@property (nonatomic,copy) NSArray *mediaTypes;
@property (nonatomic) BOOL allowsEditing;
@property (nonatomic, retain) UIView *cameraOverlayView;
@property (nonatomic) UIImagePickerControllerCameraDevice cameraDevice;
@property (nonatomic) BOOL showsCameraControls;

@end

#endif /* _UIIMAGEPICKERCONTROLLER_H_ */