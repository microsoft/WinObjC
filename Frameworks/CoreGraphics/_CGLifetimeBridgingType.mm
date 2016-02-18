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

#import "_CGLifetimeBridgingType.h"

#include <map>
#include <mutex>

#import <objc/objc-arc.h>

static std::map<id, intptr_t> s_cgBridgedLifetimes;
static std::mutex s_mutex;

@implementation _CGLifetimeBridgingType
// When an object of the class _CGLifetimeBridgingType is created, it has an implicit retain
// and a zero refcount. 0 truly represents the number of *additional* references on the object.
// Therefore, when the number of additional references drops below 0, it should be destroyed.
- (id)retain {
    std::lock_guard<std::mutex> lock(s_mutex);
    ++s_cgBridgedLifetimes[self];
    return self;
}

- (oneway void)release {
    intptr_t newLifetime = 0;
    {
        std::lock_guard<std::mutex> lock(s_mutex);
        if ((newLifetime = --s_cgBridgedLifetimes[self]) >= 0) {
            return;
        }
        s_cgBridgedLifetimes.erase(self);
    } // release the mutex so we don't try to lock it recursively.
    if (newLifetime == -1) {
        // only dealloc the first time we cross below 0
        // so that other threads that may have decremented the refcount
        // don't trigger a double release.
        objc_delete_weak_refs(self);
        [self dealloc];
    }
}

- (NSUInteger)retainCount {
        std::lock_guard<std::mutex> lock(s_mutex);
        return s_cgBridgedLifetimes[self] + 1;
}
@end
