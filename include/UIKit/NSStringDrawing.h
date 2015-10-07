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

#ifndef _NSSTRINGDRAWING_H_
#define _NSSTRINGDRAWING_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSString.h>
#import <Foundation/NSAttributedString.h>

enum {
    NSStringDrawingTruncatesLastVisibleLine = 1 << 5,
    NSStringDrawingUsesLineFragmentOrigin = 1 << 0,
    NSStringDrawingUsesFontLeading = 1 << 1,
    NSStringDrawingUsesDeviceMetrics = 1 << 3,
};
typedef NSInteger NSStringDrawingOptions;

@interface NSStringDrawingContext : NSObject

@property (nonatomic, readonly) CGFloat actualScaleFactor;
@property (nonatomic) CGFloat minimumScaleFactor;
@property (nonatomic, readonly) CGRect totalBounds;

@property (nonatomic, readonly) CGFloat actualTrackingAdjustment; // depr
@property (nonatomic) CGFloat minimumTrackingAdjustment; // depr

@end

@interface NSString (NSStringDrawing)
- (CGSize)sizeWithAttributes:(NSDictionary *)attrs;
- (void)drawAtPoint:(CGPoint)point withAttributes:(NSDictionary *)attrs;
@end

@interface NSString (NSExtendedStringDrawing)
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options attributes:(NSDictionary *)attributes context:(NSStringDrawingContext *)context;
@end

@interface NSAttributedString (NSExtendedStringDrawing)
- (CGRect)boundingRectWithSize:(CGSize)size options:(NSStringDrawingOptions)options context:(NSStringDrawingContext *)context;
- (CGSize)size;
@end

#endif /* _NSSTRINGDRAWING_H_ */