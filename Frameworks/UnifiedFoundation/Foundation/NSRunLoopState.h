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

#define MAX_WAITSIGNALS 128
#define MAX_WAITSOCKETS 128

@interface NSRunLoopState : NSObject {
@public
    EbrEvent _waitSignals[MAX_WAITSIGNALS];
    int _waitSignalPriority[MAX_WAITSIGNALS];
    id _waitSignalObjects[MAX_WAITSIGNALS];
    int _numWaitSignals;

    int _waitSockets[MAX_WAITSOCKETS];
    id _waitSocketObjects[MAX_WAITSOCKETS];
    int _numWaitSockets;

    idt(NSMutableArray) _timers;
    idt(NSMutableArray) _observers;
    idt(NSInputSource) _cancelSource;
    int _starveCount;

    bool _builtWakeupSockets;
    int _wakeupSockets[2];
}
- (NSObject*)init;
- (void)dealloc;
- (void)wakeUp;
- (void)addTimer:(NSTimer*)timer;
- (BOOL)containsTimer:(NSTimer*)timer;
- (void)addObserver:(NSTimer*)observer;
- (void)removeObserver:(NSObject*)observer;
- (void)removeTimer:(NSTimer*)timer;
- (void)changingIntoMode:(NSString*)mode;
- (void)_notifyObservers:(uint32_t)mode;
- (void)checkHighPriorityEvents;
- (BOOL)fireFirstTimer;
- (NSDate*)limitDateForMode:(NSString*)mode;
- (void)addInputSource:(NSInputSource*)source;
- (void)removeInputSource:(NSInputSource*)source;
- (void)invalidateTimerWithDelayedPerform:(NSDelayedPerform*)delayed;
- (void)acceptInputForMode:(NSString*)mode beforeDate:(NSDate*)date;
- (NSString*)description;
@end
