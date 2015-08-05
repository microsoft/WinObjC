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
#include "Foundation/NSNull.h"

NSNull* nullSingleton;

@implementation NSNull : NSObject
    -(instancetype) initWithCoder:(NSCoder*)coder {
        return self;
    }

    -(instancetype) encodeWithCoder:(NSCoder*)coder {
        return self;
    }

    -(instancetype) copyWithZone:(NSZone*)zone {
        return nullSingleton;
    }

    -(void) release {
    }

    -(void) dealloc {
    }

    -(NSString*) description {
        return @"<null>";
    }

    +(NSNull*) null {
        if ( nullSingleton == nil ) {
            nullSingleton = [self alloc];
        }
        return nullSingleton;
    }

    
@end

