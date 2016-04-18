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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>
#import <CoreImage/CIFeature.h>

COREIMAGE_EXPORT_CLASS
@interface CIFaceFeature : CIFeature
@property (readonly, assign) CGRect bounds STUB_PROPERTY;
@property (readonly, assign) BOOL hasFaceAngle STUB_PROPERTY;
@property (readonly, assign) float faceAngle STUB_PROPERTY;
@property (readonly, assign) BOOL hasLeftEyePosition STUB_PROPERTY;
@property (readonly, assign) BOOL hasRightEyePosition STUB_PROPERTY;
@property (readonly, assign) BOOL hasMouthPosition STUB_PROPERTY;
@property (readonly, assign) CGPoint leftEyePosition STUB_PROPERTY;
@property (readonly, assign) CGPoint rightEyePosition STUB_PROPERTY;
@property (readonly, assign) CGPoint mouthPosition STUB_PROPERTY;
@property (readonly, assign) BOOL hasSmile STUB_PROPERTY;
@property (readonly, assign) BOOL leftEyeClosed STUB_PROPERTY;
@property (readonly, assign) BOOL rightEyeClosed STUB_PROPERTY;
@property (readonly, assign) BOOL hasTrackingID STUB_PROPERTY;
@property (readonly, assign) int trackingID STUB_PROPERTY;
@property (readonly, assign) BOOL hasTrackingFrameCount STUB_PROPERTY;
@property (readonly, assign) int trackingFrameCount STUB_PROPERTY;
@end
