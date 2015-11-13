//******************************************************************************
//
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

#ifndef _CAGRADIENTLAYER_H_
#define _CAGRADIENTLAYER_H_

#import <QuartzCore/CALayer.h>
#import <GLKit/GLKitExport.h>

GLKIT_EXPORT_CLASS
@interface CAGradientLayer : CALayer

@property (copy) NSArray* colors;
@property (copy) NSArray* locations;
@property CGPoint startPoint;
@property CGPoint endPoint;

@end

#endif /* _CAGRADIENTLAYER_H_ */