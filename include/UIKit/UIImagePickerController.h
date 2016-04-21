/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 *
 * Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import "UINavigationController.h"

typedef NSUInteger UIImagePickerControllerSourceType;
enum {
    UIImagePickerControllerSourceTypePhotoLibrary,
    UIImagePickerControllerSourceTypeCamera,
    UIImagePickerControllerSourceTypeSavedPhotosAlbum,
};

typedef NSUInteger UIImagePickerControllerQualityType;
enum {
    UIImagePickerControllerQualityTypeHigh = 0,
    UIImagePickerControllerQualityTypeMedium = 1, // default value
    UIImagePickerControllerQualityTypeLow = 2,
    UIImagePickerControllerQualityType640x480 = 3,
    UIImagePickerControllerQualityTypeIFrame1280x720 = 4,
    UIImagePickerControllerQualityTypeIFrame960x540 = 5,
};

typedef NSUInteger UIImagePickerControllerCameraDevice;
enum {
    UIImagePickerControllerCameraDeviceRear,
    UIImagePickerControllerCameraDeviceFront,
};

typedef NSUInteger UIImagePickerControllerCameraCaptureMode;
enum {
    UIImagePickerControllerCameraCaptureModePhoto,
    UIImagePickerControllerCameraCaptureModeVideo,
};

typedef NSInteger UIImagePickerControllerCameraFlashMode;
enum {
    UIImagePickerControllerCameraFlashModeOff = -1,
    UIImagePickerControllerCameraFlashModeAuto = 0,
    UIImagePickerControllerCameraFlashModeOn = 1,
};

@protocol UIImagePickerControllerDelegate;

UIKIT_EXPORT_CLASS
@interface UIImagePickerController
    : UINavigationController <NSCoding, NSObject, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>

@property (nonatomic) BOOL allowsEditing;
@property (nonatomic) BOOL allowsImageEditing STUB_PROPERTY;
@property (nonatomic) BOOL showsCameraControls;
@property (nonatomic) CGAffineTransform cameraViewTransform STUB_PROPERTY;
@property (nonatomic) NSTimeInterval videoMaximumDuration STUB_PROPERTY;
@property (nonatomic) UIImagePickerControllerCameraCaptureMode cameraCaptureMode STUB_PROPERTY;
@property (nonatomic) UIImagePickerControllerCameraDevice cameraDevice;
@property (nonatomic) UIImagePickerControllerCameraFlashMode cameraFlashMode STUB_PROPERTY;
@property (nonatomic) UIImagePickerControllerQualityType videoQuality STUB_PROPERTY;
@property (nonatomic) UIImagePickerControllerSourceType sourceType;
@property (nonatomic, assign) id<UINavigationControllerDelegate, UIImagePickerControllerDelegate> delegate;
@property (nonatomic, copy) NSArray* mediaTypes;
@property (nonatomic, retain) UIView* cameraOverlayView;

+ (BOOL)isCameraDeviceAvailable:(UIImagePickerControllerCameraDevice)cameraDevice;
+ (BOOL)isFlashAvailableForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice STUB_METHOD;
+ (BOOL)isSourceTypeAvailable:(UIImagePickerControllerSourceType)sourceType;
+ (NSArray*)availableCaptureModesForCameraDevice:(UIImagePickerControllerCameraDevice)cameraDevice STUB_METHOD;
+ (NSArray*)availableMediaTypesForSourceType:(UIImagePickerControllerSourceType)sourceType;
- (BOOL)startVideoCapture STUB_METHOD;
- (void)stopVideoCapture STUB_METHOD;
- (void)takePicture STUB_METHOD;

@end
