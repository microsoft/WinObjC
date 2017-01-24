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

#import "Starboard.h"
#import "StubReturn.h"
#import <UIKit/UIImage.h>
#import <UIKit/UITabBar.h>
#import <UIKit/UITabBarItem.h>
#import <UIKit/UIView.h>
#import "UIBarItemInternal.h"
#import "LoggingNative.h"
#import "UIAppearanceSetter.h"

static const wchar_t* TAG = L"UITabBarItem";

@implementation UITabBarItem {
    idretaintype(NSString) _title, _badgeValue;
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (NSObject*)initWithCoder:(NSCoder*)coder {
    _title = [coder decodeObjectForKey:@"UITitle"];
    _tag = [coder decodeIntegerForKey:@"UITag"];
    _image = [coder decodeObjectForKey:@"UIImage"];

    if ([coder containsValueForKey:@"UIEnabled"]) {
        _enabled = [coder decodeIntegerForKey:@"UIEnabled"];
        //_enabled = true;
    } else {
        _enabled = true;
    }

    if ([coder containsValueForKey:@"UISystemItem"]) {
        int val = [coder decodeIntegerForKey:@"UISystemItem"];
        if (val == 0) {
            _title = @"More";
            _image = [UIImage imageNamed:@"/img/more.png"];
        }
    }
    return self;
}

/**
 @Status Interoperable
*/
- (UITabBarItem*)initWithTitle:(NSString*)title image:(UIImage*)image tag:(NSInteger)tag {
    _title.attach([title copy]);
    _tag = tag;
    _image = image;
    _enabled = TRUE;

    return self;
}

/**
 @Status Stub
*/
- (instancetype)initWithTitle:(NSString*)title image:(UIImage*)image selectedImage:(UIImage*)selectedImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIImage*)finishedSelectedImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIImage*)finishedUnselectedImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UITabBarItem*)initWithTabBarSystemItem:(UITabBarSystemItem)sysItem tag:(NSInteger)tag {
    UNIMPLEMENTED();
    _title = @"Sys";
    _tag = tag;
    _enabled = TRUE;

    return self;
}

/**
 @Status Interoperable
*/
- (void)setTitle:(NSString*)newTitle {
    _title.attach([newTitle copy]);
}

/**
 @Status Stub
*/
- (void)setBadgeValue:(NSString*)badgeValue {
    UNIMPLEMENTED();
    _badgeValue = badgeValue;
}

/**
 @Status Stub
*/
- (NSString*)badgeValue {
    UNIMPLEMENTED();
    return _badgeValue;
}

/**
 @Status Interoperable
*/
- (void)setImage:(UIImage*)newImage {
    _image = newImage;
}

/**
 @Status Stub
*/
- (void)setFinishedSelectedImage:(UIImage*)finishedSelected withFinishedUnselectedImage:(UIImage*)unselected {
    UNIMPLEMENTED_WITH_MSG("setFinishedSelectedImage not supported");
    _image = finishedSelected;
}

/**
 @Status Stub
*/
- (void)setTitleTextAttributes:(NSObject*)attributes forState:(NSUInteger)state {
    UNIMPLEMENTED_WITH_MSG("setTitleTextAttributes not supported");
}

/**
 @Status Stub
*/
- (void)setTitlePositionAdjustment:(UIOffset)adjustment {
    UNIMPLEMENTED_WITH_MSG("setTitlePositionAdjustment not supported");
}

/**
 @Status Stub
*/
- (void)setAccessibilityLabel:(NSString*)label {
    UNIMPLEMENTED_WITH_MSG("setAccessibilityLabel not supported");
}

/**
 @Status Stub
*/
- (void)setImageInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED_WITH_MSG("setImageInsets not supported");
}

/**
 @Status Interoperable
*/
- (void)setEnabled:(BOOL)enabled {
    _enabled = enabled;
}

/**
 @Status Interoperable
*/
- (BOOL)isEnabled {
    return _enabled;
}

/**
 @Status Interoperable
*/
- (NSString*)title {
    return _title;
}

/**
 @Status Interoperable
*/
- (NSInteger)tag {
    return _tag;
}

/**
 @Status Interoperable
*/
- (void)setTag:(NSInteger)tag {
    _tag = tag;
}

/**
 @Status Interoperable
*/
- (UIImage*)image {
    return _image;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _title = nil;
    _image = nil;
    _badgeValue = nil;

    [super dealloc];
}

/**
 @Status Interoperable
*/
+ (instancetype)appearance {
    return [UIAppearanceSetter _appearanceWhenContainedIn:nil forUIClass:self];
}

/**
 @Status Interoperable
*/
+ (instancetype)appearanceWhenContainedIn:(Class<UIAppearanceContainer>)containedClass, ... {
    id curClass = [self class];

    va_list pReader;
    va_start(pReader, containedClass);

    id curVal = va_arg(pReader, id);

    while (curVal != nil) {
        assert(0);
        curVal = va_arg(pReader, id);
    }

    va_end(pReader);

    return [UIAppearanceSetter _appearanceWhenContainedIn:containedClass forUIClass:self];
}
@end
