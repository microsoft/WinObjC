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
#import <UIKit/UIKitExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGAffineTransform.h>

@class UIBezierPath;

typedef NS_ENUM(NSUInteger, UIDynamicItemCollisionBoundsType) {
    UIDynamicItemCollisionBoundsTypeRectangle,
    UIDynamicItemCollisionBoundsTypeEllipse, // radii will be determined from the items bounds width, height
    UIDynamicItemCollisionBoundsTypePath
};

@protocol UIDynamicItem <NSObject>
@required
@property (nonatomic, readonly) CGRect bounds;
@property (nonatomic, readwrite) CGPoint center;
@property (nonatomic, readwrite) CGAffineTransform transform;

@optional
@property (nonatomic, readonly) UIDynamicItemCollisionBoundsType collisionBoundsType;
@property (nonatomic, readonly) UIBezierPath* collisionBoundingPath;
@end
