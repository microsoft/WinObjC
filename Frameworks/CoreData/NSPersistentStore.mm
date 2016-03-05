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
#import <CoreData/NSPersistentStore.h>

@implementation NSPersistentStore
/**
@Status Stub
@Notes
*/
- (instancetype)initWithPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator
                                 configurationName:(NSString*)configurationName
                                               URL:(NSURL*)url
                                           options:(NSDictionary*)options {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSDictionary*)metadataForPersistentStoreWithURL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (BOOL)setMetadata:(NSDictionary*)metadata forPersistentStoreWithURL:(NSURL*)url error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (BOOL)loadMetadata:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)didAddToPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)willRemoveFromPersistentStoreCoordinator:(NSPersistentStoreCoordinator*)coordinator {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
+ (Class)migrationManagerClass {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
