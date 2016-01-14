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

NSString * const UINibExternalObjects = @"UINibExternalObjects";

@implementation NSNib {
    idretaintype(NSData) _data;
}

/**
 @Status Interoperable
*/

+(NSNib *) nibWithNibName:(NSString *)name bundle:(NSBundle *) bundle
{
    NSData* data = [NSData dataWithContentsOfFile:name];
    if (data == nil) {
        data = [NSData dataWithContentsOfFile:[name stringByAppendingPathComponent:@"/runtime.nib"]];
        // VSO 5763540: TODO - Change the order in which we resolve bundle paths or paths without .nib
        if (data == nil) {
            data = [NSData dataWithContentsOfFile:[name stringByAppendingPathExtension:@"nib"]];
            if (data == nil) {
                data = [NSData dataWithContentsOfFile:[bundle pathForResource:name ofType:@"nib"]];
                if (data == nil) {
                    return nil;
                }
            }
        }
    }

    return [self nibWithData:data bundle:bundle];
}

/**
 @Status Interoperable
*/

+(NSNib *) nibWithData:(NSData *)data bundle:(NSBundle *) bundle
{
    if ( data == nil ) {
        return nil;
    }

    NSNib *ret = [self alloc];
    ret->_data = data;
    ret->_bundle = bundle;

    return [ret autorelease];
}

/**
 @Status Interoperable
*/

- (NSArray*)instantiateWithOwner:(id)ownerObject options: (NSDictionary*)options {
    const char* bytes = (const char *) [_data bytes];
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

    NSDictionary *proxies = options[UINibExternalObjects];

    for (id key in proxies) {
        id curObj = [proxies objectForKey:key];

        [_LazyUIProxyObject addProxyObject:curObj withName:key forCoder:prop];
    }

    [prop _setBundle:(id)_bundle];
    [prop initForReadingWithData:_data];
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

- (void)dealloc {
    [super dealloc];
}

@end
