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

@class NSDate;

MEDIAPLAYER_EXPORT_CLASS
@interface MPMediaLibrary : NSObject <NSSecureCoding>

+ (MPMediaLibrary*)defaultMediaLibrary STUB_METHOD;

@property (readonly, nonatomic) NSDate* lastModifiedDate STUB_PROPERTY;

- (void)beginGeneratingLibraryChangeNotifications STUB_METHOD;
- (void)endGeneratingLibraryChangeNotifications STUB_METHOD;

@end
