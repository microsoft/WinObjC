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

@class CTCarrier;

CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyGPRS;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyEdge;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyWCDMA;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyHSDPA;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyHSUPA;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyCDMA1x;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyCDMAEVDORev0;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyCDMAEVDORevA;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyCDMAEVDORevB;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyeHRPD;
CORETELEPHONY_EXPORT NSString* const CTRadioAccessTechnologyLTE;

CORETELEPHONY_EXPORT_CLASS
@interface CTTelephonyNetworkInfo : NSObject <NSObject>
@property (readonly, retain) CTCarrier* subscriberCellularProvider STUB_PROPERTY;
@property (copy, nonatomic, nonnull) void (^subscriberCellularProviderDidUpdateNotifier)(CTCarrier*) STUB_PROPERTY;
@end
