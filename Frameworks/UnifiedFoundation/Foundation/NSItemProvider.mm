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

#import <StubReturn.h>
#import <Foundation/NSItemProvider.h>

NSString* const NSItemProviderPreferredImageSizeKey = @"NSItemProviderPreferredImageSizeKey";
NSString* const NSExtensionJavaScriptPreprocessingResultsKey = @"NSExtensionJavaScriptPreprocessingResultsKey";
NSString* const NSExtensionJavaScriptFinalizeArgumentKey = @"NSExtensionJavaScriptFinalizeArgumentKey";

@implementation NSItemProvider
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithContentsOfURL:(NSURL*)fileURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithItem:(id<NSSecureCoding>)item typeIdentifier:(NSString*)typeIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)registerItemForTypeIdentifier:(NSString*)typeIdentifier loadHandler:(NSItemProviderLoadHandler)loadHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)hasItemConformingToTypeIdentifier:(NSString*)typeIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadItemForTypeIdentifier:(NSString*)typeIdentifier
                          options:(NSDictionary*)options
                completionHandler:(NSItemProviderCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)loadPreviewImageWithOptions:(NSDictionary*)options completionHandler:(NSItemProviderCompletionHandler)completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
