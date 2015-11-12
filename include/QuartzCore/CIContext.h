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

#import <Foundation/NSObject.h>
#import <CoreGraphics/CoreGraphics.h>

@class CIImage, NSDictionary;

@interface CIContext : NSObject {
    CGContextRef _cgContext;
}

+ (CIContext*)contextWithCGContext:(CGContextRef)cgContext options:(NSDictionary*)options;

- (void)drawImage:(CIImage*)image atPoint:(CGPoint)atPoint fromRect:(CGRect)fromRect;
- (void)drawImage:(CIImage*)image inRect:(CGRect)inRect fromRect:(CGRect)fromRect;

@end
