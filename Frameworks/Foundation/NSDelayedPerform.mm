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
#include "NSDelayedPerform.h"

@implementation NSDelayedPerform : NSObject
    -(NSDelayedPerform*) initWithObject:(NSObject*)object selector:(SEL)selector argument:(NSObject*)argument {
        _object = [object retain];
        _selector = selector;
        _argument = [argument retain];
        _releaseObjects = TRUE;
        return self;
    }

    -(NSDelayedPerform*) initWithObjectNoRef:(NSObject*)object selector:(SEL)selector argument:(NSObject*)argument {
        _object = object;
        _selector = selector;
        _argument = argument;
        _releaseObjects = FALSE;
        return self;
    }

    -(void) dealloc {
        if ( _releaseObjects ) {
            [_object release];
            [_argument release];
        }

        [super dealloc];
    }

    +(NSDelayedPerform*) delayedPerformWithObject:(NSObject*)object selector:(SEL)selector argument:(NSObject*)argument {
        return [[[self allocWithZone:NULL] initWithObject:object selector:selector argument:argument] autorelease];
    }

    -(BOOL) isEqualToPerform:(NSDelayedPerform*)other {
        if( _object != other->_object)
            return NO;
   
        if(_selector==NULL || other->_selector==NULL)
            return YES;
    
        if(_selector != other->_selector)
            return NO;
        if(_argument != other->_argument)
            return NO;

        return YES;
    }

    -(NSObject*) perform {
        return [_object performSelector:_selector withObject:_argument];
    }

        
        
        
        
        
        
    
@end

