//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <CoreGraphics/CGImage.h>
#include <Starboard/SmartTypes.h>

struct ImageComparisonResult {
    size_t differences;
    woc::unique_cf<CGImageRef> deltaImage;
};

class ImageComparator {
public:
    virtual ImageComparisonResult CompareImages(CGImageRef left, CGImageRef right) = 0;
};

class PixelByPixelImageComparator : public ImageComparator {
public:
    ImageComparisonResult CompareImages(CGImageRef left, CGImageRef right) override;
};