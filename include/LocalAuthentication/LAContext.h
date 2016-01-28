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

#import <LocalAuthentication/LocalAuthenticationExport.h>
#import <Foundation/NSObject.h>

@class NSError;
@class NSString;

enum { kLAPolicyDeviceOwnerAuthenticationWithBiometrics = 0 };

enum {
    kLAErrorAuthenticationFailed = 0,
    kLAErrorUserCancel = 1,
    kLAErrorUserFallback = 2,
    kLAErrorSystemCancel = 3,
    kLAErrorPasscodeNotSet = 4,
    kLAErrorTouchIDNotAvailable = 5,
    kLAErrorTouchIDNotEnrolled = 6
};

typedef NS_ENUM(NSInteger, LAPolicy) { LAPolicyDeviceOwnerAuthenticationWithBiometrics = kLAPolicyDeviceOwnerAuthenticationWithBiometrics };

typedef NS_ENUM(NSInteger, LAError) {
    LAErrorAuthenticationFailed = kLAErrorAuthenticationFailed,
    LAErrorUserCancel = kLAErrorUserCancel,
    LAErrorUserFallback = kLAErrorUserFallback,
    LAErrorSystemCancel = kLAErrorSystemCancel,
    LAErrorPasscodeNotSet = kLAErrorPasscodeNotSet,
    LAErrorTouchIDNotAvailable = kLAErrorTouchIDNotAvailable,
    LAErrorTouchIDNotEnrolled = kLAErrorTouchIDNotEnrolled,
};

LOCALAUTHENTICATION_EXPORT NSString* const LAErrorDomain;

LOCALAUTHENTICATION_EXPORT_CLASS
@interface LAContext : NSObject
- (BOOL)canEvaluatePolicy:(LAPolicy)policy error:(NSError* _Nullable*)error STUB_METHOD;
- (void)evaluatePolicy:(LAPolicy)policy localizedReason:(NSString*)localizedReason reply:(void (^)(BOOL, NSError*))reply STUB_METHOD;
@end