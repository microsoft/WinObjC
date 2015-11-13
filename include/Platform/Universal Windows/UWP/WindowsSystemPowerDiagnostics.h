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

// WindowsSystemPowerDiagnostics.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPDBackgroundEnergyDiagnostics, WSPDForegroundEnergyDiagnostics;
@protocol WSPDIBackgroundEnergyDiagnosticsStatics
, WSPDIForegroundEnergyDiagnosticsStatics;

#import <Foundation/Foundation.h>

// Windows.System.Power.Diagnostics.BackgroundEnergyDiagnostics
#ifndef __WSPDBackgroundEnergyDiagnostics_DEFINED__
#define __WSPDBackgroundEnergyDiagnostics_DEFINED__

WINRT_EXPORT
@interface WSPDBackgroundEnergyDiagnostics : RTObject
+ (uint64_t)computeTotalEnergyUsage;
+ (void)resetTotalEnergyUsage;
+ (double)deviceSpecificConversionFactor;
@end

#endif // __WSPDBackgroundEnergyDiagnostics_DEFINED__

// Windows.System.Power.Diagnostics.ForegroundEnergyDiagnostics
#ifndef __WSPDForegroundEnergyDiagnostics_DEFINED__
#define __WSPDForegroundEnergyDiagnostics_DEFINED__

WINRT_EXPORT
@interface WSPDForegroundEnergyDiagnostics : RTObject
+ (uint64_t)computeTotalEnergyUsage;
+ (void)resetTotalEnergyUsage;
+ (double)deviceSpecificConversionFactor;
@end

#endif // __WSPDForegroundEnergyDiagnostics_DEFINED__
