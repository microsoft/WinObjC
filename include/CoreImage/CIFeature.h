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

#import <CoreImage/CoreImageExport.h>
#import <CoreGraphics/CGBase.h>
#import <Foundation/NSObject.h>

@class NSString;
COREIMAGE_EXPORT NSString* const CIFeatureTypeFace;
COREIMAGE_EXPORT NSString* const CIFeatureTypeRectangle;
COREIMAGE_EXPORT NSString* const CIFeatureTypeQRCode;
COREIMAGE_EXPORT NSString* const CIFeatureTypeText;
COREIMAGE_EXPORT_CLASS
@interface CIFeature : NSObject
@property (readonly, assign) CGRect bounds STUB_PROPERTY;
@property (readonly, retain) NSString* type STUB_PROPERTY;
@end
