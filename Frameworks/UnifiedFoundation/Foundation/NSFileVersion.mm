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
#import <Foundation/NSFileVersion.h>

@implementation NSFileVersion
/**
 @Status Stub
 @Notes
*/
+ (NSFileVersion*)currentVersionOfItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)otherVersionsOfItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSFileVersion*)versionOfItemAtURL:(NSURL*)url forPersistentIdentifier:(id)persistentIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSArray*)unresolvedConflictVersionsOfItemAtURL:(NSURL*)url {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSURL*)replaceItemAtURL:(NSURL*)url options:(NSFileVersionReplacingOptions)options error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeAndReturnError:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)removeOtherVersionsOfItemAtURL:(NSURL*)inFileURL error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
