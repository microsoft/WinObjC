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

#import "Starboard.h"
#import "UIKit/UIPasteboard.h"
#import "NSLogging.h"
#import <StubReturn.h>

#import "UWP/WindowsApplicationModelDataTransfer.h"
#import "CGImageInternal.h"
#import "MobileCoreServices/UTType.h"

#include <COMIncludes.h>
#import <windows.storage.streams.h>
#import "RawBuffer.h"
#include <COMIncludes_End.h>

static const wchar_t* TAG = L"UIPasteboard";
NSString* const UIPasteboardNameGeneral = @"UIPasteboardNameGeneral";
NSString* const UIPasteboardNameFind = @"UIPasteboardNameFind";
NSString* const UIPasteboardChangedTypesAddedKey = @"UIPasteboardChangedTypesAddedKey";
NSString* const UIPasteboardChangedTypesRemovedKey = @"UIPasteboardChangedTypesRemovedKey";

/** @Status Stub */
NSArray* const UIPasteboardTypeListString = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListURL = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListImage = StubConstant();
/** @Status Stub */
NSArray* const UIPasteboardTypeListColor = StubConstant();

NSString* const UIPasteboardChangedNotification = @"UIPasteboardChangedNotification";
NSString* const UIPasteboardRemovedNotification = @"UIPasteboardRemovedNotification";

using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage::Streams;

using namespace Microsoft::WRL;

@implementation UIPasteboard

UIPasteboard* generalPasteboard;
NSMutableDictionary* globalPasteboards;
static pthread_mutex_t globalPasteboardsLock = PTHREAD_MUTEX_INITIALIZER;

WADDataPackageView* _getClipboardContent() {
    @try {
        return [WADClipboard getContent];
    } @catch (NSException* exception) {
        if ([exception _hresult] == E_ACCESSDENIED) {
            return nil;
        }

        @throw;
    }
}

/**
 @Status Caveat
 @Notes only NSString and UIImage are supported by generalPasteboard.
*/
+ (UIPasteboard*)generalPasteboard {
    @synchronized(self) {
        if (generalPasteboard == nil) {
            generalPasteboard = [[UIPasteboard alloc] init:UIPasteboardNameGeneral];
        }
    }
    return generalPasteboard;
}

- (UIPasteboard*)init:(NSString*)pasteBoardName {
    if (self = [super init]) {
        pthread_mutex_lock(&globalPasteboardsLock);
        if (globalPasteboards == nil) {
            globalPasteboards = [[NSMutableDictionary alloc] initWithCapacity:10];
        }
        pthread_mutex_unlock(&globalPasteboardsLock);

        _name = pasteBoardName;
    }
    return self;
}

+ (void)_failureWhileHandingItemToClipboard:(NSError*)failure withMsg:(NSString*)msg {
    if (failure != nil) {
        NSTraceError(TAG, @"Error with UIPasteBoard %@", failure);
    }

    if (msg != nil) {
        NSTraceError(TAG, msg);
    }
}

/**
 @Status Caveat
 @Notes Only local app communication is supported.
*/
+ (UIPasteboard*)pasteboardWithName:(NSString*)pasteboardName create:(BOOL)create {
    // initArray

    if (pasteboardName == nil) {
        return [UIPasteboard pasteboardWithUniqueName];
    }
    UIPasteboard* temp = [[[UIPasteboard alloc] init] autorelease];
    pthread_mutex_lock(&globalPasteboardsLock);
    [globalPasteboards setObject:temp forKey:pasteboardName];
    pthread_mutex_unlock(&globalPasteboardsLock);
    return temp;
}

/**
 @Status Interoperable
*/
+ (UIPasteboard*)pasteboardWithUniqueName {
    static int curId = 0;
    char szName[255];
    @synchronized(self) {
        sprintf_s(szName, sizeof(szName), "Undefined_%d", curId);
        curId++;
    }
    NSString* uniqueName = [NSString stringWithCString:szName];
    return [UIPasteboard pasteboardWithName:uniqueName create:YES];
}

/**
 @Status Interoperable
 @Notes
*/
+ (void)removePasteboardWithName:(NSString*)pasteboardName {
    // only allow none general pasteboards to be removed
    pthread_mutex_lock(&globalPasteboardsLock);
    if (globalPasteboards != nil) {
        [globalPasteboards removeObjectForKey:pasteboardName];
    }
    pthread_mutex_unlock(&globalPasteboardsLock);
}

/**
 @Status Caveat
 @Notes only NSString, NSURL and UIImage are supported.
*/
- (NSArray<NSString*>*)pasteboardTypes {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    NSMutableArray<NSString*>* types = [[[NSMutableArray<NSString*> alloc] init] autorelease];

    if ([wasDataPackageView contains:[WADStandardDataFormats text]]) {
        [types addObject:(NSString*)kUTTypeText];
    }
    if ([wasDataPackageView contains:[WADStandardDataFormats bitmap]]) {
        [types addObject:(NSString*)kUTTypeImage];
    }
    if ([wasDataPackageView contains:[WADStandardDataFormats uri]]) {
        [types addObject:(NSString*)kUTTypeURL];
    }

    return types;
}

/**
 @Status Caveat
 @Notes only NSString, NSURL and UIImage are supported.
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    BOOL result = NO;

    for (NSString* type in pasteboardTypes) {
        if ([type isEqualToString:(NSString*)kUTTypeText]) {
            if ([wasDataPackageView contains:[WADStandardDataFormats text]]) {
                result = YES;
                break;
            }
        } else if ([type isEqualToString:(NSString*)kUTTypeImage]) {
            if ([wasDataPackageView contains:[WADStandardDataFormats bitmap]]) {
                result = YES;
                break;
            }
        } else if ([type isEqualToString:(NSString*)kUTTypeURL]) {
            if ([wasDataPackageView contains:[WADStandardDataFormats uri]]) {
                result = YES;
                break;
            }
        }
    }

    return result;
}

/**
 @Status Caveat
 @Notes only NSString and UIImage (only PNG format) are supported.
*/
- (NSData*)dataForPasteboardType:(NSString*)pasteboardType {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    NSData* data = nil;

    if ([pasteboardType isEqualToString:(NSString*)kUTTypeText]) {
        NSString* stringData = [UIPasteboard _getStringFromClipboard];
        if (stringData != nil) {
            data = [stringData dataUsingEncoding:NSUnicodeStringEncoding];
        }
    } else if ([pasteboardType isEqualToString:(NSString*)kUTTypeImage]) {
        UIImage* imageData = [UIPasteboard _getImageFromClipboard];
        if (imageData != nil) {
            // After UIImageJPEGRepresentation is implemented, should consider both PND and JPEG
            data = UIImagePNGRepresentation(imageData);
        }
    }

    return data;
}

/**
 @Status Stub
 @Notes
*/
- (id)valueForPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes only NSString and UIImage are supported.
*/
- (void)setData:(NSData*)data forPasteboardType:(NSString*)pasteboardType {
    if (data == nil || pasteboardType == nil) {
        return;
    }

    // Copy and Paste
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        WADDataPackage* dataPackage = [[WADDataPackage make] autorelease];
        dataPackage.requestedOperation = WADDataPackageOperationCopy;
        [UIPasteboard _setData:pasteboardType withData:data on:dataPackage];
        [WADClipboard setContent:dataPackage];
    }
}

+ (WSSInMemoryRandomAccessStream*)_populateStream:(WSSInMemoryRandomAccessStream*)stream withData:(const void*)data withLength:(int)length {
    WSSDataWriter* dataWriter = [[WSSDataWriter makeDataWriter:[stream getOutputStreamAt:0]] autorelease];
    ComPtr<IBuffer> buffer;
    IBuffer* rawBuffer = nullptr;
    HRESULT result;

    result = BufferFromRawData(&rawBuffer, (unsigned char*)data, length);

    if (FAILED(result)) {
        THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
    }

    buffer.Attach(rawBuffer);

    // WARNING: If someone deletes UIPasteboard before the StoreAsync is completed, _data may be released
    // causing IBuffer to segfault. Although UIPasteboard should live forever once created.

    // TODO: subclassed IAsyncOperation<T>s don't get generated correctly in ObjCUWP yet, when that happens it'll
    // open up StoreAsync.

    IDataWriter* writer = (__bridge IDataWriter*)[dataWriter comObj].Get();
    ComPtr<IAsyncOperation<UInt32>> comp;
    writer->WriteBuffer(buffer.Get());
    writer->StoreAsync(&comp);
    return stream;
}

+ (WSSInMemoryRandomAccessStream*)_grabStreamFromUIImage:(UIImage*)image {
    CGImageRef img = [image CGImage];

    if (img->_imgType == CGImageTypePNG || img->_imgType == CGImageTypeJPEG) {
        const void* data = NULL;
        int len = 0;
        StrongId<NSData> fileData;

        switch (img->_imgType) {
            case CGImageTypePNG: {
                CGPNGImageBacking* pngImg = (CGPNGImageBacking*)img->Backing();

                if (pngImg->_fileName) {
                    fileData.attach([[NSData alloc] initWithContentsOfFile:[NSString stringWithUTF8String:pngImg->_fileName]]);
                    data = [fileData bytes];
                    len = [fileData length];
                } else {
                    data = [(NSData*)pngImg->_data bytes];
                    len = [(NSData*)pngImg->_data length];
                }
            } break;

            case CGImageTypeJPEG: {
                CGJPEGImageBacking* jpgImg = (CGJPEGImageBacking*)img->Backing();

                if (jpgImg->_fileName) {
                    fileData.attach([[NSData alloc] initWithContentsOfFile:[NSString stringWithUTF8String:jpgImg->_fileName]]);
                    data = [fileData bytes];
                    len = [fileData length];
                } else {
                    data = [(NSData*)jpgImg->_data bytes];
                    len = [(NSData*)jpgImg->_data length];
                }
            } break;
            default:
                TraceError(TAG, L"Warning: unrecognized image format sent to DisplayTextureContent!");
                break;
        }

        WSSInMemoryRandomAccessStream* stream = [[WSSInMemoryRandomAccessStream make] autorelease];
        [UIPasteboard _populateStream:stream withData:data withLength:len];
        return stream;
    }
    return nil;
}

+ (void)_setData:(NSString*)type withData:(NSData*)data on:(WADDataPackage*)package {
    if ([type isEqualToString:(NSString*)kUTTypeText]) {
        [package setText:[[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease]];
    } else if ([type isEqualToString:(NSString*)kUTTypeImage]) {
        // grab the image and unpack it and repack it.
        UIImage* uiImage = [UIImage imageWithData:data];
        WSSRandomAccessStreamReference* randomAccessStreamReference =
            [WSSRandomAccessStreamReference createFromStream:[UIPasteboard _grabStreamFromUIImage:uiImage]];
        [package setBitmap:randomAccessStreamReference];
    } else if ([type isEqualToString:(NSString*)kUTTypeURL]) {
        // make sure it is a valid NSURL
        NSURL* url = [NSURL URLWithString:[[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease]];
        if (url == nil) {
            TraceWarning(TAG, L"Null NSURL not supported");
            return;
        }

        // convert to WFURI
        WFUri* uri = [[WFUri makeUri:url.absoluteString] autorelease];
        [package setUri:uri];
    } else if ([type isEqualToString:@"NSColor"]) {
        TraceWarning(TAG, L"Error NSColor Not Supported");
    } else {
        NSTraceError(TAG, @"Unsupported Type so data is not packaged %@", type);
    }
}

/**
 @Status Stub
 @Notes
*/
- (void)setValue:(id)value forPasteboardType:(NSString*)pasteboardType {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)pasteboardTypesForItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSIndexSet*)itemSetWithPasteboardTypes:(NSArray*)pasteboardTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)dataForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)valuesForPasteboardType:(NSString*)pasteboardType inItemSet:(NSIndexSet*)itemSet {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addItems:(NSArray*)items {
    UNIMPLEMENTED();
}

/**
 @Status Caveat
 @Notes Only general pasteboard, for other type, it just will return nil.
*/
- (NSString*)string {
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        return [UIPasteboard _getStringFromClipboard];
    }

    return nil;
}

/**
 @Status Caveat
 @Notes Only general pasteboard.
*/
- (void)setString:(NSString*)aString {
    if (aString == nil) {
        return;
    }

    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        [UIPasteboard _setStringToClipboard:aString];
    }
}

+ (NSString*)_getStringFromClipboard {
    __block NSString* stringData = nil;
    WADDataPackageView* wasDataPackageView = _getClipboardContent();

    if ([wasDataPackageView contains:[WADStandardDataFormats text]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [wasDataPackageView getTextAsyncWithSuccess:^void(NSString* success) {
            stringData = [success retain];

            dispatch_group_leave(group);
        }
            failure:^void(NSError* failure) {
                [UIPasteboard _failureWhileHandingItemToClipboard:failure withMsg:@"string getTextAsyncWithSuccess failed"];

                dispatch_group_leave(group);
            }];

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [stringData autorelease];
}

+ (void)_setStringToClipboard:(NSString*)stringData {
    NSData* data = [stringData dataUsingEncoding:NSUnicodeStringEncoding];
    WADDataPackage* dataPackage = [[WADDataPackage make] autorelease];

    dataPackage.requestedOperation = WADDataPackageOperationCopy;
    [UIPasteboard _setData:(NSString*)kUTTypeText withData:data on:dataPackage];
    [WADClipboard setContent:dataPackage];
}

/**
 @Status Caveat
 @Notes Only general pasteboard, for other type, it just will return nil.
*/
- (UIImage*)image {
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        return [UIPasteboard _getImageFromClipboard];
    }

    return nil;
}

/**
 @Status Caveat
 @Notes Only general pasteboard.
*/
- (void)setImage:(UIImage*)aImage {
    if (aImage == nil) {
        return;
    }

    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        [UIPasteboard _setImageToClipboard:aImage];
    }
}

+ (UIImage*)_getImageFromClipboard {
    __block UIImage* imageData = nil;
    WADDataPackageView* wasDataPackageView = _getClipboardContent();

    if ([wasDataPackageView contains:[WADStandardDataFormats bitmap]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [wasDataPackageView getBitmapAsyncWithSuccess:^void(WSSRandomAccessStreamReference* randomAccessStreamReference) {

            [randomAccessStreamReference openReadAsyncWithSuccess:^void(RTObject<WSSIRandomAccessStreamWithContentType>* content) {

                WSSBuffer* buffer = [[WSSBuffer make:content.size] autorelease];

                [content readAsync:buffer
                    count:content.size
                    options:WSSInputStreamOptionsNone
                    success:^void(RTObject<WSSIBuffer>* success) {
                        // Get the data out of the com object.
                        ComPtr<IInspectable> insp = [success comObj];
                        ComPtr<IBufferByteAccess> bufferByteAccess;
                        HRESULT result = insp.As(&bufferByteAccess);
                        if (FAILED(result)) {
                            THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
                        }

                        // Retrieve the buffer data.
                        byte* pixels = nullptr;
                        int length = success.length;
                        result = bufferByteAccess->Buffer(&pixels);
                        if (FAILED(result)) {
                            THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
                        }

                        NSData* data = [NSData dataWithBytes:pixels length:length];
                        imageData = [[UIImage imageWithData:data] retain];

                        dispatch_group_leave(group);
                    }
                    progress:nullptr
                    failure:^void(NSError* readError) {
                        [UIPasteboard _failureWhileHandingItemToClipboard:readError
                                                                  withMsg:@"_getImageFromClipboard readAsync:buffer failed"];

                        dispatch_group_leave(group);
                    }];

            }
                failure:^void(NSError* openError) {
                    [UIPasteboard _failureWhileHandingItemToClipboard:openError
                                                              withMsg:@"_getImageFromClipboard openReadAsyncWithSuccess failed"];

                    dispatch_group_leave(group);
                }];

        }
            failure:^void(NSError* failure) {
                [UIPasteboard _failureWhileHandingItemToClipboard:failure
                                                          withMsg:@"_getImageFromClipboard getBitmapAsyncWithSuccess failed"];

                dispatch_group_leave(group);
            }];

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [imageData autorelease];
}

+ (void)_setImageToClipboard:(UIImage*)imageData {
    WADDataPackage* dataPackage = [[WADDataPackage make] autorelease];
    dataPackage.requestedOperation = WADDataPackageOperationCopy;

    WSSRandomAccessStreamReference* randomAccessStreamReference =
        [WSSRandomAccessStreamReference createFromStream:[UIPasteboard _grabStreamFromUIImage:imageData]];
    [dataPackage setBitmap:randomAccessStreamReference];

    [WADClipboard setContent:dataPackage];
}

/**
 @Status Caveat
 @Notes Only general pasteboard, for other type, it just will return nil.
*/
- (NSURL*)URL {
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        return [UIPasteboard _getURLFromClipboard];
    }

    return nil;
}

/**
 @Status Caveat
 @Notes Only general pasteboard and local app communication is supported.
*/
- (void)setURL:(NSURL*)aURL {
    if (aURL == nil) {
        return;
    }

    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        [UIPasteboard _setURLToClipboard:aURL];
    }
}

+ (NSURL*)_getURLFromClipboard {
    __block NSURL* URLData = nil;
    WADDataPackageView* wasDataPackageView = _getClipboardContent();

    if ([wasDataPackageView contains:[WADStandardDataFormats uri]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [wasDataPackageView getUriAsyncWithSuccess:^void(WFUri* data) {
            NSString* temp = data.absoluteUri;
            if (temp == nil || temp.length == 0) {
                temp = data.displayUri;
            }
            if (temp == nil || temp.length == 0) {
                temp = data.absoluteCanonicalUri;
            }
            if (temp == nil || temp.length == 0) {
                temp = [data toString];
            }

            if (temp != nil) {
                URLData = [[NSURL URLWithString:temp] retain];
            } else {
                TraceError(TAG, L"Error cannot understand WFUri data");
            }

            dispatch_group_leave(group);
        }
            failure:^void(NSError* failure) {
                [UIPasteboard _failureWhileHandingItemToClipboard:failure withMsg:@"_getURLFromClipboard getBitmapAsyncWithSuccess failed"];

                dispatch_group_leave(group);
            }];

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [URLData autorelease];
}

+ (void)_setURLToClipboard:(NSURL*)URLData {
    WADDataPackage* dataPackage = [[WADDataPackage make] autorelease];
    dataPackage.requestedOperation = WADDataPackageOperationCopy;

    WFUri* uri = [[WFUri makeUri:URLData.absoluteString] autorelease];
    [dataPackage setUri:uri];

    [WADClipboard setContent:dataPackage];
}

@end
