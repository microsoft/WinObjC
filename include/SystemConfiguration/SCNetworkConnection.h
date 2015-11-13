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

#pragma once

#include <stdint.h>

enum {
    kSCNetworkFlagsTransientConnection = 0x01,
    kSCNetworkFlagsReachable = 0x02,
    kSCNetworkFlagsConnectionRequired = 0x04,
    kSCNetworkFlagsConnectionAutomatic = 0x08,
    kSCNetworkFlagsInterventionRequired = 0x10,
    kSCNetworkFlagsIsLocalAddress = 0x10000,
    kSCNetworkFlagsIsDirect = 0x20000
};

typedef uint32_t SCNetworkConnectionFlags;
