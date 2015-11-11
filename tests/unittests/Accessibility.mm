#include "gtest-api.h"

#import <UIKit/UIKit.h>
#import "Starboard.h"
#import "CALayerInternal.h"
#import "NullCompositor.h"

TEST(Accessibility, accessors)
{
    SetCACompositor(new NullCompositor);
    
    auto button = [[UIButton alloc] init];
    button.isAccessibilityElement = TRUE;
    button.accessibilityHint = @"TestHint";

    EXPECT_TRUE_MSG(button.isAccessibilityElement == TRUE, "Bad accessor");
    EXPECT_TRUE_MSG([button.accessibilityHint isEqualToString: @"TestHint"], "Bad accessor");

    auto item = [[UIBarButtonItem alloc] init];
    item.isAccessibilityElement = TRUE;
    item.accessibilityHint = @"TestHint";

    EXPECT_TRUE_MSG(item.isAccessibilityElement == TRUE, "Bad accessor");
    EXPECT_TRUE_MSG([item.accessibilityHint isEqualToString: @"TestHint"], "Bad accessor");    
}
