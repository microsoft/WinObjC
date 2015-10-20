//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <string.h>

#import "runtime.h"
#import "runtime-private.h"

@implementation Protocol
@end

inline const char* protocol_getName(Protocol* p) {
    return p->name;
}

inline BOOL protocol_isEqual(Protocol* a, Protocol* b) {
    return !strcmp(protocol_getName(a), protocol_getName(b));
}

BOOL protocol_conformsToProtocol(Protocol* a, Protocol* b) {
    struct objc_protocol_list* pl;
    size_t i;

    if (protocol_isEqual(a, b))
        return YES;

    for (pl = a->protocol_list; pl != NULL; pl = pl->next)
        for (i = 0; i < pl->count; i++)
            if (protocol_conformsToProtocol(pl->list[i], b))
                return YES;

    return NO;
}

BOOL class_conformsToProtocol(Class cls, Protocol* p) {
    struct objc_protocol_list* pl;
    struct objc_category** cats;
    long i, j;

    for (pl = cls->protocols; pl != NULL; pl = pl->next)
        for (i = 0; i < pl->count; i++)
            if (protocol_conformsToProtocol(pl->list[i], p))
                return YES;

    objc_global_mutex_lock();

    if ((cats = objc_categories_for_class(cls)) == NULL) {
        objc_global_mutex_unlock();
        return NO;
    }

    for (i = 0; cats[i] != NULL; i++) {
        for (pl = cats[i]->protocols; pl != NULL; pl = pl->next) {
            for (j = 0; j < pl->count; j++) {
                if (protocol_conformsToProtocol(pl->list[j], p)) {
                    objc_global_mutex_unlock();
                    return YES;
                }
            }
        }
    }

    objc_global_mutex_unlock();

    return NO;
}
