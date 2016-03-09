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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>
#import <CoreImage/CIFeature.h>

@class NSArray;

COREIMAGE_EXPORT_CLASS
@interface CITextFeature : CIFeature
@property (readonly) CGRect bounds STUB_PROPERTY;
@property (readonly) NSArray* subFeatures STUB_PROPERTY;
@property (readonly) CGPoint bottomLeft STUB_PROPERTY;
@property (readonly) CGPoint bottomRight STUB_PROPERTY;
@property (readonly) CGPoint topLeft STUB_PROPERTY;
@property (readonly) CGPoint topRight STUB_PROPERTY;
@end
