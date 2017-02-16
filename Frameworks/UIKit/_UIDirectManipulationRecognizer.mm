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
#import "UIGestureRecognizerInternal.h"
#import "UIPanGestureRecognizerInternal.h"
#import "_UIDirectManipulationRecognizer.h"

static const wchar_t* TAG = L"_UIDMPanGestureRecognizer";

@implementation _UIDMPanGestureRecognizer {
}

static void commonInit(UIPanGestureRecognizer* self) {
    // setting the dragSlack to be 1.0 larger than PanGestureRecognizer,
    // this is to ensure PanGestureRecognizer kicks in first before us.
    float dragSlack = [self _getDragSlack];
    [self _setDragSlack:++dragSlack];
}

- (instancetype)initWithTarget:(id)target action:(SEL)selector {
    if (self = [super initWithTarget:target action:selector]) {
        commonInit(self);
    }

    return self;
}

- (instancetype)init {
    if (self = [super init]) {
        commonInit(self);
    }

    return self;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        commonInit(self);
    }

    return self;
}

- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer*)preventingGestureRecognizer {
    // No gesture should prevent Dmanip Gesture, including Dmanip Gesture themselves
    return NO;
}

- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer*)preventedGestureRecognizer {
    // Dmanip should not prevent any Gesture, including Dmanip Gesture themselves
    return NO;
}

@end
