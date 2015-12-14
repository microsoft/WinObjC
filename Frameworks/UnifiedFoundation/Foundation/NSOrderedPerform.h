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

@interface NSOrderedPerform : NSObject {
@public
    SEL _selector;
    idt(NSObject) _target;
    idt(NSObject) _argument;
    unsigned int _order;
    idt(NSArray) _modes;
}
- (NSOrderedPerform*)initWithSelector:(SEL)selector
                               target:(NSObject*)target
                             argument:(NSObject*)argument
                                order:(NSUInteger)order
                                modes:(NSArray*)modes;
- (void)dealloc;
- (SEL)selector;
- (NSObject*)target;
- (NSObject*)argument;
- (NSUInteger)order;
- (BOOL)fireInMode:(NSString*)mode;
+ (NSOrderedPerform*)orderedPerformWithSelector:(SEL)selector
                                         target:(NSObject*)target
                                       argument:(NSObject*)argument
                                          order:(NSUInteger)order
                                          modes:(NSArray*)modes;
@end
