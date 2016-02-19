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

#import <MediaPlayer/MediaPlayerExport.h>
#import <MediaPlayer/MPMediaEntity.h>
#import <MediaPlayer/MPMediaItem.h>

@class NSArray;

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaItemCollection : MPMediaEntity

+ (MPMediaItemCollection*)collectionWithItems:(NSArray*)items STUB_METHOD;

@property (readonly, nonatomic) NSArray* items STUB_PROPERTY;
@property (readonly, nonatomic) MPMediaItem* representativeItem STUB_PROPERTY;
@property (readonly, nonatomic) NSUInteger count STUB_PROPERTY;
@property (readonly, nonatomic) MPMediaType mediaTypes STUB_PROPERTY;

- (instancetype)initWithItems:(NSArray*)items STUB_METHOD;

@end
