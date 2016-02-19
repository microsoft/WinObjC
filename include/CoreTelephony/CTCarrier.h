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

#import <CoreTelephony/CoreTelephonyExport.h>
#import <Foundation/NSObject.h>

@class NSString;

CORETELEPHONY_EXPORT_CLASS
@interface CTCarrier : NSObject <NSObject>
@property (readonly, assign, nonatomic) BOOL allowsVOIP STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* carrierName STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* isoCountryCode STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* mobileCountryCode STUB_PROPERTY;
@property (readonly, retain, nonatomic) NSString* mobileNetworkCode STUB_PROPERTY;
@end
