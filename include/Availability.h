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

#ifndef _AVAILABILITY_H_
#define _AVAILABILITY_H_

#include <StarboardAdditionalDefines.h>
#include <AvailabilityMacros.h>

#if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) && !defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
#define __IPHONE_OS_VERSION_MIN_REQUIRED __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
#endif

#define __MAC_10_0 1000
#define __MAC_10_1 1010
#define __MAC_10_2 1020
#define __MAC_10_3 1030
#define __MAC_10_4 1040
#define __MAC_10_5 1050
#define __MAC_10_6 1060
#define __MAC_10_7 1070
#define __MAC_10_8 1080
#define __MAC_10_9 1090

#define __IPHONE_2_0 20000
#define __IPHONE_2_1 20100
#define __IPHONE_2_2 20200
#define __IPHONE_3_0 30000
#define __IPHONE_3_1 30100
#define __IPHONE_3_2 30200
#define __IPHONE_4_0 40000
#define __IPHONE_4_1 40100
#define __IPHONE_4_2 40200
#define __IPHONE_4_3 40300
#define __IPHONE_5_0 50000
#define __IPHONE_5_1 50100
#define __IPHONE_6_0 60000
#define __IPHONE_6_1 60100
#define __IPHONE_7_0 70000
#define __IPHONE_7_1 70100

#define __IPHONE_OS_VERSION_MIN_REQUIRED __IPHONE_3_2
#define __IPHONE_OS_VERSION_MAX_ALLOWED __IPHONE_6_0
#define __AVAILABILITY_INTERNAL_DEPRECATED
#define DEPRECATED_ATTRIBUTE

// __IPHONE_8_0 and later is not yet supported

// Empty macro definitions
#define __OSX_AVAILABLE_STARTING(__MAC_VERSION, __IPHONE_VERSION)
#define __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_VERSION_A, __MAC_VERSION_B, __IPHONE_REGION_A, __IPHONE_REGION_B)

#endif /* !_AVAILABILITY_H_ */