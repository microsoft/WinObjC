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

#include "Starboard.h"

@interface UIButtonContent : NSObject {
@public
    id image, backgroundImage, title, titleColor, shadowColor;
}
@end

@implementation UIButtonContent : NSObject
- (instancetype)initWithCoder:(id)coder {
    image = [coder decodeObjectForKey:@"UIImage"];
    backgroundImage = [coder decodeObjectForKey:@"UIBackgroundImage"];
    title = [coder decodeObjectForKey:@"UITitle"];
    titleColor = [coder decodeObjectForKey:@"UITitleColor"];
    shadowColor = [coder decodeObjectForKey:@"UIShadowColor"];

    return self;
}

- (id) /* use typed version */ image {
    return image;
}

- (id) /* use typed version */ backgroundImage {
    return backgroundImage;
}

- (id) /* use typed version */ titleColor {
    return titleColor;
}

- (id) /* use typed version */ shadowColor {
    return shadowColor;
}

- (id) /* use typed version */ title {
    return title;
}

@end
