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
#import <Foundation/NSObject.h>

@class NSString;
@class NSDictionary;

MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerTimedMetadataKeyName;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerTimedMetadataKeyInfo;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerTimedMetadataKeyMIMEType;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerTimedMetadataKeyDataType;
MEDIAPLAYER_EXPORT NSString* const MPMoviePlayerTimedMetadataKeyLanguageCode;

MEDIAPLAYER_EXPORT_CLASS
@interface MPTimedMetadata : NSObject

@property (readonly, nonatomic) NSDictionary* allMetadata STUB_PROPERTY;
@property (readonly, nonatomic) NSString* key STUB_PROPERTY;
@property (readonly, nonatomic) NSString* keyspace STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval timestamp STUB_PROPERTY;
@property (readonly, nonatomic) id value STUB_PROPERTY;

@end
