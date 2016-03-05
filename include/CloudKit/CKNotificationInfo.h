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

#import <CloudKit/CloudKitExport.h>
#import <Foundation/NSObject.h>

@class NSString;
@class NSArray;

CLOUDKIT_EXPORT_CLASS
@interface CKNotificationInfo : NSObject <NSCopying, NSSecureCoding>

@property (copy, nonatomic) NSString* alertBody STUB_PROPERTY;
@property (copy, nonatomic) NSString* alertLocalizationKey STUB_PROPERTY;
@property (copy, nonatomic) NSArray* alertLocalizationArgs STUB_PROPERTY;
@property (copy, nonatomic) NSString* alertActionLocalizationKey STUB_PROPERTY;
@property (copy, nonatomic) NSString* alertLaunchImage STUB_PROPERTY;
@property (copy, nonatomic) NSString* soundName STUB_PROPERTY;
@property (assign, nonatomic) BOOL shouldBadge STUB_PROPERTY;
@property (assign, nonatomic) BOOL shouldSendContentAvailable STUB_PROPERTY;
@property (copy, nonatomic) NSString* category STUB_PROPERTY;
@property (copy, nonatomic) NSArray* desiredKeys STUB_PROPERTY;
@end
