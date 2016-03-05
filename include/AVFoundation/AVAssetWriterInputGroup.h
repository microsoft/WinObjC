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

#import <AVFoundation/AVFoundationExport.h>
#import <Foundation/NSObject.h>
#import <AVFoundation/AVMediaSelectionGroup.h>

@class NSArray;
@class AVAssetWriterInput;

AVFOUNDATION_EXPORT_CLASS
@interface AVAssetWriterInputGroup : AVMediaSelectionGroup <NSCopying>
+ (instancetype)assetWriterInputGroupWithInputs:(NSArray*)inputs defaultInput:(AVAssetWriterInput*)defaultInput STUB_METHOD;
- (instancetype)initWithInputs:(NSArray*)inputs defaultInput:(AVAssetWriterInput*)defaultInput STUB_METHOD;
@property (readonly, nonatomic) AVAssetWriterInput* defaultInput STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* inputs STUB_PROPERTY;
@end
