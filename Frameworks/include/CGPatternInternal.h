//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <CoreGraphics/CGPattern.h>
#import <CoreGraphics/CGContext.h>
#import "CoreGraphicsInternal.h"

CGRect _CGPatternGetBounds(CGPatternRef pattern);

/*
* Call the CGPatternCallbacks associated with the pattern.
*/
void _CGPatternIssueCallBack(CGContextRef context, CGPatternRef pattern);

CGAffineTransform _CGPatternGetTransformation(CGPatternRef pattern);

/*
* Get the final size of the pattern tile (after xStep and xStep has been applied).
*/
CGRect _CGPatternGetFinalPatternSize(CGPatternRef pattern);

/*
* Get the pattern colored value.
* If it is colored, then we have a colored pattern has inherent color,
* if it's false then we have a stencil pattern does not have inherent color.
*/
bool _CGPatternIsColored(CGPatternRef pattern);

// Starboard-only:
COREGRAPHICS_EXPORT CGPatternRef _CGPatternCreateFromImage(CGImageRef img); // TODO: need to move out this maybe to UIKit ???