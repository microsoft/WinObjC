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
#import <Starboard.h>
#import <Foundation/NSInvocationOperation.h>

NSString* const NSInvocationOperationVoidResultException = @"NSInvocationOperationVoidResultException";
NSString* const NSInvocationOperationCancelledException = @"NSInvocationOperationCancelledException";

@implementation NSInvocationOperation
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithTarget:(id)target selector:(SEL)sel object:(id)arg {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithInvocation:(NSInvocation*)inv {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
