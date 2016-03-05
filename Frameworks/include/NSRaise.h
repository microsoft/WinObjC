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

#pragma once

#import <Foundation/NSException.h>
#import <Foundation/NSString.h>

#import "StubReturn.h"

static inline void _NSInvalidAbstractInvocation(SEL selector, id object) {
    [NSException raise:NSDestinationInvalidException
                format:@"-[%@ %s]: invalid method invoked on abstract class.", [object class], sel_getName(selector)];
}

#ifndef NSInvalidAbstractInvocation
#define NSInvalidAbstractInvocation() _NSInvalidAbstractInvocation(_cmd, self)
#endif

struct _NSInvalidAbstractInvocationReturn {
    SEL _selector;
    id _object;

    template <typename T>
    operator T() {
        _NSInvalidAbstractInvocation(_selector, _object);
        return StubReturn();
    }
};

#ifndef NSInvalidAbstractInvocationReturn
#define NSInvalidAbstractInvocationReturn() _NSInvalidAbstractInvocationReturn({ _cmd, self })
#endif