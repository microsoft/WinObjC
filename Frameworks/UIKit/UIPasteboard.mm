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
#import <StubReturn.h>

#import <UIKit/UIImage.h>
#import <UIKit/UIPasteboard.h>

#import "NSLogging.h"

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

// retain here is to make sure the objects do not get destroyed when they are autoreleased
NSArray<NSString*>* const UIPasteboardTypeListString = [@[ (NSString*)kUTTypeUTF8PlainText, (NSString*)kUTTypeText ] retain];
NSArray<NSString*>* const UIPasteboardTypeListURL = [@[ (NSString*)kUTTypeURL ] retain];
NSArray<NSString*>* const UIPasteboardTypeListImage = [@[ (NSString*)kUTTypePNG, (NSString*)kUTTypeJPEG ] retain];

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

    NSMutableArray<NSString*>* types = [NSMutableArray arrayWithCapacity:3];

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
        } else {
            UNIMPLEMENTED_WITH_MSG("Unsupported pasteType (%hs) in containsPasteboardTypes", [type UTF8String]);
        }
    }

    return result;
}

/**
 @Status Caveat
 @Notes only support one item due to platform limit.
 */
- (NSArray<NSDictionary<NSString*, id>*>*)items {
    WADDataPackageView* dataPackageView = _getClipboardContent();

    int supportedTypes = 0;
    for (NSString* format in dataPackageView.availableFormats) {
        if ([format isEqualToString:[WADStandardDataFormats text]]) {
            supportedTypes++;
        } else if ([format isEqualToString:[WADStandardDataFormats bitmap]]) {
            supportedTypes++;
        } else if ([format isEqualToString:[WADStandardDataFormats uri]]) {
            supportedTypes++;
        }
    }

    // at most items can contain one item, or zero item if no supported type found
    NSMutableArray<NSDictionary<NSString*, id>*>* items = [NSMutableArray arrayWithCapacity:1];
    if (supportedTypes == 0) {
        // early return empty array if no supported type found
        return items;
    }

    NSMutableDictionary* ret = [NSMutableDictionary dictionaryWithCapacity:supportedTypes];
    if ([dataPackageView contains:[WADStandardDataFormats text]]) {
        [ret setValue:[UIPasteboard _getStringFromDataPackageView:dataPackageView] forKey:(NSString*)kUTTypeText];
    }

    if ([dataPackageView contains:[WADStandardDataFormats bitmap]]) {
        [ret setValue:[UIPasteboard _getImageFromDataPackageView:dataPackageView] forKey:(NSString*)kUTTypeImage];
    }

    if ([dataPackageView contains:[WADStandardDataFormats uri]]) {
        [ret setValue:[UIPasteboard _getURLFromDataPackageView:dataPackageView] forKey:(NSString*)kUTTypeURL];
    }

    [items addObject:ret];
    return items;
}

/**
 @Status Caveat
 @Notes only support one item
 */
- (void)setItems:(NSArray<NSDictionary<NSString*, id>*>*)items {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return;
    }

    NSInteger count = [items count];
    if (count > 0) {
        if (count > 1) {
            UNIMPLEMENTED_WITH_MSG("Only support first item in items, the rest is ignored");
        }

        StrongId<WADDataPackage> dataPackage;
        dataPackage.attach([WADDataPackage make]);
        [dataPackage setRequestedOperation:WADDataPackageOperationCopy];
        __block BOOL dataSet = NO;

        // enumerate each format and copy the supported one to clipboard
        NSDictionary<NSString*, id>* item = items[0];
        [item enumerateKeysAndObjectsUsingBlock:^(NSString* pasteboardType, id data, BOOL*) {
            if ([data isKindOfClass:[NSData class]]) {
                // data is represented with binary form, let _setData to handle NSData
                dataSet = [UIPasteboard _setData:pasteboardType withData:data on:dataPackage];
            } else {
                // otherwise, Data is Object, we can copy them directly
                dataSet = YES;
                if ([data isKindOfClass:[UIImage class]]) {
                    [UIPasteboard _setImage:data onDataPackage:dataPackage];
                } else if ([data isKindOfClass:[NSURL class]]) {
                    [UIPasteboard _setURL:data onDataPackage:dataPackage];
                } else if ([data isKindOfClass:[NSString class]]) {
                    [UIPasteboard _setString:data onDataPackage:dataPackage];
                } else {
                    dataSet = NO;
                    UNIMPLEMENTED_WITH_MSG("setting object_type=%hs for PasteboardType=%hs isn't supported yet",
                                           object_getClassName(data),
                                           [pasteboardType UTF8String]);
                }
            }
        }];

        if (dataSet) {
            [WADClipboard setContent:dataPackage];
            [WADClipboard flush];
        }
    } else {
        // assigning items to nil or an empty array clears the pasteboard
        [WADClipboard clear];
    }
}

/**
 @Status Caveat
 @Notes only support one item at most
 */
- (NSInteger)numberOfItems {
    return [self.items count];
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
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return;
    }

    if (data && pasteboardType) {
        // only set data when both data and pasteType are avaiable
        StrongId<WADDataPackage> dataPackage;
        dataPackage.attach([WADDataPackage make]);
        [dataPackage setRequestedOperation:WADDataPackageOperationCopy];
        [UIPasteboard _setData:pasteboardType withData:data on:dataPackage];
        [WADClipboard setContent:dataPackage];
        [WADClipboard flush];
    }
}

+ (WSSInMemoryRandomAccessStream*)_populateStream:(WSSInMemoryRandomAccessStream*)stream withData:(const void*)data withLength:(int)length {
    StrongId<WSSDataWriter> dataWriter;
    dataWriter.attach([WSSDataWriter makeDataWriter:[stream getOutputStreamAt:0]]);
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

    // TODO #1338 - Support via encoded data from IWIC
    woc::unique_cf<CGImageRef> imgRef(_CGImageCreateCopyWithPixelFormat(img, GUID_WICPixelFormat32bppPBGRA));
    // TODO #1450 - CGDataProvider should not be an NSData.
    NSData* data = static_cast<NSData*>(CGImageGetDataProvider(imgRef.get()));

    StrongId<WSSInMemoryRandomAccessStream> stream;
    stream.attach([WSSInMemoryRandomAccessStream make]);
    [UIPasteboard _populateStream:stream withData:[data bytes] withLength:[data length]];
    return stream;
}

// try to set data for a given type on datapackage
// return YES when data has been set on datapackage successfully, NO otherwise.
//
+ (BOOL)_setData:(NSString*)type withData:(NSData*)data on:(WADDataPackage*)package {
    if ([type isEqualToString:(NSString*)kUTTypeText]) {
        [package setText:[[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease]];
        return YES;
    } else if ([type isEqualToString:(NSString*)kUTTypeImage] || [type isEqualToString:(NSString*)kUTTypePNG] ||
               [type isEqualToString:(NSString*)kUTTypeJPEG]) {
        // TODO: we should use UITypeConformsTo to check if type conforms to kUTTypeImage,
        // but UITypeConformsTo has not been implemented yet and currently PNG is the only image format
        // being used in copying

        // grab the image and unpack it and repack it.
        UIImage* uiImage = [UIImage imageWithData:data];
        WSSRandomAccessStreamReference* randomAccessStreamReference =
            [WSSRandomAccessStreamReference createFromStream:[UIPasteboard _grabStreamFromUIImage:uiImage]];
        [package setBitmap:randomAccessStreamReference];
        return YES;
    } else if ([type isEqualToString:(NSString*)kUTTypeURL]) {
        // make sure it is a valid NSURL
        NSURL* url = [NSURL URLWithString:[[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease]];
        if (url == nil) {
            TraceWarning(TAG, L"Invalid URL.");
            return NO;
        }

        // convert to WFURI
        StrongId<WFUri> uri;
        uri.attach([WFUri makeUri:url.absoluteString]);
        [package setUri:uri];
        return YES;
    } else {
        UNIMPLEMENTED_WITH_MSG("Type %@ is not supported yet", [type UTF8String]);
        return NO;
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
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return nil;
    }

    return [UIPasteboard _getStringFromClipboard];
}

/**
 @Status Caveat
 @Notes Only general pasteboard.
*/
- (void)setString:(NSString*)aString {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return;
    }

    if (aString != nil) {
        [UIPasteboard _setStringToClipboard:aString];
    }
}

+ (NSString*)_getStringFromDataPackageView:(WADDataPackageView*)dataPackageView {
    __block NSString* stringData = nil;
    if ([dataPackageView contains:[WADStandardDataFormats text]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [dataPackageView getTextAsyncWithSuccess:^void(NSString* success) {
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

+ (NSString*)_getStringFromClipboard {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    return [UIPasteboard _getStringFromDataPackageView:wasDataPackageView];
}

+ (void)_setString:(NSString*)stringData onDataPackage:(WADDataPackage*)dataPackage {
    NSData* data = [stringData dataUsingEncoding:NSUnicodeStringEncoding];
    [UIPasteboard _setData:(NSString*)kUTTypeText withData:data on:dataPackage];
}

+ (void)_setStringToClipboard:(NSString*)stringData {
    StrongId<WADDataPackage> dataPackage;
    dataPackage.attach([WADDataPackage make]);
    [dataPackage setRequestedOperation:WADDataPackageOperationCopy];
    [UIPasteboard _setString:stringData onDataPackage:dataPackage];
    [WADClipboard setContent:dataPackage];
    [WADClipboard flush];
}

/**
 @Status Caveat
 @Notes Only general pasteboard, for other type, it just will return nil.
*/
- (UIImage*)image {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return nil;
    }

    return [UIPasteboard _getImageFromClipboard];
}

/**
 @Status Caveat
 @Notes Only general pasteboard.
*/
- (void)setImage:(UIImage*)aImage {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return;
    }

    if (aImage != nil) {
        [UIPasteboard _setImageToClipboard:aImage];
    }
}

+ (UIImage*)_getImageFromDataPackageView:(WADDataPackageView*)dataPackageView {
    __block UIImage* imageData = nil;

    if ([dataPackageView contains:[WADStandardDataFormats bitmap]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [dataPackageView getBitmapAsyncWithSuccess:^void(WSSRandomAccessStreamReference* randomAccessStreamReference) {

            [randomAccessStreamReference openReadAsyncWithSuccess:^void(RTObject<WSSIRandomAccessStreamWithContentType>* content) {

                StrongId<WSSBuffer> buffer;
                buffer.attach([WSSBuffer make:content.size]);

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

+ (UIImage*)_getImageFromClipboard {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    return [UIPasteboard _getImageFromDataPackageView:wasDataPackageView];
}

+ (void)_setImage:(UIImage*)imageData onDataPackage:(WADDataPackage*)dataPackage {
    WSSRandomAccessStreamReference* randomAccessStreamReference =
        [WSSRandomAccessStreamReference createFromStream:[UIPasteboard _grabStreamFromUIImage:imageData]];
    [dataPackage setBitmap:randomAccessStreamReference];
}

+ (void)_setImageToClipboard:(UIImage*)imageData {
    StrongId<WADDataPackage> dataPackage;
    dataPackage.attach([WADDataPackage make]);
    [dataPackage setRequestedOperation:WADDataPackageOperationCopy];
    [UIPasteboard _setImage:imageData onDataPackage:dataPackage];
    [WADClipboard setContent:dataPackage];
    [WADClipboard flush];
}

/**
 @Status Caveat
 @Notes Only general pasteboard, for other type, it just will return nil.
*/
- (NSURL*)URL {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return nil;
    }

    return [UIPasteboard _getURLFromClipboard];
}

/**
 @Status Caveat
 @Notes Only general pasteboard and local app communication is supported.
*/
- (void)setURL:(NSURL*)aURL {
    if (![_name isEqualToString:UIPasteboardNameGeneral]) {
        UNIMPLEMENTED_WITH_MSG("Only general pasteboard supported");
        return;
    }

    if (aURL != nil) {
        [UIPasteboard _setURLToClipboard:aURL];
    }
}

+ (NSURL*)_getURLFromDataPackageView:(WADDataPackageView*)dataPackageView {
    __block NSURL* URLData = nil;
    if ([dataPackageView contains:[WADStandardDataFormats uri]]) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        [dataPackageView getUriAsyncWithSuccess:^void(WFUri* data) {
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

+ (NSURL*)_getURLFromClipboard {
    WADDataPackageView* wasDataPackageView = _getClipboardContent();
    return [UIPasteboard _getURLFromDataPackageView:wasDataPackageView];
}

+ (void)_setURL:(NSURL*)URLData onDataPackage:(WADDataPackage*)dataPackage {
    StrongId<WFUri> uri;
    uri.attach([WFUri makeUri:URLData.absoluteString]);
    [dataPackage setUri:uri];
}

+ (void)_setURLToClipboard:(NSURL*)URLData {
    StrongId<WADDataPackage> dataPackage;
    dataPackage.attach([WADDataPackage make]);
    [dataPackage setRequestedOperation:WADDataPackageOperationCopy];
    [UIPasteboard _setURL:URLData onDataPackage:dataPackage];
    [WADClipboard setContent:dataPackage];
    [WADClipboard flush];
}

@end
