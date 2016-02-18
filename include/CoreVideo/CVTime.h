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

#import <CoreVideo/CoreVideoExport.h>
#import <CoreFoundation/CFBase.h>

struct CVSMPTETime {
    SInt16 subframes;
    SInt16 subframeDivisor;
    UInt32 counter;
    UInt32 type;
    UInt32 flags;
    SInt16 hours;
    SInt16 minutes;
    SInt16 seconds;
    SInt16 frames;
};

typedef struct CVSMPTETime CVSMPTETime;

typedef struct {
    int64_t timeValue;
    int64_t timeScale;
    int32_t flags;
} CVTime;

typedef struct {
    uint32_t version;
    int32_t videoTimeScale;
    int64_t videoTime;
    uint64_t hostTime;
    double rateScalar;
    int64_t videoRefreshPeriod;
    CVSMPTETime smpteTime;
    uint64_t flags;
    uint64_t reserved;
} CVTimeStamp;

COREVIDEO_EXPORT uint64_t CVGetCurrentHostTime() STUB_METHOD;
COREVIDEO_EXPORT double CVGetHostClockFrequency() STUB_METHOD;
COREVIDEO_EXPORT uint32_t CVGetHostClockMinimumTimeDelta() STUB_METHOD;

enum { kCVTimeIsIndefinite = 1 << 0 };

COREVIDEO_EXPORT const CVTime kCVZeroTime;
COREVIDEO_EXPORT const CVTime kCVIndefiniteTime;

enum {
    kCVTimeStampVideoTimeValid = (1L << 0),
    kCVTimeStampHostTimeValid = (1L << 1),
    kCVTimeStampSMPTETimeValid = (1L << 2),
    kCVTimeStampVideoRefreshPeriodValid = (1L << 3),
    kCVTimeStampRateScalarValid = (1L << 4),
    kCVTimeStampTopField = (1L << 16),
    kCVTimeStampBottomField = (1L << 17)
};

enum {
    kCVTimeStampVideoHostTimeValid = (kCVTimeStampVideoTimeValid | kCVTimeStampHostTimeValid),
    kCVTimeStampIsInterlaced = (kCVTimeStampTopField | kCVTimeStampBottomField)
};

enum { kCVSMPTETimeValid = (1L << 0), kCVSMPTETimeRunning = (1L << 1) };

enum {
    kCVSMPTETimeType24 = 0,
    kCVSMPTETimeType25 = 1,
    kCVSMPTETimeType30Drop = 2,
    kCVSMPTETimeType30 = 3,
    kCVSMPTETimeType2997 = 4,
    kCVSMPTETimeType2997Drop = 5,
    kCVSMPTETimeType60 = 6,
    kCVSMPTETimeType5994 = 7
};
