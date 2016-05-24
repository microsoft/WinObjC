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

#include "StubReturn.h"
#include "Foundation/Foundation.h"
#include "Foundation/NSObjCRuntime.h"
#include "Foundation/NSArray.h"
#include "Foundation/NSPathUtilities.h"

#include "Platform/EbrPlatform.h"

#include <direct.h>

/**
 @Status Stub
 @Notes
*/
NSString* NSFullUserName() {
    UNIMPLEMENTED();
    return StubReturn();
}

// Helper that gets the path for a folder dirName under the current app's AppData/Local... directory,
// creating the folder if necessary
NSString* _getCreateAppDataLocalDir(const char* dirName) {
    auto ret = [NSString stringWithFormat:@"%hs/%hs", EbrGetWritableFolder(), dirName];
    _mkdir([ret cStringUsingEncoding:NSUTF8StringEncoding]);
    return ret;
}

// Override for when a higher-level directory needs to be created first (eg: Foo1/Foo2/)
NSString* _getCreateAppDataLocalDir(const char* dirName1, const char* dirName2) {
    _getCreateAppDataLocalDir(dirName1);
    auto ret = [NSString stringWithFormat:@"%hs/%hs/%hs", EbrGetWritableFolder(), dirName1, dirName2];
    _mkdir([ret cStringUsingEncoding:NSUTF8StringEncoding]);
    return ret;
}

/**
 @Status Caveat
 @Notes  Currently only supports NSUserDomainMask
         Some directories (ie: NSPrinterDescriptionDirectory) do not map well to Windows and are not supported
*/
NSArray* NSSearchPathForDirectoriesInDomains(NSSearchPathDirectory dir, NSSearchPathDomainMask mask, BOOL expandTilde) {
    // expandTilde can be ignored, as Windows does not have a concept of a '~/' directory

    if (mask & NSUserDomainMask) {
        NSMutableArray* ret = [NSMutableArray new];

        switch (dir) {
            case NSApplicationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Applications")];
                break;

            case NSDemoApplicationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Applications", "Demos")];
                break;

            case NSDeveloperApplicationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Developer", "Applications")];
                break;

            case NSAdminApplicationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Applications", "Utilities")];
                break;

            case NSLibraryDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library")];
                break;

            case NSDeveloperDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Developer")];
                break;

            case NSUserDirectory:
                // No AppData/Local dir
                break;

            case NSDocumentationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "Documentation")];
                break;

            case NSDocumentDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Documents")];
                break;

            case NSCoreServiceDirectory:
                // No AppData/Local dir
                break;

            case NSAutosavedInformationDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "Autosave Information")];
                break;

            case NSDesktopDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Desktop")];
                break;

            case NSCachesDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "Caches")];
                break;

            case NSApplicationSupportDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "Application Support")];
                break;

            case NSDownloadsDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Downloads")];
                break;

            case NSInputMethodsDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "Input Methods")];
                break;

            case NSMoviesDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Movies")];
                break;

            case NSMusicDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Music")];
                break;

            case NSPicturesDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Pictures")];
                break;

            case NSPrinterDescriptionDirectory:
                // No AppData/Local dir
                break;

            case NSSharedPublicDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Public")];
                break;

            case NSPreferencePanesDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library", "PreferencePanes")];
                break;

            case NSItemReplacementDirectory:
                // No dirs, period
                break;

            case NSAllApplicationsDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Applications")];
                [ret addObject:_getCreateAppDataLocalDir("Applications", "Utilities")];
                [ret addObject:_getCreateAppDataLocalDir("Developer", "Applications")];
                [ret addObject:_getCreateAppDataLocalDir("Applications", "Demos")];
                break;

            case NSAllLibrariesDirectory:
                [ret addObject:_getCreateAppDataLocalDir("Library")];
                [ret addObject:_getCreateAppDataLocalDir("Developer")];
                break;

            default:
                assert(0);
                return nil;
        }

        return [ret autorelease];
    }

    return nil;
}

/**
 @Status Interoperable
*/
NSString* NSHomeDirectory(void) {
    return [NSString stringWithFormat:@"%hs", EbrGetWritableFolder()];
}

NSString* temporaryDirectory = @"/tmp";

/**
 @Status Interoperable
*/
NSString* NSTemporaryDirectory(void) {
    return temporaryDirectory;
}

/**
 @Status Interoperable
*/
void NSSetTemporaryDirectory(NSString* path) {
    temporaryDirectory = [path retain];
}

/**
 @Status Stub
 @Notes
*/
NSString* NSUserName() {
    UNIMPLEMENTED();
    return StubReturn();
}
