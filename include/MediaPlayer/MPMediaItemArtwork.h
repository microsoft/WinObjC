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

#import <Foundation/NSObject.h>
#import <MediaPlayer/MediaPlayerExport.h>
#import <CoreGraphics/CGBase.h>

@class UIImage;

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaItemArtwork : NSObject

@property (readonly, nonatomic) CGRect bounds STUB_PROPERTY;
@property (readonly, nonatomic) CGRect imageCropRect STUB_PROPERTY;

- (UIImage*)imageWithSize:(CGSize)size STUB_METHOD;
- (instancetype)initWithImage:(UIImage*)image STUB_METHOD;

@end
