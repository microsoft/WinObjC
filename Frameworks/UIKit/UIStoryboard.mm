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

#import <Foundation/NSString.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSBundle.h>
#import <Foundation/NSNib.h>
#import <UIKit/UIViewController.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIStoryboard.h>

@implementation UIStoryboard {
    idretaintype(NSString) _entryPoint;
    idretaintype(NSDictionary) _fileMap;
    idretaintype(NSString) _path;
}

/**
 @Status Interoperable
*/
+ (instancetype)storyboardWithName:(NSString*)name bundle:(NSBundle*)bundle {
    UIStoryboard* ret = [self alloc];

    ret->_path = [name stringByAppendingString:@".storyboardc"];

    if (bundle == nil) {
        bundle = [NSBundle mainBundle];
    }
    id storyInfoPath = [bundle pathForResource:@"Info" ofType:@"plist" inDirectory:(id)ret->_path];

    if (storyInfoPath != nil) {
        id storyInfo = [NSDictionary dictionaryWithContentsOfFile:storyInfoPath];
        if (storyInfo) {
            ret->_entryPoint = [storyInfo objectForKey:@"UIStoryboardDesignatedEntryPointIdentifier"];
            ret->_fileMap = [storyInfo objectForKey:@"UIViewControllerIdentifiersToNibNames"];

            return ret;
        }
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (UIViewController*)instantiateInitialViewController {
    id fileName = [_fileMap objectForKey:_entryPoint];

    id uiApplication = [UIApplication sharedApplication];

    id pathToNib = nil;

    NSString* runtimePath = [_path stringByAppendingPathComponent:(id)fileName];
    runtimePath = [runtimePath stringByAppendingString:@".nib"];

    EbrDebugLog("Searching = %s\n", [runtimePath UTF8String]);
    pathToNib = [[NSBundle mainBundle] pathForResource:@"runtime" ofType:@"nib" inDirectory:runtimePath];
    if (pathToNib == nil) {
        pathToNib = [[NSBundle mainBundle] pathForResource:fileName ofType:@"nib" inDirectory:(id)_path];
    }
    EbrDebugLog("Found %s\n", [pathToNib UTF8String]);

    id proxyObjects[2];
    id proxyNames[2];

    proxyObjects[0] = uiApplication;
    proxyNames[0] = @"UpstreamPlaceholder-1";
    proxyObjects[1] = self;
    proxyNames[1] = @"UIStoryboardPlaceholder";
    id proxyObjectsDict = [NSDictionary dictionaryWithObjects:proxyObjects forKeys:proxyNames count:2];

    id obj = [[NSNib alloc] loadNib:pathToNib withOwner:uiApplication proxies:proxyObjectsDict];
    int count = [obj count];

    for (int i = 0; i < count; i++) {
        id curObj = [obj objectAtIndex:i];

        if ([curObj isKindOfClass:[UIViewController class]]) {
            return curObj;
        }
    }

    return nil;
}

/**
 @Status Interoperable
*/
- (UIViewController*)instantiateViewControllerWithIdentifier:(id)identifier {
    EbrDebugLog("instantiateViewControllerWithIdentifier %s\n", [identifier UTF8String]);
    id fileName = [_fileMap objectForKey:(id)identifier];

    id uiApplication = [UIApplication sharedApplication];

    id pathToNib = nil;

    id runtimePath = [_path stringByAppendingPathComponent:(id)fileName];
    runtimePath = [runtimePath stringByAppendingString:(id) @".nib"];

    EbrDebugLog("Searching = %s\n", [runtimePath UTF8String]);
    pathToNib = [[NSBundle mainBundle] pathForResource:(id) @"runtime" ofType:@"nib" inDirectory:runtimePath];
    if (pathToNib == nil) {
        pathToNib = [[NSBundle mainBundle] pathForResource:fileName ofType:@"nib" inDirectory:(id)_path];
    }

    id proxyObjects[2];
    id proxyNames[2];

    proxyObjects[0] = uiApplication;
    proxyNames[0] = @"UpstreamPlaceholder-1";
    proxyObjects[1] = self;
    proxyNames[1] = @"UIStoryboardPlaceholder";
    id proxyObjectsDict = [NSDictionary dictionaryWithObjects:proxyObjects forKeys:proxyNames count:2];

    id nib = [NSNib alloc];
    id obj = [nib loadNib:pathToNib withOwner:uiApplication proxies:proxyObjectsDict];
    [nib release];
    int count = [obj count];

    for (int i = 0; i < count; i++) {
        id curObj = [obj objectAtIndex:i];

        if ([curObj isKindOfClass:[UIViewController class]]) {
            return curObj;
        }
    }

    return nil;
}

- (NSString*)_path {
    return _path;
}

@end
