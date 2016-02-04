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

#import <Contacts/CNContactStore.h>
#import <StubReturn.h>

NSString* const CNContactStoreDidChangeNotification = @"CNContactStoreDidChangeNotification";

@implementation CNContactStore
/**
 @Status Stub
 @Notes
*/
- (CNContact*)unifiedContactWithIdentifier:(NSString*)identifier keysToFetch:(NSArray*)keys error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)unifiedContactsMatchingPredicate:(NSPredicate*)predicate keysToFetch:(NSArray*)keys error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (CNAuthorizationStatus)authorizationStatusForEntityType:(CNEntityType)entityType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)requestAccessForEntityType:(CNEntityType)entityType completionHandler:(void (^)(BOOL, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)groupsMatchingPredicate:(NSPredicate*)predicate error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)containersMatchingPredicate:(NSPredicate*)predicate error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSString*)defaultContainerIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)enumerateContactsWithFetchRequest:(CNContactFetchRequest*)fetchRequest
                                    error:(NSError* _Nullable*)error
                               usingBlock:(void (^)(CNContact*, BOOL*))block {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)executeSaveRequest:(CNSaveRequest*)saveRequest error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
