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
#include <UIKit/UIStoryboard.h>
#include "LoggingNative.h"

static const wchar_t* TAG = L"UIStoryboardModalSegueTemplate";

@interface UIStoryboardModalSegueTemplate : NSObject
@end

@implementation UIStoryboardModalSegueTemplate {
    idretaintype(NSString) _identifier, _destination;
    id _viewController;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    _identifier = [coder decodeObjectForKey:@"UIIdentifier"];
    _destination = [coder decodeObjectForKey:@"UIDestinationViewControllerIdentifier"];

    return self;
}

- (void)setViewController:(UIViewController*)controller {
    _viewController = controller;
}

- (UIViewController*)viewController {
    return _viewController;
}

- (id)identifier {
    return _identifier;
}

- (id)destination {
    return _destination;
}

- (id)perform:(id)arg {
    if (_identifier == nil) {
        TraceVerbose(TAG, L"performSegue: identifier = nil!  dest = %hs", [_destination UTF8String]);
        [_viewController performSegueWithDestination:(id)_destination sender:arg];
        return self;
    }

    [_viewController performSegueWithIdentifier:(id)_identifier sender:arg];
    return self;
}

- (void)dealloc {
    _identifier = nil;
    _destination = nil;
    [super dealloc];
}

@end

@implementation UIStoryboardPushSegueTemplate {
    idretaintype(NSString) _identifier, _destination;
    id _viewController;
}

- (id)initWithCoder:(id)coder {
    _identifier = [coder decodeObjectForKey:@"UIIdentifier"];
    _destination = [coder decodeObjectForKey:@"UIDestinationViewControllerIdentifier"];

    return self;
}

- (void)setViewController:(UIViewController*)controller {
    _viewController = controller;
}

- (UIViewController*)viewController {
    return _viewController;
}

- (id)identifier {
    return _identifier;
}

- (id)destination {
    return _destination;
}

- (void)perform:(id)arg {
    if (_identifier == nil) {
        TraceVerbose(TAG, L"performSegue: identifier = nil!  dest = %hs", [_destination UTF8String]);
        [_viewController performSegueWithDestination:(id)_destination sender:arg];
        return;
    }

    [_viewController performSegueWithIdentifier:(id)_identifier sender:arg];
}

- (void)dealloc {
    _identifier = nil;
    _destination = nil;
    [super dealloc];
}

@end

@implementation UIStoryboardSegueTemplate {
@public
    idretaintype(NSString) _identifier, _destination;
    id _viewController;
}

- (instancetype)initWithCoder:(NSCoder*)coder {
    _identifier = [coder decodeObjectForKey:@"UIIdentifier"];
    _destination = [coder decodeObjectForKey:@"UIDestinationViewControllerIdentifier"];

    return self;
}

- (void)setViewController:(id)controller {
    _viewController = controller;
}

- (id)viewController {
    return _viewController;
}

- (id)identifier {
    return _identifier;
}

- (id)destination {
    return _destination;
}

- (void)perform:(id)arg {
    if (_identifier == nil) {
        TraceVerbose(TAG, L"performSegue: identifier = nil!  dest = %hs", [_destination UTF8String]);
        [_viewController performSegueWithDestination:(id)_destination sender:arg];
        return;
    }

    [_viewController performSegueWithIdentifier:_identifier sender:arg];
}

- (void)dealloc {
    _identifier = nil;
    _destination = nil;
    [super dealloc];
}

@end
