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

#import "Starboard.h"
#import <StubReturn.h>

#import <UIKit/UIStoryboardSegue.h>
#import <UIKit/UIViewController.h>

@implementation UIStoryboardSegue {
    idretain _identifier, _source, _destination;
}

- (instancetype)initWithIdentifier:(id)identifier source:(id)source destination:(id)dest {
    _identifier = [identifier copy];
    _source = source;
    _destination = dest;

    return self;
}

/**
 @Status Interoperable
*/
- (id)identifier {
    return _identifier;
}

/**
 @Status Interoperable
*/
- (id)destinationViewController {
    return _destination;
}

/**
 @Status Interoperable
*/
- (id)sourceViewController {
    return _source;
}

/**
 @Status Stub
 @Notes
*/
- (void)perform {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (instancetype)segueWithIdentifier:(NSString*)identifier
                             source:(UIViewController*)source
                        destination:(UIViewController*)destination
                     performHandler:(void (^)(void))performHandler {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
