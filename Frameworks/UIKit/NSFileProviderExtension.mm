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

#import <UIKit/UIKit.h>
#import <StubReturn.h>

@implementation NSFileProviderExtension
/**
 @Status Stub
 @Notes
*/
+ (NSURL*)placeholderURLForURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)writePlaceholderAtURL:(NSURL*)placeholderURL withMetadata:(NSDictionary*)metadata error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSURL*)documentStorageURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)providerIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)persistentIdentifierForItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSURL*)URLForItemWithPersistentIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)itemChangedAtURL:(NSURL*)url {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)providePlaceholderAtURL:(NSURL*)url completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)startProvidingItemAtURL:(NSURL*)url completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopProvidingItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
}

@end
