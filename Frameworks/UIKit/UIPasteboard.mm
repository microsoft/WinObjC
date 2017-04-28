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

#import "CGImageInternal.h"
#import "MobileCoreServices/UTType.h"
#import "CppWinRTHelpers.h"

#include <COMIncludes.h>
#import <windows.storage.streams.h>
#import <winrt/Windows.ApplicationModel.DataTransfer.h>
#import <winrt/Windows.Storage.Streams.h>
#import "RawBuffer.h"
#include <COMIncludes_End.h>

using namespace winrt::Windows::ApplicationModel::DataTransfer;
namespace WSS = winrt::Windows::Storage::Streams;
namespace WF = winrt::Windows::Foundation;

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

static DataPackageView _getClipboardContent() {
    try {
        return Clipboard::GetContent();
    } catch (const winrt::hresult_error& exception) {
        if (exception.code() == E_ACCESSDENIED) {
            return nullptr;
        }

        throw;
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
        NSTraceError(TAG, @"%@", msg);
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
    DataPackageView dataPackageView = _getClipboardContent();

    NSMutableArray<NSString*>* types = [NSMutableArray arrayWithCapacity:3];

    if (dataPackageView.Contains(StandardDataFormats::Text())) {
        [types addObject:(NSString*)kUTTypeText];
    }
    if (dataPackageView.Contains(StandardDataFormats::Bitmap())) {
        [types addObject:(NSString*)kUTTypeImage];
    }
    if (dataPackageView.Contains(StandardDataFormats::Uri())) {
        [types addObject:(NSString*)kUTTypeURL];
    }

    return types;
}

/**
 @Status Caveat
 @Notes only NSString, NSURL and UIImage are supported.
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes {
    DataPackageView dataPackageView = _getClipboardContent();
    BOOL result = NO;

    for (NSString* type in pasteboardTypes) {
        if ([type isEqualToString:(NSString*)kUTTypeText]) {
            if (dataPackageView.Contains(StandardDataFormats::Text())) {
                result = YES;
                break;
            }
        } else if ([type isEqualToString:(NSString*)kUTTypeImage]) {
            if (dataPackageView.Contains(StandardDataFormats::Bitmap())) {
                result = YES;
                break;
            }
        } else if ([type isEqualToString:(NSString*)kUTTypeURL]) {
            if (dataPackageView.Contains(StandardDataFormats::Uri())) {
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
    DataPackageView dataPackageView = _getClipboardContent();

    int supportedTypes = 0;
    for (const winrt::hstring& format : dataPackageView.AvailableFormats()) {
        if (format == StandardDataFormats::Text()) {
            supportedTypes++;
        } else if (format == StandardDataFormats::Bitmap()) {
            supportedTypes++;
        } else if (format == StandardDataFormats::Uri()) {
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
    if (dataPackageView.Contains(StandardDataFormats::Text())) {
        [ret setValue:[UIPasteboard _getStringFromDataPackageView:dataPackageView] forKey:(NSString*)kUTTypeText];
    }

    if (dataPackageView.Contains(StandardDataFormats::Bitmap())) {
        [ret setValue:[UIPasteboard _getImageFromDataPackageView:dataPackageView] forKey:(NSString*)kUTTypeImage];
    }

    if (dataPackageView.Contains(StandardDataFormats::Uri())) {
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

        DataPackage dataPackage;
        dataPackage.RequestedOperation(DataPackageOperation::Copy);
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
            Clipboard::SetContent(dataPackage);
            Clipboard::Flush();
        }
    } else {
        // assigning items to nil or an empty array clears the pasteboard
        Clipboard::Clear();
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
    NSData* data = nil;

    if ([pasteboardType isEqualToString:(NSString*)kUTTypeText]) {
        NSString* stringData = [UIPasteboard _getStringFromClipboard];
        if (stringData != nil) {
            data = [stringData dataUsingEncoding:NSUnicodeStringEncoding];
        }
    } else if ([pasteboardType isEqualToString:(NSString*)kUTTypeImage]) {
        UIImage* imageData = [UIPasteboard _getImageFromClipboard];
        if (imageData != nil) {
            // After UIImageJPEGRepresentation is implemented, should consider both PNG and JPEG
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
        // only set data when both data and pasteType are available
        DataPackage dataPackage;
        dataPackage.RequestedOperation(DataPackageOperation::Copy);
        [UIPasteboard _setData:pasteboardType withData:data on:dataPackage];
        Clipboard::SetContent(dataPackage);
        Clipboard::Flush();
    }
}

+ (void)_populateStream:(const WSS::InMemoryRandomAccessStream&)stream withData:(const void*)data withLength:(int)length {
    WSS::DataWriter dataWriter(stream.GetOutputStreamAt(0));
    ComPtr<IBuffer> buffer;
    HRESULT result;

    result = BufferFromRawData(&buffer, (unsigned char*)data, length);

    if (FAILED(result)) {
        THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
    }

    WSS::IBuffer wssBuffer = nullptr;
    winrt::attach_abi(wssBuffer, reinterpret_cast<winrt::ABI::Windows::Storage::Streams::IBuffer*>(buffer.Detach()));

    // WARNING: If someone deletes UIPasteboard before the StoreAsync is completed, _data may be released
    // causing IBuffer to segfault. Although UIPasteboard should live forever once created.

    dataWriter.WriteBuffer(wssBuffer);
    (void)dataWriter.StoreAsync();
}

+ (WSS::InMemoryRandomAccessStream)_grabStreamFromUIImage:(UIImage*)image {
    WSS::InMemoryRandomAccessStream stream;
    NSData* data = UIImagePNGRepresentation(image);
    [UIPasteboard _populateStream:stream withData:[data bytes] withLength:[data length]];
    return stream;
}

// try to set data for a given type on datapackage
// return YES when data has been set on datapackage successfully, NO otherwise.
//
+ (BOOL)_setData:(NSString*)type withData:(NSData*)data on:(const DataPackage&)package {
    if ([type isEqualToString:(NSString*)kUTTypeText]) {
        NSString* text = [[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease];
        package.SetText(objcwinrt::string(text));
        return YES;
    } else if ([type isEqualToString:(NSString*)kUTTypeImage] || [type isEqualToString:(NSString*)kUTTypePNG] ||
               [type isEqualToString:(NSString*)kUTTypeJPEG]) {
        // TODO: we should use UITypeConformsTo to check if type conforms to kUTTypeImage,
        // but UITypeConformsTo has not been implemented yet and currently PNG is the only image format
        // being used in copying

        // grab the image and unpack it and repack it.
        UIImage* uiImage = [UIImage imageWithData:data];
        WSS::RandomAccessStreamReference randomAccessStreamReference =
            WSS::RandomAccessStreamReference::CreateFromStream([UIPasteboard _grabStreamFromUIImage:uiImage]);
        package.SetBitmap(randomAccessStreamReference);
        return YES;
    } else if ([type isEqualToString:(NSString*)kUTTypeURL]) {
        // make sure it is a valid NSURL
        NSURL* url = [NSURL URLWithString:[[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding] autorelease]];
        if (url == nil) {
            TraceWarning(TAG, L"Invalid URL.");
            return NO;
        }

        // convert to WFURI
        WF::Uri uri(objcwinrt::string(url.absoluteString));
        package.SetUri(uri);
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

+ (NSString*)_getStringFromDataPackageView:(const DataPackageView&)dataPackageView {
    NSString* stringData = nil;
    if (dataPackageView.Contains(StandardDataFormats::Text())) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        WF::IAsyncOperation<winrt::hstring> async = dataPackageView.GetTextAsync();

        async.Completed(objcwinrt::callback([&stringData, group] (const WF::IAsyncOperation<winrt::hstring>& op, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                stringData = [objcwinrt::string(op.GetResults()) retain];
            } else {
                NSError* failure = objcwinrt::to_nserror(op, status);
                [UIPasteboard _failureWhileHandingItemToClipboard:failure withMsg:@"string GetTextAsync failed"];
            }

            dispatch_group_leave(group);
        }));

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [stringData autorelease];
}

+ (NSString*)_getStringFromClipboard {
    DataPackageView dataPackageView = _getClipboardContent();
    return [UIPasteboard _getStringFromDataPackageView:dataPackageView];
}

+ (void)_setString:(NSString*)stringData onDataPackage:(const DataPackage&)dataPackage {
    NSData* data = [stringData dataUsingEncoding:NSUnicodeStringEncoding];
    [UIPasteboard _setData:(NSString*)kUTTypeText withData:data on:dataPackage];
}

+ (void)_setStringToClipboard:(NSString*)stringData {
    DataPackage dataPackage;
    dataPackage.RequestedOperation(DataPackageOperation::Copy);
    [UIPasteboard _setString:stringData onDataPackage:dataPackage];
    Clipboard::SetContent(dataPackage);
    Clipboard::Flush();
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

+ (UIImage*)_getImageFromDataPackageView:(const DataPackageView&)dataPackageView {
    UIImage* imageData = nil;

    if (dataPackageView.Contains(StandardDataFormats::Bitmap())) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        WF::IAsyncOperation<WSS::RandomAccessStreamReference> async = dataPackageView.GetBitmapAsync();

        async.Completed(objcwinrt::callback([&imageData, group] (const WF::IAsyncOperation<WSS::RandomAccessStreamReference>& op, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                WSS::RandomAccessStreamReference stream = op.GetResults();
                WF::IAsyncOperation<WSS::IRandomAccessStreamWithContentType> async = stream.OpenReadAsync();

                async.Completed(objcwinrt::callback([&imageData, group] (const WF::IAsyncOperation<WSS::IRandomAccessStreamWithContentType>& op, WF::AsyncStatus status) {
                    if (status == WF::AsyncStatus::Completed) {
                        WSS::IRandomAccessStreamWithContentType content = op.GetResults();
                        WSS::Buffer buffer(content.Size());

                        WF::IAsyncOperationWithProgress<WSS::IBuffer, unsigned int> async = content.ReadAsync(buffer, content.Size(), WSS::InputStreamOptions::None);

                        async.Completed(objcwinrt::callback([&imageData, group] (const WF::IAsyncOperationWithProgress<WSS::IBuffer, unsigned int>& op, WF::AsyncStatus status) {
                            if (status == WF::AsyncStatus::Completed) {
                                // Get the data out of the com object.
                                WSS::IBuffer success = op.GetResults();
                                ComPtr<IInspectable> insp = objcwinrt::to_insp(success);
                                ComPtr<IBufferByteAccess> bufferByteAccess;
                                HRESULT result = insp.As(&bufferByteAccess);
                                if (FAILED(result)) {
                                    THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
                                }

                                // Retrieve the buffer data.
                                byte* pixels = nullptr;
                                int length = success.Length();
                                result = bufferByteAccess->Buffer(&pixels);
                                if (FAILED(result)) {
                                    THROW_NS_HR_MSG(result, "Internal error: Failed to create IBuffer from NSData.");
                                }

                                NSData* data = [NSData dataWithBytes:pixels length:length];
                                imageData = [[UIImage imageWithData:data] retain];
                            } else {
                                NSError* readError = objcwinrt::to_nserror(op, status);
                                [UIPasteboard _failureWhileHandingItemToClipboard:readError
                                                                          withMsg:@"_getImageFromClipboard ReadAsync:buffer failed"];
                            }

                            dispatch_group_leave(group);
                        }));
                    } else {
                        NSError* openError = objcwinrt::to_nserror(op, status);
                        [UIPasteboard _failureWhileHandingItemToClipboard:openError
                                                                  withMsg:@"_getImageFromClipboard OpenReadAsync failed"];

                        dispatch_group_leave(group);
                    }
                }));
            } else {
                NSError* failure = objcwinrt::to_nserror(op, status);
                [UIPasteboard _failureWhileHandingItemToClipboard:failure
                                                          withMsg:@"_getImageFromClipboard GetBitmapAsync failed"];

                dispatch_group_leave(group);
            }
        }));

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [imageData autorelease];
}

+ (UIImage*)_getImageFromClipboard {
    DataPackageView dataPackageView = _getClipboardContent();
    return [UIPasteboard _getImageFromDataPackageView:dataPackageView];
}

+ (void)_setImage:(UIImage*)imageData onDataPackage:(const DataPackage&)dataPackage {
    WSS::RandomAccessStreamReference randomAccessStreamReference =
        WSS::RandomAccessStreamReference::CreateFromStream([UIPasteboard _grabStreamFromUIImage:imageData]);
    dataPackage.SetBitmap(randomAccessStreamReference);
}

+ (void)_setImageToClipboard:(UIImage*)imageData {
    DataPackage dataPackage;
    dataPackage.RequestedOperation(DataPackageOperation::Copy);
    [UIPasteboard _setImage:imageData onDataPackage:dataPackage];
    Clipboard::SetContent(dataPackage);
    Clipboard::Flush();
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

+ (NSURL*)_getURLFromDataPackageView:(const DataPackageView&)dataPackageView {
    NSURL* URLData = nil;
    if (dataPackageView.Contains(StandardDataFormats::Uri())) {
        dispatch_group_t group = dispatch_group_create();
        dispatch_group_enter(group);

        WF::IAsyncOperation<WF::Uri> async = dataPackageView.GetUriAsync();

        async.Completed(objcwinrt::callback([&URLData, group] (const WF::IAsyncOperation<WF::Uri>& op, WF::AsyncStatus status) {
            if (status == WF::AsyncStatus::Completed) {
                WF::Uri data = op.GetResults();
                winrt::hstring temp = data.AbsoluteUri();
                if (temp.empty()) {
                    temp = data.DisplayUri();
                }
                if (temp.empty()) {
                    temp = data.AbsoluteCanonicalUri();
                }
                if (temp.empty()) {
                    temp = data.ToString();
                }

                if (!temp.empty()) {
                    URLData = [[NSURL URLWithString:objcwinrt::string(temp)] retain];
                } else {
                    TraceError(TAG, L"Error cannot understand WFUri data");
                }
            } else {
                NSError* failure = objcwinrt::to_nserror(op, status);
                [UIPasteboard _failureWhileHandingItemToClipboard:failure withMsg:@"_getURLFromClipboard GetUriAsync failed"];
            }

            dispatch_group_leave(group);
        }));

        dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
        dispatch_release(group);
    }

    return [URLData autorelease];
}

+ (NSURL*)_getURLFromClipboard {
    DataPackageView dataPackageView = _getClipboardContent();
    return [UIPasteboard _getURLFromDataPackageView:dataPackageView];
}

+ (void)_setURL:(NSURL*)URLData onDataPackage:(const DataPackage&)dataPackage {
    WF::Uri uri(objcwinrt::string(URLData.absoluteString));
    dataPackage.SetUri(uri);
}

+ (void)_setURLToClipboard:(NSURL*)URLData {
    DataPackage dataPackage;
    dataPackage.RequestedOperation(DataPackageOperation::Copy);
    [UIPasteboard _setURL:URLData onDataPackage:dataPackage];
    Clipboard::SetContent(dataPackage);
    Clipboard::Flush();
}

@end
