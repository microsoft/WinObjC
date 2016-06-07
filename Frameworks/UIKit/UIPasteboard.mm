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

#import <COMIncludes.h>
#import <windows.storage.streams.h>
#import "RawBuffer.h"
#import <COMIncludes_End.h>

#include "Starboard.h"
#include "UIKit/UIPasteboard.h"
#import "NSLogging.h"
#include <StubReturn.h>

#include "UWP/WindowsApplicationModelDataTransfer.h"
#include "CGImageInternal.h"

static const wchar_t* TAG = L"UIPasteboard";
NSString* const UIPasteboardNameGeneral = @"UIPasteboardNameGeneral";
NSString* const UIPasteboardNameFind = @"UIPasteboardNameFind";
NSString* const UIPasteboardChangedTypesAddedKey = @"UIPasteboardChangedTypesAddedKey";
NSString* const UIPasteboardChangedTypesRemovedKey = @"UIPasteboardChangedTypesRemovedKey";

/** @Status Interoperable */
NSArray* const UIPasteboardTypeListString = [NSMutableArray new];
/** @Status Interoperable */
NSArray* const UIPasteboardTypeListURL = [NSMutableArray new];
/** @Status Interoperable */
NSArray* const UIPasteboardTypeListImage = [NSMutableArray new];
/** @Status Interoperable */
NSArray* const UIPasteboardTypeListColor = [NSMutableArray new];

NSString* const UIPasteboardChangedNotification = @"UIPasteboardChangedNotification";
NSString* const UIPasteboardRemovedNotification = @"UIPasteboardRemovedNotification";

using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage::Streams;

using namespace Microsoft::WRL;

@implementation UIPasteboard {
    NSMutableDictionary* _typeToData;
}
UIPasteboard* generalPasteboard;
NSMutableDictionary* globalPasteBoards;

/**
 @Status Caveat
 @Notes only NSString and UIImage are supported by generalPasteboard.
*/
+ (UIPasteboard*)generalPasteboard {
    if (generalPasteboard == nil) {
        generalPasteboard = [[UIPasteboard alloc] init:UIPasteboardNameGeneral];
    }
    return generalPasteboard;
}

- (UIPasteboard*)init:(NSString*)pasteBoardName {
    if (self = [super init]) {
        if (globalPasteBoards == nil) {
            globalPasteBoards = [[NSMutableDictionary alloc] initWithCapacity:10];
        }

        if ([pasteBoardName isEqualToString:UIPasteboardNameGeneral]) {
            __weak UIPasteboard* weakSelf = self;
            EventRegistrationToken evrt = [WADClipboard addContentChangedEvent:^void(RTObject* first, RTObject* second) {
                [weakSelf _handleItemHandedToClipboard:(RTObject*)first with:(RTObject*)second];
            }];
        }

        _typeToData = [[NSMutableDictionary alloc] initWithCapacity:3];
        _name = pasteBoardName;
    }
    return self;
}

- (void)_handleItemHandedToClipboard:(RTObject*)first with:(RTObject*)second {
    WADDataPackageView* wasDataPackageView = [WADClipboard getContent];
    __weak UIPasteboard* weakSelf = self;

    if ([wasDataPackageView contains:[WADStandardDataFormats text]]) {
        [wasDataPackageView getTextAsyncWithSuccess:^void(NSString* success) {

            [weakSelf _handleTextAddedToClipboard:success];

        }
            failure:^void(NSError* failure) {
                [weakSelf _failurWhileHandingItemToClipboard:failure
                                                     withMsg:@"_handleItemHandedToClipboard getTextAsyncWithSuccess failed"];

            }];

    } else if ([wasDataPackageView contains:[WADStandardDataFormats bitmap]]) {
        [wasDataPackageView getBitmapAsyncWithSuccess:^void(WSSRandomAccessStreamReference* success) {

            [weakSelf _handleBitMapAddedToClipboard:success];

        }
            failure:^void(NSError* failure) {
                [weakSelf _failurWhileHandingItemToClipboard:failure
                                                     withMsg:@"_handleItemHandedToClipboard getBitmapAsyncWithSuccess failed"];

            }];

    } else if ([wasDataPackageView contains:[WADStandardDataFormats uri]]) {
        [wasDataPackageView getUriAsyncWithSuccess:^void(WFUri* success) {

            [weakSelf _handleItemURLAddedToClipboard:success];

        }
            failure:^void(NSError* failure) {
                [weakSelf _failurWhileHandingItemToClipboard:failure
                                                     withMsg:@"_handleItemHandedToClipboard getBitmapAsyncWithSuccess failed"];

            }];
    }
}

- (void)_handleTextAddedToClipboard:(NSString*)data {
    [_typeToData setObject:[data dataUsingEncoding:NSUTF8StringEncoding] forKey:@"NSString"];
}

- (void)_handleBitMapAddedToClipboard:(WSSRandomAccessStreamReference*)data {
    __weak UIPasteboard* weakSelf = self;

    [data openReadAsyncWithSuccess:^void(RTObject<WSSIRandomAccessStreamWithContentType>* success) {

        WSSBuffer* buffer = [[WSSBuffer make:success.size] autorelease];

        [success readAsync:buffer
            count:success.size
            options:WSSInputStreamOptionsNone
            success:^void(RTObject<WSSIBuffer>* success) {
                // Get the data out of the com object.
                ComPtr<IInspectable> insp = [success comObj];
                ComPtr<IBufferByteAccess> bufferByteAccess;
                HRESULT result;
                result = insp.As(&bufferByteAccess);
                if (FAILED(result)) {
                    @throw [NSException exceptionWithName:NSGenericException
                                                   reason:@"Internal error: Failed to create IBuffer from NSData"
                                                 userInfo:nil];
                }

                // Retrieve the buffer data.
                byte* pixels = nullptr;
                int length = success.length;
                result = bufferByteAccess->Buffer(&pixels);
                if (FAILED(result)) {
                    @throw [NSException exceptionWithName:NSGenericException
                                                   reason:@"Internal error: Failed to create IBuffer from NSData"
                                                 userInfo:nil];
                }

                [weakSelf _packageNSDataIntoUIImage:(char*)pixels length:length];

            }
            progress:nullptr
            failure:^void(NSError* failure) {
                [weakSelf _failurWhileHandingItemToClipboard:failure withMsg:@"_handleBitMapAddedToClipboard readAsync:buffer failed"];
            }];

        IBufferByteAccess* pBufferByteAccess = nullptr;

    }
        failure:^void(NSError* failure) {
            [weakSelf _failurWhileHandingItemToClipboard:failure withMsg:@"_handleBitMapAddedToClipboard openReadAsyncWithSuccess failed"];
        }];
}

- (void)_packageNSDataIntoUIImage:(char*)bytes length:(int)length {
    NSData* data = [NSData dataWithBytes:bytes length:length];
    UIImage* uiimage = [UIImage imageWithData:data];
    [_typeToData setObject:UIImagePNGRepresentation(uiimage) forKey:@"UIImage"];
}

- (void)_handleItemURLAddedToClipboard:(WFUri*)data {
    NSString* temp;
    if ([data absoluteUri] != nil && [data absoluteUri].length > 0) {
        temp = [data absoluteUri];

    } else if ([data displayUri] != nil && [data displayUri].length > 0) {
        temp = [data displayUri];
    }

    if ([data absoluteCanonicalUri] != nil && [data absoluteCanonicalUri].length > 0) {
        temp = [data absoluteCanonicalUri];
    } else if ([data toString] != nil && [data toString].length > 0) {
        temp = [data toString];
    }

    if (temp != nil) {
        [_typeToData setObject:[temp dataUsingEncoding:NSUTF8StringEncoding] forKey:@"NSString"];
    } else {
        TraceError(TAG, L"Error cannot understand WFUri data");
    }
}

- (void)_failurWhileHandingItemToClipboard:(NSError*)failure withMsg:(NSString*)msg {
    if (failure != nil) {
        NSTraceError(TAG, @"Error with UIPasteBoard %@", failure);
    }

    if (msg != nil) {
        NSTraceError(TAG, msg);
    }
}

/**
 @Status Caveat
 @Notes Only general pasteboard and local app communication is supported.
*/
+ (UIPasteboard*)pasteboardWithName:(NSString*)pasteboardName create:(BOOL)create {
    // initArray

    if (pasteboardName == nil) {
        return [UIPasteboard pasteboardWithUniqueName];
    }
    UIPasteboard* temp = [[UIPasteboard alloc] init];
    [globalPasteBoards setObject:temp forKey:pasteboardName];
    return temp;
}

/**
 @Status Interoperable
*/
+ (UIPasteboard*)pasteboardWithUniqueName {
    static int curId = 0;
    char szName[255];
    sprintf_s(szName, sizeof(szName), "Undefined_%d", curId);
    curId++;
    NSString* uniqueName = [NSString stringWithCString:szName];
    return [UIPasteboard pasteboardWithName:uniqueName create:YES];
}

/**
 @Status Interoperable
 @Notes
*/
+ (void)removePasteboardWithName:(NSString*)pasteboardName {
    // only allow none general pasteboards to be removed
    if (globalPasteBoards != nil) {
        [globalPasteBoards removeObjectForKey:pasteboardName];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (NSArray*)pasteboardTypes {
    return _typeToData.allKeys;
}

/**
 @Status Interoperable
 @Notes
*/
- (BOOL)containsPasteboardTypes:(NSArray*)pasteboardTypes {
    if ([_typeToData objectForKey:pasteboardTypes] == nil) {
        return NO;
    }
    return YES;
}

/**
 @Status Caveat
 @Notes only NSString and UIImage are supported.
*/
- (NSData*)dataForPasteboardType:(NSString*)pasteboardType {
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        return [_typeToData objectForKey:pasteboardType];
    }
    return [_typeToData objectForKey:pasteboardType];
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
    [_typeToData setObject:data forKey:pasteboardType];

    // Copy and Paste
    if ([_name isEqualToString:UIPasteboardNameGeneral]) {
        WADDataPackage* dataPackage = [[WADDataPackage make] autorelease];
        dataPackage.requestedOperation = WADDataPackageOperationCopy;
        [self _setData:pasteboardType withData:data on:dataPackage];
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
        @throw
            [NSException exceptionWithName:NSGenericException reason:@"Internal error: Failed to create IBuffer from NSData" userInfo:nil];
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

- (WSSInMemoryRandomAccessStream*)grabStreamFromUIImage:(UIImage*)image {
    CGImageRef img = [image CGImage];

    if (img->_imgType == CGImageTypePNG || img->_imgType == CGImageTypeJPEG) {
        const void* data = NULL;
        bool freeData = false;
        int len = 0;

        switch (img->_imgType) {
            case CGImageTypePNG: {
                CGPNGImageBacking* pngImg = (CGPNGImageBacking*)img->Backing();

                if (pngImg->_fileName) {
                    EbrFile* fpIn;
                    fpIn = EbrFopen(pngImg->_fileName, "rb");
                    if (!fpIn) {
                        FAIL_FAST();
                    }
                    EbrFseek(fpIn, 0, SEEK_END);
                    int fileLen = EbrFtell(fpIn);
                    EbrFseek(fpIn, 0, SEEK_SET);
                    void* pngData = (void*)IwMalloc(fileLen);
                    len = EbrFread(pngData, 1, fileLen, fpIn);
                    EbrFclose(fpIn);

                    data = pngData;
                    freeData = true;
                } else {
                    data = [(NSData*)pngImg->_data bytes];
                    len = [(NSData*)pngImg->_data length];
                }
            } break;

            case CGImageTypeJPEG: {
                CGJPEGImageBacking* jpgImg = (CGJPEGImageBacking*)img->Backing();

                if (jpgImg->_fileName) {
                    EbrFile* fpIn;
                    fpIn = EbrFopen(jpgImg->_fileName, "rb");
                    if (!fpIn) {
                        FAIL_FAST();
                    }
                    EbrFseek(fpIn, 0, SEEK_END);
                    int fileLen = EbrFtell(fpIn);
                    EbrFseek(fpIn, 0, SEEK_SET);
                    void* imgData = (void*)IwMalloc(fileLen);
                    len = EbrFread(imgData, 1, fileLen, fpIn);
                    EbrFclose(fpIn);

                    data = imgData;
                    freeData = true;
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
        return [UIPasteboard _populateStream:stream withData:data withLength:len];
    }
    return nil;
}

- (void)_setData:(NSString*)type withData:(NSData*)data on:(WADDataPackage*)package {
    if ([type isEqualToString:@"NSString"]) {
        [package setText:[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding]];
    } else if ([type isEqualToString:@"UIImage"]) {
        // grab the image and unpack it and repack it.
        UIImage* uiImage = [[UIImage imageWithData:data] retain];
        WSSRandomAccessStreamReference* randomAccessStreamReference =
            [WSSRandomAccessStreamReference createFromStream:[self grabStreamFromUIImage:uiImage]];
        [package setBitmap:randomAccessStreamReference];
    } else if ([type isEqualToString:@"NSURL"]) {
        // make sure it is a valid NSURL
        NSURL* url = [NSURL URLWithString:[[NSString alloc] initWithData:data encoding:NSUnicodeStringEncoding]];
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

@end
