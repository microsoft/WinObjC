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

#import <StubReturn.h>
#import <MediaPlayer/MPRemoteCommand.h>

@implementation MPRemoteCommand
/**
 @Status Stub
 @Notes
*/
- (void)addTarget:(id)target action:(SEL)action {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTarget:(id)target {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTarget:(id)target action:(SEL)action {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)addTargetWithHandler:(MPRemoteCommandHandlerStatus (^)(MPRemoteCommandEvent*))handler {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
