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

#import <CoreImage/CIImage.h>
#import <CoreGraphics/CGImage.h>
#import <memory>
#import <Foundation/NSDictionary.h>
#import <Starboard.h>

@interface CIImage () {
    woc::unique_cf<CGImageRef> _cgImage;
    StrongId<CIColor> _color;
    StrongId<NSDictionary> _options;
    CIFilter* _filter;
    CGRect _extent;
}

- (CGImageRef)_CGImageFromRect:(CGRect)rect;

@end