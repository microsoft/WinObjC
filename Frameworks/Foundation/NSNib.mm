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
#include "Foundation/NSNib.h"
#include "Foundation/NSString.h"
#include "Foundation/NSData.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSKeyedUnarchiver.h"
#include "UIKit/UIView.h"
#include "UIKit/UIWindow.h"
#include "NSNibUnarchiver.h"

static IWLazyClassLookup _LazyUIProxyObject("UIProxyObject");
static IWLazyClassLookup _LazyUIWindow("UIWindow");

@implementation NSNib {
    idretain _bundle;
}

/**
 @Status Interoperable
*/
- (NSArray*)loadNib:(NSString*)filename withOwner:(id)ownerObject {
    return [self loadNib:filename withOwner:ownerObject proxies:nil];
}

/**
 @Status Interoperable
*/
- (NSArray*)loadNib:(NSString*)filename withOwner:(id)ownerObject proxies:(NSDictionary*)proxies {
    NSData* data = [NSData dataWithContentsOfFile:filename];
    if (data == nil) {
        data = [NSData dataWithContentsOfFile:[filename stringByAppendingPathComponent:@"/runtime.nib"]];
    }

    return [self loadNibWithData:data withOwner:ownerObject proxies:proxies];
}

- (NSArray*)loadNibWithData:(NSData*)data withOwner:(id)ownerObject proxies:(NSDictionary*)proxies {
    char* bytes = (char*)[data bytes];
    if (!bytes) {
        return nil;
    }

    id prop;

    if (memcmp(bytes, "NIBArchive", 10) == 0) {
        prop = [NSNibUnarchiver alloc];
    } else {
        prop = [NSKeyedUnarchiver alloc];
    }

    [_LazyUIProxyObject addProxyObject:nil withName:@"IBFirstResponder" forCoder:prop];
    [_LazyUIProxyObject addProxyObject:ownerObject withName:@"IBFilesOwner" forCoder:prop];

    for (id key in proxies) {
        id curObj = [proxies objectForKey:key];

        [_LazyUIProxyObject addProxyObject:curObj withName:key forCoder:prop];
    }

    [prop _setBundle:(id)_bundle];
    [prop initForReadingWithData:data];
    // id allObjects = prop("decodeObjectForKey:", @"UINibObjectsKey");
    NSArray* connections = [prop decodeObjectForKey:@"UINibConnectionsKey"];
    NSArray* topLevelObjects = [prop decodeObjectForKey:@"UINibTopLevelObjectsKey"];
    NSArray* visibleObjects = [prop decodeObjectForKey:@"UINibVisibleWindowsKey"];
    NSArray* allObjects = [prop decodeObjectForKey:@"UINibObjectsKey"];

    for (UIRuntimeEventConnection* curconnection in connections) {
        [curconnection _makeConnection];
    }

    for (UIView* curobject in visibleObjects) {
        [curobject setHidden:FALSE];

        if ([curobject isKindOfClass:[_LazyUIWindow class]]) {
            [curobject makeKeyAndVisible];
        }
    };

    for (id curobject in allObjects) {
        if (curobject != ownerObject) {
            if ([curobject respondsToSelector:@selector(awakeFromNib)]) {
                [curobject awakeFromNib];
            }
        }
    }

    [prop autorelease];

    //  Grab TLO's, excluding owner
    NSMutableArray* ret = [NSMutableArray array];
    for (id curobject in topLevelObjects) {
        if (curobject != ownerObject) {
            [ret addObject:curobject];
        }
    }

    [_LazyUIProxyObject clearProxyObjects:prop];

    return ret;
}

- (void)_setBundle:(NSBundle*)bundle {
    _bundle = bundle;
}

- (NSBundle*)_bundle {
    return _bundle;
}

- (void)dealloc {
    _bundle = nil;
    [super dealloc];
}

@end
