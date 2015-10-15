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

@interface UIAnimationNotification : NSObject {
@public
    int _numAnimations;
    int _numStopped, _numStarted;
    id _animName;
    void* _context;
    id _animDelegate;
    SEL _animationDidStopSelector;
    SEL _animationWillStartSelector;
    id _completionBlock;
    DWORD _calledFrom;
}
- (void)_animationHasStarted:(id)animation;
- (void)animationDidStop:(id)animation finished:(BOOL)finished;
@end

void sendDidStop(id delegate, SEL selector, idt(NSString) animName, BOOL finished, void* context);
