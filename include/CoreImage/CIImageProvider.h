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
#import <CoreImage/CIImage.h>

@class NSString;

@interface NSObject (CoreImage)
- (void)provideImageData:(void*)data
             bytesPerRow:(size_t)rowbytes
                  origin:(size_t)
                       x:(size_t)y
                    size:(size_t)
                   width:(size_t)height
                userInfo:(id)info;
@end
COREIMAGE_EXPORT NSString* const kCIImageProviderTileSize;
COREIMAGE_EXPORT NSString* const kCIImageProviderUserInfo;
@interface CIImage (CIImageProvider)
@end
