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
#import <AssetsLibrary/ALAssetsGroup.h>

NSString* const ALAssetsGroupPropertyName = @"ALAssetsGroupPropertyName";
NSString* const ALAssetsGroupPropertyType = @"ALAssetsGroupPropertyType";
NSString* const ALAssetsGroupPropertyPersistentID = @"ALAssetsGroupPropertyPersistentID";
NSString* const ALAssetsGroupPropertyURL = @"ALAssetsGroupPropertyURL";

@implementation ALAssetsGroup
/**
 @Status Stub
 @Notes
*/
- (void)enumerateAssetsUsingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateAssetsWithOptions:(NSEnumerationOptions)options usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateAssetsAtIndexes:(NSIndexSet*)indexSet
                         options:(NSEnumerationOptions)options
                      usingBlock:(ALAssetsGroupEnumerationResultsBlock)enumerationBlock {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)addAsset:(ALAsset*)asset {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSInteger)numberOfAssets {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)setAssetsFilter:(ALAssetsFilter*)filter {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)valueForProperty:(NSString*)property {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGImageRef)posterImage {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
