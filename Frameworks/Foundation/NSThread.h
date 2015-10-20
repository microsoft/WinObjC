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

@interface NSThread : NSObject {
@public
    idt(NSObject) _target;
    bool _retainTarget;
    SEL _selector;
    idt(NSObject) _object;
    double _priority;
    NSUInteger _stackSize;
    BOOL _cancelled;
    idt(NSRunLoop) _runLoop;
    BOOL _isFinished;
    idretain _threadDictionary;
    idretain _name;
}
+ (double)threadPriority;
- (double)threadPriority;
- (void)setStackSize:(NSUInteger)size;
- (NSThread*)initWithTarget:(NSObject*)target selector:(SEL)selector object:(NSObject*)objParam;
- (BOOL)isCancelled;
- (BOOL)isFinished;
- (void)cancel;
- (NSUInteger)stackSize;
- (void)dealloc;
- (NSObject*)init;
- (void)associateWithCurrentThread;
- (BOOL)isMainThread;
- (NSDictionary*)threadDictionary;
- (void)start;
- (NSRunLoop*)_runLoop;
- (void)setName:(NSString*)name;
- (NSString*)name;
+ (NSThread*)detachNewThreadSelector:(SEL)selector toTarget:(NSObject*)obj withObject:(NSObject*)objParam;
+ (void)sleepForTimeInterval:(double)interval;
+ (void)sleepUntilDate:(NSDate*)date;
+ (void)setThreadPriority:(double)priority;
+ (void)exit;
+ (BOOL)isMainThread;
+ (BOOL)isMultiThreaded;
+ (NSThread*)mainThread;
+ (NSThread*)currentThread;
+ (void)initialize;
@end
